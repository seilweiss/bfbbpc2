#pragma once

#include "xDynAsset.h"

struct CameraTweak_asset : xDynAsset
{
	int32 priority;
	float32 time;
	float32 pitch_adjust;
	float32 dist_adjust;
};

struct zCameraTweak : xBase
{
	CameraTweak_asset* casset;
};

void zCameraTweakGlobal_Init();
void zCameraTweakGlobal_Add(uint32 owner, float32 priority, float32 time, float32 pitch, float32 distMult);
void zCameraTweakGlobal_Remove(uint32 owner);
void zCameraTweakGlobal_Reset();
void zCameraTweakGlobal_Update(float32 dt);
float32 zCameraTweakGlobal_GetD();
float32 zCameraTweakGlobal_GetH();
float32 zCameraTweakGlobal_GetPitch();
void zCameraTweak_Init(xBase& data, xDynAsset& asset, ulong32);
void zCameraTweak_Init(zCameraTweak*, CameraTweak_asset*);
void zCameraTweak_Save(zCameraTweak* tweak, xSerial* s);
void zCameraTweak_Load(zCameraTweak* tweak, xSerial* s);
bool32 zCameraTweak_EventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);