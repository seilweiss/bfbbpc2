#pragma once

#include "zUI.h"

struct zUIFontAsset : zUIAsset
{
	uint16 uiFontFlags;
	uint8 mode;
	uint8 fontID;
	uint32 textAssetID;
	uint8 bcolor[4];
	uint8 color[4];
	uint16 inset[4];
	uint16 space[2];
	uint16 cdim[2];
	uint32 max_height;
};

struct zUIFont : zUI
{
	zUIFontAsset* fasset;
	uint16 uiFontFlags;
	uint16 uiFontHackFlags;
	uint32 text_id;
	float32 yscroll;
	uint32 text_index;
	const char* text;
};

void zUIFontInit();
void zUIFont_Init(void* ent, void* asset);
void zUIFont_Init(zUIFont* ent, xEntAsset* asset);
void zUIFont_Save(zUIFont* ent, xSerial* s);
void zUIFont_Load(zUIFont* ent, xSerial* s);
void zUIFont_Reset(zUIFont*);
void zUIFont_PreUpdate(zUIFont* ent, xScene* sc, float32 dt);
void zUIFont_Update(zUIFont* ent, xScene*, float32);
bool32 zUIFontEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void zUIFont_Render(xEnt* e);
