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

#ifdef ENABLE_OPENXR_SUPPORT

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

size_t DecodeNextStruct(const uint8_t* parameter_buffer, size_t buffer_size,  OpenXrNextNode** next)
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
            case XR_TYPE_SPACE_VELOCITY:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceVelocity>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrInstanceCreateInfoAndroidKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthInfoKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLWin32KHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLXlibKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLXcbKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLWaylandKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingOpenGLESAndroidKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingVulkanKHR>>();
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
            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerColorScaleBiasKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrBindingModificationsKHR>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrDebugUtilsMessengerCreateInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemEyeGazeInteractionPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrEyeGazeSampleTimeEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSessionCreateInfoOverlayEXTX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerImageLayoutFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerAlphaBlendFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationDepthRangeEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGraphicsBindingEGLMNDX>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHandTrackingPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointVelocitiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHandTrackingMeshPropertiesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandPoseTypeInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationFrameStateMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewConfigurationViewFovEPIC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHolographicWindowAttachmentMSFT>>();
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
            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrAndroidSurfaceSwapchainCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSecureContentFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemBodyTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandJointsMotionRangeInfoEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVisualMeshComputeLodInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_OBJECTS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneObjectsMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneComponentParentFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneObjectTypesFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_PLANES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrScenePlanesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrScenePlaneAlignmentFilterInfoMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MESHES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMeshesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFacialTrackingPropertiesHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemColorSpacePropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_HAND_TRACKING_SCALE_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrHandTrackingScaleFB>>();
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
            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemSpatialEntityPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainCreateInfoFoveationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationLevelProfileCreateInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemKeyboardTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughProperties2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerPassthroughFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapMonoToRgbaFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapMonoToMonoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughBrightnessContrastSaturationFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemRenderModelPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrRenderModelCapabilitiesRequestFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrViewLocateFoveatedRenderingVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveatedViewConfigurationViewVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFoveatedRenderingPropertiesVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthTestVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemMarkerTrackingPropertiesVARJO>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FRAME_END_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFrameEndInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrGlobalDimmerFrameEndInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemMarkerUnderstandingPropertiesML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorArucoInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorSizeInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorAprilTagInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrMarkerDetectorCustomProfileInfoML>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKERS_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkersMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkerTypeFilterMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSceneMarkerQRCodesMSFT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSpaceStorageLocationFilterInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSwapchainImageFoveationVulkanFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSpaceWarpInfoFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemSpaceWarpPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFoveationEyeTrackedPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFaceTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemEyeTrackingPropertiesFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerSettingsFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrCompositionLayerDepthTestFB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrLocalDimmingFrameEndInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemVirtualKeyboardPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrVulkanSwapchainCreateInfoMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemHeadsetIdPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapLutMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughColorMapInterpolatedLutMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPassthroughColorLutPropertiesMETA>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemFaceTrackingProperties2FB>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrPassthroughMeshTransformInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationDynamicModeInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrFoveationCustomModeInfoHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemAnchorPropertiesHTC>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrActiveActionSetPrioritiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemForceFeedbackCurlPropertiesMNDX>>();
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
            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemPlaneDetectionPropertiesEXT>>();
                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);
                break;
            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_XrSystemUserPresencePropertiesEXT>>();
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
