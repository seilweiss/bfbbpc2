#pragma once

#include <types.h>

enum en_NPC_SOUND
{
	NPC_STYP_BOGUS = -2,
	NPC_STYP_LISTEND = 0,
	NPC_STYP_ENCOUNTER,
	NPC_STYP_CLANKING,
	NPC_STYP_EXCLAIM,
	NPC_STYP_OUCH,
	NPC_STYP_CHEERING,
	NPC_STYP_RESPAWN,
	NPC_STYP_ALERT,
	NPC_STYP_DIZZY,
	NPC_STYP_DANCE,
	NPC_STYP_LAUGH,
	NPC_STYP_ATTACK,
	NPC_STYP_PUNCH,
	NPC_STYP_WEPLAUNCH,
	NPC_STYP_LIGHTNING,
	NPC_STYP_WARNBANG,
	NPC_STYP_DEATH,
	NPC_STYP_DEATHJELLY,
	NPC_STYP_BONKED,
	NPC_STYP_UNBONKED,
	NPC_STYP_TIKISTACK,
	NPC_STYP_TIKIEXPLODE,
	NPC_STYP_TIKITHUNDER,
	NPC_STYP_XSFXTALK,
	NPC_STYP_ONELINER,
	NPC_STYP_ONELINERTOO,
	NPC_STYP_NOMORE,
	NPC_STYP_FORCE = FORCEENUMSIZEINT
};

struct NPCSndTrax
{
	en_NPC_SOUND typ_sound;
	const char* nam_sound;
	uint32 aid_sound;
};

struct NPCSndProp
{
	en_NPC_SOUND sndtype;
	int32 flg_snd;
	float32 tym_delayNext;
};

void NPCS_Startup();
void NPCS_Shutdown();
void NPCS_SndTimersUpdate(float32 dt);
void NPCS_SndTimersReset();
void NPCS_SndTypePlayed(en_NPC_SOUND sndtype, float32 delayNext);
bool32 NPCS_SndOkToPlay(en_NPC_SOUND sndtype);
void NPCS_SndTablePrepare(NPCSndTrax* trax);
NPCSndProp* NPCS_SndFindProps(en_NPC_SOUND sndtype);
en_NPC_SOUND NPCS_SndTypeFromHash(uint32 aid_snd, NPCSndTrax* cust, NPCSndTrax* share);
uint32 NPCS_SndPickSimilar(en_NPC_SOUND sndtype, NPCSndTrax* cust, NPCSndTrax* share);