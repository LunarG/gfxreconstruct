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

#include "generated/generated_openxr_struct_encoders.h"
#include "generated/generated_vulkan_api_call_encoders.h"

#include "encode/custom_dx12_struct_encoders.h"
#include "encode/custom_openxr_struct_encoders.h"
#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "encode/openxr_handle_wrappers.h"
#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#ifndef D3D12_SUPPORT
void EncodeStruct(ParameterEncoder* encoder, const LUID& value)
{
    encoder->EncodeUInt32Value(value.LowPart);
    encoder->EncodeInt32Value(value.HighPart);
}
#endif /* D3D12_SUPPORT */

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.layerName);
    encoder->EncodeUInt64Value(value.specVersion);
    encoder->EncodeUInt32Value(value.layerVersion);
    encoder->EncodeString(value.description);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtensionProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.extensionName);
    encoder->EncodeUInt32Value(value.extensionVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApplicationInfo& value)
{
    encoder->EncodeString(value.applicationName);
    encoder->EncodeUInt32Value(value.applicationVersion);
    encoder->EncodeString(value.engineName);
    encoder->EncodeUInt32Value(value.engineVersion);
    encoder->EncodeUInt64Value(value.apiVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    EncodeStruct(encoder, value.applicationInfo);
    encoder->EncodeUInt32Value(value.enabledApiLayerCount);
    encoder->EncodeStringArray(value.enabledApiLayerNames, value.enabledApiLayerCount);
    encoder->EncodeUInt32Value(value.enabledExtensionCount);
    encoder->EncodeStringArray(value.enabledExtensionNames, value.enabledExtensionCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.runtimeVersion);
    encoder->EncodeString(value.runtimeName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBuffer& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt8Array(value.varying, 4000);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.formFactor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemGraphicsProperties& value)
{
    encoder->EncodeUInt32Value(value.maxSwapchainImageHeight);
    encoder->EncodeUInt32Value(value.maxSwapchainImageWidth);
    encoder->EncodeUInt32Value(value.maxLayerCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemTrackingProperties& value)
{
    encoder->EncodeUInt32Value(value.orientationTracking);
    encoder->EncodeUInt32Value(value.positionTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(value.systemId);
    encoder->EncodeUInt32Value(value.vendorId);
    encoder->EncodeString(value.systemName);
    EncodeStruct(encoder, value.graphicsProperties);
    EncodeStruct(encoder, value.trackingProperties);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(value.systemId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector3f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceVelocity& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.velocityFlags);
    EncodeStruct(encoder, value.linearVelocity);
    EncodeStruct(encoder, value.angularVelocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrQuaternionf& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
    encoder->EncodeFloatValue(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPosef& value)
{
    EncodeStruct(encoder, value.orientation);
    EncodeStruct(encoder, value.position);
}

void EncodeStruct(ParameterEncoder* encoder, const XrReferenceSpaceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.referenceSpaceType);
    EncodeStruct(encoder, value.poseInReferenceSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Df& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSpaceCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.subactionPath);
    EncodeStruct(encoder, value.poseInActionSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceLocation& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationProperties& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeUInt32Value(value.fovMutable);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationView& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.recommendedImageRectWidth);
    encoder->EncodeUInt32Value(value.maxImageRectWidth);
    encoder->EncodeUInt32Value(value.recommendedImageRectHeight);
    encoder->EncodeUInt32Value(value.maxImageRectHeight);
    encoder->EncodeUInt32Value(value.recommendedSwapchainSampleCount);
    encoder->EncodeUInt32Value(value.maxSwapchainSampleCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFlags64Value(value.usageFlags);
    encoder->EncodeInt64Value(value.format);
    encoder->EncodeUInt32Value(value.sampleCount);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
    encoder->EncodeUInt32Value(value.faceCount);
    encoder->EncodeUInt32Value(value.arraySize);
    encoder->EncodeUInt32Value(value.mipCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageBaseHeader& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
        {
            const XrSwapchainImageOpenGLKHR& child_value = reinterpret_cast<const XrSwapchainImageOpenGLKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
        {
            const XrSwapchainImageOpenGLESKHR& child_value = reinterpret_cast<const XrSwapchainImageOpenGLESKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
        {
            const XrSwapchainImageVulkanKHR& child_value = reinterpret_cast<const XrSwapchainImageVulkanKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
        {
            const XrSwapchainImageD3D11KHR& child_value = reinterpret_cast<const XrSwapchainImageD3D11KHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
        {
            const XrSwapchainImageD3D12KHR& child_value = reinterpret_cast<const XrSwapchainImageD3D12KHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageAcquireInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageWaitInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.timeout);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageReleaseInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionBeginInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.primaryViewConfigurationType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameWaitInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameState& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.predictedDisplayTime);
    encoder->EncodeInt64Value(value.predictedDisplayPeriod);
    encoder->EncodeUInt32Value(value.shouldRender);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameBeginInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerBaseHeader& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
        {
            const XrCompositionLayerProjection& child_value = reinterpret_cast<const XrCompositionLayerProjection&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
        {
            const XrCompositionLayerQuad& child_value = reinterpret_cast<const XrCompositionLayerQuad&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
        {
            const XrCompositionLayerCubeKHR& child_value = reinterpret_cast<const XrCompositionLayerCubeKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
        {
            const XrCompositionLayerCylinderKHR& child_value = reinterpret_cast<const XrCompositionLayerCylinderKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
        {
            const XrCompositionLayerEquirectKHR& child_value = reinterpret_cast<const XrCompositionLayerEquirectKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
        {
            const XrCompositionLayerEquirect2KHR& child_value = reinterpret_cast<const XrCompositionLayerEquirect2KHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
        {
            const XrCompositionLayerPassthroughHTC& child_value = reinterpret_cast<const XrCompositionLayerPassthroughHTC&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeInt64Value(value.displayTime);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewState& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.viewStateFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFovf& value)
{
    encoder->EncodeFloatValue(value.angleLeft);
    encoder->EncodeFloatValue(value.angleRight);
    encoder->EncodeFloatValue(value.angleUp);
    encoder->EncodeFloatValue(value.angleDown);
}

void EncodeStruct(ParameterEncoder* encoder, const XrView& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSetCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.actionSetName);
    encoder->EncodeString(value.localizedActionSetName);
    encoder->EncodeUInt32Value(value.priority);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionCreateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.actionName);
    encoder->EncodeEnumValue(value.actionType);
    encoder->EncodeUInt32Value(value.countSubactionPaths);
    encoder->EncodeOpenXrAtomArray<openxr_wrappers::PathWrapper>(value.subactionPaths, value.countSubactionPaths);
    encoder->EncodeString(value.localizedActionName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionSuggestedBinding& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.binding);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileSuggestedBinding& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.interactionProfile);
    encoder->EncodeUInt32Value(value.countSuggestedBindings);
    EncodeStructArray(encoder, value.suggestedBindings, value.countSuggestedBindings);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionActionSetsAttachInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.countActionSets);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::ActionSetWrapper>(value.actionSets, value.countActionSets);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileState& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.interactionProfile);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateBoolean& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.currentState);
    encoder->EncodeUInt32Value(value.changedSinceLastSync);
    encoder->EncodeInt64Value(value.lastChangeTime);
    encoder->EncodeUInt32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateFloat& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.currentState);
    encoder->EncodeUInt32Value(value.changedSinceLastSync);
    encoder->EncodeInt64Value(value.lastChangeTime);
    encoder->EncodeUInt32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector2f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStateVector2f& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.currentState);
    encoder->EncodeUInt32Value(value.changedSinceLastSync);
    encoder->EncodeInt64Value(value.lastChangeTime);
    encoder->EncodeUInt32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionStatePose& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSet& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActionsSyncInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.countActiveActionSets);
    EncodeStructArray(encoder, value.activeActionSets, value.countActiveActionSets);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBoundSourcesForActionEnumerateInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInputSourceLocalizedNameGetInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.sourcePath);
    encoder->EncodeFlags64Value(value.whichComponents);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticActionInfo& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.subactionPath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticBaseHeader& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_HAPTIC_VIBRATION:
        {
            const XrHapticVibration& child_value = reinterpret_cast<const XrHapticVibration&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
        {
            const XrHapticAmplitudeEnvelopeVibrationFB& child_value = reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
        {
            const XrHapticPcmVibrationFB& child_value = reinterpret_cast<const XrHapticPcmVibrationFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Di& value)
{
    encoder->EncodeInt32Value(value.x);
    encoder->EncodeInt32Value(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Di& value)
{
    encoder->EncodeInt32Value(value.width);
    encoder->EncodeInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect2Di& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainSubImage& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(value.swapchain);
    EncodeStruct(encoder, value.imageRect);
    encoder->EncodeUInt32Value(value.imageArrayIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjectionView& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
    EncodeStruct(encoder, value.subImage);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjection& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeUInt32Value(value.viewCount);
    EncodeStructArray(encoder, value.views, value.viewCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerQuad& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.size);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBaseHeader& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
        {
            const XrEventDataEventsLost& child_value = reinterpret_cast<const XrEventDataEventsLost&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
        {
            const XrEventDataInstanceLossPending& child_value = reinterpret_cast<const XrEventDataInstanceLossPending&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
        {
            const XrEventDataSessionStateChanged& child_value = reinterpret_cast<const XrEventDataSessionStateChanged&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
        {
            const XrEventDataReferenceSpaceChangePending& child_value = reinterpret_cast<const XrEventDataReferenceSpaceChangePending&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
        {
            const XrEventDataInteractionProfileChanged& child_value = reinterpret_cast<const XrEventDataInteractionProfileChanged&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
        {
            const XrEventDataVisibilityMaskChangedKHR& child_value = reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
        {
            const XrEventDataPerfSettingsEXT& child_value = reinterpret_cast<const XrEventDataPerfSettingsEXT&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
        {
            const XrEventDataMainSessionVisibilityChangedEXTX& child_value = reinterpret_cast<const XrEventDataMainSessionVisibilityChangedEXTX&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
        {
            const XrEventDataDisplayRefreshRateChangedFB& child_value = reinterpret_cast<const XrEventDataDisplayRefreshRateChangedFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
        {
            const XrEventDataViveTrackerConnectedHTCX& child_value = reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
        {
            const XrEventDataSpatialAnchorCreateCompleteFB& child_value = reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
        {
            const XrEventDataSpaceSetStatusCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
        {
            const XrEventDataMarkerTrackingUpdateVARJO& child_value = reinterpret_cast<const XrEventDataMarkerTrackingUpdateVARJO&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
        {
            const XrEventDataLocalizationChangedML& child_value = reinterpret_cast<const XrEventDataLocalizationChangedML&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
        {
            const XrEventDataSpaceQueryResultsAvailableFB& child_value = reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
        {
            const XrEventDataSpaceQueryCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceQueryCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
        {
            const XrEventDataSpaceSaveCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceSaveCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
        {
            const XrEventDataSpaceEraseCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceEraseCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
        {
            const XrEventDataSpaceShareCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceShareCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
        {
            const XrEventDataSpaceListSaveCompleteFB& child_value = reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
        {
            const XrEventDataHeadsetFitChangedML& child_value = reinterpret_cast<const XrEventDataHeadsetFitChangedML&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
        {
            const XrEventDataEyeCalibrationChangedML& child_value = reinterpret_cast<const XrEventDataEyeCalibrationChangedML&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEventsLost& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.lostEventCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInstanceLossPending& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.lossTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSessionStateChanged& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.state);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataReferenceSpaceChangePending& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.referenceSpaceType);
    encoder->EncodeInt64Value(value.changeTime);
    encoder->EncodeUInt32Value(value.poseValid);
    EncodeStruct(encoder, value.poseInPreviousSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInteractionProfileChanged& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticVibration& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.duration);
    encoder->EncodeFloatValue(value.frequency);
    encoder->EncodeFloatValue(value.amplitude);
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Df& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect2Df& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector4f& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
    encoder->EncodeFloatValue(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrColor4f& value)
{
    encoder->EncodeFloatValue(value.r);
    encoder->EncodeFloatValue(value.g);
    encoder->EncodeFloatValue(value.b);
    encoder->EncodeFloatValue(value.a);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerNextInfo& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeString(value.layerName);
    encoder->EncodeFunctionPtr(value.nextGetInstanceProcAddr);
    encoder->EncodeFunctionPtr(value.nextCreateApiLayerInstance);
    EncodeStructPtr(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerCreateInfo& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeVoidPtr(value.loaderInstance);
    encoder->EncodeString(value.settings_file_location);
    EncodeStructPtr(encoder, value.nextInfo);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNegotiateApiLayerRequest& value)
{
    encoder->EncodeEnumValue(value.structType);
    encoder->EncodeUInt32Value(value.structVersion);
    encoder->EncodeSizeTValue(value.structSize);
    encoder->EncodeUInt32Value(value.layerInterfaceVersion);
    encoder->EncodeUInt64Value(value.layerApiVersion);
    encoder->EncodeFunctionPtr(value.getInstanceProcAddr);
    encoder->EncodeFunctionPtr(value.createApiLayerInstance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCubeKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(value.swapchain);
    encoder->EncodeUInt32Value(value.imageArrayIndex);
    EncodeStruct(encoder, value.orientation);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfoAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.applicationVM);
    encoder->EncodeVoidPtr(value.applicationActivity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.subImage);
    encoder->EncodeFloatValue(value.minDepth);
    encoder->EncodeFloatValue(value.maxDepth);
    encoder->EncodeFloatValue(value.nearZ);
    encoder->EncodeFloatValue(value.farZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainFormatListCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.viewFormatCount);
    encoder->EncodeEnumArray(value.viewFormats, value.viewFormatCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCylinderKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeFloatValue(value.centralAngle);
    encoder->EncodeFloatValue(value.aspectRatio);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirectKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    EncodeStruct(encoder, value.scale);
    EncodeStruct(encoder, value.bias);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWin32KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.hDC);
    encoder->EncodeVoidPtr(value.hGLRC);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXlibKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.xDisplay);
    encoder->EncodeUInt32Value(value.visualid);
    encoder->EncodeVoidPtr(value.glxFBConfig);
    encoder->EncodeSizeTValue(value.glxDrawable);
    encoder->EncodeVoidPtr(value.glxContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXcbKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.connection);
    encoder->EncodeUInt32Value(value.screenNumber);
    encoder->EncodeUInt32Value(value.fbconfigid);
    encoder->EncodeUInt32Value(value.visualid);
    encoder->EncodeUInt32Value(value.glxDrawable);
    encoder->EncodeUInt32Value(value.glxContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWaylandKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.display);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.minApiVersionSupported);
    encoder->EncodeUInt64Value(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLESAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.display);
    encoder->EncodeVoidPtr(value.config);
    encoder->EncodeVoidPtr(value.context);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLESKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLESKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.minApiVersionSupported);
    encoder->EncodeUInt64Value(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::InstanceWrapper>(value.instance);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::PhysicalDeviceWrapper>(value.physicalDevice);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(value.device);
    encoder->EncodeUInt32Value(value.queueFamilyIndex);
    encoder->EncodeUInt32Value(value.queueIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::ImageWrapper>(value.image);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsVulkanKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.minApiVersionSupported);
    encoder->EncodeUInt64Value(value.maxApiVersionSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.device);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.texture);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D11KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeLUIDValue(value.adapterLuid);
    encoder->EncodeD3D_FEATURE_LEVELValue(value.minFeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.device);
    encoder->EncodeVoidPtr(value.queue);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.texture);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D12KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeLUIDValue(value.adapterLuid);
    encoder->EncodeD3D_FEATURE_LEVELValue(value.minFeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVisibilityMaskKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVisibilityMaskChangedKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeUInt32Value(value.viewIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerColorScaleBiasKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.colorScale);
    EncodeStruct(encoder, value.colorBias);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoBaseHeaderKHR& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
        {
            const XrLoaderInitInfoAndroidKHR& child_value = reinterpret_cast<const XrLoaderInitInfoAndroidKHR&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoAndroidKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.applicationVM);
    encoder->EncodeVoidPtr(value.applicationContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanGraphicsDeviceGetInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(value.systemId);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::InstanceWrapper>(value.vulkanInstance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirect2KHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.eyeVisibility);
    EncodeStruct(encoder, value.subImage);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeFloatValue(value.centralHorizontalAngle);
    encoder->EncodeFloatValue(value.upperVerticalAngle);
    encoder->EncodeFloatValue(value.lowerVerticalAngle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBindingModificationBaseHeaderKHR& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
        {
            const XrInteractionProfileDpadBindingEXT& child_value = reinterpret_cast<const XrInteractionProfileDpadBindingEXT&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
        {
            const XrInteractionProfileAnalogThresholdVALVE& child_value = reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPerfSettingsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.domain);
    encoder->EncodeEnumValue(value.subDomain);
    encoder->EncodeEnumValue(value.fromLevel);
    encoder->EncodeEnumValue(value.toLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsObjectNameInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.objectType);
    encoder->EncodeUInt64Value(value.objectHandle);
    encoder->EncodeString(value.objectName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsLabelEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.labelName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCallbackDataEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.messageId);
    encoder->EncodeString(value.functionName);
    encoder->EncodeString(value.message);
    encoder->EncodeUInt32Value(value.objectCount);
    EncodeStructArray(encoder, value.objects, value.objectCount);
    encoder->EncodeUInt32Value(value.sessionLabelCount);
    EncodeStructArray(encoder, value.sessionLabels, value.sessionLabelCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.messageSeverities);
    encoder->EncodeFlags64Value(value.messageTypes);
    encoder->EncodeFunctionPtr(value.userCallback);
    encoder->EncodeVoidPtr(value.userData);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeGazeInteractionPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsEyeGazeInteraction);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeSampleTimeEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfoOverlayEXTX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeUInt32Value(value.sessionLayersPlacement);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMainSessionVisibilityChangedEXTX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.visible);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(value.anchor);
    EncodeStruct(encoder, value.poseInAnchorSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerImageLayoutFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerAlphaBlendFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.srcFactorColor);
    encoder->EncodeEnumValue(value.dstFactorColor);
    encoder->EncodeEnumValue(value.srcFactorAlpha);
    encoder->EncodeEnumValue(value.dstFactorAlpha);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationDepthRangeEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.recommendedNearZ);
    encoder->EncodeFloatValue(value.minNearZ);
    encoder->EncodeFloatValue(value.recommendedFarZ);
    encoder->EncodeFloatValue(value.maxFarZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingEGLMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFunctionPtr(value.getProcAddress);
    encoder->EncodeVoidPtr(value.display);
    encoder->EncodeVoidPtr(value.config);
    encoder->EncodeVoidPtr(value.context);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.nodeType);
    encoder->EncodeUInt8Array(value.nodeId, XR_GUID_SIZE_MSFT);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt8Array(value.nodeId, XR_GUID_SIZE_MSFT);
    EncodeStruct(encoder, value.poseInNodeSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsHandTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackerCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.hand);
    encoder->EncodeEnumValue(value.handJointSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsLocateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationEXT& value)
{
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
    encoder->EncodeFloatValue(value.radius);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocityEXT& value)
{
    encoder->EncodeFlags64Value(value.velocityFlags);
    EncodeStruct(encoder, value.linearVelocity);
    EncodeStruct(encoder, value.angularVelocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointLocations, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocitiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointVelocities, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingMeshPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsHandTrackingMesh);
    encoder->EncodeUInt32Value(value.maxHandMeshIndexCount);
    encoder->EncodeUInt32Value(value.maxHandMeshVertexCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshSpaceCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.handPoseType);
    EncodeStruct(encoder, value.poseInHandMeshSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshUpdateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.time);
    encoder->EncodeEnumValue(value.handPoseType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshIndexBufferMSFT& value)
{
    encoder->EncodeUInt32Value(value.indexBufferKey);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexMSFT& value)
{
    EncodeStruct(encoder, value.position);
    EncodeStruct(encoder, value.normal);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexBufferMSFT& value)
{
    encoder->EncodeInt64Value(value.vertexUpdateTime);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeUInt32Value(value.indexBufferChanged);
    encoder->EncodeUInt32Value(value.vertexBufferChanged);
    EncodeStruct(encoder, value.indexBuffer);
    EncodeStruct(encoder, value.vertexBuffer);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandPoseTypeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.handPoseType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSessionBeginInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    encoder->EncodeEnumArray(value.enabledViewConfigurationTypes, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
    encoder->EncodeUInt32Value(value.active);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    EncodeStructArray(encoder, value.viewConfigurationStates, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameEndInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.viewConfigurationCount);
    EncodeStructArray(encoder, value.viewConfigurationLayersInfo, value.viewConfigurationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.viewConfigurationType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelKeyStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::ControllerModelKeyMSFTWrapper>(value.modelKey);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodePropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.parentNodeName);
    encoder->EncodeString(value.nodeName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelPropertiesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.nodeCapacityInput);
    encoder->EncodeUInt32Value(value.nodeCountOutput);
    EncodeStructArray(encoder, value.nodeProperties, value.nodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodeStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.nodePose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelStateMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.nodeCapacityInput);
    encoder->EncodeUInt32Value(value.nodeCountOutput);
    EncodeStructArray(encoder, value.nodeStates, value.nodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationViewFovEPIC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.recommendedFov);
    EncodeStruct(encoder, value.maxMutableFov);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHolographicWindowAttachmentMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVoidPtr(value.holographicSpace);
    encoder->EncodeVoidPtr(value.coreWindow);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.reprojectionMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionPlaneOverrideMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.position);
    EncodeStruct(encoder, value.normal);
    EncodeStruct(encoder, value.velocity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrAndroidSurfaceSwapchainCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.createFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateBaseHeaderFB& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
        {
            const XrSwapchainStateFoveationFB& child_value = reinterpret_cast<const XrSwapchainStateFoveationFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
        {
            const XrSwapchainStateAndroidSurfaceDimensionsFB& child_value = reinterpret_cast<const XrSwapchainStateAndroidSurfaceDimensionsFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
        {
            const XrSwapchainStateSamplerOpenGLESFB& child_value = reinterpret_cast<const XrSwapchainStateSamplerOpenGLESFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
        {
            const XrSwapchainStateSamplerVulkanFB& child_value = reinterpret_cast<const XrSwapchainStateSamplerVulkanFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSecureContentFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationFB& value)
{
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemBodyTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsBodyTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.bodyJointSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonJointFB& value)
{
    encoder->EncodeInt32Value(value.joint);
    encoder->EncodeInt32Value(value.parentJoint);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.joints, value.jointCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointsLocateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeFloatValue(value.confidence);
    encoder->EncodeUInt32Value(value.jointCount);
    EncodeStructArray(encoder, value.jointLocations, value.jointCount);
    encoder->EncodeUInt32Value(value.skeletonChangedCount);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileDpadBindingEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.binding);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeFloatValue(value.forceThreshold);
    encoder->EncodeFloatValue(value.forceThresholdReleased);
    encoder->EncodeFloatValue(value.centerRegion);
    encoder->EncodeFloatValue(value.wedgeAngle);
    encoder->EncodeUInt32Value(value.isSticky);
    EncodeStructPtr(encoder, value.onHaptic);
    EncodeStructPtr(encoder, value.offHaptic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileAnalogThresholdVALVE& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(value.action);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.binding);
    encoder->EncodeFloatValue(value.onThreshold);
    encoder->EncodeFloatValue(value.offThreshold);
    EncodeStructPtr(encoder, value.onHaptic);
    EncodeStructPtr(encoder, value.offHaptic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsMotionRangeInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.handJointsMotionRange);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUuidMSFT& value)
{
    encoder->EncodeUInt8Array(value.bytes, 16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObserverCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneSphereBoundMSFT& value)
{
    EncodeStruct(encoder, value.center);
    encoder->EncodeFloatValue(value.radius);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneOrientedBoxBoundMSFT& value)
{
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.extents);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneFrustumBoundMSFT& value)
{
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.fov);
    encoder->EncodeFloatValue(value.farDistance);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneBoundsMSFT& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeInt64Value(value.time);
    encoder->EncodeUInt32Value(value.sphereCount);
    EncodeStructArray(encoder, value.spheres, value.sphereCount);
    encoder->EncodeUInt32Value(value.boxCount);
    EncodeStructArray(encoder, value.boxes, value.boxCount);
    encoder->EncodeUInt32Value(value.frustumCount);
    EncodeStructArray(encoder, value.frustums, value.frustumCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrNewSceneComputeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.requestedFeatureCount);
    encoder->EncodeEnumArray(value.requestedFeatures, value.requestedFeatureCount);
    encoder->EncodeEnumValue(value.consistency);
    EncodeStruct(encoder, value.bounds);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVisualMeshComputeLodInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.lod);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentMSFT& value)
{
    encoder->EncodeEnumValue(value.componentType);
    EncodeStruct(encoder, value.id);
    EncodeStruct(encoder, value.parentId);
    encoder->EncodeInt64Value(value.updateTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.componentCapacityInput);
    encoder->EncodeUInt32Value(value.componentCountOutput);
    EncodeStructArray(encoder, value.components, value.componentCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.componentType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationMSFT& value)
{
    encoder->EncodeFlags64Value(value.flags);
    EncodeStruct(encoder, value.pose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.locationCount);
    EncodeStructArray(encoder, value.locations, value.locationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsLocateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
    encoder->EncodeUInt32Value(value.componentIdCount);
    EncodeStructArray(encoder, value.componentIds, value.componentIdCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectMSFT& value)
{
    encoder->EncodeEnumValue(value.objectType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectsMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.sceneObjectCount);
    EncodeStructArray(encoder, value.sceneObjects, value.sceneObjectCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentParentFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.parentId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectTypesFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.objectTypeCount);
    encoder->EncodeEnumArray(value.objectTypes, value.objectTypeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneMSFT& value)
{
    encoder->EncodeEnumValue(value.alignment);
    EncodeStruct(encoder, value.size);
    encoder->EncodeUInt64Value(value.meshBufferId);
    encoder->EncodeUInt32Value(value.supportsIndicesUint16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlanesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.scenePlaneCount);
    EncodeStructArray(encoder, value.scenePlanes, value.scenePlaneCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneAlignmentFilterInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.alignmentCount);
    encoder->EncodeEnumArray(value.alignments, value.alignmentCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshMSFT& value)
{
    encoder->EncodeUInt64Value(value.meshBufferId);
    encoder->EncodeUInt32Value(value.supportsIndicesUint16);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.sceneMeshCount);
    EncodeStructArray(encoder, value.sceneMeshes, value.sceneMeshCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.meshBufferId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshVertexBufferMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint32MSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint16MSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt16Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSerializedSceneFragmentDataGetInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.sceneFragmentId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDeserializeSceneFragmentMSFT& value)
{
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeUInt8Array(value.buffer, value.bufferSize);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneDeserializeInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.fragmentCount);
    EncodeStructArray(encoder, value.fragments, value.fragmentCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataDisplayRefreshRateChangedFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.fromDisplayRefreshRate);
    encoder->EncodeFloatValue(value.toDisplayRefreshRate);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViveTrackerPathsHTCX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.persistentPath);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.rolePath);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataViveTrackerConnectedHTCX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructPtr(encoder, value.paths);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFacialTrackingPropertiesHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportEyeFacialTracking);
    encoder->EncodeUInt32Value(value.supportLipFacialTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFacialExpressionsHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeInt64Value(value.sampleTime);
    encoder->EncodeUInt32Value(value.expressionCount);
    encoder->EncodeFloatPtr(value.expressionWeightings);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFacialTrackerCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.facialTrackingType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemColorSpacePropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.colorSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVector4sFB& value)
{
    encoder->EncodeInt16Value(value.x);
    encoder->EncodeInt16Value(value.y);
    encoder->EncodeInt16Value(value.z);
    encoder->EncodeInt16Value(value.w);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingMeshFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.jointCapacityInput);
    encoder->EncodeUInt32Value(value.jointCountOutput);
    EncodeStructArray(encoder, value.jointBindPoses, value.jointCapacityInput);
    encoder->EncodeFloatArray(value.jointRadii, value.jointCapacityInput);
    encoder->EncodeEnumArray(value.jointParents, value.jointCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertexPositions, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexNormals, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexUVs, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexBlendIndices, value.vertexCapacityInput);
    EncodeStructArray(encoder, value.vertexBlendWeights, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeInt16Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingScaleFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.sensorOutput);
    encoder->EncodeFloatValue(value.currentOutput);
    encoder->EncodeUInt32Value(value.overrideHandScale);
    encoder->EncodeFloatValue(value.overrideValueInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingAimStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.status);
    EncodeStruct(encoder, value.aimPose);
    encoder->EncodeFloatValue(value.pinchStrengthIndex);
    encoder->EncodeFloatValue(value.pinchStrengthMiddle);
    encoder->EncodeFloatValue(value.pinchStrengthRing);
    encoder->EncodeFloatValue(value.pinchStrengthLittle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandCapsuleFB& value)
{
    EncodeStructArray(encoder, value.points, XR_HAND_TRACKING_CAPSULE_POINT_COUNT_FB);
    encoder->EncodeFloatValue(value.radius);
    encoder->EncodeEnumValue(value.joint);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingCapsulesStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructArray(encoder, value.capsules, XR_HAND_TRACKING_CAPSULE_COUNT_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpatialEntityPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsSpatialEntity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusSetInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.componentType);
    encoder->EncodeUInt32Value(value.enabled);
    encoder->EncodeInt64Value(value.timeout);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.enabled);
    encoder->EncodeUInt32Value(value.changePending);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUuidEXT& value)
{
    encoder->EncodeUInt8Array(value.data, XR_UUID_SIZE_EXT);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpatialAnchorCreateCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSetStatusCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.componentType);
    encoder->EncodeUInt32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationProfileCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfoFoveationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateFoveationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::FoveationProfileFBWrapper>(value.profile);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationLevelProfileCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.level);
    encoder->EncodeFloatValue(value.verticalOffset);
    encoder->EncodeEnumValue(value.dynamic);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemKeyboardTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsKeyboardTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingDescriptionFB& value)
{
    encoder->EncodeUInt64Value(value.trackedKeyboardId);
    EncodeStruct(encoder, value.size);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardSpaceCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.trackedKeyboardId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingQueryFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrTriangleMeshCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeEnumValue(value.windingOrder);
    encoder->EncodeUInt32Value(value.vertexCount);
    EncodeStructPtr(encoder, value.vertexBuffer);
    encoder->EncodeUInt32Value(value.triangleCount);
    encoder->EncodeUInt32Ptr(value.indexBuffer);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsPassthrough);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughProperties2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.capabilities);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughLayerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(value.passthrough);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeEnumValue(value.purpose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(value.layerHandle);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(value.layer);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(value.mesh);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceTransformFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughStyleFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.textureOpacityFactor);
    EncodeStruct(encoder, value.edgeColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToRgbaFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructArray(encoder, value.textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToMonoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt8Array(value.textureColorMap, XR_PASSTHROUGH_COLOR_MAP_MONO_SIZE_FB);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughBrightnessContrastSaturationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.brightness);
    encoder->EncodeFloatValue(value.contrast);
    encoder->EncodeFloatValue(value.saturation);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPassthroughStateChangedFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPathInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(value.path);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vendorId);
    encoder->EncodeString(value.modelName);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::RenderModelKeyFBWrapper>(value.modelKey);
    encoder->EncodeUInt32Value(value.modelVersion);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelBufferFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeUInt8Array(value.buffer, value.bufferCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelLoadInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::RenderModelKeyFBWrapper>(value.modelKey);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemRenderModelPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsRenderModelLoading);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelCapabilitiesRequestFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateFoveatedRenderingVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.foveatedRenderingActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveatedViewConfigurationViewVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.foveatedRenderingActive);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveatedRenderingPropertiesVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsFoveatedRendering);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.depthTestRangeNearZ);
    encoder->EncodeFloatValue(value.depthTestRangeFarZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerTrackingPropertiesVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsMarkerTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMarkerTrackingUpdateVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.markerId);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeUInt32Value(value.isPredicted);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoVARJO& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.markerId);
    EncodeStruct(encoder, value.poseInMarkerSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFrameEndInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.focusDistance);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrGlobalDimmerFrameEndInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.dimmerValue);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCoordinateSpaceCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeMLCoordinateFrameUIDValue(value.cfuid);
    EncodeStruct(encoder, value.poseInCoordinateSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerUnderstandingPropertiesML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsMarkerUnderstanding);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.profile);
    encoder->EncodeEnumValue(value.markerType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorArucoInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.arucoDict);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSizeInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.markerLength);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorAprilTagInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.aprilTagDict);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCustomProfileInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.fpsHint);
    encoder->EncodeEnumValue(value.resolutionHint);
    encoder->EncodeEnumValue(value.cameraHint);
    encoder->EncodeEnumValue(value.cornerRefineMethod);
    encoder->EncodeUInt32Value(value.useEdgeRefinement);
    encoder->EncodeEnumValue(value.fullAnalysisIntervalHint);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSnapshotInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorStateML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.state);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(value.markerDetector);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::MarkerMLWrapper>(value.marker);
    EncodeStruct(encoder, value.poseInMarkerSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.name);
    EncodeStruct(encoder, value.mapUuid);
    encoder->EncodeEnumValue(value.mapType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataLocalizationChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeEnumValue(value.state);
    EncodeStruct(encoder, value.map);
    encoder->EncodeEnumValue(value.confidence);
    encoder->EncodeFlags64Value(value.errorFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapQueryInfoBaseHeaderML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrMapLocalizationRequestInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.mapUuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapImportInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.size);
    encoder->EncodeString(value.data);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationEnableEventsInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceNameMSFT& value)
{
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.spatialAnchorPersistenceName);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(value.spatialAnchor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(value.spatialAnchorStore);
    EncodeStruct(encoder, value.spatialAnchorPersistenceName);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerMSFT& value)
{
    encoder->EncodeEnumValue(value.markerType);
    encoder->EncodeInt64Value(value.lastSeenTime);
    EncodeStruct(encoder, value.center);
    EncodeStruct(encoder, value.size);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkersMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.sceneMarkerCapacityInput);
    EncodeStructArray(encoder, value.sceneMarkers, value.sceneMarkerCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerTypeFilterMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.markerTypeCount);
    encoder->EncodeEnumArray(value.markerTypes, value.markerTypeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodeMSFT& value)
{
    encoder->EncodeEnumValue(value.symbolType);
    encoder->EncodeUInt8Value(value.version);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodesMSFT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.qrCodeCapacityInput);
    EncodeStructArray(encoder, value.qrCodes, value.qrCodeCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoBaseHeaderFB& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_SPACE_QUERY_INFO_FB:
        {
            const XrSpaceQueryInfoFB& child_value = reinterpret_cast<const XrSpaceQueryInfoFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceFilterInfoBaseHeaderFB& value)
{
    // Cast and call the appropriate encoder based on the structure type
    switch(value.type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", value.type);
            break;
        }
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
        {
            const XrSpaceUuidFilterInfoFB& child_value = reinterpret_cast<const XrSpaceUuidFilterInfoFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
        {
            const XrSpaceComponentFilterInfoFB& child_value = reinterpret_cast<const XrSpaceComponentFilterInfoFB&>(value);
            EncodeStruct(encoder, child_value);
            break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.queryAction);
    encoder->EncodeUInt32Value(value.maxResultCount);
    encoder->EncodeInt64Value(value.timeout);
    EncodeStructPtr(encoder, value.filter);
    EncodeStructPtr(encoder, value.excludeFilter);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceStorageLocationFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUuidFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.uuidCount);
    EncodeStructArray(encoder, value.uuids, value.uuidCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentFilterInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.componentType);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultFB& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.resultCapacityInput);
    encoder->EncodeUInt32Value(value.resultCountOutput);
    EncodeStructArray(encoder, value.results, value.resultCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryResultsAvailableFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceSaveInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.location);
    encoder->EncodeEnumValue(value.persistenceMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceEraseInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSaveCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceEraseCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.uuid);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageFoveationVulkanFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::ImageWrapper>(value.image);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateAndroidSurfaceDimensionsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.width);
    encoder->EncodeUInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerOpenGLESFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.minFilter);
    encoder->EncodeUInt32Value(value.magFilter);
    encoder->EncodeUInt32Value(value.wrapModeS);
    encoder->EncodeUInt32Value(value.wrapModeT);
    encoder->EncodeUInt32Value(value.swizzleRed);
    encoder->EncodeUInt32Value(value.swizzleGreen);
    encoder->EncodeUInt32Value(value.swizzleBlue);
    encoder->EncodeUInt32Value(value.swizzleAlpha);
    encoder->EncodeFloatValue(value.maxAnisotropy);
    EncodeStruct(encoder, value.borderColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerVulkanFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.minFilter);
    encoder->EncodeEnumValue(value.magFilter);
    encoder->EncodeEnumValue(value.mipmapMode);
    encoder->EncodeEnumValue(value.wrapModeS);
    encoder->EncodeEnumValue(value.wrapModeT);
    encoder->EncodeEnumValue(value.swizzleRed);
    encoder->EncodeEnumValue(value.swizzleGreen);
    encoder->EncodeEnumValue(value.swizzleBlue);
    encoder->EncodeEnumValue(value.swizzleAlpha);
    encoder->EncodeFloatValue(value.maxAnisotropy);
    EncodeStruct(encoder, value.borderColor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceShareInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.spaceCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceWrapper>(value.spaces, value.spaceCount);
    encoder->EncodeUInt32Value(value.userCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceUserFBWrapper>(value.users, value.userCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceShareCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSpaceWarpInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    EncodeStruct(encoder, value.motionVectorSubImage);
    EncodeStruct(encoder, value.appSpaceDeltaPose);
    EncodeStruct(encoder, value.depthSubImage);
    encoder->EncodeFloatValue(value.minDepth);
    encoder->EncodeFloatValue(value.maxDepth);
    encoder->EncodeFloatValue(value.nearZ);
    encoder->EncodeFloatValue(value.farZ);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpaceWarpPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.recommendedMotionVectorImageRectWidth);
    encoder->EncodeUInt32Value(value.recommendedMotionVectorImageRectHeight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticAmplitudeEnvelopeVibrationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.duration);
    encoder->EncodeUInt32Value(value.amplitudeCount);
    encoder->EncodeFloatArray(value.amplitudes, value.amplitudeCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfFB& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
    encoder->EncodeFloatValue(value.depth);
}

void EncodeStruct(ParameterEncoder* encoder, const XrOffset3DfFB& value)
{
    encoder->EncodeFloatValue(value.x);
    encoder->EncodeFloatValue(value.y);
    encoder->EncodeFloatValue(value.z);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRect3DfFB& value)
{
    EncodeStruct(encoder, value.offset);
    EncodeStruct(encoder, value.extent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeString(value.buffer);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRoomLayoutFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.floorUuid);
    EncodeStruct(encoder, value.ceilingUuid);
    encoder->EncodeUInt32Value(value.wallUuidCapacityInput);
    encoder->EncodeUInt32Value(value.wallUuidCountOutput);
    EncodeStructArray(encoder, value.wallUuids, value.wallUuidCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrBoundary2DFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsSupportInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
    encoder->EncodeString(value.recognizedLabels);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDigitalLensControlALMALENCE& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSceneCaptureCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSceneCaptureRequestInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.requestByteCount);
    encoder->EncodeString(value.request);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceContainerFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.uuidCapacityInput);
    encoder->EncodeUInt32Value(value.uuidCountOutput);
    EncodeStructArray(encoder, value.uuids, value.uuidCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedProfileCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructArray(encoder, value.foveationCenter, XR_FOVEATION_CENTER_SIZE_META);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveationEyeTrackedPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsFoveationEyeTracked);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsFaceTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.faceExpressionSet);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionStatusFB& value)
{
    encoder->EncodeUInt32Value(value.isValid);
    encoder->EncodeUInt32Value(value.isEyeFollowingBlendshapesValid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeightsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.weightCount);
    encoder->EncodeFloatArray(value.weights, value.weightCount);
    encoder->EncodeUInt32Value(value.confidenceCount);
    encoder->EncodeFloatArray(value.confidences, value.confidenceCount);
    EncodeStruct(encoder, value.status);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeFB& value)
{
    encoder->EncodeUInt32Value(value.isValid);
    EncodeStruct(encoder, value.gazePose);
    encoder->EncodeFloatValue(value.gazeConfidence);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeTrackerCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeTrackingPropertiesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsEyeTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructArray(encoder, value.gaze, XR_EYE_POSITION_COUNT_FB);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughKeyboardHandsIntensityFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.leftHandIntensity);
    encoder->EncodeFloatValue(value.rightHandIntensity);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSettingsFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHapticPcmVibrationFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeFloatArray(value.buffer, value.bufferSize);
    encoder->EncodeFloatValue(value.sampleRate);
    encoder->EncodeUInt32Value(value.append);
    encoder->EncodeUInt32Ptr(value.samplesConsumed);
}

void EncodeStruct(ParameterEncoder* encoder, const XrDevicePcmSampleRateStateFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.sampleRate);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.depthMask);
    encoder->EncodeEnumValue(value.compareOp);
}

void EncodeStruct(ParameterEncoder* encoder, const XrLocalDimmingFrameEndInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.localDimmingMode);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughPreferencesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemVirtualKeyboardPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsVirtualKeyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardSpaceCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.locationType);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardLocationInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.locationType);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    encoder->EncodeFloatValue(value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelVisibilitySetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.visible);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardAnimationStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt32Value(value.animationIndex);
    encoder->EncodeFloatValue(value.fraction);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelAnimationStatesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.stateCapacityInput);
    encoder->EncodeUInt32Value(value.stateCountOutput);
    EncodeStructArray(encoder, value.states, value.stateCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextureDataMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.textureWidth);
    encoder->EncodeUInt32Value(value.textureHeight);
    encoder->EncodeUInt32Value(value.bufferCapacityInput);
    encoder->EncodeUInt32Value(value.bufferCountOutput);
    encoder->EncodeUInt8Array(value.buffer, value.bufferCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardInputInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.inputSource);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.inputSpace);
    EncodeStruct(encoder, value.inputPoseInSpace);
    encoder->EncodeFlags64Value(value.inputState);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextContextChangeInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.textContext);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardCommitTextMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
    encoder->EncodeString(value.text);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardBackspaceMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardEnterMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardShownMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardHiddenMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(value.keyboard);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraIntrinsicsOCULUS& value)
{
    encoder->EncodeInt64Value(value.lastChangeTime);
    EncodeStruct(encoder, value.fov);
    encoder->EncodeFloatValue(value.virtualNearPlaneDistance);
    encoder->EncodeFloatValue(value.virtualFarPlaneDistance);
    EncodeStruct(encoder, value.imageSensorPixelResolution);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraExtrinsicsOCULUS& value)
{
    encoder->EncodeInt64Value(value.lastChangeTime);
    encoder->EncodeFlags64Value(value.cameraStatusFlags);
    encoder->EncodeEnumValue(value.attachedToDevice);
    EncodeStruct(encoder, value.relativePose);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraOCULUS& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeString(value.name);
    EncodeStruct(encoder, value.intrinsics);
    EncodeStruct(encoder, value.extrinsics);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlagsValue(value.additionalCreateFlags);
    encoder->EncodeFlagsValue(value.additionalUsageFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsStateMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.enabled);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsCounterMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.counterFlags);
    encoder->EncodeEnumValue(value.counterUnit);
    encoder->EncodeUInt32Value(value.uintValue);
    encoder->EncodeFloatValue(value.floatValue);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceListSaveInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.spaceCount);
    encoder->EncodeOpenXrHandleArray<openxr_wrappers::SpaceWrapper>(value.spaces, value.spaceCount);
    encoder->EncodeEnumValue(value.location);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceListSaveCompleteFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(value.requestId);
    encoder->EncodeEnumValue(value.result);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUserCreateInfoFB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.userId);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHeadsetIdPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.id);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.recommendedImageDimensions);
    encoder->EncodeUInt32Value(value.isValid);
}

void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionGetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStructPtr(encoder, value.layer);
    encoder->EncodeInt64Value(value.predictedDisplayTime);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutDataMETA& value)
{
    encoder->EncodeUInt32Value(value.bufferSize);
    encoder->EncodeUInt8Array(value.buffer, value.bufferSize);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutCreateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.channels);
    encoder->EncodeUInt32Value(value.resolution);
    EncodeStruct(encoder, value.data);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutUpdateInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    EncodeStruct(encoder, value.data);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapLutMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.colorLut);
    encoder->EncodeFloatValue(value.weight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapInterpolatedLutMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.sourceColorLut);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(value.targetColorLut);
    encoder->EncodeFloatValue(value.weight);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughColorLutPropertiesMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.maxColorLutResolution);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshGetInfoMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshMETA& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCapacityInput);
    encoder->EncodeUInt32Value(value.indexCountOutput);
    encoder->EncodeUInt32Array(value.indices, value.indexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingProperties2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsVisualFaceTracking);
    encoder->EncodeUInt32Value(value.supportsAudioFaceTracking);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfo2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.faceExpressionSet);
    encoder->EncodeUInt32Value(value.requestedDataSourceCount);
    encoder->EncodeEnumArray(value.requestedDataSources, value.requestedDataSourceCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfo2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeights2FB& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.weightCount);
    encoder->EncodeFloatArray(value.weights, value.weightCount);
    encoder->EncodeUInt32Value(value.confidenceCount);
    encoder->EncodeFloatArray(value.confidences, value.confidenceCount);
    encoder->EncodeUInt32Value(value.isValid);
    encoder->EncodeUInt32Value(value.isEyeFollowingBlendshapesValid);
    encoder->EncodeEnumValue(value.dataSource);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.form);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFloatValue(value.alpha);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughMeshTransformInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCount);
    EncodeStructArray(encoder, value.vertices, value.vertexCount);
    encoder->EncodeUInt32Value(value.indexCount);
    encoder->EncodeUInt32Array(value.indices, value.indexCount);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.scale);
}

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.layerFlags);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughHTCWrapper>(value.passthrough);
    EncodeStruct(encoder, value.color);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationApplyInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.mode);
    encoder->EncodeUInt32Value(value.subImageCount);
    EncodeStructArray(encoder, value.subImages, value.subImageCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationConfigurationHTC& value)
{
    encoder->EncodeEnumValue(value.level);
    encoder->EncodeFloatValue(value.clearFovDegree);
    EncodeStruct(encoder, value.focalCenterOffset);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationDynamicModeInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.dynamicFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationCustomModeInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.configCount);
    EncodeStructArray(encoder, value.configs, value.configCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemAnchorPropertiesHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsAnchor);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorNameHTC& value)
{
    encoder->EncodeString(value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoHTC& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.space);
    EncodeStruct(encoder, value.poseInSpace);
    EncodeStruct(encoder, value.name);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPriorityEXT& value)
{
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(value.actionSet);
    encoder->EncodeUInt32Value(value.priorityOverride);
}

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPrioritiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.actionSetPriorityCount);
    EncodeStructArray(encoder, value.actionSetPriorities, value.actionSetPriorityCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemForceFeedbackCurlPropertiesMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsForceFeedbackCurl);
}

