#pragma once

#include "xEnt.h"

typedef void(*xFFXDoEffectCallback)(xEnt*, xScene*, float32, void*);

struct xFFX
{
	uint32 flags;
	xFFXDoEffectCallback doEffect;
	void* fdata;
	xFFX* next;
};

struct xFFXShakeState
{
	xVec3 disp;
	float32 dur;
	float32 freq;
	float32 tmr;
	float32 alpha;
	float32 lval;
	xFFXShakeState* next;
};

struct xFFXRotMatchState
{
	int32 lgrounded;
	xVec3 lfup;
	xVec3 lfat;
	xVec3 plfat;
	float32 tmr;
	float32 mrate;
	float32 tmatch;
	float32 rrate;
	float32 trelax;
	float32 max_decl;
	xFFXRotMatchState* next;
};

void xFFXPoolInit(uint32 num_ffx);
xFFX* xFFXAlloc();
void xFFXFree(xFFX*);
void xFFXTurnOn(xFFX* f);
void xFFXTurnOff(xFFX* f);
int16 xFFXAddEffect(xEnt* ent, xFFX* f);
int16 xFFXAddEffect(xEnt* ent, xFFXDoEffectCallback dof, void* fd);
bool32 xFFXRemoveEffectByFData(xEnt*, void*);
void xFFXApply(xEnt* ent, xScene* sc, float32 dt);
void xFFXShakeUpdateEnt(xEnt* ent, xScene*, float32 dt, void* fdata);
void xFFXShakePoolInit(uint32 num);
xFFXShakeState* xFFXShakeAlloc();
void xFFXShakeFree(xFFXShakeState* s);
void xFFXRotMatchPoolInit(uint32 num);
xFFXRotMatchState* xFFXRotMatchAlloc();
