#include "xShadow.h"

#include <rpcollis.h>

struct xShadowMgr
{
	xEnt* ent;
	xShadowCache* cache;
	int32 priority;
	int32 cacheReady;
};

void xShadowInit() STUB_VOID
void xShadowRender(xVec3*, float32, float32) STUB_VOID
static bool32 SetupShadow() STUB
void xShadowSetWorld(RpWorld* world) STUB_VOID
void xShadowSetLight(xVec3* target_pos, xVec3* in_vec, float32) STUB_VOID
bool32 xShadowCameraCreate() STUB
void xShadowCameraUpdate(void* model, xShadowRenderModelCallback renderCB, xVec3* center, float32 radius, int32 shadowMode) STUB_VOID
void xShadowRenderWorld(xVec3* center, float32 radius, float32 max_dist) STUB_VOID
static void modelRenderCB(void* model) STUB_VOID
uint32 xShadowReceiveShadowSetup(xEnt* ent) STUB
void xShadowReceiveShadow(xEnt* ent, float32 shadowFactor, int32 shadowMode, RwMatrix* shadowMat, RwRaster* shadowRast) STUB_VOID
void xShadowRender(xEnt* ent, float32 max_dist) STUB_VOID
void xShadow_ListAdd(xEnt* ent) STUB_VOID
bool32 Im2DRenderQuad(float32 x1, float32 y1, float32 x2, float32 y2, float32 z, float32 recipCamZ, float32 uvOffset) STUB
static void InvertRaster(RwCamera*) STUB_VOID
static void ShadowCameraDestroy(RwCamera* shadowCamera) STUB_VOID
static RwCamera* ShadowCameraUpdate(RwCamera* shadowCamera, void* model, xShadowRenderModelCallback renderCB, xVec3*, float32, int32) STUB
static RwRaster* ShadowRasterCreate(int32) STUB
static RpCollisionTriangle* ShadowRenderTriangleCB(RpIntersection*, RpWorldSector*, RpCollisionTriangle* collTriangle, RwReal, void* data) STUB
static bool32 ShadowRender(RwCamera* shadowCamera, RwRaster*, RpIntersection* shadowZone, float32 shadowFactor, float32 fadeDist) STUB
static void GCSaveFrameBuffer() STUB_VOID
static void GCRestoreFrameBuffer() STUB_VOID
static RwCamera* ShadowCameraCreatePersp(int32) STUB
static RwCamera* ShadowCameraSetSpherePersp(RwCamera* camera, RwV3d* center, float32 radius) STUB
static RpCollisionTriangle* shadowCacheEnvCB(RpIntersection*, RpWorldSector*, RpCollisionTriangle* tri, RwReal, void* data) STUB
static RwBool shadowCacheLeafCB(RwInt32 numTriangles, RwInt32 triOffset, void* data) STUB
static bool32 shadowCacheEntityCB(xEnt* ent, void* cbdata) STUB
void xShadowVertical_FillCache(xShadowCache* cache, xVec3* pos, float32 r, float32 depth, float32 minNormY) STUB_VOID
void xShadowVertical_DrawCache(xShadowCache* cache, float32 shadowFactor, float32 fadeDist, int32 shadowMode, RwMatrix* shadowMat, RwRaster* shadowRast) STUB_VOID
void xShadowManager_Init(int32 numEnts) STUB_VOID
void xShadowManager_Reset() STUB_VOID
void xShadowManager_Add(xEnt* ent) STUB_VOID
void xShadowManager_Remove(xEnt* ent) STUB_VOID
static int32 CmpShadowMgr(const void* a, const void* b) STUB
void xShadowManager_Render() STUB_VOID
static void xShadow_PickByRayCast(xShadowMgr* mgr) STUB_VOID
static void xShadow_PickEntForNPC(xShadowMgr* mgr) STUB_VOID