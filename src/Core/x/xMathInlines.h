#pragma once

inline float32 xatan2(float32 y, float32 x)
{
	return xAngleClampFast(std::atan2f(y, x));
}

inline float32 xasin(float32 x)
{
	return std::asinf(x);
}

inline float32 xacos(float32 x)
{
	return std::acosf(x);
}

inline float32 xsqrt(float32 x) WIP
{
	return std::sqrtf(x);
}

inline void xsqrtfast(float32&, float32) STUB_VOID

inline float32 xexp(float32 x)
{
	return std::expf(x);
}

inline float32 xlog(float32 x)
{
    return std::logf(x);
}

inline float32 xpow(float32 x, float32 y) STUB;

template <class T> inline T range_limit(T v, T minv, T maxv)
{
    if (v <= minv)
    {
        return minv;
    }

    if (v >= maxv)
    {
        return maxv;
    }

    return v;
}