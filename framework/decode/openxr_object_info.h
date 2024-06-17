/*
** Copyright (c) 2019-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_OPENXR_OBJECT_INFO_H
#define GFXRECON_DECODE_OPENXR_OBJECT_INFO_H

#if ENABLE_OPENXR_SUPPORT

//#include "decode/openxr_resource_allocator.h"
//#include "decode/openxr_resource_initializer.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//
// Structures for storing OpenXR object info.
//

template <typename T>
struct OpenXrObjectInfo
{
    typedef T HandleType;

    // Standard info stored for all OpenXr objects.
    HandleType       handle{ XR_NULL_HANDLE };            // Handle created for the object during replay.
    format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
    format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
};

template <typename T>
struct OpenXrAtomInfo
{
    typedef T HandleType;

    // Standard info stored for all OpenXr objects.
    HandleType       handle{ 0 };                         // Handle created for the object during replay.
    format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
    format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
};

//
// Declarations for OpenXr objects without additional replay state info.
//

typedef OpenXrObjectInfo<XrAction>                           OpenXrActionInfo;
typedef OpenXrObjectInfo<XrActionSet>                        OpenXrActionSetInfo;
typedef OpenXrObjectInfo<XrInstance>                         OpenXrInstanceInfo;
typedef OpenXrObjectInfo<XrSession>                          OpenXrSessionInfo;
typedef OpenXrObjectInfo<XrSpace>                            OpenXrSpaceInfo;
typedef OpenXrObjectInfo<XrSwapchain>                        OpenXrSwapchainInfo;
typedef OpenXrObjectInfo<XrDebugUtilsMessengerEXT>           OpenXrDebugUtilsMessengerEXTInfo;
typedef OpenXrObjectInfo<XrHandTrackerEXT>                   OpenXrHandTrackerEXTInfo;
typedef OpenXrObjectInfo<XrPlaneDetectorEXT>                 OpenXrPlaneDetectorEXTInfo;
typedef OpenXrObjectInfo<XrBodyTrackerFB>                    OpenXrBodyTrackerFBInfo;
typedef OpenXrObjectInfo<XrEyeTrackerFB>                     OpenXrEyeTrackerFBInfo;
typedef OpenXrObjectInfo<XrFaceTrackerFB>                    OpenXrFaceTrackerFBInfo;
typedef OpenXrObjectInfo<XrFaceTracker2FB>                   OpenXrFaceTracker2FBInfo;
typedef OpenXrObjectInfo<XrFoveationProfileFB>               OpenXrFoveationProfileFBInfo;
typedef OpenXrObjectInfo<XrGeometryInstanceFB>               OpenXrGeometryInstanceFBInfo;
typedef OpenXrObjectInfo<XrPassthroughFB>                    OpenXrPassthroughFBInfo;
typedef OpenXrObjectInfo<XrPassthroughLayerFB>               OpenXrPassthroughLayerFBInfo;
typedef OpenXrObjectInfo<XrSpaceUserFB>                      OpenXrSpaceUserFBInfo;
typedef OpenXrObjectInfo<XrTriangleMeshFB>                   OpenXrTriangleMeshFBInfo;
typedef OpenXrObjectInfo<XrFacialTrackerHTC>                 OpenXrFacialTrackerHTCInfo;
typedef OpenXrObjectInfo<XrPassthroughHTC>                   OpenXrPassthroughHTCInfo;
typedef OpenXrObjectInfo<XrVirtualKeyboardMETA>              OpenXrVirtualKeyboardMETAInfo;
typedef OpenXrObjectInfo<XrPassthroughColorLutMETA>          OpenXrPassthroughColorLutMETAInfo;
typedef OpenXrObjectInfo<XrMarkerDetectorML>                 OpenXrMarkerDetectorMLInfo;
typedef OpenXrObjectInfo<XrExportedLocalizationMapML>        OpenXrExportedLocalizationMapMLInfo;
typedef OpenXrObjectInfo<XrSceneMSFT>                        OpenXrSceneMSFTInfo;
typedef OpenXrObjectInfo<XrSceneObserverMSFT>                OpenXrSceneObserverMSFTInfo;
typedef OpenXrObjectInfo<XrSpatialAnchorMSFT>                OpenXrSpatialAnchorMSFTInfo;
typedef OpenXrObjectInfo<XrSpatialAnchorStoreConnectionMSFT> OpenXrSpatialAnchorStoreConnectionMSFTInfo;
typedef OpenXrObjectInfo<XrSpatialGraphNodeBindingMSFT>      OpenXrSpatialGraphNodeBindingMSFTInfo;

typedef OpenXrAtomInfo<XrSystemId>               OpenXrSystemIdInfo;
typedef OpenXrAtomInfo<XrPath>                   OpenXrPathInfo;
typedef OpenXrAtomInfo<XrAsyncRequestIdFB>       OpenXrAsyncRequestIdFBInfo;
typedef OpenXrAtomInfo<XrRenderModelKeyFB>       OpenXrRenderModelKeyFBInfo;
typedef OpenXrAtomInfo<XrMarkerML>               OpenXrMarkerMLInfo;
typedef OpenXrAtomInfo<XrControllerModelKeyMSFT> OpenXrControllerModelKeyMSFTInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_OBJECT_INFO_H
