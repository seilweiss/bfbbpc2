#include "zNPCGoalVillager.h"

xFactoryInst* GOALCreate_Villager(int32 who, RyzMemGrow* grow, void*) STUB

bool32 zNPCGoalPlayerNear::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPlayerNear::Exit(float32, void*) STUB
bool32 zNPCGoalPlayerNear::Suspend(float32, void*) STUB
bool32 zNPCGoalPlayerNear::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPlayerNear::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalPlayerNear::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalPlayerNear::ChkCheatMedic() STUB_VOID
void zNPCGoalPlayerNear::DoCheatPanHandle() STUB_VOID
void zNPCGoalPlayerNear::ChkCheatDogTrix(int32* nextgoal, en_trantype* trantype) STUB_VOID

bool32 zNPCGoalTalk::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTalk::Exit(float32, void*) STUB
bool32 zNPCGoalTalk::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalTalk::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalTalk::StartSFX(xSFX*) STUB_VOID

bool32 zNPCGoalSpeak::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalSpeak::Exit(float32, void*) STUB
bool32 zNPCGoalSpeak::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalSpeak::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalCheer::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalCheer::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalChatter::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalChatter::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalHurt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalHurt::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalHurt::ChkRewardCheat() STUB_VOID

bool32 zNPCGoalBalloon::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBalloon::Exit(float32, void*) STUB
bool32 zNPCGoalBalloon::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalBalloon::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalBoyRide::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBoyRide::Exit(float32, void*) STUB
bool32 zNPCGoalBoyRide::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalBoyRide::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalBoyFall::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalBoyFall::CollReview(void*) STUB

bool32 zNPCGoalBoyWeep::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBoyWeep::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalBoyWeep::NPCMessage(NPCMsg* mail) STUB