#pragma once

#include <types.h>
#include <rwcore.h>

void iVSync();
void iSystemInit(uint32 options);
void iSystemExit();
uint8 iGetMinute();
uint8 iGetHour();
uint8 iGetDay();
uint8 iGetMonth();
uint32 iGetCurrFormattedDate(char* str);
uint32 iGetCurrFormattedTime(char* str);