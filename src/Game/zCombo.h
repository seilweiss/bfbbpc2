#pragma once

#include "xHud.h"

void zCombo_Setup();
void zCombo_Add(int32 points);
void zComboHideMessage(xhud::widget& w, xhud::motive&);
void zCombo_HideImmediately();
void zCombo_Update(float32 dt);