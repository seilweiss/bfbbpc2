#pragma once

#include <types.h>

bool32 zMenuRunning();
void zMenuInit(uint32 theSceneID);
void zMenuExit();
void zMenuSetup();
uint32 zMenuLoop();
int32 zMenuGetCorruptFiles(char* [64]);
int32 zMenuCardCheckStartup(int32* bytesNeeded, int32* availOnDisk, int32* neededFiles);
uint32 zMenuGetBadCard();
void zMenuFMVPlay(char*, uint32, float32, bool, bool);
bool32 zMenuIsFirstBoot();
void zMenuFirstBootSet(bool32);