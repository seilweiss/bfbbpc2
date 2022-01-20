#pragma once

#include "xParCmd.h"

void zParCmdInit();
void zParCmdFindClipVolumes();
void xParCmdKillDistance_Update(xParCmd* c, xParGroup* ps, float32);
void xParCmdClipVolumes_Update(xParCmd*, xParGroup* ps, float32);
void xParCmdPlayerCollision_Update(xParCmd*, xParGroup*, float32);
void xParCmdAnimalMagentism_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdDamagePlayer_Update(xParCmd* c, xParGroup* ps, float32);
void xParCmdJet_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdCustom_Grass_Update(xParCmd*, xParGroup* ps, float32 dt);
void xParCmdApplyCamMat_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdCustom_Update(xParCmd* c, xParGroup* ps, float32 dt);