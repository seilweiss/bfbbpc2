#pragma once

#include "zEnt.h"
#include "xMgr.h"

struct xIniFile;

struct zUIAsset : xEntAsset
{
	uint32 uiFlags;
	uint16 dim[2];
	uint32 textureID;
	float32 uva[2];
	float32 uvb[2];
	float32 uvc[2];
	float32 uvd[2];
};

typedef struct _zUI : zEnt
{
	zUIAsset* sasset;
	uint32 uiFlags;
	uint32 uiButton;
	uint16 preUpdateIndex;
	uint16 updateIndex;
} zUI;

class zUIMgr : public xMgr
{
private:
	int32 m_preUpdateStart;
	int32 m_preUpdateEnd;
	uint32 m_preUpdateMax;
	zUI** m_preUpdate;
	int32 m_updateStart;
	int32 m_updateEnd;
	uint32 m_updateMax;
	zUI** m_update;

public:
	void PreUpdate(zScene* s, float32 dt);
	void Update(zScene* s, float32 dt);
	void Setup(zScene* s);
	void Touch(zUI* ui);
	void Remove(zUI* ui);
	void Remove_PreUpdate(zUI*);
	void Remove_Update(zUI*);
	void Add(zUI*);
	void Add_PreUpdate(zUI*);
	void Add_Update(zUI*);
};

void zUI_Init();
void zUI_Init(void* ent, void* asset);
void zUI_Init(zUI* ent, xEntAsset* asset);
void zUI_Save(zUI* ent, xSerial* s);
void zUI_Load(zUI* ent, xSerial* s);
void zUI_Reset(zUI* ent);
void zUI_PreUpdate(zUI* ent, xScene*, float32);
void zUI_Update(zUI* ent, xScene*, float32 dt);
int32 iRenderQSort_Face(const void* arg1, const void* arg2);
void zUIRenderAll();
void zUI_Render(xEnt* ent);
bool32 zUIEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*);
void zUI_ParseINI(xIniFile* ini);
bool32 zUIPortalEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void zUI_ScenePortalSetToCurrentLevel(zScene* zsc);
void zUI_ScenePortalInit(zScene* zsc);
void zUI_PortalToKrabs(uint32 taskNum);
void zUI_ScenePortalUpdate();
void zUI_ScenePortalSave(xSerial* s);
void zUI_ScenePortalLoad(xSerial* s);