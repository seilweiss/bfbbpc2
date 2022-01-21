#pragma once

#include "xEnt.h"

struct zScene;

void zThrown_Setup(zScene* sc);
void zThrown_Reset();
void zThrown_LaunchVel(xEnt* ent, xVec3* vel);
void zThrown_LaunchDir(xEnt* ent, xVec3* dir);
bool32 zThrown_LaunchPos(xEnt* ent, xVec3* pos, xVec3* dir);
void zThrown_LaunchStack(xEnt* ent, xEnt* stackTgt);
void zThrown_PatrickLauncher(xEnt* ent, xEnt* launcher);
void zThrown_AddFruit(xEnt* ent);
void zThrown_Remove(xEnt* ent);
bool32 zThrown_KillFruit(xEnt* ent);
bool32 zThrown_IsFruit(xEnt* ent, float32* stackHeight);
bool32 zThrown_IsStacked(xEnt* ent);