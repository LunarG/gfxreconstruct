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

#include "encode/vulkan_state_tracker.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() : object_count_(0) {}

VulkanStateTracker::~VulkanStateTracker() {}

void VulkanStateTracker::TrackCommand(VkCommandBuffer                 command_buffer,
                                      format::ApiCallId               call_id,
                                      const util::MemoryOutputStream* parameter_buffer)
{
    std::unique_lock<std::mutex> lock(mutex_);

    CommandBufferWrapper* wrapper = state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));
    if (wrapper != nullptr)
    {
        if ((call_id == format::ApiCallId::ApiCall_vkBeginCommandBuffer) ||
            (call_id == format::ApiCallId::ApiCall_vkResetCommandBuffer))
        {
            // Clear command data on command buffer reset.
            wrapper->command_data.Reset();
            wrapper->pending_layouts.clear();
        }

        if (call_id != format::ApiCallId::ApiCall_vkResetCommandBuffer)
        {
            // Append the command data.
            size_t size = parameter_buffer->GetDataSize();
            wrapper->command_data.Write(&size, sizeof(size));
            wrapper->command_data.Write(&call_id, sizeof(call_id));
            wrapper->command_data.Write(parameter_buffer->GetData(), size);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to update command state for unrecognized command buffer handle");
    }
}

void VulkanStateTracker::TrackResetCommandPool(VkCommandPool command_pool)
{
    std::unique_lock<std::mutex> lock(mutex_);

    CommandPoolWrapper* wrapper = state_table_.GetCommandPoolWrapper(format::ToHandleId(command_pool));
    if (wrapper != nullptr)
    {
        for (auto entry : wrapper->allocated_buffers)
        {
            entry.second->command_data.Reset();
            entry.second->pending_layouts.clear();
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track command pool reset state for unrecognized command pool handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                                             const VkPhysicalDeviceMemoryProperties* properties)
{
    assert(properties != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    PhysicalDeviceWrapper* wrapper = state_table_.GetPhysicalDeviceWrapper(format::ToHandleId(physical_device));
    if (wrapper != nullptr)
    {
        for (uint32_t i = 0; i < properties->memoryTypeCount; ++i)
        {
            wrapper->memory_types.push_back(properties->memoryTypes[i]);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track memory properties for unrecognized physical device handle");
    }
}

void VulkanStateTracker::TrackBufferMemoryBinding(VkDevice       device,
                                                  VkBuffer       buffer,
                                                  VkDeviceMemory memory,
                                                  VkDeviceSize   memoryOffset)
{
    std::unique_lock<std::mutex> lock(mutex_);

    BufferWrapper* wrapper = state_table_.GetBufferWrapper(format::ToHandleId(buffer));
    if (wrapper != nullptr)
    {
        wrapper->bind_device = device;
        wrapper->bind_memory = memory;
        wrapper->bind_offset = memoryOffset;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track memory binding state for unrecognized buffer handle");
    }
}

void VulkanStateTracker::TrackImageMemoryBinding(VkDevice       device,
                                                 VkImage        image,
                                                 VkDeviceMemory memory,
                                                 VkDeviceSize   memoryOffset)
{
    std::unique_lock<std::mutex> lock(mutex_);

    ImageWrapper* wrapper = state_table_.GetImageWrapper(format::ToHandleId(image));
    if (wrapper != nullptr)
    {
        wrapper->bind_device = device;
        wrapper->bind_memory = memory;
        wrapper->bind_offset = memoryOffset;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track memory binding state for unrecognized image handle");
    }
}

void VulkanStateTracker::TrackMappedMemory(VkDeviceMemory memory,
                                           void*          mapped_data,
                                           VkDeviceSize   mapped_offset,
                                           VkDeviceSize   mapped_size)
{
    std::unique_lock<std::mutex> lock(mutex_);

    DeviceMemoryWrapper* wrapper = state_table_.GetDeviceMemoryWrapper(format::ToHandleId(memory));
    if (wrapper != nullptr)
    {
        wrapper->mapped_data   = mapped_data;
        wrapper->mapped_offset = mapped_offset;
        wrapper->mapped_size   = mapped_size;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track mapped state for unrecognized device memory handle");
    }
}

void VulkanStateTracker::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert(begin_info != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    CommandBufferWrapper* wrapper = state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));
    if (wrapper != nullptr)
    {
        wrapper->active_render_pass      = begin_info->renderPass;
        wrapper->render_pass_framebuffer = begin_info->framebuffer;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track render pass begin state for an unrecognized command buffer handle");
    }
}

void VulkanStateTracker::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    std::unique_lock<std::mutex> lock(mutex_);

    CommandBufferWrapper* wrapper = state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));
    if (wrapper != nullptr)
    {
        assert((wrapper->active_render_pass != VK_NULL_HANDLE) && (wrapper->render_pass_framebuffer != VK_NULL_HANDLE));

        const RenderPassWrapper* render_pass_wrapper =
            state_table_.GetRenderPassWrapper(format::ToHandleId(wrapper->active_render_pass));
        const FramebufferWrapper* framebuffer_wrapper =
            state_table_.GetFramebufferWrapper(format::ToHandleId(wrapper->render_pass_framebuffer));

        if ((framebuffer_wrapper != nullptr) && (render_pass_wrapper != nullptr))
        {
            uint32_t attachment_count = static_cast<uint32_t>(framebuffer_wrapper->attachments.size());

            assert(attachment_count <= render_pass_wrapper->attachment_final_layouts.size());

            for (uint32_t i = 0; i < attachment_count; ++i)
            {
                wrapper->pending_layouts[framebuffer_wrapper->attachments[i]] =
                    render_pass_wrapper->attachment_final_layouts[i];
            }
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Attempting to track render pass end state with unrecognized render pass and/or framebuffer handles");
        }

        // Clear the active render pass state now that the pass has ended.
        wrapper->active_render_pass      = VK_NULL_HANDLE;
        wrapper->render_pass_framebuffer = VK_NULL_HANDLE;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track render pass end state for an unrecognized command buffer handle");
    }
}

