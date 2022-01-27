#pragma once

#include "xDynAsset.h"

struct xScene;

struct CameraFly_asset : xDynAsset
{
	uint32 flyID;
};

struct zCameraFly : xBase
{
	CameraFly_asset* casset;
};

void zCameraFly_Init(xBase& data, xDynAsset& asset, ulong32);
void zCameraFly_Init(zCameraFly*, CameraFly_asset*);
void zCameraFly_Setup(zCameraFly* fly);
void zCameraFly_Update(xBase*, xScene*, float32);
void zCameraFly_Save(zCameraFly* fly, xSerial* s);
void zCameraFly_Load(zCameraFly* fly, xSerial* s);
uint32 zCameraFlyProcessStopEvent();
bool32 zCameraFlyEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);