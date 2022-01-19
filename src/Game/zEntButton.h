#pragma once

#include "zEnt.h"
#include "xEntMotion.h"

struct zEntButtonAsset
{
	uint32 modelPressedInfoID;
	uint32 actMethod;
	int32 initButtonState;
	int32 isReset;
	float32 resetDelay;
	uint32 buttonActFlags;
};

typedef struct _zEntButton : zEnt
{
	zEntButtonAsset* basset;
	xEntMotion motion;
	uint32 state;
	float32 speed;
	uint32 oldState;
	int32 oldMotState;
	float32 counter;
	xModelInstance* modelPressed;
	float32 holdTimer;
	uint32 hold;
	float32 topHeight;
} zEntButton;

void zEntButton_Init(void* ent, void* asset);
void zEntButton_Init(zEntButton* ent, xEntAsset* asset);
void zEntButton_Move(zEntButton* ent, xScene* s, float32 dt, xEntFrame* frame);
void zEntButton_Setup(zEntButton* ent, xScene*);
void zEntButton_Save(zEntButton* ent, xSerial* s);
void zEntButton_Load(zEntButton* ent, xSerial* s);
void zEntButton_Reset(zEntButton* ent, xScene* sc);
void zEntButton_Update(zEntButton* ent, xScene* sc, float32 dt);
void zEntButton_Render(zEntButton* ent);
void zEntButton_SetReady(zEntButton*);
void zEntButton_Press(zEntButton* ent, uint32 mask);
void zEntButton_Hold(zEntButton* ent, uint32 mask);
void zEntButton_SceneUpdate(float32 dt);
bool32 zEntButtonEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);