#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>

#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"
#include "google/protobuf/repeated_ptr_field.h"
#include "rust/cpp_kernel/strings.h"

extern "C" {
#define expose_repeated_field_methods(ty, rust_ty)                            \
  google::protobuf::RepeatedField<ty>* __pb_rust_RepeatedField_##rust_ty##_new() {      \
    return new google::protobuf::RepeatedField<ty>();                                   \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_free(                              \
      google::protobuf::RepeatedField<ty>* r) {                                         \
    delete r;                                                                 \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_add(google::protobuf::RepeatedField<ty>* r,  \
                                               ty val) {                      \
    r->Add(val);                                                              \
  }                                                                           \
  size_t __pb_rust_RepeatedField_##rust_ty##_size(                            \
      google::protobuf::RepeatedField<ty>* r) {                                         \
    return r->size();                                                         \
  }                                                                           \
  ty __pb_rust_RepeatedField_##rust_ty##_get(google::protobuf::RepeatedField<ty>* r,    \
                                             size_t index) {                  \
    return r->Get(index);                                                     \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_set(google::protobuf::RepeatedField<ty>* r,  \
                                               size_t index, ty val) {        \
    return r->Set(index, val);                                                \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_copy_from(                         \
      const google::protobuf::RepeatedField<ty>* src, google::protobuf::RepeatedField<ty>* dst) { \
    dst->CopyFrom(*src);                                                      \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_clear(                             \
      google::protobuf::RepeatedField<ty>* r) {                                         \
    r->Clear();                                                               \
  }                                                                           \
  void __pb_rust_RepeatedField_##rust_ty##_reserve(                           \
      google::protobuf::RepeatedField<ty>* r, size_t additional) {                      \
    r->Reserve(r->size() + additional);                                       \
  }

expose_repeated_field_methods(int32_t, i32);
expose_repeated_field_methods(uint32_t, u32);
expose_repeated_field_methods(float, f32);
expose_repeated_field_methods(double, f64);
expose_repeated_field_methods(bool, bool);
expose_repeated_field_methods(uint64_t, u64);
expose_repeated_field_methods(int64_t, i64);
#undef expose_repeated_field_methods

#define expose_repeated_ptr_field_methods(ty)                          \
  google::protobuf::RepeatedPtrField<std::string>*                               \
      __pb_rust_RepeatedField_##ty##_new() {                           \
    return new google::protobuf::RepeatedPtrField<std::string>();                \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_free(                            \
      google::protobuf::RepeatedPtrField<std::string>* r) {                      \
    delete r;                                                          \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_add(                             \
      google::protobuf::RepeatedPtrField<std::string>* r,                        \
      google::protobuf::rust_internal::PtrAndLen val) {                          \
    r->Add(std::string(val.ptr, val.len));                             \
  }                                                                    \
  size_t __pb_rust_RepeatedField_##ty##_size(                          \
      google::protobuf::RepeatedPtrField<std::string>* r) {                      \
    return r->size();                                                  \
  }                                                                    \
  google::protobuf::rust_internal::PtrAndLen __pb_rust_RepeatedField_##ty##_get( \
      google::protobuf::RepeatedPtrField<std::string>* r, size_t index) {        \
    const std::string& s = r->Get(index);                              \
    return google::protobuf::rust_internal::PtrAndLen(s.data(), s.size());       \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_set(                             \
      google::protobuf::RepeatedPtrField<std::string>* r, size_t index,          \
      google::protobuf::rust_internal::PtrAndLen val) {                          \
    *r->Mutable(index) = std::string(val.ptr, val.len);                \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_copy_from(                       \
      const google::protobuf::RepeatedPtrField<std::string>* src,                \
      google::protobuf::RepeatedPtrField<std::string>* dst) {                    \
    dst->CopyFrom(*src);                                               \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_clear(                           \
      google::protobuf::RepeatedPtrField<std::string>* r) {                      \
    r->Clear();                                                        \
  }                                                                    \
  void __pb_rust_RepeatedField_##ty##_reserve(                         \
      google::protobuf::RepeatedPtrField<std::string>* r, size_t additional) {   \
    r->Reserve(r->size() + additional);                                \
  }

expose_repeated_ptr_field_methods(ProtoString);
expose_repeated_ptr_field_methods(ProtoBytes);
#undef expose_repeated_field_methods

#undef expose_repeated_ptr_field_methods

}  // extern "C"
