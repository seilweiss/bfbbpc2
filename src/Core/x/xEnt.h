#pragma once

#include "xBase.h"
#include "xMath3.h"
#include "xModel.h"
#include "xCollide.h"
#include "xGrid.h"
#include "xBound.h"

struct xEnt;
struct xScene;
struct xEntFrame;
struct xEntCollis;
struct xFFX;
struct xShadowSimpleCache;

typedef void(*xEntCollisPostCallback)(xEnt*, xScene*, float32, xEntCollis*);
typedef uint32(*xEntCollisDepenqCallback)(xEnt*, xEnt*, xScene*, float32, xCollis*);
typedef void(*xEntUpdateCallback)(xEnt*, xScene*, float32);
typedef void(*xEntEndUpdateCallback)(xEnt*, xScene*, float32);
typedef void(*xEntBoundUpdateCallback)(xEnt*, xVec3*);
typedef void(*xEntMoveCallback)(xEnt*, xScene*, float32, xEntFrame*);
typedef void(*xEntRenderCallback)(xEnt*);
typedef void(*xEntTranslateCallback)(xEnt*, xVec3*, xMat4x3*);

typedef xEnt* (*xEntSceneCallback)(xEnt*, xScene*, void*);

struct xEntAsset : xBaseAsset
{
	uint8 flags;
	uint8 subtype;
	uint8 pflags;
	uint8 moreFlags;
	uint8 pad;
	uint32 surfaceID;
	xVec3 ang;
	xVec3 pos;
	xVec3 scale;
	float32 redMult;
	float32 greenMult;
	float32 blueMult;
	float32 seeThru;
	float32 seeThruSpeed;
	uint32 modelInfoID;
	uint32 animListID;
};

struct xEntFrame
{
	xMat4x3 mat;
	xMat4x3 oldmat;
	xVec3 oldvel;
	xRot oldrot;
	xRot drot;
	xRot rot;
	xVec3 dpos;
	xVec3 dvel;
	xVec3 vel;
	uint32 mode;
};

struct xEntCollis
{
	uint8 chk;
	uint8 pen;
	uint8 env_sidx;
	uint8 env_eidx;
	uint8 npc_sidx;
	uint8 npc_eidx;
	uint8 dyn_sidx;
	uint8 dyn_eidx;
	uint8 stat_sidx;
	uint8 stat_eidx;
	uint8 idx;
	xCollis colls[18];
	xEntCollisPostCallback post;
	xEntCollisDepenqCallback depenq;
};

struct xEntShadow
{
	enum radius_enum
	{
		RADIUS_CACHE,
		RADIUS_RASTER,
		MAX_RADIUS
	};

	xVec3 pos;
	xVec3 vec;
	RpAtomic* shadowModel;
	float32 dst_cast;
	float32 radius[2];
};

struct xEnt : xBase
{
	struct anim_coll_data;

	xEntAsset* asset;
	uint16 idx;
	uint16 num_updates;
	uint8 flags;
	uint8 miscflags;
	uint8 subType;
	uint8 pflags;
	uint8 moreFlags;
	uint8 isCulled;
	uint8 driving_count;
	uint8 num_ffx;
	uint8 collType;
	uint8 collLev;
	uint8 chkby;
	uint8 penby;
	xModelInstance* model;
	xModelInstance* collModel;
	xModelInstance* camcollModel;
	xLightKit* lightKit;
	xEntUpdateCallback update;
	xEntEndUpdateCallback endUpdate;
	xEntBoundUpdateCallback bupdate;
	xEntMoveCallback move;
	xEntRenderCallback render;
	xEntFrame* frame;
	xEntCollis* collis;
	xGridBound gridb;
	xBound bound;
	xEntTranslateCallback transl;
	xFFX* ffx;
	xEnt* driver;
	int32 driveMode;
	xShadowSimpleCache* simpShadow;
	xEntShadow* entShadow;
	anim_coll_data* anim_coll;
	void* user_data;
};

