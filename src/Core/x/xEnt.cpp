#include "xEnt.h"

#include "xMemMgr.h"
#include "xEvent.h"
#include "zBase.h"
#include "zPlatform.h"
#include "xString.h"
#include "iMath3.h"
#include "xScene.h"
#include "zEntDestructObj.h"
#include "xSurface.h"
#include "zCollGeom.h"
#include "iCollide.h"
#include "xserializer.h"
#include "zSurface.h"
#include "xGroup.h"
#include "zScene.h"
#include "xstransvc.h"
#include "xFX.h"
#include "zLight.h"
#include "xShadow.h"
#include "xFFX.h"
#include "zGrid.h"

#include <float.h>

static float32 sEntityTimePassed;
static xBox all_ents_box;
static bool32 all_ents_box_init;
static bool32 setMaterialTextureRestore;
int32 sSetPipeline;
static RxPipeline* oldPipe;
bool32 xent_entent;

namespace {

	namespace anim_coll {

		void reset(xEnt& ent)
		{
            if (!ent.anim_coll)
            {
                ent.anim_coll = (xEnt::anim_coll_data*)xMEMALLOC(sizeof(xEnt::anim_coll_data));
                ent.anim_coll->flags = 0;
                ent.anim_coll->verts = NULL;
            }

            xModelInstance& model = *ent.model;
            xMat4x3& mat = *(xMat4x3*)model.Mat;
            xEnt::anim_coll_data& ac = *ent.anim_coll;

            if (ac.flags & XENT_ANIMCOLL_UNK0x8)
            {
                return;
            }

            switch (model.BoneCount)
            {
            case 0:
            {
                break;
            }
            case 1:
            {
                ac.flags |= XENT_ANIMCOLL_UNK0x1;
                ac.old_mat = mat;
                ac.new_mat = g_I3;
                break;
            }
            default:
            {
                ac.flags |= XENT_ANIMCOLL_UNK0x2;
                ac.old_mat = mat;
                ac.new_mat = g_I3;

                xModelAnimCollStart(model);

                xBox& box = ent.bound.box.box;
                xVec3 size = box.upper - box.lower;
                float32 max_size = size.x;

                if (max_size < size.y)
                {
                    max_size = size.y;
                }

                if (max_size < size.z)
                {
                    max_size = size.z;
                }

                max_size += 1.0f;

                box.upper += max_size;
                box.lower -= max_size;

                model.Data->boundingSphere.radius *= 3.0f;

                break;
            }
            }
		}

        void refresh(xEnt& ent)
        {
            xEnt::anim_coll_data& ac = *ent.anim_coll;
            xMat4x3& bone_mat = *((xMat4x3*)ent.model->Mat + 1);

            xMat4x3Mul((xMat4x3*)ent.model->Mat, &bone_mat, &ac.old_mat);

            ac.new_mat = bone_mat;
            bone_mat = g_I3;
        }

        inline void pre_move(xEnt& ent)
        {
            xMat4x3& mat = *(xMat4x3*)ent.model->Mat;
            xEnt::anim_coll_data& ac = *ent.anim_coll;

            ent.frame->mat = mat = ac.old_mat;
        }

        inline void post_move(xEnt& ent)
        {
            xMat4x3& mat = *(xMat4x3*)ent.model->Mat;
            xEnt::anim_coll_data& ac = *ent.anim_coll;

            ac.old_mat = ent.frame->mat;

            xMat4x3Mul(&mat, &ac.new_mat, &ac.old_mat);

            ent.frame->mat = mat;
        }

	}

}

void xEntSetTimePassed(float32 sec)
{
    sEntityTimePassed = sec;
}

void xEntSceneInit()
{
    all_ents_box_init = TRUE;
}

void xEntSceneExit()
{
}

static void xEntAddHittableFlag(xEnt* ent)
{
    if (ent->baseType == eBaseTypeNPC ||
        ent->baseType == eBaseTypeDestructObj ||
        ent->baseType == eBaseTypeButton ||
        ent->baseType == eBaseTypeBoulder ||
        (ent->baseType == eBaseTypePlatform && ent->subType == ZPLATFORM_PADDLE))
    {
        ent->moreFlags |= XENT_MORE_HITTABLE;
    }
    else
    {
        for (uint32 i = 0; i < ent->linkCount; i++)
        {
            if (ent->link[i].srcEvent == eEventHit ||
                ent->link[i].srcEvent == eEventHit_Cruise ||
                ent->link[i].srcEvent == eEventHit_Melee ||
                ent->link[i].srcEvent == eEventHit_BubbleBounce ||
                ent->link[i].srcEvent == eEventHit_BubbleBash ||
                ent->link[i].srcEvent == eEventHit_BubbleBowl ||
                ent->link[i].srcEvent == eEventHit_PatrickSlam ||
                ent->link[i].srcEvent == eEventHit_Throw ||
                ent->link[i].srcEvent == eEventHit_PaddleLeft ||
                ent->link[i].srcEvent == eEventHit_PaddleRight)
            {
                ent->moreFlags |= XENT_MORE_HITTABLE;
                break;
            }
        }
    }
}

static void hack_receive_shadow(xEnt* ent) WIP
{
    static const uint32 receive_models[] =
    {
        xStrHash("db03_path_a"),
        xStrHash("db03_path_b"),
        xStrHash("db03_path_c"),
        xStrHash("db03_path_d"),
        xStrHash("db03_path_e"),
        xStrHash("db03_path_f"),
        xStrHash("db03_path_g"),
        xStrHash("db03_path_h"),
        xStrHash("db03_path_i"),
        xStrHash("db03_path_j"),
        xStrHash("db03_path_k"),
        xStrHash("db03_path_l"),
        xStrHash("db03_path_m"),
        xStrHash("db03_path_o"),
        xStrHash("db03_path_p")
    };

    const uint32* end = receive_models + sizeof(receive_models) / sizeof(receive_models[0]);
    const uint32* cur = receive_models;

    while (cur != end)
    {
        if (ent->asset->modelInfoID == *cur)
        {
            ent->baseFlags |= XBASE_RECSHADOW;
            ent->asset->baseFlags |= XBASE_RECSHADOW;
            break;
        }

        cur++;
    }
}

