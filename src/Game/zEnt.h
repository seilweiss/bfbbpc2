#pragma once

#include "xEnt.h"
#include "xAnim.h"

struct zScene;

struct zEnt : xEnt
{
	xAnimTable* atbl;
};

void zEntInit(zEnt* ent, xEntAsset* asset, uint32 type);
void zEntSetup(zEnt* ent);
void zEntSave(zEnt* ent, xSerial* s);
void zEntLoad(zEnt* ent, xSerial* s);
void zEntReset(zEnt* ent);
void zEntUpdate(zEnt* ent, zScene* scene, float32 elapsedSec);
void zEntEventAll(xBase* from, uint32 fromEvent, uint32 toEvent, float32* toParam);
void zEntEventAllOfType(xBase*, uint32, uint32, float32*, uint32);
void zEntEventAllOfType(uint32 toEvent, uint32 type);
xModelInstance* zEntRecurseModelInfo(void* info, xEnt* ent);
void zEntParseModelInfo(xEnt* ent, uint32 assetID);
void zEntAnimEvent(zEnt* ent, uint32 animEvent, const float32* animParam);
xAnimTable* xEnt_AnimTable_AutoEventSmall();
void zEntAnimEvent_AutoAnim(zEnt* ent, uint32 animEvent, const float32* animParam);
xModelAssetParam* zEntGetModelParams(uint32 assetID, uint32* size);
char* zParamGetString(xModelAssetParam*, uint32, char*, char*);
int32 zParamGetInt(xModelAssetParam* param, uint32 size, const char* tok, int32 def);
int32 zParamGetInt(xModelAssetParam* param, uint32 size, char* tok, int32 def);
float32 zParamGetFloat(xModelAssetParam* param, uint32 size, const char* tok, float32 def);
float32 zParamGetFloat(xModelAssetParam* param, uint32 size, char* tok, float32 def);
int32 zParamGetFloatList(xModelAssetParam* param, uint32 size, const char* tok, int32 count, float32* def, float32* result);
int32 zParamGetFloatList(xModelAssetParam* param, uint32 size, char* tok, int32 count, float32* def, float32* result);
int32 zParamGetVector(xModelAssetParam* param, uint32 size, const char* tok, xVec3, xVec3* result);
int32 zParamGetVector(xModelAssetParam* param, uint32 size, char* tok, xVec3, xVec3* result);
void zEntGetShadowParams(xEnt* ent, xVec3* center, float32* radius, xEntShadow::radius_enum rtype);

inline void checkpoint_collision_hack(zEnt*) STUB_VOID