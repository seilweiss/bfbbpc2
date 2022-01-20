#pragma once

#include "xBase.h"
#include "xMath3.h"

struct zVolume;
struct xEnt;
struct xScene;

struct zGustAsset : xBaseAsset
{
	uint32 flags;
	uint32 volumeID;
	uint32 effectID;
	xVec3 vel;
	float32 fade;
	float32 partMod;
};

struct zGust : xBase
{
	uint32 flags;
	zGustAsset* asset;
	zVolume* volume;
	zVolume* fx_volume;
	float32 debris_timer;
};

void zGustInit();
void zGustSetup();
void zGustTurnOn(zGust*);
void zGustTurnOff(zGust*);
void zGustToggleOn(zGust*);
zGust* zGustGetGust(uint16 n);
void zGustUpdateEnt(xEnt* ent, xScene*, float32 dt, void* gdata);
void zGustSave(zGust* ent, xSerial* s);
void zGustLoad(zGust* ent, xSerial* s);
void zGustReset(zGust*);
bool32 zGustEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void zGustUpdateFX(float32 seconds);