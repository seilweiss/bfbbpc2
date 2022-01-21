#include "iTime.h"

void iTimeInit() STUB_VOID
void iTimeExit() STUB_VOID
iTime iTimeGet() STUB
float32 iTimeDiffSec(iTime time) STUB
float32 iTimeDiffSec(iTime t0, iTime t1) STUB
void iTimeGameAdvance(float32 elapsed) STUB_VOID
void iTimeSetGame(float32 time) STUB_VOID
void iProfileClear(uint32 sceneID) {}
void iFuncProfileDump() {}
void iFuncProfileParse(char*, int32) {}