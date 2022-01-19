#include "xEnt.h"

#include "zEntDestructObj.h"

namespace {

	namespace anim_coll {

		void reset(xEnt& ent) STUB_VOID;
		void refresh(xEnt& ent) STUB_VOID;

	}

}

void xEntSetTimePassed(float32 sec) STUB_VOID
void xEntSceneInit() STUB_VOID
void xEntSceneExit() {}
static void xEntAddHittableFlag(xEnt* ent) STUB_VOID
static void hack_receive_shadow(xEnt*) STUB_VOID
static void xEntAddShadowRecFlag(xEnt*) STUB_VOID
void xEntInit(xEnt* ent, xEntAsset* asset) STUB_VOID
void xEntInitForType(xEnt* ent) STUB_VOID

namespace {

	float32 get_lower_extent(const xBound&) STUB;
	bool collide_downward(xVec3& loc, xEnt*& hit, xScene& s, xEnt& ent, float32 max_dist) STUB;
	void stacked_owner_destroyed(zEntDestructObj&, void* context) STUB_VOID;
	void mount_stacked_entity(xEnt&, xEnt&) STUB_VOID;
	void dismount_stacked_entity(xEnt&) STUB_VOID;
	void setup_stacked_entity(xEnt&) STUB_VOID;
	void drop_stacked_entity(xEnt&) STUB_VOID;
	void stop_stacked_entity(xEnt&) STUB_VOID;
	void update_stacked_entity(xScene&, xEnt&, float32) STUB_VOID;

}

void xEntSetup(xEnt* ent) STUB_VOID;
void xEntSave(xEnt* ent, xSerial* s) STUB_VOID;
void xEntLoad(xEnt* ent, xSerial* s) STUB_VOID;
void xEntReset(xEnt* ent) STUB_VOID;
xModelInstance* xEntLoadModel(xEnt* ent, RpAtomic* imodel) STUB
static void xEntAddToPos(xEnt*, const xVec3*) STUB_VOID
void xEntSetupPipeline(xModelInstance* model) STUB_VOID
void xEntSetupPipeline(xSurface* surf, RpAtomic* model) STUB_VOID
void xEntRestorePipeline(xModelInstance* model) STUB_VOID
void xEntRestorePipeline(xSurface*, RpAtomic* model) STUB_VOID
void xEntRender(xEnt* ent) STUB_VOID
void xEntUpdate(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xEntBeginUpdate(xEnt* ent, float32 dt) STUB_VOID
void xEntEndUpdate(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xEntDefaultBoundUpdate(xEnt* ent, xVec3* pos) STUB_VOID
void xEntDefaultTranslate(xEnt* ent, xVec3* dpos, xMat4x3* dmat) STUB_VOID
static void xEntRotationToMatrix(xEntFrame*) STUB_VOID
void xEntMotionToMatrix(xEnt* ent, xEntFrame* frame) STUB_VOID
void xEntMove(xEnt* ent, xScene* sc, float32 dt) STUB_VOID

namespace {

	namespace anim_coll {

		void post_move(xEnt&) STUB_VOID;
		void pre_move(xEnt&) STUB_VOID;

	}

}

void xEntApplyPhysics(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xEntCollide(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xEntBeginCollide(xEnt* ent, xScene*, float32) STUB_VOID
void xEntEndCollide(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xEntCollCheckEnv(xEnt* p, xScene* sc) STUB_VOID
static void xEntCollCheckOneGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt, xGrid* grid) STUB_VOID
void xEntCollCheckByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt) STUB_VOID
void xEntCollCheckNPCsByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt) STUB_VOID
void xEntCollCheckStats(xEnt* p, xScene* sc, xEntSceneCallback hitIt) STUB_VOID
void xEntCollCheckDyns(xEnt* p, xScene* sc, xEntSceneCallback hitIt) STUB_VOID
void xEntCollCheckNPCs(xEnt* p, xScene* sc, xEntSceneCallback hitIt) STUB_VOID
xEnt* xEntCollCheckOneEntNoDepen(xEnt* ent, xScene*, void* data) STUB
void xEntCollideFloor(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntCollideCeiling(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntCollideWalls(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntSetNostepNormAngle(float32 angle) STUB_VOID
xBox* xEntGetAllEntsBox() STUB
void xEntAnimateCollision(xEnt& ent, bool on) STUB_VOID
bool xEntValidType(uint8 type) STUB
void xEntReposition(xEnt& ent, const xMat4x3& mat) STUB_VOID
void xEntInitShadow(xEnt& ent, xEntShadow& shadow) STUB_VOID