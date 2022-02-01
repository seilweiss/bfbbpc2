#include "xbinio.h"

#include "xFile.h"

#include <string.h>

#define BFD_SEEK_SET 0
#define BFD_SEEK_CUR 1
#define BFD_SEEK_END 2

struct st_BINIO_XTRADATA
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
	en_BIO_ASYNC_ERRCODES asyn_status;
	uint32 pad[3];
	int32 gcaskey;
};

static uint32 g_loadlock = 0xFFFFFF00;
static st_FILELOADINFO g_loadinst[8] = {};
static xFile g_xfload[8] = {};
static st_BINIO_XTRADATA g_xtraload[8] = {};
static st_BINIO_XTRADATA* g_async_context = NULL;

static void LoadDestroy(st_FILELOADINFO* fli);
static bool32 SkipBytes(st_FILELOADINFO* fli, int32 fwd);
static bool32 ReadSeek(st_FILELOADINFO* fli, int32 pos);
static void SetBuffer(st_FILELOADINFO* fli, char* dblbuffer, int32 bufsize);
static void DiscardBuffer(st_FILELOADINFO* fli);
static int32 ReadRaw(st_FILELOADINFO* fli, void* data, int32 size, int32 count);
static int32 ReadBytes(st_FILELOADINFO* fli, char* data, int32 count);
static int32 ReadMShorts(st_FILELOADINFO* fli, int16* data, int32 count);
static int32 ReadMLongs(st_FILELOADINFO* fli, int32* data, int32 count);
static int32 ReadMFloats(st_FILELOADINFO* fli, float32* data, int32 count);
static int32 ReadMDoubles(st_FILELOADINFO* fli, float64* data, int32 count);
static int32 ReadIShorts(st_FILELOADINFO* fli, int16* data, int32 count);
static int32 ReadILongs(st_FILELOADINFO* fli, int32* data, int32 count);
static int32 ReadIFloats(st_FILELOADINFO* fli, float32* data, int32 count);
static int32 ReadIDoubles(st_FILELOADINFO* fli, float64* data, int32 count);
static int32 AsyncMRead(st_FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n);
static int32 AsyncIRead(st_FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n);
static en_BIO_ASYNC_ERRCODES AsyncReadStatus(st_FILELOADINFO* fli);
static void Swap2(char* d, int32 n);
static void Swap4(char* d, int32 n);
static void Swap8(char* d, int32 n);
static xFile* BFD_open(const char* filename, const char* mode, uint32 lockid, int32, void* xtradata);
static void BFD_close(xFile* bffp, void* xtradata);
static int32 BFD_read(void* data, int32 elesize, int32 elecnt, xFile* bffp, void* xtradata);
static bool32 BFD_seek(xFile*, int32, int32, void*);
static int32 BFD_getLength(xFile*, void*);
static uint32 BFD_startSector(const char*);
static bool32 BFD_AsyncRead(st_FILELOADINFO* fli, int32 pos, void* data, int32 size, int32 n, bool32);
static en_BIO_ASYNC_ERRCODES BFD_AsyncReadStatus(st_FILELOADINFO* fli);

st_FILELOADINFO* xBinioLoadCreate(const char* filename)
{
    st_FILELOADINFO* fli = NULL;
    xFile* tmp_fp;
    int32 i;
    int32 uselock = -1;

    for (i = 0; i < 8; i++)
    {
        if (!(g_loadlock & (1 << i)))
        {
            g_loadlock |= 1 << i;

            uselock = i;
            fli = &g_loadinst[i];

            break;
        }
    }

    if (fli)
    {
        memset(fli, 0, sizeof(st_FILELOADINFO));

        fli->lockid = (uselock < 0) ? 0 : uselock;
        fli->xtradata = &g_xtraload[uselock];
        fli->destroy = LoadDestroy;
        fli->readBytes = ReadBytes;
        fli->readMShorts = ReadMShorts;
        fli->readMLongs = ReadMLongs;
        fli->readMFloats = ReadMFloats;
        fli->readMDoubles = ReadMDoubles;
        fli->readIShorts = ReadIShorts;
        fli->readILongs = ReadILongs;
        fli->readIFloats = ReadIFloats;
        fli->readIDoubles = ReadIDoubles;
        fli->asyncIRead = AsyncIRead;
        fli->asyncMRead = AsyncMRead;
        fli->asyncReadStatus = AsyncReadStatus;
        fli->skipBytes = SkipBytes;
        fli->seekSpot = ReadSeek;
        fli->setDoubleBuf = SetBuffer;
        fli->discardDblBuf = DiscardBuffer;
        fli->error = FIOERR_NONE;
        fli->remain = 0;
        fli->basesector = 0;
        fli->filesize = 0;
        fli->position = 0;
        fli->basesector = 0;

        tmp_fp = BFD_open(filename, "rb", uselock, 0, fli->xtradata);

        if (tmp_fp)
        {
            fli->basesector = BFD_startSector(filename);
            fli->privdata = tmp_fp;
            fli->filesize = BFD_getLength(tmp_fp, fli->xtradata);
            fli->remain = fli->filesize;
        }
        else
        {
            LoadDestroy(fli);
            fli = NULL;
        }
    }

    return fli;
}

