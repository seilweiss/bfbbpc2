#include "zEnv.h"

void zEnvInit(void* env, void* easset) STUB_VOID
void zEnvInit(zEnv* env, xEnvAsset* easset) STUB_VOID
void zEnvSetup(zEnv* env) STUB_VOID
void zEnvStartingCamera(zEnv* env) STUB_VOID
void zEnvRender(xEnv* env) STUB_VOID
void zEnvSave(zEnv* ent, xSerial* s) STUB_VOID
void zEnvLoad(zEnv* ent, xSerial* s) STUB_VOID
void zEnvReset(zEnv*) STUB_VOID
bool32 zEnvEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB