#include "iCollide.h"

#include <rpcollis.h>

void iCollideInit(xScene*) {}
bool32 PointWithinTriangle(xVec3* _pt, xVec3** _tri, xVec3* _normal) STUB
void FindNearestPointOnLine(xVec3* _result, xVec3* _point, xVec3* _start, xVec3* _end) STUB_VOID
static void properSphereIsectTri(const xVec3* center, float32 radius, xVec3* tohit, float32* dist_ptr, RpCollisionTriangle* tri) STUB_VOID
RpCollisionTriangle* sphereHitsEnvCB(RpIntersection* isx, RpWorldSector*, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* sphereHitsEnv3CB(RpIntersection* isx, RpWorldSector* sector, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* sphereHitsEnv4CB(RpIntersection* isx, RpWorldSector* sector, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* sphereHitsModel3CB(RpIntersection*, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* rayHitsEnvCB(RpIntersection*, RpWorldSector* sector, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* rayHitsEnvBackwardCB(RpIntersection*, RpWorldSector* sector, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* rayHitsModelCB(RpIntersection* isx, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
static RpCollisionTriangle* rayHitsModelBackwardCB(RpIntersection* isx, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
uint32 iSphereHitsEnv(const xSphere* b, const xEnv* env, xCollis* coll) STUB
int32 iSphereHitsEnv3(const xSphere* b, const xEnv* env, xCollis* colls, uint8 ncolls, float32 sth) STUB
int32 iSphereHitsEnv4(const xSphere* b, const xEnv* env, const xMat3x3* mat, xCollis* colls) STUB
int32 iSphereHitsModel3(const xSphere* b, const xModelInstance* m, xCollis* colls, uint8 ncolls, float32 sth) STUB
uint32 iRayHitsEnv(const xRay3* r, const xEnv* env, xCollis* coll) STUB
uint32 iRayHitsModel(const xRay3* r, const xModelInstance* m, xCollis* coll) STUB
void iSphereForModel(xSphere* o, const xModelInstance* m) STUB_VOID
void iBoxForModel(xBox* o, const xModelInstance* m) STUB_VOID
void iBoxForModelLocal(xBox* o, const xModelInstance* m) STUB_VOID