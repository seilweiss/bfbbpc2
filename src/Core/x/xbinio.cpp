#include "xbinio.h"

#include "xFile.h"

typedef struct st_BINIO_XTRADATA
{
	char* dbl_buf;
	int32 dblbuf_size;
	int32 dbl_beg;
	int32 dbl_end;
	int32 dbl_amt;
	uint32 fpos;
	char* asyn_data;
	int32 asyn_amt;
	int32 asyn_elesize;
	int32 asyn_ismot;
	BIO_ASYNC_ERRCODES asyn_status;
	uint32 pad[3];
	int32 gcaskey;
} BINIO_XTRADATA;

static uint32 g_loadlock = 0xFFFFFF00;
static FILELOADINFO g_loadinst[8] = {};
static xFile g_xfload[8] = {};
static BINIO_XTRADATA g_xtraload[8] = {};
static BINIO_XTRADATA* g_async_context = NULL;

FILELOADINFO* xBinioLoadCreate(const char* filename) STUB
static void LoadDestroy(FILELOADINFO* fli) STUB_VOID
static bool32 SkipBytes(FILELOADINFO* fli, int32 fwd) STUB
static bool32 ReadSeek(FILELOADINFO* fli, int32 pos) STUB
static void SetBuffer(FILELOADINFO* fli, char* dblbuffer, int32 bufsize) STUB_VOID
static void DiscardBuffer(FILELOADINFO* fli) STUB_VOID
static int32 ReadRaw(FILELOADINFO* fli, void* data, int32 size, int32 count) STUB
static int32 ReadBytes(FILELOADINFO* fli, char* data, int32 count) STUB
static int32 ReadMShorts(FILELOADINFO* fli, int16* data, int32 count) STUB
static int32 ReadMLongs(FILELOADINFO* fli, int32* data, int32 count) STUB
static int32 ReadMFloats(FILELOADINFO* fli, float32* data, int32 count) STUB
static int32 ReadMDoubles(FILELOADINFO* fli, float64* data, int32 count) STUB
static int32 ReadIShorts(FILELOADINFO* fli, int16* data, int32 count) STUB
static int32 ReadILongs(FILELOADINFO* fli, int32* data, int32 count) STUB
static int32 ReadIFloats(FILELOADINFO* fli, float32* data, int32 count) STUB
static int32 ReadIDoubles(FILELOADINFO* fli, float64* data, int32 count) STUB
static int32 AsyncMRead(FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n) STUB
static int32 AsyncIRead(FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n) STUB
static BIO_ASYNC_ERRCODES AsyncReadStatus(FILELOADINFO* fli) STUB
static void Swap2(char* d, int32 n) STUB_VOID
static void Swap4(char* d, int32 n) STUB_VOID
static void Swap8(char* d, int32 n) STUB_VOID
static xFile* BFD_open(const char* filename, const char* mode, uint32 lockid, int32, void* xtradata) STUB
static void BFD_close(xFile* bffp, void* xtradata) STUB_VOID
static int32 BFD_read(void* data, int32 elesize, int32 elecnt, xFile* bffp, void* xtradata) STUB
static bool32 BFD_seek(xFile*, int32, int32, void*) STUB
static int32 BFD_getLength(xFile*, void*) STUB
static uint32 BFD_startSector(const char*) STUB

#if defined(PS2)
static void BFD_cb_asyncread(xFile*);
#elif defined(GAMECUBE)
static void BFD_cb_GCP2_readasync(xFile*);
#elif defined(WIN32)
static void BFD_cb_asyncread(xFile*);
#endif

static bool32 BFD_AsyncRead(FILELOADINFO* fli, int32 pos, void* data, int32 size, int32 n, int32) STUB
static BIO_ASYNC_ERRCODES BFD_AsyncReadStatus(FILELOADINFO* fli) STUB