void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationMNDX& value)
{
    encoder->EncodeEnumValue(value.location);
    encoder->EncodeFloatValue(value.value);
}

void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationsMNDX& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.locationCount);
    EncodeStructArray(encoder, value.locations, value.locationCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.requestedDataSourceCount);
    encoder->EncodeEnumArray(value.requestedDataSources, value.requestedDataSourceCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceStateEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.isActive);
    encoder->EncodeEnumValue(value.dataSource);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPlaneDetectionPropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.supportedFeatures);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeFlags64Value(value.flags);
}

void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfEXT& value)
{
    encoder->EncodeFloatValue(value.width);
    encoder->EncodeFloatValue(value.height);
    encoder->EncodeFloatValue(value.depth);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorBeginInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
    encoder->EncodeUInt32Value(value.orientationCount);
    encoder->EncodeEnumArray(value.orientations, value.orientationCount);
    encoder->EncodeUInt32Value(value.semanticTypeCount);
    encoder->EncodeEnumArray(value.semanticTypes, value.semanticTypeCount);
    encoder->EncodeUInt32Value(value.maxPlanes);
    encoder->EncodeFloatValue(value.minArea);
    EncodeStruct(encoder, value.boundingBoxPose);
    EncodeStruct(encoder, value.boundingBoxExtent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorGetInfoEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(value.baseSpace);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt64Value(value.planeId);
    encoder->EncodeFlags64Value(value.locationFlags);
    EncodeStruct(encoder, value.pose);
    EncodeStruct(encoder, value.extents);
    encoder->EncodeEnumValue(value.orientation);
    encoder->EncodeEnumValue(value.semanticType);
    encoder->EncodeUInt32Value(value.polygonBufferCount);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationsEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.planeLocationCapacityInput);
    encoder->EncodeUInt32Value(value.planeLocationCountOutput);
    EncodeStructArray(encoder, value.planeLocations, value.planeLocationCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorPolygonBufferEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.vertexCapacityInput);
    encoder->EncodeUInt32Value(value.vertexCountOutput);
    EncodeStructArray(encoder, value.vertices, value.vertexCapacityInput);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataUserPresenceChangedEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(value.session);
    encoder->EncodeUInt32Value(value.isUserPresent);
}

void EncodeStruct(ParameterEncoder* encoder, const XrSystemUserPresencePropertiesEXT& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.supportsUserPresence);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataHeadsetFitChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.status);
    encoder->EncodeInt64Value(value.time);
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEyeCalibrationChangedML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeEnumValue(value.status);
}

void EncodeStruct(ParameterEncoder* encoder, const XrUserCalibrationEnableEventsInfoML& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeUInt32Value(value.enabled);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
