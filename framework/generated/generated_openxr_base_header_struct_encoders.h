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

#ifndef  GFXRECON_GENERATED_OPENXR_BASE_HEADER_STRUCT_ENCODERS_H
#define  GFXRECON_GENERATED_OPENXR_BASE_HEADER_STRUCT_ENCODERS_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
void EncodeBaseHeaderStructArray(ParameterEncoder* encoder, const T* value, size_t len, bool omit_data = false, bool omit_addr = false)
{
    if (value == nullptr)
    {
        return EncodeStructArray(encoder, value, len, omit_data, omit_addr);
    }
    switch (value->type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeBaseHeaderStructArray: unrecognized Base Header child structure type %d", value->type);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
        {
            const XrCompositionLayerProjection* child_value = reinterpret_cast<const XrCompositionLayerProjection*>(value);
            EncodeStructArray<XrCompositionLayerProjection>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
        {
            const XrCompositionLayerQuad* child_value = reinterpret_cast<const XrCompositionLayerQuad*>(value);
            EncodeStructArray<XrCompositionLayerQuad>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
        {
            const XrCompositionLayerCubeKHR* child_value = reinterpret_cast<const XrCompositionLayerCubeKHR*>(value);
            EncodeStructArray<XrCompositionLayerCubeKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
        {
            const XrCompositionLayerCylinderKHR* child_value = reinterpret_cast<const XrCompositionLayerCylinderKHR*>(value);
            EncodeStructArray<XrCompositionLayerCylinderKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
        {
            const XrCompositionLayerEquirectKHR* child_value = reinterpret_cast<const XrCompositionLayerEquirectKHR*>(value);
            EncodeStructArray<XrCompositionLayerEquirectKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
        {
            const XrCompositionLayerEquirect2KHR* child_value = reinterpret_cast<const XrCompositionLayerEquirect2KHR*>(value);
            EncodeStructArray<XrCompositionLayerEquirect2KHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
        {
            const XrCompositionLayerPassthroughHTC* child_value = reinterpret_cast<const XrCompositionLayerPassthroughHTC*>(value);
            EncodeStructArray<XrCompositionLayerPassthroughHTC>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
        {
            const XrEventDataEventsLost* child_value = reinterpret_cast<const XrEventDataEventsLost*>(value);
            EncodeStructArray<XrEventDataEventsLost>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
        {
            const XrEventDataInstanceLossPending* child_value = reinterpret_cast<const XrEventDataInstanceLossPending*>(value);
            EncodeStructArray<XrEventDataInstanceLossPending>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
        {
            const XrEventDataSessionStateChanged* child_value = reinterpret_cast<const XrEventDataSessionStateChanged*>(value);
            EncodeStructArray<XrEventDataSessionStateChanged>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
        {
            const XrEventDataReferenceSpaceChangePending* child_value = reinterpret_cast<const XrEventDataReferenceSpaceChangePending*>(value);
            EncodeStructArray<XrEventDataReferenceSpaceChangePending>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
        {
            const XrEventDataInteractionProfileChanged* child_value = reinterpret_cast<const XrEventDataInteractionProfileChanged*>(value);
            EncodeStructArray<XrEventDataInteractionProfileChanged>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
        {
            const XrEventDataVisibilityMaskChangedKHR* child_value = reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR*>(value);
            EncodeStructArray<XrEventDataVisibilityMaskChangedKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
        {
            const XrEventDataPerfSettingsEXT* child_value = reinterpret_cast<const XrEventDataPerfSettingsEXT*>(value);
            EncodeStructArray<XrEventDataPerfSettingsEXT>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
        {
            const XrEventDataMainSessionVisibilityChangedEXTX* child_value = reinterpret_cast<const XrEventDataMainSessionVisibilityChangedEXTX*>(value);
            EncodeStructArray<XrEventDataMainSessionVisibilityChangedEXTX>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
        {
            const XrEventDataDisplayRefreshRateChangedFB* child_value = reinterpret_cast<const XrEventDataDisplayRefreshRateChangedFB*>(value);
            EncodeStructArray<XrEventDataDisplayRefreshRateChangedFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
        {
            const XrEventDataViveTrackerConnectedHTCX* child_value = reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX*>(value);
            EncodeStructArray<XrEventDataViveTrackerConnectedHTCX>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
        {
            const XrEventDataSpatialAnchorCreateCompleteFB* child_value = reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpatialAnchorCreateCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
        {
            const XrEventDataSpaceSetStatusCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceSetStatusCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
        {
            const XrEventDataMarkerTrackingUpdateVARJO* child_value = reinterpret_cast<const XrEventDataMarkerTrackingUpdateVARJO*>(value);
            EncodeStructArray<XrEventDataMarkerTrackingUpdateVARJO>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
        {
            const XrEventDataLocalizationChangedML* child_value = reinterpret_cast<const XrEventDataLocalizationChangedML*>(value);
            EncodeStructArray<XrEventDataLocalizationChangedML>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
        {
            const XrEventDataSpaceQueryResultsAvailableFB* child_value = reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB*>(value);
            EncodeStructArray<XrEventDataSpaceQueryResultsAvailableFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
        {
            const XrEventDataSpaceQueryCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceQueryCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceQueryCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
        {
            const XrEventDataSpaceSaveCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceSaveCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceSaveCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
        {
            const XrEventDataSpaceEraseCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceEraseCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceEraseCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
        {
            const XrEventDataSpaceShareCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceShareCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceShareCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
        {
            const XrEventDataSpaceListSaveCompleteFB* child_value = reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB*>(value);
            EncodeStructArray<XrEventDataSpaceListSaveCompleteFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
        {
            const XrEventDataHeadsetFitChangedML* child_value = reinterpret_cast<const XrEventDataHeadsetFitChangedML*>(value);
            EncodeStructArray<XrEventDataHeadsetFitChangedML>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
        {
            const XrEventDataEyeCalibrationChangedML* child_value = reinterpret_cast<const XrEventDataEyeCalibrationChangedML*>(value);
            EncodeStructArray<XrEventDataEyeCalibrationChangedML>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_HAPTIC_VIBRATION:
        {
            const XrHapticVibration* child_value = reinterpret_cast<const XrHapticVibration*>(value);
            EncodeStructArray<XrHapticVibration>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
        {
            const XrHapticAmplitudeEnvelopeVibrationFB* child_value = reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(value);
            EncodeStructArray<XrHapticAmplitudeEnvelopeVibrationFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
        {
            const XrHapticPcmVibrationFB* child_value = reinterpret_cast<const XrHapticPcmVibrationFB*>(value);
            EncodeStructArray<XrHapticPcmVibrationFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
        {
            const XrSwapchainImageOpenGLKHR* child_value = reinterpret_cast<const XrSwapchainImageOpenGLKHR*>(value);
            EncodeStructArray<XrSwapchainImageOpenGLKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
        {
            const XrSwapchainImageOpenGLESKHR* child_value = reinterpret_cast<const XrSwapchainImageOpenGLESKHR*>(value);
            EncodeStructArray<XrSwapchainImageOpenGLESKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
        {
            const XrSwapchainImageVulkanKHR* child_value = reinterpret_cast<const XrSwapchainImageVulkanKHR*>(value);
            EncodeStructArray<XrSwapchainImageVulkanKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
        {
            const XrSwapchainImageD3D11KHR* child_value = reinterpret_cast<const XrSwapchainImageD3D11KHR*>(value);
            EncodeStructArray<XrSwapchainImageD3D11KHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
        {
            const XrSwapchainImageD3D12KHR* child_value = reinterpret_cast<const XrSwapchainImageD3D12KHR*>(value);
            EncodeStructArray<XrSwapchainImageD3D12KHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
        {
            const XrLoaderInitInfoAndroidKHR* child_value = reinterpret_cast<const XrLoaderInitInfoAndroidKHR*>(value);
            EncodeStructArray<XrLoaderInitInfoAndroidKHR>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
        {
            const XrInteractionProfileDpadBindingEXT* child_value = reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(value);
            EncodeStructArray<XrInteractionProfileDpadBindingEXT>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
        {
            const XrInteractionProfileAnalogThresholdVALVE* child_value = reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(value);
            EncodeStructArray<XrInteractionProfileAnalogThresholdVALVE>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
        {
            const XrSwapchainStateFoveationFB* child_value = reinterpret_cast<const XrSwapchainStateFoveationFB*>(value);
            EncodeStructArray<XrSwapchainStateFoveationFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
        {
            const XrSwapchainStateAndroidSurfaceDimensionsFB* child_value = reinterpret_cast<const XrSwapchainStateAndroidSurfaceDimensionsFB*>(value);
            EncodeStructArray<XrSwapchainStateAndroidSurfaceDimensionsFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
        {
            const XrSwapchainStateSamplerOpenGLESFB* child_value = reinterpret_cast<const XrSwapchainStateSamplerOpenGLESFB*>(value);
            EncodeStructArray<XrSwapchainStateSamplerOpenGLESFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
        {
            const XrSwapchainStateSamplerVulkanFB* child_value = reinterpret_cast<const XrSwapchainStateSamplerVulkanFB*>(value);
            EncodeStructArray<XrSwapchainStateSamplerVulkanFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SPACE_QUERY_INFO_FB:
        {
            const XrSpaceQueryInfoFB* child_value = reinterpret_cast<const XrSpaceQueryInfoFB*>(value);
            EncodeStructArray<XrSpaceQueryInfoFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
        {
            const XrSpaceUuidFilterInfoFB* child_value = reinterpret_cast<const XrSpaceUuidFilterInfoFB*>(value);
            EncodeStructArray<XrSpaceUuidFilterInfoFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
        {
            const XrSpaceComponentFilterInfoFB* child_value = reinterpret_cast<const XrSpaceComponentFilterInfoFB*>(value);
            EncodeStructArray<XrSpaceComponentFilterInfoFB>(
                encoder,
                child_value,
                len,
                omit_data,
                omit_addr);
            break;
        }
    }
}


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_BASE_HEADER_STRUCT_ENCODERS_H
