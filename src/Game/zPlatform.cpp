#include "zPlatform.h"

static void genericPlatRender(xEnt* ent) STUB_VOID
void zPlatform_Init(void* plat, void* asset) STUB_VOID
void zPlatform_Init(zPlatform* plat, xEntAsset* asset) STUB_VOID
void zPlatform_Setup(zPlatform* plat, xScene*) STUB_VOID
void zPlatform_Save(zPlatform* ent, xSerial* s) STUB_VOID
void zPlatform_Load(zPlatform* ent, xSerial* s) STUB_VOID
void zPlatform_Reset(zPlatform* plat, xScene* sc) STUB_VOID
static bool32 zMechIsStartingForth(zPlatform*, uint16) STUB
static bool32 zMechIsStartingBack(zPlatform*, uint16) STUB
static float32 SolvePaddleMotion(zPlatform* plat, float32* time, float32 tmr) STUB
void zPlatform_PaddleStartRotate(xEnt* entplat, int32 direction, int32 stutter) STUB_VOID
uint32 zPlatform_PaddleCollide(xCollis* coll, const xVec3* hitsource, const xVec3* hitvel, uint32 worldSpaceNorm) STUB
static void zPlatFM_Update(zPlatform* plat, xScene*, float32 dt) STUB_VOID
void zPlatform_Update(xEnt* entplat, xScene* sc, float32 dt) STUB_VOID
void zPlatform_Move(xEnt* entplat, xScene* s, float32 dt, xEntFrame* frame) STUB_VOID
void zPlatform_Shake(zPlatform* plat, float32, float32 ampl, float32 freq) STUB_VOID
static void zPlatform_Tremble(zPlatform* plat, float32 ampl, float32 freq, float32 dur) STUB_VOID
static void zPlatform_BreakawayFallFX(zPlatform*, float32) STUB_VOID
void zPlatform_Mount(zPlatform* plat) STUB_VOID
void zPlatform_Dismount(zPlatform* plat) STUB_VOID
static void zPlatformTranslate(xEnt* xent, xVec3* dpos, xMat4x3* dmat) STUB_VOID
static void zPlatFM_EventSetup(zPlatform* plat, const float32* toParam, int32 idx) STUB_VOID
bool32 zPlatformEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB