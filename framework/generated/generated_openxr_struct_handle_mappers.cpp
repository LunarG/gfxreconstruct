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

#include "generated/generated_openxr_struct_handle_mappers.h"
#include "decode/custom_openxr_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/openxr_handle_mapping_util.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_openxr_struct_handle_mappers.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_XrSystemProperties* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSystemProperties* value = wrapper->decoded_value;

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);
    }
}

void MapStructHandles(Decoded_XrSessionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSessionCreateInfo* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);
    }
}

void MapStructHandles(Decoded_XrActionSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionSpaceCreateInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
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
            case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
                MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughHTC*>(wrapper),
                                 object_info_table);
                // Return here because we processed the appropriate data in
                // the correct structure type
                return;
        }

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
    }
}

void MapStructHandles(Decoded_XrActionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionCreateInfo* value = wrapper->decoded_value;

        value->subactionPaths = handle_mapping::MapHandleArray<OpenXrPathInfo>(&wrapper->subactionPaths, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
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
    }
}

void MapStructHandles(Decoded_XrSessionActionSetsAttachInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSessionActionSetsAttachInfo* value = wrapper->decoded_value;

        value->actionSets = handle_mapping::MapHandleArray<OpenXrActionSetInfo>(&wrapper->actionSets, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);
    }
}

void MapStructHandles(Decoded_XrInteractionProfileState* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileState* value = wrapper->decoded_value;

        value->interactionProfile = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->interactionProfile, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrActionStateGetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrActionStateGetInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
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
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
    }
}

void MapStructHandles(Decoded_XrInputSourceLocalizedNameGetInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInputSourceLocalizedNameGetInfo* value = wrapper->decoded_value;

        value->sourcePath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->sourcePath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrHapticActionInfo* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrHapticActionInfo* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->subactionPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->subactionPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
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
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
    }
}

void MapStructHandles(Decoded_XrCompositionLayerQuad* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerQuad* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrEventDataSessionStateChanged* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSessionStateChanged* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataReferenceSpaceChangePending* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataReferenceSpaceChangePending* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataInteractionProfileChanged* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataInteractionProfileChanged* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerCubeKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerCubeKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->swapchain = handle_mapping::MapHandle<OpenXrSwapchainInfo>(wrapper->swapchain, object_info_table, &CommonObjectInfoTable::GetXrSwapchainInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerDepthInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerCylinderKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerCylinderKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerEquirectKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerEquirectKHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGraphicsBindingVulkanKHR* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->instance = handle_mapping::MapHandle<VulkanInstanceInfo>(wrapper->instance, object_info_table, &CommonObjectInfoTable::GetVkInstanceInfo);

        value->physicalDevice = handle_mapping::MapHandle<VulkanPhysicalDeviceInfo>(wrapper->physicalDevice, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);

        value->device = handle_mapping::MapHandle<VulkanDeviceInfo>(wrapper->device, object_info_table, &CommonObjectInfoTable::GetVkDeviceInfo);
    }
}

void MapStructHandles(Decoded_XrSwapchainImageVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainImageVulkanKHR* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVisibilityMaskChangedKHR* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
    }
}

