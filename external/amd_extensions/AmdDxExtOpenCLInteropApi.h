/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2011 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextopenclinteropapi.h
* @brief
*    AMD D3D OpenCL Interop Exension API include file.
*    This is the main include file for apps using OpenCL Interop extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTOPENCLAPI_H_
#define _AMDDXEXTOPENCLAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

// OpenCL Interop extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtCLInteropID = 7;

struct ID3D10Resource;
struct ID3D11Resource;

/**
***************************************************************************************************
* @brief Abstract OpenCL Interop extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtCLInterop : public IAmdDxExtInterface
{
public:
    virtual HRESULT QueryInteropGpuMask(UINT* pGpuIdBitmask) = 0;

    virtual HRESULT CLAcquireResource(ID3D10Resource* pResource, UINT gpuIdBitmask) = 0;
    virtual HRESULT CLReleaseResource(ID3D10Resource* pResource, UINT gpuIdBitmask) = 0;

    virtual HRESULT CLAcquireResource11(ID3D11Resource* pResource, UINT gpuIdBitmask) = 0;
    virtual HRESULT CLReleaseResource11(ID3D11Resource* pResource, UINT gpuIdBitmask) = 0;
};

#endif //_AMDDXEXTOPENCLAPI_H_
