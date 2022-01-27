#include "xShadowSimple.h"

#include <rpcollis.h>

struct xShadowSimpleQueue
{
	xShadowSimpleCache* cache;
	uint32 priority;
	xEnt* ent;
	float32 radius;
	float32 ecc;
};

static RpCollisionTriangle* shadowRayCB(RpIntersection*, RpWorldSector*, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* shadowRayModelCB(RpIntersection* isx, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static bool32 shadowRayEntCB(xEnt* ent, void* cbdata) STUB
static void xShadowSimple_SceneCollide(xShadowSimpleCache* cache, xVec3* pos, float32 depth) STUB_VOID
static void xShadowSimple_CalcCorners(xShadowSimpleCache* cache, xEnt* ent, float32 radius, float32 ecc) STUB_VOID
static void xShadowSimple_AddVerts(xShadowSimpleCache* cache) STUB_VOID
void xShadowSimple_Init() STUB_VOID
void xShadowSimple_CacheInit(xShadowSimpleCache* cache, xEnt* ent, uint8 alpha) STUB_VOID
void xShadowSimple_Add(xShadowSimpleCache* cache, xEnt* ent, float32 radius, float32 ecc) STUB_VOID
void xShadowSimple_Render() STUB_VOID