#pragma once

#include "xVec3.h"

#include <string.h>

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

#define XRAY_UNK0x400 0x400
#define XRAY_UNK0x800 0x800

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

extern xMat4x3 g_I3;

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

inline void xMat3x3LookAt(xMat3x3* m, const xVec3* pos, const xVec3* at)
{
	xVec3 v;

	xVec3Sub(&v, at, pos);
	xMat3x3LookVec(m, &v);
}

inline float32 xMat3x3LookVec3(xMat3x3&, const xVec3&) STUB
inline void xMat3x3MulRotC(xMat3x3*, xMat3x3*, float32, float32, float32, float32) STUB_VOID
inline void xMat3x3SMul(xMat3x3*, const xMat3x3*, float32) STUB_VOID

static inline void xMat3x3RMulVec(xVec3* o, const xMat3x3* m, const xVec3* v)
{
	float32 x = m->right.x * v->x + m->up.x * v->y + m->at.x * v->z;
	float32 y = m->right.y * v->x + m->up.y * v->y + m->at.y * v->z;
	float32 z = m->right.z * v->x + m->up.z * v->y + m->at.z * v->z;

	o->x = x;
	o->y = y;
	o->z = z;
}

inline void xMat4x3Copy(xMat4x3* o, const xMat4x3* m)
{
	memcpy(o, m, sizeof(xMat4x3));
}

inline void xMat4x3Identity(xMat4x3* m)
{
	xMat4x3Copy(m, &g_I3);
}

inline void xMat4x3RotC(xMat4x3*, float32, float32, float32, float32) STUB_VOID
inline void xMat4x3Rot(xMat4x3*, const xVec3*, float32) STUB_VOID

inline void xMat4x3Tolocal(xVec3* o, const xMat4x3* m, const xVec3* v)
{
	o->x = v->x - m->pos.x;
	o->y = v->y - m->pos.y;
	o->z = v->z - m->pos.z;

	xMat3x3Tolocal(o, m, o);
}

inline void xMat4x3Toworld(xVec3* o, const xMat4x3* m, const xVec3* v)
{
	xMat3x3RMulVec(o, m, v);

	o->x += m->pos.x;
	o->y += m->pos.y;
	o->z += m->pos.z;
}

inline void xMat4x3OrthoInv(xMat4x3*, const xMat4x3*) STUB_VOID
inline void xQuatCopy(xQuat*, const xQuat*) STUB_VOID
inline uint32 xQuatEquals(const xQuat*, const xQuat*) STUB
inline void xQuatAdd(xQuat*, const xQuat*, const xQuat*) STUB_VOID
inline void xQuatSMul(xQuat*, const xQuat*, float32) STUB_VOID

inline float32 xQuatGetAngle(const xQuat* q)
{
	if (q->s > 1.0f - EPSILON)
	{
		return 0.0f;
	}

	if (q->s < -1.0f + EPSILON)
	{
		return 2.0f * PI;
	}

	return 2.0f * xacos(q->s);
}

inline float32 xQuatDot(const xQuat*, const xQuat*) STUB
inline float32 xQuatLength2(const xQuat*) STUB
inline void xQuatFlip(xQuat*, const xQuat*) STUB_VOID

inline void xQuatConj(xQuat* o, const xQuat* q)
{
	o->s = q->s;

	xVec3Inv(&o->v, &q->v);
}

inline void xRotCopy(xRot*, const xRot*) STUB_VOID