static void xEntAddShadowRecFlag(xEnt* ent)
{
    switch (ent->baseType)
    {
    case eBaseTypePlatform:
    case eBaseTypeStatic:
    case eBaseTypeButton:
    case eBaseTypeDestructObj:
    case eBaseTypeNPC:
    case eBaseTypeBoulder:
    {
        if (ent->model->PipeFlags & XMODELPIPE_BLENDMASK)
        {
            ent->baseFlags &= (uint16)~XBASE_RECSHADOW;
        }

        break;
    }
    case eBaseTypeCamera:
    case eBaseTypeDoor:
    case eBaseTypeSavePoint:
    case eBaseTypeItem:
    case eBaseTypeDynamic:
    case eBaseTypeMovePoint:
    case eBaseTypeTimer:
    case eBaseTypeBubble:
    case eBaseTypePortal:
    case eBaseTypeGroup:
    case eBaseTypePendulum:
    case eBaseTypeSFX:
    case eBaseTypeFFX:
    case eBaseTypeVFX:
    case eBaseTypeCounter:
    case eBaseTypeHangable:
    case eBaseTypeProjectile:
    case eBaseTypeSurface:
    case eBaseTypeGust:
    case eBaseTypeVolume:
    case eBaseTypeDispatcher:
    case eBaseTypeCond:
    case eBaseTypeUI:
    case eBaseTypeUIFont:
    case eBaseTypeProjectileType:
    case eBaseTypeLobMaster:
    case eBaseTypeFog:
    case eBaseTypeLight:
    case eBaseTypeParticleEmitter:
    case eBaseTypeParticleSystem:
    case eBaseTypeCutsceneMgr:
    case eBaseTypeEGenerator:
    case eBaseTypeScript:
    case eBaseTypeHud:
    case eBaseTypeNPCProps:
    case eBaseTypeParticleEmitterProps:
    default:
    {
        ent->baseFlags &= (uint16)~XBASE_RECSHADOW;
        break;
    }
    }

    hack_receive_shadow(ent);
}

void xEntInit(xEnt* ent, xEntAsset* asset) WIP
{
    xBaseInit(ent, asset);

    ent->asset = asset;
    ent->update = xEntUpdate;
    ent->bupdate = xEntDefaultBoundUpdate;
    ent->render = xEntRender;
    ent->move = NULL;
    ent->transl = xEntDefaultTranslate;
    ent->flags = asset->flags;
    ent->miscflags = 0;
    ent->moreFlags = asset->moreFlags;
    ent->subType = asset->subtype;
    ent->pflags = asset->pflags;
    ent->ffx = NULL;
    ent->num_ffx = 0;
    ent->driver = NULL;
    ent->model = NULL;
    ent->collModel = NULL;
    ent->camcollModel = NULL;
    ent->frame = NULL;
    ent->collis = NULL;
    ent->lightKit = NULL;
    ent->simpShadow = NULL;
    ent->entShadow = NULL;
    ent->baseFlags |= XBASE_UNK0x20;

    xGridBoundInit(&ent->gridb, ent);

    ent->anim_coll = NULL;

    if (all_ents_box_init)
    {
        iBoxInitBoundVec(&all_ents_box, &asset->pos);

        all_ents_box_init = FALSE;
    }
    else
    {
        iBoxBoundVec(&all_ents_box, &all_ents_box, &asset->pos);
    }
}

void xEntInitForType(xEnt* ent) WIP
{
    ent->update = xEntUpdate;
    ent->render = xEntRender;

    if (ent->collType == XENT_COLLTYPE_TRIG)
    {
        ent->pflags &= ~(XENT_PHYSICS_UNK0x1 | XENT_PHYSICS_UNK0x2);
        ent->chkby = XENT_COLLTYPE_PLYR | XENT_COLLTYPE_NPC;
        ent->penby = 0;
    }
    else if (ent->collType == XENT_COLLTYPE_STAT)
    {
        ent->pflags &= ~(XENT_PHYSICS_UNK0x1 | XENT_PHYSICS_UNK0x2);
        ent->chkby = XENT_COLLTYPE_PLYR | XENT_COLLTYPE_NPC;
        ent->penby = XENT_COLLTYPE_PLYR | XENT_COLLTYPE_NPC;
    }
    else if (ent->collType == XENT_COLLTYPE_DYN)
    {
        ent->pflags |= XENT_PHYSICS_UNK0x1;
        ent->move = NULL;
        ent->frame = (xEntFrame*)xMEMALLOC(sizeof(xEntFrame));

        memset(ent->frame, 0, sizeof(xEntFrame));

        ent->pflags &= (uint8)~XENT_PHYSICS_UNK0x2;
        ent->chkby = XENT_COLLTYPE_PLYR | XENT_COLLTYPE_NPC;
        ent->penby = XENT_COLLTYPE_PLYR | XENT_COLLTYPE_NPC;
    }
    else if (ent->collType == XENT_COLLTYPE_NPC)
    {
        ent->pflags |= XENT_PHYSICS_UNK0x1;
        ent->move = NULL;
        ent->pflags |= XENT_PHYSICS_UNK0x2;
        ent->chkby = XENT_COLLTYPE_PLYR;
        ent->penby = XENT_COLLTYPE_PLYR;
    }
    else if (ent->collType == XENT_COLLTYPE_PLYR)
    {
        ent->pflags |= XENT_PHYSICS_UNK0x1;
        ent->move = NULL;
        ent->frame = (xEntFrame*)xMEMALLOC(sizeof(xEntFrame));

        memset(ent->frame, 0, sizeof(xEntFrame));

        ent->pflags |= XENT_PHYSICS_UNK0x2;
        ent->chkby = 0;
        ent->penby = 0;
        ent->collis = (xEntCollis*)xMEMALLOC(sizeof(xEntCollis));
        ent->collis->chk = XENTCOLLIS_UNK0x1 | XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4 | XENTCOLLIS_UNK0x8 | XENTCOLLIS_UNK0x20;
        ent->collis->pen = XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4 | XENTCOLLIS_UNK0x8 | XENTCOLLIS_UNK0x20;
        ent->collis->post = NULL;
        ent->collis->depenq = NULL;
    }

    if (((ent->moreFlags & XENT_MORE_ANIMCOLL) || (ent->flags & XENT_STACKABLE)) && !ent->frame)
    {
        ent->frame = (xEntFrame*)xMEMALLOC(sizeof(xEntFrame));

        memset(ent->frame, 0, sizeof(xEntFrame));
    }

    ent->baseFlags |= XBASE_UNK0x20;
}

