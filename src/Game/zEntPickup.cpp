#include "zEntPickup.h"

static void PickupFallPhysics(zEntPickup* ent, xScene* sc, float32 dt) STUB_VOID
uint32 isRewardPickup(zEntPickup*) STUB
void zEntPickup_Startup() STUB_VOID
void zEntPickupInit(void* ent, void* asset) STUB_VOID
void zEntPickupInit(zEntPickup* ent, xEntAsset* asset) STUB_VOID
void zEntPickup_Setup(zEntPickup* p) STUB_VOID
void zEntPickup_Setup() STUB_VOID
bool32 zEntPickupEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void zEntPickup_FlyToInterface(zEntPickup*, float32) STUB_VOID
void zEntPickup_CheckAllPickupsAgainstPlayer(xScene* sc, float32 dt) STUB_VOID
static bool32 CheckPickupAgainstPlayer(xEnt* cbent, void*) STUB
void zEntPickup_DoPickup(zEntPickup*) STUB_VOID
void zEntPickup_GivePickup(zEntPickup* ent) STUB_VOID
static void collectPickup(zEntPickup* ent) STUB_VOID
void zEntPickup_GiveAllRewardsNow() STUB_VOID
void zEntPickup_Update(zEntPickup* ent, xScene* sc, float32 dt) STUB_VOID
void zEntPickup_Reset(zEntPickup* ent) STUB_VOID
void zEntPickup_Save(zEntPickup* ent, xSerial* s) STUB_VOID
void zEntPickup_Load(zEntPickup* ent, xSerial* s) STUB_VOID
void zEntPickup_FlushGrabbed() STUB_VOID
void zEntPickup_MakeDroppable(zEntPickup*, xVec3*, xBase*) STUB_VOID
void zEntPickup_Drop(zEntPickup* ent) STUB_VOID
static bool32 ShowPickupFx(zEntPickup*) STUB
static void zEntPickup_UpdateFX(zEntPickup* ent, xScene*, float32 dt) STUB_VOID
static void set_alpha_blend(xModelInstance*) STUB_VOID
void zEntPickup_Render(zEntPickup* plist, uint32 pcount) STUB_VOID
void zEntPickup_RenderOne(xEnt* ent) STUB_VOID
void zEntPickup_RenderList(zEntPickup* plist, uint32 pcount) STUB_VOID
void zEntPickup_UpdateFlyToInterface(zEntPickup* ent, uint32 pcount, float32 dt) STUB_VOID
static uint32 rewardRequest(uint32 shinyType, xVec3* ppos, xVec3 pos) STUB
void zEntPickup_SceneEnter() STUB_VOID
void zEntPickup_SceneReset() STUB_VOID
void zEntPickup_SceneUpdate(float32 dt) STUB_VOID
static void spawnNRewards(uint32* pickups, uint32 num, xVec3* ppos, xVec3 pos) STUB_VOID
void zEntPickup_SpawnNRewards(uint32* pickups, uint32 num, xVec3* ppos) STUB_VOID
void zEntPickup_SpawnNRewards(uint32* pickups, uint32 num, xVec3 pos) STUB_VOID
void zEntPickup_RewardPostSetup() STUB_VOID