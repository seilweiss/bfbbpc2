#include "zEntHangable.h"

void zEntHangable_SetupFX() STUB_VOID
static void HangableSetup(zEntHangable* ent, xEntAsset* asset) STUB_VOID
void zEntHangable_Init(void* ent, void* asset) STUB_VOID
void zEntHangable_Init(zEntHangable*, xEntAsset*) STUB_VOID
static void zEntHangable_UpdateFX(zEntHangable* ent) STUB_VOID
void zEntHangable_Update(zEntHangable* ent, xScene*, float32 dt) STUB_VOID
static void zEntHangableMountFX(zEntHangable*) STUB_VOID
bool32 zEntHangableEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB
static bool32 HangableIsMovingTooMuch(xVec3*, xVec3*, xVec3*, xVec3*) STUB
void zEntHangable_SetMatrix(zEntHangable* ent, float32 dt) STUB_VOID
void zEntHangable_Save(zEntHangable* ent, xSerial* s) STUB_VOID
void zEntHangable_Load(zEntHangable* ent, xSerial* s) STUB_VOID
void zEntHangable_Reset(zEntHangable* ent) STUB_VOID
void zEntHangable_SetShaggy(zEntHangable*, zEnt*) STUB_VOID
void zEntHangable_FollowUpdate(zEntHangable* ent) STUB_VOID
void zEntHangable_SetFollow(zEntHangable*, zEnt*) STUB_VOID