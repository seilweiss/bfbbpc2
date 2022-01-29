#pragma once

#include "xEnt.h"

class zMovePoint;
class zNPCCommon;

enum en_NPC_UI_WIDGETS
{
	NPC_WIDGE_TALK,
	NPC_WIDGE_NOMORE,
	NPC_WIDGE_FORCE
};

class NPCWidget
{
private:
	en_NPC_UI_WIDGETS idxID;
	xBase* base_widge;
	zNPCCommon* npc_ownerlock;

public:
	void Init(en_NPC_UI_WIDGETS);
	void Reset();
	bool32 On(const zNPCCommon* npc, bool32 theman);
	bool32 Off(const zNPCCommon* npc, bool32 theman);
	bool32 IsVisible();
	bool32 Lock(const zNPCCommon*);
	bool32 Unlock(const zNPCCommon*);
	bool32 NPCIsTheLocker(const zNPCCommon* npc_lock);
	bool32 IsLocked() STUB;
};

enum en_npctgt
{
	NPC_TGT_NONE,
	NPC_TGT_PLYR,
	NPC_TGT_ENT,
	NPC_TGT_BASE,
	NPC_TGT_POS,
	NPC_TGT_MVPT,
	NPC_TGT_NOMORE,
	NPC_TGT_FORCEINT = FORCEENUMSIZEINT
};

class NPCTarget
{
private:
	en_npctgt typ_target;
	union
	{
		xEnt* ent_target;
		xBase* bas_target;
		xVec3 pos_target;
		zMovePoint* nav_target;
	};
	zNPCCommon* npc_owner;

public:
	void TargetSet(xEnt*, int32);
	void TargetClear();
	bool32 FindNearest(int32 flg_consider, xBase* skipme, xVec3* from, float32 dst_max);
	void PosGet(xVec3* pos);
	bool32 InCylinder(xVec3* from, float32 rad, float32 hyt, float32 off);
	bool32 IsDead();
	bool32 HaveTarget() STUB;
};

class NPCLaser
{
private:
	RwRaster* rast_laser;
	float32 radius[2];
	float32 uv_scroll[2];
	RwRGBA rgba[2];
	float32 uv_base[2];

public:
	void Render(xVec3* pos_src, xVec3* pos_tgt);
	void ColorSet(const RwRGBA*, const RwRGBA*) STUB_VOID;
	void Prepare() STUB_VOID;
	void RadiusSet(float32, float32) STUB_VOID;
	void UVScrollSet(float32, float32) STUB_VOID;
	void TextureSet(RwRaster*) STUB_VOID;
	RwRaster* TextureGet() STUB;
	void UVScrollUpdate(float32) STUB_VOID;
};

class NPCCone
{
private:
	float32 rad_cone;
	RwRGBA rgba_top;
	RwRGBA rgba_bot;
	RwRaster* rast_cone;
	float32 uv_tip[2];
	float32 uv_slice[2];

public:
	void RenderCone(xVec3* pos_tiptop, xVec3* pos_botcenter);
	void TextureSet(RwRaster*) STUB_VOID;
	void UVSliceSet(float32, float32) STUB_VOID;
	void UVBaseSet(float32, float32) STUB_VOID;
	void ColorSet(RwRGBA, RwRGBA) STUB_VOID;
	void RadiusSet(float32) STUB_VOID;
};

class NPCBlinker
{
private:
	float32 tmr_uvcell;
	int32 idx_uvcell;

public:
	void Reset();
	void Update(float32 dt, float32 ratio, float32 tym_slow, float32 tym_fast);
	void IndexToUVCoord(int32, float32*, float32*);
	void Render(const xVec3* pos_blink, float32 rad_blink, const RwRaster* rast_blink);
};

enum en_fwstate
{
	FW_STAT_UNUSED,
	FW_STAT_READY,
	FW_STAT_FLIGHT,
	FW_STAT_BOOM,
	FW_STAT_DONE,
	FW_STAT_NOMORE,
	FW_STAT_FORCE = FORCEENUMSIZEINT
};

enum en_fwstyle
{
	FW_STYL_DEFAULT,
	FW_STYL_JULY4TH,
	FW_STYL_XMAS,
	FW_STYL_STPATS,
	FW_STYL_VALENTINE,
	FW_STYL_NOMORE,
	FW_STYL_FORCE = FORCEENUMSIZEINT
};

class Firework
{
private:
	struct
	{
		en_fwstate fwstate : 8;
		en_fwstyle fwstyle : 8;
		int32 flg_firework : 16;
	};
	float32 tym_lifespan;
	float32 tmr_remain;
	xVec3 pos;
	xVec3 vel;

public:
	void Cleanup();
	void Update(float32 dt);
	void FlyFlyFly(float32 dt);
	void Detonate();
};

