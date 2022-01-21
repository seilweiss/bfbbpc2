#include "zScript.h"

void zScriptInit(void* b, void* tasset) STUB_VOID
void zScriptInit(xBase*, xScriptAsset*) STUB_VOID
void zScriptReset(zScript*) STUB_VOID
void zScriptSave(zScript* ent, xSerial* s) STUB_VOID
void zScriptLoad(zScript* ent, xSerial* s) STUB_VOID
bool32 zScriptEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
static void zScriptExecuteEvents(zScript* t, float32 start, float32 end) STUB_VOID
void zScriptUpdate(xBase* to, xScene*, float32 dt) STUB_VOID