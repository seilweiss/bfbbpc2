#pragma once

#include <types.h>

struct xBase;

void zMusicRefreshVolume();
void zMusicInit();
void zMusicNotify(int32 situation);
void zMusicNotifyEvent(const float32* toParam, xBase*);
void zMusicUpdate(float32 dt);
void zMusicKill();
void zMusicPause();
void zMusicUnpause(bool32 kill);
void zMusicSetVolume(float32 vol, float32 delay);
void zMusicReset();