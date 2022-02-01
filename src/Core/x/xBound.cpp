#include "xBound.h"

#include "xCollide.h"
#include "iMath3.h"
#include "xDraw.h"

void xBoundUpdate(xBound* b)
{
    if (b->type == XBOUND_BOX)
    {
        xVec3Add(&b->box.center, &b->box.box.lower, &b->box.box.upper);
        xVec3SMul(&b->box.center, &b->box.center, 0.5f);
    }
    else if (b->type == XBOUND_OBB)
    {
        xVec3Add(&b->box.center, &b->box.box.lower, &b->box.box.upper);
        xVec3SMul(&b->box.center, &b->box.center, 0.5f);
        xMat4x3Toworld(&b->box.center, b->mat, &b->box.center);
    }

    if (b->type != XBOUND_NA)
    {
        xQuickCullForBound(&b->qcd, b);
    }
}

void xBoundGetBox(xBox& box, const xBound& bound)
{
    switch (bound.type)
    {
    case XBOUND_SPH:
    {
        const xSphere& o = bound.sph;

        box.upper.assign(o.center.x + o.r, o.center.y + o.r, o.center.z + o.r);
        box.lower.assign(o.center.x - o.r, o.center.y - o.r, o.center.z - o.r);

        break;
    }
    case XBOUND_BOX:
    {
        box = bound.box.box;
        break;
    }
    case XBOUND_OBB:
    {
        xBoxInitBoundOBB(&box, &bound.box.box, bound.mat);
        break;
    }
    }
}

void xBoundGetSphere(xSphere& o, const xBound& bound)
{
    switch (bound.type)
    {
    case XBOUND_SPH:
    {
        o = bound.sph;
        break;
    }
    case XBOUND_BOX:
    {
        o.center = bound.box.center;
        o.r = (bound.box.box.upper - bound.box.center).length();
        break;
    }
    case XBOUND_OBB:
    {
        const xMat4x3& mat = *bound.mat;
        xVec3 v = (bound.box.box.upper - bound.box.box.lower) * 0.5f;

        o.r = xsqrt(xsqr(v.x) * mat.right.length2() + xsqr(v.y) * mat.up.length2() + xsqr(v.z) * mat.at.length2());
        o.center = bound.box.center;

        break;
    }
    }
}

void xBoundSphereHitsOBB(const xSphere* s, const xBox* b, const xMat4x3* m, xCollis* coll)
{
    xSphereHitsOBB_nu(s, b, m, coll);
}

void xBoundHitsBound(const xBound* a, const xBound* b, xCollis* c)
{
    if (!xQuickCullIsects(&a->qcd, &b->qcd))
    {
        c->flags &= ~XCOLLIS_UNK0x1;
    }
    else
    {
        switch (a->type | (b->type << 3))
        {
        case (XBOUND_SPH | (XBOUND_SPH << 3)):
        {
            xSphereHitsSphere(&a->sph, &b->sph, c);
            break;
        }
        case (XBOUND_SPH | (XBOUND_OBB << 3)):
        {
            xBoundSphereHitsOBB(&a->sph, &b->box.box, b->mat, c);
            break;
        }
        case (XBOUND_SPH | (XBOUND_BOX << 3)):
        {
            xSphereHitsBox(&a->sph, &b->box.box, c);
            break;
        }
        case (XBOUND_BOX | (XBOUND_SPH << 3)):
        {
            xBoxHitsSphere(&a->box.box, &b->sph, c);
            break;
        }
        case (XBOUND_BOX | (XBOUND_OBB << 3)):
        {
            xBoxHitsObb(&a->box.box, &b->box.box, b->mat, c);
            break;
        }
        case (XBOUND_OBB | (XBOUND_OBB << 3)):
        {
            break;
        }
        }
    }
}

