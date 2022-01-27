#include "zCameraTweak.h"

struct zCamTweak
{
	uint32 owner;
	float32 priority;
	float32 time;
	float32 pitch;
	float32 distMult;
};

struct zCamTweakLook
{
	float32 h;
	float32 dist;
	float32 pitch;
};

static void zCameraTweak_LookPreCalc(zCamTweakLook*, float32, float32, float32) STUB_VOID
void zCameraTweakGlobal_Init() STUB_VOID
void zCameraTweakGlobal_Add(uint32 owner, float32 priority, float32 time, float32 pitch, float32 distMult) STUB_VOID
void zCameraTweakGlobal_Remove(uint32 owner) STUB_VOID
void zCameraTweakGlobal_Reset() STUB_VOID
void zCameraTweakGlobal_Update(float32 dt) STUB_VOID
float32 zCameraTweakGlobal_GetD() STUB
float32 zCameraTweakGlobal_GetH() STUB
float32 zCameraTweakGlobal_GetPitch() STUB
void zCameraTweak_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void zCameraTweak_Init(zCameraTweak*, CameraTweak_asset*) STUB_VOID
void zCameraTweak_Save(zCameraTweak* tweak, xSerial* s) STUB_VOID
void zCameraTweak_Load(zCameraTweak* tweak, xSerial* s) STUB_VOID
bool32 zCameraTweak_EventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB