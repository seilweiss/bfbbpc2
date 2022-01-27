#pragma once

#include "zNPCTypeCommon.h"
#include "zNPCSupport.h"

class zNPCSubBoss : public zNPCCommon
{
private:
	NPCTarget tgt_cur;

public:
	zNPCSubBoss(int32 myType) WIP : zNPCCommon(myType) {}

	virtual void Setup();
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x10; }
	virtual uint8 ColPenByFlags() const WIP { return 0x10; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
};

void ZNPC_SubBoss_Startup();
void ZNPC_SubBoss_Shutdown();
void zNPCSubBoss_ScenePrepare();
void zNPCSubBoss_SceneFinish();
xFactoryInst* ZNPC_Create_SubBoss(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_SubBoss(xFactoryInst* inst);
void SUBB_InitEffects();