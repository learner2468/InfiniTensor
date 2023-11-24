#pragma once
#ifndef OPERATOR_UTIL_H
#define OPERATOR_UTIL_H

#include "core/tensor.h"

namespace infini {

// Launch a broadcast shape based on the shape of input A and B
Shape infer_broadcast(const Shape &A, const Shape &B);
// Launch the real axis based on rank and current axis
int get_real_axis(const int &axis, const int &rank);
// check if tensor B is unidirectional broadcastable to tensor A
bool is_unidirectional_broadcasting(const Shape &A, const Shape &B);
} // namespace infini

#endif
