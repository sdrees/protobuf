// Protocol Buffers - Google's data interchange format
// Copyright 2023 Google LLC.  All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

/// Repeated scalar fields are implemented around the runtime-specific
/// `RepeatedField` struct. `RepeatedField` stores an opaque pointer to the
/// runtime-specific representation of a repeated scalar (`upb_Array*` on upb,
/// and `RepeatedField<T>*` on cpp).
use std::marker::PhantomData;

use crate::{
    __internal::{Private, RawRepeatedField},
    __runtime::{RepeatedField, RepeatedFieldInner},
};

#[derive(Clone, Copy)]
pub struct RepeatedFieldRef<'a> {
    pub repeated_field: RawRepeatedField,
    pub _phantom: PhantomData<&'a mut ()>,
}

unsafe impl<'a> Send for RepeatedFieldRef<'a> {}
unsafe impl<'a> Sync for RepeatedFieldRef<'a> {}

#[derive(Clone, Copy)]
#[repr(transparent)]
pub struct RepeatedView<'a, T: ?Sized> {
    inner: RepeatedField<'a, T>,
}

impl<'msg, T: ?Sized> RepeatedView<'msg, T> {
    pub fn from_inner(_private: Private, inner: RepeatedFieldInner<'msg>) -> Self {
        Self { inner: RepeatedField::<'msg>::from_inner(_private, inner) }
    }
}

pub struct RepeatedFieldIter<'a, T> {
    inner: RepeatedField<'a, T>,
    current_index: usize,
}

impl<'a, T> std::fmt::Debug for RepeatedView<'a, T> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_tuple("RepeatedView").finish()
    }
}

#[repr(transparent)]
pub struct RepeatedMut<'a, T: ?Sized> {
    inner: RepeatedField<'a, T>,
}

impl<'msg, T: ?Sized> RepeatedMut<'msg, T> {
    pub fn from_inner(_private: Private, inner: RepeatedFieldInner<'msg>) -> Self {
        Self { inner: RepeatedField::from_inner(_private, inner) }
    }
}

impl<'a, T> std::ops::Deref for RepeatedMut<'a, T> {
    type Target = RepeatedView<'a, T>;
    fn deref(&self) -> &Self::Target {
        // SAFETY:
        //   - `Repeated{View,Mut}<'a, T>` are both `#[repr(transparent)]` over
        //     `RepeatedField<'a, T>`.
        //   - `RepeatedField` is a type alias for `NonNull`.
        unsafe { &*(self as *const Self as *const RepeatedView<'a, T>) }
    }
}

macro_rules! impl_repeated_primitives {
    ($($t:ty),*) => {
        $(
            impl<'a> RepeatedView<'a, $t> {
                pub fn len(&self) -> usize {
                    self.inner.len()
                }
                pub fn is_empty(&self) -> bool {
                    self.len() == 0
                }
                pub fn get(&self, index: usize) -> Option<$t> {
                    self.inner.get(index)
                }
            }

            impl<'a> RepeatedMut<'a, $t> {
                pub fn push(&mut self, val: $t) {
                    self.inner.push(val)
                }
                pub fn set(&mut self, index: usize, val: $t) {
                    self.inner.set(index, val)
                }
            }

            impl<'a> std::iter::Iterator for RepeatedFieldIter<'a, $t> {
                type Item = $t;
                fn next(&mut self) -> Option<Self::Item> {
                    let val = self.inner.get(self.current_index);
                    if val.is_some() {
                        self.current_index += 1;
                    }
                    val
                }
            }

            impl<'a> std::iter::IntoIterator for RepeatedView<'a, $t> {
                type Item = $t;
                type IntoIter = RepeatedFieldIter<'a, $t>;
                fn into_iter(self) -> Self::IntoIter {
                    RepeatedFieldIter { inner: self.inner, current_index: 0 }
                }
            }
        )*
    }
}

impl_repeated_primitives!(i32, u32, bool, f32, f64, i64, u64);
