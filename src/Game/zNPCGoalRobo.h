#pragma once

#include "zNPCGoalStd.h"
#include "zNPCHazard.h"
#include "zNPCMessenger.h"

#include <rwcore.h>

class zMovePoint;

class zNPCGoalNotice : public zNPCGoalPushAnim
{
public:
	zNPCGoalNotice(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalTaunt : public zNPCGoalLoopAnim
{
public:
	zNPCGoalTaunt(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalEvade : public zNPCGoalCommon
{
private:
	int32 flg_evade;

public:
	zNPCGoalEvade(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
};

class zNPCGoalGoHome : public zNPCGoalCommon
{
public:
	zNPCGoalGoHome(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
};

class zNPCGoalAlert : public zNPCGoalCommon
{
private:
	int32 flg_alert;

public:
	zNPCGoalAlert(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
		AddFlags(0x20000);
		flg_npcgauto &= ~0x6;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

enum en_alertfod
{
	FODDER_ALERT_NOTICE,
	FODDER_ALERT_ARENA,
	FODDER_ALERT_BEGIN,
	FODDER_ALERT_CHASE,
	FODDER_ALERT_STABDONE,
	FODDER_ALERT_EVADE,
	FODDER_ALERT_NOMORE,
	FODDER_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertFodder : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	en_alertfod alertfod;
	float32 tmr_alertfod;

public:
	zNPCGoalAlertFodder(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	bool32 CheckSpot(float32);
	void FlankPlayer(float32 dt);
	void GetInArena(float32 dt);
	void MoveEvade(float32 dt);
};

enum en_alertbomb
{
	FODBOMB_ALERT_NOTICE,
	FODBOMB_ALERT_SONAR,
	FODBOMB_ALERT_TERMINAL,
	FODBOMB_ALERT_NOMORE,
	FODBOMB_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertFodBomb : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	en_alertbomb alertbomb;
	float32 tmr_nextping;
	float32 tmr_countdown;

public:
	zNPCGoalAlertFodBomb(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	
	void Detonate();
	void SonarHoming(float32 dt);
};

enum en_alertbzzt
{
	FODBZZT_ALERT_NOTICE,
	FODBZZT_ALERT_ARENA,
	FODBZZT_ALERT_CHASE,
	FODBZZT_ALERT_NOMORE,
	FODBZZT_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertFodBzzt : public zNPCGoalCommon
{
private:
	int32 flg_alert;
	en_alertbzzt alertbzzt;
	float32 tmr_warmup;
	int32 cnt_nextlos;
	float32 len_laser;
	xVec3 pos_laserSource;
	xVec3 pos_laserTarget;
	RwRGBA rgba_deathRay;
	int32 cnt_inContact;

public:
	zNPCGoalAlertFodBzzt(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Suspend(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ToggleOrbit();
	void OrbitPlayer(float32 dt);
	void GetInArena(float32);
	void DeathRayUpdate(float32 dt);
	void DeathRayRender();
};

enum en_alertchomp
{
	CHOMPER_ALERT_NOTICE,
	CHOMPER_ALERT_ARENA,
	CHOMPER_ALERT_CHASE,
	CHOMPER_ALERT_EVADE,
	CHOMPER_ALERT_NOMORE,
	CHOMPER_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertChomper : public zNPCGoalCommon
{
private:
	en_alertchomp alertchomp;
	xVec3 pos_evade;
	float32 tmr_evade;

public:
	zNPCGoalAlertChomper(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void CirclePlayer(float32 dt);
	void GetInArena(float32 dt);
	bool32 CalcEvadePos(xVec3* pos);
	bool32 MoveEvadePos(const xVec3* pos, float32 dt);
	bool32 CheckSpot(float32);
};

enum en_alertham
{
	HAMMER_ALERT_NOTICE,
	HAMMER_ALERT_BEGIN,
	HAMMER_ALERT_CHASE,
	HAMMER_ALERT_WHAM,
	HAMMER_ALERT_EVADE,
	HAMMER_ALERT_NOMORE,
	HAMMER_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertHammer : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	en_alertham alertham;
	float32 tmr_alertham;

public:
	zNPCGoalAlertHammer(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	bool32 PlayerInSpot(float32);
	void MoveChase(float32 dt);
	void MoveEvade(float32 dt);
};

enum en_alerttart
{
	TARTAR_ALERT_NOTICE,
	TARTAR_ALERT_BEGIN,
	TARTAR_ALERT_ARENA,
	TARTAR_ALERT_READY,
	TARTAR_ALERT_NOMORE,
	TARTAR_ALERT_FORCE = FORCEENUMSIZEINT
};

enum en_hoppy
{
	HOPPY_PATTERN_START,
	HOPPY_PATTERN_SHOOT,
	HOPPY_PATTERN_HOPLEFT,
	HOPPY_PATTERN_HOPRIGHT,
	HOPPY_PATTERN_HOPSHOOT,
	HOPPY_PATTERN_NOMORE,
	HOPPY_PATTERN_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertTarTar : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	en_alerttart alerttart;
	en_hoppy hoppy;
	float32 tmr_reload;

public:
	zNPCGoalAlertTarTar(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	int32 HoppyUpdate(trantype* trantype, float32 dt);
	void GetInArena(float32 dt);
};

class zNPCGoalAlertGlove : public zNPCGoalCommon
{
private:
	float32 tmr_attack;
	float32 tmr_minAttack;
	xVec3 pos_began;
	xVec3 pos_end;
	xVec3 dir_axis;
	float32 dst_extend;
	int32 goback;
	int32 cnt_nextemit;

public:
	zNPCGoalAlertGlove(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
		flg_npcgable |= 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Suspend(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void FXTurbulence();
	void FXWhirlwind();
	void CalcAttackVector();
	bool32 CheckHandBones();

	virtual bool32 CollReview(void*);
};

enum en_alertmony
{
	MONSOON_ALERT_NOTICE,
	MONSOON_ALERT_BEGIN,
	MONSOON_ALERT_ARENA,
	MONSOON_ALERT_READY,
	MONSOON_ALERT_SPITCLOUD,
	MONSOON_ALERT_NOMORE,
	MONSOON_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertMonsoon : public zNPCGoalCommon
{
private:
	xVec3 dir_attack;
	int32 flg_attack;
	en_alertmony alertmony;
	float32 tmr_reload;
	xVec3 pos_corner;

public:
	zNPCGoalAlertMonsoon(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void MoveCorner(float32 dt);
};

enum en_slepatak
{
	SLEEP_ATAK_REACT,
	SLEEP_ATAK_ZAP,
	SLEEP_ATAK_LAUGH,
	SLEEP_ATAK_NOMORE,
	SLEEP_ATAK_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertSleepy : public zNPCGoalCommon
{
private:
	xVec3 dir_attack;
	int32 flg_attack;
	en_slepatak sleepattack;
	float32 tmr_minAttack;

public:
	zNPCGoalAlertSleepy(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

enum en_alertarf
{
	ARF_ALERT_REACT,
	ARF_ALERT_READY,
	ARF_ALERT_TELEPORT,
	ARF_ALERT_NOMORE,
	ARF_ALERT_FORCE = FORCEENUMSIZEINT
};

enum en_arfdoes
{
	ARF_DOES_NOT,
	ARF_DOES_LOB,
	ARF_DOES_MELEE,
	ARF_DOES_NOMORE,
	ARF_DOES_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertArf : public zNPCGoalCommon
{
private:
	en_alertarf alertarf;
	float32 tmr_reload;

public:
	zNPCGoalAlertArf(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
		AddFlags(0x8);
		flg_npcgauto &= ~0x6;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	en_arfdoes DecideAttack();
};

enum en_alertpuppy
{
	PUPPY_ALERT_YAPPY,
	PUPPY_ALERT_CHASE,
	PUPPY_ALERT_ATTAAAAACK,
	PUPPY_ALERT_DISAPPEAR,
	PUPPY_ALERT_NOMORE,
	PUPPY_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertPuppy : public zNPCGoalCommon
{
private:
	en_alertpuppy alertpup;

public:
	zNPCGoalAlertPuppy(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

enum en_alertchuk
{
	CHUCK_ALERT_NOTICE,
	CHUCK_ALERT_BEGIN,
	CHUCK_ALERT_ARENA,
	CHUCK_ALERT_READY,
	CHUCK_ALERT_BACKAWAY,
	CHUCK_ALERT_ZOOMPAST,
	CHUCK_ALERT_DIDTHROW,
	CHUCK_ALERT_NOMORE,
	CHUCK_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertChuck : public zNPCGoalCommon
{
private:
	xVec3 dir_attack;
	int32 flg_attack;
	en_alertchuk alertchuk;
	float32 tmr_reload;
	float32 tmr_hover;
	xVec3 dir_zoom;
	float32 dst_zoom;

public:
	zNPCGoalAlertChuck(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	
	void GetInArena(float32 dt);
	bool32 ZoomMove(float32 dt);
};

class zNPCGoalAlertTubelet : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	int32 cnt_nextlos;
	float32 len_laser;
	int32 pete_attack_last;

public:
	zNPCGoalAlertTubelet(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
	bool32 MoveToHome(float32 dt);
	void PeteAttackBegin();
	void PeteAttackParSys(float32, int32);
	void EmitSteam(float32);
};

enum en_alertslik
{
	SLICK_ALERT_NOTICE,
	SLICK_ALERT_BEGIN,
	SLICK_ALERT_ARENA,
	SLICK_ALERT_READY,
	SLICK_ALERT_NOMORE,
	SLICK_ALERT_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalAlertSlick : public zNPCGoalCommon
{
private:
	int32 flg_alert;
	en_alertslik alertslik;
	float32 tmr_reload;
	xVec3 pos_corner;

public:
	zNPCGoalAlertSlick(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void GetInArena(float32 dt);
	void MoveCorner(float32 dt);
};

class zNPCGoalChase : public zNPCGoalCommon
{
private:
	int32 flg_chase;

public:
	zNPCGoalChase(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
};

class zNPCGoalAttackCQC : public zNPCGoalPushAnim
{
private:
	xVec3 dir_attack;
	int32 flg_attack;

public:
	zNPCGoalAttackCQC(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
};

class zNPCGoalAttackFodder : public zNPCGoalPushAnim
{
private:
	class CattleNotify : public HAZNotify
	{
	private:
		zNPCGoalAttackFodder* goal;

	public:
		CattleNotify() WIP : HAZNotify() {}

		virtual bool32 Notify(haznote note, NPCHazard*);
	};

	xVec3 dir_attack;
	int32 flg_attack;
	CattleNotify cbNotify;
	NPCHazard* haz_cattle;

public:
	zNPCGoalAttackFodder(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	bool32 SyncCattleProd();
};

class zNPCGoalAttackChomper : public zNPCGoalPushAnim
{
public:
	zNPCGoalAttackChomper(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void BreathAttack();
};

class zNPCGoalAttackHammer : public zNPCGoalPushAnim
{
private:
	int32 flg_attack;
	xVec3 pos_lastVert;
	xVec3 pos_oldVert;
	uint32 streakID[2];

public:
	zNPCGoalAttackHammer(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
	bool32 PlayerTests(xVec3* pos_vert, float32);
	bool32 ShockwaveTests(xVec3* pos_vert, float32);
	void TellBunnies();
	void ModifyAnimSpeed();
	void FXStreakPrep();
	void FXStreakDone();
	void FXStreakUpdate(xVec3* pos_streak);
};

class zNPCGoalAttackTarTar : public zNPCGoalPushAnim
{
private:
	int32 flg_attack;
	int32 idx_launch;
	xVec3 pos_aimbase;

public:
	zNPCGoalAttackTarTar(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void CacheAimPoint();
	bool32 ShootBlob(float32, int32 zapidx);
};

class zNPCGoalAttackMonsoon : public zNPCGoalPushAnim
{
private:
	int32 idx_launch;

public:
	zNPCGoalAttackMonsoon(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	
	bool32 SpitCloud();
};

class zNPCGoalAttackArfMelee : public zNPCGoalPushAnim
{
private:
	uint32 streakID[4];

public:
	zNPCGoalAttackArfMelee(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void PlayerTests();
	void FXStreakPrep();
	void FXStreakDone();
	void FXStreakUpdate();
};

class zNPCGoalAttackArf : public zNPCGoalPushAnim
{
private:
	int32 flg_attack;

public:
	zNPCGoalAttackArf(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void SetAttackMode(int32, int32);
	void LaunchBone(float32, int32);
	bool32 LaunchDoggie(float32);
};

class zNPCGoalAttackChuck : public zNPCGoalPushAnim
{
private:
	int32 idx_launch;

public:
	zNPCGoalAttackChuck(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void BombzAway(float32);
};

class zNPCGoalAttackSlick : public zNPCGoalLoopAnim
{
private:
	int32 idx_launch;

public:
	zNPCGoalAttackSlick(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x6);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void FireOne(int32);
};

class zNPCGoalDogLaunch : public zNPCGoalCommon
{
private:
	int32 flg_launch;
	xVec3 pos_src;
	xVec3 pos_tgt;
	xParabola parabinfo;
	float32 tmr_remain;

public:
	zNPCGoalDogLaunch(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
		flg_npcgable = 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 CollReview(void*) WIP { return FALSE; }

	void ViciousAttack(xVec3*, xVec3*, zMovePoint*, int32);
	void SilentSwimout(xVec3*, xVec3*, zMovePoint*) STUB_VOID;
	void PreCollide();
	bool32 BallisticUpdate(float32 dt);
	void BubTrailCone(const xVec3* pos, int32 num, const xVec3* pos_rand, const xVec3* vel_rand, const xMat3x3* mat);
	void FurryFlurry();
};

class zNPCGoalDogBark : public zNPCGoalLoopAnim
{
public:
	zNPCGoalDogBark(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDogDash : public zNPCGoalLoopAnim
{
public:
	zNPCGoalDogDash(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void HoundPlayer(float32);
};

class zNPCGoalDogPounce : public zNPCGoalPushAnim
{
public:
	zNPCGoalDogPounce(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void Detonate();
};

class zNPCGoalTeleport : public zNPCGoalCommon
{
private:
	float32 tmr_countdown;

public:
	zNPCGoalTeleport(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalHokeyPokey : public zNPCGoalLoopAnim
{
private:
	int32 flg_hokey;
	float32 ang_spinrate;

public:
	zNPCGoalHokeyPokey(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalEvilPat : public zNPCGoalCommon
{
public:
	zNPCGoalEvilPat(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 NPCMessage(NPCMsg* msg);

	int32 InputStun(NPCStunInfo* info);
	void GlyphStart();
	void GlyphStop();
};

class zNPCGoalStunned : public zNPCGoalCommon
{
public:
	zNPCGoalStunned(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	int32 InputInfo(NPCStunInfo*);
};

class zNPCGoalPatCarry : public zNPCGoalCommon
{
public:
	zNPCGoalPatCarry(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalPatThrow : public zNPCGoalCommon
{
public:
	zNPCGoalPatThrow(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		flg_npcgable = 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 CollReview(void*) WIP { return FALSE; }
};

class zNPCGoalLassoBase : public zNPCGoalCommon
{
public:
	zNPCGoalLassoBase(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalLassoGrab : public zNPCGoalCommon
{
public:
	zNPCGoalLassoGrab(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	
	void DoTurnAway(float32 dt);
};

class zNPCGoalLassoThrow : public zNPCGoalCommon
{
private:
	int32 flg_throw;
	int32 floorBounce;
	float32 tmr_colDelay;

public:
	zNPCGoalLassoThrow(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
		flg_npcgable |= 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 CollReview(void*);

	void ApplyYank(int32 left);
};

class zNPCGoalDamage : public zNPCGoalCommon
{
private:
	int32 flg_howtodie;

public:
	zNPCGoalDamage(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Process(trantype* trantype, float32, void*, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	int32 InputInfo(NPCDamageInfo* info);
};

class zNPCGoalBashed : public zNPCGoalLoopAnim
{
public:
	zNPCGoalBashed(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalWound : public zNPCGoalPushAnim
{
private:
	xVec3 dir_fling;
	int32 flg_knock;

public:
	zNPCGoalWound(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
		flg_npcgable |= 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 CollReview(void*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalKnock : public zNPCGoalCommon
{
private:
	int32 flg_knock;
	xVec3 pos_bumper;
	int32 floorBounce;
	uint32 streakID;

public:
	zNPCGoalKnock(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
		flg_npcgable |= 0x1;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	int32 InputInfo(NPCDamageInfo* info);

	virtual bool32 CollReview(void*);

	void StreakPrep();
	void StreakDone();
	void StreakUpdate();
};

class zNPCGoalAfterlife : public zNPCGoalDead
{
public:
	zNPCGoalAfterlife(int32 myType) WIP : zNPCGoalDead(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void DieTheGoodDeath();
};

class zNPCGoalRespawn : public zNPCGoalCommon
{
private:
	float32 tmr_respawn;
	float32 tmr_robobits;
	int32 cnt_ring;
	xVec3 pos_poofHere;

public:
	zNPCGoalRespawn(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	float32 LaunchRoboBits();
	void DoAppearFX(float32 dt);
	void KickFromTheNest();
	int32 InputInfo(NPCSpawnInfo*);
};

class zNPCGoalTubePal : public zNPCGoalCommon
{
public:
	zNPCGoalTubePal(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
		AddFlags(0x20000);
		flg_npcgauto &= ~0x6;
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 EvalRules(trantype* trantype, float32 dt, void* updCtxt);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
};

class zNPCGoalTubeDuckling : public zNPCGoalCommon
{
private:
	int32 flg_duckling;
	float32 tmr_running;
	float32 tmr_hoverCycle;
	float32 dst_visacard;
	xVec3 dir_visacard;
	float32 tmr_outward;
	float32 dst_preOrbit;

public:
	zNPCGoalTubeDuckling(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x4);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
	void MoveFrolic(float32 dt);
	void DuckStackInterpInit();
	int32 DuckStackInterp(float32 dt);
};

struct NPCBullseye
{
	xVec3 pos;
	float32 spd;
};

enum en_marystat
{
	TUBE_MARY_WAIT,
	TUBE_MARY_ANGRY,
	TUBE_MARY_COOLOFF,
	TUBE_MARY_NOMORE,
	TUBE_MARY_FORCE = FORCEENUMSIZEINT
};

class zNPCGoalTubeAttack : public zNPCGoalCommon
{
private:
	int32 flg_attack;
	union
	{
		struct
		{
			en_marystat marystat;
			float32 ang_spinrate;
		} mary;
		struct
		{
			int32 flg_paul;
			int32 cnt_nextlos;
			float32 len_laser;
			xVec3 pos_laserSource;
			xVec3 pos_laserTarget;
			NPCBullseye bullseye;
		} paul;
	};

public:
	zNPCGoalTubeAttack(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x4);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
	void LaserRender();
	void MaryAttack(float32 dt, xScene*);
	void MarySpinUp();
	void MarySpinDown();
	void MaryzFury();
	void MaryzBlessing();
	void AttackDataReset();
};

class zNPCGoalTubeLasso : public zNPCGoalCommon
{
public:
	zNPCGoalTubeLasso(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x4);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
	void MoveTryToEscape(float32 dt);
};

class zNPCGoalTubeBirth : public zNPCGoalCommon
{
public:
	zNPCGoalTubeBirth(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x4);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
};

class zNPCGoalTubeBonked : public zNPCGoalCommon
{
private:
	float32 tmr_recover;
	float32 ang_spinrate;
	xVec3 vec_offsetPete;

public:
	zNPCGoalTubeBonked(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void CheckForTran(trantype* trantype, int32* nextgoal);
};

class zNPCGoalTubeDead : public zNPCGoalDead
{
public:
	zNPCGoalTubeDead(int32 myType) WIP : zNPCGoalDead(myType) {}

	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void ChkPrelimTran(trantype* trantype, int32* nextgoal);
};

class zNPCGoalTubeDying : public zNPCGoalCommon
{
private:
	int32 flg_tubedying;
	float32 spd_gothatway;
	int32 cnt_loop;
	float32 hyt_was;
	float32 scl_shrink;
	xVec3 pos_lassoDeath;

public:
	zNPCGoalTubeDying(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void DeathByLasso(const xVec3*);
};

class zNPCGoalDeflate : public zNPCGoalCommon
{
private:
	float32 spd_gothatway;
	int32 cnt_loop;
	float32 scl_shrink;

public:
	zNPCGoalDeflate(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xFactoryInst* GOALCreate_Robotic(int32 who, RyzMemGrow* grow, void*);
void ROBO_PrepRoboCop();