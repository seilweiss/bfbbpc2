#pragma once

#include "xListItem.h"
#include "xFactory.h"

class xGoal;
struct xPsyche;
struct xBase;

typedef enum en_GOALSTATE
{
	GOAL_STAT_UNKNOWN,
	GOAL_STAT_PROCESS,
	GOAL_STAT_ENTER,
	GOAL_STAT_EXIT,
	GOAL_STAT_SUSPEND,
	GOAL_STAT_RESUME,
	GOAL_STAT_PAUSED,
	GOAL_STAT_DONE,
	GOAL_STAT_NOMORE,
	GOAL_STAT_FORCE = FORCEENUMSIZEINT
} GOALSTATE;

typedef enum en_trantype
{
	GOAL_TRAN_NONE,
	GOAL_TRAN_SET,
	GOAL_TRAN_PUSH,
	GOAL_TRAN_POP,
	GOAL_TRAN_POPTO,
	GOAL_TRAN_POPALL,
	GOAL_TRAN_POPBASE,
	GOAL_TRAN_POPSAFE,
	GOAL_TRAN_SWAP,
	GOAL_TRAN_NOMORE,
	GOAL_TRAN_FORCE = FORCEENUMSIZEINT
} trantype;

typedef bool32(*xGoalProcessCallback)(xGoal*, void*, trantype*, float32, void*);
typedef bool32(*xGoalPrecalcCallback)(xGoal*, void*, float32, void*);
typedef bool32(*xGoalChkRuleCallback)(xGoal*, void*, trantype*, float32, void*);

class xGoal : public xListItem<xGoal>, public xFactoryInst
{
private:
	xPsyche* psyche;
	int32 goalID;
	GOALSTATE stat;
	int32 flg_able;
	xGoalProcessCallback fun_process;
	xGoalPrecalcCallback fun_precalc;
	xGoalChkRuleCallback fun_chkRule;
	void* cbdata;

public:
	xGoal(int32 id) WIP : xListItem(), xFactoryInst(), goalID(id), flg_able(0), stat(GOAL_STAT_UNKNOWN) {}

	virtual void Clear() = 0;
	virtual bool32 Enter(float32 dt, void* updCtxt) WIP { return FALSE; }
	virtual bool32 Exit(float32 dt, void* updCtxt) WIP { return FALSE; }
	virtual bool32 Suspend(float32 dt, void* updCtxt) WIP { return FALSE; }
	virtual bool32 Resume(float32 dt, void* updCtxt) WIP { return FALSE; }
	virtual bool32 PreCalc(float32 dt, void* updCtxt);
	virtual bool32 EvalRules(trantype* trantype, float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* ctxt);
	virtual bool32 SysEvent(xBase*, xBase*, uint32, const float32*, xBase*, int32*) WIP { return TRUE; }

	xBase* GetOwner() const;
	xPsyche* GetPsyche() const WIP { return psyche; }
	void SetPsyche(xPsyche* p) WIP { psyche = p; }
	int32 GetID() const WIP { return goalID; }
	GOALSTATE GetState() const WIP { return stat; }
	void SetState(GOALSTATE s) WIP { stat = s; }
	int32 GetFlags() const WIP { return flg_able; }
	void SetFlags(int32 flags) WIP { flg_able = flags; }
	void AddFlags(int32 flags) WIP { flg_able |= flags; }
	const char* Name() WIP { return NULL; }

	void SetCallbacks(xGoalProcessCallback process, xGoalPrecalcCallback precalc, xGoalChkRuleCallback chkRule, void* data) WIP
	{
		fun_process = process;
		fun_precalc = precalc;
		fun_chkRule = chkRule;
		cbdata = data;
	}
};