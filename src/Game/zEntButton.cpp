#include "zEntButton.h"

void zEntButton_Init(void* ent, void* asset) STUB_VOID
void zEntButton_Init(zEntButton* ent, xEntAsset* asset) STUB_VOID
void zEntButton_Move(zEntButton* ent, xScene* s, float32 dt, xEntFrame* frame) STUB_VOID
void zEntButton_Setup(zEntButton* ent, xScene*) STUB_VOID
void zEntButton_Save(zEntButton* ent, xSerial* s) STUB_VOID
void zEntButton_Load(zEntButton* ent, xSerial* s) STUB_VOID
void zEntButton_Reset(zEntButton* ent, xScene* sc) STUB_VOID
void zEntButton_Update(zEntButton* ent, xScene* sc, float32 dt) STUB_VOID
void zEntButton_Render(zEntButton* ent) STUB_VOID
void zEntButton_SetReady(zEntButton*) STUB_VOID
static void zEntButton_Press(zEntButton*) STUB_VOID
static void PressButtonSound(uint32) STUB_VOID
void zEntButton_Press(zEntButton* ent, uint32 mask) STUB_VOID
void zEntButton_Hold(zEntButton* ent, uint32 mask) STUB_VOID
void zEntButton_SceneUpdate(float32 dt) STUB_VOID
bool32 zEntButtonEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB