#pragma once

#include "xMath3.h"

struct xPar;
struct xParGroup;
struct xParCmdTex;

void iParMgrInit();
void iParMgrUpdate(float32);
void iParMgrRender();
void iParMgrRenderParSys_Sprite(void* data, xParGroup* ps);
void iRenderInit();
void iRenderSetCameraViewMatrix(xMat4x3* m);
void iRenderPushQuadStreak(xPar* p, xParCmdTex* tex);
void iRenderFlush();
void iRenderTrianglesImmediate(int32, int32, void*, int32, uint16*, int32);
void iParMgrRenderParSys_Streak(void* data, xParGroup* ps);
void iParMgrRenderParSys_InvStreak(void* data, xParGroup* ps);
void iParMgrRenderParSys_QuadStreak(void* data, xParGroup* ps);
void iParMgrRenderParSys_Static(void*, xParGroup*);
void iParMgrRenderParSys_Ground(void* data, xParGroup* ps);
void iParMgrRenderParSys_Flat(void* data, xParGroup* ps);