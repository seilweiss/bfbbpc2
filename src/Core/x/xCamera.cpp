#include "xCamera.h"

#include "xstransvc.h"
#include "xEnt.h"
#include "xCollideFast.h"
#include "xScrFx.h"
#include "xScene.h"
#include "xEnv.h"
#include "zGlobals.h"
#include "zGrid.h"

#include <rwcore.h>
#include <rpworld.h>

#include <string.h>

static bool32 sCamCollis = FALSE;

int32 xcam_collis_owner_disable = 0;
bool32 xcam_do_collis = TRUE;
float32 xcam_collis_radius = 0.4f;
float32 xcam_collis_stiffness = 0.3f;

static RpAtomic* sInvisWallHack = NULL;

float32 gCameraLastFov = 0.0f;

static xMat4x3 sCameraFXMatOld;

cameraFXTableEntry sCameraFXTable[CAMERAFX_TYPE_COUNT] =
{
    { CAMERAFX_TYPE_UNK0, NULL, NULL },
    { CAMERAFX_TYPE_ZOOM, xCameraFXZoomUpdate, NULL },
    { CAMERAFX_TYPE_SHAKE, xCameraFXShakeUpdate, NULL }
};

cameraFX sCameraFX[CAMERAFX_COUNT];

static void xCameraFXInit();

inline void add_camera_tweaks() {}

void xCameraInit(xCamera* cam, uint32 width, uint32 height) WIP
{
    xCameraFXInit();

    cam->lo_cam = iCameraCreate(width, height, TRUE);

    xCameraSetFOV(cam, 75.0f);

    cam->bound.sph.center.x = 0.0f;
    cam->bound.sph.center.y = 0.0f;
    cam->bound.sph.center.z = 0.0f;
    cam->bound.sph.r = 0.5f;
    cam->tgt_mat = NULL;
    cam->tgt_omat = NULL;
    cam->tgt_bound = NULL;
    cam->sc = NULL;
    cam->tran_accum.x = 0.0f;
    cam->tran_accum.y = 0.0f;
    cam->tran_accum.z = 0.0f;

    add_camera_tweaks();
}

void xCameraExit(xCamera* cam)
{
    if (cam->lo_cam)
    {
        iCameraDestroy(cam->lo_cam);
        cam->lo_cam = NULL;
    }
}

void xCameraReset(xCamera* cam, float32 d, float32 h, float32 pitch) WIP
{
    sInvisWallHack = (RpAtomic*)xSTFindAsset(0xB8895D14);

    xMat4x3Identity(&cam->mat);

    cam->omat = cam->mat;
    cam->focus.x = 0.0f;
    cam->focus.y = 0.0f;
    cam->focus.z = 10.0f;
    cam->tran_accum.x = 0.0f;
    cam->tran_accum.y = 0.0f;
    cam->tran_accum.z = 0.0f;
    cam->flags = 0;

    float32 goal_p = PI;

    if (cam->tgt_mat)
    {
        goal_p += xatan2(cam->tgt_mat->at.x, cam->tgt_mat->at.z);
    }

    xCameraMove(cam, 0x2E, d, h, goal_p, 0.0f, 2.0f / 3.0f, 2.0f / 3.0f);

    cam->pitch_goal = pitch;
    cam->pitch_cur = pitch;
    cam->roll_cur = 0.0f;

    xMat3x3Euler(&cam->mat, cam->yaw_cur, cam->pitch_cur, cam->roll_cur);

    cam->omat = cam->mat;
    cam->yaw_ct = 1.0f;
    cam->yaw_cd = 1.0f;
    cam->yaw_ccv = 0.65f;
    cam->yaw_csv = 1.0f;
    cam->pitch_ct = 1.0f;
    cam->pitch_cd = 1.0f;
    cam->pitch_ccv = 0.7f;
    cam->pitch_csv = 1.0f;
    cam->roll_ct = 1.0f;
    cam->roll_cd = 1.0f;
    cam->roll_ccv = 0.7f;
    cam->roll_csv = 1.0f;
    cam->flags |= XCAMERA_UNK0x80;

    xcam_do_collis = TRUE;
    xcam_collis_owner_disable = 0;
}

static void xCam_buildbasis(xCamera* cam) WIP
{
    if (!cam->tgt_mat)
    {
        return;
    }

    float32 d2d;
    float32 dx__ = cam->mat.pos.x - cam->tgt_mat->pos.x;
    float32 dz__ = cam->mat.pos.z - cam->tgt_mat->pos.z;
    float32 dist2 = xsqr(dx__) + xsqr(dz__);

    if (xapproxeq(dist2, 1.0f))
    {
        cam->mbasis.at.x = dx__;
        cam->mbasis.at.z = dz__;

        d2d = 1.0f;
    }
    else if (xapproxeq(dist2, 0.0f))
    {
        cam->mbasis.at.x = 0.0f;
        cam->mbasis.at.z = 0.0f;

        d2d = 0.0f;
    }
    else
    {
        d2d = xsqrt(dist2);

        float32 dist_inv = 1.0f / d2d;

        cam->mbasis.at.x = dx__ * dist_inv;
        cam->mbasis.at.z = dz__ * dist_inv;
    }

    if (d2d < EPSILON)
    {
        cam->mbasis.at.x = cam->mat.at.x;
        cam->mbasis.at.z = cam->mat.at.z;

        float32 dist = xsqrt(xsqr(cam->mbasis.at.x) + xsqr(cam->mbasis.at.z));

        if (dist > 0.001f)
        {
            cam->mbasis.at.x *= 1.0f / dist;
            cam->mbasis.at.z *= 1.0f / dist;
        }
        else
        {
            cam->mbasis.at.x = isin(cam->pcur);
            cam->mbasis.at.z = icos(cam->pcur);
        }
    }

    cam->mbasis.at.y = 0.0f;
    cam->mbasis.up.x = 0.0f;
    cam->mbasis.up.y = 1.0f;
    cam->mbasis.up.z = 0.0f;
    cam->mbasis.right.x = cam->mbasis.at.z;
    cam->mbasis.right.y = 0.0f;
    cam->mbasis.right.z = -cam->mbasis.at.x;
}