typedef enum _tageNPCSnd
{
	eNPCSnd_GloveAttack,
	eNPCSnd_SleepyAttack,
	eNPCSnd_TubeAttack,
	eNPCSnd_FodBzztAttack,
	eNPCSnd_JellyfishAttack,
	eNPCSnd_Total
} eNPCSnd;

void NPCSupport_Startup();
void NPCSupport_Shutdown();
void NPCSupport_ScenePrepare();
void NPCSupport_SceneFinish();
void NPCSupport_ScenePostInit();
void NPCSupport_SceneReset();
void NPCSupport_Timestep(float32 dt);

void NPCWidget_Startup();
void NPCWidget_Shutdown();
void NPCWidget_ScenePrepare();
void NPCWidget_SceneFinish();
void NPCWidget_SceneReset();
void NPCWidget_ScenePostInit();
NPCWidget* NPCWidget_Find(en_NPC_UI_WIDGETS which);

void Firework_Release(Firework*);
void Firework_ScenePrepare();
void Firework_SceneFinish();
void Firework_SceneReset(bool32);
void Firework_Timestep(float32 dt);

void NPCC_ang_toXZDir(float32 angle, xVec3* dir);
float32 NPCC_dir_toXZAng(const xVec3* dir);
float32 NPCC_aimMiss(xVec3* dir_aim, xVec3* pos_src, xVec3* pos_tgt, float32 dst_miss, xVec3* pos_miss);
float32 NPCC_aimVary(xVec3* dir_aim, xVec3* pos_src, xVec3* pos_tgt, float32 dst_vary, int32 flg_vary, xVec3* pos_aimPoint);
bool32 NPCC_chk_hitPlyr(xBound* bnd, xCollis* collide);
bool32 NPCC_chk_hitEnt(xEnt* tgt, xBound* bnd, xCollis* collide);
bool32 NPCC_LineHitsBound(xVec3* a, xVec3* b, xBound* bnd, xCollis* callers_colrec);
bool32 NPCC_bnd_ofBase(xBase*, xBound*);
bool32 NPCC_pos_ofBase(xBase* tgt, xVec3* pos);
void NPCC_xBoundAway(xBound* bnd);
void NPCC_xBoundBack(xBound* bnd);
bool32 NPCC_HaveLOSToPos(xVec3* pos_src, xVec3* pos_tgt, float32 dst_max, xBase* tgt, xCollis* colCallers);
float32 NPCC_DstSqPlyrToPos(const xVec3* pos);
float32 NPCC_ds2_toCam(const xVec3* pos_from, xVec3* delta);
void NPCC_Bounce(xVec3* vec_input, xVec3* vec_anti, float32 elastic);
void NPCC_rotHPB(xMat3x3* mat, float32 heading, float32 pitch, float32 bank);
float32 NPCC_TmrCycle(float32* tmr, float32 dt, float32 interval);
void NPCC_MakePerp(xVec3* dir_perp, const xVec3* dir_axis);
void NPCC_MakeArbPlane(const xVec3* dir_norm, xVec3* at, xVec3* rt);
RwTexture* NPCC_FindRWTexture(const char* txtrname);
RwTexture* NPCC_FindRWTexture(uint32 hashid);
RwRaster* NPCC_FindRWRaster(const char* txtrname);
RwRaster* NPCC_FindRWRaster(RwTexture* txtr);
void NPCC_GenSmooth(xVec3** pos_base, xVec3** pos_mid);

void zNPC_SNDInit();
void zNPC_SNDPlay3D(eNPCSnd snd, xEnt* ent);
void zNPC_SNDStop(eNPCSnd snd);
int32 NPCC_LampStatus();
uint32 NPCC_ForceTalkOk();

inline xVec3* NPCC_rightDir(xEnt* ent) STUB
inline xVec3* NPCC_upDir(xEnt* ent) STUB
inline xVec3* NPCC_faceDir(xEnt* ent) STUB
inline float32 NPCC_DstSq(const xVec3*, const xVec3*, xVec3*) STUB
inline void NPCC_DrawPlayerPredict(int32, float32, float32) {}

inline float32 SQ(float32) STUB
inline float32 QUB(float32) STUB
inline float32 BOWL3(float32) STUB
inline float32 ARCH3(float32) STUB
inline float32 BOWL(float32) STUB
inline float32 ARCH(float32) STUB
inline uint8 LERP(float32, uint8, uint8) STUB
inline float32 LERP(float32, float32, float32) STUB
inline xVec3* LERP(float32, xVec3*, const xVec3*, const xVec3*) STUB
inline float32 EASE(float32) STUB
inline float32 SMOOTH(float32, float32, float32) STUB
inline xVec3* SMOOTH(float32, xVec3*, const xVec3*, const xVec3*) STUB
inline float32 RANGEWRAP(float32*, float32, float32) STUB