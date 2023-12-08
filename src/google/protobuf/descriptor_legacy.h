// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.
//
// This file contains classes which describe a type of protocol message.
// You can use a message's descriptor to learn at runtime what fields
// it contains and what the types of those fields are.  The Message
// interface also allows you to dynamically access and modify individual
// fields by passing the FieldDescriptor of the field you are interested
// in.
//
// Most users will not care about descriptors, because they will write
// code specific to certain protocol types and will simply use the classes
// generated by the protocol compiler directly.  Advanced users who want
// to operate on arbitrary types (not known at compile time) may want to
// read descriptors in order to learn about the contents of a message.
// A very small number of users will want to construct their own
// Descriptors, either because they are implementing Message manually or
// because they are writing something like the protocol compiler.
//
// For an example of how you might use descriptors, see the code example
// at the top of message.h.

#ifndef GOOGLE_PROTOBUF_DESCRIPTOR_LEGACY_H__
#define GOOGLE_PROTOBUF_DESCRIPTOR_LEGACY_H__

#include "absl/strings/string_view.h"
#include "google/protobuf/descriptor.h"

// Must be included last.
#include "google/protobuf/port_def.inc"

// This file is meant to be a temporary housing for legacy descriptor APIs we
// want to deprecate and remove.  This will help prevent backslide by allowing
// us to control visibility.

namespace google {
namespace protobuf {
PROTOBUF_IGNORE_DEPRECATION_START

// Wraps FileDescriptor.
class FileDescriptorLegacy {
 public:
  explicit FileDescriptorLegacy(const FileDescriptor* desc) : desc_(desc) {}

  // Any dependencies on file-level syntax keyword should be replaced by
  // feature-level switches to support go/protobuf-editions.
  enum Syntax {
    SYNTAX_UNKNOWN = FileDescriptor::SYNTAX_UNKNOWN,
    SYNTAX_PROTO2 = FileDescriptor::SYNTAX_PROTO2,
    SYNTAX_PROTO3 = FileDescriptor::SYNTAX_PROTO3,
    SYNTAX_EDITIONS = FileDescriptor::SYNTAX_EDITIONS,
  };
  Syntax syntax() const { return static_cast<Syntax>(desc_->syntax()); }
  static absl::string_view SyntaxName(Syntax syntax) {
    return FileDescriptor::SyntaxName(
        static_cast<FileDescriptor::Syntax>(syntax));
  }

 private:
  const FileDescriptor* desc_;
};

class FieldDescriptorLegacy {
 public:
  explicit FieldDescriptorLegacy(const FieldDescriptor* desc) : desc_(desc) {}

  bool has_optional_keyword() const { return desc_->has_optional_keyword(); }

 private:
  const FieldDescriptor* desc_;
};

class OneofDescriptorLegacy {
 public:
  explicit OneofDescriptorLegacy(const OneofDescriptor* desc) : desc_(desc) {}

  bool is_synthetic() const { return desc_->is_synthetic(); }

 private:
  const OneofDescriptor* desc_;
};

PROTOBUF_IGNORE_DEPRECATION_STOP
}  // namespace protobuf
}  // namespace google

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_DESCRIPTOR_LEGACY_H__
