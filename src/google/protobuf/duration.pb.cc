// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/duration.proto
// Protobuf C++ Version: 5.27.0-dev

#include "google/protobuf/duration.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
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

inline constexpr Duration::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : seconds_{::int64_t{0}},
        nanos_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Duration::Duration(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct DurationDefaultTypeInternal {
  PROTOBUF_CONSTEXPR DurationDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~DurationDefaultTypeInternal() {}
  union {
    Duration _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 DurationDefaultTypeInternal _Duration_default_instance_;
}  // namespace protobuf
}  // namespace google
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_google_2fprotobuf_2fduration_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_google_2fprotobuf_2fduration_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2fduration_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Duration, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Duration, _impl_.seconds_),
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Duration, _impl_.nanos_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::google::protobuf::Duration)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::google::protobuf::_Duration_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2fduration_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\036google/protobuf/duration.proto\022\017google"
    ".protobuf\"*\n\010Duration\022\017\n\007seconds\030\001 \001(\003\022\r"
    "\n\005nanos\030\002 \001(\005B\203\001\n\023com.google.protobufB\rD"
    "urationProtoP\001Z1google.golang.org/protob"
    "uf/types/known/durationpb\370\001\001\242\002\003GPB\252\002\036Goo"
    "gle.Protobuf.WellKnownTypesb\006proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2fduration_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2fduration_2eproto = {
    false,
    false,
    235,
    descriptor_table_protodef_google_2fprotobuf_2fduration_2eproto,
    "google/protobuf/duration.proto",
    &descriptor_table_google_2fprotobuf_2fduration_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2fduration_2eproto::offsets,
    file_level_enum_descriptors_google_2fprotobuf_2fduration_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2fduration_2eproto,
};
namespace google {
namespace protobuf {
// ===================================================================

class Duration::_Internal {
 public:
};

Duration::Duration(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.protobuf.Duration)
}
Duration::Duration(
    ::google::protobuf::Arena* arena, const Duration& from)
    : Duration(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE Duration::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void Duration::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, seconds_),
           0,
           offsetof(Impl_, nanos_) -
               offsetof(Impl_, seconds_) +
               sizeof(Impl_::nanos_));
}
Duration::~Duration() {
  // @@protoc_insertion_point(destructor:google.protobuf.Duration)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Duration::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Duration::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Duration, _impl_._cached_size_),
              false,
          },
          &Duration::MergeImpl,
          &Duration::kDescriptorMethods,
          &descriptor_table_google_2fprotobuf_2fduration_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> Duration::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Duration_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::protobuf::Duration>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int32 nanos = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Duration, _impl_.nanos_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(Duration, _impl_.nanos_)}},
    // int64 seconds = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Duration, _impl_.seconds_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(Duration, _impl_.seconds_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 seconds = 1;
    {PROTOBUF_FIELD_OFFSET(Duration, _impl_.seconds_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // int32 nanos = 2;
    {PROTOBUF_FIELD_OFFSET(Duration, _impl_.nanos_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void Duration::Clear() {
// @@protoc_insertion_point(message_clear_start:google.protobuf.Duration)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.seconds_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.nanos_) -
      reinterpret_cast<char*>(&_impl_.seconds_)) + sizeof(_impl_.nanos_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Duration::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.Duration)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int64 seconds = 1;
  if (this->_internal_seconds() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt64ToArrayWithField<1>(
            stream, this->_internal_seconds(), target);
  }

  // int32 nanos = 2;
  if (this->_internal_nanos() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_nanos(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.protobuf.Duration)
  return target;
}

::size_t Duration::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:google.protobuf.Duration)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // int64 seconds = 1;
  if (this->_internal_seconds() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
        this->_internal_seconds());
  }

  // int32 nanos = 2;
  if (this->_internal_nanos() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_nanos());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Duration::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Duration*>(&to_msg);
  auto& from = static_cast<const Duration&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.protobuf.Duration)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_seconds() != 0) {
    _this->_impl_.seconds_ = from._impl_.seconds_;
  }
  if (from._internal_nanos() != 0) {
    _this->_impl_.nanos_ = from._impl_.nanos_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Duration::CopyFrom(const Duration& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.protobuf.Duration)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Duration::IsInitialized() const {
  return true;
}

void Duration::InternalSwap(Duration* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Duration, _impl_.nanos_)
      + sizeof(Duration::_impl_.nanos_)
      - PROTOBUF_FIELD_OFFSET(Duration, _impl_.seconds_)>(
          reinterpret_cast<char*>(&_impl_.seconds_),
          reinterpret_cast<char*>(&other->_impl_.seconds_));
}

::google::protobuf::Metadata Duration::GetMetadata() const {
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
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_google_2fprotobuf_2fduration_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