static void LoadDestroy(st_FILELOADINFO* fli)
{
    xFile* fp = (xFile*)fli->privdata;
    uint32 lockid;

    if (fp)
    {
        BFD_close(fp, fli->xtradata);
    }

    lockid = fli->lockid;

    memset(fli, 0, sizeof(st_FILELOADINFO));

    g_loadlock &= ~(1 << lockid);
}

static bool32 SkipBytes(st_FILELOADINFO* fli, int32 fwd)
{
    xFile* file = (xFile*)fli->privdata;

    if (fli->error != FIOERR_NONE)
    {
        return FALSE;
    }

    if (fwd == 0)
    {
        return TRUE;
    }

    if (fwd < 0)
    {
        fwd = 0;
    }

    if (BFD_seek(file, fli->position + fwd, BFD_SEEK_SET, fli->xtradata) != OK)
    {
        fli->error = FIOERR_SEEKFAIL;
    }
    else
    {
        fli->remain -= fwd;
        fli->position += fwd;
    }

    if (fli->error != FIOERR_NONE)
    {
        return FALSE;
    }

    return TRUE;
}

static bool32 ReadSeek(st_FILELOADINFO* fli, int32 pos)
{
    xFile* file = (xFile*)fli->privdata;

    if (fli->error != FIOERR_NONE)
    {
        return FALSE;
    }

    pos = (pos < fli->filesize) ? pos : fli->filesize;

    if (BFD_seek(file, pos, BFD_SEEK_SET, fli->xtradata) != OK)
    {
        fli->error = FIOERR_SEEKFAIL;
    }
    else
    {
        fli->position = pos;
        fli->remain = fli->filesize - pos;
    }

    if (fli->error != FIOERR_NONE)
    {
        return FALSE;
    }

    return TRUE;
}

static void SetBuffer(st_FILELOADINFO* fli, char* dblbuffer, int32 bufsize)
{
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)fli->xtradata;

    if (xtra)
    {
        xtra->dbl_buf = dblbuffer;
        xtra->dblbuf_size = bufsize;
        xtra->dbl_beg = 0;
        xtra->dbl_end = 0;
        xtra->dbl_amt = 0;
    }
}

static void DiscardBuffer(st_FILELOADINFO* fli)
{
    SetBuffer(fli, NULL, 0);
}

static int32 ReadRaw(st_FILELOADINFO* fli, void* data, int32 size, int32 count)
{
    xFile* file = (xFile*)fli->privdata;
    int32 amt;
    int32 n;

    if (fli->error != FIOERR_NONE)
    {
        return 0;
    }

    amt = (size * count > fli->remain) ? fli->remain / size : count;

    if (amt != 0)
    {
        n = BFD_read(data, size, amt, file, fli->xtradata);

        if (n != amt)
        {
            fli->error = FIOERR_READFAIL;
        }

        fli->remain -= size * amt;
        fli->position += size * amt;
    }

    return amt;
}

static int32 ReadBytes(st_FILELOADINFO* fli, char* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(char), count);

    return act;
}

static int32 ReadMShorts(st_FILELOADINFO* fli, int16* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(int16), count);

#ifdef LITTLE_ENDIAN
    Swap2((char*)data, act);
#endif

    return act;
}

static int32 ReadMLongs(st_FILELOADINFO* fli, int32* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(int32), count);

#ifdef LITTLE_ENDIAN
    Swap4((char*)data, act);
#endif

    return act;
}

static int32 ReadMFloats(st_FILELOADINFO* fli, float32* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(float32), count);

#ifdef LITTLE_ENDIAN
    Swap4((char*)data, act);
#endif

    return act;
}

static int32 ReadMDoubles(st_FILELOADINFO* fli, float64* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(float64), count);

#ifdef LITTLE_ENDIAN
    Swap8((char*)data, act);
#endif

    return act;
}

static int32 ReadIShorts(st_FILELOADINFO* fli, int16* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(int16), count);

#ifdef BIG_ENDIAN
    Swap2((char*)data, act);
#endif

    return act;
}

static int32 ReadILongs(st_FILELOADINFO* fli, int32* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(int32), count);

#ifdef BIG_ENDIAN
    Swap4((char*)data, act);
#endif

    return act;
}

static int32 ReadIFloats(st_FILELOADINFO* fli, float32* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(float32), count);

