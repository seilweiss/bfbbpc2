#include "zEntDestructObj.h"

namespace {

	void SwapModel(zEntDestructObj* s, xModelInstance* model) STUB_VOID

}

void zEntDestructObj_FindFX() STUB_VOID
void zEntDestructObj_Init(void* ent, void* asset) STUB_VOID
void zEntDestructObj_Init(zEntDestructObj* ent, xEntAsset* asset) STUB_VOID
void zEntDestructObj_Move(zEntDestructObj*, xScene*, float32, xEntFrame*) STUB_VOID
void zEntDestructObj_Update(zEntDestructObj* ent, xScene* sc, float32 dt) STUB_VOID
void zEntDestructObj_Hit(zEntDestructObj* ent, uint32 mask) STUB_VOID
uint32 zEntDestructObj_GetHit(zEntDestructObj* ent, uint32 mask) STUB
void zEntDestructObj_Save(zEntDestructObj* ent, xSerial* s) STUB_VOID
void zEntDestructObj_Load(zEntDestructObj* ent, xSerial* s) STUB_VOID
void zEntDestructObj_Setup(zEntDestructObj* ent) STUB_VOID
void zEntDestructObj_Reset(zEntDestructObj* ent, xScene*) STUB_VOID
uint32 zEntDestructObj_isDestroyed(zEntDestructObj* ent) STUB
void zEntDestructObj_DestroyFX(zEntDestructObj* o) STUB_VOID
bool32 zEntDestructObjEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB