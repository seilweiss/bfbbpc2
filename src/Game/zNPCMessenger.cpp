#include "zNPCMessenger.h"

#include "xordarray.h"

struct NPCPSClt
{
	void(*notify)(void*, NPCMsg*);
	void* notedata;
	int32 flg_filter;
	NPCPSClt* next;
};

struct NPCPSData
{
	NPCPSClt* cltblob;
	NPCPSClt* cltfree;
	st_XORDEREDARRAY cltlist;
	NPCMsg* msgblob;
	NPCMsg* msgfree;
	st_XORDEREDARRAY quelist;
};

void zNPCMsg_Startup() STUB_VOID
void zNPCMsg_Shutdown() {}
void zNPCMsg_ScenePrepare() {}
void zNPCMsg_SceneFinish() STUB_VOID
void zNPCMsg_SceneReset() STUB_VOID
void zNPCMsg_Timestep(xScene*, float32 dt) STUB_VOID
void zNPCMsg_SendMsg(en_NPC_MSG_ID msgevent, uint32 sendto) STUB_VOID
void zNPCMsg_SendMsg(en_NPC_MSG_ID msgevent, zNPCCommon* npc_sendto) STUB_VOID
void zNPCMsg_SendMsg(NPCMsg* inmsg, zNPCCommon* npc_sendto) STUB_VOID
void zNPCMsg_SendMsg(NPCMsg* inmsg, float32 delay, zNPCCommon* npc_sendto) STUB_VOID
static void NPCPS_copyMsgInfo(NPCMsg*, NPCMsg*, float32) STUB_VOID
static void NPCPS_queMessage(NPCMsg*) STUB_VOID
static int32 NPCPS_flagForMID(en_NPC_MSG_ID) STUB
static void NPCPS_MsgPoolInit(NPCPSData*, int32) STUB_VOID
static void NPCPS_MsgPoolReset(NPCPSData*) STUB_VOID
static void NPCPS_CltPoolInit(NPCPSData*, int32) STUB_VOID
static void NPCPS_CltPoolReset(NPCPSData*) STUB_VOID
static NPCPSData* NPCPS_postOffice() STUB
static NPCMsg* NPCPS_grabMsg() STUB
static void NPCPS_freeMsg(NPCMsg*) STUB_VOID
void zNPCMsg_AreaNotify(zNPCCommon* sender, en_NPC_MSG_ID msgid, float32 rad, int32 filter, en_NPCTYPES toNPCType) STUB_VOID
void zNPCMsg_AreaNotify(zNPCCommon* sender, en_NPC_MSG_ID msgid, float32 rad, int32 filter, en_NPCTYPES* npcTypeList) STUB_VOID
void zNPCMsg_AreaNotify(zNPCCommon* sender, NPCMsg* msg, float32 radius, int32 filter, en_NPCTYPES* npcTypeList) STUB_VOID
void zNPCMsg_AreaPlayerStun(float32 stuntime, float32 radius, xVec3* pos) STUB_VOID
void zNPCMsg_AreaNPCExplodeNoRobo(zNPCCommon* who, float32 radius, const xVec3* pos_fromHere) STUB_VOID