#include "iPad.h"

#include "xPad.h"

bool32 iPadInit() STUB
xPad* iPadEnable(xPad* pad, int16 port) STUB
static int32 iPadConvStick(float32) STUB
bool32 iPadUpdate(_tagxPad* pad, uint32* on) STUB
void iPadRumbleFx(_tagxPad* p, _tagxRumble* r, float32 time_passed) STUB_VOID
void iPadStopRumble(_tagxPad* pad) STUB_VOID
void iPadStopRumble() STUB_VOID
void iPadStartRumble(_tagxPad* pad, _tagxRumble* rumble) STUB_VOID
void iPadKill() {}