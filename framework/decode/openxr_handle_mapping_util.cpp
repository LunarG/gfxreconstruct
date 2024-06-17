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

#include "decode/openxr_handle_mapping_util.h"

#include "decode/openxr_object_info.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(handle_mapping)

uint64_t MapHandle(uint64_t object, XrObjectType object_type, const CommonObjectInfoTable& object_info_table)
{
    switch (object_type)
    {
        case XR_OBJECT_TYPE_INSTANCE:
            return format::ToHandleId(
                MapHandle<OpenXrInstanceInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrInstanceInfo));
        case XR_OBJECT_TYPE_SESSION:
            return format::ToHandleId(
                MapHandle<OpenXrSessionInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo));
        case XR_OBJECT_TYPE_SWAPCHAIN:
            return format::ToHandleId(
                MapHandle<OpenXrSwapchainInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrSwapchainInfo));
        case XR_OBJECT_TYPE_SPACE:
            return format::ToHandleId(
                MapHandle<OpenXrSpaceInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo));
        case XR_OBJECT_TYPE_ACTION:
            return format::ToHandleId(
                MapHandle<OpenXrActionInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrActionInfo));
        case XR_OBJECT_TYPE_ACTION_SET:
            return format::ToHandleId(
                MapHandle<OpenXrActionSetInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo));
        case XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return format::ToHandleId(MapHandle<OpenXrDebugUtilsMessengerEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrDebugUtilsMessengerEXTInfo));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT:
            return format::ToHandleId(MapHandle<OpenXrSpatialAnchorMSFTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo));
        case XR_OBJECT_TYPE_SPATIAL_GRAPH_NODE_BINDING_MSFT:
            return format::ToHandleId(MapHandle<OpenXrSpatialGraphNodeBindingMSFTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrSpatialGraphNodeBindingMSFTInfo));
        case XR_OBJECT_TYPE_HAND_TRACKER_EXT:
            return format::ToHandleId(MapHandle<OpenXrHandTrackerEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrHandTrackerEXTInfo));
        case XR_OBJECT_TYPE_BODY_TRACKER_FB:
            return format::ToHandleId(MapHandle<OpenXrBodyTrackerFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrBodyTrackerFBInfo));
        case XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT:
            return format::ToHandleId(MapHandle<OpenXrSceneObserverMSFTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrSceneObserverMSFTInfo));
        case XR_OBJECT_TYPE_SCENE_MSFT:
            return format::ToHandleId(
                MapHandle<OpenXrSceneMSFTInfo>(object, object_info_table, &CommonObjectInfoTable::GetXrSceneMSFTInfo));
        case XR_OBJECT_TYPE_FACIAL_TRACKER_HTC:
            return format::ToHandleId(MapHandle<OpenXrFacialTrackerHTCInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrFacialTrackerHTCInfo));
        case XR_OBJECT_TYPE_FOVEATION_PROFILE_FB:
            return format::ToHandleId(MapHandle<OpenXrFoveationProfileFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrFoveationProfileFBInfo));
        case XR_OBJECT_TYPE_TRIANGLE_MESH_FB:
            return format::ToHandleId(MapHandle<OpenXrTriangleMeshFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo));
        case XR_OBJECT_TYPE_PASSTHROUGH_FB:
            return format::ToHandleId(MapHandle<OpenXrPassthroughFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrPassthroughFBInfo));
        case XR_OBJECT_TYPE_PASSTHROUGH_LAYER_FB:
            return format::ToHandleId(MapHandle<OpenXrPassthroughLayerFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo));
        case XR_OBJECT_TYPE_GEOMETRY_INSTANCE_FB:
            return format::ToHandleId(MapHandle<OpenXrGeometryInstanceFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrGeometryInstanceFBInfo));
        case XR_OBJECT_TYPE_MARKER_DETECTOR_ML:
            return format::ToHandleId(MapHandle<OpenXrMarkerDetectorMLInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo));
        case XR_OBJECT_TYPE_EXPORTED_LOCALIZATION_MAP_ML:
            return format::ToHandleId(MapHandle<OpenXrExportedLocalizationMapMLInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrExportedLocalizationMapMLInfo));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_STORE_CONNECTION_MSFT:
            return format::ToHandleId(MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo));
        case XR_OBJECT_TYPE_FACE_TRACKER_FB:
            return format::ToHandleId(MapHandle<OpenXrFaceTrackerFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrFaceTrackerFBInfo));
        case XR_OBJECT_TYPE_EYE_TRACKER_FB:
            return format::ToHandleId(MapHandle<OpenXrEyeTrackerFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrEyeTrackerFBInfo));
        case XR_OBJECT_TYPE_VIRTUAL_KEYBOARD_META:
            return format::ToHandleId(MapHandle<OpenXrVirtualKeyboardMETAInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo));
        case XR_OBJECT_TYPE_SPACE_USER_FB:
            return format::ToHandleId(MapHandle<OpenXrSpaceUserFBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrSpaceUserFBInfo));
        case XR_OBJECT_TYPE_PASSTHROUGH_COLOR_LUT_META:
            return format::ToHandleId(MapHandle<OpenXrPassthroughColorLutMETAInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo));
        case XR_OBJECT_TYPE_FACE_TRACKER2_FB:
            return format::ToHandleId(MapHandle<OpenXrFaceTracker2FBInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrFaceTracker2FBInfo));
        case XR_OBJECT_TYPE_PASSTHROUGH_HTC:
            return format::ToHandleId(MapHandle<OpenXrPassthroughHTCInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrPassthroughHTCInfo));
        case XR_OBJECT_TYPE_PLANE_DETECTOR_EXT:
            return format::ToHandleId(MapHandle<OpenXrPlaneDetectorEXTInfo>(
                object, object_info_table, &CommonObjectInfoTable::GetXrPlaneDetectorEXTInfo));
        case XR_OBJECT_TYPE_UNKNOWN:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized object type %d", object_type);
            return object;
    }
}

GFXRECON_END_NAMESPACE(handle_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
