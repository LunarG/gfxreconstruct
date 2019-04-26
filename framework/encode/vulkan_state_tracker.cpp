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

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                                  uint32_t                       property_count,
                                                                  const VkQueueFamilyProperties* properties)
{
    assert(properties != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    PhysicalDeviceWrapper* wrapper = state_table_.GetPhysicalDeviceWrapper(format::ToHandleId(physical_device));
    if (wrapper != nullptr)
    {
        wrapper->queue_family_properties_call_id = format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties;

        wrapper->queue_family_properties_count = property_count;
        wrapper->queue_family_properties       = std::make_unique<VkQueueFamilyProperties[]>(property_count);
        memcpy(wrapper->queue_family_properties.get(), properties, property_count);
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track queue family properties for unrecognized physical device handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties2(format::ApiCallId               call_id,
                                                                   VkPhysicalDevice                physical_device,
                                                                   uint32_t                        property_count,
                                                                   const VkQueueFamilyProperties2* properties)
{
    assert(properties != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    PhysicalDeviceWrapper* wrapper = state_table_.GetPhysicalDeviceWrapper(format::ToHandleId(physical_device));
    if (wrapper != nullptr)
    {
        wrapper->queue_family_properties_call_id = call_id;

        wrapper->queue_family_properties_count = property_count;
        wrapper->queue_family_properties2      = std::make_unique<VkQueueFamilyProperties2[]>(property_count);
        memcpy(wrapper->queue_family_properties2.get(), properties, property_count);

        // Copy pNext structure and update pNext pointers.
        for (uint32_t i = 0; i < property_count; ++i)
        {
            if (properties[i].pNext != nullptr)
            {
                const VkBaseOutStructure* next = reinterpret_cast<const VkBaseOutStructure*>(properties[i].pNext);
                if (next->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV)
                {
                    const VkQueueFamilyCheckpointPropertiesNV* original =
                        reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(next);

                    std::unique_ptr<VkQueueFamilyCheckpointPropertiesNV> copy =
                        std::make_unique<VkQueueFamilyCheckpointPropertiesNV>(*original);

                    if (copy->pNext != nullptr)
                    {
                        // At time of implementation, only VkQueueFamilyCheckpointPropertiesNV was allowed.
                        copy->pNext = nullptr;
                        GFXRECON_LOG_WARNING(
                            "Omitting unrecognized pNext structure from queue family properties tracking");
                    }

                    wrapper->queue_family_properties2[i].pNext = copy.get();
                    wrapper->queue_family_checkpoint_properties.push_back(std::move(copy));
                }
                else
                {
                    // At time of implementation, only VkQueueFamilyCheckpointPropertiesNV was allowed.
                    wrapper->queue_family_properties2[i].pNext = nullptr;
                    GFXRECON_LOG_WARNING("Omitting unrecognized pNext structure from queue family properties tracking");
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track queue family properties for unrecognized physical device handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                                           uint32_t         queue_family_index,
                                                           VkSurfaceKHR     surface,
                                                           VkBool32         supported)
{
    std::unique_lock<std::mutex> lock(mutex_);

    SurfaceKHRWrapper* wrapper = state_table_.GetSurfaceKHRWrapper(format::ToHandleId(surface));
    if (wrapper != nullptr)
    {
        auto& entry               = wrapper->surface_support[physical_device];
        entry[queue_family_index] = supported;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track surface support state for unrecognized surface handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                                VkSurfaceKHR                    surface,
                                                                const VkSurfaceCapabilitiesKHR& capabilities)
{
    std::unique_lock<std::mutex> lock(mutex_);

    SurfaceKHRWrapper* wrapper = state_table_.GetSurfaceKHRWrapper(format::ToHandleId(surface));
    if (wrapper != nullptr)
    {
        wrapper->surface_capabilities[physical_device] = capabilities;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track surface capability state for unrecognized surface handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                                           VkSurfaceKHR              surface,
                                                           uint32_t                  format_count,
                                                           const VkSurfaceFormatKHR* formats)
{
    assert(formats != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    SurfaceKHRWrapper* wrapper = state_table_.GetSurfaceKHRWrapper(format::ToHandleId(surface));
    if (wrapper != nullptr)
    {
        auto& entry = wrapper->surface_formats[physical_device];
        entry.assign(formats, formats + format_count);
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track surface format support state for unrecognized surface handle");
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                                VkSurfaceKHR            surface,
                                                                uint32_t                mode_count,
                                                                const VkPresentModeKHR* modes)
{
    assert(modes != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    SurfaceKHRWrapper* wrapper = state_table_.GetSurfaceKHRWrapper(format::ToHandleId(surface));
    if (wrapper != nullptr)
    {
        auto& entry = wrapper->surface_present_modes[physical_device];
        entry.assign(modes, modes + mode_count);
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track surface capability state for unrecognized surface handle");
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

void VulkanStateTracker::TrackMappedMemory(VkDevice         device,
                                           VkDeviceMemory   memory,
                                           void*            mapped_data,
                                           VkDeviceSize     mapped_offset,
                                           VkDeviceSize     mapped_size,
                                           VkMemoryMapFlags mapped_flags)
{
    std::unique_lock<std::mutex> lock(mutex_);

    DeviceMemoryWrapper* wrapper = state_table_.GetDeviceMemoryWrapper(format::ToHandleId(memory));
    if (wrapper != nullptr)
    {
        wrapper->map_device    = device;
        wrapper->mapped_data   = mapped_data;
        wrapper->mapped_offset = mapped_offset;
        wrapper->mapped_size   = mapped_size;
        wrapper->mapped_flags  = mapped_flags;
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
                // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
                // will result in updates to consecutive bindings, where the next binding is dstBinding+1 and
                // starting from array element 0.  Track the current count, binding, and array element to handle
                // consecutive updates.
                uint32_t current_count             = write->descriptorCount;
                uint32_t current_binding           = write->dstBinding;
                uint32_t current_dst_array_element = write->dstArrayElement;
                uint32_t current_src_array_element = 0;

                for (;;)
                {
                    auto& binding = wrapper->bindings[current_binding];

                    // Update current and write counts for binding's descriptor count. If current count is
                    // greater than the count for the descriptor range defined by dstArrayElement through binding count,
                    // consecutive bindings are being updated.
                    uint32_t current_writes = std::min(current_count, (binding.count - current_dst_array_element));

                    bool* written_start = &binding.written[current_dst_array_element];
                    std::fill(written_start, written_start + current_writes, true);

                    switch (write->descriptorType)
                    {
                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                            memcpy(&binding.images[current_dst_array_element],
                                   &write->pImageInfo[current_src_array_element],
                                   (sizeof(VkDescriptorImageInfo) * current_writes));
                            break;
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                            memcpy(&binding.buffers[current_dst_array_element],
                                   &write->pBufferInfo[current_src_array_element],
                                   (sizeof(VkDescriptorBufferInfo) * current_writes));
                            break;
                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                            memcpy(&binding.texel_buffer_views[current_dst_array_element],
                                   &write->pTexelBufferView[current_src_array_element],
                                   (sizeof(VkBufferView) * current_writes));
                            break;
                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                            // TODO
                            break;
                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                            // TODO
                            break;
                        default:
                            GFXRECON_LOG_WARNING(
                                "Attempting to track descriptor state for unrecognized descriptor type");
                            break;
                    }

                    // Check for consecutive update.
                    if (current_count == current_writes)
                    {
                        break;
                    }
                    else
                    {
                        current_count -= current_writes;
                        current_binding += 1;
                        current_dst_array_element = 0;
                        current_src_array_element += current_writes;
                    }
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
            DescriptorSetWrapper* dst_wrapper = state_table_.GetDescriptorSetWrapper(format::ToHandleId(copy->dstSet));
            DescriptorSetWrapper* src_wrapper = state_table_.GetDescriptorSetWrapper(format::ToHandleId(copy->srcSet));

            if ((dst_wrapper != nullptr) && (src_wrapper != nullptr))
            {
                // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
                // will result in updates to/from consecutive bindings.
                uint32_t current_count             = copy->descriptorCount;
                uint32_t current_dst_binding       = copy->dstBinding;
                uint32_t current_src_binding       = copy->srcBinding;
                uint32_t current_dst_array_element = copy->dstArrayElement;
                uint32_t current_src_array_element = copy->srcArrayElement;

                for (;;)
                {
                    auto& dst_binding = dst_wrapper->bindings[current_dst_binding];
                    auto& src_binding = src_wrapper->bindings[current_src_binding];

                    assert(src_binding.type == dst_binding.type);

                    // Check available counts for consecutive updates.
                    uint32_t dst_copy_count = dst_binding.count - current_dst_array_element;
                    uint32_t src_copy_count = src_binding.count - current_src_array_element;
                    uint32_t current_copies = std::min(current_count, std::min(dst_copy_count, src_copy_count));

                    bool* written_start = &dst_binding.written[current_dst_array_element];
                    std::fill(written_start, written_start + current_copies, true);

                    if (src_binding.images != nullptr)
                    {
                        memcpy(&dst_binding.images[current_dst_array_element],
                               &src_binding.images[current_src_array_element],
                               (sizeof(VkDescriptorImageInfo) * current_copies));
                    }
                    else if (src_binding.buffers != nullptr)
                    {
                        memcpy(&dst_binding.buffers[current_dst_array_element],
                               &src_binding.buffers[current_src_array_element],
                               (sizeof(VkDescriptorBufferInfo) * current_copies));
                    }
                    else
                    {
                        memcpy(&dst_binding.texel_buffer_views[current_dst_array_element],
                               &src_binding.texel_buffer_views[current_src_array_element],
                               (sizeof(VkBufferView) * current_copies));
                    }

                    // Check for consecutive update.
                    if (current_count == current_copies)
                    {
                        break;
                    }
                    else
                    {
                        current_count -= current_copies;

                        if (dst_copy_count == src_copy_count)
                        {
                            // Both bindings must increment.
                            current_dst_binding += 1;
                            current_src_binding += 1;
                            current_dst_array_element = 0;
                            current_src_array_element = 0;
                        }
                        else if (dst_copy_count < src_copy_count)
                        {
                            // Only the destination binding must increment.
                            current_dst_binding += 1;
                            current_dst_array_element = 0;
                            current_src_array_element += current_copies;
                        }
                        else
                        {
                            // Only the source binding must increment.
                            current_src_binding += 1;
                            current_src_array_element = 0;
                            current_dst_array_element += current_copies;
                        }
                    }
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
                // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
                // will result in updates to consecutive bindings.
                uint32_t current_count         = entry.count;
                uint32_t current_binding       = entry.binding;
                uint32_t current_array_element = entry.array_element;
                size_t   current_offset        = entry.offset;

                for (;;)
                {
                    auto& binding = wrapper->bindings[current_binding];

                    assert(binding.images != nullptr);

                    // Check count for consecutive updates.
                    uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                    bool* written_start = &binding.written[current_array_element];
                    std::fill(written_start, written_start + current_writes, true);

                    if (entry.stride == sizeof(VkDescriptorImageInfo))
                    {
                        // Structures are tightly packed.
                        memcpy(&binding.images[current_array_element],
                               (bytes + current_offset),
                               (sizeof(VkDescriptorImageInfo) * current_writes));
                    }
                    else
                    {
                        // Structures are not tightly packed, so must be copied individually.
                        const uint8_t* src_address = bytes + current_offset;
                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            memcpy(
                                &binding.images[current_array_element + i], src_address, sizeof(VkDescriptorImageInfo));
                            src_address += entry.stride;
                        }
                    }

                    // Check for consecutive update.
                    if (current_count == current_writes)
                    {
                        break;
                    }
                    else
                    {
                        current_count -= current_writes;
                        current_binding += 1;
                        current_array_element = 0;
                        current_offset += (current_writes * entry.stride);
                    }
                }
            }

            for (const auto& entry : template_info->buffer_info)
            {
                // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
                // will result in updates to consecutive bindings.
                uint32_t current_count         = entry.count;
                uint32_t current_binding       = entry.binding;
                uint32_t current_array_element = entry.array_element;
                size_t   current_offset        = entry.offset;

                for (;;)
                {
                    auto& binding = wrapper->bindings[current_binding];

                    assert(binding.buffers != nullptr);

                    // Check count for consecutive updates.
                    uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                    bool* written_start = &binding.written[current_array_element];
                    std::fill(written_start, written_start + current_writes, true);

                    if (entry.stride == sizeof(VkDescriptorBufferInfo))
                    {
                        memcpy(&binding.buffers[current_array_element],
                               (bytes + current_offset),
                               (sizeof(VkDescriptorBufferInfo) * current_writes));
                    }
                    else
                    {
                        // Structures are not tightly packed, so must be copied individually.
                        const uint8_t* src_address = bytes + current_offset;
                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            memcpy(&binding.buffers[current_array_element + i],
                                   src_address,
                                   sizeof(VkDescriptorBufferInfo));
                            src_address += entry.stride;
                        }
                    }

                    // Check for consecutive update.
                    if (current_count == current_writes)
                    {
                        break;
                    }
                    else
                    {
                        current_count -= current_writes;
                        current_binding += 1;
                        current_array_element = 0;
                        current_offset += (current_writes * entry.stride);
                    }
                }
            }

            for (const auto& entry : template_info->texel_buffer_view)
            {
                // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
                // will result in updates to consecutive bindings.
                uint32_t current_count         = entry.count;
                uint32_t current_binding       = entry.binding;
                uint32_t current_array_element = entry.array_element;
                size_t   current_offset        = entry.offset;

                for (;;)
                {
                    auto& binding = wrapper->bindings[current_binding];

                    assert(binding.texel_buffer_views != nullptr);

                    // Check count for consecutive updates.
                    uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                    bool* written_start = &binding.written[current_array_element];
                    std::fill(written_start, written_start + current_writes, true);

                    if (entry.stride == sizeof(VkBufferView))
                    {
                        memcpy(&binding.texel_buffer_views[current_array_element],
                               (bytes + current_offset),
                               (sizeof(VkBufferView) * current_writes));
                    }
                    else
                    {
                        // Structures are not tightly packed, so must be copied individually.
                        const uint8_t* src_address = bytes + current_offset;
                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            memcpy(&binding.texel_buffer_views[current_array_element + i],
                                   src_address,
                                   sizeof(VkBufferView));
                            src_address += entry.stride;
                        }
                    }

                    // Check for consecutive update.
                    if (current_count == current_writes)
                    {
                        break;
                    }
                    else
                    {
                        current_count -= current_writes;
                        current_binding += 1;
                        current_array_element = 0;
                        current_offset += (current_writes * entry.stride);
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
        // Pool reset implicitly frees descriptor sets, so remove all wrappers for sets allocated from the pool..
        for (const auto& set_entry : wrapper->allocated_sets)
        {
            DescriptorSetWrapper* set_wrapper = nullptr;
            state_table_.RemoveWrapper(format::ToHandleId(set_entry.first), &set_wrapper);

            assert((set_wrapper != nullptr) && (set_wrapper == set_entry.second));

            delete set_wrapper;
        }
        wrapper->allocated_sets.clear();
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track descriptor pool reset state for unrecognized descriptor pool handle");
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(uint32_t                       wait_count,
                                                   const VkSemaphore*             waits,
                                                   uint32_t                       signal_count,
                                                   const VkSemaphore*             signals,
                                                   SemaphoreWrapper::SignalSource signal_source)
{
    if (((waits != nullptr) && (wait_count > 0)) || ((signals != nullptr) && (signal_count > 0)))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        if (waits != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                SemaphoreWrapper* wrapper = state_table_.GetSemaphoreWrapper(format::ToHandleId(waits[i]));
                if (wrapper != nullptr)
                {
                    wrapper->signaled = SemaphoreWrapper::SignalSourceNone;
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Attempting to track semaphore signaled state for unrecognized semaphore handle");
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
                    wrapper->signaled = signal_source;
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Attempting to track semaphore signaled state for unrecognized semaphore handle");
                }
            }
        }
    }
}

void VulkanStateTracker::TrackAcquireImage(uint32_t       image_index,
                                           VkSwapchainKHR swapchain,
                                           VkSemaphore    semaphore,
                                           VkFence        fence)
{
    std::unique_lock<std::mutex> lock(mutex_);

    SwapchainKHRWrapper* wrapper = state_table_.GetSwapchainKHRWrapper(format::ToHandleId(swapchain));
    if (wrapper != nullptr)
    {
        wrapper->image_acquired_info[image_index].is_acquired        = true;
        wrapper->image_acquired_info[image_index].acquired_semaphore = semaphore;
        wrapper->image_acquired_info[image_index].acquired_fence     = fence;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track swapchain image acquire state for unrecognized swapchain handle");
    }
}

void VulkanStateTracker::TrackPresentedImages(uint32_t              count,
                                              const VkSwapchainKHR* swapchains,
                                              const uint32_t*       image_indices,
                                              VkQueue               queue)
{
    assert((count > 0) && (swapchains != nullptr) && (image_indices != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    for (uint32_t i = 0; i < count; ++i)
    {
        SwapchainKHRWrapper* wrapper = state_table_.GetSwapchainKHRWrapper(format::ToHandleId(swapchains[i]));
        if (wrapper != nullptr)
        {
            uint32_t image_index                                           = image_indices[i];
            wrapper->last_presented_image                                  = image_index;
            wrapper->image_acquired_info[image_index].is_acquired          = false;
            wrapper->image_acquired_info[image_index].last_presented_queue = queue;
        }
        else
        {
            GFXRECON_LOG_WARNING("Attempting to track swapchain image present state for unrecognized swapchain handle");
        }
    }
}

void VulkanStateTracker::DestroyState(DeviceWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Queues are not explicitly destroyed, so queue wrappers need to be destroyed when the device wrapper is
        // destroyed.
        for (const auto& entry : wrapper->queues)
        {
            QueueWrapper* queue_wrapper = nullptr;
            state_table_.RemoveWrapper(format::ToHandleId(entry.first), &queue_wrapper);

            assert(queue_wrapper == entry.second);

            if (queue_wrapper != nullptr)
            {
                delete queue_wrapper;
            }
        }
    }
}

void VulkanStateTracker::DestroyState(CommandPoolWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Destroying the pool implicitly destroys objects allocated from the pool.
        for (const auto& entry : wrapper->allocated_buffers)
        {
            CommandBufferWrapper* buffer_wrapper = nullptr;
            state_table_.RemoveWrapper(format::ToHandleId(entry.first), &buffer_wrapper);

            assert(buffer_wrapper == entry.second);

            if (buffer_wrapper != nullptr)
            {
                delete buffer_wrapper;
            }
        }
    }
}

void VulkanStateTracker::DestroyState(CommandBufferWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Remove the wrapper from the parent pool wrapper.
        CommandPoolWrapper* pool_wrapper = wrapper->pool;
        assert(pool_wrapper != nullptr);

        pool_wrapper->allocated_buffers.erase(wrapper->handle);
    }
}

void VulkanStateTracker::DestroyState(DescriptorPoolWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Destroying the pool implicitly destroys objects allocated from the pool.
        for (const auto& entry : wrapper->allocated_sets)
        {
            DescriptorSetWrapper* set_wrapper = nullptr;
            state_table_.RemoveWrapper(format::ToHandleId(entry.first), &set_wrapper);

            assert(set_wrapper == entry.second);

            if (set_wrapper != nullptr)
            {
                delete set_wrapper;
            }
        }
    }
}

void VulkanStateTracker::DestroyState(DescriptorSetWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Remove the wrapper from the parent pool wrapper.
        DescriptorPoolWrapper* pool_wrapper = wrapper->pool;
        assert(pool_wrapper != nullptr);

        pool_wrapper->allocated_sets.erase(wrapper->handle);
    }
}

void VulkanStateTracker::DestroyState(SwapchainKHRWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        // Swapchain images are not explicitly destroyed, so swapchain image wrappers need to be destroyed when the
        // swapchain wrapper is destroyed.
        for (auto entry : wrapper->images)
        {
            assert(entry != nullptr);

            ImageWrapper* image_wrapper = nullptr;
            state_table_.RemoveWrapper(format::ToHandleId(entry->handle), &image_wrapper);

            assert(image_wrapper == entry);

            delete image_wrapper;
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
