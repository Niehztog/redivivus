/**
 * Auto-generated global data definitions
 * Binary: Game.exe
 */

#include "globals.h"
#include "D2Client/Renderer/Glide.h"
#include "D2Glide/Renderer/Glide.h"
#include "D2Glide/glFloorCache.h"
#include "D2Glide/glSubtileCache.h"
#include "D2Glide/glTextureCache.h"


// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

int gaPerspectiveImageSizeTable[8] = { 0x100, 0x100, 0x100, 0x80, 0x100, 0x40, 0x100, 0x20 };

GrTexInfo gTexInfoDebugFontGlide = {
    /* .smallLodLog2 = */ 0x4,
    /* .largeLodLog2 = */ 0x4,
    /* .aspectRatioLog2 = */ (GrAspectRatio_t)-0x1,
    /* .format = */ 0x5,
    /* .data = */ nullptr
};

void * gapGlideStripVertexPtrsA[10] = {
    (void*)gaGlidePerspectiveVertices,
    (void*)&gaGlidePerspectiveVertices[1].fX,
    (void*)&gaGlidePerspectiveVertices[3].fX,
    (void*)&gaGlidePerspectiveVertices[4].fX,
    (void*)&gaGlidePerspectiveVertices[6].fX,
    (void*)&gaGlidePerspectiveVertices[7].fX,
    (void*)&gaGlidePerspectiveVertices[9].fX,
    (void*)&gaGlidePerspectiveVertices[10].fX,
    (void*)&gaGlidePerspectiveVertices[12].fX,
    (void*)&gaGlidePerspectiveVertices[13].fX
};

void * gapGlideStripVertexPtrsB[10] = {
    (void*)&gaGlidePerspectiveVertices[1].fX,
    (void*)&gaGlidePerspectiveVertices[2].fX,
    (void*)&gaGlidePerspectiveVertices[4].fX,
    (void*)&gaGlidePerspectiveVertices[5].fX,
    (void*)&gaGlidePerspectiveVertices[7].fX,
    (void*)&gaGlidePerspectiveVertices[8].fX,
    (void*)&gaGlidePerspectiveVertices[10].fX,
    (void*)&gaGlidePerspectiveVertices[11].fX,
    (void*)&gaGlidePerspectiveVertices[13].fX,
    (void*)&gaGlidePerspectiveVertices[14].fX
};

D2GlideWallCornerStrc gaGlideWallCornerTable[60] = {
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x0,
        /* .nZ = */ 0x0
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x3,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x1,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x1,
        /* .nZ = */ -0x58
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x3,
        /* .nZ = */ -0x68
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x5,
        /* .nZ = */ -0x78
    },
    {
        /* .nX = */ -0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x78
    },
    {
        /* .nX = */ -0x3,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x68
    },
    {
        /* .nX = */ -0x1,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x58
    },
    {
        /* .nX = */ 0x1,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x3,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x3,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x1,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x1,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x3,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ -0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x78
    },
    {
        /* .nX = */ -0x3,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x68
    },
    {
        /* .nX = */ -0x1,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x58
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x1,
        /* .nZ = */ -0x58
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x3,
        /* .nZ = */ -0x68
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ -0x5,
        /* .nZ = */ -0x78
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x3,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x1,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x1,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x48
    },
    {
        /* .nX = */ 0x3,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x38
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0xa,
        /* .nZ = */ 0x28
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x8,
        /* .nZ = */ 0x18
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x6,
        /* .nZ = */ 0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x4,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x2,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x2,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x4,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x6,
        /* .nY = */ 0x5,
        /* .nZ = */ 0x8
    },
    {
        /* .nX = */ 0x8,
        /* .nY = */ 0x5,
        /* .nZ = */ 0x18
    },
    {
        /* .nX = */ 0xa,
        /* .nY = */ 0x5,
        /* .nZ = */ 0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x2,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x4,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x4,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x2,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x0,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x28
    },
    {
        /* .nX = */ 0x2,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x4,
        /* .nY = */ 0x5,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x4,
        /* .nZ = */ -0x8
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x2,
        /* .nZ = */ -0x18
    },
    {
        /* .nX = */ 0x5,
        /* .nY = */ 0x0,
        /* .nZ = */ -0x28
    }
};

