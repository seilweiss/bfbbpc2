#include "xNPCBasic.h"

void xNPCBasic::Init(xEntAsset* asset) STUB_VOID
void xNPCBasic::Reset() STUB_VOID

static void NPC_alwaysUseSphere(xEnt* ent, xVec3*) STUB_VOID
static void NPC_spdBasedColFreq(xNPCBasic* npc, float32 dt) STUB_VOID

void xNPCBasic::Process(xScene* xscn, float32 dt) STUB_VOID
void xNPCBasic::CollideReview() STUB_VOID
void xNPCBasic::NewTime(xScene*, float32) STUB_VOID

void NPC_entwrap_setup(xEnt* ent) STUB_VOID
void NPC_entwrap_reset(xEnt* ent) STUB_VOID
void NPC_entwrap_update(xEnt* ent, xScene* xscn, float32 dt_caller) STUB_VOID
void NPC_entwrap_bupdate(xEnt* ent, xVec3* pos) STUB_VOID
void NPC_entwrap_move(xEnt* ent, xScene* xscn, float32 dt, xEntFrame* frm) STUB_VOID
bool32 NPC_entwrap_event(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void NPC_entwrap_render(xEnt* ent) STUB_VOID