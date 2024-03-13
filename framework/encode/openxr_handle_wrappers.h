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

#ifndef GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_state_info.h"
#include "format/format.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <limits>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

//
// Handle wrappers for storing object state information with object handles.
//

template <typename T>
struct HandleWrapper
{
    typedef T HandleType;

    // Dispatch table key for dispatchable handles. Must be the first struct member to be compatible with the
    // loader defined handles.
    void* dispatch_key{ nullptr };

    // Standard state info required for all handles.
    HandleType        handle{ XR_NULL_HANDLE };           // Original handle value provided by the driver.
    format::HandleId  handle_id{ format::kNullHandleId }; // Globally unique ID assigned to the handle by the layer.
    format::ApiCallId create_call_id{ format::ApiCallId::ApiCall_Unknown };
    openxr_state_info::CreateParameters create_parameters;
};

//
// Type definitions for handle wrappers that do not require additional state info.
//

// clang-format off
struct SpaceWrapper : public HandleWrapper<XrSpace> {};
struct ActionWrapper : public HandleWrapper<XrAction> {};
struct SwapchainWrapper : public HandleWrapper<XrSwapchain> {};
struct DebugUtilsMessengerEXTWrapper : public HandleWrapper<XrDebugUtilsMessengerEXT> {};
struct SpatialAnchorMSFTWrapper : public HandleWrapper<XrSpatialAnchorMSFT> {};
struct SpatialGraphNodeBindingMSFTWrapper : public HandleWrapper<XrSpatialGraphNodeBindingMSFT> {};
struct HandTrackerEXTWrapper : public HandleWrapper<XrHandTrackerEXT> {};
struct BodyTrackerFBWrapper : public HandleWrapper<XrBodyTrackerFB> {};
struct SceneObserverMSFTWrapper : public HandleWrapper<XrSceneObserverMSFT> {};
struct SceneMSFTWrapper : public HandleWrapper<XrSceneMSFT> {};
struct FacialTrackerHTCWrapper : public HandleWrapper<XrFacialTrackerHTC> {};
struct FoveationProfileFBWrapper : public HandleWrapper<XrFoveationProfileFB> {};
struct TriangleMeshFBWrapper : public HandleWrapper<XrTriangleMeshFB> {};
struct PassthroughLayerFBWrapper : public HandleWrapper<XrPassthroughLayerFB> {};
struct GeometryInstanceFBWrapper : public HandleWrapper<XrGeometryInstanceFB> {};
struct MarkerDetectorMLWrapper : public HandleWrapper<XrMarkerDetectorML> {};
struct ExportedLocalizationMapMLWrapper : public HandleWrapper<XrExportedLocalizationMapML> {};
struct SpatialAnchorStoreConnectionMSFTWrapper : public HandleWrapper<XrSpatialAnchorStoreConnectionMSFT> {};
struct SpaceUserFBWrapper : public HandleWrapper<XrSpaceUserFB> {};
struct FaceTrackerFBWrapper : public HandleWrapper<XrFaceTrackerFB> {};
struct EyeTrackerFBWrapper : public HandleWrapper<XrEyeTrackerFB> {};
struct VirtualKeyboardMETAWrapper : public HandleWrapper<XrVirtualKeyboardMETA> {};
struct PassthroughColorLutMETAWrapper : public HandleWrapper<XrPassthroughColorLutMETA> {};
struct FaceTracker2FBWrapper : public HandleWrapper<XrFaceTracker2FB> {};
struct PassthroughHTCWrapper : public HandleWrapper<XrPassthroughHTC> {};
struct PlaneDetectorEXTWrapper : public HandleWrapper<XrPlaneDetectorEXT> {};
struct DisplayModeKHRWrapper            : public HandleWrapper<VkDisplayModeKHR> {};
// clang-format on

struct ActionSetWrapper : public HandleWrapper<XrActionSet>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
};

struct PassthroughFBWrapper : public HandleWrapper<XrPassthroughFB>
{
    OpenXrInstanceTable* layer_table_ref{ nullptr };
};

struct SessionWrapper : public HandleWrapper<XrSession>
{
    OpenXrInstanceTable*               layer_table_ref{ nullptr };
    std::vector<PassthroughFBWrapper*> child_passthroughs;
};

struct InstanceWrapper : public HandleWrapper<XrInstance>
{
    OpenXrInstanceTable            layer_table;
    XrVersion                      api_version{ XR_MAKE_VERSION(1, 0, 0) };
    std::vector<SessionWrapper*>   child_sessions;
    std::vector<ActionSetWrapper*> child_action_sets;
};

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_HANDLE_WRAPPERS_H
