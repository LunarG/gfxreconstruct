/*
** Copyright (c) 2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H
#define GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H

#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_table.h"
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
inline void InitializeState<VkPhysicalDevice, DeviceWrapper, VkDeviceCreateInfo>(VkPhysicalDevice parent_handle,
                                                                                 DeviceWrapper*   wrapper,
                                                                                 const VkDeviceCreateInfo* create_info,
                                                                                 format::ApiCallId create_call_id,
                                                                                 CreateParameters  create_parameters)
{
    assert(parent_handle != VK_NULL_HANDLE);
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->physical_device = reinterpret_cast<PhysicalDeviceWrapper*>(parent_handle);
}

template <>
inline void InitializeState<VkDevice, PipelineLayoutWrapper, VkPipelineLayoutCreateInfo>(
    VkDevice                          parent_handle,
    PipelineLayoutWrapper*            wrapper,
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
        assert(create_info->pSetLayouts[i] != VK_NULL_HANDLE);

        auto layout_wrapper = reinterpret_cast<DescriptorSetLayoutWrapper*>(create_info->pSetLayouts[i]);
        CreateDependencyInfo info;
        info.handle_id         = layout_wrapper->handle_id;
        info.create_call_id    = layout_wrapper->create_call_id;
        info.create_parameters = layout_wrapper->create_parameters;

        layout_dependencies->layouts.emplace_back(std::move(info));
    }

    wrapper->layout_dependencies = layout_dependencies;
}

template <>
inline void
InitializeState<VkDevice, CommandPoolWrapper, VkCommandPoolCreateInfo>(VkDevice                       parent_handle,
                                                                       CommandPoolWrapper*            wrapper,
                                                                       const VkCommandPoolCreateInfo* create_info,
                                                                       format::ApiCallId              create_call_id,
                                                                       CreateParameters               create_parameters)
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
inline void InitializeState<VkDevice, QueryPoolWrapper, VkQueryPoolCreateInfo>(VkDevice          parent_handle,
                                                                               QueryPoolWrapper* wrapper,
                                                                               const VkQueryPoolCreateInfo* create_info,
                                                                               format::ApiCallId create_call_id,
                                                                               CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);
    assert(create_info != nullptr);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device      = reinterpret_cast<DeviceWrapper*>(parent_handle);
    wrapper->query_type  = create_info->queryType;
    wrapper->query_count = create_info->queryCount;
    wrapper->pending_queries.resize(create_info->queryCount);
}

template <>
inline void InitializeState<VkDevice, FenceWrapper, VkFenceCreateInfo>(VkDevice                 parent_handle,
                                                                       FenceWrapper*            wrapper,
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
    wrapper->device           = reinterpret_cast<DeviceWrapper*>(parent_handle);
}

template <>
inline void InitializeState<VkDevice, EventWrapper, VkEventCreateInfo>(VkDevice                 parent_handle,
                                                                       EventWrapper*            wrapper,
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

    wrapper->device = reinterpret_cast<DeviceWrapper*>(parent_handle);
}

template <>
inline void InitializeState<VkDevice, SemaphoreWrapper, VkSemaphoreCreateInfo>(VkDevice          parent_handle,
                                                                               SemaphoreWrapper* wrapper,
                                                                               const VkSemaphoreCreateInfo* create_info,
                                                                               format::ApiCallId create_call_id,
                                                                               CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device = reinterpret_cast<DeviceWrapper*>(parent_handle);
}

template <>
inline void
InitializeState<VkDevice, FramebufferWrapper, VkFramebufferCreateInfo>(VkDevice                       parent_handle,
                                                                       FramebufferWrapper*            wrapper,
                                                                       const VkFramebufferCreateInfo* create_info,
                                                                       format::ApiCallId              create_call_id,
                                                                       CreateParameters               create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto render_pass_wrapper = reinterpret_cast<RenderPassWrapper*>(create_info->renderPass);
    assert(render_pass_wrapper != nullptr);
    wrapper->render_pass_id                = render_pass_wrapper->handle_id;
    wrapper->render_pass_create_call_id    = render_pass_wrapper->create_call_id;
    wrapper->render_pass_create_parameters = render_pass_wrapper->create_parameters;

    if (create_info->pAttachments != nullptr)
    {
        for (uint32_t i = 0; i < create_info->attachmentCount; ++i)
        {
            auto image_view_wrapper = reinterpret_cast<ImageViewWrapper*>(create_info->pAttachments[i]);
            assert(image_view_wrapper != nullptr);

            wrapper->image_view_ids.push_back(image_view_wrapper->handle_id);
            wrapper->attachments.push_back(image_view_wrapper->image);
        }
    }
}

template <>
inline void
InitializeState<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo>(VkDevice                      parent_handle,
                                                                     RenderPassWrapper*            wrapper,
                                                                     const VkRenderPassCreateInfo* create_info,
                                                                     format::ApiCallId             create_call_id,
                                                                     CreateParameters              create_parameters)
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
inline void InitializeGroupObjectState<VkDevice, VkPipelineCache, PipelineWrapper, VkGraphicsPipelineCreateInfo>(
    VkDevice                            parent_handle,
    VkPipelineCache                     secondary_handle,
    PipelineWrapper*                    wrapper,
    const VkGraphicsPipelineCreateInfo* create_info,
    format::ApiCallId                   create_call_id,
    CreateParameters                    create_parameters)
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
        auto shader_wrapper = reinterpret_cast<ShaderModuleWrapper*>(create_info->pStages[i].module);
        assert(shader_wrapper != nullptr);

        CreateDependencyInfo info;
        info.handle_id         = shader_wrapper->handle_id;
        info.create_call_id    = shader_wrapper->create_call_id;
        info.create_parameters = shader_wrapper->create_parameters;

        wrapper->shader_module_dependencies.emplace_back(std::move(info));
    }

    auto render_pass_wrapper = reinterpret_cast<RenderPassWrapper*>(create_info->renderPass);
    assert(render_pass_wrapper != nullptr);

    wrapper->render_pass_dependency.handle_id         = render_pass_wrapper->handle_id;
    wrapper->render_pass_dependency.create_call_id    = render_pass_wrapper->create_call_id;
    wrapper->render_pass_dependency.create_parameters = render_pass_wrapper->create_parameters;

    auto layout_wrapper = reinterpret_cast<PipelineLayoutWrapper*>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void InitializeGroupObjectState<VkDevice, VkPipelineCache, PipelineWrapper, VkComputePipelineCreateInfo>(
    VkDevice                           parent_handle,
    VkPipelineCache                    secondary_handle,
    PipelineWrapper*                   wrapper,
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

    auto shader_wrapper = reinterpret_cast<ShaderModuleWrapper*>(create_info->stage.module);
    assert(shader_wrapper != nullptr);

    CreateDependencyInfo info;
    info.handle_id         = shader_wrapper->handle_id;
    info.create_call_id    = shader_wrapper->create_call_id;
    info.create_parameters = shader_wrapper->create_parameters;

    wrapper->shader_module_dependencies.emplace_back(std::move(info));

    auto layout_wrapper = reinterpret_cast<PipelineLayoutWrapper*>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void InitializeGroupObjectState<VkDevice, VkPipelineCache, PipelineWrapper, VkRayTracingPipelineCreateInfoNV>(
    VkDevice                                parent_handle,
    VkPipelineCache                         secondary_handle,
    PipelineWrapper*                        wrapper,
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
        auto shader_wrapper = reinterpret_cast<ShaderModuleWrapper*>(create_info->pStages[i].module);
        assert(shader_wrapper != nullptr);

        CreateDependencyInfo info;
        info.handle_id         = shader_wrapper->handle_id;
        info.create_call_id    = shader_wrapper->create_call_id;
        info.create_parameters = shader_wrapper->create_parameters;

        wrapper->shader_module_dependencies.emplace_back(std::move(info));
    }

    auto layout_wrapper = reinterpret_cast<PipelineLayoutWrapper*>(create_info->layout);
    assert(layout_wrapper != nullptr);

    wrapper->layout_dependency.handle_id         = layout_wrapper->handle_id;
    wrapper->layout_dependency.create_call_id    = layout_wrapper->create_call_id;
    wrapper->layout_dependency.create_parameters = layout_wrapper->create_parameters;
    wrapper->layout_dependencies                 = layout_wrapper->layout_dependencies;
}

template <>
inline void InitializeState<VkDevice, DeviceMemoryWrapper, VkMemoryAllocateInfo>(VkDevice             parent_handle,
                                                                                 DeviceMemoryWrapper* wrapper,
                                                                                 const VkMemoryAllocateInfo* alloc_info,
                                                                                 format::ApiCallId create_call_id,
                                                                                 CreateParameters  create_parameters)
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
inline void InitializeState<VkDevice, BufferWrapper, VkBufferCreateInfo>(VkDevice                  parent_handle,
                                                                         BufferWrapper*            wrapper,
                                                                         const VkBufferCreateInfo* create_info,
                                                                         format::ApiCallId         create_call_id,
                                                                         CreateParameters          create_parameters)
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
inline void InitializeState<VkDevice, ImageWrapper, VkImageCreateInfo>(VkDevice                 parent_handle,
                                                                       ImageWrapper*            wrapper,
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
inline void
InitializeState<VkDevice, SwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(VkDevice                        parent_handle,
                                                                         SwapchainKHRWrapper*            wrapper,
                                                                         const VkSwapchainCreateInfoKHR* create_info,
                                                                         format::ApiCallId               create_call_id,
                                                                         CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    wrapper->device        = reinterpret_cast<DeviceWrapper*>(parent_handle);
    wrapper->surface       = reinterpret_cast<SurfaceKHRWrapper*>(create_info->surface);
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
inline void InitializeGroupObjectState<VkDevice, VkSwapchainKHR, ImageWrapper, void>(VkDevice          parent_handle,
                                                                                     VkSwapchainKHR    swapchain_handle,
                                                                                     ImageWrapper*     wrapper,
                                                                                     const void*       create_info,
                                                                                     format::ApiCallId create_call_id,
                                                                                     CreateParameters create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);
    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto swapchain_wrapper = reinterpret_cast<SwapchainKHRWrapper*>(swapchain_handle);
    assert(swapchain_wrapper != nullptr);

    wrapper->image_type         = VK_IMAGE_TYPE_2D;
    wrapper->format             = swapchain_wrapper->format;
    wrapper->extent             = swapchain_wrapper->extent;
    wrapper->mip_levels         = 1;
    wrapper->array_layers       = swapchain_wrapper->array_layers;
    wrapper->samples            = VK_SAMPLE_COUNT_1_BIT;
    wrapper->tiling             = VK_IMAGE_TILING_OPTIMAL;
    wrapper->queue_family_index = swapchain_wrapper->queue_family_index;

    swapchain_wrapper->image_acquired_info.emplace_back(ImageAcquiredInfo{});
}

template <>
inline void
InitializeState<VkDevice, BufferViewWrapper, VkBufferViewCreateInfo>(VkDevice                      parent_handle,
                                                                     BufferViewWrapper*            wrapper,
                                                                     const VkBufferViewCreateInfo* create_info,
                                                                     format::ApiCallId             create_call_id,
                                                                     CreateParameters              create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto buffer        = reinterpret_cast<BufferWrapper*>(create_info->buffer);
    wrapper->buffer_id = buffer->handle_id;
}

template <>
inline void InitializeState<VkDevice, ImageViewWrapper, VkImageViewCreateInfo>(VkDevice          parent_handle,
                                                                               ImageViewWrapper* wrapper,
                                                                               const VkImageViewCreateInfo* create_info,
                                                                               format::ApiCallId create_call_id,
                                                                               CreateParameters  create_parameters)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(parent_handle);

    wrapper->create_call_id    = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    auto image        = reinterpret_cast<ImageWrapper*>(create_info->image);
    wrapper->image_id = image->handle_id;
    wrapper->image    = image;
}

template <>
inline void InitializeState<VkDevice, DescriptorSetLayoutWrapper, VkDescriptorSetLayoutCreateInfo>(
    VkDevice                               parent_handle,
    DescriptorSetLayoutWrapper*            wrapper,
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

            wrapper->binding_info.emplace_back(std::move(binding_info));
        }
    }
}

inline void InitializePoolObjectState(VkDevice                           parent_handle,
                                      CommandBufferWrapper*              wrapper,
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
                                      DescriptorSetWrapper*              wrapper,
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

    wrapper->device = reinterpret_cast<DeviceWrapper*>(parent_handle);

    auto layout_wrapper = reinterpret_cast<DescriptorSetLayoutWrapper*>(alloc_info->pSetLayouts[alloc_index]);
    assert(layout_wrapper != nullptr);

    // Add a binding entry for each binding described by the descriptor set layout.
    for (const auto& binding_info : layout_wrapper->binding_info)
    {
        DescriptorInfo descriptor_info;
        descriptor_info.type    = binding_info.type;
        descriptor_info.count   = binding_info.count;
        descriptor_info.written = std::make_unique<bool[]>(binding_info.count);

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
