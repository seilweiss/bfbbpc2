#include "zEnt.h"

void zEntInit(zEnt* ent, xEntAsset* asset, uint32 type) STUB_VOID
void zEntSetup(zEnt* ent) STUB_VOID
void zEntSave(zEnt* ent, xSerial* s) STUB_VOID
void zEntLoad(zEnt* ent, xSerial* s) STUB_VOID
void zEntReset(zEnt* ent) STUB_VOID
void zEntUpdate(zEnt* ent, zScene* scene, float32 elapsedSec) STUB_VOID
void zEntEventAll(xBase* from, uint32 fromEvent, uint32 toEvent, float32* toParam) STUB_VOID
void zEntEventAllOfType(xBase*, uint32, uint32, float32*, uint32) STUB_VOID
void zEntEventAllOfType(uint32 toEvent, uint32 type) STUB_VOID
xModelInstance* zEntRecurseModelInfo(void* info, xEnt* ent) STUB
void zEntParseModelInfo(xEnt* ent, uint32 assetID) STUB_VOID
void zEntAnimEvent(zEnt* ent, uint32 animEvent, const float32* animParam) STUB_VOID
xAnimTable* xEnt_AnimTable_AutoEventSmall() STUB
void zEntAnimEvent_AutoAnim(zEnt* ent, uint32 animEvent, const float32* animParam) STUB_VOID
char* zParamGetString(xModelAssetParam*, uint32, char*, char*) STUB
int32 zParamGetInt(xModelAssetParam* param, uint32 size, const char* tok, int32 def) STUB
int32 zParamGetInt(xModelAssetParam* param, uint32 size, char* tok, int32 def) STUB
float32 zParamGetFloat(xModelAssetParam* param, uint32 size, const char* tok, float32 def) STUB
float32 zParamGetFloat(xModelAssetParam* param, uint32 size, char* tok, float32 def) STUB
int32 zParamGetFloatList(xModelAssetParam* param, uint32 size, const char* tok, int32 count, float32* def, float32* result) STUB
int32 zParamGetFloatList(xModelAssetParam* param, uint32 size, char* tok, int32 count, float32* def, float32* result) STUB
int32 zParamGetVector(xModelAssetParam* param, uint32 size, const char* tok, xVec3, xVec3* result) STUB
int32 zParamGetVector(xModelAssetParam* param, uint32 size, char* tok, xVec3, xVec3* result) STUB
void zEntGetShadowParams(xEnt* ent, xVec3* center, float32* radius, xEntShadow::radius_enum rtype) STUB_VOID