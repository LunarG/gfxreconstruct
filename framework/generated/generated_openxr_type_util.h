/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_OPENXR_TYPE_UTIL_H
#define  GFXRECON_GENERATED_OPENXR_TYPE_UTIL_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Instantiating the primary template indicates that either the template was
// called with an invalid OpenXR struct type or that the code generation is out
// of date, both of which are errors
template <typename T> XrStructureType GetType() = delete;

template <> constexpr XrStructureType GetType<XrApiLayerProperties>(){ return XR_TYPE_API_LAYER_PROPERTIES; }
template <> constexpr XrStructureType GetType<XrExtensionProperties>(){ return XR_TYPE_EXTENSION_PROPERTIES; }
template <> constexpr XrStructureType GetType<XrInstanceCreateInfo>(){ return XR_TYPE_INSTANCE_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrInstanceProperties>(){ return XR_TYPE_INSTANCE_PROPERTIES; }
template <> constexpr XrStructureType GetType<XrEventDataBuffer>(){ return XR_TYPE_EVENT_DATA_BUFFER; }
template <> constexpr XrStructureType GetType<XrSystemGetInfo>(){ return XR_TYPE_SYSTEM_GET_INFO; }
template <> constexpr XrStructureType GetType<XrSystemProperties>(){ return XR_TYPE_SYSTEM_PROPERTIES; }
template <> constexpr XrStructureType GetType<XrSessionCreateInfo>(){ return XR_TYPE_SESSION_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrSpaceVelocity>(){ return XR_TYPE_SPACE_VELOCITY; }
template <> constexpr XrStructureType GetType<XrReferenceSpaceCreateInfo>(){ return XR_TYPE_REFERENCE_SPACE_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrActionSpaceCreateInfo>(){ return XR_TYPE_ACTION_SPACE_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrSpaceLocation>(){ return XR_TYPE_SPACE_LOCATION; }
template <> constexpr XrStructureType GetType<XrViewConfigurationProperties>(){ return XR_TYPE_VIEW_CONFIGURATION_PROPERTIES; }
template <> constexpr XrStructureType GetType<XrViewConfigurationView>(){ return XR_TYPE_VIEW_CONFIGURATION_VIEW; }
template <> constexpr XrStructureType GetType<XrSwapchainCreateInfo>(){ return XR_TYPE_SWAPCHAIN_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrSwapchainImageAcquireInfo>(){ return XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO; }
template <> constexpr XrStructureType GetType<XrSwapchainImageWaitInfo>(){ return XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO; }
template <> constexpr XrStructureType GetType<XrSwapchainImageReleaseInfo>(){ return XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO; }
template <> constexpr XrStructureType GetType<XrSessionBeginInfo>(){ return XR_TYPE_SESSION_BEGIN_INFO; }
template <> constexpr XrStructureType GetType<XrFrameWaitInfo>(){ return XR_TYPE_FRAME_WAIT_INFO; }
template <> constexpr XrStructureType GetType<XrFrameState>(){ return XR_TYPE_FRAME_STATE; }
template <> constexpr XrStructureType GetType<XrFrameBeginInfo>(){ return XR_TYPE_FRAME_BEGIN_INFO; }
template <> constexpr XrStructureType GetType<XrFrameEndInfo>(){ return XR_TYPE_FRAME_END_INFO; }
template <> constexpr XrStructureType GetType<XrViewLocateInfo>(){ return XR_TYPE_VIEW_LOCATE_INFO; }
template <> constexpr XrStructureType GetType<XrViewState>(){ return XR_TYPE_VIEW_STATE; }
template <> constexpr XrStructureType GetType<XrView>(){ return XR_TYPE_VIEW; }
template <> constexpr XrStructureType GetType<XrActionSetCreateInfo>(){ return XR_TYPE_ACTION_SET_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrActionCreateInfo>(){ return XR_TYPE_ACTION_CREATE_INFO; }
template <> constexpr XrStructureType GetType<XrInteractionProfileSuggestedBinding>(){ return XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING; }
template <> constexpr XrStructureType GetType<XrSessionActionSetsAttachInfo>(){ return XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO; }
template <> constexpr XrStructureType GetType<XrInteractionProfileState>(){ return XR_TYPE_INTERACTION_PROFILE_STATE; }
template <> constexpr XrStructureType GetType<XrActionStateGetInfo>(){ return XR_TYPE_ACTION_STATE_GET_INFO; }
template <> constexpr XrStructureType GetType<XrActionStateBoolean>(){ return XR_TYPE_ACTION_STATE_BOOLEAN; }
template <> constexpr XrStructureType GetType<XrActionStateFloat>(){ return XR_TYPE_ACTION_STATE_FLOAT; }
template <> constexpr XrStructureType GetType<XrActionStateVector2f>(){ return XR_TYPE_ACTION_STATE_VECTOR2F; }
template <> constexpr XrStructureType GetType<XrActionStatePose>(){ return XR_TYPE_ACTION_STATE_POSE; }
template <> constexpr XrStructureType GetType<XrActionsSyncInfo>(){ return XR_TYPE_ACTIONS_SYNC_INFO; }
template <> constexpr XrStructureType GetType<XrBoundSourcesForActionEnumerateInfo>(){ return XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO; }
template <> constexpr XrStructureType GetType<XrInputSourceLocalizedNameGetInfo>(){ return XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO; }
template <> constexpr XrStructureType GetType<XrHapticActionInfo>(){ return XR_TYPE_HAPTIC_ACTION_INFO; }
template <> constexpr XrStructureType GetType<XrCompositionLayerProjectionView>(){ return XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW; }
template <> constexpr XrStructureType GetType<XrCompositionLayerProjection>(){ return XR_TYPE_COMPOSITION_LAYER_PROJECTION; }
template <> constexpr XrStructureType GetType<XrCompositionLayerQuad>(){ return XR_TYPE_COMPOSITION_LAYER_QUAD; }
template <> constexpr XrStructureType GetType<XrEventDataEventsLost>(){ return XR_TYPE_EVENT_DATA_EVENTS_LOST; }
template <> constexpr XrStructureType GetType<XrEventDataInstanceLossPending>(){ return XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING; }
template <> constexpr XrStructureType GetType<XrEventDataSessionStateChanged>(){ return XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED; }
template <> constexpr XrStructureType GetType<XrEventDataReferenceSpaceChangePending>(){ return XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING; }
template <> constexpr XrStructureType GetType<XrEventDataInteractionProfileChanged>(){ return XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED; }
template <> constexpr XrStructureType GetType<XrHapticVibration>(){ return XR_TYPE_HAPTIC_VIBRATION; }
template <> constexpr XrStructureType GetType<XrCompositionLayerCubeKHR>(){ return XR_TYPE_COMPOSITION_LAYER_CUBE_KHR; }
template <> constexpr XrStructureType GetType<XrInstanceCreateInfoAndroidKHR>(){ return XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR; }
template <> constexpr XrStructureType GetType<XrCompositionLayerDepthInfoKHR>(){ return XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR; }
template <> constexpr XrStructureType GetType<XrVulkanSwapchainFormatListCreateInfoKHR>(){ return XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR; }
template <> constexpr XrStructureType GetType<XrCompositionLayerCylinderKHR>(){ return XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR; }
template <> constexpr XrStructureType GetType<XrCompositionLayerEquirectKHR>(){ return XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingOpenGLWin32KHR>(){ return XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingOpenGLXlibKHR>(){ return XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingOpenGLXcbKHR>(){ return XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingOpenGLWaylandKHR>(){ return XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR; }
template <> constexpr XrStructureType GetType<XrSwapchainImageOpenGLKHR>(){ return XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsRequirementsOpenGLKHR>(){ return XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingOpenGLESAndroidKHR>(){ return XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR; }
template <> constexpr XrStructureType GetType<XrSwapchainImageOpenGLESKHR>(){ return XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsRequirementsOpenGLESKHR>(){ return XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingVulkanKHR>(){ return XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR; }
template <> constexpr XrStructureType GetType<XrSwapchainImageVulkanKHR>(){ return XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsRequirementsVulkanKHR>(){ return XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingD3D11KHR>(){ return XR_TYPE_GRAPHICS_BINDING_D3D11_KHR; }
template <> constexpr XrStructureType GetType<XrSwapchainImageD3D11KHR>(){ return XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsRequirementsD3D11KHR>(){ return XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingD3D12KHR>(){ return XR_TYPE_GRAPHICS_BINDING_D3D12_KHR; }
template <> constexpr XrStructureType GetType<XrSwapchainImageD3D12KHR>(){ return XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR; }
template <> constexpr XrStructureType GetType<XrGraphicsRequirementsD3D12KHR>(){ return XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR; }
template <> constexpr XrStructureType GetType<XrVisibilityMaskKHR>(){ return XR_TYPE_VISIBILITY_MASK_KHR; }
template <> constexpr XrStructureType GetType<XrEventDataVisibilityMaskChangedKHR>(){ return XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR; }
template <> constexpr XrStructureType GetType<XrCompositionLayerColorScaleBiasKHR>(){ return XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR; }
template <> constexpr XrStructureType GetType<XrLoaderInitInfoAndroidKHR>(){ return XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR; }
template <> constexpr XrStructureType GetType<XrVulkanInstanceCreateInfoKHR>(){ return XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR; }
template <> constexpr XrStructureType GetType<XrVulkanDeviceCreateInfoKHR>(){ return XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR; }
template <> constexpr XrStructureType GetType<XrVulkanGraphicsDeviceGetInfoKHR>(){ return XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR; }
template <> constexpr XrStructureType GetType<XrCompositionLayerEquirect2KHR>(){ return XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR; }
template <> constexpr XrStructureType GetType<XrBindingModificationsKHR>(){ return XR_TYPE_BINDING_MODIFICATIONS_KHR; }
template <> constexpr XrStructureType GetType<XrEventDataPerfSettingsEXT>(){ return XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT; }
template <> constexpr XrStructureType GetType<XrDebugUtilsObjectNameInfoEXT>(){ return XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrDebugUtilsLabelEXT>(){ return XR_TYPE_DEBUG_UTILS_LABEL_EXT; }
template <> constexpr XrStructureType GetType<XrDebugUtilsMessengerCallbackDataEXT>(){ return XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT; }
template <> constexpr XrStructureType GetType<XrDebugUtilsMessengerCreateInfoEXT>(){ return XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrSystemEyeGazeInteractionPropertiesEXT>(){ return XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT; }
template <> constexpr XrStructureType GetType<XrEyeGazeSampleTimeEXT>(){ return XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT; }
template <> constexpr XrStructureType GetType<XrSessionCreateInfoOverlayEXTX>(){ return XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX; }
template <> constexpr XrStructureType GetType<XrEventDataMainSessionVisibilityChangedEXTX>(){ return XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorCreateInfoMSFT>(){ return XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorSpaceCreateInfoMSFT>(){ return XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrCompositionLayerImageLayoutFB>(){ return XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerAlphaBlendFB>(){ return XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB; }
template <> constexpr XrStructureType GetType<XrViewConfigurationDepthRangeEXT>(){ return XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT; }
template <> constexpr XrStructureType GetType<XrGraphicsBindingEGLMNDX>(){ return XR_TYPE_GRAPHICS_BINDING_EGL_MNDX; }
template <> constexpr XrStructureType GetType<XrSpatialGraphNodeSpaceCreateInfoMSFT>(){ return XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSpatialGraphStaticNodeBindingCreateInfoMSFT>(){ return XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>(){ return XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSpatialGraphNodeBindingPropertiesMSFT>(){ return XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT; }
template <> constexpr XrStructureType GetType<XrSystemHandTrackingPropertiesEXT>(){ return XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT; }
template <> constexpr XrStructureType GetType<XrHandTrackerCreateInfoEXT>(){ return XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrHandJointsLocateInfoEXT>(){ return XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrHandJointLocationsEXT>(){ return XR_TYPE_HAND_JOINT_LOCATIONS_EXT; }
template <> constexpr XrStructureType GetType<XrHandJointVelocitiesEXT>(){ return XR_TYPE_HAND_JOINT_VELOCITIES_EXT; }
template <> constexpr XrStructureType GetType<XrSystemHandTrackingMeshPropertiesMSFT>(){ return XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT; }
template <> constexpr XrStructureType GetType<XrHandMeshSpaceCreateInfoMSFT>(){ return XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrHandMeshUpdateInfoMSFT>(){ return XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrHandMeshMSFT>(){ return XR_TYPE_HAND_MESH_MSFT; }
template <> constexpr XrStructureType GetType<XrHandPoseTypeInfoMSFT>(){ return XR_TYPE_HAND_POSE_TYPE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationSessionBeginInfoMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationStateMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationFrameStateMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationLayerInfoMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationFrameEndInfoMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSecondaryViewConfigurationSwapchainCreateInfoMSFT>(){ return XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrControllerModelKeyStateMSFT>(){ return XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT; }
template <> constexpr XrStructureType GetType<XrControllerModelNodePropertiesMSFT>(){ return XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT; }
template <> constexpr XrStructureType GetType<XrControllerModelPropertiesMSFT>(){ return XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT; }
template <> constexpr XrStructureType GetType<XrControllerModelNodeStateMSFT>(){ return XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT; }
template <> constexpr XrStructureType GetType<XrControllerModelStateMSFT>(){ return XR_TYPE_CONTROLLER_MODEL_STATE_MSFT; }
template <> constexpr XrStructureType GetType<XrViewConfigurationViewFovEPIC>(){ return XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC; }
template <> constexpr XrStructureType GetType<XrHolographicWindowAttachmentMSFT>(){ return XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT; }
template <> constexpr XrStructureType GetType<XrCompositionLayerReprojectionInfoMSFT>(){ return XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrCompositionLayerReprojectionPlaneOverrideMSFT>(){ return XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT; }
template <> constexpr XrStructureType GetType<XrAndroidSurfaceSwapchainCreateInfoFB>(){ return XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerSecureContentFB>(){ return XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB; }
template <> constexpr XrStructureType GetType<XrSystemBodyTrackingPropertiesFB>(){ return XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrBodyTrackerCreateInfoFB>(){ return XR_TYPE_BODY_TRACKER_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrBodySkeletonFB>(){ return XR_TYPE_BODY_SKELETON_FB; }
template <> constexpr XrStructureType GetType<XrBodyJointsLocateInfoFB>(){ return XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrBodyJointLocationsFB>(){ return XR_TYPE_BODY_JOINT_LOCATIONS_FB; }
template <> constexpr XrStructureType GetType<XrInteractionProfileDpadBindingEXT>(){ return XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT; }
template <> constexpr XrStructureType GetType<XrInteractionProfileAnalogThresholdVALVE>(){ return XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE; }
template <> constexpr XrStructureType GetType<XrHandJointsMotionRangeInfoEXT>(){ return XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrSceneObserverCreateInfoMSFT>(){ return XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneCreateInfoMSFT>(){ return XR_TYPE_SCENE_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrNewSceneComputeInfoMSFT>(){ return XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrVisualMeshComputeLodInfoMSFT>(){ return XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneComponentsMSFT>(){ return XR_TYPE_SCENE_COMPONENTS_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneComponentsGetInfoMSFT>(){ return XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneComponentLocationsMSFT>(){ return XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneComponentsLocateInfoMSFT>(){ return XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneObjectsMSFT>(){ return XR_TYPE_SCENE_OBJECTS_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneComponentParentFilterInfoMSFT>(){ return XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneObjectTypesFilterInfoMSFT>(){ return XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrScenePlanesMSFT>(){ return XR_TYPE_SCENE_PLANES_MSFT; }
template <> constexpr XrStructureType GetType<XrScenePlaneAlignmentFilterInfoMSFT>(){ return XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshesMSFT>(){ return XR_TYPE_SCENE_MESHES_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshBuffersGetInfoMSFT>(){ return XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshBuffersMSFT>(){ return XR_TYPE_SCENE_MESH_BUFFERS_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshVertexBufferMSFT>(){ return XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshIndicesUint32MSFT>(){ return XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMeshIndicesUint16MSFT>(){ return XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT; }
template <> constexpr XrStructureType GetType<XrSerializedSceneFragmentDataGetInfoMSFT>(){ return XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneDeserializeInfoMSFT>(){ return XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrEventDataDisplayRefreshRateChangedFB>(){ return XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB; }
template <> constexpr XrStructureType GetType<XrViveTrackerPathsHTCX>(){ return XR_TYPE_VIVE_TRACKER_PATHS_HTCX; }
template <> constexpr XrStructureType GetType<XrEventDataViveTrackerConnectedHTCX>(){ return XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX; }
template <> constexpr XrStructureType GetType<XrSystemFacialTrackingPropertiesHTC>(){ return XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC; }
template <> constexpr XrStructureType GetType<XrFacialExpressionsHTC>(){ return XR_TYPE_FACIAL_EXPRESSIONS_HTC; }
template <> constexpr XrStructureType GetType<XrFacialTrackerCreateInfoHTC>(){ return XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrSystemColorSpacePropertiesFB>(){ return XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrHandTrackingMeshFB>(){ return XR_TYPE_HAND_TRACKING_MESH_FB; }
template <> constexpr XrStructureType GetType<XrHandTrackingScaleFB>(){ return XR_TYPE_HAND_TRACKING_SCALE_FB; }
template <> constexpr XrStructureType GetType<XrHandTrackingAimStateFB>(){ return XR_TYPE_HAND_TRACKING_AIM_STATE_FB; }
template <> constexpr XrStructureType GetType<XrHandTrackingCapsulesStateFB>(){ return XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB; }
template <> constexpr XrStructureType GetType<XrSystemSpatialEntityPropertiesFB>(){ return XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorCreateInfoFB>(){ return XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceComponentStatusSetInfoFB>(){ return XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceComponentStatusFB>(){ return XR_TYPE_SPACE_COMPONENT_STATUS_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpatialAnchorCreateCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceSetStatusCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrFoveationProfileCreateInfoFB>(){ return XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainCreateInfoFoveationFB>(){ return XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainStateFoveationFB>(){ return XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB; }
template <> constexpr XrStructureType GetType<XrFoveationLevelProfileCreateInfoFB>(){ return XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemKeyboardTrackingPropertiesFB>(){ return XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrKeyboardSpaceCreateInfoFB>(){ return XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrKeyboardTrackingQueryFB>(){ return XR_TYPE_KEYBOARD_TRACKING_QUERY_FB; }
template <> constexpr XrStructureType GetType<XrTriangleMeshCreateInfoFB>(){ return XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemPassthroughPropertiesFB>(){ return XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrSystemPassthroughProperties2FB>(){ return XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughCreateInfoFB>(){ return XR_TYPE_PASSTHROUGH_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughLayerCreateInfoFB>(){ return XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerPassthroughFB>(){ return XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB; }
template <> constexpr XrStructureType GetType<XrGeometryInstanceCreateInfoFB>(){ return XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrGeometryInstanceTransformFB>(){ return XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughStyleFB>(){ return XR_TYPE_PASSTHROUGH_STYLE_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughColorMapMonoToRgbaFB>(){ return XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughColorMapMonoToMonoFB>(){ return XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughBrightnessContrastSaturationFB>(){ return XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB; }
template <> constexpr XrStructureType GetType<XrEventDataPassthroughStateChangedFB>(){ return XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB; }
template <> constexpr XrStructureType GetType<XrRenderModelPathInfoFB>(){ return XR_TYPE_RENDER_MODEL_PATH_INFO_FB; }
template <> constexpr XrStructureType GetType<XrRenderModelPropertiesFB>(){ return XR_TYPE_RENDER_MODEL_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrRenderModelBufferFB>(){ return XR_TYPE_RENDER_MODEL_BUFFER_FB; }
template <> constexpr XrStructureType GetType<XrRenderModelLoadInfoFB>(){ return XR_TYPE_RENDER_MODEL_LOAD_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemRenderModelPropertiesFB>(){ return XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrRenderModelCapabilitiesRequestFB>(){ return XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB; }
template <> constexpr XrStructureType GetType<XrViewLocateFoveatedRenderingVARJO>(){ return XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO; }
template <> constexpr XrStructureType GetType<XrFoveatedViewConfigurationViewVARJO>(){ return XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO; }
template <> constexpr XrStructureType GetType<XrSystemFoveatedRenderingPropertiesVARJO>(){ return XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO; }
template <> constexpr XrStructureType GetType<XrCompositionLayerDepthTestVARJO>(){ return XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO; }
template <> constexpr XrStructureType GetType<XrSystemMarkerTrackingPropertiesVARJO>(){ return XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO; }
template <> constexpr XrStructureType GetType<XrEventDataMarkerTrackingUpdateVARJO>(){ return XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO; }
template <> constexpr XrStructureType GetType<XrMarkerSpaceCreateInfoVARJO>(){ return XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO; }
template <> constexpr XrStructureType GetType<XrFrameEndInfoML>(){ return XR_TYPE_FRAME_END_INFO_ML; }
template <> constexpr XrStructureType GetType<XrGlobalDimmerFrameEndInfoML>(){ return XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML; }
template <> constexpr XrStructureType GetType<XrCoordinateSpaceCreateInfoML>(){ return XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML; }
template <> constexpr XrStructureType GetType<XrSystemMarkerUnderstandingPropertiesML>(){ return XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorCreateInfoML>(){ return XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorArucoInfoML>(){ return XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorSizeInfoML>(){ return XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorAprilTagInfoML>(){ return XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorCustomProfileInfoML>(){ return XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorSnapshotInfoML>(){ return XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML; }
template <> constexpr XrStructureType GetType<XrMarkerDetectorStateML>(){ return XR_TYPE_MARKER_DETECTOR_STATE_ML; }
template <> constexpr XrStructureType GetType<XrMarkerSpaceCreateInfoML>(){ return XR_TYPE_MARKER_SPACE_CREATE_INFO_ML; }
template <> constexpr XrStructureType GetType<XrLocalizationMapML>(){ return XR_TYPE_LOCALIZATION_MAP_ML; }
template <> constexpr XrStructureType GetType<XrEventDataLocalizationChangedML>(){ return XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML; }
template <> constexpr XrStructureType GetType<XrMapLocalizationRequestInfoML>(){ return XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML; }
template <> constexpr XrStructureType GetType<XrLocalizationMapImportInfoML>(){ return XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML; }
template <> constexpr XrStructureType GetType<XrLocalizationEnableEventsInfoML>(){ return XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorPersistenceInfoMSFT>(){ return XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>(){ return XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMarkersMSFT>(){ return XR_TYPE_SCENE_MARKERS_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMarkerTypeFilterMSFT>(){ return XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT; }
template <> constexpr XrStructureType GetType<XrSceneMarkerQRCodesMSFT>(){ return XR_TYPE_SCENE_MARKER_QR_CODES_MSFT; }
template <> constexpr XrStructureType GetType<XrSpaceQueryInfoFB>(){ return XR_TYPE_SPACE_QUERY_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceStorageLocationFilterInfoFB>(){ return XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceUuidFilterInfoFB>(){ return XR_TYPE_SPACE_UUID_FILTER_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceComponentFilterInfoFB>(){ return XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceQueryResultsFB>(){ return XR_TYPE_SPACE_QUERY_RESULTS_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceQueryResultsAvailableFB>(){ return XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceQueryCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrSpaceSaveInfoFB>(){ return XR_TYPE_SPACE_SAVE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceEraseInfoFB>(){ return XR_TYPE_SPACE_ERASE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceSaveCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceEraseCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainImageFoveationVulkanFB>(){ return XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainStateAndroidSurfaceDimensionsFB>(){ return XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainStateSamplerOpenGLESFB>(){ return XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB; }
template <> constexpr XrStructureType GetType<XrSwapchainStateSamplerVulkanFB>(){ return XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB; }
template <> constexpr XrStructureType GetType<XrSpaceShareInfoFB>(){ return XR_TYPE_SPACE_SHARE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceShareCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerSpaceWarpInfoFB>(){ return XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemSpaceWarpPropertiesFB>(){ return XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrHapticAmplitudeEnvelopeVibrationFB>(){ return XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB; }
template <> constexpr XrStructureType GetType<XrSemanticLabelsFB>(){ return XR_TYPE_SEMANTIC_LABELS_FB; }
template <> constexpr XrStructureType GetType<XrRoomLayoutFB>(){ return XR_TYPE_ROOM_LAYOUT_FB; }
template <> constexpr XrStructureType GetType<XrBoundary2DFB>(){ return XR_TYPE_BOUNDARY_2D_FB; }
template <> constexpr XrStructureType GetType<XrSemanticLabelsSupportInfoFB>(){ return XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB; }
template <> constexpr XrStructureType GetType<XrDigitalLensControlALMALENCE>(){ return XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE; }
template <> constexpr XrStructureType GetType<XrEventDataSceneCaptureCompleteFB>(){ return XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrSceneCaptureRequestInfoFB>(){ return XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSpaceContainerFB>(){ return XR_TYPE_SPACE_CONTAINER_FB; }
template <> constexpr XrStructureType GetType<XrFoveationEyeTrackedProfileCreateInfoMETA>(){ return XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrFoveationEyeTrackedStateMETA>(){ return XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META; }
template <> constexpr XrStructureType GetType<XrSystemFoveationEyeTrackedPropertiesMETA>(){ return XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META; }
template <> constexpr XrStructureType GetType<XrSystemFaceTrackingPropertiesFB>(){ return XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrFaceTrackerCreateInfoFB>(){ return XR_TYPE_FACE_TRACKER_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrFaceExpressionInfoFB>(){ return XR_TYPE_FACE_EXPRESSION_INFO_FB; }
template <> constexpr XrStructureType GetType<XrFaceExpressionWeightsFB>(){ return XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB; }
template <> constexpr XrStructureType GetType<XrEyeTrackerCreateInfoFB>(){ return XR_TYPE_EYE_TRACKER_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrEyeGazesInfoFB>(){ return XR_TYPE_EYE_GAZES_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemEyeTrackingPropertiesFB>(){ return XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB; }
template <> constexpr XrStructureType GetType<XrEyeGazesFB>(){ return XR_TYPE_EYE_GAZES_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughKeyboardHandsIntensityFB>(){ return XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerSettingsFB>(){ return XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB; }
template <> constexpr XrStructureType GetType<XrHapticPcmVibrationFB>(){ return XR_TYPE_HAPTIC_PCM_VIBRATION_FB; }
template <> constexpr XrStructureType GetType<XrDevicePcmSampleRateStateFB>(){ return XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB; }
template <> constexpr XrStructureType GetType<XrCompositionLayerDepthTestFB>(){ return XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB; }
template <> constexpr XrStructureType GetType<XrLocalDimmingFrameEndInfoMETA>(){ return XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META; }
template <> constexpr XrStructureType GetType<XrPassthroughPreferencesMETA>(){ return XR_TYPE_PASSTHROUGH_PREFERENCES_META; }
template <> constexpr XrStructureType GetType<XrSystemVirtualKeyboardPropertiesMETA>(){ return XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardCreateInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardSpaceCreateInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardLocationInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardModelVisibilitySetInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardAnimationStateMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardModelAnimationStatesMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardTextureDataMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardInputInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META; }
template <> constexpr XrStructureType GetType<XrVirtualKeyboardTextContextChangeInfoMETA>(){ return XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META; }
template <> constexpr XrStructureType GetType<XrEventDataVirtualKeyboardCommitTextMETA>(){ return XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META; }
template <> constexpr XrStructureType GetType<XrEventDataVirtualKeyboardBackspaceMETA>(){ return XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META; }
template <> constexpr XrStructureType GetType<XrEventDataVirtualKeyboardEnterMETA>(){ return XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META; }
template <> constexpr XrStructureType GetType<XrEventDataVirtualKeyboardShownMETA>(){ return XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META; }
template <> constexpr XrStructureType GetType<XrEventDataVirtualKeyboardHiddenMETA>(){ return XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META; }
template <> constexpr XrStructureType GetType<XrExternalCameraOCULUS>(){ return XR_TYPE_EXTERNAL_CAMERA_OCULUS; }
template <> constexpr XrStructureType GetType<XrVulkanSwapchainCreateInfoMETA>(){ return XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrPerformanceMetricsStateMETA>(){ return XR_TYPE_PERFORMANCE_METRICS_STATE_META; }
template <> constexpr XrStructureType GetType<XrPerformanceMetricsCounterMETA>(){ return XR_TYPE_PERFORMANCE_METRICS_COUNTER_META; }
template <> constexpr XrStructureType GetType<XrSpaceListSaveInfoFB>(){ return XR_TYPE_SPACE_LIST_SAVE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrEventDataSpaceListSaveCompleteFB>(){ return XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB; }
template <> constexpr XrStructureType GetType<XrSpaceUserCreateInfoFB>(){ return XR_TYPE_SPACE_USER_CREATE_INFO_FB; }
template <> constexpr XrStructureType GetType<XrSystemHeadsetIdPropertiesMETA>(){ return XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META; }
template <> constexpr XrStructureType GetType<XrRecommendedLayerResolutionMETA>(){ return XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META; }
template <> constexpr XrStructureType GetType<XrRecommendedLayerResolutionGetInfoMETA>(){ return XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META; }
template <> constexpr XrStructureType GetType<XrPassthroughColorLutCreateInfoMETA>(){ return XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrPassthroughColorLutUpdateInfoMETA>(){ return XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META; }
template <> constexpr XrStructureType GetType<XrPassthroughColorMapLutMETA>(){ return XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META; }
template <> constexpr XrStructureType GetType<XrPassthroughColorMapInterpolatedLutMETA>(){ return XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META; }
template <> constexpr XrStructureType GetType<XrSystemPassthroughColorLutPropertiesMETA>(){ return XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META; }
template <> constexpr XrStructureType GetType<XrSpaceTriangleMeshGetInfoMETA>(){ return XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META; }
template <> constexpr XrStructureType GetType<XrSpaceTriangleMeshMETA>(){ return XR_TYPE_SPACE_TRIANGLE_MESH_META; }
template <> constexpr XrStructureType GetType<XrSystemFaceTrackingProperties2FB>(){ return XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB; }
template <> constexpr XrStructureType GetType<XrFaceTrackerCreateInfo2FB>(){ return XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB; }
template <> constexpr XrStructureType GetType<XrFaceExpressionInfo2FB>(){ return XR_TYPE_FACE_EXPRESSION_INFO2_FB; }
template <> constexpr XrStructureType GetType<XrFaceExpressionWeights2FB>(){ return XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB; }
template <> constexpr XrStructureType GetType<XrPassthroughCreateInfoHTC>(){ return XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrPassthroughColorHTC>(){ return XR_TYPE_PASSTHROUGH_COLOR_HTC; }
template <> constexpr XrStructureType GetType<XrPassthroughMeshTransformInfoHTC>(){ return XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrCompositionLayerPassthroughHTC>(){ return XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC; }
template <> constexpr XrStructureType GetType<XrFoveationApplyInfoHTC>(){ return XR_TYPE_FOVEATION_APPLY_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrFoveationDynamicModeInfoHTC>(){ return XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrFoveationCustomModeInfoHTC>(){ return XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrSystemAnchorPropertiesHTC>(){ return XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC; }
template <> constexpr XrStructureType GetType<XrSpatialAnchorCreateInfoHTC>(){ return XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC; }
template <> constexpr XrStructureType GetType<XrActiveActionSetPrioritiesEXT>(){ return XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT; }
template <> constexpr XrStructureType GetType<XrSystemForceFeedbackCurlPropertiesMNDX>(){ return XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX; }
template <> constexpr XrStructureType GetType<XrForceFeedbackCurlApplyLocationsMNDX>(){ return XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX; }
template <> constexpr XrStructureType GetType<XrHandTrackingDataSourceInfoEXT>(){ return XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrHandTrackingDataSourceStateEXT>(){ return XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT; }
template <> constexpr XrStructureType GetType<XrSystemPlaneDetectionPropertiesEXT>(){ return XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorCreateInfoEXT>(){ return XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorBeginInfoEXT>(){ return XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorGetInfoEXT>(){ return XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorLocationEXT>(){ return XR_TYPE_PLANE_DETECTOR_LOCATION_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorLocationsEXT>(){ return XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT; }
template <> constexpr XrStructureType GetType<XrPlaneDetectorPolygonBufferEXT>(){ return XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT; }
template <> constexpr XrStructureType GetType<XrEventDataUserPresenceChangedEXT>(){ return XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT; }
template <> constexpr XrStructureType GetType<XrSystemUserPresencePropertiesEXT>(){ return XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT; }
template <> constexpr XrStructureType GetType<XrEventDataHeadsetFitChangedML>(){ return XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML; }
template <> constexpr XrStructureType GetType<XrEventDataEyeCalibrationChangedML>(){ return XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML; }
template <> constexpr XrStructureType GetType<XrUserCalibrationEnableEventsInfoML>(){ return XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML; }
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_TYPE_UTIL_H
