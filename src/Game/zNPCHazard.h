#pragma once

#include "xMath3.h"
#include "xCollide.h"
#include "xMath2.h"
#include "xColor.h"

class zNPCCommon;
struct zLightning;
struct xShadowCache;
class NPCHazard;
struct xAnimTable;

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

enum en_hazmodel
{
	NPC_HAZMDL_BOOMBALL_BUBBLE,
	NPC_HAZMDL_BOOMBALL_SMOKE,
	NPC_HAZMDL_FODBOMB,
	NPC_HAZMDL_TUBEBLAST,
	NPC_HAZMDL_DUPLOBOOM,
	NPC_HAZMDL_CATTLEPROD,
	NPC_HAZMDL_TARTARPROJ,
	NPC_HAZMDL_TARTARSPLAT,
	NPC_HAZMDL_TARTARSTEAM,
	NPC_HAZMDL_CHUCKBOMB,
	NPC_HAZMDL_CHUCKSPLISH,
	NPC_HAZMDL_CHUCKSPLASH,
	NPC_HAZMDL_ARFBONE,
	NPC_HAZMDL_SLICKPROJ,
	NPC_HAZMDL_SLICKPUDDLE,
	NPC_HAZMDL_SLICKBURST,
	NPC_HAZMDL_SLICKGLOB,
	NPC_HAZMDL_MONCLOUD,
	NPC_HAZMDL_FUNFRAG_WRENCH,
	NPC_HAZMDL_FUNFRAG_JOYSTICK,
	NPC_HAZMDL_FUNFRAG_SINK,
	NPC_HAZMDL_FUNFRAG_DUCK,
	NPC_HAZMDL_FUNFRAG_BRA,
	NPC_HAZMDL_FUNFRAG_HEADPHONES,
	NPC_HAZMDL_FUNFRAG_CELLPHONE,
	NPC_HAZMDL_FUNFRAG_SHOE,
	NPC_HAZMDL_THUNDER,
	NPC_HAZMDL_ROBOBITS,
	NPC_HAZMDL_VISSPLASH,
	NPC_HAZMDL_PUPPYNUKE,
	NPC_HAZMDL_NOMORE,
	NPC_HAZMDL_FORCE = FORCEENUMSIZEINT
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

class UVAModelInfo
{
private:
	xVec2 offset_vel;
	uint32 flg_uvam;
	RpAtomic* model;
	RwTexCoords* uv;
	int32 uvsize;
	xVec2 offset;

public:
	bool32 Init(RpAtomic* model, uint32 flg_uvamCaller);
	void Hemorrage();
	void Update(float32 dt, const xVec2* use_offset);
	void Refresh();
	void SetColor(xColor);
	bool32 GetUV(RwTexCoords*&, int32&, RpAtomic*) const;
	bool32 CloneUV(RwTexCoords*&, int32&, RpAtomic*) const;
	void Clear() STUB_VOID;
	void UVVelSet(float32, float32) STUB_VOID;
	bool32 Valid() const STUB;
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
	NPCHazard() {}
	NPCHazard(en_npchaz hazard) WIP : typ_hazard(hazard) {}

	void WipeIt();
	bool32 ConfigHelper(en_npchaz haztype);
	void Reconfigure(en_npchaz haztype);
	UVAModelInfo* GetUVAInfo(en_hazmodel, float32, float32);
	bool32 GrabModel(en_hazmodel idx_model);
	void FreeModel();
	void Discard();
	void Kill();
	void Start(const xVec3* pos, float32 tym);
	void PosSet(const xVec3* pos);
	void Timestep(float32 dt);
	void Render();
	void Cleanup();
	void SetAlpha(float32);
	bool32 ColTestSphere(const xBound*, float32);
	bool32 ColTestCyl(const xBound* bnd_tgt, float32 rad, float32 hyt);
	bool32 ColPlyrSphere(float32);
	bool32 ColPlyrCyl(float32, float32);
	void HurtThePlayer();
	void TypData_RotMatStore(xVec3*);
	void TypData_RotMatSet(xMat3x3*);
	void TypData_RotMatApply(xMat3x3*);
	void OrientToDir(const xVec3* vec_path, bool32 doTheTwist);
	en_hazmodel PickFunFrag();
	void PreCollide();
	int32 StaggeredCollide();
	void StagColGeneral(int32 who);
	void StagColStat();
	void StagColDyn();
	void StagColNPC();
	void CollideResponse(xSweptSphere* swdata, float32 tym_inFuture);
	void ColResp_Default(xSweptSphere* swdata, float32 tym_inFuture);
	void Upd_Explode(float32);
	void DeathStar();
	void Upd_PuppyNuke(float32 dt);
	void Upd_FodBomb(float32 dt);
	void FodBombBubbles(float32);
	void Upd_CattleProd(float32);
	void Upd_TubeletBlast(float32);
	void Upd_DuploBoom(float32);
	void Upd_TikiThunder(float32);
	void Upd_Mushroom(float32 dt);
	void Upd_Patriot(float32);
	void Upd_TTFlight(float32);
	void ReconTarTar();
	void Upd_TTSpill(float32);
	int32 KickSteamyStinky();
	void Upd_TTStink(float32);
	void TarTarFalumpf();
	void TarTarGunkTrail();
	void TarTarSplash(const xVec3* dir_norm);
	void TarTarLinger();
	void Upd_ChuckBomb(float32 dt);
	void DisperseBubWake(float32 radius, const xVec3* velocity);
	void ReconChuck();
	void Upd_ChuckBlast(float32);
	void WaterSplash(const xVec3* dir_norm);
	void WavesOfEvil();
	int32 KickBlooshBlob(const xVec3* vel_flight);
	void Upd_ChuckBloosh(float32);
	void Upd_BoneFlight(float32 dt);
	void ReconArfBone();
	void Upd_BoneBlast(float32 dt);
	void Upd_OilBubble(float32);
	void ReconSlickOil();
	void OilSplash(const xVec3* dir_norm);
	void Upd_OilOoze(float32 dt);
	int32 KickOilBurst();
	int32 KickOilGlobby();
	void Upd_OilBurst(float32);
	void Upd_OilGlob(float32 dt);
	void Upd_MonCloud(float32 dt);
	void Upd_FunFrag(float32);
	void StreakUpdate(uint32 streakID, float32 rad);
	void Upd_RoboBits(float32);
	void Upd_VisSplash(float32);
	void VisSplashSparklies();
	void MarkForRecycle() STUB_VOID;
	void SetNPCOwner(zNPCCommon*) STUB_VOID;
	void NotifyCBSet(HAZNotify*) STUB_VOID;
	const xVec3& Right() const STUB_REF(xVec3);
	const xVec3& Up() const STUB_REF(xVec3);
	const xVec3& At() const STUB_REF(xVec3);
};

typedef bool(*HAZ_Iterate_Callback)(NPCHazard&, void*);

void zNPCHazard_Startup();
void zNPCHazard_Shutdown();
void zNPCHazard_ScenePrepare();
void zNPCHazard_SceneFinish();
void zNPCHazard_SceneReset();
void zNPCHazard_ScenePostInit();
void zNPCHazard_InitEffects();
void zNPCHazard_KillEffects();
void zNPCHazard_Timestep(float32 dt);
void zNPCCommon_Hazards_RenderAll(bool32 doOpaqueStuff);
NPCHazard* HAZ_Acquire();
int32 HAZ_AvailablePool();
void HAZ_Iterate(HAZ_Iterate_Callback fp, void* context, int32 flag_filter);
xAnimTable* ZNPC_AnimTable_HazardStd();