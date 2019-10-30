/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2015 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  AmdDxExtLvrResources.h
* @brief AMD D3D LvrResources Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTLVRRESOURCES_H_
#define _AMDDXEXTLVRRESOURCES_H_

struct AmdPrivateDisplaySurfaceDesc
{
    UINT        width;
    UINT        height;
    DXGI_FORMAT format;
    UINT        dxBindFlags;
};

struct AmdCpuMappedSharedBufferDesc
{
    UINT  sizeWidth;
    UINT  structureByteStride;
    UINT  bindFlags;
    UINT  cpuAccessFlags;
    UINT  createFlags;
};

enum AmdSharedBufferCreateFlags
{
    AMD_SHARED_BUFFER_CREATE_ACCESSED_BY_VCE = 1,
};

union AmdResApiAccessFlags
{
    struct
    {
        UINT apiDx11   : 1;
        UINT apiDx12   : 1;
        UINT apiMantle : 1;
        UINT apiVulkan : 1;
        UINT reserved  : 28;
    };
    UINT value;
};

union AmdResOpenFlags
{
    struct
    {
        UINT inherit    : 1;
        UINT reserved   : 31;
    };
    UINT value;
};

union AmdResAccessFlags
{
    struct
    {
        UINT accessShaderRead  : 1;
        UINT accessShaderWrite : 1;
        UINT accessRender      : 1;
        UINT reserved          : 29;
    };
    UINT value;
};

union AmdResMiscAccessFlags
{
    struct
    {
        UINT discardContents : 1;
        UINT reserved        : 31;
    };
    UINT value;
};

struct AmdResAccessParam
{
    AmdResAccessFlags     access;
    AmdResMiscAccessFlags flags;
};
#endif
