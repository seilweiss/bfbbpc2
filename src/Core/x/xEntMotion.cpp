#include "xEntMotion.h"

void xEntMotionInit(xEntMotion* motion, xEnt* owner, xEntMotionAsset* asset) STUB_VOID
void xEntMotionReset(xEntMotion* motion, xScene* sc) STUB_VOID
void xEntMotionMove(xEntMotion* motion, xScene* sc, float32 dt, xEntFrame* frame) STUB_VOID
static void xEntERMove(xEntMotion* motion, xScene*, float32 dt, xEntFrame* frame) STUB_VOID
static void xEntOrbitMove(xEntMotion* motion, xScene*, float32 dt, xEntFrame* frame) STUB_VOID
static void xEntMPGetNext(xEntMotion* motion, xMovePoint* prev, xScene*) STUB_VOID
static void xEntMPMove(xEntMotion* motion, xScene* sc, float32 dt, xEntFrame* frame) STUB_VOID
static void xEntPenMove(xEntMotion* motion, xScene*, float32 dt, xEntFrame* frame) STUB_VOID
static void xEntMechMove(xEntMotion* motion, xScene* sc, float32 dt, xEntFrame* frame) STUB_VOID
static uint32 xEntSldMove(xEntMotion* motion, xScene*, float32 dt, xEntFrame* frame) STUB
static uint32 xEntRotMove(xEntMotion* motion, xScene*, float32 dt, xEntFrame* frame) STUB
void xEntMechForward(xEntMotion* motion) STUB_VOID
void xEntMechReverse(xEntMotion* motion) STUB_VOID
void xEntMotionTranslate(xEntMotion* motion, const xVec3* dpos, xMat4x3* dmat) STUB_VOID
void xEntMotionDebugInit(uint16 num_xems) STUB_VOID
void xEntMotionDebugExit() STUB_VOID
static void xEntMotionDebugAdd(xEntMotion*) STUB_VOID
static void xEntMotionDebugCB() STUB_VOID
static void xEntMotionDebugWrite(const xEntMotion* xem) STUB_VOID
static void xEntMotionDebugDraw(const xEntMotion* xem) STUB_VOID
static void xEntMotionDebugIPad(const xEntMotion* xem) STUB_VOID