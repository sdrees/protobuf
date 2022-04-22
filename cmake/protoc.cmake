set(protoc_files
  ${protobuf_SOURCE_DIR}/src/google/protobuf/compiler/main.cc
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
set(protoc_rc_files
  ${CMAKE_CURRENT_BINARY_DIR}/version.rc
)
endif()

add_executable(protoc ${protoc_files} ${protoc_rc_files})
target_link_libraries(protoc
  libprotoc
  libprotobuf
  ${protobuf_ABSL_USED_TARGETS}
)
add_executable(protobuf::protoc ALIAS protoc)

set_target_properties(protoc PROPERTIES
    VERSION ${protobuf_VERSION})