void MapStructHandles(Decoded_XrCompositionLayerEquirect2KHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerEquirect2KHR* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        MapStructHandles(wrapper->subImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrSessionCreateInfoOverlayEXTX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoMSFT* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorSpaceCreateInfoMSFT* value = wrapper->decoded_value;

        value->anchor = handle_mapping::MapHandle<OpenXrSpatialAnchorMSFTInfo>(wrapper->anchor, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerImageLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerAlphaBlendFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGraphicsBindingEGLMNDX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrHandJointsLocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrHandJointsLocateInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructPtrArrayHandles<Decoded_XrCompositionLayerBaseHeader*>(wrapper->layers->GetMetaStructPointer(), wrapper->layers->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_XrSecondaryViewConfigurationLayerInfoMSFT>(wrapper->viewConfigurationLayersInfo->GetMetaStructPointer(), wrapper->viewConfigurationLayersInfo->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrControllerModelKeyStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrControllerModelKeyStateMSFT* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrControllerModelKeyMSFTInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrControllerModelKeyMSFTInfo);
    }
}

void MapStructHandles(Decoded_XrHolographicWindowAttachmentMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSecureContentFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrBodyJointsLocateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrBodyJointsLocateInfoFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrInteractionProfileDpadBindingEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileDpadBindingEXT* value = wrapper->decoded_value;

        value->binding = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->binding, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        value->actionSet = handle_mapping::MapHandle<OpenXrActionSetInfo>(wrapper->actionSet, object_info_table, &CommonObjectInfoTable::GetXrActionSetInfo);
    }
}

void MapStructHandles(Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrInteractionProfileAnalogThresholdVALVE* value = wrapper->decoded_value;

        value->action = handle_mapping::MapHandle<OpenXrActionInfo>(wrapper->action, object_info_table, &CommonObjectInfoTable::GetXrActionInfo);

        value->binding = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->binding, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
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
    }
}

void MapStructHandles(Decoded_XrSceneComponentsLocateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSceneComponentsLocateInfoMSFT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrViveTrackerPathsHTCX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrViveTrackerPathsHTCX* value = wrapper->decoded_value;

        value->persistentPath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->persistentPath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);

        value->rolePath = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->rolePath, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrViveTrackerPathsHTCX>(wrapper->paths->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpatialAnchorCreateCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceSetStatusCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSwapchainStateFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainStateFoveationFB* value = wrapper->decoded_value;

        value->profile = handle_mapping::MapHandle<OpenXrFoveationProfileFBInfo>(wrapper->profile, object_info_table, &CommonObjectInfoTable::GetXrFoveationProfileFBInfo);
    }
}

void MapStructHandles(Decoded_XrPassthroughLayerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughLayerCreateInfoFB* value = wrapper->decoded_value;

        value->passthrough = handle_mapping::MapHandle<OpenXrPassthroughFBInfo>(wrapper->passthrough, object_info_table, &CommonObjectInfoTable::GetXrPassthroughFBInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerPassthroughFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerPassthroughFB* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->layerHandle = handle_mapping::MapHandle<OpenXrPassthroughLayerFBInfo>(wrapper->layerHandle, object_info_table, &CommonObjectInfoTable::GetXrPassthroughLayerFBInfo);
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
    }
}

void MapStructHandles(Decoded_XrGeometryInstanceTransformFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrGeometryInstanceTransformFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrPassthroughStyleFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrRenderModelPathInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelPathInfoFB* value = wrapper->decoded_value;

        value->path = handle_mapping::MapHandle<OpenXrPathInfo>(wrapper->path, object_info_table, &CommonObjectInfoTable::GetXrPathInfo);
    }
}

void MapStructHandles(Decoded_XrRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelPropertiesFB* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrRenderModelKeyFBInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrRenderModelKeyFBInfo);
    }
}

void MapStructHandles(Decoded_XrRenderModelLoadInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrRenderModelLoadInfoFB* value = wrapper->decoded_value;

        value->modelKey = handle_mapping::MapHandle<OpenXrRenderModelKeyFBInfo>(wrapper->modelKey, object_info_table, &CommonObjectInfoTable::GetXrRenderModelKeyFBInfo);
    }
}

void MapStructHandles(Decoded_XrFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrGlobalDimmerFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
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
    }
}

