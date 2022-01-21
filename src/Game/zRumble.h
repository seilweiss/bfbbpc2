#pragma once

#include "xRumble.h"

struct xEnt;

typedef enum _tagSDRumbleType
{
	SDR_None,
	SDR_Test,
	SDR_Damage,
	SDR_Bounce,
	SDR_EventLight,
	SDR_EventMedium,
	SDR_EventHeavy,
	SDR_DustDestroyedObj,
	SDR_XploDestroyedObj,
	SDR_WebDestroyed,
	SDR_Tiki,
	SDR_LassoDestroy,
	SDR_DamageByEGen,
	SDR_BounceHit,
	SDR_CruiseBubbleLaunch,
	SDR_CruiseBubbleExplode,
	SDR_TeleportStart,
	SDR_Teleport,
	SDR_TeleportEject,
	SDR_Total
} SDRumbleType;

void zRumbleStart(int32 pad_id, SDRumbleType rumble_type, xEnt* ent);
void zRumbleStart(int32 pad_id, SDRumbleType rumble_type);
void zRumbleStart(SDRumbleType rumble_type);
void zRumbleStart(SDRumbleType rumble_type, xEnt* ent);
void zRumbleStartDistance(int32 pad_id, float32 real_dist, float32 max_dist, RumbleType type, float32 maxTime);
void zRumbleStartEntDistance(xEnt*, float32, RumbleType, float32);
bool32 zPadAddRumble(RumbleType type, float32 time, int32 replace, uint32 fxflags);