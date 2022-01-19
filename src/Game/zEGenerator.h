#pragma once

#include "zEnt.h"

struct zLightning;

struct zEGenAsset : xEntAsset
{
	xVec3 src_dpos;
	uint8 damage_type;
	uint8 flags;
	float32 ontime;
	uint32 onAnimID;
};

struct zEGenerator : zEnt
{
	zEGenAsset* zasset;
	uint16 flags;
	uint16 num_dsts;
	float32 tmr;
	xAnimFile* afile;
	xVec3 src_pos;
	xVec3 dst_pos;
	xVec3 dst_off;
	xBase* dst;
	zLightning* lfx[2];
};

void zEGenerator_Init(void* egen, void* asset);
void zEGenerator_Init(zEGenerator* egen, xEntAsset* asset);
void zEGenerator_Save(zEGenerator* ent, xSerial* s);
void zEGenerator_Load(zEGenerator* ent, xSerial* s);
void zEGenerator_Reset(zEGenerator* egen, xScene*);
void zEGenerator_Move(zEGenerator*, xScene*, float32);
void zEGenerator_Update(zEGenerator* egen, xScene* sc, float32 dt);
void zEGenerator_Render(zEGenerator* egen);
void zEGenerator_TurnOn(zEGenerator* egen);
void zEGenerator_TurnOff(zEGenerator*);
bool32 zEGeneratorEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase* toParamWidget);