#include "iEnv.h"

#include "xJSP.h"

static RpAtomic* SetPipelineCB(RpAtomic* atomic, void* data) STUB
static void iEnvSetBSP(iEnv* env, int32 envDataType, RpWorld* bsp) STUB_VOID
void iEnvLoad(iEnv* env, const void* data, uint32, int32 dataType) STUB_VOID
void iEnvFree(iEnv* env) STUB_VOID
void iEnvDefaultLighting(iEnv*) {}
void iEnvLightingBasics(iEnv*, xEnvAsset*) {}
static void Jsp_ClumpRender(RpClump* clump, xJSPNodeInfo* nodeInfo) STUB_VOID
void iEnvRender(iEnv* env) STUB_VOID
void iEnvEndRenderFX(iEnv*) STUB_VOID