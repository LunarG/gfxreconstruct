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

#include "generated/generated_openxr_struct_handle_wrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

void UnwrapStructHandles(XrApiLayerProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrExtensionProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInstanceProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataBuffer* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSessionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceVelocity* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrReferenceSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceLocation* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewConfigurationProperties* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewConfigurationView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            default:
                // Handle as parent-type below
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
                UnwrapStructHandles(reinterpret_cast<XrSwapchainImageVulkanKHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

    }
}

void UnwrapStructHandles(XrSwapchainImageAcquireInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageReleaseInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSessionBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFrameWaitInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFrameState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFrameBeginInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            default:
                // Handle as parent-type below
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerProjection*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerQuad*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerCubeKHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerCylinderKHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerEquirectKHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerEquirect2KHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerPassthroughFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                UnwrapStructHandles(reinterpret_cast<XrCompositionLayerPassthroughHTC*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

    }
}

void UnwrapStructHandles(XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
        value->layers = UnwrapStructPtrArrayHandles(const_cast<XrCompositionLayerBaseHeader**>(value->layers), value->layerCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionSetCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->suggestedBindings = UnwrapStructArrayHandles(const_cast<XrActionSuggestedBinding*>(value->suggestedBindings), value->countSuggestedBindings, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInteractionProfileState* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionStateBoolean* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionStateFloat* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionStateVector2f* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActionStatePose* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActiveActionSet* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
        value->activeActionSets = UnwrapStructArrayHandles(const_cast<XrActiveActionSet*>(value->activeActionSets), value->countActiveActionSets, unwrap_memory);
    }
}

void UnwrapStructHandles(XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInputSourceLocalizedNameGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainSubImage* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->views = UnwrapStructArrayHandles(const_cast<XrCompositionLayerProjectionView*>(value->views), value->viewCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            default:
                // Handle as parent-type below
                break;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSessionStateChanged*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                UnwrapStructHandles(reinterpret_cast<XrEventDataReferenceSpaceChangePending*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                UnwrapStructHandles(reinterpret_cast<XrEventDataInteractionProfileChanged*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                UnwrapStructHandles(reinterpret_cast<XrEventDataVisibilityMaskChangedKHR*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                UnwrapStructHandles(reinterpret_cast<XrEventDataViveTrackerConnectedHTCX*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpatialAnchorCreateCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceSetStatusCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                UnwrapStructHandles(reinterpret_cast<XrEventDataLocalizationChangedML*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceQueryResultsAvailableFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceQueryCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceSaveCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceEraseCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceShareCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                UnwrapStructHandles(reinterpret_cast<XrEventDataSpaceListSaveCompleteFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

    }
}

void UnwrapStructHandles(XrEventDataEventsLost* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataInstanceLossPending* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHapticVibration* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpacesLocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceLocations* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceVelocities* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInstanceCreateInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVulkanSwapchainFormatListCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingOpenGLWin32KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingOpenGLXlibKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingOpenGLXcbKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingOpenGLWaylandKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingOpenGLESAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsVulkanKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsD3D11KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsD3D12KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingMetalKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageMetalKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsRequirementsMetalKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVisibilityMaskKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerColorScaleBiasKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrLoaderInitInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBindingModificationBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            default:
                // Handle as parent-type below
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                UnwrapStructHandles(reinterpret_cast<XrInteractionProfileDpadBindingEXT*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                UnwrapStructHandles(reinterpret_cast<XrInteractionProfileAnalogThresholdVALVE*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

    }
}

void UnwrapStructHandles(XrBindingModificationsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->bindingModifications = UnwrapStructPtrArrayHandles(const_cast<XrBindingModificationBaseHeaderKHR**>(value->bindingModifications), value->bindingModificationCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataPerfSettingsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemEyeGazeInteractionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEyeGazeSampleTimeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSessionCreateInfoOverlayEXTX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataMainSessionVisibilityChangedEXTX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerImageLayoutFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerAlphaBlendFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewConfigurationDepthRangeEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGraphicsBindingEGLMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialGraphNodeSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialGraphNodeBindingPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemHandTrackingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandJointLocationsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandJointVelocitiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemHandTrackingMeshPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandMeshSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandMeshUpdateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandMeshMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandPoseTypeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationSessionBeginInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->layers = UnwrapStructPtrArrayHandles(const_cast<XrCompositionLayerBaseHeader**>(value->layers), value->layerCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->viewConfigurationLayersInfo = UnwrapStructArrayHandles(const_cast<XrSecondaryViewConfigurationLayerInfoMSFT*>(value->viewConfigurationLayersInfo), value->viewConfigurationCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrControllerModelKeyStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrControllerModelNodePropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrControllerModelPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrControllerModelNodeStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrControllerModelStateMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewConfigurationViewFovEPIC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHolographicWindowAttachmentMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerReprojectionInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerReprojectionPlaneOverrideMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrAndroidSurfaceSwapchainCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainStateBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            default:
                // Handle as parent-type below
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                UnwrapStructHandles(reinterpret_cast<XrSwapchainStateFoveationFB*>(value),
                                 unwrap_memory);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

    }
}

void UnwrapStructHandles(XrCompositionLayerSecureContentFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemBodyTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBodyTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBodySkeletonFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBodyJointLocationsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandJointsMotionRangeInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneObserverCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneBoundsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->bounds, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVisualMeshComputeLodInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneComponentsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneComponentsGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneComponentLocationsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneObjectsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneComponentParentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneObjectTypesFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrScenePlanesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrScenePlaneAlignmentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshBuffersGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshBuffersMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshVertexBufferMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshIndicesUint32MSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMeshIndicesUint16MSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSerializedSceneFragmentDataGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneDeserializeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataDisplayRefreshRateChangedFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViveTrackerPathsHTCX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataViveTrackerConnectedHTCX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->paths = UnwrapStructPtrHandles(value->paths, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemFacialTrackingPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFacialExpressionsHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFacialTrackerCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemColorSpacePropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingMeshFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingScaleFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingAimStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingCapsulesStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemSpatialEntityPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceComponentStatusSetInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceComponentStatusFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainCreateInfoFoveationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationLevelProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemKeyboardTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrKeyboardSpaceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrKeyboardTrackingQueryFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrTriangleMeshCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemPassthroughPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemPassthroughProperties2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorMapMonoToRgbaFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorMapMonoToMonoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughBrightnessContrastSaturationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataPassthroughStateChangedFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRenderModelPathInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRenderModelBufferFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRenderModelLoadInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRenderModelCapabilitiesRequestFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrViewLocateFoveatedRenderingVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveatedViewConfigurationViewVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemFoveatedRenderingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerDepthTestVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemMarkerTrackingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataMarkerTrackingUpdateVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerSpaceCreateInfoVARJO* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrGlobalDimmerFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCoordinateSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemMarkerUnderstandingPropertiesML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorArucoInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorSizeInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorAprilTagInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorCustomProfileInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorSnapshotInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerDetectorStateML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrLocalizationMapML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrMapLocalizationRequestInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrLocalizationMapImportInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrLocalizationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMarkersMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMarkerTypeFilterMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneMarkerQRCodesMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceQueryInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceStorageLocationFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceUuidFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceComponentFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceQueryResultFB* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->results = UnwrapStructArrayHandles(value->results, value->resultCapacityInput, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceQueryResultsAvailableFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceQueryCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainStateAndroidSurfaceDimensionsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainStateSamplerOpenGLESFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSwapchainStateSamplerVulkanFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceShareCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->motionVectorSubImage, unwrap_memory);
        UnwrapStructHandles(&value->depthSubImage, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemSpaceWarpPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHapticAmplitudeEnvelopeVibrationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSemanticLabelsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRoomLayoutFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrBoundary2DFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSemanticLabelsSupportInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDigitalLensControlALMALENCE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSceneCaptureCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSceneCaptureRequestInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceContainerFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationEyeTrackedProfileCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationEyeTrackedStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemFoveationEyeTrackedPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemFaceTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceExpressionInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceExpressionWeightsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEyeTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemEyeTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEyeGazesFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughKeyboardHandsIntensityFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerSettingsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHapticPcmVibrationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrDevicePcmSampleRateStateFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerDepthTestFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrLocalDimmingFrameEndInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughPreferencesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemVirtualKeyboardPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardModelVisibilitySetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardAnimationStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardModelAnimationStatesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardTextureDataMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVirtualKeyboardTextContextChangeInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrExternalCameraOCULUS* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrVulkanSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPerformanceMetricsStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPerformanceMetricsCounterMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataSpaceListSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceUserCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemHeadsetIdPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRecommendedLayerResolutionMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->layer = UnwrapStructPtrHandles(value->layer, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorLutCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorLutUpdateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemPassthroughColorLutPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceTriangleMeshGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpaceTriangleMeshMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemFaceTrackingProperties2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceTrackerCreateInfo2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceExpressionInfo2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFaceExpressionWeights2FB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthProviderCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthSwapchainStateMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthImageAcquireInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthImageViewMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthImageMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEnvironmentDepthHandRemovalSetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemEnvironmentDepthPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughColorHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->subImages = UnwrapStructArrayHandles(value->subImages, value->subImageCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationDynamicModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFoveationCustomModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemAnchorPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrActiveActionSetPriorityEXT* value, HandleUnwrapMemory* unwrap_memory)
{
}

void UnwrapStructHandles(XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->actionSetPriorities = UnwrapStructArrayHandles(const_cast<XrActiveActionSetPriorityEXT*>(value->actionSetPriorities), value->actionSetPriorityCount, unwrap_memory);
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemForceFeedbackCurlPropertiesMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrForceFeedbackCurlApplyLocationsMNDX* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingDataSourceInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrHandTrackingDataSourceStateEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemPlaneDetectionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorLocationEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorLocationsEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrPlaneDetectorPolygonBufferEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFutureCancelInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFuturePollInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFutureCompletionEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrFuturePollResultEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrSystemUserPresencePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataHeadsetFitChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrEventDataEyeCalibrationChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

void UnwrapStructHandles(XrUserCalibrationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = const_cast<void*>(UnwrapNextStructHandles(value->next, unwrap_memory));
        }
    }
}

XrBaseInStructure* CopyNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)
{
    assert(base != nullptr);

    XrBaseInStructure* copy = nullptr;
    switch (base->type)
    {
    default:
        GFXRECON_LOG_WARNING("Failed to copy entire next chain when unwrapping handles due to unrecognized type %d", base->type);
        break;
    case XR_TYPE_ACTION_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_SET_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionSetCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_SPACE_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionSpaceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_STATE_BOOLEAN:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionStateBoolean*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_STATE_FLOAT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionStateFloat*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_STATE_GET_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionStateGetInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_STATE_POSE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionStatePose*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTION_STATE_VECTOR2F:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionStateVector2f*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTIONS_SYNC_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActionsSyncInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrAndroidSurfaceSwapchainCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_API_LAYER_PROPERTIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrApiLayerProperties*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BINDING_MODIFICATIONS_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBindingModificationsKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBodyJointLocationsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBodyJointsLocateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BODY_SKELETON_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBodySkeletonFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBodyTrackerCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBoundSourcesForActionEnumerateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BOUNDARY_2D_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBoundary2DFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerAlphaBlendFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerColorScaleBiasKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerCubeKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerCylinderKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthTestFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthTestVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerEquirect2KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerEquirectKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerImageLayoutFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerPassthroughHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerProjection*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerProjectionView*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_QUAD:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerQuad*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerReprojectionInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerReprojectionPlaneOverrideMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSecureContentFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSettingsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrControllerModelKeyStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrControllerModelNodePropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrControllerModelNodeStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrControllerModelPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrControllerModelStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCoordinateSpaceCreateInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDebugUtilsLabelEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDebugUtilsMessengerCallbackDataEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDebugUtilsObjectNameInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDevicePcmSampleRateStateFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDigitalLensControlALMALENCE*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthHandRemovalSetInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthImageAcquireInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthImageMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthImageViewMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthProviderCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthSwapchainCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEnvironmentDepthSwapchainStateMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_BUFFER:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataBuffer*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataDisplayRefreshRateChangedFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_EVENTS_LOST:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataEventsLost*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataEyeCalibrationChangedML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataHeadsetFitChangedML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataInstanceLossPending*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataInteractionProfileChanged*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataLocalizationChangedML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataMainSessionVisibilityChangedEXTX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataMarkerTrackingUpdateVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataPassthroughStateChangedFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataPerfSettingsEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataReferenceSpaceChangePending*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSceneCaptureCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSessionStateChanged*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceEraseCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceQueryCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceSaveCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpaceShareCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataUserPresenceChangedEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVirtualKeyboardBackspaceMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVirtualKeyboardCommitTextMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVirtualKeyboardEnterMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVirtualKeyboardHiddenMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVirtualKeyboardShownMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EXTENSION_PROPERTIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrExtensionProperties*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrExternalCameraOCULUS*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEyeGazeSampleTimeEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EYE_GAZES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEyeGazesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EYE_GAZES_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEyeGazesInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEyeTrackerCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceExpressionInfo2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_EXPRESSION_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceExpressionInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceExpressionWeights2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceExpressionWeightsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceTrackerCreateInfo2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFaceTrackerCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFacialExpressionsHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFacialTrackerCreateInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrForceFeedbackCurlApplyLocationsMNDX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveatedViewConfigurationViewVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationApplyInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationCustomModeInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationDynamicModeInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationEyeTrackedProfileCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationEyeTrackedStateMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationLevelProfileCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationProfileCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_BEGIN_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameBeginInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_END_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameEndInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_END_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameEndInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_STATE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameState*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_WAIT_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameWaitInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFutureCancelInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FUTURE_COMPLETION_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFutureCompletionEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FUTURE_POLL_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFuturePollInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FUTURE_POLL_RESULT_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFuturePollResultEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGeometryInstanceCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGeometryInstanceTransformFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGlobalDimmerFrameEndInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingD3D11KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingD3D12KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingEGLMNDX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingMetalKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsD3D11KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsD3D12KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsMetalKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsOpenGLESKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsOpenGLKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsRequirementsVulkanKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointLocationsEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointVelocitiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointsLocateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointsMotionRangeInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_MESH_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandMeshMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandMeshSpaceCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandMeshUpdateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandPoseTypeInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingAimStateFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingCapsulesStateFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingDataSourceInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingDataSourceStateEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_MESH_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingMeshFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_SCALE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingScaleFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAPTIC_ACTION_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHapticActionInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHapticAmplitudeEnvelopeVibrationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHapticPcmVibrationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAPTIC_VIBRATION:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHapticVibration*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHolographicWindowAttachmentMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInputSourceLocalizedNameGetInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INSTANCE_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInstanceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInstanceCreateInfoAndroidKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INSTANCE_PROPERTIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInstanceProperties*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INTERACTION_PROFILE_STATE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInteractionProfileState*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInteractionProfileSuggestedBinding*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrKeyboardSpaceCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrKeyboardTrackingQueryFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLoaderInitInfoAndroidKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLocalDimmingFrameEndInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLocalizationEnableEventsInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLocalizationMapImportInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOCALIZATION_MAP_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLocalizationMapML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMapLocalizationRequestInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorAprilTagInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorArucoInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorCreateInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorCustomProfileInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorSizeInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorSnapshotInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_STATE_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorStateML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerSpaceCreateInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerSpaceCreateInfoVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrNewSceneComputeInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughBrightnessContrastSaturationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorLutCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorLutUpdateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapMonoToMonoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapMonoToRgbaFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughCreateInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughKeyboardHandsIntensityFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughLayerCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughPreferencesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_STYLE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughStyleFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPerformanceMetricsCounterMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPerformanceMetricsStateMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorBeginInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorGetInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorLocationEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorLocationsEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPlaneDetectorPolygonBufferEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRecommendedLayerResolutionGetInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRecommendedLayerResolutionMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrReferenceSpaceCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_BUFFER_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelBufferFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelCapabilitiesRequestFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelLoadInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelPathInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ROOM_LAYOUT_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRoomLayoutFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneCaptureRequestInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentLocationsMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentParentFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentsGetInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentsLocateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENTS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentsMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneDeserializeInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkerQRCodesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkerTypeFilterMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKERS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkersMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshBuffersGetInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshBuffersMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshIndicesUint16MSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshIndicesUint32MSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshVertexBufferMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESHES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneObjectTypesFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_OBJECTS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneObjectsMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneObserverCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrScenePlaneAlignmentFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_PLANES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrScenePlanesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationFrameStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationLayerInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SEMANTIC_LABELS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSemanticLabelsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSemanticLabelsSupportInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSerializedSceneFragmentDataGetInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSessionActionSetsAttachInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SESSION_BEGIN_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSessionBeginInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SESSION_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSessionCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSessionCreateInfoOverlayEXTX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceComponentFilterInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceComponentStatusFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceComponentStatusSetInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_CONTAINER_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceContainerFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_ERASE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceEraseInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceListSaveInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_LOCATION:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceLocation*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_LOCATIONS:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceLocations*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_QUERY_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceQueryInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_QUERY_RESULTS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceQueryResultsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_SAVE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceSaveInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_SHARE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceShareInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceStorageLocationFilterInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceTriangleMeshGetInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_TRIANGLE_MESH_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceTriangleMeshMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceUserCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceUuidFilterInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_VELOCITIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceVelocities*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_VELOCITY:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceVelocity*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACES_LOCATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpacesLocateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorCreateInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorPersistenceInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialAnchorSpaceCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialGraphNodeBindingPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialGraphNodeSpaceCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_CREATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainCreateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainCreateInfoFoveationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageAcquireInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageD3D11KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageD3D12KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageMetalKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageOpenGLESKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageOpenGLKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageReleaseInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageVulkanKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageWaitInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainStateAndroidSurfaceDimensionsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainStateFoveationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainStateSamplerOpenGLESFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainStateSamplerVulkanFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemAnchorPropertiesHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemBodyTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemColorSpacePropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemEnvironmentDepthPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemEyeGazeInteractionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemEyeTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFaceTrackingProperties2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFaceTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFacialTrackingPropertiesHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemForceFeedbackCurlPropertiesMNDX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFoveatedRenderingPropertiesVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFoveationEyeTrackedPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_GET_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemGetInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHandTrackingMeshPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHandTrackingPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHeadsetIdPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemKeyboardTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemMarkerTrackingPropertiesVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemMarkerUnderstandingPropertiesML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughColorLutPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughProperties2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPlaneDetectionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PROPERTIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemProperties*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemRenderModelPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemSpaceWarpPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemSpatialEntityPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemUserPresencePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemVirtualKeyboardPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrTriangleMeshCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrUserCalibrationEnableEventsInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrView*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationDepthRangeEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationProperties*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_VIEW:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationView*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationViewFovEPIC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewLocateFoveatedRenderingVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_LOCATE_INFO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewLocateInfo*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_STATE:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewState*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardAnimationStateMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardInputInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardLocationInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardModelAnimationStatesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardModelVisibilitySetInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardSpaceCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardTextContextChangeInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVirtualKeyboardTextureDataMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VISIBILITY_MASK_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVisibilityMaskKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVisualMeshComputeLodInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViveTrackerPathsHTCX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVulkanGraphicsDeviceGetInfoKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVulkanSwapchainCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVulkanSwapchainFormatListCreateInfoKHR*>(base), 1, unwrap_memory));
        break;
    }

    return copy;
}

void* UnwrapNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        const XrBaseInStructure* base = reinterpret_cast<const XrBaseInStructure*>(value);

        switch (base->type)
        {
        default:
        {
            // This structure does not contain handles, but may point to a structure that does.
            XrBaseInStructure* copy = CopyNextStruct(base, unwrap_memory);
            if (copy != nullptr)
            {
                copy->next = reinterpret_cast<const XrBaseInStructure*>(UnwrapNextStructHandles(base->next, unwrap_memory));
            }
            return copy;
        }
        case XR_TYPE_ACTION_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActionCreateInfo*>(base), unwrap_memory);
        case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActionSpaceCreateInfo*>(base), unwrap_memory);
        case XR_TYPE_ACTION_STATE_GET_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActionStateGetInfo*>(base), unwrap_memory);
        case XR_TYPE_ACTIONS_SYNC_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActionsSyncInfo*>(base), unwrap_memory);
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base), unwrap_memory);
        case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrBindingModificationsKHR*>(base), unwrap_memory);
        case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrBodyJointsLocateInfoFB*>(base), unwrap_memory);
        case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrBoundSourcesForActionEnumerateInfo*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerCubeKHR*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerCylinderKHR*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerEquirect2KHR*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerEquirectKHR*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerPassthroughHTC*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerProjection*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerProjectionView*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerQuad*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base), unwrap_memory);
        case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrControllerModelKeyStateMSFT*>(base), unwrap_memory);
        case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEnvironmentDepthImageAcquireInfoMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataInteractionProfileChanged*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataLocalizationChangedML*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataReferenceSpaceChangePending*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSceneCaptureCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSessionStateChanged*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceEraseCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceListSaveCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceQueryCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceQueryResultsAvailableFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceSaveCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceSetStatusCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpaceShareCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataSpatialAnchorCreateCompleteFB*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataUserPresenceChangedEXT*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVirtualKeyboardBackspaceMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVirtualKeyboardCommitTextMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVirtualKeyboardEnterMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVirtualKeyboardHiddenMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVirtualKeyboardShownMETA*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataVisibilityMaskChangedKHR*>(base), unwrap_memory);
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEventDataViveTrackerConnectedHTCX*>(base), unwrap_memory);
        case XR_TYPE_EYE_GAZES_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrEyeGazesInfoFB*>(base), unwrap_memory);
        case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrFoveationApplyInfoHTC*>(base), unwrap_memory);
        case XR_TYPE_FRAME_END_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrFrameEndInfo*>(base), unwrap_memory);
        case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrFutureCancelInfoEXT*>(base), unwrap_memory);
        case XR_TYPE_FUTURE_POLL_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrFuturePollInfoEXT*>(base), unwrap_memory);
        case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrGeometryInstanceCreateInfoFB*>(base), unwrap_memory);
        case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrGeometryInstanceTransformFB*>(base), unwrap_memory);
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(base), unwrap_memory);
        case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrHandJointsLocateInfoEXT*>(base), unwrap_memory);
        case XR_TYPE_HAPTIC_ACTION_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrHapticActionInfo*>(base), unwrap_memory);
        case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrInputSourceLocalizedNameGetInfo*>(base), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrInteractionProfileAnalogThresholdVALVE*>(base), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrInteractionProfileDpadBindingEXT*>(base), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_STATE:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrInteractionProfileState*>(base), unwrap_memory);
        case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrInteractionProfileSuggestedBinding*>(base), unwrap_memory);
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrMarkerSpaceCreateInfoML*>(base), unwrap_memory);
        case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrNewSceneComputeInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughLayerCreateInfoFB*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_STYLE_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughStyleFB*>(base), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPlaneDetectorBeginInfoEXT*>(base), unwrap_memory);
        case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPlaneDetectorGetInfoEXT*>(base), unwrap_memory);
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrRecommendedLayerResolutionGetInfoMETA*>(base), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrRenderModelLoadInfoFB*>(base), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrRenderModelPathInfoFB*>(base), unwrap_memory);
        case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrRenderModelPropertiesFB*>(base), unwrap_memory);
        case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSceneComponentsLocateInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSecondaryViewConfigurationLayerInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSessionActionSetsAttachInfo*>(base), unwrap_memory);
        case XR_TYPE_SESSION_CREATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSessionCreateInfo*>(base), unwrap_memory);
        case XR_TYPE_SPACE_ERASE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceEraseInfoFB*>(base), unwrap_memory);
        case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceListSaveInfoFB*>(base), unwrap_memory);
        case XR_TYPE_SPACE_LOCATION:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceLocation*>(base), unwrap_memory);
        case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceQueryResultsFB*>(base), unwrap_memory);
        case XR_TYPE_SPACE_SAVE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceSaveInfoFB*>(base), unwrap_memory);
        case XR_TYPE_SPACE_SHARE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpaceShareInfoFB*>(base), unwrap_memory);
        case XR_TYPE_SPACES_LOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpacesLocateInfo*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorCreateInfoFB*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorCreateInfoHTC*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorCreateInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorPersistenceInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialAnchorSpaceCreateInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(base), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSwapchainImageVulkanKHR*>(base), unwrap_memory);
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSwapchainStateFoveationFB*>(base), unwrap_memory);
        case XR_TYPE_SYSTEM_PROPERTIES:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSystemProperties*>(base), unwrap_memory);
        case XR_TYPE_VIEW_LOCATE_INFO:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrViewLocateInfo*>(base), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrVirtualKeyboardInputInfoMETA*>(base), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrVirtualKeyboardLocationInfoMETA*>(base), unwrap_memory);
        case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrVirtualKeyboardSpaceCreateInfoMETA*>(base), unwrap_memory);
        case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrViveTrackerPathsHTCX*>(base), unwrap_memory);
        case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrVulkanGraphicsDeviceGetInfoKHR*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
