#include "iParMgr.h"

void iParMgrInit() STUB_VOID
void iParMgrUpdate(float32) {}
void iParMgrRender() {}
void iParMgrRenderParSys_Sprite(void* data, xParGroup* ps) STUB_VOID
void iRenderInit() STUB_VOID
void iRenderSetCameraViewMatrix(xMat4x3* m) STUB_VOID
void iRenderPushQuadStreak(xPar* p, xParCmdTex* tex) STUB_VOID
static void iRenderPushFlat(xPar* p, xParCmdTex* tex) STUB_VOID
void iRenderFlush() STUB_VOID
void iRenderTrianglesImmediate(int32, int32, void*, int32, uint16*, int32) STUB_VOID
void iParMgrRenderParSys_Streak(void* data, xParGroup* ps) STUB_VOID
void iParMgrRenderParSys_InvStreak(void* data, xParGroup* ps) STUB_VOID
void iParMgrRenderParSys_QuadStreak(void* data, xParGroup* ps) STUB_VOID
void iParMgrRenderParSys_Static(void*, xParGroup*) {}
void iParMgrRenderParSys_Ground(void* data, xParGroup* ps) STUB_VOID
void iParMgrRenderParSys_Flat(void* data, xParGroup* ps) STUB_VOID