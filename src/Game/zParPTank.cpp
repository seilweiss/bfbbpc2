#include "zParPTank.h"

uint32 gPTankDisable = FALSE;

namespace {

	struct snow_particle_data
	{
		xVec3 loc;
		float32 size;
		xVec3 vel;
		float32 life;
		float32 u;
		float32 pad[3];
	};

}

static void zParPTankSparkleCreate(zParPTank* zp, uint32 max_particles, zParPTankUpdateCallback update) STUB_VOID
static void zParPTankSparkleUpdate(zParPTank* zp, float32 dt) STUB_VOID
void zParPTankSpawnSparkles(xVec3* pos, uint32 count) STUB_VOID
static void zParPTankBubbleCreate(zParPTank* zp, uint32 max_particles, zParPTankUpdateCallback update) STUB_VOID
static void zParPTankMenuBubbleCreate(zParPTank* zp, uint32 max_particles, zParPTankUpdateCallback update) STUB_VOID
static void zParPTankBubbleUpdate(zParPTank* zp, float32 dt) STUB_VOID
static void zParPTankSpawnBubbles(xVec3* pos, xVec3* vel, uint32 count, float32 scale, zParPTank* zp) STUB_VOID
void zParPTankSpawnBubbles(xVec3* pos, xVec3* vel, uint32 count, float32 scale) STUB_VOID
int32 zParPTankBubblesAvailable() STUB
void zParPTankSpawnMenuBubbles(xVec3* pos, xVec3* vel, uint32 count) STUB_VOID
static void zParPTankSnowCreate(zParPTank*, uint32, zParPTankUpdateCallback) STUB_VOID
static void zParPTankSnowUpdate(zParPTank* zp, float32 dt) STUB_VOID
void zParPTankSpawnSnow(xVec3* pos, xVec3* vel, uint32 count) STUB_VOID
static void zParPTankSteamCreate(zParPTank* zp, uint32 max_particles, zParPTankUpdateCallback update) STUB_VOID
static void zParPTankSteamUpdate(zParPTank* zp, float32 dt) STUB_VOID
zParPTank* zParPTankAdd() STUB
void zParPTankInit() STUB_VOID
void zParPTankSceneEnter() STUB_VOID
void zParPTankSceneExit() {}
void zParPTankExit() STUB_VOID
void zParPTankUpdate(float32 dt) STUB_VOID
void zParPTankRender() STUB_VOID
int32 zParPTankConvertEmitRate(xParEmitter* pe, float32 dt) STUB