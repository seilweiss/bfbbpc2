#pragma once

#include "zNPCTypeCommon.h"

class zNPCDuplotron : public zNPCCommon
{
private:
	float32 tmr_smokeCycle;
	zNPCSpawner* spawner;
	float32 tmr_blink;
	int32 idx_blink;

public:
	zNPCDuplotron(int32 myType) WIP : zNPCCommon(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void BUpdate(xVec3* pos);
	virtual void Move(xScene*, float32, xEntFrame*) {}
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x18; }
	virtual uint8 ColPenByFlags() const WIP { return 0x18; }
	virtual uint8 PhysicsFlags() const WIP { return 0; }
	virtual bool32 NPCMessage(NPCMsg* mail);
	virtual void ParseINI();
	virtual void ParseLinks();
	virtual void SelfSetup();
	virtual bool32 IsAlive();
	virtual void DuploNotice(en_SM_NOTICES note, void* data);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*);

	void ParseChild(xBase* child);
	bool32 DupoHandleMail(NPCMsg* mail);
	void VFXSmokeStack(float32 dt);
	void VFXOverheat(float32 dt, float32);
	void VFXCycleLights(float32 dt, int32 fastpace);
};

void ZNPC_Duplotron_Startup();
void ZNPC_Duplotron_Shutdown();
void zNPCDuplotron_ScenePrepare();
void zNPCDuplotron_SceneFinish();
void zNPCDuplotron_ScenePostInit();
xFactoryInst* ZNPC_Create_Duplotron(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Duplotron(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_Duplotron();
void DUPO_InitEffects();
void DUPO_KillEffects();