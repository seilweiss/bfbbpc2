#include "xhipio.h"

HIPLOADFUNCS* get_HIPLFuncs() STUB
static HIPLOADDATA* HIPLCreate(const char* filename, char* dblbuf, int32 bufsize) STUB
static void HIPLDestroy(HIPLOADDATA* lddata) STUB_VOID
static uint32 HIPLBaseSector(HIPLOADDATA* lddata) STUB
static bool32 HIPLSetBypass(HIPLOADDATA* lddata, bool32 enable, bool32 use_async) STUB
static void HIPLSetSpot(HIPLOADDATA* lddata, int32 spot) STUB_VOID
static uint32 HIPLBlockEnter(HIPLOADDATA* lddata) STUB
static void HIPLBlockExit(HIPLOADDATA* lddata) STUB_VOID
static int32 HIPLBlockRead(HIPLOADDATA* lddata, void* data, int32 cnt, int32 size) STUB
static int32 HIPLBypassRead(HIPLOADDATA* lddata, void* data, int32 cnt, int32 size) STUB
static int32 HIPLReadAsync(HIPLOADDATA*, int32, char*, int32, int32) STUB
static READ_ASYNC_STATUS HIPLPollRead(HIPLOADDATA* lddata) STUB
static int32 HIPLReadBytes(HIPLOADDATA* lddata, char* data, int32 cnt) STUB
static int32 HIPLReadShorts(HIPLOADDATA* lddata, int16* data, int32 cnt) STUB
static int32 HIPLReadLongs(HIPLOADDATA* lddata, int32* data, int32 cnt) STUB
static int32 HIPLReadFloats(HIPLOADDATA* lddata, float32* data, int32 cnt) STUB
static int32 HIPLReadString(st_HIPLOADDATA* lddata, char* buf) STUB