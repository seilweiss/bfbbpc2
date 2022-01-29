#include "zNPCFXCinematic.h"

inline void get_bone_matrix(xMat4x3&, const NCINEntry*, const RwMatrix*) STUB_VOID
inline void clamp_bone_index(NCINEntry*, RpAtomic*) {}

static void NCIN_Par_BPLANK_JET_1_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_JET_2_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_FLAMES_1_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_FLAMES_2_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_JET_1_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_JET_2_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_SMOKE_1_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_BPLANK_SBB_SMOKE_2_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_CIN_BIGDUP_SMOKE_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_CIN_BIGDUP_SPAWN_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Par_CIN_PLATFORM_JETS_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID

void NCINBeNosey::CanRenderNow() STUB_VOID
void NCINBeNosey::UpdatedAnimated(RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32 dataIndex) STUB_VOID

void zNPCFXStartup() STUB_VOID
void zNPCFXShutdown() {}
static NCINEntry* zNPCFXCutscenePickTable(const zCutsceneMgr* csnmgr) STUB
bool32 zNPCFXCutscenePrep(const xScene*, float32, const zCutsceneMgr* csnmgr) STUB
void zNPCFXCutsceneDone(const xScene*, float32, const zCutsceneMgr* csnmgr) STUB_VOID
void zNPCFXCutscene(const xScene*, float32, const zCutsceneMgr* csnmgr) STUB_VOID

static void NCIN_Generic_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BubSlam(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BubWipe(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BubTrailBone_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_BubHit(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Zapper(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HammerShock(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HammerStreak_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HammerStreak_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_WaterSplash(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HazProjShoot(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HazTTSteam_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HazTTSteam_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_TTGunSmoke_AR(const zCutsceneMgr* csnmgr, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_ArfDogBoom(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_SleepyLamp_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_SleepyLamp_AR(const zCutsceneMgr* csnmgr, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_SleepyDRay_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_SleepyDRay_AR(const zCutsceneMgr* csnmgr, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_MaryBoom(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_PeteBonk(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FireSpiral_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FireSpiral_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_ShieldPop(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_OilHazard(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FodProd_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FodProd_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_FodProdBone_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FodProdBone_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_MidFish_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_MidFish_AR(const zCutsceneMgr*, NCINEntry*, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_BombTrail_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BombTrail_AR(const zCutsceneMgr*, NCINEntry*, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_BoneTrail_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BoneTrail_AR(const zCutsceneMgr*, NCINEntry*, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_HookRecoil_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_HookRecoil_AR(const zCutsceneMgr* csnmgr, NCINEntry*, RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_Lightnin2Bones_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_Lightnin2Bones_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_LightninBone_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_LightninBone_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_B101Shockwave_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FreezeBreath_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_FreezeBreath_AR(const zCutsceneMgr* csnmgr, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_B201HideBelt_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_GooLever_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_GooLever_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_PatBossShrapnel_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_PatBossShrapnel_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_SpatGlow_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_SpatGlow_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_GloveShrapnel_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_GloveShrapnel_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_EntityBonePar_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_BubbleTrail_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_BubbleTrail_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic*, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID
static void NCIN_SBBNode_Upd(const zCutsceneMgr*, NCINEntry* fxrec, bool32 killit) STUB_VOID
static void NCIN_SBBNode_AR(const zCutsceneMgr*, NCINEntry* fxrec, RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32) STUB_VOID