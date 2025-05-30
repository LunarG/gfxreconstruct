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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/custom_openxr_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/openxr_next_node.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_struct_decoders_forward.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_XrApiLayerProperties
{
    using struct_type = XrApiLayerProperties;

    XrApiLayerProperties* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_XrExtensionProperties
{
    using struct_type = XrExtensionProperties;

    XrExtensionProperties* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder extensionName;
};

struct Decoded_XrApplicationInfo
{
    using struct_type = XrApplicationInfo;

    XrApplicationInfo* decoded_value{ nullptr };

    StringDecoder applicationName;
    StringDecoder engineName;
};

struct Decoded_XrInstanceCreateInfo
{
    using struct_type = XrInstanceCreateInfo;

    XrInstanceCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrApplicationInfo* applicationInfo{ nullptr };
    StringArrayDecoder enabledApiLayerNames;
    StringArrayDecoder enabledExtensionNames;
};

struct Decoded_XrInstanceProperties
{
    using struct_type = XrInstanceProperties;

    XrInstanceProperties* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder runtimeName;
};

struct Decoded_XrEventDataBuffer
{
    using struct_type = XrEventDataBuffer;

    XrEventDataBuffer* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> varying;
};

struct Decoded_XrSystemGetInfo
{
    using struct_type = XrSystemGetInfo;

    XrSystemGetInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemGraphicsProperties
{
    using struct_type = XrSystemGraphicsProperties;

    XrSystemGraphicsProperties* decoded_value{ nullptr };
};

struct Decoded_XrSystemTrackingProperties
{
    using struct_type = XrSystemTrackingProperties;

    XrSystemTrackingProperties* decoded_value{ nullptr };
};

struct Decoded_XrSystemProperties
{
    using struct_type = XrSystemProperties;

    XrSystemProperties* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId systemId{ format::kNullHandleId };
    StringDecoder systemName;
    Decoded_XrSystemGraphicsProperties* graphicsProperties{ nullptr };
    Decoded_XrSystemTrackingProperties* trackingProperties{ nullptr };
};

struct Decoded_XrSessionCreateInfo
{
    using struct_type = XrSessionCreateInfo;

    XrSessionCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId systemId{ format::kNullHandleId };
};

struct Decoded_XrVector3f
{
    using struct_type = XrVector3f;

    XrVector3f* decoded_value{ nullptr };
};

struct Decoded_XrSpaceVelocity
{
    using struct_type = XrSpaceVelocity;

    XrSpaceVelocity* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrVector3f* linearVelocity{ nullptr };
    Decoded_XrVector3f* angularVelocity{ nullptr };
};

struct Decoded_XrQuaternionf
{
    using struct_type = XrQuaternionf;

    XrQuaternionf* decoded_value{ nullptr };
};

struct Decoded_XrPosef
{
    using struct_type = XrPosef;

    XrPosef* decoded_value{ nullptr };

    Decoded_XrQuaternionf* orientation{ nullptr };
    Decoded_XrVector3f* position{ nullptr };
};

struct Decoded_XrReferenceSpaceCreateInfo
{
    using struct_type = XrReferenceSpaceCreateInfo;

    XrReferenceSpaceCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* poseInReferenceSpace{ nullptr };
};

struct Decoded_XrExtent2Df
{
    using struct_type = XrExtent2Df;

    XrExtent2Df* decoded_value{ nullptr };
};

struct Decoded_XrActionSpaceCreateInfo
{
    using struct_type = XrActionSpaceCreateInfo;

    XrActionSpaceCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId action{ format::kNullHandleId };
    format::HandleId subactionPath{ format::kNullHandleId };
    Decoded_XrPosef* poseInActionSpace{ nullptr };
};

struct Decoded_XrSpaceLocation
{
    using struct_type = XrSpaceLocation;

    XrSpaceLocation* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrViewConfigurationProperties
{
    using struct_type = XrViewConfigurationProperties;

    XrViewConfigurationProperties* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrViewConfigurationView
{
    using struct_type = XrViewConfigurationView;

    XrViewConfigurationView* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainCreateInfo
{
    using struct_type = XrSwapchainCreateInfo;

    XrSwapchainCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainImageAcquireInfo
{
    using struct_type = XrSwapchainImageAcquireInfo;

    XrSwapchainImageAcquireInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainImageWaitInfo
{
    using struct_type = XrSwapchainImageWaitInfo;

    XrSwapchainImageWaitInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainImageReleaseInfo
{
    using struct_type = XrSwapchainImageReleaseInfo;

    XrSwapchainImageReleaseInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSessionBeginInfo
{
    using struct_type = XrSessionBeginInfo;

    XrSessionBeginInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFrameWaitInfo
{
    using struct_type = XrFrameWaitInfo;

    XrFrameWaitInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFrameState
{
    using struct_type = XrFrameState;

    XrFrameState* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFrameBeginInfo
{
    using struct_type = XrFrameBeginInfo;

    XrFrameBeginInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFrameEndInfo
{
    using struct_type = XrFrameEndInfo;

    XrFrameEndInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrCompositionLayerBaseHeader*>* layers{ nullptr };
};

struct Decoded_XrViewLocateInfo
{
    using struct_type = XrViewLocateInfo;

    XrViewLocateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
};

struct Decoded_XrViewState
{
    using struct_type = XrViewState;

    XrViewState* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFovf
{
    using struct_type = XrFovf;

    XrFovf* decoded_value{ nullptr };
};

struct Decoded_XrView
{
    using struct_type = XrView;

    XrView* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrFovf* fov{ nullptr };
};

struct Decoded_XrActionSetCreateInfo
{
    using struct_type = XrActionSetCreateInfo;

    XrActionSetCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder actionSetName;
    StringDecoder localizedActionSetName;
};

struct Decoded_XrActionCreateInfo
{
    using struct_type = XrActionCreateInfo;

    XrActionCreateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder actionName;
    HandlePointerDecoder<XrPath> subactionPaths;
    StringDecoder localizedActionName;
};

struct Decoded_XrActionSuggestedBinding
{
    using struct_type = XrActionSuggestedBinding;

    XrActionSuggestedBinding* decoded_value{ nullptr };

    format::HandleId action{ format::kNullHandleId };
    format::HandleId binding{ format::kNullHandleId };
};

struct Decoded_XrInteractionProfileSuggestedBinding
{
    using struct_type = XrInteractionProfileSuggestedBinding;

    XrInteractionProfileSuggestedBinding* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId interactionProfile{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrActionSuggestedBinding>* suggestedBindings{ nullptr };
};

struct Decoded_XrSessionActionSetsAttachInfo
{
    using struct_type = XrSessionActionSetsAttachInfo;

    XrSessionActionSetsAttachInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    HandlePointerDecoder<XrActionSet> actionSets;
};

struct Decoded_XrInteractionProfileState
{
    using struct_type = XrInteractionProfileState;

    XrInteractionProfileState* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId interactionProfile{ format::kNullHandleId };
};

struct Decoded_XrActionStateGetInfo
{
    using struct_type = XrActionStateGetInfo;

    XrActionStateGetInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId action{ format::kNullHandleId };
    format::HandleId subactionPath{ format::kNullHandleId };
};

struct Decoded_XrActionStateBoolean
{
    using struct_type = XrActionStateBoolean;

    XrActionStateBoolean* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrActionStateFloat
{
    using struct_type = XrActionStateFloat;

    XrActionStateFloat* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVector2f
{
    using struct_type = XrVector2f;

    XrVector2f* decoded_value{ nullptr };
};

struct Decoded_XrActionStateVector2f
{
    using struct_type = XrActionStateVector2f;

    XrActionStateVector2f* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrVector2f* currentState{ nullptr };
};

struct Decoded_XrActionStatePose
{
    using struct_type = XrActionStatePose;

    XrActionStatePose* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrActiveActionSet
{
    using struct_type = XrActiveActionSet;

    XrActiveActionSet* decoded_value{ nullptr };

    format::HandleId actionSet{ format::kNullHandleId };
    format::HandleId subactionPath{ format::kNullHandleId };
};

struct Decoded_XrActionsSyncInfo
{
    using struct_type = XrActionsSyncInfo;

    XrActionsSyncInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrActiveActionSet>* activeActionSets{ nullptr };
};

struct Decoded_XrBoundSourcesForActionEnumerateInfo
{
    using struct_type = XrBoundSourcesForActionEnumerateInfo;

    XrBoundSourcesForActionEnumerateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId action{ format::kNullHandleId };
};

struct Decoded_XrInputSourceLocalizedNameGetInfo
{
    using struct_type = XrInputSourceLocalizedNameGetInfo;

    XrInputSourceLocalizedNameGetInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId sourcePath{ format::kNullHandleId };
};

struct Decoded_XrHapticActionInfo
{
    using struct_type = XrHapticActionInfo;

    XrHapticActionInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId action{ format::kNullHandleId };
    format::HandleId subactionPath{ format::kNullHandleId };
};

struct Decoded_XrOffset2Di
{
    using struct_type = XrOffset2Di;

    XrOffset2Di* decoded_value{ nullptr };
};

struct Decoded_XrExtent2Di
{
    using struct_type = XrExtent2Di;

    XrExtent2Di* decoded_value{ nullptr };
};

struct Decoded_XrRect2Di
{
    using struct_type = XrRect2Di;

    XrRect2Di* decoded_value{ nullptr };

    Decoded_XrOffset2Di* offset{ nullptr };
    Decoded_XrExtent2Di* extent{ nullptr };
};

struct Decoded_XrSwapchainSubImage
{
    using struct_type = XrSwapchainSubImage;

    XrSwapchainSubImage* decoded_value{ nullptr };

    format::HandleId swapchain{ format::kNullHandleId };
    Decoded_XrRect2Di* imageRect{ nullptr };
};

struct Decoded_XrCompositionLayerProjectionView
{
    using struct_type = XrCompositionLayerProjectionView;

    XrCompositionLayerProjectionView* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrFovf* fov{ nullptr };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
};

struct Decoded_XrCompositionLayerProjection
{
    using struct_type = XrCompositionLayerProjection;

    XrCompositionLayerProjection* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrCompositionLayerProjectionView>* views{ nullptr };
};

struct Decoded_XrCompositionLayerQuad
{
    using struct_type = XrCompositionLayerQuad;

    XrCompositionLayerQuad* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrExtent2Df* size{ nullptr };
};

struct Decoded_XrEventDataEventsLost
{
    using struct_type = XrEventDataEventsLost;

    XrEventDataEventsLost* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataInstanceLossPending
{
    using struct_type = XrEventDataInstanceLossPending;

    XrEventDataInstanceLossPending* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataSessionStateChanged
{
    using struct_type = XrEventDataSessionStateChanged;

    XrEventDataSessionStateChanged* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_XrEventDataReferenceSpaceChangePending
{
    using struct_type = XrEventDataReferenceSpaceChangePending;

    XrEventDataReferenceSpaceChangePending* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
    Decoded_XrPosef* poseInPreviousSpace{ nullptr };
};

struct Decoded_XrEventDataInteractionProfileChanged
{
    using struct_type = XrEventDataInteractionProfileChanged;

    XrEventDataInteractionProfileChanged* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_XrHapticVibration
{
    using struct_type = XrHapticVibration;

    XrHapticVibration* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrOffset2Df
{
    using struct_type = XrOffset2Df;

    XrOffset2Df* decoded_value{ nullptr };
};

struct Decoded_XrRect2Df
{
    using struct_type = XrRect2Df;

    XrRect2Df* decoded_value{ nullptr };

    Decoded_XrOffset2Df* offset{ nullptr };
    Decoded_XrExtent2Df* extent{ nullptr };
};

struct Decoded_XrVector4f
{
    using struct_type = XrVector4f;

    XrVector4f* decoded_value{ nullptr };
};

struct Decoded_XrColor4f
{
    using struct_type = XrColor4f;

    XrColor4f* decoded_value{ nullptr };
};

struct Decoded_XrApiLayerNextInfo
{
    using struct_type = XrApiLayerNextInfo;

    XrApiLayerNextInfo* decoded_value{ nullptr };

    StringDecoder layerName;
    uint64_t nextGetInstanceProcAddr{ 0 };
    uint64_t nextCreateApiLayerInstance{ 0 };
    StructPointerDecoder<Decoded_XrApiLayerNextInfo>* next{ nullptr };
};

struct Decoded_XrApiLayerCreateInfo
{
    using struct_type = XrApiLayerCreateInfo;

    XrApiLayerCreateInfo* decoded_value{ nullptr };

    uint64_t loaderInstance{ 0 };
    StringDecoder settings_file_location;
    StructPointerDecoder<Decoded_XrApiLayerNextInfo>* nextInfo{ nullptr };
};

struct Decoded_XrNegotiateApiLayerRequest
{
    using struct_type = XrNegotiateApiLayerRequest;

    XrNegotiateApiLayerRequest* decoded_value{ nullptr };

    uint64_t getInstanceProcAddr{ 0 };
    uint64_t createApiLayerInstance{ 0 };
};

struct Decoded_XrColor3f
{
    using struct_type = XrColor3f;

    XrColor3f* decoded_value{ nullptr };
};

struct Decoded_XrExtent3Df
{
    using struct_type = XrExtent3Df;

    XrExtent3Df* decoded_value{ nullptr };
};

struct Decoded_XrSpheref
{
    using struct_type = XrSpheref;

    XrSpheref* decoded_value{ nullptr };

    Decoded_XrPosef* center{ nullptr };
};

struct Decoded_XrBoxf
{
    using struct_type = XrBoxf;

    XrBoxf* decoded_value{ nullptr };

    Decoded_XrPosef* center{ nullptr };
    Decoded_XrExtent3Df* extents{ nullptr };
};

struct Decoded_XrFrustumf
{
    using struct_type = XrFrustumf;

    XrFrustumf* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrFovf* fov{ nullptr };
};

struct Decoded_XrUuid
{
    using struct_type = XrUuid;

    XrUuid* decoded_value{ nullptr };

    PointerDecoder<uint8_t> data;
};

struct Decoded_XrSpacesLocateInfo
{
    using struct_type = XrSpacesLocateInfo;

    XrSpacesLocateInfo* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
    HandlePointerDecoder<XrSpace> spaces;
};

struct Decoded_XrSpaceLocationData
{
    using struct_type = XrSpaceLocationData;

    XrSpaceLocationData* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrSpaceLocations
{
    using struct_type = XrSpaceLocations;

    XrSpaceLocations* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSpaceLocationData>* locations{ nullptr };
};

struct Decoded_XrSpaceVelocityData
{
    using struct_type = XrSpaceVelocityData;

    XrSpaceVelocityData* decoded_value{ nullptr };

    Decoded_XrVector3f* linearVelocity{ nullptr };
    Decoded_XrVector3f* angularVelocity{ nullptr };
};

struct Decoded_XrSpaceVelocities
{
    using struct_type = XrSpaceVelocities;

    XrSpaceVelocities* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSpaceVelocityData>* velocities{ nullptr };
};

struct Decoded_XrCompositionLayerCubeKHR
{
    using struct_type = XrCompositionLayerCubeKHR;

    XrCompositionLayerCubeKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    format::HandleId swapchain{ format::kNullHandleId };
    Decoded_XrQuaternionf* orientation{ nullptr };
};

struct Decoded_XrInstanceCreateInfoAndroidKHR
{
    using struct_type = XrInstanceCreateInfoAndroidKHR;

    XrInstanceCreateInfoAndroidKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t applicationVM{ 0 };
    uint64_t applicationActivity{ 0 };
};

struct Decoded_XrCompositionLayerDepthInfoKHR
{
    using struct_type = XrCompositionLayerDepthInfoKHR;

    XrCompositionLayerDepthInfoKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
};

struct Decoded_XrVulkanSwapchainFormatListCreateInfoKHR
{
    using struct_type = XrVulkanSwapchainFormatListCreateInfoKHR;

    XrVulkanSwapchainFormatListCreateInfoKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<VkFormat> viewFormats;
};

struct Decoded_XrCompositionLayerCylinderKHR
{
    using struct_type = XrCompositionLayerCylinderKHR;

    XrCompositionLayerCylinderKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrCompositionLayerEquirectKHR
{
    using struct_type = XrCompositionLayerEquirectKHR;

    XrCompositionLayerEquirectKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrVector2f* scale{ nullptr };
    Decoded_XrVector2f* bias{ nullptr };
};

struct Decoded_XrGraphicsBindingOpenGLWin32KHR
{
    using struct_type = XrGraphicsBindingOpenGLWin32KHR;

    XrGraphicsBindingOpenGLWin32KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t hDC{ 0 };
    uint64_t hGLRC{ 0 };
};

struct Decoded_XrGraphicsBindingOpenGLXlibKHR
{
    using struct_type = XrGraphicsBindingOpenGLXlibKHR;

    XrGraphicsBindingOpenGLXlibKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t xDisplay{ 0 };
    uint64_t glxFBConfig{ 0 };
    uint64_t glxContext{ 0 };
};

struct Decoded_XrGraphicsBindingOpenGLXcbKHR
{
    using struct_type = XrGraphicsBindingOpenGLXcbKHR;

    XrGraphicsBindingOpenGLXcbKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t connection{ 0 };
};

struct Decoded_XrGraphicsBindingOpenGLWaylandKHR
{
    using struct_type = XrGraphicsBindingOpenGLWaylandKHR;

    XrGraphicsBindingOpenGLWaylandKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t display{ 0 };
};

struct Decoded_XrSwapchainImageOpenGLKHR
{
    using struct_type = XrSwapchainImageOpenGLKHR;

    XrSwapchainImageOpenGLKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsRequirementsOpenGLKHR
{
    using struct_type = XrGraphicsRequirementsOpenGLKHR;

    XrGraphicsRequirementsOpenGLKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingOpenGLESAndroidKHR
{
    using struct_type = XrGraphicsBindingOpenGLESAndroidKHR;

    XrGraphicsBindingOpenGLESAndroidKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t display{ 0 };
    uint64_t config{ 0 };
    uint64_t context{ 0 };
};

struct Decoded_XrSwapchainImageOpenGLESKHR
{
    using struct_type = XrSwapchainImageOpenGLESKHR;

    XrSwapchainImageOpenGLESKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsRequirementsOpenGLESKHR
{
    using struct_type = XrGraphicsRequirementsOpenGLESKHR;

    XrGraphicsRequirementsOpenGLESKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingVulkanKHR
{
    using struct_type = XrGraphicsBindingVulkanKHR;

    XrGraphicsBindingVulkanKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId instance{ format::kNullHandleId };
    format::HandleId physicalDevice{ format::kNullHandleId };
    format::HandleId device{ format::kNullHandleId };
};

struct Decoded_XrSwapchainImageVulkanKHR
{
    using struct_type = XrSwapchainImageVulkanKHR;

    XrSwapchainImageVulkanKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_XrGraphicsRequirementsVulkanKHR
{
    using struct_type = XrGraphicsRequirementsVulkanKHR;

    XrGraphicsRequirementsVulkanKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingD3D11KHR
{
    using struct_type = XrGraphicsBindingD3D11KHR;

    XrGraphicsBindingD3D11KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t device{ 0 };
};

struct Decoded_XrSwapchainImageD3D11KHR
{
    using struct_type = XrSwapchainImageD3D11KHR;

    XrSwapchainImageD3D11KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t texture{ 0 };
};

struct Decoded_XrGraphicsRequirementsD3D11KHR
{
    using struct_type = XrGraphicsRequirementsD3D11KHR;

    XrGraphicsRequirementsD3D11KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingD3D12KHR
{
    using struct_type = XrGraphicsBindingD3D12KHR;

    XrGraphicsBindingD3D12KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t device{ 0 };
    uint64_t queue{ 0 };
};

struct Decoded_XrSwapchainImageD3D12KHR
{
    using struct_type = XrSwapchainImageD3D12KHR;

    XrSwapchainImageD3D12KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t texture{ 0 };
};

struct Decoded_XrGraphicsRequirementsD3D12KHR
{
    using struct_type = XrGraphicsRequirementsD3D12KHR;

    XrGraphicsRequirementsD3D12KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingMetalKHR
{
    using struct_type = XrGraphicsBindingMetalKHR;

    XrGraphicsBindingMetalKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t commandQueue{ 0 };
};

struct Decoded_XrSwapchainImageMetalKHR
{
    using struct_type = XrSwapchainImageMetalKHR;

    XrSwapchainImageMetalKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t texture{ 0 };
};

struct Decoded_XrGraphicsRequirementsMetalKHR
{
    using struct_type = XrGraphicsRequirementsMetalKHR;

    XrGraphicsRequirementsMetalKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t metalDevice{ 0 };
};

struct Decoded_XrVisibilityMaskKHR
{
    using struct_type = XrVisibilityMaskKHR;

    XrVisibilityMaskKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector2f>* vertices{ nullptr };
    PointerDecoder<uint32_t> indices;
};

struct Decoded_XrEventDataVisibilityMaskChangedKHR
{
    using struct_type = XrEventDataVisibilityMaskChangedKHR;

    XrEventDataVisibilityMaskChangedKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_XrCompositionLayerColorScaleBiasKHR
{
    using struct_type = XrCompositionLayerColorScaleBiasKHR;

    XrCompositionLayerColorScaleBiasKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrColor4f* colorScale{ nullptr };
    Decoded_XrColor4f* colorBias{ nullptr };
};

struct Decoded_XrLoaderInitInfoAndroidKHR
{
    using struct_type = XrLoaderInitInfoAndroidKHR;

    XrLoaderInitInfoAndroidKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t applicationVM{ 0 };
    uint64_t applicationContext{ 0 };
};

struct Decoded_XrVulkanGraphicsDeviceGetInfoKHR
{
    using struct_type = XrVulkanGraphicsDeviceGetInfoKHR;

    XrVulkanGraphicsDeviceGetInfoKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId systemId{ format::kNullHandleId };
    format::HandleId vulkanInstance{ format::kNullHandleId };
};

struct Decoded_XrCompositionLayerEquirect2KHR
{
    using struct_type = XrCompositionLayerEquirect2KHR;

    XrCompositionLayerEquirect2KHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrSwapchainSubImage* subImage{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrBindingModificationsKHR
{
    using struct_type = XrBindingModificationsKHR;

    XrBindingModificationsKHR* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrBindingModificationBaseHeaderKHR*>* bindingModifications{ nullptr };
};

struct Decoded_XrEventDataPerfSettingsEXT
{
    using struct_type = XrEventDataPerfSettingsEXT;

    XrEventDataPerfSettingsEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrDebugUtilsObjectNameInfoEXT
{
    using struct_type = XrDebugUtilsObjectNameInfoEXT;

    XrDebugUtilsObjectNameInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder objectName;
};

struct Decoded_XrDebugUtilsLabelEXT
{
    using struct_type = XrDebugUtilsLabelEXT;

    XrDebugUtilsLabelEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder labelName;
};

struct Decoded_XrDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = XrDebugUtilsMessengerCallbackDataEXT;

    XrDebugUtilsMessengerCallbackDataEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder messageId;
    StringDecoder functionName;
    StringDecoder message;
    StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* objects{ nullptr };
    StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* sessionLabels{ nullptr };
};

struct Decoded_XrDebugUtilsMessengerCreateInfoEXT
{
    using struct_type = XrDebugUtilsMessengerCreateInfoEXT;

    XrDebugUtilsMessengerCreateInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t userCallback{ 0 };
    uint64_t userData{ 0 };
};

struct Decoded_XrSystemEyeGazeInteractionPropertiesEXT
{
    using struct_type = XrSystemEyeGazeInteractionPropertiesEXT;

    XrSystemEyeGazeInteractionPropertiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEyeGazeSampleTimeEXT
{
    using struct_type = XrEyeGazeSampleTimeEXT;

    XrEyeGazeSampleTimeEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSessionCreateInfoOverlayEXTX
{
    using struct_type = XrSessionCreateInfoOverlayEXTX;

    XrSessionCreateInfoOverlayEXTX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataMainSessionVisibilityChangedEXTX
{
    using struct_type = XrEventDataMainSessionVisibilityChangedEXTX;

    XrEventDataMainSessionVisibilityChangedEXTX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpatialAnchorCreateInfoMSFT
{
    using struct_type = XrSpatialAnchorCreateInfoMSFT;

    XrSpatialAnchorCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrSpatialAnchorSpaceCreateInfoMSFT
{
    using struct_type = XrSpatialAnchorSpaceCreateInfoMSFT;

    XrSpatialAnchorSpaceCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId anchor{ format::kNullHandleId };
    Decoded_XrPosef* poseInAnchorSpace{ nullptr };
};

struct Decoded_XrCompositionLayerImageLayoutFB
{
    using struct_type = XrCompositionLayerImageLayoutFB;

    XrCompositionLayerImageLayoutFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerAlphaBlendFB
{
    using struct_type = XrCompositionLayerAlphaBlendFB;

    XrCompositionLayerAlphaBlendFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrViewConfigurationDepthRangeEXT
{
    using struct_type = XrViewConfigurationDepthRangeEXT;

    XrViewConfigurationDepthRangeEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGraphicsBindingEGLMNDX
{
    using struct_type = XrGraphicsBindingEGLMNDX;

    XrGraphicsBindingEGLMNDX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t getProcAddress{ 0 };
    uint64_t display{ 0 };
    uint64_t config{ 0 };
    uint64_t context{ 0 };
};

struct Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT
{
    using struct_type = XrSpatialGraphNodeSpaceCreateInfoMSFT;

    XrSpatialGraphNodeSpaceCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> nodeId;
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT
{
    using struct_type = XrSpatialGraphStaticNodeBindingCreateInfoMSFT;

    XrSpatialGraphStaticNodeBindingCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* poseInSpace{ nullptr };
};

struct Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT
{
    using struct_type = XrSpatialGraphNodeBindingPropertiesGetInfoMSFT;

    XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpatialGraphNodeBindingPropertiesMSFT
{
    using struct_type = XrSpatialGraphNodeBindingPropertiesMSFT;

    XrSpatialGraphNodeBindingPropertiesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> nodeId;
    Decoded_XrPosef* poseInNodeSpace{ nullptr };
};

struct Decoded_XrSystemHandTrackingPropertiesEXT
{
    using struct_type = XrSystemHandTrackingPropertiesEXT;

    XrSystemHandTrackingPropertiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHandTrackerCreateInfoEXT
{
    using struct_type = XrHandTrackerCreateInfoEXT;

    XrHandTrackerCreateInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHandJointsLocateInfoEXT
{
    using struct_type = XrHandJointsLocateInfoEXT;

    XrHandJointsLocateInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
};

struct Decoded_XrHandJointLocationEXT
{
    using struct_type = XrHandJointLocationEXT;

    XrHandJointLocationEXT* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrHandJointVelocityEXT
{
    using struct_type = XrHandJointVelocityEXT;

    XrHandJointVelocityEXT* decoded_value{ nullptr };

    Decoded_XrVector3f* linearVelocity{ nullptr };
    Decoded_XrVector3f* angularVelocity{ nullptr };
};

struct Decoded_XrHandJointLocationsEXT
{
    using struct_type = XrHandJointLocationsEXT;

    XrHandJointLocationsEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrHandJointLocationEXT>* jointLocations{ nullptr };
};

struct Decoded_XrHandJointVelocitiesEXT
{
    using struct_type = XrHandJointVelocitiesEXT;

    XrHandJointVelocitiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrHandJointVelocityEXT>* jointVelocities{ nullptr };
};

struct Decoded_XrSystemHandTrackingMeshPropertiesMSFT
{
    using struct_type = XrSystemHandTrackingMeshPropertiesMSFT;

    XrSystemHandTrackingMeshPropertiesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHandMeshSpaceCreateInfoMSFT
{
    using struct_type = XrHandMeshSpaceCreateInfoMSFT;

    XrHandMeshSpaceCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* poseInHandMeshSpace{ nullptr };
};

struct Decoded_XrHandMeshUpdateInfoMSFT
{
    using struct_type = XrHandMeshUpdateInfoMSFT;

    XrHandMeshUpdateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHandMeshIndexBufferMSFT
{
    using struct_type = XrHandMeshIndexBufferMSFT;

    XrHandMeshIndexBufferMSFT* decoded_value{ nullptr };

    PointerDecoder<uint32_t> indices;
};

struct Decoded_XrHandMeshVertexMSFT
{
    using struct_type = XrHandMeshVertexMSFT;

    XrHandMeshVertexMSFT* decoded_value{ nullptr };

    Decoded_XrVector3f* position{ nullptr };
    Decoded_XrVector3f* normal{ nullptr };
};

struct Decoded_XrHandMeshVertexBufferMSFT
{
    using struct_type = XrHandMeshVertexBufferMSFT;

    XrHandMeshVertexBufferMSFT* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_XrHandMeshVertexMSFT>* vertices{ nullptr };
};

struct Decoded_XrHandMeshMSFT
{
    using struct_type = XrHandMeshMSFT;

    XrHandMeshMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrHandMeshIndexBufferMSFT* indexBuffer{ nullptr };
    Decoded_XrHandMeshVertexBufferMSFT* vertexBuffer{ nullptr };
};

struct Decoded_XrHandPoseTypeInfoMSFT
{
    using struct_type = XrHandPoseTypeInfoMSFT;

    XrHandPoseTypeInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT
{
    using struct_type = XrSecondaryViewConfigurationSessionBeginInfoMSFT;

    XrSecondaryViewConfigurationSessionBeginInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrViewConfigurationType> enabledViewConfigurationTypes;
};

struct Decoded_XrSecondaryViewConfigurationStateMSFT
{
    using struct_type = XrSecondaryViewConfigurationStateMSFT;

    XrSecondaryViewConfigurationStateMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationFrameStateMSFT
{
    using struct_type = XrSecondaryViewConfigurationFrameStateMSFT;

    XrSecondaryViewConfigurationFrameStateMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSecondaryViewConfigurationStateMSFT>* viewConfigurationStates{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationLayerInfoMSFT
{
    using struct_type = XrSecondaryViewConfigurationLayerInfoMSFT;

    XrSecondaryViewConfigurationLayerInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrCompositionLayerBaseHeader*>* layers{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT
{
    using struct_type = XrSecondaryViewConfigurationFrameEndInfoMSFT;

    XrSecondaryViewConfigurationFrameEndInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT>* viewConfigurationLayersInfo{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT
{
    using struct_type = XrSecondaryViewConfigurationSwapchainCreateInfoMSFT;

    XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrControllerModelKeyStateMSFT
{
    using struct_type = XrControllerModelKeyStateMSFT;

    XrControllerModelKeyStateMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId modelKey{ format::kNullHandleId };
};

struct Decoded_XrControllerModelNodePropertiesMSFT
{
    using struct_type = XrControllerModelNodePropertiesMSFT;

    XrControllerModelNodePropertiesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder parentNodeName;
    StringDecoder nodeName;
};

struct Decoded_XrControllerModelPropertiesMSFT
{
    using struct_type = XrControllerModelPropertiesMSFT;

    XrControllerModelPropertiesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrControllerModelNodePropertiesMSFT>* nodeProperties{ nullptr };
};

struct Decoded_XrControllerModelNodeStateMSFT
{
    using struct_type = XrControllerModelNodeStateMSFT;

    XrControllerModelNodeStateMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* nodePose{ nullptr };
};

struct Decoded_XrControllerModelStateMSFT
{
    using struct_type = XrControllerModelStateMSFT;

    XrControllerModelStateMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrControllerModelNodeStateMSFT>* nodeStates{ nullptr };
};

struct Decoded_XrViewConfigurationViewFovEPIC
{
    using struct_type = XrViewConfigurationViewFovEPIC;

    XrViewConfigurationViewFovEPIC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrFovf* recommendedFov{ nullptr };
    Decoded_XrFovf* maxMutableFov{ nullptr };
};

struct Decoded_XrHolographicWindowAttachmentMSFT
{
    using struct_type = XrHolographicWindowAttachmentMSFT;

    XrHolographicWindowAttachmentMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    uint64_t holographicSpace{ 0 };
    uint64_t coreWindow{ 0 };
};

struct Decoded_XrCompositionLayerReprojectionInfoMSFT
{
    using struct_type = XrCompositionLayerReprojectionInfoMSFT;

    XrCompositionLayerReprojectionInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT
{
    using struct_type = XrCompositionLayerReprojectionPlaneOverrideMSFT;

    XrCompositionLayerReprojectionPlaneOverrideMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrVector3f* position{ nullptr };
    Decoded_XrVector3f* normal{ nullptr };
    Decoded_XrVector3f* velocity{ nullptr };
};

struct Decoded_XrAndroidSurfaceSwapchainCreateInfoFB
{
    using struct_type = XrAndroidSurfaceSwapchainCreateInfoFB;

    XrAndroidSurfaceSwapchainCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerSecureContentFB
{
    using struct_type = XrCompositionLayerSecureContentFB;

    XrCompositionLayerSecureContentFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrBodyJointLocationFB
{
    using struct_type = XrBodyJointLocationFB;

    XrBodyJointLocationFB* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrSystemBodyTrackingPropertiesFB
{
    using struct_type = XrSystemBodyTrackingPropertiesFB;

    XrSystemBodyTrackingPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrBodyTrackerCreateInfoFB
{
    using struct_type = XrBodyTrackerCreateInfoFB;

    XrBodyTrackerCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrBodySkeletonJointFB
{
    using struct_type = XrBodySkeletonJointFB;

    XrBodySkeletonJointFB* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrBodySkeletonFB
{
    using struct_type = XrBodySkeletonFB;

    XrBodySkeletonFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrBodySkeletonJointFB>* joints{ nullptr };
};

struct Decoded_XrBodyJointsLocateInfoFB
{
    using struct_type = XrBodyJointsLocateInfoFB;

    XrBodyJointsLocateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
};

struct Decoded_XrBodyJointLocationsFB
{
    using struct_type = XrBodyJointLocationsFB;

    XrBodyJointLocationsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrBodyJointLocationFB>* jointLocations{ nullptr };
};

struct Decoded_XrInteractionProfileDpadBindingEXT
{
    using struct_type = XrInteractionProfileDpadBindingEXT;

    XrInteractionProfileDpadBindingEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId binding{ format::kNullHandleId };
    format::HandleId actionSet{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* onHaptic{ nullptr };
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* offHaptic{ nullptr };
};

struct Decoded_XrInteractionProfileAnalogThresholdVALVE
{
    using struct_type = XrInteractionProfileAnalogThresholdVALVE;

    XrInteractionProfileAnalogThresholdVALVE* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId action{ format::kNullHandleId };
    format::HandleId binding{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* onHaptic{ nullptr };
    StructPointerDecoder<Decoded_XrHapticBaseHeader>* offHaptic{ nullptr };
};

struct Decoded_XrHandJointsMotionRangeInfoEXT
{
    using struct_type = XrHandJointsMotionRangeInfoEXT;

    XrHandJointsMotionRangeInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrUuidMSFT
{
    using struct_type = XrUuidMSFT;

    XrUuidMSFT* decoded_value{ nullptr };

    PointerDecoder<uint8_t> bytes;
};

struct Decoded_XrSceneObserverCreateInfoMSFT
{
    using struct_type = XrSceneObserverCreateInfoMSFT;

    XrSceneObserverCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneCreateInfoMSFT
{
    using struct_type = XrSceneCreateInfoMSFT;

    XrSceneCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneSphereBoundMSFT
{
    using struct_type = XrSceneSphereBoundMSFT;

    XrSceneSphereBoundMSFT* decoded_value{ nullptr };

    Decoded_XrVector3f* center{ nullptr };
};

struct Decoded_XrSceneOrientedBoxBoundMSFT
{
    using struct_type = XrSceneOrientedBoxBoundMSFT;

    XrSceneOrientedBoxBoundMSFT* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrVector3f* extents{ nullptr };
};

struct Decoded_XrSceneFrustumBoundMSFT
{
    using struct_type = XrSceneFrustumBoundMSFT;

    XrSceneFrustumBoundMSFT* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrFovf* fov{ nullptr };
};

struct Decoded_XrSceneBoundsMSFT
{
    using struct_type = XrSceneBoundsMSFT;

    XrSceneBoundsMSFT* decoded_value{ nullptr };

    format::HandleId space{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrSceneSphereBoundMSFT>* spheres{ nullptr };
    StructPointerDecoder<Decoded_XrSceneOrientedBoxBoundMSFT>* boxes{ nullptr };
    StructPointerDecoder<Decoded_XrSceneFrustumBoundMSFT>* frustums{ nullptr };
};

struct Decoded_XrNewSceneComputeInfoMSFT
{
    using struct_type = XrNewSceneComputeInfoMSFT;

    XrNewSceneComputeInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrSceneComputeFeatureMSFT> requestedFeatures;
    Decoded_XrSceneBoundsMSFT* bounds{ nullptr };
};

struct Decoded_XrVisualMeshComputeLodInfoMSFT
{
    using struct_type = XrVisualMeshComputeLodInfoMSFT;

    XrVisualMeshComputeLodInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneComponentMSFT
{
    using struct_type = XrSceneComponentMSFT;

    XrSceneComponentMSFT* decoded_value{ nullptr };

    Decoded_XrUuidMSFT* id{ nullptr };
    Decoded_XrUuidMSFT* parentId{ nullptr };
};

struct Decoded_XrSceneComponentsMSFT
{
    using struct_type = XrSceneComponentsMSFT;

    XrSceneComponentsMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneComponentMSFT>* components{ nullptr };
};

struct Decoded_XrSceneComponentsGetInfoMSFT
{
    using struct_type = XrSceneComponentsGetInfoMSFT;

    XrSceneComponentsGetInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneComponentLocationMSFT
{
    using struct_type = XrSceneComponentLocationMSFT;

    XrSceneComponentLocationMSFT* decoded_value{ nullptr };

    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrSceneComponentLocationsMSFT
{
    using struct_type = XrSceneComponentLocationsMSFT;

    XrSceneComponentLocationsMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneComponentLocationMSFT>* locations{ nullptr };
};

struct Decoded_XrSceneComponentsLocateInfoMSFT
{
    using struct_type = XrSceneComponentsLocateInfoMSFT;

    XrSceneComponentsLocateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
    StructPointerDecoder<Decoded_XrUuidMSFT>* componentIds{ nullptr };
};

struct Decoded_XrSceneObjectMSFT
{
    using struct_type = XrSceneObjectMSFT;

    XrSceneObjectMSFT* decoded_value{ nullptr };
};

struct Decoded_XrSceneObjectsMSFT
{
    using struct_type = XrSceneObjectsMSFT;

    XrSceneObjectsMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneObjectMSFT>* sceneObjects{ nullptr };
};

struct Decoded_XrSceneComponentParentFilterInfoMSFT
{
    using struct_type = XrSceneComponentParentFilterInfoMSFT;

    XrSceneComponentParentFilterInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrUuidMSFT* parentId{ nullptr };
};

struct Decoded_XrSceneObjectTypesFilterInfoMSFT
{
    using struct_type = XrSceneObjectTypesFilterInfoMSFT;

    XrSceneObjectTypesFilterInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrSceneObjectTypeMSFT> objectTypes;
};

struct Decoded_XrScenePlaneMSFT
{
    using struct_type = XrScenePlaneMSFT;

    XrScenePlaneMSFT* decoded_value{ nullptr };

    Decoded_XrExtent2Df* size{ nullptr };
};

struct Decoded_XrScenePlanesMSFT
{
    using struct_type = XrScenePlanesMSFT;

    XrScenePlanesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrScenePlaneMSFT>* scenePlanes{ nullptr };
};

struct Decoded_XrScenePlaneAlignmentFilterInfoMSFT
{
    using struct_type = XrScenePlaneAlignmentFilterInfoMSFT;

    XrScenePlaneAlignmentFilterInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrScenePlaneAlignmentTypeMSFT> alignments;
};

struct Decoded_XrSceneMeshMSFT
{
    using struct_type = XrSceneMeshMSFT;

    XrSceneMeshMSFT* decoded_value{ nullptr };
};

struct Decoded_XrSceneMeshesMSFT
{
    using struct_type = XrSceneMeshesMSFT;

    XrSceneMeshesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneMeshMSFT>* sceneMeshes{ nullptr };
};

struct Decoded_XrSceneMeshBuffersGetInfoMSFT
{
    using struct_type = XrSceneMeshBuffersGetInfoMSFT;

    XrSceneMeshBuffersGetInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneMeshBuffersMSFT
{
    using struct_type = XrSceneMeshBuffersMSFT;

    XrSceneMeshBuffersMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSceneMeshVertexBufferMSFT
{
    using struct_type = XrSceneMeshVertexBufferMSFT;

    XrSceneMeshVertexBufferMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector3f>* vertices{ nullptr };
};

struct Decoded_XrSceneMeshIndicesUint32MSFT
{
    using struct_type = XrSceneMeshIndicesUint32MSFT;

    XrSceneMeshIndicesUint32MSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint32_t> indices;
};

struct Decoded_XrSceneMeshIndicesUint16MSFT
{
    using struct_type = XrSceneMeshIndicesUint16MSFT;

    XrSceneMeshIndicesUint16MSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint16_t> indices;
};

struct Decoded_XrSerializedSceneFragmentDataGetInfoMSFT
{
    using struct_type = XrSerializedSceneFragmentDataGetInfoMSFT;

    XrSerializedSceneFragmentDataGetInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrUuidMSFT* sceneFragmentId{ nullptr };
};

struct Decoded_XrDeserializeSceneFragmentMSFT
{
    using struct_type = XrDeserializeSceneFragmentMSFT;

    XrDeserializeSceneFragmentMSFT* decoded_value{ nullptr };

    PointerDecoder<uint8_t> buffer;
};

struct Decoded_XrSceneDeserializeInfoMSFT
{
    using struct_type = XrSceneDeserializeInfoMSFT;

    XrSceneDeserializeInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrDeserializeSceneFragmentMSFT>* fragments{ nullptr };
};

struct Decoded_XrEventDataDisplayRefreshRateChangedFB
{
    using struct_type = XrEventDataDisplayRefreshRateChangedFB;

    XrEventDataDisplayRefreshRateChangedFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrViveTrackerPathsHTCX
{
    using struct_type = XrViveTrackerPathsHTCX;

    XrViveTrackerPathsHTCX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId persistentPath{ format::kNullHandleId };
    format::HandleId rolePath{ format::kNullHandleId };
};

struct Decoded_XrEventDataViveTrackerConnectedHTCX
{
    using struct_type = XrEventDataViveTrackerConnectedHTCX;

    XrEventDataViveTrackerConnectedHTCX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>* paths{ nullptr };
};

struct Decoded_XrSystemFacialTrackingPropertiesHTC
{
    using struct_type = XrSystemFacialTrackingPropertiesHTC;

    XrSystemFacialTrackingPropertiesHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFacialExpressionsHTC
{
    using struct_type = XrFacialExpressionsHTC;

    XrFacialExpressionsHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<float> expressionWeightings;
};

struct Decoded_XrFacialTrackerCreateInfoHTC
{
    using struct_type = XrFacialTrackerCreateInfoHTC;

    XrFacialTrackerCreateInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemColorSpacePropertiesFB
{
    using struct_type = XrSystemColorSpacePropertiesFB;

    XrSystemColorSpacePropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVector4sFB
{
    using struct_type = XrVector4sFB;

    XrVector4sFB* decoded_value{ nullptr };
};

struct Decoded_XrHandTrackingMeshFB
{
    using struct_type = XrHandTrackingMeshFB;

    XrHandTrackingMeshFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrPosef>* jointBindPoses{ nullptr };
    PointerDecoder<float> jointRadii;
    PointerDecoder<XrHandJointEXT> jointParents;
    StructPointerDecoder<Decoded_XrVector3f>* vertexPositions{ nullptr };
    StructPointerDecoder<Decoded_XrVector3f>* vertexNormals{ nullptr };
    StructPointerDecoder<Decoded_XrVector2f>* vertexUVs{ nullptr };
    StructPointerDecoder<Decoded_XrVector4sFB>* vertexBlendIndices{ nullptr };
    StructPointerDecoder<Decoded_XrVector4f>* vertexBlendWeights{ nullptr };
    PointerDecoder<int16_t> indices;
};

struct Decoded_XrHandTrackingScaleFB
{
    using struct_type = XrHandTrackingScaleFB;

    XrHandTrackingScaleFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHandTrackingAimStateFB
{
    using struct_type = XrHandTrackingAimStateFB;

    XrHandTrackingAimStateFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* aimPose{ nullptr };
};

struct Decoded_XrHandCapsuleFB
{
    using struct_type = XrHandCapsuleFB;

    XrHandCapsuleFB* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_XrVector3f>* points{ nullptr };
};

struct Decoded_XrHandTrackingCapsulesStateFB
{
    using struct_type = XrHandTrackingCapsulesStateFB;

    XrHandTrackingCapsulesStateFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrHandCapsuleFB>* capsules{ nullptr };
};

struct Decoded_XrSystemSpatialEntityPropertiesFB
{
    using struct_type = XrSystemSpatialEntityPropertiesFB;

    XrSystemSpatialEntityPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpatialAnchorCreateInfoFB
{
    using struct_type = XrSpatialAnchorCreateInfoFB;

    XrSpatialAnchorCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* poseInSpace{ nullptr };
};

struct Decoded_XrSpaceComponentStatusSetInfoFB
{
    using struct_type = XrSpaceComponentStatusSetInfoFB;

    XrSpaceComponentStatusSetInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceComponentStatusFB
{
    using struct_type = XrSpaceComponentStatusFB;

    XrSpaceComponentStatusFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataSpatialAnchorCreateCompleteFB
{
    using struct_type = XrEventDataSpatialAnchorCreateCompleteFB;

    XrEventDataSpatialAnchorCreateCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrUuid* uuid{ nullptr };
};

struct Decoded_XrEventDataSpaceSetStatusCompleteFB
{
    using struct_type = XrEventDataSpaceSetStatusCompleteFB;

    XrEventDataSpaceSetStatusCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrUuid* uuid{ nullptr };
};

struct Decoded_XrFoveationProfileCreateInfoFB
{
    using struct_type = XrFoveationProfileCreateInfoFB;

    XrFoveationProfileCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainCreateInfoFoveationFB
{
    using struct_type = XrSwapchainCreateInfoFoveationFB;

    XrSwapchainCreateInfoFoveationFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainStateFoveationFB
{
    using struct_type = XrSwapchainStateFoveationFB;

    XrSwapchainStateFoveationFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId profile{ format::kNullHandleId };
};

struct Decoded_XrFoveationLevelProfileCreateInfoFB
{
    using struct_type = XrFoveationLevelProfileCreateInfoFB;

    XrFoveationLevelProfileCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemKeyboardTrackingPropertiesFB
{
    using struct_type = XrSystemKeyboardTrackingPropertiesFB;

    XrSystemKeyboardTrackingPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrKeyboardTrackingDescriptionFB
{
    using struct_type = XrKeyboardTrackingDescriptionFB;

    XrKeyboardTrackingDescriptionFB* decoded_value{ nullptr };

    Decoded_XrVector3f* size{ nullptr };
    StringDecoder name;
};

struct Decoded_XrKeyboardSpaceCreateInfoFB
{
    using struct_type = XrKeyboardSpaceCreateInfoFB;

    XrKeyboardSpaceCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrKeyboardTrackingQueryFB
{
    using struct_type = XrKeyboardTrackingQueryFB;

    XrKeyboardTrackingQueryFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrTriangleMeshCreateInfoFB
{
    using struct_type = XrTriangleMeshCreateInfoFB;

    XrTriangleMeshCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector3f>* vertexBuffer{ nullptr };
    PointerDecoder<uint32_t> indexBuffer;
};

struct Decoded_XrSystemPassthroughPropertiesFB
{
    using struct_type = XrSystemPassthroughPropertiesFB;

    XrSystemPassthroughPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemPassthroughProperties2FB
{
    using struct_type = XrSystemPassthroughProperties2FB;

    XrSystemPassthroughProperties2FB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughCreateInfoFB
{
    using struct_type = XrPassthroughCreateInfoFB;

    XrPassthroughCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughLayerCreateInfoFB
{
    using struct_type = XrPassthroughLayerCreateInfoFB;

    XrPassthroughLayerCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId passthrough{ format::kNullHandleId };
};

struct Decoded_XrCompositionLayerPassthroughFB
{
    using struct_type = XrCompositionLayerPassthroughFB;

    XrCompositionLayerPassthroughFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    format::HandleId layerHandle{ format::kNullHandleId };
};

struct Decoded_XrGeometryInstanceCreateInfoFB
{
    using struct_type = XrGeometryInstanceCreateInfoFB;

    XrGeometryInstanceCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId layer{ format::kNullHandleId };
    format::HandleId mesh{ format::kNullHandleId };
    format::HandleId baseSpace{ format::kNullHandleId };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrVector3f* scale{ nullptr };
};

struct Decoded_XrGeometryInstanceTransformFB
{
    using struct_type = XrGeometryInstanceTransformFB;

    XrGeometryInstanceTransformFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrVector3f* scale{ nullptr };
};

struct Decoded_XrPassthroughStyleFB
{
    using struct_type = XrPassthroughStyleFB;

    XrPassthroughStyleFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrColor4f* edgeColor{ nullptr };
};

struct Decoded_XrPassthroughColorMapMonoToRgbaFB
{
    using struct_type = XrPassthroughColorMapMonoToRgbaFB;

    XrPassthroughColorMapMonoToRgbaFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrColor4f>* textureColorMap{ nullptr };
};

struct Decoded_XrPassthroughColorMapMonoToMonoFB
{
    using struct_type = XrPassthroughColorMapMonoToMonoFB;

    XrPassthroughColorMapMonoToMonoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> textureColorMap;
};

struct Decoded_XrPassthroughBrightnessContrastSaturationFB
{
    using struct_type = XrPassthroughBrightnessContrastSaturationFB;

    XrPassthroughBrightnessContrastSaturationFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataPassthroughStateChangedFB
{
    using struct_type = XrEventDataPassthroughStateChangedFB;

    XrEventDataPassthroughStateChangedFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrRenderModelPathInfoFB
{
    using struct_type = XrRenderModelPathInfoFB;

    XrRenderModelPathInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId path{ format::kNullHandleId };
};

struct Decoded_XrRenderModelPropertiesFB
{
    using struct_type = XrRenderModelPropertiesFB;

    XrRenderModelPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder modelName;
    format::HandleId modelKey{ format::kNullHandleId };
};

struct Decoded_XrRenderModelBufferFB
{
    using struct_type = XrRenderModelBufferFB;

    XrRenderModelBufferFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> buffer;
};

struct Decoded_XrRenderModelLoadInfoFB
{
    using struct_type = XrRenderModelLoadInfoFB;

    XrRenderModelLoadInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId modelKey{ format::kNullHandleId };
};

struct Decoded_XrSystemRenderModelPropertiesFB
{
    using struct_type = XrSystemRenderModelPropertiesFB;

    XrSystemRenderModelPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrRenderModelCapabilitiesRequestFB
{
    using struct_type = XrRenderModelCapabilitiesRequestFB;

    XrRenderModelCapabilitiesRequestFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrViewLocateFoveatedRenderingVARJO
{
    using struct_type = XrViewLocateFoveatedRenderingVARJO;

    XrViewLocateFoveatedRenderingVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFoveatedViewConfigurationViewVARJO
{
    using struct_type = XrFoveatedViewConfigurationViewVARJO;

    XrFoveatedViewConfigurationViewVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemFoveatedRenderingPropertiesVARJO
{
    using struct_type = XrSystemFoveatedRenderingPropertiesVARJO;

    XrSystemFoveatedRenderingPropertiesVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerDepthTestVARJO
{
    using struct_type = XrCompositionLayerDepthTestVARJO;

    XrCompositionLayerDepthTestVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemMarkerTrackingPropertiesVARJO
{
    using struct_type = XrSystemMarkerTrackingPropertiesVARJO;

    XrSystemMarkerTrackingPropertiesVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataMarkerTrackingUpdateVARJO
{
    using struct_type = XrEventDataMarkerTrackingUpdateVARJO;

    XrEventDataMarkerTrackingUpdateVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerSpaceCreateInfoVARJO
{
    using struct_type = XrMarkerSpaceCreateInfoVARJO;

    XrMarkerSpaceCreateInfoVARJO* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* poseInMarkerSpace{ nullptr };
};

struct Decoded_XrFrameEndInfoML
{
    using struct_type = XrFrameEndInfoML;

    XrFrameEndInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrGlobalDimmerFrameEndInfoML
{
    using struct_type = XrGlobalDimmerFrameEndInfoML;

    XrGlobalDimmerFrameEndInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCoordinateSpaceCreateInfoML
{
    using struct_type = XrCoordinateSpaceCreateInfoML;

    XrCoordinateSpaceCreateInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* poseInCoordinateSpace{ nullptr };
};

struct Decoded_XrSystemMarkerUnderstandingPropertiesML
{
    using struct_type = XrSystemMarkerUnderstandingPropertiesML;

    XrSystemMarkerUnderstandingPropertiesML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorCreateInfoML
{
    using struct_type = XrMarkerDetectorCreateInfoML;

    XrMarkerDetectorCreateInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorArucoInfoML
{
    using struct_type = XrMarkerDetectorArucoInfoML;

    XrMarkerDetectorArucoInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorSizeInfoML
{
    using struct_type = XrMarkerDetectorSizeInfoML;

    XrMarkerDetectorSizeInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorAprilTagInfoML
{
    using struct_type = XrMarkerDetectorAprilTagInfoML;

    XrMarkerDetectorAprilTagInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorCustomProfileInfoML
{
    using struct_type = XrMarkerDetectorCustomProfileInfoML;

    XrMarkerDetectorCustomProfileInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorSnapshotInfoML
{
    using struct_type = XrMarkerDetectorSnapshotInfoML;

    XrMarkerDetectorSnapshotInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerDetectorStateML
{
    using struct_type = XrMarkerDetectorStateML;

    XrMarkerDetectorStateML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMarkerSpaceCreateInfoML
{
    using struct_type = XrMarkerSpaceCreateInfoML;

    XrMarkerSpaceCreateInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId markerDetector{ format::kNullHandleId };
    format::HandleId marker{ format::kNullHandleId };
    Decoded_XrPosef* poseInMarkerSpace{ nullptr };
};

struct Decoded_XrLocalizationMapML
{
    using struct_type = XrLocalizationMapML;

    XrLocalizationMapML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder name;
    Decoded_XrUuid* mapUuid{ nullptr };
};

struct Decoded_XrEventDataLocalizationChangedML
{
    using struct_type = XrEventDataLocalizationChangedML;

    XrEventDataLocalizationChangedML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
    Decoded_XrLocalizationMapML* map{ nullptr };
};

struct Decoded_XrLocalizationMapQueryInfoBaseHeaderML
{
    using struct_type = XrLocalizationMapQueryInfoBaseHeaderML;

    XrLocalizationMapQueryInfoBaseHeaderML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrMapLocalizationRequestInfoML
{
    using struct_type = XrMapLocalizationRequestInfoML;

    XrMapLocalizationRequestInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrUuid* mapUuid{ nullptr };
};

struct Decoded_XrLocalizationMapImportInfoML
{
    using struct_type = XrLocalizationMapImportInfoML;

    XrLocalizationMapImportInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder data;
};

struct Decoded_XrLocalizationEnableEventsInfoML
{
    using struct_type = XrLocalizationEnableEventsInfoML;

    XrLocalizationEnableEventsInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpatialAnchorPersistenceNameMSFT
{
    using struct_type = XrSpatialAnchorPersistenceNameMSFT;

    XrSpatialAnchorPersistenceNameMSFT* decoded_value{ nullptr };

    StringDecoder name;
};

struct Decoded_XrSpatialAnchorPersistenceInfoMSFT
{
    using struct_type = XrSpatialAnchorPersistenceInfoMSFT;

    XrSpatialAnchorPersistenceInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrSpatialAnchorPersistenceNameMSFT* spatialAnchorPersistenceName{ nullptr };
    format::HandleId spatialAnchor{ format::kNullHandleId };
};

struct Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT
{
    using struct_type = XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT;

    XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId spatialAnchorStore{ format::kNullHandleId };
    Decoded_XrSpatialAnchorPersistenceNameMSFT* spatialAnchorPersistenceName{ nullptr };
};

struct Decoded_XrSceneMarkerMSFT
{
    using struct_type = XrSceneMarkerMSFT;

    XrSceneMarkerMSFT* decoded_value{ nullptr };

    Decoded_XrOffset2Df* center{ nullptr };
    Decoded_XrExtent2Df* size{ nullptr };
};

struct Decoded_XrSceneMarkersMSFT
{
    using struct_type = XrSceneMarkersMSFT;

    XrSceneMarkersMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneMarkerMSFT>* sceneMarkers{ nullptr };
};

struct Decoded_XrSceneMarkerTypeFilterMSFT
{
    using struct_type = XrSceneMarkerTypeFilterMSFT;

    XrSceneMarkerTypeFilterMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrSceneMarkerTypeMSFT> markerTypes;
};

struct Decoded_XrSceneMarkerQRCodeMSFT
{
    using struct_type = XrSceneMarkerQRCodeMSFT;

    XrSceneMarkerQRCodeMSFT* decoded_value{ nullptr };
};

struct Decoded_XrSceneMarkerQRCodesMSFT
{
    using struct_type = XrSceneMarkerQRCodesMSFT;

    XrSceneMarkerQRCodesMSFT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSceneMarkerQRCodeMSFT>* qrCodes{ nullptr };
};

struct Decoded_XrSpaceQueryInfoFB
{
    using struct_type = XrSpaceQueryInfoFB;

    XrSpaceQueryInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSpaceFilterInfoBaseHeaderFB>* filter{ nullptr };
    StructPointerDecoder<Decoded_XrSpaceFilterInfoBaseHeaderFB>* excludeFilter{ nullptr };
};

struct Decoded_XrSpaceStorageLocationFilterInfoFB
{
    using struct_type = XrSpaceStorageLocationFilterInfoFB;

    XrSpaceStorageLocationFilterInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceUuidFilterInfoFB
{
    using struct_type = XrSpaceUuidFilterInfoFB;

    XrSpaceUuidFilterInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrUuid>* uuids{ nullptr };
};

struct Decoded_XrSpaceComponentFilterInfoFB
{
    using struct_type = XrSpaceComponentFilterInfoFB;

    XrSpaceComponentFilterInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceQueryResultFB
{
    using struct_type = XrSpaceQueryResultFB;

    XrSpaceQueryResultFB* decoded_value{ nullptr };

    format::HandleId space{ format::kNullHandleId };
    Decoded_XrUuid* uuid{ nullptr };
};

struct Decoded_XrSpaceQueryResultsFB
{
    using struct_type = XrSpaceQueryResultsFB;

    XrSpaceQueryResultsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSpaceQueryResultFB>* results{ nullptr };
};

struct Decoded_XrEventDataSpaceQueryResultsAvailableFB
{
    using struct_type = XrEventDataSpaceQueryResultsAvailableFB;

    XrEventDataSpaceQueryResultsAvailableFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
};

struct Decoded_XrEventDataSpaceQueryCompleteFB
{
    using struct_type = XrEventDataSpaceQueryCompleteFB;

    XrEventDataSpaceQueryCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
};

struct Decoded_XrSpaceSaveInfoFB
{
    using struct_type = XrSpaceSaveInfoFB;

    XrSpaceSaveInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
};

struct Decoded_XrSpaceEraseInfoFB
{
    using struct_type = XrSpaceEraseInfoFB;

    XrSpaceEraseInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
};

struct Decoded_XrEventDataSpaceSaveCompleteFB
{
    using struct_type = XrEventDataSpaceSaveCompleteFB;

    XrEventDataSpaceSaveCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrUuid* uuid{ nullptr };
};

struct Decoded_XrEventDataSpaceEraseCompleteFB
{
    using struct_type = XrEventDataSpaceEraseCompleteFB;

    XrEventDataSpaceEraseCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrUuid* uuid{ nullptr };
};

struct Decoded_XrSwapchainImageFoveationVulkanFB
{
    using struct_type = XrSwapchainImageFoveationVulkanFB;

    XrSwapchainImageFoveationVulkanFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB
{
    using struct_type = XrSwapchainStateAndroidSurfaceDimensionsFB;

    XrSwapchainStateAndroidSurfaceDimensionsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSwapchainStateSamplerOpenGLESFB
{
    using struct_type = XrSwapchainStateSamplerOpenGLESFB;

    XrSwapchainStateSamplerOpenGLESFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrColor4f* borderColor{ nullptr };
};

struct Decoded_XrSwapchainStateSamplerVulkanFB
{
    using struct_type = XrSwapchainStateSamplerVulkanFB;

    XrSwapchainStateSamplerVulkanFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrColor4f* borderColor{ nullptr };
};

struct Decoded_XrSpaceShareInfoFB
{
    using struct_type = XrSpaceShareInfoFB;

    XrSpaceShareInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    HandlePointerDecoder<XrSpace> spaces;
    HandlePointerDecoder<XrSpaceUserFB> users;
};

struct Decoded_XrEventDataSpaceShareCompleteFB
{
    using struct_type = XrEventDataSpaceShareCompleteFB;

    XrEventDataSpaceShareCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
};

struct Decoded_XrCompositionLayerSpaceWarpInfoFB
{
    using struct_type = XrCompositionLayerSpaceWarpInfoFB;

    XrCompositionLayerSpaceWarpInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrSwapchainSubImage* motionVectorSubImage{ nullptr };
    Decoded_XrPosef* appSpaceDeltaPose{ nullptr };
    Decoded_XrSwapchainSubImage* depthSubImage{ nullptr };
};

struct Decoded_XrSystemSpaceWarpPropertiesFB
{
    using struct_type = XrSystemSpaceWarpPropertiesFB;

    XrSystemSpaceWarpPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHapticAmplitudeEnvelopeVibrationFB
{
    using struct_type = XrHapticAmplitudeEnvelopeVibrationFB;

    XrHapticAmplitudeEnvelopeVibrationFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<float> amplitudes;
};

struct Decoded_XrOffset3DfFB
{
    using struct_type = XrOffset3DfFB;

    XrOffset3DfFB* decoded_value{ nullptr };
};

struct Decoded_XrRect3DfFB
{
    using struct_type = XrRect3DfFB;

    XrRect3DfFB* decoded_value{ nullptr };

    Decoded_XrOffset3DfFB* offset{ nullptr };
    Decoded_XrExtent3Df* extent{ nullptr };
};

struct Decoded_XrSemanticLabelsFB
{
    using struct_type = XrSemanticLabelsFB;

    XrSemanticLabelsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder buffer;
};

struct Decoded_XrRoomLayoutFB
{
    using struct_type = XrRoomLayoutFB;

    XrRoomLayoutFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrUuid* floorUuid{ nullptr };
    Decoded_XrUuid* ceilingUuid{ nullptr };
    StructPointerDecoder<Decoded_XrUuid>* wallUuids{ nullptr };
};

struct Decoded_XrBoundary2DFB
{
    using struct_type = XrBoundary2DFB;

    XrBoundary2DFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector2f>* vertices{ nullptr };
};

struct Decoded_XrSemanticLabelsSupportInfoFB
{
    using struct_type = XrSemanticLabelsSupportInfoFB;

    XrSemanticLabelsSupportInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder recognizedLabels;
};

struct Decoded_XrDigitalLensControlALMALENCE
{
    using struct_type = XrDigitalLensControlALMALENCE;

    XrDigitalLensControlALMALENCE* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataSceneCaptureCompleteFB
{
    using struct_type = XrEventDataSceneCaptureCompleteFB;

    XrEventDataSceneCaptureCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
};

struct Decoded_XrSceneCaptureRequestInfoFB
{
    using struct_type = XrSceneCaptureRequestInfoFB;

    XrSceneCaptureRequestInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder request;
};

struct Decoded_XrSpaceContainerFB
{
    using struct_type = XrSpaceContainerFB;

    XrSpaceContainerFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrUuid>* uuids{ nullptr };
};

struct Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA
{
    using struct_type = XrFoveationEyeTrackedProfileCreateInfoMETA;

    XrFoveationEyeTrackedProfileCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFoveationEyeTrackedStateMETA
{
    using struct_type = XrFoveationEyeTrackedStateMETA;

    XrFoveationEyeTrackedStateMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector2f>* foveationCenter{ nullptr };
};

struct Decoded_XrSystemFoveationEyeTrackedPropertiesMETA
{
    using struct_type = XrSystemFoveationEyeTrackedPropertiesMETA;

    XrSystemFoveationEyeTrackedPropertiesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemFaceTrackingPropertiesFB
{
    using struct_type = XrSystemFaceTrackingPropertiesFB;

    XrSystemFaceTrackingPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFaceTrackerCreateInfoFB
{
    using struct_type = XrFaceTrackerCreateInfoFB;

    XrFaceTrackerCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFaceExpressionInfoFB
{
    using struct_type = XrFaceExpressionInfoFB;

    XrFaceExpressionInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFaceExpressionStatusFB
{
    using struct_type = XrFaceExpressionStatusFB;

    XrFaceExpressionStatusFB* decoded_value{ nullptr };
};

struct Decoded_XrFaceExpressionWeightsFB
{
    using struct_type = XrFaceExpressionWeightsFB;

    XrFaceExpressionWeightsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<float> weights;
    PointerDecoder<float> confidences;
    Decoded_XrFaceExpressionStatusFB* status{ nullptr };
};

struct Decoded_XrEyeGazeFB
{
    using struct_type = XrEyeGazeFB;

    XrEyeGazeFB* decoded_value{ nullptr };

    Decoded_XrPosef* gazePose{ nullptr };
};

struct Decoded_XrEyeTrackerCreateInfoFB
{
    using struct_type = XrEyeTrackerCreateInfoFB;

    XrEyeTrackerCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEyeGazesInfoFB
{
    using struct_type = XrEyeGazesInfoFB;

    XrEyeGazesInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
};

struct Decoded_XrSystemEyeTrackingPropertiesFB
{
    using struct_type = XrSystemEyeTrackingPropertiesFB;

    XrSystemEyeTrackingPropertiesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEyeGazesFB
{
    using struct_type = XrEyeGazesFB;

    XrEyeGazesFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrEyeGazeFB>* gaze{ nullptr };
};

struct Decoded_XrPassthroughKeyboardHandsIntensityFB
{
    using struct_type = XrPassthroughKeyboardHandsIntensityFB;

    XrPassthroughKeyboardHandsIntensityFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerSettingsFB
{
    using struct_type = XrCompositionLayerSettingsFB;

    XrCompositionLayerSettingsFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrHapticPcmVibrationFB
{
    using struct_type = XrHapticPcmVibrationFB;

    XrHapticPcmVibrationFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<float> buffer;
    PointerDecoder<uint32_t> samplesConsumed;
};

struct Decoded_XrDevicePcmSampleRateStateFB
{
    using struct_type = XrDevicePcmSampleRateStateFB;

    XrDevicePcmSampleRateStateFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrCompositionLayerDepthTestFB
{
    using struct_type = XrCompositionLayerDepthTestFB;

    XrCompositionLayerDepthTestFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrLocalDimmingFrameEndInfoMETA
{
    using struct_type = XrLocalDimmingFrameEndInfoMETA;

    XrLocalDimmingFrameEndInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughPreferencesMETA
{
    using struct_type = XrPassthroughPreferencesMETA;

    XrPassthroughPreferencesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemVirtualKeyboardPropertiesMETA
{
    using struct_type = XrSystemVirtualKeyboardPropertiesMETA;

    XrSystemVirtualKeyboardPropertiesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVirtualKeyboardCreateInfoMETA
{
    using struct_type = XrVirtualKeyboardCreateInfoMETA;

    XrVirtualKeyboardCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVirtualKeyboardSpaceCreateInfoMETA
{
    using struct_type = XrVirtualKeyboardSpaceCreateInfoMETA;

    XrVirtualKeyboardSpaceCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* poseInSpace{ nullptr };
};

struct Decoded_XrVirtualKeyboardLocationInfoMETA
{
    using struct_type = XrVirtualKeyboardLocationInfoMETA;

    XrVirtualKeyboardLocationInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* poseInSpace{ nullptr };
};

struct Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA
{
    using struct_type = XrVirtualKeyboardModelVisibilitySetInfoMETA;

    XrVirtualKeyboardModelVisibilitySetInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVirtualKeyboardAnimationStateMETA
{
    using struct_type = XrVirtualKeyboardAnimationStateMETA;

    XrVirtualKeyboardAnimationStateMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrVirtualKeyboardModelAnimationStatesMETA
{
    using struct_type = XrVirtualKeyboardModelAnimationStatesMETA;

    XrVirtualKeyboardModelAnimationStatesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVirtualKeyboardAnimationStateMETA>* states{ nullptr };
};

struct Decoded_XrVirtualKeyboardTextureDataMETA
{
    using struct_type = XrVirtualKeyboardTextureDataMETA;

    XrVirtualKeyboardTextureDataMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<uint8_t> buffer;
};

struct Decoded_XrVirtualKeyboardInputInfoMETA
{
    using struct_type = XrVirtualKeyboardInputInfoMETA;

    XrVirtualKeyboardInputInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId inputSpace{ format::kNullHandleId };
    Decoded_XrPosef* inputPoseInSpace{ nullptr };
};

struct Decoded_XrVirtualKeyboardTextContextChangeInfoMETA
{
    using struct_type = XrVirtualKeyboardTextContextChangeInfoMETA;

    XrVirtualKeyboardTextContextChangeInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder textContext;
};

struct Decoded_XrEventDataVirtualKeyboardCommitTextMETA
{
    using struct_type = XrEventDataVirtualKeyboardCommitTextMETA;

    XrEventDataVirtualKeyboardCommitTextMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId keyboard{ format::kNullHandleId };
    StringDecoder text;
};

struct Decoded_XrEventDataVirtualKeyboardBackspaceMETA
{
    using struct_type = XrEventDataVirtualKeyboardBackspaceMETA;

    XrEventDataVirtualKeyboardBackspaceMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId keyboard{ format::kNullHandleId };
};

struct Decoded_XrEventDataVirtualKeyboardEnterMETA
{
    using struct_type = XrEventDataVirtualKeyboardEnterMETA;

    XrEventDataVirtualKeyboardEnterMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId keyboard{ format::kNullHandleId };
};

struct Decoded_XrEventDataVirtualKeyboardShownMETA
{
    using struct_type = XrEventDataVirtualKeyboardShownMETA;

    XrEventDataVirtualKeyboardShownMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId keyboard{ format::kNullHandleId };
};

struct Decoded_XrEventDataVirtualKeyboardHiddenMETA
{
    using struct_type = XrEventDataVirtualKeyboardHiddenMETA;

    XrEventDataVirtualKeyboardHiddenMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId keyboard{ format::kNullHandleId };
};

struct Decoded_XrExternalCameraIntrinsicsOCULUS
{
    using struct_type = XrExternalCameraIntrinsicsOCULUS;

    XrExternalCameraIntrinsicsOCULUS* decoded_value{ nullptr };

    Decoded_XrFovf* fov{ nullptr };
    Decoded_XrExtent2Di* imageSensorPixelResolution{ nullptr };
};

struct Decoded_XrExternalCameraExtrinsicsOCULUS
{
    using struct_type = XrExternalCameraExtrinsicsOCULUS;

    XrExternalCameraExtrinsicsOCULUS* decoded_value{ nullptr };

    Decoded_XrPosef* relativePose{ nullptr };
};

struct Decoded_XrExternalCameraOCULUS
{
    using struct_type = XrExternalCameraOCULUS;

    XrExternalCameraOCULUS* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StringDecoder name;
    Decoded_XrExternalCameraIntrinsicsOCULUS* intrinsics{ nullptr };
    Decoded_XrExternalCameraExtrinsicsOCULUS* extrinsics{ nullptr };
};

struct Decoded_XrVulkanSwapchainCreateInfoMETA
{
    using struct_type = XrVulkanSwapchainCreateInfoMETA;

    XrVulkanSwapchainCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPerformanceMetricsStateMETA
{
    using struct_type = XrPerformanceMetricsStateMETA;

    XrPerformanceMetricsStateMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPerformanceMetricsCounterMETA
{
    using struct_type = XrPerformanceMetricsCounterMETA;

    XrPerformanceMetricsCounterMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceListSaveInfoFB
{
    using struct_type = XrSpaceListSaveInfoFB;

    XrSpaceListSaveInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    HandlePointerDecoder<XrSpace> spaces;
};

struct Decoded_XrEventDataSpaceListSaveCompleteFB
{
    using struct_type = XrEventDataSpaceListSaveCompleteFB;

    XrEventDataSpaceListSaveCompleteFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId requestId{ format::kNullHandleId };
};

struct Decoded_XrSpaceUserCreateInfoFB
{
    using struct_type = XrSpaceUserCreateInfoFB;

    XrSpaceUserCreateInfoFB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemHeadsetIdPropertiesMETA
{
    using struct_type = XrSystemHeadsetIdPropertiesMETA;

    XrSystemHeadsetIdPropertiesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrUuid* id{ nullptr };
};

struct Decoded_XrRecommendedLayerResolutionMETA
{
    using struct_type = XrRecommendedLayerResolutionMETA;

    XrRecommendedLayerResolutionMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrExtent2Di* recommendedImageDimensions{ nullptr };
};

struct Decoded_XrRecommendedLayerResolutionGetInfoMETA
{
    using struct_type = XrRecommendedLayerResolutionGetInfoMETA;

    XrRecommendedLayerResolutionGetInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrCompositionLayerBaseHeader>* layer{ nullptr };
};

struct Decoded_XrPassthroughColorLutDataMETA
{
    using struct_type = XrPassthroughColorLutDataMETA;

    XrPassthroughColorLutDataMETA* decoded_value{ nullptr };

    PointerDecoder<uint8_t> buffer;
};

struct Decoded_XrPassthroughColorLutCreateInfoMETA
{
    using struct_type = XrPassthroughColorLutCreateInfoMETA;

    XrPassthroughColorLutCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPassthroughColorLutDataMETA* data{ nullptr };
};

struct Decoded_XrPassthroughColorLutUpdateInfoMETA
{
    using struct_type = XrPassthroughColorLutUpdateInfoMETA;

    XrPassthroughColorLutUpdateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPassthroughColorLutDataMETA* data{ nullptr };
};

struct Decoded_XrPassthroughColorMapLutMETA
{
    using struct_type = XrPassthroughColorMapLutMETA;

    XrPassthroughColorMapLutMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId colorLut{ format::kNullHandleId };
};

struct Decoded_XrPassthroughColorMapInterpolatedLutMETA
{
    using struct_type = XrPassthroughColorMapInterpolatedLutMETA;

    XrPassthroughColorMapInterpolatedLutMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId sourceColorLut{ format::kNullHandleId };
    format::HandleId targetColorLut{ format::kNullHandleId };
};

struct Decoded_XrSystemPassthroughColorLutPropertiesMETA
{
    using struct_type = XrSystemPassthroughColorLutPropertiesMETA;

    XrSystemPassthroughColorLutPropertiesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceTriangleMeshGetInfoMETA
{
    using struct_type = XrSpaceTriangleMeshGetInfoMETA;

    XrSpaceTriangleMeshGetInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpaceTriangleMeshMETA
{
    using struct_type = XrSpaceTriangleMeshMETA;

    XrSpaceTriangleMeshMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector3f>* vertices{ nullptr };
    PointerDecoder<uint32_t> indices;
};

struct Decoded_XrSystemFaceTrackingProperties2FB
{
    using struct_type = XrSystemFaceTrackingProperties2FB;

    XrSystemFaceTrackingProperties2FB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFaceTrackerCreateInfo2FB
{
    using struct_type = XrFaceTrackerCreateInfo2FB;

    XrFaceTrackerCreateInfo2FB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrFaceTrackingDataSource2FB> requestedDataSources;
};

struct Decoded_XrFaceExpressionInfo2FB
{
    using struct_type = XrFaceExpressionInfo2FB;

    XrFaceExpressionInfo2FB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFaceExpressionWeights2FB
{
    using struct_type = XrFaceExpressionWeights2FB;

    XrFaceExpressionWeights2FB* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<float> weights;
    PointerDecoder<float> confidences;
};

struct Decoded_XrEnvironmentDepthProviderCreateInfoMETA
{
    using struct_type = XrEnvironmentDepthProviderCreateInfoMETA;

    XrEnvironmentDepthProviderCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA
{
    using struct_type = XrEnvironmentDepthSwapchainCreateInfoMETA;

    XrEnvironmentDepthSwapchainCreateInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEnvironmentDepthSwapchainStateMETA
{
    using struct_type = XrEnvironmentDepthSwapchainStateMETA;

    XrEnvironmentDepthSwapchainStateMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEnvironmentDepthImageAcquireInfoMETA
{
    using struct_type = XrEnvironmentDepthImageAcquireInfoMETA;

    XrEnvironmentDepthImageAcquireInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
};

struct Decoded_XrEnvironmentDepthImageViewMETA
{
    using struct_type = XrEnvironmentDepthImageViewMETA;

    XrEnvironmentDepthImageViewMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrFovf* fov{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
};

struct Decoded_XrEnvironmentDepthImageMETA
{
    using struct_type = XrEnvironmentDepthImageMETA;

    XrEnvironmentDepthImageMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrEnvironmentDepthImageViewMETA>* views{ nullptr };
};

struct Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA
{
    using struct_type = XrEnvironmentDepthHandRemovalSetInfoMETA;

    XrEnvironmentDepthHandRemovalSetInfoMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemEnvironmentDepthPropertiesMETA
{
    using struct_type = XrSystemEnvironmentDepthPropertiesMETA;

    XrSystemEnvironmentDepthPropertiesMETA* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughCreateInfoHTC
{
    using struct_type = XrPassthroughCreateInfoHTC;

    XrPassthroughCreateInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughColorHTC
{
    using struct_type = XrPassthroughColorHTC;

    XrPassthroughColorHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPassthroughMeshTransformInfoHTC
{
    using struct_type = XrPassthroughMeshTransformInfoHTC;

    XrPassthroughMeshTransformInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector3f>* vertices{ nullptr };
    PointerDecoder<uint32_t> indices;
    format::HandleId baseSpace{ format::kNullHandleId };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrVector3f* scale{ nullptr };
};

struct Decoded_XrCompositionLayerPassthroughHTC
{
    using struct_type = XrCompositionLayerPassthroughHTC;

    XrCompositionLayerPassthroughHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    format::HandleId passthrough{ format::kNullHandleId };
    Decoded_XrPassthroughColorHTC* color{ nullptr };
};

struct Decoded_XrFoveationApplyInfoHTC
{
    using struct_type = XrFoveationApplyInfoHTC;

    XrFoveationApplyInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrSwapchainSubImage>* subImages{ nullptr };
};

struct Decoded_XrFoveationConfigurationHTC
{
    using struct_type = XrFoveationConfigurationHTC;

    XrFoveationConfigurationHTC* decoded_value{ nullptr };

    Decoded_XrVector2f* focalCenterOffset{ nullptr };
};

struct Decoded_XrFoveationDynamicModeInfoHTC
{
    using struct_type = XrFoveationDynamicModeInfoHTC;

    XrFoveationDynamicModeInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFoveationCustomModeInfoHTC
{
    using struct_type = XrFoveationCustomModeInfoHTC;

    XrFoveationCustomModeInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrFoveationConfigurationHTC>* configs{ nullptr };
};

struct Decoded_XrSystemAnchorPropertiesHTC
{
    using struct_type = XrSystemAnchorPropertiesHTC;

    XrSystemAnchorPropertiesHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSpatialAnchorNameHTC
{
    using struct_type = XrSpatialAnchorNameHTC;

    XrSpatialAnchorNameHTC* decoded_value{ nullptr };

    StringDecoder name;
};

struct Decoded_XrSpatialAnchorCreateInfoHTC
{
    using struct_type = XrSpatialAnchorCreateInfoHTC;

    XrSpatialAnchorCreateInfoHTC* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
    Decoded_XrPosef* poseInSpace{ nullptr };
    Decoded_XrSpatialAnchorNameHTC* name{ nullptr };
};

struct Decoded_XrActiveActionSetPriorityEXT
{
    using struct_type = XrActiveActionSetPriorityEXT;

    XrActiveActionSetPriorityEXT* decoded_value{ nullptr };

    format::HandleId actionSet{ format::kNullHandleId };
};

struct Decoded_XrActiveActionSetPrioritiesEXT
{
    using struct_type = XrActiveActionSetPrioritiesEXT;

    XrActiveActionSetPrioritiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrActiveActionSetPriorityEXT>* actionSetPriorities{ nullptr };
};

struct Decoded_XrSystemForceFeedbackCurlPropertiesMNDX
{
    using struct_type = XrSystemForceFeedbackCurlPropertiesMNDX;

    XrSystemForceFeedbackCurlPropertiesMNDX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrForceFeedbackCurlApplyLocationMNDX
{
    using struct_type = XrForceFeedbackCurlApplyLocationMNDX;

    XrForceFeedbackCurlApplyLocationMNDX* decoded_value{ nullptr };
};

struct Decoded_XrForceFeedbackCurlApplyLocationsMNDX
{
    using struct_type = XrForceFeedbackCurlApplyLocationsMNDX;

    XrForceFeedbackCurlApplyLocationsMNDX* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationMNDX>* locations{ nullptr };
};

struct Decoded_XrHandTrackingDataSourceInfoEXT
{
    using struct_type = XrHandTrackingDataSourceInfoEXT;

    XrHandTrackingDataSourceInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    PointerDecoder<XrHandTrackingDataSourceEXT> requestedDataSources;
};

struct Decoded_XrHandTrackingDataSourceStateEXT
{
    using struct_type = XrHandTrackingDataSourceStateEXT;

    XrHandTrackingDataSourceStateEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrSystemPlaneDetectionPropertiesEXT
{
    using struct_type = XrSystemPlaneDetectionPropertiesEXT;

    XrSystemPlaneDetectionPropertiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPlaneDetectorCreateInfoEXT
{
    using struct_type = XrPlaneDetectorCreateInfoEXT;

    XrPlaneDetectorCreateInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrPlaneDetectorBeginInfoEXT
{
    using struct_type = XrPlaneDetectorBeginInfoEXT;

    XrPlaneDetectorBeginInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
    PointerDecoder<XrPlaneDetectorOrientationEXT> orientations;
    PointerDecoder<XrPlaneDetectorSemanticTypeEXT> semanticTypes;
    Decoded_XrPosef* boundingBoxPose{ nullptr };
    Decoded_XrExtent3Df* boundingBoxExtent{ nullptr };
};

struct Decoded_XrPlaneDetectorGetInfoEXT
{
    using struct_type = XrPlaneDetectorGetInfoEXT;

    XrPlaneDetectorGetInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId baseSpace{ format::kNullHandleId };
};

struct Decoded_XrPlaneDetectorLocationEXT
{
    using struct_type = XrPlaneDetectorLocationEXT;

    XrPlaneDetectorLocationEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    Decoded_XrPosef* pose{ nullptr };
    Decoded_XrExtent2Df* extents{ nullptr };
};

struct Decoded_XrPlaneDetectorLocationsEXT
{
    using struct_type = XrPlaneDetectorLocationsEXT;

    XrPlaneDetectorLocationsEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrPlaneDetectorLocationEXT>* planeLocations{ nullptr };
};

struct Decoded_XrPlaneDetectorPolygonBufferEXT
{
    using struct_type = XrPlaneDetectorPolygonBufferEXT;

    XrPlaneDetectorPolygonBufferEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    StructPointerDecoder<Decoded_XrVector2f>* vertices{ nullptr };
};

struct Decoded_XrFutureCancelInfoEXT
{
    using struct_type = XrFutureCancelInfoEXT;

    XrFutureCancelInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId future{ format::kNullHandleId };
};

struct Decoded_XrFuturePollInfoEXT
{
    using struct_type = XrFuturePollInfoEXT;

    XrFuturePollInfoEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId future{ format::kNullHandleId };
};

struct Decoded_XrFutureCompletionEXT
{
    using struct_type = XrFutureCompletionEXT;

    XrFutureCompletionEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrFuturePollResultEXT
{
    using struct_type = XrFuturePollResultEXT;

    XrFuturePollResultEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataUserPresenceChangedEXT
{
    using struct_type = XrEventDataUserPresenceChangedEXT;

    XrEventDataUserPresenceChangedEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_XrSystemUserPresencePropertiesEXT
{
    using struct_type = XrSystemUserPresencePropertiesEXT;

    XrSystemUserPresencePropertiesEXT* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataHeadsetFitChangedML
{
    using struct_type = XrEventDataHeadsetFitChangedML;

    XrEventDataHeadsetFitChangedML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrEventDataEyeCalibrationChangedML
{
    using struct_type = XrEventDataEyeCalibrationChangedML;

    XrEventDataEyeCalibrationChangedML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

struct Decoded_XrUserCalibrationEnableEventsInfoML
{
    using struct_type = XrUserCalibrationEnableEventsInfoML;

    XrUserCalibrationEnableEventsInfoML* decoded_value{ nullptr };

    OpenXrNextNode* next{ nullptr };
};

typedef Decoded_XrGraphicsBindingVulkanKHR Decoded_XrGraphicsBindingVulkan2KHR;

typedef Decoded_XrSwapchainImageVulkanKHR Decoded_XrSwapchainImageVulkan2KHR;

typedef Decoded_XrGraphicsRequirementsVulkanKHR Decoded_XrGraphicsRequirementsVulkan2KHR;

typedef Decoded_XrSpacesLocateInfo Decoded_XrSpacesLocateInfoKHR;

typedef Decoded_XrSpaceLocationData Decoded_XrSpaceLocationDataKHR;

typedef Decoded_XrSpaceLocations Decoded_XrSpaceLocationsKHR;

typedef Decoded_XrSpaceVelocityData Decoded_XrSpaceVelocityDataKHR;

typedef Decoded_XrSpaceVelocities Decoded_XrSpaceVelocitiesKHR;

typedef Decoded_XrColor3f Decoded_XrColor3fKHR;

typedef Decoded_XrExtent3Df Decoded_XrExtent3DfKHR;

typedef Decoded_XrSpheref Decoded_XrSpherefKHR;

typedef Decoded_XrBoxf Decoded_XrBoxfKHR;

typedef Decoded_XrFrustumf Decoded_XrFrustumfKHR;

typedef Decoded_XrUuid Decoded_XrUuidEXT;

typedef Decoded_XrExtent3Df Decoded_XrExtent3DfFB;

typedef Decoded_XrDevicePcmSampleRateStateFB Decoded_XrDevicePcmSampleRateGetInfoFB;

typedef Decoded_XrExtent3Df Decoded_XrExtent3DfEXT;

union XrSwapchainImageBaseHeaderSizeUnion
{
    XrSwapchainImageOpenGLKHR a;
    XrSwapchainImageOpenGLESKHR b;
    XrSwapchainImageVulkanKHR c;
    XrSwapchainImageD3D11KHR d;
    XrSwapchainImageD3D12KHR e;
};

struct Decoded_XrSwapchainImageBaseHeader
{
    using struct_type = XrSwapchainImageBaseHeader;
    using union_size_type = XrSwapchainImageBaseHeaderSizeUnion;

    XrSwapchainImageBaseHeader* decoded_value{ nullptr };

    static Decoded_XrSwapchainImageBaseHeader* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrSwapchainImageBaseHeader* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrSwapchainImageBaseHeader>(len, initialize);
                break;
         case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
             return_type = reinterpret_cast<Decoded_XrSwapchainImageBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrSwapchainImageOpenGLKHR>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
             return_type = reinterpret_cast<Decoded_XrSwapchainImageBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrSwapchainImageOpenGLESKHR>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
             return_type = reinterpret_cast<Decoded_XrSwapchainImageBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrSwapchainImageVulkanKHR>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
             return_type = reinterpret_cast<Decoded_XrSwapchainImageBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrSwapchainImageD3D11KHR>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
             return_type = reinterpret_cast<Decoded_XrSwapchainImageBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrSwapchainImageD3D12KHR>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainImageBaseHeader* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                Decoded_XrSwapchainImageOpenGLKHR* local_dest = reinterpret_cast<Decoded_XrSwapchainImageOpenGLKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            {
                Decoded_XrSwapchainImageOpenGLESKHR* local_dest = reinterpret_cast<Decoded_XrSwapchainImageOpenGLESKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                Decoded_XrSwapchainImageVulkanKHR* local_dest = reinterpret_cast<Decoded_XrSwapchainImageVulkanKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                Decoded_XrSwapchainImageD3D11KHR* local_dest = reinterpret_cast<Decoded_XrSwapchainImageD3D11KHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                Decoded_XrSwapchainImageD3D12KHR* local_dest = reinterpret_cast<Decoded_XrSwapchainImageD3D12KHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrSwapchainImageBaseHeader *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrSwapchainImageBaseHeader *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrSwapchainImageBaseHeader>(len);
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainImageOpenGLKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainImageOpenGLKHR{ XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR };
                }
                output_data = reinterpret_cast<XrSwapchainImageBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainImageOpenGLESKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainImageOpenGLESKHR{ XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR };
                }
                output_data = reinterpret_cast<XrSwapchainImageBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainImageVulkanKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainImageVulkanKHR{ XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR };
                }
                output_data = reinterpret_cast<XrSwapchainImageBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainImageD3D11KHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainImageD3D11KHR{ XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR };
                }
                output_data = reinterpret_cast<XrSwapchainImageBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainImageD3D12KHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainImageD3D12KHR{ XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR };
                }
                output_data = reinterpret_cast<XrSwapchainImageBaseHeader*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrCompositionLayerBaseHeaderSizeUnion
{
    XrCompositionLayerProjection a;
    XrCompositionLayerQuad b;
    XrCompositionLayerCubeKHR c;
    XrCompositionLayerCylinderKHR d;
    XrCompositionLayerEquirectKHR e;
    XrCompositionLayerEquirect2KHR f;
    XrCompositionLayerPassthroughFB g;
    XrCompositionLayerPassthroughHTC h;
};

struct Decoded_XrCompositionLayerBaseHeader
{
    using struct_type = XrCompositionLayerBaseHeader;
    using union_size_type = XrCompositionLayerBaseHeaderSizeUnion;

    XrCompositionLayerBaseHeader* decoded_value{ nullptr };

    static Decoded_XrCompositionLayerBaseHeader* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrCompositionLayerBaseHeader* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrCompositionLayerBaseHeader>(len, initialize);
                break;
         case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerProjection>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_QUAD:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerQuad>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerCubeKHR>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerCylinderKHR>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerEquirectKHR>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerEquirect2KHR>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerPassthroughFB>(len, initialize));
             break;
         case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
             return_type = reinterpret_cast<Decoded_XrCompositionLayerBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrCompositionLayerPassthroughHTC>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrCompositionLayerBaseHeader* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            {
                Decoded_XrCompositionLayerProjection* local_dest = reinterpret_cast<Decoded_XrCompositionLayerProjection*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
            {
                Decoded_XrCompositionLayerQuad* local_dest = reinterpret_cast<Decoded_XrCompositionLayerQuad*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            {
                Decoded_XrCompositionLayerCubeKHR* local_dest = reinterpret_cast<Decoded_XrCompositionLayerCubeKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            {
                Decoded_XrCompositionLayerCylinderKHR* local_dest = reinterpret_cast<Decoded_XrCompositionLayerCylinderKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            {
                Decoded_XrCompositionLayerEquirectKHR* local_dest = reinterpret_cast<Decoded_XrCompositionLayerEquirectKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            {
                Decoded_XrCompositionLayerEquirect2KHR* local_dest = reinterpret_cast<Decoded_XrCompositionLayerEquirect2KHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            {
                Decoded_XrCompositionLayerPassthroughFB* local_dest = reinterpret_cast<Decoded_XrCompositionLayerPassthroughFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            {
                Decoded_XrCompositionLayerPassthroughHTC* local_dest = reinterpret_cast<Decoded_XrCompositionLayerPassthroughHTC*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrCompositionLayerBaseHeader *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrCompositionLayerBaseHeader *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrCompositionLayerBaseHeader>(len);
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerProjection>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerProjection{ XR_TYPE_COMPOSITION_LAYER_PROJECTION };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerQuad>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerQuad{ XR_TYPE_COMPOSITION_LAYER_QUAD };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerCubeKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerCubeKHR{ XR_TYPE_COMPOSITION_LAYER_CUBE_KHR };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerCylinderKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerCylinderKHR{ XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerEquirectKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerEquirectKHR{ XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerEquirect2KHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerEquirect2KHR{ XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerPassthroughFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerPassthroughFB{ XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            {
                auto *allocation = DecodeAllocator::Allocate<XrCompositionLayerPassthroughHTC>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrCompositionLayerPassthroughHTC{ XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC };
                }
                output_data = reinterpret_cast<XrCompositionLayerBaseHeader*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
    format::HandleId space{ format::kNullHandleId };
};


union XrHapticBaseHeaderSizeUnion
{
    XrHapticVibration a;
    XrHapticAmplitudeEnvelopeVibrationFB b;
    XrHapticPcmVibrationFB c;
};

struct Decoded_XrHapticBaseHeader
{
    using struct_type = XrHapticBaseHeader;
    using union_size_type = XrHapticBaseHeaderSizeUnion;

    XrHapticBaseHeader* decoded_value{ nullptr };

    static Decoded_XrHapticBaseHeader* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrHapticBaseHeader* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrHapticBaseHeader>(len, initialize);
                break;
         case XR_TYPE_HAPTIC_VIBRATION:
             return_type = reinterpret_cast<Decoded_XrHapticBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrHapticVibration>(len, initialize));
             break;
         case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
             return_type = reinterpret_cast<Decoded_XrHapticBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrHapticAmplitudeEnvelopeVibrationFB>(len, initialize));
             break;
         case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
             return_type = reinterpret_cast<Decoded_XrHapticBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrHapticPcmVibrationFB>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrHapticBaseHeader* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_HAPTIC_VIBRATION:
            {
                Decoded_XrHapticVibration* local_dest = reinterpret_cast<Decoded_XrHapticVibration*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            {
                Decoded_XrHapticAmplitudeEnvelopeVibrationFB* local_dest = reinterpret_cast<Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            {
                Decoded_XrHapticPcmVibrationFB* local_dest = reinterpret_cast<Decoded_XrHapticPcmVibrationFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrHapticBaseHeader *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrHapticBaseHeader *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrHapticBaseHeader>(len);
                break;
            case XR_TYPE_HAPTIC_VIBRATION:
            {
                auto *allocation = DecodeAllocator::Allocate<XrHapticVibration>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrHapticVibration{ XR_TYPE_HAPTIC_VIBRATION };
                }
                output_data = reinterpret_cast<XrHapticBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrHapticAmplitudeEnvelopeVibrationFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrHapticAmplitudeEnvelopeVibrationFB{ XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB };
                }
                output_data = reinterpret_cast<XrHapticBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrHapticPcmVibrationFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrHapticPcmVibrationFB{ XR_TYPE_HAPTIC_PCM_VIBRATION_FB };
                }
                output_data = reinterpret_cast<XrHapticBaseHeader*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrEventDataBaseHeaderSizeUnion
{
    XrEventDataEventsLost a;
    XrEventDataInstanceLossPending b;
    XrEventDataSessionStateChanged c;
    XrEventDataReferenceSpaceChangePending d;
    XrEventDataInteractionProfileChanged e;
    XrEventDataVisibilityMaskChangedKHR f;
    XrEventDataPerfSettingsEXT g;
    XrEventDataMainSessionVisibilityChangedEXTX h;
    XrEventDataDisplayRefreshRateChangedFB i;
    XrEventDataViveTrackerConnectedHTCX j;
    XrEventDataSpatialAnchorCreateCompleteFB k;
    XrEventDataSpaceSetStatusCompleteFB l;
    XrEventDataMarkerTrackingUpdateVARJO m;
    XrEventDataLocalizationChangedML n;
    XrEventDataSpaceQueryResultsAvailableFB o;
    XrEventDataSpaceQueryCompleteFB p;
    XrEventDataSpaceSaveCompleteFB q;
    XrEventDataSpaceEraseCompleteFB r;
    XrEventDataSpaceShareCompleteFB s;
    XrEventDataSpaceListSaveCompleteFB t;
    XrEventDataHeadsetFitChangedML u;
    XrEventDataEyeCalibrationChangedML v;
};

struct Decoded_XrEventDataBaseHeader
{
    using struct_type = XrEventDataBaseHeader;
    using union_size_type = XrEventDataBaseHeaderSizeUnion;

    XrEventDataBaseHeader* decoded_value{ nullptr };

    static Decoded_XrEventDataBaseHeader* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrEventDataBaseHeader* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrEventDataBaseHeader>(len, initialize);
                break;
         case XR_TYPE_EVENT_DATA_EVENTS_LOST:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataEventsLost>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataInstanceLossPending>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSessionStateChanged>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataReferenceSpaceChangePending>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataInteractionProfileChanged>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataVisibilityMaskChangedKHR>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataPerfSettingsEXT>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataMainSessionVisibilityChangedEXTX>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataDisplayRefreshRateChangedFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataViveTrackerConnectedHTCX>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpatialAnchorCreateCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceSetStatusCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataMarkerTrackingUpdateVARJO>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataLocalizationChangedML>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceQueryResultsAvailableFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceQueryCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceSaveCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceEraseCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceShareCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataSpaceListSaveCompleteFB>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataHeadsetFitChangedML>(len, initialize));
             break;
         case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
             return_type = reinterpret_cast<Decoded_XrEventDataBaseHeader*>(DecodeAllocator::Allocate<Decoded_XrEventDataEyeCalibrationChangedML>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrEventDataBaseHeader* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            {
                Decoded_XrEventDataEventsLost* local_dest = reinterpret_cast<Decoded_XrEventDataEventsLost*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            {
                Decoded_XrEventDataInstanceLossPending* local_dest = reinterpret_cast<Decoded_XrEventDataInstanceLossPending*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            {
                Decoded_XrEventDataSessionStateChanged* local_dest = reinterpret_cast<Decoded_XrEventDataSessionStateChanged*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            {
                Decoded_XrEventDataReferenceSpaceChangePending* local_dest = reinterpret_cast<Decoded_XrEventDataReferenceSpaceChangePending*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            {
                Decoded_XrEventDataInteractionProfileChanged* local_dest = reinterpret_cast<Decoded_XrEventDataInteractionProfileChanged*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            {
                Decoded_XrEventDataVisibilityMaskChangedKHR* local_dest = reinterpret_cast<Decoded_XrEventDataVisibilityMaskChangedKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            {
                Decoded_XrEventDataPerfSettingsEXT* local_dest = reinterpret_cast<Decoded_XrEventDataPerfSettingsEXT*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            {
                Decoded_XrEventDataMainSessionVisibilityChangedEXTX* local_dest = reinterpret_cast<Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            {
                Decoded_XrEventDataDisplayRefreshRateChangedFB* local_dest = reinterpret_cast<Decoded_XrEventDataDisplayRefreshRateChangedFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            {
                Decoded_XrEventDataViveTrackerConnectedHTCX* local_dest = reinterpret_cast<Decoded_XrEventDataViveTrackerConnectedHTCX*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            {
                Decoded_XrEventDataSpatialAnchorCreateCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceSetStatusCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceSetStatusCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            {
                Decoded_XrEventDataMarkerTrackingUpdateVARJO* local_dest = reinterpret_cast<Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            {
                Decoded_XrEventDataLocalizationChangedML* local_dest = reinterpret_cast<Decoded_XrEventDataLocalizationChangedML*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            {
                Decoded_XrEventDataSpaceQueryResultsAvailableFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceQueryCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceQueryCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceSaveCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceSaveCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceEraseCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceEraseCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceShareCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceShareCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            {
                Decoded_XrEventDataSpaceListSaveCompleteFB* local_dest = reinterpret_cast<Decoded_XrEventDataSpaceListSaveCompleteFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            {
                Decoded_XrEventDataHeadsetFitChangedML* local_dest = reinterpret_cast<Decoded_XrEventDataHeadsetFitChangedML*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            {
                Decoded_XrEventDataEyeCalibrationChangedML* local_dest = reinterpret_cast<Decoded_XrEventDataEyeCalibrationChangedML*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrEventDataBaseHeader *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrEventDataBaseHeader *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrEventDataBaseHeader>(len);
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataEventsLost>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataEventsLost{ XR_TYPE_EVENT_DATA_EVENTS_LOST };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataInstanceLossPending>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataInstanceLossPending{ XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSessionStateChanged>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSessionStateChanged{ XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataReferenceSpaceChangePending>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataReferenceSpaceChangePending{ XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataInteractionProfileChanged>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataInteractionProfileChanged{ XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataVisibilityMaskChangedKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataVisibilityMaskChangedKHR{ XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataPerfSettingsEXT>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataPerfSettingsEXT{ XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataMainSessionVisibilityChangedEXTX>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataMainSessionVisibilityChangedEXTX{ XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataDisplayRefreshRateChangedFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataDisplayRefreshRateChangedFB{ XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataViveTrackerConnectedHTCX>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataViveTrackerConnectedHTCX{ XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpatialAnchorCreateCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpatialAnchorCreateCompleteFB{ XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceSetStatusCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceSetStatusCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataMarkerTrackingUpdateVARJO>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataMarkerTrackingUpdateVARJO{ XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataLocalizationChangedML>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataLocalizationChangedML{ XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceQueryResultsAvailableFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceQueryResultsAvailableFB{ XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceQueryCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceQueryCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceSaveCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceSaveCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceEraseCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceEraseCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceShareCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceShareCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataSpaceListSaveCompleteFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataSpaceListSaveCompleteFB{ XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataHeadsetFitChangedML>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataHeadsetFitChangedML{ XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            {
                auto *allocation = DecodeAllocator::Allocate<XrEventDataEyeCalibrationChangedML>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrEventDataEyeCalibrationChangedML{ XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML };
                }
                output_data = reinterpret_cast<XrEventDataBaseHeader*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrLoaderInitInfoBaseHeaderKHRSizeUnion
{
    XrLoaderInitInfoAndroidKHR a;
};

struct Decoded_XrLoaderInitInfoBaseHeaderKHR
{
    using struct_type = XrLoaderInitInfoBaseHeaderKHR;
    using union_size_type = XrLoaderInitInfoBaseHeaderKHRSizeUnion;

    XrLoaderInitInfoBaseHeaderKHR* decoded_value{ nullptr };

    static Decoded_XrLoaderInitInfoBaseHeaderKHR* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrLoaderInitInfoBaseHeaderKHR* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrLoaderInitInfoBaseHeaderKHR>(len, initialize);
                break;
         case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
             return_type = reinterpret_cast<Decoded_XrLoaderInitInfoBaseHeaderKHR*>(DecodeAllocator::Allocate<Decoded_XrLoaderInitInfoAndroidKHR>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrLoaderInitInfoBaseHeaderKHR* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            {
                Decoded_XrLoaderInitInfoAndroidKHR* local_dest = reinterpret_cast<Decoded_XrLoaderInitInfoAndroidKHR*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrLoaderInitInfoBaseHeaderKHR *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrLoaderInitInfoBaseHeaderKHR *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrLoaderInitInfoBaseHeaderKHR>(len);
                break;
            case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            {
                auto *allocation = DecodeAllocator::Allocate<XrLoaderInitInfoAndroidKHR>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrLoaderInitInfoAndroidKHR{ XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR };
                }
                output_data = reinterpret_cast<XrLoaderInitInfoBaseHeaderKHR*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrBindingModificationBaseHeaderKHRSizeUnion
{
    XrInteractionProfileDpadBindingEXT a;
    XrInteractionProfileAnalogThresholdVALVE b;
};

struct Decoded_XrBindingModificationBaseHeaderKHR
{
    using struct_type = XrBindingModificationBaseHeaderKHR;
    using union_size_type = XrBindingModificationBaseHeaderKHRSizeUnion;

    XrBindingModificationBaseHeaderKHR* decoded_value{ nullptr };

    static Decoded_XrBindingModificationBaseHeaderKHR* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrBindingModificationBaseHeaderKHR* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrBindingModificationBaseHeaderKHR>(len, initialize);
                break;
         case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
             return_type = reinterpret_cast<Decoded_XrBindingModificationBaseHeaderKHR*>(DecodeAllocator::Allocate<Decoded_XrInteractionProfileDpadBindingEXT>(len, initialize));
             break;
         case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
             return_type = reinterpret_cast<Decoded_XrBindingModificationBaseHeaderKHR*>(DecodeAllocator::Allocate<Decoded_XrInteractionProfileAnalogThresholdVALVE>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrBindingModificationBaseHeaderKHR* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            {
                Decoded_XrInteractionProfileDpadBindingEXT* local_dest = reinterpret_cast<Decoded_XrInteractionProfileDpadBindingEXT*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            {
                Decoded_XrInteractionProfileAnalogThresholdVALVE* local_dest = reinterpret_cast<Decoded_XrInteractionProfileAnalogThresholdVALVE*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrBindingModificationBaseHeaderKHR *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrBindingModificationBaseHeaderKHR *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrBindingModificationBaseHeaderKHR>(len);
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            {
                auto *allocation = DecodeAllocator::Allocate<XrInteractionProfileDpadBindingEXT>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrInteractionProfileDpadBindingEXT{ XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT };
                }
                output_data = reinterpret_cast<XrBindingModificationBaseHeaderKHR*>(allocation);
                break;
            }
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            {
                auto *allocation = DecodeAllocator::Allocate<XrInteractionProfileAnalogThresholdVALVE>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrInteractionProfileAnalogThresholdVALVE{ XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE };
                }
                output_data = reinterpret_cast<XrBindingModificationBaseHeaderKHR*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrSwapchainStateBaseHeaderFBSizeUnion
{
    XrSwapchainStateFoveationFB a;
    XrSwapchainStateAndroidSurfaceDimensionsFB b;
    XrSwapchainStateSamplerOpenGLESFB c;
    XrSwapchainStateSamplerVulkanFB d;
};

struct Decoded_XrSwapchainStateBaseHeaderFB
{
    using struct_type = XrSwapchainStateBaseHeaderFB;
    using union_size_type = XrSwapchainStateBaseHeaderFBSizeUnion;

    XrSwapchainStateBaseHeaderFB* decoded_value{ nullptr };

    static Decoded_XrSwapchainStateBaseHeaderFB* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrSwapchainStateBaseHeaderFB* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrSwapchainStateBaseHeaderFB>(len, initialize);
                break;
         case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
             return_type = reinterpret_cast<Decoded_XrSwapchainStateBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSwapchainStateFoveationFB>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
             return_type = reinterpret_cast<Decoded_XrSwapchainStateBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
             return_type = reinterpret_cast<Decoded_XrSwapchainStateBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSwapchainStateSamplerOpenGLESFB>(len, initialize));
             break;
         case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
             return_type = reinterpret_cast<Decoded_XrSwapchainStateBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSwapchainStateSamplerVulkanFB>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrSwapchainStateBaseHeaderFB* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            {
                Decoded_XrSwapchainStateFoveationFB* local_dest = reinterpret_cast<Decoded_XrSwapchainStateFoveationFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            {
                Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* local_dest = reinterpret_cast<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            {
                Decoded_XrSwapchainStateSamplerOpenGLESFB* local_dest = reinterpret_cast<Decoded_XrSwapchainStateSamplerOpenGLESFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            {
                Decoded_XrSwapchainStateSamplerVulkanFB* local_dest = reinterpret_cast<Decoded_XrSwapchainStateSamplerVulkanFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrSwapchainStateBaseHeaderFB *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrSwapchainStateBaseHeaderFB *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrSwapchainStateBaseHeaderFB>(len);
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainStateFoveationFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainStateFoveationFB{ XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB };
                }
                output_data = reinterpret_cast<XrSwapchainStateBaseHeaderFB*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainStateAndroidSurfaceDimensionsFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainStateAndroidSurfaceDimensionsFB{ XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB };
                }
                output_data = reinterpret_cast<XrSwapchainStateBaseHeaderFB*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainStateSamplerOpenGLESFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainStateSamplerOpenGLESFB{ XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB };
                }
                output_data = reinterpret_cast<XrSwapchainStateBaseHeaderFB*>(allocation);
                break;
            }
            case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSwapchainStateSamplerVulkanFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSwapchainStateSamplerVulkanFB{ XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB };
                }
                output_data = reinterpret_cast<XrSwapchainStateBaseHeaderFB*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrSpaceQueryInfoBaseHeaderFBSizeUnion
{
    XrSpaceQueryInfoFB a;
};

struct Decoded_XrSpaceQueryInfoBaseHeaderFB
{
    using struct_type = XrSpaceQueryInfoBaseHeaderFB;
    using union_size_type = XrSpaceQueryInfoBaseHeaderFBSizeUnion;

    XrSpaceQueryInfoBaseHeaderFB* decoded_value{ nullptr };

    static Decoded_XrSpaceQueryInfoBaseHeaderFB* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrSpaceQueryInfoBaseHeaderFB* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrSpaceQueryInfoBaseHeaderFB>(len, initialize);
                break;
         case XR_TYPE_SPACE_QUERY_INFO_FB:
             return_type = reinterpret_cast<Decoded_XrSpaceQueryInfoBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSpaceQueryInfoFB>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceQueryInfoBaseHeaderFB* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_SPACE_QUERY_INFO_FB:
            {
                Decoded_XrSpaceQueryInfoFB* local_dest = reinterpret_cast<Decoded_XrSpaceQueryInfoFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrSpaceQueryInfoBaseHeaderFB *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrSpaceQueryInfoBaseHeaderFB *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrSpaceQueryInfoBaseHeaderFB>(len);
                break;
            case XR_TYPE_SPACE_QUERY_INFO_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSpaceQueryInfoFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSpaceQueryInfoFB{ XR_TYPE_SPACE_QUERY_INFO_FB };
                }
                output_data = reinterpret_cast<XrSpaceQueryInfoBaseHeaderFB*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrSpaceFilterInfoBaseHeaderFBSizeUnion
{
    XrSpaceUuidFilterInfoFB a;
    XrSpaceComponentFilterInfoFB b;
};

struct Decoded_XrSpaceFilterInfoBaseHeaderFB
{
    using struct_type = XrSpaceFilterInfoBaseHeaderFB;
    using union_size_type = XrSpaceFilterInfoBaseHeaderFBSizeUnion;

    XrSpaceFilterInfoBaseHeaderFB* decoded_value{ nullptr };

    static Decoded_XrSpaceFilterInfoBaseHeaderFB* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrSpaceFilterInfoBaseHeaderFB* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrSpaceFilterInfoBaseHeaderFB>(len, initialize);
                break;
         case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
             return_type = reinterpret_cast<Decoded_XrSpaceFilterInfoBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSpaceUuidFilterInfoFB>(len, initialize));
             break;
         case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
             return_type = reinterpret_cast<Decoded_XrSpaceFilterInfoBaseHeaderFB*>(DecodeAllocator::Allocate<Decoded_XrSpaceComponentFilterInfoFB>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrSpaceFilterInfoBaseHeaderFB* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            {
                Decoded_XrSpaceUuidFilterInfoFB* local_dest = reinterpret_cast<Decoded_XrSpaceUuidFilterInfoFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            {
                Decoded_XrSpaceComponentFilterInfoFB* local_dest = reinterpret_cast<Decoded_XrSpaceComponentFilterInfoFB*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrSpaceFilterInfoBaseHeaderFB *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrSpaceFilterInfoBaseHeaderFB *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrSpaceFilterInfoBaseHeaderFB>(len);
                break;
            case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSpaceUuidFilterInfoFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSpaceUuidFilterInfoFB{ XR_TYPE_SPACE_UUID_FILTER_INFO_FB };
                }
                output_data = reinterpret_cast<XrSpaceFilterInfoBaseHeaderFB*>(allocation);
                break;
            }
            case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            {
                auto *allocation = DecodeAllocator::Allocate<XrSpaceComponentFilterInfoFB>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrSpaceComponentFilterInfoFB{ XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB };
                }
                output_data = reinterpret_cast<XrSpaceFilterInfoBaseHeaderFB*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


union XrFutureCompletionBaseHeaderEXTSizeUnion
{
    XrFutureCompletionEXT a;
};

struct Decoded_XrFutureCompletionBaseHeaderEXT
{
    using struct_type = XrFutureCompletionBaseHeaderEXT;
    using union_size_type = XrFutureCompletionBaseHeaderEXTSizeUnion;

    XrFutureCompletionBaseHeaderEXT* decoded_value{ nullptr };

    static Decoded_XrFutureCompletionBaseHeaderEXT* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_XrFutureCompletionBaseHeaderEXT* return_type = nullptr;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                return_type = DecodeAllocator::Allocate<Decoded_XrFutureCompletionBaseHeaderEXT>(len, initialize);
                break;
         case XR_TYPE_FUTURE_COMPLETION_EXT:
             return_type = reinterpret_cast<Decoded_XrFutureCompletionBaseHeaderEXT*>(DecodeAllocator::Allocate<Decoded_XrFutureCompletionEXT>(len, initialize));
             break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_XrFutureCompletionBaseHeaderEXT* dest)
    {
        size_t   bytes_read          = 0;

        // Peek at the actual structure type
        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        XrStructureType xr_type = static_cast<XrStructureType>(peek_structure_type);

        switch (xr_type)
        {
            default:
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case XR_TYPE_FUTURE_COMPLETION_EXT:
            {
                Decoded_XrFutureCompletionEXT* local_dest = reinterpret_cast<Decoded_XrFutureCompletionEXT*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    XrFutureCompletionBaseHeaderEXT *AllocateOutputData(size_t len)
    {
        assert(decoded_value);
        XrStructureType struct_type = decoded_value->type;
        XrFutureCompletionBaseHeaderEXT *output_data = nullptr;

        switch (struct_type)
        {
            default:
                output_data = DecodeAllocator::Allocate<XrFutureCompletionBaseHeaderEXT>(len);
                break;
            case XR_TYPE_FUTURE_COMPLETION_EXT:
            {
                auto *allocation = DecodeAllocator::Allocate<XrFutureCompletionEXT>(len);
                for (size_t i=0; i < len; i++)
                {
                    allocation[i] = XrFutureCompletionEXT{ XR_TYPE_FUTURE_COMPLETION_EXT };
                }
                output_data = reinterpret_cast<XrFutureCompletionBaseHeaderEXT*>(allocation);
                break;
            }
        }
        return output_data;
    }

    OpenXrNextNode* next{ nullptr };
};


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_H