#define XENT_UNK0x1 0x1
#define XENT_UNK0x80 0x80
#define XENT_UNK0x81 (XENT_UNK0x1 | XENT_UNK0x80)

#define XENT_COLLTYPE_NONE 0x0 // none
#define XENT_COLLTYPE_TRIG 0x1 // trigger (TRIG)
#define XENT_COLLTYPE_STAT 0x2 // static (SIMP)
#define XENT_COLLTYPE_DYN 0x4 // dynamic (PLAT)
#define XENT_COLLTYPE_NPC 0x8 // npc/enemy (VIL)
#define XENT_COLLTYPE_PLYR 0x10 // player (PLYR)

void xEntSetTimePassed(float32 sec);
void xEntSceneInit();
void xEntSceneExit();
void xEntInit(xEnt* ent, xEntAsset* asset);
void xEntInitForType(xEnt* ent);
void xEntSetup(xEnt* ent);
void xEntSave(xEnt* ent, xSerial* s);
void xEntLoad(xEnt* ent, xSerial* s);
void xEntReset(xEnt* ent);
xModelInstance* xEntLoadModel(xEnt* ent, RpAtomic* imodel);
void xEntSetupPipeline(xModelInstance* model);
void xEntSetupPipeline(xSurface* surf, RpAtomic* model);
void xEntRestorePipeline(xModelInstance* model);
void xEntRestorePipeline(xSurface*, RpAtomic* model);
void xEntRender(xEnt* ent);
void xEntUpdate(xEnt* ent, xScene* sc, float32 dt);
void xEntBeginUpdate(xEnt* ent, float32 dt);
void xEntEndUpdate(xEnt* ent, xScene* sc, float32 dt);
void xEntDefaultBoundUpdate(xEnt* ent, xVec3* pos);
void xEntDefaultTranslate(xEnt* ent, xVec3* dpos, xMat4x3* dmat);
void xEntMotionToMatrix(xEnt* ent, xEntFrame* frame);
void xEntMove(xEnt* ent, xScene* sc, float32 dt);
void xEntApplyPhysics(xEnt* ent, xScene* sc, float32 dt);
void xEntCollide(xEnt* ent, xScene* sc, float32 dt);
void xEntBeginCollide(xEnt* ent, xScene*, float32);
void xEntEndCollide(xEnt* ent, xScene* sc, float32 dt);
void xEntCollCheckEnv(xEnt* p, xScene* sc);
void xEntCollCheckByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt);
void xEntCollCheckNPCsByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt);
void xEntCollCheckStats(xEnt* p, xScene* sc, xEntSceneCallback hitIt);
void xEntCollCheckDyns(xEnt* p, xScene* sc, xEntSceneCallback hitIt);
void xEntCollCheckNPCs(xEnt* p, xScene* sc, xEntSceneCallback hitIt);
xEnt* xEntCollCheckOneEntNoDepen(xEnt* ent, xScene*, void* data);
void xEntCollideFloor(xEnt* p, xScene* sc, float32 dt);
void xEntCollideCeiling(xEnt* p, xScene* sc, float32 dt);
void xEntCollideWalls(xEnt* p, xScene* sc, float32 dt);
void xEntSetNostepNormAngle(float32 angle);
xBox* xEntGetAllEntsBox();
void xEntAnimateCollision(xEnt& ent, bool on);
bool xEntValidType(uint8 type);
void xEntReposition(xEnt& ent, const xMat4x3& mat);
void xEntInitShadow(xEnt& ent, xEntShadow& shadow);

inline uint32 xEntIsEnabled(xEnt*) STUB
inline void xEntEnable(xEnt*) STUB_VOID

inline uint32 xEntIsVisible(const xEnt* ent)
{
	return (ent->flags & XENT_UNK0x81) == XENT_UNK0x1;
}

inline void xEntShow(xEnt*) STUB_VOID
inline void xEntHide(xEnt*) STUB_VOID
inline xVec3* xEntGetPos(const xEnt*) STUB
inline xVec3* xEntGetCenter(const xEnt*) STUB
inline xMat4x3* xEntGetFrame(const xEnt* ent) STUB