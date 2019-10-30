/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2012 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxexthsainteropapi.h
* @brief
*    AMD HSA DX Interop Exension API include file.
*    This is the main include file for apps using the HSA DX Interop extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTHSAINTEROPAPI_H_
#define _AMDDXEXTHSAINTEROPAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtHSAInterop.h"

// AMD extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtHSADXInteropID = 14;

/**
***************************************************************************************************
* @brief Abstract HSA DX Interop extension interface class for D3D10/D3D11
*
***************************************************************************************************
*/
class IAmdDxExtHSAInterop : public IAmdDxExtInterface
{
public:
    virtual HRESULT CreateCpuBuffer10(const D3D10_BUFFER_DESC* pDesc,
                                      LPVOID pExistingSysMem,
                                      ID3D10Buffer** ppBuffer) = 0;

    virtual HRESULT CreateCpuBuffer11(const D3D11_BUFFER_DESC* pDesc,
                                      LPVOID pExistingSysMem,
                                      ID3D11Buffer** ppBuffer) = 0;

    virtual HRESULT GetResourceSize10(ID3D10Resource* pResource,
                                      UINT64* pResourceSize) = 0;

    virtual HRESULT GetResourceSize11(ID3D11Resource* pResource,
                                      UINT64*         pResourceSize) = 0;

    virtual HRESULT GetResourceBaseVa10(ID3D10Resource*  pResource,
                                        VIRTUAL_ADDRESS* pResourceVa) = 0;

    virtual HRESULT GetResourceBaseVa11(ID3D11Resource*  pResource,
                                        VIRTUAL_ADDRESS* pResourceVa) = 0;

    virtual HRESULT MakeResourcesResidentOnGpu10(ID3D10Resource** pResources,
                                                 UINT numResources) = 0;

    virtual HRESULT MakeResourcesResidentOnGpu11(ID3D11Resource** pResources,
                                                 UINT numResources) = 0;

    virtual HRESULT ReleaseResidentResourcesOnGpu() = 0;

    virtual HRESULT GetPsShaderResourceViewStateSize(UINT slot,
                                                     UINT* pSRViewStateSize) = 0;

    virtual HRESULT GetPsShaderResourceViewState(UINT slot,
                                                 VOID* pSRViewState) = 0;

    virtual HRESULT GetPsSamplerStateSize(UINT slot,
                                          UINT* pSamplerStateSize) = 0;

    virtual HRESULT GetPsSamplerState(UINT slot,
                                      VOID* pSamplerStateSRD) = 0;

    virtual HRESULT GetPsUnorderedAccessViewStateSize(UINT slot,
                                                      UINT* pUAViewStateSize) = 0;

    virtual HRESULT GetPsUnorderedAccessViewState(UINT slot,
                                                  VOID* pUAViewState) = 0;
};


#endif //_AMDDXEXTHSAINTEROPAPI_H_