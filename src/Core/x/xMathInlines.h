#pragma once

#include <types.h>

inline float32 xatan2(float32 y, float32 x) STUB
inline float32 xasin(float32 x) STUB
inline float32 xacos(float32) STUB
inline float32 xsqrt(float32 x) STUB
inline void xsqrtfast(float32&, float32) STUB_VOID
inline float32 xexp(float32) STUB
inline float32 xlog(float32) STUB
inline float32 xpow(float32 x, float32 y) STUB;

template <class T> inline T range_limit(T v, T minv, T maxv) STUB