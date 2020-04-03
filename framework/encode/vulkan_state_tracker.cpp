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

#include "encode/vulkan_state_info.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() {}

VulkanStateTracker::~VulkanStateTracker() {}

void VulkanStateTracker::TrackCommandExecution(CommandBufferWrapper*           wrapper,
                                               format::ApiCallId               call_id,
                                               const util::MemoryOutputStream* parameter_buffer)
{
    assert(wrapper != nullptr);

    if ((call_id == format::ApiCallId::ApiCall_vkBeginCommandBuffer) ||
        (call_id == format::ApiCallId::ApiCall_vkResetCommandBuffer))
    {
        // Clear command data on command buffer reset.
        wrapper->command_data.Reset();
        wrapper->pending_layouts.clear();
        wrapper->recorded_queries.clear();

        for (size_t i = 0; i < CommandHandleType::NumHandleTypes; ++i)
        {
            wrapper->command_handles[i].clear();
        }
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

void VulkanStateTracker::TrackResetCommandPool(VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<CommandPoolWrapper*>(command_pool);

    for (const auto& entry : wrapper->child_buffers)
    {
        entry.second->command_data.Reset();
        entry.second->pending_layouts.clear();
        entry.second->recorded_queries.clear();

        for (size_t i = 0; i < CommandHandleType::NumHandleTypes; ++i)
        {
            entry.second->command_handles[i].clear();
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                                             const VkPhysicalDeviceMemoryProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<PhysicalDeviceWrapper*>(physical_device);

    wrapper->memory_properties = *properties;
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                                  uint32_t                       property_count,
                                                                  const VkQueueFamilyProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper                             = reinterpret_cast<PhysicalDeviceWrapper*>(physical_device);
    wrapper->queue_family_properties_call_id = format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties;
    wrapper->queue_family_properties_count   = property_count;
    wrapper->queue_family_properties         = std::make_unique<VkQueueFamilyProperties[]>(property_count);
    memcpy(wrapper->queue_family_properties.get(), properties, property_count);
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties2(format::ApiCallId               call_id,
                                                                   VkPhysicalDevice                physical_device,
                                                                   uint32_t                        property_count,
                                                                   const VkQueueFamilyProperties2* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper                             = reinterpret_cast<PhysicalDeviceWrapper*>(physical_device);
    wrapper->queue_family_properties_call_id = call_id;
    wrapper->queue_family_properties_count   = property_count;
    wrapper->queue_family_properties2        = std::make_unique<VkQueueFamilyProperties2[]>(property_count);
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
                    GFXRECON_LOG_WARNING("Omitting unrecognized pNext structure from queue family properties tracking");
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

void VulkanStateTracker::TrackPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                                           uint32_t         queue_family_index,
                                                           VkSurfaceKHR     surface,
                                                           VkBool32         supported)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto  wrapper             = reinterpret_cast<SurfaceKHRWrapper*>(surface);
    auto& entry               = wrapper->surface_support[GetWrappedId(physical_device)];
    entry[queue_family_index] = supported;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                                VkSurfaceKHR                    surface,
                                                                const VkSurfaceCapabilitiesKHR& capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper                                                 = reinterpret_cast<SurfaceKHRWrapper*>(surface);
    wrapper->surface_capabilities[GetWrappedId(physical_device)] = capabilities;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                                           VkSurfaceKHR              surface,
                                                           uint32_t                  format_count,
                                                           const VkSurfaceFormatKHR* formats)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (formats != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto  wrapper = reinterpret_cast<SurfaceKHRWrapper*>(surface);
    auto& entry   = wrapper->surface_formats[GetWrappedId(physical_device)];
    entry.assign(formats, formats + format_count);
}

void VulkanStateTracker::TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                                VkSurfaceKHR            surface,
                                                                uint32_t                mode_count,
                                                                const VkPresentModeKHR* modes)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (modes != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto  wrapper = reinterpret_cast<SurfaceKHRWrapper*>(surface);
    auto& entry   = wrapper->surface_present_modes[GetWrappedId(physical_device)];
    entry.assign(modes, modes + mode_count);
}

void VulkanStateTracker::TrackBufferMemoryBinding(VkDevice       device,
                                                  VkBuffer       buffer,
                                                  VkDeviceMemory memory,
                                                  VkDeviceSize   memoryOffset)
{
    assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper            = reinterpret_cast<BufferWrapper*>(buffer);
    wrapper->bind_device    = reinterpret_cast<DeviceWrapper*>(device);
    wrapper->bind_memory_id = GetWrappedId(memory);
    wrapper->bind_offset    = memoryOffset;
}

void VulkanStateTracker::TrackImageMemoryBinding(VkDevice       device,
                                                 VkImage        image,
                                                 VkDeviceMemory memory,
                                                 VkDeviceSize   memoryOffset)
{
    assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper            = reinterpret_cast<ImageWrapper*>(image);
    wrapper->bind_device    = reinterpret_cast<DeviceWrapper*>(device);
    wrapper->bind_memory_id = GetWrappedId(memory);
    wrapper->bind_offset    = memoryOffset;
}

void VulkanStateTracker::TrackMappedMemory(VkDevice         device,
                                           VkDeviceMemory   memory,
                                           void*            mapped_data,
                                           VkDeviceSize     mapped_offset,
                                           VkDeviceSize     mapped_size,
                                           VkMemoryMapFlags mapped_flags)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper           = reinterpret_cast<DeviceMemoryWrapper*>(memory);
    wrapper->map_device    = reinterpret_cast<DeviceWrapper*>(device);
    wrapper->mapped_data   = mapped_data;
    wrapper->mapped_offset = mapped_offset;
    wrapper->mapped_size   = mapped_size;
    wrapper->mapped_flags  = mapped_flags;
}

void VulkanStateTracker::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert((command_buffer != VK_NULL_HANDLE) && (begin_info != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper                     = reinterpret_cast<CommandBufferWrapper*>(command_buffer);
    wrapper->active_render_pass      = reinterpret_cast<RenderPassWrapper*>(begin_info->renderPass);
    wrapper->render_pass_framebuffer = reinterpret_cast<FramebufferWrapper*>(begin_info->framebuffer);
}

void VulkanStateTracker::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    assert(command_buffer != VK_NULL_HANDLE);

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<CommandBufferWrapper*>(command_buffer);
    assert((wrapper->active_render_pass != VK_NULL_HANDLE) && (wrapper->render_pass_framebuffer != VK_NULL_HANDLE));

    auto render_pass_wrapper = wrapper->active_render_pass;
    auto framebuffer_wrapper = wrapper->render_pass_framebuffer;
    assert((framebuffer_wrapper != nullptr) && (render_pass_wrapper != nullptr));

    uint32_t attachment_count = static_cast<uint32_t>(framebuffer_wrapper->attachments.size());
    assert(attachment_count <= render_pass_wrapper->attachment_final_layouts.size());

    for (uint32_t i = 0; i < attachment_count; ++i)
    {
        wrapper->pending_layouts[framebuffer_wrapper->attachments[i]] =
            render_pass_wrapper->attachment_final_layouts[i];
    }

    // Clear the active render pass state now that the pass has ended.
    wrapper->active_render_pass      = nullptr;
    wrapper->render_pass_framebuffer = nullptr;
}

void VulkanStateTracker::TrackExecuteCommands(VkCommandBuffer        command_buffer,
                                              uint32_t               command_buffer_count,
                                              const VkCommandBuffer* command_buffers)
{
    assert((command_buffer != VK_NULL_HANDLE) && (command_buffers != nullptr));

    std::unique_lock<std::mutex> lock(mutex_);

    auto primary_wrapper = reinterpret_cast<CommandBufferWrapper*>(command_buffer);

    for (uint32_t i = 0; i < command_buffer_count; ++i)
    {
        auto secondary_wrapper = reinterpret_cast<CommandBufferWrapper*>(command_buffers[i]);
        assert(secondary_wrapper != nullptr);

        for (const auto& layout_entry : secondary_wrapper->pending_layouts)
        {
            primary_wrapper->pending_layouts[layout_entry.first] = layout_entry.second;
        }

        for (const auto& secondary_query_pool_entry : secondary_wrapper->recorded_queries)
        {
            auto& primary_query_pool_info = primary_wrapper->recorded_queries[secondary_query_pool_entry.first];

            for (const auto& secondary_query_entry : secondary_query_pool_entry.second)
            {
                auto& primary_query_info  = primary_query_pool_info[secondary_query_entry.first];
                primary_query_info.active = secondary_query_entry.second.active;

                if (primary_query_info.active)
                {
                    primary_query_info.flags              = secondary_query_entry.second.flags;
                    primary_query_info.query_type_index   = secondary_query_entry.second.query_type_index;
                    primary_query_info.queue_family_index = secondary_query_entry.second.queue_family_index;
                }
            }
        }
    }
}

void VulkanStateTracker::TrackImageBarriers(VkCommandBuffer             command_buffer,
                                            uint32_t                    image_barrier_count,
                                            const VkImageMemoryBarrier* image_barriers)
{
    assert(command_buffer != VK_NULL_HANDLE);

    if ((image_barrier_count > 0) && (image_barriers != nullptr))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        auto wrapper = reinterpret_cast<CommandBufferWrapper*>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper                      = reinterpret_cast<ImageWrapper*>(image_barriers[i].image);
            wrapper->pending_layouts[image_wrapper] = image_barriers[i].newLayout;
        }
    }
}

