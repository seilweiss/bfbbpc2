#include "zEntTrigger.h"

void zEntTriggerInit(void* ent, void* asset) STUB_VOID
void zEntTriggerInit(zEntTrigger* ent, xEntAsset* asset) STUB_VOID
void zEntTriggerUpdate(zEntTrigger* trig, xScene*, float32) STUB_VOID
bool32 zEntTriggerEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
void zEntTriggerSave(zEntTrigger* ent, xSerial* s) STUB_VOID
void zEntTriggerLoad(zEntTrigger* ent, xSerial* s) STUB_VOID
void zEntTriggerReset(zEntTrigger*) STUB_VOID
bool zEntTriggerHitsSphere(const zEntTrigger& trig, const xSphere& o, const xVec3& dir) STUB