static void xCam_cyltoworld(xVec3* v, const xMat4x3* tgt_mat, float32 d, float32 h, float32 p, uint32 flags)
{
    if (flags & XCAMERA_UNK0x10)
    {
        v->y = h;
    }
    else
    {
        v->y = h + tgt_mat->pos.y;
    }

    if (flags & XCAMERA_UNK0x20)
    {
        v->x = d * isin(p) + tgt_mat->pos.x;
        v->z = d * icos(p) + tgt_mat->pos.z;
    }
    else
    {
        p += xatan2(tgt_mat->at.x, tgt_mat->at.z);

        v->x = d * isin(p) + tgt_mat->pos.x;
        v->z = d * icos(p) + tgt_mat->pos.z;
    }
}

static void xCam_worldtocyl(float32& d, float32& h, float32& p, const xMat4x3* tgt_mat, const xVec3* v, uint32 flags) WIP
{
    float32 lx;
    float32 lz;

    float32 dx__ = v->x - tgt_mat->pos.x;
    float32 dz__ = v->z - tgt_mat->pos.z;
    float32 dist2 = xsqr(dx__) + xsqr(dz__);

    if (xapproxeq(dist2, 1.0f))
    {
        d = 1.0f;
        lx = dx__;
        lz = dz__;
    }
    else if (xapproxeq(dist2, 0.0f))
    {
        d = 0.0f;
        lx = 0.0f;
        lz = 0.0f;
    }
    else
    {
        d = xsqrt(dist2);

        float32 dist_inv = 1.0f / d;

        lx = dx__ * dist_inv;
        lz = dz__ * dist_inv;
    }

    if (flags & XCAMERA_UNK0x10)
    {
        h = v->y;
    }
    else
    {
        h = v->y - tgt_mat->pos.y;
    }

    p = xatan2(lx, lz);

    if (!(flags & XCAMERA_UNK0x20))
    {
        float32 tgt_p = xatan2(tgt_mat->at.x, tgt_mat->at.z);

        p = xDangleClamp(p - tgt_p);
    }
}

static void xCam_CorrectD(xCamera* cam, float32 f1, float32 f2, float32 f3) WIP
{
    float32 f2_0 = (10.0f / 7.0f) * (2.0f * f1 - f2 * f3);

    f2_0 -= f2;
    f2_0 *= f3;

    float32 f0_0 = cam->mbasis.at.x * f2_0;
    float32 f0_1 = cam->mbasis.at.z * f2_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f0_1;
}

static void xCam_CorrectH(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f2_0 = 0.15f * f2;
    float32 f1_0 = (10.0f / 7.0f) * (f1 - f2_0 * f3);

    f1_0 -= f2_0;
    f1_0 *= f3;

    cam->mat.pos.y += f1_0;
}

static void xCam_CorrectP(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f8 = 0.15f * f2;
    float32 f1_0 = 2.5f * (2.0f * f1 - f8 * f3);

    f1_0 -= f8;
    f1_0 *= f3;

    float32 f0_0 = cam->mbasis.right.x * f1_0;
    float32 f1_1 = cam->mbasis.right.z * f1_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f1_1;
}

static void xCam_DampP(xCamera* cam, float32 f1, float32 f2)
{
    float32 f2_0 = f2 * (-6.0f * f1 * f2);
    float32 f0_0 = cam->mbasis.right.x * f2_0;
    float32 f2_1 = cam->mbasis.right.z * f2_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f2_1;
}