GrTexInfo gTexInfoBlocks0Glide = {
    /* .smallLodLog2 = */ 0x8,
    /* .largeLodLog2 = */ 0x8,
    /* .aspectRatioLog2 = */ 0x2,
    /* .format = */ 0xa,
    /* .data = */ nullptr
};

GrTexInfo gTexInfoBlocks1Glide = {
    /* .smallLodLog2 = */ 0x8,
    /* .largeLodLog2 = */ 0x8,
    /* .aspectRatioLog2 = */ 0x2,
    /* .format = */ 0xa,
    /* .data = */ nullptr
};

GrTexInfo g_GrTexInfoGlBlocks = {
    /* .smallLodLog2 = */ 0x5,
    /* .largeLodLog2 = */ 0x5,
    /* .aspectRatioLog2 = */ 0x0,
    /* .format = */ 0x5,
    /* .data = */ nullptr
};

GrTexInfo gTexInfoGlideSurfaceBlocks = {
    /* .smallLodLog2 = */ 0x8,
    /* .largeLodLog2 = */ 0x8,
    /* .aspectRatioLog2 = */ 0x1,
    /* .format = */ 0x5,
    /* .data = */ nullptr
};

GlSubtileCacheStrc gGlideSubtileTextureCache = {
    /* .dwEntrySize = */ 0,
    /* .nMaxEntries = */ 0,
    /* .nUsedCount = */ 0,
    /* .pActiveHead = */ nullptr,
    /* .pActiveTail = */ nullptr,
    /* .pFreeHead = */ nullptr,
    /* .pFreeTail = */ nullptr,
    /* .pNodes = */ nullptr
};

GlFloorCacheStrc gGlideFloorTextureCache = {
    /* .dwEntrySize = */ 0,
    /* .nMaxEntries = */ 0,
    /* .nUsedCount = */ 0,
    /* .pActiveHead = */ nullptr,
    /* .pActiveTail = */ nullptr,
    /* .pFreeHead = */ nullptr,
    /* .pFreeTail = */ nullptr,
    /* .pNodes = */ nullptr
};

uint32_t gGlidePaletteEntry0[256] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

int gnGlideSecondaryTMUCount[2] = { 0, 0 };

double gfGlideVertex0T = 0;

double gfGlideVertex1T = 0;

GlTextureCacheStrc gGlideSmallTextureCache[3] = {
    {
        /* .dwEntrySize = */ 0,
        /* .nMaxEntries = */ 0,
        /* .nUsedCount = */ 0,
        /* .pActiveHead = */ nullptr,
        /* .pActiveTail = */ nullptr,
        /* .pFreeHead = */ nullptr,
        /* .pFreeTail = */ nullptr,
        /* .pNodes = */ nullptr
    },
    {
        /* .dwEntrySize = */ 0,
        /* .nMaxEntries = */ 0,
        /* .nUsedCount = */ 0,
        /* .pActiveHead = */ nullptr,
        /* .pActiveTail = */ nullptr,
        /* .pFreeHead = */ nullptr,
        /* .pFreeTail = */ nullptr,
        /* .pNodes = */ nullptr
    },
    {
        /* .dwEntrySize = */ 0,
        /* .nMaxEntries = */ 0,
        /* .nUsedCount = */ 0,
        /* .pActiveHead = */ nullptr,
        /* .pActiveTail = */ nullptr,
        /* .pFreeHead = */ nullptr,
        /* .pFreeTail = */ nullptr,
        /* .pNodes = */ nullptr
    }
};

