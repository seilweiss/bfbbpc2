#pragma once

#include <types.h>

// This whole file is most likely GameCube only

struct _GXRenderModeObj;

namespace ROMFont {

	void Init();
	void InitDisplay(_GXRenderModeObj*);
	void InitGX();
	void InitVI();
	void RenderBegin();
	void RenderEnd();
	void SwapBuffers();
	void DrawCell(int32, int32, int32, int32);
	void LoadSheet(void*);
	int32 DrawString(int32, int32, char*);
	int32 GetWidth(char*);
	void DrawTextBox(int32, int32, int32, int32, char*);

}

namespace ResetButton {

	void EnableReset();
	void DisableReset();
	void SetSndKillFunction(void(*)());
	void CheckResetButton();

}

namespace iTRCDisk {

	void Init();
	void SetErrorMessage(const char*);
	void ResetMessage();
	void SetPadStopRumblingFunction(void(*)());
	void SetSndSuspendFunction(void(*)());
	void SetSndResumeFunction(void(*)());
	void SetSndKillFunction(void(*)());
	void SetMovieSuspendFunction(void(*)());
	void SetMovieResumeFunction(void(*)());
	bool IsDiskIDed();
	void DisplayErrorMessage();
	void SetDVDState();
	bool CheckDVDAndResetState();

}