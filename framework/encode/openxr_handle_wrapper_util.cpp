/*
** Copyright (c) 2020-2024 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "encode/openxr_handle_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

OpenXrStateHandleTable state_handle_table_;

uint64_t GetOpenXrWrappedId(uint64_t object, XrObjectType object_type)
{
    switch (object_type)
    {
        case XR_OBJECT_TYPE_INSTANCE:
            return GetOpenXrWrappedId<openxr_wrappers::InstanceWrapper>(format::FromHandleId<XrInstance>(object));
        case XR_OBJECT_TYPE_SESSION:
            return GetOpenXrWrappedId<openxr_wrappers::SessionWrapper>(format::FromHandleId<XrSession>(object));
        case XR_OBJECT_TYPE_SWAPCHAIN:
            return GetOpenXrWrappedId<openxr_wrappers::SwapchainWrapper>(format::FromHandleId<XrSwapchain>(object));
        case XR_OBJECT_TYPE_SPACE:
            return GetOpenXrWrappedId<openxr_wrappers::SpaceWrapper>(format::FromHandleId<XrSpace>(object));
        case XR_OBJECT_TYPE_ACTION_SET:
            return GetOpenXrWrappedId<openxr_wrappers::ActionSetWrapper>(format::FromHandleId<XrActionSet>(object));
        case XR_OBJECT_TYPE_ACTION:
            return GetOpenXrWrappedId<openxr_wrappers::ActionWrapper>(format::FromHandleId<XrAction>(object));
        case XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return GetOpenXrWrappedId<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(
                format::FromHandleId<XrDebugUtilsMessengerEXT>(object));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT:
            return GetOpenXrWrappedId<openxr_wrappers::SpatialAnchorMSFTWrapper>(
                format::FromHandleId<XrSpatialAnchorMSFT>(object));
        case XR_OBJECT_TYPE_SPATIAL_GRAPH_NODE_BINDING_MSFT:
            return GetOpenXrWrappedId<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(
                format::FromHandleId<XrSpatialGraphNodeBindingMSFT>(object));
        case XR_OBJECT_TYPE_HAND_TRACKER_EXT:
            return GetOpenXrWrappedId<openxr_wrappers::HandTrackerEXTWrapper>(
                format::FromHandleId<XrHandTrackerEXT>(object));
        case XR_OBJECT_TYPE_BODY_TRACKER_FB:
            return GetOpenXrWrappedId<openxr_wrappers::BodyTrackerFBWrapper>(
                format::FromHandleId<XrBodyTrackerFB>(object));
        case XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT:
            return GetOpenXrWrappedId<openxr_wrappers::SceneObserverMSFTWrapper>(
                format::FromHandleId<XrSceneObserverMSFT>(object));
        case XR_OBJECT_TYPE_SCENE_MSFT:
            return GetOpenXrWrappedId<openxr_wrappers::SceneMSFTWrapper>(format::FromHandleId<XrSceneMSFT>(object));
        case XR_OBJECT_TYPE_FACIAL_TRACKER_HTC:
            return GetOpenXrWrappedId<openxr_wrappers::FacialTrackerHTCWrapper>(
                format::FromHandleId<XrFacialTrackerHTC>(object));
        case XR_OBJECT_TYPE_FOVEATION_PROFILE_FB:
            return GetOpenXrWrappedId<openxr_wrappers::FoveationProfileFBWrapper>(
                format::FromHandleId<XrFoveationProfileFB>(object));
        case XR_OBJECT_TYPE_TRIANGLE_MESH_FB:
            return GetOpenXrWrappedId<openxr_wrappers::TriangleMeshFBWrapper>(
                format::FromHandleId<XrTriangleMeshFB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_FB:
            return GetOpenXrWrappedId<openxr_wrappers::PassthroughFBWrapper>(
                format::FromHandleId<XrPassthroughFB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_LAYER_FB:
            return GetOpenXrWrappedId<openxr_wrappers::PassthroughLayerFBWrapper>(
                format::FromHandleId<XrPassthroughLayerFB>(object));
        case XR_OBJECT_TYPE_GEOMETRY_INSTANCE_FB:
            return GetOpenXrWrappedId<openxr_wrappers::GeometryInstanceFBWrapper>(
                format::FromHandleId<XrGeometryInstanceFB>(object));
        case XR_OBJECT_TYPE_MARKER_DETECTOR_ML:
            return GetOpenXrWrappedId<openxr_wrappers::MarkerDetectorMLWrapper>(
                format::FromHandleId<XrMarkerDetectorML>(object));
        case XR_OBJECT_TYPE_EXPORTED_LOCALIZATION_MAP_ML:
            return GetOpenXrWrappedId<openxr_wrappers::ExportedLocalizationMapMLWrapper>(
                format::FromHandleId<XrExportedLocalizationMapML>(object));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_STORE_CONNECTION_MSFT:
            return GetOpenXrWrappedId<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(
                format::FromHandleId<XrSpatialAnchorStoreConnectionMSFT>(object));
        case XR_OBJECT_TYPE_SPACE_USER_FB:
            return GetOpenXrWrappedId<openxr_wrappers::SpaceUserFBWrapper>(format::FromHandleId<XrSpaceUserFB>(object));
        case XR_OBJECT_TYPE_FACE_TRACKER_FB:
            return GetOpenXrWrappedId<openxr_wrappers::FaceTrackerFBWrapper>(
                format::FromHandleId<XrFaceTrackerFB>(object));
        case XR_OBJECT_TYPE_EYE_TRACKER_FB:
            return GetOpenXrWrappedId<openxr_wrappers::EyeTrackerFBWrapper>(
                format::FromHandleId<XrEyeTrackerFB>(object));
        case XR_OBJECT_TYPE_VIRTUAL_KEYBOARD_META:
            return GetOpenXrWrappedId<openxr_wrappers::VirtualKeyboardMETAWrapper>(
                format::FromHandleId<XrVirtualKeyboardMETA>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_COLOR_LUT_META:
            return GetOpenXrWrappedId<openxr_wrappers::PassthroughColorLutMETAWrapper>(
                format::FromHandleId<XrPassthroughColorLutMETA>(object));
        case XR_OBJECT_TYPE_FACE_TRACKER2_FB:
            return GetOpenXrWrappedId<openxr_wrappers::FaceTracker2FBWrapper>(
                format::FromHandleId<XrFaceTracker2FB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_HTC:
            return GetOpenXrWrappedId<openxr_wrappers::PassthroughHTCWrapper>(
                format::FromHandleId<XrPassthroughHTC>(object));
        case XR_OBJECT_TYPE_PLANE_DETECTOR_EXT:
            return GetOpenXrWrappedId<openxr_wrappers::PlaneDetectorEXTWrapper>(
                format::FromHandleId<XrPlaneDetectorEXT>(object));

        case XR_OBJECT_TYPE_UNKNOWN:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized object type %d", object_type);
            return object;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
