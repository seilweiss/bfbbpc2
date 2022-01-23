#pragma once

#include "xEnt.h"
#include "xFactory.h"
#include "xShadowSimple.h"

// not in dwarf data
enum en_npcdcat
{
};

// not in dwarf data
enum en_npcperf
{
};

enum en_npcbtyp
{
	NPCP_BASIS_NONE,
	NPCP_BASIS_EVILROBOT,
	NPCP_BASIS_FRIENDLYROBOT,
	NPCP_BASIS_LOVINGCITIZEN,
	NPCP_BASIS_GRUMPYCITIZEN,
	NPCP_BASIS_NOMORE,
	NPCP_BASIS_FORCE = FORCEENUMSIZEINT
};

enum en_dupowavmod
{
	NPCP_DUPOWAVE_CONTINUOUS,
	NPCP_DUPOWAVE_DISCREET,
	NPCP_DUPOWAVE_NOMORE,
	NPCP_DUPOWAVE_FORCE = FORCEENUMSIZEINT
};

enum en_npcparm
{
	NPC_PARM_NONE,
	NPC_PARM_MOVERATE,
	NPC_PARM_TURNRATE,
	NPC_PARM_ACCEL,
	NPC_PARM_DRIFT,
	NPC_PARM_MASS,
	NPC_PARM_TOSSGRAV,
	NPC_PARM_TOSSELASTIC,
	NPC_PARM_BND_ISBOX,
	NPC_PARM_BND_CENTER,
	NPC_PARM_BND_EXTENT,
	NPC_PARM_HITPOINTS,
	NPC_PARM_MODELSCALE,
	NPC_PARM_DETECT_RAD,
	NPC_PARM_DETECT_HYT,
	NPC_PARM_DETECT_OFF,
	NPC_PARM_ATTACK_RAD,
	NPC_PARM_ATTACK_FOV,
	NPC_PARM_SND_RAD,
	NPC_PARM_TIMEFIDGET,
	NPC_PARM_TIMEATTACK,
	NPC_PARM_TIMESTUN,
	NPC_PARM_TIMEALERT,
	NPC_PARM_VTX_ATTACKBASE,
	NPC_PARM_VTX_ATTACK,
	NPC_PARM_VTX_ATTACK1,
	NPC_PARM_VTX_ATTACK2,
	NPC_PARM_VTX_ATTACK3,
	NPC_PARM_VTX_ATTACK4,
	NPC_PARM_VTX_EYEBALL,
	NPC_PARM_VTX_DMGSMOKEA,
	NPC_PARM_VTX_DMGSMOKEB,
	NPC_PARM_VTX_DMGSMOKEC,
	NPC_PARM_VTX_DMGFLAMEA,
	NPC_PARM_VTX_DMGFLAMEB,
	NPC_PARM_VTX_DMGFLAMEC,
	NPC_PARM_VTX_PROPEL,
	NPC_PARM_VTX_EXHAUST,
	NPC_PARM_VTX_GEN01,
	NPC_PARM_VTX_GEN02,
	NPC_PARM_VTX_GEN03,
	NPC_PARM_VTX_GEN04,
	NPC_PARM_VTX_GEN05,
	NPC_PARM_ATK_SIZE01,
	NPC_PARM_ATK_FRAMES01,
	NPC_PARM_ATK_FRAMES01A,
	NPC_PARM_ATK_FRAMES01B,
	NPC_PARM_ATK_FRAMES02,
	NPC_PARM_ATK_FRAMES02A,
	NPC_PARM_ATK_FRAMES02B,
	NPC_PARM_ATK_FRAMES03,
	NPC_PARM_ATK_FRAMES03A,
	NPC_PARM_ATK_FRAMES03B,
	NPC_PARM_ESTEEM_A,
	NPC_PARM_ESTEEM_B,
	NPC_PARM_ESTEEM_C,
	NPC_PARM_ESTEEM_D,
	NPC_PARM_ESTEEM_E,
	NPC_PARM_SHADOW_CASTDIST,
	NPC_PARM_SHADOW_RADCACHE,
	NPC_PARM_SHADOW_RADRASTER,
	NPC_PARAM_TEST_COUNT,
	NPC_PARM_ENDTAG_INI,
	NPC_PARM_FIRSTMVPT,
	NPC_PARM_ENDTAG_PROPS,
	NPC_PARM_BOGUSSHARE,
	NPC_PARM_ENDTAG_SHARE,
	NPC_PARM_NOMORE,
	NPC_PARM_FORCEINT = FORCEENUMSIZEINT
};

class xNPCBasic : public xEnt, public xFactoryInst
{
private:
	void(*f_setup)(xEnt*);
	void(*f_reset)(xEnt*);
	struct
	{
		int32 flg_basenpc : 16;
		int32 inUpdate : 8;
		int32 flg_upward : 8;
	};
	int32 colFreq;
	int32 colFreqReset;
	struct
	{
		uint32 flg_colCheck : 8;
		uint32 flg_penCheck : 8;
		uint32 flg_unused : 16;
	};
	int32 myNPCType;
	xEntShadow entShadow_embedded;
	xShadowSimpleCache simpShadow_embedded;

public:
	xNPCBasic(int32 myType) WIP : xFactoryInst(), myNPCType(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void PostInit() WIP {}
	virtual void Setup() WIP {}
	virtual void PostSetup() WIP {}
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void BUpdate(xVec3* pos) WIP { xEntDefaultBoundUpdate(this, pos); }
	virtual void NewTime(xScene*, float32);
	virtual void Move(xScene*, float32, xEntFrame*) WIP {}
	virtual bool32 SysEvent(xBase*, xBase*, uint32, const float32*, xBase*, int32*) WIP { return TRUE; }
	virtual void Render() WIP { xEntRender(this); }
	virtual void Save(xSerial*) const WIP {}
	virtual void Load(xSerial*) WIP {}
	virtual void CollideReview();
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0; }
	virtual uint8 ColPenByFlags() const WIP { return 0; }
	virtual uint8 PhysicsFlags() const WIP { return 0; }

	int32 SelfType() const WIP { return myNPCType; }
	void RestoreColFlags() STUB_VOID;
	bool32 DBG_IsNormLog(en_npcdcat, int32) WIP { return FALSE; }
	void DBG_PStatOn(en_npcperf) WIP {}
	void DBG_PStatCont(en_npcperf) WIP {}
	void DBG_PStatClear() WIP {}
	void DBG_HaltOnMe(uint32, char*) WIP {}
};

void NPC_entwrap_setup(xEnt* ent);
void NPC_entwrap_reset(xEnt* ent);
void NPC_entwrap_update(xEnt* ent, xScene* xscn, float32 dt_caller);
void NPC_entwrap_bupdate(xEnt* ent, xVec3* pos);
void NPC_entwrap_move(xEnt* ent, xScene* xscn, float32 dt, xEntFrame* frm);
bool32 NPC_entwrap_event(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void NPC_entwrap_render(xEnt* ent);