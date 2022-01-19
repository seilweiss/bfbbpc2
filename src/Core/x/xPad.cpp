#include "xPad.h"

inline float32 normalize_analog(int32, int32, int32, int32, int32, int32) STUB

bool32 xPadInit() STUB
xPad* xPadEnable(int32 idx) STUB
void xPadRumbleEnable(int32 idx, bool32 enable) STUB_VOID
bool32 xPadUpdate(int32 idx, float32 time_passed) STUB
void xPadNormalizeAnalog(xPad& pad, int32 inner_zone, int32 outer_zone) STUB_VOID
void xPadKill() STUB_VOID
xRumble* xPadGetRumbleSlot() STUB
void xPadDestroyRumbleChain(xPad*) STUB_VOID
void xPadDestroyRumbleChain(int32 idx) STUB_VOID
bool32 xPadAddRumble(int32 idx, RumbleType type, float32 time, int32 replace, uint32 fxflags) STUB
void xPadAnalogIsDigital(int32, int32) STUB_VOID