#pragma once

#include "iMath.h"

#define PI 3.1415927f
#define EPSILON 0.00001f

#define xsqr(x) ((x) * (x))

#define xabs(x) iabs(x)

#define xmax(a, b) (((a) > (b)) ? (a) : (b))
#define xmin(a, b) (((a) < (b)) ? (a) : (b))
#define xclamp(x, a, b) (xmax((a), xmin((x), (b))))

#define xapproxeq(a, b) (xabs((a) - (b)) <= (EPSILON))

#define xdeg2rad(x) ((PI) * (x) / 180.0f)
#define xrad2deg(x) (180.0f * (x) / (PI))

struct xFuncPiece
{
	float32 coef[5];
	float32 end;
	int32 order;
	xFuncPiece* next;
};

void xMathInit();
void xMathExit();
float32 xatof(const char* x);
void xsrand(uint32 seed);
uint32 xrand();
float32 xurand();
uint32 xMathSolveQuadratic(float32 a, float32 b, float32 c, float32* x1, float32* x2);
uint32 xMathSolveCubic(float32 a, float32 b, float32 c, float32 d, float32* x1, float32* x2, float32* x3);
float32 xAngleClamp(float32 a);
float32 xAngleClampFast(float32 a);
float32 xDangleClamp(float32 a);
void xAccelMove(float32& x, float32& v, float32 a, float32 dt, float32 endx, float32 maxv);
float32 xAccelMoveTime(float32 dx, float32 a, float32, float32 maxv);
void xAccelMove(float32& x, float32& v, float32 a, float32 dt, float32 maxv);
void xAccelStop(float32& x, float32& v, float32 a, float32 dt);
float32 xFuncPiece_Eval(xFuncPiece* func, float32 param, xFuncPiece** iterator);
void xFuncPiece_EndPoints(xFuncPiece* func, float32 pi, float32 pf, float32 fi, float32 ff);
void xFuncPiece_ShiftPiece(xFuncPiece* shift, xFuncPiece* func, float32 newZero);

inline float32 xfmod(float32, float32) STUB

inline float32 xrmod(float32 ang)
{
    float32 frac = 1.0f / (2.0f * PI) * ang;

    if (frac < 0.0f)
    {
        return (frac - std::ceilf(frac) + 1.0f) * (2.0f * PI);
    }

    if (frac >= 1.0f)
    {
        return (frac - std::floorf(frac)) * (2.0f * PI);
    }

    return ang;
}

inline const char* xbtoa(uint32) STUB
inline float32 xSCurve(float32) STUB
inline float32 xSCurve(float32 t, float32 softness) STUB
inline void xSCurve(float32&, float32&, float32&, float32) STUB_VOID
inline float32 xSCurveInverse(float32) STUB

#include "xMathInlines.h"