namespace {

    float32 get_lower_extent(const xBound& bound)
    {
        switch (bound.type)
        {
        case XBOUND_SPH:
        {
            return bound.sph.r;
        }
        case XBOUND_BOX:
        {
            return bound.box.center.y - bound.box.box.lower.y;
        }
        case XBOUND_OBB:
        {
            if (bound.mat->up.x == 0.0f && bound.mat->up.z == 0.0f)
            {
                return bound.box.center.y - (bound.mat->up.y * bound.box.box.lower.y + bound.mat->pos.y);
            }
            else
            {
                xBox box;
                xBoundGetBox(box, bound);
                return bound.box.center.y - box.lower.y;
            }
        }
        default:
        {
            return 0.0f;
        }
        }
    }

    bool collide_downward(xVec3& loc, xEnt*& hit, xScene& s, xEnt& ent, float32 max_dist) WIP
    {
        xRay3 ray;
        uint8 old_bound_type;
        float32 old_bound_radius;
        xCollis coll;
        float32 f31 = get_lower_extent(ent.bound);
        xVec3* r30 = xBoundCenter(&ent.bound);

        ray.origin = *r30;
        ray.dir.assign(0.0f, -1.0f, 0.0f);
        ray.min_t = 0.0f;
        ray.max_t = max_dist + f31;
        ray.flags = XRAY3_UNK0x400 | XRAY3_UNK0x800;

        old_bound_type = ent.bound.type;
        old_bound_radius = ent.bound.sph.r;

        ent.bound.type = XBOUND_SPH;
        ent.bound.sph.r = 0.0f;

        r30->y = FLOAT_MAX;

        coll.flags = XCOLLIS_UNK0x100;

        xRayHitsSceneFlags(&s, &ray, &coll, XENT_COLLTYPE_PLYR, XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4 | XENTCOLLIS_UNK0x20);

        ent.bound.type = old_bound_type;
        ent.bound.sph.r = old_bound_radius;

        r30->y = ray.origin.y;

        if (!(coll.flags & XCOLLIS_UNK0x1))
        {
            return false;
        }

        loc = ((xMat4x3*)ent.model->Mat)->pos;
        loc.y -= coll.dist - f31;

        hit = (xEnt*)coll.optr;

        return true;
    }

    void drop_stacked_entity(xEnt&);

    void stacked_owner_destroyed(zEntDestructObj&, void* context)
    {
        drop_stacked_entity(*(xEnt*)context);
    }

    void mount_stacked_entity(xEnt& ent, xEnt& driver)
    {
        if (driver.collType != XENT_COLLTYPE_DYN)
        {
            return;
        }

        if (ent.driver)
        {
            ent.driver->driving_count--;
        }

        ent.driver = &driver;
        driver.driving_count++;

        if (driver.baseType == eBaseTypeDestructObj)
        {
            zEntDestructObj& d = *(zEntDestructObj*)&driver;
            d.destroy_notify = stacked_owner_destroyed;
            d.notify_context = &ent;
        }
    }

    void dismount_stacked_entity(xEnt& ent)
    {
        if (!ent.driver)
        {
            return;
        }

        if (ent.driver->baseType == eBaseTypeDestructObj)
        {
            zEntDestructObj& d = *(zEntDestructObj*)ent.driver;
            d.destroy_notify = NULL;
            d.notify_context = NULL;
        }

        ent.driver = NULL;
    }

    void setup_stacked_entity(xEnt& ent)
    {
        ent.pflags = XENT_PHYSICS_UNK0x4;
    }

    void drop_stacked_entity(xEnt& ent)
    {
        ent.pflags = XENT_PHYSICS_UNK0x4;

        dismount_stacked_entity(ent);
    }

    void stop_stacked_entity(xEnt& ent)
    {
        ent.pflags = 0;
    }

    void update_stacked_entity(xScene& sc, xEnt& ent, float32 dt)
    {
        xEntApplyPhysics(&ent, &sc, dt);
        xEntMove(&ent, &sc, dt);

        float32 f1 = ent.model->Mat->pos.y - ent.frame->mat.pos.y;

        if (f1 <= 0.0f)
        {
            return;
        }

        xVec3 var_24;
        xEnt* var_28;

        if (!collide_downward(var_24, var_28, sc, ent, f1))
        {
            return;
        }

        ent.frame->mat.pos.y = var_24.y;

        stop_stacked_entity(ent);

        if (var_28)
        {
            mount_stacked_entity(ent, *var_28);
        }
    }

}

void xEntSetup(xEnt* ent)
{
    xBaseSetup(ent);

    ent->baseFlags |= XBASE_UNK0x20;

    if (ent->asset->surfaceID != 0)
    {
        xSurface* surf = (xSurface*)xSceneResolvID(g_xSceneCur, ent->asset->surfaceID);

        if (surf)
        {
            surf->type = XSURFACE_TYPE_1;
            surf->ent = ent;

            xModelInstance* minst = ent->model;

            while (minst)
            {
                minst->Surf = surf;
                minst = minst->Next;
            }
        }
    }

    for (int32 i = 0; i < ent->linkCount; i++)
    {
        xLinkAsset* la = &ent->link[i];

        if (la->dstEvent == eEventDrivenby)
        {
            xEnt* dent = (xEnt*)xSceneResolvID(g_xSceneCur, la->dstAssetID);

            if (dent)
            {
                ent->driver = dent;
                ent->driveMode = (int32)la->param[0];

                dent->driving_count++;
            }
        }
    }

    ent->model->RedMultiplier = ent->asset->redMult;
    ent->model->GreenMultiplier = ent->asset->greenMult;
    ent->model->BlueMultiplier = ent->asset->blueMult;
    ent->model->Alpha = ent->asset->seeThru;

    xEntAddHittableFlag(ent);
    xEntAddShadowRecFlag(ent);

    zCollGeom_EntSetup(ent);

    if (ent->model)
    {
        if (ent->bound.type == XBOUND_BOX)
        {
            iBoxForModel(&ent->bound.box.box, ent->collModel ? ent->collModel : ent->model);
        }
        else if (ent->bound.type == XBOUND_OBB)
        {
            iBoxForModelLocal(&ent->bound.box.box, ent->collModel ? ent->collModel : ent->model);
        }
    }

    if (ent->moreFlags & XENT_MORE_ANIMCOLL)
    {
        anim_coll::reset(*ent);
    }

    if (ent->flags & XENT_STACKABLE)
    {
        setup_stacked_entity(*ent);
    }
}

