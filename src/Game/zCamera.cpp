#include "zCamera.h"

namespace {

	inline float32 _GetCurrentD() STUB;
	inline float32 GetCurrentD() STUB;
	inline float32 _GetCurrentH() STUB;
	inline float32 GetCurrentH() STUB;
	inline float32 GetCurrentPitch() STUB;

}

void zCameraReset(xCamera* cam) STUB_VOID
static float32 EaseInOut(float32) STUB
static void zCameraConversUpdate(xCamera* cam, float32 dt) STUB_VOID
static float32 TranSpeed(zFlyKey*) STUB
static float32 MatrixSpeed(zFlyKey* keys) STUB
static bool32 zCameraFlyUpdate(xCamera* cam, float32 dt) STUB
void zCameraFlyStart(uint32 assetID) STUB_VOID
static void zCameraFlyRestoreBackup(xCamera* backup) STUB_VOID
static bool32 zCameraRewardUpdate(xCamera* cam, float32 dt) STUB
static void zCameraFreeLookSetGoals(xCamera* cam, float32 pitch_s, float32& dgoal, float32& hgoal, float32& pitch_goal, float32& lktm, float32 dt) STUB_VOID
void zCameraUpdate(xCamera* cam, float32 dt) STUB_VOID
void zCameraSetBbounce(bool32 bbouncing) STUB_VOID
void zCameraSetLongbounce(bool32 lbounce) STUB_VOID
void zCameraSetHighbounce(bool32 hbounce) STUB_VOID
void zCameraSetPlayerVel(xVec3* vel) STUB_VOID
void zCameraDisableTracking(camera_owner_enum owner) STUB_VOID
void zCameraEnableTracking(camera_owner_enum owner) STUB_VOID
uint32 zCameraIsTrackingDisabled() STUB
void zCameraDisableInput() STUB_VOID
void zCameraEnableInput() STUB_VOID
void zCameraDisableLassoCam() STUB_VOID
void zCameraEnableLassoCam() STUB_VOID
void zCameraSetLassoCamFactor(float32 factor) STUB_VOID
float32 zCameraGetLassoCamFactor() STUB
bool32 zCameraGetConvers() STUB
void zCameraSetConvers(bool32 on) STUB_VOID
void zCameraDoTrans(xCamAsset* asset, float32 ttime) STUB_VOID
void zCameraTranslate(xCamera* cam, float32 dposx, float32 dposy, float32 dposz) STUB_VOID
void zCameraEnableWallJump(xCamera*, const xVec3& collNormal) STUB_VOID
void zCameraDisableWallJump(xCamera*) STUB_VOID
void zCameraSetReward(bool32 on) STUB_VOID
void zCameraMinTargetHeightSet(float32 height) STUB_VOID
void zCameraMinTargetHeightClear() STUB_VOID
uint32 zCamera_FlyOnly() STUB