#include "iSnd.h"

void iSndInit() STUB_VOID
void iSndExit() STUB_VOID
void iSndSetEnvironmentalEffect(isound_effect) {}
void iSndInitSceneLoaded() {}
bool iSndIsPlaying(uint32 assetID) STUB
bool iSndIsPlaying(uint32 assetID, uint32 parid) STUB
bool iSndIsPlayingByHandle(uint32 id) STUB
iSndFileInfo* iSndLookup(uint32 id) STUB
void iSndPause(uint32 snd, uint32 pause) STUB_VOID
void iSndStop(uint32 snd) STUB_VOID
static int32 iVolFromX(float32) STUB
static iSndVol iSndCalcVol(xSndVoiceInfo* vp) STUB
static iSndVol iSndCalcVol3d(xSndVoiceInfo*) STUB
static iSndVol iSndVolUpdate(xSndVoiceInfo*) STUB
static void iSndUpdateStreams() STUB_VOID
static void iSndUpdateSounds() STUB_VOID
void iSndUpdate() STUB_VOID
uint32 iSndFindFreeVoice(uint32 priority, uint32 flags, uint32 owner) STUB
static uint32 iSndPrepStream(xSndVoiceInfo*) STUB
static uint32 iSndPlayMemStream(xSndVoiceInfo*) STUB
static uint32 iSndPlayStream(xSndVoiceInfo*) STUB
static uint32 iSndPlaySound(xSndVoiceInfo*) STUB
uint32 iSndPlay(xSndVoiceInfo* vp) STUB
void iSndSetVol(uint32 snd, float32 vol) STUB_VOID
void iSndSetPitch(uint32 snd, float32 pitch) STUB_VOID
void iSndStartStereo(uint32 id1, uint32 id2, float32 pitch) {}
void iSndStereo(uint32 stereo) STUB_VOID
void iSndWaitForDeadSounds() STUB_VOID
void iSndSuspendCD(uint32) {}
void iSndSceneExit() STUB_VOID
bool32 iSndLoadSounds(void*) STUB
void iSndSuspend() STUB_VOID
void iSndResume() STUB_VOID
float32 iSndGetVol(uint32 snd) STUB