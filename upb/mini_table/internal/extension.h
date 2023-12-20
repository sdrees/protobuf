// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef UPB_MINI_TABLE_INTERNAL_EXTENSION_H_
#define UPB_MINI_TABLE_INTERNAL_EXTENSION_H_

#include <stdint.h>

#include "upb/mini_table/field.h"
#include "upb/mini_table/sub.h"

// Must be last.
#include "upb/port/def.inc"

struct upb_MiniTableExtension {
  // Do not move this field. We need to be able to alias pointers.
  upb_MiniTableField UPB_PRIVATE(field);

  const upb_MiniTable* UPB_PRIVATE(extendee);
  upb_MiniTableSub UPB_PRIVATE(sub);  // NULL unless submsg or proto2 enum
};

#ifdef __cplusplus
extern "C" {
#endif

UPB_INLINE const upb_MiniTableField* UPB_PRIVATE(
    _upb_MiniTableExtension_AsField)(const upb_MiniTableExtension* e) {
  return (const upb_MiniTableField*)&e->UPB_PRIVATE(field);
}

UPB_INLINE uint32_t
UPB_PRIVATE(_upb_MiniTableExtension_Number)(const upb_MiniTableExtension* e) {
  return e->UPB_PRIVATE(field).UPB_ONLYBITS(number);
}

UPB_INLINE const upb_MiniTable* UPB_PRIVATE(
    _upb_MiniTableExtension_GetSubMessage)(const upb_MiniTableExtension* e) {
  return upb_MiniTableSub_Message(e->UPB_PRIVATE(sub));
}

UPB_INLINE void UPB_PRIVATE(_upb_MiniTableExtension_SetSubMessage)(
    upb_MiniTableExtension* e, const upb_MiniTable* m) {
  e->UPB_PRIVATE(sub).UPB_PRIVATE(submsg) = m;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif /* UPB_MINI_TABLE_INTERNAL_EXTENSION_H_ */
