#include "xCollideFast.h"

#include "iCollideFast.h"
#include "iMath3.h"

void xCollideFastInit(xScene* sc)
{
	iCollideFastInit(sc);
}

uint32 xRayHitsSphereFast(const xRay3* r, const xSphere* s)
{
    xVec3 var_28;
    xVec3Sub(&var_28, &r->origin, &s->center);

    float32 c = xVec3Dot(&var_28, &var_28) - xsqr(s->r);

    if (c <= 0.0f)
    {
        return TRUE;
    }

    if ((r->flags & XRAY3_UNK0x800) && c > (2.0f * s->r + r->max_t) * r->max_t)
    {
        return FALSE;
    }

    float32 f1 = xVec3Dot(&var_28, &r->dir);

    if (f1 >= 0.0f)
    {
        return FALSE;
    }

    if (xsqr(f1) >= c)
    {
        return TRUE;
    }

    return FALSE;
}

uint32 xRayHitsBoxFast(const xRay3* r, const xBox* b)
{
    xIsect isx;
    iBoxIsectRay(b, r, &isx);
    return (isx.penned <= 0.0f || isx.contained <= 0.0f);
}