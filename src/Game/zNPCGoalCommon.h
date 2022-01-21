#pragma once

#include "xBehaviour.h"

struct NPCMsg;

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

class zNPCGoalCommon : public xGoal
{
private:
	int32 flg_npcgauto;
	int32 flg_npcgable;
	uint32 anid_played;
	struct
	{
		int32 flg_info : 16;
		int32 flg_user : 16;
	};

public:
	zNPCGoalCommon(int32 myType) WIP : xGoal(myType) { flg_npcgauto |= ~0x8; }

	virtual void Clear() WIP { flg_info = 0; xGoal::Clear(); }
	virtual bool32 Enter(float32, void*);
	virtual bool32 Resume(float32, void*);
	virtual bool32 PreCalc(float32 dt, void* updCtxt);
	virtual bool32 NPCMessage(NPCMsg*) WIP { return FALSE; }
	virtual bool32 CollReview(void*) WIP { return FALSE; }

	const char* Name() WIP { return NULL; }
	uint32 DoAutoAnim(NPC_GOAL_SPOT gspot, bool32 forceRestart);
	uint32 DoExplicitAnim(uint32 anid, bool32 forceRestart);
};