void VulkanStateTracker::TrackExecuteCommands(VkCommandBuffer        command_buffer,
                                              uint32_t               command_buffer_count,
                                              const VkCommandBuffer* command_buffers)
{
    std::unique_lock<std::mutex> lock(mutex_);

    CommandBufferWrapper* primary_wrapper = state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));
    if (primary_wrapper != nullptr)
    {
        if (command_buffers != nullptr)
        {
            for (uint32_t i = 0; i < command_buffer_count; ++i)
            {
                CommandBufferWrapper* secondary_wrapper =
                    state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));

                if (secondary_wrapper != nullptr)
                {
                    for (auto layout_entry : secondary_wrapper->pending_layouts)
                    {
                        primary_wrapper->pending_layouts[layout_entry.first] = layout_entry.second;
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING("Attempting to track execute commands state with an unrecognized secondary "
                                         "command buffer handle");
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Attempting to track execute commands state for an unrecognized primary command buffer handle");
    }
}

void VulkanStateTracker::TrackImageBarriers(VkCommandBuffer             command_buffer,
                                            uint32_t                    image_barrier_count,
                                            const VkImageMemoryBarrier* image_barriers)
{
    if ((image_barrier_count > 0) && (image_barriers != nullptr))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        CommandBufferWrapper* wrapper = state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffer));
        if (wrapper != nullptr)
        {
            for (uint32_t i = 0; i < image_barrier_count; ++i)
            {
                wrapper->pending_layouts[image_barriers[i].image] = image_barriers[i].newLayout;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Attempting to track pipeline barrier state for an unrecognized command buffer handle");
        }
    }
}

void VulkanStateTracker::TrackImageLayoutTransitions(uint32_t submit_count, const VkSubmitInfo* submits)
{
    if ((submit_count > 0) && (submits != nullptr) && (submits->commandBufferCount > 0))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        for (uint32_t submit = 0; submit < submit_count; ++submit)
        {
            uint32_t               command_buffer_count = submits[submit].commandBufferCount;
            const VkCommandBuffer* command_buffers      = submits[submit].pCommandBuffers;

            for (uint32_t cmd = 0; cmd < command_buffer_count; ++cmd)
            {
                CommandBufferWrapper* command_wrapper =
                    state_table_.GetCommandBufferWrapper(format::ToHandleId(command_buffers[cmd]));

                if (command_wrapper != nullptr)
                {
                    // Apply pending image layouts.
                    for (auto layout_entry : command_wrapper->pending_layouts)
                    {
                        ImageWrapper* image_wrapper =
                            state_table_.GetImageWrapper(format::ToHandleId(layout_entry.first));

                        if (image_wrapper != nullptr)
                        {
                            image_wrapper->current_layout = layout_entry.second;
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING(
                                "Attempting to track image layout state with an unrecognized image handle");
                        }
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Attempting to track image layout state for an unrecognized command buffer handle");
                }
            }
        }
    }
}

