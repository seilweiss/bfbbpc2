#include "zMenu.h"

bool32 zMenuRunning() STUB
void zMenuInit(uint32 theSceneID) STUB_VOID
void zMenuExit() STUB_VOID
void zMenuSetup() STUB_VOID
uint32 zMenuLoop() STUB
static bool32 zMenuIsPaused() STUB
static bool32 zMenuLoopContinue() STUB
static uint32 zMenuUpdateMode() STUB
int32 zMenuGetCorruptFiles(char* [64]) STUB
int32 zMenuCardCheckStartup(int32* bytesNeeded, int32* availOnDisk, int32* neededFiles) STUB
uint32 zMenuGetBadCard() STUB
void zMenuFMVPlay(char*, uint32, float32, bool, bool) STUB_VOID
bool32 zMenuIsFirstBoot() STUB
void zMenuFirstBootSet(bool32) STUB_VOID