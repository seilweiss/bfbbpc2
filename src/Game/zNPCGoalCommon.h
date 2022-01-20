#pragma once

#include "xBehaviour.h"

typedef enum en_NPC_GOAL_SPOT
{
	NPC_GSPOT_START = 32,
	NPC_GSPOT_RESUME,
	NPC_GSPOT_FINISH,
	NPC_GSPOT_STARTALT,
	NPC_GSPOT_ALTA,
	NPC_GSPOT_ALTB,
	NPC_GSPOT_PATROLPAUSE,
	NPC_GSPOT_NOMORE,
	NPC_GSPOT_FORCEINT = FORCEENUMSIZEINT
} NPC_GOAL_SPOT;