void xEntSave(xEnt* ent, xSerial* s)
{
    xBaseSave(ent, s);

    if (xEntIsVisible(ent))
    {
        s->Write_b1(1);
    }
    else
    {
        s->Write_b1(0);
    }
}

void xEntLoad(xEnt* ent, xSerial* s)
{
    xBaseLoad(ent, s);

    int32 b = 0;
    s->Read_b1(&b);

    if (b)
    {
        xEntShow(ent);
    }
    else
    {
        xEntHide(ent);
    }
}

void xEntReset(xEnt* ent) WIP
{
    xBaseReset(ent, ent->asset);

    ent->baseFlags |= XBASE_UNK0x20;
    ent->flags = ent->asset->flags;
    ent->miscflags = 0;
    ent->moreFlags = ent->asset->moreFlags;

    xEntAddHittableFlag(ent);
    xEntAddShadowRecFlag(ent);

    xMat4x3 frame;

    xMat3x3Euler(&frame, ent->asset->ang.x, ent->asset->ang.y, ent->asset->ang.z);
    xVec3SMulBy(&frame.right, ent->asset->scale.x);
    xVec3SMulBy(&frame.up, ent->asset->scale.y);
    xVec3SMulBy(&frame.at, ent->asset->scale.z);
    xVec3Copy(&frame.pos, &ent->asset->pos);

    frame.flags = 0;

    if (ent->model)
    {
        xModelSetFrame(ent->model, &frame);

        if (ent->collModel)
        {
            xModelSetFrame(ent->collModel, &frame);
        }

        if (ent->moreFlags & XENT_MORE_ANIMCOLL)
        {
            anim_coll::reset(*ent);
        }

        xModelInstance* minst = ent->model;

        while (minst)
        {
            minst->RedMultiplier = ent->asset->redMult;
            minst->GreenMultiplier = ent->asset->greenMult;
            minst->BlueMultiplier = ent->asset->blueMult;
            minst->Alpha = minst->Data->geometry->matList.materials[0]->color.alpha / 255.0f;
            minst->Scale.x = 0.0f;
            minst->Scale.y = 0.0f;
            minst->Scale.z = 0.0f;

            minst = minst->Next;
        }
    }

    if (ent->frame)
    {
        xMat4x3Copy(&ent->frame->mat, &frame);

        ent->frame->oldmat = ent->frame->mat;

        xVec3Copy(&ent->frame->dpos, &g_O3);
        xVec3Copy(&ent->frame->dvel, &g_O3);
        xVec3Copy(&ent->frame->vel, &g_O3);
        xVec3Copy(&ent->frame->oldvel, &g_O3);
        xVec3Copy(&ent->frame->rot.axis, &ent->asset->ang);

        ent->frame->rot.angle = 0.0f;

        xRotCopy(&ent->frame->oldrot, &ent->frame->rot);
    }

    if (ent->bupdate && ent->model)
    {
        ent->bupdate(ent, (xVec3*)&ent->model->Mat->pos);
    }

    ent->num_updates = xrand() % 128;

    if (ent->flags & XENT_STACKABLE)
    {
        setup_stacked_entity(*ent);
    }
}

xModelInstance* xEntLoadModel(xEnt* ent, RpAtomic* imodel)
{
    xModelInstance* model = xModelInstanceAlloc(imodel, ent, 0, 0, NULL);

    while (imodel = iModelFile_RWMultiAtomic(imodel))
    {
        xModelInstanceAttach(xModelInstanceAlloc(imodel, ent, XMODEL_UNK0x8, 0, NULL), model);
    }

    if (ent)
    {
        ent->model = model;
    }

    return model;
}

static void xEntAddToPos(xEnt* ent, const xVec3* v)
{
    xVec3AddTo(&ent->frame->mat.pos, v);
}

void xEntSetupPipeline(xModelInstance* model)
{
    xEntSetupPipeline(model->Surf, model->Data);
}

