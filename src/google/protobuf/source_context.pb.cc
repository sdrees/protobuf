// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/source_context.proto
// Protobuf C++ Version: 5.30.0-dev

#include "google/protobuf/source_context.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace google {
namespace protobuf {

inline constexpr SourceContext::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        file_name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()) {}

template <typename>
PROTOBUF_CONSTEXPR SourceContext::SourceContext(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(SourceContext_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct SourceContextDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SourceContextDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SourceContextDefaultTypeInternal() {}
  union {
    SourceContext _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SourceContextDefaultTypeInternal _SourceContext_default_instance_;
}  // namespace protobuf
}  // namespace google
static constexpr const ::_pb::EnumDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_enum_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor *PROTOBUF_NONNULL *PROTOBUF_NULLABLE
    file_level_service_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::google::protobuf::SourceContext, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::google::protobuf::SourceContext, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::google::protobuf::SourceContext, _impl_.file_name_),
        0,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 9, -1, sizeof(::google::protobuf::SourceContext)},
};
static const ::_pb::Message* PROTOBUF_NONNULL const file_default_instances[] = {
    &::google::protobuf::_SourceContext_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2fsource_5fcontext_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n$google/protobuf/source_context.proto\022\017"
    "google.protobuf\"\"\n\rSourceContext\022\021\n\tfile"
    "_name\030\001 \001(\tB\212\001\n\023com.google.protobufB\022Sou"
    "rceContextProtoP\001Z6google.golang.org/pro"
    "tobuf/types/known/sourcecontextpb\242\002\003GPB\252"
    "\002\036Google.Protobuf.WellKnownTypesb\006proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto = {
    false,
    false,
    240,
    descriptor_table_protodef_google_2fprotobuf_2fsource_5fcontext_2eproto,
    "google/protobuf/source_context.proto",
    &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2fsource_5fcontext_2eproto::offsets,
    file_level_enum_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2fsource_5fcontext_2eproto,
};
namespace google {
namespace protobuf {
// ===================================================================

class SourceContext::_Internal {
 public:
  using HasBits =
      decltype(std::declval<SourceContext>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(SourceContext, _impl_._has_bits_);
};

SourceContext::SourceContext(::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, SourceContext_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.protobuf.SourceContext)
}
PROTOBUF_NDEBUG_INLINE SourceContext::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena, const Impl_& from,
    const ::google::protobuf::SourceContext& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        file_name_(arena, from.file_name_) {}

SourceContext::SourceContext(
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena,
    const SourceContext& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, SourceContext_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SourceContext* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:google.protobuf.SourceContext)
}
PROTOBUF_NDEBUG_INLINE SourceContext::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
      : _cached_size_{0},
        file_name_(arena) {}

inline void SourceContext::SharedCtor(::_pb::Arena* PROTOBUF_NULLABLE arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
SourceContext::~SourceContext() {
  // @@protoc_insertion_point(destructor:google.protobuf.SourceContext)
  SharedDtor(*this);
}
inline void SourceContext::SharedDtor(MessageLite& self) {
  SourceContext& this_ = static_cast<SourceContext&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.file_name_.Destroy();
  this_._impl_.~Impl_();
}

inline void* PROTOBUF_NONNULL SourceContext::PlacementNew_(
    const void* PROTOBUF_NONNULL, void* PROTOBUF_NONNULL mem,
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena) {
  return ::new (mem) SourceContext(arena);
}
constexpr auto SourceContext::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(SourceContext),
                                            alignof(SourceContext));
}
constexpr auto SourceContext::InternalGenerateClassData_() {
  return ::google::protobuf::internal::ClassDataFull{
      ::google::protobuf::internal::ClassData{
          &_SourceContext_default_instance_._instance,
          &_table_.header,
          nullptr,  // OnDemandRegisterArenaDtor
          nullptr,  // IsInitialized
          &SourceContext::MergeImpl,
          ::google::protobuf::Message::GetNewImpl<SourceContext>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
          &SourceContext::SharedDtor,
          ::google::protobuf::Message::GetClearImpl<SourceContext>(), &SourceContext::ByteSizeLong,
              &SourceContext::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
          PROTOBUF_FIELD_OFFSET(SourceContext, _impl_._cached_size_),
          false,
      },
      &SourceContext::kDescriptorMethods,
      &descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto,
      nullptr,  // tracker
  };
}

PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 const ::google::protobuf::internal::ClassDataFull
        SourceContext_class_data_ =
            SourceContext::InternalGenerateClassData_();

const ::google::protobuf::internal::ClassData* PROTOBUF_NONNULL SourceContext::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&SourceContext_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(SourceContext_class_data_.tc_table);
  return SourceContext_class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 47, 2>
SourceContext::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(SourceContext, _impl_._has_bits_),
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    SourceContext_class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::protobuf::SourceContext>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string file_name = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(SourceContext, _impl_.file_name_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string file_name = 1;
    {PROTOBUF_FIELD_OFFSET(SourceContext, _impl_.file_name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\35\11\0\0\0\0\0\0"
    "google.protobuf.SourceContext"
    "file_name"
  }},
};
PROTOBUF_NOINLINE void SourceContext::Clear() {
// @@protoc_insertion_point(message_clear_start:google.protobuf.SourceContext)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.file_name_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::uint8_t* PROTOBUF_NONNULL SourceContext::_InternalSerialize(
    const ::google::protobuf::MessageLite& base, ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) {
  const SourceContext& this_ = static_cast<const SourceContext&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::uint8_t* PROTOBUF_NONNULL SourceContext::_InternalSerialize(
    ::uint8_t* PROTOBUF_NONNULL target,
    ::google::protobuf::io::EpsCopyOutputStream* PROTOBUF_NONNULL stream) const {
  const SourceContext& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.SourceContext)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string file_name = 1;
  if ((this_._impl_._has_bits_[0] & 0x00000001u) != 0) {
    if (!this_._internal_file_name().empty()) {
      const std::string& _s = this_._internal_file_name();
      ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
          _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "google.protobuf.SourceContext.file_name");
      target = stream->WriteStringMaybeAliased(1, _s, target);
    }
  }

  if (ABSL_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.protobuf.SourceContext)
  return target;
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
::size_t SourceContext::ByteSizeLong(const MessageLite& base) {
  const SourceContext& this_ = static_cast<const SourceContext&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
::size_t SourceContext::ByteSizeLong() const {
  const SourceContext& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(message_byte_size_start:google.protobuf.SourceContext)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void)cached_has_bits;

   {
    // string file_name = 1;
    cached_has_bits = this_._impl_._has_bits_[0];
    if (cached_has_bits & 0x00000001u) {
      if (!this_._internal_file_name().empty()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                        this_._internal_file_name());
      }
    }
  }
  return this_.MaybeComputeUnknownFieldsSize(total_size,
                                             &this_._impl_._cached_size_);
}

void SourceContext::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<SourceContext*>(&to_msg);
  auto& from = static_cast<const SourceContext&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.protobuf.SourceContext)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    if (!from._internal_file_name().empty()) {
      _this->_internal_set_file_name(from._internal_file_name());
    } else {
      if (_this->_impl_.file_name_.IsDefault()) {
        _this->_internal_set_file_name("");
      }
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void SourceContext::CopyFrom(const SourceContext& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.protobuf.SourceContext)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void SourceContext::InternalSwap(SourceContext* PROTOBUF_RESTRICT PROTOBUF_NONNULL other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.file_name_, &other->_impl_.file_name_, arena);
}

::google::protobuf::Metadata SourceContext::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ [[maybe_unused]] =
        (::_pbi::AddDescriptors(&descriptor_table_google_2fprotobuf_2fsource_5fcontext_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
