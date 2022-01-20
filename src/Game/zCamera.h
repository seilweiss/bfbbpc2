#pragma once

#include "xCamera.h"

enum camera_owner_enum
{
	CO_BOULDER = 0x1,
	CO_CRUISE_BUBBLE = 0x2,
	CO_BUNGEE = 0x4,
	CO_BOSS = 0x8,
	CO_OOB = 0x10,
	CO_ZIPLINE = 0x20,
	CO_TURRET = 0x40,
	CO_REWARDANIM = 0x80
};

struct zFlyKey
{
	int32 frame;
	float32 matrix[12];
	float32 aperture[2];
	float32 focal;
};

void zCameraReset(xCamera* cam);
void zCameraFlyStart(uint32 assetID);
void zCameraUpdate(xCamera* cam, float32 dt);
void zCameraSetBbounce(bool32 bbouncing);
void zCameraSetLongbounce(bool32 lbounce);
void zCameraSetHighbounce(bool32 hbounce);
void zCameraSetPlayerVel(xVec3* vel);
void zCameraDisableTracking(camera_owner_enum owner);
void zCameraEnableTracking(camera_owner_enum owner);
uint32 zCameraIsTrackingDisabled();
void zCameraDisableInput();
void zCameraEnableInput();
void zCameraDisableLassoCam();
void zCameraEnableLassoCam();
void zCameraSetLassoCamFactor(float32 factor);
float32 zCameraGetLassoCamFactor();
bool32 zCameraGetConvers();
void zCameraSetConvers(bool32 on);
void zCameraDoTrans(xCamAsset* asset, float32 ttime);
void zCameraTranslate(xCamera* cam, float32 dposx, float32 dposy, float32 dposz);
void zCameraEnableWallJump(xCamera*, const xVec3& collNormal);
void zCameraDisableWallJump(xCamera*);
void zCameraSetReward(bool32 on);
void zCameraMinTargetHeightSet(float32 height);
void zCameraMinTargetHeightClear();
uint32 zCamera_FlyOnly();

inline void zCameraTranslate(xCamera*, xVec3*) STUB_VOID