#include "xSpline.h"

static void Tridiag_Solve(float32* a, float32* b, float32* c, xVec3* d, xVec3* x, int32 n) STUB_VOID
static void Interpolate_Bspline(xVec3* data, xVec3* control, float32* knots, uint32 nodata) STUB_VOID
static float32 ArcLength3(xCoef3* coef, float64 ustart, float64 uend) STUB
static void EvalCoef3(xCoef3* coef, float32 u, uint32 deriv, xVec3* o) STUB_VOID
static void BasisToCoef3(xCoef3*, float32*[4], xVec3*, xVec3*, xVec3*, xVec3*) STUB_VOID
static void CoefToUnity3(xCoef3*, xCoef3*, float32, float32) STUB_VOID
static void BasisBspline(float32* N[4], float32* t) STUB_VOID
static float32 ClampBspline(xSpline3*, float32) STUB
static uint32 SegBspline(xSpline3*, float32) STUB
static void EvalBspline3(xSpline3* spl, float32 u, uint32 deriv, xVec3* o) STUB_VOID
static xCoef3* CoefSeg3(xSpline3* spl, uint32 seg, xCoef3* tempCoef) STUB
void xSpline3_EvalSeg(xSpline3* spl, float32 u, uint32 deriv, xVec3* o) STUB_VOID
static float32 ArcEvalIterate(xSpline3* spl, float32 s, uint32 deriv, xVec3* o, uint32 iterations) STUB
float32 xSpline3_EvalArcApprox(xSpline3* spl, float32 s, uint32 deriv, xVec3* o) STUB
void xSpline3_ArcInit(xSpline3* spl, uint32 sample) STUB_VOID
xSpline3* AllocSpline3(xVec3* points, float32* time, uint32 numpoints, uint32 numalloc, uint32 flags, uint32 type) STUB
xSpline3* xSpline3_Bezier(xVec3* points, float32* time, uint32 numpoints, uint32 numalloc, xVec3* p1, xVec3* p2) STUB
void xSpline3_Update(xSpline3*) STUB_VOID
void xSpline3_Catmullize(xSpline3*) STUB_VOID