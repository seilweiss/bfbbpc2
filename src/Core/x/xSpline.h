#pragma once

#include "xMath3.h"

struct xCoef
{
	float32 a[4];
};

struct xCoef3
{
	xCoef x;
	xCoef y;
	xCoef z;
};

struct xSpline3
{
	uint16 type;
	uint16 flags;
	uint32 N;
	uint32 allocN;
	xVec3* points;
	float32* time;
	xVec3* p12;
	xVec3* bctrl;
	float32* knot;
	xCoef3* coef;
	uint32 arcSample;
	float32* arcLength;
};

void xSpline3_EvalSeg(xSpline3* spl, float32 u, uint32 deriv, xVec3* o);
float32 xSpline3_EvalArcApprox(xSpline3* spl, float32 s, uint32 deriv, xVec3* o);
void xSpline3_ArcInit(xSpline3* spl, uint32 sample);
xSpline3* xSpline3_Bezier(xVec3* points, float32* time, uint32 numpoints, uint32 numalloc, xVec3* p1, xVec3* p2);
void xSpline3_Update(xSpline3*);
void xSpline3_Catmullize(xSpline3*);

inline float32 xSpline3_ArcTotal(xSpline3*) STUB