#pragma once

#include "zEnt.h"

struct zEntDestructObj;
struct zParEmitter;
struct zShrapnelAsset;
struct xSFXAsset;

typedef void(*zEntDestructObjDestroyCallback)(zEntDestructObj&, void*);

struct zEntDestructObjAsset
{
	float32 animSpeed;
	uint32 initAnimState;
	uint32 health;
	uint32 spawnItemID;
	uint32 dflags;
	uint8 collType;
	uint8 fxType;
	uint8 pad[2];
	float32 blast_radius;
	float32 blast_strength;
	uint32 shrapnelID_destroy;
	uint32 shrapnelID_hit;
	uint32 sfx_destroy;
	uint32 sfx_hit;
	uint32 hitModel;
	uint32 destroyModel;
};

struct zEntDestructObj : zEnt
{
	zEntDestructObjAsset* dasset;
	uint32 state;
	uint32 healthCnt;
	float32 fx_timer;
	zParEmitter* fx_emitter;
	float32 respawn_timer;
	uint32 throw_target;
	zShrapnelAsset* shrapnel_destroy;
	zShrapnelAsset* shrapnel_hit;
	xModelInstance* base_model;
	xModelInstance* hit_model;
	xModelInstance* destroy_model;
	zEntDestructObjDestroyCallback destroy_notify;
	void* notify_context;
	xSFXAsset* sfx_destroy;
	xSFXAsset* sfx_hit;
};

void zEntDestructObj_FindFX();
void zEntDestructObj_Init(void* ent, void* asset);
void zEntDestructObj_Init(zEntDestructObj* ent, xEntAsset* asset);
void zEntDestructObj_Move(zEntDestructObj*, xScene*, float32, xEntFrame*);
void zEntDestructObj_Update(zEntDestructObj* ent, xScene* sc, float32 dt);
void zEntDestructObj_Hit(zEntDestructObj* ent, uint32 mask);
uint32 zEntDestructObj_GetHit(zEntDestructObj* ent, uint32 mask);
void zEntDestructObj_Save(zEntDestructObj* ent, xSerial* s);
void zEntDestructObj_Load(zEntDestructObj* ent, xSerial* s);
void zEntDestructObj_Setup(zEntDestructObj* ent);
void zEntDestructObj_Reset(zEntDestructObj* ent, xScene*);
uint32 zEntDestructObj_isDestroyed(zEntDestructObj* ent);
void zEntDestructObj_DestroyFX(zEntDestructObj* o);
bool32 zEntDestructObjEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
