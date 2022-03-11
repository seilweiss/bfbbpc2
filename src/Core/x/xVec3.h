#pragma once

#include "xMath.h"

struct xVec3
{
	float32 x;
	float32 y;
	float32 z;

	static const xVec3 m_Null;
	static const xVec3 m_UnitAxisX;
	static const xVec3 m_UnitAxisY;

	xVec3& assign(float32 x, float32 y, float32 z) WIP { this->x = x; this->y = y; this->z = z; return *this; }
	xVec3& assign(float32 f) WIP { assign(f, f, f); return *this; }
	xVec3& operator+=(const xVec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	xVec3 operator+(const xVec3& v) const { xVec3 temp = *this; temp += v; return temp; }
	xVec3& operator+=(float32 f) WIP { x += f; y += f; z += f; return *this; }
	xVec3 operator+(float32 f) const WIP { xVec3 temp = *this; temp += f; return temp; }
	xVec3& operator-=(const xVec3& v) WIP { x -= v.x; y -= v.y; z -= v.z; return *this; }
	xVec3 operator-(const xVec3& v) const WIP { xVec3 temp = *this; temp -= v; return temp; }
	xVec3& operator-=(float32 f) WIP { x -= f; y -= f; z -= f; return *this; }
	xVec3 operator-(float32 f) const WIP { xVec3 temp = *this; temp -= f; return temp; }
	xVec3& operator*=(const xVec3& v) WIP { x *= v.x; y *= v.y; z *= v.z; return *this; }
	xVec3 operator*(const xVec3& v) const WIP { xVec3 temp = *this; temp *= v; return temp; }
	xVec3& operator*=(float32 f) WIP { x *= f; y *= f; z *= f; return *this; }
	xVec3 operator*(float32 f) const WIP { xVec3 temp = *this; temp *= f; return temp; }
	xVec3& operator/=(float32 f) WIP { x = 1.0f / f; y = 1.0f / f; z = 1.0f / f; return *this; }
	xVec3 operator/(float32 f) const { xVec3 temp = *this; temp /= f; return temp; }
	xVec3& operator=(const xVec3& v) WIP { x = v.x; y = v.y; z = v.z; return *this; }
	xVec3& operator=(float32 f) WIP { x = f; y = f; z = f; return *this; }
	xVec3 operator-() const WIP { xVec3 v = *this; v.x = -v.x; v.y = -v.y; v.z = -v.z; return v; }
	xVec3 cross(const xVec3& c) const { xVec3 v = {}; v.x = y * c.z - c.y * z; v.y = z * c.x - c.z * x; v.z = x * c.y - c.x * y; return v; }
	float32 dot(const xVec3& c) const { return x * c.x + y * c.y + z * c.z; }
	float32 length() const WIP { return xsqrt(length2()); }
	float32 length2() const WIP { return xsqr(x) + xsqr(y) + xsqr(z); }
	xVec3& invert() WIP { x = -x; y = -y; z = -z; return *this; }
	xVec3 inverse() const WIP { xVec3 v = *this; v.invert(); return v; }
	xVec3& normalize() { *this /= length(); return *this; }
	xVec3 normal() const WIP { xVec3 v = *this; v.normalize(); return v; }
	xVec3& safe_normalize(const xVec3& c) WIP { float32 len2 = length2(); if (len2 < 0.0001f) return (*this = c); else return (*this *= 1.0f / xsqrt(len2)); }
	xVec3 safe_normal(const xVec3& c) const WIP { xVec3 v = *this; v.safe_normalize(c); return v; }
	xVec3& right_normalize() WIP { safe_normalize(m_UnitAxisX); return *this; }
	xVec3& up_normalize() WIP { safe_normalize(m_UnitAxisX); return *this; }
	xVec3 up_normal() const WIP { return safe_normal(m_UnitAxisY); }
	xVec3& set_abs() { x = xabs(x); y = xabs(y); z = xabs(z); return *this; }
	xVec3 get_abs() const { xVec3 v = *this; return v.set_abs(); }
	
	static xVec3 create(float32 x, float32 y, float32 z) WIP { xVec3 v = { x, y, z }; return v; }
	static xVec3 create(float32 f) WIP { xVec3 v = { f, f, f }; return v; }
};

float32 xVec3Normalize(xVec3* o, const xVec3* v);
float32 xVec3NormalizeFast(xVec3* o, const xVec3* v);

#include "xVec3Inlines.h"