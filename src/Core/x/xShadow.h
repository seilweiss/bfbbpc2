#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct xEnt;

struct xShadowPoly
{
	xVec3 vert[3];
	xVec3 norm;
};

struct xShadowCache
{
	xVec3 pos;
	float32 radius;
	uint32 entCount;
	uint32 polyCount;
	float32 polyRayDepth[5];
	uint16 castOnEnt;
	uint16 castOnPoly;
	xEnt* ent[16];
	xShadowPoly poly[256];
};

typedef void(*xShadowRenderModelCallback)(void*);

void xShadowInit();
void xShadowRender(xVec3*, float32, float32);
void xShadowSetWorld(RpWorld* world);
void xShadowSetLight(xVec3* target_pos, xVec3* in_vec, float32);
bool32 xShadowCameraCreate();
void xShadowCameraUpdate(void* model, xShadowRenderModelCallback renderCB, xVec3* center, float32 radius, int32 shadowMode);
void xShadowRenderWorld(xVec3* center, float32 radius, float32 max_dist);
uint32 xShadowReceiveShadowSetup(xEnt* ent);
void xShadowReceiveShadow(xEnt* ent, float32 shadowFactor, int32 shadowMode, RwMatrix* shadowMat, RwRaster* shadowRast);
void xShadowRender(xEnt* ent, float32 max_dist);
void xShadow_ListAdd(xEnt* ent);
bool32 Im2DRenderQuad(float32 x1, float32 y1, float32 x2, float32 y2, float32 z, float32 recipCamZ, float32 uvOffset);
void xShadowVertical_FillCache(xShadowCache* cache, xVec3* pos, float32 r, float32 depth, float32 minNormY);
void xShadowVertical_DrawCache(xShadowCache* cache, float32 shadowFactor, float32 fadeDist, int32 shadowMode, RwMatrix* shadowMat, RwRaster* shadowRast);
void xShadowManager_Init(int32 numEnts);
void xShadowManager_Reset();
void xShadowManager_Add(xEnt* ent);
void xShadowManager_Remove(xEnt* ent);
void xShadowManager_Render();
