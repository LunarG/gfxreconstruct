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

/**
***************************************************************************************************
* @file  amddxextmultiviewapi.h
* @brief
*    AMD MultiView Exension API include file.
*    This is the main include file for apps using the MultiView extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTMULTIVIEWAPI_H_
#define _AMDDXEXTMULTIVIEWAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtMultiView.h"

const unsigned int AmdDxMultiViewMajorVersion = 1;
const unsigned int AmdDxMultiViewMinorVersion = 1;
// Sync extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtMultiViewID = 23;

/**
***************************************************************************************************
* @brief Abstract MultiView extension interface class
***************************************************************************************************
*/
class IAmdDxExtMultiView : public IAmdDxExtInterface
{
public:
    // Extension version
    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVersion) = 0;

    // Viewport and RT slice broadcasting mask control
    // If vpMaskPerRtSlice = FALSE, bits 0..15 of vpMask are applied to each RT slice and bits 16-63
    // are ignored, otherwise bits 0..15 of vpMask are applied to RT slices 0, 4, 8, ...; bits 16-31
    // to slices 1, 5, ...; bits 32-47 to slices 2, 6, ...; bits 48-63 to slices 3, 7, ....
    virtual HRESULT SetViewBroadcastMasks(UINT64 vpMask,
                                          UINT64 rtSliceMask,
                                          BOOL   vpMaskPerRtSlice) = 0;
    // Query max simultaneous clip rects
    virtual UINT GetMaxClipRects() = 0;
    // Apply new set of clip rects
    virtual HRESULT SetClipRects(UINT clipRectCount, const AmdDxClipRect* pClipRects) = 0;
};

#endif //_AMDDXEXTMULTIVIEWAPI_H_
