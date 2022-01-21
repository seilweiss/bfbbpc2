#pragma once

#include <types.h>

struct tag_xFile;

enum IFILE_READSECTOR_STATUS
{
	IFILE_RDSTAT_NOOP,
	IFILE_RDSTAT_INPROG,
	IFILE_RDSTAT_DONE,
	IFILE_RDSTAT_FAIL,
	IFILE_RDSTAT_QUEUED,
	IFILE_RDSTAT_EXPIRED
};

typedef struct tag_iFile
{

} iFile;

typedef void(*iFileReadAsyncCallback)(tag_xFile*);

void iFileInit();
void iFileExit();
uint32* iFileLoad(char* name, uint32* buffer, uint32* size);
uint32 iFileOpen(const char* name, int32 flags, tag_xFile* file);
int32 iFileSeek(tag_xFile* file, int32 offset, int32 whence);
uint32 iFileRead(tag_xFile* file, void* buf, uint32 size);
int32 iFileReadAsync(tag_xFile*, void*, uint32, iFileReadAsyncCallback, int32);
IFILE_READSECTOR_STATUS iFileReadAsyncStatus(int32 key, int32* amtToFar);
uint32 iFileClose(tag_xFile* file);
uint32 iFileGetSize(tag_xFile* file);
void iFileReadStop();
void iFileFullPath(const char* relname, char* fullname);
void iFileSetPath(char* path);
uint32 iFileFind(const char*, tag_xFile*);
void iFileGetInfo(tag_xFile*, uint32*, uint32*);

inline void iFileAsyncService() {}