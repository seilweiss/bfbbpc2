#pragma once

#include "xEnt.h"
#include "xMemMgr.h"

struct xScene
{
	uint32 sceneID;
	uint16 flags;
	uint16 num_ents;
	uint16 num_trigs;
	uint16 num_stats;
	uint16 num_dyns;
	uint16 num_npcs;
	uint16 num_act_ents;
	uint16 num_nact_ents;
	float32 gravity;
	float32 drag;
	float32 friction;
	uint16 num_ents_allocd;
	uint16 num_trigs_allocd;
	uint16 num_stats_allocd;
	uint16 num_dyns_allocd;
	uint16 num_npcs_allocd;
	xEnt** trigs;
	xEnt** stats;
	xEnt** dyns;
	xEnt** npcs;
	xEnt** act_ents;
	xEnt** nact_ents;
	xEnv* env;
	xMemPool mempool;
	xBase* (*resolvID)(uint32);
	char* (*base2Name)(xBase*);
	char* (*id2Name)(uint32);
};

#define XSCENE_UNK0x1 0x1
#define XSCENE_UNK0x2 0x2
#define XSCENE_UNK0x4 0x4

struct xNearFloorPoly
{
	xBox box;
	xVec3 center;
	xVec3 facingVec;
	float32 facingDot;
	float32 floorDot;
	xVec3 vert[3];
	float32 neardist;
	xVec3 nearpt;
	int32 nearvert;
	int32 nearedge;
	uint32 oid;
	void* optr;
	xModelInstance* mptr;
};

extern xScene* g_xSceneCur;

typedef void(*xRayHitsGridCallback)(xScene*, xRay3*, xQCData*, xEnt*, void*);

void xSceneInit(xScene* sc, uint16 num_trigs, uint16 num_stats, uint16 num_dyns, uint16 num_npcs);
void xSceneExit(xScene*);
void xSceneSave(xScene*, xSerial*);
void xSceneLoad(xScene*, xSerial*);
void xSceneSetup(xScene* sc);
void xSceneAddEnt(xScene* sc, xEnt* ent);
xBase* xSceneResolvID(xScene* sc, uint32 id);
char* xSceneID2Name(xScene* sc, uint32 id);
void xSceneForAllEnts(xScene* sc, xEntSceneCallback func, void* data);
void xSceneForAllStatics(xScene* sc, xEntSceneCallback func, void* data);
void xSceneForAllDynamics(xScene* sc, xEntSceneCallback func, void* data);
void xSceneForAllNPCs(xScene* sc, xEntSceneCallback func, void* data);
void xRayHitsGrid(xGrid* grid, xScene* sc, xRay3* r, xRayHitsGridCallback rentcb, xQCData* qcr, void* data);
void xRayHitsTikiLandableEnt(xScene*, xRay3* r, xQCData* qcr, xEnt* ent, void* colldata);
void xRayHitsEnt(xScene*, xRay3* r, xQCData* qcr, xEnt* ent, void* colldata);
void xRayHitsTikiLandableScene(xScene* sc, xRay3* r, xCollis* coll);
void xRayHitsScene(xScene* sc, xRay3* r, xCollis* coll);
void xRayHitsSceneFlags(xScene* sc, xRay3* r, xCollis* coll, uint8 collType, uint8 chk);
uint32 xSceneNearestFloorPoly(xScene* sc, xNearFloorPoly* nfpoly, uint8 collType, uint8 chk);