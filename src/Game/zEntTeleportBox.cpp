#include "zEntTeleportBox.h"

static void VecFromAngle(float32, xVec3*) STUB_VOID
uint32 OpenCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JumpInCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JumpInCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JumpOutCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JumpOutCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JItoOCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JItoOCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JOtoOCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JOtoOCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 CtoOCheck(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 CtoOCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 JumpInEffectPlrInvisibleCB(uint32, xAnimActiveEffect*, xAnimSingle*, void*) STUB
static uint32 JumpInEffectPlrTeleportCB(uint32, xAnimActiveEffect*, xAnimSingle*, void* object) STUB
static uint32 JumpInEffectJIAnimCB(uint32, xAnimActiveEffect*, xAnimSingle*, void* object) STUB
static uint32 CtoOEffectTboxEnableCB(uint32, xAnimActiveEffect*, xAnimSingle*, void* object) STUB
static uint32 JumpOutEffectPlrVisibleCB(uint32, xAnimActiveEffect*, xAnimSingle*, void*) STUB
static uint32 JumpOutEffectPlrEjectCB(uint32, xAnimActiveEffect*, xAnimSingle*, void* object) STUB
static uint32 JumpOutEffectJOAnimCB(uint32, xAnimActiveEffect*, xAnimSingle*, void* object) STUB
void zEntTeleportBox_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void zEntTeleportBox_Init(zEntTeleportBox* ent, teleport_asset* asset) STUB_VOID
void zEntTeleportBox_InitAll() STUB_VOID
void zEntTeleportBox_Setup(zEntTeleportBox* ent) STUB_VOID
void zEntTeleportBox_Update(xEnt* rawent, xScene* sc, float32 dt) STUB_VOID
void zEntTeleportBox_Save(zEntTeleportBox* ent, xSerial* s) STUB_VOID
void zEntTeleportBox_Load(zEntTeleportBox* ent, xSerial* s) STUB_VOID
void zEntTeleportBox_Open(zEntTeleportBox*) STUB_VOID
void zEntTeleportBox_Close(zEntTeleportBox*) STUB_VOID
uint32 zEntTeleportBox_isOpen(zEntTeleportBox*) STUB
uint32 zEntTeleportBox_isClosed(zEntTeleportBox*) STUB
bool32 zEntTeleportBox_playerIn() STUB
bool32 zEntTeleportBoxEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB