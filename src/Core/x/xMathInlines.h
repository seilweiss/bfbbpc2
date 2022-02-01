#pragma once

#define xsqr(x) ((x) * (x))

#define xabs(x) iabs(x)

#define xmax(a, b) (((a) > (b)) ? (a) : (b))
#define xmin(a, b) (((a) < (b)) ? (a) : (b))
#define xclamp(x, a, b) (xmax((a), xmin((x), (b))))

#define EPSILON 0.00001f
#define xapproxeq(a, b) (xabs((a) - (b)) <= (EPSILON))

inline float32 xatan2(float32 y, float32 x)
{
	return xAngleClampFast(std::atan2f(y, x));
}

inline float32 xasin(float32 x) STUB
inline float32 xacos(float32) STUB

inline float32 xsqrt(float32 x) WIP
{
	return std::sqrtf(x);
}

inline void xsqrtfast(float32&, float32) STUB_VOID
inline float32 xexp(float32) STUB
inline float32 xlog(float32) STUB
inline float32 xpow(float32 x, float32 y) STUB;

template <class T> inline T range_limit(T v, T minv, T maxv) STUB