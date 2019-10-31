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
* @file  amddxextpipapi.h
* @brief
*    AMD D3D Picture-in-Picture (PIP) Exension API include file.
*    This is the main include file for apps using PIP extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTPIPAPI_H_
#define _AMDDXEXTPIPAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include <DXGI.h>
#include <D3D11.h>
#include "AmdDxExtPip.h"

const unsigned int AmdDxPipMajorVersion = 1;
const unsigned int AmdDxPipMinorVersion = 0;

// PIP extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtPipDisplayID = 28;

class IAmdDxExtPipSwapChain;

/**
***************************************************************************************************
* @brief Abstract PIP Display extension interface class
***************************************************************************************************
*/
class IAmdDxExtPipDisplay : public IAmdDxExtInterface
{
public:
    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    //Query PIP caps/mode on given output.
    virtual HRESULT QueryCaps(AmdDxPipDisplayCaps* pDisplayPipModes) = 0;

    // Create a PIP swapchain object
    virtual HRESULT CreateSwapChain(
        IDXGIOutput*                 pDXGIOutput,
        const AmdDxPipSwapChainDesc* pDesc,
        IAmdDxExtPipSwapChain**      ppPipSwapChain) = 0;

    // Destroy a PIP swapchain object
    virtual HRESULT DestroySwapChain(IAmdDxExtPipSwapChain* pPipSwapChain) = 0;
};

/**
***************************************************************************************************
* @brief Abstract PIP SwapChain interface class
***************************************************************************************************
*/
class IAmdDxExtPipSwapChain
{
public:
    // Returns a D3D11 Texture2D object representing the back buffer that application can write to
    virtual HRESULT GetBuffer(ID3D11Texture2D** ppTexture) = 0;

    // Flush the immediate device context and present the back buffer
    virtual HRESULT Present(const AmdDxPipPresentInfo* pPresentInfo) = 0;
};

#endif //_AMDDXEXTPIPAPI_H_
