#include "zLight.h"

void zLightResetAll(xEnv* env) STUB_VOID
void zLightInit(void* b, void* tasset) STUB_VOID
void zLightInit(xBase* b, zLightAsset* tasset) STUB_VOID
void zLightResolveLinks() STUB_VOID
void zLightDestroyAll() STUB_VOID
void zLightDestroy(zLight*) STUB_VOID
void zLightReset(zLight*) STUB_VOID
void zLightSave(zLight* ent, xSerial* s) STUB_VOID
void zLightLoad(zLight* ent, xSerial* s) STUB_VOID
bool32 zLightEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
void zLightUpdate(xBase* to, xScene*, float32 dt) STUB_VOID
void zLightAddLocalEnv() STUB_VOID
void zLightAddLocal(xEnt* ent) STUB_VOID
void zLightRemoveLocalEnv() STUB_VOID
void zLightSetVolume(zVolume* vol) STUB_VOID
void zLightEffectSet(zLight*, int32) STUB_VOID
void zLightOn(zLight* zl, int32 on) STUB_VOID