void MapStructHandles(Decoded_XrEventDataLocalizationChangedML* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataLocalizationChangedML* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorPersistenceInfoMSFT* value = wrapper->decoded_value;

        value->spatialAnchor = handle_mapping::MapHandle<OpenXrSpatialAnchorMSFTInfo>(wrapper->spatialAnchor, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorMSFTInfo);
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value = wrapper->decoded_value;

        value->spatialAnchorStore = handle_mapping::MapHandle<OpenXrSpatialAnchorStoreConnectionMSFTInfo>(wrapper->spatialAnchorStore, object_info_table, &CommonObjectInfoTable::GetXrSpatialAnchorStoreConnectionMSFTInfo);
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
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceQueryResultsAvailableFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceQueryCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceQueryCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceSaveInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceEraseInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceEraseInfoFB* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceSaveCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceEraseCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceEraseCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrSwapchainImageFoveationVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSwapchainImageFoveationVulkanFB* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->image = handle_mapping::MapHandle<VulkanImageInfo>(wrapper->image, object_info_table, &CommonObjectInfoTable::GetVkImageInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceShareInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceShareInfoFB* value = wrapper->decoded_value;

        value->spaces = handle_mapping::MapHandleArray<OpenXrSpaceInfo>(&wrapper->spaces, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->users = handle_mapping::MapHandleArray<OpenXrSpaceUserFBInfo>(&wrapper->users, object_info_table, &CommonObjectInfoTable::GetXrSpaceUserFBInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceShareCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceShareCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        MapStructHandles(wrapper->motionVectorSubImage, object_info_table);

        MapStructHandles(wrapper->depthSubImage, object_info_table);
    }
}

void MapStructHandles(Decoded_XrEventDataSceneCaptureCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSceneCaptureCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    }
}

void MapStructHandles(Decoded_XrEyeGazesInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEyeGazesInfoFB* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerSettingsFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrCompositionLayerDepthTestFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardSpaceCreateInfoMETA* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardLocationInfoMETA* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrVirtualKeyboardInputInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVirtualKeyboardInputInfoMETA* value = wrapper->decoded_value;

        value->inputSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->inputSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardCommitTextMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardBackspaceMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardEnterMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardShownMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataVirtualKeyboardHiddenMETA* value = wrapper->decoded_value;

        value->keyboard = handle_mapping::MapHandle<OpenXrVirtualKeyboardMETAInfo>(wrapper->keyboard, object_info_table, &CommonObjectInfoTable::GetXrVirtualKeyboardMETAInfo);
    }
}

void MapStructHandles(Decoded_XrSpaceListSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpaceListSaveInfoFB* value = wrapper->decoded_value;

        value->spaces = handle_mapping::MapHandleArray<OpenXrSpaceInfo>(&wrapper->spaces, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataSpaceListSaveCompleteFB* value = wrapper->decoded_value;

        value->requestId = handle_mapping::MapHandle<OpenXrAsyncRequestIdFBInfo>(wrapper->requestId, object_info_table, &CommonObjectInfoTable::GetXrAsyncRequestIdFBInfo);
    }
}

void MapStructHandles(Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrCompositionLayerBaseHeader>(wrapper->layer->GetMetaStructPointer(), 1, object_info_table);
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapLutMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughColorMapLutMETA* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->colorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->colorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);
    }
}

void MapStructHandles(Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughColorMapInterpolatedLutMETA* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->sourceColorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->sourceColorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);

        value->targetColorLut = handle_mapping::MapHandle<OpenXrPassthroughColorLutMETAInfo>(wrapper->targetColorLut, object_info_table, &CommonObjectInfoTable::GetXrPassthroughColorLutMETAInfo);
    }
}

void MapStructHandles(Decoded_XrPassthroughMeshTransformInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPassthroughMeshTransformInfoHTC* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrCompositionLayerPassthroughHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrCompositionLayerPassthroughHTC* value = wrapper->decoded_value;

        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);

        value->passthrough = handle_mapping::MapHandle<OpenXrPassthroughHTCInfo>(wrapper->passthrough, object_info_table, &CommonObjectInfoTable::GetXrPassthroughHTCInfo);
    }
}

