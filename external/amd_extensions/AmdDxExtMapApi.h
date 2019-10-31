/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2010 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextmapapi.h
* @brief
*    AMD D3D Extended Mapping Extension API include file.
*    This is the main include file for apps using the Extended Map extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTMAPAPI_H_
#define _AMDDXEXTMAPAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

// Extended map extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtMapID = 12;

/**
***************************************************************************************************
* @brief Abstract extended map extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtMap : public IAmdDxExtInterface
{
public:
    virtual HRESULT CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
                                 const D3D11_SUBRESOURCE_DATA* pInitialData,
                                 ID3D11Buffer** ppBuffer) = 0;
    virtual HRESULT CreateTexture1D(const D3D11_TEXTURE1D_DESC* pDesc,
                                    const D3D11_SUBRESOURCE_DATA* pInitialData,
                                    ID3D11Texture1D** ppTexture1D) = 0;
    virtual HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
                                    const D3D11_SUBRESOURCE_DATA* pInitialData,
                                    ID3D11Texture2D** ppTexture2D) = 0;
    virtual HRESULT CreateTexture3D(const D3D11_TEXTURE3D_DESC* pDesc,
                                    const D3D11_SUBRESOURCE_DATA* pInitialData,
                                    ID3D11Texture3D** ppTexture3D) = 0;
    virtual VOID Map(ID3D11Resource* pResource,
                     UINT subresource,
                     D3D11_MAP mapType,
                     UINT mapFlags,
                     D3D11_MAPPED_SUBRESOURCE* pMappedResource) = 0;
    virtual VOID Unmap(ID3D11Resource* pResource, UINT subresource) = 0;
};

#endif // _AMDDXEXTMAPAPI_H_
