// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef GOOGLE_PROTOBUF_UTIL_INTERNAL_ERROR_LISTENER_H__
#define GOOGLE_PROTOBUF_UTIL_INTERNAL_ERROR_LISTENER_H__

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "google/protobuf/stubs/callback.h"
#include "google/protobuf/stubs/common.h"
#include "google/protobuf/stubs/logging.h"
#include "absl/strings/string_view.h"
#include "google/protobuf/port.h"
#include "google/protobuf/util/internal/location_tracker.h"

// Must be included last.
#include "google/protobuf/port_def.inc"

namespace google {
namespace protobuf {
namespace util {
namespace converter {

// Interface for error listener.
class PROTOBUF_EXPORT ErrorListener {
 public:
  ErrorListener(const ErrorListener&) = delete;
  ErrorListener& operator=(const ErrorListener&) = delete;
  virtual ~ErrorListener() {}

  // Reports an invalid name at the given location.
  virtual void InvalidName(const LocationTrackerInterface& loc,
                           absl::string_view invalid_name,
                           absl::string_view message) = 0;

  // Reports an invalid value for a field.
  virtual void InvalidValue(const LocationTrackerInterface& loc,
                            absl::string_view type_name,
                            absl::string_view value) = 0;

  // Reports a missing required field.
  virtual void MissingField(const LocationTrackerInterface& loc,
                            absl::string_view missing_name) = 0;

 protected:
  ErrorListener() {}
};

// An error listener that ignores all errors.
class PROTOBUF_EXPORT NoopErrorListener : public ErrorListener {
 public:
  NoopErrorListener() {}
  NoopErrorListener(const NoopErrorListener&) = delete;
  NoopErrorListener& operator=(const NoopErrorListener&) = delete;
  ~NoopErrorListener() override {}

  void InvalidName(const LocationTrackerInterface& /*loc*/,
                   absl::string_view /* invalid_name */,
                   absl::string_view /* message */) override {}

  void InvalidValue(const LocationTrackerInterface& /*loc*/,
                    absl::string_view /* type_name */,
                    absl::string_view /* value */) override {}

  void MissingField(const LocationTrackerInterface& /* loc */,
                    absl::string_view /* missing_name */) override {}
};


}  // namespace converter
}  // namespace util
}  // namespace protobuf
}  // namespace google

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_UTIL_INTERNAL_ERROR_LISTENER_H__