static void xCam_CorrectYaw(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->yaw_ct * (2.0f * cam->yaw_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->yaw_csv * f3;

    cam->yaw_cur += f1_0;
}

static void xCam_CorrectPitch(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->pitch_ct * (2.0f * cam->pitch_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->pitch_csv * f3;

    cam->pitch_cur += f1_0;
}

static void xCam_CorrectRoll(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->roll_ct * (2.0f * cam->roll_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->roll_csv * f3;

    cam->roll_cur += f1_0;
}

void SweptSphereHitsCameraEnt(xScene*, xRay3* ray, xQCData* qcd, xEnt* ent, void* data)
{
    xSweptSphere* sws = (xSweptSphere*)data;

    if (!ent->camcollModel)
    {
        return;
    }

    if (!(ent->chkby & XENT_COLLTYPE_PLYR))
    {
        return;
    }

    if (!xQuickCullIsects(qcd, &ent->bound.qcd))
    {
        return;
    }

    if (!xEntIsVisible(ent))
    {
        if (ent->model->Data != sInvisWallHack)
        {
            return;
        }

        if (ent->collLev != 5)
        {
            if (ent->bound.type == XBOUND_BOX)
            {
                xSweptSphereToBox(sws, &ent->bound.box.box, NULL);
                return;
            }
            else if (ent->bound.type == XBOUND_OBB)
            {
                xSweptSphereToBox(sws, &ent->bound.box.box, ent->bound.mat);
                return;
            }
            else
            {
                return;
            }
        }
    }

    uint32 result = FALSE;

    switch (ent->bound.type)
    {
    case XBOUND_SPH:
    {
        float32 oldrad = ent->bound.sph.r;

        ent->bound.sph.r += sws->radius;

        result = xRayHitsSphereFast(ray, &ent->bound.sph);

        ent->bound.sph.r = oldrad;

        break;
    }
    case XBOUND_BOX:
    {
        xBox tmpbox;

        tmpbox.upper.x = ent->bound.box.box.upper.x + sws->radius;
        tmpbox.upper.y = ent->bound.box.box.upper.y + sws->radius;
        tmpbox.upper.z = ent->bound.box.box.upper.z + sws->radius;
        tmpbox.lower.x = ent->bound.box.box.lower.x - sws->radius;
        tmpbox.lower.y = ent->bound.box.box.lower.y - sws->radius;
        tmpbox.lower.z = ent->bound.box.box.lower.z - sws->radius;

        result = xRayHitsBoxFast(ray, &tmpbox);

        break;
    }
    case XBOUND_OBB:
    {
        float32 f31 = xVec3Length(&ent->bound.mat->right);
        xBox tmpbox;
        xRay3 lr;
        xMat3x3 mn;

        xMat3x3Normalize(&mn, ent->bound.mat);
        xMat4x3Tolocal(&lr.origin, ent->bound.mat, &ray->origin);
        xMat3x3Tolocal(&lr.dir, &mn, &ray->dir);

        lr.max_t = ray->max_t / f31;
        lr.min_t = ray->min_t / f31;
        lr.flags = ray->flags;

        tmpbox.upper.x = ent->bound.box.box.upper.x + sws->radius / f31;
        tmpbox.upper.y = ent->bound.box.box.upper.y + sws->radius / f31;
        tmpbox.upper.z = ent->bound.box.box.upper.z + sws->radius / f31;
        tmpbox.lower.x = ent->bound.box.box.lower.x - sws->radius / f31;
        tmpbox.lower.y = ent->bound.box.box.lower.y - sws->radius / f31;
        tmpbox.lower.z = ent->bound.box.box.lower.z - sws->radius / f31;

        result = xRayHitsBoxFast(&lr, &tmpbox);

        break;
    }
    }

    if (result)
    {
        xModelInstance* collmod = ent->camcollModel;

        xSweptSphereToModel(sws, collmod->Data, collmod->Mat);
    }
}

static void _xCameraUpdate(xCamera* cam, float32 dt) WIP
{
    if (!cam->tgt_mat)
    {
        return;
    }

    static float32 last_dt = 1.0f / 60.0f;

    xCam_worldtocyl(cam->dcur, cam->hcur, cam->pcur, cam->tgt_mat, &cam->mat.pos, cam->flags);

    float32 wcvx = cam->mat.pos.x - cam->omat.pos.x;
    float32 wcvy = cam->mat.pos.y - cam->omat.pos.y;
    float32 wcvz = cam->mat.pos.z - cam->omat.pos.z;
    float32 m = 1.0f / last_dt;

    wcvx *= m;
    wcvy *= m;
    wcvz *= m;

    cam->omat.pos = cam->mat.pos;

    xCam_buildbasis(cam);

    float32 dcv = wcvx * cam->mbasis.at.x + wcvz * cam->mbasis.at.z;
    float32 hcv = wcvy;
    float32 pcv = wcvx * cam->mbasis.right.x + wcvz * cam->mbasis.right.z;

    wcvx *= dt;
    wcvy *= dt;
    wcvz *= dt;

    cam->mat.pos.x += wcvx;
    cam->mat.pos.y += wcvy;
    cam->mat.pos.z += wcvz;

    if (cam->flags & XCAMERA_UNK0x1)
    {
        float32 tnext = cam->tmr - dt;

        if (tnext <= 0.0f)
        {
            cam->flags &= ~XCAMERA_UNK0x1;
            cam->tmr = 0.0f;
            cam->omat.pos = cam->mat.pos;
        }
        else
        {
            float32 dtg = cam->dgoal - cam->dcur;
            float32 htg = cam->hgoal - cam->hcur;
            float32 ptg = xDangleClamp(cam->pgoal - cam->pcur) * (cam->dgoal + cam->dcur) * 0.5f;
            float32 dsv;
            float32 hsv;
            float32 psv;

            if (tnext <= cam->tm_dec)
            {
                float32 T_inv = 1.0f / cam->tmr;

                dsv = (dtg * 2.0f - dcv * dt) * T_inv;
                hsv = (htg * 2.0f - hcv * dt) * T_inv;
                psv = (ptg * 2.0f - pcv * dt) * T_inv;
            }
            else if (tnext <= cam->tm_acc)
            {
                float32 T_inv = 1.0f / (2.0f * cam->tmr - dt - cam->tm_dec);

                dsv = (dtg * 2.0f - dcv * dt) * T_inv;
                hsv = (htg * 2.0f - hcv * dt) * T_inv;
                psv = (ptg * 2.0f - pcv * dt) * T_inv;
            }
            else
            {
                float32 it = 1.0f / (cam->tmr - cam->tm_acc);
                float32 ot = 2.0f / (cam->tmr + cam->tm_acc - cam->tm_dec);
                float32 T_inv = cam->tmr - dt + cam->tm_acc - cam->tm_dec;

                dsv = (dtg * 2.0f - (dtg * ot + cam->depv) * 0.5f * T_inv - dcv * dt) * it;
                hsv = (htg * 2.0f - (htg * ot + cam->hepv) * 0.5f * T_inv - hcv * dt) * it;
                psv = (ptg * 2.0f - (ptg * ot + cam->pepv) * 0.5f * T_inv - pcv * dt) * it;
            }

            float32 dpv = dsv - dcv;
            float32 hpv = hsv - hcv;
            float32 ppv = psv - pcv;
            float32 vax = cam->mbasis.right.x * ppv + cam->mbasis.at.x * dpv;
            float32 vay = cam->mbasis.right.y * ppv + hpv;
            float32 vaz = cam->mbasis.right.z * ppv + cam->mbasis.at.z * dpv;

            vax *= dt;
            vay *= dt;
            vaz *= dt;

            cam->mat.pos.x += vax;
            cam->mat.pos.y += vay;
            cam->mat.pos.z += vaz;
            cam->tmr = tnext;
        }
    }
    else
    {
        if (cam->flags & XCAMERA_UNK0x2)
        {
            if (!xapproxeq(cam->dcur / cam->dgoal, 1.0f))
            {
                float32 dtg = cam->dgoal - cam->dcur;
                xCam_CorrectD(cam, dtg, dcv, dt);
            }
        }
        else if (cam->dmax > cam->dmin)
        {
            if (cam->dcur < cam->dmin)
            {
                float32 dtg = cam->dmin - cam->dcur;
                xCam_CorrectD(cam, dtg, dcv, dt);
            }
            else if (cam->dcur > cam->dmax)
            {
                float32 dtg = cam->dmax - cam->dcur;
                xCam_CorrectD(cam, dtg, dcv, dt);
            }
        }

        if (cam->flags & XCAMERA_UNK0x4)
        {
            if (!xapproxeq(cam->hcur / cam->hgoal, 1.0f))
            {
                float32 htg = cam->hgoal - cam->hcur;
                xCam_CorrectH(cam, htg, hcv, dt);
            }
        }
        else if (cam->hmax > cam->hmin)
        {
            if (cam->hcur < cam->hmin)
            {
                float32 htg = cam->hmin - cam->hcur;
                xCam_CorrectH(cam, htg, hcv, dt);
            }
            else if (cam->hcur > cam->hmax)
            {
                float32 htg = cam->hmax - cam->hcur;
                xCam_CorrectH(cam, htg, hcv, dt);
            }
        }

        if (cam->flags & XCAMERA_UNK0x8)
        {
            if (!xapproxeq(cam->pcur / cam->pgoal, 1.0f))
            {
                float32 ptg = xDangleClamp(cam->pgoal - cam->pcur) * cam->dcur;
                xCam_CorrectP(cam, ptg, pcv, dt);
            }
        }
        else if (cam->pmax > cam->pmin)
        {
            float32 dphi = xDangleClamp(cam->pmax - cam->pcur);
            float32 dplo = xDangleClamp(cam->pmin - cam->pcur);

            if (dplo > 0.0f && (dphi > 0.0f || xabs(dplo) <= xabs(dphi)))
            {
                float32 ptg = (dplo + EPSILON) * cam->dcur;
                xCam_CorrectP(cam, ptg, pcv, dt);
            }
            else if (dphi < 0.0f)
            {
                float32 ptg = (dphi - EPSILON) * cam->dcur;
                xCam_CorrectP(cam, ptg, pcv, dt);
            }
            else
            {
                xCam_DampP(cam, pcv, dt);
            }
        }
        else
        {
            xCam_DampP(cam, pcv, dt);
        }
    }

    if (cam->flags & XCAMERA_UNK0x80)
    {
        xVec3 oeu;
        xVec3 eu;

        xMat3x3GetEuler(&cam->mat, &eu);
        xMat3x3GetEuler(&cam->omat, &oeu);

        float32 m = 1.0f / last_dt;
        float32 ycv = xDangleClamp(eu.x - oeu.x) * m;
        float32 pcv = xDangleClamp(eu.y - oeu.y) * m;
        float32 rcv = xDangleClamp(eu.z - oeu.z) * m;

        ycv *= cam->yaw_ccv;
        pcv *= cam->pitch_ccv;
        rcv *= cam->roll_ccv;

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;

        cam->yaw_cur += ycv * dt;
        cam->pitch_cur += pcv * dt;
        cam->roll_cur += rcv * dt;

        if (cam->flags & XCAMERA_UNK0x40)
        {
            float32 tnext = cam->ltmr - dt;

            if (tnext <= 0.0f)
            {
                cam->flags &= ~XCAMERA_UNK0x40;
                cam->ltmr = 0.0f;
            }
            else
            {
                float32 ytg = xDangleClamp(cam->yaw_goal - cam->yaw_cur);
                float32 ptg = xDangleClamp(cam->pitch_goal - cam->pitch_cur);
                float32 rtg = xDangleClamp(cam->roll_goal - cam->roll_cur);
                float32 ysv;
                float32 psv;
                float32 rsv;

                if (tnext <= cam->ltm_dec)
                {
                    float32 T_inv = 1.0f / cam->ltmr;

                    ysv = (ytg * 2.0f - ycv * dt) * T_inv;
                    psv = (ptg * 2.0f - pcv * dt) * T_inv;
                    rsv = (rtg * 2.0f - rcv * dt) * T_inv;
                }
                else if (tnext <= cam->ltm_acc)
                {
                    float32 T_inv = 1.0f / (cam->ltmr * 2.0f - dt - cam->ltm_dec);

                    ysv = (ytg * 2.0f - ycv * dt) * T_inv;
                    psv = (ptg * 2.0f - pcv * dt) * T_inv;
                    rsv = (rtg * 2.0f - rcv * dt) * T_inv;
                }
                else
                {
                    float32 it = 1.0f / (cam->ltmr - cam->ltm_acc);
                    float32 ot = 2.0f / (cam->ltmr + cam->ltm_acc - cam->ltm_dec);
                    float32 T_inv = cam->ltmr - dt + cam->ltm_acc - cam->ltm_dec;

                    ysv = (ytg * 2.0f - (ytg * ot + cam->yaw_epv) * 0.5f * T_inv - ycv * dt) * it;
                    psv = (ptg * 2.0f - (ptg * ot + cam->pitch_epv) * 0.5f * T_inv - pcv * dt) * it;
                    rsv = (rtg * 2.0f - (rtg * ot + cam->roll_epv) * 0.5f * T_inv - rcv * dt) * it;
                }

                float32 ypv = ysv - ycv;
                float32 ppv = psv - pcv;
                float32 rpv = rsv - rcv;

                cam->yaw_cur += ypv * dt;
                cam->pitch_cur += ppv * dt;
                cam->roll_cur += rpv * dt;

                xMat3x3Euler(&cam->mat, cam->yaw_cur, cam->pitch_cur, cam->roll_cur);

                cam->ltmr = tnext;
            }
        }
        else
        {
            if (!xapproxeq(cam->yaw_cur, cam->yaw_goal))
            {
                float32 ytg = xDangleClamp(cam->yaw_goal - cam->yaw_cur);
                xCam_CorrectYaw(cam, ytg, ycv, dt);
            }

            if (!xapproxeq(cam->pitch_cur, cam->pitch_goal))
            {
                float32 ptg = xDangleClamp(cam->pitch_goal - cam->pitch_cur);
                xCam_CorrectPitch(cam, ptg, pcv, dt);
            }

            if (!xapproxeq(cam->roll_cur, cam->roll_goal))
            {
                float32 rtg = xDangleClamp(cam->roll_goal - cam->roll_cur);
                xCam_CorrectRoll(cam, rtg, rcv, dt);
            }

            xMat3x3Euler(&cam->mat, cam->yaw_cur, cam->pitch_cur, cam->roll_cur);
        }
    }
    else
    {
        xQuatFromMat(&cam->orn_cur, &cam->mat);

        xQuat oq;
        xQuatFromMat(&oq, &cam->omat);

        xQuat qdiff_o_c;
        xQuatDiff(&qdiff_o_c, &oq, &cam->orn_cur);

        xRot rot_cv;
        xQuatToAxisAngle(&qdiff_o_c, &rot_cv.axis, &rot_cv.angle);

        rot_cv.angle *= m;
        rot_cv.angle = 0.0f;

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;

        xVec3 f;
        xMat3x3RMulVec(&f, cam->tgt_mat, &cam->focus);
        xVec3AddTo(&f, &cam->tgt_mat->pos);

        float32 atx;
        float32 aty;
        float32 atz;
        float32 dx__ = cam->tgt_mat->pos.x - cam->mat.pos.x;
        float32 dz__ = cam->tgt_mat->pos.z - cam->mat.pos.z;
        float32 dist2 = xsqr(dx__) + xsqr(dz__);

        if (xapproxeq(dist2, 1.0f))
        {
            atx = dx__;
            atz = dz__;
        }
        else if (xapproxeq(dist2, 0.0f))
        {
            atx = 0.0f;
            atz = 0.0f;
        }
        else
        {
            float32 dist_inv = 1.0f / xsqrt(dist2);

            atx = dx__ * dist_inv;
            atz = dz__ * dist_inv;
        }

        aty = 0.0f;

        if (cam->tgt_mat->at.x * atx + cam->tgt_mat->at.y * aty + cam->tgt_mat->at.z * atz < 0.0f)
        {
            float32 mpx;
            float32 mpy;
            float32 mpz;
            float32 s = -2.0f * (((f.x - cam->tgt_mat->pos.x) * atx) + ((f.y - cam->tgt_mat->pos.y) * aty) + ((f.z - cam->tgt_mat->pos.z) * atz));

            mpx = atx * s;
            mpy = aty * s;
            mpz = atz * s;

            f.x += mpx;
            f.y += mpy;
            f.z += mpz;
        }

        xMat3x3 des_mat;
        xMat3x3LookAt(&des_mat, &f, &cam->mat.pos);

        xMat3x3 latgt;
        xMat3x3LookAt(&latgt, &cam->tgt_mat->pos, &cam->mat.pos);

        float32 ang_dist = xacos(latgt.at.x * des_mat.at.x + latgt.at.y * des_mat.at.y + latgt.at.z * des_mat.at.z);

        if (ang_dist > xdeg2rad(30.0f))
        {
            xQuat a;
            xQuatFromMat(&a, &latgt);

            xQuat b;
            xQuatFromMat(&b, &des_mat);

            xQuat o;
            float32 s = PI - ang_dist;

            if (s < PI / 2.0f)
            {
                if (s > xdeg2rad(5.0f))
                {
                    xQuatSlerp(&o, &a, &b, s / ang_dist);
                }
                else
                {
                    o = a;
                }
            }
            else
            {
                xQuatSlerp(&o, &a, &b, xdeg2rad(30.0f) / ang_dist);
            }

            xQuatToMat(&o, &des_mat);
        }

        xQuat desq;
        xQuatFromMat(&desq, &des_mat);

        xCameraLook(cam, 0, &desq, 0.25f, 0.0f, 0.0f);

        xQuat difq;
        xQuatConj(&difq, &cam->orn_cur);
        xQuatMul(&difq, &difq, &desq);

        xQuat newq;
        xQuatSlerp(&newq, &cam->orn_cur, &desq, 25.5f * dt);

        xQuatToMat(&newq, &cam->mat);
    }

    // While loop that runs once (breaks at end). Using if doesn't match here for some reason
    while (xcam_do_collis && sCamCollis)
    {
        xSweptSphere sws;
        xVec3 tgtpos;

        tgtpos.x = cam->tgt_mat->pos.x;
        tgtpos.y = 0.7f + cam->tgt_mat->pos.y;
        tgtpos.z = cam->tgt_mat->pos.z;

        xSweptSpherePrepare(&sws, &tgtpos, &cam->mat.pos, 0.07f);
        xSweptSphereToEnv(&sws, globals.sceneCur->env);

        xRay3 ray;

        xVec3Copy(&ray.origin, &sws.start);
        xVec3Sub(&ray.dir, &sws.end, &sws.start);

        ray.max_t = xVec3Length(&ray.dir);

        float32 one_len = 1.0f / xmax(ray.max_t, EPSILON);

        xVec3SMul(&ray.dir, &ray.dir, one_len);

        ray.flags = XRAY3_UNK0x800;

        if (!(ray.flags & XRAY3_UNK0x400))
        {
            ray.flags |= XRAY3_UNK0x400;
            ray.min_t = 0.0f;
        }

        xRayHitsGrid(&colls_grid, globals.sceneCur, &ray, SweptSphereHitsCameraEnt, &sws.qcd, &sws);
        xRayHitsGrid(&colls_oso_grid, globals.sceneCur, &ray, SweptSphereHitsCameraEnt, &sws.qcd, &sws);

        if (sws.curdist != sws.dist)
        {
            float32 stopdist = xmax(sws.curdist, 0.6f);

            cam->mat.pos.x = ray.origin.x + stopdist * ray.dir.x;
            cam->mat.pos.y = ray.origin.y + stopdist * ray.dir.y;
            cam->mat.pos.z = ray.origin.z + stopdist * ray.dir.z;
        }

        break;
    }

    last_dt = dt;

    iCameraUpdatePos(cam->lo_cam, &cam->mat);
}

void xCameraUpdate(xCamera* cam, float32 dt)
{
    int32 i;
    int32 num_updates = (int32)std::ceilf(144.0f * dt);
    float32 sdt = dt / num_updates;

    for (i = 0; i < num_updates; i++)
    {
        sCamCollis = (i == num_updates - 1);

        _xCameraUpdate(cam, sdt);
    }
}

void xCameraBegin(xCamera* cam, bool32 clear)
{
    iCameraBegin(cam->lo_cam, clear);
    iCameraFrustumPlanes(cam->lo_cam, cam->frustplane);
    iCameraUpdateFog(cam->lo_cam, 0);
}

void xCameraFXBegin(xCamera* cam)
{
    xMat4x3Identity(&sCameraFXMatOld);
    xMat4x3Copy(&sCameraFXMatOld, &cam->mat);
}

static void xCameraFXInit()
{
    memset(sCameraFX, 0, sizeof(sCameraFX));

    for (int32 i = 0; i < CAMERAFX_COUNT; i++)
    {
        sCameraFX[i].flags = 0;
    }
}

cameraFX* xCameraFXAlloc() WIP
{
    for (int32 i = 0; i < 10; i++)
    {
        cameraFX* f = &sCameraFX[i];

        if (f->flags == 0)
        {
            f->flags = CAMERAFX_ACTIVE;
            f->elapsedTime = 0.0f;
            f->maxTime = 0.0f;

            return f;
        }
    }

    return NULL;
}

void xCameraFXZoomUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m) WIP
{
    switch (f->zoom.mode)
    {
    case CAMERAFX_ZOOM_MODE_0:
    {
        f->zoom.velCur += f->zoom.accel * dt;
        f->zoom.distanceCur += f->zoom.velCur * dt;

        if (f->zoom.distanceCur >= f->zoom.distance)
        {
            f->zoom.distanceCur = f->zoom.distance;
            f->zoom.mode = CAMERAFX_ZOOM_MODE_2;
            f->zoom.holdTimeCur = 0.0f;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distanceCur);

        break;
    }
    case CAMERAFX_ZOOM_MODE_2:
    {
        f->zoom.holdTimeCur += dt;

        if (f->zoom.holdTimeCur > f->zoom.holdTime)
        {
            f->zoom.mode = CAMERAFX_ZOOM_MODE_1;
            f->zoom.distanceCur = f->zoom.distance;
            f->zoom.velCur = f->zoom.vel;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distance);

        break;
    }
    case CAMERAFX_ZOOM_MODE_1:
    {
        f->zoom.velCur += f->zoom.accel * dt;
        f->zoom.distanceCur -= f->zoom.velCur * dt;

        if (f->zoom.distanceCur <= 0.0f)
        {
            f->zoom.distanceCur = 0.0f;
            f->zoom.mode = CAMERAFX_ZOOM_MODE_3;
            f->flags |= CAMERAFX_UNK0x2;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distanceCur);

        break;
    }
    case CAMERAFX_ZOOM_MODE_3:
    {
        break;
    }
    }
}

void xCameraFXShake(float32 maxTime, float32 magnitude, float32 cycleMax, float32 rotate_magnitude, float32 radius, xVec3* epicenter, xVec3* player) WIP
{
    cameraFX* f = xCameraFXAlloc();

    if (!f)
    {
        return;
    }

    f->type = CAMERAFX_TYPE_SHAKE;
    f->maxTime = maxTime;
    f->shake.magnitude = magnitude;
    f->shake.dir.x = 1.0f;
    f->shake.dir.y = 1.0f;
    f->shake.cycleMax = cycleMax;
    f->shake.cycleTime = 0.0f;
    f->shake.dampen = 0.0f;
    f->shake.dampenRate = 1.0f / maxTime;
    f->shake.rotate_magnitude = rotate_magnitude;
    f->shake.radius = radius;
    f->shake.epicenterP = epicenter;

    if (f->shake.epicenterP)
    {
        f->shake.epicenter = *f->shake.epicenterP;
    }

    f->shake.player = player;
}

void xCameraFXShakeUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m)
{
    float32 x;
    float32 y;
    float32 scale;
    float32 noise;

    f->shake.cycleTime += dt;

    while (f->shake.cycleTime > f->shake.cycleMax)
    {
        f->shake.dir.x = -f->shake.dir.x;
        f->shake.dir.y = -f->shake.dir.y;
        f->shake.cycleTime -= f->shake.cycleMax;
    }

    scale = (f->maxTime - f->elapsedTime) * f->shake.dampenRate;
    noise = (xurand() - 0.5f) * 0.1f;

    if (f->shake.radius > 0.0f && f->shake.player)
    {
        xVec3 dpos;
        xVec3Sub(&dpos, f->shake.player, &f->shake.epicenter);

        float32 dist = dpos.length();

        if (dist > f->shake.radius)
        {
            scale = 0.0f;
        }
        else
        {
            scale *= icos(dist / f->shake.radius * PI * 0.5f);
        }
    }

    x = (f->shake.magnitude + noise) * f->shake.dir.x * scale / f->shake.cycleMax * f->shake.cycleTime * isin(f->shake.cycleTime / f->shake.cycleMax * PI);
    noise = (xurand() - 0.5f) * 0.1f;
    y = (f->shake.magnitude + noise) * f->shake.dir.y * scale / f->shake.cycleMax * f->shake.cycleTime * isin(f->shake.cycleTime / f->shake.cycleMax * PI);

    xMat4x3MoveLocalRight(m, x);
    xMat4x3MoveLocalUp(m, y);

    xVec3 e;
    xMat3x3GetEuler(m, &e);

    e.z += f->shake.cycleTime / f->shake.cycleMax * xrad2deg(1.0f / 90.0f) * 0.1f * scale * f->shake.rotate_magnitude;

    xMat3x3Euler(m, &e);
}

void xCameraFXUpdate(xCamera* cam, float32 dt) WIP
{
    for (int32 i = 0; i < CAMERAFX_COUNT; i++)
    {
        cameraFX* f = &sCameraFX[i];

        if (f->flags & CAMERAFX_ACTIVE)
        {
            f->elapsedTime += dt;

            if (f->maxTime > 0.0f && (f->elapsedTime > 0.0f || f->flags & CAMERAFX_UNK0x2))
            {
                f->flags = 0;

                if (sCameraFXTable[f->type].funcKill)
                {
                    sCameraFXTable[f->type].funcKill(f);
                }
            }
            else if (sCameraFXTable[f->type].func)
            {
                sCameraFXTable[f->type].func(f, dt, &sCameraFXMatOld, &cam->mat);
            }
        }
    }

    iCameraUpdatePos(cam->lo_cam, &cam->mat);
}

void xCameraFXEnd(xCamera* cam)
{
    xMat4x3Copy(&cam->mat, &sCameraFXMatOld);
    iCameraUpdatePos(cam->lo_cam, &sCameraFXMatOld);
}

void xCameraEnd(xCamera* cam, float32 seconds, bool32 update_scrn_fx)
{
    if (update_scrn_fx)
    {
        xScrFxUpdate(cam->lo_cam, seconds);
    }

    iCameraEnd(cam->lo_cam);
}

void xCameraShowRaster(xCamera* cam)
{
    iCameraShowRaster(cam->lo_cam);
}

void xCameraSetScene(xCamera* cam, xScene* sc)
{
    cam->sc = sc;

    iCameraAssignEnv(cam->lo_cam, sc->env->geom);
}

void xCameraSetTargetMatrix(xCamera* cam, xMat4x3* mat)
{
    cam->tgt_mat = mat;
}

void xCameraSetTargetOMatrix(xCamera* cam, xMat4x3* mat)
{
    cam->tgt_omat = mat;
}

void xCameraDoCollisions(bool32 do_collis, int32 owner)
{
    xcam_collis_owner_disable &= ~(1 << owner);
    xcam_collis_owner_disable |= (int32)!do_collis << owner;
    xcam_do_collis = (xcam_collis_owner_disable == 0);
}

void xCameraMove(xCamera* cam, uint32 flags, float32 dgoal, float32 hgoal, float32 pgoal, float32 tm, float32 tm_acc, float32 tm_dec) WIP
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0x3E) | (flags & XCAMERA_UNKMASK0x3E);
    cam->dgoal = dgoal;
    cam->hgoal = hgoal;
    cam->pgoal = pgoal;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        cam->dcur = dgoal;
        cam->hcur = hgoal;
        cam->pcur = pgoal;

        xCam_cyltoworld(&cam->mat.pos, cam->tgt_mat, dgoal, hgoal, pgoal, cam->flags);

        cam->omat.pos = cam->mat.pos;
        cam->yaw_cur = cam->yaw_goal = cam->pcur + (cam->pcur >= PI ? -PI : PI);
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x1;
        cam->tm_acc = tm - tm_acc;
        cam->tm_dec = tm_dec;
        cam->tmr = tm;

        float32 s = 1.0f / (tm - 0.5f * (tm_acc - tm_dec));

        cam->depv = (dgoal - cam->dcur) * s;
        cam->hepv = (hgoal - cam->hcur) * s;
        cam->pepv = xDangleClamp(pgoal - cam->pcur) * s * 0.5f * (dgoal + cam->dcur);
    }
}

