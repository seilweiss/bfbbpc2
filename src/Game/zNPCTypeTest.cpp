#include "zNPCTypeTest.h"

void ZNPC_Test_Startup() STUB_VOID
void ZNPC_Test_Shutdown() {}
xFactoryInst* ZNPC_Create_Test(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Test(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_Test() STUB

zNPCTest::zNPCTest(int32 myType) WIP : zNPCCommon(myType) {}
void zNPCTest::Reset() STUB_VOID
void zNPCTest::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCTest::SelfSetup() STUB_VOID
uint32 zNPCTest::AnimPick(int32, en_NPC_GOAL_SPOT, xGoal*) STUB