#pragma once

#include <types.h>
#include <rwcore.h>
#include <rpworld.h>

struct xClumpCollBSPTree;

struct xJSPNodeInfo
{
	int32 originalMatIndex;
	int32 nodeFlags;
};

struct xJSPHeader
{
	char idtag[4];
	uint32 version;
	uint32 jspNodeCount;
	RpClump* clump;
	xClumpCollBSPTree* colltree;
	xJSPNodeInfo* jspNodeList;
};