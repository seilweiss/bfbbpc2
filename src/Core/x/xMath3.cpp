#include "xMath3.h"

const xVec3 g_O3 = { 0.0f, 0.0f, 0.0f };
xMat4x3 g_I3;

void xMath3Init() STUB_VOID
void xLine3VecDist2(const xVec3* p1, const xVec3* p2, const xVec3* v, xIsect* isx) STUB_VOID
bool32 xPointInBox(const xBox* b, const xVec3* p) STUB
void xBoxInitBoundOBB(xBox* o, const xBox* b, const xMat4x3* m) STUB_VOID
void xBoxInitBoundCapsule(xBox* b, const xCapsule* c) STUB_VOID
void xBoxFromCone(xBox& box, const xVec3& center, const xVec3& dir, float32 dist, float32 r1, float32 r2) STUB_VOID
void xMat3x3Normalize(xMat3x3* o, const xMat3x3* m) STUB_VOID
void xMat3x3GetEuler(const xMat3x3* m, xVec3* a) STUB_VOID
void xMat4x3MoveLocalRight(xMat4x3* m, float32 mag) STUB_VOID
void xMat4x3MoveLocalUp(xMat4x3* m, float32 mag) STUB_VOID
void xMat4x3MoveLocalAt(xMat4x3* m, float32 mag) STUB_VOID
float32 xMat3x3LookVec(xMat3x3* m, const xVec3* at) STUB
void xMat3x3Euler(xMat3x3* m, const xVec3* ypr) STUB_VOID
void xMat3x3Euler(xMat3x3* m, float32 yaw, float32 pitch, float32 roll) STUB_VOID
void xMat3x3RotC(xMat3x3* m, float32 _x, float32 _y, float32 _z, float32 t) STUB_VOID
void xMat3x3RotX(xMat3x3* m, float32 t) STUB_VOID
void xMat3x3RotY(xMat3x3* m, float32 t) STUB_VOID
void xMat3x3RotZ(xMat3x3* m, float32 t) STUB_VOID
void xMat3x3ScaleC(xMat3x3* m, float32 x, float32 y, float32 z) STUB_VOID
void xMat3x3RMulRotY(xMat3x3* o, const xMat3x3* m, float32 t) STUB_VOID
void xMat3x3Transpose(xMat3x3* o, const xMat3x3* m) STUB_VOID
void xMat3x3Mul(xMat3x3* o, const xMat3x3* a, const xMat3x3* b) STUB_VOID
void xMat3x3LMulVec(xVec3* o, const xMat3x3* m, const xVec3* v) STUB_VOID
void xMat3x3Tolocal(xVec3* o, const xMat3x3* m, const xVec3* v) STUB_VOID
void xMat4x3Rot(xMat4x3* m, const xVec3* a, float32 t, const xVec3* p) STUB_VOID
void xMat4x3Mul(xMat4x3* o, const xMat4x3* a, const xMat4x3* b) STUB_VOID
void xQuatFromMat(xQuat* q, const xMat3x3* m) STUB_VOID
void xQuatFromAxisAngle(xQuat* q, const xVec3* a, float32 t) STUB_VOID
void xQuatToMat(const xQuat* q, xMat3x3* m) STUB_VOID
void xQuatToAxisAngle(const xQuat* q, xVec3* a, float32* t) STUB_VOID
float32 xQuatNormalize(xQuat* o, const xQuat* q) STUB
void xQuatSlerp(xQuat* o, const xQuat* a, const xQuat* b, float32 t) STUB_VOID
void xQuatMul(xQuat* o, const xQuat* a, const xQuat* b) STUB_VOID
void xQuatDiff(xQuat* o, const xQuat* a, const xQuat* b) STUB_VOID