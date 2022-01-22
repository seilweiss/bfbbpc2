#include "zNPCMgr.h"

#include "zNPCMgrpv.h"

zNPCMgr* zNPCMgrSelf() STUB
st_XORDEREDARRAY* zNPCMgr_GetNPCList() STUB
void zNPCMgr_Startup() STUB_VOID
void zNPCMgr_Shutdown() STUB_VOID
void zNPCMgr_scenePrepare(int32 npccnt) STUB_VOID
void zNPCMgr_sceneFinish() STUB_VOID
void zNPCMgr_sceneReset() STUB_VOID
void zNPCMgr_scenePostInit() STUB_VOID
void zNPCMgr_scenePostSetup() STUB_VOID
void zNPCMgr_sceneTimestep(xScene* xscn, float32 dt) STUB_VOID
void zNPCMgr_scenePostRender() STUB_VOID
void zNPCMgr_scenePostParticleRender() STUB_VOID
xEnt* zNPCMgr_createNPCInst(int32, xEntAsset* assdat) STUB
void zNPCMgr::Startup() STUB_VOID
void zNPCMgr::Shutdown() STUB_VOID
void zNPCMgr::ScenePrepare(int32) STUB_VOID
void zNPCMgr::SceneFinish() STUB_VOID
void zNPCMgr::SceneReset() STUB_VOID
void zNPCMgr::ScenePostInit() STUB_VOID
void zNPCMgr::ScenePostSetup() STUB_VOID
void zNPCMgr::ScenePostRender() STUB_VOID
void zNPCMgr::ScenePostParticleRender() STUB_VOID
xEnt* zNPCMgr::CreateNPC(xEntAsset* asset) STUB
void zNPCMgr::BackdoorUpdateAllNPCsOnce(xScene*, float32) STUB_VOID
void zNPCMgr::SceneTimestep(xScene*, float32) STUB_VOID
void zNPCMgr::PrepTypeTable() STUB_VOID
en_NPCTYPES zNPCMgr::NPCTypeForModel(uint32 brainID, uint32 mdl_hash) STUB
int32 zNPCMgr_OrdTest_npcid(const void* vkey, void* vitem) STUB
int32 zNPCMgr_OrdComp_npcid(void* vkey, void* vitem) STUB