uint32_t gaGlideColorDebugGradientIndices[1024] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

uint32_t gaGlideDebugFontTexStartAddrs[96] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

void * lpBuffer_008802c8[96] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2GlideVertexStrc gaGlidePerspectiveVertices[15] = {
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    }
};

D2GlideVertexStrc gaGlideGroundTileVertices[36] = {
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    },
    {
        /* .fX = */ 0,
        /* .fY = */ 0,
        /* .dwColor = */ 0,
        /* .fOOW = */ 0,
        /* .fS = */ 0,
        /* .fT = */ 0,
        /* .fW = */ 0
    }
};

void * gapGlideGroundStripVertexPtrs[60] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

// =============================================================================
// Initialized scalars
// =============================================================================

uint32_t gnGlideTextureMode = -0x1;
uint32_t ghGlideSstWindow = 0;
int gnGlideTextureMemoryUsed = 0;
uint32_t gbGlideIsDebugBuild = 0;
FxI32 gnGlideTextureMemoryMask = 0;
uint32_t ghGlideWindow = 0;
uint32_t gbGlideInitialized = 0;
uint32_t gbWINDOWED = 0;
uint32_t gnGlideColorCombineMode = 0;
uint32_t gnGlideAlphaBlendMode = 0;
uint32_t gnGlideTextureFilteringMode = 0;
uint32_t gbGlideInScene = 0;
uint32_t gbGlidePerspectiveMode = 0;
uint32_t gnGlideSpriteSecondaryTMUEnabled = 0;
uint32_t gnGlideTMUIndex = 0;
int gGlideVertex0 = 0;
float gfGlideQuadZ0 = 0;
uint32_t gnGlideVertexColor = 0;
float gfGlideVertex0OOW = 0;
float gfGlideVertex0S = 0;
float gfGlideVertex0X = 0;
float gfGlideQuadZ1 = 0;
float gfGlideVertex0Color = 0;
float gfGlideVertex1OOW = 0;
float gfGlideVertex1S = 0;
float gfGlidePaletteTableOffset = 0;
float gfGlideVertex1Y = 0;
float gfGlideVertex2Color = 0;
float gfGlideVertex3OOW = 0;
float gfGlideVertex3S = 0;
float gfGlideVertex3T = 0;
float gfGlideVertex2X = 0;
float gfGlideVertex2Y = 0;
float gfGlideVertex1Color = 0;
float gfGlideVertex3Color = 0;
int gnGlideAlphaBlendDst = 0;
int gnGlideAlphaBlendSrc = 0;
void * gpGlideSpriteBuffer = 0;
void * gpGlideSpritePixelBuffer = 0;
float gfGlideDebugFontVertex0X = 0;
float gfGlideDebugFontVertex0Y = 0;
float gfGlideDebugFontVertex1X = 0;
float gfGlideDebugFontVertex1Y = 0;
float gfGlideDebugFontVertex3S = 0;
float gfGlideDebugFontVertex2T = 0;
float gfGlideDebugFontVertex3X = 0;
float gfGlideDebugFontVertex3T = 0;
void * gpGlideDebugFontTexture = 0;
uint32_t gnGlideDebugFontTMU = 0;
int * gpnLightmapRowPointers = 0;
int gGlidePerspectiveVertexBuffer = 0;
float gfGlideWallVertexYMin = 0;
float gfGlideWallVertex2X = 0;
float gfGlideWallVertexYMid = 0;
float gfGlideWallVertexYMax = 0;
float gfGlideWallVertex3Y = 0;
float gfGlideWallVertex4X = 0;
float gfGlideWallVertex4Y = 0;
uint8_t gbGlideGlobalLightGreen = 0;
uint8_t gbGlideGlobalLightBlue = 0;
uint8_t gbGlideGlobalLightRed = 0;
// also labelled: glVertex
uint8_t * gpGlideLightingTable = 0;
int gnGlidePerspectiveOriginX = 0;
// also labelled: gpGlideTexturePalette
int32_t gnGlidePerspectiveScale = 0;
int gnGlidePerspectiveOriginY = 0;
void * gpPerspectiveLookupTable = 0;
uint8_t (*gpGlideSmackerTexBuf0)[32768] = 0;
uint8_t (*gpGlideSmackerTexBuf1)[32768] = 0;
uint32_t gnGlideSmackTex1StartAddr = 0;
uint32_t gnGlideSmackTex2StartAddr = 0;
uint8_t (*gpGlideSmackerTexBuf2)[32768] = 0;
uint32_t gnGlideTMUHandle = 0;
uint32_t gnGlideTMUId = 0;
void * gpGlBlocksWallBuffer = 0;
void * gpGlBlocksFloorBuffer = 0;
uint32_t gnBinkGlideYOffset = 0;
uint32_t gnBinkGlideXOffset = 0;
void * gpBinkVideoGlide = 0;
uint32_t gnGlideBinkSurfaceType = 0;
uint32_t g_bGlideBinkVideoQuitRequested = 0;

