#include "zRumble.h"

void zRumbleStart(int32 pad_id, SDRumbleType rumble_type, xEnt* ent) STUB_VOID
void zRumbleStart(int32 pad_id, SDRumbleType rumble_type) STUB_VOID
void zRumbleStart(SDRumbleType rumble_type) STUB_VOID
void zRumbleStart(SDRumbleType rumble_type, xEnt* ent) STUB_VOID
void zRumbleStartDistance(int32 pad_id, float32 real_dist, float32 max_dist, RumbleType type, float32 maxTime) STUB_VOID
void zRumbleStartEntDistance(xEnt*, float32, RumbleType, float32) STUB_VOID
bool32 zPadAddRumble(RumbleType type, float32 time, int32 replace, uint32 fxflags) STUB