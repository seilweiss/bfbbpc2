#pragma once

#include "zLightning.h"
#include "xPtankPool.h"
#include "xFX.h"

class zNPCCommon;
struct xShadowCache;
struct xEnt;

enum en_npclyt
{
	NPC_LYT_PLACEHOLDER,
	NPC_LYT_JELLYFISH,
	NPC_LYT_JELLYFISHBLUE,
	NPC_LYT_CATTLEPROD,
	NPC_LYT_TIKITHUNDER,
	NPC_LYT_CLOUDWARN,
	NPC_LYT_CLOUDZAP,
	NPC_LYT_SLEEPYARC,
	NPC_LYT_NOMORE,
	NPC_LYT_FORCE = FORCEENUMSIZEINT
};

enum en_npcstreak
{
	NPC_STRK_TARTARBLOB,
	NPC_STRK_OILBUBBLE,
	NPC_STRK_HAMMERSMASH_VERT,
	NPC_STRK_HAMMERSMASH_HORZ,
	NPC_STRK_ARFMELEE,
	NPC_STRK_TOSSEDROBOT,
	NPC_STRK_TOSSEDJELLY,
	NPC_STRK_TOSSEDJELLYBLUE,
	NPC_STRK_NOMORE,
	NPC_STRK_FORCE = FORCEENUMSIZEINT
};

enum en_npcburst
{
	NPC_BURST_OILBUB,
	NPC_BURST_TUBEBONK,
	NPC_BURST_NOMORE,
	NPC_BURST_FORCE = FORCEENUMSIZEINT
};

enum en_nparptyp
{
	NPAR_TYP_UNKNOWN,
	NPAR_TYP_OILBUB,
	NPAR_TYP_TUBESPIRAL,
	NPAR_TYP_TUBECONFETTI,
	NPAR_TYP_GLOVEDUST,
	NPAR_TYP_MONSOONRAIN,
	NPAR_TYP_SLEEPYZEEZ,
	NPAR_TYP_CHUCKSPLASH,
	NPAR_TYP_TARTARGUNK,
	NPAR_TYP_DOGBREATH,
	NPAR_TYP_VISSPLASH,
	NPAR_TYP_FIREWORKS,
	NPAR_TYP_NOMORE,
	NPAR_TYP_FORCE = FORCEENUMSIZEINT
};

struct NPARData
{
	xVec3 pos;
	float32 xy_size[2];
	float32 uv_tl[2];
	float32 uv_br[2];
	RwRGBA color;
	float32 tmr_remain;
	float32 tym_exist;
	float32 fac_abuse;
	xVec3 vel;
	struct
	{
		int32 flg_popts : 24;
		int32 nparmode : 8;
	};
	float32 unused[3];
};

struct NPARXtraData
{
};

class NPARMgmt
{
private:
	en_nparptyp typ_npar;
	int32 flg_npar;
	NPARData* par_buf;
	int32 cnt_active;
	int32 num_max;
	RwTexture* txtr;
	NPARXtraData* xtra_data;
	void** user_data;

public:
	void Init(en_nparptyp parType, void** userData, NPARXtraData* xtraData);
	void Clear();
	void UpdateAndRender(float32);
	void Done() STUB_VOID;
	void Reset() STUB_VOID;
	bool32 IsReady() STUB;
	void XtraDataSet(NPARXtraData*) STUB_VOID;
	void UserDataSet(void**) STUB_VOID;
	void PromoteTail(int32) STUB_VOID;
	NPARData* NextAvail() STUB;
	void KillAll() STUB_VOID;
};

enum en_nparmode
{
	NPAR_MODE_STD = 0,
	NPAR_MODE_ALT_A = 1,
	NPAR_MODE_ALT_B,
	NPAR_MODE_ALT_C,
	NPAR_MODE_ALT_D,
	NPAR_MODE_ALT_E,
	NPAR_MODE_SPIRALNORM = 1,
	NPAR_MODE_SPIRALCALT,
	NPAR_MODE_SPIRALCINE,
	NPAR_MODE_OIL_TRAIL = 1,
	NPAR_MODE_OIL_VAPOR,
	NPAR_MODE_OIL_SPLASH,
	NPAR_MODE_FETTI_SPARKLIES = 1,
	NPAR_MODE_DRIP = 1,
	NPAR_MODE_DROP,
	NPAR_MODE_SPLASH,
	NPAR_MODE_TRAIL,
	NPAR_MODE_TTNOZZLE = 1,
	NPAR_MODE_TTTRAIL,
	NPAR_MODE_TTSPLASH,
	NPAR_MODE_TTSPOIL,
	NPAR_MODE_TTSMOKE,
	NPAR_MODE_DOGGYWISP = 1,
	NPAR_MODE_DOGGYATTACK,
	NPAR_MODE_FWEXHAUST = 1,
	NPAR_MODE_FWSTARBURST,
	NPAR_MODE_FWGLITTER,
	NPAR_MODE_NOMORE
};

class NPARParmOilBub
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	xVec3 acc_oilBubble;
	float32 siz_base[2];

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmTubeSpiral
{
private:
	RwRGBA colr_base;
	float32 siz_base[2];

public:
	void ConfigPar(NPARData*, en_nparmode, const xVec3*, const xVec3*, float32) const;
};

