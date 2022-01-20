#pragma once

#include "zEnt.h"
#include "xEntMotion.h"

typedef struct _zPendulum : zEnt
{
	xEntMotion motion;
	float32 lt;
	float32 q1t;
	float32 q3t;
} zPendulum;

void zPendulum_Init(void* pend, void* asset);
void zPendulum_Init(zPendulum* pend, xEntAsset* asset);
void zPendulum_Save(zPendulum* pend, xSerial* s);
void zPendulum_Load(zPendulum* pend, xSerial* s);
void zPendulum_Setup(zPendulum* pend, xScene*);
void zPendulum_Reset(zPendulum* pend, xScene* sc);
void zPendulum_Update(zPendulum* pend, xScene* sc, float32 dt);
void zPendulum_Move(zPendulum* pend, xScene* s, float32 dt, xEntFrame* frame);
bool32 zPendulumEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);