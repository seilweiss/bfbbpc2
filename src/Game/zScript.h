#pragma once

#include "xBase.h"

struct xScene;

struct xScriptAsset : xBaseAsset
{
	float32 scriptStartTime;
	uint32 eventCount;
};

typedef struct _zScript : xBase
{
	xScriptAsset* tasset;
	uint8 state;
	uint8 more;
	uint8 pad[2];
	float32 time;
} zScript;

void zScriptInit(void* b, void* tasset);
void zScriptInit(xBase*, xScriptAsset*);
void zScriptReset(zScript*);
void zScriptSave(zScript* ent, xSerial* s);
void zScriptLoad(zScript* ent, xSerial* s);
bool32 zScriptEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void zScriptUpdate(xBase* to, xScene*, float32 dt);
