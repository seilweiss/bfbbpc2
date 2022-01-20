#include "zGameState.h"

int32 zGameStateGet() STUB
int32 zGameModeGet() STUB
GameOstrich zGameGetOstrich() STUB
void zGameSetOstrich(GameOstrich o) STUB_VOID
bool32 zGameStateFindEvent(uint32*, int32, int32, int32, int32*, int32*) STUB
void zGameStateSwitchEvent(int32 event) STUB_VOID
void zGameStateSwitch(int32 theNewState) STUB_VOID
void zGameModeSwitch(eGameMode modeNew) STUB_VOID