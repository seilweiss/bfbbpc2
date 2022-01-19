#pragma once

#include <types.h>

typedef enum _tagTRCState
{
	TRC_Unknown,
	TRC_PadMissing,
	TRC_PadInserted,
	TRC_PadInvalidNoAnalog,
	TRC_PadInvalidType,
	TRC_DiskNotIdentified,
	TRC_DiskIdentified,
	TRC_DiskTrayOpen,
	TRC_DiskTrayClosed,
	TRC_DiskNoDisk,
	TRC_DiskInvalid,
	TRC_DiskRetry,
	TRC_DiskFatal,
	TRC_Total
} TRCState;

void xTRCInit();
void xTRCRender();
void xTRCReset();
void xTRCPad(int32 pad_id, TRCState state);
void xTRCDisk(TRCState);
void render_mem_card_no_space(int32 needed, int32 available, int32 neededFiles, bool enabled);
void RenderText(const char* text, bool enabled);
