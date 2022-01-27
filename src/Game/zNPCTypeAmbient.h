#pragma once

#include "zNPCTypeCommon.h"

class zNPCAmbient : public zNPCCommon
{
public:
	zNPCAmbient(int32 myType) WIP : zNPCCommon(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual bool32 NPCMessage(NPCMsg* mail);
	virtual bool32 AmbiHandleMail(NPCMsg* mail) WIP { return FALSE; }
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x18; }
	virtual uint8 ColPenByFlags() const WIP { return 0x18; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
};

class zNPCJelly : public zNPCAmbient
{
private:
	int32 cnt_angerLevel;
	int32 hitpoints;
	float32 tmr_pulseAlpha;
	zNPCCommon* npc_daddyJelly;

public:
	zNPCJelly(int32 myType) WIP : zNPCAmbient(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void Reset();
	virtual void SelfSetup();

	void JellySpawn(const xVec3* pos_spawn, float32 tym_fall);
	void JellyKill();

	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void BUpdate(xVec3*);
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 AmbiHandleMail(NPCMsg* mail);
	virtual bool32 IsAlive() STUB;

	void PlayWithAlpha(float32);
	void SetAlpha(float32 alf);
	void PlayWithAnimSpd();
	void PumpFaster();
	void JellyBoneWorldPos(xVec3* pos, int32 idx_request) const;
	void PlayWithLightnin();
	void ActLikeOctopus();
	void MeetTheKing(zNPCCommon*) STUB_VOID;
};

class zNPCNeptune : public zNPCAmbient
{
public:
	zNPCNeptune(int32 myType) WIP : zNPCAmbient(myType) {}

	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void ParseINI();
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void SelfSetup() {}
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0; }
	virtual uint8 ColPenByFlags() const WIP { return 0; }
};

class zNPCMimeFish : public zNPCAmbient
{
public:
	zNPCMimeFish(int32 myType) WIP : zNPCAmbient(myType) {}

	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void Reset();
	virtual void Process(xScene*, float32);
	virtual void SelfSetup() {}
};

void ZNPC_Ambient_Startup();
void ZNPC_Ambient_Shutdown();
xFactoryInst* ZNPC_Create_Ambient(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Ambient(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_Ambient();
xAnimTable* ZNPC_AnimTable_Jelly();
xAnimTable* ZNPC_AnimTable_Neptune();