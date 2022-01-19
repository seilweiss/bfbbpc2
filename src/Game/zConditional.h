#pragma once

#include "xBase.h"

struct zCondAsset : xBaseAsset
{
	uint32 constNum;
	uint32 expr1;
	uint32 op;
	uint32 value_asset;
};

typedef struct _zConditional : xBase
{
	zCondAsset* asset;
} zConditional;

void zConditionalInit(void* b, void* asset);
void zConditionalInit(xBase*, zCondAsset*);
void zConditionalReset(zConditional*);
void zConditionalSave(zConditional* ent, xSerial* s);
void zConditionalLoad(zConditional* ent, xSerial* s);
uint32 zConditional_Evaluate(zConditional* c);
bool32 zConditionalEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);