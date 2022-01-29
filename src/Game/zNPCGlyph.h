#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct xModelInstance;

enum en_npcglyph
{
	NPC_GLYPH_UNKNOWN,
	NPC_GLYPH_SHINYONE,
	NPC_GLYPH_SHINYFIVE,
	NPC_GLYPH_SHINYTEN,
	NPC_GLYPH_SHINYFIFTY,
	NPC_GLYPH_SHINYHUNDRED,
	NPC_GLYPH_TALK,
	NPC_GLYPH_TALKOTHER,
	NPC_GLYPH_FRIEND,
	NPC_GLYPH_DAZED,
	NPC_GLYPH_NOMORE,
	NPC_GLYPH_FORCE = FORCEENUMSIZEINT
};

class NPCGlyph
{
private:
	en_npcglyph typ_glyph;
	int32 flg_glyph;
	xModelInstance* mdl_glyph;
	xVec3 pos_glyph;
	xVec3 vel_glyph;
	xMat3x3 rot_glyph;
	xVec3 scl_glyph;
	float32 tmr_glyph;

public:
	NPCGlyph() {}
	NPCGlyph(en_npcglyph type) WIP : typ_glyph(type) {}

	void Reset();
	void Init(en_npcglyph, RpAtomic*);
	void Kill();
	void Render();
	void Enable(bool32 ison);
	void Discard();
	void PosSet(xVec3* pos);
	void VelSet(xVec3*);
	void ScaleSet(xVec3* scale);
	void RotSet(xVec3* ang, bool32 doautospin);
	void RotSet(xMat3x3*, bool32);
	void VelSet_Shiny();
	void RotAddDelta(xMat3x3* mat_rot);
	void Timestep(float32 dt);
};

void zNPCGlyph_Startup();
void zNPCGlyph_Shutdown();
void zNPCGlyph_ScenePrepare();
void zNPCGlyph_SceneFinish();
void zNPCGlyph_SceneReset();
void zNPCGlyph_ScenePostInit();
void zNPCGlyph_Timestep(float32 dt);
bool32 zNPCGlyph_TypeIsOpaque(en_npcglyph);
bool32 zNPCGlyph_TypeNeedsLightKit(en_npcglyph);
bool32 zNPCGlyph_TypeToList(en_npcglyph gtyp, NPCGlyph** glist);
void zNPCCommon_Glyphs_RenderAll(bool32 doOpaqueStuff);
NPCGlyph* GLYF_Acquire(en_npcglyph type);