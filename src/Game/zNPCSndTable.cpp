#include "zNPCSndTable.h"

void NPCS_Startup() STUB_VOID
void NPCS_Shutdown() {}
void NPCS_SndTimersUpdate(float32 dt) STUB_VOID
void NPCS_SndTimersReset() STUB_VOID
void NPCS_SndTypePlayed(en_NPC_SOUND sndtype, float32 delayNext) STUB_VOID
bool32 NPCS_SndOkToPlay(en_NPC_SOUND sndtype) STUB
void NPCS_SndTablePrepare(NPCSndTrax* trax) STUB_VOID
NPCSndProp* NPCS_SndFindProps(en_NPC_SOUND sndtype) STUB
en_NPC_SOUND NPCS_SndTypeFromHash(uint32 aid_snd, NPCSndTrax* cust, NPCSndTrax* share) STUB
uint32 NPCS_SndPickSimilar(en_NPC_SOUND sndtype, NPCSndTrax* cust, NPCSndTrax* share) STUB