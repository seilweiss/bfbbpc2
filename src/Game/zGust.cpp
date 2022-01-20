#include "zGust.h"

static void zGustInit(zGust*, zGustAsset*) STUB_VOID
static void zGustSetup(zGust*) STUB_VOID
void zGustInit() STUB_VOID
void zGustSetup() STUB_VOID
void zGustTurnOn(zGust*) STUB_VOID
void zGustTurnOff(zGust*) STUB_VOID
void zGustToggleOn(zGust*) STUB_VOID
zGust* zGustGetGust(uint16 n) STUB
void zGustUpdateEnt(xEnt* ent, xScene*, float32 dt, void* gdata) STUB_VOID
void zGustSave(zGust* ent, xSerial* s) STUB_VOID
void zGustLoad(zGust* ent, xSerial* s) STUB_VOID
void zGustReset(zGust*) STUB_VOID
bool32 zGustEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
static void UpdateGustFX(zGust* g, float32 seconds) STUB_VOID
void zGustUpdateFX(float32 seconds) STUB_VOID