#include "zNPCSupplement.h"

void NPCSupplement_Startup() {}
void NPCSupplement_Shutdown() STUB_VOID
void NPCSupplement_ScenePrepare() STUB_VOID
void NPCSupplement_SceneFinish() STUB_VOID
void NPCSupplement_ScenePostInit() STUB_VOID
void NPCSupplement_SceneReset() STUB_VOID
void NPCSupplement_Timestep(float32 dt) STUB_VOID
void NPCC_MakeLightningInfo(en_npclyt style, LightningAdd* info) STUB_VOID
void NPCC_MakeStreakInfo(en_npcstreak styp, StreakInfo* info) STUB_VOID
uint32 NPCC_StreakCreate(en_npcstreak styp) STUB
void NPCC_BurstBubble(en_npcburst burst, xVec3* pos_base) STUB_VOID
void NPCC_MakeASplash(const xVec3* pos, float32 radius) STUB_VOID
void NPCC_Slick_MakePlayerSlip(zNPCCommon* npc) STUB_VOID
void NPCC_RenderProjTexture(RwRaster* rast, float32 factor, xMat4x3* mat, float32 radius, float32 height, xShadowCache* cache, int32 fillCache, xEnt* ent) STUB_VOID
void NPCC_RenderProjTextureFaceCamera(RwRaster* rast, float32 factor, xVec3* pos, float32 radius, float32 height, xShadowCache* cache, int32 fillCache, xEnt* ent) STUB_VOID
void NPAR_ScenePrepare() STUB_VOID
void NPAR_SceneFinish() STUB_VOID
void NPAR_SceneReset() STUB_VOID
static void NPAR_CheckSpecials() STUB_VOID
void NPAR_Timestep(float32 dt) STUB_VOID
NPARMgmt* NPAR_PartySetup(en_nparptyp parType, void** userData, NPARXtraData* xtraData) STUB
NPARMgmt* NPAR_FindParty(en_nparptyp parType) STUB

void NPARMgmt::Init(en_nparptyp parType, void** userData, NPARXtraData* xtraData) STUB_VOID
void NPARMgmt::Clear() STUB_VOID
void NPARMgmt::UpdateAndRender(float32) STUB_VOID

void NPARParmOilBub::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_OilBubble(NPARMgmt* mgmt, float32 dt) STUB_VOID
void NPAR_CopyNPARToPTPool(NPARData*, ptank_pool__pos_color_size_uv2*) STUB_VOID

void NPARParmTubeSpiral::ConfigPar(NPARData*, en_nparmode, const xVec3*, const xVec3*, float32) const STUB_VOID

void NPAR_Upd_TubeSpiral(NPARMgmt* mgmt, float32 dt) STUB_VOID
static void NPAR_TubeSpiralMagic(RwRGBA* color, int32, float32 pam) STUB_VOID

void NPARParmTubeConfetti::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_TubeConfetti(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmGloveDust::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_GloveDust(NPARMgmt* mgmt, float32 dt) STUB_VOID
void NPAR_Upd_MonsoonRain(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmSleepyZeez::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_SleepyZeez(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmChuckSplash::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_ChuckSplash(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmVisSplash::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_VisSplash(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmTarTarGunk::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_TarTarGunk(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmDogBreath::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_DogBreath(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPARParmFahrwerkz::ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const STUB_VOID

void NPAR_Upd_Fireworks(NPARMgmt* mgmt, float32 dt) STUB_VOID

void NPAR_EmitOilShieldPop(const xVec3* pos) STUB_VOID
void NPAR_EmitOilTrailz(const xVec3* pos) STUB_VOID
void NPAR_EmitOilVapors(const xVec3* pos) STUB_VOID
void NPAR_EmitOilSplash(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitOilBubble(en_nparmode, const xVec3*, const xVec3*) STUB_VOID
void NPAR_EmitTubeSpiral(const xVec3* pos, const xVec3* vel, float32 lifespan) STUB_VOID
void NPAR_EmitTubeSpiralCin(const xVec3* pos, const xVec3* vel, float32 lifespan) STUB_VOID
void NPAR_EmitTubeConfetti(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTubeSparklies(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitGloveDust(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitSleepyZeez(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitH2ODrips(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitH2ODrops(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitH2OSpray(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitH2OTrail(const xVec3* pos) STUB_VOID
void NPAR_EmitDroplets(en_nparmode, const xVec3*, const xVec3*) STUB_VOID
void NPAR_EmitTarTarNozzle(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTarTarTrail(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTarTarSplash(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTarTarSpoil(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTarTarSmoke(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitTarTarGunk(en_nparmode, const xVec3*, const xVec3*) STUB_VOID
void NPAR_EmitDoggyWisps(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitDoggyAttack(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitDoggyBreath(en_nparmode, const xVec3*, const xVec3*) STUB_VOID
void NPAR_EmitVSSpray(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitVisSplash(en_nparmode, const xVec3*, const xVec3*) STUB_VOID
void NPAR_EmitFWExhaust(const xVec3* pos, const xVec3* vel) STUB_VOID
void NPAR_EmitFireworks(en_nparmode, const xVec3*, const xVec3*) STUB_VOID

static void NPCC_ShadowCacheReset() STUB_VOID
xShadowCache* NPCC_ShadowCacheReserve() STUB
void NPCC_ShadowCacheRelease(xShadowCache* shadcache) STUB_VOID