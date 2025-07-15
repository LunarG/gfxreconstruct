/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_ENUM_UTIL_H
#define GFXRECON_DECODE_OPENXR_ENUM_UTIL_H

#if ENABLE_OPENXR_SUPPORT

#include "util/defines.h"

#include "openxr/openxr.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(enumutil)

/**
 * Get VkResult code description.
 *
 * Returns a string describing the specified VkResult code.  The description is based on the language in the Vulkan API
 * specification.
 *
 * @param value VkResult code to process.
 * @return String describing the specified VkResult code.
 */
static const char* GetResultDescription(XrResult result)
{
    switch (result)
    {
        case XR_SUCCESS:
            return "Function successfully completed.";
        case XR_TIMEOUT_EXPIRED:
            return "The specified timeout time occurred before the operation could complete.";
        case XR_SESSION_LOSS_PENDING:
            return "The session will be lost soon.";
        case XR_EVENT_UNAVAILABLE:
            return "No event was available.";
        case XR_SPACE_BOUNDS_UNAVAILABLE:
            return "The space\'s bounds are not known at the moment.";
        case XR_SESSION_NOT_FOCUSED:
            return "The session is not in the focused state.";
        case XR_FRAME_DISCARDED:
            return "A frame has been discarded from composition.";
        case XR_ERROR_VALIDATION_FAILURE:
            return "The function usage was invalid in some way.";
        case XR_ERROR_RUNTIME_FAILURE:
            return "The runtime failed to handle the function in an unexpected way that is not covered by another "
                   "error result.";
        case XR_ERROR_OUT_OF_MEMORY:
            return "A memory allocation has failed.";
        case XR_ERROR_API_VERSION_UNSUPPORTED:
            return "The runtime does not support the requested AP version.";
        case XR_ERROR_INITIALIZATION_FAILED:
            return "Initialization of object could not be completed.";
        case XR_ERROR_FUNCTION_UNSUPPORTED:
            return "The requested function was not found or is otherwise unsupported.";
        case XR_ERROR_FEATURE_UNSUPPORTED:
            return "The requested feature is not supported.";
        case XR_ERROR_EXTENSION_NOT_PRESENT:
            return "A requested extension is not supported.";
        case XR_ERROR_LIMIT_REACHED:
            return "The runtime supports no more of the requested resource.";
        case XR_ERROR_SIZE_INSUFFICIENT:
            return "The supplied size was smaller than required.";
        case XR_ERROR_HANDLE_INVALID:
            return "A supplied object handle was invalid.";
        case XR_ERROR_INSTANCE_LOST:
            return "The XrInstance was lost or could not be found. It will need to be destroyed and optionally "
                   "recreated.";
        case XR_ERROR_SESSION_RUNNING:
            return "The session is already running.";
        case XR_ERROR_SESSION_NOT_RUNNING:
            return "The session is not yet running.";
        case XR_ERROR_SESSION_LOST:
            return "The XrSession was lost. It will need to be destroyed and optionally recreated.";
        case XR_ERROR_SYSTEM_INVALID:
            return "The provided XrSystemId was invalid.";
        case XR_ERROR_PATH_INVALID:
            return "The provided XrPath was not valid.";
        case XR_ERROR_PATH_COUNT_EXCEEDED:
            return "The maximum number of supported semantic paths has been reached.";
        case XR_ERROR_PATH_FORMAT_INVALID:
            return "The semantic path character format is invalid.";
        case XR_ERROR_PATH_UNSUPPORTED:
            return "The semantic path is unsupported.";
        case XR_ERROR_LAYER_INVALID:
            return "The layer was NULL or otherwise invalid.";
        case XR_ERROR_LAYER_LIMIT_EXCEEDED:
            return "The number of specified layers is greater than the supported number.";
        case XR_ERROR_SWAPCHAIN_RECT_INVALID:
            return "The image rect was negatively sized or otherwise invalid.";
        case XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED:
            return "The image format is not supported by the runtime or platform.";
        case XR_ERROR_ACTION_TYPE_MISMATCH:
            return "The API used to retrieve an action\'s state does not match the action\'s type.";
        case XR_ERROR_SESSION_NOT_READY:
            return "The session is not in the ready state.";
        case XR_ERROR_SESSION_NOT_STOPPING:
            return "The session is not in the stopping state.";
        case XR_ERROR_TIME_INVALID:
            return "The provided XrTime was zero, negative, or out of range.";
        case XR_ERROR_REFERENCE_SPACE_UNSUPPORTED:
            return "The specified reference space is not supported by the runtime or system.";
        case XR_ERROR_FILE_ACCESS_ERROR:
            return "The file could not be accessed.";
        case XR_ERROR_FILE_CONTENTS_INVALID:
            return "The file\'s contents were invalid.";
        case XR_ERROR_FORM_FACTOR_UNSUPPORTED:
            return "The specified form factor is not supported by the current runtime or platform.";
        case XR_ERROR_FORM_FACTOR_UNAVAILABLE:
            return "The specified form factor is supported, but the device is currently not available, e.g. not "
                   "plugged in or powered off.";
        case XR_ERROR_API_LAYER_NOT_PRESENT:
            return "A requested API layer is not present or could not be loaded.";
        case XR_ERROR_CALL_ORDER_INVALID:
            return "The call was made without having made a previously required call.";
        case XR_ERROR_GRAPHICS_DEVICE_INVALID:
            return "The given graphics device is not in a valid state. The graphics device could be lost or "
                   "initialized without meeting graphics requirements.";
        case XR_ERROR_POSE_INVALID:
            return "The supplied pose was invalid with respect to the requirements.";
        case XR_ERROR_INDEX_OUT_OF_RANGE:
            return "The supplied index was outside the range of valid indices.";
        case XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED:
            return "The specified view configuration type is not supported by the runtime or platform.";
        case XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED:
            return "The specified environment blend mode is not supported by the runtime or platform.";
        case XR_ERROR_NAME_DUPLICATED:
            return "The name provided was a duplicate of an already-existing resource.";
        case XR_ERROR_NAME_INVALID:
            return "The name provided was invalid.";
        case XR_ERROR_ACTIONSET_NOT_ATTACHED:
            return "A referenced action set is not attached to the session.";
        case XR_ERROR_ACTIONSETS_ALREADY_ATTACHED:
            return "The session already has attached action sets.";
        case XR_ERROR_LOCALIZED_NAME_DUPLICATED:
            return "The localized name provided was a duplicate of an already-existing resource.";
        case XR_ERROR_LOCALIZED_NAME_INVALID:
            return "The localized name provided was invalid.";
        case XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING:
            return "The xrGetGraphicsRequirements* call was not made before calling xrCreateSession.";
        case XR_ERROR_RUNTIME_UNAVAILABLE:
            return "The loader was unable to find or load a runtime.";
        case XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR:
            return "xrSetAndroidApplicationThreadKHR failed as thread id is invalid. (Added by the "
                   "XR_KHR_android_thread_settings extension)";
        case XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR:
            return "xrSetAndroidApplicationThreadKHR failed setting the thread attributes/priority. (Added by the "
                   "XR_KHR_android_thread_settings extension)";
        case XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT:
            return "Spatial anchor could not be created at that location. (Added by the XR_MSFT_spatial_anchor "
                   "extension)";
        case XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT:
            return "The secondary view configuration was not enabled when creating the session. (Added by the "
                   "XR_MSFT_secondary_view_configuration extension)";
        case XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT:
            return "The controller model key is invalid. (Added by the XR_MSFT_controller_model extension)";
        case XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT:
            return "The reprojection mode is not supported. (Added by the XR_MSFT_composition_layer_reprojection "
                   "extension)";
        case XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT:
            return "Compute new scene not completed. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT:
            return "Scene component id invalid. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT:
            return "Scene component type mismatch. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT:
            return "Scene mesh buffer id invalid. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT:
            return "Scene compute feature incompatible. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT:
            return "Scene compute consistency mismatch. (Added by the XR_MSFT_scene_understanding extension)";
        case XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB:
            return "The display refresh rate is not supported by the platform. (Added by the "
                   "XR_FB_display_refresh_rate extension)";
        case XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB:
            return "The color space is not supported by the runtime. (Added by the XR_FB_color_space extension)";
        case XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB:
            return "The component type is not supported for this space. (Added by the XR_FB_spatial_entity extension)";
        case XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB:
            return "The required component is not enabled for this space. (Added by the XR_FB_spatial_entit extension)";
        case XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB:
            return "A request to set the component\'s status is currently pending. (Added by the XR_FB_spatial_entity "
                   "extension)";
        case XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB:
            return "The component is already set to the requested value. (Added by the XR_FB_spatial_entity extension)";
        case XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB:
            return "The object state is unexpected for the issued command. (Added by the XR_FB_passthrough extension)";
        case XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB:
            return "Trying to create an MR feature when one was already created and only one instance is allowed. "
                   "(Added by the XR_FB_passthrough extension)";
        case XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB:
            return "Requested functionality requires a feature to be created first. (Added by the XR_FB_passthrough "
                   "extension)";
        case XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB:
            return "Requested functionality is not permitted - application is not allowed to perform the requested "
                   "operation. (Added by the XR_FB_passthrough extension)";
        case XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB:
            return "There weren\'t sufficient resources available to perform an operation. (Added by the "
                   "XR_FB_passthrough extension)";
        case XR_ERROR_UNKNOWN_PASSTHROUGH_FB:
            return "Unknown Passthrough error (no further details provided). (Added by the XR_FB_passthrough "
                   "extension)";
        case XR_ERROR_RENDER_MODEL_KEY_INVALID_FB:
            return "The model key is invalid. (Added by the XR_FB_render_model extension)";
        case XR_RENDER_MODEL_UNAVAILABLE_FB:
            return "The model is unavailable. (Added by the XR_FB_render_model extension)";
        case XR_ERROR_MARKER_NOT_TRACKED_VARJO:
            return "Marker tracking is disabled or the specified marker is not currently tracked. (Added by the "
                   "XR_VARJO_marker_tracking extension)";
        case XR_ERROR_MARKER_ID_INVALID_VARJO:
            return "The specified marker ID is not valid. (Added by the XR_VARJO_marker_tracking extension)";
        case XR_ERROR_MARKER_DETECTOR_PERMISSION_DENIED_ML:
            return "The com.magicleap.permission.MARKER_TRACKING permission was denied. (Added by the "
                   "XR_ML_marker_understanding extension)";
        case XR_ERROR_MARKER_DETECTOR_LOCATE_FAILED_ML:
            return "The specified marker could not be located spatially. (Added by the XR_ML_marker_understanding "
                   "extension)";
        case XR_ERROR_MARKER_DETECTOR_INVALID_DATA_QUERY_ML:
            return "The marker queried does not contain data of the requested type. (Added by the "
                   "XR_ML_marker_understanding extension)";
        case XR_ERROR_MARKER_DETECTOR_INVALID_CREATE_INFO_ML:
            return "createInfo contains mutually exclusive parameters, such as setting "
                   "XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_APRIL_TAG_ML with XR_MARKER_TYPE_ARUCO_ML. (Added by the "
                   "XR_ML_marker_understanding extension)";
        case XR_ERROR_MARKER_INVALID_ML:
            return "The marker id passed to the function was invalid. (Added by the XR_ML_marker_understanding "
                   "extension)";
        case XR_ERROR_LOCALIZATION_MAP_INCOMPATIBLE_ML:
            return "The localization map being imported is not compatible with current OS or mode. (Added by the "
                   "XR_ML_localization_map extension)";
        case XR_ERROR_LOCALIZATION_MAP_UNAVAILABLE_ML:
            return "The localization map requested is not available. (Added by the XR_ML_localization_map extension)";
        case XR_ERROR_LOCALIZATION_MAP_FAIL_ML:
            return "The map localization service failed to fulfill the request, retry later. (Added by the "
                   "XR_ML_localization_map extension)";
        case XR_ERROR_LOCALIZATION_MAP_IMPORT_EXPORT_PERMISSION_DENIED_ML:
            return "The com.magicleap.permission.SPACE_IMPORT_EXPORT permission was denied. (Added by the "
                   "XR_ML_localization_map extension)";
        case XR_ERROR_LOCALIZATION_MAP_PERMISSION_DENIED_ML:
            return "The com.magicleap.permission.SPACE_MANAGER permission was denied. (Added by the "
                   "XR_ML_localization_map extension)";
        case XR_ERROR_LOCALIZATION_MAP_ALREADY_EXISTS_ML:
            return "The map being imported already exists in the system. (Added by the XR_ML_localization_map "
                   "extension)";
        case XR_ERROR_LOCALIZATION_MAP_CANNOT_EXPORT_CLOUD_MAP_ML:
            return "The map localization service cannot export cloud based maps. (Added by the XR_ML_localization_map "
                   "extension)";
        case XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT:
            return "A spatial anchor was not found associated with the spatial anchor name provided (Added by the "
                   "XR_MSFT_spatial_anchor_persistence extension)";
        case XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT:
            return "The spatial anchor name provided was not valid (Added by the XR_MSFT_spatial_anchor_persistence "
                   "extension)";
        case XR_SCENE_MARKER_DATA_NOT_STRING_MSFT:
            return "Marker does not encode a string. (Added by the XR_MSFT_scene_marker extension)";
        case XR_ERROR_SPACE_MAPPING_INSUFFICIENT_FB:
            return "Anchor import from cloud or export from device failed. (Added by the XR_FB_spatial_entity_sharing "
                   "extension)";
        case XR_ERROR_SPACE_LOCALIZATION_FAILED_FB:
            return "Anchors were downloaded from the cloud but failed to be imported/aligned on the device. (Added by "
                   "the XR_FB_spatial_entity_sharing extension)";
        case XR_ERROR_SPACE_NETWORK_TIMEOUT_FB:
            return "Timeout occurred while waiting for network request to complete. (Added by the "
                   "XR_FB_spatial_entity_sharing extension)";
        case XR_ERROR_SPACE_NETWORK_REQUEST_FAILED_FB:
            return "The network request failed. (Added by the XR_FB_spatial_entity_sharing extension)";
        case XR_ERROR_SPACE_CLOUD_STORAGE_DISABLED_FB:
            return "Cloud storage is required for this operation but is currently disabled. (Added by the "
                   "XR_FB_spatial_entity_sharing extension)";
        case XR_ERROR_PASSTHROUGH_COLOR_LUT_BUFFER_SIZE_MISMATCH_META:
            return "The provided data buffer did not match the required size. (Added by the "
                   "XR_META_passthrough_color_lut extension)";
        case XR_ERROR_HINT_ALREADY_SET_QCOM:
            return "Tracking optimization hint is already set for the domain. (Added by the "
                   "XR_QCOM_tracking_optimization_settings extension)";
        case XR_ERROR_NOT_AN_ANCHOR_HTC:
            return "The provided space is valid but not an anchor. (Added by the XR_HTC_anchor extension)";
        case XR_ERROR_SPACE_NOT_LOCATABLE_EXT:
            return "The space passed to the function was not locatable. (Added by the XR_EXT_plane_detection "
                   "extension)";
        case XR_ERROR_PLANE_DETECTION_PERMISSION_DENIED_EXT:
            return "The permission for this resource was not granted. (Added by the XR_EXT_plane_detection extension)";
        default:
            return "an error has occurred";
    }
}

GFXRECON_END_NAMESPACE(enumutil)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_ENUM_UTIL_H
