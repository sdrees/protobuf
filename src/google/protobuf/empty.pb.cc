// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/protobuf/empty.proto
// Protobuf C++ Version: 5.30.0-dev

#include "google/protobuf/empty.pb.h"

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
template <typename>
PROTOBUF_CONSTEXPR Empty::Empty(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::internal::ZeroFieldsBase(Empty_class_data_.base()){}
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::internal::ZeroFieldsBase() {
}
#endif  // PROTOBUF_CUSTOM_VTABLE
struct EmptyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR EmptyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~EmptyDefaultTypeInternal() {}
  union {
    Empty _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 EmptyDefaultTypeInternal _Empty_default_instance_;
}  // namespace protobuf
}  // namespace google
static constexpr const ::_pb::EnumDescriptor** PROTOBUF_NULLABLE
    file_level_enum_descriptors_google_2fprotobuf_2fempty_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor** PROTOBUF_NULLABLE
    file_level_service_descriptors_google_2fprotobuf_2fempty_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2fempty_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::google::protobuf::Empty, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::google::protobuf::Empty)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::google::protobuf::_Empty_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2fempty_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\033google/protobuf/empty.proto\022\017google.pr"
    "otobuf\"\007\n\005EmptyB}\n\023com.google.protobufB\n"
    "EmptyProtoP\001Z.google.golang.org/protobuf"
    "/types/known/emptypb\370\001\001\242\002\003GPB\252\002\036Google.P"
    "rotobuf.WellKnownTypesb\006proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2fempty_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2fempty_2eproto = {
    false,
    false,
    190,
    descriptor_table_protodef_google_2fprotobuf_2fempty_2eproto,
    "google/protobuf/empty.proto",
    &descriptor_table_google_2fprotobuf_2fempty_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2fempty_2eproto::offsets,
    file_level_enum_descriptors_google_2fprotobuf_2fempty_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2fempty_2eproto,
};
namespace google {
namespace protobuf {
// ===================================================================

class Empty::_Internal {
 public:
};

Empty::Empty(::google::protobuf::Arena* PROTOBUF_NULLABLE arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::internal::ZeroFieldsBase(arena, Empty_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::internal::ZeroFieldsBase(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  // @@protoc_insertion_point(arena_constructor:google.protobuf.Empty)
}
Empty::Empty(
    ::google::protobuf::Arena* PROTOBUF_NULLABLE arena,
    const Empty& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::internal::ZeroFieldsBase(arena, Empty_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::internal::ZeroFieldsBase(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Empty* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);

  // @@protoc_insertion_point(copy_constructor:google.protobuf.Empty)
}

inline void* Empty::PlacementNew_(
    const void*, void* mem, ::google::protobuf::Arena* PROTOBUF_NULLABLE arena) {
  return ::new (mem) Empty(arena);
}
constexpr auto Empty::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(Empty),
                                            alignof(Empty));
}
constexpr auto Empty::InternalGenerateClassData_() {
  return ::google::protobuf::internal::ClassDataFull{
      ::google::protobuf::internal::ClassData{
          &_Empty_default_instance_._instance,
          &_table_.header,
          nullptr,  // OnDemandRegisterArenaDtor
          nullptr,  // IsInitialized
          &Empty::MergeImpl,
          ::google::protobuf::internal::ZeroFieldsBase::GetNewImpl<Empty>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
          &Empty::SharedDtor,
          ::google::protobuf::internal::ZeroFieldsBase::GetClearImpl<Empty>(), &Empty::ByteSizeLong,
              &Empty::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
          PROTOBUF_FIELD_OFFSET(Empty, _impl_._cached_size_),
          false,
      },
      &Empty::kDescriptorMethods,
      &descriptor_table_google_2fprotobuf_2fempty_2eproto,
      nullptr,  // tracker
  };
}

PROTOBUF_CONSTINIT PROTOBUF_EXPORT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 const ::google::protobuf::internal::ClassDataFull
        Empty_class_data_ =
            Empty::InternalGenerateClassData_();

const ::google::protobuf::internal::ClassData* Empty::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&Empty_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(Empty_class_data_.tc_table);
  return Empty_class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 0, 0, 0, 2> Empty::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    0, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967295,  // skipmap
    offsetof(decltype(_table_), field_names),  // no field_entries
    0,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    Empty_class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::protobuf::Empty>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }},
  // no field_entries, or aux_entries
  {{
  }},
};








::google::protobuf::Metadata Empty::GetMetadata() const {
  return ::google::protobuf::internal::ZeroFieldsBase::GetMetadataImpl(GetClassData()->full());
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
        (::_pbi::AddDescriptors(&descriptor_table_google_2fprotobuf_2fempty_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
