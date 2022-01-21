#pragma once

#include "xScene.h"
#include "zPortal.h"
#include "zEnt.h"
#include "zEnv.h"

struct zScene : xScene
{
	zPortal* pendingPortal;
	union
	{
		uint32 num_ents;
		uint32 num_base;
	};
	union
	{
		xBase** base;
		zEnt** ents;
	};
	uint32 num_update_base;
	xBase** update_base;
	uint32 baseCount[72];
	xBase* baseList[72];
	zEnv* zen;
};

typedef xBase* (*zSceneBaseCallback)(xBase*, zScene*, void*);

void zSceneSet(xBase*, uint32);
void zSceneInitEnvironmentalSoundEffect();
void zSceneInit(uint32 theSceneID, bool32 reloadInProgress);
void zSceneExit(bool32 beginReload);
void zSceneUpdateSFXWidgets();
void zSceneSwitch(zPortal* p, bool32 forceSameScene);
void zSceneSave(zScene* ent, xSerial* s);
void zSceneLoad(zScene* ent, xSerial* s);
void zSceneReset();
void zSceneSetup();
bool32 zSceneSetup_serialTraverseCB(uint32 clientID, xSerial* xser);
void zSceneUpdate(float32 elapsedSec);
void zSceneRender();
xBase* zSceneFindObject(uint32 gameID);
xBase* zSceneGetObject(int32 type, int32 idx);
const char* zSceneGetName(uint32 gameID);
const char* zSceneGetName(xBase* b);
void zSceneForAllBase(zSceneBaseCallback, void*);
void zSceneForAllBase(zSceneBaseCallback func, int32 baseType, void* data);
void zSceneMemLvlChkCB();
uint32 zSceneLeavingLevel();
const char* zSceneGetLevelName(uint32 sceneID);
uint32 zSceneGetLevelIndex();
uint32 zSceneGetLevelIndex(uint32);
const char* zSceneGetLevelPrefix(uint32 index);
const char* zSceneGetAreaname(uint32);
uint32 zSceneCalcProgress();
void zScene_UpdateFlyToInterface(float32 dt);
void zSceneCardCheckStartup_set(int32 needed, int32 available, int32 files);
void zSceneEnableVisited(zScene* s);
void zSceneEnableScreenAdj(uint32 enable);
void zSceneSetOldScreenAdj();
uint32 zScene_ScreenAdjustMode();
void zSceneSpawnRandomBubbles();