void xEntSetupPipeline(xSurface* surf, RpAtomic* model)
{
    setMaterialTextureRestore = FALSE;
    sSetPipeline = FALSE;

    if (!surf)
    {
        return;
    }

    zSurfaceProps* pp = (zSurfaceProps*)surf->moprops;

    if (!pp)
    {
        return;
    }

    if (pp->texanim_flags & ZSURFACEPROPS_TEXANIM_0x1)
    {
        xGroup* g = (xGroup*)zSceneFindObject(pp->texanim[0].group);

        if (g)
        {
            uint32 texid = xGroupGetItem(g, pp->texanim[0].group_idx);
            RwTexture* texptr = (RwTexture*)xSTFindAsset(texid);

            if (texptr)
            {
                iModelSetMaterialTexture(model, texptr);
                setMaterialTextureRestore = TRUE;
            }
        }
    }

    if (pp->texanim_flags & ZSURFACEPROPS_TEXANIM_0x2)
    {
        xGroup* g = (xGroup*)zSceneFindObject(pp->texanim[1].group);

        if (g)
        {
            uint32 texid = xGroupGetItem(g, pp->texanim[1].group_idx);
            RwTexture* texptr = (RwTexture*)xSTFindAsset(texid);

            if (texptr)
            {
                xFXanimUV2PSetTexture(texptr);
                sSetPipeline = TRUE;
            }
        }
    }
    else if (pp->uvfx_flags & ZSURFACEPROPS_UVFX_0x2)
    {
        RwTexture* texptr = (RwTexture*)xSTFindAsset(pp->asset->matfx.dualmapID);

        if (texptr)
        {
            xFXanimUV2PSetTexture(texptr);
            sSetPipeline = TRUE;
        }
    }
    else
    {
        xFXanimUV2PSetTexture(NULL);
    }

    if (pp->uvfx_flags & (ZSURFACEPROPS_UVFX_0x1 | ZSURFACEPROPS_UVFX_0x2))
    {
        sSetPipeline = TRUE;

        xFXanimUVSetTranslation(&pp->uvfx[0].trans);
        xFXanimUV2PSetTranslation(&pp->uvfx[1].trans);
        xFXanimUVSetScale(&pp->uvfx[0].scale);
        xFXanimUV2PSetScale(&pp->uvfx[1].scale);
        xFXanimUVSetAngle(1.0f / (180.0f * PI) * pp->uvfx[0].rot);
        xFXanimUV2PSetAngle(1.0f / (180.0f * PI) * pp->uvfx[1].rot);
    }

    if (sSetPipeline)
    {
        oldPipe = model->pipeline;
        xFXanimUVAtomicSetup(model);
    }
}

void xEntRestorePipeline(xModelInstance* model)
{
    xEntRestorePipeline(model->Surf, model->Data);
}

void xEntRestorePipeline(xSurface*, RpAtomic* model)
{
    if (setMaterialTextureRestore)
    {
        iModelResetMaterial(model);
        setMaterialTextureRestore = FALSE;
    }

    if (sSetPipeline)
    {
        model->pipeline = oldPipe;
        sSetPipeline = FALSE;
    }
}

void xEntRender(xEnt* ent) WIP
{
    if (!ent->model || !xEntIsVisible(ent) || (ent->model->Flags & XMODEL_UNK0x400))
    {
        return;
    }

    ent->isCulled = 0;

    if (ent->baseType == eBaseTypePlayer || (ent->baseType == eBaseTypeNPC && !(ent->flags & XENT_NOSHADOW)))
    {
        bool32 shadowOutside;
        xVec3 shadVec;

        shadVec.x = ent->model->Mat->pos.x;
        shadVec.y = ent->model->Mat->pos.y - 10.0f;
        shadVec.z = ent->model->Mat->pos.z;

        if (iModelCullPlusShadow(ent->model->Data, ent->model->Mat, &shadVec, &shadowOutside))
        {
            if (shadowOutside)
            {
                ent->isCulled = 1;
                return;
            }

            goto renderShadow;
        }
    }
    else
    {
        if (iModelCull(ent->model->Data, ent->model->Mat))
        {
            ent->isCulled = 1;
            return;
        }
    }

    xModelRender(ent->model);

renderShadow:
    if ((ent->baseType == eBaseTypeNPC && !(ent->flags & XENT_NOSHADOW)) || ent->baseType == eBaseTypePlayer)
    {
        zLightAddLocal(ent);
        xShadow_ListAdd(ent);
    }
}

void xEntUpdate(xEnt* ent, xScene* sc, float32 dt)
{
    xEntBeginUpdate(ent, sc, dt);

    if (ent->pflags & XENT_PHYSICS_UNK0x2)
    {
        xEntApplyPhysics(ent, sc, dt);
    }

    if (ent->pflags & XENT_PHYSICS_UNK0x1)
    {
        xEntMove(ent, sc, dt);
    }

    xFFXApply(ent, sc, dt);

    if (ent->collis)
    {
        xEntCollide(ent, sc, dt);
    }

    if ((ent->flags & XENT_STACKABLE) && (ent->pflags & XENT_PHYSICS_UNK0x4))
    {
        update_stacked_entity(*sc, *ent, dt);
    }

    xEntEndUpdate(ent, sc, dt);
}

void xEntBeginUpdate(xEnt* ent, xScene*, float32 dt)
{
    if (ent->model)
    {
        xModelUpdate(ent->model, dt);

        if (ent->frame)
        {
            xVec3Copy(&ent->frame->oldvel, &ent->frame->vel);

            ent->frame->oldmat = ent->frame->mat;

            xRotCopy(&ent->frame->oldrot, &ent->frame->rot);
            xMat4x3Copy(&ent->frame->mat, xModelGetFrame(ent->model));

            ent->frame->mode = 0;
        }
    }
}

void xEntEndUpdate(xEnt* ent, xScene* sc, float32 dt)
{
    ent->num_updates++;

    if (ent->model)
    {
        if (ent->frame)
        {
            if (!(ent->frame->mode & XENTFRAME_MODE_0x20000))
            {
                xMat3x3Copy((xMat3x3*)ent->model->Mat, &ent->frame->mat);
            }

            if (!(ent->frame->mode & XENTFRAME_MODE_0x10000))
            {
                xVec3* mpos = (xVec3*)&ent->model->Mat->pos;
                xVec3Copy(mpos, &ent->frame->mat.pos);
            }
        }

        if (ent->bupdate)
        {
            xVec3* upos = (xVec3*)&ent->model->Mat->pos;
            ent->bupdate(ent, upos);
        }

        xModelEval(ent->model);

        if (ent->moreFlags & XENT_MORE_ANIMCOLL)
        {
            anim_coll::refresh(*ent);
        }

        if (ent->endUpdate)
        {
            ent->endUpdate(ent, sc, dt);
        }
    }
}

void xEntDefaultBoundUpdate(xEnt* ent, xVec3* pos) WIP
{
    xBound* bound = &ent->bound;

    if (bound->type == XBOUND_SPH)
    {
        xVec3Copy(&bound->sph.center, pos);

        bound->sph.center.y += 0.7f;
        bound->sph.r = 0.7f;
    }

    xBoundUpdate(bound);
    zGridUpdateEnt(ent);
}

