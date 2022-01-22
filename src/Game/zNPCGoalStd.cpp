#include "zNPCGoalStd.h"

xFactoryInst* GOALCreate_Standard(int32 who, RyzMemGrow* grow, void*) STUB
void GOALDestroy_Goal(xFactoryInst* inst) STUB_VOID

bool32 zNPCGoalPushAnim::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPushAnim::Exit(float32, void*) STUB
bool32 zNPCGoalPushAnim::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPushAnim::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalLoopAnim::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalLoopAnim::Exit(float32, void*) STUB
bool32 zNPCGoalLoopAnim::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalLoopAnim::MolestLoopAnim() STUB_VOID
void zNPCGoalLoopAnim::UnmolestAnim() STUB_VOID
void zNPCGoalLoopAnim::LoopCountSet(int32 num) STUB_VOID
void zNPCGoalLoopAnim::UseDefaultAnims() STUB_VOID
void zNPCGoalLoopAnim::ValidateStages() STUB_VOID

bool32 zNPCGoalIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalIdle::Exit(float32, void*) STUB
bool32 zNPCGoalIdle::Suspend(float32, void*) STUB
bool32 zNPCGoalIdle::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalIdle::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalIdle::NPCMessage(NPCMsg* msg) STUB

bool32 zNPCGoalPatrol::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPatrol::Exit(float32, void*) STUB
bool32 zNPCGoalPatrol::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPatrol::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalPatrol::DoOnArriveStuff() STUB_VOID
void zNPCGoalPatrol::PickTransition(int32*, trantype*) STUB_VOID
void zNPCGoalPatrol::MoveNormal(float32 dt) STUB_VOID
void zNPCGoalPatrol::MoveSpline(float32 dt) STUB_VOID
void zNPCGoalPatrol::Chk_AutoSmooth() STUB_VOID
void zNPCGoalPatrol::MoveAutoSmooth(float32 dt) STUB_VOID

bool32 zNPCGoalFidget::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalFidget::Exit(float32 dt, void* updCtxt) STUB

bool32 zNPCGoalWander::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalWander::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalWander::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalWander::VerticalWander(float32 spd_dt, const xVec3* vec_dest) STUB_VOID
void zNPCGoalWander::CalcNewDir() STUB_VOID

bool32 zNPCGoalWaiting::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalWaiting::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalWaiting::Exit(float32, void*) STUB
bool32 zNPCGoalWaiting::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB

bool32 zNPCGoalDead::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDead::Exit(float32, void*) STUB

bool32 zNPCGoalLimbo::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalLimbo::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalDEVAnimCycle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDEVAnimCycle::Exit(float32, void*) STUB
bool32 zNPCGoalDEVAnimCycle::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalDEVAnimCycle::NPCMessage(NPCMsg* mail) STUB
xAnimState* zNPCGoalDEVAnimCycle::ASTGetNext(xAnimState*) STUB

bool32 zNPCGoalDEVAnimSpin::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDEVAnimSpin::Exit(float32, void*) STUB
bool32 zNPCGoalDEVAnimSpin::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalDEVAnimSpin::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalDEVAnimSpin::ASTMolestAnim(xAnimState*) STUB_VOID
void zNPCGoalDEVAnimSpin::ASTUnmolestAnim() STUB_VOID

bool32 zNPCGoalDEVHero::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDEVHero::Exit(float32, void*) STUB
bool32 zNPCGoalDEVHero::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalDEVHero::NPCMessage(NPCMsg* mail) STUB