void VulkanStateTracker::TrackUpdateDescriptorSets(uint32_t                    write_count,
                                                   const VkWriteDescriptorSet* writes,
                                                   uint32_t                    copy_count,
                                                   const VkCopyDescriptorSet*  copies)
{
    std::unique_lock<std::mutex> lock(mutex_);

    if (writes != nullptr)
    {
        for (uint32_t i = 0; i < write_count; ++i)
        {
            const VkWriteDescriptorSet* write = &writes[i];
            DescriptorSetWrapper* wrapper     = state_table_.GetDescriptorSetWrapper(format::ToHandleId(write->dstSet));
            if (wrapper != nullptr)
            {
                auto& binding = wrapper->bindings[write->dstBinding];

                bool* written_start = &binding.written[write->dstArrayElement];
                std::fill(written_start, written_start + write->descriptorCount, true);

                switch (write->descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        memcpy(&binding.images[write->dstArrayElement],
                               write->pImageInfo,
                               (sizeof(VkDescriptorImageInfo) * write->descriptorCount));
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        memcpy(&binding.buffers[write->dstArrayElement],
                               write->pBufferInfo,
                               (sizeof(VkDescriptorBufferInfo) * write->descriptorCount));
                        break;
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        memcpy(&binding.texel_buffer_views[write->dstArrayElement],
                               write->pTexelBufferView,
                               (sizeof(VkBufferView) * write->descriptorCount));
                        break;
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                        // TODO
                        break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                        // TODO
                        break;
                    default:
                        GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                        break;
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Attempting to track descriptor write state for unrecognized descriptor set handle");
            }
        }
    }

    if (copies != nullptr)
    {
        for (uint32_t i = 0; i < copy_count; ++i)
        {
            const VkCopyDescriptorSet* copy   = &copies[i];
            DescriptorSetWrapper* src_wrapper = state_table_.GetDescriptorSetWrapper(format::ToHandleId(copy->srcSet));
            DescriptorSetWrapper* dst_wrapper = state_table_.GetDescriptorSetWrapper(format::ToHandleId(copy->dstSet));

            if ((src_wrapper != nullptr) && (dst_wrapper != nullptr))
            {
                auto& src_binding = src_wrapper->bindings[copy->srcBinding];
                auto& dst_binding = dst_wrapper->bindings[copy->dstBinding];

                bool* written_start = &dst_binding.written[copy->dstArrayElement];
                std::fill(written_start, written_start + copy->descriptorCount, true);

                assert(src_binding.type == dst_binding.type);

                if (src_binding.images != nullptr)
                {
                    memcpy(&dst_binding.images[copy->dstArrayElement],
                           &src_binding.images[copy->srcArrayElement],
                           (sizeof(VkDescriptorImageInfo) * copy->descriptorCount));
                }
                else if (src_binding.buffers != nullptr)
                {
                    memcpy(&dst_binding.buffers[copy->dstArrayElement],
                           &src_binding.buffers[copy->srcArrayElement],
                           (sizeof(VkDescriptorBufferInfo) * copy->descriptorCount));
                }
                else
                {
                    memcpy(&dst_binding.texel_buffer_views[copy->dstArrayElement],
                           &src_binding.texel_buffer_views[copy->srcArrayElement],
                           (sizeof(VkBufferView) * copy->descriptorCount));
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Attempting to track descriptor copy state for unrecognized descriptor set handle");
            }
        }
    }
}

void VulkanStateTracker::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet           set,
                                                              const UpdateTemplateInfo* template_info,
                                                              const void*               data)
{
    if ((template_info != nullptr) && (data != nullptr))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        DescriptorSetWrapper* wrapper = state_table_.GetDescriptorSetWrapper(format::ToHandleId(set));
        if (wrapper != nullptr)
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (const auto& entry : template_info->image_info)
            {
                auto& binding = wrapper->bindings[entry.binding];

                bool* written_start = &binding.written[entry.array_element];
                std::fill(written_start, written_start + entry.count, true);

                if (entry.stride == sizeof(VkDescriptorImageInfo))
                {
                    // Structures are tightly packed.
                    memcpy(&binding.images[entry.array_element],
                           (bytes + entry.offset),
                           (sizeof(VkDescriptorImageInfo) * entry.count));
                }
                else
                {
                    // Structures are not tightly packed, so must be copied individually.
                    const uint8_t* src_address = bytes + entry.offset;
                    for (uint32_t i = 0; i < entry.count; ++i)
                    {
                        memcpy(&binding.images[entry.array_element + i], src_address, sizeof(VkDescriptorImageInfo));
                        src_address += entry.stride;
                    }
                }
            }

            for (const auto& entry : template_info->buffer_info)
            {
                auto& binding = wrapper->bindings[entry.binding];

                bool* written_start = &binding.written[entry.array_element];
                std::fill(written_start, written_start + entry.count, true);

                if (entry.stride == sizeof(VkDescriptorBufferInfo))
                {
                    memcpy(&binding.buffers[entry.array_element],
                           (bytes + entry.offset),
                           (sizeof(VkDescriptorBufferInfo) * entry.count));
                }
                else
                {
                    // Structures are not tightly packed, so must be copied individually.
                    const uint8_t* src_address = bytes + entry.offset;
                    for (uint32_t i = 0; i < entry.count; ++i)
                    {
                        memcpy(&binding.images[entry.array_element + i], src_address, sizeof(VkDescriptorBufferInfo));
                        src_address += entry.stride;
                    }
                }
            }

            for (const auto& entry : template_info->texel_buffer_view)
            {
                auto& binding = wrapper->bindings[entry.binding];

                bool* written_start = &binding.written[entry.array_element];
                std::fill(written_start, written_start + entry.count, true);

                if (entry.stride == sizeof(VkBufferView))
                {
                    memcpy(&binding.texel_buffer_views[entry.array_element],
                           (bytes + entry.offset),
                           (sizeof(VkBufferView) * entry.count));
                }
                else
                {
                    // Structures are not tightly packed, so must be copied individually.
                    const uint8_t* src_address = bytes + entry.offset;
                    for (uint32_t i = 0; i < entry.count; ++i)
                    {
                        size_t offset = entry.offset + (entry.stride * i);
                        memcpy(&binding.images[entry.array_element + i], src_address, sizeof(VkBufferView));
                        src_address += entry.stride;
                    }
                }
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Attempting to track descriptor write state for unrecognized descriptor set handle");
        }
    }
}

