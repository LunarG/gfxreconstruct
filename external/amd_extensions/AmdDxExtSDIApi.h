/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2013 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextsdiapi.h
* @brief
*    AMD D3D SDI Exension API include file.
*    This is the main include file for apps using Hi Z extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSDIAPI_H_
#define _AMDDXEXTSDIAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtSDI.h"

// AMD extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtSDIID = 6;

/**
***************************************************************************************************
* @brief Abstract SDI extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtSDI : public IAmdDxExtInterface
{
public:
    virtual HRESULT QuerySDIAllocationAddress(AmdDxSDIQueryAllocInfo *pInfo) = 0;
    virtual HRESULT MakeResidentSDISurfaces(AmdDxLocalSDISurfaceList *pList) = 0;
    virtual BOOL WriteMarker(ID3D10Resource *pResource, AmdDxMarkerInfo *pMarkerInfo) = 0;
    virtual BOOL WaitMarker(ID3D10Resource *pResource, UINT val) = 0;
    virtual BOOL WriteMarker11(ID3D11Resource *pResource, AmdDxMarkerInfo *pMarkerInfo) = 0;
    virtual BOOL WaitMarker11(ID3D11Resource *pResource, UINT val) = 0;
    virtual HRESULT CreateSDIAdapterSurfaces(AmdDxRemoteSDISurfaceList *pList) = 0;
    virtual HRESULT SetPinnedSysMemAddress(UINT *pSysMem) = 0;
    virtual HRESULT SyncPixelBuffer(ID3D10Resource *pResource, AmdDxSDISyncInfo* pSyncInfo) = 0;
    virtual HRESULT SyncPixelBuffer11(ID3D11Resource *pResource, AmdDxSDISyncInfo* pSyncInfo) = 0;
    virtual HRESULT DestroySDIAdapterSurfaces(AmdDxRemoteSDISurfaceList *pList) = 0;
};

#endif //_AMDDXEXTSDIAPI_H_