namespace D2Common::Drlg::Maze {

} // namespace D2Common::Drlg::Maze

namespace Fog::Src::Excel {

} // namespace Fog::Src::Excel

namespace NWardenClient {

} // namespace NWardenClient

namespace Class::WardenClient {

} // namespace Class::WardenClient

namespace Class::UIWidget {

} // namespace Class::UIWidget

namespace Class::ButtonImplementation {

} // namespace Class::ButtonImplementation

namespace Class::ButtonWrapper {

} // namespace Class::ButtonWrapper

namespace Class::EditBoxImplementation {

} // namespace Class::EditBoxImplementation

namespace Class::EditBoxWrapper {

} // namespace Class::EditBoxWrapper

namespace Class::SpinnerImplementation {

} // namespace Class::SpinnerImplementation

namespace Class::SpinnerWrapper {

} // namespace Class::SpinnerWrapper

namespace D2Client::UNIT::Object {

} // namespace D2Client::UNIT::Object

namespace Class::ListBoxWrapper {

} // namespace Class::ListBoxWrapper

namespace Class::ListBoxImplementation {

} // namespace Class::ListBoxImplementation

namespace D2Win::_FONT {

} // namespace D2Win::_FONT

namespace D2Game::GAME::Event::Dispatch {

} // namespace D2Game::GAME::Event::Dispatch

namespace D2Game::GAME::Event::Dispatch::Player {

} // namespace D2Game::GAME::Event::Dispatch::Player

namespace D2Game::GAME::Event::Dispatch::Object {

} // namespace D2Game::GAME::Event::Dispatch::Object

namespace D2Game::GAME::Event::Dispatch::Monster {

} // namespace D2Game::GAME::Event::Dispatch::Monster

namespace Class::ChatIgnoreList {

} // namespace Class::ChatIgnoreList

namespace Class::IgnoreList {

} // namespace Class::IgnoreList

namespace D2Common::Drlg::Outdoors {

} // namespace D2Common::Drlg::Outdoors

namespace Define_the_symbol__ATL_MIXED {

} // namespace Define_the_symbol__ATL_MIXED

namespace crashy {

} // namespace crashy

namespace Storm::SFile {

} // namespace Storm::SFile

namespace Class::FILEREC {

} // namespace Class::FILEREC

namespace Class::EVENTREC {

} // namespace Class::EVENTREC

namespace Class::REQUEST {

} // namespace Class::REQUEST

namespace Class::AUDIOSTREAM {

} // namespace Class::AUDIOSTREAM

namespace Class::HANDLER {

} // namespace Class::HANDLER

namespace D2Client::CharScreen {

} // namespace D2Client::CharScreen

namespace D2Client::UI::Automap {

} // namespace D2Client::UI::Automap

namespace D2Game::GAME::Rendering {

} // namespace D2Game::GAME::Rendering