void xCameraMove(xCamera* cam, const xVec3& loc)
{
    cam->omat.pos = cam->mat.pos = loc;
    cam->flags &= ~XCAMERA_UNKMASK0x3E;
    cam->tm_acc = cam->tm_dec = cam->tmr = 0.0f;
}

void xCameraMove(xCamera* cam, const xVec3& loc, float32 maxSpeed) WIP
{
    xVec3 dpos;
    xVec3Sub(&dpos, &loc, &cam->mat.pos);

    float32 dist = xVec3Length(&dpos);

    if (dist > maxSpeed)
    {
        xVec3SMul(&dpos, &dpos, maxSpeed / dist);
        xVec3Add(&cam->mat.pos, &cam->mat.pos, &dpos);
    }
    else
    {
        cam->mat.pos = loc;
    }

    cam->omat.pos = cam->mat.pos;
    cam->flags &= ~XCAMERA_UNKMASK0x3E;
    cam->tm_acc = cam->tm_dec = cam->tmr = 0.0f;
}

void xCameraFOV(xCamera* cam, float32 fov, float32 maxSpeed, float32 dt) WIP
{
    float32 speed = maxSpeed * dt;
    float32 currentFOV = xCameraGetFOV(cam);

    if (currentFOV == fov)
    {
        return;
    }

    if (speed != 0.0f)
    {
        float32 len = fov - currentFOV;

        if (xabs(len) > speed)
        {
            len *= speed / len;

            xCameraSetFOV(cam, currentFOV + len);
        }
        else
        {
            xCameraSetFOV(cam, fov);
        }
    }
    else
    {
        xCameraSetFOV(cam, fov);
    }
}

