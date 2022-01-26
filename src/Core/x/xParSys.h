#pragma once

#include "xBase.h"

#include <rwcore.h>

struct xParCmd;
struct xParGroup;
struct xParCmdTex;
struct xScene;

struct xParSysAsset : xBaseAsset
{
	uint32 type;
	uint32 parentParSysID;
	uint32 textureID;
	uint8 parFlags;
	uint8 priority;
	uint16 maxPar;
	uint8 renderFunc;
	uint8 renderSrcBlendMode;
	uint8 renderDstBlendMode;
	uint8 cmdCount;
	uint32 cmdSize;
};

struct xParSys : xBase
{
	xParSysAsset* tasset;
	uint32 cmdCount;
	xParCmd* cmd;
	xParSys* parent;
	xParGroup* group;
	bool visible;
	RwTexture* txtr_particle;
};

void xParCmdTexInit(xParCmdTex*);
void xParSysInit(void* b, void* tasset);
void xParSysInit(xBase* b, xParSysAsset* tasset);
void xParSysSetup(xParSys* t);
void xParSysReset(xParSys*);
void xParSysExit(xParSys* t);
bool32 xParSysEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
void xParSysUpdate(xBase* to, xScene*, float32 dt);
void xParSysRender(xBase* b);