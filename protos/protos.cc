// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "protos/protos.h"

#include <atomic>
#include <cstddef>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/strings/str_format.h"
#include "absl/strings/string_view.h"
#include "protos/protos_extension_lock.h"
#include "upb/mem/arena.h"
#include "upb/message/copy.h"
#include "upb/message/internal/extension.h"
#include "upb/message/message.h"
#include "upb/message/promote.h"
#include "upb/mini_table/extension.h"
#include "upb/mini_table/extension_registry.h"
#include "upb/mini_table/message.h"
#include "upb/wire/decode.h"
#include "upb/wire/encode.h"

namespace protos {

// begin:google_only
// absl::Status MessageAllocationError(SourceLocation loc) {
//   return absl::Status(absl::StatusCode::kInternal,
//                       "Upb message allocation error", loc);
// }
//
// absl::Status ExtensionNotFoundError(int extension_number, SourceLocation loc) {
//   return absl::Status(
//       absl::StatusCode::kInternal,
//       absl::StrFormat("Extension %d not found", extension_number), loc);
// }
//
// absl::Status MessageEncodeError(upb_EncodeStatus status, SourceLocation loc) {
//   return absl::Status(absl::StatusCode::kInternal,
//                       absl::StrFormat("Upb message encoding error %d", status),
//                       loc
//
//   );
// }
//
// absl::Status MessageDecodeError(upb_DecodeStatus status, SourceLocation loc
//
// ) {
//   return absl::Status(absl::StatusCode::kInternal,
//                       absl::StrFormat("Upb message parse error %d", status), loc
//
//   );
// }
// end:google_only

// begin:github_only
absl::Status MessageAllocationError(SourceLocation loc) {
  return absl::Status(absl::StatusCode::kUnknown,
                      "Upb message allocation error");
}

absl::Status ExtensionNotFoundError(int ext_number, SourceLocation loc) {
  return absl::Status(absl::StatusCode::kUnknown,
                      absl::StrFormat("Extension %d not found", ext_number));
}

absl::Status MessageEncodeError(upb_EncodeStatus s, SourceLocation loc) {
  return absl::Status(absl::StatusCode::kUnknown, "Encoding error");
}

absl::Status MessageDecodeError(upb_DecodeStatus status, SourceLocation loc

) {
  return absl::Status(absl::StatusCode::kUnknown, "Upb message parse error");
}
// end:github_only

namespace internal {

upb_ExtensionRegistry* GetUpbExtensions(
    const ExtensionRegistry& extension_registry) {
  return extension_registry.registry_;
}

/**
 * MessageLock(msg) acquires lock on msg when constructed and releases it when
 * destroyed.
 */
class MessageLock {
 public:
  explicit MessageLock(const upb_Message* msg) : msg_(msg) {
    UpbExtensionLocker locker =
        upb_extension_locker_global.load(std::memory_order_acquire);
    unlocker_ = (locker != nullptr) ? locker(msg) : nullptr;
  }
  MessageLock(const MessageLock&) = delete;
  void operator=(const MessageLock&) = delete;
  ~MessageLock() {
    if (unlocker_ != nullptr) {
      unlocker_(msg_);
    }
  }

 private:
  const upb_Message* msg_;
  UpbExtensionUnlocker unlocker_;
};

bool HasExtensionOrUnknown(const upb_Message* msg,
                           const upb_MiniTableExtension* eid) {
  MessageLock msg_lock(msg);
  return _upb_Message_Getext(msg, eid) != nullptr ||
         upb_Message_FindUnknown(msg, upb_MiniTableExtension_Number(eid), 0)
                 .status == kUpb_FindUnknown_Ok;
}

const upb_Extension* GetOrPromoteExtension(upb_Message* msg,
                                           const upb_MiniTableExtension* eid,
                                           upb_Arena* arena) {
  MessageLock msg_lock(msg);
  const upb_Extension* ext = _upb_Message_Getext(msg, eid);
  if (ext == nullptr) {
    upb_GetExtension_Status ext_status = upb_MiniTable_GetOrPromoteExtension(
        (upb_Message*)msg, eid, 0, arena, &ext);
    if (ext_status != kUpb_GetExtension_Ok) {
      ext = nullptr;
    }
  }
  return ext;
}

absl::StatusOr<absl::string_view> Serialize(const upb_Message* message,
                                            const upb_MiniTable* mini_table,
                                            upb_Arena* arena, int options) {
  MessageLock msg_lock(message);
  size_t len;
  char* ptr;
  upb_EncodeStatus status =
      upb_Encode(message, mini_table, options, arena, &ptr, &len);
  if (status == kUpb_EncodeStatus_Ok) {
    return absl::string_view(ptr, len);
  }
  return MessageEncodeError(status);
}

void DeepCopy(upb_Message* target, const upb_Message* source,
              const upb_MiniTable* mini_table, upb_Arena* arena) {
  MessageLock msg_lock(source);
  upb_Message_DeepCopy(target, source, mini_table, arena);
}

upb_Message* DeepClone(const upb_Message* source,
                       const upb_MiniTable* mini_table, upb_Arena* arena) {
  MessageLock msg_lock(source);
  return upb_Message_DeepClone(source, mini_table, arena);
}

absl::Status MoveExtension(upb_Message* message, upb_Arena* message_arena,
                           const upb_MiniTableExtension* ext,
                           upb_Message* extension, upb_Arena* extension_arena) {
  upb_Extension* msg_ext =
      _upb_Message_GetOrCreateExtension(message, ext, message_arena);
  if (!msg_ext) {
    return MessageAllocationError();
  }
  if (message_arena != extension_arena) {
    // Try fuse, if fusing is not allowed or fails, create copy of extension.
    if (!upb_Arena_Fuse(message_arena, extension_arena)) {
      msg_ext->data.ptr = DeepClone(
          extension, upb_MiniTableExtension_GetSubMessage(msg_ext->ext),
          message_arena);
      return absl::OkStatus();
    }
  }
  msg_ext->data.ptr = extension;
  return absl::OkStatus();
}

absl::Status SetExtension(upb_Message* message, upb_Arena* message_arena,
                          const upb_MiniTableExtension* ext,
                          const upb_Message* extension) {
  upb_Extension* msg_ext =
      _upb_Message_GetOrCreateExtension(message, ext, message_arena);
  if (!msg_ext) {
    return MessageAllocationError();
  }
  // Clone extension into target message arena.
  msg_ext->data.ptr =
      DeepClone(extension, upb_MiniTableExtension_GetSubMessage(msg_ext->ext),
                message_arena);
  return absl::OkStatus();
}

}  // namespace internal

}  // namespace protos
