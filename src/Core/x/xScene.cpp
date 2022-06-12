#include "xScene.h"

xScene* g_xSceneCur = NULL;

void xSceneInit(xScene* sc, uint16 num_trigs, uint16 num_stats, uint16 num_dyns, uint16 num_npcs) STUB_VOID
void xSceneExit(xScene*) {}
void xSceneSave(xScene*, xSerial*) {}
void xSceneLoad(xScene*, xSerial*) {}
void xSceneSetup(xScene* sc) STUB_VOID
void xSceneAddEnt(xScene* sc, xEnt* ent) STUB_VOID
xBase* xSceneResolvID(xScene* sc, uint32 id) STUB
char* xSceneID2Name(xScene* sc, uint32 id) STUB
void xSceneForAllEnts(xScene* sc, xEntSceneCallback func, void* data) STUB_VOID
void xSceneForAllStatics(xScene* sc, xEntSceneCallback func, void* data) STUB_VOID
void xSceneForAllDynamics(xScene* sc, xEntSceneCallback func, void* data) STUB_VOID
void xSceneForAllNPCs(xScene* sc, xEntSceneCallback func, void* data) STUB_VOID
void xRayHitsGrid(xGrid* grid, xScene* sc, xRay3* r, xRayHitsGridCallback rentcb, xQCData* qcr, void* data) STUB_VOID
void xRayHitsTikiLandableEnt(xScene*, xRay3* r, xQCData* qcr, xEnt* ent, void* colldata) STUB_VOID
void xRayHitsEnt(xScene*, xRay3* r, xQCData* qcr, xEnt* ent, void* colldata) STUB_VOID
void xRayHitsTikiLandableScene(xScene* sc, xRay3* r, xCollis* coll) STUB_VOID
void xRayHitsScene(xScene* sc, xRay3* r, xCollis* coll) STUB_VOID

namespace {

	struct cb_ray_hits_ent
	{
		const xRay3& ray;
		xCollis& coll;
		uint8 chkby;
		uint8 collType;

		cb_ray_hits_ent(const xRay3& ray, xCollis& coll, uint8 chkby, uint8 collType) WIP : ray(ray), coll(coll), chkby(chkby), collType(collType) {}

		bool operator()(xEnt&, xGridBound&) STUB;
	};

}

void xRayHitsSceneFlags(xScene* sc, xRay3* r, xCollis* coll, uint8 collType, uint8 chk) STUB_VOID
static void ProjectTriangle(xVec3*, xVec3*, float32*, float32*) STUB_VOID
static void ProjectBox(xVec3*, xBox*, float32*, float32*) STUB_VOID
static uint32 Mgc_TriBoxTest(xVec3* apkTri, xBox* rkBox) STUB
static RpCollisionTriangle* nearestFloorCB(RpIntersection*, RpCollisionTriangle* collTriangle, RwReal, void* data) STUB
static RpCollisionTriangle* boxNearestFloorCB(RpIntersection* intersection, RpCollisionTriangle* collTriangle, RwReal distance, void* data) STUB
static RpCollisionTriangle* sectorNearestFloorCB(RpIntersection* intersection, RpCollisionTriangle* collTriangle, RwReal distance, void* data) STUB
static bool32 gridNearestFloorCB(xEnt* ent, void* cbdata) STUB
uint32 xSceneNearestFloorPoly(xScene* sc, xNearFloorPoly* nfpoly, uint8 collType, uint8 chk) STUB