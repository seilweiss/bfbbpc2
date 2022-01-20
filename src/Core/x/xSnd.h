#pragma once

#include "iSnd.h"
#include "xMath3.h"

struct xEnt;

enum sound_category
{
	SND_CAT_INVALID = -1,
	SND_CAT_GAME = 0,
	SND_CAT_DIALOG,
	SND_CAT_MUSIC,
	SND_CAT_CUTSCENE,
	SND_CAT_UI,
	SND_CAT_NUM_CATEGORIES
};

enum sound_effect
{
	SND_EFFECT_NONE,
	SND_EFFECT_CAVE
};

enum sound_listener_type
{
	SND_LISTENER_CAMERA,
	SND_LISTENER_PLAYER,
	SND_MAX_LISTENER_TYPES
};

enum sound_listener_game_mode
{
	SND_LISTENER_MODE_PLAYER,
	SND_LISTENER_MODE_CAMERA
};

template <int32 N> class sound_queue
{
public:
	sound_queue() STUB_VOID;

	void play(uint32, float32, float32, uint32, uint32, uint32, sound_category) STUB_VOID;
	void push(uint32) STUB_VOID;

private:
	uint32 _playing[N + 1];
	int32 head;
	int32 tail;
};

struct xSndVoiceInfo
{
	uint32 assetID;
	uint32 sndID;
	uint32 parentID;
	xVec3* parentPos;
	int32 internalID;
	uint32 flags;
	uint16 pad;
	uint16 priority;
	float32 vol;
	float32 pitch;
	uint32 sample_rate;
	uint32 deadct;
	sound_category category;
	xVec3 actualPos;
	xVec3 playPos;
	float32 innerRadius2;
	float32 outerRadius2;
	uint32 lock_owner;
	iSndInfo ps;
};

typedef void(*xSndExternalCallback)(uint32);

void xSndInit();
void xSndSceneInit();
void xSndSetEnvironmentalEffect(sound_effect effectType);
void xSndSuspend();
void xSndResume();
void xSndPauseAll(uint32 pause_effects, uint32 pause_streams);
void xSndPauseCategory(uint32 mask, uint32 pause);
void xSndSetCategoryVol(sound_category category, float32 vol);
void xSndStopAll(uint32 mask);
void xSndProcessSoundPos(const xVec3* pActual, xVec3* pProcessed);
void xSndInternalUpdateVoicePos(xSndVoiceInfo* pVoice);
void xSndUpdate();
void xSndSetListenerData(sound_listener_type listenerType, const xMat4x3* pMat);
void xSndSelectListenerMode(sound_listener_game_mode listenerMode);
void xSndExit();
uint32 xSndPlay(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, uint32 parentID, sound_category category, float32 delay);
uint32 xSndPlay3D(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, xEnt* parent, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay);
uint32 xSndPlay3D(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay);
uint32 xSndPlayInternal(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, uint32 parentID, xEnt* parentEnt, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay);
void xSndStartStereo(uint32 id1, uint32 id2, float32 pitch);
uint32 xSndIDIsPlaying(uint32 sndID);
void xSndStop(uint32 snd);
void xSndParentDied(uint32 pid);
void xSndStopChildren(uint32 pid);
void xSndSetVol(uint32 snd, float32 vol);
void xSndSetPitch(uint32 snd, float32 pitch);
void xSndSetExternalCallback(xSndExternalCallback callback);
uint32 xSndPlay3DFade(uint32 id, float32 vol, float32 pitch, uint32 priority, uint32 flags, const xVec3* pos, float32 innerRadius, float32 outerRadius, sound_category category, float32 delay, float32 fade_time);
void xSndStopFade(uint32 snd, float32 fade_time);
bool xSndStreamLock(uint32 owner, sound_category kill_cat, bool kill_nonlooping);
bool xSndStreamReady(uint32 owner);
void xSndStreamUnlock(uint32 owner);

inline bool xSndCategoryGetsEffects(sound_category) STUB
inline float32 xSndGetVol(uint32) STUB
inline uint32 xSndPlay3D(uint32, float32, float32, uint32, uint32, xEnt*, float32, sound_category, float32) STUB
inline uint32 xSndPlay3D(uint32, float32, float32, uint32, uint32, const xVec3*, float32, sound_category, float32) STUB
inline uint32 xSndIsPlaying(uint32) STUB
inline bool xSndIsPlayingByHandle(uint32) STUB