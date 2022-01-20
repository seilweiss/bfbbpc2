#pragma once

#include "xBase.h"
#include "iLight.h"

struct xEnv;
struct xScene;
struct xEnt;
struct zVolume;

struct zLightAsset : xBaseAsset
{
	uint8 lightType;
	uint8 lightEffect;
	uint8 lightPad[2];
	uint32 lightFlags;
	float32 lightColor[4];
	xVec3 lightDir;
	float32 lightConeAngle;
	xSphere lightSphere;
	uint32 attachID;
};

typedef struct _zLight : xBase
{
	uint32 flags;
	zLightAsset* tasset;
	iLight light;
	xBase* attached_to;
	int32 true_idx;
	float32* reg;
	int32 effect_idx;
} zLight;

void zLightResetAll(xEnv* env);
void zLightInit(void* b, void* tasset);
void zLightInit(xBase* b, zLightAsset* tasset);
void zLightResolveLinks();
void zLightDestroyAll();
void zLightDestroy(zLight*);
void zLightReset(zLight*);
void zLightSave(zLight* ent, xSerial* s);
void zLightLoad(zLight* ent, xSerial* s);
bool32 zLightEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void zLightUpdate(xBase* to, xScene*, float32 dt);
void zLightAddLocalEnv();
void zLightAddLocal(xEnt* ent);
void zLightRemoveLocalEnv();
void zLightSetVolume(zVolume* vol);
void zLightEffectSet(zLight*, int32);
void zLightOn(zLight* zl, int32 on);