void MapStructHandles(Decoded_XrFoveationApplyInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_XrSwapchainSubImage>(wrapper->subImages->GetMetaStructPointer(), wrapper->subImages->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrSpatialAnchorCreateInfoHTC* value = wrapper->decoded_value;

        value->space = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->space, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
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
        if (wrapper->next)
        {
            MapNextStructHandles(wrapper->next->GetPointer(), wrapper->next->GetMetaStructPointer(), object_info_table);
        }

        MapStructArrayHandles<Decoded_XrActiveActionSetPriorityEXT>(wrapper->actionSetPriorities->GetMetaStructPointer(), wrapper->actionSetPriorities->GetLength(), object_info_table);
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPlaneDetectorBeginInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrPlaneDetectorGetInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrPlaneDetectorGetInfoEXT* value = wrapper->decoded_value;

        value->baseSpace = handle_mapping::MapHandle<OpenXrSpaceInfo>(wrapper->baseSpace, object_info_table, &CommonObjectInfoTable::GetXrSpaceInfo);
    }
}

void MapStructHandles(Decoded_XrEventDataUserPresenceChangedEXT* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrEventDataUserPresenceChangedEXT* value = wrapper->decoded_value;

        value->session = handle_mapping::MapHandle<OpenXrSessionInfo>(wrapper->session, object_info_table, &CommonObjectInfoTable::GetXrSessionInfo);
    }
}

void MapNextStructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((value != nullptr) && (wrapper != nullptr))
    {
        const XrBaseInStructure* base = reinterpret_cast<const XrBaseInStructure*>(value);

        switch (base->type)
        {
        default:
            // TODO: Report or raise fatal error for unrecongized type?
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerDepthInfoKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLWin32KHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLXlibKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLXcbKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLWaylandKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingOpenGLESAndroidKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingVulkanKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingD3D11KHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingD3D12KHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerColorScaleBiasKHR*>(wrapper), object_info_table);
            break;
        case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            MapStructHandles(reinterpret_cast<Decoded_XrSessionCreateInfoOverlayEXTX*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerImageLayoutFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerAlphaBlendFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            MapStructHandles(reinterpret_cast<Decoded_XrGraphicsBindingEGLMNDX*>(wrapper), object_info_table);
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            MapStructHandles(reinterpret_cast<Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT*>(wrapper), object_info_table);
            break;
        case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            MapStructHandles(reinterpret_cast<Decoded_XrHolographicWindowAttachmentMSFT*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSecureContentFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerPassthroughFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapMonoToRgbaFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapMonoToMonoFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughBrightnessContrastSaturationFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_FRAME_END_INFO_ML:
            MapStructHandles(reinterpret_cast<Decoded_XrFrameEndInfoML*>(wrapper), object_info_table);
            break;
        case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            MapStructHandles(reinterpret_cast<Decoded_XrGlobalDimmerFrameEndInfoML*>(wrapper), object_info_table);
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrSwapchainImageFoveationVulkanFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSpaceWarpInfoFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerSettingsFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            MapStructHandles(reinterpret_cast<Decoded_XrCompositionLayerDepthTestFB*>(wrapper), object_info_table);
            break;
        case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            MapStructHandles(reinterpret_cast<Decoded_XrLocalDimmingFrameEndInfoMETA*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapLutMETA*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughColorMapInterpolatedLutMETA*>(wrapper), object_info_table);
            break;
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            MapStructHandles(reinterpret_cast<Decoded_XrPassthroughMeshTransformInfoHTC*>(wrapper), object_info_table);
            break;
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            MapStructHandles(reinterpret_cast<Decoded_XrActiveActionSetPrioritiesEXT*>(wrapper), object_info_table);
            break;
        }
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSystemProperties* id_wrapper, const XrSystemProperties* handle_struct, CommonObjectInfoTable* object_info_table)
{
    if (id_wrapper != nullptr)
    {
        handle_mapping::AddHandle<OpenXrSystemIdInfo>(parent_id, id_wrapper->systemId, handle_struct->systemId, object_info_table, &CommonObjectInfoTable::AddXrSystemIdInfo);
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
