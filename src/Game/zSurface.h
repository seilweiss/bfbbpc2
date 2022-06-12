#pragma once

#include "xSurface.h"
#include "xMath3.h"

struct zSurfMatFX
{
	uint32 flags;
	uint32 bumpmapID;
	uint32 envmapID;
	float32 shininess;
	float32 bumpiness;
	uint32 dualmapID;
};

struct zSurfColorFX
{
	uint16 flags;
	uint16 mode;
	float32 speed;
};

struct zSurfTextureAnim
{
	uint16 pad;
	uint16 mode;
	uint32 group;
	float32 speed;
};

struct zSurfUVFX
{
	int32 mode;
	float32 rot;
	float32 rot_spd;
	xVec3 trans;
	xVec3 trans_spd;
	xVec3 scale;
	xVec3 scale_spd;
	xVec3 min;
	xVec3 max;
	xVec3 minmax_spd;
};

struct zSurfAssetBase : xBaseAsset
{
	uint8 game_damage_type;
	uint8 game_sticky;
	uint8 game_damage_flags;
	uint8 surf_type;
	uint8 phys_pad;
	uint8 sld_start;
	uint8 sld_stop;
	uint8 phys_flags;
	float32 friction;
	zSurfMatFX matfx;
	zSurfColorFX colorfx;
	uint32 texture_anim_flags;
	zSurfTextureAnim texture_anim[2];
	uint32 uvfx_flags;
	zSurfUVFX uvfx[2];
	uint8 on;
	uint8 surf_pad[3];
	float32 oob_delay;
	float32 walljump_scale_xz;
	float32 walljump_scale_y;
	float32 damage_timer;
	float32 damage_bounce;
};

struct zSurfacePropTexAnim
{
	uint16 mode;
	float32 speed;
	float32 frame;
	uint32 group;
	int32 group_idx;
	xBase* group_ptr;
};

struct zSurfacePropUVFX
{
	int32 mode;
	float32 rot;
	float32 rot_spd;
	float32 minmax_timer[2];
	xVec3 trans;
	xVec3 trans_spd;
	xVec3 scale;
	xVec3 scale_spd;
	xVec3 min;
	xVec3 max;
	xVec3 minmax_spd;
};

struct zSurfaceProps
{
	zSurfAssetBase* asset;
	uint32 texanim_flags;
	zSurfacePropTexAnim texanim[2];
	uint32 uvfx_flags;
	zSurfacePropUVFX uvfx[2];
};

#define ZSURFACEPROPS_TEXANIM_0x1 0x1
#define ZSURFACEPROPS_TEXANIM_0x2 0x2
#define ZSURFACEPROPS_UVFX_0x1 0x1
#define ZSURFACEPROPS_UVFX_0x2 0x2

struct xCollis;
struct xScene;

void zSurfaceInit();
void zSurfaceRegisterMapper(uint32 assetId);
void zSurfaceExit();
void zSurfaceResetSurface(xSurface*);
xSurface* zSurfaceGetSurface(uint32 mat_id);
xSurface* zSurfaceGetSurface(const xCollis* coll);
uint32 zSurfaceGetSlide(const xSurface* surf);
uint32 zSurfaceGetStep(const xSurface* surf);
bool zSurfaceOutOfBounds(const xSurface& s);
float32 zSurfaceGetSlideStartAngle(const xSurface* surf);
float32 zSurfaceGetSlideStopAngle(const xSurface* surf);
uint32 zSurfaceGetMatchOrient(const xSurface* surf);
int32 zSurfaceGetDamageType(const xSurface* surf);
uint32 zSurfaceGetDamagePassthrough(const xSurface* surf);
uint32 zSurfaceGetSticky(const xSurface* surf);
uint32 zSurfaceGetStandOn(const xSurface* surf);
float32 zSurfaceGetFriction(const xSurface* surf);
float32 zSurfaceGetOutOfBoundsDelay(const xSurface& s);
int32 zSurfaceGetSlickness(const xSurface* surf);
float32 zSurfaceGetDamping(const xSurface* surf, float32 min_vel);
void zSurfaceSave(xSurface* ent, xSerial* s);
void zSurfaceLoad(xSurface* ent, xSerial* s);
void zSurfaceSetup(xSurface* s);
void zSurfaceUpdate(xBase* to, xScene*, float32 dt);
void zSurfaceGetName(int32 type, char* buffer);
xSurface& zSurfaceGetDefault();