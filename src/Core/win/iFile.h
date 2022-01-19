#pragma once

#include <types.h>

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

IFILE_READSECTOR_STATUS iFileReadAsyncStatus(int32 key, int32* amtToFar);

inline void iFileAsyncService() {}