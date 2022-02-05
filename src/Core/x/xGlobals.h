#pragma once

#include "xCamera.h"
#include "xPad.h"
#include "xUpdateCull.h"
#include "iFog.h"

#include <rwcore.h>
#include <rpworld.h>

struct xGlobals
{
	xCamera camera;
	xPad* pad0;
	xPad* pad1;
	xPad* pad2;
	xPad* pad3;
	int32 profile;
	char profFunc[6][128];
	xUpdateCullMgr* updateMgr;
	bool32 sceneFirst;
	char sceneStart[32];
	RpWorld* currWorld;
	iFogParams fog;
	iFogParams fogA;
	iFogParams fogB;
	iTime fog_t0;
	iTime fog_t1;
	bool32 option_vibration;
	uint32 QuarterSpeed;
	float32 update_dt;
	bool32 useHIPHOP;
	bool NoMusic;
	int8 currentActivePad;
	bool firstStartPressed;
	uint32 minVSyncCnt;
	bool dontShowPadMessageDuringLoadingOrCutScene;
	bool autoSaveFeature;
};