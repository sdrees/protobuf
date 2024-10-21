// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "google/protobuf/compiler/hpb/gen_extensions.h"

#include "absl/strings/str_cat.h"
#include "google/protobuf/compiler/hpb/context.h"
#include "google/protobuf/compiler/hpb/names.h"
#include "upb_generator/c/names.h"

namespace google::protobuf::hpb_generator {

namespace protobuf = ::proto2;

std::string ExtensionIdentifierBase(const protobuf::FieldDescriptor* ext) {
  assert(ext->is_extension());
  std::string ext_scope;
  if (ext->extension_scope()) {
    return upb::generator::CApiMessageType(ext->extension_scope()->full_name());
  } else {
    return ToCIdent(ext->file()->package());
  }
}

std::string ContainingTypeName(const protobuf::FieldDescriptor* ext) {
  return ext->containing_type()->file() != ext->file()
             ? QualifiedClassName(ext->containing_type())
             : ClassName(ext->containing_type());
}

void WriteExtensionIdentifierHeader(const protobuf::FieldDescriptor* ext,
                                    Context& ctx) {
  std::string mini_table_name =
      absl::StrCat(ExtensionIdentifierBase(ext), "_", ext->name(), "_ext");
  if (ext->extension_scope()) {
    ctx.EmitLegacy(
        R"cc(
          static const ::hpb::internal::ExtensionIdentifier<$0, $1> $2;
        )cc",
        ContainingTypeName(ext), CppTypeParameterName(ext), ext->name());
  } else {
    ctx.EmitLegacy(
        R"cc(
          extern const ::hpb::internal::ExtensionIdentifier<$0, $1> $2;
        )cc",
        ContainingTypeName(ext), CppTypeParameterName(ext), ext->name());
  }
}

void WriteExtensionIdentifiersHeader(
    const std::vector<const protobuf::FieldDescriptor*>& extensions,
    Context& ctx) {
  for (const auto* ext : extensions) {
    if (!ext->extension_scope()) {
      WriteExtensionIdentifierHeader(ext, ctx);
    }
  }
}

void WriteExtensionIdentifier(const protobuf::FieldDescriptor* ext,
                              Context& ctx) {
  std::string mini_table_name =
      absl::StrCat(ExtensionIdentifierBase(ext), "_", ext->name(), "_ext");
  if (ext->extension_scope()) {
    ctx.EmitLegacy(
        R"cc(
          constexpr ::hpb::internal::ExtensionIdentifier<$0, $3> $4::$2 =
              ::hpb::internal::PrivateAccess::InvokeConstructor<
                  ::hpb::internal::ExtensionIdentifier<$0, $3>>(&$1);
        )cc",
        ContainingTypeName(ext), mini_table_name, ext->name(),
        CppTypeParameterName(ext), ClassName(ext->extension_scope()));
  } else {
    ctx.EmitLegacy(
        R"cc(
          constexpr ::hpb::internal::ExtensionIdentifier<$0, $3> $2 =
              ::hpb::internal::PrivateAccess::InvokeConstructor<
                  ::hpb::internal::ExtensionIdentifier<$0, $3>>(&$1);
        )cc",
        ContainingTypeName(ext), mini_table_name, ext->name(),
        CppTypeParameterName(ext));
  }
}

void WriteExtensionIdentifiers(
    const std::vector<const protobuf::FieldDescriptor*>& extensions,
    Context& ctx) {
  for (const auto* ext : extensions) {
    if (!ext->extension_scope()) {
      WriteExtensionIdentifier(ext, ctx);
    }
  }
}

}  // namespace protobuf
}  // namespace google::hpb_generator
