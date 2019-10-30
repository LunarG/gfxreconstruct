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
* @file  AmdDxExtQbStereoApi.h
* @brief
*    AMD D3D Stereo Exension API include file.
*    This is the main include file for apps using the stereo extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTQBSTEREOAPI_H_
#define _AMDDXEXTQBSTEREOAPI_H_

#include <dxgi.h>

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

// Stereo extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtQuadBufferStereoID = 2;

/**
***************************************************************************************************
* @brief Abstract quad buffer stereo extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtQuadBufferStereo : public IAmdDxExtInterface
{
public:

    virtual HRESULT EnableQuadBufferStereo(BOOL enable) = 0;

    virtual HRESULT GetDisplayModeList(DXGI_FORMAT EnumFormat,
                                       UINT Flags,
                                       UINT *pNumModes,
                                       DXGI_MODE_DESC *pDesc) = 0;

    virtual UINT GetLineOffset(IDXGISwapChain* pSwapChain) = 0;


};

#endif // _AMDDXEXTQBSTEREOAPI_H_