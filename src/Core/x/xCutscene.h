#pragma once

#include "xFile.h"
#include "xBase.h"

#include <rwcore.h>
#include <rpworld.h>

struct xCamera;
struct xEnt;

class XCSNNosey
{
public:
	XCSNNosey() WIP {}

	virtual void CanRenderNow() {}
	virtual void UpdatedAnimated(RpAtomic* model, RwMatrix* animMat, uint32 animIndex, uint32 dataIndex) {}

private:
	void* userdata;
	int32 flg_nosey;
};

struct xCutsceneInfo
{
	uint32 Magic;
	uint32 AssetID;
	uint32 NumData;
	uint32 NumTime;
	uint32 MaxModel;
	uint32 MaxBufEven;
	uint32 MaxBufOdd;
	uint32 HeaderSize;
	uint32 VisCount;
	uint32 VisSize;
	uint32 BreakCount;
	uint32 pad;
	char SoundLeft[16];
	char SoundRight[16];
};

struct xCutsceneData
{
	uint32 DataType;
	uint32 AssetID;
	uint32 ChunkSize;
	union
	{
		uint32 FileOffset;
		void* DataPtr;
	};
};

struct xCutsceneBreak
{
	float32 Time;
	int32 Index;
};

struct xCutsceneTime
{
	float32 StartTime;
	float32 EndTime;
	uint32 NumData;
	uint32 ChunkIndex;
};

struct xCutscene
{
	xCutsceneInfo* Info;
	xCutsceneData* Data;
	uint32* TimeChunkOffs;
	uint32* Visibility;
	xCutsceneBreak* BreakList;
	xCutsceneTime* Play;
	xCutsceneTime* Stream;
	uint32 Waiting;
	uint32 BadReadPause;
	float32 BadReadSpeed;
	void* RawBuf;
	void* AlignBuf;
	float32 Time;
	float32 CamTime;
	uint32 PlayIndex;
	uint32 Ready;
	int32 DataLoading;
	uint32 GotData;
	uint32 ShutDownWait;
	float32 PlaybackSpeed;
	uint32 Opened;
	xFile File;
	int32 AsyncID;
	void* MemBuf;
	void* MemCurr;
	uint32 SndStarted;
	uint32 SndNumChannel;
	uint32 SndChannelReq[2];
	uint32 SndAssetID[2];
	uint32 SndHandle[2];
	XCSNNosey* cb_nosey;

	void NoseySet(XCSNNosey*) STUB_VOID;
	void NoseyClear() STUB_VOID;
};

struct xCutsceneZbuffer
{
	float32 start;
	float32 end;
	float32 nearPlane;
	float32 farPlane;
};

struct xCutsceneZbufferHack
{
	const char* name;
	xCutsceneZbuffer times[4];
};

struct xCutsceneMgrAsset : xBaseAsset
{
	uint32 cutsceneAssetID;
	uint32 flags;
	float32 interpSpeed;
	float32 startTime[15];
	float32 endTime[15];
	uint32 emitID[15];
};

struct xCutsceneMgr : xBase
{
	xCutsceneMgrAsset* tasset;
	xCutscene* csn;
	uint32 stop;
	xCutsceneZbufferHack* zhack;
	float32 oldfov;
};

void xCutscene_Init(void* toc);
xCutscene* xCutscene_Create(uint32 id);
bool32 xCutscene_Destroy(xCutscene* csn);
bool32 xCutscene_LoadStart(xCutscene* csn);
bool32 xCutscene_Update(xCutscene* csn, float32 dt);
void xCutscene_SetSpeed(xCutscene* csn, float32 speed);
void xCutscene_SetCamera(xCutscene* csn, xCamera* cam);
void xCutscene_Render(xCutscene* csn, xEnt**, int32*, float32*);
