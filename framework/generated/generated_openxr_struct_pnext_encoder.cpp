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

#include "generated/generated_openxr_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"
#include "util/defines.h"

#include <openxr/openxr.h>

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const XrBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr)
    {
        base = base->pNext;
    }

    if (base != nullptr)
    {
        switch (base-type)
        {
        default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->type);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->type);
                OpenXrCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        case XR_TYPE_SPACE_VELOCITY:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceVelocity*>(base));
            break;
#ifdef XR_USE_PLATFORM_ANDROID
        case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrInstanceCreateInfoAndroidKHR*>(base));
            break;
#endif /* XR_USE_PLATFORM_ANDROID */
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base));
            break;
#ifdef XR_USE_GRAPHICS_API_OPENGL
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR*>(base));
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_OPENGL */
#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_OPENGL_ES */
#ifdef XR_USE_GRAPHICS_API_VULKAN
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_GRAPHICS_API_D3D11
        case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingD3D11KHR*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_D3D11 */
#ifdef XR_USE_GRAPHICS_API_D3D12
        case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingD3D12KHR*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_D3D12 */
        case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerColorScaleBiasKHR*>(base));
            break;
        case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const XrBindingModificationsKHR*>(base));
            break;
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemEyeGazeInteractionPropertiesEXT*>(base));
            break;
        case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrEyeGazeSampleTimeEXT*>(base));
            break;
        case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSessionCreateInfoOverlayEXTX*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerImageLayoutFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerAlphaBlendFB*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationDepthRangeEXT*>(base));
            break;
#ifdef XR_USE_PLATFORM_EGL
        case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGraphicsBindingEGLMNDX*>(base));
            break;
#endif /* XR_USE_PLATFORM_EGL */
        case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHandTrackingPropertiesEXT*>(base));
            break;
        case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointVelocitiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHandTrackingMeshPropertiesMSFT*>(base));
            break;
        case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandPoseTypeInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationFrameStateMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base));
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(base));
            break;
        case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewConfigurationViewFovEPIC*>(base));
            break;
#ifdef XR_USE_PLATFORM_WIN32
        case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHolographicWindowAttachmentMSFT*>(base));
            break;
#endif /* XR_USE_PLATFORM_WIN32 */
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerReprojectionInfoMSFT*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerReprojectionPlaneOverrideMSFT*>(base));
            break;
#ifdef XR_USE_PLATFORM_ANDROID
        case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrAndroidSurfaceSwapchainCreateInfoFB*>(base));
            break;
#endif /* XR_USE_PLATFORM_ANDROID */
        case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSecureContentFB*>(base));
            break;
        case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemBodyTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandJointsMotionRangeInfoEXT*>(base));
            break;
        case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVisualMeshComputeLodInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_OBJECTS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneObjectsMSFT*>(base));
            break;
        case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneComponentParentFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneObjectTypesFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_PLANES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrScenePlanesMSFT*>(base));
            break;
        case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrScenePlaneAlignmentFilterInfoMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MESHES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMeshesMSFT*>(base));
            break;
        case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFacialTrackingPropertiesHTC*>(base));
            break;
        case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemColorSpacePropertiesFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_SCALE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingScaleFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingAimStateFB*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingCapsulesStateFB*>(base));
            break;
        case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemSpatialEntityPropertiesFB*>(base));
            break;
        case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainCreateInfoFoveationFB*>(base));
            break;
        case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationLevelProfileCreateInfoFB*>(base));
            break;
        case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemKeyboardTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughProperties2FB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapMonoToRgbaFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapMonoToMonoFB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughBrightnessContrastSaturationFB*>(base));
            break;
        case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemRenderModelPropertiesFB*>(base));
            break;
        case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrRenderModelCapabilitiesRequestFB*>(base));
            break;
        case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrViewLocateFoveatedRenderingVARJO*>(base));
            break;
        case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveatedViewConfigurationViewVARJO*>(base));
            break;
        case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFoveatedRenderingPropertiesVARJO*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthTestVARJO*>(base));
            break;
        case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemMarkerTrackingPropertiesVARJO*>(base));
            break;
        case XR_TYPE_FRAME_END_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFrameEndInfoML*>(base));
            break;
        case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrGlobalDimmerFrameEndInfoML*>(base));
            break;
        case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemMarkerUnderstandingPropertiesML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorArucoInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorSizeInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorAprilTagInfoML*>(base));
            break;
        case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            EncodeStructPtr(encoder, reinterpret_cast<const XrMarkerDetectorCustomProfileInfoML*>(base));
            break;
        case XR_TYPE_SCENE_MARKERS_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkersMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkerTypeFilterMSFT*>(base));
            break;
        case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSceneMarkerQRCodesMSFT*>(base));
            break;
        case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSpaceStorageLocationFilterInfoFB*>(base));
            break;
#ifdef XR_USE_GRAPHICS_API_VULKAN
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_VULKAN */
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base));
            break;
        case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemSpaceWarpPropertiesFB*>(base));
            break;
        case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationEyeTrackedProfileCreateInfoMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFoveationEyeTrackedPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFaceTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemEyeTrackingPropertiesFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerSettingsFB*>(base));
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrCompositionLayerDepthTestFB*>(base));
            break;
        case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrLocalDimmingFrameEndInfoMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemVirtualKeyboardPropertiesMETA*>(base));
            break;
#ifdef XR_USE_GRAPHICS_API_VULKAN
        case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrVulkanSwapchainCreateInfoMETA*>(base));
            break;
#endif /* XR_USE_GRAPHICS_API_VULKAN */
        case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemHeadsetIdPropertiesMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPassthroughColorLutPropertiesMETA*>(base));
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemFaceTrackingProperties2FB*>(base));
            break;
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base));
            break;
        case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationDynamicModeInfoHTC*>(base));
            break;
        case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrFoveationCustomModeInfoHTC*>(base));
            break;
        case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemAnchorPropertiesHTC*>(base));
            break;
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemForceFeedbackCurlPropertiesMNDX*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingDataSourceInfoEXT*>(base));
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrHandTrackingDataSourceStateEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemPlaneDetectionPropertiesEXT*>(base));
            break;
        case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const XrSystemUserPresencePropertiesEXT*>(base));
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