namespace D2Client::UI::Help {

} // namespace D2Client::UI::Help

namespace D2Client::UI::npcmenu {

} // namespace D2Client::UI::npcmenu

namespace D2Client::NPC {

} // namespace D2Client::NPC

namespace D2Client::UNIT::UnitSnd {

} // namespace D2Client::UNIT::UnitSnd

namespace D2Client::UI::ui {

} // namespace D2Client::UI::ui

namespace D2Game::Quests::QUESTS::Quest40 {

} // namespace D2Game::Quests::QUESTS::Quest40

namespace D2Game::Quests::QUESTS::A5Q1 {

} // namespace D2Game::Quests::QUESTS::A5Q1

namespace D2Game::Quests::QUESTS::A5Q2 {

} // namespace D2Game::Quests::QUESTS::A5Q2

namespace D2Game::Quests::QUESTS::A5Q3 {

} // namespace D2Game::Quests::QUESTS::A5Q3

namespace D2Game::Quests::QUESTS::A5Q4 {

} // namespace D2Game::Quests::QUESTS::A5Q4

namespace D2Game::Quests::QUESTS::A5Q5 {

} // namespace D2Game::Quests::QUESTS::A5Q5

namespace D2Game::Quests::QUESTS::A5Q6 {

} // namespace D2Game::Quests::QUESTS::A5Q6

namespace D2Game::Quests::QUESTS::Quest37 {

} // namespace D2Game::Quests::QUESTS::Quest37

namespace D2Game::Quests::QUESTS::A1Q0 {

} // namespace D2Game::Quests::QUESTS::A1Q0

namespace D2Game::Quests::QUESTS::A1Q1 {

} // namespace D2Game::Quests::QUESTS::A1Q1

namespace D2Game::Quests::QUESTS::A1Q2 {

} // namespace D2Game::Quests::QUESTS::A1Q2

namespace D2Game::Quests::QUESTS::A1Q3 {

} // namespace D2Game::Quests::QUESTS::A1Q3

namespace D2Game::Quests::QUESTS::A1Q4 {

} // namespace D2Game::Quests::QUESTS::A1Q4

namespace D2Game::Quests::QUESTS::A1Q5 {

} // namespace D2Game::Quests::QUESTS::A1Q5

namespace D2Game::Quests::QUESTS::A1Q6 {

} // namespace D2Game::Quests::QUESTS::A1Q6

namespace D2Game::Quests::QUESTS::A1Q7 {

} // namespace D2Game::Quests::QUESTS::A1Q7

namespace D2Game::Quests::QUESTS::Quest38 {

} // namespace D2Game::Quests::QUESTS::Quest38

namespace D2Game::Quests::QUESTS::A2Q0 {

} // namespace D2Game::Quests::QUESTS::A2Q0

namespace D2Game::Quests::QUESTS::A2Q1 {

} // namespace D2Game::Quests::QUESTS::A2Q1

namespace D2Game::Quests::QUESTS::A2Q2 {

} // namespace D2Game::Quests::QUESTS::A2Q2

namespace D2Game::Quests::QUESTS::A2Q3 {

} // namespace D2Game::Quests::QUESTS::A2Q3

namespace D2Game::Quests::QUESTS::A2Q4 {

} // namespace D2Game::Quests::QUESTS::A2Q4

namespace D2Game::Quests::QUESTS::A2Q5 {

} // namespace D2Game::Quests::QUESTS::A2Q5

namespace D2Game::Quests::QUESTS::A2Q6 {

} // namespace D2Game::Quests::QUESTS::A2Q6

namespace D2Game::Quests::QUESTS::A2Q7 {

} // namespace D2Game::Quests::QUESTS::A2Q7

namespace D2Game::Quests::QUESTS::A2Q8 {

} // namespace D2Game::Quests::QUESTS::A2Q8

