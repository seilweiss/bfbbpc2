#include "xBound.h"

void xBoundUpdate(xBound* b) STUB_VOID
void xBoundGetBox(xBox& box, const xBound& bound) STUB_VOID
void xBoundGetSphere(xSphere& o, const xBound& bound) STUB_VOID
void xBoundSphereHitsOBB(const xSphere*, const xBox*, const xMat4x3*, xCollis*) STUB_VOID
void xBoundHitsBound(const xBound* a, const xBound* b, xCollis* c) STUB_VOID
void xBoundOBBIsectRay(const xBox* b, const xMat4x3* m, const xRay3* r, xIsect* isect) STUB_VOID
void xRayHitsBound(const xRay3* r, const xBound* b, xCollis* c) STUB_VOID
void xSphereHitsBound(const xSphere* o, const xBound* b, xCollis* c) STUB_VOID
void xVecHitsBound(const xVec3* v, const xBound* b, xCollis* c) STUB_VOID
void xBoundDraw(const xBound*) STUB_VOID