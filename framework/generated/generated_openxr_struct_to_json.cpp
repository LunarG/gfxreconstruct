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

#include "generated_openxr_struct_to_json.h"
#include "generated_vulkan_struct_to_json.h"
#include "generated_openxr_enum_to_json.h"
#include "generated_vulkan_enum_to_json.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
using util::FieldToJson;
using util::HandleToJson;
using util::to_hex_variable_width;
using util::uuid_to_string;


void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerProperties& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerProperties& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["layerName"], &meta_struct.layerName);
        jdata["specVersion"] = decoded_value.specVersion;
        jdata["layerVersion"] = decoded_value.layerVersion;
        FieldToJson(jdata["description"], &meta_struct.description);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtensionProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrExtensionProperties& decoded_value = *data->decoded_value;
        const Decoded_XrExtensionProperties& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["extensionName"], &meta_struct.extensionName);
        jdata["extensionVersion"] = decoded_value.extensionVersion;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApplicationInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrApplicationInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApplicationInfo& meta_struct = *data;

        FieldToJson(jdata["applicationName"], &meta_struct.applicationName);
        jdata["applicationVersion"] = decoded_value.applicationVersion;
        FieldToJson(jdata["engineName"], &meta_struct.engineName);
        jdata["engineVersion"] = decoded_value.engineVersion;
        jdata["apiVersion"] = decoded_value.apiVersion;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrInstanceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrInstanceCreateFlags_t{decoded_value.createFlags};
        FieldToJson(jdata["applicationInfo"], meta_struct.applicationInfo);
        jdata["enabledApiLayerCount"] = decoded_value.enabledApiLayerCount;
        FieldToJson(jdata["enabledApiLayerNames"], &meta_struct.enabledApiLayerNames);
        jdata["enabledExtensionCount"] = decoded_value.enabledExtensionCount;
        FieldToJson(jdata["enabledExtensionNames"], &meta_struct.enabledExtensionNames);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrInstanceProperties& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceProperties& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["runtimeVersion"] = decoded_value.runtimeVersion;
        FieldToJson(jdata["runtimeName"], &meta_struct.runtimeName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBuffer* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataBuffer& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataBuffer& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["varying"], &meta_struct.varying);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGetInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSystemGetInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["formFactor"] = decoded_value.formFactor;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGraphicsProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemGraphicsProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemGraphicsProperties& meta_struct = *data;

        jdata["maxSwapchainImageHeight"] = decoded_value.maxSwapchainImageHeight;
        jdata["maxSwapchainImageWidth"] = decoded_value.maxSwapchainImageWidth;
        jdata["maxLayerCount"] = decoded_value.maxLayerCount;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemTrackingProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemTrackingProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemTrackingProperties& meta_struct = *data;

        jdata["orientationTracking"] = static_cast<bool>(decoded_value.orientationTracking);
        jdata["positionTracking"] = static_cast<bool>(decoded_value.positionTracking);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemProperties& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["systemId"], meta_struct.systemId);
        jdata["vendorId"] = decoded_value.vendorId;
        FieldToJson(jdata["systemName"], &meta_struct.systemName);
        FieldToJson(jdata["graphicsProperties"], meta_struct.graphicsProperties);
        FieldToJson(jdata["trackingProperties"], meta_struct.trackingProperties);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSessionCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrSessionCreateFlags_t{decoded_value.createFlags};
        HandleToJson(jdata["systemId"], meta_struct.systemId);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector3f* data)
{
    if (data && data->decoded_value)
    {
        const XrVector3f& decoded_value = *data->decoded_value;
        const Decoded_XrVector3f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
        FieldToJson(jdata["z"], decoded_value.z);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocity* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceVelocity& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceVelocity& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["velocityFlags"] = XrSpaceVelocityFlags_t{decoded_value.velocityFlags};
        FieldToJson(jdata["linearVelocity"], meta_struct.linearVelocity);
        FieldToJson(jdata["angularVelocity"], meta_struct.angularVelocity);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrQuaternionf* data)
{
    if (data && data->decoded_value)
    {
        const XrQuaternionf& decoded_value = *data->decoded_value;
        const Decoded_XrQuaternionf& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
        FieldToJson(jdata["z"], decoded_value.z);
        FieldToJson(jdata["w"], decoded_value.w);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPosef* data)
{
    if (data && data->decoded_value)
    {
        const XrPosef& decoded_value = *data->decoded_value;
        const Decoded_XrPosef& meta_struct = *data;

        FieldToJson(jdata["orientation"], meta_struct.orientation);
        FieldToJson(jdata["position"], meta_struct.position);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrReferenceSpaceCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrReferenceSpaceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrReferenceSpaceCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["referenceSpaceType"] = decoded_value.referenceSpaceType;
        FieldToJson(jdata["poseInReferenceSpace"], meta_struct.poseInReferenceSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Df* data)
{
    if (data && data->decoded_value)
    {
        const XrExtent2Df& decoded_value = *data->decoded_value;
        const Decoded_XrExtent2Df& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width);
        FieldToJson(jdata["height"], decoded_value.height);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSpaceCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrActionSpaceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionSpaceCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["action"], meta_struct.action);
        HandleToJson(jdata["subactionPath"], meta_struct.subactionPath);
        FieldToJson(jdata["poseInActionSpace"], meta_struct.poseInActionSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocation* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceLocation& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceLocation& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationFlags"] = XrSpaceLocationFlags_t{decoded_value.locationFlags};
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationProperties* data)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationProperties& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationProperties& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        jdata["fovMutable"] = static_cast<bool>(decoded_value.fovMutable);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationView* data)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationView& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationView& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["recommendedImageRectWidth"] = decoded_value.recommendedImageRectWidth;
        jdata["maxImageRectWidth"] = decoded_value.maxImageRectWidth;
        jdata["recommendedImageRectHeight"] = decoded_value.recommendedImageRectHeight;
        jdata["maxImageRectHeight"] = decoded_value.maxImageRectHeight;
        jdata["recommendedSwapchainSampleCount"] = decoded_value.recommendedSwapchainSampleCount;
        jdata["maxSwapchainSampleCount"] = decoded_value.maxSwapchainSampleCount;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrSwapchainCreateFlags_t{decoded_value.createFlags};
        jdata["usageFlags"] = XrSwapchainUsageFlags_t{decoded_value.usageFlags};
        jdata["format"] = decoded_value.format;
        jdata["sampleCount"] = decoded_value.sampleCount;
        jdata["width"] = decoded_value.width;
        jdata["height"] = decoded_value.height;
        jdata["faceCount"] = decoded_value.faceCount;
        jdata["arraySize"] = decoded_value.arraySize;
        jdata["mipCount"] = decoded_value.mipCount;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageBaseHeader* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageBaseHeader& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageOpenGLKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageOpenGLESKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageVulkanKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageD3D11KHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageD3D12KHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageAcquireInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageAcquireInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageAcquireInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageWaitInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageWaitInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageWaitInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["timeout"] = decoded_value.timeout;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageReleaseInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageReleaseInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageReleaseInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionBeginInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSessionBeginInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionBeginInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["primaryViewConfigurationType"] = decoded_value.primaryViewConfigurationType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameWaitInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrFrameWaitInfo& decoded_value = *data->decoded_value;
        const Decoded_XrFrameWaitInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameState* data)
{
    if (data && data->decoded_value)
    {
        const XrFrameState& decoded_value = *data->decoded_value;
        const Decoded_XrFrameState& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["predictedDisplayTime"] = decoded_value.predictedDisplayTime;
        jdata["predictedDisplayPeriod"] = decoded_value.predictedDisplayPeriod;
        jdata["shouldRender"] = static_cast<bool>(decoded_value.shouldRender);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameBeginInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrFrameBeginInfo& decoded_value = *data->decoded_value;
        const Decoded_XrFrameBeginInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerBaseHeader* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerBaseHeader& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerProjection*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerQuad*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerCubeKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerCylinderKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerEquirectKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerEquirect2KHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerPassthroughFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerPassthroughHTC*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrFrameEndInfo& decoded_value = *data->decoded_value;
        const Decoded_XrFrameEndInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["displayTime"] = decoded_value.displayTime;
        jdata["environmentBlendMode"] = decoded_value.environmentBlendMode;
        jdata["layerCount"] = decoded_value.layerCount;
        FieldToJson(jdata["layers"], meta_struct.layers);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrViewLocateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrViewLocateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        jdata["displayTime"] = decoded_value.displayTime;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewState* data)
{
    if (data && data->decoded_value)
    {
        const XrViewState& decoded_value = *data->decoded_value;
        const Decoded_XrViewState& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewStateFlags"] = XrViewStateFlags_t{decoded_value.viewStateFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFovf* data)
{
    if (data && data->decoded_value)
    {
        const XrFovf& decoded_value = *data->decoded_value;
        const Decoded_XrFovf& meta_struct = *data;

        FieldToJson(jdata["angleLeft"], decoded_value.angleLeft);
        FieldToJson(jdata["angleRight"], decoded_value.angleRight);
        FieldToJson(jdata["angleUp"], decoded_value.angleUp);
        FieldToJson(jdata["angleDown"], decoded_value.angleDown);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrView* data)
{
    if (data && data->decoded_value)
    {
        const XrView& decoded_value = *data->decoded_value;
        const Decoded_XrView& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSetCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrActionSetCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionSetCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["actionSetName"], &meta_struct.actionSetName);
        FieldToJson(jdata["localizedActionSetName"], &meta_struct.localizedActionSetName);
        jdata["priority"] = decoded_value.priority;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrActionCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionCreateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["actionName"], &meta_struct.actionName);
        jdata["actionType"] = decoded_value.actionType;
        jdata["countSubactionPaths"] = decoded_value.countSubactionPaths;
        HandleToJson(jdata["subactionPaths"], &meta_struct.subactionPaths);
        FieldToJson(jdata["localizedActionName"], &meta_struct.localizedActionName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSuggestedBinding* data)
{
    if (data && data->decoded_value)
    {
        const XrActionSuggestedBinding& decoded_value = *data->decoded_value;
        const Decoded_XrActionSuggestedBinding& meta_struct = *data;

        HandleToJson(jdata["action"], meta_struct.action);
        HandleToJson(jdata["binding"], meta_struct.binding);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileSuggestedBinding* data)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileSuggestedBinding& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileSuggestedBinding& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["interactionProfile"], meta_struct.interactionProfile);
        jdata["countSuggestedBindings"] = decoded_value.countSuggestedBindings;
        FieldToJson(jdata["suggestedBindings"], meta_struct.suggestedBindings);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionActionSetsAttachInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSessionActionSetsAttachInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionActionSetsAttachInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["countActionSets"] = decoded_value.countActionSets;
        HandleToJson(jdata["actionSets"], &meta_struct.actionSets);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileState* data)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileState& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileState& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["interactionProfile"], meta_struct.interactionProfile);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateGetInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrActionStateGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateGetInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["action"], meta_struct.action);
        HandleToJson(jdata["subactionPath"], meta_struct.subactionPath);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateBoolean* data)
{
    if (data && data->decoded_value)
    {
        const XrActionStateBoolean& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateBoolean& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["currentState"] = static_cast<bool>(decoded_value.currentState);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        jdata["lastChangeTime"] = decoded_value.lastChangeTime;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateFloat* data)
{
    if (data && data->decoded_value)
    {
        const XrActionStateFloat& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateFloat& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["currentState"], decoded_value.currentState);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        jdata["lastChangeTime"] = decoded_value.lastChangeTime;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector2f* data)
{
    if (data && data->decoded_value)
    {
        const XrVector2f& decoded_value = *data->decoded_value;
        const Decoded_XrVector2f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateVector2f* data)
{
    if (data && data->decoded_value)
    {
        const XrActionStateVector2f& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateVector2f& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["currentState"], meta_struct.currentState);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        jdata["lastChangeTime"] = decoded_value.lastChangeTime;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStatePose* data)
{
    if (data && data->decoded_value)
    {
        const XrActionStatePose& decoded_value = *data->decoded_value;
        const Decoded_XrActionStatePose& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSet* data)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSet& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSet& meta_struct = *data;

        HandleToJson(jdata["actionSet"], meta_struct.actionSet);
        HandleToJson(jdata["subactionPath"], meta_struct.subactionPath);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionsSyncInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrActionsSyncInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionsSyncInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["countActiveActionSets"] = decoded_value.countActiveActionSets;
        FieldToJson(jdata["activeActionSets"], meta_struct.activeActionSets);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundSourcesForActionEnumerateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrBoundSourcesForActionEnumerateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrBoundSourcesForActionEnumerateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["action"], meta_struct.action);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInputSourceLocalizedNameGetInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrInputSourceLocalizedNameGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrInputSourceLocalizedNameGetInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["sourcePath"], meta_struct.sourcePath);
        jdata["whichComponents"] = XrInputSourceLocalizedNameFlags_t{decoded_value.whichComponents};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticActionInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrHapticActionInfo& decoded_value = *data->decoded_value;
        const Decoded_XrHapticActionInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["action"], meta_struct.action);
        HandleToJson(jdata["subactionPath"], meta_struct.subactionPath);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticBaseHeader* data)
{
    if (data && data->decoded_value)
    {
        const XrHapticBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrHapticBaseHeader& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_HAPTIC_VIBRATION:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticVibration*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticPcmVibrationFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Di* data)
{
    if (data && data->decoded_value)
    {
        const XrOffset2Di& decoded_value = *data->decoded_value;
        const Decoded_XrOffset2Di& meta_struct = *data;

        jdata["x"] = decoded_value.x;
        jdata["y"] = decoded_value.y;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Di* data)
{
    if (data && data->decoded_value)
    {
        const XrExtent2Di& decoded_value = *data->decoded_value;
        const Decoded_XrExtent2Di& meta_struct = *data;

        jdata["width"] = decoded_value.width;
        jdata["height"] = decoded_value.height;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Di* data)
{
    if (data && data->decoded_value)
    {
        const XrRect2Di& decoded_value = *data->decoded_value;
        const Decoded_XrRect2Di& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset);
        FieldToJson(jdata["extent"], meta_struct.extent);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainSubImage* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainSubImage& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainSubImage& meta_struct = *data;

        HandleToJson(jdata["swapchain"], meta_struct.swapchain);
        FieldToJson(jdata["imageRect"], meta_struct.imageRect);
        jdata["imageArrayIndex"] = decoded_value.imageArrayIndex;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjectionView* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerProjectionView& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerProjectionView& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjection* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerProjection& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerProjection& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["viewCount"] = decoded_value.viewCount;
        FieldToJson(jdata["views"], meta_struct.views);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerQuad* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerQuad& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerQuad& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["eyeVisibility"] = decoded_value.eyeVisibility;
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["size"], meta_struct.size);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBaseHeader* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataBaseHeader& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataEventsLost*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataInstanceLossPending*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSessionStateChanged*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataReferenceSpaceChangePending*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataInteractionProfileChanged*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataVisibilityMaskChangedKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataPerfSettingsEXT*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataDisplayRefreshRateChangedFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataViveTrackerConnectedHTCX*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceSetStatusCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataLocalizationChangedML*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceQueryCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceSaveCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceEraseCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceShareCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceListSaveCompleteFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataHeadsetFitChangedML*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataEyeCalibrationChangedML*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEventsLost* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataEventsLost& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataEventsLost& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["lostEventCount"] = decoded_value.lostEventCount;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInstanceLossPending* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataInstanceLossPending& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataInstanceLossPending& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["lossTime"] = decoded_value.lossTime;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSessionStateChanged* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSessionStateChanged& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSessionStateChanged& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        jdata["state"] = decoded_value.state;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataReferenceSpaceChangePending* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataReferenceSpaceChangePending& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataReferenceSpaceChangePending& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        jdata["referenceSpaceType"] = decoded_value.referenceSpaceType;
        jdata["changeTime"] = decoded_value.changeTime;
        jdata["poseValid"] = static_cast<bool>(decoded_value.poseValid);
        FieldToJson(jdata["poseInPreviousSpace"], meta_struct.poseInPreviousSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInteractionProfileChanged* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataInteractionProfileChanged& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataInteractionProfileChanged& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticVibration* data)
{
    if (data && data->decoded_value)
    {
        const XrHapticVibration& decoded_value = *data->decoded_value;
        const Decoded_XrHapticVibration& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["duration"] = decoded_value.duration;
        FieldToJson(jdata["frequency"], decoded_value.frequency);
        FieldToJson(jdata["amplitude"], decoded_value.amplitude);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Df* data)
{
    if (data && data->decoded_value)
    {
        const XrOffset2Df& decoded_value = *data->decoded_value;
        const Decoded_XrOffset2Df& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Df* data)
{
    if (data && data->decoded_value)
    {
        const XrRect2Df& decoded_value = *data->decoded_value;
        const Decoded_XrRect2Df& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset);
        FieldToJson(jdata["extent"], meta_struct.extent);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4f* data)
{
    if (data && data->decoded_value)
    {
        const XrVector4f& decoded_value = *data->decoded_value;
        const Decoded_XrVector4f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
        FieldToJson(jdata["z"], decoded_value.z);
        FieldToJson(jdata["w"], decoded_value.w);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor4f* data)
{
    if (data && data->decoded_value)
    {
        const XrColor4f& decoded_value = *data->decoded_value;
        const Decoded_XrColor4f& meta_struct = *data;

        FieldToJson(jdata["r"], decoded_value.r);
        FieldToJson(jdata["g"], decoded_value.g);
        FieldToJson(jdata["b"], decoded_value.b);
        FieldToJson(jdata["a"], decoded_value.a);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerNextInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerNextInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerNextInfo& meta_struct = *data;

        jdata["structType"] = decoded_value.structType;
        jdata["structVersion"] = decoded_value.structVersion;
        jdata["structSize"] = decoded_value.structSize;
        FieldToJson(jdata["layerName"], &meta_struct.layerName);
        FieldToJson(jdata["nextGetInstanceProcAddr"], to_hex_variable_width(meta_struct.nextGetInstanceProcAddr));
        FieldToJson(jdata["nextCreateApiLayerInstance"], to_hex_variable_width(meta_struct.nextCreateApiLayerInstance));
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerCreateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerCreateInfo& meta_struct = *data;

        jdata["structType"] = decoded_value.structType;
        jdata["structVersion"] = decoded_value.structVersion;
        jdata["structSize"] = decoded_value.structSize;
        jdata["loaderInstance"] = meta_struct.loaderInstance;
        FieldToJson(jdata["settings_file_location"], &meta_struct.settings_file_location);
        FieldToJson(jdata["nextInfo"], meta_struct.nextInfo);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNegotiateApiLayerRequest* data)
{
    if (data && data->decoded_value)
    {
        const XrNegotiateApiLayerRequest& decoded_value = *data->decoded_value;
        const Decoded_XrNegotiateApiLayerRequest& meta_struct = *data;

        jdata["structType"] = decoded_value.structType;
        jdata["structVersion"] = decoded_value.structVersion;
        jdata["structSize"] = decoded_value.structSize;
        jdata["layerInterfaceVersion"] = decoded_value.layerInterfaceVersion;
        jdata["layerApiVersion"] = decoded_value.layerApiVersion;
        FieldToJson(jdata["getInstanceProcAddr"], to_hex_variable_width(meta_struct.getInstanceProcAddr));
        FieldToJson(jdata["createApiLayerInstance"], to_hex_variable_width(meta_struct.createApiLayerInstance));
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor3f* data)
{
    if (data && data->decoded_value)
    {
        const XrColor3f& decoded_value = *data->decoded_value;
        const Decoded_XrColor3f& meta_struct = *data;

        FieldToJson(jdata["r"], decoded_value.r);
        FieldToJson(jdata["g"], decoded_value.g);
        FieldToJson(jdata["b"], decoded_value.b);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3Df* data)
{
    if (data && data->decoded_value)
    {
        const XrExtent3Df& decoded_value = *data->decoded_value;
        const Decoded_XrExtent3Df& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width);
        FieldToJson(jdata["height"], decoded_value.height);
        FieldToJson(jdata["depth"], decoded_value.depth);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpheref* data)
{
    if (data && data->decoded_value)
    {
        const XrSpheref& decoded_value = *data->decoded_value;
        const Decoded_XrSpheref& meta_struct = *data;

        FieldToJson(jdata["center"], meta_struct.center);
        FieldToJson(jdata["radius"], decoded_value.radius);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoxf* data)
{
    if (data && data->decoded_value)
    {
        const XrBoxf& decoded_value = *data->decoded_value;
        const Decoded_XrBoxf& meta_struct = *data;

        FieldToJson(jdata["center"], meta_struct.center);
        FieldToJson(jdata["extents"], meta_struct.extents);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrustumf* data)
{
    if (data && data->decoded_value)
    {
        const XrFrustumf& decoded_value = *data->decoded_value;
        const Decoded_XrFrustumf& meta_struct = *data;

        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["nearZ"], decoded_value.nearZ);
        FieldToJson(jdata["farZ"], decoded_value.farZ);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuid* data)
{
    if (data && data->decoded_value)
    {
        const XrUuid& decoded_value = *data->decoded_value;
        const Decoded_XrUuid& meta_struct = *data;

        FieldToJson(jdata["data"], uuid_to_string(sizeof(decoded_value.data), decoded_value.data));
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpacesLocateInfo* data)
{
    if (data && data->decoded_value)
    {
        const XrSpacesLocateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSpacesLocateInfo& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        jdata["spaceCount"] = decoded_value.spaceCount;
        HandleToJson(jdata["spaces"], &meta_struct.spaces);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocationData* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceLocationData& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceLocationData& meta_struct = *data;

        jdata["locationFlags"] = XrSpaceLocationFlags_t{decoded_value.locationFlags};
        FieldToJson(jdata["pose"], meta_struct.pose);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocations* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceLocations& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceLocations& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationCount"] = decoded_value.locationCount;
        FieldToJson(jdata["locations"], meta_struct.locations);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocityData* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceVelocityData& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceVelocityData& meta_struct = *data;

        jdata["velocityFlags"] = XrSpaceVelocityFlags_t{decoded_value.velocityFlags};
        FieldToJson(jdata["linearVelocity"], meta_struct.linearVelocity);
        FieldToJson(jdata["angularVelocity"], meta_struct.angularVelocity);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocities* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceVelocities& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceVelocities& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["velocityCount"] = decoded_value.velocityCount;
        FieldToJson(jdata["velocities"], meta_struct.velocities);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCubeKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerCubeKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerCubeKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["eyeVisibility"] = decoded_value.eyeVisibility;
        HandleToJson(jdata["swapchain"], meta_struct.swapchain);
        jdata["imageArrayIndex"] = decoded_value.imageArrayIndex;
        FieldToJson(jdata["orientation"], meta_struct.orientation);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfoAndroidKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrInstanceCreateInfoAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceCreateInfoAndroidKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["applicationVM"] = meta_struct.applicationVM;
        jdata["applicationActivity"] = meta_struct.applicationActivity;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthInfoKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthInfoKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["minDepth"], decoded_value.minDepth);
        FieldToJson(jdata["maxDepth"], decoded_value.maxDepth);
        FieldToJson(jdata["nearZ"], decoded_value.nearZ);
        FieldToJson(jdata["farZ"], decoded_value.farZ);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrVulkanSwapchainFormatListCreateInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewFormatCount"] = decoded_value.viewFormatCount;
        FieldToJson(jdata["viewFormats"], meta_struct.viewFormats);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCylinderKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerCylinderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerCylinderKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["eyeVisibility"] = decoded_value.eyeVisibility;
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["radius"], decoded_value.radius);
        FieldToJson(jdata["centralAngle"], decoded_value.centralAngle);
        FieldToJson(jdata["aspectRatio"], decoded_value.aspectRatio);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirectKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerEquirectKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerEquirectKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["eyeVisibility"] = decoded_value.eyeVisibility;
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["radius"], decoded_value.radius);
        FieldToJson(jdata["scale"], meta_struct.scale);
        FieldToJson(jdata["bias"], meta_struct.bias);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWin32KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLWin32KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLWin32KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["hDC"] = meta_struct.hDC;
        jdata["hGLRC"] = meta_struct.hGLRC;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXlibKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLXlibKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLXlibKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["xDisplay"] = meta_struct.xDisplay;
        jdata["visualid"] = decoded_value.visualid;
        jdata["glxFBConfig"] = meta_struct.glxFBConfig;
        jdata["glxDrawable"] = decoded_value.glxDrawable;
        jdata["glxContext"] = meta_struct.glxContext;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXcbKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLXcbKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLXcbKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["connection"] = meta_struct.connection;
        jdata["screenNumber"] = decoded_value.screenNumber;
        jdata["fbconfigid"] = decoded_value.fbconfigid;
        jdata["visualid"] = decoded_value.visualid;
        jdata["glxDrawable"] = decoded_value.glxDrawable;
        jdata["glxContext"] = decoded_value.glxContext;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWaylandKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLWaylandKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLWaylandKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["display"] = meta_struct.display;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageOpenGLKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageOpenGLKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["image"] = decoded_value.image;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsOpenGLKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsOpenGLKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["minApiVersionSupported"] = decoded_value.minApiVersionSupported;
        jdata["maxApiVersionSupported"] = decoded_value.maxApiVersionSupported;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLESAndroidKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLESAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLESAndroidKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["display"] = meta_struct.display;
        jdata["config"] = meta_struct.config;
        jdata["context"] = meta_struct.context;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLESKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageOpenGLESKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageOpenGLESKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["image"] = decoded_value.image;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLESKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsOpenGLESKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsOpenGLESKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["minApiVersionSupported"] = decoded_value.minApiVersionSupported;
        jdata["maxApiVersionSupported"] = decoded_value.maxApiVersionSupported;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingVulkanKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingVulkanKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["instance"], meta_struct.instance);
        HandleToJson(jdata["physicalDevice"], meta_struct.physicalDevice);
        HandleToJson(jdata["device"], meta_struct.device);
        jdata["queueFamilyIndex"] = decoded_value.queueFamilyIndex;
        jdata["queueIndex"] = decoded_value.queueIndex;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageVulkanKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageVulkanKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["image"], meta_struct.image);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsVulkanKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsVulkanKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["minApiVersionSupported"] = decoded_value.minApiVersionSupported;
        jdata["maxApiVersionSupported"] = decoded_value.maxApiVersionSupported;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D11KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingD3D11KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["device"] = meta_struct.device;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D11KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageD3D11KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["texture"] = meta_struct.texture;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D11KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsD3D11KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["adapterLuid"], decoded_value.adapterLuid);
        jdata["minFeatureLevel"] = decoded_value.minFeatureLevel;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D12KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingD3D12KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["device"] = meta_struct.device;
        jdata["queue"] = meta_struct.queue;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D12KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageD3D12KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["texture"] = meta_struct.texture;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D12KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsD3D12KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["adapterLuid"], decoded_value.adapterLuid);
        jdata["minFeatureLevel"] = decoded_value.minFeatureLevel;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingMetalKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingMetalKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingMetalKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["commandQueue"] = meta_struct.commandQueue;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageMetalKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageMetalKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageMetalKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["texture"] = meta_struct.texture;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsMetalKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsMetalKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsMetalKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["metalDevice"] = meta_struct.metalDevice;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisibilityMaskKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrVisibilityMaskKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVisibilityMaskKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVisibilityMaskChangedKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVisibilityMaskChangedKHR& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVisibilityMaskChangedKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        jdata["viewIndex"] = decoded_value.viewIndex;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerColorScaleBiasKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerColorScaleBiasKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerColorScaleBiasKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["colorScale"], meta_struct.colorScale);
        FieldToJson(jdata["colorBias"], meta_struct.colorBias);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoBaseHeaderKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrLoaderInitInfoBaseHeaderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrLoaderInitInfoBaseHeaderKHR& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrLoaderInitInfoAndroidKHR*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoAndroidKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrLoaderInitInfoAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrLoaderInitInfoAndroidKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["applicationVM"] = meta_struct.applicationVM;
        jdata["applicationContext"] = meta_struct.applicationContext;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanGraphicsDeviceGetInfoKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrVulkanGraphicsDeviceGetInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanGraphicsDeviceGetInfoKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["systemId"], meta_struct.systemId);
        HandleToJson(jdata["vulkanInstance"], meta_struct.vulkanInstance);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirect2KHR* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerEquirect2KHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerEquirect2KHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["eyeVisibility"] = decoded_value.eyeVisibility;
        FieldToJson(jdata["subImage"], meta_struct.subImage);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["radius"], decoded_value.radius);
        FieldToJson(jdata["centralHorizontalAngle"], decoded_value.centralHorizontalAngle);
        FieldToJson(jdata["upperVerticalAngle"], decoded_value.upperVerticalAngle);
        FieldToJson(jdata["lowerVerticalAngle"], decoded_value.lowerVerticalAngle);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationBaseHeaderKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrBindingModificationBaseHeaderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrBindingModificationBaseHeaderKHR& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrInteractionProfileDpadBindingEXT*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrInteractionProfileAnalogThresholdVALVE*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationsKHR* data)
{
    if (data && data->decoded_value)
    {
        const XrBindingModificationsKHR& decoded_value = *data->decoded_value;
        const Decoded_XrBindingModificationsKHR& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["bindingModificationCount"] = decoded_value.bindingModificationCount;
        FieldToJson(jdata["bindingModifications"], meta_struct.bindingModifications);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPerfSettingsEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataPerfSettingsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataPerfSettingsEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["domain"] = decoded_value.domain;
        jdata["subDomain"] = decoded_value.subDomain;
        jdata["fromLevel"] = decoded_value.fromLevel;
        jdata["toLevel"] = decoded_value.toLevel;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsObjectNameInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsObjectNameInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsObjectNameInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["objectType"] = decoded_value.objectType;
        jdata["objectHandle"] = decoded_value.objectHandle;
        FieldToJson(jdata["objectName"], &meta_struct.objectName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsLabelEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsLabelEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsLabelEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["labelName"], &meta_struct.labelName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCallbackDataEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsMessengerCallbackDataEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsMessengerCallbackDataEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["messageId"], &meta_struct.messageId);
        FieldToJson(jdata["functionName"], &meta_struct.functionName);
        FieldToJson(jdata["message"], &meta_struct.message);
        jdata["objectCount"] = decoded_value.objectCount;
        FieldToJson(jdata["objects"], meta_struct.objects);
        jdata["sessionLabelCount"] = decoded_value.sessionLabelCount;
        FieldToJson(jdata["sessionLabels"], meta_struct.sessionLabels);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCreateInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsMessengerCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsMessengerCreateInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["messageSeverities"] = XrDebugUtilsMessageSeverityFlagsEXT_t{decoded_value.messageSeverities};
        jdata["messageTypes"] = XrDebugUtilsMessageTypeFlagsEXT_t{decoded_value.messageTypes};
        FieldToJson(jdata["userCallback"], to_hex_variable_width(meta_struct.userCallback));
        FieldToJson(jdata["userData"], to_hex_variable_width(meta_struct.userData));
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeGazeInteractionPropertiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemEyeGazeInteractionPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemEyeGazeInteractionPropertiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsEyeGazeInteraction"] = static_cast<bool>(decoded_value.supportsEyeGazeInteraction);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeSampleTimeEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazeSampleTimeEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazeSampleTimeEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfoOverlayEXTX* data)
{
    if (data && data->decoded_value)
    {
        const XrSessionCreateInfoOverlayEXTX& decoded_value = *data->decoded_value;
        const Decoded_XrSessionCreateInfoOverlayEXTX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrOverlaySessionCreateFlagsEXTX_t{decoded_value.createFlags};
        jdata["sessionLayersPlacement"] = decoded_value.sessionLayersPlacement;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMainSessionVisibilityChangedEXTX* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataMainSessionVisibilityChangedEXTX& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataMainSessionVisibilityChangedEXTX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["visible"] = static_cast<bool>(decoded_value.visible);
        jdata["flags"] = XrOverlayMainSessionFlagsEXTX_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["pose"], meta_struct.pose);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["anchor"], meta_struct.anchor);
        FieldToJson(jdata["poseInAnchorSpace"], meta_struct.poseInAnchorSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerImageLayoutFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerImageLayoutFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerImageLayoutFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrCompositionLayerImageLayoutFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerAlphaBlendFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerAlphaBlendFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerAlphaBlendFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["srcFactorColor"] = decoded_value.srcFactorColor;
        jdata["dstFactorColor"] = decoded_value.dstFactorColor;
        jdata["srcFactorAlpha"] = decoded_value.srcFactorAlpha;
        jdata["dstFactorAlpha"] = decoded_value.dstFactorAlpha;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationDepthRangeEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationDepthRangeEXT& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationDepthRangeEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["recommendedNearZ"], decoded_value.recommendedNearZ);
        FieldToJson(jdata["minNearZ"], decoded_value.minNearZ);
        FieldToJson(jdata["recommendedFarZ"], decoded_value.recommendedFarZ);
        FieldToJson(jdata["maxFarZ"], decoded_value.maxFarZ);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingEGLMNDX* data)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingEGLMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingEGLMNDX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["getProcAddress"], to_hex_variable_width(meta_struct.getProcAddress));
        jdata["display"] = meta_struct.display;
        jdata["config"] = meta_struct.config;
        jdata["context"] = meta_struct.context;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["nodeType"] = decoded_value.nodeType;
        FieldToJson(jdata["nodeId"], &meta_struct.nodeId);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphStaticNodeBindingCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeBindingPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["nodeId"], &meta_struct.nodeId);
        FieldToJson(jdata["poseInNodeSpace"], meta_struct.poseInNodeSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingPropertiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemHandTrackingPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHandTrackingPropertiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsHandTracking"] = static_cast<bool>(decoded_value.supportsHandTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackerCreateInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackerCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackerCreateInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["hand"] = decoded_value.hand;
        jdata["handJointSet"] = decoded_value.handJointSet;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsLocateInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointsLocateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointsLocateInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointLocationEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointLocationEXT& meta_struct = *data;

        jdata["locationFlags"] = XrSpaceLocationFlags_t{decoded_value.locationFlags};
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["radius"], decoded_value.radius);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocityEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointVelocityEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointVelocityEXT& meta_struct = *data;

        jdata["velocityFlags"] = XrSpaceVelocityFlags_t{decoded_value.velocityFlags};
        FieldToJson(jdata["linearVelocity"], meta_struct.linearVelocity);
        FieldToJson(jdata["angularVelocity"], meta_struct.angularVelocity);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationsEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointLocationsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointLocationsEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["jointCount"] = decoded_value.jointCount;
        FieldToJson(jdata["jointLocations"], meta_struct.jointLocations);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocitiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointVelocitiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointVelocitiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["jointCount"] = decoded_value.jointCount;
        FieldToJson(jdata["jointVelocities"], meta_struct.jointVelocities);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingMeshPropertiesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemHandTrackingMeshPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHandTrackingMeshPropertiesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsHandTrackingMesh"] = static_cast<bool>(decoded_value.supportsHandTrackingMesh);
        jdata["maxHandMeshIndexCount"] = decoded_value.maxHandMeshIndexCount;
        jdata["maxHandMeshVertexCount"] = decoded_value.maxHandMeshVertexCount;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshSpaceCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshSpaceCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["handPoseType"] = decoded_value.handPoseType;
        FieldToJson(jdata["poseInHandMeshSpace"], meta_struct.poseInHandMeshSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshUpdateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshUpdateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshUpdateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["time"] = decoded_value.time;
        jdata["handPoseType"] = decoded_value.handPoseType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshIndexBufferMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshIndexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshIndexBufferMSFT& meta_struct = *data;

        jdata["indexBufferKey"] = decoded_value.indexBufferKey;
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshVertexMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshVertexMSFT& meta_struct = *data;

        FieldToJson(jdata["position"], meta_struct.position);
        FieldToJson(jdata["normal"], meta_struct.normal);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexBufferMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshVertexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshVertexBufferMSFT& meta_struct = *data;

        jdata["vertexUpdateTime"] = decoded_value.vertexUpdateTime;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["indexBufferChanged"] = static_cast<bool>(decoded_value.indexBufferChanged);
        jdata["vertexBufferChanged"] = static_cast<bool>(decoded_value.vertexBufferChanged);
        FieldToJson(jdata["indexBuffer"], meta_struct.indexBuffer);
        FieldToJson(jdata["vertexBuffer"], meta_struct.vertexBuffer);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandPoseTypeInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandPoseTypeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandPoseTypeInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["handPoseType"] = decoded_value.handPoseType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationSessionBeginInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationCount"] = decoded_value.viewConfigurationCount;
        FieldToJson(jdata["enabledViewConfigurationTypes"], meta_struct.enabledViewConfigurationTypes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationStateMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationStateMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        jdata["active"] = static_cast<bool>(decoded_value.active);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameStateMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationFrameStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationFrameStateMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationCount"] = decoded_value.viewConfigurationCount;
        FieldToJson(jdata["viewConfigurationStates"], meta_struct.viewConfigurationStates);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationLayerInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        jdata["environmentBlendMode"] = decoded_value.environmentBlendMode;
        jdata["layerCount"] = decoded_value.layerCount;
        FieldToJson(jdata["layers"], meta_struct.layers);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationFrameEndInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationCount"] = decoded_value.viewConfigurationCount;
        FieldToJson(jdata["viewConfigurationLayersInfo"], meta_struct.viewConfigurationLayersInfo);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["viewConfigurationType"] = decoded_value.viewConfigurationType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelKeyStateMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelKeyStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelKeyStateMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["modelKey"], meta_struct.modelKey);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodePropertiesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelNodePropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelNodePropertiesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["parentNodeName"], &meta_struct.parentNodeName);
        FieldToJson(jdata["nodeName"], &meta_struct.nodeName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelPropertiesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelPropertiesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["nodeCapacityInput"] = decoded_value.nodeCapacityInput;
        jdata["nodeCountOutput"] = decoded_value.nodeCountOutput;
        FieldToJson(jdata["nodeProperties"], meta_struct.nodeProperties);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodeStateMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelNodeStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelNodeStateMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["nodePose"], meta_struct.nodePose);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelStateMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelStateMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["nodeCapacityInput"] = decoded_value.nodeCapacityInput;
        jdata["nodeCountOutput"] = decoded_value.nodeCountOutput;
        FieldToJson(jdata["nodeStates"], meta_struct.nodeStates);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationViewFovEPIC* data)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationViewFovEPIC& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationViewFovEPIC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["recommendedFov"], meta_struct.recommendedFov);
        FieldToJson(jdata["maxMutableFov"], meta_struct.maxMutableFov);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHolographicWindowAttachmentMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrHolographicWindowAttachmentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHolographicWindowAttachmentMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["holographicSpace"] = meta_struct.holographicSpace;
        jdata["coreWindow"] = meta_struct.coreWindow;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerReprojectionInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerReprojectionInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["reprojectionMode"] = decoded_value.reprojectionMode;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerReprojectionPlaneOverrideMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["position"], meta_struct.position);
        FieldToJson(jdata["normal"], meta_struct.normal);
        FieldToJson(jdata["velocity"], meta_struct.velocity);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrAndroidSurfaceSwapchainCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrAndroidSurfaceSwapchainFlagsFB_t{decoded_value.createFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateBaseHeaderFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateBaseHeaderFB& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateFoveationFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateSamplerOpenGLESFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateSamplerVulkanFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSecureContentFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSecureContentFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSecureContentFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrCompositionLayerSecureContentFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointLocationFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointLocationFB& meta_struct = *data;

        jdata["locationFlags"] = XrSpaceLocationFlags_t{decoded_value.locationFlags};
        FieldToJson(jdata["pose"], meta_struct.pose);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemBodyTrackingPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemBodyTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemBodyTrackingPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsBodyTracking"] = static_cast<bool>(decoded_value.supportsBodyTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyTrackerCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodyTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyTrackerCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["bodyJointSet"] = decoded_value.bodyJointSet;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonJointFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodySkeletonJointFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodySkeletonJointFB& meta_struct = *data;

        jdata["joint"] = decoded_value.joint;
        jdata["parentJoint"] = decoded_value.parentJoint;
        FieldToJson(jdata["pose"], meta_struct.pose);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodySkeletonFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodySkeletonFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["jointCount"] = decoded_value.jointCount;
        FieldToJson(jdata["joints"], meta_struct.joints);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointsLocateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointsLocateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointsLocateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointLocationsFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointLocationsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["confidence"], decoded_value.confidence);
        jdata["jointCount"] = decoded_value.jointCount;
        FieldToJson(jdata["jointLocations"], meta_struct.jointLocations);
        jdata["skeletonChangedCount"] = decoded_value.skeletonChangedCount;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileDpadBindingEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileDpadBindingEXT& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileDpadBindingEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["binding"], meta_struct.binding);
        HandleToJson(jdata["actionSet"], meta_struct.actionSet);
        FieldToJson(jdata["forceThreshold"], decoded_value.forceThreshold);
        FieldToJson(jdata["forceThresholdReleased"], decoded_value.forceThresholdReleased);
        FieldToJson(jdata["centerRegion"], decoded_value.centerRegion);
        FieldToJson(jdata["wedgeAngle"], decoded_value.wedgeAngle);
        jdata["isSticky"] = static_cast<bool>(decoded_value.isSticky);
        FieldToJson(jdata["onHaptic"], meta_struct.onHaptic);
        FieldToJson(jdata["offHaptic"], meta_struct.offHaptic);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileAnalogThresholdVALVE* data)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileAnalogThresholdVALVE& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileAnalogThresholdVALVE& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["action"], meta_struct.action);
        HandleToJson(jdata["binding"], meta_struct.binding);
        FieldToJson(jdata["onThreshold"], decoded_value.onThreshold);
        FieldToJson(jdata["offThreshold"], decoded_value.offThreshold);
        FieldToJson(jdata["onHaptic"], meta_struct.onHaptic);
        FieldToJson(jdata["offHaptic"], meta_struct.offHaptic);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsMotionRangeInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandJointsMotionRangeInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointsMotionRangeInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["handJointsMotionRange"] = decoded_value.handJointsMotionRange;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrUuidMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrUuidMSFT& meta_struct = *data;

        FieldToJson(jdata["bytes"], &meta_struct.bytes);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObserverCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneObserverCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObserverCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneSphereBoundMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneSphereBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneSphereBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["center"], meta_struct.center);
        FieldToJson(jdata["radius"], decoded_value.radius);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneOrientedBoxBoundMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneOrientedBoxBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneOrientedBoxBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["extents"], meta_struct.extents);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneFrustumBoundMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneFrustumBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneFrustumBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["farDistance"], decoded_value.farDistance);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneBoundsMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneBoundsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneBoundsMSFT& meta_struct = *data;

        HandleToJson(jdata["space"], meta_struct.space);
        jdata["time"] = decoded_value.time;
        jdata["sphereCount"] = decoded_value.sphereCount;
        FieldToJson(jdata["spheres"], meta_struct.spheres);
        jdata["boxCount"] = decoded_value.boxCount;
        FieldToJson(jdata["boxes"], meta_struct.boxes);
        jdata["frustumCount"] = decoded_value.frustumCount;
        FieldToJson(jdata["frustums"], meta_struct.frustums);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNewSceneComputeInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrNewSceneComputeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrNewSceneComputeInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["requestedFeatureCount"] = decoded_value.requestedFeatureCount;
        FieldToJson(jdata["requestedFeatures"], meta_struct.requestedFeatures);
        jdata["consistency"] = decoded_value.consistency;
        FieldToJson(jdata["bounds"], meta_struct.bounds);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisualMeshComputeLodInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrVisualMeshComputeLodInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrVisualMeshComputeLodInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["lod"] = decoded_value.lod;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentMSFT& meta_struct = *data;

        jdata["componentType"] = decoded_value.componentType;
        FieldToJson(jdata["id"], meta_struct.id);
        FieldToJson(jdata["parentId"], meta_struct.parentId);
        jdata["updateTime"] = decoded_value.updateTime;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["componentCapacityInput"] = decoded_value.componentCapacityInput;
        jdata["componentCountOutput"] = decoded_value.componentCountOutput;
        FieldToJson(jdata["components"], meta_struct.components);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsGetInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsGetInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["componentType"] = decoded_value.componentType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentLocationMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentLocationMSFT& meta_struct = *data;

        jdata["flags"] = XrSpaceLocationFlags_t{decoded_value.flags};
        FieldToJson(jdata["pose"], meta_struct.pose);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationsMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentLocationsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentLocationsMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationCount"] = decoded_value.locationCount;
        FieldToJson(jdata["locations"], meta_struct.locations);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsLocateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsLocateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsLocateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        jdata["componentIdCount"] = decoded_value.componentIdCount;
        FieldToJson(jdata["componentIds"], meta_struct.componentIds);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectMSFT& meta_struct = *data;

        jdata["objectType"] = decoded_value.objectType;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectsMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectsMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["sceneObjectCount"] = decoded_value.sceneObjectCount;
        FieldToJson(jdata["sceneObjects"], meta_struct.sceneObjects);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentParentFilterInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentParentFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentParentFilterInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["parentId"], meta_struct.parentId);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectTypesFilterInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectTypesFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectTypesFilterInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["objectTypeCount"] = decoded_value.objectTypeCount;
        FieldToJson(jdata["objectTypes"], meta_struct.objectTypes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrScenePlaneMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlaneMSFT& meta_struct = *data;

        jdata["alignment"] = decoded_value.alignment;
        FieldToJson(jdata["size"], meta_struct.size);
        jdata["meshBufferId"] = decoded_value.meshBufferId;
        jdata["supportsIndicesUint16"] = static_cast<bool>(decoded_value.supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlanesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrScenePlanesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlanesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["scenePlaneCount"] = decoded_value.scenePlaneCount;
        FieldToJson(jdata["scenePlanes"], meta_struct.scenePlanes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneAlignmentFilterInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrScenePlaneAlignmentFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlaneAlignmentFilterInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["alignmentCount"] = decoded_value.alignmentCount;
        FieldToJson(jdata["alignments"], meta_struct.alignments);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshMSFT& meta_struct = *data;

        jdata["meshBufferId"] = decoded_value.meshBufferId;
        jdata["supportsIndicesUint16"] = static_cast<bool>(decoded_value.supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["sceneMeshCount"] = decoded_value.sceneMeshCount;
        FieldToJson(jdata["sceneMeshes"], meta_struct.sceneMeshes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersGetInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshBuffersGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshBuffersGetInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["meshBufferId"] = decoded_value.meshBufferId;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshBuffersMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshBuffersMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshVertexBufferMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshVertexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshVertexBufferMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint32MSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshIndicesUint32MSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshIndicesUint32MSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint16MSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshIndicesUint16MSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshIndicesUint16MSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSerializedSceneFragmentDataGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["sceneFragmentId"], meta_struct.sceneFragmentId);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDeserializeSceneFragmentMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrDeserializeSceneFragmentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrDeserializeSceneFragmentMSFT& meta_struct = *data;

        jdata["bufferSize"] = decoded_value.bufferSize;
        FieldToJson(jdata["buffer"], meta_struct.buffer);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneDeserializeInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneDeserializeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneDeserializeInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["fragmentCount"] = decoded_value.fragmentCount;
        FieldToJson(jdata["fragments"], meta_struct.fragments);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataDisplayRefreshRateChangedFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataDisplayRefreshRateChangedFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataDisplayRefreshRateChangedFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["fromDisplayRefreshRate"], decoded_value.fromDisplayRefreshRate);
        FieldToJson(jdata["toDisplayRefreshRate"], decoded_value.toDisplayRefreshRate);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViveTrackerPathsHTCX* data)
{
    if (data && data->decoded_value)
    {
        const XrViveTrackerPathsHTCX& decoded_value = *data->decoded_value;
        const Decoded_XrViveTrackerPathsHTCX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["persistentPath"], meta_struct.persistentPath);
        HandleToJson(jdata["rolePath"], meta_struct.rolePath);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataViveTrackerConnectedHTCX* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataViveTrackerConnectedHTCX& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataViveTrackerConnectedHTCX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["paths"], meta_struct.paths);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFacialTrackingPropertiesHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemFacialTrackingPropertiesHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFacialTrackingPropertiesHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportEyeFacialTracking"] = static_cast<bool>(decoded_value.supportEyeFacialTracking);
        jdata["supportLipFacialTracking"] = static_cast<bool>(decoded_value.supportLipFacialTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialExpressionsHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFacialExpressionsHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFacialExpressionsHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["sampleTime"] = decoded_value.sampleTime;
        jdata["expressionCount"] = decoded_value.expressionCount;
        FieldToJson(jdata["expressionWeightings"], meta_struct.expressionWeightings);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialTrackerCreateInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFacialTrackerCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFacialTrackerCreateInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["facialTrackingType"] = decoded_value.facialTrackingType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemColorSpacePropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemColorSpacePropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemColorSpacePropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["colorSpace"] = decoded_value.colorSpace;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4sFB* data)
{
    if (data && data->decoded_value)
    {
        const XrVector4sFB& decoded_value = *data->decoded_value;
        const Decoded_XrVector4sFB& meta_struct = *data;

        jdata["x"] = decoded_value.x;
        jdata["y"] = decoded_value.y;
        jdata["z"] = decoded_value.z;
        jdata["w"] = decoded_value.w;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingMeshFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingMeshFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingMeshFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["jointCapacityInput"] = decoded_value.jointCapacityInput;
        jdata["jointCountOutput"] = decoded_value.jointCountOutput;
        FieldToJson(jdata["jointBindPoses"], meta_struct.jointBindPoses);
        FieldToJson(jdata["jointRadii"], meta_struct.jointRadii);
        FieldToJson(jdata["jointParents"], meta_struct.jointParents);
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertexPositions"], meta_struct.vertexPositions);
        FieldToJson(jdata["vertexNormals"], meta_struct.vertexNormals);
        FieldToJson(jdata["vertexUVs"], meta_struct.vertexUVs);
        FieldToJson(jdata["vertexBlendIndices"], meta_struct.vertexBlendIndices);
        FieldToJson(jdata["vertexBlendWeights"], meta_struct.vertexBlendWeights);
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingScaleFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingScaleFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingScaleFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["sensorOutput"], decoded_value.sensorOutput);
        FieldToJson(jdata["currentOutput"], decoded_value.currentOutput);
        jdata["overrideHandScale"] = static_cast<bool>(decoded_value.overrideHandScale);
        FieldToJson(jdata["overrideValueInput"], decoded_value.overrideValueInput);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingAimStateFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingAimStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingAimStateFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["status"] = XrHandTrackingAimFlagsFB_t{decoded_value.status};
        FieldToJson(jdata["aimPose"], meta_struct.aimPose);
        FieldToJson(jdata["pinchStrengthIndex"], decoded_value.pinchStrengthIndex);
        FieldToJson(jdata["pinchStrengthMiddle"], decoded_value.pinchStrengthMiddle);
        FieldToJson(jdata["pinchStrengthRing"], decoded_value.pinchStrengthRing);
        FieldToJson(jdata["pinchStrengthLittle"], decoded_value.pinchStrengthLittle);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandCapsuleFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHandCapsuleFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandCapsuleFB& meta_struct = *data;

        FieldToJson(jdata["points"], meta_struct.points);
        FieldToJson(jdata["radius"], decoded_value.radius);
        jdata["joint"] = decoded_value.joint;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingCapsulesStateFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingCapsulesStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingCapsulesStateFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["capsules"], meta_struct.capsules);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpatialEntityPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemSpatialEntityPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemSpatialEntityPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsSpatialEntity"] = static_cast<bool>(decoded_value.supportsSpatialEntity);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusSetInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentStatusSetInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentStatusSetInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["componentType"] = decoded_value.componentType;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        jdata["timeout"] = decoded_value.timeout;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentStatusFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentStatusFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        jdata["changePending"] = static_cast<bool>(decoded_value.changePending);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpatialAnchorCreateCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpatialAnchorCreateCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpatialAnchorCreateCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["uuid"], meta_struct.uuid);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSetStatusCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceSetStatusCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceSetStatusCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["uuid"], meta_struct.uuid);
        jdata["componentType"] = decoded_value.componentType;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationProfileCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationProfileCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationProfileCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfoFoveationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainCreateInfoFoveationFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainCreateInfoFoveationFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrSwapchainCreateFoveationFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateFoveationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateFoveationFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateFoveationFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrSwapchainStateFoveationFlagsFB_t{decoded_value.flags};
        HandleToJson(jdata["profile"], meta_struct.profile);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationLevelProfileCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationLevelProfileCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationLevelProfileCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["level"] = decoded_value.level;
        FieldToJson(jdata["verticalOffset"], decoded_value.verticalOffset);
        jdata["dynamic"] = decoded_value.dynamic;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemKeyboardTrackingPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemKeyboardTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemKeyboardTrackingPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsKeyboardTracking"] = static_cast<bool>(decoded_value.supportsKeyboardTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingDescriptionFB* data)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardTrackingDescriptionFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardTrackingDescriptionFB& meta_struct = *data;

        jdata["trackedKeyboardId"] = decoded_value.trackedKeyboardId;
        FieldToJson(jdata["size"], meta_struct.size);
        jdata["flags"] = XrKeyboardTrackingFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["name"], &meta_struct.name);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardSpaceCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardSpaceCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardSpaceCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["trackedKeyboardId"] = decoded_value.trackedKeyboardId;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingQueryFB* data)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardTrackingQueryFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardTrackingQueryFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrKeyboardTrackingQueryFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrTriangleMeshCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrTriangleMeshCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrTriangleMeshCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrTriangleMeshFlagsFB_t{decoded_value.flags};
        jdata["windingOrder"] = decoded_value.windingOrder;
        jdata["vertexCount"] = decoded_value.vertexCount;
        FieldToJson(jdata["vertexBuffer"], meta_struct.vertexBuffer);
        jdata["triangleCount"] = decoded_value.triangleCount;
        FieldToJson(jdata["indexBuffer"], meta_struct.indexBuffer);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsPassthrough"] = static_cast<bool>(decoded_value.supportsPassthrough);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughProperties2FB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughProperties2FB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughProperties2FB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["capabilities"] = XrPassthroughCapabilityFlagsFB_t{decoded_value.capabilities};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrPassthroughFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughLayerCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughLayerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughLayerCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["passthrough"], meta_struct.passthrough);
        jdata["flags"] = XrPassthroughFlagsFB_t{decoded_value.flags};
        jdata["purpose"] = decoded_value.purpose;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerPassthroughFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerPassthroughFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrCompositionLayerFlags_t{decoded_value.flags};
        HandleToJson(jdata["space"], meta_struct.space);
        HandleToJson(jdata["layerHandle"], meta_struct.layerHandle);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrGeometryInstanceCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrGeometryInstanceCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["layer"], meta_struct.layer);
        HandleToJson(jdata["mesh"], meta_struct.mesh);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["scale"], meta_struct.scale);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceTransformFB* data)
{
    if (data && data->decoded_value)
    {
        const XrGeometryInstanceTransformFB& decoded_value = *data->decoded_value;
        const Decoded_XrGeometryInstanceTransformFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["scale"], meta_struct.scale);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughStyleFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughStyleFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughStyleFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["textureOpacityFactor"], decoded_value.textureOpacityFactor);
        FieldToJson(jdata["edgeColor"], meta_struct.edgeColor);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToRgbaFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapMonoToRgbaFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapMonoToRgbaFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["textureColorMap"], meta_struct.textureColorMap);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToMonoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapMonoToMonoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapMonoToMonoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["textureColorMap"], &meta_struct.textureColorMap);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughBrightnessContrastSaturationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughBrightnessContrastSaturationFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughBrightnessContrastSaturationFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["brightness"], decoded_value.brightness);
        FieldToJson(jdata["contrast"], decoded_value.contrast);
        FieldToJson(jdata["saturation"], decoded_value.saturation);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPassthroughStateChangedFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataPassthroughStateChangedFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataPassthroughStateChangedFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrPassthroughStateChangedFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPathInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelPathInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelPathInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["path"], meta_struct.path);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vendorId"] = decoded_value.vendorId;
        FieldToJson(jdata["modelName"], &meta_struct.modelName);
        HandleToJson(jdata["modelKey"], meta_struct.modelKey);
        jdata["modelVersion"] = decoded_value.modelVersion;
        jdata["flags"] = XrRenderModelFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelBufferFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelBufferFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelBufferFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["bufferCapacityInput"] = decoded_value.bufferCapacityInput;
        jdata["bufferCountOutput"] = decoded_value.bufferCountOutput;
        FieldToJson(jdata["buffer"], meta_struct.buffer);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelLoadInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelLoadInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelLoadInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["modelKey"], meta_struct.modelKey);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemRenderModelPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemRenderModelPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemRenderModelPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsRenderModelLoading"] = static_cast<bool>(decoded_value.supportsRenderModelLoading);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelCapabilitiesRequestFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelCapabilitiesRequestFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelCapabilitiesRequestFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrRenderModelFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateFoveatedRenderingVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrViewLocateFoveatedRenderingVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrViewLocateFoveatedRenderingVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["foveatedRenderingActive"] = static_cast<bool>(decoded_value.foveatedRenderingActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveatedViewConfigurationViewVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveatedViewConfigurationViewVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrFoveatedViewConfigurationViewVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["foveatedRenderingActive"] = static_cast<bool>(decoded_value.foveatedRenderingActive);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveatedRenderingPropertiesVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemFoveatedRenderingPropertiesVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFoveatedRenderingPropertiesVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsFoveatedRendering"] = static_cast<bool>(decoded_value.supportsFoveatedRendering);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthTestVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthTestVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["depthTestRangeNearZ"], decoded_value.depthTestRangeNearZ);
        FieldToJson(jdata["depthTestRangeFarZ"], decoded_value.depthTestRangeFarZ);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerTrackingPropertiesVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemMarkerTrackingPropertiesVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrSystemMarkerTrackingPropertiesVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsMarkerTracking"] = static_cast<bool>(decoded_value.supportsMarkerTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMarkerTrackingUpdateVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataMarkerTrackingUpdateVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataMarkerTrackingUpdateVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["markerId"] = decoded_value.markerId;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["isPredicted"] = static_cast<bool>(decoded_value.isPredicted);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoVARJO* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerSpaceCreateInfoVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerSpaceCreateInfoVARJO& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["markerId"] = decoded_value.markerId;
        FieldToJson(jdata["poseInMarkerSpace"], meta_struct.poseInMarkerSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrFrameEndInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrFrameEndInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["focusDistance"], decoded_value.focusDistance);
        jdata["flags"] = XrFrameEndInfoFlagsML_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGlobalDimmerFrameEndInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrGlobalDimmerFrameEndInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrGlobalDimmerFrameEndInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["dimmerValue"], decoded_value.dimmerValue);
        jdata["flags"] = XrGlobalDimmerFrameEndInfoFlagsML_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCoordinateSpaceCreateInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrCoordinateSpaceCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrCoordinateSpaceCreateInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["cfuid"], decoded_value.cfuid);
        FieldToJson(jdata["poseInCoordinateSpace"], meta_struct.poseInCoordinateSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerUnderstandingPropertiesML* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemMarkerUnderstandingPropertiesML& decoded_value = *data->decoded_value;
        const Decoded_XrSystemMarkerUnderstandingPropertiesML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsMarkerUnderstanding"] = static_cast<bool>(decoded_value.supportsMarkerUnderstanding);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCreateInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorCreateInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["profile"] = decoded_value.profile;
        jdata["markerType"] = decoded_value.markerType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorArucoInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorArucoInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorArucoInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["arucoDict"] = decoded_value.arucoDict;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSizeInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorSizeInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorSizeInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["markerLength"], decoded_value.markerLength);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorAprilTagInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorAprilTagInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorAprilTagInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["aprilTagDict"] = decoded_value.aprilTagDict;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCustomProfileInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorCustomProfileInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorCustomProfileInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["fpsHint"] = decoded_value.fpsHint;
        jdata["resolutionHint"] = decoded_value.resolutionHint;
        jdata["cameraHint"] = decoded_value.cameraHint;
        jdata["cornerRefineMethod"] = decoded_value.cornerRefineMethod;
        jdata["useEdgeRefinement"] = static_cast<bool>(decoded_value.useEdgeRefinement);
        jdata["fullAnalysisIntervalHint"] = decoded_value.fullAnalysisIntervalHint;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSnapshotInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorSnapshotInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorSnapshotInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorStateML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorStateML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorStateML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["state"] = decoded_value.state;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMarkerSpaceCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerSpaceCreateInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["markerDetector"], meta_struct.markerDetector);
        HandleToJson(jdata["marker"], meta_struct.marker);
        FieldToJson(jdata["poseInMarkerSpace"], meta_struct.poseInMarkerSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapML* data)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["name"], &meta_struct.name);
        FieldToJson(jdata["mapUuid"], meta_struct.mapUuid);
        jdata["mapType"] = decoded_value.mapType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataLocalizationChangedML* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataLocalizationChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataLocalizationChangedML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        jdata["state"] = decoded_value.state;
        FieldToJson(jdata["map"], meta_struct.map);
        jdata["confidence"] = decoded_value.confidence;
        jdata["errorFlags"] = XrLocalizationMapErrorFlagsML_t{decoded_value.errorFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapQueryInfoBaseHeaderML* data)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapQueryInfoBaseHeaderML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapQueryInfoBaseHeaderML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMapLocalizationRequestInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrMapLocalizationRequestInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMapLocalizationRequestInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["mapUuid"], meta_struct.mapUuid);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapImportInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapImportInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapImportInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["size"] = decoded_value.size;
        FieldToJson(jdata["data"], &meta_struct.data);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationEnableEventsInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationEnableEventsInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationEnableEventsInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceNameMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorPersistenceNameMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorPersistenceNameMSFT& meta_struct = *data;

        FieldToJson(jdata["name"], &meta_struct.name);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorPersistenceInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorPersistenceInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["spatialAnchorPersistenceName"], meta_struct.spatialAnchorPersistenceName);
        HandleToJson(jdata["spatialAnchor"], meta_struct.spatialAnchor);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["spatialAnchorStore"], meta_struct.spatialAnchorStore);
        FieldToJson(jdata["spatialAnchorPersistenceName"], meta_struct.spatialAnchorPersistenceName);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerMSFT& meta_struct = *data;

        jdata["markerType"] = decoded_value.markerType;
        jdata["lastSeenTime"] = decoded_value.lastSeenTime;
        FieldToJson(jdata["center"], meta_struct.center);
        FieldToJson(jdata["size"], meta_struct.size);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkersMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkersMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkersMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["sceneMarkerCapacityInput"] = decoded_value.sceneMarkerCapacityInput;
        FieldToJson(jdata["sceneMarkers"], meta_struct.sceneMarkers);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerTypeFilterMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerTypeFilterMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerTypeFilterMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["markerTypeCount"] = decoded_value.markerTypeCount;
        FieldToJson(jdata["markerTypes"], meta_struct.markerTypes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodeMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerQRCodeMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerQRCodeMSFT& meta_struct = *data;

        jdata["symbolType"] = decoded_value.symbolType;
        jdata["version"] = decoded_value.version;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodesMSFT* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerQRCodesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerQRCodesMSFT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["qrCodeCapacityInput"] = decoded_value.qrCodeCapacityInput;
        FieldToJson(jdata["qrCodes"], meta_struct.qrCodes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoBaseHeaderFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryInfoBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryInfoBaseHeaderFB& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SPACE_QUERY_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceQueryInfoFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceFilterInfoBaseHeaderFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceFilterInfoBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceFilterInfoBaseHeaderFB& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceUuidFilterInfoFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceComponentFilterInfoFB*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["queryAction"] = decoded_value.queryAction;
        jdata["maxResultCount"] = decoded_value.maxResultCount;
        jdata["timeout"] = decoded_value.timeout;
        FieldToJson(jdata["filter"], meta_struct.filter);
        FieldToJson(jdata["excludeFilter"], meta_struct.excludeFilter);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceStorageLocationFilterInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceStorageLocationFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceStorageLocationFilterInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUuidFilterInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceUuidFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceUuidFilterInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["uuidCount"] = decoded_value.uuidCount;
        FieldToJson(jdata["uuids"], meta_struct.uuids);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentFilterInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentFilterInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["componentType"] = decoded_value.componentType;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryResultFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryResultFB& meta_struct = *data;

        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["uuid"], meta_struct.uuid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryResultsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryResultsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["resultCapacityInput"] = decoded_value.resultCapacityInput;
        jdata["resultCountOutput"] = decoded_value.resultCountOutput;
        FieldToJson(jdata["results"], meta_struct.results);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryResultsAvailableFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceQueryResultsAvailableFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceQueryResultsAvailableFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceQueryCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceQueryCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceSaveInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceSaveInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceSaveInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["location"] = decoded_value.location;
        jdata["persistenceMode"] = decoded_value.persistenceMode;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceEraseInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceEraseInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceEraseInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSaveCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceSaveCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceSaveCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["uuid"], meta_struct.uuid);
        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceEraseCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceEraseCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceEraseCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["uuid"], meta_struct.uuid);
        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageFoveationVulkanFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageFoveationVulkanFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageFoveationVulkanFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["image"], meta_struct.image);
        jdata["width"] = decoded_value.width;
        jdata["height"] = decoded_value.height;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateAndroidSurfaceDimensionsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["width"] = decoded_value.width;
        jdata["height"] = decoded_value.height;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerOpenGLESFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateSamplerOpenGLESFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateSamplerOpenGLESFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["minFilter"] = decoded_value.minFilter;
        jdata["magFilter"] = decoded_value.magFilter;
        jdata["wrapModeS"] = decoded_value.wrapModeS;
        jdata["wrapModeT"] = decoded_value.wrapModeT;
        jdata["swizzleRed"] = decoded_value.swizzleRed;
        jdata["swizzleGreen"] = decoded_value.swizzleGreen;
        jdata["swizzleBlue"] = decoded_value.swizzleBlue;
        jdata["swizzleAlpha"] = decoded_value.swizzleAlpha;
        FieldToJson(jdata["maxAnisotropy"], decoded_value.maxAnisotropy);
        FieldToJson(jdata["borderColor"], meta_struct.borderColor);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerVulkanFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateSamplerVulkanFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateSamplerVulkanFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["minFilter"] = decoded_value.minFilter;
        jdata["magFilter"] = decoded_value.magFilter;
        jdata["mipmapMode"] = decoded_value.mipmapMode;
        jdata["wrapModeS"] = decoded_value.wrapModeS;
        jdata["wrapModeT"] = decoded_value.wrapModeT;
        jdata["swizzleRed"] = decoded_value.swizzleRed;
        jdata["swizzleGreen"] = decoded_value.swizzleGreen;
        jdata["swizzleBlue"] = decoded_value.swizzleBlue;
        jdata["swizzleAlpha"] = decoded_value.swizzleAlpha;
        FieldToJson(jdata["maxAnisotropy"], decoded_value.maxAnisotropy);
        FieldToJson(jdata["borderColor"], meta_struct.borderColor);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceShareInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceShareInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceShareInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["spaceCount"] = decoded_value.spaceCount;
        HandleToJson(jdata["spaces"], &meta_struct.spaces);
        jdata["userCount"] = decoded_value.userCount;
        HandleToJson(jdata["users"], &meta_struct.users);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceShareCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceShareCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceShareCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSpaceWarpInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSpaceWarpInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSpaceWarpInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerSpaceWarpInfoFlagsFB_t{decoded_value.layerFlags};
        FieldToJson(jdata["motionVectorSubImage"], meta_struct.motionVectorSubImage);
        FieldToJson(jdata["appSpaceDeltaPose"], meta_struct.appSpaceDeltaPose);
        FieldToJson(jdata["depthSubImage"], meta_struct.depthSubImage);
        FieldToJson(jdata["minDepth"], decoded_value.minDepth);
        FieldToJson(jdata["maxDepth"], decoded_value.maxDepth);
        FieldToJson(jdata["nearZ"], decoded_value.nearZ);
        FieldToJson(jdata["farZ"], decoded_value.farZ);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpaceWarpPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemSpaceWarpPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemSpaceWarpPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["recommendedMotionVectorImageRectWidth"] = decoded_value.recommendedMotionVectorImageRectWidth;
        jdata["recommendedMotionVectorImageRectHeight"] = decoded_value.recommendedMotionVectorImageRectHeight;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticAmplitudeEnvelopeVibrationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHapticAmplitudeEnvelopeVibrationFB& decoded_value = *data->decoded_value;
        const Decoded_XrHapticAmplitudeEnvelopeVibrationFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["duration"] = decoded_value.duration;
        jdata["amplitudeCount"] = decoded_value.amplitudeCount;
        FieldToJson(jdata["amplitudes"], meta_struct.amplitudes);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset3DfFB* data)
{
    if (data && data->decoded_value)
    {
        const XrOffset3DfFB& decoded_value = *data->decoded_value;
        const Decoded_XrOffset3DfFB& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x);
        FieldToJson(jdata["y"], decoded_value.y);
        FieldToJson(jdata["z"], decoded_value.z);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect3DfFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRect3DfFB& decoded_value = *data->decoded_value;
        const Decoded_XrRect3DfFB& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset);
        FieldToJson(jdata["extent"], meta_struct.extent);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSemanticLabelsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSemanticLabelsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["bufferCapacityInput"] = decoded_value.bufferCapacityInput;
        jdata["bufferCountOutput"] = decoded_value.bufferCountOutput;
        FieldToJson(jdata["buffer"], &meta_struct.buffer);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRoomLayoutFB* data)
{
    if (data && data->decoded_value)
    {
        const XrRoomLayoutFB& decoded_value = *data->decoded_value;
        const Decoded_XrRoomLayoutFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["floorUuid"], meta_struct.floorUuid);
        FieldToJson(jdata["ceilingUuid"], meta_struct.ceilingUuid);
        jdata["wallUuidCapacityInput"] = decoded_value.wallUuidCapacityInput;
        jdata["wallUuidCountOutput"] = decoded_value.wallUuidCountOutput;
        FieldToJson(jdata["wallUuids"], meta_struct.wallUuids);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundary2DFB* data)
{
    if (data && data->decoded_value)
    {
        const XrBoundary2DFB& decoded_value = *data->decoded_value;
        const Decoded_XrBoundary2DFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsSupportInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSemanticLabelsSupportInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSemanticLabelsSupportInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrSemanticLabelsSupportFlagsFB_t{decoded_value.flags};
        FieldToJson(jdata["recognizedLabels"], &meta_struct.recognizedLabels);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDigitalLensControlALMALENCE* data)
{
    if (data && data->decoded_value)
    {
        const XrDigitalLensControlALMALENCE& decoded_value = *data->decoded_value;
        const Decoded_XrDigitalLensControlALMALENCE& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrDigitalLensControlFlagsALMALENCE_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSceneCaptureCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSceneCaptureCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSceneCaptureCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCaptureRequestInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSceneCaptureRequestInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSceneCaptureRequestInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["requestByteCount"] = decoded_value.requestByteCount;
        FieldToJson(jdata["request"], &meta_struct.request);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceContainerFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceContainerFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceContainerFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["uuidCapacityInput"] = decoded_value.uuidCapacityInput;
        jdata["uuidCountOutput"] = decoded_value.uuidCountOutput;
        FieldToJson(jdata["uuids"], meta_struct.uuids);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationEyeTrackedProfileCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrFoveationEyeTrackedProfileCreateFlagsMETA_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedStateMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationEyeTrackedStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationEyeTrackedStateMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["foveationCenter"], meta_struct.foveationCenter);
        jdata["flags"] = XrFoveationEyeTrackedStateFlagsMETA_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemFoveationEyeTrackedPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsFoveationEyeTracked"] = static_cast<bool>(decoded_value.supportsFoveationEyeTracked);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemFaceTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFaceTrackingPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsFaceTracking"] = static_cast<bool>(decoded_value.supportsFaceTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceTrackerCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["faceExpressionSet"] = decoded_value.faceExpressionSet;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionStatusFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionStatusFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionStatusFB& meta_struct = *data;

        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(decoded_value.isEyeFollowingBlendshapesValid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeightsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionWeightsFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionWeightsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["weightCount"] = decoded_value.weightCount;
        FieldToJson(jdata["weights"], meta_struct.weights);
        jdata["confidenceCount"] = decoded_value.confidenceCount;
        FieldToJson(jdata["confidences"], meta_struct.confidences);
        FieldToJson(jdata["status"], meta_struct.status);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazeFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazeFB& meta_struct = *data;

        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        FieldToJson(jdata["gazePose"], meta_struct.gazePose);
        FieldToJson(jdata["gazeConfidence"], decoded_value.gazeConfidence);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeTrackerCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEyeTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeTrackerCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazesInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazesInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeTrackingPropertiesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemEyeTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemEyeTrackingPropertiesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsEyeTracking"] = static_cast<bool>(decoded_value.supportsEyeTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazesFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazesFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["gaze"], meta_struct.gaze);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughKeyboardHandsIntensityFB* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughKeyboardHandsIntensityFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughKeyboardHandsIntensityFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["leftHandIntensity"], decoded_value.leftHandIntensity);
        FieldToJson(jdata["rightHandIntensity"], decoded_value.rightHandIntensity);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSettingsFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSettingsFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSettingsFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerSettingsFlagsFB_t{decoded_value.layerFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticPcmVibrationFB* data)
{
    if (data && data->decoded_value)
    {
        const XrHapticPcmVibrationFB& decoded_value = *data->decoded_value;
        const Decoded_XrHapticPcmVibrationFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["bufferSize"] = decoded_value.bufferSize;
        FieldToJson(jdata["buffer"], meta_struct.buffer);
        FieldToJson(jdata["sampleRate"], decoded_value.sampleRate);
        jdata["append"] = static_cast<bool>(decoded_value.append);
        FieldToJson(jdata["samplesConsumed"], meta_struct.samplesConsumed);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDevicePcmSampleRateStateFB* data)
{
    if (data && data->decoded_value)
    {
        const XrDevicePcmSampleRateStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrDevicePcmSampleRateStateFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["sampleRate"], decoded_value.sampleRate);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestFB* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthTestFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthTestFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["depthMask"] = static_cast<bool>(decoded_value.depthMask);
        jdata["compareOp"] = decoded_value.compareOp;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalDimmingFrameEndInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrLocalDimmingFrameEndInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrLocalDimmingFrameEndInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["localDimmingMode"] = decoded_value.localDimmingMode;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughPreferencesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughPreferencesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughPreferencesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrPassthroughPreferenceFlagsMETA_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemVirtualKeyboardPropertiesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemVirtualKeyboardPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemVirtualKeyboardPropertiesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsVirtualKeyboard"] = static_cast<bool>(decoded_value.supportsVirtualKeyboard);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardSpaceCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationType"] = decoded_value.locationType;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardLocationInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardLocationInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardLocationInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationType"] = decoded_value.locationType;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace);
        FieldToJson(jdata["scale"], decoded_value.scale);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardModelVisibilitySetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["visible"] = static_cast<bool>(decoded_value.visible);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardAnimationStateMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardAnimationStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardAnimationStateMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["animationIndex"] = decoded_value.animationIndex;
        FieldToJson(jdata["fraction"], decoded_value.fraction);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelAnimationStatesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardModelAnimationStatesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardModelAnimationStatesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["stateCapacityInput"] = decoded_value.stateCapacityInput;
        jdata["stateCountOutput"] = decoded_value.stateCountOutput;
        FieldToJson(jdata["states"], meta_struct.states);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextureDataMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardTextureDataMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardTextureDataMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["textureWidth"] = decoded_value.textureWidth;
        jdata["textureHeight"] = decoded_value.textureHeight;
        jdata["bufferCapacityInput"] = decoded_value.bufferCapacityInput;
        jdata["bufferCountOutput"] = decoded_value.bufferCountOutput;
        FieldToJson(jdata["buffer"], meta_struct.buffer);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardInputInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardInputInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardInputInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["inputSource"] = decoded_value.inputSource;
        HandleToJson(jdata["inputSpace"], meta_struct.inputSpace);
        FieldToJson(jdata["inputPoseInSpace"], meta_struct.inputPoseInSpace);
        jdata["inputState"] = XrVirtualKeyboardInputStateFlagsMETA_t{decoded_value.inputState};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardTextContextChangeInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["textContext"], &meta_struct.textContext);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardCommitTextMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardCommitTextMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardCommitTextMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["keyboard"], meta_struct.keyboard);
        FieldToJson(jdata["text"], &meta_struct.text);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardBackspaceMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardBackspaceMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardBackspaceMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["keyboard"], meta_struct.keyboard);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardEnterMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardEnterMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardEnterMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["keyboard"], meta_struct.keyboard);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardShownMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardShownMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardShownMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["keyboard"], meta_struct.keyboard);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardHiddenMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardHiddenMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardHiddenMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["keyboard"], meta_struct.keyboard);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraIntrinsicsOCULUS* data)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraIntrinsicsOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraIntrinsicsOCULUS& meta_struct = *data;

        jdata["lastChangeTime"] = decoded_value.lastChangeTime;
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["virtualNearPlaneDistance"], decoded_value.virtualNearPlaneDistance);
        FieldToJson(jdata["virtualFarPlaneDistance"], decoded_value.virtualFarPlaneDistance);
        FieldToJson(jdata["imageSensorPixelResolution"], meta_struct.imageSensorPixelResolution);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraExtrinsicsOCULUS* data)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraExtrinsicsOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraExtrinsicsOCULUS& meta_struct = *data;

        jdata["lastChangeTime"] = decoded_value.lastChangeTime;
        jdata["cameraStatusFlags"] = XrExternalCameraStatusFlagsOCULUS_t{decoded_value.cameraStatusFlags};
        jdata["attachedToDevice"] = decoded_value.attachedToDevice;
        FieldToJson(jdata["relativePose"], meta_struct.relativePose);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraOCULUS* data)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraOCULUS& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["name"], &meta_struct.name);
        FieldToJson(jdata["intrinsics"], meta_struct.intrinsics);
        FieldToJson(jdata["extrinsics"], meta_struct.extrinsics);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrVulkanSwapchainCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanSwapchainCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["additionalCreateFlags"] = VkImageCreateFlags_t{decoded_value.additionalCreateFlags};
        jdata["additionalUsageFlags"] = VkImageUsageFlags_t{decoded_value.additionalUsageFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsStateMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPerformanceMetricsStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPerformanceMetricsStateMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsCounterMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPerformanceMetricsCounterMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPerformanceMetricsCounterMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["counterFlags"] = XrPerformanceMetricsCounterFlagsMETA_t{decoded_value.counterFlags};
        jdata["counterUnit"] = decoded_value.counterUnit;
        jdata["uintValue"] = decoded_value.uintValue;
        FieldToJson(jdata["floatValue"], decoded_value.floatValue);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceListSaveInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceListSaveInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceListSaveInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["spaceCount"] = decoded_value.spaceCount;
        HandleToJson(jdata["spaces"], &meta_struct.spaces);
        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceListSaveCompleteFB* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceListSaveCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceListSaveCompleteFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["requestId"], meta_struct.requestId);
        jdata["result"] = decoded_value.result;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUserCreateInfoFB* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceUserCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceUserCreateInfoFB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["userId"] = decoded_value.userId;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHeadsetIdPropertiesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemHeadsetIdPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHeadsetIdPropertiesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["id"], meta_struct.id);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrRecommendedLayerResolutionMETA& decoded_value = *data->decoded_value;
        const Decoded_XrRecommendedLayerResolutionMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["recommendedImageDimensions"], meta_struct.recommendedImageDimensions);
        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionGetInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrRecommendedLayerResolutionGetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrRecommendedLayerResolutionGetInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["layer"], meta_struct.layer);
        jdata["predictedDisplayTime"] = decoded_value.predictedDisplayTime;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutDataMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutDataMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutDataMETA& meta_struct = *data;

        jdata["bufferSize"] = decoded_value.bufferSize;
        FieldToJson(jdata["buffer"], meta_struct.buffer);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["channels"] = decoded_value.channels;
        jdata["resolution"] = decoded_value.resolution;
        FieldToJson(jdata["data"], meta_struct.data);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutUpdateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutUpdateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutUpdateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["data"], meta_struct.data);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapLutMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapLutMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapLutMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["colorLut"], meta_struct.colorLut);
        FieldToJson(jdata["weight"], decoded_value.weight);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapInterpolatedLutMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapInterpolatedLutMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapInterpolatedLutMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["sourceColorLut"], meta_struct.sourceColorLut);
        HandleToJson(jdata["targetColorLut"], meta_struct.targetColorLut);
        FieldToJson(jdata["weight"], decoded_value.weight);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughColorLutPropertiesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughColorLutPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughColorLutPropertiesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["maxColorLutResolution"] = decoded_value.maxColorLutResolution;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshGetInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceTriangleMeshGetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceTriangleMeshGetInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSpaceTriangleMeshMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceTriangleMeshMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        jdata["indexCapacityInput"] = decoded_value.indexCapacityInput;
        jdata["indexCountOutput"] = decoded_value.indexCountOutput;
        FieldToJson(jdata["indices"], meta_struct.indices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingProperties2FB* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemFaceTrackingProperties2FB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFaceTrackingProperties2FB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsVisualFaceTracking"] = static_cast<bool>(decoded_value.supportsVisualFaceTracking);
        jdata["supportsAudioFaceTracking"] = static_cast<bool>(decoded_value.supportsAudioFaceTracking);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfo2FB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceTrackerCreateInfo2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceTrackerCreateInfo2FB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["faceExpressionSet"] = decoded_value.faceExpressionSet;
        jdata["requestedDataSourceCount"] = decoded_value.requestedDataSourceCount;
        FieldToJson(jdata["requestedDataSources"], meta_struct.requestedDataSources);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfo2FB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionInfo2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionInfo2FB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeights2FB* data)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionWeights2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionWeights2FB& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["weightCount"] = decoded_value.weightCount;
        FieldToJson(jdata["weights"], meta_struct.weights);
        jdata["confidenceCount"] = decoded_value.confidenceCount;
        FieldToJson(jdata["confidences"], meta_struct.confidences);
        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(decoded_value.isEyeFollowingBlendshapesValid);
        jdata["dataSource"] = decoded_value.dataSource;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthProviderCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthProviderCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthProviderCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrEnvironmentDepthProviderCreateFlagsMETA_t{decoded_value.createFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthSwapchainCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["createFlags"] = XrEnvironmentDepthSwapchainCreateFlagsMETA_t{decoded_value.createFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainStateMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthSwapchainStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthSwapchainStateMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["width"] = decoded_value.width;
        jdata["height"] = decoded_value.height;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageAcquireInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthImageAcquireInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthImageAcquireInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        jdata["displayTime"] = decoded_value.displayTime;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageViewMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthImageViewMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthImageViewMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["fov"], meta_struct.fov);
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthImageMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthImageMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["swapchainIndex"] = decoded_value.swapchainIndex;
        FieldToJson(jdata["nearZ"], decoded_value.nearZ);
        FieldToJson(jdata["farZ"], decoded_value.farZ);
        FieldToJson(jdata["views"], meta_struct.views);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrEnvironmentDepthHandRemovalSetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEnvironmentDepthPropertiesMETA* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemEnvironmentDepthPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemEnvironmentDepthPropertiesMETA& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsEnvironmentDepth"] = static_cast<bool>(decoded_value.supportsEnvironmentDepth);
        jdata["supportsHandRemoval"] = static_cast<bool>(decoded_value.supportsHandRemoval);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughCreateInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["form"] = decoded_value.form;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        FieldToJson(jdata["alpha"], decoded_value.alpha);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughMeshTransformInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughMeshTransformInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughMeshTransformInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCount"] = decoded_value.vertexCount;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        jdata["indexCount"] = decoded_value.indexCount;
        FieldToJson(jdata["indices"], meta_struct.indices);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["scale"], meta_struct.scale);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerPassthroughHTC& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerPassthroughHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["layerFlags"] = XrCompositionLayerFlags_t{decoded_value.layerFlags};
        HandleToJson(jdata["space"], meta_struct.space);
        HandleToJson(jdata["passthrough"], meta_struct.passthrough);
        FieldToJson(jdata["color"], meta_struct.color);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationApplyInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationApplyInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationApplyInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["mode"] = decoded_value.mode;
        jdata["subImageCount"] = decoded_value.subImageCount;
        FieldToJson(jdata["subImages"], meta_struct.subImages);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationConfigurationHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationConfigurationHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationConfigurationHTC& meta_struct = *data;

        jdata["level"] = decoded_value.level;
        FieldToJson(jdata["clearFovDegree"], decoded_value.clearFovDegree);
        FieldToJson(jdata["focalCenterOffset"], meta_struct.focalCenterOffset);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationDynamicModeInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationDynamicModeInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationDynamicModeInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["dynamicFlags"] = XrFoveationDynamicFlagsHTC_t{decoded_value.dynamicFlags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationCustomModeInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrFoveationCustomModeInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationCustomModeInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["configCount"] = decoded_value.configCount;
        FieldToJson(jdata["configs"], meta_struct.configs);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemAnchorPropertiesHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemAnchorPropertiesHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSystemAnchorPropertiesHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsAnchor"] = static_cast<bool>(decoded_value.supportsAnchor);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorNameHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorNameHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorNameHTC& meta_struct = *data;

        FieldToJson(jdata["name"], &meta_struct.name);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoHTC* data)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoHTC& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["space"], meta_struct.space);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace);
        FieldToJson(jdata["name"], meta_struct.name);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPriorityEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSetPriorityEXT& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSetPriorityEXT& meta_struct = *data;

        HandleToJson(jdata["actionSet"], meta_struct.actionSet);
        jdata["priorityOverride"] = decoded_value.priorityOverride;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPrioritiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSetPrioritiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSetPrioritiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["actionSetPriorityCount"] = decoded_value.actionSetPriorityCount;
        FieldToJson(jdata["actionSetPriorities"], meta_struct.actionSetPriorities);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemForceFeedbackCurlPropertiesMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsForceFeedbackCurl"] = static_cast<bool>(decoded_value.supportsForceFeedbackCurl);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationMNDX* data)
{
    if (data && data->decoded_value)
    {
        const XrForceFeedbackCurlApplyLocationMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrForceFeedbackCurlApplyLocationMNDX& meta_struct = *data;

        jdata["location"] = decoded_value.location;
        FieldToJson(jdata["value"], decoded_value.value);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationsMNDX* data)
{
    if (data && data->decoded_value)
    {
        const XrForceFeedbackCurlApplyLocationsMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrForceFeedbackCurlApplyLocationsMNDX& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["locationCount"] = decoded_value.locationCount;
        FieldToJson(jdata["locations"], meta_struct.locations);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingDataSourceInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingDataSourceInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["requestedDataSourceCount"] = decoded_value.requestedDataSourceCount;
        FieldToJson(jdata["requestedDataSources"], meta_struct.requestedDataSources);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceStateEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingDataSourceStateEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingDataSourceStateEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["dataSource"] = decoded_value.dataSource;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPlaneDetectionPropertiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemPlaneDetectionPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPlaneDetectionPropertiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportedFeatures"] = XrPlaneDetectionCapabilityFlagsEXT_t{decoded_value.supportedFeatures};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorCreateInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorCreateInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["flags"] = XrPlaneDetectorFlagsEXT_t{decoded_value.flags};
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorBeginInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorBeginInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorBeginInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        jdata["orientationCount"] = decoded_value.orientationCount;
        FieldToJson(jdata["orientations"], meta_struct.orientations);
        jdata["semanticTypeCount"] = decoded_value.semanticTypeCount;
        FieldToJson(jdata["semanticTypes"], meta_struct.semanticTypes);
        jdata["maxPlanes"] = decoded_value.maxPlanes;
        FieldToJson(jdata["minArea"], decoded_value.minArea);
        FieldToJson(jdata["boundingBoxPose"], meta_struct.boundingBoxPose);
        FieldToJson(jdata["boundingBoxExtent"], meta_struct.boundingBoxExtent);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorGetInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorGetInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorGetInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace);
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorLocationEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorLocationEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["planeId"] = decoded_value.planeId;
        jdata["locationFlags"] = XrSpaceLocationFlags_t{decoded_value.locationFlags};
        FieldToJson(jdata["pose"], meta_struct.pose);
        FieldToJson(jdata["extents"], meta_struct.extents);
        jdata["orientation"] = decoded_value.orientation;
        jdata["semanticType"] = decoded_value.semanticType;
        jdata["polygonBufferCount"] = decoded_value.polygonBufferCount;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationsEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorLocationsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorLocationsEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["planeLocationCapacityInput"] = decoded_value.planeLocationCapacityInput;
        jdata["planeLocationCountOutput"] = decoded_value.planeLocationCountOutput;
        FieldToJson(jdata["planeLocations"], meta_struct.planeLocations);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorPolygonBufferEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorPolygonBufferEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorPolygonBufferEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["vertexCapacityInput"] = decoded_value.vertexCapacityInput;
        jdata["vertexCountOutput"] = decoded_value.vertexCountOutput;
        FieldToJson(jdata["vertices"], meta_struct.vertices);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCancelInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrFutureCancelInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrFutureCancelInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["future"], meta_struct.future);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollInfoEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrFuturePollInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrFuturePollInfoEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["future"], meta_struct.future);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionBaseHeaderEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrFutureCompletionBaseHeaderEXT& decoded_value = *data->decoded_value;
        const Decoded_XrFutureCompletionBaseHeaderEXT& meta_struct = *data;

        switch (decoded_value.type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_FUTURE_COMPLETION_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrFutureCompletionEXT*>(data));
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        jdata["type"] = decoded_value.type;
        jdata["futureResult"] = decoded_value.futureResult;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrFutureCompletionEXT& decoded_value = *data->decoded_value;
        const Decoded_XrFutureCompletionEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["futureResult"] = decoded_value.futureResult;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollResultEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrFuturePollResultEXT& decoded_value = *data->decoded_value;
        const Decoded_XrFuturePollResultEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["state"] = decoded_value.state;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataUserPresenceChangedEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataUserPresenceChangedEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataUserPresenceChangedEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        HandleToJson(jdata["session"], meta_struct.session);
        jdata["isUserPresent"] = static_cast<bool>(decoded_value.isUserPresent);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemUserPresencePropertiesEXT* data)
{
    if (data && data->decoded_value)
    {
        const XrSystemUserPresencePropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemUserPresencePropertiesEXT& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["supportsUserPresence"] = static_cast<bool>(decoded_value.supportsUserPresence);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataHeadsetFitChangedML* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataHeadsetFitChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataHeadsetFitChangedML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["status"] = decoded_value.status;
        jdata["time"] = decoded_value.time;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEyeCalibrationChangedML* data)
{
    if (data && data->decoded_value)
    {
        const XrEventDataEyeCalibrationChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataEyeCalibrationChangedML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["status"] = decoded_value.status;
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUserCalibrationEnableEventsInfoML* data)
{
    if (data && data->decoded_value)
    {
        const XrUserCalibrationEnableEventsInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrUserCalibrationEnableEventsInfoML& meta_struct = *data;

        jdata["type"] = decoded_value.type;
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data)
{
    if (data && data->GetPointer())
    {
        const auto type = reinterpret_cast<const XrBaseInStructure*>(data->GetPointer())->type;
        switch (type)
        {
            case XR_TYPE_ACTION_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_SET_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionSetCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionSpaceCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_STATE_BOOLEAN:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionStateBoolean*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_STATE_FLOAT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionStateFloat*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_STATE_GET_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionStateGetInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_STATE_POSE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionStatePose*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTION_STATE_VECTOR2F:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionStateVector2f*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTIONS_SYNC_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActionsSyncInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActiveActionSetPrioritiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_API_LAYER_PROPERTIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrApiLayerProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBindingModificationsKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBodyJointLocationsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBodyJointsLocateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BODY_SKELETON_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBodySkeletonFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBodyTrackerCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBoundSourcesForActionEnumerateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_BOUNDARY_2D_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBoundary2DFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerAlphaBlendFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerColorScaleBiasKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerCubeKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerCylinderKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerEquirect2KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerEquirectKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerImageLayoutFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerPassthroughFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerPassthroughHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerProjection*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerProjectionView*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_QUAD:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerQuad*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerReprojectionInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSecureContentFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSettingsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSpaceWarpInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrControllerModelKeyStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrControllerModelNodePropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrControllerModelNodeStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrControllerModelPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrControllerModelStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCoordinateSpaceCreateInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsLabelEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsMessengerCallbackDataEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsMessengerCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsObjectNameInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDevicePcmSampleRateStateFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDigitalLensControlALMALENCE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthImageAcquireInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthImageMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthImageViewMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthProviderCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEnvironmentDepthSwapchainStateMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_BUFFER:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataBuffer*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataDisplayRefreshRateChangedFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataEventsLost*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataEyeCalibrationChangedML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataHeadsetFitChangedML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataInstanceLossPending*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataInteractionProfileChanged*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataLocalizationChangedML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataPassthroughStateChangedFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataPerfSettingsEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataReferenceSpaceChangePending*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSceneCaptureCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSessionStateChanged*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceEraseCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceListSaveCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceQueryCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceSaveCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceSetStatusCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpaceShareCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataUserPresenceChangedEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVirtualKeyboardBackspaceMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVirtualKeyboardCommitTextMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVirtualKeyboardEnterMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVirtualKeyboardHiddenMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVirtualKeyboardShownMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataVisibilityMaskChangedKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEventDataViveTrackerConnectedHTCX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EXTENSION_PROPERTIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrExtensionProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
            {
                const auto* next = reinterpret_cast<const Decoded_XrExternalCameraOCULUS*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeGazeSampleTimeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EYE_GAZES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeGazesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EYE_GAZES_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeGazesInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeTrackerCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceExpressionInfo2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_EXPRESSION_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceExpressionInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceExpressionWeights2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceExpressionWeightsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceTrackerCreateInfo2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFaceTrackerCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFacialExpressionsHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFacialTrackerCreateInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrForceFeedbackCurlApplyLocationsMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveatedViewConfigurationViewVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationApplyInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationCustomModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationDynamicModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationEyeTrackedStateMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationLevelProfileCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationProfileCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FRAME_BEGIN_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameBeginInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FRAME_END_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameEndInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FRAME_END_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameEndInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FRAME_STATE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameState*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FRAME_WAIT_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameWaitInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFutureCancelInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FUTURE_COMPLETION_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFutureCompletionEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FUTURE_POLL_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFuturePollInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_FUTURE_POLL_RESULT_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFuturePollResultEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGeometryInstanceCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGeometryInstanceTransformFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGlobalDimmerFrameEndInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingD3D11KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingD3D12KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingEGLMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingMetalKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLESAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWaylandKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWin32KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXcbKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXlibKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingVulkanKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsD3D11KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsD3D12KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsMetalKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsOpenGLESKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsOpenGLKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsRequirementsVulkanKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointLocationsEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointVelocitiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointsLocateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointsMotionRangeInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_MESH_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandMeshMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandMeshSpaceCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandMeshUpdateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandPoseTypeInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackerCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingAimStateFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingCapsulesStateFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingDataSourceInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingDataSourceStateEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_MESH_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingMeshFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAND_TRACKING_SCALE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingScaleFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAPTIC_ACTION_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHapticActionInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHapticPcmVibrationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HAPTIC_VIBRATION:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHapticVibration*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHolographicWindowAttachmentMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInputSourceLocalizedNameGetInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INSTANCE_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInstanceCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInstanceCreateInfoAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INSTANCE_PROPERTIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInstanceProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInteractionProfileAnalogThresholdVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInteractionProfileDpadBindingEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INTERACTION_PROFILE_STATE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInteractionProfileState*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInteractionProfileSuggestedBinding*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrKeyboardSpaceCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrKeyboardTrackingQueryFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLoaderInitInfoAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalDimmingFrameEndInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalizationEnableEventsInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalizationMapImportInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_LOCALIZATION_MAP_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalizationMapML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMapLocalizationRequestInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorAprilTagInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorArucoInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorCreateInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorCustomProfileInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorSizeInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorSnapshotInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_STATE_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorStateML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerSpaceCreateInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerSpaceCreateInfoVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrNewSceneComputeInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughBrightnessContrastSaturationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorLutCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorLutUpdateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapInterpolatedLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToMonoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToRgbaFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughCreateInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughKeyboardHandsIntensityFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughLayerCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughMeshTransformInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughPreferencesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PASSTHROUGH_STYLE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughStyleFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPerformanceMetricsCounterMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPerformanceMetricsStateMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorBeginInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorGetInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorLocationEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorLocationsEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPlaneDetectorPolygonBufferEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRecommendedLayerResolutionGetInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRecommendedLayerResolutionMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrReferenceSpaceCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RENDER_MODEL_BUFFER_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelBufferFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelCapabilitiesRequestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelLoadInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelPathInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_ROOM_LAYOUT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRoomLayoutFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneCaptureRequestInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentLocationsMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentParentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentsGetInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentsLocateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_COMPONENTS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentsMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneDeserializeInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerQRCodesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerTypeFilterMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MARKERS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkersMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshBuffersGetInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshBuffersMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshIndicesUint16MSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshIndicesUint32MSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshVertexBufferMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_MESHES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectTypesFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_OBJECTS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectsMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObserverCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlaneAlignmentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SCENE_PLANES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlanesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SEMANTIC_LABELS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSemanticLabelsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSemanticLabelsSupportInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionActionSetsAttachInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SESSION_BEGIN_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionBeginInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SESSION_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionCreateInfoOverlayEXTX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceComponentFilterInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceComponentStatusFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceComponentStatusSetInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_CONTAINER_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceContainerFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_ERASE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceEraseInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceListSaveInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_LOCATION:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceLocation*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_LOCATIONS:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceLocations*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_QUERY_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceQueryInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceQueryResultsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_SAVE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceSaveInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_SHARE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceShareInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceStorageLocationFilterInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceTriangleMeshGetInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_TRIANGLE_MESH_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceTriangleMeshMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceUserCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceUuidFilterInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_VELOCITIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceVelocities*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACE_VELOCITY:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceVelocity*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPACES_LOCATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpacesLocateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorCreateInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorPersistenceInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_CREATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainCreateInfoFoveationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageAcquireInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageD3D11KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageD3D12KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageFoveationVulkanFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageMetalKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageOpenGLESKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageOpenGLKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageReleaseInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageVulkanKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageWaitInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainStateFoveationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainStateSamplerOpenGLESFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainStateSamplerVulkanFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemAnchorPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemBodyTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemColorSpacePropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEnvironmentDepthPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeGazeInteractionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFacialTrackingPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveatedRenderingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_GET_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemGetInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingMeshPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHeadsetIdPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemKeyboardTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerTrackingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerUnderstandingPropertiesML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughColorLutPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPlaneDetectionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_PROPERTIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemRenderModelPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpaceWarpPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpatialEntityPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemUserPresencePropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemVirtualKeyboardPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrTriangleMeshCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrUserCalibrationEnableEventsInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW:
            {
                const auto* next = reinterpret_cast<const Decoded_XrView*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationDepthRangeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_VIEW:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationView*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationViewFovEPIC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewLocateFoveatedRenderingVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_LOCATE_INFO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewLocateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIEW_STATE:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewState*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardAnimationStateMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardInputInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardLocationInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardModelAnimationStatesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVirtualKeyboardTextureDataMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VISIBILITY_MASK_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVisibilityMaskKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVisualMeshComputeLodInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViveTrackerPathsHTCX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVulkanGraphicsDeviceGetInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVulkanSwapchainCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next);
                break;
            }

            default:
            {
                GFXRECON_LOG_WARNING("Unknown next node type: %u.", (unsigned) type);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
