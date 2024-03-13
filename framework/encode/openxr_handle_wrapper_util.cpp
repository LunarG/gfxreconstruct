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
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

OpenXrStateHandleTable openxr_state_handle_table_;

uint64_t GetWrappedId(uint64_t object, XrObjectType object_type)
{
    switch (object_type)
    {
        case XR_OBJECT_TYPE_INSTANCE:
            return GetWrappedId<InstanceWrapper>(format::FromHandleId<XrInstance>(object));
        case XR_OBJECT_TYPE_SESSION:
            return GetWrappedId<SessionWrapper>(format::FromHandleId<XrSession>(object));
        case XR_OBJECT_TYPE_SWAPCHAIN:
            return GetWrappedId<SwapchainWrapper>(format::FromHandleId<XrSwapchain>(object));
        case XR_OBJECT_TYPE_SPACE:
            return GetWrappedId<SpaceWrapper>(format::FromHandleId<XrSpace>(object));
        case XR_OBJECT_TYPE_ACTION_SET:
            return GetWrappedId<ActionSetWrapper>(format::FromHandleId<XrActionSet>(object));
        case XR_OBJECT_TYPE_ACTION:
            return GetWrappedId<ActionWrapper>(format::FromHandleId<XrAction>(object));
        case XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return GetWrappedId<DebugUtilsMessengerEXTWrapper>(format::FromHandleId<XrDebugUtilsMessengerEXT>(object));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT:
            return GetWrappedId<SpatialAnchorMSFTWrapper>(format::FromHandleId<XrSpatialAnchorMSFT>(object));
        case XR_OBJECT_TYPE_SPATIAL_GRAPH_NODE_BINDING_MSFT:
            return GetWrappedId<SpatialGraphNodeBindingMSFTWrapper>(
                format::FromHandleId<XrSpatialGraphNodeBindingMSFT>(object));
        case XR_OBJECT_TYPE_HAND_TRACKER_EXT:
            return GetWrappedId<HandTrackerEXTWrapper>(format::FromHandleId<XrHandTrackerEXT>(object));
        case XR_OBJECT_TYPE_BODY_TRACKER_FB:
            return GetWrappedId<BodyTrackerFBWrapper>(format::FromHandleId<XrBodyTrackerFB>(object));
        case XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT:
            return GetWrappedId<SceneObserverMSFTWrapper>(format::FromHandleId<XrSceneObserverMSFT>(object));
        case XR_OBJECT_TYPE_SCENE_MSFT:
            return GetWrappedId<SceneMSFTWrapper>(format::FromHandleId<XrSceneMSFT>(object));
        case XR_OBJECT_TYPE_FACIAL_TRACKER_HTC:
            return GetWrappedId<FacialTrackerHTCWrapper>(format::FromHandleId<XrFacialTrackerHTC>(object));
        case XR_OBJECT_TYPE_FOVEATION_PROFILE_FB:
            return GetWrappedId<FoveationProfileFBWrapper>(format::FromHandleId<XrFoveationProfileFB>(object));
        case XR_OBJECT_TYPE_TRIANGLE_MESH_FB:
            return GetWrappedId<TriangleMeshFBWrapper>(format::FromHandleId<XrTriangleMeshFB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_FB:
            return GetWrappedId<PassthroughFBWrapper>(format::FromHandleId<XrPassthroughFB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_LAYER_FB:
            return GetWrappedId<PassthroughLayerFBWrapper>(format::FromHandleId<XrPassthroughLayerFB>(object));
        case XR_OBJECT_TYPE_GEOMETRY_INSTANCE_FB:
            return GetWrappedId<GeometryInstanceFBWrapper>(format::FromHandleId<XrGeometryInstanceFB>(object));
        case XR_OBJECT_TYPE_MARKER_DETECTOR_ML:
            return GetWrappedId<MarkerDetectorMLWrapper>(format::FromHandleId<XrMarkerDetectorML>(object));
        case XR_OBJECT_TYPE_EXPORTED_LOCALIZATION_MAP_ML:
            return GetWrappedId<ExportedLocalizationMapMLWrapper>(
                format::FromHandleId<XrExportedLocalizationMapML>(object));
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_STORE_CONNECTION_MSFT:
            return GetWrappedId<SpatialAnchorStoreConnectionMSFTWrapper>(
                format::FromHandleId<XrSpatialAnchorStoreConnectionMSFT>(object));
        case XR_OBJECT_TYPE_SPACE_USER_FB:
            return GetWrappedId<SpaceUserFBWrapper>(format::FromHandleId<XrSpaceUserFB>(object));
        case XR_OBJECT_TYPE_FACE_TRACKER_FB:
            return GetWrappedId<FaceTrackerFBWrapper>(format::FromHandleId<XrFaceTrackerFB>(object));
        case XR_OBJECT_TYPE_EYE_TRACKER_FB:
            return GetWrappedId<EyeTrackerFBWrapper>(format::FromHandleId<XrEyeTrackerFB>(object));
        case XR_OBJECT_TYPE_VIRTUAL_KEYBOARD_META:
            return GetWrappedId<VirtualKeyboardMETAWrapper>(format::FromHandleId<XrVirtualKeyboardMETA>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_COLOR_LUT_META:
            return GetWrappedId<PassthroughColorLutMETAWrapper>(
                format::FromHandleId<XrPassthroughColorLutMETA>(object));
        case XR_OBJECT_TYPE_FACE_TRACKER2_FB:
            return GetWrappedId<FaceTracker2FBWrapper>(format::FromHandleId<XrFaceTracker2FB>(object));
        case XR_OBJECT_TYPE_PASSTHROUGH_HTC:
            return GetWrappedId<PassthroughHTCWrapper>(format::FromHandleId<XrPassthroughHTC>(object));
        case XR_OBJECT_TYPE_PLANE_DETECTOR_EXT:
            return GetWrappedId<PlaneDetectorEXTWrapper>(format::FromHandleId<XrPlaneDetectorEXT>(object));

        case XR_OBJECT_TYPE_UNKNOWN:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown OpenXr object type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized OpenXr object type %d", object_type);
            return object;
    }
}

uint64_t GetWrappedId(uint64_t object, OpenXrAtomName atom_type)
{
    switch (atom_type)
    {
        case OPENXR_ATOM_NAME_SYSTEM_ID:
            return GetAtomWrappedId<SystemIdWrapper>(format::FromHandleId<XrSystemId>(object));
        case OPENXR_ATOM_NAME_PATH:
            return GetAtomWrappedId<PathWrapper>(format::FromHandleId<XrPath>(object));
        case OPENXR_ATOM_NAME_ASYNC_REQUEST_ID_FB:
            return GetAtomWrappedId<AsyncRequestIdFBWrapper>(format::FromHandleId<XrAsyncRequestIdFB>(object));
        case OPENXR_ATOM_NAME_RENDER_MODEL_KEY_FB:
            return GetAtomWrappedId<RenderModelKeyFBWrapper>(format::FromHandleId<XrRenderModelKeyFB>(object));
        case OPENXR_ATOM_NAME_MARKER_ML:
            return GetAtomWrappedId<MarkerMLWrapper>(format::FromHandleId<XrMarkerML>(object));
        case OPENXR_ATOM_NAME_CONTROLLER_MODEL_KEY_MSFT:
            return GetAtomWrappedId<ControllerModelKeyMSFTWrapper>(
                format::FromHandleId<XrControllerModelKeyMSFT>(object));

        case OPENXR_ATOM_NAME_UNKNOWN:
            // No conversion will be performed for unknown objects.
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown OpenXr atom type.");
            return object;
        default:
            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized OpenXr atom type %d", atom_type);
            return object;
    }
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
