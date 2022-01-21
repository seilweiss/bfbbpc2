#pragma once

#include "xVolume.h"

struct zVolume : xVolume
{
};

void zVolumeInit(zVolume*, xVolumeAsset*);
void zVolumeInit();
void zVolumeSetup();
zVolume* zVolumeGetVolume(uint16 n);
void zVolume_OccludePrecalc(xVec3* camPos);
bool32 zVolumeEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);