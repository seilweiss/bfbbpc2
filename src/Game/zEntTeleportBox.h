#pragma once

#include "zEnt.h"
#include "xDynAsset.h"

struct teleport_asset : xDynAsset
{
	uint32 marker;
	uint32 opened;
	uint32 launchAngle;
	uint32 camAngle;
	uint32 targetID;
};

typedef struct _zEntTeleportBox : zEnt
{
	uint32 status;
	teleport_asset* tasset;
	zEnt* target;
	uint32 currPlrState;
	uint32 prevPlrState;
	uint32 jumpInAnim;
	uint32 jumpOutAnim;
	uint32 JOtoOpenAnim;
	uint32 JItoOpenAnim;
	xBox trig[2];
	uint32 currPlayerIn;
	uint32 prevPlayerIn;
	uint32 currPlayerNear;
	uint32 prevPlayerNear;
	float32 lastdt;
	float32 plrCtrlTimer;
} zEntTeleportBox;

uint32 OpenCheck(xAnimTransition*, xAnimSingle*, void* object);
void zEntTeleportBox_Init(xBase& data, xDynAsset& asset, ulong32);
void zEntTeleportBox_Init(zEntTeleportBox* ent, teleport_asset* asset);
void zEntTeleportBox_InitAll();
void zEntTeleportBox_Setup(zEntTeleportBox* ent);
void zEntTeleportBox_Update(xEnt* rawent, xScene* sc, float32 dt);
void zEntTeleportBox_Save(zEntTeleportBox* ent, xSerial* s);
void zEntTeleportBox_Load(zEntTeleportBox* ent, xSerial* s);
void zEntTeleportBox_Open(zEntTeleportBox*);
void zEntTeleportBox_Close(zEntTeleportBox*);
uint32 zEntTeleportBox_isOpen(zEntTeleportBox*);
uint32 zEntTeleportBox_isClosed(zEntTeleportBox*);
bool32 zEntTeleportBox_playerIn();
bool32 zEntTeleportBoxEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);