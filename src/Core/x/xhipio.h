#pragma once

#include "xbinio.h"

enum en_READ_ASYNC_STATUS
{
	HIP_RDSTAT_NONE = -1,
	HIP_RDSTAT_INPROG = 0,
	HIP_RDSTAT_SUCCESS,
	HIP_RDSTAT_FAILED,
	HIP_RDSTAT_NOBYPASS,
	HIP_RDSTAT_NOASYNC
};

struct st_HIPLOADBLOCK
{
	int32 endpos;
	uint32 blk_id;
	int32 blk_remain;
	int32 flags;
};

struct st_HIPLOADDATA
{
	st_FILELOADINFO* fli;
	int32 lockid;
	int32 bypass;
	int32 bypass_recover;
	uint32 base_sector;
	int32 use_async;
	en_READ_ASYNC_STATUS asyn_stat;
	int32 pos;
	int32 top;
	int32 readTop;
	st_HIPLOADBLOCK stk[8];
};

struct st_HIPLOADFUNCS
{
	st_HIPLOADDATA* (*create)(const char* filename, char* dblbuf, int32 bufsize);
	void(*destroy)(st_HIPLOADDATA* lddata);
	uint32(*basesector)(st_HIPLOADDATA* lddata);
	uint32(*enter)(st_HIPLOADDATA* lddata);
	void(*exit)(st_HIPLOADDATA* lddata);
	int32(*readBytes)(st_HIPLOADDATA* lddata, char* data, int32 cnt);
	int32(*readShorts)(st_HIPLOADDATA* lddata, int16* data, int32 cnt);
	int32(*readLongs)(st_HIPLOADDATA* lddata, int32* data, int32 cnt);
	int32(*readFloats)(st_HIPLOADDATA* lddata, float32* data, int32 cnt);
	int32(*readString)(st_HIPLOADDATA* lddata, char* buf);
	bool32(*setBypass)(st_HIPLOADDATA* lddata, bool32 enable, bool32 use_async);
	void(*setSpot)(st_HIPLOADDATA* lddata, int32 spot);
	en_READ_ASYNC_STATUS(*pollRead)(st_HIPLOADDATA* lddata);
};

st_HIPLOADFUNCS* get_HIPLFuncs();