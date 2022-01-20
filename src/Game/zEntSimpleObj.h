#pragma once

#include "zEnt.h"

struct xSimpleObjAsset
{
	float32 animSpeed;
	uint32 initAnimState;
	uint8 collType;
	uint8 flags;
};

struct zEntSimpleObj : zEnt
{
	xSimpleObjAsset* sasset;
	uint32 sflags;
	void* anim;
	float32 animTime;
};

void zEntSimpleObj_MgrInit(zEntSimpleObj** entList, uint32 entCount);
void zEntSimpleObj_MgrUpdateRender(RpWorld*, float32 dt);
void zEntSimpleObj_MgrCustomUpdate(zScene* s, float32 dt);
void zEntSimpleObj_MgrCustomRender();
void zEntTrackPhysics_Init(void* ent, void* asset);
void zEntSimpleObj_Init(void* ent, void* asset);
void zEntSimpleObj_Init(zEntSimpleObj* ent, xEntAsset* asset, bool physparams);
void zEntSimpleObj_Update(zEntSimpleObj* ent, xScene* sc, float32 dt);
void zEntSimpleObj_Setup(zEntSimpleObj* ent);
void zEntSimpleObj_Save(zEntSimpleObj* ent, xSerial* s);
void zEntSimpleObj_Load(zEntSimpleObj* ent, xSerial* s);
void zEntSimpleObj_Reset(zEntSimpleObj*, xScene*);
bool32 zEntSimpleObjEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
