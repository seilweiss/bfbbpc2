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

enum en_xpsytime
{
	XPSY_TYMR_CURGOAL,
	XPSY_TYMR_NOMORE
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
	void BrainBegin();
	void BrainExtend();
	void BrainEnd();
	xGoal* AddGoal(int32 gid, void* createData);
	void FreshWipe();
	void SetOwner(xBase*, void*);
	void KillBrain(xFactory*);
	void Lobotomy(xFactory*);
	void Amnesia(bool32);
	int32 IndexInStack(int32 gid) const;
	xGoal* GetCurGoal() const;
	xGoal* GIDInStack(int32 gid) const;
	int32 GIDOfActive() const;
	int32 GIDOfPending() const;
	xGoal* GetPrevRecovery(int32 gid) const;
	bool32 xGoalSet(int32 gid, int32);
	bool32 GoalPush(int32 gid, int32);
	bool32 GoalPopToBase(int32 overpend);
	bool32 GoalPopRecover(int32 overpend);
	bool32 GoalPop(int32 gid_popto, int32);
	bool32 GoalSwap(int32 gid, int32);
	bool32 GoalNone(int32 denyExplicit, int32);
	void SetTopState(en_GOALSTATE);
	xGoal* FindGoal(int32 gid);
	void ForceTran(float32, void*);
	bool32 Timestep(float32 dt, void* updCtxt);
	bool32 ParseTranRequest(en_trantype trantyp, int32 trangid);
	int32 TranGoal(float32 dt, void* updCtxt);
	float32 TimerGet(en_xpsytime tymr);
	void TimerClear();
	void TimerUpdate(float32);
	int32 GIDOfSafety() const WIP { return gid_safegoal; }
	void ImmTranOn() STUB_VOID;
	void ImmTranOff() STUB_VOID;
	bool32 ImmTranIsOn() STUB;
	bool32 HasGoal(int32) STUB;
	void SetSafety(int32) STUB_VOID;
	void SetNotify(xPSYNote*) STUB_VOID;
	void ExpTranOn() STUB_VOID;
	void ExpTranOff() STUB_VOID;
	void ExpTranIsOn() STUB_VOID;
	void DBG_HistAdd(int32) {}
	xBase* GetClient() WIP { return clt_owner; }
};

class xBehaveMgr : public RyzMemData
{
private:
	xFactory* goalFactory;
	xPsyche* psypool;
	st_XORDEREDARRAY psylist;

public:
	xBehaveMgr() {}
	~xBehaveMgr() WIP {}

	void Startup(int32, int32);
	void RegBuiltIn();
	xPsyche* Subscribe(xBase* owner, int32);
	void UnSubscribe(xPsyche* psy);
	void ScenePrepare();
	void SceneFinish();
	void SceneReset();
	xFactory* GetFactory() WIP { return goalFactory; }
};

void xBehaveMgr_Startup();
void xBehaveMgr_Shutdown();
xBehaveMgr* xBehaveMgr_GetSelf();
xFactory* xBehaveMgr_GoalFactory();
void xBehaveMgr_ScenePrepare();
void xBehaveMgr_SceneFinish();
void xBehaveMgr_SceneReset();