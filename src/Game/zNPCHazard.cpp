#include "zNPCHazard.h"

void zNPCHazard_Startup() STUB_VOID
void zNPCHazard_Shutdown() {}
void zNPCHazard_ScenePrepare() STUB_VOID
void zNPCHazard_SceneFinish() STUB_VOID
void zNPCHazard_SceneReset() STUB_VOID
void zNPCHazard_ScenePostInit() STUB_VOID
void zNPCHazard_InitEffects() STUB_VOID
void zNPCHazard_KillEffects() {}
static int32 HAZ_ord_sorttest(void* vkey, void* vitem) STUB
void zNPCHazard_Timestep(float32 dt) STUB_VOID
void zNPCCommon_Hazards_RenderAll(bool32 doOpaqueStuff) STUB_VOID
NPCHazard* HAZ_Acquire() STUB
int32 HAZ_AvailablePool() STUB
void HAZ_Iterate(HAZ_Iterate_Callback fp, void* context, int32 flag_filter) STUB_VOID

void NPCHazard::WipeIt() STUB_VOID
bool32 NPCHazard::ConfigHelper(en_npchaz haztype) STUB
void NPCHazard::Reconfigure(en_npchaz haztype) STUB_VOID
UVAModelInfo* NPCHazard::GetUVAInfo(en_hazmodel, float32, float32) STUB
bool32 NPCHazard::GrabModel(en_hazmodel idx_model) STUB
void NPCHazard::FreeModel() STUB_VOID
void NPCHazard::Discard() STUB_VOID
void NPCHazard::Kill() STUB_VOID
void NPCHazard::Start(const xVec3* pos, float32 tym) STUB_VOID
void NPCHazard::PosSet(const xVec3* pos) STUB_VOID
void NPCHazard::Timestep(float32 dt) STUB_VOID
void NPCHazard::Render() STUB_VOID
void NPCHazard::Cleanup() STUB_VOID
void NPCHazard::SetAlpha(float32) STUB_VOID
bool32 NPCHazard::ColTestSphere(const xBound*, float32) STUB
bool32 NPCHazard::ColTestCyl(const xBound* bnd_tgt, float32 rad, float32 hyt) STUB
bool32 NPCHazard::ColPlyrSphere(float32) STUB
bool32 NPCHazard::ColPlyrCyl(float32, float32) STUB
void NPCHazard::HurtThePlayer() STUB_VOID
void NPCHazard::TypData_RotMatStore(xVec3*) STUB_VOID
void NPCHazard::TypData_RotMatSet(xMat3x3*) STUB_VOID
void NPCHazard::TypData_RotMatApply(xMat3x3*) STUB_VOID
void NPCHazard::OrientToDir(const xVec3* vec_path, bool32 doTheTwist) STUB_VOID
en_hazmodel NPCHazard::PickFunFrag() STUB
void NPCHazard::PreCollide() STUB_VOID
int32 NPCHazard::StaggeredCollide() STUB
void NPCHazard::StagColGeneral(int32 who) STUB_VOID
void NPCHazard::StagColStat() STUB_VOID
void NPCHazard::StagColDyn() STUB_VOID
void NPCHazard::StagColNPC() STUB_VOID
void NPCHazard::CollideResponse(xSweptSphere* swdata, float32 tym_inFuture) STUB_VOID
void NPCHazard::ColResp_Default(xSweptSphere* swdata, float32 tym_inFuture) STUB_VOID

xAnimTable* ZNPC_AnimTable_HazardStd() STUB

void NPCHazard::Upd_Explode(float32) STUB_VOID
void NPCHazard::DeathStar() STUB_VOID
void NPCHazard::Upd_PuppyNuke(float32 dt) STUB_VOID
void NPCHazard::Upd_FodBomb(float32 dt) STUB_VOID
void NPCHazard::FodBombBubbles(float32) STUB_VOID
void NPCHazard::Upd_CattleProd(float32) STUB_VOID
void NPCHazard::Upd_TubeletBlast(float32) STUB_VOID
void NPCHazard::Upd_DuploBoom(float32) STUB_VOID
void NPCHazard::Upd_TikiThunder(float32) STUB_VOID
void NPCHazard::Upd_Mushroom(float32 dt) STUB_VOID
void NPCHazard::Upd_Patriot(float32) {}
void NPCHazard::Upd_TTFlight(float32) STUB_VOID
void NPCHazard::ReconTarTar() STUB_VOID
void NPCHazard::Upd_TTSpill(float32) STUB_VOID
int32 NPCHazard::KickSteamyStinky() STUB
void NPCHazard::Upd_TTStink(float32) STUB_VOID
void NPCHazard::TarTarFalumpf() STUB_VOID
void NPCHazard::TarTarGunkTrail() STUB_VOID
void NPCHazard::TarTarSplash(const xVec3* dir_norm) STUB_VOID
void NPCHazard::TarTarLinger() STUB_VOID
void NPCHazard::Upd_ChuckBomb(float32 dt) STUB_VOID
void NPCHazard::DisperseBubWake(float32 radius, const xVec3* velocity) STUB_VOID
void NPCHazard::ReconChuck() STUB_VOID
void NPCHazard::Upd_ChuckBlast(float32) STUB_VOID
void NPCHazard::WaterSplash(const xVec3* dir_norm) STUB_VOID
void NPCHazard::WavesOfEvil() STUB_VOID
int32 NPCHazard::KickBlooshBlob(const xVec3* vel_flight) STUB
void NPCHazard::Upd_ChuckBloosh(float32) STUB_VOID
void NPCHazard::Upd_BoneFlight(float32 dt) STUB_VOID
void NPCHazard::ReconArfBone() STUB_VOID
void NPCHazard::Upd_BoneBlast(float32 dt) STUB_VOID
void NPCHazard::Upd_OilBubble(float32) STUB_VOID
void NPCHazard::ReconSlickOil() STUB_VOID
void NPCHazard::OilSplash(const xVec3* dir_norm) STUB_VOID
void NPCHazard::Upd_OilOoze(float32 dt) STUB_VOID
int32 NPCHazard::KickOilBurst() STUB
int32 NPCHazard::KickOilGlobby() STUB
void NPCHazard::Upd_OilBurst(float32) STUB_VOID
void NPCHazard::Upd_OilGlob(float32 dt) STUB_VOID
void NPCHazard::Upd_MonCloud(float32 dt) STUB_VOID
void NPCHazard::Upd_FunFrag(float32) STUB_VOID
void NPCHazard::StreakUpdate(uint32 streakID, float32 rad) STUB_VOID
void NPCHazard::Upd_RoboBits(float32) STUB_VOID
void NPCHazard::Upd_VisSplash(float32) STUB_VOID
void NPCHazard::VisSplashSparklies() STUB_VOID

bool32 UVAModelInfo::Init(RpAtomic* model, uint32 flg_uvamCaller) STUB
void UVAModelInfo::Hemorrage() STUB_VOID
void UVAModelInfo::Update(float32 dt, const xVec2* use_offset) STUB_VOID
void UVAModelInfo::Refresh() STUB_VOID
void UVAModelInfo::SetColor(xColor) STUB_VOID
bool32 UVAModelInfo::GetUV(RwTexCoords*&, int32&, RpAtomic*) const STUB
bool32 UVAModelInfo::CloneUV(RwTexCoords*&, int32&, RpAtomic*) const STUB