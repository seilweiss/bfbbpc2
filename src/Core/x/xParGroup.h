#pragma once

#include "xPar.h"

struct xParGroup;
struct xParCmdTex;

typedef void(*xParGroupDrawCallback)(void*, xParGroup*);

struct xParGroup
{
	xPar* m_root;
	xPar* m_dead;
	int32 m_num_of_particles;
	uint8 m_alive;
	uint8 m_killWhenDead;
	uint8 m_active;
	uint8 m_visible;
	uint8 m_culled;
	uint8 m_priority;
	uint8 m_flags;
	uint8 m_regidx;
	xParGroup* m_next;
	xParGroup* m_prev;
	xParGroupDrawCallback draw;
	xParCmdTex* m_cmdTex;
};

void xParGroupInit(xParGroup* ps);
void xParGroupSetAging(xParGroup* ps, bool32 age);
void xParGroupSetBack2Life(xParGroup* ps, bool32 b2l);
void xParGroupSetVisibility(xParGroup* ps, bool32 vis);
void xParGroupSetPriority(xParGroup* ps, uint8 val);
void xParGroupRegister(xParGroup* ps);
void xParGroupUnregister(xParGroup* ps);
void xParGroupSetActive(xParGroup* ps, uint32 isActive);
void xParGroupKillAllParticles(xParGroup* ps);
void xParGroupAnimate(xParGroup* ps, float32 dt);
void xParGroupAddParP(xParGroup*, xPar*);
xPar* xParGroupAddPar(xParGroup* ps);
void xParGroupKillPar(xParGroup* ps, xPar* p);
void xParGroupAddParToDeadList(xParGroup*, xPar*);