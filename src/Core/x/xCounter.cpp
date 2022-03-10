#include "xCounter.h"

#include "xDebug.h"
#include "xserializer.h"
#include "xEvent.h"

namespace {

	void add_tweaks(xCounter&) {}

}

void xCounterInit()
{
	xDebugRemoveTweak("Widgets|Counters");
}

void xCounterInit(void* b, void* asset)
{
	xCounterInit((xBase*)b, (xCounterAsset*)asset);
}

void xCounterInit(xBase* b, xCounterAsset* asset)
{
    xCounter* t = (xCounter*)b;

    xBaseInit(t, asset);

    t->eventFunc = xCounterEventCB;
    t->asset = asset;

    if (t->linkCount)
    {
        t->link = (xLinkAsset*)(t->asset + 1);
    }
    else
    {
        t->link = NULL;
    }

    t->state = XCOUNTER_ACTIVE;
    t->count = asset->count;
    t->counterFlags = 0;

    add_tweaks(*t);
}

void xCounterReset(xBase* b)
{
    xCounter* t = (xCounter*)b;

    xBaseInit(t, t->asset);

    if (t->linkCount)
    {
        t->link = (xLinkAsset*)(t->asset + 1);
    }
    else
    {
        t->link = NULL;
    }

    t->count = t->asset->count;
    t->state = XCOUNTER_ACTIVE;
}

void xCounterSave(xCounter* ent, xSerial* s)
{
    xBaseSave(ent, s);

    s->Write(ent->state);
    s->Write(ent->count);
}

void xCounterLoad(xCounter* ent, xSerial* s)
{
    xBaseLoad(ent, s);

    s->Read(&ent->state);
    s->Read(&ent->count);
}

bool32 xCounterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*)
{
    xCounter* t = (xCounter*)to;

    switch (toEvent)
    {
    case eEventDecrement:
    {
        if (t->state != XCOUNTER_EXPIRED && (!(t->counterFlags & XCOUNTER_ISSPATULA) || t->count != 2))
        {
            t->count--;

            if (t->count == 0)
            {
                zEntEvent(t, t, eEventExpired);
            }
            else if (t->count > 0 && t->count <= 20)
            {
                zEntEvent(t, t, t->count + (eEventCount1 - 1));
            }
        }

        break;
    }
    case eEventIncrement:
    {
        if (t->state != XCOUNTER_EXPIRED)
        {
            t->count++;

            if (t->count == 0)
            {
                zEntEvent(t, t, eEventExpired);
            }
            else if (t->count > 0 && t->count <= 20)
            {
                zEntEvent(t, t, t->count + (eEventCount1 - 1));
            }
        }

        break;
    }
    case eEventReset:
    {
        t->state = XCOUNTER_ACTIVE;
        t->count = t->asset->count;
        break;
    }
    case eEventExpired:
    {
        if (!(t->counterFlags & XCOUNTER_ISSPATULA) || t->count != 2)
        {
            t->count = 0;
            t->state = XCOUNTER_EXPIRED;
        }

        break;
    }
    default:
    {
        if (t->state != XCOUNTER_EXPIRED && toEvent >= eEventCount1 && toEvent <= eEventCount20)
        {
            int16 newCount = toEvent - (eEventCount1 - 1);

            if (!(t->counterFlags & XCOUNTER_ISSPATULA) || t->count != 2)
            {
                t->count = newCount;
            }
        }

        break;
    }
    }

    return TRUE;
}