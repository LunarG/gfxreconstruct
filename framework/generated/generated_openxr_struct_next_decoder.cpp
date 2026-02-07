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

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include "decode/custom_openxr_struct_decoders.h"
#include "decode/decode_allocator.h"
#include "decode/openxr_next_node.h"
#include "decode/openxr_next_typed_node.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_openxr_enum_to_string.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeNextStruct(const uint8_t* parameter_buffer, size_t buffer_size, OpenXrNextNode** next)
{
    assert(next != nullptr);

    size_t bytes_read = 0;
    uint32_t attrib = 0;

    if ((parameter_buffer != nullptr) && (buffer_size >= sizeof(attrib)))
    {
        size_t type_offset = 0;

        // Peek at the pointer attribute mask to make sure we have a non-NULL value that can be decoded.
        attrib = *(reinterpret_cast<const uint32_t*>(parameter_buffer));

        if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
        {
            // Offset to XrStructureType, after the pointer encoding preamble.
            type_offset = sizeof(attrib);

            if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                type_offset += sizeof(format::AddressEncodeType);
            }
        }

        if ((type_offset != 0) && ((buffer_size - type_offset) >= sizeof(XrStructureType)))
        {
            const XrStructureType* type = reinterpret_cast<const XrStructureType*>(parameter_buffer + type_offset);

            switch (*type)
            {
            default:
                // TODO: This may need to be a fatal error
                GFXRECON_LOG_ERROR("Failed to decode next value with unrecognized XrStructureType = %s", (util::ToString(*type).c_str()));
                break;
            case XR_TYPE_ACTION_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_SET_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionSetCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_SPACE_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionSpaceCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_STATE_BOOLEAN:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionStateBoolean>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_STATE_FLOAT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionStateFloat>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_STATE_GET_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionStateGetInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_STATE_POSE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionStatePose>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTION_STATE_VECTOR2F:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionStateVector2f>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTIONS_SYNC_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActionsSyncInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActiveActionSetPrioritiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrAndroidSurfaceSwapchainCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_API_LAYER_PROPERTIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrApiLayerProperties>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBindingModificationsKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBodyJointLocationsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBodyJointsLocateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BODY_SKELETON_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBodySkeletonFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBodyTrackerCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBoundSourcesForActionEnumerateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BOUNDARY_2D_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBoundary2DFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerAlphaBlendFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerColorScaleBiasKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerCubeKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerCylinderKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthTestFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthTestVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerEquirect2KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerEquirectKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerImageLayoutFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerPassthroughFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerPassthroughHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerProjection>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerProjectionView>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerQuad>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerReprojectionInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSecureContentFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSettingsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSpaceWarpInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrControllerModelKeyStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrControllerModelNodePropertiesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrControllerModelNodeStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrControllerModelPropertiesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrControllerModelStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCoordinateSpaceCreateInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDebugUtilsLabelEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDebugUtilsMessengerCallbackDataEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDebugUtilsMessengerCreateInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDebugUtilsObjectNameInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDevicePcmSampleRateStateFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDigitalLensControlALMALENCE>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthImageAcquireInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthImageMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthImageViewMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthProviderCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEnvironmentDepthSwapchainStateMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_BUFFER:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataBuffer>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataDisplayRefreshRateChangedFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataEventsLost>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataEyeCalibrationChangedML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataHeadsetFitChangedML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataInstanceLossPending>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataInteractionProfileChanged>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataLocalizationChangedML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataMainSessionVisibilityChangedEXTX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataMarkerTrackingUpdateVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataPassthroughStateChangedFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataPerfSettingsEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataReferenceSpaceChangePending>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSceneCaptureCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSessionStateChanged>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceEraseCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceListSaveCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceQueryCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceQueryResultsAvailableFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceSaveCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceSetStatusCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpaceShareCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataSpatialAnchorCreateCompleteFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataUserPresenceChangedEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVirtualKeyboardBackspaceMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVirtualKeyboardCommitTextMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVirtualKeyboardEnterMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVirtualKeyboardHiddenMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVirtualKeyboardShownMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataVisibilityMaskChangedKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEventDataViveTrackerConnectedHTCX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EXTENSION_PROPERTIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrExtensionProperties>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrExternalCameraOCULUS>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEyeGazeSampleTimeEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EYE_GAZES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEyeGazesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EYE_GAZES_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEyeGazesInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEyeTrackerCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceExpressionInfo2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_EXPRESSION_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceExpressionInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceExpressionWeights2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceExpressionWeightsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceTrackerCreateInfo2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFaceTrackerCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFacialExpressionsHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFacialTrackerCreateInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveatedViewConfigurationViewVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationApplyInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationCustomModeInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationDynamicModeInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationEyeTrackedStateMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationLevelProfileCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationProfileCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_BEGIN_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameBeginInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_END_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameEndInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_END_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameEndInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_STATE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameState>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_WAIT_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameWaitInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFutureCancelInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FUTURE_COMPLETION_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFutureCompletionEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FUTURE_POLL_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFuturePollInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FUTURE_POLL_RESULT_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFuturePollResultEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGeometryInstanceCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGeometryInstanceTransformFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGlobalDimmerFrameEndInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingD3D11KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingD3D12KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingEGLMNDX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingMetalKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLESAndroidKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLWaylandKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLWin32KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLXcbKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLXlibKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingVulkanKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsD3D11KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsD3D12KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsMetalKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsOpenGLESKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsOpenGLKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsRequirementsVulkanKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointLocationsEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointVelocitiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointsLocateInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointsMotionRangeInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_MESH_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandMeshMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandMeshSpaceCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandMeshUpdateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandPoseTypeInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackerCreateInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingAimStateFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingCapsulesStateFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingDataSourceInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingDataSourceStateEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_MESH_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingMeshFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_SCALE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingScaleFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAPTIC_ACTION_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHapticActionInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHapticAmplitudeEnvelopeVibrationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHapticPcmVibrationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAPTIC_VIBRATION:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHapticVibration>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHolographicWindowAttachmentMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInputSourceLocalizedNameGetInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INSTANCE_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInstanceCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInstanceCreateInfoAndroidKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INSTANCE_PROPERTIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInstanceProperties>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInteractionProfileAnalogThresholdVALVE>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInteractionProfileDpadBindingEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INTERACTION_PROFILE_STATE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInteractionProfileState>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInteractionProfileSuggestedBinding>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrKeyboardSpaceCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrKeyboardTrackingQueryFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLoaderInitInfoAndroidKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLocalDimmingFrameEndInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLocalizationEnableEventsInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLocalizationMapImportInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOCALIZATION_MAP_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLocalizationMapML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMapLocalizationRequestInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorAprilTagInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorArucoInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorCreateInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorCustomProfileInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorSizeInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorSnapshotInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_STATE_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorStateML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerSpaceCreateInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerSpaceCreateInfoVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrNewSceneComputeInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughBrightnessContrastSaturationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorLutCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorLutUpdateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapInterpolatedLutMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapLutMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapMonoToMonoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapMonoToRgbaFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughCreateInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughKeyboardHandsIntensityFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughLayerCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughMeshTransformInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughPreferencesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_STYLE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughStyleFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPerformanceMetricsCounterMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPerformanceMetricsStateMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorBeginInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorCreateInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorGetInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorLocationEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorLocationsEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPlaneDetectorPolygonBufferEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRecommendedLayerResolutionGetInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRecommendedLayerResolutionMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrReferenceSpaceCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_BUFFER_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelBufferFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelCapabilitiesRequestFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelLoadInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelPathInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ROOM_LAYOUT_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRoomLayoutFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneCaptureRequestInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentLocationsMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentParentFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentsGetInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentsLocateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENTS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentsMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneDeserializeInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkerQRCodesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkerTypeFilterMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKERS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkersMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshBuffersGetInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshBuffersMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshIndicesUint16MSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshIndicesUint32MSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshVertexBufferMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESHES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneObjectTypesFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_OBJECTS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneObjectsMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneObserverCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrScenePlaneAlignmentFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_PLANES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrScenePlanesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationFrameStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SEMANTIC_LABELS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSemanticLabelsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSemanticLabelsSupportInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSessionActionSetsAttachInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SESSION_BEGIN_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSessionBeginInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SESSION_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSessionCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSessionCreateInfoOverlayEXTX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceComponentFilterInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceComponentStatusFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceComponentStatusSetInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_CONTAINER_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceContainerFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_ERASE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceEraseInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceListSaveInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_LOCATION:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceLocation>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_LOCATIONS:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceLocations>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_QUERY_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceQueryInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_QUERY_RESULTS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceQueryResultsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_SAVE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceSaveInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_SHARE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceShareInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceStorageLocationFilterInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceTriangleMeshGetInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_TRIANGLE_MESH_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceTriangleMeshMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceUserCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceUuidFilterInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_VELOCITIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceVelocities>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_VELOCITY:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceVelocity>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACES_LOCATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpacesLocateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorCreateInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorPersistenceInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_CREATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainCreateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainCreateInfoFoveationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageAcquireInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageD3D11KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageD3D12KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageFoveationVulkanFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageMetalKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageOpenGLESKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageOpenGLKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageReleaseInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageVulkanKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageWaitInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainStateFoveationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainStateSamplerOpenGLESFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainStateSamplerVulkanFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemAnchorPropertiesHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemBodyTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemColorSpacePropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemEnvironmentDepthPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemEyeGazeInteractionPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemEyeTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFaceTrackingProperties2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFaceTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFacialTrackingPropertiesHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemForceFeedbackCurlPropertiesMNDX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFoveatedRenderingPropertiesVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFoveationEyeTrackedPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_GET_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemGetInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHandTrackingMeshPropertiesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHandTrackingPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHeadsetIdPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemKeyboardTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemMarkerTrackingPropertiesVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemMarkerUnderstandingPropertiesML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughColorLutPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughProperties2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPlaneDetectionPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PROPERTIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemProperties>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemRenderModelPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemSpaceWarpPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemSpatialEntityPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemUserPresencePropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemVirtualKeyboardPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrTriangleMeshCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrUserCalibrationEnableEventsInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrView>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationDepthRangeEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationProperties>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_VIEW:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationView>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationViewFovEPIC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewLocateFoveatedRenderingVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_LOCATE_INFO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewLocateInfo>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_STATE:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewState>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardAnimationStateMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardInputInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardLocationInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVirtualKeyboardTextureDataMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VISIBILITY_MASK_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVisibilityMaskKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVisualMeshComputeLodInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViveTrackerPathsHTCX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanDeviceCreateInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanInstanceCreateInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanSwapchainCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanSwapchainFormatListCreateInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            }
        }
    }

    if ((bytes_read == 0) && (attrib != 0))
    {
        // The encoded pointer attribute mask included kIsNull, or the type was unrecognized.
        // We will report that we read the attribute mask, but nothing else was decoded.
        bytes_read = sizeof(attrib);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
