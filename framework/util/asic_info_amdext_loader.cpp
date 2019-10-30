//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author Esen Yilmaz
/// \file   asic_info_amdext_loader.cpp
//=============================================================================

#include "logging.h"
#include "asic_info_amdext_loader.h"

bool AsicInfoAmdExtLoader::GetAsicInfo(AmdDxASICInfo* pAsicInfo)
{
#ifdef _WIN32
    if (nullptr == pAsicInfo)
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: NULL pAsicInfo received from client", __FUNCTION__);
        return false;
    }

    HRESULT hr = E_FAIL;

    ID3D11Device*        pDevice;
    ID3D11DeviceContext* pDeviceContext;
    D3D_FEATURE_LEVEL    FeatureLevelsRequested    = D3D_FEATURE_LEVEL_11_0;
    UINT                 numFeatureLevelsRequested = 1;
    D3D_FEATURE_LEVEL    FeatureLevelsSupported;
    hr = D3D11CreateDevice(NULL,
                           D3D_DRIVER_TYPE_HARDWARE,
                           NULL,
                           0,
                           &FeatureLevelsRequested,
                           numFeatureLevelsRequested,
                           D3D11_SDK_VERSION,
                           &pDevice,
                           &FeatureLevelsSupported,
                           &pDeviceContext);
    if (FAILED(hr))
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not create ID3D11Device", __FUNCTION__);
        return false;
    }

    HMODULE g_hDLL;

#if defined _WIN64
    g_hDLL = GetModuleHandle(TEXT("atidxx64.dll"));
#else
    g_hDLL = GetModuleHandle(TEXT("atidxx32.dll"));
#endif

    if (nullptr == g_hDLL)
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not get driver module handle", __FUNCTION__);
        return false;
    }

    PFNAmdDxExtCreate11 pFnDxExtCreateFunc = (PFNAmdDxExtCreate11)GetProcAddress(g_hDLL, "AmdDxExtCreate11");
    if (nullptr == pFnDxExtCreateFunc)
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not to get proc address for AmdDxExtCreate11", __FUNCTION__);
        return false;
    }

    IAmdDxExt* pEXT;
    hr = pFnDxExtCreateFunc(pDevice, &pEXT);
    if (FAILED(hr))
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not create main extension interface", __FUNCTION__);
        return false;
    }

    if (nullptr == pEXT)
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: extension interface successfully retrieved but it is NULL", __FUNCTION__);
        return false;
    }

    AmdDxExtVersion extVersion;
    hr = pEXT->GetVersion(&extVersion);
    if (FAILED(hr))
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not driver extension version", __FUNCTION__);
        return false;
    }

    IAmdDxExtASICInfo* pAIE = static_cast<IAmdDxExtASICInfo*>(pEXT->GetExtInterface(AmdDxExtASICInfoID));
    if (nullptr == pAIE)
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: driver does not support ASIC Info ID extension", __FUNCTION__);
        return false;
    }

    AmdDxASICInfoParam asicInfoParam = { 0 };
    AmdDxASICInfo      asicInfo;
    asicInfoParam.pASICInfo = &asicInfo;
    hr                      = pAIE->GetInfoData(&asicInfoParam);
    if (FAILED(hr))
    {
        GFXRECON_LOG_ERROR("[%s]: ERROR: could not get ASIC info", __FUNCTION__);
        return false;
    }

    *pAsicInfo = asicInfo;

    return true;
#else
    GFXRECON_LOG_ERROR("GetAsicInfo function only supported in Windows.");
    return false;
#endif
}