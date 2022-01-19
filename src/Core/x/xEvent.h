#pragma once

#include <types.h>

struct xBase;

void zEntEvent(char* to, uint32 toEvent);
void zEntEvent(uint32 toID, uint32 toEvent);
void zEntEvent(uint32 toID, uint32 toEvent, float32 toParam0, float32 toParam1, float32 toParam2, float32 toParam3);
void zEntEvent(xBase* to, uint32 toEvent);
void zEntEvent(xBase* to, uint32 toEvent, float32 toParam0, float32 toParam1, float32 toParam2, float32 toParam3);
void zEntEvent(xBase* to, uint32 toEvent, const float32* toParam);
void zEntEvent(xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void zEntEvent(xBase* from, xBase* to, uint32 toEvent);
void zEntEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam);
void zEntEvent(xBase* from, uint32, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32 forceEvent);
