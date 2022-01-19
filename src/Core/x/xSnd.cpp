#include "xSnd.h"

void xSndInit() STUB_VOID
void xSndSceneInit() STUB_VOID
void xSndSetEnvironmentalEffect(sound_effect effectType) STUB_VOID
void xSndSuspend() STUB_VOID
void xSndResume() STUB_VOID
void xSndPauseAll(uint32 pause_effects, uint32 pause_streams) STUB_VOID
void xSndPauseCategory(uint32 mask, uint32 pause) STUB_VOID
void xSndSetCategoryVol(sound_category category, float32 vol) STUB_VOID
void xSndStopAll(uint32 mask) STUB_VOID
static void xSndDelayedInit() STUB_VOID
static void xSndDelayedUpdate() STUB_VOID
static void xSndAddDelayed(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, uint32 parentID, xEnt* parentEnt, xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay) STUB_VOID
static void xSndCalculateListenerPosition() STUB_VOID
void xSndProcessSoundPos(const xVec3* pActual, xVec3* pProcessed) STUB_VOID
void xSndInternalUpdateVoicePos(xSndVoiceInfo* pVoice) STUB_VOID
void xSndUpdate() STUB_VOID
void xSndSetListenerData(sound_listener_type listenerType, const xMat4x3* pMat) STUB_VOID
void xSndSelectListenerMode(sound_listener_game_mode listenerMode) STUB_VOID
void xSndExit() STUB_VOID
uint32 xSndPlay(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, uint32 parentID, sound_category category, float32 delay) STUB
uint32 xSndPlay3D(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, xEnt* parent, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay) STUB
uint32 xSndPlay3D(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay) STUB
uint32 xSndPlayInternal(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, uint32 parentID, xEnt* parentEnt, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay) STUB
void xSndStartStereo(uint32 id1, uint32 id2, float32 pitch) STUB_VOID
uint32 xSndIDIsPlaying(uint32 sndID) STUB
void xSndStop(uint32 snd) STUB_VOID
void xSndParentDied(uint32 pid) STUB_VOID
void xSndStopChildren(uint32 pid) STUB_VOID
void xSndSetVol(uint32 snd, float32 vol) STUB_VOID
void xSndSetPitch(uint32 snd, float32 pitch) STUB_VOID
void xSndSetExternalCallback(xSndExternalCallback callback) STUB_VOID

namespace {

	struct fade_data
	{
		bool in;
		uint32 handle;
		float32 start_delay;
		float32 time;
		float32 end_time;
		float32 volume;
	};

}

static void reset_faders() STUB_VOID
static void update_faders(float32 dt) STUB_VOID
uint32 xSndPlay3DFade(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay, float32 fade_time) STUB
void xSndStopFade(uint32 snd, float32 fade_time) STUB_VOID
bool xSndStreamLock(uint32 owner, sound_category kill_cat, bool kill_nonlooping) STUB
bool xSndStreamReady(uint32 owner) STUB
void xSndStreamUnlock(uint32 owner) STUB_VOID