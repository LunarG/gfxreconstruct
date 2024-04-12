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

#include "generated_openxr_struct_to_json.h"
#include "generated_vulkan_struct_to_json.h"
#include "generated_openxr_enum_to_json.h"
#include "generated_vulkan_enum_to_json.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
using util::JsonOptions;
using util::to_hex_variable_width;
using util::uuid_to_string;


void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerProperties& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerProperties& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["layerName"], &meta_struct.layerName, options);
        FieldToJson(jdata["specVersion"], decoded_value.specVersion, options);
        FieldToJson(jdata["layerVersion"], decoded_value.layerVersion, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtensionProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExtensionProperties& decoded_value = *data->decoded_value;
        const Decoded_XrExtensionProperties& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["extensionName"], &meta_struct.extensionName, options);
        FieldToJson(jdata["extensionVersion"], decoded_value.extensionVersion, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApplicationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrApplicationInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApplicationInfo& meta_struct = *data;

        FieldToJson(jdata["applicationName"], &meta_struct.applicationName, options);
        FieldToJson(jdata["applicationVersion"], decoded_value.applicationVersion, options);
        FieldToJson(jdata["engineName"], &meta_struct.engineName, options);
        FieldToJson(jdata["engineVersion"], decoded_value.engineVersion, options);
        FieldToJson(jdata["apiVersion"], decoded_value.apiVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInstanceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrInstanceCreateFlags_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["applicationInfo"], meta_struct.applicationInfo, options);
        FieldToJson(jdata["enabledApiLayerCount"], decoded_value.enabledApiLayerCount, options);
        FieldToJson(jdata["enabledApiLayerNames"], &meta_struct.enabledApiLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], decoded_value.enabledExtensionCount, options);
        FieldToJson(jdata["enabledExtensionNames"], &meta_struct.enabledExtensionNames, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInstanceProperties& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceProperties& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["runtimeVersion"], decoded_value.runtimeVersion, options);
        FieldToJson(jdata["runtimeName"], &meta_struct.runtimeName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBuffer* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataBuffer& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataBuffer& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["varying"], &meta_struct.varying, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSystemGetInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["formFactor"], decoded_value.formFactor, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGraphicsProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemGraphicsProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemGraphicsProperties& meta_struct = *data;

        FieldToJson(jdata["maxSwapchainImageHeight"], decoded_value.maxSwapchainImageHeight, options);
        FieldToJson(jdata["maxSwapchainImageWidth"], decoded_value.maxSwapchainImageWidth, options);
        FieldToJson(jdata["maxLayerCount"], decoded_value.maxLayerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemTrackingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemTrackingProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemTrackingProperties& meta_struct = *data;

        jdata["orientationTracking"] = static_cast<bool>(decoded_value.orientationTracking);
        jdata["positionTracking"] = static_cast<bool>(decoded_value.positionTracking);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemProperties& decoded_value = *data->decoded_value;
        const Decoded_XrSystemProperties& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["systemId"], decoded_value.systemId, options);
        FieldToJson(jdata["vendorId"], decoded_value.vendorId, options);
        FieldToJson(jdata["systemName"], &meta_struct.systemName, options);
        FieldToJson(jdata["graphicsProperties"], meta_struct.graphicsProperties, options);
        FieldToJson(jdata["trackingProperties"], meta_struct.trackingProperties, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSessionCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSessionCreateFlags_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["systemId"], decoded_value.systemId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector3f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVector3f& decoded_value = *data->decoded_value;
        const Decoded_XrVector3f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocity* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceVelocity& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceVelocity& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSpaceVelocityFlags_t(),jdata["velocityFlags"], decoded_value.velocityFlags, options);
        FieldToJson(jdata["linearVelocity"], meta_struct.linearVelocity, options);
        FieldToJson(jdata["angularVelocity"], meta_struct.angularVelocity, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrQuaternionf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrQuaternionf& decoded_value = *data->decoded_value;
        const Decoded_XrQuaternionf& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
        FieldToJson(jdata["w"], decoded_value.w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPosef* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPosef& decoded_value = *data->decoded_value;
        const Decoded_XrPosef& meta_struct = *data;

        FieldToJson(jdata["orientation"], meta_struct.orientation, options);
        FieldToJson(jdata["position"], meta_struct.position, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrReferenceSpaceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrReferenceSpaceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrReferenceSpaceCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["referenceSpaceType"], decoded_value.referenceSpaceType, options);
        FieldToJson(jdata["poseInReferenceSpace"], meta_struct.poseInReferenceSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExtent2Df& decoded_value = *data->decoded_value;
        const Decoded_XrExtent2Df& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSpaceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionSpaceCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionSpaceCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["subactionPath"], decoded_value.subactionPath, options);
        FieldToJson(jdata["poseInActionSpace"], meta_struct.poseInActionSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocation* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceLocation& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceLocation& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], decoded_value.locationFlags, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationProperties& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationProperties& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        jdata["fovMutable"] = static_cast<bool>(decoded_value.fovMutable);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationView& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationView& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["recommendedImageRectWidth"], decoded_value.recommendedImageRectWidth, options);
        FieldToJson(jdata["maxImageRectWidth"], decoded_value.maxImageRectWidth, options);
        FieldToJson(jdata["recommendedImageRectHeight"], decoded_value.recommendedImageRectHeight, options);
        FieldToJson(jdata["maxImageRectHeight"], decoded_value.maxImageRectHeight, options);
        FieldToJson(jdata["recommendedSwapchainSampleCount"], decoded_value.recommendedSwapchainSampleCount, options);
        FieldToJson(jdata["maxSwapchainSampleCount"], decoded_value.maxSwapchainSampleCount, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSwapchainCreateFlags_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(XrSwapchainUsageFlags_t(),jdata["usageFlags"], decoded_value.usageFlags, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["sampleCount"], decoded_value.sampleCount, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["faceCount"], decoded_value.faceCount, options);
        FieldToJson(jdata["arraySize"], decoded_value.arraySize, options);
        FieldToJson(jdata["mipCount"], decoded_value.mipCount, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageBaseHeader& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageAcquireInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageAcquireInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageAcquireInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageWaitInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageWaitInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["timeout"], decoded_value.timeout, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageReleaseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageReleaseInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageReleaseInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSessionBeginInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionBeginInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["primaryViewConfigurationType"], decoded_value.primaryViewConfigurationType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFrameWaitInfo& decoded_value = *data->decoded_value;
        const Decoded_XrFrameWaitInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFrameState& decoded_value = *data->decoded_value;
        const Decoded_XrFrameState& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["predictedDisplayTime"], decoded_value.predictedDisplayTime, options);
        FieldToJson(jdata["predictedDisplayPeriod"], decoded_value.predictedDisplayPeriod, options);
        jdata["shouldRender"] = static_cast<bool>(decoded_value.shouldRender);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFrameBeginInfo& decoded_value = *data->decoded_value;
        const Decoded_XrFrameBeginInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerBaseHeader& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewLocateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrViewLocateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        FieldToJson(jdata["displayTime"], decoded_value.displayTime, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewState& decoded_value = *data->decoded_value;
        const Decoded_XrViewState& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrViewStateFlags_t(),jdata["viewStateFlags"], decoded_value.viewStateFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFovf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFovf& decoded_value = *data->decoded_value;
        const Decoded_XrFovf& meta_struct = *data;

        FieldToJson(jdata["angleLeft"], decoded_value.angleLeft, options);
        FieldToJson(jdata["angleRight"], decoded_value.angleRight, options);
        FieldToJson(jdata["angleUp"], decoded_value.angleUp, options);
        FieldToJson(jdata["angleDown"], decoded_value.angleDown, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrView& decoded_value = *data->decoded_value;
        const Decoded_XrView& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["fov"], meta_struct.fov, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSetCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionSetCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionSetCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["actionSetName"], &meta_struct.actionSetName, options);
        FieldToJson(jdata["localizedActionSetName"], &meta_struct.localizedActionSetName, options);
        FieldToJson(jdata["priority"], decoded_value.priority, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionCreateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["actionName"], &meta_struct.actionName, options);
        FieldToJson(jdata["actionType"], decoded_value.actionType, options);
        FieldToJson(jdata["countSubactionPaths"], decoded_value.countSubactionPaths, options);
        FieldToJson(jdata["subactionPaths"], meta_struct.subactionPaths, options);
        FieldToJson(jdata["localizedActionName"], &meta_struct.localizedActionName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSuggestedBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionSuggestedBinding& decoded_value = *data->decoded_value;
        const Decoded_XrActionSuggestedBinding& meta_struct = *data;

        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileSuggestedBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileSuggestedBinding& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileSuggestedBinding& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["interactionProfile"], decoded_value.interactionProfile, options);
        FieldToJson(jdata["countSuggestedBindings"], decoded_value.countSuggestedBindings, options);
        FieldToJson(jdata["suggestedBindings"], meta_struct.suggestedBindings, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionActionSetsAttachInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSessionActionSetsAttachInfo& decoded_value = *data->decoded_value;
        const Decoded_XrSessionActionSetsAttachInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["countActionSets"], decoded_value.countActionSets, options);
        HandleToJson(jdata["actionSets"], &meta_struct.actionSets, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileState& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileState& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["interactionProfile"], decoded_value.interactionProfile, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionStateGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateGetInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["subactionPath"], decoded_value.subactionPath, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateBoolean* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionStateBoolean& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateBoolean& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["currentState"] = static_cast<bool>(decoded_value.currentState);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], decoded_value.lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateFloat* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionStateFloat& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateFloat& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["currentState"], decoded_value.currentState, options);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], decoded_value.lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector2f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVector2f& decoded_value = *data->decoded_value;
        const Decoded_XrVector2f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateVector2f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionStateVector2f& decoded_value = *data->decoded_value;
        const Decoded_XrActionStateVector2f& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["currentState"], meta_struct.currentState, options);
        jdata["changedSinceLastSync"] = static_cast<bool>(decoded_value.changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], decoded_value.lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStatePose* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionStatePose& decoded_value = *data->decoded_value;
        const Decoded_XrActionStatePose& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSet& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSet& meta_struct = *data;

        HandleToJson(jdata["actionSet"], meta_struct.actionSet, options);
        FieldToJson(jdata["subactionPath"], decoded_value.subactionPath, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionsSyncInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActionsSyncInfo& decoded_value = *data->decoded_value;
        const Decoded_XrActionsSyncInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["countActiveActionSets"], decoded_value.countActiveActionSets, options);
        FieldToJson(jdata["activeActionSets"], meta_struct.activeActionSets, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundSourcesForActionEnumerateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBoundSourcesForActionEnumerateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrBoundSourcesForActionEnumerateInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInputSourceLocalizedNameGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInputSourceLocalizedNameGetInfo& decoded_value = *data->decoded_value;
        const Decoded_XrInputSourceLocalizedNameGetInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sourcePath"], decoded_value.sourcePath, options);
        FieldToJson(XrInputSourceLocalizedNameFlags_t(),jdata["whichComponents"], decoded_value.whichComponents, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticActionInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHapticActionInfo& decoded_value = *data->decoded_value;
        const Decoded_XrHapticActionInfo& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["subactionPath"], decoded_value.subactionPath, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHapticBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrHapticBaseHeader& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrOffset2Di& decoded_value = *data->decoded_value;
        const Decoded_XrOffset2Di& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExtent2Di& decoded_value = *data->decoded_value;
        const Decoded_XrExtent2Di& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRect2Di& decoded_value = *data->decoded_value;
        const Decoded_XrRect2Di& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainSubImage* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainSubImage& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainSubImage& meta_struct = *data;

        HandleToJson(jdata["swapchain"], meta_struct.swapchain, options);
        FieldToJson(jdata["imageRect"], meta_struct.imageRect, options);
        FieldToJson(jdata["imageArrayIndex"], decoded_value.imageArrayIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjectionView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerProjectionView& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerProjectionView& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["fov"], meta_struct.fov, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjection* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerProjection& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerProjection& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["viewCount"], decoded_value.viewCount, options);
        FieldToJson(jdata["views"], meta_struct.views, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerQuad* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerQuad& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerQuad& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["eyeVisibility"], decoded_value.eyeVisibility, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["size"], meta_struct.size, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataBaseHeader& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataBaseHeader& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEventsLost* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataEventsLost& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataEventsLost& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["lostEventCount"], decoded_value.lostEventCount, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInstanceLossPending* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataInstanceLossPending& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataInstanceLossPending& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["lossTime"], decoded_value.lossTime, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSessionStateChanged* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSessionStateChanged& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSessionStateChanged& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        FieldToJson(jdata["state"], decoded_value.state, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataReferenceSpaceChangePending* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataReferenceSpaceChangePending& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataReferenceSpaceChangePending& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        FieldToJson(jdata["referenceSpaceType"], decoded_value.referenceSpaceType, options);
        FieldToJson(jdata["changeTime"], decoded_value.changeTime, options);
        jdata["poseValid"] = static_cast<bool>(decoded_value.poseValid);
        FieldToJson(jdata["poseInPreviousSpace"], meta_struct.poseInPreviousSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInteractionProfileChanged* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataInteractionProfileChanged& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataInteractionProfileChanged& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticVibration* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHapticVibration& decoded_value = *data->decoded_value;
        const Decoded_XrHapticVibration& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["duration"], decoded_value.duration, options);
        FieldToJson(jdata["frequency"], decoded_value.frequency, options);
        FieldToJson(jdata["amplitude"], decoded_value.amplitude, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrOffset2Df& decoded_value = *data->decoded_value;
        const Decoded_XrOffset2Df& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRect2Df& decoded_value = *data->decoded_value;
        const Decoded_XrRect2Df& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVector4f& decoded_value = *data->decoded_value;
        const Decoded_XrVector4f& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
        FieldToJson(jdata["w"], decoded_value.w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor4f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrColor4f& decoded_value = *data->decoded_value;
        const Decoded_XrColor4f& meta_struct = *data;

        FieldToJson(jdata["r"], decoded_value.r, options);
        FieldToJson(jdata["g"], decoded_value.g, options);
        FieldToJson(jdata["b"], decoded_value.b, options);
        FieldToJson(jdata["a"], decoded_value.a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerNextInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerNextInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerNextInfo& meta_struct = *data;

        FieldToJson(jdata["structType"], decoded_value.structType, options);
        FieldToJson(jdata["structVersion"], decoded_value.structVersion, options);
        FieldToJson(jdata["structSize"], decoded_value.structSize, options);
        FieldToJson(jdata["layerName"], &meta_struct.layerName, options);
        FieldToJson(jdata["nextGetInstanceProcAddr"], to_hex_variable_width(meta_struct.nextGetInstanceProcAddr), options);
        FieldToJson(jdata["nextCreateApiLayerInstance"], to_hex_variable_width(meta_struct.nextCreateApiLayerInstance), options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrApiLayerCreateInfo& decoded_value = *data->decoded_value;
        const Decoded_XrApiLayerCreateInfo& meta_struct = *data;

        FieldToJson(jdata["structType"], decoded_value.structType, options);
        FieldToJson(jdata["structVersion"], decoded_value.structVersion, options);
        FieldToJson(jdata["structSize"], decoded_value.structSize, options);
        FieldToJson(jdata["loaderInstance"], meta_struct.loaderInstance, options);
        FieldToJson(jdata["settings_file_location"], &meta_struct.settings_file_location, options);
        FieldToJson(jdata["nextInfo"], meta_struct.nextInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNegotiateApiLayerRequest* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrNegotiateApiLayerRequest& decoded_value = *data->decoded_value;
        const Decoded_XrNegotiateApiLayerRequest& meta_struct = *data;

        FieldToJson(jdata["structType"], decoded_value.structType, options);
        FieldToJson(jdata["structVersion"], decoded_value.structVersion, options);
        FieldToJson(jdata["structSize"], decoded_value.structSize, options);
        FieldToJson(jdata["layerInterfaceVersion"], decoded_value.layerInterfaceVersion, options);
        FieldToJson(jdata["layerApiVersion"], decoded_value.layerApiVersion, options);
        FieldToJson(jdata["getInstanceProcAddr"], to_hex_variable_width(meta_struct.getInstanceProcAddr), options);
        FieldToJson(jdata["createApiLayerInstance"], to_hex_variable_width(meta_struct.createApiLayerInstance), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCubeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerCubeKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerCubeKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["eyeVisibility"], decoded_value.eyeVisibility, options);
        HandleToJson(jdata["swapchain"], meta_struct.swapchain, options);
        FieldToJson(jdata["imageArrayIndex"], decoded_value.imageArrayIndex, options);
        FieldToJson(jdata["orientation"], meta_struct.orientation, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfoAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInstanceCreateInfoAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrInstanceCreateInfoAndroidKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["applicationVM"], meta_struct.applicationVM, options);
        FieldToJson(jdata["applicationActivity"], meta_struct.applicationActivity, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthInfoKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["minDepth"], decoded_value.minDepth, options);
        FieldToJson(jdata["maxDepth"], decoded_value.maxDepth, options);
        FieldToJson(jdata["nearZ"], decoded_value.nearZ, options);
        FieldToJson(jdata["farZ"], decoded_value.farZ, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVulkanSwapchainFormatListCreateInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewFormatCount"], decoded_value.viewFormatCount, options);
        FieldToJson(jdata["viewFormats"], meta_struct.viewFormats, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCylinderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerCylinderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerCylinderKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["eyeVisibility"], decoded_value.eyeVisibility, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
        FieldToJson(jdata["centralAngle"], decoded_value.centralAngle, options);
        FieldToJson(jdata["aspectRatio"], decoded_value.aspectRatio, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirectKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerEquirectKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerEquirectKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["eyeVisibility"], decoded_value.eyeVisibility, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
        FieldToJson(jdata["scale"], meta_struct.scale, options);
        FieldToJson(jdata["bias"], meta_struct.bias, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWin32KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLWin32KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLWin32KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["hDC"], meta_struct.hDC, options);
        FieldToJson(jdata["hGLRC"], meta_struct.hGLRC, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXlibKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLXlibKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLXlibKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["xDisplay"], meta_struct.xDisplay, options);
        FieldToJson(jdata["visualid"], decoded_value.visualid, options);
        FieldToJson(jdata["glxFBConfig"], meta_struct.glxFBConfig, options);
        FieldToJson(jdata["glxDrawable"], decoded_value.glxDrawable, options);
        FieldToJson(jdata["glxContext"], meta_struct.glxContext, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXcbKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLXcbKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLXcbKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["connection"], meta_struct.connection, options);
        FieldToJson(jdata["screenNumber"], decoded_value.screenNumber, options);
        FieldToJson(jdata["fbconfigid"], decoded_value.fbconfigid, options);
        FieldToJson(jdata["visualid"], decoded_value.visualid, options);
        FieldToJson(jdata["glxDrawable"], decoded_value.glxDrawable, options);
        FieldToJson(jdata["glxContext"], decoded_value.glxContext, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWaylandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLWaylandKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLWaylandKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["display"], meta_struct.display, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageOpenGLKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageOpenGLKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["image"], decoded_value.image, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsOpenGLKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsOpenGLKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["minApiVersionSupported"], decoded_value.minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], decoded_value.maxApiVersionSupported, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLESAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingOpenGLESAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingOpenGLESAndroidKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["display"], meta_struct.display, options);
        FieldToJson(jdata["config"], meta_struct.config, options);
        FieldToJson(jdata["context"], meta_struct.context, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLESKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageOpenGLESKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageOpenGLESKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["image"], decoded_value.image, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLESKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsOpenGLESKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsOpenGLESKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["minApiVersionSupported"], decoded_value.minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], decoded_value.maxApiVersionSupported, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingVulkanKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["instance"], meta_struct.instance, options);
        HandleToJson(jdata["physicalDevice"], meta_struct.physicalDevice, options);
        HandleToJson(jdata["device"], meta_struct.device, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(jdata["queueIndex"], decoded_value.queueIndex, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageVulkanKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["image"], meta_struct.image, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsVulkanKHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsVulkanKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["minApiVersionSupported"], decoded_value.minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], decoded_value.maxApiVersionSupported, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingD3D11KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["device"], meta_struct.device, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageD3D11KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["texture"], meta_struct.texture, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsD3D11KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsD3D11KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["adapterLuid"], decoded_value.adapterLuid, options);
        FieldToJson(jdata["minFeatureLevel"], decoded_value.minFeatureLevel, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingD3D12KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["device"], meta_struct.device, options);
        FieldToJson(jdata["queue"], meta_struct.queue, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageD3D12KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["texture"], meta_struct.texture, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsRequirementsD3D12KHR& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsRequirementsD3D12KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["adapterLuid"], decoded_value.adapterLuid, options);
        FieldToJson(jdata["minFeatureLevel"], decoded_value.minFeatureLevel, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisibilityMaskKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVisibilityMaskKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVisibilityMaskKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVisibilityMaskChangedKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVisibilityMaskChangedKHR& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVisibilityMaskChangedKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        FieldToJson(jdata["viewIndex"], decoded_value.viewIndex, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerColorScaleBiasKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerColorScaleBiasKHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerColorScaleBiasKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["colorScale"], meta_struct.colorScale, options);
        FieldToJson(jdata["colorBias"], meta_struct.colorBias, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoBaseHeaderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLoaderInitInfoBaseHeaderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrLoaderInitInfoBaseHeaderKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLoaderInitInfoAndroidKHR& decoded_value = *data->decoded_value;
        const Decoded_XrLoaderInitInfoAndroidKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["applicationVM"], meta_struct.applicationVM, options);
        FieldToJson(jdata["applicationContext"], meta_struct.applicationContext, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanGraphicsDeviceGetInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVulkanGraphicsDeviceGetInfoKHR& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanGraphicsDeviceGetInfoKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["systemId"], decoded_value.systemId, options);
        HandleToJson(jdata["vulkanInstance"], meta_struct.vulkanInstance, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirect2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerEquirect2KHR& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerEquirect2KHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["eyeVisibility"], decoded_value.eyeVisibility, options);
        FieldToJson(jdata["subImage"], meta_struct.subImage, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
        FieldToJson(jdata["centralHorizontalAngle"], decoded_value.centralHorizontalAngle, options);
        FieldToJson(jdata["upperVerticalAngle"], decoded_value.upperVerticalAngle, options);
        FieldToJson(jdata["lowerVerticalAngle"], decoded_value.lowerVerticalAngle, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationBaseHeaderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBindingModificationBaseHeaderKHR& decoded_value = *data->decoded_value;
        const Decoded_XrBindingModificationBaseHeaderKHR& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPerfSettingsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataPerfSettingsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataPerfSettingsEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["domain"], decoded_value.domain, options);
        FieldToJson(jdata["subDomain"], decoded_value.subDomain, options);
        FieldToJson(jdata["fromLevel"], decoded_value.fromLevel, options);
        FieldToJson(jdata["toLevel"], decoded_value.toLevel, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsObjectNameInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsObjectNameInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["objectHandle"], decoded_value.objectHandle, options);
        FieldToJson(jdata["objectName"], &meta_struct.objectName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsLabelEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsLabelEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsLabelEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["labelName"], &meta_struct.labelName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsMessengerCallbackDataEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsMessengerCallbackDataEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["messageId"], &meta_struct.messageId, options);
        FieldToJson(jdata["functionName"], &meta_struct.functionName, options);
        FieldToJson(jdata["message"], &meta_struct.message, options);
        FieldToJson(jdata["objectCount"], decoded_value.objectCount, options);
        FieldToJson(jdata["objects"], meta_struct.objects, options);
        FieldToJson(jdata["sessionLabelCount"], decoded_value.sessionLabelCount, options);
        FieldToJson(jdata["sessionLabels"], meta_struct.sessionLabels, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDebugUtilsMessengerCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrDebugUtilsMessengerCreateInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t(),jdata["messageSeverities"], decoded_value.messageSeverities, options);
        FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t(),jdata["messageTypes"], decoded_value.messageTypes, options);
        FieldToJson(jdata["userCallback"], to_hex_variable_width(meta_struct.userCallback), options);
        FieldToJson(jdata["userData"], to_hex_variable_width(meta_struct.userData), options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeGazeInteractionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemEyeGazeInteractionPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemEyeGazeInteractionPropertiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsEyeGazeInteraction"] = static_cast<bool>(decoded_value.supportsEyeGazeInteraction);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeSampleTimeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazeSampleTimeEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazeSampleTimeEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfoOverlayEXTX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSessionCreateInfoOverlayEXTX& decoded_value = *data->decoded_value;
        const Decoded_XrSessionCreateInfoOverlayEXTX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrOverlaySessionCreateFlagsEXTX_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["sessionLayersPlacement"], decoded_value.sessionLayersPlacement, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMainSessionVisibilityChangedEXTX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataMainSessionVisibilityChangedEXTX& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataMainSessionVisibilityChangedEXTX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["visible"] = static_cast<bool>(decoded_value.visible);
        FieldToJson(XrOverlayMainSessionFlagsEXTX_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["anchor"], meta_struct.anchor, options);
        FieldToJson(jdata["poseInAnchorSpace"], meta_struct.poseInAnchorSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerImageLayoutFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerImageLayoutFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerImageLayoutFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerImageLayoutFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerAlphaBlendFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerAlphaBlendFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerAlphaBlendFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["srcFactorColor"], decoded_value.srcFactorColor, options);
        FieldToJson(jdata["dstFactorColor"], decoded_value.dstFactorColor, options);
        FieldToJson(jdata["srcFactorAlpha"], decoded_value.srcFactorAlpha, options);
        FieldToJson(jdata["dstFactorAlpha"], decoded_value.dstFactorAlpha, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationDepthRangeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationDepthRangeEXT& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationDepthRangeEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["recommendedNearZ"], decoded_value.recommendedNearZ, options);
        FieldToJson(jdata["minNearZ"], decoded_value.minNearZ, options);
        FieldToJson(jdata["recommendedFarZ"], decoded_value.recommendedFarZ, options);
        FieldToJson(jdata["maxFarZ"], decoded_value.maxFarZ, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingEGLMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGraphicsBindingEGLMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrGraphicsBindingEGLMNDX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["getProcAddress"], to_hex_variable_width(meta_struct.getProcAddress), options);
        FieldToJson(jdata["display"], meta_struct.display, options);
        FieldToJson(jdata["config"], meta_struct.config, options);
        FieldToJson(jdata["context"], meta_struct.context, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["nodeType"], decoded_value.nodeType, options);
        FieldToJson(jdata["nodeId"], &meta_struct.nodeId, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphStaticNodeBindingCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialGraphNodeBindingPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["nodeId"], &meta_struct.nodeId, options);
        FieldToJson(jdata["poseInNodeSpace"], meta_struct.poseInNodeSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemHandTrackingPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHandTrackingPropertiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsHandTracking"] = static_cast<bool>(decoded_value.supportsHandTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackerCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackerCreateInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["hand"], decoded_value.hand, options);
        FieldToJson(jdata["handJointSet"], decoded_value.handJointSet, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsLocateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointsLocateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointsLocateInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointLocationEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointLocationEXT& meta_struct = *data;

        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], decoded_value.locationFlags, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocityEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointVelocityEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointVelocityEXT& meta_struct = *data;

        FieldToJson(XrSpaceVelocityFlags_t(),jdata["velocityFlags"], decoded_value.velocityFlags, options);
        FieldToJson(jdata["linearVelocity"], meta_struct.linearVelocity, options);
        FieldToJson(jdata["angularVelocity"], meta_struct.angularVelocity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointLocationsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointLocationsEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["jointCount"], decoded_value.jointCount, options);
        FieldToJson(jdata["jointLocations"], meta_struct.jointLocations, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocitiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointVelocitiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointVelocitiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["jointCount"], decoded_value.jointCount, options);
        FieldToJson(jdata["jointVelocities"], meta_struct.jointVelocities, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingMeshPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemHandTrackingMeshPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHandTrackingMeshPropertiesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsHandTrackingMesh"] = static_cast<bool>(decoded_value.supportsHandTrackingMesh);
        FieldToJson(jdata["maxHandMeshIndexCount"], decoded_value.maxHandMeshIndexCount, options);
        FieldToJson(jdata["maxHandMeshVertexCount"], decoded_value.maxHandMeshVertexCount, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshSpaceCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshSpaceCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["handPoseType"], decoded_value.handPoseType, options);
        FieldToJson(jdata["poseInHandMeshSpace"], meta_struct.poseInHandMeshSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshUpdateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshUpdateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshUpdateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["handPoseType"], decoded_value.handPoseType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshIndexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshIndexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshIndexBufferMSFT& meta_struct = *data;

        FieldToJson(jdata["indexBufferKey"], decoded_value.indexBufferKey, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshVertexMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshVertexMSFT& meta_struct = *data;

        FieldToJson(jdata["position"], meta_struct.position, options);
        FieldToJson(jdata["normal"], meta_struct.normal, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshVertexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshVertexBufferMSFT& meta_struct = *data;

        FieldToJson(jdata["vertexUpdateTime"], decoded_value.vertexUpdateTime, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandMeshMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandMeshMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["indexBufferChanged"] = static_cast<bool>(decoded_value.indexBufferChanged);
        jdata["vertexBufferChanged"] = static_cast<bool>(decoded_value.vertexBufferChanged);
        FieldToJson(jdata["indexBuffer"], meta_struct.indexBuffer, options);
        FieldToJson(jdata["vertexBuffer"], meta_struct.vertexBuffer, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandPoseTypeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandPoseTypeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHandPoseTypeInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["handPoseType"], decoded_value.handPoseType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationSessionBeginInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationCount"], decoded_value.viewConfigurationCount, options);
        FieldToJson(jdata["enabledViewConfigurationTypes"], meta_struct.enabledViewConfigurationTypes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationStateMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        jdata["active"] = static_cast<bool>(decoded_value.active);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationFrameStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationFrameStateMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationCount"], decoded_value.viewConfigurationCount, options);
        FieldToJson(jdata["viewConfigurationStates"], meta_struct.viewConfigurationStates, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationFrameEndInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationCount"], decoded_value.viewConfigurationCount, options);
        FieldToJson(jdata["viewConfigurationLayersInfo"], meta_struct.viewConfigurationLayersInfo, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelKeyStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelKeyStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelKeyStateMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["modelKey"], decoded_value.modelKey, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodePropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelNodePropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelNodePropertiesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["parentNodeName"], &meta_struct.parentNodeName, options);
        FieldToJson(jdata["nodeName"], &meta_struct.nodeName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelPropertiesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelPropertiesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["nodeCapacityInput"], decoded_value.nodeCapacityInput, options);
        FieldToJson(jdata["nodeCountOutput"], decoded_value.nodeCountOutput, options);
        FieldToJson(jdata["nodeProperties"], meta_struct.nodeProperties, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodeStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelNodeStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelNodeStateMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["nodePose"], meta_struct.nodePose, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrControllerModelStateMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrControllerModelStateMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["nodeCapacityInput"], decoded_value.nodeCapacityInput, options);
        FieldToJson(jdata["nodeCountOutput"], decoded_value.nodeCountOutput, options);
        FieldToJson(jdata["nodeStates"], meta_struct.nodeStates, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationViewFovEPIC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewConfigurationViewFovEPIC& decoded_value = *data->decoded_value;
        const Decoded_XrViewConfigurationViewFovEPIC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["recommendedFov"], meta_struct.recommendedFov, options);
        FieldToJson(jdata["maxMutableFov"], meta_struct.maxMutableFov, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHolographicWindowAttachmentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHolographicWindowAttachmentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrHolographicWindowAttachmentMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["holographicSpace"], meta_struct.holographicSpace, options);
        FieldToJson(jdata["coreWindow"], meta_struct.coreWindow, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerReprojectionInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerReprojectionInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["reprojectionMode"], decoded_value.reprojectionMode, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerReprojectionPlaneOverrideMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["position"], meta_struct.position, options);
        FieldToJson(jdata["normal"], meta_struct.normal, options);
        FieldToJson(jdata["velocity"], meta_struct.velocity, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrAndroidSurfaceSwapchainCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrAndroidSurfaceSwapchainFlagsFB_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateBaseHeaderFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSecureContentFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSecureContentFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSecureContentFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerSecureContentFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointLocationFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointLocationFB& meta_struct = *data;

        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], decoded_value.locationFlags, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemBodyTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemBodyTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemBodyTrackingPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsBodyTracking"] = static_cast<bool>(decoded_value.supportsBodyTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodyTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyTrackerCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["bodyJointSet"], decoded_value.bodyJointSet, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonJointFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodySkeletonJointFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodySkeletonJointFB& meta_struct = *data;

        FieldToJson(jdata["joint"], decoded_value.joint, options);
        FieldToJson(jdata["parentJoint"], decoded_value.parentJoint, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodySkeletonFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodySkeletonFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["jointCount"], decoded_value.jointCount, options);
        FieldToJson(jdata["joints"], meta_struct.joints, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointsLocateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointsLocateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointsLocateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBodyJointLocationsFB& decoded_value = *data->decoded_value;
        const Decoded_XrBodyJointLocationsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["confidence"], decoded_value.confidence, options);
        FieldToJson(jdata["jointCount"], decoded_value.jointCount, options);
        FieldToJson(jdata["jointLocations"], meta_struct.jointLocations, options);
        FieldToJson(jdata["skeletonChangedCount"], decoded_value.skeletonChangedCount, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileDpadBindingEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileDpadBindingEXT& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileDpadBindingEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        HandleToJson(jdata["actionSet"], meta_struct.actionSet, options);
        FieldToJson(jdata["forceThreshold"], decoded_value.forceThreshold, options);
        FieldToJson(jdata["forceThresholdReleased"], decoded_value.forceThresholdReleased, options);
        FieldToJson(jdata["centerRegion"], decoded_value.centerRegion, options);
        FieldToJson(jdata["wedgeAngle"], decoded_value.wedgeAngle, options);
        jdata["isSticky"] = static_cast<bool>(decoded_value.isSticky);
        FieldToJson(jdata["onHaptic"], meta_struct.onHaptic, options);
        FieldToJson(jdata["offHaptic"], meta_struct.offHaptic, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileAnalogThresholdVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrInteractionProfileAnalogThresholdVALVE& decoded_value = *data->decoded_value;
        const Decoded_XrInteractionProfileAnalogThresholdVALVE& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["action"], meta_struct.action, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["onThreshold"], decoded_value.onThreshold, options);
        FieldToJson(jdata["offThreshold"], decoded_value.offThreshold, options);
        FieldToJson(jdata["onHaptic"], meta_struct.onHaptic, options);
        FieldToJson(jdata["offHaptic"], meta_struct.offHaptic, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsMotionRangeInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandJointsMotionRangeInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandJointsMotionRangeInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["handJointsMotionRange"], decoded_value.handJointsMotionRange, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrUuidMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrUuidMSFT& meta_struct = *data;

        FieldToJson(jdata["bytes"], &meta_struct.bytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObserverCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneObserverCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObserverCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneSphereBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneSphereBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneSphereBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["center"], meta_struct.center, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneOrientedBoxBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneOrientedBoxBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneOrientedBoxBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["extents"], meta_struct.extents, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneFrustumBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneFrustumBoundMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneFrustumBoundMSFT& meta_struct = *data;

        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["fov"], meta_struct.fov, options);
        FieldToJson(jdata["farDistance"], decoded_value.farDistance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneBoundsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneBoundsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneBoundsMSFT& meta_struct = *data;

        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["sphereCount"], decoded_value.sphereCount, options);
        FieldToJson(jdata["spheres"], meta_struct.spheres, options);
        FieldToJson(jdata["boxCount"], decoded_value.boxCount, options);
        FieldToJson(jdata["boxes"], meta_struct.boxes, options);
        FieldToJson(jdata["frustumCount"], decoded_value.frustumCount, options);
        FieldToJson(jdata["frustums"], meta_struct.frustums, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNewSceneComputeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrNewSceneComputeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrNewSceneComputeInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestedFeatureCount"], decoded_value.requestedFeatureCount, options);
        FieldToJson(jdata["requestedFeatures"], meta_struct.requestedFeatures, options);
        FieldToJson(jdata["consistency"], decoded_value.consistency, options);
        FieldToJson(jdata["bounds"], meta_struct.bounds, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisualMeshComputeLodInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVisualMeshComputeLodInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrVisualMeshComputeLodInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["lod"], decoded_value.lod, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentMSFT& meta_struct = *data;

        FieldToJson(jdata["componentType"], decoded_value.componentType, options);
        FieldToJson(jdata["id"], meta_struct.id, options);
        FieldToJson(jdata["parentId"], meta_struct.parentId, options);
        FieldToJson(jdata["updateTime"], decoded_value.updateTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["componentCapacityInput"], decoded_value.componentCapacityInput, options);
        FieldToJson(jdata["componentCountOutput"], decoded_value.componentCountOutput, options);
        FieldToJson(jdata["components"], meta_struct.components, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsGetInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["componentType"], decoded_value.componentType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentLocationMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentLocationMSFT& meta_struct = *data;

        FieldToJson(XrSpaceLocationFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentLocationsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentLocationsMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["locationCount"], decoded_value.locationCount, options);
        FieldToJson(jdata["locations"], meta_struct.locations, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsLocateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentsLocateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentsLocateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["componentIdCount"], decoded_value.componentIdCount, options);
        FieldToJson(jdata["componentIds"], meta_struct.componentIds, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectMSFT& meta_struct = *data;

        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectsMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectsMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sceneObjectCount"], decoded_value.sceneObjectCount, options);
        FieldToJson(jdata["sceneObjects"], meta_struct.sceneObjects, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentParentFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneComponentParentFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneComponentParentFilterInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["parentId"], meta_struct.parentId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectTypesFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneObjectTypesFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneObjectTypesFilterInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["objectTypeCount"], decoded_value.objectTypeCount, options);
        FieldToJson(jdata["objectTypes"], meta_struct.objectTypes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrScenePlaneMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlaneMSFT& meta_struct = *data;

        FieldToJson(jdata["alignment"], decoded_value.alignment, options);
        FieldToJson(jdata["size"], meta_struct.size, options);
        FieldToJson(jdata["meshBufferId"], decoded_value.meshBufferId, options);
        jdata["supportsIndicesUint16"] = static_cast<bool>(decoded_value.supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlanesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrScenePlanesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlanesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["scenePlaneCount"], decoded_value.scenePlaneCount, options);
        FieldToJson(jdata["scenePlanes"], meta_struct.scenePlanes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneAlignmentFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrScenePlaneAlignmentFilterInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrScenePlaneAlignmentFilterInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["alignmentCount"], decoded_value.alignmentCount, options);
        FieldToJson(jdata["alignments"], meta_struct.alignments, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshMSFT& meta_struct = *data;

        FieldToJson(jdata["meshBufferId"], decoded_value.meshBufferId, options);
        jdata["supportsIndicesUint16"] = static_cast<bool>(decoded_value.supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sceneMeshCount"], decoded_value.sceneMeshCount, options);
        FieldToJson(jdata["sceneMeshes"], meta_struct.sceneMeshes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshBuffersGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshBuffersGetInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["meshBufferId"], decoded_value.meshBufferId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshBuffersMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshBuffersMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshVertexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshVertexBufferMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshVertexBufferMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint32MSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshIndicesUint32MSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshIndicesUint32MSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint16MSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMeshIndicesUint16MSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMeshIndicesUint16MSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSerializedSceneFragmentDataGetInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sceneFragmentId"], meta_struct.sceneFragmentId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDeserializeSceneFragmentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDeserializeSceneFragmentMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrDeserializeSceneFragmentMSFT& meta_struct = *data;

        FieldToJson(jdata["bufferSize"], decoded_value.bufferSize, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneDeserializeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneDeserializeInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneDeserializeInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["fragmentCount"], decoded_value.fragmentCount, options);
        FieldToJson(jdata["fragments"], meta_struct.fragments, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataDisplayRefreshRateChangedFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataDisplayRefreshRateChangedFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataDisplayRefreshRateChangedFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["fromDisplayRefreshRate"], decoded_value.fromDisplayRefreshRate, options);
        FieldToJson(jdata["toDisplayRefreshRate"], decoded_value.toDisplayRefreshRate, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViveTrackerPathsHTCX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViveTrackerPathsHTCX& decoded_value = *data->decoded_value;
        const Decoded_XrViveTrackerPathsHTCX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["persistentPath"], decoded_value.persistentPath, options);
        FieldToJson(jdata["rolePath"], decoded_value.rolePath, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataViveTrackerConnectedHTCX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataViveTrackerConnectedHTCX& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataViveTrackerConnectedHTCX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["paths"], meta_struct.paths, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFacialTrackingPropertiesHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemFacialTrackingPropertiesHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFacialTrackingPropertiesHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportEyeFacialTracking"] = static_cast<bool>(decoded_value.supportEyeFacialTracking);
        jdata["supportLipFacialTracking"] = static_cast<bool>(decoded_value.supportLipFacialTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialExpressionsHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFacialExpressionsHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFacialExpressionsHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["sampleTime"], decoded_value.sampleTime, options);
        FieldToJson(jdata["expressionCount"], decoded_value.expressionCount, options);
        FieldToJson(jdata["expressionWeightings"], meta_struct.expressionWeightings, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialTrackerCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFacialTrackerCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFacialTrackerCreateInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["facialTrackingType"], decoded_value.facialTrackingType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemColorSpacePropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemColorSpacePropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemColorSpacePropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["colorSpace"], decoded_value.colorSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4sFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVector4sFB& decoded_value = *data->decoded_value;
        const Decoded_XrVector4sFB& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
        FieldToJson(jdata["w"], decoded_value.w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingMeshFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingMeshFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingMeshFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["jointCapacityInput"], decoded_value.jointCapacityInput, options);
        FieldToJson(jdata["jointCountOutput"], decoded_value.jointCountOutput, options);
        FieldToJson(jdata["jointBindPoses"], meta_struct.jointBindPoses, options);
        FieldToJson(jdata["jointRadii"], meta_struct.jointRadii, options);
        FieldToJson(jdata["jointParents"], meta_struct.jointParents, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertexPositions"], meta_struct.vertexPositions, options);
        FieldToJson(jdata["vertexNormals"], meta_struct.vertexNormals, options);
        FieldToJson(jdata["vertexUVs"], meta_struct.vertexUVs, options);
        FieldToJson(jdata["vertexBlendIndices"], meta_struct.vertexBlendIndices, options);
        FieldToJson(jdata["vertexBlendWeights"], meta_struct.vertexBlendWeights, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingScaleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingScaleFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingScaleFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sensorOutput"], decoded_value.sensorOutput, options);
        FieldToJson(jdata["currentOutput"], decoded_value.currentOutput, options);
        jdata["overrideHandScale"] = static_cast<bool>(decoded_value.overrideHandScale);
        FieldToJson(jdata["overrideValueInput"], decoded_value.overrideValueInput, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingAimStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingAimStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingAimStateFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrHandTrackingAimFlagsFB_t(),jdata["status"], decoded_value.status, options);
        FieldToJson(jdata["aimPose"], meta_struct.aimPose, options);
        FieldToJson(jdata["pinchStrengthIndex"], decoded_value.pinchStrengthIndex, options);
        FieldToJson(jdata["pinchStrengthMiddle"], decoded_value.pinchStrengthMiddle, options);
        FieldToJson(jdata["pinchStrengthRing"], decoded_value.pinchStrengthRing, options);
        FieldToJson(jdata["pinchStrengthLittle"], decoded_value.pinchStrengthLittle, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandCapsuleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandCapsuleFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandCapsuleFB& meta_struct = *data;

        FieldToJson(jdata["points"], meta_struct.points, options);
        FieldToJson(jdata["radius"], decoded_value.radius, options);
        FieldToJson(jdata["joint"], decoded_value.joint, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingCapsulesStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingCapsulesStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingCapsulesStateFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["capsules"], meta_struct.capsules, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpatialEntityPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemSpatialEntityPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemSpatialEntityPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsSpatialEntity"] = static_cast<bool>(decoded_value.supportsSpatialEntity);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusSetInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentStatusSetInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentStatusSetInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["componentType"], decoded_value.componentType, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["timeout"], decoded_value.timeout, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentStatusFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentStatusFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        jdata["changePending"] = static_cast<bool>(decoded_value.changePending);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrUuidEXT& decoded_value = *data->decoded_value;
        const Decoded_XrUuidEXT& meta_struct = *data;

        FieldToJson(jdata["data"], uuid_to_string(sizeof(decoded_value.data), decoded_value.data), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpatialAnchorCreateCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpatialAnchorCreateCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpatialAnchorCreateCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["uuid"], meta_struct.uuid, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSetStatusCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceSetStatusCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceSetStatusCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["uuid"], meta_struct.uuid, options);
        FieldToJson(jdata["componentType"], decoded_value.componentType, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationProfileCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationProfileCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationProfileCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfoFoveationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainCreateInfoFoveationFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainCreateInfoFoveationFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSwapchainCreateFoveationFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateFoveationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateFoveationFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateFoveationFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSwapchainStateFoveationFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        HandleToJson(jdata["profile"], meta_struct.profile, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationLevelProfileCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationLevelProfileCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationLevelProfileCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["level"], decoded_value.level, options);
        FieldToJson(jdata["verticalOffset"], decoded_value.verticalOffset, options);
        FieldToJson(jdata["dynamic"], decoded_value.dynamic, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemKeyboardTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemKeyboardTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemKeyboardTrackingPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsKeyboardTracking"] = static_cast<bool>(decoded_value.supportsKeyboardTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingDescriptionFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardTrackingDescriptionFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardTrackingDescriptionFB& meta_struct = *data;

        FieldToJson(jdata["trackedKeyboardId"], decoded_value.trackedKeyboardId, options);
        FieldToJson(jdata["size"], meta_struct.size, options);
        FieldToJson(XrKeyboardTrackingFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardSpaceCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardSpaceCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardSpaceCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["trackedKeyboardId"], decoded_value.trackedKeyboardId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingQueryFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrKeyboardTrackingQueryFB& decoded_value = *data->decoded_value;
        const Decoded_XrKeyboardTrackingQueryFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrKeyboardTrackingQueryFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrTriangleMeshCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrTriangleMeshCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrTriangleMeshCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrTriangleMeshFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["windingOrder"], decoded_value.windingOrder, options);
        FieldToJson(jdata["vertexCount"], decoded_value.vertexCount, options);
        FieldToJson(jdata["vertexBuffer"], meta_struct.vertexBuffer, options);
        FieldToJson(jdata["triangleCount"], decoded_value.triangleCount, options);
        FieldToJson(jdata["indexBuffer"], meta_struct.indexBuffer, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsPassthrough"] = static_cast<bool>(decoded_value.supportsPassthrough);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughProperties2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughProperties2FB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughProperties2FB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPassthroughCapabilityFlagsFB_t(),jdata["capabilities"], decoded_value.capabilities, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPassthroughFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughLayerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughLayerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughLayerCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["passthrough"], meta_struct.passthrough, options);
        FieldToJson(XrPassthroughFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["purpose"], decoded_value.purpose, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerPassthroughFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerPassthroughFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["flags"], decoded_value.flags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        HandleToJson(jdata["layerHandle"], meta_struct.layerHandle, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGeometryInstanceCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrGeometryInstanceCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["layer"], meta_struct.layer, options);
        HandleToJson(jdata["mesh"], meta_struct.mesh, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["scale"], meta_struct.scale, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceTransformFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGeometryInstanceTransformFB& decoded_value = *data->decoded_value;
        const Decoded_XrGeometryInstanceTransformFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["scale"], meta_struct.scale, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughStyleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughStyleFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughStyleFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["textureOpacityFactor"], decoded_value.textureOpacityFactor, options);
        FieldToJson(jdata["edgeColor"], meta_struct.edgeColor, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToRgbaFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapMonoToRgbaFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapMonoToRgbaFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["textureColorMap"], meta_struct.textureColorMap, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToMonoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapMonoToMonoFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapMonoToMonoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["textureColorMap"], &meta_struct.textureColorMap, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughBrightnessContrastSaturationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughBrightnessContrastSaturationFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughBrightnessContrastSaturationFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["brightness"], decoded_value.brightness, options);
        FieldToJson(jdata["contrast"], decoded_value.contrast, options);
        FieldToJson(jdata["saturation"], decoded_value.saturation, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPassthroughStateChangedFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataPassthroughStateChangedFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataPassthroughStateChangedFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPassthroughStateChangedFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPathInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelPathInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelPathInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["path"], decoded_value.path, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vendorId"], decoded_value.vendorId, options);
        FieldToJson(jdata["modelName"], &meta_struct.modelName, options);
        FieldToJson(jdata["modelKey"], decoded_value.modelKey, options);
        FieldToJson(jdata["modelVersion"], decoded_value.modelVersion, options);
        FieldToJson(XrRenderModelFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelBufferFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelBufferFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelBufferFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["bufferCapacityInput"], decoded_value.bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], decoded_value.bufferCountOutput, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelLoadInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelLoadInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelLoadInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["modelKey"], decoded_value.modelKey, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemRenderModelPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemRenderModelPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemRenderModelPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsRenderModelLoading"] = static_cast<bool>(decoded_value.supportsRenderModelLoading);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelCapabilitiesRequestFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRenderModelCapabilitiesRequestFB& decoded_value = *data->decoded_value;
        const Decoded_XrRenderModelCapabilitiesRequestFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrRenderModelFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateFoveatedRenderingVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrViewLocateFoveatedRenderingVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrViewLocateFoveatedRenderingVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["foveatedRenderingActive"] = static_cast<bool>(decoded_value.foveatedRenderingActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveatedViewConfigurationViewVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveatedViewConfigurationViewVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrFoveatedViewConfigurationViewVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["foveatedRenderingActive"] = static_cast<bool>(decoded_value.foveatedRenderingActive);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveatedRenderingPropertiesVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemFoveatedRenderingPropertiesVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFoveatedRenderingPropertiesVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsFoveatedRendering"] = static_cast<bool>(decoded_value.supportsFoveatedRendering);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthTestVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthTestVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["depthTestRangeNearZ"], decoded_value.depthTestRangeNearZ, options);
        FieldToJson(jdata["depthTestRangeFarZ"], decoded_value.depthTestRangeFarZ, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerTrackingPropertiesVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemMarkerTrackingPropertiesVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrSystemMarkerTrackingPropertiesVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsMarkerTracking"] = static_cast<bool>(decoded_value.supportsMarkerTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMarkerTrackingUpdateVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataMarkerTrackingUpdateVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataMarkerTrackingUpdateVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["markerId"], decoded_value.markerId, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        jdata["isPredicted"] = static_cast<bool>(decoded_value.isPredicted);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerSpaceCreateInfoVARJO& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerSpaceCreateInfoVARJO& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["markerId"], decoded_value.markerId, options);
        FieldToJson(jdata["poseInMarkerSpace"], meta_struct.poseInMarkerSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFrameEndInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrFrameEndInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["focusDistance"], decoded_value.focusDistance, options);
        FieldToJson(XrFrameEndInfoFlagsML_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGlobalDimmerFrameEndInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrGlobalDimmerFrameEndInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrGlobalDimmerFrameEndInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["dimmerValue"], decoded_value.dimmerValue, options);
        FieldToJson(XrGlobalDimmerFrameEndInfoFlagsML_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCoordinateSpaceCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCoordinateSpaceCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrCoordinateSpaceCreateInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["cfuid"], decoded_value.cfuid, options);
        FieldToJson(jdata["poseInCoordinateSpace"], meta_struct.poseInCoordinateSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerUnderstandingPropertiesML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemMarkerUnderstandingPropertiesML& decoded_value = *data->decoded_value;
        const Decoded_XrSystemMarkerUnderstandingPropertiesML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsMarkerUnderstanding"] = static_cast<bool>(decoded_value.supportsMarkerUnderstanding);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorCreateInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["profile"], decoded_value.profile, options);
        FieldToJson(jdata["markerType"], decoded_value.markerType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorArucoInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorArucoInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorArucoInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["arucoDict"], decoded_value.arucoDict, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSizeInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorSizeInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorSizeInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["markerLength"], decoded_value.markerLength, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorAprilTagInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorAprilTagInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorAprilTagInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["aprilTagDict"], decoded_value.aprilTagDict, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCustomProfileInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorCustomProfileInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorCustomProfileInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["fpsHint"], decoded_value.fpsHint, options);
        FieldToJson(jdata["resolutionHint"], decoded_value.resolutionHint, options);
        FieldToJson(jdata["cameraHint"], decoded_value.cameraHint, options);
        FieldToJson(jdata["cornerRefineMethod"], decoded_value.cornerRefineMethod, options);
        jdata["useEdgeRefinement"] = static_cast<bool>(decoded_value.useEdgeRefinement);
        FieldToJson(jdata["fullAnalysisIntervalHint"], decoded_value.fullAnalysisIntervalHint, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSnapshotInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorSnapshotInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorSnapshotInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorStateML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerDetectorStateML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerDetectorStateML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["state"], decoded_value.state, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMarkerSpaceCreateInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMarkerSpaceCreateInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["markerDetector"], meta_struct.markerDetector, options);
        FieldToJson(jdata["marker"], decoded_value.marker, options);
        FieldToJson(jdata["poseInMarkerSpace"], meta_struct.poseInMarkerSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["mapUuid"], meta_struct.mapUuid, options);
        FieldToJson(jdata["mapType"], decoded_value.mapType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataLocalizationChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataLocalizationChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataLocalizationChangedML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        FieldToJson(jdata["state"], decoded_value.state, options);
        FieldToJson(jdata["map"], meta_struct.map, options);
        FieldToJson(jdata["confidence"], decoded_value.confidence, options);
        FieldToJson(XrLocalizationMapErrorFlagsML_t(),jdata["errorFlags"], decoded_value.errorFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapQueryInfoBaseHeaderML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapQueryInfoBaseHeaderML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapQueryInfoBaseHeaderML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMapLocalizationRequestInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrMapLocalizationRequestInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrMapLocalizationRequestInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["mapUuid"], meta_struct.mapUuid, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapImportInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationMapImportInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationMapImportInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["data"], &meta_struct.data, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationEnableEventsInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLocalizationEnableEventsInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrLocalizationEnableEventsInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceNameMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorPersistenceNameMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorPersistenceNameMSFT& meta_struct = *data;

        FieldToJson(jdata["name"], &meta_struct.name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorPersistenceInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorPersistenceInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["spatialAnchorPersistenceName"], meta_struct.spatialAnchorPersistenceName, options);
        HandleToJson(jdata["spatialAnchor"], meta_struct.spatialAnchor, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["spatialAnchorStore"], meta_struct.spatialAnchorStore, options);
        FieldToJson(jdata["spatialAnchorPersistenceName"], meta_struct.spatialAnchorPersistenceName, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerMSFT& meta_struct = *data;

        FieldToJson(jdata["markerType"], decoded_value.markerType, options);
        FieldToJson(jdata["lastSeenTime"], decoded_value.lastSeenTime, options);
        FieldToJson(jdata["center"], meta_struct.center, options);
        FieldToJson(jdata["size"], meta_struct.size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkersMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkersMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkersMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sceneMarkerCapacityInput"], decoded_value.sceneMarkerCapacityInput, options);
        FieldToJson(jdata["sceneMarkers"], meta_struct.sceneMarkers, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerTypeFilterMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerTypeFilterMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerTypeFilterMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["markerTypeCount"], decoded_value.markerTypeCount, options);
        FieldToJson(jdata["markerTypes"], meta_struct.markerTypes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodeMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerQRCodeMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerQRCodeMSFT& meta_struct = *data;

        FieldToJson(jdata["symbolType"], decoded_value.symbolType, options);
        FieldToJson(jdata["version"], decoded_value.version, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneMarkerQRCodesMSFT& decoded_value = *data->decoded_value;
        const Decoded_XrSceneMarkerQRCodesMSFT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["qrCodeCapacityInput"], decoded_value.qrCodeCapacityInput, options);
        FieldToJson(jdata["qrCodes"], meta_struct.qrCodes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryInfoBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryInfoBaseHeaderFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceFilterInfoBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceFilterInfoBaseHeaderFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceFilterInfoBaseHeaderFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["queryAction"], decoded_value.queryAction, options);
        FieldToJson(jdata["maxResultCount"], decoded_value.maxResultCount, options);
        FieldToJson(jdata["timeout"], decoded_value.timeout, options);
        FieldToJson(jdata["filter"], meta_struct.filter, options);
        FieldToJson(jdata["excludeFilter"], meta_struct.excludeFilter, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceStorageLocationFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceStorageLocationFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceStorageLocationFilterInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUuidFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceUuidFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceUuidFilterInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["uuidCount"], decoded_value.uuidCount, options);
        FieldToJson(jdata["uuids"], meta_struct.uuids, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceComponentFilterInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceComponentFilterInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["componentType"], decoded_value.componentType, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryResultFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryResultFB& meta_struct = *data;

        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["uuid"], meta_struct.uuid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceQueryResultsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceQueryResultsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["resultCapacityInput"], decoded_value.resultCapacityInput, options);
        FieldToJson(jdata["resultCountOutput"], decoded_value.resultCountOutput, options);
        FieldToJson(jdata["results"], meta_struct.results, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryResultsAvailableFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceQueryResultsAvailableFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceQueryResultsAvailableFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceQueryCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceQueryCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceSaveInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceSaveInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceSaveInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["persistenceMode"], decoded_value.persistenceMode, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceEraseInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceEraseInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceEraseInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSaveCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceSaveCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceSaveCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["uuid"], meta_struct.uuid, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceEraseCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceEraseCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceEraseCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["uuid"], meta_struct.uuid, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageFoveationVulkanFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainImageFoveationVulkanFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainImageFoveationVulkanFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["image"], meta_struct.image, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateAndroidSurfaceDimensionsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerOpenGLESFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateSamplerOpenGLESFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateSamplerOpenGLESFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["minFilter"], decoded_value.minFilter, options);
        FieldToJson(jdata["magFilter"], decoded_value.magFilter, options);
        FieldToJson(jdata["wrapModeS"], decoded_value.wrapModeS, options);
        FieldToJson(jdata["wrapModeT"], decoded_value.wrapModeT, options);
        FieldToJson(jdata["swizzleRed"], decoded_value.swizzleRed, options);
        FieldToJson(jdata["swizzleGreen"], decoded_value.swizzleGreen, options);
        FieldToJson(jdata["swizzleBlue"], decoded_value.swizzleBlue, options);
        FieldToJson(jdata["swizzleAlpha"], decoded_value.swizzleAlpha, options);
        FieldToJson(jdata["maxAnisotropy"], decoded_value.maxAnisotropy, options);
        FieldToJson(jdata["borderColor"], meta_struct.borderColor, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerVulkanFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSwapchainStateSamplerVulkanFB& decoded_value = *data->decoded_value;
        const Decoded_XrSwapchainStateSamplerVulkanFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["minFilter"], decoded_value.minFilter, options);
        FieldToJson(jdata["magFilter"], decoded_value.magFilter, options);
        FieldToJson(jdata["mipmapMode"], decoded_value.mipmapMode, options);
        FieldToJson(jdata["wrapModeS"], decoded_value.wrapModeS, options);
        FieldToJson(jdata["wrapModeT"], decoded_value.wrapModeT, options);
        FieldToJson(jdata["swizzleRed"], decoded_value.swizzleRed, options);
        FieldToJson(jdata["swizzleGreen"], decoded_value.swizzleGreen, options);
        FieldToJson(jdata["swizzleBlue"], decoded_value.swizzleBlue, options);
        FieldToJson(jdata["swizzleAlpha"], decoded_value.swizzleAlpha, options);
        FieldToJson(jdata["maxAnisotropy"], decoded_value.maxAnisotropy, options);
        FieldToJson(jdata["borderColor"], meta_struct.borderColor, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceShareInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceShareInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceShareInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["spaceCount"], decoded_value.spaceCount, options);
        HandleToJson(jdata["spaces"], &meta_struct.spaces, options);
        FieldToJson(jdata["userCount"], decoded_value.userCount, options);
        HandleToJson(jdata["users"], &meta_struct.users, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceShareCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceShareCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceShareCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSpaceWarpInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSpaceWarpInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSpaceWarpInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerSpaceWarpInfoFlagsFB_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        FieldToJson(jdata["motionVectorSubImage"], meta_struct.motionVectorSubImage, options);
        FieldToJson(jdata["appSpaceDeltaPose"], meta_struct.appSpaceDeltaPose, options);
        FieldToJson(jdata["depthSubImage"], meta_struct.depthSubImage, options);
        FieldToJson(jdata["minDepth"], decoded_value.minDepth, options);
        FieldToJson(jdata["maxDepth"], decoded_value.maxDepth, options);
        FieldToJson(jdata["nearZ"], decoded_value.nearZ, options);
        FieldToJson(jdata["farZ"], decoded_value.farZ, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpaceWarpPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemSpaceWarpPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemSpaceWarpPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["recommendedMotionVectorImageRectWidth"], decoded_value.recommendedMotionVectorImageRectWidth, options);
        FieldToJson(jdata["recommendedMotionVectorImageRectHeight"], decoded_value.recommendedMotionVectorImageRectHeight, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticAmplitudeEnvelopeVibrationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHapticAmplitudeEnvelopeVibrationFB& decoded_value = *data->decoded_value;
        const Decoded_XrHapticAmplitudeEnvelopeVibrationFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["duration"], decoded_value.duration, options);
        FieldToJson(jdata["amplitudeCount"], decoded_value.amplitudeCount, options);
        FieldToJson(jdata["amplitudes"], meta_struct.amplitudes, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3DfFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExtent3DfFB& decoded_value = *data->decoded_value;
        const Decoded_XrExtent3DfFB& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["depth"], decoded_value.depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset3DfFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrOffset3DfFB& decoded_value = *data->decoded_value;
        const Decoded_XrOffset3DfFB& meta_struct = *data;

        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect3DfFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRect3DfFB& decoded_value = *data->decoded_value;
        const Decoded_XrRect3DfFB& meta_struct = *data;

        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSemanticLabelsFB& decoded_value = *data->decoded_value;
        const Decoded_XrSemanticLabelsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["bufferCapacityInput"], decoded_value.bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], decoded_value.bufferCountOutput, options);
        FieldToJson(jdata["buffer"], &meta_struct.buffer, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRoomLayoutFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRoomLayoutFB& decoded_value = *data->decoded_value;
        const Decoded_XrRoomLayoutFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["floorUuid"], meta_struct.floorUuid, options);
        FieldToJson(jdata["ceilingUuid"], meta_struct.ceilingUuid, options);
        FieldToJson(jdata["wallUuidCapacityInput"], decoded_value.wallUuidCapacityInput, options);
        FieldToJson(jdata["wallUuidCountOutput"], decoded_value.wallUuidCountOutput, options);
        FieldToJson(jdata["wallUuids"], meta_struct.wallUuids, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundary2DFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrBoundary2DFB& decoded_value = *data->decoded_value;
        const Decoded_XrBoundary2DFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsSupportInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSemanticLabelsSupportInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSemanticLabelsSupportInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrSemanticLabelsSupportFlagsFB_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["recognizedLabels"], &meta_struct.recognizedLabels, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDigitalLensControlALMALENCE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDigitalLensControlALMALENCE& decoded_value = *data->decoded_value;
        const Decoded_XrDigitalLensControlALMALENCE& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrDigitalLensControlFlagsALMALENCE_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSceneCaptureCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSceneCaptureCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSceneCaptureCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCaptureRequestInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSceneCaptureRequestInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSceneCaptureRequestInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestByteCount"], decoded_value.requestByteCount, options);
        FieldToJson(jdata["request"], &meta_struct.request, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceContainerFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceContainerFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceContainerFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["uuidCapacityInput"], decoded_value.uuidCapacityInput, options);
        FieldToJson(jdata["uuidCountOutput"], decoded_value.uuidCountOutput, options);
        FieldToJson(jdata["uuids"], meta_struct.uuids, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationEyeTrackedProfileCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrFoveationEyeTrackedProfileCreateFlagsMETA_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationEyeTrackedStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationEyeTrackedStateMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["foveationCenter"], meta_struct.foveationCenter, options);
        FieldToJson(XrFoveationEyeTrackedStateFlagsMETA_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemFoveationEyeTrackedPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsFoveationEyeTracked"] = static_cast<bool>(decoded_value.supportsFoveationEyeTracked);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemFaceTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFaceTrackingPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsFaceTracking"] = static_cast<bool>(decoded_value.supportsFaceTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceTrackerCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["faceExpressionSet"], decoded_value.faceExpressionSet, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionStatusFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionStatusFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionStatusFB& meta_struct = *data;

        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(decoded_value.isEyeFollowingBlendshapesValid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeightsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionWeightsFB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionWeightsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["weightCount"], decoded_value.weightCount, options);
        FieldToJson(jdata["weights"], meta_struct.weights, options);
        FieldToJson(jdata["confidenceCount"], decoded_value.confidenceCount, options);
        FieldToJson(jdata["confidences"], meta_struct.confidences, options);
        FieldToJson(jdata["status"], meta_struct.status, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazeFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazeFB& meta_struct = *data;

        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        FieldToJson(jdata["gazePose"], meta_struct.gazePose, options);
        FieldToJson(jdata["gazeConfidence"], decoded_value.gazeConfidence, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEyeTrackerCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeTrackerCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazesInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazesInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemEyeTrackingPropertiesFB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemEyeTrackingPropertiesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsEyeTracking"] = static_cast<bool>(decoded_value.supportsEyeTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEyeGazesFB& decoded_value = *data->decoded_value;
        const Decoded_XrEyeGazesFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["gaze"], meta_struct.gaze, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughKeyboardHandsIntensityFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughKeyboardHandsIntensityFB& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughKeyboardHandsIntensityFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["leftHandIntensity"], decoded_value.leftHandIntensity, options);
        FieldToJson(jdata["rightHandIntensity"], decoded_value.rightHandIntensity, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSettingsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerSettingsFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerSettingsFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerSettingsFlagsFB_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticPcmVibrationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHapticPcmVibrationFB& decoded_value = *data->decoded_value;
        const Decoded_XrHapticPcmVibrationFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["bufferSize"], decoded_value.bufferSize, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
        FieldToJson(jdata["sampleRate"], decoded_value.sampleRate, options);
        jdata["append"] = static_cast<bool>(decoded_value.append);
        FieldToJson(jdata["samplesConsumed"], meta_struct.samplesConsumed, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDevicePcmSampleRateStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrDevicePcmSampleRateStateFB& decoded_value = *data->decoded_value;
        const Decoded_XrDevicePcmSampleRateStateFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["sampleRate"], decoded_value.sampleRate, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerDepthTestFB& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerDepthTestFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["depthMask"] = static_cast<bool>(decoded_value.depthMask);
        FieldToJson(jdata["compareOp"], decoded_value.compareOp, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalDimmingFrameEndInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrLocalDimmingFrameEndInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrLocalDimmingFrameEndInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["localDimmingMode"], decoded_value.localDimmingMode, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughPreferencesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughPreferencesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughPreferencesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPassthroughPreferenceFlagsMETA_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemVirtualKeyboardPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemVirtualKeyboardPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemVirtualKeyboardPropertiesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsVirtualKeyboard"] = static_cast<bool>(decoded_value.supportsVirtualKeyboard);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardCreateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardSpaceCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["locationType"], decoded_value.locationType, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardLocationInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardLocationInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardLocationInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["locationType"], decoded_value.locationType, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace, options);
        FieldToJson(jdata["scale"], decoded_value.scale, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardModelVisibilitySetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["visible"] = static_cast<bool>(decoded_value.visible);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardAnimationStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardAnimationStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardAnimationStateMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["animationIndex"], decoded_value.animationIndex, options);
        FieldToJson(jdata["fraction"], decoded_value.fraction, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelAnimationStatesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardModelAnimationStatesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardModelAnimationStatesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["stateCapacityInput"], decoded_value.stateCapacityInput, options);
        FieldToJson(jdata["stateCountOutput"], decoded_value.stateCountOutput, options);
        FieldToJson(jdata["states"], meta_struct.states, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextureDataMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardTextureDataMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardTextureDataMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["textureWidth"], decoded_value.textureWidth, options);
        FieldToJson(jdata["textureHeight"], decoded_value.textureHeight, options);
        FieldToJson(jdata["bufferCapacityInput"], decoded_value.bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], decoded_value.bufferCountOutput, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardInputInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardInputInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardInputInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["inputSource"], decoded_value.inputSource, options);
        HandleToJson(jdata["inputSpace"], meta_struct.inputSpace, options);
        FieldToJson(jdata["inputPoseInSpace"], meta_struct.inputPoseInSpace, options);
        FieldToJson(XrVirtualKeyboardInputStateFlagsMETA_t(),jdata["inputState"], decoded_value.inputState, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVirtualKeyboardTextContextChangeInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["textContext"], &meta_struct.textContext, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardCommitTextMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardCommitTextMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardCommitTextMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["keyboard"], meta_struct.keyboard, options);
        FieldToJson(jdata["text"], &meta_struct.text, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardBackspaceMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardBackspaceMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardBackspaceMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["keyboard"], meta_struct.keyboard, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardEnterMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardEnterMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardEnterMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["keyboard"], meta_struct.keyboard, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardShownMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardShownMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardShownMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["keyboard"], meta_struct.keyboard, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardHiddenMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataVirtualKeyboardHiddenMETA& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataVirtualKeyboardHiddenMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["keyboard"], meta_struct.keyboard, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraIntrinsicsOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraIntrinsicsOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraIntrinsicsOCULUS& meta_struct = *data;

        FieldToJson(jdata["lastChangeTime"], decoded_value.lastChangeTime, options);
        FieldToJson(jdata["fov"], meta_struct.fov, options);
        FieldToJson(jdata["virtualNearPlaneDistance"], decoded_value.virtualNearPlaneDistance, options);
        FieldToJson(jdata["virtualFarPlaneDistance"], decoded_value.virtualFarPlaneDistance, options);
        FieldToJson(jdata["imageSensorPixelResolution"], meta_struct.imageSensorPixelResolution, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraExtrinsicsOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraExtrinsicsOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraExtrinsicsOCULUS& meta_struct = *data;

        FieldToJson(jdata["lastChangeTime"], decoded_value.lastChangeTime, options);
        FieldToJson(XrExternalCameraStatusFlagsOCULUS_t(),jdata["cameraStatusFlags"], decoded_value.cameraStatusFlags, options);
        FieldToJson(jdata["attachedToDevice"], decoded_value.attachedToDevice, options);
        FieldToJson(jdata["relativePose"], meta_struct.relativePose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExternalCameraOCULUS& decoded_value = *data->decoded_value;
        const Decoded_XrExternalCameraOCULUS& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["intrinsics"], meta_struct.intrinsics, options);
        FieldToJson(jdata["extrinsics"], meta_struct.extrinsics, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrVulkanSwapchainCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrVulkanSwapchainCreateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["additionalCreateFlags"], decoded_value.additionalCreateFlags, options);
        FieldToJson(jdata["additionalUsageFlags"], decoded_value.additionalUsageFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPerformanceMetricsStateMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPerformanceMetricsStateMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsCounterMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPerformanceMetricsCounterMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPerformanceMetricsCounterMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPerformanceMetricsCounterFlagsMETA_t(),jdata["counterFlags"], decoded_value.counterFlags, options);
        FieldToJson(jdata["counterUnit"], decoded_value.counterUnit, options);
        FieldToJson(jdata["uintValue"], decoded_value.uintValue, options);
        FieldToJson(jdata["floatValue"], decoded_value.floatValue, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceListSaveInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceListSaveInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceListSaveInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["spaceCount"], decoded_value.spaceCount, options);
        HandleToJson(jdata["spaces"], &meta_struct.spaces, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceListSaveCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataSpaceListSaveCompleteFB& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataSpaceListSaveCompleteFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestId"], decoded_value.requestId, options);
        FieldToJson(jdata["result"], decoded_value.result, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUserCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceUserCreateInfoFB& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceUserCreateInfoFB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["userId"], decoded_value.userId, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHeadsetIdPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemHeadsetIdPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemHeadsetIdPropertiesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["id"], meta_struct.id, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRecommendedLayerResolutionMETA& decoded_value = *data->decoded_value;
        const Decoded_XrRecommendedLayerResolutionMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["recommendedImageDimensions"], meta_struct.recommendedImageDimensions, options);
        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionGetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrRecommendedLayerResolutionGetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrRecommendedLayerResolutionGetInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["layer"], meta_struct.layer, options);
        FieldToJson(jdata["predictedDisplayTime"], decoded_value.predictedDisplayTime, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutDataMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutDataMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutDataMETA& meta_struct = *data;

        FieldToJson(jdata["bufferSize"], decoded_value.bufferSize, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutCreateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutCreateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["channels"], decoded_value.channels, options);
        FieldToJson(jdata["resolution"], decoded_value.resolution, options);
        FieldToJson(jdata["data"], meta_struct.data, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutUpdateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorLutUpdateInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorLutUpdateInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["data"], meta_struct.data, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapLutMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapLutMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapLutMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["colorLut"], meta_struct.colorLut, options);
        FieldToJson(jdata["weight"], decoded_value.weight, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapInterpolatedLutMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorMapInterpolatedLutMETA& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorMapInterpolatedLutMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["sourceColorLut"], meta_struct.sourceColorLut, options);
        HandleToJson(jdata["targetColorLut"], meta_struct.targetColorLut, options);
        FieldToJson(jdata["weight"], decoded_value.weight, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughColorLutPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemPassthroughColorLutPropertiesMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPassthroughColorLutPropertiesMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["maxColorLutResolution"], decoded_value.maxColorLutResolution, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshGetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceTriangleMeshGetInfoMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceTriangleMeshGetInfoMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpaceTriangleMeshMETA& decoded_value = *data->decoded_value;
        const Decoded_XrSpaceTriangleMeshMETA& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["indexCapacityInput"], decoded_value.indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], decoded_value.indexCountOutput, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingProperties2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemFaceTrackingProperties2FB& decoded_value = *data->decoded_value;
        const Decoded_XrSystemFaceTrackingProperties2FB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsVisualFaceTracking"] = static_cast<bool>(decoded_value.supportsVisualFaceTracking);
        jdata["supportsAudioFaceTracking"] = static_cast<bool>(decoded_value.supportsAudioFaceTracking);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfo2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceTrackerCreateInfo2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceTrackerCreateInfo2FB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["faceExpressionSet"], decoded_value.faceExpressionSet, options);
        FieldToJson(jdata["requestedDataSourceCount"], decoded_value.requestedDataSourceCount, options);
        FieldToJson(jdata["requestedDataSources"], meta_struct.requestedDataSources, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfo2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionInfo2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionInfo2FB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeights2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFaceExpressionWeights2FB& decoded_value = *data->decoded_value;
        const Decoded_XrFaceExpressionWeights2FB& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["weightCount"], decoded_value.weightCount, options);
        FieldToJson(jdata["weights"], meta_struct.weights, options);
        FieldToJson(jdata["confidenceCount"], decoded_value.confidenceCount, options);
        FieldToJson(jdata["confidences"], meta_struct.confidences, options);
        jdata["isValid"] = static_cast<bool>(decoded_value.isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(decoded_value.isEyeFollowingBlendshapesValid);
        FieldToJson(jdata["dataSource"], decoded_value.dataSource, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughCreateInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["form"], decoded_value.form, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughColorHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughColorHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["alpha"], decoded_value.alpha, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughMeshTransformInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPassthroughMeshTransformInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrPassthroughMeshTransformInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCount"], decoded_value.vertexCount, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["indexCount"], decoded_value.indexCount, options);
        FieldToJson(jdata["indices"], meta_struct.indices, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["scale"], meta_struct.scale, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrCompositionLayerPassthroughHTC& decoded_value = *data->decoded_value;
        const Decoded_XrCompositionLayerPassthroughHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], decoded_value.layerFlags, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        HandleToJson(jdata["passthrough"], meta_struct.passthrough, options);
        FieldToJson(jdata["color"], meta_struct.color, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationApplyInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationApplyInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationApplyInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["subImageCount"], decoded_value.subImageCount, options);
        FieldToJson(jdata["subImages"], meta_struct.subImages, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationConfigurationHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationConfigurationHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationConfigurationHTC& meta_struct = *data;

        FieldToJson(jdata["level"], decoded_value.level, options);
        FieldToJson(jdata["clearFovDegree"], decoded_value.clearFovDegree, options);
        FieldToJson(jdata["focalCenterOffset"], meta_struct.focalCenterOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationDynamicModeInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationDynamicModeInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationDynamicModeInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrFoveationDynamicFlagsHTC_t(),jdata["dynamicFlags"], decoded_value.dynamicFlags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationCustomModeInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFoveationCustomModeInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrFoveationCustomModeInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["configCount"], decoded_value.configCount, options);
        FieldToJson(jdata["configs"], meta_struct.configs, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemAnchorPropertiesHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemAnchorPropertiesHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSystemAnchorPropertiesHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsAnchor"] = static_cast<bool>(decoded_value.supportsAnchor);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorNameHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorNameHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorNameHTC& meta_struct = *data;

        FieldToJson(jdata["name"], &meta_struct.name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSpatialAnchorCreateInfoHTC& decoded_value = *data->decoded_value;
        const Decoded_XrSpatialAnchorCreateInfoHTC& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["space"], meta_struct.space, options);
        FieldToJson(jdata["poseInSpace"], meta_struct.poseInSpace, options);
        FieldToJson(jdata["name"], meta_struct.name, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPriorityEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSetPriorityEXT& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSetPriorityEXT& meta_struct = *data;

        HandleToJson(jdata["actionSet"], meta_struct.actionSet, options);
        FieldToJson(jdata["priorityOverride"], decoded_value.priorityOverride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPrioritiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrActiveActionSetPrioritiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrActiveActionSetPrioritiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["actionSetPriorityCount"], decoded_value.actionSetPriorityCount, options);
        FieldToJson(jdata["actionSetPriorities"], meta_struct.actionSetPriorities, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemForceFeedbackCurlPropertiesMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsForceFeedbackCurl"] = static_cast<bool>(decoded_value.supportsForceFeedbackCurl);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrForceFeedbackCurlApplyLocationMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrForceFeedbackCurlApplyLocationMNDX& meta_struct = *data;

        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["value"], decoded_value.value, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationsMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrForceFeedbackCurlApplyLocationsMNDX& decoded_value = *data->decoded_value;
        const Decoded_XrForceFeedbackCurlApplyLocationsMNDX& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["locationCount"], decoded_value.locationCount, options);
        FieldToJson(jdata["locations"], meta_struct.locations, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingDataSourceInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingDataSourceInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["requestedDataSourceCount"], decoded_value.requestedDataSourceCount, options);
        FieldToJson(jdata["requestedDataSources"], meta_struct.requestedDataSources, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceStateEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrHandTrackingDataSourceStateEXT& decoded_value = *data->decoded_value;
        const Decoded_XrHandTrackingDataSourceStateEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["isActive"] = static_cast<bool>(decoded_value.isActive);
        FieldToJson(jdata["dataSource"], decoded_value.dataSource, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPlaneDetectionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemPlaneDetectionPropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemPlaneDetectionPropertiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPlaneDetectionCapabilityFlagsEXT_t(),jdata["supportedFeatures"], decoded_value.supportedFeatures, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorCreateInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorCreateInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(XrPlaneDetectorFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3DfEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrExtent3DfEXT& decoded_value = *data->decoded_value;
        const Decoded_XrExtent3DfEXT& meta_struct = *data;

        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["depth"], decoded_value.depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorBeginInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorBeginInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["orientationCount"], decoded_value.orientationCount, options);
        FieldToJson(jdata["orientations"], meta_struct.orientations, options);
        FieldToJson(jdata["semanticTypeCount"], decoded_value.semanticTypeCount, options);
        FieldToJson(jdata["semanticTypes"], meta_struct.semanticTypes, options);
        FieldToJson(jdata["maxPlanes"], decoded_value.maxPlanes, options);
        FieldToJson(jdata["minArea"], decoded_value.minArea, options);
        FieldToJson(jdata["boundingBoxPose"], meta_struct.boundingBoxPose, options);
        FieldToJson(jdata["boundingBoxExtent"], meta_struct.boundingBoxExtent, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorGetInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorGetInfoEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorGetInfoEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["baseSpace"], meta_struct.baseSpace, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorLocationEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorLocationEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["planeId"], decoded_value.planeId, options);
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], decoded_value.locationFlags, options);
        FieldToJson(jdata["pose"], meta_struct.pose, options);
        FieldToJson(jdata["extents"], meta_struct.extents, options);
        FieldToJson(jdata["orientation"], decoded_value.orientation, options);
        FieldToJson(jdata["semanticType"], decoded_value.semanticType, options);
        FieldToJson(jdata["polygonBufferCount"], decoded_value.polygonBufferCount, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorLocationsEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorLocationsEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["planeLocationCapacityInput"], decoded_value.planeLocationCapacityInput, options);
        FieldToJson(jdata["planeLocationCountOutput"], decoded_value.planeLocationCountOutput, options);
        FieldToJson(jdata["planeLocations"], meta_struct.planeLocations, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorPolygonBufferEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrPlaneDetectorPolygonBufferEXT& decoded_value = *data->decoded_value;
        const Decoded_XrPlaneDetectorPolygonBufferEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["vertexCapacityInput"], decoded_value.vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], decoded_value.vertexCountOutput, options);
        FieldToJson(jdata["vertices"], meta_struct.vertices, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataUserPresenceChangedEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataUserPresenceChangedEXT& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataUserPresenceChangedEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["session"], meta_struct.session, options);
        jdata["isUserPresent"] = static_cast<bool>(decoded_value.isUserPresent);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemUserPresencePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrSystemUserPresencePropertiesEXT& decoded_value = *data->decoded_value;
        const Decoded_XrSystemUserPresencePropertiesEXT& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["supportsUserPresence"] = static_cast<bool>(decoded_value.supportsUserPresence);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataHeadsetFitChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataHeadsetFitChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataHeadsetFitChangedML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["status"], decoded_value.status, options);
        FieldToJson(jdata["time"], decoded_value.time, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEyeCalibrationChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrEventDataEyeCalibrationChangedML& decoded_value = *data->decoded_value;
        const Decoded_XrEventDataEyeCalibrationChangedML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["status"], decoded_value.status, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUserCalibrationEnableEventsInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrUserCalibrationEnableEventsInfoML& decoded_value = *data->decoded_value;
        const Decoded_XrUserCalibrationEnableEventsInfoML& meta_struct = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        jdata["enabled"] = static_cast<bool>(decoded_value.enabled);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data, const JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        const auto type = reinterpret_cast<const XrBaseInStructure*>(data->GetPointer())->type;
        switch (type)
        {
            case XR_TYPE_SPACE_VELOCITY:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceVelocity*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInstanceCreateInfoAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWin32KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXlibKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXcbKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWaylandKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLESAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingVulkanKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingD3D11KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingD3D12KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerColorScaleBiasKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBindingModificationsKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsMessengerCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeGazeInteractionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeGazeSampleTimeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionCreateInfoOverlayEXTX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerImageLayoutFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerAlphaBlendFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationDepthRangeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingEGLMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointVelocitiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingMeshPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandPoseTypeInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationViewFovEPIC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHolographicWindowAttachmentMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerReprojectionInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSecureContentFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemBodyTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointsMotionRangeInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVisualMeshComputeLodInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_OBJECTS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectsMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentParentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectTypesFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_PLANES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlanesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlaneAlignmentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MESHES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFacialTrackingPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemColorSpacePropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_TRACKING_SCALE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingScaleFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingAimStateFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingCapsulesStateFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpatialEntityPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainCreateInfoFoveationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationLevelProfileCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemKeyboardTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerPassthroughFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToRgbaFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToMonoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughBrightnessContrastSaturationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemRenderModelPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelCapabilitiesRequestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewLocateFoveatedRenderingVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveatedViewConfigurationViewVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveatedRenderingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerTrackingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FRAME_END_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFrameEndInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGlobalDimmerFrameEndInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerUnderstandingPropertiesML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorArucoInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorSizeInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorAprilTagInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorCustomProfileInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKERS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkersMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerTypeFilterMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerQRCodesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceStorageLocationFilterInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageFoveationVulkanFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSpaceWarpInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpaceWarpPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSettingsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalDimmingFrameEndInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemVirtualKeyboardPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVulkanSwapchainCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHeadsetIdPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapInterpolatedLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughColorLutPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughMeshTransformInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationDynamicModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationCustomModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemAnchorPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActiveActionSetPrioritiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingDataSourceInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingDataSourceStateEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPlaneDetectionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemUserPresencePropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            default:
            {
                GFXRECON_LOG_WARNING("Unknown next node type: %u.", (unsigned)type);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
