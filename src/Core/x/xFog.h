#pragma once

#include "xBase.h"

struct xScene;

struct xFogAsset : xBaseAsset
{
	uint8 bkgndColor[4];
	uint8 fogColor[4];
	float32 fogDensity;
	float32 fogStart;
	float32 fogStop;
	float32 transitionTime;
	uint8 fogType;
	uint8 padFog[3];
};

typedef struct _xFog : xBase
{
	xFogAsset* tasset;
} xFog;

void xFogClearFog();
void xFogInit(void* b, void* tasset);
void xFogInit(xBase*, xFogAsset*);
void xFogReset(xFog*);
void xFogSave(xFog* ent, xSerial* s);
void xFogLoad(xFog* ent, xSerial* s);
bool32 xFogEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void xFogUpdate(xBase*, xScene*, float32);
