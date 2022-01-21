#include "zThrown.h"

#include "zShrapnel.h"
#include "xEntDrive.h"

struct zThrownStruct;

struct CarryableStats
{
	float32 killTimer;
};

struct LaunchStats
{
	float32 throwSpeedXZ;
	float32 throwSpeedY;
	float32 collResetTimer;
};

struct ThrowableStats
{
	const char* name;
	void(*collCB)(zThrownStruct*, xEntCollis*, float32*, float32*);
	CarryableStats* carry;
	LaunchStats* launch;
	const char* glowColor;
	const char* shrapName;
	float32 stackHeight;
	uint32 nameHash;
	uint32 nameHashMINF;
	zShrapnelAsset* shrapAsset;
};

struct zThrownStruct
{
	xEnt* ent;
	xEnt* stackEnt;
	xEnt* stackTgt;
	xEnt* patLauncher;
	void(*oldupdate)(xEnt*, xScene*, float32);
	xVec3 vel;
	xVec3 oldcollpos;
	float32 collResetTimer;
	float32 killTimer;
	ThrowableStats* stats;
	uint32 oldRecShadow;
	xEntDrive drv;
	int32 driveDebounce;
	xEnt* driveLastFloor;
	xEntFrame frame;
};

static inline xBase* zThrown_ButtonIteratorCB(xBase* b, zScene*, void* user) STUB
static inline void checkAgainstButtons(xEnt*) STUB_VOID

void zThrown_Setup(zScene* sc) STUB_VOID
static void zThrown_AddTempFrame(zThrownStruct*) STUB_VOID
static void zFruit_ColorFade(zThrownStruct*) STUB_VOID
static void zFruit_Update(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
static void Recurse_TranslateStack(xEnt* ent, xVec3* delta) STUB_VOID
static void zThrown_Update(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void zThrown_Reset() STUB_VOID
void zThrown_LaunchVel(xEnt* ent, xVec3* vel) STUB_VOID
void zThrown_LaunchDir(xEnt* ent, xVec3* dir) STUB_VOID
bool32 zThrown_LaunchPos(xEnt* ent, xVec3* pos, xVec3* dir) STUB
void zThrown_LaunchStack(xEnt* ent, xEnt* stackTgt) STUB_VOID
void zThrown_PatrickLauncher(xEnt* ent, xEnt* launcher) STUB_VOID
void zThrown_AddFruit(xEnt* ent) STUB_VOID
void zThrown_Remove(xEnt* ent) STUB_VOID
bool32 zThrown_KillFruit(xEnt* ent) STUB
static bool32 zThrownCollide_CauseDamage(zThrownStruct* thrown, xEntCollis* collis) STUB
static void zThrownCollide_ThrowFruit(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
static void zThrownCollide_ThrowFreeze(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
static void zThrownCollide_DestructObj(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
static void zThrownCollide_BSandyHead(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
static void zThrownCollide_Tiki(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
static void zThrownCollide_StoneTiki(zThrownStruct* thrown, xEntCollis* collis, float32* bounce, float32* friction) STUB_VOID
bool32 zThrown_IsFruit(xEnt* ent, float32* stackHeight) STUB
bool32 zThrown_IsStacked(xEnt* ent) STUB