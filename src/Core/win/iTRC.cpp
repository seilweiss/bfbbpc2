#include "iTRC.h"

namespace ROMFont {

	void Init() STUB_VOID;
	void InitDisplay(_GXRenderModeObj*) STUB_VOID;
	void InitGX() STUB_VOID;
	void InitVI() STUB_VOID;
	void RenderBegin() STUB_VOID;
	void RenderEnd() STUB_VOID;
	void SwapBuffers() STUB_VOID;
	void DrawCell(int32, int32, int32, int32) STUB_VOID;
	void LoadSheet(void*) STUB_VOID;
	int32 DrawString(int32, int32, char*) STUB;
	int32 GetWidth(char*) STUB;
	void DrawTextBox(int32, int32, int32, int32, char*) STUB_VOID;

}

namespace ResetButton {

	void EnableReset() STUB_VOID;
	void DisableReset() STUB_VOID;
	void SetSndKillFunction(void(*)()) STUB_VOID;
	void CheckResetButton() STUB_VOID;

}

namespace iTRCDisk {

	void Init() STUB_VOID;
	void SetErrorMessage(const char*) STUB_VOID;
	void ResetMessage() STUB_VOID;
	void SetPadStopRumblingFunction(void(*)()) STUB_VOID;
	void SetSndSuspendFunction(void(*)()) STUB_VOID;
	void SetSndResumeFunction(void(*)()) STUB_VOID;
	void SetSndKillFunction(void(*)()) STUB_VOID;
	void SetMovieSuspendFunction(void(*)()) STUB_VOID;
	void SetMovieResumeFunction(void(*)()) STUB_VOID;
	bool IsDiskIDed() STUB;
	void DisplayErrorMessage() STUB_VOID;
	void SetDVDState() STUB_VOID;
	bool CheckDVDAndResetState() STUB;

}