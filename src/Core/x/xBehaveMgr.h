#pragma once

#include "xBehaviour.h"
#include "xBase.h"

enum en_psynote
{
	PSY_NOTE_HASRESUMED,
	PSY_NOTE_HASENTERED,
	PSY_NOTE_ANIMCHANGED,
	PSY_NOTE_NOMORE,
	PSY_NOTE_FORCE = FORCEENUMSIZEINT
};

enum PSY_BRAIN_STATUS
{
	PSY_STAT_BLANK,
	PSY_STAT_GROW,
	PSY_STAT_EXTEND,
	PSY_STAT_THINK,
	PSY_STAT_NOMORE,
	PSY_STAT_FORCE = FORCEENUMSIZEINT
};

enum en_pendtype
{
	PEND_TRAN_NONE,
	PEND_TRAN_SET,
	PEND_TRAN_PUSH,
	PEND_TRAN_POP,
	PEND_TRAN_POPTO,
	PEND_TRAN_POPALL,
	PEND_TRAN_SWAP,
	PEND_TRAN_INPROG,
	PEND_TRAN_NOMORE
};

class xPSYNote
{
public:
	xPSYNote() WIP {}

	void Notice(en_psynote, xGoal*, void*) WIP {}
};

class xPsyche : public RyzMemData
{
private:
	xBase* clt_owner;
	xPSYNote* cb_notice;
	int32 flg_psyche;
	xGoal* goallist;
	xGoal* goalstak[5];
	float32 tmr_stack[1][5];
	int32 staktop;
	xGoal* pendgoal;
	en_pendtype pendtype;
	int32 gid_safegoal;
	void(*fun_remap)(int32*, en_trantype*);
	void* userContext;
	int32 cnt_transLastTimestep;
	PSY_BRAIN_STATUS psystat;
	xBase fakebase;

public:
	int32 GIDOfSafety() const WIP { return gid_safegoal; }
	void ImmTranOn() STUB_VOID;
	void ImmTranOff() STUB_VOID;
	bool32 ImmTranIsOn() STUB;
	bool32 HasGoal(int32) STUB;
	void SetSafety(int32) STUB_VOID;
	void SetNotify(xPSYNote*) STUB_VOID;
};

class xBehaveMgr : public RyzMemData
{
private:
	xFactory* goalFactory;
	xPsyche* psypool;
	st_XORDEREDARRAY psylist;

public:
	xFactory* GetFactory() WIP { return goalFactory; }
};