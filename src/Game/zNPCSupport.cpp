#include "zNPCSupport.h"

void NPCSupport_Startup() STUB_VOID
void NPCSupport_Shutdown() STUB_VOID
void NPCSupport_ScenePrepare() STUB_VOID
void NPCSupport_SceneFinish() STUB_VOID
void NPCSupport_ScenePostInit() STUB_VOID
void NPCSupport_SceneReset() STUB_VOID
void NPCSupport_Timestep(float32 dt) STUB_VOID

void NPCWidget_Startup() STUB_VOID
void NPCWidget_Shutdown() {}
void NPCWidget_ScenePrepare() {}
void NPCWidget_SceneFinish() STUB_VOID
void NPCWidget_SceneReset() STUB_VOID
void NPCWidget_ScenePostInit() STUB_VOID
NPCWidget* NPCWidget_Find(en_NPC_UI_WIDGETS which) STUB

void NPCWidget::Init(en_NPC_UI_WIDGETS) STUB_VOID
void NPCWidget::Reset() {}
bool32 NPCWidget::On(const zNPCCommon* npc, bool32 theman) STUB
bool32 NPCWidget::Off(const zNPCCommon* npc, bool32 theman) STUB
bool32 NPCWidget::IsVisible() STUB
bool32 NPCWidget::Lock(const zNPCCommon*) STUB
bool32 NPCWidget::Unlock(const zNPCCommon*) STUB
bool32 NPCWidget::NPCIsTheLocker(const zNPCCommon* npc_lock) STUB

void NPCTarget::TargetSet(xEnt*, int32) STUB_VOID
void NPCTarget::TargetClear() STUB_VOID
bool32 NPCTarget::FindNearest(int32 flg_consider, xBase* skipme, xVec3* from, float32 dst_max) STUB
void NPCTarget::PosGet(xVec3* pos) STUB_VOID
bool32 NPCTarget::InCylinder(xVec3* from, float32 rad, float32 hyt, float32 off) STUB
bool32 NPCTarget::IsDead() STUB

void NPCLaser::Render(xVec3* pos_src, xVec3* pos_tgt) STUB_VOID

void NPCCone::RenderCone(xVec3* pos_tiptop, xVec3* pos_botcenter) STUB_VOID

void NPCBlinker::Reset() STUB_VOID
void NPCBlinker::Update(float32 dt, float32 ratio, float32 tym_slow, float32 tym_fast) STUB_VOID
void NPCBlinker::IndexToUVCoord(int32, float32*, float32*) STUB_VOID
void NPCBlinker::Render(const xVec3* pos_blink, float32 rad_blink, const RwRaster* rast_blink) STUB_VOID

void Firework_Release(Firework*) STUB_VOID
void Firework_ScenePrepare() STUB_VOID
void Firework_SceneFinish() STUB_VOID
void Firework_SceneReset(bool32) STUB_VOID
void Firework_Timestep(float32 dt) STUB_VOID

void Firework::Cleanup() {}
void Firework::Update(float32 dt) STUB_VOID
void Firework::FlyFlyFly(float32 dt) STUB_VOID
void Firework::Detonate() STUB_VOID

void NPCC_ang_toXZDir(float32 angle, xVec3* dir) STUB_VOID
float32 NPCC_dir_toXZAng(const xVec3* dir) STUB
float32 NPCC_aimMiss(xVec3* dir_aim, xVec3* pos_src, xVec3* pos_tgt, float32 dst_miss, xVec3* pos_miss) STUB
float32 NPCC_aimVary(xVec3* dir_aim, xVec3* pos_src, xVec3* pos_tgt, float32 dst_vary, int32 flg_vary, xVec3* pos_aimPoint) STUB
bool32 NPCC_chk_hitPlyr(xBound* bnd, xCollis* collide) STUB
bool32 NPCC_chk_hitEnt(xEnt* tgt, xBound* bnd, xCollis* collide) STUB
bool32 NPCC_LineHitsBound(xVec3* a, xVec3* b, xBound* bnd, xCollis* callers_colrec) STUB
bool32 NPCC_bnd_ofBase(xBase*, xBound*) STUB
bool32 NPCC_pos_ofBase(xBase* tgt, xVec3* pos) STUB
void NPCC_xBoundAway(xBound* bnd) STUB_VOID
void NPCC_xBoundBack(xBound* bnd) STUB_VOID
bool32 NPCC_HaveLOSToPos(xVec3* pos_src, xVec3* pos_tgt, float32 dst_max, xBase* tgt, xCollis* colCallers) STUB
float32 NPCC_DstSqPlyrToPos(const xVec3* pos) STUB
float32 NPCC_ds2_toCam(const xVec3* pos_from, xVec3* delta) STUB
void NPCC_Bounce(xVec3* vec_input, xVec3* vec_anti, float32 elastic) STUB_VOID
void NPCC_rotHPB(xMat3x3* mat, float32 heading, float32 pitch, float32 bank) STUB_VOID
float32 NPCC_TmrCycle(float32* tmr, float32 dt, float32 interval) STUB
void NPCC_MakePerp(xVec3* dir_perp, const xVec3* dir_axis) STUB_VOID
void NPCC_MakeArbPlane(const xVec3* dir_norm, xVec3* at, xVec3* rt) STUB_VOID
RwTexture* NPCC_FindRWTexture(const char* txtrname) STUB
RwTexture* NPCC_FindRWTexture(uint32 hashid) STUB
RwRaster* NPCC_FindRWRaster(const char* txtrname) STUB
RwRaster* NPCC_FindRWRaster(RwTexture* txtr) STUB
void NPCC_GenSmooth(xVec3** pos_base, xVec3** pos_mid) STUB_VOID

void zNPC_SNDInit() STUB_VOID
void zNPC_SNDPlay3D(eNPCSnd snd, xEnt* ent) STUB_VOID
void zNPC_SNDStop(eNPCSnd snd) STUB_VOID
int32 NPCC_LampStatus() STUB
uint32 NPCC_ForceTalkOk() STUB