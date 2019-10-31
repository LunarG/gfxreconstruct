/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2015 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is in28tended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  AmdDxExtMultiDrawApi.h
* @brief
*    AMD Multi Draw Indirect Exension API include file.
*    This is the main include file for apps using the Multi Draw Indirect extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTMULTIDRAWAPI_H_
#define _AMDDXEXTMULTIDRAWAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

const unsigned int AmdDxMultiDrawMajorVersion = 1;
const unsigned int AmdDxMultiDrawMinorVersion = 4;
// Samples extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtMultiDrawID = 17;

/**
***************************************************************************************************
* @brief Abstract Samples extension interface class
***************************************************************************************************
*/
class IAmdDxExtMultiDraw : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    virtual HRESULT MultiDrawInstancedIndirect(
        UINT          drawCount,
        ID3D11Buffer* pBufferForArgs,
        UINT          alignedByteOffsetForArgs,
        UINT          byteStrideForArgs) = 0;

    virtual HRESULT MultiDrawIndexedInstancedIndirect(
        UINT          drawCount,
        ID3D11Buffer* pBufferForArgs,
        UINT          alignedByteOffsetForArgs,
        UINT          byteStrideForArgs) = 0;

    virtual HRESULT MultiDrawInstancedIndirectCountIndirect(
        ID3D11Buffer* pBufferForDrawCount,
        UINT          alignedByteOffsetForDrawCount,
        ID3D11Buffer* pBufferForArgs,
        UINT          alignedByteOffsetForArgs,
        UINT          byteStrideForArgs) = 0;

    virtual HRESULT MultiDrawIndexedInstancedIndirectCountIndirect(
        ID3D11Buffer* pBufferForDrawCount,
        UINT          alignedByteOffsetForDrawCount,
        ID3D11Buffer* pBufferForArgs,
        UINT          alignedByteOffsetForArgs,
        UINT          byteStrideForArgs) = 0;

    // Supported with AmdDxMultiDraw version 1.4
    virtual HRESULT MultiDrawInstancedIndirectCtx(
        UINT                 drawCount,
        ID3D11Buffer*        pBufferForArgs,
        UINT                 alignedByteOffsetForArgs,
        UINT                 byteStrideForArgs,
        ID3D11DeviceContext* pCtx) = 0;

    // Supported with AmdDxMultiDraw version 1.4
    virtual HRESULT MultiDrawIndexedInstancedIndirectCtx(
        UINT                 drawCount,
        ID3D11Buffer*        pBufferForArgs,
        UINT                 alignedByteOffsetForArgs,
        UINT                 byteStrideForArgs,
        ID3D11DeviceContext* pCtx) = 0;

    // Supported with AmdDxMultiDraw version 1.4
    virtual HRESULT MultiDrawInstancedIndirectCountIndirectCtx(
        ID3D11Buffer*        pBufferForDrawCount,
        UINT                 alignedByteOffsetForDrawCount,
        ID3D11Buffer*        pBufferForArgs,
        UINT                 alignedByteOffsetForArgs,
        UINT                 byteStrideForArgs,
        ID3D11DeviceContext* pCtx) = 0;

    // Supported with AmdDxMultiDraw version 1.4
    virtual HRESULT MultiDrawIndexedInstancedIndirectCountIndirectCtx(
        ID3D11Buffer*        pBufferForDrawCount,
        UINT                 alignedByteOffsetForDrawCount,
        ID3D11Buffer*        pBufferForArgs,
        UINT                 alignedByteOffsetForArgs,
        UINT                 byteStrideForArgs,
        ID3D11DeviceContext* pCtx) = 0;
};

#endif //_AMDDXEXTMULTIDRAWAPI_H_
