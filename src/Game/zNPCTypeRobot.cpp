#include "zNPCTypeRobot.h"

void zNPCRobot::Init(xEntAsset* asset) STUB_VOID
void zNPCRobot::Reset() STUB_VOID
void zNPCRobot::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCRobot::NewTime(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCRobot::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCRobot::CollideReview() STUB_VOID
uint8 zNPCRobot::ColChkFlags() const STUB
uint8 zNPCRobot::ColPenFlags() const STUB
uint8 zNPCRobot::PhysicsFlags() const STUB
bool32 zNPCRobot::NPCMessage(NPCMsg* mail) STUB
void zNPCRobot::ParseINI() STUB_VOID
void zNPCRobot::SelfSetup() STUB_VOID
void zNPCRobot::DuploOwner(zNPCCommon* duper) STUB_VOID
void zNPCRobot::LassoNotify(en_LASSO_EVENT event) STUB_VOID
bool32 zNPCRobot::SetCarryState(en_NPC_CARRY_STATE stat) STUB
void zNPCRobot::Stun(float32 stuntime) STUB_VOID
uint32 zNPCRobot::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*) STUB
float32 zNPCRobot::GenShadCacheRad() STUB
bool32 zNPCRobot::LassoSetup() STUB
bool32 zNPCRobot::RoboHandleMail(NPCMsg* mail) STUB
int32 zNPCRobot::IsDying() STUB