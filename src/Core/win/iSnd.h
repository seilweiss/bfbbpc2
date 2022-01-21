#pragma once

#include <types.h>

struct xSndVoiceInfo;

// not in dwarf data
enum isound_effect
{
};

struct iSndVol
{
	int16 volL;
	int16 volR;
};

struct iSndInfo
{
	uint32 flags;
	iSndVol vol;
	uint32 pitch;
	int32 lastStreamBuffer;
};

struct iSndFileInfo
{
	uint32 ID;
	uint32 assetID;
	uint16 sample_rate;
	bool is_streamed;
	union
	{
		struct
		{
			uint32 address;
			uint32 size;
		} nonstream;
		struct
		{
			int32 file_index;
			uint32 lsn;
			uint32 data_size;
			uint16 stream_interleave_size;
			uint16 stream_interleave_count;
		} stream;
	};
};

void iSndInit();
void iSndExit();
void iSndSetEnvironmentalEffect(isound_effect);
void iSndInitSceneLoaded();
bool iSndIsPlaying(uint32 assetID);
bool iSndIsPlaying(uint32 assetID, uint32 parid);
bool iSndIsPlayingByHandle(uint32 id);
iSndFileInfo* iSndLookup(uint32 id);
void iSndPause(uint32 snd, uint32 pause);
void iSndStop(uint32 snd);
void iSndUpdate();
uint32 iSndFindFreeVoice(uint32 priority, uint32 flags, uint32 owner);
uint32 iSndPlay(xSndVoiceInfo* vp);
void iSndSetVol(uint32 snd, float32 vol);
void iSndSetPitch(uint32 snd, float32 pitch);
void iSndStartStereo(uint32 id1, uint32 id2, float32 pitch);
void iSndStereo(uint32 stereo);
void iSndWaitForDeadSounds();
void iSndSuspendCD(uint32);
void iSndSceneExit();
bool32 iSndLoadSounds(void*);
void iSndSuspend();
void iSndResume();
float32 iSndGetVol(uint32 snd);