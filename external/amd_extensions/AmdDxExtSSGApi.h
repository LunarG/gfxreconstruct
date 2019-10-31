/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2016 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
#ifndef _AMDDXEXTSSGAPI_H_
#define _AMDDXEXTSSGAPI_H_

/**
***************************************************************************************************
* @file  AmdDxExtSSGApi.h
* @brief AMD SSG Extension API include file
***************************************************************************************************
*/

#include <d3d11.h>

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtSSG.h"

const unsigned int AmdDxSSGMajorVersion = 1;
const unsigned int AmdDxSSGMinorVersion = 0;

// Extended SSG extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtSsgID = 22;

/**
***************************************************************************************************
* @brief Abstract extended SSG interface class
*
***************************************************************************************************
*/
class IAmdDxExtSSG : public IAmdDxExtInterface
{
public:
    // Version information
    virtual HRESULT GetExtensionVersion(AmdDxSsgVersion* pVersion) = 0;

    // Open or create a file and get a SSG file handle for it
    // The handle will be used later in data transfer calls
    virtual HRESULT CreateFile(const WCHAR* pFileName, AmdDxSsgFileAccess fileAccess,
                               AmdDxSsgFileHandle* phFile) = 0;

    // Release a file when it is no longer used
    virtual HRESULT ReleaseFile(AmdDxSsgFileHandle hFile) = 0;

    // Get size information of a file
    // File transfer in SSG EXT requires that transfer size & offset be aligned to block
    // boundary
    virtual HRESULT GetFileInfo(AmdDxSsgFileHandle hFile, AmdDxSsgFileInfo* pInfo) = 0;

    // Create an event to use in asynchronous file transfer
    virtual HRESULT CreateEvent(AmdDxSsgEventHandle* phEvent) = 0;

    // Delete an event
    virtual HRESULT DestroyEvent(AmdDxSsgEventHandle hEvent) = 0;

    // Wait for an asynchronous file transfer to complete
    // The event handle should have been submitted in a previous transfer call
    virtual HRESULT WaitEvent(AmdDxSsgEventHandle hEvent) = 0;

    // P2P transfer file data to a D3D11 buffer
    virtual HRESULT ReadBufferFromFile(ID3D11Buffer* pBuffer, AmdDxSsgFileHandle hFile, UINT numRegions,
                                       AmdDxSsgRegionDesc* pRegions, AmdDxSsgEventHandle hEvent) = 0;

    // P2P transfer D3D11 buffer data to a file
    virtual HRESULT WriteBufferToFile(ID3D11Buffer* pBuffer, AmdDxSsgFileHandle hFile, UINT numRegions,
                                      AmdDxSsgRegionDesc* pRegions, AmdDxSsgEventHandle hEvent) = 0;

};

#endif // _AMDDXEXTSSGAPI_H_

