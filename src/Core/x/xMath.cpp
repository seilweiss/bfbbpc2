#include "xMath.h"

void xMathInit() STUB_VOID
void xMathExit() STUB_VOID
float32 xatof(const char* x) STUB
void xsrand(uint32 seed) STUB_VOID
uint32 xrand() STUB
float32 xurand() STUB
uint32 xMathSolveQuadratic(float32 a, float32 b, float32 c, float32* x1, float32* x2) STUB
uint32 xMathSolveCubic(float32 a, float32 b, float32 c, float32 d, float32* x1, float32* x2, float32* x3) STUB
float32 xAngleClamp(float32 a) STUB
float32 xAngleClampFast(float32 a) STUB
float32 xDangleClamp(float32 a) STUB
void xAccelMove(float32& x, float32& v, float32 a, float32 dt, float32 endx, float32 maxv) STUB_VOID
float32 xAccelMoveTime(float32 dx, float32 a, float32, float32 maxv) STUB
void xAccelMove(float32& x, float32& v, float32 a, float32 dt, float32 maxv) STUB_VOID
void xAccelStop(float32& x, float32& v, float32 a, float32 dt) STUB_VOID
float32 xFuncPiece_Eval(xFuncPiece* func, float32 param, xFuncPiece** iterator) STUB
void xFuncPiece_EndPoints(xFuncPiece* func, float32 pi, float32 pf, float32 fi, float32 ff) STUB_VOID
void xFuncPiece_ShiftPiece(xFuncPiece* shift, xFuncPiece* func, float32 newZero) STUB_VOID