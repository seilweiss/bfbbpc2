#pragma once

#include "zNPCHazard.h"
#include "zCutsceneMgr.h"

struct zParEmitter;
struct zShrapnelAsset;

enum en_ncinfx
{
	NCIN_FXTYP_UNKNOWN,
	NCIN_FXTYP_EXAMPLE,
	NCIN_FXTYP_BUBSLAM_LG,
	NCIN_FXTYP_BUBSLAM_SM,
	NCIN_FXTYP_SMOKETRAIL,
	NCIN_FXTYP_BUBTRAIL,
	NCIN_FXTYP_BUBTRAILBONE,
	NCIN_FXTYP_BUBWIPE,
	NCIN_FXTYP_JELLYLIGHT_01,
	NCIN_FXTYP_WATERSPLASH,
	NCIN_FXTYP_TARTARSHOOT,
	NCIN_FXTYP_OILSHOOT,
	NCIN_FXTYP_BONESHOOT,
	NCIN_FXTYP_BONETRAIL,
	NCIN_FXTYP_BOMBTRAIL,
	NCIN_FXTYP_OILHAZARD,
	NCIN_FXTYP_TARTARSTEAM,
	NCIN_FXTYP_ARFDOGBOOM,
	NCIN_FXTYP_SHIELDPOP,
	NCIN_FXTYP_TTGUNSMOKE,
	NCIN_FXTYP_SPATULAGLOW,
	NCIN_FXTYP_HOOKRECOIL,
	NCIN_FXTYP_FODDERPROD,
	NCIN_FXTYP_BZZTDANCE,
	NCIN_FXTYP_BZZTBEAM,
	NCIN_FXTYP_BADBREATH,
	NCIN_FXTYP_BOMBBLINK,
	NCIN_FXTYP_HAMSHOCK,
	NCIN_FXTYP_HAMSTREAK,
	NCIN_FXTYP_MONCLOUD,
	NCIN_FXTYP_MIDFISH,
	NCIN_FXTYP_GLOVEFRAG,
	NCIN_FXTYP_MARYBOOM,
	NCIN_FXTYP_PETEBONK,
	NCIN_FXTYP_FIRESPIRAL,
	NCIN_FXTYP_SLEEPYLAMP,
	NCIN_FXTYP_SLEEPYDRAY,
	NCIN_FXTYP_B101OPEN_SBENTER,
	NCIN_FXTYP_B101OPEN_PATENTER,
	NCIN_FXTYP_B101OPEN_SHOCKWAVE,
	NCIN_FXTYP_B101ROUND1_SHOCK1,
	NCIN_FXTYP_B101ROUND1_SHOCK2,
	NCIN_FXTYP_B101ROUND1_SHOCK3,
	NCIN_FXTYP_B101ENDING_SHOCK1,
	NCIN_FXTYP_B101ENDING_SHOCK2,
	NCIN_FXTYP_B101ENDING_SHOCK3,
	NCIN_FXTYP_B101ENDING_SHOCK4,
	NCIN_FXTYP_B101ENDING_SHOCKWAVE,
	NCIN_FXTYP_B201OPEN_FREEZE,
	NCIN_FXTYP_B201ROUND1_FREEZE,
	NCIN_FXTYP_B201HIDECONVEYOR,
	NCIN_FXTYP_B201GOOLEVER,
	NCIN_FXTYP_B201FRAG,
	NCIN_FXTYP_B303STUFF,
	NCIN_FXTYP_PAR_ENTITY_BONE,
	NCIN_FXTYP_PROBE,
	NCIN_FXTYP_DUPLOPUFFS,
	NCIN_FXTYP_SPAWNRING,
	NCIN_FXTYP_BUBPLYRSKEL,
	NCIN_FXTYP_GLINT,
	NCIN_FXTYP_NOMORE,
	NCIN_FXTYP_FORCE = FORCEENUMSIZEINT
};

struct NCINLyt
{
	zLightning* lyt_zap;
};

struct NCINHaz
{
	NPCHazard* npchaz;
};

struct NCINLamp
{
	xVec3 pos_robo;
	RwRaster* rast;
};

struct NCINDRay
{
	RwRaster* rast;
};

struct NCINStrk
{
	uint32 sid_vert;
	uint32 sid_horz;
};

struct NCINArc
{
	zLightning* lightning;
	xVec3 endPos;
};

struct NCINPar
{
	zParEmitter* emitter;
};

struct NCINEnts
{
	xEnt* ent[4];
};

struct NCINShrap
{
	zShrapnelAsset* shrap;
};

struct NCINCustom
{
	float32 f[1];
	xVec3 v[2];
};

struct NCINRast
{
	RwRaster* raster;
};

struct NCINMat
{
	RwMatrix* mat;
};

union NCINData
{
	NCINLyt lytdata;
	NCINHaz hazdata;
	NCINLamp lampdata;
	NCINDRay draydata;
	NCINStrk strkdata;
	NCINArc arcdata;
	NCINPar pardata;
	NCINEnts entdata;
	NCINShrap shrapdata;
	NCINCustom customdata;
	NCINRast rastinfo;
	NCINMat matdata;
};

struct NCINEntry
{
	en_ncinfx typ_ncinfx;
	void(*cb_fxupd)(const zCutsceneMgr*, NCINEntry*, int32);
	void(*cb_fxanim)(const zCutsceneMgr*, NCINEntry*, RpAtomic*, RwMatrix*, uint32, uint32);
	void(*cb_fxrend)(const zCutsceneMgr*, NCINEntry*);
	float32 tym_beg;
	float32 tym_end;
	xVec3 pos_A[2];
	xVec3 pos_B[2];
	char* twk_name;
	int32 idx_anim;
	int32 idx_bone;
	int32 flg_stat;
	NCINData fxdata;
};

class NCINBeNosey : public XCSNNosey
{
private:
	zCutsceneMgr* use_csnmgr;
	NCINEntry* use_fxtab;

public:
	NCINBeNosey() WIP : XCSNNosey() {}

	virtual void CanRenderNow();
	virtual void UpdatedAnimated(RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32 dataIndex);

	void Init(const zCutsceneMgr*, NCINEntry*, int32) STUB_VOID;
	void Done() STUB_VOID;
};

void zNPCFXStartup();
void zNPCFXShutdown();
bool32 zNPCFXCutscenePrep(const xScene*, float32, const zCutsceneMgr* csnmgr);
void zNPCFXCutsceneDone(const xScene*, float32, const zCutsceneMgr* csnmgr);
void zNPCFXCutscene(const xScene*, float32, const zCutsceneMgr* csnmgr);