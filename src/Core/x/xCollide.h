#pragma once

#include "xMath3.h"
#include "xQuickCull.h"

#include <rwcore.h>
#include <rpcollbsptree.h>

struct xModelInstance;
struct xScene;
struct xEnv;
struct xEnt;

typedef enum _xCollsIdx
{
	k_XCOLLS_IDX_FLOOR,
	k_XCOLLS_IDX_CEIL,
	k_XCOLLS_IDX_FRONT,
	k_XCOLLS_IDX_LEFT,
	k_XCOLLS_IDX_REAR,
	k_XCOLLS_IDX_RIGHT,
	k_XCOLLS_IDX_COUNT
} xCollsIdx;

struct xCollis
{
	struct tri_data
	{
		uint32 index;
		float32 r;
		float32 d;
	};

	uint32 flags;
	uint32 oid;
	void* optr;
	xModelInstance* mptr;
	float32 dist;
	xVec3 norm;
	xVec3 tohit;
	xVec3 depen;
	xVec3 hdng;
	union
	{
		struct
		{
			float32 t;
			float32 u;
			float32 v;
		} tuv;
		tri_data tri;
	};
};

struct xParabola
{
	xVec3 initPos;
	xVec3 initVel;
	float32 gravity;
	float32 minTime;
	float32 maxTime;
};

union xiMat4x3Union
{
	xMat4x3 xm;
	RwMatrix im;
};

struct xSweptSphere
{
	xVec3 start;
	xVec3 end;
	float32 radius;
	float32 dist;
	xiMat4x3Union basis;
	xiMat4x3Union invbasis;
	xBox box;
	xQCData qcd;
	float32 boxsize;
	float32 curdist;
	xVec3 contact;
	xVec3 polynorm;
	uint32 oid;
	void* optr;
	xModelInstance* mptr;
	int32 hitIt;
	xVec3 worldPos;
	xVec3 worldContact;
	xVec3 worldNormal;
	xVec3 worldTangent;
	xVec3 worldPolynorm;
};

xCollsIdx xCollideGetCollsIdx(xCollis* coll, const xVec3* tohit, const xMat3x3* mat);
void xCollideInit(xScene* sc);
uint32 xSphereHitsSphere(const xSphere* a, const xSphere* b, xCollis* coll);
uint32 xSphereHitsBox(const xSphere* a, const xBox* b, xCollis* coll);
uint32 xSphereHitsOBB_nu(const xSphere* s, const xBox* b, const xMat4x3* m, xCollis* coll);
uint32 xSphereHitsModel(const xSphere* b, const xModelInstance* m, xCollis* coll);
void xParabolaRecenter(xParabola* p, float32 newZeroT);
bool32 xParabolaHitsEnv(xParabola* p, const xEnv* env, xCollis* colls);
uint32 xBoxHitsSphere(const xBox* a, const xSphere* b, xCollis* coll);
uint32 xBoxHitsObb(const xBox* a, const xBox* b, const xMat4x3* mat, xCollis* coll);
void xCollideCalcTri(xCollis::tri_data& tri, const xModelInstance& model, const xVec3& center, const xVec3& heading);
xVec3 xCollisTriHit(const xCollis::tri_data& tri, const xModelInstance& model);

RpCollBSPTree* _rpCollBSPTreeForAllCapsuleLeafNodeIntersections(RpCollBSPTree* tree, RwLine* line, float32 radius, RpV3dGradient* grad, RpCollBSPTreeIntersectionCallBack callBack, void* data);

void xSweptSpherePrepare(xSweptSphere* sws, xVec3* start, xVec3* end, float32 radius);
void xSweptSphereGetResults(xSweptSphere* sws);
bool32 xSweptSphereToTriangle(xSweptSphere* sws, xVec3* v0, xVec3* v1, xVec3* v2);
bool32 xSweptSphereToSphere(xSweptSphere* sws, xSphere* sph);
bool32 xSweptSphereToBox(xSweptSphere* sws, xBox* box, xMat4x3* mat);
bool32 xSweptSphereToEnv(xSweptSphere* sws, xEnv* env);
bool32 xSweptSphereToModel(xSweptSphere* sws, RpAtomic* model, RwMatrix* mat);
bool32 xSweptSphereToScene(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType);
bool32 xSweptSphereToStatDyn(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType);
bool32 xSweptSphereToNPC(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType);
bool32 xSweptSphereToNonMoving(xSweptSphere* sws, xScene* sc, xEnt* mover, uint8 collType);
bool xSphereHitsCapsule(const xVec3& center, float32 radius, const xVec3& v1, const xVec3& v2, float32 width);
bool xSphereHitsBound(const xSphere& o, const xBound& b);
bool xOBBHitsOBB(const xBox& a, const xMat4x3& amat, const xBox& b, const xMat4x3& bmat);
bool xSphereHitsVCylinder(const xVec3& sc, float32 sr, const xVec3& cc, float32 cr, float32 ch);
bool xSphereHitsVCircle(const xVec3& sc, float32 sr, const xVec3& cc, float32 cr);

inline bool xSphereHitsSphere(const xVec3, float32, const xVec3&, float32) STUB
inline bool xSphereHitsSphere(const xSphere&, const xSphere&) STUB
inline bool xSphereHitsBox(const xVec3&, float32, const xBox&) STUB
inline bool xSphereHitsBox(const xSphere&, const xBox&) STUB
inline bool xSphereHitsOBB(const xVec3&, float32, const xBox&, const xMat4x3&) STUB
inline bool xSphereHitsOBB(const xSphere&, const xBox&, const xMat4x3&) STUB
inline bool xSphereHitsVCircle(const xSphere&, const xVec3&, float32) STUB
inline bool xSphereHitsCapsule(const xSphere&, const xVec3&, const xVec3&, float32) STUB
inline void xParabolaEvalPos(const xParabola*, xVec3*, float32) STUB_VOID
inline void xParabolaEvalVel(const xParabola*, xVec3*, float32) STUB_VOID