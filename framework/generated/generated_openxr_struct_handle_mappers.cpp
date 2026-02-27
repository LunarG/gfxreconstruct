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

#include "generated/generated_openxr_struct_handle_mappers.h"

#include "decode/custom_openxr_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/openxr_handle_mapping_util.h"
#include "generated/generated_openxr_struct_decoders.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_XrApiLayerProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrExtensionProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInstanceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInstanceProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataBuffer* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemGetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSystemProperties* value = wrapper->decoded_value;

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSessionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSessionCreateInfo* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceVelocity* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrReferenceSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionSpaceCreateInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceLocation* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViewConfigurationProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViewConfigurationView* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainImageBaseHeader* value = wrapper->decoded_value;

        switch (value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageVulkanKHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageAcquireInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageReleaseInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSessionBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFrameWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFrameState* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFrameBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerBaseHeader* value = wrapper->decoded_value;

        switch (value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerProjection*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_QUAD:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerQuad*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerCubeKHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerCylinderKHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerEquirectKHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerEquirect2KHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughHTC*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrFrameEndInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructPtrArrayHandles<Decoded_XrCompositionLayerBaseHeader*>(wrapper->layers->GetMetaStructPointer(), wrapper->layers->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrViewLocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrViewLocateInfo* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViewState* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrView* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionSetCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionCreateInfo* value = wrapper->decoded_value;

        value->subactionPaths = handle_mapping::MapHandleArray<OpenXrPathInfo>(&wrapper->subactionPaths, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionSuggestedBinding* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->binding = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->binding, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrInteractionProfileSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileSuggestedBinding* value = wrapper->decoded_value;

        value->interactionProfile = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->interactionProfile, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        MapStructArrayHandles<Decoded_XrActionSuggestedBinding>(wrapper->suggestedBindings->GetMetaStructPointer(), wrapper->suggestedBindings->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSessionActionSetsAttachInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSessionActionSetsAttachInfo* value = wrapper->decoded_value;

        value->actionSets = handle_mapping::MapHandleArray<OpenXrActionSetInfo>(&wrapper->actionSets, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInteractionProfileState* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileState* value = wrapper->decoded_value;

        value->interactionProfile = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->interactionProfile, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionStateGetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionStateGetInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionStateBoolean* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionStateFloat* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionStateVector2f* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActionStatePose* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActiveActionSet* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActiveActionSet* value = wrapper->decoded_value;

        value->actionSet = handle_mapping::MapHandle<OpenXrActionSetInfo>(wrapper->actionSet, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrActionsSyncInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrActiveActionSet>(wrapper->activeActionSets->GetMetaStructPointer(), wrapper->activeActionSets->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrBoundSourcesForActionEnumerateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrBoundSourcesForActionEnumerateInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInputSourceLocalizedNameGetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInputSourceLocalizedNameGetInfo* value = wrapper->decoded_value;

        value->sourcePath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->sourcePath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHapticActionInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrHapticActionInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainSubImage* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainSubImage* value = wrapper->decoded_value;

        value->swapchain = handle_mapping::MapHandle<OpenXrSwapchainInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetXrSwapchainInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerProjectionView* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerProjection* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerProjection* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructArrayHandles<Decoded_XrCompositionLayerProjectionView>(wrapper->views->GetMetaStructPointer(), wrapper->views->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerQuad* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerQuad* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataBaseHeader* value = wrapper->decoded_value;

        switch (value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSessionStateChanged*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataReferenceSpaceChangePending*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataInteractionProfileChanged*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataVisibilityMaskChangedKHR*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataViveTrackerConnectedHTCX*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceSetStatusCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataLocalizationChangedML*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceQueryCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceSaveCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceEraseCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceShareCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceListSaveCompleteFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }
    }
}

void MapStructHandles(Decoded_XrEventDataEventsLost* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataInstanceLossPending* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSessionStateChanged* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSessionStateChanged* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataReferenceSpaceChangePending* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataReferenceSpaceChangePending* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataInteractionProfileChanged* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataInteractionProfileChanged* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHapticVibration* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpacesLocateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpacesLocateInfo* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->spaces = handle_mapping::MapHandleArray<OpenXrSpaceInfo>(&wrapper->spaces, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceLocations* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceVelocities* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerCubeKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerCubeKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->swapchain = handle_mapping::MapHandle<OpenXrSwapchainInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetXrSwapchainInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInstanceCreateInfoAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerDepthInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->subImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerCylinderKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerCylinderKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerEquirectKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerEquirectKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageOpenGLKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsOpenGLKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageOpenGLESKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsOpenGLESKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGraphicsBindingVulkanKHR* value = wrapper->decoded_value;

        value->instance = handle_mapping::MapHandle<VulkanInstanceInfo>(wrapper->instance, object_info_table, &CommonObjectInfoTable::GetVkInstanceInfo);

        value->physicalDevice = handle_mapping::MapHandle<VulkanPhysicalDeviceInfo>(wrapper->physicalDevice, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);

        value->device = handle_mapping::MapHandle<VulkanDeviceInfo>(wrapper->device, object_info_table, &CommonObjectInfoTable::GetVkDeviceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainImageVulkanKHR* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsRequirementsMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVisibilityMaskKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVisibilityMaskChangedKHR* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLoaderInitInfoAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVulkanGraphicsDeviceGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVulkanGraphicsDeviceGetInfoKHR* value = wrapper->decoded_value;

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);

        value->vulkanInstance = handle_mapping::MapHandle<VulkanInstanceInfo>(wrapper->vulkanInstance, object_info_table, &CommonObjectInfoTable::GetVkInstanceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerEquirect2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerEquirect2KHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBindingModificationBaseHeaderKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrBindingModificationBaseHeaderKHR* value = wrapper->decoded_value;

        switch (value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
                MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileDpadBindingEXT*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
            case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
                MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileAnalogThresholdVALVE*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }
    }
}

void MapStructHandles(Decoded_XrBindingModificationsKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructPtrArrayHandles<Decoded_XrBindingModificationBaseHeaderKHR*>(wrapper->bindingModifications->GetMetaStructPointer(), wrapper->bindingModifications->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataPerfSettingsEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrDebugUtilsObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrDebugUtilsLabelEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrDebugUtilsMessengerCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrDebugUtilsObjectNameInfoEXT>(wrapper->objects->GetMetaStructPointer(), wrapper->objects->GetLength(), object_info_table);

        MapStructArrayHandles<Decoded_XrDebugUtilsLabelEXT>(wrapper->sessionLabels->GetMetaStructPointer(), wrapper->sessionLabels->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrDebugUtilsMessengerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemEyeGazeInteractionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEyeGazeSampleTimeEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSessionCreateInfoOverlayEXTX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataMainSessionVisibilityChangedEXTX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoMSFT* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorSpaceCreateInfoMSFT* value = wrapper->decoded_value;

        value->anchor = handle_mapping::MapHandle<OpenXrSpatialAnchorMSFTInfo>(wrapper->anchor, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerImageLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerAlphaBlendFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViewConfigurationDepthRangeEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingEGLMNDX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemHandTrackingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandJointsLocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrHandJointsLocateInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandJointLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandJointVelocitiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemHandTrackingMeshPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandMeshSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandMeshUpdateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandMeshMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandPoseTypeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrSecondaryViewConfigurationStateMSFT>(wrapper->viewConfigurationStates->GetMetaStructPointer(), wrapper->viewConfigurationStates->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructPtrArrayHandles<Decoded_XrCompositionLayerBaseHeader*>(wrapper->layers->GetMetaStructPointer(), wrapper->layers->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT>(wrapper->viewConfigurationLayersInfo->GetMetaStructPointer(), wrapper->viewConfigurationLayersInfo->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrControllerModelKeyStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrControllerModelKeyStateMSFT* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrControllerModelKeyMSFTInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrControllerModelKeyMSFTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrControllerModelNodePropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrControllerModelPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrControllerModelNodePropertiesMSFT>(wrapper->nodeProperties->GetMetaStructPointer(), wrapper->nodeProperties->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrControllerModelNodeStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrControllerModelStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrControllerModelNodeStateMSFT>(wrapper->nodeStates->GetMetaStructPointer(), wrapper->nodeStates->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrViewConfigurationViewFovEPIC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHolographicWindowAttachmentMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerReprojectionInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainStateBaseHeaderFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainStateBaseHeaderFB* value = wrapper->decoded_value;

        switch (value->type)
        {
            default:
                // Handle as base-type below
                break;
            case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
                MapStructHandles(reinterpret_cast<Decoded_XrSwapchainStateFoveationFB*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSecureContentFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemBodyTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBodyTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBodySkeletonFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBodyJointsLocateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrBodyJointsLocateInfoFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBodyJointLocationsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInteractionProfileDpadBindingEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileDpadBindingEXT* value = wrapper->decoded_value;

        value->binding = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->binding, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        value->actionSet = handle_mapping::MapHandle<OpenXrActionSetInfo>(wrapper->actionSet, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileAnalogThresholdVALVE* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->binding = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->binding, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandJointsMotionRangeInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneObserverCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneBoundsMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSceneBoundsMSFT* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrNewSceneComputeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->bounds, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVisualMeshComputeLodInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneComponentsMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneComponentsGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneComponentLocationsMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneComponentsLocateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSceneComponentsLocateInfoMSFT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneObjectsMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneComponentParentFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneObjectTypesFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrScenePlanesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrScenePlaneAlignmentFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshBuffersGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshBuffersMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshVertexBufferMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshIndicesUint32MSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMeshIndicesUint16MSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneDeserializeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataDisplayRefreshRateChangedFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViveTrackerPathsHTCX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrViveTrackerPathsHTCX* value = wrapper->decoded_value;

        value->persistentPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->persistentPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        value->rolePath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->rolePath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrViveTrackerPathsHTCX>(wrapper->paths->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemFacialTrackingPropertiesHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFacialExpressionsHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFacialTrackerCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemColorSpacePropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingMeshFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingScaleFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingAimStateFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingCapsulesStateFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemSpatialEntityPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceComponentStatusSetInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceComponentStatusFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpatialAnchorCreateCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceSetStatusCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationProfileCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainCreateInfoFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainStateFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainStateFoveationFB* value = wrapper->decoded_value;

        value->profile = handle_mapping::MapHandle<OpenXrFoveationProfileFBInfo>(wrapper->profile, object_info_table, &CommonObjectInfoTable::GetXrFoveationProfileFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationLevelProfileCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemKeyboardTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrKeyboardSpaceCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrKeyboardTrackingQueryFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrTriangleMeshCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemPassthroughPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemPassthroughProperties2FB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughLayerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughLayerCreateInfoFB* value = wrapper->decoded_value;

        value->passthrough = handle_mapping::MapHandle<OpenXrPassthroughFBInfo>(wrapper->passthrough, object_info_table, &CommonObjectInfoTable::GetXrPassthroughFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerPassthroughFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerPassthroughFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->layerHandle = handle_mapping::MapHandle<OpenXrPassthroughLayerFBInfo>(wrapper->layerHandle, object_info_table, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGeometryInstanceCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGeometryInstanceCreateInfoFB* value = wrapper->decoded_value;

        value->layer = handle_mapping::MapHandle<OpenXrPassthroughLayerFBInfo>(wrapper->layer, object_info_table, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);

        value->mesh = handle_mapping::MapHandle<OpenXrTriangleMeshFBInfo>(wrapper->mesh, object_info_table, &CommonObjectInfoTable::GetXrTriangleMeshFBInfo);

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGeometryInstanceTransformFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGeometryInstanceTransformFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughStyleFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataPassthroughStateChangedFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelPathInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelPathInfoFB* value = wrapper->decoded_value;

        value->path = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->path, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelPropertiesFB* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrRenderModelKeyFBInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrRenderModelKeyFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelBufferFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelLoadInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelLoadInfoFB* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrRenderModelKeyFBInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrRenderModelKeyFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelCapabilitiesRequestFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrViewLocateFoveatedRenderingVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveatedViewConfigurationViewVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemFoveatedRenderingPropertiesVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerDepthTestVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemMarkerTrackingPropertiesVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataMarkerTrackingUpdateVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerSpaceCreateInfoVARJO* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGlobalDimmerFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCoordinateSpaceCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemMarkerUnderstandingPropertiesML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorArucoInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorSizeInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorAprilTagInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorCustomProfileInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorSnapshotInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerDetectorStateML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrMarkerSpaceCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrMarkerSpaceCreateInfoML* value = wrapper->decoded_value;

        value->markerDetector = handle_mapping::MapHandle<OpenXrMarkerDetectorMLInfo>(wrapper->markerDetector, object_info_table, &CommonObjectInfoTable::GetXrMarkerDetectorMLInfo);

        value->marker = handle_mapping::MapHandle<OpenXrMarkerMLInfo>(wrapper->marker, object_info_table, &CommonObjectInfoTable::GetXrMarkerMLInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLocalizationMapML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataLocalizationChangedML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataLocalizationChangedML* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructHandles(wrapper->map, object_info_table);
    }
}

void MapStructHandles(Decoded_XrMapLocalizationRequestInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLocalizationMapImportInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLocalizationEnableEventsInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorPersistenceInfoMSFT* value = wrapper->decoded_value;

        value->spatialAnchor = handle_mapping::MapHandle<OpenXrSpatialAnchorMSFTInfo>(wrapper->spatialAnchor, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value = wrapper->decoded_value;

        value->spatialAnchorStore = handle_mapping::MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(wrapper->spatialAnchorStore, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMarkersMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMarkerTypeFilterMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneMarkerQRCodesMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceQueryInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceStorageLocationFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceUuidFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceComponentFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceQueryResultFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceQueryResultFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceQueryResultsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrSpaceQueryResultFB>(wrapper->results->GetMetaStructPointer(), wrapper->results->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceQueryResultsAvailableFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceQueryCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceQueryCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceSaveInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceEraseInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceEraseInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceSaveCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceEraseCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceEraseCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainImageFoveationVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainImageFoveationVulkanFB* value = wrapper->decoded_value;

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainStateSamplerOpenGLESFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSwapchainStateSamplerVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceShareInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceShareInfoFB* value = wrapper->decoded_value;

        value->spaces = handle_mapping::MapHandleArray<OpenXrSpaceInfo>(&wrapper->spaces, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->users = handle_mapping::MapHandleArray<OpenXrSpaceUserFBInfo>(&wrapper->users, object_info_table, &CommonObjectInfoTable::GetXrSpaceUserFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceShareCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceShareCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->motionVectorSubImage, object_info_table);

        MapStructHandles(wrapper->depthSubImage, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemSpaceWarpPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHapticAmplitudeEnvelopeVibrationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSemanticLabelsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRoomLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBoundary2DFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSemanticLabelsSupportInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrDigitalLensControlALMALENCE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSceneCaptureCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSceneCaptureCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSceneCaptureRequestInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceContainerFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationEyeTrackedStateMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemFaceTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceExpressionInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceExpressionWeightsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEyeTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEyeGazesInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEyeGazesInfoFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemEyeTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEyeGazesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughKeyboardHandsIntensityFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSettingsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHapticPcmVibrationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrDevicePcmSampleRateStateFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerDepthTestFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughPreferencesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemVirtualKeyboardPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardSpaceCreateInfoMETA* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardLocationInfoMETA* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardAnimationStateMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardModelAnimationStatesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrVirtualKeyboardAnimationStateMETA>(wrapper->states->GetMetaStructPointer(), wrapper->states->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardTextureDataMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardInputInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardInputInfoMETA* value = wrapper->decoded_value;

        value->inputSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->inputSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardCommitTextMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardBackspaceMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardEnterMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardShownMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardHiddenMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrExternalCameraOCULUS* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVulkanSwapchainCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPerformanceMetricsStateMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPerformanceMetricsCounterMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceListSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceListSaveInfoFB* value = wrapper->decoded_value;

        value->spaces = handle_mapping::MapHandleArray<OpenXrSpaceInfo>(&wrapper->spaces, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceListSaveCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceUserCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemHeadsetIdPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRecommendedLayerResolutionMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrCompositionLayerBaseHeader>(wrapper->layer->GetMetaStructPointer(), 1, object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorLutCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorLutUpdateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapLutMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughColorMapLutMETA* value = wrapper->decoded_value;

        value->colorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->colorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughColorMapInterpolatedLutMETA* value = wrapper->decoded_value;

        value->sourceColorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->sourceColorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);

        value->targetColorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->targetColorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemPassthroughColorLutPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceTriangleMeshGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpaceTriangleMeshMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemFaceTrackingProperties2FB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceTrackerCreateInfo2FB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceExpressionInfo2FB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFaceExpressionWeights2FB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthProviderCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthSwapchainStateMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthImageAcquireInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEnvironmentDepthImageAcquireInfoMETA* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthImageViewMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthImageMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrEnvironmentDepthImageViewMETA>(wrapper->views->GetMetaStructPointer(), wrapper->views->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemEnvironmentDepthPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughMeshTransformInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughMeshTransformInfoHTC* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerPassthroughHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerPassthroughHTC* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->passthrough = handle_mapping::MapHandle<OpenXrPassthroughHTCInfo>(wrapper->passthrough, object_info_table, &CommonObjectInfoTable::GetXrPassthroughHTCInfo);

        MapStructHandles(wrapper->color, object_info_table);
    }
}

void MapStructHandles(Decoded_XrFoveationApplyInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrSwapchainSubImage>(wrapper->subImages->GetMetaStructPointer(), wrapper->subImages->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationDynamicModeInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFoveationCustomModeInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemAnchorPropertiesHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoHTC* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrActiveActionSetPriorityEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActiveActionSetPriorityEXT* value = wrapper->decoded_value;

        value->actionSet = handle_mapping::MapHandle<OpenXrActionSetInfo>(wrapper->actionSet, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);
    }
}

void MapStructHandles(Decoded_XrActiveActionSetPrioritiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrActiveActionSetPriorityEXT>(wrapper->actionSetPriorities->GetMetaStructPointer(), wrapper->actionSetPriorities->GetLength(), object_info_table);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrForceFeedbackCurlApplyLocationsMNDX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingDataSourceInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrHandTrackingDataSourceStateEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemPlaneDetectionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPlaneDetectorBeginInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorGetInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPlaneDetectorGetInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorLocationEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }

        MapStructArrayHandles<Decoded_XrPlaneDetectorLocationEXT>(wrapper->planeLocations->GetMetaStructPointer(), wrapper->planeLocations->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorPolygonBufferEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFutureCancelInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrFutureCancelInfoEXT* value = wrapper->decoded_value;

        value->future = handle_mapping::MapHandle<OpenXrFutureEXTInfo>(wrapper->future, object_info_table, &CommonObjectInfoTable::GetXrFutureEXTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFuturePollInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrFuturePollInfoEXT* value = wrapper->decoded_value;

        value->future = handle_mapping::MapHandle<OpenXrFutureEXTInfo>(wrapper->future, object_info_table, &CommonObjectInfoTable::GetXrFutureEXTInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFutureCompletionEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrFuturePollResultEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataUserPresenceChangedEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataUserPresenceChangedEXT* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSystemUserPresencePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataHeadsetFitChangedML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataEyeCalibrationChangedML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrUserCalibrationEnableEventsInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next, object_info_table);
        }
    }
}

void MapNextStructHandles(OpenXrNextNode* next, const CommonObjectInfoTable& object_info_table)
{
    GFXRECON_ASSERT(next != nullptr);

    void *wrapper = next->GetMetaStructPointer();
    const auto* header = reinterpret_cast<const OpenXrMetaStructHeader*>(next->GetMetaStructPointer());

    switch (*header->type)
    {
    default:
        // TODO: Report or raise fatal error for unrecognized type?
        break;
    case XR_TYPE_ACTION_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrActionCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_SET_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrActionSetCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_SPACE_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrActionSpaceCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_STATE_BOOLEAN:
        MapStructHandles(reinterpret_cast<Decoded_XrActionStateBoolean*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_STATE_FLOAT:
        MapStructHandles(reinterpret_cast<Decoded_XrActionStateFloat*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_STATE_GET_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrActionStateGetInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_STATE_POSE:
        MapStructHandles(reinterpret_cast<Decoded_XrActionStatePose*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTION_STATE_VECTOR2F:
        MapStructHandles(reinterpret_cast<Decoded_XrActionStateVector2f*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTIONS_SYNC_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrActionsSyncInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrActiveActionSetPrioritiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrAndroidSurfaceSwapchainCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_API_LAYER_PROPERTIES:
        MapStructHandles(reinterpret_cast<Decoded_XrApiLayerProperties*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BINDING_MODIFICATIONS_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrBindingModificationsKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrBodyJointLocationsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrBodyJointsLocateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BODY_SKELETON_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrBodySkeletonFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrBodyTrackerCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrBoundSourcesForActionEnumerateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_BOUNDARY_2D_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrBoundary2DFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerAlphaBlendFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerColorScaleBiasKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerCubeKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerCylinderKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerDepthInfoKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerDepthTestFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerDepthTestVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerEquirect2KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerEquirectKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerImageLayoutFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerProjection*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerProjectionView*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_QUAD:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerQuad*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerReprojectionInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSecureContentFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSettingsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSpaceWarpInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrControllerModelKeyStateMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrControllerModelNodePropertiesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrControllerModelNodeStateMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrControllerModelPropertiesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrControllerModelStateMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrCoordinateSpaceCreateInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrDebugUtilsLabelEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrDebugUtilsMessengerCallbackDataEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrDebugUtilsMessengerCreateInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrDebugUtilsObjectNameInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrDevicePcmSampleRateStateFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
        MapStructHandles(reinterpret_cast<Decoded_XrDigitalLensControlALMALENCE*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_HAND_REMOVAL_SET_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_ACQUIRE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthImageAcquireInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthImageMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_IMAGE_VIEW_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthImageViewMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_PROVIDER_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthProviderCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ENVIRONMENT_DEPTH_SWAPCHAIN_STATE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEnvironmentDepthSwapchainStateMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_BUFFER:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataBuffer*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataDisplayRefreshRateChangedFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_EVENTS_LOST:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataEventsLost*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataEyeCalibrationChangedML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataHeadsetFitChangedML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataInstanceLossPending*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataInteractionProfileChanged*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataLocalizationChangedML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataPassthroughStateChangedFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataPerfSettingsEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataReferenceSpaceChangePending*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSceneCaptureCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSessionStateChanged*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceEraseCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceListSaveCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceQueryCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceSaveCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceSetStatusCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpaceShareCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataUserPresenceChangedEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVirtualKeyboardBackspaceMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVirtualKeyboardCommitTextMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVirtualKeyboardEnterMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVirtualKeyboardHiddenMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVirtualKeyboardShownMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataVisibilityMaskChangedKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
        MapStructHandles(reinterpret_cast<Decoded_XrEventDataViveTrackerConnectedHTCX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EXTENSION_PROPERTIES:
        MapStructHandles(reinterpret_cast<Decoded_XrExtensionProperties*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
        MapStructHandles(reinterpret_cast<Decoded_XrExternalCameraOCULUS*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrEyeGazeSampleTimeEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EYE_GAZES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEyeGazesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EYE_GAZES_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEyeGazesInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrEyeTrackerCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceExpressionInfo2FB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_EXPRESSION_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceExpressionInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceExpressionWeights2FB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceExpressionWeightsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceTrackerCreateInfo2FB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFaceTrackerCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrFacialExpressionsHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrFacialTrackerCreateInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
        MapStructHandles(reinterpret_cast<Decoded_XrForceFeedbackCurlApplyLocationsMNDX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveatedViewConfigurationViewVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationApplyInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationCustomModeInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationDynamicModeInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationEyeTrackedStateMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationLevelProfileCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrFoveationProfileCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FRAME_BEGIN_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrFrameBeginInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FRAME_END_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrFrameEndInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FRAME_END_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrFrameEndInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FRAME_STATE:
        MapStructHandles(reinterpret_cast<Decoded_XrFrameState*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FRAME_WAIT_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrFrameWaitInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FUTURE_CANCEL_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrFutureCancelInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FUTURE_COMPLETION_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrFutureCompletionEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FUTURE_POLL_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrFuturePollInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_FUTURE_POLL_RESULT_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrFuturePollResultEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrGeometryInstanceCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrGeometryInstanceTransformFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrGlobalDimmerFrameEndInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingD3D11KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingD3D12KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingEGLMNDX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_METAL_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingMetalKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLESAndroidKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLWaylandKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLWin32KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLXcbKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLXlibKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingVulkanKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsD3D11KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsD3D12KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_METAL_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsMetalKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsOpenGLESKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsOpenGLKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrGraphicsRequirementsVulkanKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandJointLocationsEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandJointVelocitiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandJointsLocateInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandJointsMotionRangeInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_MESH_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandMeshMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandMeshSpaceCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandMeshUpdateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandPoseTypeInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackerCreateInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingAimStateFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingCapsulesStateFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingDataSourceInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingDataSourceStateEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_MESH_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingMeshFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAND_TRACKING_SCALE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHandTrackingScaleFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAPTIC_ACTION_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrHapticActionInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrHapticPcmVibrationFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HAPTIC_VIBRATION:
        MapStructHandles(reinterpret_cast<Decoded_XrHapticVibration*>(wrapper), object_info_table);
        break;
    case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrHolographicWindowAttachmentMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrInputSourceLocalizedNameGetInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INSTANCE_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrInstanceCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrInstanceCreateInfoAndroidKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INSTANCE_PROPERTIES:
        MapStructHandles(reinterpret_cast<Decoded_XrInstanceProperties*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
        MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileAnalogThresholdVALVE*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileDpadBindingEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INTERACTION_PROFILE_STATE:
        MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileState*>(wrapper), object_info_table);
        break;
    case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
        MapStructHandles(reinterpret_cast<Decoded_XrInteractionProfileSuggestedBinding*>(wrapper), object_info_table);
        break;
    case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrKeyboardSpaceCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrKeyboardTrackingQueryFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrLoaderInitInfoAndroidKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrLocalDimmingFrameEndInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrLocalizationEnableEventsInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrLocalizationMapImportInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_LOCALIZATION_MAP_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrLocalizationMapML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMapLocalizationRequestInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorAprilTagInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorArucoInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorCreateInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorCustomProfileInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorSizeInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorSnapshotInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_DETECTOR_STATE_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerDetectorStateML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerSpaceCreateInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrMarkerSpaceCreateInfoVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrNewSceneComputeInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughBrightnessContrastSaturationFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorLutCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorLutUpdateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapInterpolatedLutMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapLutMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapMonoToMonoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapMonoToRgbaFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughCreateInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughKeyboardHandsIntensityFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughLayerCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughMeshTransformInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughPreferencesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PASSTHROUGH_STYLE_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrPassthroughStyleFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPerformanceMetricsCounterMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrPerformanceMetricsStateMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorBeginInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorCreateInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorGetInfoEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorLocationEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorLocationsEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrPlaneDetectorPolygonBufferEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrRecommendedLayerResolutionGetInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
        MapStructHandles(reinterpret_cast<Decoded_XrRecommendedLayerResolutionMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrReferenceSpaceCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RENDER_MODEL_BUFFER_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRenderModelBufferFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRenderModelCapabilitiesRequestFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRenderModelLoadInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRenderModelPathInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRenderModelPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_ROOM_LAYOUT_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrRoomLayoutFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneCaptureRequestInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneComponentLocationsMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneComponentParentFilterInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneComponentsGetInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneComponentsLocateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_COMPONENTS_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneComponentsMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneDeserializeInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMarkerQRCodesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMarkerTypeFilterMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MARKERS_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMarkersMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshBuffersGetInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshBuffersMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshIndicesUint16MSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshIndicesUint32MSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshVertexBufferMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_MESHES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneMeshesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneObjectTypesFilterInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_OBJECTS_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneObjectsMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSceneObserverCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrScenePlaneAlignmentFilterInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SCENE_PLANES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrScenePlanesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationFrameStateMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationStateMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SEMANTIC_LABELS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSemanticLabelsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSemanticLabelsSupportInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSessionActionSetsAttachInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SESSION_BEGIN_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSessionBeginInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SESSION_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSessionCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
        MapStructHandles(reinterpret_cast<Decoded_XrSessionCreateInfoOverlayEXTX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceComponentFilterInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceComponentStatusFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceComponentStatusSetInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_CONTAINER_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceContainerFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_ERASE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceEraseInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceListSaveInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_LOCATION:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceLocation*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_LOCATIONS:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceLocations*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_QUERY_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceQueryInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_QUERY_RESULTS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceQueryResultsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_SAVE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceSaveInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_SHARE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceShareInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceStorageLocationFilterInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceTriangleMeshGetInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_TRIANGLE_MESH_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceTriangleMeshMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceUserCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceUuidFilterInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_VELOCITIES:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceVelocities*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACE_VELOCITY:
        MapStructHandles(reinterpret_cast<Decoded_XrSpaceVelocity*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPACES_LOCATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSpacesLocateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorCreateInfoHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorPersistenceInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_CREATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainCreateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainCreateInfoFoveationFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageAcquireInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageD3D11KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageD3D12KHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageFoveationVulkanFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_METAL_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageMetalKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageOpenGLESKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageOpenGLKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageReleaseInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageVulkanKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageWaitInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainStateFoveationFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainStateSamplerOpenGLESFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSwapchainStateSamplerVulkanFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemAnchorPropertiesHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemBodyTrackingPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemColorSpacePropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_ENVIRONMENT_DEPTH_PROPERTIES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemEnvironmentDepthPropertiesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemEyeGazeInteractionPropertiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemEyeTrackingPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemFaceTrackingProperties2FB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemFaceTrackingPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemFacialTrackingPropertiesHTC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemForceFeedbackCurlPropertiesMNDX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemFoveatedRenderingPropertiesVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemFoveationEyeTrackedPropertiesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_GET_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemGetInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemHandTrackingMeshPropertiesMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemHandTrackingPropertiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemHeadsetIdPropertiesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemKeyboardTrackingPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemMarkerTrackingPropertiesVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemMarkerUnderstandingPropertiesML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemPassthroughColorLutPropertiesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemPassthroughProperties2FB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemPassthroughPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemPlaneDetectionPropertiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_PROPERTIES:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemProperties*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemRenderModelPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemSpaceWarpPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemSpatialEntityPropertiesFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemUserPresencePropertiesEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrSystemVirtualKeyboardPropertiesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
        MapStructHandles(reinterpret_cast<Decoded_XrTriangleMeshCreateInfoFB*>(wrapper), object_info_table);
        break;
    case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
        MapStructHandles(reinterpret_cast<Decoded_XrUserCalibrationEnableEventsInfoML*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW:
        MapStructHandles(reinterpret_cast<Decoded_XrView*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
        MapStructHandles(reinterpret_cast<Decoded_XrViewConfigurationDepthRangeEXT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
        MapStructHandles(reinterpret_cast<Decoded_XrViewConfigurationProperties*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_CONFIGURATION_VIEW:
        MapStructHandles(reinterpret_cast<Decoded_XrViewConfigurationView*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
        MapStructHandles(reinterpret_cast<Decoded_XrViewConfigurationViewFovEPIC*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
        MapStructHandles(reinterpret_cast<Decoded_XrViewLocateFoveatedRenderingVARJO*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_LOCATE_INFO:
        MapStructHandles(reinterpret_cast<Decoded_XrViewLocateInfo*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIEW_STATE:
        MapStructHandles(reinterpret_cast<Decoded_XrViewState*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardAnimationStateMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardInputInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardLocationInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardModelAnimationStatesMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVirtualKeyboardTextureDataMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VISIBILITY_MASK_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrVisibilityMaskKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
        MapStructHandles(reinterpret_cast<Decoded_XrVisualMeshComputeLodInfoMSFT*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
        MapStructHandles(reinterpret_cast<Decoded_XrViveTrackerPathsHTCX*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrVulkanGraphicsDeviceGetInfoKHR*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
        MapStructHandles(reinterpret_cast<Decoded_XrVulkanSwapchainCreateInfoMETA*>(wrapper), object_info_table);
        break;
    case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
        MapStructHandles(reinterpret_cast<Decoded_XrVulkanSwapchainFormatListCreateInfoKHR*>(wrapper), object_info_table);
        break;
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSystemProperties* id_wrapper, const XrSystemProperties* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrSystemIdInfo>(parent_id, id_wrapper->systemId, handle_struct->systemId, object_info_table, &CommonObjectInfoTable::AddXrSystemIdInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceLocation* id_wrapper, const XrSpaceLocation* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrInteractionProfileState* id_wrapper, const XrInteractionProfileState* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrPathInfo>(parent_id, id_wrapper->interactionProfile, handle_struct->interactionProfile, object_info_table, &CommonObjectInfoTable::AddXrPathInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrControllerModelKeyStateMSFT* id_wrapper, const XrControllerModelKeyStateMSFT* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrControllerModelKeyMSFTInfo>(parent_id, id_wrapper->modelKey, handle_struct->modelKey, object_info_table, &CommonObjectInfoTable::AddXrControllerModelKeyMSFTInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrViveTrackerPathsHTCX* id_wrapper, const XrViveTrackerPathsHTCX* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrPathInfo>(parent_id, id_wrapper->persistentPath, handle_struct->persistentPath, object_info_table, &CommonObjectInfoTable::AddXrPathInfo);
        handle_mapping::AddHandle<OpenXrPathInfo>(parent_id, id_wrapper->rolePath, handle_struct->rolePath, object_info_table, &CommonObjectInfoTable::AddXrPathInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPathInfoFB* id_wrapper, const XrRenderModelPathInfoFB* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrPathInfo>(parent_id, id_wrapper->path, handle_struct->path, object_info_table, &CommonObjectInfoTable::AddXrPathInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPropertiesFB* id_wrapper, const XrRenderModelPropertiesFB* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrRenderModelKeyFBInfo>(parent_id, id_wrapper->modelKey, handle_struct->modelKey, object_info_table, &CommonObjectInfoTable::AddXrRenderModelKeyFBInfo);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultsFB* id_wrapper, const XrSpaceQueryResultsFB* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_XrSpaceQueryResultFB>(parent_id, id_wrapper->results->GetMetaStructPointer(), id_wrapper->results->GetLength(), handle_struct->results, static_cast<size_t>(handle_struct->resultCapacityInput), object_info_table);
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultFB* id_wrapper, const XrSpaceQueryResultFB* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrSpaceInfo>(parent_id, id_wrapper->space, handle_struct->space, object_info_table, &CommonObjectInfoTable::AddXrSpaceInfo);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrSystemProperties* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->systemId);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrSpaceLocation* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrInteractionProfileState* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->interactionProfile);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrControllerModelKeyStateMSFT* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->modelKey);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrViveTrackerPathsHTCX* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->persistentPath);
        consumer->PushRecaptureHandleId(&id_wrapper->rolePath);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrRenderModelPathInfoFB* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->path);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrRenderModelPropertiesFB* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->modelKey);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrSpaceQueryResultsFB* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        PushRecaptureStructArrayHandleIds<Decoded_XrSpaceQueryResultFB>(id_wrapper->results->GetMetaStructPointer(), id_wrapper->results->GetLength(), consumer);
    }
}

void PushRecaptureStructHandleIds(const Decoded_XrSpaceQueryResultFB* id_wrapper, CommonConsumerBase* consumer)
{
    GFXRECON_ASSERT(consumer != nullptr);
    if (consumer->IsRecapture() && id_wrapper != nullptr)
    {
        consumer->PushRecaptureHandleId(&id_wrapper->space);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