void xCameraLook(xCamera* cam, uint32 flags, const xQuat* orn_goal, float32 tm, float32 tm_acc, float32 tm_dec)
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0xF80) | (flags & XCAMERA_UNKMASK0xF80);
    cam->orn_goal = *orn_goal;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        xQuatToMat(orn_goal, &cam->mat);

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x40;
        cam->ltm_acc = tm - tm_acc;
        cam->ltm_dec = tm_dec;
        cam->ltmr = tm;

        xQuatDiff(&cam->orn_diff, &cam->orn_cur, orn_goal);

        float32 s = 1.0f / (tm - (tm_acc - tm_dec) * 0.5f);

        cam->orn_epv = s * xQuatGetAngle(&cam->orn_diff);
    }
}

void xCameraLookYPR(xCamera* cam, uint32 flags, float32 yaw, float32 pitch, float32 roll, float32 tm, float32 tm_acc, float32 tm_dec) WIP
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0xF80) | (flags & XCAMERA_UNKMASK0xF80) | XCAMERA_UNK0x80;
    cam->yaw_goal = yaw;
    cam->pitch_goal = pitch;
    cam->roll_goal = roll;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        cam->yaw_cur = yaw;
        cam->pitch_cur = pitch;
        cam->roll_cur = roll;

        xMat3x3Euler(&cam->mat, yaw, pitch, roll);

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x40;
        cam->ltm_acc = tm - tm_acc;
        cam->ltm_dec = tm_dec;
        cam->ltmr = tm;

        float32 s = 1.0f / (tm - (0.5f * (tm_acc - tm_dec)));

        cam->yaw_epv = s * xDangleClamp(yaw - cam->yaw_cur);
        cam->pitch_epv = s * xDangleClamp(pitch - cam->pitch_cur);
        cam->roll_epv = s * xDangleClamp(roll - cam->roll_cur);
    }
}

