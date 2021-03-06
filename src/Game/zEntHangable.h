#pragma once

#include "zEnt.h"

struct xEntHangableAsset
{
	uint32 flags;
	float32 pivotOffset;
	float32 leverArm;
	float32 gravity;
	float32 accel;
	float32 decay;
	float32 grabDelay;
	float32 stopDecel;
};

struct zEntHangable : zEnt
{
	xEntHangableAsset* hangInfo;
	xVec3 pivot;
	xVec3 endpos;
	xVec3 vel;
	xVec3 swingplane;
	float32 grabTimer;
	float32 spin;
	uint32 state;
	zEnt* shaggy;
	int32 enabled;
	zEnt* follow;
	int32 moving;
	float32 candle_timer;
	int32 candle_state;
};

void zEntHangable_SetupFX();
void zEntHangable_Init(void* ent, void* asset);
void zEntHangable_Init(zEntHangable*, xEntAsset*);
void zEntHangable_Update(zEntHangable* ent, xScene*, float32 dt);
bool32 zEntHangableEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase*);
void zEntHangable_SetMatrix(zEntHangable* ent, float32 dt);
void zEntHangable_Save(zEntHangable* ent, xSerial* s);
void zEntHangable_Load(zEntHangable* ent, xSerial* s);
void zEntHangable_Reset(zEntHangable* ent);
void zEntHangable_SetShaggy(zEntHangable*, zEnt*);
void zEntHangable_FollowUpdate(zEntHangable* ent);
void zEntHangable_SetFollow(zEntHangable*, zEnt*);