#pragma once

#include "xMath.h"

struct xVec2
{
	float32 x;
	float32 y;

	xVec2& assign(float32 x, float32 y) WIP { this->x = x; this->y = y; return *this; }
	xVec2& assign(float32 f) WIP { assign(f, f); return *this; }
	xVec2& operator=(const xVec2& v) WIP { x = v.x; y = v.y; return *this; }
	xVec2& operator=(float32 f) WIP { x = f; y = f; return *this; }
	xVec2& operator+=(const xVec2& v) WIP { x += v.x; y += v.y; return *this; }
	xVec2 operator+(const xVec2& v) const WIP { xVec2 temp = *this; temp += v; return temp; }
	xVec2& operator-=(const xVec2& v) { x -= v.x; y -= v.y; return *this; }
	xVec2 operator-(const xVec2& v) const { xVec2 temp = *this; temp -= v; return temp; }
	xVec2& operator*=(float32 f) WIP { x *= f; y *= f; return *this; }
	xVec2 operator*(float32 f) const WIP { xVec2 temp = *this; temp *= f; return temp; }
	xVec2& operator/=(float32 f) WIP { x /= f; y /= f; return *this; }
	xVec2 operator/(float32 f) const WIP { xVec2 temp = *this; temp /= f; return temp; }
	float32 dot(const xVec2& c) const WIP { return x * c.x + y * c.y; }
	float32 length() const WIP { return xsqrt(length2()); }
	float32 length2() const { return xsqr(x) + xsqr(y); }
	xVec2& normalize() WIP { *this /= length(); return *this; }
	xVec2 normal() const WIP { xVec2 v = *this; v.normalize(); return v; }

	static xVec2 create(float32 x, float32 y) WIP { xVec2 v = { x, y }; return v; }
};

template <class T> struct basic_rect
{
	T x;
	T y;
	T w;
	T h;

	basic_rect& operator|=(const basic_rect&) STUB_REF(basic_rect);
	basic_rect& assign(T _x, T _y, T _w, T _h) WIP { x = _x; y = _y; w = _w; h = _h; return *this; }
	basic_rect& move(T _x, T _y) WIP { x += _x; y += _y; return *this; }
	basic_rect& scale(T _x, T _y, T _w, T _h) WIP { x *= _x; y *= _y; w *= _w; h *= _h; return *this; }
	basic_rect& scale(T _x, T _y) WIP { scale(_x, _y, _x, _y); return *this; }
	basic_rect& scale(T s) WIP { scale(s, s, s, s); return *this; }
	basic_rect& expand(T _x, T _y, T _w, T _h) WIP { x -= _x; w += _w; y -= _y; h += _h; return *this; }
	basic_rect& expand(T f) WIP { expand(f, f, f, f); return *this; }
	basic_rect& contract(T _x, T _y, T _w, T _h) WIP { expand(_x, _y, _w, _h); return *this; }
	basic_rect& contract(T f) WIP { expand(-f); return *this; }
	basic_rect& set_bounds(T x1, T y1, T x2, T y2) WIP { x = x1; w = x2 - x1; y = y1; h = y2 - y1; return *this; }
	void get_bounds(T& x1, T& y1, T& x2, T& y2) const WIP { x1 = x; x2 = x + w; y1 = y; y2 = y + h; }
	void clip(basic_rect&, basic_rect&) STUB_VOID;
	bool empty() const WIP { return w <= 0 || h <= 0; }
};

inline void xVec2Init(xVec2*, float32, float32) STUB_VOID
inline float32 xVec2Dist(float32, float32, float32, float32) STUB
inline float32 xVec2Dot(const xVec2*, const xVec2*) STUB
inline float32 xVec2Length2(const xVec2*) STUB