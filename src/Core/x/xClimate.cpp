#include "xClimate.h"

#include "zParEmitter.h"
#include "xString.h"
#include "zEnv.h"
#include "zMain.h"
#include "zParPTank.h"

static Climate* sClimate = NULL;

static float32 snow_life = 3.0f;
static const xVec3 snow_vel = { 0.0f, -2.0f, 0.0f };
static const xVec3 snow_dvel = { 0.1f, 0.1f, 0.1f };

static void xClimateVecFromAngle(float32 angle, xVec3* v)
{
    xMat3x3 mat;
    xMat3x3Identity(&mat);
    xMat3x3Euler(&mat, xdeg2rad(angle), 0.0f, 0.0f);

    xVec3Init(v, 0.0f, 0.0f, 1.0f);
    xMat3x3LMulVec(v, &mat, v);
}

void xClimateInit(Climate* climate) WIP
{
    climate->rain.strength = 0.0f;

    climate->rain.rain_emitter = zParEmitterFind(xStrHash("PAREMIT_RAIN"));
    climate->rain.rain_emitter->emit_flags &= ~XPAREMITTER_UNK0x1;

    climate->rain.snow_emitter = zParEmitterFind(xStrHash("PAREMIT_SNOW"));
    climate->rain.snow_emitter->emit_flags &= ~XPAREMITTER_UNK0x1;
}

void xClimateInitAsset(Climate* climate, xEnvAsset* easset) WIP
{
    sClimate = climate;

    Wind* w = &climate->wind;

    w->strength = 0.0f;

    xClimateVecFromAngle(w->angle, &w->dir);

    if (easset->climateFlags == 0)
    {
        climate->wind.strength = 0.0f;
        climate->rain.strength = 0.0f;
    }
    else if (easset->climateFlags & XENVASSET_CLIMATE_UNK0x1)
    {
        climate->rain.rain = TRUE;
        climate->rain.strength = 0.5f * (easset->climateStrengthMax - easset->climateStrengthMin);
        climate->rain.strength += easset->climateStrengthMin;
    }
    else if (easset->climateFlags & XENVASSET_CLIMATE_UNK0x2)
    {
        climate->rain.rain = FALSE;
        climate->rain.strength = 0.5f * (easset->climateStrengthMax - easset->climateStrengthMin);
        climate->rain.strength += easset->climateStrengthMin;
    }
}

void xClimateSetSnow(float32 stre)
{
    sClimate->rain.rain = FALSE;
    sClimate->rain.strength = stre;
}

void xClimateSetRain(float32 stre)
{
    sClimate->rain.rain = TRUE;
    sClimate->rain.strength = stre;
}

static void GetPosBigDogWhattupFool(xVec3* pos) WIP
{
    xMat4x3* mat = &xglobals->camera.mat;

    pos->x = 10.0f * mat->at.x + mat->pos.x;
    pos->y = 10.0f * mat->at.y + mat->pos.y;
    pos->z = 10.0f * mat->at.z + mat->pos.z;
}

static void UpdateRain(Climate* climate, float32 seconds) WIP
{
    Rain* r = &climate->rain;
    xParEmitterCustomSettings info;

    memset(&info, 0, sizeof(xParEmitterCustomSettings));

    info.custom_flags = XPAREMITTER_CUSTOM_UNK0x100;

    if (r->rain)
    {
        int32 total_rain_drops = (int32)(25.0f * r->strength);

        for (int32 i = 0; i < total_rain_drops; i++)
        {
            GetPosBigDogWhattupFool(&info.pos);

            info.pos.x += 25.0f * xurand() - 12.5f;
            info.pos.y += 8.0f;
            info.pos.z += 25.0f * xurand() - 12.5f;

            xParEmitterEmitCustom(r->rain_emitter, seconds, &info);
        }
    }
    else
    {
        info.custom_flags |= XPAREMITTER_CUSTOM_UNK0x2 | XPAREMITTER_CUSTOM_UNK0x200;

        int32 total_snow_flakes = (int32)(25.0f * r->strength);

        xVec3 p;
        GetPosBigDogWhattupFool(&p);

        if (gPTankDisable)
        {
            for (int32 i = 0; i < total_snow_flakes; i++)
            {
                info.pos = p;
                info.pos.x += 45.0f * xurand() - 22.5f;
                info.pos.z += 45.0f * xurand() - 22.5f - p.z;

                float32 perc = 1.0f - (info.pos.x - p.x) * (info.pos.z - p.z) / 506.25f;

                info.vel.x = snow_dvel.x * xurand() + snow_vel.x;
                info.vel.y = snow_dvel.y * xurand() + snow_vel.y;
                info.vel.z = snow_dvel.z * xurand() + snow_vel.z;

                info.pos.y += 4.0f * perc + 4.0f;
                info.life.val[0] = snow_life * perc + snow_life;

                xParEmitterEmitCustom(r->snow_emitter, seconds, &info);
            }
        }
        else
        {
            int32 num = (int32)(0.1f * total_snow_flakes);

            if (num > 0)
            {
                xVec3* pos = (xVec3*)xMemPushTemp(num * 2 * sizeof(xVec3));
                xVec3* vel = pos + num;

                if (pos)
                {
                    xVec3* pp = pos;
                    xVec3* vp = vel;

                    for (int32 i = 0; i < num; i++)
                    {
                        pp->x += 45.0f * xurand() - 22.5f;
                        pp->z += 45.0f * xurand() - 22.5f;

                        float32 xx = pp->x - p.x;
                        float32 zz = pp->z - p.z;
                        float32 perc = 1.0f - (xsqr(xx) + xsqr(zz)) / 506.25f;

                        pp->y += 4.0f * perc;

                        vp->x = snow_dvel.x * xurand() + snow_vel.x;
                        vp->y = snow_dvel.y * xurand() + snow_vel.y;
                        vp->z = snow_dvel.z * xurand() + snow_vel.z;

                        pp++;
                        vp++;
                    }

                    zParPTankSpawnSnow(pos, vel, num);
                    xMemPopTemp(pos);
                }
            }
        }
    }
}

static void UpdateWind(Climate*, float32) {}

void xClimateUpdate(Climate* climate, float32 seconds)
{
    UpdateRain(climate, seconds);
    UpdateWind(climate, seconds);
}