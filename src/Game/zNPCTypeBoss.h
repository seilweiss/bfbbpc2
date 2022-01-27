#pragma once

#include "zNPCTypeCommon.h"
#include "zNPCSupport.h"

#include <float.h>

class zNPCBoss : public zNPCCommon
{
private:
	NPCTarget tgt_cur;

public:
	zNPCBoss(int32 myType) WIP : zNPCCommon(myType) {}

	virtual void Setup();
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x10; }
	virtual uint8 ColPenByFlags() const WIP { return 0x10; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
	virtual float32 AttackTimeLeft() WIP { return FLT_MAX; }
	virtual void HoldUpDude() {}
	virtual void ThanksImDone() {}
};

void ZNPC_Boss_Startup();
void ZNPC_Boss_Shutdown();
void zNPCBoss_ScenePrepare();
void zNPCBoss_SceneFinish();
xFactoryInst* ZNPC_Create_Boss(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Boss(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_BossSBobbyArm();
void BOSS_InitEffects();