/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos OpenXR XML API Registry.
**
*/

#if ENABLE_OPENXR_SUPPORT

#include "generated/generated_openxr_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
void EncodeNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const XrBaseInStructure*>(value);

    if (base != nullptr)
    {
        switch (base->type)
        {
        default:
            {
                // next is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A next value with unrecognized XrStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->type);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A next value with unrecognized XrStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->type);
                OpenXrCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodeNextStruct(encoder, base->next);
            }
            break;
        case XR_TYPE_ACTION_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionCreateInfo*>(base));
            break;
        case XR_TYPE_ACTION_SET_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionSetCreateInfo*>(base));
            break;
        case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionSpaceCreateInfo*>(base));
            break;
        case XR_TYPE_ACTION_STATE_BOOLEAN:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionStateBoolean*>(base));
            break;
        case XR_TYPE_ACTION_STATE_FLOAT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionStateFloat*>(base));
            break;
        case XR_TYPE_ACTION_STATE_GET_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionStateGetInfo*>(base));
            break;
        case XR_TYPE_ACTION_STATE_POSE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionStatePose*>(base));
            break;
        case XR_TYPE_ACTION_STATE_VECTOR2F:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionStateVector2f*>(base));
            break;
        case XR_TYPE_ACTIONS_SYNC_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActionsSyncInfo*>(base));
            break;
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base));
            break;
        case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrAndroidSurfaceSwapchainCreateInfoFB*>(base));
            break;
        case XR_TYPE_API_LAYER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrApiLayerProperties*>(base));
            break;
        case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBindingModificationsKHR*>(base));
            break;
        case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBodyJointLocationsFB*>(base));
            break;
        case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBodyJointsLocateInfoFB*>(base));
            break;
        case XR_TYPE_BODY_SKELETON_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBodySkeletonFB*>(base));
            break;
        case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBodyTrackerCreateInfoFB*>(base));
            break;
        case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBoundSourcesForActionEnumerateInfo*>(base));
            break;
        case XR_TYPE_BOUNDARY_2D_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBoundary2DFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerAlphaBlendFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerColorScaleBiasKHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerCubeKHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerCylinderKHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthTestFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthTestVARJO*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerEquirect2KHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerEquirectKHR*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerImageLayoutFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerPassthroughHTC*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerProjection*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerProjectionView*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerQuad*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerReprojectionInfoMSFT*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerReprojectionPlaneOverrideMSFT*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSecureContentFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSettingsFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base));
            break;
        case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrControllerModelKeyStateMSFT*>(base));
            break;
        case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrControllerModelNodePropertiesMSFT*>(base));
            break;
        case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrControllerModelNodeStateMSFT*>(base));
            break;
        case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrControllerModelPropertiesMSFT*>(base));
            break;
        case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrControllerModelStateMSFT*>(base));
            break;
        case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCoordinateSpaceCreateInfoML*>(base));
            break;
        case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDebugUtilsLabelEXT*>(base));
            break;
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDebugUtilsMessengerCallbackDataEXT*>(base));
            break;
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDebugUtilsObjectNameInfoEXT*>(base));
            break;
        case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDevicePcmSampleRateStateFB*>(base));
            break;
        case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDigitalLensControlALMALENCE*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthHandRemovalSetInfoMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthImageAcquireInfoMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthImageMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthImageViewMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthProviderCreateInfoMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthSwapchainCreateInfoMETA*>(base));
            break;
        case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEnvironmentDepthSwapchainStateMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_BUFFER:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataBuffer*>(base));
            break;
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataDisplayRefreshRateChangedFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataEventsLost*>(base));
            break;
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataEyeCalibrationChangedML*>(base));
            break;
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataHeadsetFitChangedML*>(base));
            break;
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataInstanceLossPending*>(base));
            break;
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataInteractionProfileChanged*>(base));
            break;
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataLocalizationChangedML*>(base));
            break;
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataMainSessionVisibilityChangedEXTX*>(base));
            break;
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataMarkerTrackingUpdateVARJO*>(base));
            break;
        case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataPassthroughStateChangedFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataPerfSettingsEXT*>(base));
            break;
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataReferenceSpaceChangePending*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSceneCaptureCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSessionStateChanged*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceEraseCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceQueryCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceSaveCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpaceShareCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB*>(base));
            break;
        case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataUserPresenceChangedEXT*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVirtualKeyboardBackspaceMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVirtualKeyboardCommitTextMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVirtualKeyboardEnterMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVirtualKeyboardHiddenMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVirtualKeyboardShownMETA*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR*>(base));
            break;
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX*>(base));
            break;
        case XR_TYPE_EXTENSION_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrExtensionProperties*>(base));
            break;
        case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
            EncodeStructPtr(encoder, reinterpret_cast<const XrExternalCameraOCULUS*>(base));
            break;
        case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEyeGazeSampleTimeEXT*>(base));
            break;
        case XR_TYPE_EYE_GAZES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEyeGazesFB*>(base));
            break;
        case XR_TYPE_EYE_GAZES_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEyeGazesInfoFB*>(base));
            break;
        case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEyeTrackerCreateInfoFB*>(base));
            break;
        case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceExpressionInfo2FB*>(base));
            break;
        case XR_TYPE_FACE_EXPRESSION_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceExpressionInfoFB*>(base));
            break;
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceExpressionWeights2FB*>(base));
            break;
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceExpressionWeightsFB*>(base));
            break;
        case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceTrackerCreateInfo2FB*>(base));
            break;
        case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFaceTrackerCreateInfoFB*>(base));
            break;
        case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFacialExpressionsHTC*>(base));
            break;
        case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFacialTrackerCreateInfoHTC*>(base));
            break;
        case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrForceFeedbackCurlApplyLocationsMNDX*>(base));
            break;
        case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveatedViewConfigurationViewVARJO*>(base));
            break;
        case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationApplyInfoHTC*>(base));
            break;
        case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationCustomModeInfoHTC*>(base));
            break;
        case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationDynamicModeInfoHTC*>(base));
            break;
        case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationEyeTrackedProfileCreateInfoMETA*>(base));
            break;
        case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationEyeTrackedStateMETA*>(base));
            break;
        case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationLevelProfileCreateInfoFB*>(base));
            break;
        case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationProfileCreateInfoFB*>(base));
            break;
        case XR_TYPE_FRAME_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameBeginInfo*>(base));
            break;
        case XR_TYPE_FRAME_END_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameEndInfo*>(base));
            break;
        case XR_TYPE_FRAME_END_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameEndInfoML*>(base));
            break;
        case XR_TYPE_FRAME_STATE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameState*>(base));
            break;
        case XR_TYPE_FRAME_WAIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameWaitInfo*>(base));
            break;
        case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFutureCancelInfoEXT*>(base));
            break;
        case XR_TYPE_FUTURE_COMPLETION_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFutureCompletionEXT*>(base));
            break;
        case XR_TYPE_FUTURE_POLL_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFuturePollInfoEXT*>(base));
            break;
        case XR_TYPE_FUTURE_POLL_RESULT_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFuturePollResultEXT*>(base));
            break;
        case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGeometryInstanceCreateInfoFB*>(base));
            break;
        case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGeometryInstanceTransformFB*>(base));
            break;
        case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGlobalDimmerFrameEndInfoML*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingD3D11KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingD3D12KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingEGLMNDX*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingMetalKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsD3D11KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsD3D12KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsMetalKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsOpenGLESKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsOpenGLKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsRequirementsVulkanKHR*>(base));
            break;
        case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointLocationsEXT*>(base));
            break;
        case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointVelocitiesEXT*>(base));
            break;
        case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointsLocateInfoEXT*>(base));
            break;
        case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointsMotionRangeInfoEXT*>(base));
            break;
        case XR_TYPE_HAND_MESH_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandMeshMSFT*>(base));
            break;
        case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandMeshSpaceCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandMeshUpdateInfoMSFT*>(base));
            break;
        case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandPoseTypeInfoMSFT*>(base));
            break;
        case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackerCreateInfoEXT*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingAimStateFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingCapsulesStateFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingDataSourceInfoEXT*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingDataSourceStateEXT*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_MESH_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingMeshFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_SCALE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingScaleFB*>(base));
            break;
        case XR_TYPE_HAPTIC_ACTION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHapticActionInfo*>(base));
            break;
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(base));
            break;
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHapticPcmVibrationFB*>(base));
            break;
        case XR_TYPE_HAPTIC_VIBRATION:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHapticVibration*>(base));
            break;
        case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHolographicWindowAttachmentMSFT*>(base));
            break;
        case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInputSourceLocalizedNameGetInfo*>(base));
            break;
        case XR_TYPE_INSTANCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInstanceCreateInfo*>(base));
            break;
        case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInstanceCreateInfoAndroidKHR*>(base));
            break;
        case XR_TYPE_INSTANCE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInstanceProperties*>(base));
            break;
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(base));
            break;
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(base));
            break;
        case XR_TYPE_INTERACTION_PROFILE_STATE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInteractionProfileState*>(base));
            break;
        case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInteractionProfileSuggestedBinding*>(base));
            break;
        case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrKeyboardSpaceCreateInfoFB*>(base));
            break;
        case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrKeyboardTrackingQueryFB*>(base));
            break;
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLoaderInitInfoAndroidKHR*>(base));
            break;
        case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLocalDimmingFrameEndInfoMETA*>(base));
            break;
        case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLocalizationEnableEventsInfoML*>(base));
            break;
        case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLocalizationMapImportInfoML*>(base));
            break;
        case XR_TYPE_LOCALIZATION_MAP_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLocalizationMapML*>(base));
            break;
        case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMapLocalizationRequestInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorAprilTagInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorArucoInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorCreateInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorCustomProfileInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorSizeInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorSnapshotInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_STATE_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorStateML*>(base));
            break;
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerSpaceCreateInfoML*>(base));
            break;
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerSpaceCreateInfoVARJO*>(base));
            break;
        case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrNewSceneComputeInfoMSFT*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughBrightnessContrastSaturationFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorHTC*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorLutCreateInfoMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorLutUpdateInfoMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapMonoToMonoFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapMonoToRgbaFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughCreateInfoFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughCreateInfoHTC*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughKeyboardHandsIntensityFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughLayerCreateInfoFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughPreferencesMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_STYLE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughStyleFB*>(base));
            break;
        case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPerformanceMetricsCounterMETA*>(base));
            break;
        case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPerformanceMetricsStateMETA*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorBeginInfoEXT*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorCreateInfoEXT*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorGetInfoEXT*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorLocationEXT*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorLocationsEXT*>(base));
            break;
        case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPlaneDetectorPolygonBufferEXT*>(base));
            break;
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRecommendedLayerResolutionGetInfoMETA*>(base));
            break;
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRecommendedLayerResolutionMETA*>(base));
            break;
        case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrReferenceSpaceCreateInfo*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_BUFFER_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelBufferFB*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelCapabilitiesRequestFB*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelLoadInfoFB*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelPathInfoFB*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelPropertiesFB*>(base));
            break;
        case XR_TYPE_ROOM_LAYOUT_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRoomLayoutFB*>(base));
            break;
        case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneCaptureRequestInfoFB*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentLocationsMSFT*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentParentFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentsGetInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentsLocateInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENTS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentsMSFT*>(base));
            break;
        case XR_TYPE_SCENE_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneDeserializeInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkerQRCodesMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkerTypeFilterMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MARKERS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkersMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshBuffersGetInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshBuffersMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshIndicesUint16MSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshIndicesUint32MSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshVertexBufferMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESHES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshesMSFT*>(base));
            break;
        case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneObjectTypesFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_OBJECTS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneObjectsMSFT*>(base));
            break;
        case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneObserverCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrScenePlaneAlignmentFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_PLANES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrScenePlanesMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationFrameStateMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationLayerInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationStateMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SEMANTIC_LABELS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSemanticLabelsFB*>(base));
            break;
        case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSemanticLabelsSupportInfoFB*>(base));
            break;
        case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSerializedSceneFragmentDataGetInfoMSFT*>(base));
            break;
        case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSessionActionSetsAttachInfo*>(base));
            break;
        case XR_TYPE_SESSION_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSessionBeginInfo*>(base));
            break;
        case XR_TYPE_SESSION_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSessionCreateInfo*>(base));
            break;
        case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSessionCreateInfoOverlayEXTX*>(base));
            break;
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceComponentFilterInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceComponentStatusFB*>(base));
            break;
        case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceComponentStatusSetInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_CONTAINER_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceContainerFB*>(base));
            break;
        case XR_TYPE_SPACE_ERASE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceEraseInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceListSaveInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_LOCATION:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceLocation*>(base));
            break;
        case XR_TYPE_SPACE_LOCATIONS:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceLocations*>(base));
            break;
        case XR_TYPE_SPACE_QUERY_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceQueryInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceQueryResultsFB*>(base));
            break;
        case XR_TYPE_SPACE_SAVE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceSaveInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_SHARE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceShareInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceStorageLocationFilterInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceTriangleMeshGetInfoMETA*>(base));
            break;
        case XR_TYPE_SPACE_TRIANGLE_MESH_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceTriangleMeshMETA*>(base));
            break;
        case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceUserCreateInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceUuidFilterInfoFB*>(base));
            break;
        case XR_TYPE_SPACE_VELOCITIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceVelocities*>(base));
            break;
        case XR_TYPE_SPACE_VELOCITY:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceVelocity*>(base));
            break;
        case XR_TYPE_SPACES_LOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpacesLocateInfo*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorCreateInfoFB*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorCreateInfoHTC*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorPersistenceInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialAnchorSpaceCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialGraphNodeSpaceCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainCreateInfo*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainCreateInfoFoveationFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageAcquireInfo*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageD3D11KHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageD3D12KHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageMetalKHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageOpenGLESKHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageOpenGLKHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageReleaseInfo*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageVulkanKHR*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageWaitInfo*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainStateAndroidSurfaceDimensionsFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainStateFoveationFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainStateSamplerOpenGLESFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainStateSamplerVulkanFB*>(base));
            break;
        case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemAnchorPropertiesHTC*>(base));
            break;
        case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemBodyTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemColorSpacePropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemEnvironmentDepthPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemEyeGazeInteractionPropertiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemEyeTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFaceTrackingProperties2FB*>(base));
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFaceTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFacialTrackingPropertiesHTC*>(base));
            break;
        case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemForceFeedbackCurlPropertiesMNDX*>(base));
            break;
        case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFoveatedRenderingPropertiesVARJO*>(base));
            break;
        case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFoveationEyeTrackedPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_GET_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemGetInfo*>(base));
            break;
        case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHandTrackingMeshPropertiesMSFT*>(base));
            break;
        case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHandTrackingPropertiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHeadsetIdPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemKeyboardTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemMarkerTrackingPropertiesVARJO*>(base));
            break;
        case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemMarkerUnderstandingPropertiesML*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughColorLutPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughProperties2FB*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPlaneDetectionPropertiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemProperties*>(base));
            break;
        case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemRenderModelPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemSpaceWarpPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemSpatialEntityPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemUserPresencePropertiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemVirtualKeyboardPropertiesMETA*>(base));
            break;
        case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrTriangleMeshCreateInfoFB*>(base));
            break;
        case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrUserCalibrationEnableEventsInfoML*>(base));
            break;
        case XR_TYPE_VIEW:
            EncodeStructPtr(encoder, reinterpret_cast<const XrView*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationDepthRangeEXT*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationProperties*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_VIEW:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationView*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationViewFovEPIC*>(base));
            break;
        case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewLocateFoveatedRenderingVARJO*>(base));
            break;
        case XR_TYPE_VIEW_LOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewLocateInfo*>(base));
            break;
        case XR_TYPE_VIEW_STATE:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewState*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardAnimationStateMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardCreateInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardInputInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardLocationInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardModelAnimationStatesMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardModelVisibilitySetInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardSpaceCreateInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardTextContextChangeInfoMETA*>(base));
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVirtualKeyboardTextureDataMETA*>(base));
            break;
        case XR_TYPE_VISIBILITY_MASK_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVisibilityMaskKHR*>(base));
            break;
        case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVisualMeshComputeLodInfoMSFT*>(base));
            break;
        case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViveTrackerPathsHTCX*>(base));
            break;
        case XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanDeviceCreateInfoKHR*>(base));
            break;
        case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanGraphicsDeviceGetInfoKHR*>(base));
            break;
        case XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanInstanceCreateInfoKHR*>(base));
            break;
        case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanSwapchainCreateInfoMETA*>(base));
            break;
        case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanSwapchainFormatListCreateInfoKHR*>(base));
            break;
        }
    }
    else
    {
        // next was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