void xCameraRotate(xCamera* cam, const xMat3x3& m, float32 time, float32 accel, float32 decl) WIP
{
    cam->flags = cam->flags & ~XCAMERA_UNKMASK0xF80 | XCAMERA_UNK0x80;

    xVec3 eu;
    xMat3x3GetEuler(&m, &eu);

    cam->yaw_goal = eu.x;
    cam->pitch_goal = eu.y;
    cam->roll_goal = eu.z;

    if (time == 0.0f)
    {
        cam->yaw_cur = eu.x;
        cam->pitch_cur = eu.y;
        cam->roll_cur = eu.z;
    }

    *(xMat3x3*)&cam->mat = m;

    if (time == 0.0f)
    {
        *(xMat3x3*)&cam->omat = m;
    }

    if (time == 0.0f)
    {
        cam->ltm_acc = cam->ltm_dec = cam->ltmr = 0.0f;
    }
    else
    {
        cam->ltm_acc = accel;
        cam->ltm_dec = decl;
        cam->ltmr = time;
    }

    cam->yaw_epv = cam->pitch_epv = cam->roll_epv = 0.0f;
}

void xCameraRotate(xCamera* cam, const xVec3& v, float32 roll, float32 time, float32 accel, float32 decl) WIP
{
    cam->yaw_goal = xatan2(v.x, v.z);
    cam->pitch_goal = -xasin(v.y);
    cam->roll_goal = roll;

    if (time == 0.0f)
    {
        cam->yaw_cur = cam->yaw_goal;
        cam->pitch_cur = cam->pitch_goal;
        cam->roll_cur = cam->roll_goal;
    }

    cam->flags = cam->flags & ~XCAMERA_UNKMASK0xF80 | XCAMERA_UNK0x80;

    xMat3x3Euler(&cam->mat, cam->yaw_goal, cam->pitch_goal, cam->roll_goal);

    if (time == 0.0f)
    {
        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }

    if (time == 0.0f)
    {
        cam->ltm_acc = cam->ltm_dec = cam->ltmr = 0.0f;
    }
    else
    {
        cam->ltm_acc = accel;
        cam->ltm_dec = decl;
        cam->ltmr = time;
    }

    cam->yaw_epv = cam->pitch_epv = cam->roll_epv = 0.0f;
}

