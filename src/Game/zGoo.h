#pragma once

#include <types.h>
#include <rwcore.h>
#include <rpworld.h>

struct xEnt;

void zGooInit(int32 nobj);
void zGooExit();
bool32 zGooAdd(xEnt* obj, float32 depth, int32 freezeGroup);
bool32 zGooIs(xEnt* obj, float32& depth, uint32 playerCheck);
void zGooCollsBegin();
void zGooCollsEnd();
void zGooStopTide();
void zGooMeltFinished(RpAtomic* atomic);

inline bool32 zGooIs(xEnt*) STUB