void xBoundOBBIsectRay(const xBox* b, const xMat4x3* m, const xRay3* r, xIsect* isect) WIP
{
    xRay3 xfr;
    xBox sbox;
    xVec3 scale;
    xMat4x3 mnormal;

    {
        float32 len2 = xsqr(m->right.x) + xsqr(m->right.y) + xsqr(m->right.z);

        if (xapproxeq(len2, 1.0f))
        {
            scale.x = 1.0f;

            mnormal.right.x = m->right.x;
            mnormal.right.y = m->right.y;
            mnormal.right.z = m->right.z;
        }
        else if (xapproxeq(len2, 0.0f))
        {
            scale.x = 0.0f;

            mnormal.right.x = 0.0f;
            mnormal.right.y = 1.0f;
            mnormal.right.z = 0.0f;
        }
        else
        {
            scale.x = xsqrt(len2);

            float32 len_inv = 1.0f / scale.x;

            mnormal.right.x = m->right.x * len_inv;
            mnormal.right.y = m->right.y * len_inv;
            mnormal.right.z = m->right.z * len_inv;
        }
    }

    {
        float32 len2 = xsqr(m->up.x) + xsqr(m->up.y) + xsqr(m->up.z);

        if (xapproxeq(len2, 1.0f))
        {
            scale.y = 1.0f;

            mnormal.up.x = m->up.x;
            mnormal.up.y = m->up.y;
            mnormal.up.z = m->up.z;
        }
        else if (xapproxeq(len2, 0.0f))
        {
            scale.y = 0.0f;

            mnormal.up.x = 0.0f;
            mnormal.up.y = 1.0f;
            mnormal.up.z = 0.0f;
        }
        else
        {
            scale.y = xsqrt(len2);

            float32 len_inv = 1.0f / scale.y;

            mnormal.up.x = m->up.x * len_inv;
            mnormal.up.y = m->up.y * len_inv;
            mnormal.up.z = m->up.z * len_inv;
        }
    }

    {
        float32 len2 = xsqr(m->at.x) + xsqr(m->at.y) + xsqr(m->at.z);

        if (xapproxeq(len2, 1.0f))
        {
            scale.z = 1.0f;

            mnormal.at.x = m->at.x;
            mnormal.at.y = m->at.y;
            mnormal.at.z = m->at.z;
        }
        else if (xapproxeq(len2, 0.0f))
        {
            scale.z = 0.0f;

            mnormal.at.x = 0.0f;
            mnormal.at.y = 1.0f;
            mnormal.at.z = 0.0f;
        }
        else
        {
            scale.z = xsqrt(len2);

            float32 len_inv = 1.0f / scale.z;

            mnormal.at.x = m->at.x * len_inv;
            mnormal.at.y = m->at.y * len_inv;
            mnormal.at.z = m->at.z * len_inv;
        }
    }

    mnormal.pos = m->pos;

    sbox.upper.x = b->upper.x * scale.x;
    sbox.upper.y = b->upper.y * scale.y;
    sbox.upper.z = b->upper.z * scale.z;
    sbox.lower.x = b->lower.x * scale.x;
    sbox.lower.y = b->lower.y * scale.y;
    sbox.lower.z = b->lower.z * scale.z;

    xMat4x3Tolocal(&xfr.origin, &mnormal, &r->origin);
    xMat4x3Tolocal(&xfr.dir, &mnormal, &r->dir);

    xfr.min_t = r->min_t;
    xfr.max_t = r->max_t;
    xfr.flags = r->flags;

    iBoxIsectRay(&sbox, &xfr, isect);
}

void xRayHitsBound(const xRay3* r, const xBound* b, xCollis* c)
{
    xIsect isect;

    if (b->type == XBOUND_SPH)
    {
        iSphereIsectRay(&b->sph, r, &isect);
    }
    else if (b->type == XBOUND_OBB)
    {
        xBoundOBBIsectRay(&b->box.box, b->mat, r, &isect);
    }
    else if (b->type == XBOUND_BOX)
    {
        iBoxIsectRay(&b->box.box, r, &isect);
    }

    if (isect.penned <= 0.0f)
    {
        c->flags |= XCOLLIS_UNK0x1;
        c->dist = isect.dist;
    }
    else
    {
        c->flags &= ~XCOLLIS_UNK0x1;
    }
}

void xSphereHitsBound(const xSphere* o, const xBound* b, xCollis* c)
{
    switch (b->type)
    {
    case XBOUND_SPH:
    {
        xSphereHitsSphere(o, &b->sph, c);
        break;
    }
    case XBOUND_OBB:
    {
        xBoundSphereHitsOBB(o, &b->box.box, b->mat, c);
        break;
    }
    case XBOUND_BOX:
    {
        xSphereHitsBox(o, &b->box.box, c);
        break;
    }
    }
}

void xVecHitsBound(const xVec3* v, const xBound* b, xCollis* c)
{
    xIsect isect;

    if (b->type == XBOUND_SPH)
    {
        iSphereIsectVec(&b->sph, v, &isect);
    }
    else if (b->type == XBOUND_OBB)
    {
        xVec3 lv;

        xMat4x3Tolocal(&lv, b->mat, v);
        iBoxIsectVec(&b->box.box, &lv, &isect);
    }
    else if (b->type == XBOUND_BOX)
    {
        iBoxIsectVec(&b->box.box, v, &isect);
    }

    if (isect.penned <= 0.0f)
    {
        c->flags |= XCOLLIS_UNK0x1;
    }
    else
    {
        c->flags &= ~XCOLLIS_UNK0x1;
    }
}

void xBoundDraw(const xBound* b)
{
    if (b->type == XBOUND_SPH)
    {
        xDrawSphere2(&b->sph, 0xC);
    }
    else if (b->type == XBOUND_OBB)
    {
        xDrawOBB(&b->box.box, b->mat);
    }
    else if (b->type == XBOUND_BOX)
    {
        xDrawBox(&b->box.box);
    }
}