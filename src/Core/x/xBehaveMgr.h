#pragma once

#include <types.h>

struct xGoal;

typedef enum en_psynote
{
	PSY_NOTE_HASRESUMED,
	PSY_NOTE_HASENTERED,
	PSY_NOTE_ANIMCHANGED,
	PSY_NOTE_NOMORE,
	PSY_NOTE_FORCE = FORCEENUMSIZEINT
} psynote;

class xPSYNote
{
public:
	xPSYNote() WIP {}

	void Notice(psynote, xGoal*, void*) WIP {}
};