/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2017 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  AmdDxExtCreateDeviceApi.h
* @brief
*    AMD CreateDevice Exension API include file.
*    This is the main include file for apps using the CreateDevice extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTCREATEDEVICEEXTAPI_H_
#define _AMDDXEXTCREATEDEVICEEXTAPI_H_

#include <d3d11.h>
#include "AmdDxExtCreateDeviceExt.h"
#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

HRESULT WINAPI AmdD3D11CreateDeviceExt(
    IDXGIAdapter*            pAdapter,
    D3D_DRIVER_TYPE          DriverType,
    HMODULE                  Software,
    UINT                     Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT                     FeatureLevels,
    UINT                     SDKVersion,
    ID3D11Device**           ppDevice,
    D3D_FEATURE_LEVEL*       pFeatureLevel,
    ID3D11DeviceContext**    ppImmediateContext,
    AmdExtCreateDeviceInfo*  pAmdExtParam);        ///< Custom creation parameter

typedef HRESULT (WINAPI *PFNAmdD3D11CreateDeviceExt)(
    IDXGIAdapter*            pAdapter,
    D3D_DRIVER_TYPE          DriverType,
    HMODULE                  Software,
    UINT                     Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT                     FeatureLevels,
    UINT                     SDKVersion,
    ID3D11Device**           ppDevice,
    D3D_FEATURE_LEVEL*       pFeatureLevel,
    ID3D11DeviceContext**    ppImmediateContext,
    AmdExtCreateDeviceInfo*  pAmdExtParam);        ///< Custom creation parameter

HRESULT WINAPI AmdD3D11CreateDeviceAndSwapChainExt(
    IDXGIAdapter*               pAdapter,
    D3D_DRIVER_TYPE             DriverType,
    HMODULE                     Software,
    UINT                        Flags,
    const D3D_FEATURE_LEVEL*    pFeatureLevels,
    UINT                        FeatureLevels,
    UINT                        SDKVersion,
    const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain**            ppSwapChain,
    ID3D11Device**              ppDevice,
    D3D_FEATURE_LEVEL*          pFeatureLevel,
    ID3D11DeviceContext**       ppImmediateContext,
    AmdExtCreateDeviceInfo*     pAmdExtParam);  ///< Custom creation parameter

typedef HRESULT (WINAPI *PFNAmdD3D11CreateDeviceAndSwapChainExt)(
    IDXGIAdapter*               pAdapter,
    D3D_DRIVER_TYPE             DriverType,
    HMODULE                     Software,
    UINT                        Flags,
    const D3D_FEATURE_LEVEL*    pFeatureLevels,
    UINT                        FeatureLevels,
    UINT                        SDKVersion,
    const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain**            ppSwapChain,
    ID3D11Device**              ppDevice,
    D3D_FEATURE_LEVEL*          pFeatureLevel,
    ID3D11DeviceContext**       ppImmediateContext,
    AmdExtCreateDeviceInfo*     pAmdExtParam);  ///< Custom creation parameter

#endif //_AMDDXEXTCREATEDEVICEEXTAPI_H_