void VulkanStateTracker::TrackCommandBufferSubmissions(uint32_t submit_count, const VkSubmitInfo* submits)
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
                auto command_wrapper = reinterpret_cast<CommandBufferWrapper*>(command_buffers[cmd]);
                assert(command_wrapper != nullptr);

                // Apply pending image layouts.
                for (const auto& layout_entry : command_wrapper->pending_layouts)
                {
                    auto image_wrapper = reinterpret_cast<ImageWrapper*>(layout_entry.first);
                    assert(image_wrapper != nullptr);

                    image_wrapper->current_layout = layout_entry.second;
                }

                // Apply pending query activations.
                for (const auto& query_pool_entry : command_wrapper->recorded_queries)
                {
                    auto query_pool_wrapper = query_pool_entry.first;
                    assert(query_pool_wrapper != nullptr);

                    for (const auto& query_entry : query_pool_entry.second)
                    {
                        auto& query_info  = query_pool_wrapper->pending_queries[query_entry.first];
                        query_info.active = query_entry.second.active;

                        if (query_info.active)
                        {
                            query_info.flags              = query_entry.second.flags;
                            query_info.query_type_index   = query_entry.second.query_type_index;
                            query_info.queue_family_index = query_entry.second.queue_family_index;
                        }
                    }
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

    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if (writes != nullptr)
    {
        for (uint32_t i = 0; i < write_count; ++i)
        {
            const VkWriteDescriptorSet* write   = &writes[i];
            auto                        wrapper = reinterpret_cast<DescriptorSetWrapper*>(write->dstSet);
            assert(wrapper != nullptr);

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
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] = GetWrappedId(src_info[i].sampler);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        format::HandleId*            dst_image_ids   = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] = GetWrappedId(src_info[i].sampler);
                            dst_image_ids[i]   = GetWrappedId(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] = GetWrappedId(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info       = &binding.buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info       = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] = GetWrappedId(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        format::HandleId*   dst_view_ids = &binding.handle_ids[current_dst_array_element];
                        VkBufferView*       dst_info     = &binding.texel_buffer_views[current_dst_array_element];
                        const VkBufferView* src_info     = &write->pTexelBufferView[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_view_ids[i] = GetWrappedId(src_info[i]);
                            dst_info[i]     = src_info[i];
                        }
                        break;
                    }
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
    }

    if (copies != nullptr)
    {
        for (uint32_t i = 0; i < copy_count; ++i)
        {
            auto copy        = &copies[i];
            auto dst_wrapper = reinterpret_cast<DescriptorSetWrapper*>(copy->dstSet);
            auto src_wrapper = reinterpret_cast<DescriptorSetWrapper*>(copy->srcSet);
            assert((dst_wrapper != nullptr) && (src_wrapper != nullptr));

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

                memcpy(&dst_binding.handle_ids[current_dst_array_element],
                       &src_binding.handle_ids[current_src_array_element],
                       (sizeof(format::HandleId) * current_copies));

                if (src_binding.images != nullptr)
                {
                    memcpy(&dst_binding.sampler_ids[current_dst_array_element],
                           &src_binding.sampler_ids[current_src_array_element],
                           (sizeof(format::HandleId) * current_copies));

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
    }
}

void VulkanStateTracker::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet           set,
                                                              const UpdateTemplateInfo* template_info,
                                                              const void*               data)
{
    assert(set != VK_NULL_HANDLE);

    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if ((template_info != nullptr) && (data != nullptr))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        auto           wrapper = reinterpret_cast<DescriptorSetWrapper*>(set);
        const uint8_t* bytes   = reinterpret_cast<const uint8_t*>(data);

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

                format::HandleId*      dst_sampler_ids = &binding.sampler_ids[current_array_element];
                format::HandleId*      dst_image_ids   = &binding.handle_ids[current_array_element];
                VkDescriptorImageInfo* dst_info        = &binding.images[current_array_element];
                const uint8_t*         src_address     = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto image_info = reinterpret_cast<const VkDescriptorImageInfo*>(src_address);
                    if ((binding.type == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        dst_sampler_ids[i] = GetWrappedId(image_info->sampler);
                    }

                    if (binding.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        dst_image_ids[i] = GetWrappedId(image_info->imageView);
                    }

                    memcpy(&dst_info[i], image_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
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

                format::HandleId*       dst_buffer_ids = &binding.handle_ids[current_array_element];
                VkDescriptorBufferInfo* dst_info       = &binding.buffers[current_array_element];
                const uint8_t*          src_address    = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_info  = reinterpret_cast<const VkDescriptorBufferInfo*>(src_address);
                    dst_buffer_ids[i] = GetWrappedId(buffer_info->buffer);
                    memcpy(&dst_info[i], buffer_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
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

                format::HandleId* dst_view_ids = &binding.handle_ids[current_array_element];
                VkBufferView*     dst_info     = &binding.texel_buffer_views[current_array_element];
                const uint8_t*    src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_view = reinterpret_cast<const VkBufferView*>(src_address);
                    dst_view_ids[i]  = GetWrappedId(*buffer_view);
                    dst_info[i]      = *buffer_view;

                    src_address += entry.stride;
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
}

void VulkanStateTracker::TrackResetDescriptorPool(VkDescriptorPool descriptor_pool)
{
    assert(descriptor_pool != VK_NULL_HANDLE);

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<DescriptorPoolWrapper*>(descriptor_pool);

    // Pool reset implicitly frees descriptor sets, so remove all wrappers from the state tracker.
    for (const auto& set_entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(set_entry.second);
    }
}

void VulkanStateTracker::TrackQueryActivation(
    VkCommandBuffer command_buffer, VkQueryPool query_pool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto                      wrapper              = reinterpret_cast<CommandBufferWrapper*>(command_buffer);
    const CommandPoolWrapper* command_pool_wrapper = wrapper->parent_pool;

    auto& query_pool_info         = wrapper->recorded_queries[reinterpret_cast<QueryPoolWrapper*>(query_pool)];
    auto& query_info              = query_pool_info[query];
    query_info.active             = true;
    query_info.flags              = flags;
    query_info.query_type_index   = index;
    query_info.queue_family_index = command_pool_wrapper->queue_family_index;
}

void VulkanStateTracker::TrackQueryReset(VkCommandBuffer command_buffer,
                                         VkQueryPool     query_pool,
                                         uint32_t        first_query,
                                         uint32_t        query_count)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    std::unique_lock<std::mutex> lock(mutex_);

    auto  wrapper         = reinterpret_cast<CommandBufferWrapper*>(command_buffer);
    auto& query_pool_info = wrapper->recorded_queries[reinterpret_cast<QueryPoolWrapper*>(query_pool)];

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        query_pool_info[i].active = false;
    }
}

void VulkanStateTracker::TrackQueryReset(VkQueryPool query_pool, uint32_t first_query, uint32_t query_count)
{
    assert(query_pool != VK_NULL_HANDLE);

    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<QueryPoolWrapper*>(query_pool);
    assert((first_query + query_count) <= wrapper->pending_queries.size());

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        wrapper->pending_queries[i].active = false;
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(VkSemaphore signal)
{
    if (signal != VK_NULL_HANDLE)
    {
        std::unique_lock<std::mutex> lock(mutex_);

        auto wrapper = reinterpret_cast<SemaphoreWrapper*>(signal);
        assert(wrapper != nullptr);
        wrapper->signaled = true;
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(uint32_t           wait_count,
                                                   const VkSemaphore* waits,
                                                   uint32_t           signal_count,
                                                   const VkSemaphore* signals)
{
    if (((waits != nullptr) && (wait_count > 0)) || ((signals != nullptr) && (signal_count > 0)))
    {
        std::unique_lock<std::mutex> lock(mutex_);

        if (waits != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                auto wrapper = reinterpret_cast<SemaphoreWrapper*>(waits[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signals != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper = reinterpret_cast<SemaphoreWrapper*>(signals[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackAcquireImage(
    uint32_t image_index, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
{
    std::unique_lock<std::mutex> lock(mutex_);

    auto wrapper = reinterpret_cast<SwapchainKHRWrapper*>(swapchain);

    assert((wrapper != nullptr) && (image_index < wrapper->image_acquired_info.size()));

    wrapper->image_acquired_info[image_index].is_acquired           = true;
    wrapper->image_acquired_info[image_index].acquired_device_mask  = deviceMask;
    wrapper->image_acquired_info[image_index].acquired_semaphore_id = GetWrappedId(semaphore);
    wrapper->image_acquired_info[image_index].acquired_fence_id     = GetWrappedId(fence);
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
        auto     wrapper     = reinterpret_cast<SwapchainKHRWrapper*>(swapchains[i]);
        uint32_t image_index = image_indices[i];

        assert((wrapper != nullptr) && (image_index < wrapper->image_acquired_info.size()));

        wrapper->last_presented_image                                  = image_index;
        wrapper->image_acquired_info[image_index].is_acquired          = false;
        wrapper->image_acquired_info[image_index].last_presented_queue = queue;
    }
}

void VulkanStateTracker::DestroyState(InstanceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Physical devices are not explicitly destroyed, so need to be removed from the state tracker when their parent
    // instance is destroyed.
    for (const auto physical_device_entry : wrapper->child_physical_devices)
    {
        for (const auto display_entry : physical_device_entry->child_displays)
        {
            for (const auto display_mode_entry : display_entry->child_display_modes)
            {
                state_table_.RemoveWrapper(display_mode_entry);
            }

            state_table_.RemoveWrapper(display_entry);
        }

        state_table_.RemoveWrapper(physical_device_entry);
    }
}

void VulkanStateTracker::DestroyState(DeviceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Queues are not explicitly destroyed, so need to be removed from the state tracker when their parent device is
    // destroyed.
    for (const auto& entry : wrapper->child_queues)
    {
        state_table_.RemoveWrapper(entry);
    }
}

void VulkanStateTracker::DestroyState(CommandPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    for (const auto& entry : wrapper->child_buffers)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(DescriptorPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    for (const auto& entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(SwapchainKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Swapchain images are not explicitly destroyed, so need to be removed from state tracking when the parent
    // swapchain is destroyed.
    for (auto entry : wrapper->child_images)
    {
        state_table_.RemoveWrapper(entry);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
