#pragma once

#include "xCutscene.h"

struct xScene;

struct zCutsceneMgr : xCutsceneMgr
{
};

void zCutsceneMgrInit(void* b, void* tasset);
void zCutsceneMgrInit(xBase*, xCutsceneMgrAsset*);
void zCutsceneMgrReset(zCutsceneMgr*);
void zCutsceneMgrSave(zCutsceneMgr*, xSerial* s);
void zCutsceneMgrLoad(zCutsceneMgr*, xSerial* s);
void zCutSceneNamesTable_clearAll();
bool32 zCutsceneMgrEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void zCutsceneMgrFinishLoad(xBase* to);
void zCutsceneMgrFinishExit(xBase* to);
void zCutsceneMgrUpdate(xBase* to, xScene* sc, float32 dt);