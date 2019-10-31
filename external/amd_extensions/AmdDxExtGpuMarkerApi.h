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
* @file  amddxextgpumarkerapi.h
* @brief
*    AMD D3D GPU Marker Exension API include file.
*    This is the main include file for apps using marker extension.
***************************************************************************************************
*/
#ifndef _AMDDXEXTGPUMARKERAPI_H_
#define _AMDDXEXTGPUMARKERAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtGpuMarker.h"

const unsigned int AmdDxGpuMarkerMajorVersion = 1;
const unsigned int AmdDxGpuMarkerMinorVersion = 0;

// Marker extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtGpuMarkerID = 29;

/**
***************************************************************************************************
* @brief Abstract gpu marker extension interface class
***************************************************************************************************
*/
class IAmdDxExtGpuMarker : public IAmdDxExtInterface
{
public:
    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    virtual HRESULT CreateMarkerBuffer(AmdDxExtMarkerBufferCreateInfo* pCreateInfo) = 0;

    virtual HRESULT WriteMarker(AmdDxExtGpuMarkerWriteInfo* pWriteInfo) = 0;

    virtual HRESULT ReleaseMarkerBuffer(AmdDxExtMarkerBufferHandle* pBufferHandle) = 0;
};

#endif //_AMDDXEXTGPUMARKERAPI_H_