void xEntDefaultTranslate(xEnt* ent, xVec3* dpos, xMat4x3* dmat)
{
    if (dmat)
    {
        if (ent->model)
        {
            xMat4x3Mul((xMat4x3*)ent->model->Mat, (xMat4x3*)ent->model->Mat, dmat);
        }

        if (ent->frame)
        {
            xMat4x3Mul(&ent->frame->mat, &ent->frame->mat, dmat);
        }

        xMat4x3Toworld(xEntGetCenter(ent), dmat, xEntGetCenter(ent));
    }
    else
    {
        if (ent->model)
        {
            xVec3AddTo(xEntGetPos(ent), dpos);
        }

        if (ent->frame)
        {
            xVec3AddTo(&ent->frame->mat.pos, dpos);
        }

        xVec3AddTo(xEntGetCenter(ent), dpos);
    }
}

static void xEntRotationToMatrix(xEntFrame* frame)
{
    if (frame->mode & XENTFRAME_MODE_0x20)
    {
        if (frame->mode & XENTFRAME_MODE_0x400)
        {
            xVec3AddTo(&frame->rot.axis, &frame->drot.axis);
            xMat3x3Euler(&frame->mat, frame->rot.axis.x, frame->rot.axis.y, frame->rot.axis.z);
        }
        else
        {
            frame->rot.angle = xAngleClamp(frame->rot.angle + frame->drot.angle);

            xMat3x3Rot(&frame->mat, &frame->rot.axis, frame->rot.angle);
        }
    }
}

void xEntMotionToMatrix(xEnt* ent, xEntFrame* frame)
{
    if (frame->mode & XENTFRAME_MODE_0x1000)
    {
        xEntRotationToMatrix(frame);
    }

    if (frame->mode & XENTFRAME_MODE_0x2)
    {
        if (frame->mode & XENTFRAME_MODE_0x800)
        {
            xMat3x3RMulVec(&frame->dpos, &frame->mat, &frame->dpos);
        }

        xEntAddToPos(ent, &frame->dpos);
    }

    if (frame->mode & XENTFRAME_MODE_0x8)
    {
        if (frame->mode & XENTFRAME_MODE_0x800)
        {
            xMat3x3RMulVec(&frame->dvel, &frame->mat, &frame->dvel);
        }

        xVec3AddTo(&frame->vel, &frame->dvel);
    }

    if (!(frame->mode & XENTFRAME_MODE_0x1000))
    {
        xEntRotationToMatrix(frame);
    }
}

void xEntMove(xEnt* ent, xScene* sc, float32 dt)
{
    if (ent->moreFlags & XENT_MORE_ANIMCOLL)
    {
        anim_coll::pre_move(*ent);
    }

    ent->move(ent, sc, dt, ent->frame);

    xEntMotionToMatrix(ent, ent->frame);

    if (ent->driver)
    {
        xEntFrame* dframe = ent->driver->frame;

        if (ent->driveMode == XENT_DRIVEMODE_0)
        {
            xVec3 dpos;
            xVec3Sub(&dpos, &dframe->mat.pos, &dframe->oldmat.pos);

            ent->transl(ent, &dpos, NULL);
        }
        else if (ent->driveMode == XENT_DRIVEMODE_1)
        {
            RwMatrixUpdate((RwMatrix*)&dframe->oldmat);

            xMat4x3 invOldmat;
            RwMatrixInvert((RwMatrix*)&invOldmat, (RwMatrix*)&dframe->oldmat);

            xMat4x3 deltaMat;
            xMat4x3Mul(&deltaMat, &invOldmat, &dframe->mat);

            ent->transl(ent, NULL, &deltaMat);
        }
    }

    if (ent->moreFlags & XENT_MORE_ANIMCOLL)
    {
        anim_coll::post_move(*ent);
    }
}

void xEntApplyPhysics(xEnt* ent, xScene* sc, float32 dt)
{
    xVec3 dposvel = { 0.0f, 0.0f, 0.0f };

    if ((ent->pflags & XENT_PHYSICS_UNK0x4) && (sc->flags & XSCENE_UNK0x1))
    {
        ent->frame->vel.y += sc->gravity * dt;
    }

    if ((ent->pflags & XENT_PHYSICS_UNK0x10) && (sc->flags & XSCENE_UNK0x2))
    {
        float32 tfric = 1.0f - sc->friction * dt;
        xVec3SMulBy(&ent->frame->vel, tfric);
    }

    if ((ent->pflags & XENT_PHYSICS_UNK0x8) && (sc->flags & XSCENE_UNK0x4))
    {
        float32 tdrag = 1.0f - sc->drag * dt;
        xVec3SMulBy(&ent->frame->vel, tdrag);
    }

    xVec3Add(&dposvel, &ent->frame->vel, &ent->frame->oldvel);
    xVec3SMulBy(&dposvel, 0.5f * dt);

    if (dposvel.y < 0.0f)
    {
        float32 dposXZ = xsqrt(xsqr(dposvel.x) + xsqr(dposvel.z));
        float32 scaleXZ = (dposXZ > 0.00001f) ? (30.0f * dt * 0.63f / dposXZ) : 0.0f;
        float32 scaleY = 30.0f * dt * 0.63f / xabs(dposvel.y);

        if (scaleXZ < 1.0f)
        {
            dposvel.x *= scaleXZ;
            dposvel.z *= scaleXZ;
        }

        if (scaleY < 1.0f)
        {
            dposvel.y *= scaleY;
        }
    }

    xEntAddToPos(ent, &dposvel);
}

