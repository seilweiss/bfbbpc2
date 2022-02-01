#pragma once

#include "xMath3.h"
#include "xQuickCull.h"

struct xCollis;

struct xBound
{
	xQCData qcd;
	uint8 type;
	uint8 pad[3];
	union
	{
		xSphere sph;
		xBBox box;
		xCylinder cyl;
	};
	xMat4x3* mat;
};

#define XBOUND_NA 0 // None/invalid
#define XBOUND_SPH 1 // Sphere - xBound::sph
#define XBOUND_BOX 2 // Axis aligned bounding box - xBound::box
#define XBOUND_CYL 3 // Cylinder - xBound::cyl
#define XBOUND_OBB 4 // Oriented bounding box - xBound::box * xBound::mat

void xBoundUpdate(xBound* b);
void xBoundGetBox(xBox& box, const xBound& bound);
void xBoundGetSphere(xSphere& o, const xBound& bound);
void xBoundSphereHitsOBB(const xSphere*, const xBox*, const xMat4x3*, xCollis*);
void xBoundHitsBound(const xBound* a, const xBound* b, xCollis* c);
void xBoundOBBIsectRay(const xBox* b, const xMat4x3* m, const xRay3* r, xIsect* isect);
void xRayHitsBound(const xRay3* r, const xBound* b, xCollis* c);
void xSphereHitsBound(const xSphere* o, const xBound* b, xCollis* c);
void xVecHitsBound(const xVec3* v, const xBound* b, xCollis* c);
void xBoundDraw(const xBound*);

inline xVec3* xBoundCenter(xBound*) STUB
inline const xVec3* xBoundCenter(const xBound*) STUB