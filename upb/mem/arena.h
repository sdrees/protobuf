// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

/* upb_Arena is a specific allocator implementation that uses arena allocation.
 * The user provides an allocator that will be used to allocate the underlying
 * arena blocks.  Arenas by nature do not require the individual allocations
 * to be freed.  However the Arena does allow users to register cleanup
 * functions that will run when the arena is destroyed.
 *
 * A upb_Arena is *not* thread-safe.
 *
 * You could write a thread-safe arena allocator that satisfies the
 * upb_alloc interface, but it would not be as efficient for the
 * single-threaded case. */

#ifndef UPB_MEM_ARENA_H_
#define UPB_MEM_ARENA_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "upb/mem/alloc.h"

// Must be last.
#include "upb/port/def.inc"

typedef struct upb_Arena upb_Arena;

// LINT.IfChange(struct_definition)
typedef struct {
  char* UPB_ONLYBITS(ptr);
  char* UPB_ONLYBITS(end);
} _upb_ArenaHead;
// LINT.ThenChange(//depot/google3/third_party/upb/bits/typescript/arena.ts)

#ifdef __cplusplus
extern "C" {
#endif

// Creates an arena from the given initial block (if any -- n may be 0).
// Additional blocks will be allocated from |alloc|.  If |alloc| is NULL, this
// is a fixed-size arena and cannot grow.
UPB_API upb_Arena* upb_Arena_Init(void* mem, size_t n, upb_alloc* alloc);

UPB_API void upb_Arena_Free(upb_Arena* a);
UPB_API bool upb_Arena_Fuse(upb_Arena* a, upb_Arena* b);

bool upb_Arena_IncRefFor(upb_Arena* a, const void* owner);
void upb_Arena_DecRefFor(upb_Arena* a, const void* owner);

void* UPB_PRIVATE(_upb_Arena_SlowMalloc)(upb_Arena* a, size_t size);

size_t upb_Arena_SpaceAllocated(upb_Arena* a);
uint32_t upb_Arena_DebugRefCount(upb_Arena* a);

UPB_INLINE size_t UPB_PRIVATE(_upb_ArenaHas)(upb_Arena* a) {
  const _upb_ArenaHead* h = (_upb_ArenaHead*)a;
  return (size_t)(h->UPB_ONLYBITS(end) - h->UPB_ONLYBITS(ptr));
}

UPB_API_INLINE void* upb_Arena_Malloc(upb_Arena* a, size_t size) {
  size = UPB_ALIGN_MALLOC(size);
  const size_t span = size + UPB_ASAN_GUARD_SIZE;
  if (UPB_UNLIKELY(UPB_PRIVATE(_upb_ArenaHas)(a) < span)) {
    return UPB_PRIVATE(_upb_Arena_SlowMalloc)(a, span);
  }

  // We have enough space to do a fast malloc.
  _upb_ArenaHead* h = (_upb_ArenaHead*)a;
  void* ret = h->UPB_ONLYBITS(ptr);
  UPB_ASSERT(UPB_ALIGN_MALLOC((uintptr_t)ret) == (uintptr_t)ret);
  UPB_ASSERT(UPB_ALIGN_MALLOC(size) == size);
  UPB_UNPOISON_MEMORY_REGION(ret, size);

  h->UPB_ONLYBITS(ptr) += span;

  return ret;
}

// Shrinks the last alloc from arena.
// REQUIRES: (ptr, oldsize) was the last malloc/realloc from this arena.
// We could also add a upb_Arena_TryShrinkLast() which is simply a no-op if
// this was not the last alloc.
UPB_API_INLINE void upb_Arena_ShrinkLast(upb_Arena* a, void* ptr,
                                         size_t oldsize, size_t size) {
  _upb_ArenaHead* h = (_upb_ArenaHead*)a;
  oldsize = UPB_ALIGN_MALLOC(oldsize);
  size = UPB_ALIGN_MALLOC(size);
  // Must be the last alloc.
  UPB_ASSERT((char*)ptr + oldsize ==
             h->UPB_ONLYBITS(ptr) - UPB_ASAN_GUARD_SIZE);
  UPB_ASSERT(size <= oldsize);
  h->UPB_ONLYBITS(ptr) = (char*)ptr + size;
}

UPB_API_INLINE void* upb_Arena_Realloc(upb_Arena* a, void* ptr, size_t oldsize,
                                       size_t size) {
  _upb_ArenaHead* h = (_upb_ArenaHead*)a;
  oldsize = UPB_ALIGN_MALLOC(oldsize);
  size = UPB_ALIGN_MALLOC(size);
  bool is_most_recent_alloc =
      (uintptr_t)ptr + oldsize == (uintptr_t)h->UPB_ONLYBITS(ptr);

  if (is_most_recent_alloc) {
    ptrdiff_t diff = size - oldsize;
    if ((ptrdiff_t)UPB_PRIVATE(_upb_ArenaHas)(a) >= diff) {
      h->UPB_ONLYBITS(ptr) += diff;
      return ptr;
    }
  } else if (size <= oldsize) {
    return ptr;
  }

  void* ret = upb_Arena_Malloc(a, size);

  if (ret && oldsize > 0) {
    memcpy(ret, ptr, UPB_MIN(oldsize, size));
  }

  return ret;
}

UPB_API_INLINE upb_Arena* upb_Arena_New(void) {
  return upb_Arena_Init(NULL, 0, &upb_alloc_global);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif /* UPB_MEM_ARENA_H_ */