void xEntCollide(xEnt* ent, xScene* sc, float32 dt)
{
    if (!ent->model)
    {
        return;
    }

    if (ent->collis->chk & (XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4 | XENTCOLLIS_UNK0x8 | XENTCOLLIS_UNK0x20))
    {
        xEntBeginCollide(ent, sc, dt);
    }

    if (ent->collis->chk & XENTCOLLIS_UNK0x8)
    {
        xEntCollCheckNPCsByGrid(ent, sc, xEntCollCheckOneEntNoDepen);
    }

    if (ent->collis->chk & (XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4))
    {
        xEntCollCheckByGrid(ent, sc, xEntCollCheckOneEntNoDepen);
    }

    if (ent->collis->chk & XENTCOLLIS_UNK0x20)
    {
        xEntCollCheckEnv(ent, sc);
    }

    xCollis* coll = &ent->collis->colls[0];

    if (!(ent->collis->chk & (XENTCOLLIS_UNK0x2 | XENTCOLLIS_UNK0x4 | XENTCOLLIS_UNK0x8 | XENTCOLLIS_UNK0x20)))
    {
        return;
    }

    float32 h_dot_n;
    float32 depen_len;

    depen_len = (ent->bound.type == XBOUND_SPH) ? ent->bound.sph.r : 0.7f;

    if ((ent->pflags & XENT_PHYSICS_UNK0x80) && (coll->flags & XCOLLIS_UNK0x1))
    {
        h_dot_n = xVec3Dot(&coll->hdng, &coll->norm);

        if (h_dot_n > 0.0f)
        {
            xVec3Inv(&coll->norm, &coll->norm);
            h_dot_n = -h_dot_n;
        }

        float32 f1 = h_dot_n * coll->dist + depen_len;

        if (f1 < 0.0f || f1 > depen_len)
        {
            f1 = xclamp(f1, 0.0f, depen_len);
        }

        xVec3SMul(&coll->depen, &coll->norm, f1);
    }

    if (ent->frame->vel.y <= 0.0f)
    {
        xEntCollideFloor(ent, sc, dt);
    }
    else
    {
        xEntCollideCeiling(ent, sc, dt);
    }

    xEntCollideWalls(ent, sc, dt);
    xEntEndCollide(ent, sc, dt);
}

void xEntBeginCollide(xEnt* ent, xScene*, float32) WIP
{
    if (ent->bupdate)
    {
        ent->bupdate(ent, &ent->frame->mat.pos);
    }

    for (uint8 idx = 0; idx < XENTCOLLIS_COLLS_COUNT; idx++)
    {
        xCollis* coll = &ent->collis->colls[idx];

        coll->flags = (XCOLLIS_UNK0x100 | XCOLLIS_UNK0x200 | XCOLLIS_UNK0x400 | XCOLLIS_UNK0x800 | XCOLLIS_UNK0x1000);
        coll->optr = NULL;
        coll->mptr = NULL;
        coll->dist = FLOAT_MAX;
    }

    ent->collis->idx = 6;
    ent->collis->stat_sidx = 6;
    ent->collis->stat_eidx = 6;
    ent->collis->dyn_sidx = 6;
    ent->collis->dyn_eidx = 6;
    ent->collis->npc_sidx = 6;
    ent->collis->npc_eidx = 6;
    ent->collis->env_sidx = 6;
    ent->collis->env_eidx = 6;
}

void xEntEndCollide(xEnt* ent, xScene* sc, float32 dt)
{
    if (ent->collis->post)
    {
        ent->collis->post(ent, sc, dt, ent->collis);
    }
}

void xEntCollCheckEnv(xEnt* p, xScene* sc) WIP
{
    p->collis->env_sidx = p->collis->idx;

    xCollis* coll = &p->collis->colls[p->collis->idx];

    coll->flags = (XCOLLIS_UNK0x100 | XCOLLIS_UNK0x200 | XCOLLIS_UNK0x400 | XCOLLIS_UNK0x800 | XCOLLIS_UNK0x1000);

    uint8 ncolls = iSphereHitsEnv3(&p->bound.sph, sc->env, coll, 18 - p->collis->idx, xdeg2rad(45.0f));

    p->collis->idx += ncolls;
    p->collis->env_eidx = p->collis->idx;
}

static void xEntCollCheckOneGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt, xGrid* grid) WIP
{
    xVec3* r26 = xEntGetCenter(p);

    xGridIterator it;
    int32 px;
    int32 pz;

    xGridBound* cell = xGridIterFirstCell(grid, r26->x, r26->y, r26->z, px, pz, it);

    while (cell)
    {
        if (xQuickCullIsects(&p->bound.qcd, (xQCData*)(cell + 1)))
        {
            hitIt((xEnt*)cell->data, sc, p);
        }

        cell = xGridIterNextCell(it);
    }

    float32 f6 = 0.5f * grid->csizex;
    float32 f4 = grid->csizex * px;
    float32 f7 = 0.5f * grid->csizez;
    float32 f3 = grid->csizez * pz;

    float32 clcenterx = f6 + (f4 + grid->minx); // f6
    float32 clcenterz = f7 + (f3 + grid->minz); // f7

    static int32 offs[4][3][2] =
    {
        {
            { -1, 0 },
            { -1, -1 },
            { 0, -1 }
        },
        {
            { 0, -1 },
            { 1, -1 },
            { 1, 0 }
        },
        {
            { 1, 0 },
            { 1, 1 },
            { 0, 1 }
        },
        {
            { 0, 1 },
            { -1, 1 },
            { -1, 0 }
        }
    };

    static int32 k;

    if (r26->x < clcenterx)
    {
        if (r26->z < clcenterz)
        {
            k = 0;
        }
        else
        {
            k = 1;
        }
    }
    else
    {
        if (r26->z < clcenterz)
        {
            k = 3;
        }
        else
        {
            k = 2;
        }
    }

    for (int32 i = 0; i < 3; i++)
    {
        int32 _x = px + offs[k][i][1];
        int32 _z = pz + offs[k][i][0];

        cell = xGridIterFirstCell(grid, _x, _z, it);

        while (cell)
        {
            if (xQuickCullIsects(&p->bound.qcd, (xQCData*)(cell + 1)))
            {
                hitIt((xEnt*)cell->data, sc, p);
            }

            cell = xGridIterNextCell(it);
        }
    }

    cell = xGridIterFirstCell(&grid->other, it);

    while (cell)
    {
        if (xQuickCullIsects(&p->bound.qcd, (xQCData*)(cell + 1)))
        {
            hitIt((xEnt*)cell->data, sc, p);
        }

        cell = xGridIterNextCell(it);
    }
}

void xEntCollCheckByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt)
{
    p->collis->stat_sidx = p->collis->idx;
    p->collis->dyn_sidx = p->collis->idx;

    xEntCollCheckOneGrid(p, sc, hitIt, &colls_grid);
    xEntCollCheckOneGrid(p, sc, hitIt, &colls_oso_grid);

    p->collis->stat_eidx = p->collis->idx;
    p->collis->dyn_eidx = p->collis->idx;
}

void xEntCollCheckNPCsByGrid(xEnt* p, xScene* sc, xEntSceneCallback hitIt)
{
    p->collis->npc_sidx = p->collis->idx;

    xEntCollCheckOneGrid(p, sc, hitIt, &npcs_grid);

    p->collis->npc_eidx = p->collis->idx;
}

void xEntCollCheckStats(xEnt* p, xScene* sc, xEntSceneCallback hitIt)
{
    p->collis->stat_sidx = p->collis->idx;

    xSceneForAllStatics(sc, hitIt, p);

    p->collis->stat_eidx = p->collis->idx;
}

void xEntCollCheckDyns(xEnt* p, xScene* sc, xEntSceneCallback hitIt)
{
    p->collis->dyn_sidx = p->collis->idx;

    xSceneForAllDynamics(sc, hitIt, p);

    p->collis->dyn_eidx = p->collis->idx;
}

void xEntCollCheckNPCs(xEnt* p, xScene* sc, xEntSceneCallback hitIt)
{
    p->collis->npc_sidx = p->collis->idx;

    xSceneForAllNPCs(sc, hitIt, p);

    p->collis->npc_eidx = p->collis->idx;
}

xEnt* xEntCollCheckOneEntNoDepen(xEnt* ent, xScene*, void* data) WIP
{
    xent_entent = TRUE;

    xEnt* p = (xEnt*)data;
    xCollis* coll;
    uint32 modl_coll = FALSE;

    if (p->collis->idx >= 15)
    {
        xent_entent = FALSE;
        return NULL;
    }

    if (!(ent->chkby & p->collType))
    {
        xent_entent = FALSE;
        return ent;
    }

    if (ent->id == p->id && (ent == p || ent->baseType != eBaseTypeBoulder))
    {
        xent_entent = FALSE;
        return ent;
    }

    coll = &p->collis->colls[p->collis->idx];

    if (ent->collLev == 5 && (p->collType & (XENT_COLLTYPE_NPC | XENT_COLLTYPE_PLYR)))
    {
        modl_coll = TRUE;
    }

    if (modl_coll)
    {
        coll->flags = 0;
    }
    else
    {
        coll->flags = (XCOLLIS_UNK0x100 | XCOLLIS_UNK0x200 | XCOLLIS_UNK0x400 | XCOLLIS_UNK0x800 | XCOLLIS_UNK0x1000);
    }

    xBoundHitsBound(&p->bound, &ent->bound, coll);

    if (coll->flags & XCOLLIS_UNK0x1)
    {
        if (modl_coll)
        {
            coll->flags = (XCOLLIS_UNK0x100 | XCOLLIS_UNK0x200 | XCOLLIS_UNK0x400 | XCOLLIS_UNK0x800 | XCOLLIS_UNK0x1000);

            xBound tmp;
            xBound* bptr;
            uint8 ncolls;

            if (p->bound.type == XBOUND_SPH)
            {
                ncolls = iSphereHitsModel3(&p->bound.sph, ent->collModel ? ent->collModel : ent->model, coll, 15 - p->collis->idx, xdeg2rad(45.0f));
            }
            else if (p->bound.type == XBOUND_BOX)
            {
                xVec3* upper = &p->bound.box.box.upper;
                xVec3* lower = &p->bound.box.box.lower;

                bptr = &tmp;

                tmp.type = XBOUND_SPH;

                xVec3Add(&bptr->sph.center, upper, lower);
                xVec3SMulBy(&bptr->sph.center, 0.5f);

                tmp.sph.r = 0.167f * (upper->x + upper->y + upper->z - lower->x - lower->y - lower->z);

                ncolls = iSphereHitsModel3(&p->bound.sph, ent->collModel ? ent->collModel : ent->model, coll, 15 - p->collis->idx, xdeg2rad(45.0f));
            }

            for (uint8 idx = 0; idx < ncolls; idx++)
            {
                coll[idx].optr = ent;
                coll[idx].mptr = ent->model;

                p->collis->idx++;
            }

            xent_entent = FALSE;

            return ent;
        }
        else
        {
            coll->oid = ent->id;
            coll->optr = ent;
            coll->mptr = ent->model;

            p->collis->idx++;

            if ((ent->pflags & XENT_PHYSICS_UNK0x20) && ent->bound.type == XBOUND_SPH && p->bound.type == XBOUND_SPH && coll->hdng.y < -0.86602497f /* negative square root of 0.75? */)
            {
                float32 rsum = p->bound.sph.r + ent->bound.sph.r;
                float32 dx = p->bound.sph.center.x - ent->bound.sph.center.x;
                float32 dy = p->bound.sph.center.y - ent->bound.sph.center.y;
                float32 dz = p->bound.sph.center.z - ent->bound.sph.center.z;
                float32 hsqr = xsqr(rsum) - (xsqr(dx) + xsqr(dz));

                if (hsqr >= 0.0f)
                {
                    coll->depen.x = 0.0f;
                    coll->depen.y = xsqrt(hsqr) - dy;
                    coll->depen.z = 0.0f;
                    coll->dist = 0.7f - coll->depen.y;
                    coll->hdng.x = 0.0f;
                    coll->hdng.y = -1.0f;
                    coll->hdng.z = 0.0f;
                }
            }
        }
    }

    xent_entent = FALSE;

    return ent;
}

void xEntCollideFloor(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntCollideCeiling(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntCollideWalls(xEnt* p, xScene* sc, float32 dt) STUB_VOID
void xEntSetNostepNormAngle(float32 angle) STUB_VOID
xBox* xEntGetAllEntsBox() STUB
void xEntAnimateCollision(xEnt& ent, bool on) STUB_VOID
bool xEntValidType(uint8 type) STUB
void xEntReposition(xEnt& ent, const xMat4x3& mat) STUB_VOID
void xEntInitShadow(xEnt& ent, xEntShadow& shadow) STUB_VOID