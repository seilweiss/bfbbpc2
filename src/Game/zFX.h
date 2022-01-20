#pragma once

#include "xMath3.h"
#include "xColor.h"

#include <rwcore.h>
#include <rpworld.h>

struct xEnt;

struct xFXRing
{
	uint32 texture;
	float32 lifetime;
	xVec3 pos;
	float32 time;
	float32 ring_radius;
	float32 ring_radius_delta;
	float32 ring_tilt;
	float32 ring_tilt_delta;
	float32 ring_height;
	float32 ring_height_delta;
	xColor ring_color;
	uint16 ring_segs;
	uint8 u_repeat;
	uint8 v_repeat;
	xFXRing** parent;
};

enum zFXGooState
{
	zFXGooStateNormal,
	zFXGooStateFreezing,
	zFXGooStateFrozen,
	zFXGooStateMelting,
	zFXGooStateInactive = 0xdeadbeef,
	zFXGooStateForce32Bit = 0xffffffff
};

struct zFXGooInstance
{
	RpAtomic* atomic;
	int32 freezeGroup;
	xVec3* orig_verts;
	RwRGBA* orig_colors;
	float32 time;
	float32 timer;
	float32 w0;
	float32 w2;
	float32 warbc[4];
	float32 state_time[4];
	xVec3 center;
	zFXGooState state;
	float32 warb_time;
	float32 alpha;
	float32 min;
	float32 max;
	xVec3* ref_parentPos;
	xVec3 pos_parentOnFreeze;
};

void zFX_SceneEnter(RpWorld* world);
void zFX_SceneExit(RpWorld* world);
void zFX_SceneReset();
void zFXPatrickStun(const xVec3* pos);
void zFXHammer(const xVec3* pos);
void zFXPorterWave(const xVec3* pos);
xFXRing* zFXMuscleArmWave(const xVec3* pos);
void zFXGooEnable(RpAtomic* atomic, int32 freezeGroup);
void zFXGoo_SceneEnter();
void zFXGoo_SceneExit();
void zFXGooUpdateInstance(zFXGooInstance* goo, float32 dt);
void zFXGooUpdate(float32);
RpAtomic* zFXGooRenderAtomic(RpAtomic* atomic);
void zFXUpdate(float32 dt);
void zFXGooFreeze(RpAtomic* atomic, const xVec3* center, xVec3* ref_parPosVec);
bool32 zFXGooIs(xEnt* obj, float32& depth, uint32 playerCheck);
void zFXGooEventSetWarb(xEnt* ent, const float32* warb);
void zFXGooEventSetFreezeDuration(xEnt* ent, float32 duration);
void zFXGooEventMelt(xEnt* ent);
float32 zFXGooFreezeTimeLeft();
void zFX_SpawnBubbleHit(const xVec3* pos, uint32 num);
void zFX_SpawnBubbleHit(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd, float32 vel_scale);
void zFX_SpawnBubbleTrail(const xVec3* pos, uint32 num);
void zFX_SpawnBubbleTrail(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd);
void zFX_SpawnBubbleTrailNoNegRandVel(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd);
void zFX_SpawnBubbleTrail(const xVec3* p1, const xVec3* p2, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd);
void zFX_SpawnBubbleTrail(const xVec3* p1, const xVec3* p2, const xVec3* vel1, const xVec3* vel2, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd, float32 scale);
void zFX_SpawnBubbleMenuTrail(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd);
void zFX_SpawnBubbleWall();
void zFX_SpawnBubbleSlam(const xVec3* pos, uint32 num, float32 rang, float32 bvel, float32 rvel);
void zFX_SpawnBubbleBlast(const xVec3* pos, uint32 num, float32 radius, float32 blast_vel, float32 rand_vel);
void zFXPopOn(xEnt& ent, float32 rate, float32 time);
void zFXPopOff(xEnt& ent, float32 rate, float32 time);
