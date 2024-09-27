// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/source_context.proto
// Protobuf C++ Version: 5.29.0-dev

#ifndef google_2fprotobuf_2fsource_5fcontext_2eproto_2epb_2eh
#define google_2fprotobuf_2fsource_5fcontext_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2fsource_5fcontext_2eproto PROTOBUF_EXPORT

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct PROTOBUF_EXPORT TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto {
  static const ::uint32_t offsets[];
};
PROTOBUF_EXPORT extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto;
namespace google {
namespace protobuf {
class SourceContext;
struct SourceContextDefaultTypeInternal;
PROTOBUF_EXPORT extern SourceContextDefaultTypeInternal _SourceContext_default_instance_;
}  // namespace protobuf
}  // namespace google

namespace google {
namespace protobuf {

// ===================================================================


// -------------------------------------------------------------------

class PROTOBUF_EXPORT SourceContext final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:google.protobuf.SourceContext) */ {
 public:
  inline SourceContext() : SourceContext(nullptr) {}
  ~SourceContext() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(SourceContext* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(SourceContext));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR SourceContext(
      ::google::protobuf::internal::ConstantInitialized);

  inline SourceContext(const SourceContext& from) : SourceContext(nullptr, from) {}
  inline SourceContext(SourceContext&& from) noexcept
      : SourceContext(nullptr, std::move(from)) {}
  inline SourceContext& operator=(const SourceContext& from) {
    CopyFrom(from);
    return *this;
  }
  inline SourceContext& operator=(SourceContext&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SourceContext& default_instance() {
    return *internal_default_instance();
  }
  static inline const SourceContext* internal_default_instance() {
    return reinterpret_cast<const SourceContext*>(
        &_SourceContext_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(SourceContext& a, SourceContext& b) { a.Swap(&b); }
  inline void Swap(SourceContext* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SourceContext* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SourceContext* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<SourceContext>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SourceContext& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const SourceContext& from) { SourceContext::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(SourceContext* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "google.protobuf.SourceContext"; }

 protected:
  explicit SourceContext(::google::protobuf::Arena* arena);
  SourceContext(::google::protobuf::Arena* arena, const SourceContext& from);
  SourceContext(::google::protobuf::Arena* arena, SourceContext&& from) noexcept
      : SourceContext(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kFileNameFieldNumber = 1,
  };
  // string file_name = 1;
  void clear_file_name() ;
  const std::string& file_name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_file_name(Arg_&& arg, Args_... args);
  std::string* mutable_file_name();
  PROTOBUF_NODISCARD std::string* release_file_name();
  void set_allocated_file_name(std::string* value);

  private:
  const std::string& _internal_file_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_file_name(
      const std::string& value);
  std::string* _internal_mutable_file_name();

  public:
  // @@protoc_insertion_point(class_scope:google.protobuf.SourceContext)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      47, 2>
      _table_;


  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const SourceContext& from_msg);
    ::google::protobuf::internal::ArenaStringPtr file_name_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// SourceContext

// string file_name = 1;
inline void SourceContext::clear_file_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.file_name_.ClearToEmpty();
}
inline const std::string& SourceContext::file_name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.SourceContext.file_name)
  return _internal_file_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void SourceContext::set_file_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.file_name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:google.protobuf.SourceContext.file_name)
}
inline std::string* SourceContext::mutable_file_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_file_name();
  // @@protoc_insertion_point(field_mutable:google.protobuf.SourceContext.file_name)
  return _s;
}
inline const std::string& SourceContext::_internal_file_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.file_name_.Get();
}
inline void SourceContext::_internal_set_file_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.file_name_.Set(value, GetArena());
}
inline std::string* SourceContext::_internal_mutable_file_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.file_name_.Mutable( GetArena());
}
inline std::string* SourceContext::release_file_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:google.protobuf.SourceContext.file_name)
  return _impl_.file_name_.Release();
}
inline void SourceContext::set_allocated_file_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.file_name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.file_name_.IsDefault()) {
    _impl_.file_name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.SourceContext.file_name)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace google


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // google_2fprotobuf_2fsource_5fcontext_2eproto_2epb_2eh
