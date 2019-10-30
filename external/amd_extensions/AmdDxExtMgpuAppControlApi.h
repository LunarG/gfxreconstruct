/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2014 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
#ifndef _AMDDXEXTMGPUAPPCONTROLAPI_H_
#define _AMDDXEXTMGPUAPPCONTROLAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtMgpuAppControl.h"

const unsigned int AmdDxMgpuAppControlMajorVersion = 1;
const unsigned int AmdDxMgpuAppControlMinorVersion = 4;
// MGPU App Control extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtMgpuAppControlID = 16;

class IAmdDxExtMgpuAppControl : public IAmdDxExtInterface
{
public:

    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // GPU queue control
    virtual VOID    SetRenderGpuMask(UINT gpuMask) = 0;

    // Explicit Transfer
    virtual HRESULT TransferResource(
        ID3D11Resource*     pSrcResource,
        ID3D11Resource*     pDstResource,
        UINT                srcGpuIdx,
        UINT                dstGpuIdx,
        UINT                srcSubResourceIndex,
        UINT                dstSubResourceIndex,
        const D3D11_RECT*   pSrcRegion,
        const D3D11_RECT*   pDstRegion) = 0;

    // GPU enumeration and information
    virtual VOID    GetGpuInfo(AmdAppControlInfo* pInfo) = 0;

    // Resource control across GPUs
    virtual VOID    MarkResourceAsInstanced(ID3D11Resource* pResource) = 0;

    // Sync Object Management
    virtual HANDLE  AllocateSyncObject() = 0;
    virtual VOID    FreeSyncObject(HANDLE syncObject) = 0;

    // Sync Object Control
    virtual VOID    SignalSyncObject(
        HANDLE syncObject,
        UINT gpuIdx,
        AmdAppControlTransferEngineId gfxEngine) = 0;
    virtual BOOL    WaitForSyncObject(
        HANDLE syncObject,
        UINT gpuIdx,
        AmdAppControlTransferEngineId gfxEngine) = 0;

    // Explicit Transfer with specified engine and no implicit synchronization by the driver
    /// @note: Partial transfers (pSrcRegion/pDstRegion) are only allowed when using
    ///        AmdAppControlTransferEngineId3D
    virtual HRESULT TransferResourceEx(
        ID3D11Resource*                 pSrcResource,
        ID3D11Resource*                 pDstResource,
        UINT                            srcGpuIdx,
        UINT                            dstGpuIdx,
        UINT                            srcSubResourceIndex,
        UINT                            dstSubResourceIndex,
        const D3D11_RECT*               pSrcRegion,
        const D3D11_RECT*               pDstRegion,
        AmdAppControlTransferEngineId   desiredTransferEngine,
        BOOL                            performInternalSync) = 0;



};

#endif // _AMDDXEXTMGPUAPPCONTROLAPI_H_
