#include "zNPCTypeVillager.h"

void ZNPC_Villager_Startup() STUB_VOID
void ZNPC_Villager_Shutdown() {}
void zNPCVillager_ScenePrepare() {}
void zNPCVillager_SceneFinish() STUB_VOID
void zNPCVillager_SceneReset() {}
void zNPCVillager_ScenePostInit() STUB_VOID
void zNPCVillager_SceneTimestep(xScene*, float32 dt) STUB_VOID
xFactoryInst* ZNPC_Create_Villager(int32 who, RyzMemGrow* growCtxt, void*) STUB
void ZNPC_Destroy_Villager(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_Villager() STUB
xAnimTable* ZNPC_AnimTable_Villager(xAnimTable* callerTable) STUB
xAnimTable* ZNPC_AnimTable_BalloonBoy() STUB
xAnimTable* ZNPC_AnimTable_BalloonBoy(xAnimTable* callerTable) STUB
xAnimTable* ZNPC_AnimTable_SuperFriend() STUB
xAnimTable* ZNPC_AnimTable_SuperFriend(xAnimTable* callerTable) STUB

uint8 zNPCVillager::ColChkFlags() const STUB
uint8 zNPCVillager::ColPenFlags() const STUB
uint8 zNPCVillager::PhysicsFlags() const STUB
void zNPCVillager::Init(xEntAsset* asset) STUB_VOID
void zNPCVillager::Reset() STUB_VOID
void zNPCVillager::ParseINI() STUB_VOID
void zNPCVillager::ParseNonRandTalk() STUB_VOID
void zNPCVillager::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCVillager::ChkCheatSize() STUB_VOID
void zNPCVillager::CollideReview() STUB_VOID
void zNPCVillager::SelfSetup() STUB_VOID
uint32 zNPCVillager::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*) STUB
bool32 zNPCVillager::NPCMessage(NPCMsg* mail) STUB
bool32 zNPCVillager::FolkHandleMail(NPCMsg* mail) STUB
void zNPCVillager::SpeakBegin() STUB_VOID
void zNPCVillager::SpeakEnd() STUB_VOID
void zNPCVillager::SpeakStart(uint32 sndid, uint32, int32 anim) STUB_VOID
void zNPCVillager::SpeakStop() STUB_VOID
bool32 zNPCVillager::PlayerIsStaring() STUB
void zNPCVillager::AddTalking(xPsyche* psy, xGoalProcessCallback eval_plyrnear, xGoalProcessCallback eval_talking, xGoalProcessCallback eval_chatter, xGoalProcessCallback eval_speak) STUB_VOID
void zNPCVillager::FindMyConverse() STUB_VOID
void zNPCVillager::TossMyConverse() STUB_VOID

void zNPCFish::Init(xEntAsset* asset) STUB_VOID
void zNPCFish::Reset() STUB_VOID
void zNPCFish::ParseINI() STUB_VOID
void zNPCFish::FishSoundTables() STUB_VOID
void zNPCFish::SelfSetup() STUB_VOID
uint32 zNPCFish::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCFish::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCFish::FolkHandleMail(NPCMsg* msg) STUB
void zNPCFish::MonitorCowering(xScene*, float32) STUB_VOID
void zNPCFish::CheckDoChat() {}

void zNPCMerManChair::Init(xEntAsset* asset) STUB_VOID
void zNPCMerManChair::Reset() STUB_VOID
void zNPCMerManChair::SelfSetup() STUB_VOID
uint32 zNPCMerManChair::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCMerManChair::Process(xScene*, float32 dt) STUB_VOID

void zNPCNewsFish::Init(xEntAsset* asset) STUB_VOID
void zNPCNewsFish::PostSetup() STUB_VOID
void zNPCNewsFish::Process(xScene*, float32 dt) STUB_VOID
void zNPCNewsFish::Reset() STUB_VOID
void zNPCNewsFish::SpeakStart(uint32 sndid, uint32 sndhandle) STUB_VOID
void zNPCNewsFish::SpeakStop() STUB_VOID
bool32 zNPCNewsFish::IsTalking() STUB
void zNPCNewsFish::TalkOnScreen(bool32 talkOnScreen) STUB_VOID
void zNPCNewsFish::Render() STUB_VOID
bool zNPCNewsFish::say(say_enum s, int32 flags) STUB
bool32 zNPCNewsFish::say(const say_enum* s, ulong32 size, int32 flags, int32 max_say) STUB
void zNPCNewsFish::reset_said() STUB_VOID

void zNPCSandyBikini::Reset() STUB_VOID
void zNPCSandyBikini::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCSandyBikini::VFXLeakyFaucet(float32 dt) STUB_VOID

void zNPCBalloonBoy::Init(xEntAsset* asset) STUB_VOID
void zNPCBalloonBoy::Reset() STUB_VOID
void zNPCBalloonBoy::SelfSetup() STUB_VOID
void zNPCBalloonBoy::Render() STUB_VOID
void zNPCBalloonBoy::PlatShadRend() STUB_VOID
void zNPCBalloonBoy::AddBallooning(xPsyche*) STUB_VOID
uint32 zNPCBalloonBoy::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
bool32 zNPCBalloonBoy::FolkHandleMail(NPCMsg* mail) STUB
bool32 zNPCBalloonBoy::ParseSysEvent(NPCSysEvent* sed) STUB
void zNPCBalloonBoy::PlatAnimSet(en_BBOY_PLATANIM platanim) STUB_VOID
void zNPCBalloonBoy::PlatAnimSync() STUB_VOID
bool32 zNPCBalloonBoy::IAmBallooning() STUB

void zNPCBubbleBuddy::Init(xEntAsset* asset) STUB_VOID
void zNPCBubbleBuddy::Setup() STUB_VOID
void zNPCBubbleBuddy::Reset() STUB_VOID
void zNPCBubbleBuddy::RenderExtra() STUB_VOID
void zNPCBubbleBuddy_AlphaUpdate(float32) STUB_VOID
RpAtomic* NPC_BubBud_RenderCB(RpAtomic* atomic) STUB

static bool32 FOLK_grul_goAlert(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static bool32 MERC_grul_goAlert(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB

void FOLK_InitEffects() STUB_VOID
void FOLK_KillEffects() {}