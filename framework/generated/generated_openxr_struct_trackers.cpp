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

#include "generated/generated_openxr_struct_trackers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_trackers)

XrApiLayerProperties* TrackStruct(const XrApiLayerProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrApiLayerProperties* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrExtensionProperties* TrackStruct(const XrExtensionProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrExtensionProperties* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrInstanceCreateInfo* TrackStruct(const XrInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInstanceCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->enabledApiLayerNames)
    {
        unwrapped_struct->enabledApiLayerNames = MakeUnwrapOpenXrStructs(unwrapped_struct->enabledApiLayerNames, unwrapped_struct->enabledApiLayerCount, unwrap_memory);
    }
    if (unwrapped_struct->enabledExtensionNames)
    {
        unwrapped_struct->enabledExtensionNames = MakeUnwrapOpenXrStructs(unwrapped_struct->enabledExtensionNames, unwrapped_struct->enabledExtensionCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrInstanceProperties* TrackStruct(const XrInstanceProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInstanceProperties* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataBuffer* TrackStruct(const XrEventDataBuffer* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataBuffer* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemGetInfo* TrackStruct(const XrSystemGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemGetInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemProperties* TrackStruct(const XrSystemProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemProperties* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSessionCreateInfo* TrackStruct(const XrSessionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSessionCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceVelocity* TrackStruct(const XrSpaceVelocity* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceVelocity* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrReferenceSpaceCreateInfo* TrackStruct(const XrReferenceSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrReferenceSpaceCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionSpaceCreateInfo* TrackStruct(const XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionSpaceCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceLocation* TrackStruct(const XrSpaceLocation* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceLocation* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViewConfigurationProperties* TrackStruct(const XrViewConfigurationProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewConfigurationProperties* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViewConfigurationView* TrackStruct(const XrViewConfigurationView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewConfigurationView* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainCreateInfo* TrackStruct(const XrSwapchainCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageBaseHeader* TrackStruct(const XrSwapchainImageBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageBaseHeader* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageAcquireInfo* TrackStruct(const XrSwapchainImageAcquireInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageAcquireInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageWaitInfo* TrackStruct(const XrSwapchainImageWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageWaitInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageReleaseInfo* TrackStruct(const XrSwapchainImageReleaseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageReleaseInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSessionBeginInfo* TrackStruct(const XrSessionBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSessionBeginInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFrameWaitInfo* TrackStruct(const XrFrameWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFrameWaitInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFrameState* TrackStruct(const XrFrameState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFrameState* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFrameBeginInfo* TrackStruct(const XrFrameBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFrameBeginInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerBaseHeader* TrackStruct(const XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerBaseHeader* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFrameEndInfo* TrackStruct(const XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFrameEndInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->layers)
    {
        unwrapped_struct->layers = MakeUnwrapOpenXrStructs(unwrapped_struct->layers, unwrapped_struct->layerCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrViewLocateInfo* TrackStruct(const XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewLocateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViewState* TrackStruct(const XrViewState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewState* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrView* TrackStruct(const XrView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrView* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionSetCreateInfo* TrackStruct(const XrActionSetCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionSetCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionCreateInfo* TrackStruct(const XrActionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionCreateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->subactionPaths)
    {
        unwrapped_struct->subactionPaths = MakeUnwrapOpenXrStructs(unwrapped_struct->subactionPaths, unwrapped_struct->countSubactionPaths, unwrap_memory);
    }

    return unwrapped_struct;
}

XrInteractionProfileSuggestedBinding* TrackStruct(const XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInteractionProfileSuggestedBinding* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->suggestedBindings)
    {
        unwrapped_struct->suggestedBindings = MakeUnwrapOpenXrStructs(unwrapped_struct->suggestedBindings, unwrapped_struct->countSuggestedBindings, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSessionActionSetsAttachInfo* TrackStruct(const XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSessionActionSetsAttachInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->actionSets)
    {
        unwrapped_struct->actionSets = MakeUnwrapOpenXrStructs(unwrapped_struct->actionSets, unwrapped_struct->countActionSets, unwrap_memory);
    }

    return unwrapped_struct;
}

XrInteractionProfileState* TrackStruct(const XrInteractionProfileState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInteractionProfileState* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionStateGetInfo* TrackStruct(const XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionStateGetInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionStateBoolean* TrackStruct(const XrActionStateBoolean* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionStateBoolean* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionStateFloat* TrackStruct(const XrActionStateFloat* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionStateFloat* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionStateVector2f* TrackStruct(const XrActionStateVector2f* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionStateVector2f* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionStatePose* TrackStruct(const XrActionStatePose* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionStatePose* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActionsSyncInfo* TrackStruct(const XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActionsSyncInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->activeActionSets)
    {
        unwrapped_struct->activeActionSets = MakeUnwrapOpenXrStructs(unwrapped_struct->activeActionSets, unwrapped_struct->countActiveActionSets, unwrap_memory);
    }

    return unwrapped_struct;
}

XrBoundSourcesForActionEnumerateInfo* TrackStruct(const XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBoundSourcesForActionEnumerateInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrInputSourceLocalizedNameGetInfo* TrackStruct(const XrInputSourceLocalizedNameGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInputSourceLocalizedNameGetInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHapticActionInfo* TrackStruct(const XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHapticActionInfo* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHapticBaseHeader* TrackStruct(const XrHapticBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHapticBaseHeader* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerProjectionView* TrackStruct(const XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerProjectionView* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerProjection* TrackStruct(const XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerProjection* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->views)
    {
        unwrapped_struct->views = MakeUnwrapOpenXrStructs(unwrapped_struct->views, unwrapped_struct->viewCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrCompositionLayerQuad* TrackStruct(const XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerQuad* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataBaseHeader* TrackStruct(const XrEventDataBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataBaseHeader* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataEventsLost* TrackStruct(const XrEventDataEventsLost* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataEventsLost* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataInstanceLossPending* TrackStruct(const XrEventDataInstanceLossPending* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataInstanceLossPending* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSessionStateChanged* TrackStruct(const XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSessionStateChanged* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataReferenceSpaceChangePending* TrackStruct(const XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataReferenceSpaceChangePending* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataInteractionProfileChanged* TrackStruct(const XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataInteractionProfileChanged* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHapticVibration* TrackStruct(const XrHapticVibration* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHapticVibration* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerCubeKHR* TrackStruct(const XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerCubeKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrInstanceCreateInfoAndroidKHR* TrackStruct(const XrInstanceCreateInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInstanceCreateInfoAndroidKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerDepthInfoKHR* TrackStruct(const XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerDepthInfoKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVulkanSwapchainFormatListCreateInfoKHR* TrackStruct(const XrVulkanSwapchainFormatListCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVulkanSwapchainFormatListCreateInfoKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->viewFormats)
    {
        unwrapped_struct->viewFormats = MakeUnwrapOpenXrStructs(unwrapped_struct->viewFormats, unwrapped_struct->viewFormatCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrCompositionLayerCylinderKHR* TrackStruct(const XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerCylinderKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerEquirectKHR* TrackStruct(const XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerEquirectKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingOpenGLWin32KHR* TrackStruct(const XrGraphicsBindingOpenGLWin32KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingOpenGLWin32KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingOpenGLXlibKHR* TrackStruct(const XrGraphicsBindingOpenGLXlibKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingOpenGLXlibKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingOpenGLXcbKHR* TrackStruct(const XrGraphicsBindingOpenGLXcbKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingOpenGLXcbKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingOpenGLWaylandKHR* TrackStruct(const XrGraphicsBindingOpenGLWaylandKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingOpenGLWaylandKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageOpenGLKHR* TrackStruct(const XrSwapchainImageOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageOpenGLKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsRequirementsOpenGLKHR* TrackStruct(const XrGraphicsRequirementsOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsRequirementsOpenGLKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingOpenGLESAndroidKHR* TrackStruct(const XrGraphicsBindingOpenGLESAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingOpenGLESAndroidKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageOpenGLESKHR* TrackStruct(const XrSwapchainImageOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageOpenGLESKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsRequirementsOpenGLESKHR* TrackStruct(const XrGraphicsRequirementsOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsRequirementsOpenGLESKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingVulkanKHR* TrackStruct(const XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingVulkanKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageVulkanKHR* TrackStruct(const XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageVulkanKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsRequirementsVulkanKHR* TrackStruct(const XrGraphicsRequirementsVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsRequirementsVulkanKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingD3D11KHR* TrackStruct(const XrGraphicsBindingD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingD3D11KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageD3D11KHR* TrackStruct(const XrSwapchainImageD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageD3D11KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsRequirementsD3D11KHR* TrackStruct(const XrGraphicsRequirementsD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsRequirementsD3D11KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingD3D12KHR* TrackStruct(const XrGraphicsBindingD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingD3D12KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageD3D12KHR* TrackStruct(const XrSwapchainImageD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageD3D12KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsRequirementsD3D12KHR* TrackStruct(const XrGraphicsRequirementsD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsRequirementsD3D12KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVisibilityMaskKHR* TrackStruct(const XrVisibilityMaskKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVisibilityMaskKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataVisibilityMaskChangedKHR* TrackStruct(const XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVisibilityMaskChangedKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerColorScaleBiasKHR* TrackStruct(const XrCompositionLayerColorScaleBiasKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerColorScaleBiasKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLoaderInitInfoBaseHeaderKHR* TrackStruct(const XrLoaderInitInfoBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLoaderInitInfoBaseHeaderKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLoaderInitInfoAndroidKHR* TrackStruct(const XrLoaderInitInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLoaderInitInfoAndroidKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVulkanInstanceCreateInfoKHR* TrackStruct(const XrVulkanInstanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVulkanInstanceCreateInfoKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVulkanDeviceCreateInfoKHR* TrackStruct(const XrVulkanDeviceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVulkanDeviceCreateInfoKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVulkanGraphicsDeviceGetInfoKHR* TrackStruct(const XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVulkanGraphicsDeviceGetInfoKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerEquirect2KHR* TrackStruct(const XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerEquirect2KHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrBindingModificationBaseHeaderKHR* TrackStruct(const XrBindingModificationBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBindingModificationBaseHeaderKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrBindingModificationsKHR* TrackStruct(const XrBindingModificationsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBindingModificationsKHR* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->bindingModifications)
    {
        unwrapped_struct->bindingModifications = MakeUnwrapOpenXrStructs(unwrapped_struct->bindingModifications, unwrapped_struct->bindingModificationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataPerfSettingsEXT* TrackStruct(const XrEventDataPerfSettingsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataPerfSettingsEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrDebugUtilsObjectNameInfoEXT* TrackStruct(const XrDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDebugUtilsObjectNameInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrDebugUtilsLabelEXT* TrackStruct(const XrDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDebugUtilsLabelEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrDebugUtilsMessengerCallbackDataEXT* TrackStruct(const XrDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDebugUtilsMessengerCallbackDataEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->objects)
    {
        unwrapped_struct->objects = MakeUnwrapOpenXrStructs(unwrapped_struct->objects, unwrapped_struct->objectCount, unwrap_memory);
    }
    if (unwrapped_struct->sessionLabels)
    {
        unwrapped_struct->sessionLabels = MakeUnwrapOpenXrStructs(unwrapped_struct->sessionLabels, unwrapped_struct->sessionLabelCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrDebugUtilsMessengerCreateInfoEXT* TrackStruct(const XrDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDebugUtilsMessengerCreateInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemEyeGazeInteractionPropertiesEXT* TrackStruct(const XrSystemEyeGazeInteractionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemEyeGazeInteractionPropertiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEyeGazeSampleTimeEXT* TrackStruct(const XrEyeGazeSampleTimeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEyeGazeSampleTimeEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSessionCreateInfoOverlayEXTX* TrackStruct(const XrSessionCreateInfoOverlayEXTX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSessionCreateInfoOverlayEXTX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataMainSessionVisibilityChangedEXTX* TrackStruct(const XrEventDataMainSessionVisibilityChangedEXTX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataMainSessionVisibilityChangedEXTX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorCreateInfoMSFT* TrackStruct(const XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorSpaceCreateInfoMSFT* TrackStruct(const XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorSpaceCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerImageLayoutFB* TrackStruct(const XrCompositionLayerImageLayoutFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerImageLayoutFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerAlphaBlendFB* TrackStruct(const XrCompositionLayerAlphaBlendFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerAlphaBlendFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViewConfigurationDepthRangeEXT* TrackStruct(const XrViewConfigurationDepthRangeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewConfigurationDepthRangeEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGraphicsBindingEGLMNDX* TrackStruct(const XrGraphicsBindingEGLMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGraphicsBindingEGLMNDX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialGraphNodeSpaceCreateInfoMSFT* TrackStruct(const XrSpatialGraphNodeSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialGraphNodeSpaceCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialGraphStaticNodeBindingCreateInfoMSFT* TrackStruct(const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialGraphStaticNodeBindingCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* TrackStruct(const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialGraphNodeBindingPropertiesMSFT* TrackStruct(const XrSpatialGraphNodeBindingPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialGraphNodeBindingPropertiesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemHandTrackingPropertiesEXT* TrackStruct(const XrSystemHandTrackingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemHandTrackingPropertiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandTrackerCreateInfoEXT* TrackStruct(const XrHandTrackerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackerCreateInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandJointsLocateInfoEXT* TrackStruct(const XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandJointsLocateInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandJointLocationsEXT* TrackStruct(const XrHandJointLocationsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandJointLocationsEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->jointLocations)
    {
        unwrapped_struct->jointLocations = MakeUnwrapOpenXrStructs(unwrapped_struct->jointLocations, unwrapped_struct->jointCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrHandJointVelocitiesEXT* TrackStruct(const XrHandJointVelocitiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandJointVelocitiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->jointVelocities)
    {
        unwrapped_struct->jointVelocities = MakeUnwrapOpenXrStructs(unwrapped_struct->jointVelocities, unwrapped_struct->jointCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSystemHandTrackingMeshPropertiesMSFT* TrackStruct(const XrSystemHandTrackingMeshPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemHandTrackingMeshPropertiesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandMeshSpaceCreateInfoMSFT* TrackStruct(const XrHandMeshSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandMeshSpaceCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandMeshUpdateInfoMSFT* TrackStruct(const XrHandMeshUpdateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandMeshUpdateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandMeshMSFT* TrackStruct(const XrHandMeshMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandMeshMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandPoseTypeInfoMSFT* TrackStruct(const XrHandPoseTypeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandPoseTypeInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSecondaryViewConfigurationSessionBeginInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationSessionBeginInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationSessionBeginInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->enabledViewConfigurationTypes)
    {
        unwrapped_struct->enabledViewConfigurationTypes = MakeUnwrapOpenXrStructs(unwrapped_struct->enabledViewConfigurationTypes, unwrapped_struct->viewConfigurationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSecondaryViewConfigurationStateMSFT* TrackStruct(const XrSecondaryViewConfigurationStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationStateMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSecondaryViewConfigurationFrameStateMSFT* TrackStruct(const XrSecondaryViewConfigurationFrameStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationFrameStateMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->viewConfigurationStates)
    {
        unwrapped_struct->viewConfigurationStates = MakeUnwrapOpenXrStructs(unwrapped_struct->viewConfigurationStates, unwrapped_struct->viewConfigurationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSecondaryViewConfigurationLayerInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationLayerInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->layers)
    {
        unwrapped_struct->layers = MakeUnwrapOpenXrStructs(unwrapped_struct->layers, unwrapped_struct->layerCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSecondaryViewConfigurationFrameEndInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationFrameEndInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->viewConfigurationLayersInfo)
    {
        unwrapped_struct->viewConfigurationLayersInfo = MakeUnwrapOpenXrStructs(unwrapped_struct->viewConfigurationLayersInfo, unwrapped_struct->viewConfigurationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrControllerModelKeyStateMSFT* TrackStruct(const XrControllerModelKeyStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrControllerModelKeyStateMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrControllerModelNodePropertiesMSFT* TrackStruct(const XrControllerModelNodePropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrControllerModelNodePropertiesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrControllerModelPropertiesMSFT* TrackStruct(const XrControllerModelPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrControllerModelPropertiesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->nodeProperties)
    {
        unwrapped_struct->nodeProperties = MakeUnwrapOpenXrStructs(unwrapped_struct->nodeProperties, unwrapped_struct->nodeCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrControllerModelNodeStateMSFT* TrackStruct(const XrControllerModelNodeStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrControllerModelNodeStateMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrControllerModelStateMSFT* TrackStruct(const XrControllerModelStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrControllerModelStateMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->nodeStates)
    {
        unwrapped_struct->nodeStates = MakeUnwrapOpenXrStructs(unwrapped_struct->nodeStates, unwrapped_struct->nodeCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrViewConfigurationViewFovEPIC* TrackStruct(const XrViewConfigurationViewFovEPIC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewConfigurationViewFovEPIC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHolographicWindowAttachmentMSFT* TrackStruct(const XrHolographicWindowAttachmentMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHolographicWindowAttachmentMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerReprojectionInfoMSFT* TrackStruct(const XrCompositionLayerReprojectionInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerReprojectionInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerReprojectionPlaneOverrideMSFT* TrackStruct(const XrCompositionLayerReprojectionPlaneOverrideMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerReprojectionPlaneOverrideMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrAndroidSurfaceSwapchainCreateInfoFB* TrackStruct(const XrAndroidSurfaceSwapchainCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrAndroidSurfaceSwapchainCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainStateBaseHeaderFB* TrackStruct(const XrSwapchainStateBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainStateBaseHeaderFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerSecureContentFB* TrackStruct(const XrCompositionLayerSecureContentFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerSecureContentFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemBodyTrackingPropertiesFB* TrackStruct(const XrSystemBodyTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemBodyTrackingPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrBodyTrackerCreateInfoFB* TrackStruct(const XrBodyTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBodyTrackerCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrBodySkeletonFB* TrackStruct(const XrBodySkeletonFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBodySkeletonFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->joints)
    {
        unwrapped_struct->joints = MakeUnwrapOpenXrStructs(unwrapped_struct->joints, unwrapped_struct->jointCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrBodyJointsLocateInfoFB* TrackStruct(const XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBodyJointsLocateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrBodyJointLocationsFB* TrackStruct(const XrBodyJointLocationsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBodyJointLocationsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->jointLocations)
    {
        unwrapped_struct->jointLocations = MakeUnwrapOpenXrStructs(unwrapped_struct->jointLocations, unwrapped_struct->jointCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrInteractionProfileDpadBindingEXT* TrackStruct(const XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInteractionProfileDpadBindingEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrInteractionProfileAnalogThresholdVALVE* TrackStruct(const XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrInteractionProfileAnalogThresholdVALVE* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandJointsMotionRangeInfoEXT* TrackStruct(const XrHandJointsMotionRangeInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandJointsMotionRangeInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneObserverCreateInfoMSFT* TrackStruct(const XrSceneObserverCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneObserverCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneCreateInfoMSFT* TrackStruct(const XrSceneCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrNewSceneComputeInfoMSFT* TrackStruct(const XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrNewSceneComputeInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->requestedFeatures)
    {
        unwrapped_struct->requestedFeatures = MakeUnwrapOpenXrStructs(unwrapped_struct->requestedFeatures, unwrapped_struct->requestedFeatureCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrVisualMeshComputeLodInfoMSFT* TrackStruct(const XrVisualMeshComputeLodInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVisualMeshComputeLodInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneComponentsMSFT* TrackStruct(const XrSceneComponentsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneComponentsMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->components)
    {
        unwrapped_struct->components = MakeUnwrapOpenXrStructs(unwrapped_struct->components, unwrapped_struct->componentCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneComponentsGetInfoMSFT* TrackStruct(const XrSceneComponentsGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneComponentsGetInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneComponentLocationsMSFT* TrackStruct(const XrSceneComponentLocationsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneComponentLocationsMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->locations)
    {
        unwrapped_struct->locations = MakeUnwrapOpenXrStructs(unwrapped_struct->locations, unwrapped_struct->locationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneComponentsLocateInfoMSFT* TrackStruct(const XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneComponentsLocateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->componentIds)
    {
        unwrapped_struct->componentIds = MakeUnwrapOpenXrStructs(unwrapped_struct->componentIds, unwrapped_struct->componentIdCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneObjectsMSFT* TrackStruct(const XrSceneObjectsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneObjectsMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->sceneObjects)
    {
        unwrapped_struct->sceneObjects = MakeUnwrapOpenXrStructs(unwrapped_struct->sceneObjects, unwrapped_struct->sceneObjectCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneComponentParentFilterInfoMSFT* TrackStruct(const XrSceneComponentParentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneComponentParentFilterInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneObjectTypesFilterInfoMSFT* TrackStruct(const XrSceneObjectTypesFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneObjectTypesFilterInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->objectTypes)
    {
        unwrapped_struct->objectTypes = MakeUnwrapOpenXrStructs(unwrapped_struct->objectTypes, unwrapped_struct->objectTypeCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrScenePlanesMSFT* TrackStruct(const XrScenePlanesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrScenePlanesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->scenePlanes)
    {
        unwrapped_struct->scenePlanes = MakeUnwrapOpenXrStructs(unwrapped_struct->scenePlanes, unwrapped_struct->scenePlaneCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrScenePlaneAlignmentFilterInfoMSFT* TrackStruct(const XrScenePlaneAlignmentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrScenePlaneAlignmentFilterInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->alignments)
    {
        unwrapped_struct->alignments = MakeUnwrapOpenXrStructs(unwrapped_struct->alignments, unwrapped_struct->alignmentCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMeshesMSFT* TrackStruct(const XrSceneMeshesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->sceneMeshes)
    {
        unwrapped_struct->sceneMeshes = MakeUnwrapOpenXrStructs(unwrapped_struct->sceneMeshes, unwrapped_struct->sceneMeshCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMeshBuffersGetInfoMSFT* TrackStruct(const XrSceneMeshBuffersGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshBuffersGetInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneMeshBuffersMSFT* TrackStruct(const XrSceneMeshBuffersMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshBuffersMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneMeshVertexBufferMSFT* TrackStruct(const XrSceneMeshVertexBufferMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshVertexBufferMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMeshIndicesUint32MSFT* TrackStruct(const XrSceneMeshIndicesUint32MSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshIndicesUint32MSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMeshIndicesUint16MSFT* TrackStruct(const XrSceneMeshIndicesUint16MSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMeshIndicesUint16MSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSerializedSceneFragmentDataGetInfoMSFT* TrackStruct(const XrSerializedSceneFragmentDataGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSerializedSceneFragmentDataGetInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneDeserializeInfoMSFT* TrackStruct(const XrSceneDeserializeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneDeserializeInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->fragments)
    {
        unwrapped_struct->fragments = MakeUnwrapOpenXrStructs(unwrapped_struct->fragments, unwrapped_struct->fragmentCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataDisplayRefreshRateChangedFB* TrackStruct(const XrEventDataDisplayRefreshRateChangedFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataDisplayRefreshRateChangedFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViveTrackerPathsHTCX* TrackStruct(const XrViveTrackerPathsHTCX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViveTrackerPathsHTCX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataViveTrackerConnectedHTCX* TrackStruct(const XrEventDataViveTrackerConnectedHTCX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataViveTrackerConnectedHTCX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemFacialTrackingPropertiesHTC* TrackStruct(const XrSystemFacialTrackingPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemFacialTrackingPropertiesHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFacialExpressionsHTC* TrackStruct(const XrFacialExpressionsHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFacialExpressionsHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFacialTrackerCreateInfoHTC* TrackStruct(const XrFacialTrackerCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFacialTrackerCreateInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemColorSpacePropertiesFB* TrackStruct(const XrSystemColorSpacePropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemColorSpacePropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandTrackingMeshFB* TrackStruct(const XrHandTrackingMeshFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingMeshFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->jointBindPoses)
    {
        unwrapped_struct->jointBindPoses = MakeUnwrapOpenXrStructs(unwrapped_struct->jointBindPoses, unwrapped_struct->jointCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->jointRadii)
    {
        unwrapped_struct->jointRadii = MakeUnwrapOpenXrStructs(unwrapped_struct->jointRadii, unwrapped_struct->jointCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->jointParents)
    {
        unwrapped_struct->jointParents = MakeUnwrapOpenXrStructs(unwrapped_struct->jointParents, unwrapped_struct->jointCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->vertexPositions)
    {
        unwrapped_struct->vertexPositions = MakeUnwrapOpenXrStructs(unwrapped_struct->vertexPositions, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->vertexNormals)
    {
        unwrapped_struct->vertexNormals = MakeUnwrapOpenXrStructs(unwrapped_struct->vertexNormals, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->vertexUVs)
    {
        unwrapped_struct->vertexUVs = MakeUnwrapOpenXrStructs(unwrapped_struct->vertexUVs, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->vertexBlendIndices)
    {
        unwrapped_struct->vertexBlendIndices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertexBlendIndices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->vertexBlendWeights)
    {
        unwrapped_struct->vertexBlendWeights = MakeUnwrapOpenXrStructs(unwrapped_struct->vertexBlendWeights, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrHandTrackingScaleFB* TrackStruct(const XrHandTrackingScaleFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingScaleFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandTrackingAimStateFB* TrackStruct(const XrHandTrackingAimStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingAimStateFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHandTrackingCapsulesStateFB* TrackStruct(const XrHandTrackingCapsulesStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingCapsulesStateFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemSpatialEntityPropertiesFB* TrackStruct(const XrSystemSpatialEntityPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemSpatialEntityPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorCreateInfoFB* TrackStruct(const XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceComponentStatusSetInfoFB* TrackStruct(const XrSpaceComponentStatusSetInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceComponentStatusSetInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceComponentStatusFB* TrackStruct(const XrSpaceComponentStatusFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceComponentStatusFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSpatialAnchorCreateCompleteFB* TrackStruct(const XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpatialAnchorCreateCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSpaceSetStatusCompleteFB* TrackStruct(const XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceSetStatusCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveationProfileCreateInfoFB* TrackStruct(const XrFoveationProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationProfileCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainCreateInfoFoveationFB* TrackStruct(const XrSwapchainCreateInfoFoveationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainCreateInfoFoveationFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainStateFoveationFB* TrackStruct(const XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainStateFoveationFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveationLevelProfileCreateInfoFB* TrackStruct(const XrFoveationLevelProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationLevelProfileCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemKeyboardTrackingPropertiesFB* TrackStruct(const XrSystemKeyboardTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemKeyboardTrackingPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrKeyboardSpaceCreateInfoFB* TrackStruct(const XrKeyboardSpaceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrKeyboardSpaceCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrKeyboardTrackingQueryFB* TrackStruct(const XrKeyboardTrackingQueryFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrKeyboardTrackingQueryFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrTriangleMeshCreateInfoFB* TrackStruct(const XrTriangleMeshCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrTriangleMeshCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemPassthroughPropertiesFB* TrackStruct(const XrSystemPassthroughPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemPassthroughPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemPassthroughProperties2FB* TrackStruct(const XrSystemPassthroughProperties2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemPassthroughProperties2FB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughCreateInfoFB* TrackStruct(const XrPassthroughCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughLayerCreateInfoFB* TrackStruct(const XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughLayerCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerPassthroughFB* TrackStruct(const XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerPassthroughFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGeometryInstanceCreateInfoFB* TrackStruct(const XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGeometryInstanceCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGeometryInstanceTransformFB* TrackStruct(const XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGeometryInstanceTransformFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughStyleFB* TrackStruct(const XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughStyleFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorMapMonoToRgbaFB* TrackStruct(const XrPassthroughColorMapMonoToRgbaFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorMapMonoToRgbaFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorMapMonoToMonoFB* TrackStruct(const XrPassthroughColorMapMonoToMonoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorMapMonoToMonoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughBrightnessContrastSaturationFB* TrackStruct(const XrPassthroughBrightnessContrastSaturationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughBrightnessContrastSaturationFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataPassthroughStateChangedFB* TrackStruct(const XrEventDataPassthroughStateChangedFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataPassthroughStateChangedFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRenderModelPathInfoFB* TrackStruct(const XrRenderModelPathInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRenderModelPathInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRenderModelPropertiesFB* TrackStruct(const XrRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRenderModelPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRenderModelBufferFB* TrackStruct(const XrRenderModelBufferFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRenderModelBufferFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->buffer)
    {
        unwrapped_struct->buffer = MakeUnwrapOpenXrStructs(unwrapped_struct->buffer, unwrapped_struct->bufferCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrRenderModelLoadInfoFB* TrackStruct(const XrRenderModelLoadInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRenderModelLoadInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemRenderModelPropertiesFB* TrackStruct(const XrSystemRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemRenderModelPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRenderModelCapabilitiesRequestFB* TrackStruct(const XrRenderModelCapabilitiesRequestFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRenderModelCapabilitiesRequestFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrViewLocateFoveatedRenderingVARJO* TrackStruct(const XrViewLocateFoveatedRenderingVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrViewLocateFoveatedRenderingVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveatedViewConfigurationViewVARJO* TrackStruct(const XrFoveatedViewConfigurationViewVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveatedViewConfigurationViewVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemFoveatedRenderingPropertiesVARJO* TrackStruct(const XrSystemFoveatedRenderingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemFoveatedRenderingPropertiesVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerDepthTestVARJO* TrackStruct(const XrCompositionLayerDepthTestVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerDepthTestVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemMarkerTrackingPropertiesVARJO* TrackStruct(const XrSystemMarkerTrackingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemMarkerTrackingPropertiesVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataMarkerTrackingUpdateVARJO* TrackStruct(const XrEventDataMarkerTrackingUpdateVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataMarkerTrackingUpdateVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerSpaceCreateInfoVARJO* TrackStruct(const XrMarkerSpaceCreateInfoVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerSpaceCreateInfoVARJO* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFrameEndInfoML* TrackStruct(const XrFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFrameEndInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrGlobalDimmerFrameEndInfoML* TrackStruct(const XrGlobalDimmerFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrGlobalDimmerFrameEndInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCoordinateSpaceCreateInfoML* TrackStruct(const XrCoordinateSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCoordinateSpaceCreateInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemMarkerUnderstandingPropertiesML* TrackStruct(const XrSystemMarkerUnderstandingPropertiesML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemMarkerUnderstandingPropertiesML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorCreateInfoML* TrackStruct(const XrMarkerDetectorCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorCreateInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorArucoInfoML* TrackStruct(const XrMarkerDetectorArucoInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorArucoInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorSizeInfoML* TrackStruct(const XrMarkerDetectorSizeInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorSizeInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorAprilTagInfoML* TrackStruct(const XrMarkerDetectorAprilTagInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorAprilTagInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorCustomProfileInfoML* TrackStruct(const XrMarkerDetectorCustomProfileInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorCustomProfileInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorSnapshotInfoML* TrackStruct(const XrMarkerDetectorSnapshotInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorSnapshotInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerDetectorStateML* TrackStruct(const XrMarkerDetectorStateML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerDetectorStateML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMarkerSpaceCreateInfoML* TrackStruct(const XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMarkerSpaceCreateInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLocalizationMapML* TrackStruct(const XrLocalizationMapML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLocalizationMapML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataLocalizationChangedML* TrackStruct(const XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataLocalizationChangedML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLocalizationMapQueryInfoBaseHeaderML* TrackStruct(const XrLocalizationMapQueryInfoBaseHeaderML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLocalizationMapQueryInfoBaseHeaderML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrMapLocalizationRequestInfoML* TrackStruct(const XrMapLocalizationRequestInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrMapLocalizationRequestInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLocalizationMapImportInfoML* TrackStruct(const XrLocalizationMapImportInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLocalizationMapImportInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->data)
    {
        unwrapped_struct->data = MakeUnwrapOpenXrStructs(unwrapped_struct->data, unwrapped_struct->size, unwrap_memory);
    }

    return unwrapped_struct;
}

XrLocalizationEnableEventsInfoML* TrackStruct(const XrLocalizationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLocalizationEnableEventsInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorPersistenceInfoMSFT* TrackStruct(const XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorPersistenceInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* TrackStruct(const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneMarkersMSFT* TrackStruct(const XrSceneMarkersMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMarkersMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->sceneMarkers)
    {
        unwrapped_struct->sceneMarkers = MakeUnwrapOpenXrStructs(unwrapped_struct->sceneMarkers, unwrapped_struct->sceneMarkerCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMarkerTypeFilterMSFT* TrackStruct(const XrSceneMarkerTypeFilterMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMarkerTypeFilterMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->markerTypes)
    {
        unwrapped_struct->markerTypes = MakeUnwrapOpenXrStructs(unwrapped_struct->markerTypes, unwrapped_struct->markerTypeCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSceneMarkerQRCodesMSFT* TrackStruct(const XrSceneMarkerQRCodesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneMarkerQRCodesMSFT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->qrCodes)
    {
        unwrapped_struct->qrCodes = MakeUnwrapOpenXrStructs(unwrapped_struct->qrCodes, unwrapped_struct->qrCodeCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSpaceQueryInfoBaseHeaderFB* TrackStruct(const XrSpaceQueryInfoBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceQueryInfoBaseHeaderFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceFilterInfoBaseHeaderFB* TrackStruct(const XrSpaceFilterInfoBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceFilterInfoBaseHeaderFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceQueryInfoFB* TrackStruct(const XrSpaceQueryInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceQueryInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceStorageLocationFilterInfoFB* TrackStruct(const XrSpaceStorageLocationFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceStorageLocationFilterInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceUuidFilterInfoFB* TrackStruct(const XrSpaceUuidFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceUuidFilterInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->uuids)
    {
        unwrapped_struct->uuids = MakeUnwrapOpenXrStructs(unwrapped_struct->uuids, unwrapped_struct->uuidCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSpaceComponentFilterInfoFB* TrackStruct(const XrSpaceComponentFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceComponentFilterInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceQueryResultsFB* TrackStruct(const XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceQueryResultsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->results)
    {
        unwrapped_struct->results = MakeUnwrapOpenXrStructs(unwrapped_struct->results, unwrapped_struct->resultCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataSpaceQueryResultsAvailableFB* TrackStruct(const XrEventDataSpaceQueryResultsAvailableFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceQueryResultsAvailableFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSpaceQueryCompleteFB* TrackStruct(const XrEventDataSpaceQueryCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceQueryCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceSaveInfoFB* TrackStruct(const XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceSaveInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceEraseInfoFB* TrackStruct(const XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceEraseInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSpaceSaveCompleteFB* TrackStruct(const XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceSaveCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSpaceEraseCompleteFB* TrackStruct(const XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceEraseCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainImageFoveationVulkanFB* TrackStruct(const XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainImageFoveationVulkanFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainStateAndroidSurfaceDimensionsFB* TrackStruct(const XrSwapchainStateAndroidSurfaceDimensionsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainStateAndroidSurfaceDimensionsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainStateSamplerOpenGLESFB* TrackStruct(const XrSwapchainStateSamplerOpenGLESFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainStateSamplerOpenGLESFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSwapchainStateSamplerVulkanFB* TrackStruct(const XrSwapchainStateSamplerVulkanFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSwapchainStateSamplerVulkanFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceShareInfoFB* TrackStruct(const XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceShareInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->spaces)
    {
        unwrapped_struct->spaces = MakeUnwrapOpenXrStructs(unwrapped_struct->spaces, unwrapped_struct->spaceCount, unwrap_memory);
    }
    if (unwrapped_struct->users)
    {
        unwrapped_struct->users = MakeUnwrapOpenXrStructs(unwrapped_struct->users, unwrapped_struct->userCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataSpaceShareCompleteFB* TrackStruct(const XrEventDataSpaceShareCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceShareCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerSpaceWarpInfoFB* TrackStruct(const XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerSpaceWarpInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemSpaceWarpPropertiesFB* TrackStruct(const XrSystemSpaceWarpPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemSpaceWarpPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHapticAmplitudeEnvelopeVibrationFB* TrackStruct(const XrHapticAmplitudeEnvelopeVibrationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHapticAmplitudeEnvelopeVibrationFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->amplitudes)
    {
        unwrapped_struct->amplitudes = MakeUnwrapOpenXrStructs(unwrapped_struct->amplitudes, unwrapped_struct->amplitudeCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSemanticLabelsFB* TrackStruct(const XrSemanticLabelsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSemanticLabelsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->buffer)
    {
        unwrapped_struct->buffer = MakeUnwrapOpenXrStructs(unwrapped_struct->buffer, unwrapped_struct->bufferCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrRoomLayoutFB* TrackStruct(const XrRoomLayoutFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRoomLayoutFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->wallUuids)
    {
        unwrapped_struct->wallUuids = MakeUnwrapOpenXrStructs(unwrapped_struct->wallUuids, unwrapped_struct->wallUuidCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrBoundary2DFB* TrackStruct(const XrBoundary2DFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrBoundary2DFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSemanticLabelsSupportInfoFB* TrackStruct(const XrSemanticLabelsSupportInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSemanticLabelsSupportInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrDigitalLensControlALMALENCE* TrackStruct(const XrDigitalLensControlALMALENCE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDigitalLensControlALMALENCE* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataSceneCaptureCompleteFB* TrackStruct(const XrEventDataSceneCaptureCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSceneCaptureCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSceneCaptureRequestInfoFB* TrackStruct(const XrSceneCaptureRequestInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSceneCaptureRequestInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->request)
    {
        unwrapped_struct->request = MakeUnwrapOpenXrStructs(unwrapped_struct->request, unwrapped_struct->requestByteCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSpaceContainerFB* TrackStruct(const XrSpaceContainerFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceContainerFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->uuids)
    {
        unwrapped_struct->uuids = MakeUnwrapOpenXrStructs(unwrapped_struct->uuids, unwrapped_struct->uuidCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrFoveationEyeTrackedProfileCreateInfoMETA* TrackStruct(const XrFoveationEyeTrackedProfileCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationEyeTrackedProfileCreateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveationEyeTrackedStateMETA* TrackStruct(const XrFoveationEyeTrackedStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationEyeTrackedStateMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemFoveationEyeTrackedPropertiesMETA* TrackStruct(const XrSystemFoveationEyeTrackedPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemFoveationEyeTrackedPropertiesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemFaceTrackingPropertiesFB* TrackStruct(const XrSystemFaceTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemFaceTrackingPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFaceTrackerCreateInfoFB* TrackStruct(const XrFaceTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceTrackerCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFaceExpressionInfoFB* TrackStruct(const XrFaceExpressionInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceExpressionInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFaceExpressionWeightsFB* TrackStruct(const XrFaceExpressionWeightsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceExpressionWeightsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->weights)
    {
        unwrapped_struct->weights = MakeUnwrapOpenXrStructs(unwrapped_struct->weights, unwrapped_struct->weightCount, unwrap_memory);
    }
    if (unwrapped_struct->confidences)
    {
        unwrapped_struct->confidences = MakeUnwrapOpenXrStructs(unwrapped_struct->confidences, unwrapped_struct->confidenceCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEyeTrackerCreateInfoFB* TrackStruct(const XrEyeTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEyeTrackerCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEyeGazesInfoFB* TrackStruct(const XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEyeGazesInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemEyeTrackingPropertiesFB* TrackStruct(const XrSystemEyeTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemEyeTrackingPropertiesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEyeGazesFB* TrackStruct(const XrEyeGazesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEyeGazesFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughKeyboardHandsIntensityFB* TrackStruct(const XrPassthroughKeyboardHandsIntensityFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughKeyboardHandsIntensityFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerSettingsFB* TrackStruct(const XrCompositionLayerSettingsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerSettingsFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrHapticPcmVibrationFB* TrackStruct(const XrHapticPcmVibrationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHapticPcmVibrationFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->buffer)
    {
        unwrapped_struct->buffer = MakeUnwrapOpenXrStructs(unwrapped_struct->buffer, unwrapped_struct->bufferSize, unwrap_memory);
    }

    return unwrapped_struct;
}

XrDevicePcmSampleRateStateFB* TrackStruct(const XrDevicePcmSampleRateStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrDevicePcmSampleRateStateFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrCompositionLayerDepthTestFB* TrackStruct(const XrCompositionLayerDepthTestFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerDepthTestFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrLocalDimmingFrameEndInfoMETA* TrackStruct(const XrLocalDimmingFrameEndInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrLocalDimmingFrameEndInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughPreferencesMETA* TrackStruct(const XrPassthroughPreferencesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughPreferencesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemVirtualKeyboardPropertiesMETA* TrackStruct(const XrSystemVirtualKeyboardPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemVirtualKeyboardPropertiesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardCreateInfoMETA* TrackStruct(const XrVirtualKeyboardCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardCreateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardSpaceCreateInfoMETA* TrackStruct(const XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardSpaceCreateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardLocationInfoMETA* TrackStruct(const XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardLocationInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardModelVisibilitySetInfoMETA* TrackStruct(const XrVirtualKeyboardModelVisibilitySetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardModelVisibilitySetInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardAnimationStateMETA* TrackStruct(const XrVirtualKeyboardAnimationStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardAnimationStateMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardModelAnimationStatesMETA* TrackStruct(const XrVirtualKeyboardModelAnimationStatesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardModelAnimationStatesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->states)
    {
        unwrapped_struct->states = MakeUnwrapOpenXrStructs(unwrapped_struct->states, unwrapped_struct->stateCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrVirtualKeyboardTextureDataMETA* TrackStruct(const XrVirtualKeyboardTextureDataMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardTextureDataMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->buffer)
    {
        unwrapped_struct->buffer = MakeUnwrapOpenXrStructs(unwrapped_struct->buffer, unwrapped_struct->bufferCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrVirtualKeyboardInputInfoMETA* TrackStruct(const XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardInputInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVirtualKeyboardTextContextChangeInfoMETA* TrackStruct(const XrVirtualKeyboardTextContextChangeInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVirtualKeyboardTextContextChangeInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataVirtualKeyboardCommitTextMETA* TrackStruct(const XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVirtualKeyboardCommitTextMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataVirtualKeyboardBackspaceMETA* TrackStruct(const XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVirtualKeyboardBackspaceMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataVirtualKeyboardEnterMETA* TrackStruct(const XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVirtualKeyboardEnterMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataVirtualKeyboardShownMETA* TrackStruct(const XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVirtualKeyboardShownMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataVirtualKeyboardHiddenMETA* TrackStruct(const XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataVirtualKeyboardHiddenMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrExternalCameraOCULUS* TrackStruct(const XrExternalCameraOCULUS* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrExternalCameraOCULUS* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrVulkanSwapchainCreateInfoMETA* TrackStruct(const XrVulkanSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrVulkanSwapchainCreateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPerformanceMetricsStateMETA* TrackStruct(const XrPerformanceMetricsStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPerformanceMetricsStateMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPerformanceMetricsCounterMETA* TrackStruct(const XrPerformanceMetricsCounterMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPerformanceMetricsCounterMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceListSaveInfoFB* TrackStruct(const XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceListSaveInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->spaces)
    {
        unwrapped_struct->spaces = MakeUnwrapOpenXrStructs(unwrapped_struct->spaces, unwrapped_struct->spaceCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataSpaceListSaveCompleteFB* TrackStruct(const XrEventDataSpaceListSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataSpaceListSaveCompleteFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceUserCreateInfoFB* TrackStruct(const XrSpaceUserCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceUserCreateInfoFB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemHeadsetIdPropertiesMETA* TrackStruct(const XrSystemHeadsetIdPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemHeadsetIdPropertiesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRecommendedLayerResolutionMETA* TrackStruct(const XrRecommendedLayerResolutionMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRecommendedLayerResolutionMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrRecommendedLayerResolutionGetInfoMETA* TrackStruct(const XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrRecommendedLayerResolutionGetInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorLutCreateInfoMETA* TrackStruct(const XrPassthroughColorLutCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorLutCreateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorLutUpdateInfoMETA* TrackStruct(const XrPassthroughColorLutUpdateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorLutUpdateInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorMapLutMETA* TrackStruct(const XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorMapLutMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorMapInterpolatedLutMETA* TrackStruct(const XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorMapInterpolatedLutMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemPassthroughColorLutPropertiesMETA* TrackStruct(const XrSystemPassthroughColorLutPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemPassthroughColorLutPropertiesMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceTriangleMeshGetInfoMETA* TrackStruct(const XrSpaceTriangleMeshGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceTriangleMeshGetInfoMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpaceTriangleMeshMETA* TrackStruct(const XrSpaceTriangleMeshMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpaceTriangleMeshMETA* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }
    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSystemFaceTrackingProperties2FB* TrackStruct(const XrSystemFaceTrackingProperties2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemFaceTrackingProperties2FB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFaceTrackerCreateInfo2FB* TrackStruct(const XrFaceTrackerCreateInfo2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceTrackerCreateInfo2FB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->requestedDataSources)
    {
        unwrapped_struct->requestedDataSources = MakeUnwrapOpenXrStructs(unwrapped_struct->requestedDataSources, unwrapped_struct->requestedDataSourceCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrFaceExpressionInfo2FB* TrackStruct(const XrFaceExpressionInfo2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceExpressionInfo2FB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFaceExpressionWeights2FB* TrackStruct(const XrFaceExpressionWeights2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFaceExpressionWeights2FB* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->weights)
    {
        unwrapped_struct->weights = MakeUnwrapOpenXrStructs(unwrapped_struct->weights, unwrapped_struct->weightCount, unwrap_memory);
    }
    if (unwrapped_struct->confidences)
    {
        unwrapped_struct->confidences = MakeUnwrapOpenXrStructs(unwrapped_struct->confidences, unwrapped_struct->confidenceCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrPassthroughCreateInfoHTC* TrackStruct(const XrPassthroughCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughCreateInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughColorHTC* TrackStruct(const XrPassthroughColorHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughColorHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPassthroughMeshTransformInfoHTC* TrackStruct(const XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPassthroughMeshTransformInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCount, unwrap_memory);
    }
    if (unwrapped_struct->indices)
    {
        unwrapped_struct->indices = MakeUnwrapOpenXrStructs(unwrapped_struct->indices, unwrapped_struct->indexCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrCompositionLayerPassthroughHTC* TrackStruct(const XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrCompositionLayerPassthroughHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveationApplyInfoHTC* TrackStruct(const XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationApplyInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->subImages)
    {
        unwrapped_struct->subImages = MakeUnwrapOpenXrStructs(unwrapped_struct->subImages, unwrapped_struct->subImageCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrFoveationDynamicModeInfoHTC* TrackStruct(const XrFoveationDynamicModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationDynamicModeInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrFoveationCustomModeInfoHTC* TrackStruct(const XrFoveationCustomModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrFoveationCustomModeInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->configs)
    {
        unwrapped_struct->configs = MakeUnwrapOpenXrStructs(unwrapped_struct->configs, unwrapped_struct->configCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSystemAnchorPropertiesHTC* TrackStruct(const XrSystemAnchorPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemAnchorPropertiesHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSpatialAnchorCreateInfoHTC* TrackStruct(const XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSpatialAnchorCreateInfoHTC* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrActiveActionSetPrioritiesEXT* TrackStruct(const XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrActiveActionSetPrioritiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->actionSetPriorities)
    {
        unwrapped_struct->actionSetPriorities = MakeUnwrapOpenXrStructs(unwrapped_struct->actionSetPriorities, unwrapped_struct->actionSetPriorityCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrSystemForceFeedbackCurlPropertiesMNDX* TrackStruct(const XrSystemForceFeedbackCurlPropertiesMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemForceFeedbackCurlPropertiesMNDX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrForceFeedbackCurlApplyLocationsMNDX* TrackStruct(const XrForceFeedbackCurlApplyLocationsMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrForceFeedbackCurlApplyLocationsMNDX* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->locations)
    {
        unwrapped_struct->locations = MakeUnwrapOpenXrStructs(unwrapped_struct->locations, unwrapped_struct->locationCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrHandTrackingDataSourceInfoEXT* TrackStruct(const XrHandTrackingDataSourceInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingDataSourceInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->requestedDataSources)
    {
        unwrapped_struct->requestedDataSources = MakeUnwrapOpenXrStructs(unwrapped_struct->requestedDataSources, unwrapped_struct->requestedDataSourceCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrHandTrackingDataSourceStateEXT* TrackStruct(const XrHandTrackingDataSourceStateEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrHandTrackingDataSourceStateEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemPlaneDetectionPropertiesEXT* TrackStruct(const XrSystemPlaneDetectionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemPlaneDetectionPropertiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPlaneDetectorCreateInfoEXT* TrackStruct(const XrPlaneDetectorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorCreateInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPlaneDetectorBeginInfoEXT* TrackStruct(const XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorBeginInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->orientations)
    {
        unwrapped_struct->orientations = MakeUnwrapOpenXrStructs(unwrapped_struct->orientations, unwrapped_struct->orientationCount, unwrap_memory);
    }
    if (unwrapped_struct->semanticTypes)
    {
        unwrapped_struct->semanticTypes = MakeUnwrapOpenXrStructs(unwrapped_struct->semanticTypes, unwrapped_struct->semanticTypeCount, unwrap_memory);
    }

    return unwrapped_struct;
}

XrPlaneDetectorGetInfoEXT* TrackStruct(const XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorGetInfoEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPlaneDetectorLocationEXT* TrackStruct(const XrPlaneDetectorLocationEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorLocationEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrPlaneDetectorLocationsEXT* TrackStruct(const XrPlaneDetectorLocationsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorLocationsEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->planeLocations)
    {
        unwrapped_struct->planeLocations = MakeUnwrapOpenXrStructs(unwrapped_struct->planeLocations, unwrapped_struct->planeLocationCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrPlaneDetectorPolygonBufferEXT* TrackStruct(const XrPlaneDetectorPolygonBufferEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrPlaneDetectorPolygonBufferEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);

    if (unwrapped_struct->vertices)
    {
        unwrapped_struct->vertices = MakeUnwrapOpenXrStructs(unwrapped_struct->vertices, unwrapped_struct->vertexCapacityInput, unwrap_memory);
    }

    return unwrapped_struct;
}

XrEventDataUserPresenceChangedEXT* TrackStruct(const XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataUserPresenceChangedEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrSystemUserPresencePropertiesEXT* TrackStruct(const XrSystemUserPresencePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrSystemUserPresencePropertiesEXT* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataHeadsetFitChangedML* TrackStruct(const XrEventDataHeadsetFitChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataHeadsetFitChangedML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrEventDataEyeCalibrationChangedML* TrackStruct(const XrEventDataEyeCalibrationChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrEventDataEyeCalibrationChangedML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}

XrUserCalibrationEnableEventsInfoML* TrackStruct(const XrUserCalibrationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrUserCalibrationEnableEventsInfoML* unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);


    return unwrapped_struct;
}


void* TrackStruct(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value == nullptr)
    {
        return nullptr;
    }

    XrStructureType valueType = reinterpret_cast<const XrBaseInStructure*>(value)->type;
    switch (valueType)
    {
        case XR_TYPE_API_LAYER_PROPERTIES:
            return TrackStruct(reinterpret_cast<const XrApiLayerProperties*>(value), unwrap_memory);
        case XR_TYPE_EXTENSION_PROPERTIES:
            return TrackStruct(reinterpret_cast<const XrExtensionProperties*>(value), unwrap_memory);
        case XR_TYPE_INSTANCE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrInstanceCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_INSTANCE_PROPERTIES:
            return TrackStruct(reinterpret_cast<const XrInstanceProperties*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_BUFFER:
            return TrackStruct(reinterpret_cast<const XrEventDataBuffer*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_GET_INFO:
            return TrackStruct(reinterpret_cast<const XrSystemGetInfo*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_PROPERTIES:
            return TrackStruct(reinterpret_cast<const XrSystemProperties*>(value), unwrap_memory);
        case XR_TYPE_SESSION_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrSessionCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_SPACE_VELOCITY:
            return TrackStruct(reinterpret_cast<const XrSpaceVelocity*>(value), unwrap_memory);
        case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrReferenceSpaceCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrActionSpaceCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_SPACE_LOCATION:
            return TrackStruct(reinterpret_cast<const XrSpaceLocation*>(value), unwrap_memory);
        case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
            return TrackStruct(reinterpret_cast<const XrViewConfigurationProperties*>(value), unwrap_memory);
        case XR_TYPE_VIEW_CONFIGURATION_VIEW:
            return TrackStruct(reinterpret_cast<const XrViewConfigurationView*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrSwapchainCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageAcquireInfo*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageWaitInfo*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageReleaseInfo*>(value), unwrap_memory);
        case XR_TYPE_SESSION_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const XrSessionBeginInfo*>(value), unwrap_memory);
        case XR_TYPE_FRAME_WAIT_INFO:
            return TrackStruct(reinterpret_cast<const XrFrameWaitInfo*>(value), unwrap_memory);
        case XR_TYPE_FRAME_STATE:
            return TrackStruct(reinterpret_cast<const XrFrameState*>(value), unwrap_memory);
        case XR_TYPE_FRAME_BEGIN_INFO:
            return TrackStruct(reinterpret_cast<const XrFrameBeginInfo*>(value), unwrap_memory);
        case XR_TYPE_FRAME_END_INFO:
            return TrackStruct(reinterpret_cast<const XrFrameEndInfo*>(value), unwrap_memory);
        case XR_TYPE_VIEW_LOCATE_INFO:
            return TrackStruct(reinterpret_cast<const XrViewLocateInfo*>(value), unwrap_memory);
        case XR_TYPE_VIEW_STATE:
            return TrackStruct(reinterpret_cast<const XrViewState*>(value), unwrap_memory);
        case XR_TYPE_VIEW:
            return TrackStruct(reinterpret_cast<const XrView*>(value), unwrap_memory);
        case XR_TYPE_ACTION_SET_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrActionSetCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_ACTION_CREATE_INFO:
            return TrackStruct(reinterpret_cast<const XrActionCreateInfo*>(value), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            return TrackStruct(reinterpret_cast<const XrInteractionProfileSuggestedBinding*>(value), unwrap_memory);
        case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            return TrackStruct(reinterpret_cast<const XrSessionActionSetsAttachInfo*>(value), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_STATE:
            return TrackStruct(reinterpret_cast<const XrInteractionProfileState*>(value), unwrap_memory);
        case XR_TYPE_ACTION_STATE_GET_INFO:
            return TrackStruct(reinterpret_cast<const XrActionStateGetInfo*>(value), unwrap_memory);
        case XR_TYPE_ACTION_STATE_BOOLEAN:
            return TrackStruct(reinterpret_cast<const XrActionStateBoolean*>(value), unwrap_memory);
        case XR_TYPE_ACTION_STATE_FLOAT:
            return TrackStruct(reinterpret_cast<const XrActionStateFloat*>(value), unwrap_memory);
        case XR_TYPE_ACTION_STATE_VECTOR2F:
            return TrackStruct(reinterpret_cast<const XrActionStateVector2f*>(value), unwrap_memory);
        case XR_TYPE_ACTION_STATE_POSE:
            return TrackStruct(reinterpret_cast<const XrActionStatePose*>(value), unwrap_memory);
        case XR_TYPE_ACTIONS_SYNC_INFO:
            return TrackStruct(reinterpret_cast<const XrActionsSyncInfo*>(value), unwrap_memory);
        case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            return TrackStruct(reinterpret_cast<const XrBoundSourcesForActionEnumerateInfo*>(value), unwrap_memory);
        case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            return TrackStruct(reinterpret_cast<const XrInputSourceLocalizedNameGetInfo*>(value), unwrap_memory);
        case XR_TYPE_HAPTIC_ACTION_INFO:
            return TrackStruct(reinterpret_cast<const XrHapticActionInfo*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerProjectionView*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerProjection*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerQuad*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            return TrackStruct(reinterpret_cast<const XrEventDataEventsLost*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            return TrackStruct(reinterpret_cast<const XrEventDataInstanceLossPending*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            return TrackStruct(reinterpret_cast<const XrEventDataSessionStateChanged*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            return TrackStruct(reinterpret_cast<const XrEventDataReferenceSpaceChangePending*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            return TrackStruct(reinterpret_cast<const XrEventDataInteractionProfileChanged*>(value), unwrap_memory);
        case XR_TYPE_HAPTIC_VIBRATION:
            return TrackStruct(reinterpret_cast<const XrHapticVibration*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerCubeKHR*>(value), unwrap_memory);
        case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            return TrackStruct(reinterpret_cast<const XrInstanceCreateInfoAndroidKHR*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(value), unwrap_memory);
        case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const XrVulkanSwapchainFormatListCreateInfoKHR*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerCylinderKHR*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerEquirectKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageOpenGLKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsRequirementsOpenGLKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageOpenGLESKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsRequirementsOpenGLESKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageVulkanKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsRequirementsVulkanKHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingD3D11KHR*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageD3D11KHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsRequirementsD3D11KHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingD3D12KHR*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageD3D12KHR*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
            return TrackStruct(reinterpret_cast<const XrGraphicsRequirementsD3D12KHR*>(value), unwrap_memory);
        case XR_TYPE_VISIBILITY_MASK_KHR:
            return TrackStruct(reinterpret_cast<const XrVisibilityMaskKHR*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            return TrackStruct(reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerColorScaleBiasKHR*>(value), unwrap_memory);
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            return TrackStruct(reinterpret_cast<const XrLoaderInitInfoAndroidKHR*>(value), unwrap_memory);
        case XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const XrVulkanInstanceCreateInfoKHR*>(value), unwrap_memory);
        case XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR:
            return TrackStruct(reinterpret_cast<const XrVulkanDeviceCreateInfoKHR*>(value), unwrap_memory);
        case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            return TrackStruct(reinterpret_cast<const XrVulkanGraphicsDeviceGetInfoKHR*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerEquirect2KHR*>(value), unwrap_memory);
        case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            return TrackStruct(reinterpret_cast<const XrBindingModificationsKHR*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            return TrackStruct(reinterpret_cast<const XrEventDataPerfSettingsEXT*>(value), unwrap_memory);
        case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrDebugUtilsObjectNameInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
            return TrackStruct(reinterpret_cast<const XrDebugUtilsLabelEXT*>(value), unwrap_memory);
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            return TrackStruct(reinterpret_cast<const XrDebugUtilsMessengerCallbackDataEXT*>(value), unwrap_memory);
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const XrSystemEyeGazeInteractionPropertiesEXT*>(value), unwrap_memory);
        case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            return TrackStruct(reinterpret_cast<const XrEyeGazeSampleTimeEXT*>(value), unwrap_memory);
        case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            return TrackStruct(reinterpret_cast<const XrSessionCreateInfoOverlayEXTX*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            return TrackStruct(reinterpret_cast<const XrEventDataMainSessionVisibilityChangedEXTX*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorSpaceCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerImageLayoutFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerAlphaBlendFB*>(value), unwrap_memory);
        case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            return TrackStruct(reinterpret_cast<const XrViewConfigurationDepthRangeEXT*>(value), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            return TrackStruct(reinterpret_cast<const XrGraphicsBindingEGLMNDX*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialGraphNodeSpaceCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesMSFT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const XrSystemHandTrackingPropertiesEXT*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrHandTrackerCreateInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrHandJointsLocateInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
            return TrackStruct(reinterpret_cast<const XrHandJointLocationsEXT*>(value), unwrap_memory);
        case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            return TrackStruct(reinterpret_cast<const XrHandJointVelocitiesEXT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            return TrackStruct(reinterpret_cast<const XrSystemHandTrackingMeshPropertiesMSFT*>(value), unwrap_memory);
        case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrHandMeshSpaceCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrHandMeshUpdateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_HAND_MESH_MSFT:
            return TrackStruct(reinterpret_cast<const XrHandMeshMSFT*>(value), unwrap_memory);
        case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrHandPoseTypeInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationStateMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationFrameStateMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationLayerInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            return TrackStruct(reinterpret_cast<const XrControllerModelKeyStateMSFT*>(value), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
            return TrackStruct(reinterpret_cast<const XrControllerModelNodePropertiesMSFT*>(value), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
            return TrackStruct(reinterpret_cast<const XrControllerModelPropertiesMSFT*>(value), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
            return TrackStruct(reinterpret_cast<const XrControllerModelNodeStateMSFT*>(value), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
            return TrackStruct(reinterpret_cast<const XrControllerModelStateMSFT*>(value), unwrap_memory);
        case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            return TrackStruct(reinterpret_cast<const XrViewConfigurationViewFovEPIC*>(value), unwrap_memory);
        case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            return TrackStruct(reinterpret_cast<const XrHolographicWindowAttachmentMSFT*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerReprojectionInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerReprojectionPlaneOverrideMSFT*>(value), unwrap_memory);
        case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrAndroidSurfaceSwapchainCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerSecureContentFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemBodyTrackingPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrBodyTrackerCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_BODY_SKELETON_FB:
            return TrackStruct(reinterpret_cast<const XrBodySkeletonFB*>(value), unwrap_memory);
        case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrBodyJointsLocateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
            return TrackStruct(reinterpret_cast<const XrBodyJointLocationsFB*>(value), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            return TrackStruct(reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(value), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            return TrackStruct(reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(value), unwrap_memory);
        case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrHandJointsMotionRangeInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneObserverCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrNewSceneComputeInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrVisualMeshComputeLodInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENTS_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneComponentsMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneComponentsGetInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneComponentLocationsMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneComponentsLocateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_OBJECTS_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneObjectsMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneComponentParentFilterInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneObjectTypesFilterInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_PLANES_MSFT:
            return TrackStruct(reinterpret_cast<const XrScenePlanesMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrScenePlaneAlignmentFilterInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESHES_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshesMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshBuffersGetInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshBuffersMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshVertexBufferMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshIndicesUint32MSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMeshIndicesUint16MSFT*>(value), unwrap_memory);
        case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSerializedSceneFragmentDataGetInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneDeserializeInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataDisplayRefreshRateChangedFB*>(value), unwrap_memory);
        case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            return TrackStruct(reinterpret_cast<const XrViveTrackerPathsHTCX*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            return TrackStruct(reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            return TrackStruct(reinterpret_cast<const XrSystemFacialTrackingPropertiesHTC*>(value), unwrap_memory);
        case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
            return TrackStruct(reinterpret_cast<const XrFacialExpressionsHTC*>(value), unwrap_memory);
        case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrFacialTrackerCreateInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemColorSpacePropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_MESH_FB:
            return TrackStruct(reinterpret_cast<const XrHandTrackingMeshFB*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_SCALE_FB:
            return TrackStruct(reinterpret_cast<const XrHandTrackingScaleFB*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            return TrackStruct(reinterpret_cast<const XrHandTrackingAimStateFB*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            return TrackStruct(reinterpret_cast<const XrHandTrackingCapsulesStateFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemSpatialEntityPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceComponentStatusSetInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceComponentStatusFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrFoveationProfileCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainCreateInfoFoveationFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainStateFoveationFB*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrFoveationLevelProfileCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemKeyboardTrackingPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrKeyboardSpaceCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
            return TrackStruct(reinterpret_cast<const XrKeyboardTrackingQueryFB*>(value), unwrap_memory);
        case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrTriangleMeshCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemPassthroughPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            return TrackStruct(reinterpret_cast<const XrSystemPassthroughProperties2FB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughLayerCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerPassthroughFB*>(value), unwrap_memory);
        case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrGeometryInstanceCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            return TrackStruct(reinterpret_cast<const XrGeometryInstanceTransformFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_STYLE_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughStyleFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorMapMonoToRgbaFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorMapMonoToMonoFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughBrightnessContrastSaturationFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataPassthroughStateChangedFB*>(value), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrRenderModelPathInfoFB*>(value), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrRenderModelPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_BUFFER_FB:
            return TrackStruct(reinterpret_cast<const XrRenderModelBufferFB*>(value), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrRenderModelLoadInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemRenderModelPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            return TrackStruct(reinterpret_cast<const XrRenderModelCapabilitiesRequestFB*>(value), unwrap_memory);
        case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            return TrackStruct(reinterpret_cast<const XrViewLocateFoveatedRenderingVARJO*>(value), unwrap_memory);
        case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            return TrackStruct(reinterpret_cast<const XrFoveatedViewConfigurationViewVARJO*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            return TrackStruct(reinterpret_cast<const XrSystemFoveatedRenderingPropertiesVARJO*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerDepthTestVARJO*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            return TrackStruct(reinterpret_cast<const XrSystemMarkerTrackingPropertiesVARJO*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            return TrackStruct(reinterpret_cast<const XrEventDataMarkerTrackingUpdateVARJO*>(value), unwrap_memory);
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
            return TrackStruct(reinterpret_cast<const XrMarkerSpaceCreateInfoVARJO*>(value), unwrap_memory);
        case XR_TYPE_FRAME_END_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrFrameEndInfoML*>(value), unwrap_memory);
        case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrGlobalDimmerFrameEndInfoML*>(value), unwrap_memory);
        case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrCoordinateSpaceCreateInfoML*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            return TrackStruct(reinterpret_cast<const XrSystemMarkerUnderstandingPropertiesML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorCreateInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorArucoInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorSizeInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorAprilTagInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorCustomProfileInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorSnapshotInfoML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_DETECTOR_STATE_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerDetectorStateML*>(value), unwrap_memory);
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMarkerSpaceCreateInfoML*>(value), unwrap_memory);
        case XR_TYPE_LOCALIZATION_MAP_ML:
            return TrackStruct(reinterpret_cast<const XrLocalizationMapML*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            return TrackStruct(reinterpret_cast<const XrEventDataLocalizationChangedML*>(value), unwrap_memory);
        case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrMapLocalizationRequestInfoML*>(value), unwrap_memory);
        case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrLocalizationMapImportInfoML*>(value), unwrap_memory);
        case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrLocalizationEnableEventsInfoML*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorPersistenceInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MARKERS_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMarkersMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMarkerTypeFilterMSFT*>(value), unwrap_memory);
        case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            return TrackStruct(reinterpret_cast<const XrSceneMarkerQRCodesMSFT*>(value), unwrap_memory);
        case XR_TYPE_SPACE_QUERY_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceQueryInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceStorageLocationFilterInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceUuidFilterInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceComponentFilterInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceQueryResultsFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceQueryCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_SAVE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceSaveInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_ERASE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceEraseInfoFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceSaveCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceEraseCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainStateAndroidSurfaceDimensionsFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainStateSamplerOpenGLESFB*>(value), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            return TrackStruct(reinterpret_cast<const XrSwapchainStateSamplerVulkanFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_SHARE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceShareInfoFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceShareCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemSpaceWarpPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            return TrackStruct(reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(value), unwrap_memory);
        case XR_TYPE_SEMANTIC_LABELS_FB:
            return TrackStruct(reinterpret_cast<const XrSemanticLabelsFB*>(value), unwrap_memory);
        case XR_TYPE_ROOM_LAYOUT_FB:
            return TrackStruct(reinterpret_cast<const XrRoomLayoutFB*>(value), unwrap_memory);
        case XR_TYPE_BOUNDARY_2D_FB:
            return TrackStruct(reinterpret_cast<const XrBoundary2DFB*>(value), unwrap_memory);
        case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSemanticLabelsSupportInfoFB*>(value), unwrap_memory);
        case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
            return TrackStruct(reinterpret_cast<const XrDigitalLensControlALMALENCE*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSceneCaptureCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSceneCaptureRequestInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_CONTAINER_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceContainerFB*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrFoveationEyeTrackedProfileCreateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
            return TrackStruct(reinterpret_cast<const XrFoveationEyeTrackedStateMETA*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            return TrackStruct(reinterpret_cast<const XrSystemFoveationEyeTrackedPropertiesMETA*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemFaceTrackingPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrFaceTrackerCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_FACE_EXPRESSION_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrFaceExpressionInfoFB*>(value), unwrap_memory);
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
            return TrackStruct(reinterpret_cast<const XrFaceExpressionWeightsFB*>(value), unwrap_memory);
        case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrEyeTrackerCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_EYE_GAZES_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrEyeGazesInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            return TrackStruct(reinterpret_cast<const XrSystemEyeTrackingPropertiesFB*>(value), unwrap_memory);
        case XR_TYPE_EYE_GAZES_FB:
            return TrackStruct(reinterpret_cast<const XrEyeGazesFB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
            return TrackStruct(reinterpret_cast<const XrPassthroughKeyboardHandsIntensityFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerSettingsFB*>(value), unwrap_memory);
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            return TrackStruct(reinterpret_cast<const XrHapticPcmVibrationFB*>(value), unwrap_memory);
        case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
            return TrackStruct(reinterpret_cast<const XrDevicePcmSampleRateStateFB*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerDepthTestFB*>(value), unwrap_memory);
        case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            return TrackStruct(reinterpret_cast<const XrLocalDimmingFrameEndInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
            return TrackStruct(reinterpret_cast<const XrPassthroughPreferencesMETA*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            return TrackStruct(reinterpret_cast<const XrSystemVirtualKeyboardPropertiesMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardCreateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardSpaceCreateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardLocationInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardModelVisibilitySetInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardAnimationStateMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardModelAnimationStatesMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardTextureDataMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardInputInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVirtualKeyboardTextContextChangeInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            return TrackStruct(reinterpret_cast<const XrEventDataVirtualKeyboardCommitTextMETA*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            return TrackStruct(reinterpret_cast<const XrEventDataVirtualKeyboardBackspaceMETA*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            return TrackStruct(reinterpret_cast<const XrEventDataVirtualKeyboardEnterMETA*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            return TrackStruct(reinterpret_cast<const XrEventDataVirtualKeyboardShownMETA*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            return TrackStruct(reinterpret_cast<const XrEventDataVirtualKeyboardHiddenMETA*>(value), unwrap_memory);
        case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
            return TrackStruct(reinterpret_cast<const XrExternalCameraOCULUS*>(value), unwrap_memory);
        case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrVulkanSwapchainCreateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
            return TrackStruct(reinterpret_cast<const XrPerformanceMetricsStateMETA*>(value), unwrap_memory);
        case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
            return TrackStruct(reinterpret_cast<const XrPerformanceMetricsCounterMETA*>(value), unwrap_memory);
        case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceListSaveInfoFB*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            return TrackStruct(reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB*>(value), unwrap_memory);
        case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
            return TrackStruct(reinterpret_cast<const XrSpaceUserCreateInfoFB*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            return TrackStruct(reinterpret_cast<const XrSystemHeadsetIdPropertiesMETA*>(value), unwrap_memory);
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
            return TrackStruct(reinterpret_cast<const XrRecommendedLayerResolutionMETA*>(value), unwrap_memory);
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            return TrackStruct(reinterpret_cast<const XrRecommendedLayerResolutionGetInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorLutCreateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorLutUpdateInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorMapLutMETA*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            return TrackStruct(reinterpret_cast<const XrSystemPassthroughColorLutPropertiesMETA*>(value), unwrap_memory);
        case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
            return TrackStruct(reinterpret_cast<const XrSpaceTriangleMeshGetInfoMETA*>(value), unwrap_memory);
        case XR_TYPE_SPACE_TRIANGLE_MESH_META:
            return TrackStruct(reinterpret_cast<const XrSpaceTriangleMeshMETA*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            return TrackStruct(reinterpret_cast<const XrSystemFaceTrackingProperties2FB*>(value), unwrap_memory);
        case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
            return TrackStruct(reinterpret_cast<const XrFaceTrackerCreateInfo2FB*>(value), unwrap_memory);
        case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
            return TrackStruct(reinterpret_cast<const XrFaceExpressionInfo2FB*>(value), unwrap_memory);
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
            return TrackStruct(reinterpret_cast<const XrFaceExpressionWeights2FB*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrPassthroughCreateInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_HTC:
            return TrackStruct(reinterpret_cast<const XrPassthroughColorHTC*>(value), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            return TrackStruct(reinterpret_cast<const XrCompositionLayerPassthroughHTC*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrFoveationApplyInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrFoveationDynamicModeInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrFoveationCustomModeInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            return TrackStruct(reinterpret_cast<const XrSystemAnchorPropertiesHTC*>(value), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            return TrackStruct(reinterpret_cast<const XrSpatialAnchorCreateInfoHTC*>(value), unwrap_memory);
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            return TrackStruct(reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            return TrackStruct(reinterpret_cast<const XrSystemForceFeedbackCurlPropertiesMNDX*>(value), unwrap_memory);
        case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
            return TrackStruct(reinterpret_cast<const XrForceFeedbackCurlApplyLocationsMNDX*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrHandTrackingDataSourceInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            return TrackStruct(reinterpret_cast<const XrHandTrackingDataSourceStateEXT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const XrSystemPlaneDetectionPropertiesEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorCreateInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorBeginInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorGetInfoEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorLocationEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorLocationsEXT*>(value), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
            return TrackStruct(reinterpret_cast<const XrPlaneDetectorPolygonBufferEXT*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            return TrackStruct(reinterpret_cast<const XrEventDataUserPresenceChangedEXT*>(value), unwrap_memory);
        case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            return TrackStruct(reinterpret_cast<const XrSystemUserPresencePropertiesEXT*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            return TrackStruct(reinterpret_cast<const XrEventDataHeadsetFitChangedML*>(value), unwrap_memory);
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            return TrackStruct(reinterpret_cast<const XrEventDataEyeCalibrationChangedML*>(value), unwrap_memory);
        case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
            return TrackStruct(reinterpret_cast<const XrUserCalibrationEnableEventsInfoML*>(value), unwrap_memory);
        default:
            GFXRECON_LOG_ERROR("Unknown structure type: %u", valueType);
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(openxr_trackers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
