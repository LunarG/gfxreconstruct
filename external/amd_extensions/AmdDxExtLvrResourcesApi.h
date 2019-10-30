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
* @file  AmdDxExtLvrResourcesApi.h
* @brief AMD D3D LvrResources Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTLVRRESOURCESAPI_H_
#define _AMDDXEXTLVRRESOURCESAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtLvrResources.h"

const unsigned int AmdDxLvrResourcesMajorVersion = 2;
const unsigned int AmdDxLvrResourcesMinorVersion = 2;

// Extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtLvrResourcesID = 19;

// Supported by both CFX and DXX
class IAmdDxExtLvrResources : public IAmdDxExtInterface
{
public:
    // Version information
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // Presentable surface creation for private display
    virtual HRESULT CreatePrivateDisplaySurface(
        const AmdPrivateDisplaySurfaceDesc* pDesc,
        ID3D11Texture2D**                   ppTexture,
        HANDLE*                             pSharedHandle) = 0;

    // Buffer creation for late data latch
    virtual HRESULT CreateCpuMappedSharedBuffer(
        const AmdCpuMappedSharedBufferDesc* pDesc,
        ID3D11Buffer**                      ppBuffer,
        void**                              ppCpuAddress,
        HANDLE*                             pSharedHandle) = 0;

    virtual HRESULT CreateOptimalSharedTexture2D(
        const D3D11_TEXTURE2D_DESC* pDesc,
        AmdResApiAccessFlags        openByApi,
        AmdResOpenFlags             openFlags,
        ID3D11Texture2D**           ppTexture,
        HANDLE*                     pSharedHandle) = 0;

    virtual HRESULT EnableSharedAccess(
        ID3D11Texture2D*      pTexture2D,
        AmdResAccessFlags     access,
        AmdResMiscAccessFlags flags) = 0;

    virtual HRESULT DisableSharedAccess(
        ID3D11Texture2D*  pTexture2D) = 0;

    virtual HRESULT AcquireSharedTexture(
        ID3D11Texture2D*  pTexture2D) = 0;

    virtual HRESULT ReleaseSharedTexture(
        ID3D11Texture2D*      pTexture2D,
        AmdResMiscAccessFlags flags) = 0;
};

#endif
