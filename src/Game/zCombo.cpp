#include "zCombo.h"

#include "xTextAsset.h"

struct zComboReward
{
	int32 reward;
	const char* textName;
	uint32 rewardList[10];
	uint32 rewardNum;
	xTextAsset* textAsset;
};

static void fillCombo(zComboReward* r) STUB_VOID
void zCombo_Setup() STUB_VOID
void zCombo_Add(int32 points) STUB_VOID
void zComboHideMessage(xhud::widget& w, xhud::motive&) STUB_VOID
void zCombo_HideImmediately() STUB_VOID
void zCombo_Update(float32 dt) STUB_VOID