namespace D2Common::Monsters::MONSTERS::Umod {

} // namespace D2Common::Monsters::MONSTERS::Umod

namespace D2Game::Quests::QUESTS::A4Q0 {

} // namespace D2Game::Quests::QUESTS::A4Q0

namespace D2Game::Quests::QUESTS::A4Q1 {

} // namespace D2Game::Quests::QUESTS::A4Q1

namespace D2Game::Quests::QUESTS::A4Q2 {

} // namespace D2Game::Quests::QUESTS::A4Q2

namespace D2Game::Quests::QUESTS::A4Q3 {

} // namespace D2Game::Quests::QUESTS::A4Q3

namespace D2Game::Quests::QUESTS::A4Q4 {

} // namespace D2Game::Quests::QUESTS::A4Q4

namespace D2Game::Quests::QUESTS::Quest39 {

} // namespace D2Game::Quests::QUESTS::Quest39

namespace D2Game::Quests::QUESTS::A3Q0 {

} // namespace D2Game::Quests::QUESTS::A3Q0

namespace D2Game::Quests::QUESTS::A3Q1 {

} // namespace D2Game::Quests::QUESTS::A3Q1

namespace D2Game::Quests::QUESTS::A3Q2 {

} // namespace D2Game::Quests::QUESTS::A3Q2

namespace D2Game::Quests::QUESTS::A3Q3 {

} // namespace D2Game::Quests::QUESTS::A3Q3

namespace D2Game::Quests::QUESTS::A3Q4 {

} // namespace D2Game::Quests::QUESTS::A3Q4

namespace D2Game::Quests::QUESTS::A3Q5 {

} // namespace D2Game::Quests::QUESTS::A3Q5

namespace D2Game::Quests::QUESTS::A3Q6 {

} // namespace D2Game::Quests::QUESTS::A3Q6

namespace D2Client::Waypoint {

} // namespace D2Client::Waypoint

namespace D2Common::Drlg::DrlgGrid {

} // namespace D2Common::Drlg::DrlgGrid

namespace Fog::Memory {

} // namespace Fog::Memory

namespace Fog::Debug {

} // namespace Fog::Debug

namespace D2Game::Save {

} // namespace D2Game::Save

namespace D2Client::MCP {

} // namespace D2Client::MCP

namespace D2Client::Bnet {

} // namespace D2Client::Bnet

namespace D2Game::GameData {

} // namespace D2Game::GameData

namespace D2Client::GAME::Record {

} // namespace D2Client::GAME::Record

namespace D2Client::UI::Dialog {

} // namespace D2Client::UI::Dialog

namespace D2Client::_Selection {

} // namespace D2Client::_Selection

namespace D2Client::Cursor {

} // namespace D2Client::Cursor

namespace D2Client::Draw::Weather {

} // namespace D2Client::Draw::Weather

namespace D2Client::Draw::LightMap {

} // namespace D2Client::Draw::LightMap

namespace D2Client::GAME::View {

} // namespace D2Client::GAME::View

namespace D2Client::GAME::RosterPets {

} // namespace D2Client::GAME::RosterPets

namespace D2Client::GAME::Roster {

} // namespace D2Client::GAME::Roster

namespace D2Client::UI::Inv {

} // namespace D2Client::UI::Inv

namespace D2Client::UI::Hireables {

} // namespace D2Client::UI::Hireables

namespace D2Client::UI::Panel {

} // namespace D2Client::UI::Panel

namespace D2Client::UI::Party {

} // namespace D2Client::UI::Party

namespace D2Client::_Interaction {

} // namespace D2Client::_Interaction

namespace D2Client::Merc {

} // namespace D2Client::Merc

namespace D2Client::Mouse {

} // namespace D2Client::Mouse

namespace D2Client::Forms {

} // namespace D2Client::Forms

namespace D2Client::_CdKey {

} // namespace D2Client::_CdKey

namespace Global {

} // namespace Global
