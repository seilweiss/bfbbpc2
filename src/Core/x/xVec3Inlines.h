#pragma once

inline void xVec3Init(xVec3* v, float32 _x, float32 _y, float32 _z) STUB_VOID
inline void xVec3Copy(xVec3*, const xVec3*) STUB_VOID
inline float32 xVec3Length(const xVec3* v) STUB
inline float32 xVec3Length2(const xVec3* v) STUB
inline float32 xVec3LengthFast(float32, float32, float32) STUB
inline void xVec3Add(xVec3*, const xVec3*, const xVec3*) STUB_VOID
inline void xVec3AddTo(xVec3*, const xVec3*) STUB_VOID
inline void xVec3AddScaled(xVec3*, const xVec3*, float32) STUB_VOID
inline void xVec3Sub(xVec3* o, const xVec3* a, const xVec3* b) STUB_VOID
inline void xVec3SubFrom(xVec3*, const xVec3*) STUB_VOID
inline void xVec3SMul(xVec3* o, const xVec3* v, float32 s) STUB_VOID
inline void xVec3SMulBy(xVec3* v, float32 s) STUB_VOID
inline void xVec3Inv(xVec3* o, const xVec3* v) STUB_VOID
inline uint32 xVec3Equals(const xVec3*, const xVec3*) STUB
inline void xVec3Cross(xVec3*, const xVec3*, const xVec3*) STUB_VOID
inline float32 xVec3Dot(const xVec3*, const xVec3*) STUB
inline float32 xVec3Dist(const xVec3*, const xVec3*) STUB
inline float32 xVec3Dist2(const xVec3*, const xVec3*) STUB
inline float32 xVec3DistFast(const xVec3*, const xVec3*) STUB
inline float32 xVec3Hdng(xVec3*, const xVec3*, const xVec3*) STUB
inline void xVec3Lerp(xVec3*, const xVec3*, const xVec3*, float32) STUB_VOID