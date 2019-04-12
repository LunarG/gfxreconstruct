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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