class NPARParmTubeConfetti
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	float32 uv_scroll[2];
	uint8 row_uvstart;
	uint8 num_uvcell[2];
	uint8 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmGloveDust
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmSleepyZeez
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	float32 uv_scroll[2];
	uint8 row_uvstart;
	uint8 num_uvcell[2];
	uint8 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmChuckSplash
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	int32 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmVisSplash
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	int32 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmTarTarGunk
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	float32 uv_scroll[2];
	uint8 row_uvstart;
	uint8 num_uvcell[2];
	uint8 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmDogBreath
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	uint8 pct_keep;
	uint8 unused[3];

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

class NPARParmFahrwerkz
{
private:
	float32 tym_lifespan;
	RwRGBA colr_base;
	float32 siz_base[2];
	xVec3 acc_base;
	float32 uv_scroll[2];
	uint8 row_uvstart;
	uint8 num_uvcell[2];
	uint8 pct_keep;

public:
	void ConfigPar(NPARData* par, en_nparmode pmod, const xVec3* pos, const xVec3* vel) const;
};

void NPCSupplement_Startup();
void NPCSupplement_Shutdown();
void NPCSupplement_ScenePrepare();
void NPCSupplement_SceneFinish();
void NPCSupplement_ScenePostInit();
void NPCSupplement_SceneReset();
void NPCSupplement_Timestep(float32 dt);
void NPCC_MakeLightningInfo(en_npclyt style, LightningAdd* info);
void NPCC_MakeStreakInfo(en_npcstreak styp, StreakInfo* info);
uint32 NPCC_StreakCreate(en_npcstreak styp);
void NPCC_BurstBubble(en_npcburst burst, xVec3* pos_base);
void NPCC_MakeASplash(const xVec3* pos, float32 radius);
void NPCC_Slick_MakePlayerSlip(zNPCCommon* npc);
void NPCC_RenderProjTexture(RwRaster* rast, float32 factor, xMat4x3* mat, float32 radius, float32 height, xShadowCache* cache, int32 fillCache, xEnt* ent);
void NPCC_RenderProjTextureFaceCamera(RwRaster* rast, float32 factor, xVec3* pos, float32 radius, float32 height, xShadowCache* cache, int32 fillCache, xEnt* ent);
void NPAR_ScenePrepare();
void NPAR_SceneFinish();
void NPAR_SceneReset();
void NPAR_Timestep(float32 dt);
NPARMgmt* NPAR_PartySetup(en_nparptyp parType, void** userData, NPARXtraData* xtraData);
NPARMgmt* NPAR_FindParty(en_nparptyp parType);
void NPAR_Upd_OilBubble(NPARMgmt* mgmt, float32 dt);
void NPAR_CopyNPARToPTPool(NPARData*, ptank_pool__pos_color_size_uv2*);
void NPAR_Upd_TubeSpiral(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_TubeConfetti(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_GloveDust(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_MonsoonRain(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_SleepyZeez(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_ChuckSplash(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_VisSplash(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_TarTarGunk(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_DogBreath(NPARMgmt* mgmt, float32 dt);
void NPAR_Upd_Fireworks(NPARMgmt* mgmt, float32 dt);
void NPAR_EmitOilShieldPop(const xVec3* pos);
void NPAR_EmitOilTrailz(const xVec3* pos);
void NPAR_EmitOilVapors(const xVec3* pos);
void NPAR_EmitOilSplash(const xVec3* pos, const xVec3* vel);
void NPAR_EmitOilBubble(en_nparmode, const xVec3*, const xVec3*);
void NPAR_EmitTubeSpiral(const xVec3* pos, const xVec3* vel, float32 lifespan);
void NPAR_EmitTubeSpiralCin(const xVec3* pos, const xVec3* vel, float32 lifespan);
void NPAR_EmitTubeConfetti(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTubeSparklies(const xVec3* pos, const xVec3* vel);
void NPAR_EmitGloveDust(const xVec3* pos, const xVec3* vel);
void NPAR_EmitSleepyZeez(const xVec3* pos, const xVec3* vel);
void NPAR_EmitH2ODrips(const xVec3* pos, const xVec3* vel);
void NPAR_EmitH2ODrops(const xVec3* pos, const xVec3* vel);
void NPAR_EmitH2OSpray(const xVec3* pos, const xVec3* vel);
void NPAR_EmitH2OTrail(const xVec3* pos);
void NPAR_EmitDroplets(en_nparmode, const xVec3*, const xVec3*);
void NPAR_EmitTarTarNozzle(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTarTarTrail(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTarTarSplash(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTarTarSpoil(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTarTarSmoke(const xVec3* pos, const xVec3* vel);
void NPAR_EmitTarTarGunk(en_nparmode, const xVec3*, const xVec3*);
void NPAR_EmitDoggyWisps(const xVec3* pos, const xVec3* vel);
void NPAR_EmitDoggyAttack(const xVec3* pos, const xVec3* vel);
void NPAR_EmitDoggyBreath(en_nparmode, const xVec3*, const xVec3*);
void NPAR_EmitVSSpray(const xVec3* pos, const xVec3* vel);
void NPAR_EmitVisSplash(en_nparmode, const xVec3*, const xVec3*);
void NPAR_EmitFWExhaust(const xVec3* pos, const xVec3* vel);
void NPAR_EmitFireworks(en_nparmode, const xVec3*, const xVec3*);
xShadowCache* NPCC_ShadowCacheReserve();
void NPCC_ShadowCacheRelease(xShadowCache* shadcache);