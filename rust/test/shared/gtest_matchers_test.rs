// Protocol Buffers - Google's data interchange format
// Copyright 2024 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

google3::import! {
  "//third_party/protobuf/rust:protobuf_gtest_matchers";
}

use googletest::prelude::*;
use paste::paste;
use protobuf_gtest_matchers::proto_eq;
use unittest_proto3_rust_proto::TestAllTypes as TestAllTypesProto3;
use unittest_rust_proto::TestAllTypes;

macro_rules! generate_eq_msgs_tests {
  ($(($type: ident, $name_ext: ident)),*) => {
        paste! {$(
            #[gtest]
            fn [<expect_eq_msgs_ $name_ext>]() {
              let mut msg = [< $type >]::new();
              let mut msg2 = [< $type >]::new();
              msg.set_optional_int32(1);
              msg2.set_optional_int32(1);
              assert_that!(&msg.as_view(), proto_eq(msg2.as_view()));
              assert_that!(&msg.as_mut(), proto_eq(msg2.as_mut()));
              assert_that!(msg, proto_eq(msg2));
            }
        )*}
    }
}

macro_rules! generate_not_eq_msgs_tests {
  ($(($type: ident, $name_ext: ident)),*) => {
        paste! {$(
            #[gtest]
            fn [<expect_not_eq_msgs_ $name_ext>]() {
                let mut msg = [< $type >]::new();
                let mut msg2 = [< $type >]::new();
                msg.set_optional_int32(1);
                msg2.set_optional_int32(0);
                assert_that!(&msg.as_view(), not(proto_eq(msg2.as_view())));
                assert_that!(&msg.as_mut(), not(proto_eq(msg2.as_mut())));
                assert_that!(&msg, not(proto_eq(msg2)));
            }
        )*}
    }
}

generate_eq_msgs_tests!((TestAllTypes, editions), (TestAllTypesProto3, proto3));

generate_not_eq_msgs_tests!((TestAllTypes, editions), (TestAllTypesProto3, proto3));
