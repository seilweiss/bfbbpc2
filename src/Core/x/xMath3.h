#pragma once

#include "xVec3.h"

struct xVec4
{
	float32 x;
	float32 y;
	float32 z;
	float32 w;
};

struct xLine3
{
	xVec3 p1;
	xVec3 p2;
};

struct xSphere
{
	xVec3 center;
	float32 r;
};

struct xCylinder
{
	xVec3 center;
	float32 r;
	float32 h;
};

struct xCapsule
{
	xVec3 start;
	xVec3 end;
	float32 r;
};

struct xBox
{
	xVec3 upper;
	xVec3 lower;
};

struct xBBox
{
	xVec3 center;
	xBox box;
};

struct xMat3x3
{
	xVec3 right;
	int32 flags;
	xVec3 up;
	uint32 pad1;
	xVec3 at;
	uint32 pad2;
};

struct xMat4x3 : xMat3x3
{
	xVec3 pos;
	uint32 pad3;
};

struct xQuat
{
	xVec3 v;
	float32 s;
};

struct xRot
{
	xVec3 axis;
	float32 angle;
};

struct xRay3
{
	xVec3 origin;
	xVec3 dir;
	float32 min_t;
	float32 max_t;
	int32 flags;
};

struct xIsect
{
	uint32 flags;
	float32 penned;
	float32 contained;
	float32 lapped;
	xVec3 point;
	xVec3 norm;
	float32 dist;
};

void xMath3Init();
void xLine3VecDist2(const xVec3* p1, const xVec3* p2, const xVec3* v, xIsect* isx);
bool32 xPointInBox(const xBox* b, const xVec3* p);
void xBoxInitBoundOBB(xBox* o, const xBox* b, const xMat4x3* m);
void xBoxInitBoundCapsule(xBox* b, const xCapsule* c);
void xBoxFromCone(xBox& box, const xVec3& center, const xVec3& dir, float32 dist, float32 r1, float32 r2);
void xMat3x3Normalize(xMat3x3* o, const xMat3x3* m);
void xMat3x3GetEuler(const xMat3x3* m, xVec3* a);
void xMat4x3MoveLocalRight(xMat4x3* m, float32 mag);
void xMat4x3MoveLocalUp(xMat4x3* m, float32 mag);
void xMat4x3MoveLocalAt(xMat4x3* m, float32 mag);
float32 xMat3x3LookVec(xMat3x3* m, const xVec3* at);
void xMat3x3Euler(xMat3x3* m, const xVec3* ypr);
void xMat3x3Euler(xMat3x3* m, float32 yaw, float32 pitch, float32 roll);
void xMat3x3RotC(xMat3x3* m, float32 _x, float32 _y, float32 _z, float32 t);
void xMat3x3RotX(xMat3x3* m, float32 t);
void xMat3x3RotY(xMat3x3* m, float32 t);
void xMat3x3RotZ(xMat3x3* m, float32 t);
void xMat3x3ScaleC(xMat3x3* m, float32 x, float32 y, float32 z);
void xMat3x3RMulRotY(xMat3x3* o, const xMat3x3* m, float32 t);
void xMat3x3Transpose(xMat3x3* o, const xMat3x3* m);
void xMat3x3Mul(xMat3x3* o, const xMat3x3* a, const xMat3x3* b);
void xMat3x3LMulVec(xVec3* o, const xMat3x3* m, const xVec3* v);
void xMat3x3Tolocal(xVec3* o, const xMat3x3* m, const xVec3* v);
void xMat4x3Rot(xMat4x3* m, const xVec3* a, float32 t, const xVec3* p);
void xMat4x3Mul(xMat4x3* o, const xMat4x3* a, const xMat4x3* b);
void xQuatFromMat(xQuat* q, const xMat3x3* m);
void xQuatFromAxisAngle(xQuat* q, const xVec3* a, float32 t);
void xQuatToMat(const xQuat* q, xMat3x3* m);
void xQuatToAxisAngle(const xQuat* q, xVec3* a, float32* t);
float32 xQuatNormalize(xQuat* o, const xQuat* q);
void xQuatSlerp(xQuat* o, const xQuat* a, const xQuat* b, float32 t);
void xQuatMul(xQuat* o, const xQuat* a, const xQuat* b);
void xQuatDiff(xQuat* o, const xQuat* a, const xQuat* b);

inline void xBoxFromSphere(xBox&, const xSphere&) STUB_VOID
inline void xBoxFromLine(xBox& box, const xLine3& line) STUB_VOID
inline void xBoxFromCircle(xBox&, const xVec3&, const xVec3&, float32) STUB_VOID
inline void xBoxFromRay(xBox&, const xRay3&) STUB_VOID
inline void xBoxUnion(xBox&, const xBox&, const xBox&) STUB_VOID
inline void xMat3x3Copy(xMat3x3*, const xMat3x3*) STUB_VOID
inline void xMat3x3Identity(xMat3x3*) STUB_VOID
inline void xMat3x3Rot(xMat3x3* m, const xVec3* a, float32 t) STUB_VOID
inline void xMat3x3Scale(xMat3x3*, const xVec3*) STUB_VOID
inline void xMat3x3LookAt(xMat3x3*, const xVec3*, const xVec3*) STUB_VOID
inline float32 xMat3x3LookVec3(xMat3x3&, const xVec3&) STUB
inline void xMat3x3MulRotC(xMat3x3*, xMat3x3*, float32, float32, float32, float32) STUB_VOID
inline void xMat3x3SMul(xMat3x3*, const xMat3x3*, float32) STUB_VOID
static inline void xMat3x3RMulVec(xVec3* o, const xMat3x3* m, const xVec3* v) STUB_VOID
inline void xMat4x3Copy(xMat4x3*, const xMat4x3*) STUB_VOID
inline void xMat4x3Identity(xMat4x3*) STUB_VOID
inline void xMat4x3RotC(xMat4x3*, float32, float32, float32, float32) STUB_VOID
inline void xMat4x3Rot(xMat4x3*, const xVec3*, float32) STUB_VOID
inline void xMat4x3Tolocal(xVec3*, const xMat4x3*, const xVec3*) STUB_VOID
inline void xMat4x3Toworld(xVec3* o, const xMat4x3* m, const xVec3* v) STUB_VOID
inline void xMat4x3OrthoInv(xMat4x3*, const xMat4x3*) STUB_VOID
inline void xQuatCopy(xQuat*, const xQuat*) STUB_VOID
inline uint32 xQuatEquals(const xQuat*, const xQuat*) STUB
inline void xQuatAdd(xQuat*, const xQuat*, const xQuat*) STUB_VOID
inline void xQuatSMul(xQuat*, const xQuat*, float32) STUB_VOID
inline float32 xQuatGetAngle(const xQuat*) STUB
inline float32 xQuatDot(const xQuat*, const xQuat*) STUB
inline float32 xQuatLength2(const xQuat*) STUB
inline void xQuatFlip(xQuat*, const xQuat*) STUB_VOID
inline void xQuatConj(xQuat*, const xQuat*) STUB_VOID
inline void xRotCopy(xRot*, const xRot*) STUB_VOID