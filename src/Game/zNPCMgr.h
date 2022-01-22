#pragma once

#include "xBehaveMgr.h"
#include "xEnt.h"
#include "zNPCTypes.h"

class zNPCMgr : public RyzMemData
{
private:
	st_XORDEREDARRAY npclist;
	xFactory* npcFactory;
	xBehaveMgr* bmgr;
	xBase selfbase;

public:
	zNPCMgr() WIP {}
	~zNPCMgr();

	void Startup();
	void Shutdown();
	void ScenePrepare(int32);
	void SceneFinish();
	void SceneReset();
	void ScenePostInit();
	void ScenePostSetup();
	void ScenePostRender();
	void ScenePostParticleRender();
	xEnt* CreateNPC(xEntAsset* asset);
	void BackdoorUpdateAllNPCsOnce(xScene*, float32);
	void SceneTimestep(xScene*, float32);
	void PrepTypeTable();
	en_NPCTYPES NPCTypeForModel(uint32 brainID, uint32 mdl_hash);
	void DBG_Reset() {}
	void DBG_PerfTrack() {}
};

zNPCMgr* zNPCMgrSelf();
st_XORDEREDARRAY* zNPCMgr_GetNPCList();
void zNPCMgr_Startup();
void zNPCMgr_Shutdown();
void zNPCMgr_scenePrepare(int32 npccnt);
void zNPCMgr_sceneFinish();
void zNPCMgr_sceneReset();
void zNPCMgr_scenePostInit();
void zNPCMgr_scenePostSetup();
void zNPCMgr_sceneTimestep(xScene* xscn, float32 dt);
void zNPCMgr_scenePostRender();
void zNPCMgr_scenePostParticleRender();
xEnt* zNPCMgr_createNPCInst(int32, xEntAsset* assdat);
int32 zNPCMgr_OrdTest_npcid(const void* vkey, void* vitem);
int32 zNPCMgr_OrdComp_npcid(void* vkey, void* vitem);