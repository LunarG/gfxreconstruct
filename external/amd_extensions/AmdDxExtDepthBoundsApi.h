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
* @file  amddxextdepthboundsapi.h
* @brief
*    AMD D3D Depth Bounds Extension API include file.
*    This is the main include file for apps using the Depth Bounds extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTDEPTHBOUNDSAPI_H_
#define _AMDDXEXTDEPTHBOUNDSAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

const unsigned int AmdDxDepthBoundsMajorVersion = 1;
const unsigned int AmdDxDepthBoundsMinorVersion = 1;

// Depth Bounds extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtDepthBoundsID = 11;

/**
***************************************************************************************************
* @brief Abstract Depth Bounds extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtDepthBounds : public IAmdDxExtInterface
{
public:
    virtual HRESULT SetDepthBounds(BOOL enabled, FLOAT minDepth, FLOAT maxDepth) = 0;

    // Added with DXX Ext version 9.1, Depth bounds version 1.1
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // Added with DXX Ext version 9.1, Depth bounds version 1.1
    virtual HRESULT SetDepthBoundsCtx(BOOL enabled,
                                      FLOAT minDepth,
                                      FLOAT maxDepth,
                                      ID3D11DeviceContext* pCtx) = 0;
};

#endif //_AMDDXEXTDEPTHBOUNDSAPI_H_
