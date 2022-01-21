#pragma once

#include <types.h>

struct _tagxPad;
struct _tagxRumble;

typedef struct _tagiPad
{
	int32 port;
} iPad;

bool32 iPadInit();
_tagxPad* iPadEnable(_tagxPad* pad, int16 port);
bool32 iPadUpdate(_tagxPad* pad, uint32* on);
void iPadRumbleFx(_tagxPad* p, _tagxRumble* r, float32 time_passed);
void iPadStopRumble(_tagxPad* pad);
void iPadStopRumble();
void iPadStartRumble(_tagxPad* pad, _tagxRumble* rumble);
void iPadKill();