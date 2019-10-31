/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2015 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextsyncapi.h
* @brief
*    AMD GPU Sync Extension API include file.
*    This is the main include file for apps using GPU sync extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTSYNCAPI_H_
#define _AMDDXEXTSYNCAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtSync.h"

const unsigned int AmdDxSyncMajorVersion = 1;
const unsigned int AmdDxSyncMinorVersion = 1;
// Sync extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtSyncID = 18;

/**
***************************************************************************************************
* @brief Abstract DX sync extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtSync : public IAmdDxExtInterface
{
public:
    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // Flush with event for tracking completion
    virtual HRESULT FlushWithEvent(UINT gpuIdx, HANDLE hEvent) = 0;

    // GPU synchronization
    virtual HRESULT CreateGpuSemaphore(UINT initialCount, HANDLE* pSyncObject) = 0;
    virtual VOID    DestroyGpuSemaphore(HANDLE syncObject) = 0;
    virtual HRESULT EnqueueSignalSemaphore(
        HANDLE syncObject,
        UINT gpuIdx,
        AmdGpuEngine engineId) = 0;
    virtual HRESULT EnqueueWaitSemaphore(
        HANDLE syncObject,
        UINT gpuIdx,
        AmdGpuEngine engineId) = 0;

};

#endif //_AMDDXEXTSYNCAPI_H_
