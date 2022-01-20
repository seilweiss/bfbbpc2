#pragma once

#include "zEnt.h"

struct xTriggerAsset
{
	xVec3 p[4];
	xVec3 direction;
	uint32 flags;
};

struct zEntTrigger : zEnt
{
	xMat4x3 triggerMatrix;
	xBox triggerBox;
	uint32 entered;
};

void zEntTriggerInit(void* ent, void* asset);
void zEntTriggerInit(zEntTrigger* ent, xEntAsset* asset);
void zEntTriggerUpdate(zEntTrigger* trig, xScene*, float32);
bool32 zEntTriggerEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void zEntTriggerSave(zEntTrigger* ent, xSerial* s);
void zEntTriggerLoad(zEntTrigger* ent, xSerial* s);
void zEntTriggerReset(zEntTrigger*);
bool zEntTriggerHitsSphere(const zEntTrigger& trig, const xSphere& o, const xVec3& dir);