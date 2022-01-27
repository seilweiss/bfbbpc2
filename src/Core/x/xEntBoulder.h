#pragma once

#include "xEnt.h"
#include "xShadowSimple.h"
#include "xDynAsset.h"

struct xEntBoulderAsset
{
	float32 gravity;
	float32 mass;
	float32 bounce;
	float32 friction;
	float32 statFric;
	float32 maxVel;
	float32 maxAngVel;
	float32 stickiness;
	float32 bounceDamp;
	uint32 flags;
	float32 killtimer;
	uint32 hitpoints;
	uint32 soundID;
	float32 volume;
	float32 minSoundVel;
	float32 maxSoundVel;
	float32 innerRadius;
	float32 outerRadius;
};

struct xEntBoulder : xEnt
{
	xEntBoulderAsset* basset;
	xShadowSimpleCache simpShadow_embedded;
	xEntShadow entShadow_embedded;
	xVec3 localCenter;
	xVec3 vel;
	xVec3 rotVec;
	xVec3 force;
	xVec3 instForce;
	float32 angVel;
	float32 timeToLive;
	int32 hitpoints;
	float32 lastRolling;
	uint32 rollingID;
	uint8 collis_chk;
	uint8 collis_pen;
	uint8 pad1[2];
};

struct xBoulderGeneratorAsset : xDynAsset
{
	uint32 object;
	xVec3 offset;
	float32 offsetRand;
	xVec3 initvel;
	float32 velAngleRand;
	float32 velMagRand;
	xVec3 initaxis;
	float32 angvel;
};

struct xBoulderGenerator : xBase
{
	xBoulderGeneratorAsset* bgasset;
	int32 numBoulders;
	int32 nextBoulder;
	xEntBoulder** boulderList;
	int32* boulderAges;
	uint32 isMarker;
	void* objectPtr;
	float32 lengthOfInitVel;
	xVec3 perp1;
	xVec3 perp2;
};

void xEntBoulder_FitToModel(xEntBoulder*);
void xEntBoulder_Render(xEnt* ent);
void xEntBoulder_Init(void* ent, void* asset);
void xEntBoulder_Init(xEntBoulder* ent, xEntAsset* asset);
void xEntBoulder_ApplyForces(xEntCollis* collis);
void xEntBoulder_AddInstantForce(xEntBoulder*, xVec3*);
void xEntBoulder_AddForce(xEntBoulder* ent, xVec3* force);
void xEntBoulder_BUpdate(xEnt*, xVec3*);
void xEntBoulder_RealBUpdate(xEnt* ent, xVec3* pos);
void xEntBoulder_Update(xEntBoulder* ent, xScene* sc, float32 dt);
bool32 xEntBoulder_KilledBySurface(xEntBoulder* ent, xScene*, float32);
void xEntBoulder_Kill(xEntBoulder* ent);
void xEntBoulder_BubbleBowl(float32 multiplier);
void xEntBoulder_Setup(xEntBoulder* ent);
void xEntBoulder_Reset(xEntBoulder* ent, xScene*);
bool32 xEntBoulderEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void xBoulderGenerator_Init(xBase& data, xDynAsset& asset, ulong32);
void xBoulderGenerator_Init(xBoulderGenerator* bg, xBoulderGeneratorAsset* asset);
void xBoulderGenerator_Reset(xBoulderGenerator*);
void xBoulderGenerator_Launch(xBoulderGenerator* bg, xVec3* pnt, float32 t);
bool32 xBoulderGenerator_EventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void xBoulderGenerator_GenBoulder(xBoulderGenerator* bg);