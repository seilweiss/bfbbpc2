#include "xCollide.h"

#include "xClumpColl.h"

xCollsIdx xCollideGetCollsIdx(xCollis* coll, const xVec3* tohit, const xMat3x3* mat) STUB
void xCollideInit(xScene* sc) STUB_VOID
uint32 xSphereHitsSphere(const xSphere* a, const xSphere* b, xCollis* coll) STUB
uint32 xSphereHitsBox(const xSphere* a, const xBox* b, xCollis* coll) STUB
uint32 xSphereHitsOBB_nu(const xSphere* s, const xBox* b, const xMat4x3* m, xCollis* coll) STUB
static RpCollisionTriangle* sphereHitsModelCB(RpIntersection*, RpCollisionTriangle* tri, RwReal dist, void* data) STUB
uint32 xSphereHitsModel(const xSphere* b, const xModelInstance* m, xCollis* coll) STUB
void xParabolaRecenter(xParabola* p, float32 newZeroT) STUB_VOID
static bool32 xParabolaEnvCB(xClumpCollBSPTriangle* triangles, void* data) STUB
bool32 xParabolaHitsEnv(xParabola* p, const xEnv* env, xCollis* colls) STUB
uint32 xBoxHitsSphere(const xBox* a, const xSphere* b, xCollis* coll) STUB
static uint32 Mgc_BoxBoxTest(const xBox* a, const xMat4x3* matA, const xBox* b, const xMat4x3* matB) STUB
uint32 xBoxHitsObb(const xBox* a, const xBox* b, const xMat4x3* mat, xCollis* coll) STUB
void xCollideCalcTri(xCollis::tri_data& tri, const xModelInstance& model, const xVec3& center, const xVec3& heading) STUB_VOID
namespace { void render_tri(xCollis::tri_data&, const xModelInstance&) {} }
xVec3 xCollisTriHit(const xCollis::tri_data& tri, const xModelInstance& model) STUB
RpCollBSPTree* _rpCollBSPTreeForAllCapsuleLeafNodeIntersections(RpCollBSPTree* tree, RwLine* line, float32 radius, RpV3dGradient* grad, RpCollBSPTreeIntersectionCallBack callBack, void* data) STUB
void xSweptSpherePrepare(xSweptSphere* sws, xVec3* start, xVec3* end, float32 radius) STUB_VOID
void xSweptSphereGetResults(xSweptSphere* sws) STUB_VOID
bool32 xSweptSphereToTriangle(xSweptSphere* sws, xVec3* v0, xVec3* v1, xVec3* v2) STUB
bool32 xSweptSphereToSphere(xSweptSphere* sws, xSphere* sph) STUB
bool32 xSweptSphereToBox(xSweptSphere* sws, xBox* box, xMat4x3* mat) STUB
static RpCollisionTriangle* SweptSphereHitsEnvCB(RpIntersection*, RpWorldSector* sector, RpCollisionTriangle* tri, RwReal, void* data) STUB
static bool32 SweptSphereLeafNodeCB(xClumpCollBSPTriangle* triangles, void* data) STUB
bool32 xSweptSphereToEnv(xSweptSphere* sws, xEnv* env) STUB
static RwBool SweptSphereModelCB(RwInt32 numTriangles, RwInt32 triOffset, void* data) STUB
bool32 xSweptSphereToModel(xSweptSphere* sws, RpAtomic* model, RwMatrix* mat) STUB
static void SweptSphereHitsEntCB(xScene*, xRay3* ray, xQCData* qcd, xEnt* ent, void* data) STUB_VOID
bool32 xSweptSphereToScene(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType) STUB
bool32 xSweptSphereToStatDyn(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType) STUB
bool32 xSweptSphereToNPC(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType) STUB
bool32 xSweptSphereToNonMoving(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType) STUB
bool xSphereHitsCapsule(const xVec3& center, float32 radius, const xVec3& v1, const xVec3& v2, float32 width) STUB
bool xSphereHitsBound(const xSphere& o, const xBound& b) STUB
bool xOBBHitsOBB(const xBox& a, const xMat4x3& amat, const xBox& b, const xMat4x3& bmat) STUB
bool xSphereHitsVCylinder(const xVec3& sc, float32 sr, const xVec3& cc, float32 cr, float32 ch) STUB
bool xSphereHitsVCircle(const xVec3& sc, float32 sr, const xVec3& cc, float32 cr) STUB