#include "zLightning.h"

#include "xDebug.h"

static void lightningTweakChangeType(const tweak_info&) STUB_VOID
static void lightningTweakStart(const tweak_info&) STUB_VOID
void zLightningInit() STUB_VOID
static zLightning* FindFreeLightning() STUB
zLightning* zLightningAdd(LightningAdd* add) STUB
static void UpdateLightning(zLightning* l, float32 seconds) STUB_VOID
void zLightningUpdate(float32 seconds) STUB_VOID
static void zLightningFunc_Render(zLightning* l) STUB_VOID
static void RenderLightning(zLightning* l) STUB_VOID
void zLightningRender() STUB_VOID
void zLightningShow(zLightning* l, bool32 show) STUB_VOID
void zLightningKill(zLightning* l) STUB_VOID
void zLightningModifyEndpoints(zLightning* l, xVec3* start, xVec3* end) STUB_VOID