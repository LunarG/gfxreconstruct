/*
** Copyright (c) 2019-2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H
#define GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "generated/generated_vulkan_state_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_state_tracker)

// Functions to initialize the object creation data stored by Vulkan handle wrappers. Explicit specialization is used to
// support special cases that require tracking the creation parameters of the wrapped handle and other handles that
// creation depend on (eg. graphics pipeline creation depends on a VkShaderModule, VkPipelineLayout, and VkRenderPass
// handles). These functions are only intended to be used by the VulkanStateTracker class, but must be in namespace
// scope to meet C++ language requirements for explicit template specialization.

// Utility functions for indexing arrays of "create info" structures, with a specialization for the 'void'
// type, which is used with handles that do not have a "create info" structure.
template <typename CreateInfo>
const CreateInfo* GetCreateInfoEntry(uint32_t index, const CreateInfo* create_infos)
{
    return &create_infos[index];
}

template <>
inline const void* GetCreateInfoEntry<void>(uint32_t, const void*)
{
    return nullptr;
}

template <typename ParentHandle, typename Wrapper, typename CreateInfo>
void InitializeState(ParentHandle      parent_handle,
                     Wrapper*          wrapper,
                     const CreateInfo* create_info,
                     format::ApiCallId create_call_id,
                     CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);
    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);
}

template <typename ParentHandle, typename SecondaryHandle, typename Wrapper, typename CreateInfo>
void InitializeGroupObjectState(ParentHandle      parent_handle,
                                SecondaryHandle   secondary_handle,
                                Wrapper*          wrapper,
                                const CreateInfo* create_info,
                                format::ApiCallId create_call_id,
                                CreateParameters  create_parameters)
{
    // The secondary handle is only used by sepcializations.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);
    InitializeState<ParentHandle, Wrapper, CreateInfo>(
        parent_handle, wrapper, create_info, create_call_id, create_parameters);
}

template <>
inline void
InitializeState<VkPhysicalDevice, VulkanDeviceWrapper, VkDeviceCreateInfo>(VkPhysicalDevice          parent_handle,
                                                                           VulkanDeviceWrapper*      wrapper,
                                                                           const VkDeviceCreateInfo* create_info,
                                                                           format::ApiCallId         create_call_id,
                                                                           CreateParameters          create_parameters)
{
    assert(parent_handle != VK_NULL_HANDLE);
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->physical_device = GetWrapper<VulkanPhysicalDeviceWrapper>(parent_handle);
}

template <>
inline void InitializeState<VkDevice, VulkanPipelineLayoutWrapper, VkPipelineLayoutCreateInfo>(
    VkDevice                          parent_handle,
    VulkanPipelineLayoutWrapper*      wrapper,
    const VkPipelineLayoutCreateInfo* create_info,
    format::ApiCallId                 create_call_id,
    CreateParameters                  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies = std::make_shared<PipelineLayoutDependencies>();

    for (uint32_t i = 0; i < create_info->setLayoutCount; ++i)
    {
        if (create_info->pSetLayouts[i] != VK_NULL_HANDLE)
        {
            auto layout_wrapper = GetWrapper<VulkanDescriptorSetLayoutWrapper>(create_info->pSetLayouts[i]);
            CreateDependencyInfo info;
            info.handle_id         = layout_wrapper->handle_id;
            info.create_call_id    = layout_wrapper->create_call_id;
            info.create_parameters = layout_wrapper->create_parameters;

            layout_dependencies->layouts.emplace_back(std::move(info));
        }
    }

    wrapper->layout_dependencies = layout_dependencies;
}

template <>
inline void
InitializeState<VkDevice, VulkanCommandPoolWrapper, VkCommandPoolCreateInfo>(VkDevice                  parent_handle,
                                                                             VulkanCommandPoolWrapper* wrapper,
                                                                             const VkCommandPoolCreateInfo* create_info,
                                                                             format::ApiCallId create_call_id,
                                                                             CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);
    assert(create_info != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->queue_family_index = create_info->queueFamilyIndex;
}

template <>
inline void
InitializeState<VkDevice, VulkanQueryPoolWrapper, VkQueryPoolCreateInfo>(VkDevice                     parent_handle,
                                                                         VulkanQueryPoolWrapper*      wrapper,
                                                                         const VkQueryPoolCreateInfo* create_info,
                                                                         format::ApiCallId            create_call_id,
                                                                         CreateParameters             create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);
    assert(create_info != nullptr);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device      = GetWrapper<VulkanDeviceWrapper>(parent_handle);
    wrapper->query_type  = create_info->queryType;
    wrapper->query_count = create_info->queryCount;
    wrapper->pending_queries.resize(create_info->queryCount);
}

template <>
inline void InitializeState<VkDevice, VulkanFenceWrapper, VkFenceCreateInfo>(VkDevice                 parent_handle,
                                                                             VulkanFenceWrapper*      wrapper,
                                                                             const VkFenceCreateInfo* create_info,
                                                                             format::ApiCallId        create_call_id,
                                                                             CreateParameters         create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->created_signaled = ((create_info->flags & VK_FENCE_CREATE_SIGNALED_BIT) == VK_FENCE_CREATE_SIGNALED_BIT);
    wrapper->device           = GetWrapper<VulkanDeviceWrapper>(parent_handle);
}

template <>
inline void InitializeState<VkDevice, VulkanEventWrapper, VkEventCreateInfo>(VkDevice                 parent_handle,
                                                                             VulkanEventWrapper*      wrapper,
                                                                             const VkEventCreateInfo* create_info,
                                                                             format::ApiCallId        create_call_id,
                                                                             CreateParameters         create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device = GetWrapper<VulkanDeviceWrapper>(parent_handle);
}

template <>
inline void
InitializeState<VkDevice, VulkanPipelineCacheWrapper, VkPipelineCacheCreateInfo>(VkDevice              parent_handle,
                                                                           VulkanPipelineCacheWrapper* wrapper,
                                                                           const VkPipelineCacheCreateInfo* create_info,
                                                                           format::ApiCallId create_call_id,
                                                                           CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device = GetWrapper<VulkanDeviceWrapper>(parent_handle);

    wrapper->create_info = *create_info;
}

template <>
inline void
InitializeState<VkDevice, VulkanSemaphoreWrapper, VkSemaphoreCreateInfo>(VkDevice                     parent_handle,
                                                                         VulkanSemaphoreWrapper*      wrapper,
                                                                         const VkSemaphoreCreateInfo* create_info,
                                                                         format::ApiCallId            create_call_id,
                                                                         CreateParameters             create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device = GetWrapper<VulkanDeviceWrapper>(parent_handle);

    auto next = reinterpret_cast<const VkBaseInStructure*>(create_info->pNext);
    while (next)
    {
        if (next->sType == VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO)
        {
            auto semaphore_type = reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(next);
            wrapper->type       = semaphore_type->semaphoreType;
        }
        next = next->pNext;
    }
}

template <>
inline void
InitializeState<VkDevice, VulkanFramebufferWrapper, VkFramebufferCreateInfo>(VkDevice                  parent_handle,
                                                                             VulkanFramebufferWrapper* wrapper,
                                                                             const VkFramebufferCreateInfo* create_info,
                                                                             format::ApiCallId create_call_id,
                                                                             CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto render_pass_wrapper = GetWrapper<VulkanRenderPassWrapper>(create_info->renderPass);
    assert(render_pass_wrapper != nullptr);
    wrapper->render_pass_id                = render_pass_wrapper->handle_id;
    wrapper->render_pass_create_call_id    = render_pass_wrapper->create_call_id;
    wrapper->render_pass_create_parameters = render_pass_wrapper->create_parameters;

    if (create_info->pAttachments != nullptr)
    {
        for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
        {
            auto image_view_wrapper = GetWrapper<VulkanImageViewWrapper>(create_info->pAttachments[i]);
            assert(image_view_wrapper != nullptr);

            wrapper->image_view_ids.push_back(image_view_wrapper->handle_id);
            wrapper->attachments.push_back(image_view_wrapper->image);
        }
    }
}

template <>
inline void
InitializeState<VkDevice, VulkanRenderPassWrapper, VkRenderPassCreateInfo>(VkDevice                      parent_handle,
                                                                           VulkanRenderPassWrapper*      wrapper,
                                                                           const VkRenderPassCreateInfo* create_info,
                                                                           format::ApiCallId             create_call_id,
                                                                           CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    if (create_info->pAttachments != nullptr)
    {
        for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
        {
            wrapper->attachment_final_layouts.push_back(create_info->pAttachments[i].finalLayout);
        }
    }
}

template <>
inline void
InitializeState<VkDevice, VulkanRenderPassWrapper, VkRenderPassCreateInfo2>(VkDevice                 parent_handle,
                                                                            VulkanRenderPassWrapper* wrapper,
                                                                            const VkRenderPassCreateInfo2* create_info,
                                                                            format::ApiCallId create_call_id,
                                                                            CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    if (create_info->pAttachments != nullptr)
    {
        for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
        {
            wrapper->attachment_final_layouts.push_back(create_info->pAttachments[i].finalLayout);
        }
    }
}

template <>
inline void InitializeGroupObjectState<VkDevice, VkPipelineCache, VulkanPipelineWrapper, VkGraphicsPipelineCreateInfo>(
    VkDevice                            parent_handle,
    VkPipelineCache                     secondary_handle,
    VulkanPipelineWrapper*              wrapper,
    const VkGraphicsPipelineCreateInfo* create_info,
    format::ApiCallId                   create_call_id,
    CreateParameters                    create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    // TODO: Track pipeline cache dependency.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    for (uint32_t i = 0; i < create_info->stageCount; ++i)
    {
        if (create_info->pStages[i].module != VK_NULL_HANDLE)
        {
            auto shader_wrapper = GetWrapper<VulkanShaderModuleWrapper>(create_info->pStages[i].module);
            if (shader_wrapper)
            {
                CreateDependencyInfo info;
                info.handle_id         = shader_wrapper->handle_id;
                info.create_call_id    = shader_wrapper->create_call_id;
                info.create_parameters = shader_wrapper->create_parameters;

                wrapper->shader_module_dependencies.emplace_back(std::move(info));
            }
        }
    }

    auto render_pass_wrapper = GetWrapper<VulkanRenderPassWrapper>(create_info->renderPass);
    if (render_pass_wrapper)
    {
        wrapper->render_pass_dependency.handle_id         = render_pass_wrapper->handle_id;
        wrapper->render_pass_dependency.create_call_id    = render_pass_wrapper->create_call_id;
        wrapper->render_pass_dependency.create_parameters = render_pass_wrapper->create_parameters;
    }

    if (create_info->layout != VK_NULL_HANDLE)
    {
        auto layout_wrapper = GetWrapper<VulkanPipelineLayoutWrapper>(create_info->layout);
        assert(layout_wrapper != nullptr);

        wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
        wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
        wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
        wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
    }
}

template <>
inline void InitializeGroupObjectState<VkDevice, VkPipelineCache, VulkanPipelineWrapper, VkComputePipelineCreateInfo>(
    VkDevice                           parent_handle,
    VkPipelineCache                    secondary_handle,
    VulkanPipelineWrapper*             wrapper,
    const VkComputePipelineCreateInfo* create_info,
    format::ApiCallId                  create_call_id,
    CreateParameters                   create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    // TODO: Track pipeline cache dependency.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto shader_wrapper = GetWrapper<VulkanShaderModuleWrapper>(create_info->stage.module);
    if (shader_wrapper)
    {
        CreateDependencyInfo info;
        info.handle_id         = shader_wrapper->handle_id;
        info.create_call_id    = shader_wrapper->create_call_id;
        info.create_parameters = shader_wrapper->create_parameters;

        wrapper->shader_module_dependencies.emplace_back(std::move(info));
    }
    auto layout_wrapper = GetWrapper<VulkanPipelineLayoutWrapper>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void
InitializeGroupObjectState<VkDevice, VkPipelineCache, VulkanPipelineWrapper, VkRayTracingPipelineCreateInfoNV>(
    VkDevice                                parent_handle,
    VkPipelineCache                         secondary_handle,
    VulkanPipelineWrapper*                  wrapper,
    const VkRayTracingPipelineCreateInfoNV* create_info,
    format::ApiCallId                       create_call_id,
    CreateParameters                        create_parameters)
{
    assert(wrapper != nullptr);
    assert((create_info != nullptr) && (create_info->pStages != nullptr));
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    // TODO: Track pipeline cache dependency.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    for (uint32_t i = 0; i < create_info->stageCount; ++i)
    {
        auto shader_wrapper = GetWrapper<VulkanShaderModuleWrapper>(create_info->pStages[i].module);
        if (shader_wrapper)
        {
            CreateDependencyInfo info;
            info.handle_id         = shader_wrapper->handle_id;
            info.create_call_id    = shader_wrapper->create_call_id;
            info.create_parameters = shader_wrapper->create_parameters;

            wrapper->shader_module_dependencies.emplace_back(std::move(info));
        }
    }

    auto layout_wrapper = GetWrapper<VulkanPipelineLayoutWrapper>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void
InitializeGroupObjectState<VkDevice, VkDeferredOperationKHR, VulkanPipelineWrapper, VkRayTracingPipelineCreateInfoKHR>(
    VkDevice                                 parent_handle,
    VkDeferredOperationKHR                   secondary_handle,
    VulkanPipelineWrapper*                   wrapper,
    const VkRayTracingPipelineCreateInfoKHR* create_info,
    format::ApiCallId                        create_call_id,
    CreateParameters                         create_parameters)
{
    assert(wrapper != nullptr);
    assert((create_info != nullptr) && (create_info->pStages != nullptr));
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    // TODO: Track pipeline cache dependency.
    GFXRECON_UNREFERENCED_PARAMETER(secondary_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    for (uint32_t i = 0; i < create_info->stageCount; ++i)
    {
        auto shader_wrapper = GetWrapper<VulkanShaderModuleWrapper>(create_info->pStages[i].module);
        if (shader_wrapper)
        {
            CreateDependencyInfo info;
            info.handle_id         = shader_wrapper->handle_id;
            info.create_call_id    = shader_wrapper->create_call_id;
            info.create_parameters = shader_wrapper->create_parameters;

            wrapper->shader_module_dependencies.emplace_back(std::move(info));
        }
    }

    auto layout_wrapper = GetWrapper<VulkanPipelineLayoutWrapper>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void
InitializeState<VkDevice, VulkanDeviceMemoryWrapper, VkMemoryAllocateInfo>(VkDevice                    parent_handle,
                                                                           VulkanDeviceMemoryWrapper*  wrapper,
                                                                           const VkMemoryAllocateInfo* alloc_info,
                                                                           format::ApiCallId           create_call_id,
                                                                           CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(alloc_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->memory_type_index = alloc_info->memoryTypeIndex;
    wrapper->allocation_size   = alloc_info->allocationSize;
}

template <>
inline void InitializeState<VkDevice, VulkanBufferWrapper, VkBufferCreateInfo>(VkDevice                  parent_handle,
                                                                               VulkanBufferWrapper*      wrapper,
                                                                               const VkBufferCreateInfo* create_info,
                                                                               format::ApiCallId         create_call_id,
                                                                               CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->created_size = create_info->size;

    // TODO: Do we need to track the queue family that the buffer is actually used with?
    if ((create_info->queueFamilyIndexCount > 0) && (create_info->pQueueFamilyIndices != nullptr))
    {
        wrapper->queue_family_index = create_info->pQueueFamilyIndices[0];
    }
}

// Images created with vkCreateImage.
template <>
inline void InitializeState<VkDevice, VulkanImageWrapper, VkImageCreateInfo>(VkDevice                 parent_handle,
                                                                             VulkanImageWrapper*      wrapper,
                                                                             const VkImageCreateInfo* create_info,
                                                                             format::ApiCallId        create_call_id,
                                                                             CreateParameters         create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->image_type   = create_info->imageType;
    wrapper->format       = create_info->format;
    wrapper->extent       = create_info->extent;
    wrapper->mip_levels   = create_info->mipLevels;
    wrapper->array_layers = create_info->arrayLayers;
    wrapper->samples      = create_info->samples;
    wrapper->tiling       = create_info->tiling;

    // TODO: Do we need to track the queue family that the image is actually used with?
    if ((create_info->queueFamilyIndexCount > 0) && (create_info->pQueueFamilyIndices != nullptr))
    {
        wrapper->queue_family_index = create_info->pQueueFamilyIndices[0];
    }
}

template <>
inline void InitializeState<VkDevice, VulkanSwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(
    VkDevice                        parent_handle,
    VulkanSwapchainKHRWrapper*      wrapper,
    const VkSwapchainCreateInfoKHR* create_info,
    format::ApiCallId               create_call_id,
    CreateParameters                create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device        = GetWrapper<VulkanDeviceWrapper>(parent_handle);
    wrapper->surface       = GetWrapper<VulkanSurfaceKHRWrapper>(create_info->surface);
    wrapper->format        = create_info->imageFormat;
    wrapper->extent        = { create_info->imageExtent.width, create_info->imageExtent.height, 0 };
    wrapper->pre_transform = create_info->preTransform;
    wrapper->array_layers  = create_info->imageArrayLayers;

    if ((create_info->queueFamilyIndexCount > 0) && (create_info->pQueueFamilyIndices != nullptr))
    {
        wrapper->queue_family_index = create_info->pQueueFamilyIndices[0];
    }
}

// Swapchain Images retrieved with vkGetSwapchainImagesKHR.
template <>
inline void
InitializeGroupObjectState<VkDevice, VkSwapchainKHR, VulkanImageWrapper, void>(VkDevice            parent_handle,
                                                                               VkSwapchainKHR      swapchain_handle,
                                                                               VulkanImageWrapper* wrapper,
                                                                               const void*         create_info,
                                                                               format::ApiCallId   create_call_id,
                                                                               CreateParameters    create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);
    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto swapchain_wrapper = GetWrapper<VulkanSwapchainKHRWrapper>(swapchain_handle);
    assert(swapchain_wrapper != nullptr);

    wrapper->image_type         = VK_IMAGE_TYPE_2D;
    wrapper->format             = swapchain_wrapper->format;
    wrapper->extent             = swapchain_wrapper->extent;
    wrapper->mip_levels         = 1;
    wrapper->array_layers       = swapchain_wrapper->array_layers;
    wrapper->samples            = VK_SAMPLE_COUNT_1_BIT;
    wrapper->tiling             = VK_IMAGE_TILING_OPTIMAL;
    wrapper->queue_family_index = swapchain_wrapper->queue_family_index;
}

template <>
inline void
InitializeState<VkDevice, VulkanBufferViewWrapper, VkBufferViewCreateInfo>(VkDevice                      parent_handle,
                                                                           VulkanBufferViewWrapper*      wrapper,
                                                                           const VkBufferViewCreateInfo* create_info,
                                                                           format::ApiCallId             create_call_id,
                                                                           CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto buffer        = GetWrapper<VulkanBufferWrapper>(create_info->buffer);
    wrapper->buffer_id = buffer->handle_id;
}

template <>
inline void
InitializeState<VkDevice, VulkanImageViewWrapper, VkImageViewCreateInfo>(VkDevice                     parent_handle,
                                                                         VulkanImageViewWrapper*      wrapper,
                                                                         const VkImageViewCreateInfo* create_info,
                                                                         format::ApiCallId            create_call_id,
                                                                         CreateParameters             create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto image        = GetWrapper<VulkanImageWrapper>(create_info->image);
    wrapper->image_id = image->handle_id;
    wrapper->image    = image;
}

template <>
inline void InitializeState<VkDevice, VulkanDescriptorSetLayoutWrapper, VkDescriptorSetLayoutCreateInfo>(
    VkDevice                               parent_handle,
    VulkanDescriptorSetLayoutWrapper*      wrapper,
    const VkDescriptorSetLayoutCreateInfo* create_info,
    format::ApiCallId                      create_call_id,
    CreateParameters                       create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    if ((create_info->bindingCount > 0) && (create_info->pBindings != nullptr))
    {
        wrapper->binding_info.reserve(create_info->bindingCount);
        for (uint32_t i = 0; i < create_info->bindingCount; ++i)
        {
            const VkDescriptorSetLayoutBinding* binding = &create_info->pBindings[i];

            DescriptorBindingInfo binding_info;
            binding_info.binding_index = binding->binding;
            binding_info.count         = binding->descriptorCount;
            binding_info.type          = binding->descriptorType;

            binding_info.immutable_samplers =
                ((binding->pImmutableSamplers != nullptr) &&
                 ((binding->descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                  (binding->descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER)));

            wrapper->binding_info.emplace_back(std::move(binding_info));
        }
    }
}

inline void InitializePoolObjectState(VkDevice                           parent_handle,
                                      VulkanCommandBufferWrapper*        wrapper,
                                      uint32_t                           alloc_index,
                                      const VkCommandBufferAllocateInfo* alloc_info,
                                      format::ApiCallId                  create_call_id,
                                      CreateParameters                   create_parameters)
{
    assert(wrapper != nullptr);
    assert(alloc_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);
    GFXRECON_UNREFERENCED_PARAMETER(alloc_index);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->level = alloc_info->level;
}

inline void InitializePoolObjectState(VkDevice                           parent_handle,
                                      VulkanDescriptorSetWrapper*        wrapper,
                                      uint32_t                           alloc_index,
                                      const VkDescriptorSetAllocateInfo* alloc_info,
                                      format::ApiCallId                  create_call_id,
                                      CreateParameters                   create_parameters)
{
    assert(wrapper != nullptr);
    assert(alloc_info != nullptr);
    assert(create_parameters != nullptr);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device = GetWrapper<VulkanDeviceWrapper>(parent_handle);

    auto layout_wrapper = GetWrapper<VulkanDescriptorSetLayoutWrapper>(alloc_info->pSetLayouts[alloc_index]);
    assert(layout_wrapper != nullptr);

    // Add a binding entry for each binding described by the descriptor set layout.
    for (const auto& binding_info : layout_wrapper->binding_info)
    {
        DescriptorInfo descriptor_info;
        descriptor_info.type               = binding_info.type;
        descriptor_info.count              = binding_info.count;
        descriptor_info.immutable_samplers = binding_info.immutable_samplers;
        descriptor_info.written            = std::make_unique<bool[]>(binding_info.count);

        std::fill(descriptor_info.written.get(), descriptor_info.written.get() + binding_info.count, false);

        descriptor_info.handle_ids = std::make_unique<format::HandleId[]>(binding_info.count);

        switch (binding_info.type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                descriptor_info.sampler_ids = std::make_unique<format::HandleId[]>(binding_info.count);
                descriptor_info.images      = std::make_unique<VkDescriptorImageInfo[]>(binding_info.count);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                descriptor_info.buffers = std::make_unique<VkDescriptorBufferInfo[]>(binding_info.count);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                descriptor_info.texel_buffer_views = std::make_unique<VkBufferView[]>(binding_info.count);
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                descriptor_info.acceleration_structures =
                    std::make_unique<VkAccelerationStructureKHR[]>(binding_info.count);
                break;
            case VK_DESCRIPTOR_TYPE_MUTABLE_VALVE:
                descriptor_info.sampler_ids        = std::make_unique<format::HandleId[]>(binding_info.count);
                descriptor_info.images             = std::make_unique<VkDescriptorImageInfo[]>(binding_info.count);
                descriptor_info.buffers            = std::make_unique<VkDescriptorBufferInfo[]>(binding_info.count);
                descriptor_info.texel_buffer_views = std::make_unique<VkBufferView[]>(binding_info.count);
                descriptor_info.acceleration_structures =
                    std::make_unique<VkAccelerationStructureKHR[]>(binding_info.count);
                descriptor_info.mutable_type = std::make_unique<VkDescriptorType[]>(binding_info.count);
                std::fill(descriptor_info.mutable_type.get(),
                          descriptor_info.mutable_type.get() + binding_info.count,
                          VK_DESCRIPTOR_TYPE_MUTABLE_VALVE);
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to initialize descriptor state for unrecognized descriptor type");
                break;
        }

        wrapper->bindings.emplace(binding_info.binding_index, std::move(descriptor_info));
    }

    // Track descriptor set layout dependency.
    wrapper->set_layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->set_layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->set_layout_dependency.create_parameters = layout_wrapper->create_parameters;
}

GFXRECON_END_NAMESPACE(vulkan_state_tracker)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H
