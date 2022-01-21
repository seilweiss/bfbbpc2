#include "zScene.h"

#include "xDynAsset.h"

namespace {

	struct dynamic_type_data
	{
		const char* name;
		int32 type;
		uint32 size;
		bool is_ent;
		void(*load)(xBase&, xDynAsset&, ulong32);
	};

	uint32 count_dynamic_types(const char*) STUB;
	void add_dynamic_types(zScene&) STUB_VOID;
	uint32 init_dynamic_type(zScene& s, uint32 index, const dynamic_type_data& d) STUB;
	uint32 init_dynamic_types(zScene&, uint32) STUB;

}

struct zSceneObjectInstanceDesc
{
	const char* name;
	int32 baseType;
	uint32 assetType;
	uint32 sizeRuntime;
	uint32(*func)(zScene*, zSceneObjectInstanceDesc*, uint32);
	void(*objectInitFunc)(void*, void*);
	uint32(*querySubObjects)(void*);
};

static uint32 zSceneInitFunc_DefaultEnt(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Default(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_MovePoint(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_SBNPC(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Player(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Camera(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Surface(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Gust(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Volume(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
static uint32 zSceneInitFunc_LobMaster(zScene*, zSceneObjectInstanceDesc*, uint32 base_idx) STUB
static uint32 zSceneInitFunc_Dispatcher(zScene* s, zSceneObjectInstanceDesc* desc, uint32 base_idx) STUB
void zSceneSet(xBase*, uint32) STUB_VOID
static void PipeCountStuffCB(RpAtomic*, uint32 pipeFlags, uint32) STUB_VOID
static void PipeAddStuffCB(RpAtomic* data, uint32 pipeFlags, uint32) STUB_VOID
static void PipeForAllSceneModels(void(*pipeCB)(RpAtomic*, uint32, uint32)) STUB_VOID
void zSceneInitEnvironmentalSoundEffect() STUB_VOID
static uint32 BaseTypeNeedsUpdate(uint8 baseType) STUB
inline void add_scene_tweaks() {}
void zSceneInit(uint32 theSceneID, bool32 reloadInProgress) STUB_VOID
void zSceneExit(bool32 beginReload) STUB_VOID
void zSceneUpdateSFXWidgets() STUB_VOID
static void HackSwapIt(char*, int32) STUB_VOID
void zSceneSwitch(zPortal* p, bool32 forceSameScene) STUB_VOID
void zSceneSave(zScene* ent, xSerial* s) STUB_VOID
void zSceneLoad(zScene* ent, xSerial* s) STUB_VOID
void zSceneReset() STUB_VOID
static void ActivateCB(xBase* base) STUB_VOID
static void DeactivateCB(xBase* base) STUB_VOID
void zSceneSetup() STUB_VOID
bool32 zSceneSetup_serialTraverseCB(uint32 clientID, xSerial* xser) STUB
void zSceneUpdate(float32 elapsedSec) STUB_VOID
static void zSceneRenderPreFX() STUB_VOID
static void zSceneRenderPostFX() STUB_VOID
void zSceneRender() STUB_VOID
static void zSceneObjHashtableInit(int32) STUB_VOID
static void zSceneObjHashtableExit() STUB_VOID
static int32 zSceneObjHashtableUsage() STUB
static void zSceneObjHashtableAdd(uint32 id, xBase* base) STUB_VOID
static xBase* zSceneObjHashtableGet(uint32) STUB
xBase* zSceneFindObject(uint32 gameID) STUB
xBase* zSceneGetObject(int32 type, int32 idx) STUB
const char* zSceneGetName(uint32 gameID) STUB
const char* zSceneGetName(xBase* b) STUB
void zSceneForAllBase(zSceneBaseCallback, void*) STUB_VOID
void zSceneForAllBase(zSceneBaseCallback func, int32 baseType, void* data) STUB_VOID
static xBase* zSceneExitSoundIteratorCB(xBase*, zScene*, void*) STUB
void zSceneMemLvlChkCB() STUB_VOID
uint32 zSceneLeavingLevel() STUB
const char* zSceneGetLevelName(uint32 sceneID) STUB
uint32 zSceneGetLevelIndex() STUB
uint32 zSceneGetLevelIndex(uint32) STUB
const char* zSceneGetLevelPrefix(uint32 index) STUB
const char* zSceneGetAreaname(uint32) STUB
uint32 zSceneCalcProgress() STUB
void zScene_UpdateFlyToInterface(float32 dt) STUB_VOID
void zSceneCardCheckStartup_set(int32 needed, int32 available, int32 files) STUB_VOID
void zSceneEnableVisited(zScene* s) STUB_VOID
void zSceneEnableScreenAdj(uint32 enable) STUB_VOID
void zSceneSetOldScreenAdj() STUB_VOID
uint32 zScene_ScreenAdjustMode() STUB
void zSceneSpawnRandomBubbles() STUB_VOID
static void zSceneAutoSave() STUB_VOID