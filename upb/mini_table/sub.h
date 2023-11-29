// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef UPB_MINI_TABLE_SUB_H_
#define UPB_MINI_TABLE_SUB_H_

#include "upb/mini_table/internal/sub.h"

// Must be last.
#include "upb/port/def.inc"

typedef union upb_MiniTableSub upb_MiniTableSub;

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

UPB_API_INLINE upb_MiniTableSub
upb_MiniTableSub_FromEnum(const struct upb_MiniTableEnum* subenum) {
  return UPB_PRIVATE(_upb_MiniTableSub_FromEnum)(subenum);
}

UPB_API_INLINE upb_MiniTableSub
upb_MiniTableSub_FromMessage(const struct upb_MiniTable* submsg) {
  return UPB_PRIVATE(_upb_MiniTableSub_FromMessage)(submsg);
}

// Getters

UPB_API_INLINE const struct upb_MiniTableEnum* upb_MiniTableSub_Enum(
    upb_MiniTableSub sub) {
  return UPB_PRIVATE(_upb_MiniTableSub_Enum)(sub);
}

UPB_API_INLINE const struct upb_MiniTable* upb_MiniTableSub_Message(
    upb_MiniTableSub sub) {
  return UPB_PRIVATE(_upb_MiniTableSub_Message)(sub);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif /* UPB_MINI_TABLE_SUB_H_ */
