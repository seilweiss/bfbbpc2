#include "zEntSimpleObj.h"

void zEntSimpleObj_MgrInit(zEntSimpleObj** entList, uint32 entCount) STUB_VOID
void zEntSimpleObj_MgrUpdateRender(RpWorld*, float32 dt) STUB_VOID
void zEntSimpleObj_MgrCustomUpdate(zScene* s, float32 dt) STUB_VOID
void zEntSimpleObj_MgrCustomRender() STUB_VOID
static void zEntSimpleObj_Render(xEnt* ent) STUB_VOID
void zEntTrackPhysics_Init(void* ent, void* asset) STUB_VOID
void zEntSimpleObj_Init(void* ent, void* asset) STUB_VOID
void zEntSimpleObj_Init(zEntSimpleObj* ent, xEntAsset* asset, bool physparams) STUB_VOID
static void zEntSimpleObj_Move(xEnt*, xScene*, float32, xEntFrame*) STUB_VOID
void zEntSimpleObj_Update(zEntSimpleObj* ent, xScene* sc, float32 dt) STUB_VOID
void zEntSimpleObj_Setup(zEntSimpleObj* ent) STUB_VOID
void zEntSimpleObj_Save(zEntSimpleObj* ent, xSerial* s) STUB_VOID
void zEntSimpleObj_Load(zEntSimpleObj* ent, xSerial* s) STUB_VOID
void zEntSimpleObj_Reset(zEntSimpleObj*, xScene*) STUB_VOID
bool32 zEntSimpleObjEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB