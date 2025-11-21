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
using util::JsonOptions;
using util::to_hex_variable_width;
using util::uuid_to_string;


void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["layerName"], &data->layerName, options);
        FieldToJson(jdata["specVersion"], data->decoded_value->specVersion, options);
        FieldToJson(jdata["layerVersion"], data->decoded_value->layerVersion, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtensionProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["extensionName"], &data->extensionName, options);
        FieldToJson(jdata["extensionVersion"], data->decoded_value->extensionVersion, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApplicationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["applicationName"], &data->applicationName, options);
        FieldToJson(jdata["applicationVersion"], data->decoded_value->applicationVersion, options);
        FieldToJson(jdata["engineName"], &data->engineName, options);
        FieldToJson(jdata["engineVersion"], data->decoded_value->engineVersion, options);
        FieldToJson(jdata["apiVersion"], data->decoded_value->apiVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrInstanceCreateFlags_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(jdata["applicationInfo"], data->applicationInfo, options);
        FieldToJson(jdata["enabledApiLayerCount"], data->decoded_value->enabledApiLayerCount, options);
        FieldToJson(jdata["enabledApiLayerNames"], &data->enabledApiLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], data->decoded_value->enabledExtensionCount, options);
        FieldToJson(jdata["enabledExtensionNames"], &data->enabledExtensionNames, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["runtimeVersion"], data->decoded_value->runtimeVersion, options);
        FieldToJson(jdata["runtimeName"], &data->runtimeName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBuffer* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["varying"], &data->varying, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["formFactor"], data->decoded_value->formFactor, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGraphicsProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["maxSwapchainImageHeight"], data->decoded_value->maxSwapchainImageHeight, options);
        FieldToJson(jdata["maxSwapchainImageWidth"], data->decoded_value->maxSwapchainImageWidth, options);
        FieldToJson(jdata["maxLayerCount"], data->decoded_value->maxLayerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemTrackingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["orientationTracking"] = static_cast<bool>(data->decoded_value->orientationTracking);
        jdata["positionTracking"] = static_cast<bool>(data->decoded_value->positionTracking);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["systemId"], data->systemId, options);
        FieldToJson(jdata["vendorId"], data->decoded_value->vendorId, options);
        FieldToJson(jdata["systemName"], &data->systemName, options);
        FieldToJson(jdata["graphicsProperties"], data->graphicsProperties, options);
        FieldToJson(jdata["trackingProperties"], data->trackingProperties, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSessionCreateFlags_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        HandleToJson(jdata["systemId"], data->systemId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector3f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocity* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSpaceVelocityFlags_t(),jdata["velocityFlags"], data->decoded_value->velocityFlags, options);
        FieldToJson(jdata["linearVelocity"], data->linearVelocity, options);
        FieldToJson(jdata["angularVelocity"], data->angularVelocity, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrQuaternionf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
        FieldToJson(jdata["w"], data->decoded_value->w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPosef* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["orientation"], data->orientation, options);
        FieldToJson(jdata["position"], data->position, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrReferenceSpaceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["referenceSpaceType"], data->decoded_value->referenceSpaceType, options);
        FieldToJson(jdata["poseInReferenceSpace"], data->poseInReferenceSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSpaceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["action"], data->action, options);
        HandleToJson(jdata["subactionPath"], data->subactionPath, options);
        FieldToJson(jdata["poseInActionSpace"], data->poseInActionSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocation* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], data->decoded_value->locationFlags, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        jdata["fovMutable"] = static_cast<bool>(data->decoded_value->fovMutable);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["recommendedImageRectWidth"], data->decoded_value->recommendedImageRectWidth, options);
        FieldToJson(jdata["maxImageRectWidth"], data->decoded_value->maxImageRectWidth, options);
        FieldToJson(jdata["recommendedImageRectHeight"], data->decoded_value->recommendedImageRectHeight, options);
        FieldToJson(jdata["maxImageRectHeight"], data->decoded_value->maxImageRectHeight, options);
        FieldToJson(jdata["recommendedSwapchainSampleCount"], data->decoded_value->recommendedSwapchainSampleCount, options);
        FieldToJson(jdata["maxSwapchainSampleCount"], data->decoded_value->maxSwapchainSampleCount, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSwapchainCreateFlags_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(XrSwapchainUsageFlags_t(),jdata["usageFlags"], data->decoded_value->usageFlags, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["sampleCount"], data->decoded_value->sampleCount, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["faceCount"], data->decoded_value->faceCount, options);
        FieldToJson(jdata["arraySize"], data->decoded_value->arraySize, options);
        FieldToJson(jdata["mipCount"], data->decoded_value->mipCount, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageOpenGLKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageOpenGLESKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageVulkanKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageD3D11KHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainImageD3D12KHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageAcquireInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageReleaseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["primaryViewConfigurationType"], data->decoded_value->primaryViewConfigurationType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["predictedDisplayTime"], data->decoded_value->predictedDisplayTime, options);
        FieldToJson(jdata["predictedDisplayPeriod"], data->decoded_value->predictedDisplayPeriod, options);
        jdata["shouldRender"] = static_cast<bool>(data->decoded_value->shouldRender);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerProjection*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerQuad*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerCubeKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerCylinderKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerEquirectKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerEquirect2KHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerPassthroughFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrCompositionLayerPassthroughHTC*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["displayTime"], data->decoded_value->displayTime, options);
        FieldToJson(jdata["environmentBlendMode"], data->decoded_value->environmentBlendMode, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
        FieldToJson(jdata["layers"], data->layers, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        FieldToJson(jdata["displayTime"], data->decoded_value->displayTime, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrViewStateFlags_t(),jdata["viewStateFlags"], data->decoded_value->viewStateFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFovf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["angleLeft"], data->decoded_value->angleLeft, options);
        FieldToJson(jdata["angleRight"], data->decoded_value->angleRight, options);
        FieldToJson(jdata["angleUp"], data->decoded_value->angleUp, options);
        FieldToJson(jdata["angleDown"], data->decoded_value->angleDown, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSetCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["actionSetName"], &data->actionSetName, options);
        FieldToJson(jdata["localizedActionSetName"], &data->localizedActionSetName, options);
        FieldToJson(jdata["priority"], data->decoded_value->priority, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["actionName"], &data->actionName, options);
        FieldToJson(jdata["actionType"], data->decoded_value->actionType, options);
        FieldToJson(jdata["countSubactionPaths"], data->decoded_value->countSubactionPaths, options);
        HandleToJson(jdata["subactionPaths"], &data->subactionPaths, options);
        FieldToJson(jdata["localizedActionName"], &data->localizedActionName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSuggestedBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["action"], data->action, options);
        HandleToJson(jdata["binding"], data->binding, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileSuggestedBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["interactionProfile"], data->interactionProfile, options);
        FieldToJson(jdata["countSuggestedBindings"], data->decoded_value->countSuggestedBindings, options);
        FieldToJson(jdata["suggestedBindings"], data->suggestedBindings, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionActionSetsAttachInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["countActionSets"], data->decoded_value->countActionSets, options);
        HandleToJson(jdata["actionSets"], &data->actionSets, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["interactionProfile"], data->interactionProfile, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["action"], data->action, options);
        HandleToJson(jdata["subactionPath"], data->subactionPath, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateBoolean* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["currentState"] = static_cast<bool>(data->decoded_value->currentState);
        jdata["changedSinceLastSync"] = static_cast<bool>(data->decoded_value->changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], data->decoded_value->lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateFloat* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["currentState"], data->decoded_value->currentState, options);
        jdata["changedSinceLastSync"] = static_cast<bool>(data->decoded_value->changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], data->decoded_value->lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector2f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateVector2f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["currentState"], data->currentState, options);
        jdata["changedSinceLastSync"] = static_cast<bool>(data->decoded_value->changedSinceLastSync);
        FieldToJson(jdata["lastChangeTime"], data->decoded_value->lastChangeTime, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStatePose* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["actionSet"], data->actionSet, options);
        HandleToJson(jdata["subactionPath"], data->subactionPath, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionsSyncInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["countActiveActionSets"], data->decoded_value->countActiveActionSets, options);
        FieldToJson(jdata["activeActionSets"], data->activeActionSets, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundSourcesForActionEnumerateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["action"], data->action, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInputSourceLocalizedNameGetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["sourcePath"], data->sourcePath, options);
        FieldToJson(XrInputSourceLocalizedNameFlags_t(),jdata["whichComponents"], data->decoded_value->whichComponents, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticActionInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["action"], data->action, options);
        HandleToJson(jdata["subactionPath"], data->subactionPath, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_HAPTIC_VIBRATION:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticVibration*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrHapticPcmVibrationFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Di* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainSubImage* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["imageRect"], data->imageRect, options);
        FieldToJson(jdata["imageArrayIndex"], data->decoded_value->imageArrayIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjectionView* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjection* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["viewCount"], data->decoded_value->viewCount, options);
        FieldToJson(jdata["views"], data->views, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerQuad* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["eyeVisibility"], data->decoded_value->eyeVisibility, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["size"], data->size, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBaseHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataEventsLost*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataInstanceLossPending*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSessionStateChanged*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataReferenceSpaceChangePending*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataInteractionProfileChanged*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataVisibilityMaskChangedKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataPerfSettingsEXT*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataDisplayRefreshRateChangedFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataViveTrackerConnectedHTCX*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceSetStatusCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataLocalizationChangedML*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceQueryCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceSaveCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceEraseCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceShareCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataSpaceListSaveCompleteFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataHeadsetFitChangedML*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrEventDataEyeCalibrationChangedML*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEventsLost* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["lostEventCount"], data->decoded_value->lostEventCount, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInstanceLossPending* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["lossTime"], data->decoded_value->lossTime, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSessionStateChanged* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        FieldToJson(jdata["state"], data->decoded_value->state, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataReferenceSpaceChangePending* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        FieldToJson(jdata["referenceSpaceType"], data->decoded_value->referenceSpaceType, options);
        FieldToJson(jdata["changeTime"], data->decoded_value->changeTime, options);
        jdata["poseValid"] = static_cast<bool>(data->decoded_value->poseValid);
        FieldToJson(jdata["poseInPreviousSpace"], data->poseInPreviousSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInteractionProfileChanged* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticVibration* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["duration"], data->decoded_value->duration, options);
        FieldToJson(jdata["frequency"], data->decoded_value->frequency, options);
        FieldToJson(jdata["amplitude"], data->decoded_value->amplitude, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
        FieldToJson(jdata["w"], data->decoded_value->w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor4f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["r"], data->decoded_value->r, options);
        FieldToJson(jdata["g"], data->decoded_value->g, options);
        FieldToJson(jdata["b"], data->decoded_value->b, options);
        FieldToJson(jdata["a"], data->decoded_value->a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerNextInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["structType"], data->decoded_value->structType, options);
        FieldToJson(jdata["structVersion"], data->decoded_value->structVersion, options);
        FieldToJson(jdata["structSize"], data->decoded_value->structSize, options);
        FieldToJson(jdata["layerName"], &data->layerName, options);
        FieldToJson(jdata["nextGetInstanceProcAddr"], to_hex_variable_width(data->nextGetInstanceProcAddr), options);
        FieldToJson(jdata["nextCreateApiLayerInstance"], to_hex_variable_width(data->nextCreateApiLayerInstance), options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["structType"], data->decoded_value->structType, options);
        FieldToJson(jdata["structVersion"], data->decoded_value->structVersion, options);
        FieldToJson(jdata["structSize"], data->decoded_value->structSize, options);
        FieldToJson(jdata["loaderInstance"], data->loaderInstance, options);
        FieldToJson(jdata["settings_file_location"], &data->settings_file_location, options);
        FieldToJson(jdata["nextInfo"], data->nextInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNegotiateApiLayerRequest* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["structType"], data->decoded_value->structType, options);
        FieldToJson(jdata["structVersion"], data->decoded_value->structVersion, options);
        FieldToJson(jdata["structSize"], data->decoded_value->structSize, options);
        FieldToJson(jdata["layerInterfaceVersion"], data->decoded_value->layerInterfaceVersion, options);
        FieldToJson(jdata["layerApiVersion"], data->decoded_value->layerApiVersion, options);
        FieldToJson(jdata["getInstanceProcAddr"], to_hex_variable_width(data->getInstanceProcAddr), options);
        FieldToJson(jdata["createApiLayerInstance"], to_hex_variable_width(data->createApiLayerInstance), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor3f* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["r"], data->decoded_value->r, options);
        FieldToJson(jdata["g"], data->decoded_value->g, options);
        FieldToJson(jdata["b"], data->decoded_value->b, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3Df* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["depth"], data->decoded_value->depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpheref* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["center"], data->center, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoxf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["center"], data->center, options);
        FieldToJson(jdata["extents"], data->extents, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrustumf* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["nearZ"], data->decoded_value->nearZ, options);
        FieldToJson(jdata["farZ"], data->decoded_value->farZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuid* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["data"], uuid_to_string(sizeof(data->decoded_value->data), data->decoded_value->data), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpacesLocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["spaceCount"], data->decoded_value->spaceCount, options);
        HandleToJson(jdata["spaces"], &data->spaces, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocationData* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], data->decoded_value->locationFlags, options);
        FieldToJson(jdata["pose"], data->pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocations* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["locationCount"], data->decoded_value->locationCount, options);
        FieldToJson(jdata["locations"], data->locations, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocityData* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceVelocityFlags_t(),jdata["velocityFlags"], data->decoded_value->velocityFlags, options);
        FieldToJson(jdata["linearVelocity"], data->linearVelocity, options);
        FieldToJson(jdata["angularVelocity"], data->angularVelocity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocities* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["velocityCount"], data->decoded_value->velocityCount, options);
        FieldToJson(jdata["velocities"], data->velocities, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCubeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["eyeVisibility"], data->decoded_value->eyeVisibility, options);
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["imageArrayIndex"], data->decoded_value->imageArrayIndex, options);
        FieldToJson(jdata["orientation"], data->orientation, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfoAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["applicationVM"], data->applicationVM, options);
        FieldToJson(jdata["applicationActivity"], data->applicationActivity, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["minDepth"], data->decoded_value->minDepth, options);
        FieldToJson(jdata["maxDepth"], data->decoded_value->maxDepth, options);
        FieldToJson(jdata["nearZ"], data->decoded_value->nearZ, options);
        FieldToJson(jdata["farZ"], data->decoded_value->farZ, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewFormatCount"], data->decoded_value->viewFormatCount, options);
        FieldToJson(jdata["viewFormats"], data->viewFormats, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCylinderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["eyeVisibility"], data->decoded_value->eyeVisibility, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
        FieldToJson(jdata["centralAngle"], data->decoded_value->centralAngle, options);
        FieldToJson(jdata["aspectRatio"], data->decoded_value->aspectRatio, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirectKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["eyeVisibility"], data->decoded_value->eyeVisibility, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
        FieldToJson(jdata["scale"], data->scale, options);
        FieldToJson(jdata["bias"], data->bias, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWin32KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["hDC"], data->hDC, options);
        FieldToJson(jdata["hGLRC"], data->hGLRC, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXlibKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["xDisplay"], data->xDisplay, options);
        FieldToJson(jdata["visualid"], data->decoded_value->visualid, options);
        FieldToJson(jdata["glxFBConfig"], data->glxFBConfig, options);
        FieldToJson(jdata["glxDrawable"], data->decoded_value->glxDrawable, options);
        FieldToJson(jdata["glxContext"], data->glxContext, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXcbKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["connection"], data->connection, options);
        FieldToJson(jdata["screenNumber"], data->decoded_value->screenNumber, options);
        FieldToJson(jdata["fbconfigid"], data->decoded_value->fbconfigid, options);
        FieldToJson(jdata["visualid"], data->decoded_value->visualid, options);
        FieldToJson(jdata["glxDrawable"], data->decoded_value->glxDrawable, options);
        FieldToJson(jdata["glxContext"], data->decoded_value->glxContext, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWaylandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["display"], data->display, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["image"], data->decoded_value->image, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["minApiVersionSupported"], data->decoded_value->minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], data->decoded_value->maxApiVersionSupported, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLESAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["display"], data->display, options);
        FieldToJson(jdata["config"], data->config, options);
        FieldToJson(jdata["context"], data->context, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLESKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["image"], data->decoded_value->image, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLESKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["minApiVersionSupported"], data->decoded_value->minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], data->decoded_value->maxApiVersionSupported, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["instance"], data->instance, options);
        HandleToJson(jdata["physicalDevice"], data->physicalDevice, options);
        HandleToJson(jdata["device"], data->device, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(jdata["queueIndex"], data->decoded_value->queueIndex, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsVulkanKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["minApiVersionSupported"], data->decoded_value->minApiVersionSupported, options);
        FieldToJson(jdata["maxApiVersionSupported"], data->decoded_value->maxApiVersionSupported, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["device"], data->device, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["texture"], data->texture, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D11KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["adapterLuid"], data->decoded_value->adapterLuid, options);
        FieldToJson(jdata["minFeatureLevel"], data->decoded_value->minFeatureLevel, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["device"], data->device, options);
        FieldToJson(jdata["queue"], data->queue, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["texture"], data->texture, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D12KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["adapterLuid"], data->decoded_value->adapterLuid, options);
        FieldToJson(jdata["minFeatureLevel"], data->decoded_value->minFeatureLevel, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingMetalKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["commandQueue"], data->commandQueue, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageMetalKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["texture"], data->texture, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsMetalKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["metalDevice"], data->metalDevice, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisibilityMaskKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVisibilityMaskChangedKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        FieldToJson(jdata["viewIndex"], data->decoded_value->viewIndex, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerColorScaleBiasKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["colorScale"], data->colorScale, options);
        FieldToJson(jdata["colorBias"], data->colorBias, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoBaseHeaderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrLoaderInitInfoAndroidKHR*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoAndroidKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["applicationVM"], data->applicationVM, options);
        FieldToJson(jdata["applicationContext"], data->applicationContext, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanGraphicsDeviceGetInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["systemId"], data->systemId, options);
        HandleToJson(jdata["vulkanInstance"], data->vulkanInstance, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirect2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["eyeVisibility"], data->decoded_value->eyeVisibility, options);
        FieldToJson(jdata["subImage"], data->subImage, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
        FieldToJson(jdata["centralHorizontalAngle"], data->decoded_value->centralHorizontalAngle, options);
        FieldToJson(jdata["upperVerticalAngle"], data->decoded_value->upperVerticalAngle, options);
        FieldToJson(jdata["lowerVerticalAngle"], data->decoded_value->lowerVerticalAngle, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationBaseHeaderKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrInteractionProfileDpadBindingEXT*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrInteractionProfileAnalogThresholdVALVE*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["bindingModificationCount"], data->decoded_value->bindingModificationCount, options);
        FieldToJson(jdata["bindingModifications"], data->bindingModifications, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPerfSettingsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["domain"], data->decoded_value->domain, options);
        FieldToJson(jdata["subDomain"], data->decoded_value->subDomain, options);
        FieldToJson(jdata["fromLevel"], data->decoded_value->fromLevel, options);
        FieldToJson(jdata["toLevel"], data->decoded_value->toLevel, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        FieldToJson(jdata["objectHandle"], data->decoded_value->objectHandle, options);
        FieldToJson(jdata["objectName"], &data->objectName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsLabelEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["labelName"], &data->labelName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["messageId"], &data->messageId, options);
        FieldToJson(jdata["functionName"], &data->functionName, options);
        FieldToJson(jdata["message"], &data->message, options);
        FieldToJson(jdata["objectCount"], data->decoded_value->objectCount, options);
        FieldToJson(jdata["objects"], data->objects, options);
        FieldToJson(jdata["sessionLabelCount"], data->decoded_value->sessionLabelCount, options);
        FieldToJson(jdata["sessionLabels"], data->sessionLabels, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t(),jdata["messageSeverities"], data->decoded_value->messageSeverities, options);
        FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t(),jdata["messageTypes"], data->decoded_value->messageTypes, options);
        FieldToJson(jdata["userCallback"], to_hex_variable_width(data->userCallback), options);
        FieldToJson(jdata["userData"], to_hex_variable_width(data->userData), options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeGazeInteractionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsEyeGazeInteraction"] = static_cast<bool>(data->decoded_value->supportsEyeGazeInteraction);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeSampleTimeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfoOverlayEXTX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrOverlaySessionCreateFlagsEXTX_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(jdata["sessionLayersPlacement"], data->decoded_value->sessionLayersPlacement, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMainSessionVisibilityChangedEXTX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["visible"] = static_cast<bool>(data->decoded_value->visible);
        FieldToJson(XrOverlayMainSessionFlagsEXTX_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["anchor"], data->anchor, options);
        FieldToJson(jdata["poseInAnchorSpace"], data->poseInAnchorSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerImageLayoutFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerImageLayoutFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerAlphaBlendFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["srcFactorColor"], data->decoded_value->srcFactorColor, options);
        FieldToJson(jdata["dstFactorColor"], data->decoded_value->dstFactorColor, options);
        FieldToJson(jdata["srcFactorAlpha"], data->decoded_value->srcFactorAlpha, options);
        FieldToJson(jdata["dstFactorAlpha"], data->decoded_value->dstFactorAlpha, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationDepthRangeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["recommendedNearZ"], data->decoded_value->recommendedNearZ, options);
        FieldToJson(jdata["minNearZ"], data->decoded_value->minNearZ, options);
        FieldToJson(jdata["recommendedFarZ"], data->decoded_value->recommendedFarZ, options);
        FieldToJson(jdata["maxFarZ"], data->decoded_value->maxFarZ, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingEGLMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["getProcAddress"], to_hex_variable_width(data->getProcAddress), options);
        FieldToJson(jdata["display"], data->display, options);
        FieldToJson(jdata["config"], data->config, options);
        FieldToJson(jdata["context"], data->context, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["nodeType"], data->decoded_value->nodeType, options);
        FieldToJson(jdata["nodeId"], &data->nodeId, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["poseInSpace"], data->poseInSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["nodeId"], &data->nodeId, options);
        FieldToJson(jdata["poseInNodeSpace"], data->poseInNodeSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsHandTracking"] = static_cast<bool>(data->decoded_value->supportsHandTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["hand"], data->decoded_value->hand, options);
        FieldToJson(jdata["handJointSet"], data->decoded_value->handJointSet, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsLocateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], data->decoded_value->locationFlags, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocityEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceVelocityFlags_t(),jdata["velocityFlags"], data->decoded_value->velocityFlags, options);
        FieldToJson(jdata["linearVelocity"], data->linearVelocity, options);
        FieldToJson(jdata["angularVelocity"], data->angularVelocity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["jointCount"], data->decoded_value->jointCount, options);
        FieldToJson(jdata["jointLocations"], data->jointLocations, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocitiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["jointCount"], data->decoded_value->jointCount, options);
        FieldToJson(jdata["jointVelocities"], data->jointVelocities, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingMeshPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsHandTrackingMesh"] = static_cast<bool>(data->decoded_value->supportsHandTrackingMesh);
        FieldToJson(jdata["maxHandMeshIndexCount"], data->decoded_value->maxHandMeshIndexCount, options);
        FieldToJson(jdata["maxHandMeshVertexCount"], data->decoded_value->maxHandMeshVertexCount, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshSpaceCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["handPoseType"], data->decoded_value->handPoseType, options);
        FieldToJson(jdata["poseInHandMeshSpace"], data->poseInHandMeshSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshUpdateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["handPoseType"], data->decoded_value->handPoseType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshIndexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["indexBufferKey"], data->decoded_value->indexBufferKey, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["position"], data->position, options);
        FieldToJson(jdata["normal"], data->normal, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["vertexUpdateTime"], data->decoded_value->vertexUpdateTime, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        jdata["indexBufferChanged"] = static_cast<bool>(data->decoded_value->indexBufferChanged);
        jdata["vertexBufferChanged"] = static_cast<bool>(data->decoded_value->vertexBufferChanged);
        FieldToJson(jdata["indexBuffer"], data->indexBuffer, options);
        FieldToJson(jdata["vertexBuffer"], data->vertexBuffer, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandPoseTypeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["handPoseType"], data->decoded_value->handPoseType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationCount"], data->decoded_value->viewConfigurationCount, options);
        FieldToJson(jdata["enabledViewConfigurationTypes"], data->enabledViewConfigurationTypes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        jdata["active"] = static_cast<bool>(data->decoded_value->active);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationCount"], data->decoded_value->viewConfigurationCount, options);
        FieldToJson(jdata["viewConfigurationStates"], data->viewConfigurationStates, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        FieldToJson(jdata["environmentBlendMode"], data->decoded_value->environmentBlendMode, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
        FieldToJson(jdata["layers"], data->layers, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationCount"], data->decoded_value->viewConfigurationCount, options);
        FieldToJson(jdata["viewConfigurationLayersInfo"], data->viewConfigurationLayersInfo, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["viewConfigurationType"], data->decoded_value->viewConfigurationType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelKeyStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["modelKey"], data->modelKey, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodePropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["parentNodeName"], &data->parentNodeName, options);
        FieldToJson(jdata["nodeName"], &data->nodeName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["nodeCapacityInput"], data->decoded_value->nodeCapacityInput, options);
        FieldToJson(jdata["nodeCountOutput"], data->decoded_value->nodeCountOutput, options);
        FieldToJson(jdata["nodeProperties"], data->nodeProperties, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodeStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["nodePose"], data->nodePose, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelStateMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["nodeCapacityInput"], data->decoded_value->nodeCapacityInput, options);
        FieldToJson(jdata["nodeCountOutput"], data->decoded_value->nodeCountOutput, options);
        FieldToJson(jdata["nodeStates"], data->nodeStates, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationViewFovEPIC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["recommendedFov"], data->recommendedFov, options);
        FieldToJson(jdata["maxMutableFov"], data->maxMutableFov, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHolographicWindowAttachmentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["holographicSpace"], data->holographicSpace, options);
        FieldToJson(jdata["coreWindow"], data->coreWindow, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["reprojectionMode"], data->decoded_value->reprojectionMode, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["position"], data->position, options);
        FieldToJson(jdata["normal"], data->normal, options);
        FieldToJson(jdata["velocity"], data->velocity, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrAndroidSurfaceSwapchainFlagsFB_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateFoveationFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateSamplerOpenGLESFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSwapchainStateSamplerVulkanFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSecureContentFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerSecureContentFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], data->decoded_value->locationFlags, options);
        FieldToJson(jdata["pose"], data->pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemBodyTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsBodyTracking"] = static_cast<bool>(data->decoded_value->supportsBodyTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["bodyJointSet"], data->decoded_value->bodyJointSet, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonJointFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["joint"], data->decoded_value->joint, options);
        FieldToJson(jdata["parentJoint"], data->decoded_value->parentJoint, options);
        FieldToJson(jdata["pose"], data->pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["jointCount"], data->decoded_value->jointCount, options);
        FieldToJson(jdata["joints"], data->joints, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointsLocateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["confidence"], data->decoded_value->confidence, options);
        FieldToJson(jdata["jointCount"], data->decoded_value->jointCount, options);
        FieldToJson(jdata["jointLocations"], data->jointLocations, options);
        FieldToJson(jdata["skeletonChangedCount"], data->decoded_value->skeletonChangedCount, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileDpadBindingEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["binding"], data->binding, options);
        HandleToJson(jdata["actionSet"], data->actionSet, options);
        FieldToJson(jdata["forceThreshold"], data->decoded_value->forceThreshold, options);
        FieldToJson(jdata["forceThresholdReleased"], data->decoded_value->forceThresholdReleased, options);
        FieldToJson(jdata["centerRegion"], data->decoded_value->centerRegion, options);
        FieldToJson(jdata["wedgeAngle"], data->decoded_value->wedgeAngle, options);
        jdata["isSticky"] = static_cast<bool>(data->decoded_value->isSticky);
        FieldToJson(jdata["onHaptic"], data->onHaptic, options);
        FieldToJson(jdata["offHaptic"], data->offHaptic, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileAnalogThresholdVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["action"], data->action, options);
        HandleToJson(jdata["binding"], data->binding, options);
        FieldToJson(jdata["onThreshold"], data->decoded_value->onThreshold, options);
        FieldToJson(jdata["offThreshold"], data->decoded_value->offThreshold, options);
        FieldToJson(jdata["onHaptic"], data->onHaptic, options);
        FieldToJson(jdata["offHaptic"], data->offHaptic, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsMotionRangeInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["handJointsMotionRange"], data->decoded_value->handJointsMotionRange, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bytes"], &data->bytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObserverCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneSphereBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["center"], data->center, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneOrientedBoxBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["extents"], data->extents, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneFrustumBoundMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["farDistance"], data->decoded_value->farDistance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneBoundsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["sphereCount"], data->decoded_value->sphereCount, options);
        FieldToJson(jdata["spheres"], data->spheres, options);
        FieldToJson(jdata["boxCount"], data->decoded_value->boxCount, options);
        FieldToJson(jdata["boxes"], data->boxes, options);
        FieldToJson(jdata["frustumCount"], data->decoded_value->frustumCount, options);
        FieldToJson(jdata["frustums"], data->frustums, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNewSceneComputeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["requestedFeatureCount"], data->decoded_value->requestedFeatureCount, options);
        FieldToJson(jdata["requestedFeatures"], data->requestedFeatures, options);
        FieldToJson(jdata["consistency"], data->decoded_value->consistency, options);
        FieldToJson(jdata["bounds"], data->bounds, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisualMeshComputeLodInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["lod"], data->decoded_value->lod, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["componentType"], data->decoded_value->componentType, options);
        FieldToJson(jdata["id"], data->id, options);
        FieldToJson(jdata["parentId"], data->parentId, options);
        FieldToJson(jdata["updateTime"], data->decoded_value->updateTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["componentCapacityInput"], data->decoded_value->componentCapacityInput, options);
        FieldToJson(jdata["componentCountOutput"], data->decoded_value->componentCountOutput, options);
        FieldToJson(jdata["components"], data->components, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["componentType"], data->decoded_value->componentType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(XrSpaceLocationFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pose"], data->pose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["locationCount"], data->decoded_value->locationCount, options);
        FieldToJson(jdata["locations"], data->locations, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsLocateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["componentIdCount"], data->decoded_value->componentIdCount, options);
        FieldToJson(jdata["componentIds"], data->componentIds, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectsMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sceneObjectCount"], data->decoded_value->sceneObjectCount, options);
        FieldToJson(jdata["sceneObjects"], data->sceneObjects, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentParentFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["parentId"], data->parentId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectTypesFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["objectTypeCount"], data->decoded_value->objectTypeCount, options);
        FieldToJson(jdata["objectTypes"], data->objectTypes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["alignment"], data->decoded_value->alignment, options);
        FieldToJson(jdata["size"], data->size, options);
        FieldToJson(jdata["meshBufferId"], data->decoded_value->meshBufferId, options);
        jdata["supportsIndicesUint16"] = static_cast<bool>(data->decoded_value->supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlanesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["scenePlaneCount"], data->decoded_value->scenePlaneCount, options);
        FieldToJson(jdata["scenePlanes"], data->scenePlanes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneAlignmentFilterInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["alignmentCount"], data->decoded_value->alignmentCount, options);
        FieldToJson(jdata["alignments"], data->alignments, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["meshBufferId"], data->decoded_value->meshBufferId, options);
        jdata["supportsIndicesUint16"] = static_cast<bool>(data->decoded_value->supportsIndicesUint16);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sceneMeshCount"], data->decoded_value->sceneMeshCount, options);
        FieldToJson(jdata["sceneMeshes"], data->sceneMeshes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["meshBufferId"], data->decoded_value->meshBufferId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshVertexBufferMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint32MSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint16MSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sceneFragmentId"], data->sceneFragmentId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDeserializeSceneFragmentMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferSize"], data->decoded_value->bufferSize, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneDeserializeInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["fragmentCount"], data->decoded_value->fragmentCount, options);
        FieldToJson(jdata["fragments"], data->fragments, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataDisplayRefreshRateChangedFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["fromDisplayRefreshRate"], data->decoded_value->fromDisplayRefreshRate, options);
        FieldToJson(jdata["toDisplayRefreshRate"], data->decoded_value->toDisplayRefreshRate, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViveTrackerPathsHTCX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["persistentPath"], data->persistentPath, options);
        HandleToJson(jdata["rolePath"], data->rolePath, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataViveTrackerConnectedHTCX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["paths"], data->paths, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFacialTrackingPropertiesHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportEyeFacialTracking"] = static_cast<bool>(data->decoded_value->supportEyeFacialTracking);
        jdata["supportLipFacialTracking"] = static_cast<bool>(data->decoded_value->supportLipFacialTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialExpressionsHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["sampleTime"], data->decoded_value->sampleTime, options);
        FieldToJson(jdata["expressionCount"], data->decoded_value->expressionCount, options);
        FieldToJson(jdata["expressionWeightings"], data->expressionWeightings, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialTrackerCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["facialTrackingType"], data->decoded_value->facialTrackingType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemColorSpacePropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["colorSpace"], data->decoded_value->colorSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4sFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
        FieldToJson(jdata["w"], data->decoded_value->w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingMeshFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["jointCapacityInput"], data->decoded_value->jointCapacityInput, options);
        FieldToJson(jdata["jointCountOutput"], data->decoded_value->jointCountOutput, options);
        FieldToJson(jdata["jointBindPoses"], data->jointBindPoses, options);
        FieldToJson(jdata["jointRadii"], data->jointRadii, options);
        FieldToJson(jdata["jointParents"], data->jointParents, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertexPositions"], data->vertexPositions, options);
        FieldToJson(jdata["vertexNormals"], data->vertexNormals, options);
        FieldToJson(jdata["vertexUVs"], data->vertexUVs, options);
        FieldToJson(jdata["vertexBlendIndices"], data->vertexBlendIndices, options);
        FieldToJson(jdata["vertexBlendWeights"], data->vertexBlendWeights, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingScaleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sensorOutput"], data->decoded_value->sensorOutput, options);
        FieldToJson(jdata["currentOutput"], data->decoded_value->currentOutput, options);
        jdata["overrideHandScale"] = static_cast<bool>(data->decoded_value->overrideHandScale);
        FieldToJson(jdata["overrideValueInput"], data->decoded_value->overrideValueInput, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingAimStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrHandTrackingAimFlagsFB_t(),jdata["status"], data->decoded_value->status, options);
        FieldToJson(jdata["aimPose"], data->aimPose, options);
        FieldToJson(jdata["pinchStrengthIndex"], data->decoded_value->pinchStrengthIndex, options);
        FieldToJson(jdata["pinchStrengthMiddle"], data->decoded_value->pinchStrengthMiddle, options);
        FieldToJson(jdata["pinchStrengthRing"], data->decoded_value->pinchStrengthRing, options);
        FieldToJson(jdata["pinchStrengthLittle"], data->decoded_value->pinchStrengthLittle, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandCapsuleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["points"], data->points, options);
        FieldToJson(jdata["radius"], data->decoded_value->radius, options);
        FieldToJson(jdata["joint"], data->decoded_value->joint, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingCapsulesStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["capsules"], data->capsules, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpatialEntityPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsSpatialEntity"] = static_cast<bool>(data->decoded_value->supportsSpatialEntity);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["poseInSpace"], data->poseInSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusSetInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["componentType"], data->decoded_value->componentType, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        jdata["changePending"] = static_cast<bool>(data->decoded_value->changePending);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpatialAnchorCreateCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["uuid"], data->uuid, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSetStatusCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["uuid"], data->uuid, options);
        FieldToJson(jdata["componentType"], data->decoded_value->componentType, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationProfileCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfoFoveationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSwapchainCreateFoveationFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateFoveationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSwapchainStateFoveationFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["profile"], data->profile, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationLevelProfileCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["level"], data->decoded_value->level, options);
        FieldToJson(jdata["verticalOffset"], data->decoded_value->verticalOffset, options);
        FieldToJson(jdata["dynamic"], data->decoded_value->dynamic, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemKeyboardTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsKeyboardTracking"] = static_cast<bool>(data->decoded_value->supportsKeyboardTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingDescriptionFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["trackedKeyboardId"], data->decoded_value->trackedKeyboardId, options);
        FieldToJson(jdata["size"], data->size, options);
        FieldToJson(XrKeyboardTrackingFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["name"], &data->name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardSpaceCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["trackedKeyboardId"], data->decoded_value->trackedKeyboardId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingQueryFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrKeyboardTrackingQueryFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrTriangleMeshCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrTriangleMeshFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["windingOrder"], data->decoded_value->windingOrder, options);
        FieldToJson(jdata["vertexCount"], data->decoded_value->vertexCount, options);
        FieldToJson(jdata["vertexBuffer"], data->vertexBuffer, options);
        FieldToJson(jdata["triangleCount"], data->decoded_value->triangleCount, options);
        FieldToJson(jdata["indexBuffer"], data->indexBuffer, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsPassthrough"] = static_cast<bool>(data->decoded_value->supportsPassthrough);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughProperties2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPassthroughCapabilityFlagsFB_t(),jdata["capabilities"], data->decoded_value->capabilities, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPassthroughFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughLayerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["passthrough"], data->passthrough, options);
        FieldToJson(XrPassthroughFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["purpose"], data->decoded_value->purpose, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["space"], data->space, options);
        HandleToJson(jdata["layerHandle"], data->layerHandle, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["layer"], data->layer, options);
        HandleToJson(jdata["mesh"], data->mesh, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["scale"], data->scale, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceTransformFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["scale"], data->scale, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughStyleFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["textureOpacityFactor"], data->decoded_value->textureOpacityFactor, options);
        FieldToJson(jdata["edgeColor"], data->edgeColor, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToRgbaFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["textureColorMap"], data->textureColorMap, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToMonoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["textureColorMap"], &data->textureColorMap, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughBrightnessContrastSaturationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["brightness"], data->decoded_value->brightness, options);
        FieldToJson(jdata["contrast"], data->decoded_value->contrast, options);
        FieldToJson(jdata["saturation"], data->decoded_value->saturation, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPassthroughStateChangedFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPassthroughStateChangedFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPathInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["path"], data->path, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vendorId"], data->decoded_value->vendorId, options);
        FieldToJson(jdata["modelName"], &data->modelName, options);
        HandleToJson(jdata["modelKey"], data->modelKey, options);
        FieldToJson(jdata["modelVersion"], data->decoded_value->modelVersion, options);
        FieldToJson(XrRenderModelFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelBufferFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["bufferCapacityInput"], data->decoded_value->bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], data->decoded_value->bufferCountOutput, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelLoadInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["modelKey"], data->modelKey, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemRenderModelPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsRenderModelLoading"] = static_cast<bool>(data->decoded_value->supportsRenderModelLoading);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelCapabilitiesRequestFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrRenderModelFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateFoveatedRenderingVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["foveatedRenderingActive"] = static_cast<bool>(data->decoded_value->foveatedRenderingActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveatedViewConfigurationViewVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["foveatedRenderingActive"] = static_cast<bool>(data->decoded_value->foveatedRenderingActive);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveatedRenderingPropertiesVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsFoveatedRendering"] = static_cast<bool>(data->decoded_value->supportsFoveatedRendering);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["depthTestRangeNearZ"], data->decoded_value->depthTestRangeNearZ, options);
        FieldToJson(jdata["depthTestRangeFarZ"], data->decoded_value->depthTestRangeFarZ, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerTrackingPropertiesVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsMarkerTracking"] = static_cast<bool>(data->decoded_value->supportsMarkerTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMarkerTrackingUpdateVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["markerId"], data->decoded_value->markerId, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        jdata["isPredicted"] = static_cast<bool>(data->decoded_value->isPredicted);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoVARJO* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["markerId"], data->decoded_value->markerId, options);
        FieldToJson(jdata["poseInMarkerSpace"], data->poseInMarkerSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["focusDistance"], data->decoded_value->focusDistance, options);
        FieldToJson(XrFrameEndInfoFlagsML_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGlobalDimmerFrameEndInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["dimmerValue"], data->decoded_value->dimmerValue, options);
        FieldToJson(XrGlobalDimmerFrameEndInfoFlagsML_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCoordinateSpaceCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["cfuid"], data->decoded_value->cfuid, options);
        FieldToJson(jdata["poseInCoordinateSpace"], data->poseInCoordinateSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerUnderstandingPropertiesML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsMarkerUnderstanding"] = static_cast<bool>(data->decoded_value->supportsMarkerUnderstanding);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["profile"], data->decoded_value->profile, options);
        FieldToJson(jdata["markerType"], data->decoded_value->markerType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorArucoInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["arucoDict"], data->decoded_value->arucoDict, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSizeInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["markerLength"], data->decoded_value->markerLength, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorAprilTagInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["aprilTagDict"], data->decoded_value->aprilTagDict, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCustomProfileInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["fpsHint"], data->decoded_value->fpsHint, options);
        FieldToJson(jdata["resolutionHint"], data->decoded_value->resolutionHint, options);
        FieldToJson(jdata["cameraHint"], data->decoded_value->cameraHint, options);
        FieldToJson(jdata["cornerRefineMethod"], data->decoded_value->cornerRefineMethod, options);
        jdata["useEdgeRefinement"] = static_cast<bool>(data->decoded_value->useEdgeRefinement);
        FieldToJson(jdata["fullAnalysisIntervalHint"], data->decoded_value->fullAnalysisIntervalHint, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSnapshotInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorStateML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["state"], data->decoded_value->state, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["markerDetector"], data->markerDetector, options);
        HandleToJson(jdata["marker"], data->marker, options);
        FieldToJson(jdata["poseInMarkerSpace"], data->poseInMarkerSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["mapUuid"], data->mapUuid, options);
        FieldToJson(jdata["mapType"], data->decoded_value->mapType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataLocalizationChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        FieldToJson(jdata["state"], data->decoded_value->state, options);
        FieldToJson(jdata["map"], data->map, options);
        FieldToJson(jdata["confidence"], data->decoded_value->confidence, options);
        FieldToJson(XrLocalizationMapErrorFlagsML_t(),jdata["errorFlags"], data->decoded_value->errorFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapQueryInfoBaseHeaderML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMapLocalizationRequestInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["mapUuid"], data->mapUuid, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapImportInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["data"], &data->data, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationEnableEventsInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceNameMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["name"], &data->name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["spatialAnchorPersistenceName"], data->spatialAnchorPersistenceName, options);
        HandleToJson(jdata["spatialAnchor"], data->spatialAnchor, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["spatialAnchorStore"], data->spatialAnchorStore, options);
        FieldToJson(jdata["spatialAnchorPersistenceName"], data->spatialAnchorPersistenceName, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["markerType"], data->decoded_value->markerType, options);
        FieldToJson(jdata["lastSeenTime"], data->decoded_value->lastSeenTime, options);
        FieldToJson(jdata["center"], data->center, options);
        FieldToJson(jdata["size"], data->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkersMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sceneMarkerCapacityInput"], data->decoded_value->sceneMarkerCapacityInput, options);
        FieldToJson(jdata["sceneMarkers"], data->sceneMarkers, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerTypeFilterMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["markerTypeCount"], data->decoded_value->markerTypeCount, options);
        FieldToJson(jdata["markerTypes"], data->markerTypes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodeMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["symbolType"], data->decoded_value->symbolType, options);
        FieldToJson(jdata["version"], data->decoded_value->version, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["qrCodeCapacityInput"], data->decoded_value->qrCodeCapacityInput, options);
        FieldToJson(jdata["qrCodes"], data->qrCodes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SPACE_QUERY_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceQueryInfoFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceFilterInfoBaseHeaderFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceUuidFilterInfoFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrSpaceComponentFilterInfoFB*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["queryAction"], data->decoded_value->queryAction, options);
        FieldToJson(jdata["maxResultCount"], data->decoded_value->maxResultCount, options);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        FieldToJson(jdata["filter"], data->filter, options);
        FieldToJson(jdata["excludeFilter"], data->excludeFilter, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceStorageLocationFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUuidFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["uuidCount"], data->decoded_value->uuidCount, options);
        FieldToJson(jdata["uuids"], data->uuids, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentFilterInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["componentType"], data->decoded_value->componentType, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["uuid"], data->uuid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["resultCapacityInput"], data->decoded_value->resultCapacityInput, options);
        FieldToJson(jdata["resultCountOutput"], data->decoded_value->resultCountOutput, options);
        FieldToJson(jdata["results"], data->results, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryResultsAvailableFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceSaveInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["persistenceMode"], data->decoded_value->persistenceMode, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceEraseInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSaveCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["uuid"], data->uuid, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceEraseCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["uuid"], data->uuid, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageFoveationVulkanFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerOpenGLESFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["minFilter"], data->decoded_value->minFilter, options);
        FieldToJson(jdata["magFilter"], data->decoded_value->magFilter, options);
        FieldToJson(jdata["wrapModeS"], data->decoded_value->wrapModeS, options);
        FieldToJson(jdata["wrapModeT"], data->decoded_value->wrapModeT, options);
        FieldToJson(jdata["swizzleRed"], data->decoded_value->swizzleRed, options);
        FieldToJson(jdata["swizzleGreen"], data->decoded_value->swizzleGreen, options);
        FieldToJson(jdata["swizzleBlue"], data->decoded_value->swizzleBlue, options);
        FieldToJson(jdata["swizzleAlpha"], data->decoded_value->swizzleAlpha, options);
        FieldToJson(jdata["maxAnisotropy"], data->decoded_value->maxAnisotropy, options);
        FieldToJson(jdata["borderColor"], data->borderColor, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerVulkanFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["minFilter"], data->decoded_value->minFilter, options);
        FieldToJson(jdata["magFilter"], data->decoded_value->magFilter, options);
        FieldToJson(jdata["mipmapMode"], data->decoded_value->mipmapMode, options);
        FieldToJson(jdata["wrapModeS"], data->decoded_value->wrapModeS, options);
        FieldToJson(jdata["wrapModeT"], data->decoded_value->wrapModeT, options);
        FieldToJson(jdata["swizzleRed"], data->decoded_value->swizzleRed, options);
        FieldToJson(jdata["swizzleGreen"], data->decoded_value->swizzleGreen, options);
        FieldToJson(jdata["swizzleBlue"], data->decoded_value->swizzleBlue, options);
        FieldToJson(jdata["swizzleAlpha"], data->decoded_value->swizzleAlpha, options);
        FieldToJson(jdata["maxAnisotropy"], data->decoded_value->maxAnisotropy, options);
        FieldToJson(jdata["borderColor"], data->borderColor, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceShareInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["spaceCount"], data->decoded_value->spaceCount, options);
        HandleToJson(jdata["spaces"], &data->spaces, options);
        FieldToJson(jdata["userCount"], data->decoded_value->userCount, options);
        HandleToJson(jdata["users"], &data->users, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceShareCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSpaceWarpInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerSpaceWarpInfoFlagsFB_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        FieldToJson(jdata["motionVectorSubImage"], data->motionVectorSubImage, options);
        FieldToJson(jdata["appSpaceDeltaPose"], data->appSpaceDeltaPose, options);
        FieldToJson(jdata["depthSubImage"], data->depthSubImage, options);
        FieldToJson(jdata["minDepth"], data->decoded_value->minDepth, options);
        FieldToJson(jdata["maxDepth"], data->decoded_value->maxDepth, options);
        FieldToJson(jdata["nearZ"], data->decoded_value->nearZ, options);
        FieldToJson(jdata["farZ"], data->decoded_value->farZ, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpaceWarpPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["recommendedMotionVectorImageRectWidth"], data->decoded_value->recommendedMotionVectorImageRectWidth, options);
        FieldToJson(jdata["recommendedMotionVectorImageRectHeight"], data->decoded_value->recommendedMotionVectorImageRectHeight, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticAmplitudeEnvelopeVibrationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["duration"], data->decoded_value->duration, options);
        FieldToJson(jdata["amplitudeCount"], data->decoded_value->amplitudeCount, options);
        FieldToJson(jdata["amplitudes"], data->amplitudes, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset3DfFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect3DfFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["bufferCapacityInput"], data->decoded_value->bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], data->decoded_value->bufferCountOutput, options);
        FieldToJson(jdata["buffer"], &data->buffer, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRoomLayoutFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["floorUuid"], data->floorUuid, options);
        FieldToJson(jdata["ceilingUuid"], data->ceilingUuid, options);
        FieldToJson(jdata["wallUuidCapacityInput"], data->decoded_value->wallUuidCapacityInput, options);
        FieldToJson(jdata["wallUuidCountOutput"], data->decoded_value->wallUuidCountOutput, options);
        FieldToJson(jdata["wallUuids"], data->wallUuids, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundary2DFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsSupportInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrSemanticLabelsSupportFlagsFB_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["recognizedLabels"], &data->recognizedLabels, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDigitalLensControlALMALENCE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrDigitalLensControlFlagsALMALENCE_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSceneCaptureCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCaptureRequestInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["requestByteCount"], data->decoded_value->requestByteCount, options);
        FieldToJson(jdata["request"], &data->request, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceContainerFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["uuidCapacityInput"], data->decoded_value->uuidCapacityInput, options);
        FieldToJson(jdata["uuidCountOutput"], data->decoded_value->uuidCountOutput, options);
        FieldToJson(jdata["uuids"], data->uuids, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrFoveationEyeTrackedProfileCreateFlagsMETA_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["foveationCenter"], data->foveationCenter, options);
        FieldToJson(XrFoveationEyeTrackedStateFlagsMETA_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsFoveationEyeTracked"] = static_cast<bool>(data->decoded_value->supportsFoveationEyeTracked);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsFaceTracking"] = static_cast<bool>(data->decoded_value->supportsFaceTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["faceExpressionSet"], data->decoded_value->faceExpressionSet, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionStatusFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["isValid"] = static_cast<bool>(data->decoded_value->isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(data->decoded_value->isEyeFollowingBlendshapesValid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeightsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["weightCount"], data->decoded_value->weightCount, options);
        FieldToJson(jdata["weights"], data->weights, options);
        FieldToJson(jdata["confidenceCount"], data->decoded_value->confidenceCount, options);
        FieldToJson(jdata["confidences"], data->confidences, options);
        FieldToJson(jdata["status"], data->status, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["isValid"] = static_cast<bool>(data->decoded_value->isValid);
        FieldToJson(jdata["gazePose"], data->gazePose, options);
        FieldToJson(jdata["gazeConfidence"], data->decoded_value->gazeConfidence, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeTrackerCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeTrackingPropertiesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsEyeTracking"] = static_cast<bool>(data->decoded_value->supportsEyeTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["gaze"], data->gaze, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughKeyboardHandsIntensityFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["leftHandIntensity"], data->decoded_value->leftHandIntensity, options);
        FieldToJson(jdata["rightHandIntensity"], data->decoded_value->rightHandIntensity, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSettingsFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerSettingsFlagsFB_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticPcmVibrationFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["bufferSize"], data->decoded_value->bufferSize, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["sampleRate"], data->decoded_value->sampleRate, options);
        jdata["append"] = static_cast<bool>(data->decoded_value->append);
        FieldToJson(jdata["samplesConsumed"], data->samplesConsumed, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDevicePcmSampleRateStateFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["sampleRate"], data->decoded_value->sampleRate, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["depthMask"] = static_cast<bool>(data->decoded_value->depthMask);
        FieldToJson(jdata["compareOp"], data->decoded_value->compareOp, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalDimmingFrameEndInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["localDimmingMode"], data->decoded_value->localDimmingMode, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughPreferencesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPassthroughPreferenceFlagsMETA_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemVirtualKeyboardPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsVirtualKeyboard"] = static_cast<bool>(data->decoded_value->supportsVirtualKeyboard);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["locationType"], data->decoded_value->locationType, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["poseInSpace"], data->poseInSpace, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardLocationInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["locationType"], data->decoded_value->locationType, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["poseInSpace"], data->poseInSpace, options);
        FieldToJson(jdata["scale"], data->decoded_value->scale, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["visible"] = static_cast<bool>(data->decoded_value->visible);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardAnimationStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["animationIndex"], data->decoded_value->animationIndex, options);
        FieldToJson(jdata["fraction"], data->decoded_value->fraction, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelAnimationStatesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["stateCapacityInput"], data->decoded_value->stateCapacityInput, options);
        FieldToJson(jdata["stateCountOutput"], data->decoded_value->stateCountOutput, options);
        FieldToJson(jdata["states"], data->states, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextureDataMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["textureWidth"], data->decoded_value->textureWidth, options);
        FieldToJson(jdata["textureHeight"], data->decoded_value->textureHeight, options);
        FieldToJson(jdata["bufferCapacityInput"], data->decoded_value->bufferCapacityInput, options);
        FieldToJson(jdata["bufferCountOutput"], data->decoded_value->bufferCountOutput, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardInputInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["inputSource"], data->decoded_value->inputSource, options);
        HandleToJson(jdata["inputSpace"], data->inputSpace, options);
        FieldToJson(jdata["inputPoseInSpace"], data->inputPoseInSpace, options);
        FieldToJson(XrVirtualKeyboardInputStateFlagsMETA_t(),jdata["inputState"], data->decoded_value->inputState, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["textContext"], &data->textContext, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardCommitTextMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["keyboard"], data->keyboard, options);
        FieldToJson(jdata["text"], &data->text, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardBackspaceMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["keyboard"], data->keyboard, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardEnterMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["keyboard"], data->keyboard, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardShownMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["keyboard"], data->keyboard, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardHiddenMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["keyboard"], data->keyboard, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraIntrinsicsOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["lastChangeTime"], data->decoded_value->lastChangeTime, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["virtualNearPlaneDistance"], data->decoded_value->virtualNearPlaneDistance, options);
        FieldToJson(jdata["virtualFarPlaneDistance"], data->decoded_value->virtualFarPlaneDistance, options);
        FieldToJson(jdata["imageSensorPixelResolution"], data->imageSensorPixelResolution, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraExtrinsicsOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["lastChangeTime"], data->decoded_value->lastChangeTime, options);
        FieldToJson(XrExternalCameraStatusFlagsOCULUS_t(),jdata["cameraStatusFlags"], data->decoded_value->cameraStatusFlags, options);
        FieldToJson(jdata["attachedToDevice"], data->decoded_value->attachedToDevice, options);
        FieldToJson(jdata["relativePose"], data->relativePose, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraOCULUS* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["intrinsics"], data->intrinsics, options);
        FieldToJson(jdata["extrinsics"], data->extrinsics, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["additionalCreateFlags"], data->decoded_value->additionalCreateFlags, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["additionalUsageFlags"], data->decoded_value->additionalUsageFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsCounterMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPerformanceMetricsCounterFlagsMETA_t(),jdata["counterFlags"], data->decoded_value->counterFlags, options);
        FieldToJson(jdata["counterUnit"], data->decoded_value->counterUnit, options);
        FieldToJson(jdata["uintValue"], data->decoded_value->uintValue, options);
        FieldToJson(jdata["floatValue"], data->decoded_value->floatValue, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceListSaveInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["spaceCount"], data->decoded_value->spaceCount, options);
        HandleToJson(jdata["spaces"], &data->spaces, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceListSaveCompleteFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["requestId"], data->requestId, options);
        FieldToJson(jdata["result"], data->decoded_value->result, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUserCreateInfoFB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["userId"], data->decoded_value->userId, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHeadsetIdPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["id"], data->id, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["recommendedImageDimensions"], data->recommendedImageDimensions, options);
        jdata["isValid"] = static_cast<bool>(data->decoded_value->isValid);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionGetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["layer"], data->layer, options);
        FieldToJson(jdata["predictedDisplayTime"], data->decoded_value->predictedDisplayTime, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutDataMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferSize"], data->decoded_value->bufferSize, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["channels"], data->decoded_value->channels, options);
        FieldToJson(jdata["resolution"], data->decoded_value->resolution, options);
        FieldToJson(jdata["data"], data->data, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutUpdateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["data"], data->data, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapLutMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["colorLut"], data->colorLut, options);
        FieldToJson(jdata["weight"], data->decoded_value->weight, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapInterpolatedLutMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["sourceColorLut"], data->sourceColorLut, options);
        HandleToJson(jdata["targetColorLut"], data->targetColorLut, options);
        FieldToJson(jdata["weight"], data->decoded_value->weight, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughColorLutPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["maxColorLutResolution"], data->decoded_value->maxColorLutResolution, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshGetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["indexCapacityInput"], data->decoded_value->indexCapacityInput, options);
        FieldToJson(jdata["indexCountOutput"], data->decoded_value->indexCountOutput, options);
        FieldToJson(jdata["indices"], data->indices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingProperties2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsVisualFaceTracking"] = static_cast<bool>(data->decoded_value->supportsVisualFaceTracking);
        jdata["supportsAudioFaceTracking"] = static_cast<bool>(data->decoded_value->supportsAudioFaceTracking);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfo2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["faceExpressionSet"], data->decoded_value->faceExpressionSet, options);
        FieldToJson(jdata["requestedDataSourceCount"], data->decoded_value->requestedDataSourceCount, options);
        FieldToJson(jdata["requestedDataSources"], data->requestedDataSources, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfo2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeights2FB* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["weightCount"], data->decoded_value->weightCount, options);
        FieldToJson(jdata["weights"], data->weights, options);
        FieldToJson(jdata["confidenceCount"], data->decoded_value->confidenceCount, options);
        FieldToJson(jdata["confidences"], data->confidences, options);
        jdata["isValid"] = static_cast<bool>(data->decoded_value->isValid);
        jdata["isEyeFollowingBlendshapesValid"] = static_cast<bool>(data->decoded_value->isEyeFollowingBlendshapesValid);
        FieldToJson(jdata["dataSource"], data->decoded_value->dataSource, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthProviderCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrEnvironmentDepthProviderCreateFlagsMETA_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrEnvironmentDepthSwapchainCreateFlagsMETA_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainStateMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageAcquireInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["displayTime"], data->decoded_value->displayTime, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageViewMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["fov"], data->fov, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["swapchainIndex"], data->decoded_value->swapchainIndex, options);
        FieldToJson(jdata["nearZ"], data->decoded_value->nearZ, options);
        FieldToJson(jdata["farZ"], data->decoded_value->farZ, options);
        FieldToJson(jdata["views"], data->views, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEnvironmentDepthPropertiesMETA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsEnvironmentDepth"] = static_cast<bool>(data->decoded_value->supportsEnvironmentDepth);
        jdata["supportsHandRemoval"] = static_cast<bool>(data->decoded_value->supportsHandRemoval);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["form"], data->decoded_value->form, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["alpha"], data->decoded_value->alpha, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughMeshTransformInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCount"], data->decoded_value->vertexCount, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["indexCount"], data->decoded_value->indexCount, options);
        FieldToJson(jdata["indices"], data->indices, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["scale"], data->scale, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrCompositionLayerFlags_t(),jdata["layerFlags"], data->decoded_value->layerFlags, options);
        HandleToJson(jdata["space"], data->space, options);
        HandleToJson(jdata["passthrough"], data->passthrough, options);
        FieldToJson(jdata["color"], data->color, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationApplyInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["subImageCount"], data->decoded_value->subImageCount, options);
        FieldToJson(jdata["subImages"], data->subImages, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationConfigurationHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["level"], data->decoded_value->level, options);
        FieldToJson(jdata["clearFovDegree"], data->decoded_value->clearFovDegree, options);
        FieldToJson(jdata["focalCenterOffset"], data->focalCenterOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationDynamicModeInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrFoveationDynamicFlagsHTC_t(),jdata["dynamicFlags"], data->decoded_value->dynamicFlags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationCustomModeInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["configCount"], data->decoded_value->configCount, options);
        FieldToJson(jdata["configs"], data->configs, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemAnchorPropertiesHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsAnchor"] = static_cast<bool>(data->decoded_value->supportsAnchor);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorNameHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["name"], &data->name, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoHTC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["space"], data->space, options);
        FieldToJson(jdata["poseInSpace"], data->poseInSpace, options);
        FieldToJson(jdata["name"], data->name, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPriorityEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["actionSet"], data->actionSet, options);
        FieldToJson(jdata["priorityOverride"], data->decoded_value->priorityOverride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPrioritiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["actionSetPriorityCount"], data->decoded_value->actionSetPriorityCount, options);
        FieldToJson(jdata["actionSetPriorities"], data->actionSetPriorities, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsForceFeedbackCurl"] = static_cast<bool>(data->decoded_value->supportsForceFeedbackCurl);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["value"], data->decoded_value->value, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationsMNDX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["locationCount"], data->decoded_value->locationCount, options);
        FieldToJson(jdata["locations"], data->locations, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["requestedDataSourceCount"], data->decoded_value->requestedDataSourceCount, options);
        FieldToJson(jdata["requestedDataSources"], data->requestedDataSources, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceStateEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["isActive"] = static_cast<bool>(data->decoded_value->isActive);
        FieldToJson(jdata["dataSource"], data->decoded_value->dataSource, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPlaneDetectionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPlaneDetectionCapabilityFlagsEXT_t(),jdata["supportedFeatures"], data->decoded_value->supportedFeatures, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(XrPlaneDetectorFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["orientationCount"], data->decoded_value->orientationCount, options);
        FieldToJson(jdata["orientations"], data->orientations, options);
        FieldToJson(jdata["semanticTypeCount"], data->decoded_value->semanticTypeCount, options);
        FieldToJson(jdata["semanticTypes"], data->semanticTypes, options);
        FieldToJson(jdata["maxPlanes"], data->decoded_value->maxPlanes, options);
        FieldToJson(jdata["minArea"], data->decoded_value->minArea, options);
        FieldToJson(jdata["boundingBoxPose"], data->boundingBoxPose, options);
        FieldToJson(jdata["boundingBoxExtent"], data->boundingBoxExtent, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorGetInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["baseSpace"], data->baseSpace, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["planeId"], data->decoded_value->planeId, options);
        FieldToJson(XrSpaceLocationFlags_t(),jdata["locationFlags"], data->decoded_value->locationFlags, options);
        FieldToJson(jdata["pose"], data->pose, options);
        FieldToJson(jdata["extents"], data->extents, options);
        FieldToJson(jdata["orientation"], data->decoded_value->orientation, options);
        FieldToJson(jdata["semanticType"], data->decoded_value->semanticType, options);
        FieldToJson(jdata["polygonBufferCount"], data->decoded_value->polygonBufferCount, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["planeLocationCapacityInput"], data->decoded_value->planeLocationCapacityInput, options);
        FieldToJson(jdata["planeLocationCountOutput"], data->decoded_value->planeLocationCountOutput, options);
        FieldToJson(jdata["planeLocations"], data->planeLocations, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorPolygonBufferEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["vertexCapacityInput"], data->decoded_value->vertexCapacityInput, options);
        FieldToJson(jdata["vertexCountOutput"], data->decoded_value->vertexCountOutput, options);
        FieldToJson(jdata["vertices"], data->vertices, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCancelInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["future"], data->future, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["future"], data->future, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionBaseHeaderEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        switch (data->decoded_value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_FUTURE_COMPLETION_EXT:
                FieldToJson(jdata,
                            reinterpret_cast<const Decoded_XrFutureCompletionEXT*>(data),
                            options);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["futureResult"], data->decoded_value->futureResult, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["futureResult"], data->decoded_value->futureResult, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollResultEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["state"], data->decoded_value->state, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataUserPresenceChangedEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["session"], data->session, options);
        jdata["isUserPresent"] = static_cast<bool>(data->decoded_value->isUserPresent);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemUserPresencePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["supportsUserPresence"] = static_cast<bool>(data->decoded_value->supportsUserPresence);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataHeadsetFitChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["status"], data->decoded_value->status, options);
        FieldToJson(jdata["time"], data->decoded_value->time, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEyeCalibrationChangedML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["status"], data->decoded_value->status, options);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUserCalibrationEnableEventsInfoML* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enabled"] = static_cast<bool>(data->decoded_value->enabled);
        FieldToJson(jdata["next"], data->next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data, const JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        const auto type = reinterpret_cast<const XrBaseInStructure*>(data->GetPointer())->type;
        switch (type)
        {
            case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrActiveActionSetPrioritiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrBindingModificationsKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerAlphaBlendFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerColorScaleBiasKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerDepthTestVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerImageLayoutFB*>(data->GetMetaStructPointer());
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

            case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSecureContentFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSettingsFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrCompositionLayerSpaceWarpInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrDebugUtilsMessengerCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrEyeGazeSampleTimeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveatedViewConfigurationViewVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationCustomModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationDynamicModeInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrFoveationLevelProfileCreateInfoFB*>(data->GetMetaStructPointer());
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

            case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingEGLMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingMetalKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLESAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWaylandKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLWin32KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXcbKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingOpenGLXlibKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrGraphicsBindingVulkanKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointVelocitiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandJointsMotionRangeInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandPoseTypeInfoMSFT*>(data->GetMetaStructPointer());
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

            case XR_TYPE_HAND_TRACKING_SCALE_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHandTrackingScaleFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrHolographicWindowAttachmentMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            {
                const auto* next = reinterpret_cast<const Decoded_XrInstanceCreateInfoAndroidKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrLocalDimmingFrameEndInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorAprilTagInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorArucoInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorCustomProfileInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrMarkerDetectorSizeInfoML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughBrightnessContrastSaturationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapInterpolatedLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapLutMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToMonoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughColorMapMonoToRgbaFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrPassthroughMeshTransformInfoHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrRenderModelCapabilitiesRequestFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneComponentParentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerQRCodesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkerTypeFilterMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MARKERS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMarkersMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_MESHES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneMeshesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectTypesFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_OBJECTS_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSceneObjectsMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlaneAlignmentFilterInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SCENE_PLANES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrScenePlanesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationFrameStateMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSessionCreateInfoOverlayEXTX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceStorageLocationFilterInfoFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SPACE_VELOCITIES:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceVelocities*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SPACE_VELOCITY:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSpaceVelocity*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainCreateInfoFoveationFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSwapchainImageFoveationVulkanFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemAnchorPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemBodyTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemColorSpacePropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEnvironmentDepthPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeGazeInteractionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemEyeTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFaceTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFacialTrackingPropertiesHTC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveatedRenderingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingMeshPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHandTrackingPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemHeadsetIdPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemKeyboardTrackingPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerTrackingPropertiesVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemMarkerUnderstandingPropertiesML*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughColorLutPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughProperties2FB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPassthroughPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemPlaneDetectionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemRenderModelPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpaceWarpPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemSpatialEntityPropertiesFB*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemUserPresencePropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrSystemVirtualKeyboardPropertiesMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationDepthRangeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewConfigurationViewFovEPIC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            {
                const auto* next = reinterpret_cast<const Decoded_XrViewLocateFoveatedRenderingVARJO*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVisualMeshComputeLodInfoMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
                break;
            }

            case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            {
                const auto* next = reinterpret_cast<const Decoded_XrVulkanSwapchainCreateInfoMETA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, next, options);
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
