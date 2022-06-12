#pragma once

#include "zEnt.h"
#include "xEntMotion.h"
#include "xEntDrive.h"

struct xPlatformERData
{
	int32 nodata;
};

struct xPlatformOrbitData
{
	int32 nodata;
};

struct xPlatformSplineData
{
	int32 nodata;
};

struct xPlatformMPData
{
	int32 nodata;
};

struct xPlatformMechData
{
	int32 nodata;
};

struct xPlatformPenData
{
	int32 nodata;
};

struct xPlatformConvBeltData
{
	float32 speed;
};

struct xPlatformFallingData
{
	float32 speed;
	uint32 bustModelID;
};

struct xPlatformFRData
{
	float32 fspeed;
	float32 rspeed;
	float32 ret_delay;
	float32 post_ret_delay;
};

struct xPlatformBreakawayData
{
	float32 ba_delay;
	uint32 bustModelID;
	float32 reset_delay;
	uint32 breakflags;
};

struct xPlatformSpringboardData
{
	float32 jmph[3];
	float32 jmpbounce;
	uint32 animID[3];
	xVec3 jmpdir;
	uint32 springflags;
};

struct xPlatformTeeterData
{
	float32 itilt;
	float32 maxtilt;
	float32 invmass;
};

struct xPlatformPaddleData
{
	int32 startOrient;
	int32 countOrient;
	float32 orientLoop;
	float32 orient[6];
	uint32 paddleFlags;
	float32 rotateSpeed;
	float32 accelTime;
	float32 decelTime;
	float32 hubRadius;
};

struct xPlatformFMData
{
	int32 nothingyet;
};

struct xPlatformAsset
{
	uint8 type;
	uint8 pad;
	uint16 flags;
	union
	{
		xPlatformERData er;
		xPlatformOrbitData orb;
		xPlatformSplineData spl;
		xPlatformMPData mp;
		xPlatformMechData mech;
		xPlatformPenData pen;
		xPlatformConvBeltData cb;
		xPlatformFallingData fall;
		xPlatformFRData fr;
		xPlatformBreakawayData ba;
		xPlatformSpringboardData sb;
		xPlatformTeeterData teet;
		xPlatformPaddleData paddle;
		xPlatformFMData fm;
	};
};

struct zPlatFMRunTime
{
	uint32 flags;
	float32 tmrs[12];
	float32 ttms[12];
	float32 atms[12];
	float32 dtms[12];
	float32 vms[12];
	float32 dss[12];
};

struct zPlatform : zEnt
{
	xPlatformAsset* passet;
	xEntMotion motion;
	uint16 state;
	uint16 plat_flags;
	float32 tmr;
	int32 ctr;
	xMovePoint* src;
	xModelInstance* am;
	xModelInstance* bm;
	int32 moving;
	xEntDrive drv;
	zPlatFMRunTime* fmrt;
	float32 pauseMult;
	float32 pauseDelta;
};

#define ZPLATFORM_PLATFORM 0
#define ZPLATFORM_MECH 4
#define ZPLATFORM_PEN 5
#define ZPLATFORM_CONVBELT 6
#define ZPLATFORM_FALLING 7
#define ZPLATFORM_FR 8
#define ZPLATFORM_BREAKAWAY 9
#define ZPLATFORM_SPRINGBOARD 10
#define ZPLATFORM_TEETER 11
#define ZPLATFORM_PADDLE 12
#define ZPLATFORM_FM 13

void zPlatform_Init(void* plat, void* asset);
void zPlatform_Init(zPlatform* plat, xEntAsset* asset);
void zPlatform_Setup(zPlatform* plat, xScene*);
void zPlatform_Save(zPlatform* ent, xSerial* s);
void zPlatform_Load(zPlatform* ent, xSerial* s);
void zPlatform_Reset(zPlatform* plat, xScene* sc);
void zPlatform_PaddleStartRotate(xEnt* entplat, int32 direction, int32 stutter);
uint32 zPlatform_PaddleCollide(xCollis* coll, const xVec3* hitsource, const xVec3* hitvel, uint32 worldSpaceNorm);
void zPlatform_Update(xEnt* entplat, xScene* sc, float32 dt);
void zPlatform_Move(xEnt* entplat, xScene* s, float32 dt, xEntFrame* frame);
void zPlatform_Shake(zPlatform* plat, float32, float32 ampl, float32 freq);
void zPlatform_Mount(zPlatform* plat);
void zPlatform_Dismount(zPlatform* plat);
bool32 zPlatformEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);