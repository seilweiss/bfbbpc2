#pragma once

#include <types.h>

typedef int64 iTime;

void iTimeInit();
void iTimeExit();
iTime iTimeGet();
float32 iTimeDiffSec(iTime time);
float32 iTimeDiffSec(iTime t0, iTime t1);
void iTimeGameAdvance(float32 elapsed);
void iTimeSetGame(float32 time);
void iProfileClear(uint32 sceneID);
void iFuncProfileDump();
void iFuncProfileParse(char*, int32);