void VulkanStateTracker::TrackResetDescriptorPool(VkDescriptorPool descriptor_pool)
{
    std::unique_lock<std::mutex> lock(mutex_);

    DescriptorPoolWrapper* wrapper = state_table_.GetDescriptorPoolWrapper(format::ToHandleId(descriptor_pool));
    if (wrapper != nullptr)
    {
        // Process each descriptor set allocated from the pool.
        for (const auto& set_entry : wrapper->allocated_sets)
        {
            DescriptorSetWrapper* set_wrapper = set_entry.second;

            assert(set_wrapper != nullptr);

            // Process each descriptor binding in the current set.
            for (auto& binding_entry : set_wrapper->bindings)
            {
                DescriptorInfo* binding = &binding_entry.second;
                std::fill(binding->written.get(), binding->written.get() + binding->count, false);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track descriptor pool reset state for unrecognized descriptor pool handle");
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(uint32_t           wait_count,
                                                   const VkSemaphore* waits,
                                                   uint32_t           signal_count,
                                                   const VkSemaphore* signals)
{
    if (waits != nullptr)
    {
        for (uint32_t i = 0; i < wait_count; ++i)
        {
            SemaphoreWrapper* wrapper = state_table_.GetSemaphoreWrapper(format::ToHandleId(waits[i]));
            if (wrapper != nullptr)
            {
                wrapper->signaled = false;
            }
            else
            {
                GFXRECON_LOG_WARNING("Attempting to track semaphore signaled state for unrecognized semaphore handle");
            }
        }
    }

    if (signals != nullptr)
    {
        for (uint32_t i = 0; i < signal_count; ++i)
        {
            SemaphoreWrapper* wrapper = state_table_.GetSemaphoreWrapper(format::ToHandleId(signals[i]));
            if (wrapper != nullptr)
            {
                wrapper->signaled = true;
            }
            else
            {
                GFXRECON_LOG_WARNING("Attempting to track semaphore signaled state for unrecognized semaphore handle");
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