static void bound_sphere_xz(xVec3& r3, xVec3& r4, const xVec3& r5, float32 f1, const xVec3& r6, float32 f2)
{
    float32 f31 = f1 / f2;
    float32 f3 = f31 * xsqrt(xsqr(f2) - xsqr(f1));
    float32 f5_0 = f1 * f31;
    float32 f6 = f3 * r6.x;
    float32 f4 = f3 * r6.z;
    float32 f8 = f5_0 * r6.x;
    float32 f5_1 = f5_0 * r6.z;

    r3.x = r5.x + f4 + f8;
    r3.y = r5.y;
    r3.z = r5.z - f6 + f5_1;

    r4.x = r5.x - f4 + f8;
    r4.y = r5.y;
    r4.z = r5.z + f6 + f5_1;
}

void xBinaryCamera::init()
{
    camera = NULL;
    s1 = s2 = NULL;
}

void xBinaryCamera::start(xCamera& camera)
{
    this->camera = &camera;

    xQuatFromMat(&cam_dir, &camera.mat);

    stick_offset = 0.0f;
}

void xBinaryCamera::stop()
{
    camera = NULL;
}

void xBinaryCamera::update(float32 dt) WIP
{
    xVec3& A = camera->mat.pos;
    xVec3& B = *s1;
    xVec3& C = *s2;

    xVec3 CA = {};
    CA.x = A.x - C.x;
    CA.z = A.z - C.z;

    float32 dCA = CA.length();

    if (dCA < 0.01f)
    {
        CA.assign(A.x - B.x, 0.0f, A.z - B.z).right_normalize();
        dCA = 0.01f;
    }
    else
    {
        CA /= dCA;
    }

    float32 yaw_start = xatan2(B.x - A.x, B.z - A.z);
    float32 yaw_end;

    if (dCA > s2_radius)
    {
        xVec3 Q1;
        xVec3 Q2;

        bound_sphere_xz(Q1, Q2, C, s2_radius, CA, dCA);

        float32 yaw_Q1 = xatan2(Q1.x - A.x, Q1.z - A.z);
        float32 yaw_Q2 = xatan2(Q2.x - A.x, Q2.z - A.z);
        float32 dyaw1 = xrmod(yaw_Q1 - yaw_start + PI) - PI;
        float32 dyaw2 = xrmod(yaw_Q2 - yaw_start + PI) - PI;
        float32 fov = xdeg2rad(1.0f) * xCameraGetFOV(camera);
        float32 max_dyaw = range_limit(0.5f * fov + cfg.margin_angle, 0.0f, PI);

        if (0.5f * xabs(dyaw2 - dyaw1) > max_dyaw)
        {
            yaw_end = xatan2(C.x - B.x, C.z - B.z);
        }
        else if (dyaw1 >= dyaw2)
        {
            yaw_end = xatan2(C.x - B.x, C.z - B.z);
        }
        else if (dyaw1 >= -max_dyaw)
        {
            if (dyaw2 <= max_dyaw)
            {
                yaw_end = yaw_start;
            }
            else
            {
                yaw_end = dyaw2 - max_dyaw + yaw_start;
            }
        }
        else
        {
            yaw_end = dyaw1 + max_dyaw + yaw_start;
        }
    }
    else
    {
        yaw_end = xatan2(C.x - B.x, C.z - B.z);
    }

    float32 sstick = 1.0f - xexp(-cfg.stick_speed * dt);
    xPad::analog_data& stick = globals.pad0->analog[1];

    stick_offset.x += (cfg.stick_yaw_vel * stick.offset.x * dt - stick_offset.x) * sstick;

    yaw_end += stick_offset.x;

    float32 yaw_diff = xrmod(yaw_end - yaw_start + PI) - PI;
    float32 max_yaw_diff = cfg.max_yaw_vel * dt;

    if (xabs(yaw_diff) > max_yaw_diff)
    {
        if (yaw_diff < 0.0f)
        {
            if (max_yaw_diff > 0.0f)
            {
                max_yaw_diff = -max_yaw_diff;
            }
        }
        else
        {
            if (max_yaw_diff < 0.0f)
            {
                max_yaw_diff = -max_yaw_diff;
            }
        }

        yaw_end = yaw_start + max_yaw_diff;
    }

    stick_offset.y += (stick.offset.y - stick_offset.y) * sstick;

    float32 d;
    float32 h;
    float32 hf;

    if (stick_offset.y > 0.0f)
    {
        float32 s = stick_offset.y;

        d = (cfg.zone_below.distance - cfg.zone_rest.distance) * s + cfg.zone_rest.distance;
        h = (cfg.zone_below.height - cfg.zone_rest.height) * s + cfg.zone_rest.height;
        hf = (cfg.zone_below.height_focus - cfg.zone_rest.height_focus) * s + cfg.zone_rest.height_focus;
    }
    else
    {
        float32 s = -stick_offset.y;

        d = (cfg.zone_above.distance - cfg.zone_rest.distance) * s + cfg.zone_rest.distance;
        h = (cfg.zone_above.height - cfg.zone_rest.height) * s + cfg.zone_rest.height;
        hf = (cfg.zone_above.height_focus - cfg.zone_rest.height_focus) * s + cfg.zone_rest.height_focus;
    }

    xVec3 end_loc = {};
    end_loc.x = B.x - d * isin(yaw_end);
    end_loc.y = B.y + h;
    end_loc.z = B.z - d * icos(yaw_end);

    float32 sloc = 1.0f - xexp(-cfg.move_speed * dt);

    xVec3 cam_loc = {};
    xVec3 heading = {};

    heading.x = B.x - end_loc.x;
    cam_loc.x = (end_loc.x - A.x) * sloc + A.x;

    cam_loc.y = (end_loc.y - A.y) * sloc + A.y;
    heading.y = B.y - end_loc.y + hf;

    cam_loc.z = (end_loc.z - A.z) * sloc + A.z;
    heading.z = B.z - end_loc.z;

    float32 heading_dist2 = heading.length2();

    if (heading_dist2 >= 0.001f)
    {
        xQuat end_dir;
        xMat3x3 mat;

        heading /= xsqrt(heading_dist2);

        xMat3x3LookVec(&mat, &heading.invert());
        xQuatFromMat(&end_dir, &mat);

        float32 sdir = 1.0f - xexp(-cfg.turn_speed * dt);
        xQuatSlerp(&cam_dir, &cam_dir, &end_dir, sdir);
    }

    xMat3x3 mat;
    xQuatToMat(&cam_dir, &mat);

    xCameraMove(camera, cam_loc);
    xCameraRotate(camera, mat, 0.0f, 0.0f, 0.0f);

    render_debug();
}