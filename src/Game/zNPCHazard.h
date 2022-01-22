#pragma once

#include "xMath3.h"
#include "xCollide.h"
#include "xMath2.h"

class zNPCCommon;
struct zLightning;
struct xShadowCache;
class NPCHazard;

enum en_npchaz
{
	NPC_HAZ_UNKNOWN,
	NPC_HAZ_EXPLODE,
	NPC_HAZ_EXPLODE_INNER,
	NPC_HAZ_FODBOMB,
	NPC_HAZ_CATTLEPROD,
	NPC_HAZ_TUBELETBLAST,
	NPC_HAZ_PUPPYNUKE,
	NPC_HAZ_DUPLOBOOM,
	NPC_HAZ_DUPLO_SHROOM,
	NPC_HAZ_PATRIOT,
	NPC_HAZ_TARTARPROJ,
	NPC_HAZ_TARTARSPILL,
	NPC_HAZ_TARTARSTINK,
	NPC_HAZ_CHUCKBOMB,
	NPC_HAZ_CHUCKBLAST,
	NPC_HAZ_CHUCKBLOOSH,
	NPC_HAZ_ARFBONE,
	NPC_HAZ_ARFBONEBLAST,
	NPC_HAZ_OILBUBBLE,
	NPC_HAZ_OILSLICK,
	NPC_HAZ_OILBURST,
	NPC_HAZ_OILGLOB,
	NPC_HAZ_MONCLOUD,
	NPC_HAZ_FUNFRAG,
	NPC_HAZ_THUNDER,
	NPC_HAZ_ROBOBITS,
	NPC_HAZ_VISSPLASH,
	NPC_HAZ_NOMORE,
	NPC_HAZ_FORCE = FORCEENUMSIZEINT
};

enum en_hazcol
{
	HAZ_COLTYP_STAT,
	HAZ_COLTYP_DYN,
	HAZ_COLTYP_NPC,
	HAZ_COLTYP_NOMORE,
	HAZ_COLTYP_FORCE = FORCEENUMSIZEINT
};

enum en_haznote
{
	HAZ_NOTE_DISCARD,
	HAZ_NOTE_ABORT,
	HAZ_NOTE_HITPLAYER,
	HAZ_NOTE_RECONFIG,
	HAZ_NOTE_NOMORE,
	HAZ_NOTE_FORCE = FORCEENUMSIZEINT
};

struct HAZTypical
{
	xMat3x3 mat_rotDelta;
	float32 rad_min;
	float32 rad_max;
	float32 rad_cur;
};

struct HAZCollide : HAZTypical
{
	xVec3 pos_collide;
	xVec3 dir_normal;
	xParabola parabinfo;
	struct
	{
		int32 flg_collide : 8;
		int32 flg_result : 8;
		int32 flg_unused : 16;
	};
	int32 cnt_skipcol;
	en_hazcol idx_rotateCol;
};

struct HAZMissile
{
	float32 vel;
};

struct HAZBall : HAZTypical
{
};

struct HAZRing : HAZTypical
{
	float32 hyt_ring;
};

struct HAZShroom : HAZTypical
{
	xVec3 vel_rise;
	xVec3 acc_rise;
};

struct HAZCloud : HAZTypical
{
	float32 spd_cloud;
	xVec3 pos_home;
	float32 rad_maxRange;
	float32 tmr_dozap;
	zLightning* zap_lytnin;
	zLightning* zap_warnin;
	xVec3 pos_warnin;
};

struct HAZPatriot : HAZMissile
{
	xVec3 pos_began;
	float32 spd_peak;
	float32 spd_curr;
	float32 acc_rate;
};

struct HAZTarTar : HAZCollide
{
	xVec3 vel;
	float32 spd_lob;
	xVec3 pos_tgt;
	uint32 streakID;
};

struct HAZCatProd : HAZBall
{
	zLightning* zap_lyta;
	zLightning* zap_lytb;
};

struct UVAModelInfo
{
	xVec2 offset_vel;
	uint32 flg_uvam;
	RpAtomic* model;
	RwTexCoords* uv;
	int32 uvsize;
	xVec2 offset;
};

class HAZNotify
{
public:
	HAZNotify() WIP {}

	virtual bool32 Notify(en_haznote note, NPCHazard*) WIP { return FALSE; }
};

class NPCHazard
{
private:
	en_npchaz typ_hazard;
	int32 flg_hazard;
	xVec3 pos_hazard;
	xModelInstance* mdl_hazard;
	UVAModelInfo* uva_uvanim;
	float32 tym_lifespan;
	float32 tmr_remain;
	float32 pam_interp;
	union
	{
		float32 tmr_generic;
		float32 tmr_nextglob;
	};
	union
	{
		int32 cnt_generic;
		int32 cnt_nextemit;
		int32 flg_casthurt;
	};
	union
	{
		HAZTypical typical;
		HAZCollide collide;
		HAZBall ball;
		HAZRing ring;
		HAZShroom shroom;
		HAZCloud cloud;
		HAZPatriot patriot;
		HAZTarTar tartar;
		HAZCatProd catprod;
	} custdata;
	HAZNotify* cb_notify;
	zNPCCommon* npc_owner;
	NPCHazard* haz_parent;
	xShadowCache* shadowCache;

public:
	void MarkForRecycle();
	void SetNPCOwner(zNPCCommon*) STUB_VOID;
	void NotifyCBSet(HAZNotify*) STUB_VOID;
};