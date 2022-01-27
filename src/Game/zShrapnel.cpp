#include "zShrapnel.h"

zFrag* zFrag_Alloc(zFragType type) STUB
void zFrag_Free(zFrag*) STUB_VOID
void zShrapnel_GameInit() STUB_VOID
void zShrapnel_ProjectileSceneInit(zFragProjectileAsset*) STUB_VOID
void zShrapnel_ParticleSceneInit(zFragParticleAsset*) STUB_VOID
void zShrapnel_SetShrapnelAssetInitCB(zShrapnelAsset*) STUB_VOID
void zShrapnel_SceneInit(zScene*) STUB_VOID
void zShrapnel_Update(float32 dt) STUB_VOID
void zShrapnel_Reset() STUB_VOID
void zShrapnel_Render() STUB_VOID
void zShrapnel_DefaultInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3* initVel, zShrapnelAssetInitCallback cb) STUB_VOID
static void CinFragCB(zFrag* frag, zFragAsset* asset) STUB_VOID
void zShrapnel_CinematicInit(zShrapnelAsset* shrap, RpAtomic* cinModel, RwMatrix* animMat, xVec3* initVel, zShrapnelAssetInitCallback cb) STUB_VOID
void zFragLoc_Setup(zFragLocation* loc, xModelInstance* parent) STUB_VOID
void zFragLoc_InitMat(zFragLocation* loc, xMat4x3* mat, xModelInstance* parent) STUB_VOID
void zFragLoc_InitVec(zFragLocation* loc, xVec3* vec, xModelInstance* parent) STUB_VOID
void zFragLoc_InitDir(zFragLocation* loc, xVec3* vec, xModelInstance* parent) STUB_VOID
void zFrag_DefaultInit(zFrag* frag, zFragAsset* fasset) STUB_VOID
void zFrag_DefaultParticleUpdate(zFrag* frag, float32) STUB_VOID
void zFrag_ParticleManager(float32 dt) STUB_VOID
void zFrag_ProjectileCollData(zFrag*) STUB_VOID
void zFrag_DefaultProjectileUpdate(zFrag* frag, float32) STUB_VOID
void zFrag_DeleteProjectile(zFrag*) STUB_VOID
void zFrag_ProjectileManager(float32 dt) STUB_VOID
void zFrag_DefaultLightningUpdate(zFrag* frag, float32) STUB_VOID
void zFrag_LightningManager(float32 dt) STUB_VOID
void zFrag_DefaultSoundUpdate(zFrag* frag, float32) STUB_VOID
void zFrag_SoundManager(float32) STUB_VOID
void zFrag_ProjectileRenderer() STUB_VOID
static void zShrapnel_DestructObjInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3*, zShrapnelAssetInitCallback) STUB_VOID
static void zShrapnel_BB03FloorInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3*, zShrapnelAssetInitCallback);
static void BB03FloorChildCB(zFrag* frag, zFragAsset*) STUB_VOID
static void zShrapnel_BB03FloorChildInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3* initVel, zShrapnelAssetInitCallback) STUB_VOID
static void zShrapnel_GlobalRobotInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3*, zShrapnelAssetInitCallback) STUB_VOID
static void zShrapnel_SpongebobInit(zShrapnelAsset* shrap, xModelInstance* parent, xVec3* initVel, zShrapnelAssetInitCallback) STUB_VOID