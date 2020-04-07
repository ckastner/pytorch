#pragma once

// Unify index_* and scatter/gather implementations.
//   Currently very much in the prototype stage.

#include <string>

#include <ATen/ATen.h>
#include <ATen/native/DispatchStub.h>

namespace at { namespace native {

// stub out implementations individually, even if it ends up being very verbose.
using debug_index_fn = void (*)(Tensor & result, const Tensor & self, const Tensor & index);

Tensor debug_index(const Tensor& self, int64_t dim, const Tensor& ind, std::string impl = "");

DECLARE_DISPATCH(debug_index_fn, index_select_memcpy_dim0_numel_outer_kernel_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_ptr_assign_dim0_kernel_true_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_ptr_assign_dim0_kernel_false_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_memcpy_dim1_kernel_true_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_memcpy_dim1_kernel_false_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_ptr_assign_dim1_kernel_true_stub);
DECLARE_DISPATCH(debug_index_fn, index_select_ptr_assign_dim1_kernel_false_stub);

}} // namespace at::native
