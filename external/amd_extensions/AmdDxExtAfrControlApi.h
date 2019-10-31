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
#ifndef _AMDDXEXTAFRCONTROLAPI_H_
#define _AMDDXEXTAFRCONTROLAPI_H_

/**
***************************************************************************************************
* @file  AmdDxExtAfrControlApi.h
* @brief AMD AFR Control Extension API include file
***************************************************************************************************
*/

#include <d3d11.h>

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtAfrControl.h"

const unsigned int AmdDxAfrControlMajorVersion = 1;
const unsigned int AmdDxAfrControlMinorVersion = 6;

// Extended AFR control extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtAfrControlID = 20;

/**
***************************************************************************************************
* @brief Abstract extended AFR control interface class
*
***************************************************************************************************
*/
class IAmdDxExtAfrControl : public IAmdDxExtInterface
{
public:
    // Version information
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    // Enable AFR control API.  Should be called before creating resources to signal intent to
    // use the AFR control API.
    virtual VOID EnableAfrControl() = 0;

    // Create resource methods with transfer type specifier
    virtual HRESULT CreateBuffer(const D3D11_BUFFER_DESC*           pDesc,
                                 const D3D11_SUBRESOURCE_DATA*      pInitialData,
                                 ID3D11Buffer**                     ppBuffer,
                                 AmdAfrTransferType                 transferType) = 0;
    virtual HRESULT CreateTexture1D(const D3D11_TEXTURE1D_DESC*     pDesc,
                                    const D3D11_SUBRESOURCE_DATA*   pInitialData,
                                    ID3D11Texture1D**               ppTexture1D,
                                    AmdAfrTransferType              transferType) = 0;
    virtual HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC*     pDesc,
                                    const D3D11_SUBRESOURCE_DATA*   pInitialData,
                                    ID3D11Texture2D**               ppTexture2D,
                                    AmdAfrTransferType              transferType) = 0;
    virtual HRESULT CreateTexture3D(const D3D11_TEXTURE3D_DESC*     pDesc,
                                    const D3D11_SUBRESOURCE_DATA*   pInitialData,
                                    ID3D11Texture3D**               ppTexture3D,
                                    AmdAfrTransferType              transferType) = 0;

    // Return the number of GPUs the UMD will use for rendering (as opposed to the number in the
    // system).  Using this allows the UMD app profile to clamp the number of GPUs returned.
    virtual UINT GetNumRenderGpus() = 0;

    // This will initiate a transfer for AmdAfrTransferApp1StepP2P,
    // AmdAfrTransferApp2StepNoBroadcast, and AmdAfrTransferApp2StepWithBroadcast.
    // If a subregion is specified and something other than AmdAfrTransferApp2StepWithBroadcast is used
    // for more than 2 GPUs, it is the app's responsibility to propagate the subregions to all GPUs.
    virtual void NotifyResourceEndWrites(ID3D11Resource*    pResource,
                                         const D3D11_RECT*  pTransferRegion,
                                         const UINT*        pSubresourceIndex) = 0;

    // This will notify the driver that the app will begin read/write access to the resource.
    virtual void NotifyResourceBeginAllAccess(ID3D11Resource* pResource) = 0;

    // This is used for AmdAfrTransferApp1StepP2P to notify when it is safe to initiate a transfer.
    // This call in frame N-(NumGpus-1) allows a 1 step P2P in frame N to start.
    // This should be called after NotifyResourceEndWrites.
    virtual void NotifyResourceEndAllAccess(ID3D11Resource* pResource) = 0;

    // Same as NotifyResourceEndWrites, but allows for multiple subresources and transfer regions
    // to be transferred.  The size of the arrays pointed to by pTransferRegions and
    // pSubresourceIndices if non-NULL is indicated by numEntries.  If pSubresourceIndices is NULL
    // and pTransferRegions is non-NULL, all transfer regions are applied to subresource 0.
    // If numEntries is zero, all subresources are transferred.
    virtual void NotifyResourceEndWritesEx(ID3D11Resource*      pResource,
                                           const D3D11_RECT*    pTransferRegions,
                                           const UINT*          pSubresourceIndices,
                                           UINT                 numEntries) = 0;

    // Create resource methods with transfer type and engine specifier.  Supported in
    // version 1.3 and higher of this API.
    virtual HRESULT CreateBufferEx(const D3D11_BUFFER_DESC*         pDesc,
                                   const D3D11_SUBRESOURCE_DATA*    pInitialData,
                                   ID3D11Buffer**                   ppBuffer,
                                   AmdAfrTransferType               transferType,
                                   AmdAfrTransferEngine             transferEngine) = 0;
    virtual HRESULT CreateTexture1DEx(const D3D11_TEXTURE1D_DESC*   pDesc,
                                      const D3D11_SUBRESOURCE_DATA* pInitialData,
                                      ID3D11Texture1D**             ppTexture1D,
                                      AmdAfrTransferType            transferType,
                                      AmdAfrTransferEngine          transferEngine) = 0;
    virtual HRESULT CreateTexture2DEx(const D3D11_TEXTURE2D_DESC*   pDesc,
                                      const D3D11_SUBRESOURCE_DATA* pInitialData,
                                      ID3D11Texture2D**             ppTexture2D,
                                      AmdAfrTransferType            transferType,
                                      AmdAfrTransferEngine          transferEngine) = 0;
    virtual HRESULT CreateTexture3DEx(const D3D11_TEXTURE3D_DESC*   pDesc,
                                      const D3D11_SUBRESOURCE_DATA* pInitialData,
                                      ID3D11Texture3D**             ppTexture3D,
                                      AmdAfrTransferType            transferType,
                                      AmdAfrTransferEngine          transferEngine) = 0;

    // Version 1.4
    // Control Crossfire Visual Confirm output.
    virtual void SetVisualConfirmationMode(AmdCrossfireVisualConfirmationMode outputMode) = 0;

    // Version 1.5
    // Get the AFR unfriendly resources.  This method should be called twice per retrieval.
    // The first call is for array sizing.  It should be called with pResourceInfo set to NULL,
    // and pNumResources should point to memory to store the number of resources with transfers.
    //
    // The second actually retrieves the transferred resources.  pResourceInfo should point to
    // enough space for an array with *pNumResources elements.  This method will populate the
    // pResourceInfo array up to *pNumResources elements and will update *pNumResources with the
    // actual number of elements in the array.
    //
    // This two-step retrieval can be called multiple times during the app's execution to retrieve
    // the latest transfer counts for unfriendly resources.
    virtual HRESULT GetUnfriendlyResources(AmdAfrResourceXferInfo*  pResourceInfo,
                                           UINT*                    pNumResources) = 0;
    // Version 1.6
    // This method starts logging of unfriendly resources for use with the GetUnfriendlyResources.
    // Thus, it should be called before the first call to GetUnfriendlyResources.
    virtual HRESULT StartLoggingUnfriendlyResources() = 0;

    // This optional method stops logging of unfriendly resources.  If used, it should be only
    // called if logging is in progress via after calling StartLoggingUnfriendlyResources.  The
    // Start/Stop methods can be used multiple times to turn on/off logging.
    virtual HRESULT StopLoggingUnfriendlyResources() = 0;
};

#endif // _AMDDXEXTAFRCONTROLAPI_H_
