#include "iMath3.h"

void iMath3Init() {}
void iSphereIsectVec(const xSphere* s, const xVec3* v, xIsect* isx) STUB_VOID
void iSphereIsectRay(const xSphere* s, const xRay3* r, xIsect* isx) STUB_VOID
void iSphereIsectSphere(const xSphere* s, const xSphere* p, xIsect* isx) STUB_VOID
void iSphereInitBoundVec(xSphere* s, const xVec3* v) STUB_VOID
void iSphereBoundVec(xSphere* o, const xSphere* s, const xVec3* v) STUB_VOID
void iCylinderIsectVec(const xCylinder* c, const xVec3* v, xIsect* isx) STUB_VOID
void iBoxVecDist(const xBox* box, const xVec3* v, xIsect* isx) STUB_VOID
void iBoxIsectVec(const xBox* b, const xVec3* v, xIsect* isx) STUB_VOID
static uint32 ClipPlane(float32 denom, float32 numer, float32* t_in, float32* t_out) STUB
static uint32 ClipBox(const xVec3*, const xVec3*, const xVec3*, float32*, float32*) STUB
void iBoxIsectRay(const xBox* b, const xRay3* r, xIsect* isx) STUB_VOID
void iBoxIsectSphere(const xBox* box, const xSphere* p, xIsect* isx) STUB_VOID
void iBoxInitBoundVec(xBox* b, const xVec3* v) STUB_VOID
void iBoxBoundVec(xBox* o, const xBox* b, const xVec3* v) STUB_VOID