#ifdef BIG_ENDIAN
    Swap4((char*)data, act);
#endif

    return act;
}

static int32 ReadIDoubles(st_FILELOADINFO* fli, float64* data, int32 count)
{
    int32 act = ReadRaw(fli, data, sizeof(float64), count);

#ifdef BIG_ENDIAN
    Swap8((char*)data, act);
#endif

    return act;
}

static int32 AsyncMRead(st_FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n)
{
    return BFD_AsyncRead(fli, offset, data, size, n, TRUE);
}

static int32 AsyncIRead(st_FILELOADINFO* fli, int32 offset, char* data, int32 size, int32 n)
{
    return BFD_AsyncRead(fli, offset, data, size, n, FALSE);
}

static en_BIO_ASYNC_ERRCODES AsyncReadStatus(st_FILELOADINFO* fli)
{
    return BFD_AsyncReadStatus(fli);
}

static void Swap2(char* d, int32 n)
{
    char t;

    while (n--)
    {
        t = d[0];
        d[0] = d[1];
        d[1] = t;

        d += 2;
    }
}

static void Swap4(char* d, int32 n)
{
    char t;

    while (n--)
    {
        t = d[0];
        d[0] = d[3];
        d[3] = t;

        t = d[1];
        d[1] = d[2];
        d[2] = t;

        d += 4;
    }
}

static void Swap8(char* d, int32 n)
{
    char t;

    while (n--)
    {
        t = d[0];
        d[0] = d[7];
        d[7] = t;

        t = d[1];
        d[1] = d[6];
        d[6] = t;

        t = d[2];
        d[2] = d[5];
        d[5] = t;

        t = d[3];
        d[3] = d[4];
        d[4] = t;

        d += 8;
    }
}

static xFile* BFD_open(const char* filename, const char* mode, uint32 lockid, int32, void* xtradata)
{
    xFile* bffp;
    uint32 orc;
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)xtradata;
    int32 xfflg = IFILE_OPEN_READ;

    if (strcmp(mode, "rb") == 0)
    {
        bffp = &g_xfload[lockid];
        xfflg = IFILE_OPEN_READ;
    }
    else if (strcmp(mode, "wb") == 0)
    {
        bffp = NULL;
        xfflg = IFILE_OPEN_WRITE;
    }
    else
    {
        bffp = NULL;
    }

    if (bffp)
    {
        strncpy(bffp->relname, filename, sizeof(bffp->relname) - 1);
        bffp->relname[sizeof(bffp->relname) - 1] = '\0';

        orc = iFileOpen(filename, xfflg, bffp);

        if (orc != OK)
        {
            bffp = NULL;
        }
        else
        {
            xtra->fpos = 0;
            xtra->dbl_buf = NULL;
            xtra->dblbuf_size = 0;
            xtra->dbl_beg = 0;
            xtra->dbl_end = 0;
            xtra->dbl_amt = 0;
        }
    }

    return bffp;
}

static void BFD_close(xFile* bffp, void* xtradata)
{
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)xtradata;

    iFileClose(bffp);

    xtra->fpos = 0;
    xtra->dbl_buf = NULL;
    xtra->dblbuf_size = 0;
    xtra->dbl_beg = 0;
    xtra->dbl_end = 0;
    xtra->dbl_amt = 0;
}

static int32 BFD_read(void* data, int32 elesize, int32 elecnt, xFile* bffp, void* xtradata)
{
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)xtradata;
    char* dest = (char*)data;
    bool32 readbeg = FALSE;
    int32 refill;
    int32 remain;
    int32 actual = 0;
    uint32 holdpos;
    uint32 safety = 0;
    uint32 numBytes = elesize * elecnt;

    if (numBytes == 0)
    {
        return 0;
    }

    if (!xtra->dbl_buf || xtra->dblbuf_size < 1 || (int32)numBytes > xtra->dblbuf_size)
    {
        iFileSeek(bffp, xtra->fpos, IFILE_SEEK_SET);

        actual = iFileRead(bffp, dest, numBytes);

        xtra->fpos += actual;
    }
    else
    {
        remain = numBytes;

        do
        {
            if (xtra->fpos < (uint32)xtra->dbl_beg)
            {
                readbeg = TRUE;

                xtra->dbl_beg = xtra->fpos - (xtra->fpos % xtra->dblbuf_size);
                xtra->dbl_end = xtra->dbl_beg + xtra->dblbuf_size;
                xtra->dbl_amt = 0;
            }
            else if (xtra->fpos >= (uint32)xtra->dbl_end)
            {
                readbeg = TRUE;

                xtra->dbl_beg = xtra->fpos - (xtra->fpos % xtra->dblbuf_size);
                xtra->dbl_end = xtra->dbl_beg + xtra->dblbuf_size;
                xtra->dbl_amt = 0;
            }

            if (readbeg)
            {
                holdpos = xtra->fpos;

                iFileSeek(bffp, xtra->dbl_beg, IFILE_SEEK_SET);

                xtra->fpos = holdpos;
                xtra->dbl_amt = iFileRead(bffp, xtra->dbl_buf, xtra->dblbuf_size);
            }

            if (xtra->dbl_amt > (int32)(xtra->fpos - xtra->dbl_beg))
            {
                refill = xtra->dbl_amt - (int32)(xtra->fpos - xtra->dbl_beg);

                if (remain < refill)
                {
                    refill = remain;
                }

                memcpy(dest + actual, xtra->dbl_buf + (xtra->fpos - xtra->dbl_beg), refill);

                actual += refill;
                remain -= refill;

                xtra->fpos += refill;
            }
        } while (actual != numBytes && xtra->dbl_amt >= 1 && safety++ <= 60000);
    }

    return actual / elesize;
}

