#include "zGameExtras.h"

struct EGGItem;

struct EGGMisc
{
	int32 other;
};

union EGGData
{
	int32 placeholder;
	EGGMisc misc;
};

struct EGGItemFuncs
{
	void(*fun_update)(float32, EGGItem*);
	void(*fun_init)(EGGItem*);
	void(*fun_reset)(EGGItem*);
	void(*fun_done)(EGGItem*);
};

struct EGGItem
{
	int32(*fun_check)(EGGItem*);
	EGGItemFuncs* funcs;
	int32 enabled;
	EGGData eggdata;
};

int32 zGameExtras_ExtrasFlags() STUB
void zGameExtras_MoDay(int32* month, int32* day) STUB_VOID
void zGameExtras_SceneInit() STUB_VOID
void zGameExtras_SceneReset() STUB_VOID
void zGameExtras_SceneExit() STUB_VOID
void zGameExtras_SceneUpdate(float32 dt) STUB_VOID
static int32 EGG_check_ExtrasFlags(EGGItem*) STUB
int32 zGameExtras_CheatFlags() STUB
void zGameExtras_NewGameReset() STUB_VOID
void zGameExtras_Save(xSerial* xser) STUB_VOID
void zGameExtras_Load(xSerial* xser) STUB_VOID
static bool32 TestCheat(uint32*) STUB
static void AddToCheatPressed(uint32) STUB_VOID
void zGameCheats(float32 dt) STUB_VOID
static void GEC_dfltSound() STUB_VOID
static void GEC_cb_AddShiny() STUB_VOID
static void GEC_cb_AddSpatulas() STUB_VOID
static void GEC_cb_BubbleBowl() STUB_VOID
static void GEC_cb_CruiseBubble() STUB_VOID
static void GEC_cb_MonsterGallery() STUB_VOID
static void GEC_cb_UnlockArtTheatre() STUB_VOID
static void GEC_cb_ChaChing() STUB_VOID
static void GEC_cb_RestoreHealth() STUB_VOID
static void GEC_cb_ExpertMode() STUB_VOID
static void GEC_cb_ShrapBobMode() STUB_VOID
static void GEC_cb_NoPantsMode() STUB_VOID
static void GEC_cb_CruiseControl() STUB_VOID
static void GEC_cb_SwapCCLR() STUB_VOID
static void GEC_cb_SwapCCUD() STUB_VOID
static void GEC_villSound() STUB_VOID
static void GEC_cb_BigPlank() STUB_VOID
static void GEC_cb_Medics() STUB_VOID
static void GEC_cb_DogTrix() STUB_VOID
static void GEC_cb_SmallPeep() STUB_VOID
static void GEC_cb_SmallCostars() STUB_VOID
static void GEC_cb_RichPeep() STUB_VOID
static void GEC_cb_PanHandle() STUB_VOID
void zGame_HackGalleryInit() STUB_VOID
uint32 zGame_HackIsGallery() STUB