#pragma once

#include <types.h>

struct xSerial;

int32 zGameExtras_ExtrasFlags();
void zGameExtras_MoDay(int32* month, int32* day);
void zGameExtras_SceneInit();
void zGameExtras_SceneReset();
void zGameExtras_SceneExit();
void zGameExtras_SceneUpdate(float32 dt);
int32 zGameExtras_CheatFlags();
void zGameExtras_NewGameReset();
void zGameExtras_Save(xSerial* xser);
void zGameExtras_Load(xSerial* xser);
void zGameCheats(float32 dt);
void zGame_HackGalleryInit();
uint32 zGame_HackIsGallery();

inline void GEC_CheatFlagAdd(int32) STUB_VOID
inline void GEC_CheatFlagToggle(int32) STUB_VOID