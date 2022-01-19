#pragma once

#include <types.h>

void xParMgrInit();
void xParMgrKillAllParticles();
void xParMgrUpdate(float32 elapsedTime);
void xParMgrRender();