static bool32 BFD_seek(xFile* bffp, int32 offset, int32 whence, void* xtradata)
{
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)xtradata;
    int32 pos = iFileSeek(bffp, offset, whence);

    xtra->fpos = offset;

    if (pos == -1)
    {
        return FAILED;
    }

    return OK;
}

static int32 BFD_getLength(xFile* bffp, void*)
{
    return iFileGetSize(bffp);
}

static uint32 BFD_startSector(const char* filename)
{
    tag_xFile file = {};
    uint32 addr = 0;
    uint32 length = 0;

    if (!iFileFind(filename, &file))
    {
        iFileGetInfo(&file, &addr, &length);
    }

    iFileClose(&file);

    return addr;
}

#if defined(PS2)
static void BFD_cb_asyncread(xFile*) STUB_VOID
#elif defined(GAMECUBE)
static void BFD_cb_GCP2_readasync(xFile*) STUB_VOID
#elif defined(WIN32)
static void BFD_cb_asyncread(xFile*) {}
#endif

static bool32 BFD_AsyncRead(st_FILELOADINFO* fli, int32 pos, void* data, int32 size, int32 n, bool32)
{
    xFile* file = (xFile*)fli->privdata;
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)fli->xtradata;
    int32 result;
    int32 rc;

    if (fli->error != FIOERR_NONE)
    {
        return FALSE;
    }

    if (g_async_context)
    {
        return FALSE;
    }

    g_async_context = xtra;

    xtra->asyn_status = BINIO_ASYNC_INPROG;
    xtra->asyn_data = (char*)data;
    xtra->asyn_elesize = size;
    xtra->asyn_amt = n;
    xtra->asyn_ismot = TRUE;

    iFileSeek(file, pos, IFILE_SEEK_SET);
    xFileSetUserData(file, fli);

    rc = iFileReadAsync(file, data, size * n, BFD_cb_asyncread, 0);

    if (rc < 0)
    {
        result = FALSE;
    }
    else
    {
        xtra->gcaskey = rc;
        result = TRUE;
    }

    if (!result)
    {
        g_async_context = NULL;
        xtra->asyn_status = BINIO_ASYNC_NOOP;
    }

    return TRUE;
}

static en_BIO_ASYNC_ERRCODES BFD_AsyncReadStatus(st_FILELOADINFO* fli)
{
    en_BIO_ASYNC_ERRCODES status;
    st_BINIO_XTRADATA* xtra = (st_BINIO_XTRADATA*)fli->xtradata;
    XFILE_READSECTOR_STATUS xrdstat;
    int32 amtsofar;

    if (!g_async_context)
    {
        return BINIO_ASYNC_NOOP;
    }

    if (xtra != g_async_context)
    {
        return BINIO_ASYNC_INPROG;
    }

    if (xtra->asyn_status == BINIO_ASYNC_INPROG)
    {
        amtsofar = 0;
        xrdstat = xFileReadAsyncStatus(xtra->gcaskey, &amtsofar);

        switch (xrdstat)
        {
        case XFILE_RDSTAT_INPROG:
        case XFILE_RDSTAT_QUEUED:
            xtra->asyn_status = BINIO_ASYNC_INPROG;
            break;
        case XFILE_RDSTAT_DONE:
            xtra->asyn_status = BINIO_ASYNC_DONE;
            break;
        case XFILE_RDSTAT_EXPIRED:
        default:
            xtra->asyn_status = BINIO_ASYNC_FAIL;
            break;
        }
    }

    status = xtra->asyn_status;

    if (status == BINIO_ASYNC_FAIL || status == BINIO_ASYNC_DONE)
    {
        xtra->asyn_status = BINIO_ASYNC_NOOP;

        g_async_context = NULL;
    }

    return status;
}