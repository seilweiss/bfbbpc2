#include "zNPCGlyph.h"

void zNPCGlyph_Startup() {}
void zNPCGlyph_Shutdown() {}
void zNPCGlyph_ScenePrepare() STUB_VOID
void zNPCGlyph_SceneFinish() STUB_VOID
void zNPCGlyph_SceneReset() {}
void zNPCGlyph_ScenePostInit() {}
void zNPCGlyph_Timestep(float32 dt) STUB_VOID
bool32 zNPCGlyph_TypeIsOpaque(en_npcglyph) STUB
bool32 zNPCGlyph_TypeNeedsLightKit(en_npcglyph) STUB
bool32 zNPCGlyph_TypeToList(en_npcglyph gtyp, NPCGlyph** glist) STUB
void zNPCCommon_Glyphs_RenderAll(bool32 doOpaqueStuff) STUB_VOID
NPCGlyph* GLYF_Acquire(en_npcglyph type) STUB

void NPCGlyph::Reset() STUB_VOID
void NPCGlyph::Init(en_npcglyph, RpAtomic*) STUB_VOID
void NPCGlyph::Kill() STUB_VOID
void NPCGlyph::Render() STUB_VOID
void NPCGlyph::Enable(bool32 ison) STUB_VOID
void NPCGlyph::Discard() STUB_VOID
void NPCGlyph::PosSet(xVec3* pos) STUB_VOID
void NPCGlyph::VelSet(xVec3*) STUB_VOID
void NPCGlyph::ScaleSet(xVec3* scale) STUB_VOID
void NPCGlyph::RotSet(xVec3* ang, bool32 doautospin) STUB_VOID
void NPCGlyph::RotSet(xMat3x3*, bool32) STUB_VOID
void NPCGlyph::VelSet_Shiny() STUB_VOID
void NPCGlyph::RotAddDelta(xMat3x3* mat_rot) STUB_VOID
void NPCGlyph::Timestep(float32 dt) STUB_VOID