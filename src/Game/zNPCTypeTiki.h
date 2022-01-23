#pragma once

#include "zNPCTypeCommon.h"

struct zScene;

class zNPCTiki : public zNPCCommon
{
private:
	uint32 tikiFlag;
	xVec3 lastAt;
	xBound origLocalBound;
	xVec3 deltaPos;
	float32 timeToLive;
	float32 t1;
	float32 t2;
	float32 t3;
	xVec3 v1;
	float32 vel;
	float32 landHt;
	xEnt* nonTikiParent;
	xVec3 nonTikiParentDisp;
	uint8 numParents;
	zNPCTiki* parents[4];
	uint8 numChildren;
	zNPCTiki* children[4];
	zNPCTiki* nextOrphan;
	uint32 updatedParents;
	int32 contactParent;
	void* tikiAnim;
	float32 tikiAnimTime;

public:
	zNPCTiki(int32 myType) WIP : zNPCCommon(myType) {}

	virtual void Reset();
	virtual void Setup();
	virtual void Init(xEntAsset* entass);
	virtual void Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*);
	virtual bool32 SetCarryState(en_NPC_CARRY_STATE cs);
	virtual void SelfSetup();
	virtual void ParseINI();
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual bool32 CanRope() WIP { return TRUE; }
	virtual uint32 AnimPick(int32, en_NPC_GOAL_SPOT, xGoal*) STUB;
	virtual void Move(xScene*, float32, xEntFrame*) {}
	virtual void BUpdate(xVec3*) STUB_VOID;
	virtual bool32 IsAlive() STUB;
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x18; }
	virtual uint8 ColPenByFlags() const WIP { return 0x18; }
	virtual uint8 PhysicsFlags() const WIP { return 0; }

	void AddChild(zNPCTiki*);
	void RemoveChild(zNPCTiki*);
	void RemoveParent(zNPCTiki*);
	void FindParents(zScene* zsc);
	void ParentUpdated(zNPCTiki*);
	void RemoveFromFamily();
};

void ZNPC_Tiki_Startup();
void ZNPC_Tiki_Shutdown();
void zNPCTiki_InitStacking(zScene* zsc);
void zNPCTiki_InitFX(zScene*);
void zNPCTiki_ExplodeFX(zNPCTiki* tiki);
void zNPCTiki_Timestep(xScene*, float32 dt);
void zNPCTiki_ReparentOrphans();
xFactoryInst* ZNPC_Create_Tiki(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Tiki(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_Tiki();