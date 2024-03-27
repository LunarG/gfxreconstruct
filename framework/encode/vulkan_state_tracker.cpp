/*
** Copyright (c) 2019 LunarG, Inc.
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

#include "encode/vulkan_state_tracker.h"

#include "encode/vulkan_state_info.h"
#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "generated/generated_vulkan_struct_trackers.h"
#include "graphics/vulkan_util.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() {}

VulkanStateTracker::~VulkanStateTracker() {}

void VulkanStateTracker::TrackCommandExecution(vulkan_wrappers::CommandBufferWrapper* wrapper,
                                               format::ApiCallId                      call_id,
                                               const util::MemoryOutputStream*        parameter_buffer)
{
    assert(wrapper != nullptr);

    if ((call_id == format::ApiCallId::ApiCall_vkBeginCommandBuffer) ||
        (call_id == format::ApiCallId::ApiCall_vkResetCommandBuffer))
    {
        // Clear command data on command buffer reset.
        wrapper->command_data.Reset();
        wrapper->pending_layouts.clear();
        wrapper->recorded_queries.clear();
        wrapper->tlas_build_info_map.clear();

        for (size_t i = 0; i < vulkan_state_info::CommandHandleType::NumHandleTypes; ++i)
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

void VulkanStateTracker::TrackTrimCommandPool(VkDevice device, VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    auto wrapper               = GetVulkanWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);
    wrapper->trim_command_pool = true;

    auto device_wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->device     = device_wrapper;
}

void VulkanStateTracker::TrackResetCommandPool(VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);

    for (const auto& entry : wrapper->child_buffers)
    {
        entry.second->command_data.Reset();
        entry.second->pending_layouts.clear();
        entry.second->recorded_queries.clear();
        entry.second->tlas_build_info_map.clear();

        for (size_t i = 0; i < vulkan_state_info::CommandHandleType::NumHandleTypes; ++i)
        {
            entry.second->command_handles[i].clear();
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                                             const VkPhysicalDeviceMemoryProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);

    wrapper->memory_properties = *properties;
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                                  uint32_t                       property_count,
                                                                  const VkQueueFamilyProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
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

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
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

    auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry = wrapper->surface_support[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];
    entry[queue_family_index] = supported;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                                VkSurfaceKHR                    surface,
                                                                const VkSurfaceCapabilitiesKHR* capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (capabilities != nullptr));

    auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper->surface_capabilities[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];

    entry.surface_info_pnext_memory.Reset();
    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface;

    entry.surface_capabilities_pnext_memory.Reset();
    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = *capabilities;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice                       physical_device,
                                                                 const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                                 VkSurfaceCapabilities2KHR* surface_capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface_info.surface != VK_NULL_HANDLE));

    auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
    auto& entry =
        wrapper->surface_capabilities[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];

    entry.surface_info_pnext_memory.Reset();
    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface_info.surface;

    if (surface_info.pNext != nullptr)
    {
        entry.surface_info.pNext = TrackStruct(surface_info.pNext, &entry.surface_info_pnext_memory);
    }

    entry.surface_capabilities_pnext_memory.Reset();
    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = surface_capabilities->surfaceCapabilities;

    if (surface_capabilities->pNext != nullptr)
    {
        entry.surface_capabilities.pNext =
            const_cast<void*>(TrackStruct(surface_capabilities->pNext, &entry.surface_capabilities_pnext_memory));
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                                           VkSurfaceKHR              surface,
                                                           uint32_t                  format_count,
                                                           const VkSurfaceFormatKHR* formats)
{
    GFXRECON_ASSERT(physical_device != VK_NULL_HANDLE);

    if (surface != VK_NULL_HANDLE && format_count > 0)
    {
        auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
        auto& entry =
            wrapper->surface_formats[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];

        entry.surface_info_pnext_memory.Reset();
        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface;

        entry.surface_formats.resize(format_count);
        entry.surface_formats_pnext_memory.resize(format_count);
        for (uint32_t i = 0; i < format_count; ++i)
        {
            entry.surface_formats_pnext_memory[i].Reset();
            entry.surface_formats[i].sType         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
            entry.surface_formats[i].pNext         = nullptr;
            entry.surface_formats[i].surfaceFormat = formats[i];
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats2(VkPhysicalDevice                       physical_device,
                                                            const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                            uint32_t                               surface_format_count,
                                                            VkSurfaceFormat2KHR*                   surface_formats)
{
    GFXRECON_ASSERT(physical_device != VK_NULL_HANDLE);

    if (surface_info.surface != VK_NULL_HANDLE && surface_format_count > 0)
    {
        auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
        auto& entry =
            wrapper->surface_formats[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];

        entry.surface_info_pnext_memory.Reset();
        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface_info.surface;

        if (surface_info.pNext != nullptr)
        {
            entry.surface_info.pNext = TrackStruct(surface_info.pNext, &entry.surface_info_pnext_memory);
        }

        entry.surface_formats.resize(surface_format_count);
        entry.surface_formats_pnext_memory.resize(surface_format_count);
        for (uint32_t i = 0; i < surface_format_count; ++i)
        {
            entry.surface_formats_pnext_memory[i].Reset();
            entry.surface_formats[i].sType         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
            entry.surface_formats[i].pNext         = nullptr;
            entry.surface_formats[i].surfaceFormat = surface_formats[i].surfaceFormat;

            if (surface_formats[i].pNext != nullptr)
            {
                entry.surface_formats[i].pNext =
                    const_cast<void*>(TrackStruct(surface_formats[i].pNext, &entry.surface_formats_pnext_memory[i]));
            }
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                                VkSurfaceKHR            surface,
                                                                uint32_t                mode_count,
                                                                const VkPresentModeKHR* modes,
                                                                const void*             surface_info_pnext)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (modes != nullptr));

    auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper->surface_present_modes[GetVulkanWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];
    entry.present_modes.assign(modes, modes + mode_count);

    entry.surface_info_pnext = nullptr;
    entry.surface_info_pnext_memory.Reset();
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = TrackStruct(surface_info_pnext, &entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackDeviceGroupSurfacePresentModes(VkDevice                          device,
                                                             VkSurfaceKHR                      surface,
                                                             VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                             const void*                       surface_info_pnext)
{
    assert((device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (pModes != nullptr));

    auto  wrapper = GetVulkanWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry   = wrapper->group_surface_present_modes[GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(device)];
    entry.present_modes = *pModes;

    entry.surface_info_pnext = nullptr;
    entry.surface_info_pnext_memory.Reset();
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = TrackStruct(surface_info_pnext, &entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackBufferDeviceAddress(VkDevice device, VkBuffer buffer, VkDeviceAddress address)
{
    assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE));

    auto wrapper       = GetVulkanWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->device_id = GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;
}

void VulkanStateTracker::TrackBufferMemoryBinding(
    VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset, const void* bind_info_pnext)
{
    assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper            = GetVulkanWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->bind_device    = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->bind_memory_id = GetVulkanWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->bind_offset    = memoryOffset;
    wrapper->bind_pnext     = nullptr;
    wrapper->bind_pnext_memory.Reset();

    if (bind_info_pnext != nullptr)
    {
        wrapper->bind_pnext = TrackStruct(bind_info_pnext, &wrapper->bind_pnext_memory);
    }
}

void VulkanStateTracker::TrackTLASBuildCommand(
    VkCommandBuffer                                        command_buffer,
    uint32_t                                               info_count,
    const VkAccelerationStructureBuildGeometryInfoKHR*     infos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* pp_buildRange_infos)
{
    if (info_count && infos && pp_buildRange_infos)
    {
        vulkan_wrappers::CommandBufferWrapper* buf_wrapper =
            GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < info_count; ++i)
        {
            if (infos[i].type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR &&
                infos[i].dstAccelerationStructure != VK_NULL_HANDLE && infos[i].geometryCount && infos[i].pGeometries)
            {
                vulkan_wrappers::AccelerationStructureKHRWrapper* tlas_wrapper =
                    GetVulkanWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                        infos[i].dstAccelerationStructure);

                tlas_wrapper->blas.clear();

                for (uint32_t g = 0; g < infos[i].geometryCount; ++g)
                {
                    if (infos[i].pGeometries[g].geometryType == VK_GEOMETRY_TYPE_INSTANCES_KHR)
                    {
                        const VkDeviceAddress address = infos[i].pGeometries[g].geometry.instances.data.deviceAddress;
                        const uint32_t        primitive_count = pp_buildRange_infos[i]->primitiveCount;
                        // According to spec both address and primitiveCount can be 0.
                        // Nothing to handle in these cases.
                        if (address && primitive_count)
                        {
                            const vulkan_wrappers::CommandBufferWrapper::tlas_build_info tlas_info = {
                                address, primitive_count, pp_buildRange_infos[i]->primitiveOffset
                            };

                            buf_wrapper->tlas_build_info_map.emplace_back(
                                std::make_pair(tlas_wrapper, std::move(tlas_info)));
                        }
                    }
                }
            }
        }
    }
}

void VulkanStateTracker::TrackImageMemoryBinding(
    VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset, const void* bind_info_pnext)
{
    // If VkBindImageMemorySwapchainInfoKHR is in pnext, memory must be VK_NULL_HANDLE.
    assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE));

    auto wrapper            = GetVulkanWrapper<vulkan_wrappers::ImageWrapper>(image);
    wrapper->bind_device    = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->bind_memory_id = GetVulkanWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->bind_offset    = memoryOffset;
    wrapper->bind_pnext     = nullptr;
    wrapper->bind_pnext_memory.Reset();

    if (bind_info_pnext != nullptr)
    {
        wrapper->bind_pnext = TrackStruct(bind_info_pnext, &wrapper->bind_pnext_memory);
    }
}

void VulkanStateTracker::TrackMappedMemory(VkDevice         device,
                                           VkDeviceMemory   memory,
                                           void*            mapped_data,
                                           VkDeviceSize     mapped_offset,
                                           VkDeviceSize     mapped_size,
                                           VkMemoryMapFlags mapped_flags)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper           = GetVulkanWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->mapped_data   = mapped_data;
    wrapper->mapped_offset = mapped_offset;
    wrapper->mapped_size   = mapped_size;
    wrapper->mapped_flags  = mapped_flags;
}

void VulkanStateTracker::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert((command_buffer != VK_NULL_HANDLE) && (begin_info != nullptr));

    auto wrapper                     = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    wrapper->active_render_pass      = GetVulkanWrapper<vulkan_wrappers::RenderPassWrapper>(begin_info->renderPass);
    wrapper->render_pass_framebuffer = GetVulkanWrapper<vulkan_wrappers::FramebufferWrapper>(begin_info->framebuffer);
}

void VulkanStateTracker::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    assert(command_buffer != VK_NULL_HANDLE);

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
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

    auto primary_wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

    for (uint32_t i = 0; i < command_buffer_count; ++i)
    {
        auto secondary_wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[i]);
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
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = GetVulkanWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
            wrapper->pending_layouts[image_wrapper] = image_barriers[i].newLayout;
        }
    }
}

void VulkanStateTracker::TrackImageBarriers2KHR(VkCommandBuffer                 command_buffer,
                                                uint32_t                        image_barrier_count,
                                                const VkImageMemoryBarrier2KHR* image_barriers)
{
    assert(command_buffer != VK_NULL_HANDLE);

    if ((image_barrier_count > 0) && (image_barriers != nullptr))
    {
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = GetVulkanWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
            wrapper->pending_layouts[image_wrapper] = image_barriers[i].newLayout;
        }
    }
}

void VulkanStateTracker::TrackCommandBufferSubmissions(uint32_t submit_count, const VkSubmitInfo* submits)
{
    if ((submit_count > 0) && (submits != nullptr) && (submits->commandBufferCount > 0))
    {
        for (uint32_t submit = 0; submit < submit_count; ++submit)
        {
            uint32_t               command_buffer_count = submits[submit].commandBufferCount;
            const VkCommandBuffer* command_buffers      = submits[submit].pCommandBuffers;

            for (uint32_t cmd = 0; cmd < command_buffer_count; ++cmd)
            {
                auto command_wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[cmd]);
                assert(command_wrapper != nullptr);

                TrackQuerySubmissions(command_wrapper);
            }
        }
    }
}

void VulkanStateTracker::TrackCommandBufferSubmissions2(uint32_t submit_count, const VkSubmitInfo2* submits)
{
    if ((submit_count > 0) && (submits != nullptr) && (submits->commandBufferInfoCount > 0))
    {
        for (uint32_t submit = 0; submit < submit_count; ++submit)
        {
            uint32_t                         command_buffer_count = submits[submit].commandBufferInfoCount;
            const VkCommandBufferSubmitInfo* command_buffer_infos = submits[submit].pCommandBufferInfos;

            for (uint32_t cmd = 0; cmd < command_buffer_count; ++cmd)
            {
                auto command_wrapper =
                    GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer_infos[cmd].commandBuffer);
                assert(command_wrapper != nullptr);

                TrackQuerySubmissions(command_wrapper);
            }
        }
    }
}

void VulkanStateTracker::TrackQuerySubmissions(vulkan_wrappers::CommandBufferWrapper* command_wrapper)
{
    // Apply pending image layouts.
    for (const auto& layout_entry : command_wrapper->pending_layouts)
    {
        auto image_wrapper = layout_entry.first;
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

void VulkanStateTracker::TrackUpdateDescriptorSets(uint32_t                    write_count,
                                                   const VkWriteDescriptorSet* writes,
                                                   uint32_t                    copy_count,
                                                   const VkCopyDescriptorSet*  copies)
{
    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if (writes != nullptr)
    {
        for (uint32_t i = 0; i < write_count; ++i)
        {
            const VkWriteDescriptorSet* write = &writes[i];
            auto wrapper                      = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(write->dstSet);
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

                binding.write_pnext = nullptr;
                binding.write_pnext_memory.Reset();
                if (write->pNext != nullptr)
                {
                    binding.write_pnext = TrackStruct(write->pNext, &binding.write_pnext_memory);
                    auto* pnext         = reinterpret_cast<const VkBaseInStructure*>(binding.write_pnext);
                    switch (pnext->sType)
                    {
                        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
                        {
                            auto* acc_struct = reinterpret_cast<VkWriteDescriptorSetAccelerationStructureKHR*>(
                                const_cast<void*>(binding.write_pnext));
                            binding.record_write_set_accel_structs.clear();
                            std::copy(acc_struct->pAccelerationStructures,
                                      acc_struct->pAccelerationStructures + acc_struct->accelerationStructureCount,
                                      std::back_inserter(binding.record_write_set_accel_structs));
                            acc_struct->pAccelerationStructures = binding.record_write_set_accel_structs.data();
                            break;
                        }
                        default:
                            break;
                    }
                }

                // Update current and write counts for binding's descriptor count. If current count is
                // greater than the count for the descriptor range defined by dstArrayElement through binding count,
                // consecutive bindings are being updated.
                uint32_t current_writes = std::min(current_count, (binding.count - current_dst_array_element));

                bool* written_start = &binding.written[current_dst_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type == VK_DESCRIPTOR_TYPE_MUTABLE_VALVE)
                {
                    VkDescriptorType* mutable_type_start = &binding.mutable_type[current_dst_array_element];
                    std::fill(mutable_type_start, mutable_type_start + current_writes, write->descriptorType);
                }

                switch (write->descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] =
                                GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
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
                            dst_sampler_ids[i] =
                                GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            dst_image_ids[i] =
                                GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
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
                            dst_image_ids[i] =
                                GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
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
                            dst_buffer_ids[i] = GetVulkanWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
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
                            dst_view_ids[i] = GetVulkanWrappedId<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
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
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        VkWriteDescriptorSetAccelerationStructureKHR* write_accel_struct =
                            graphics::GetPNextStruct<VkWriteDescriptorSetAccelerationStructureKHR>(
                                write, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR);

                        if (write_accel_struct != nullptr)
                        {
                            format::HandleId* dst_accel_struct_ids = &binding.handle_ids[current_dst_array_element];
                            VkAccelerationStructureKHR* dst_accel_struct =
                                &binding.acceleration_structures[current_dst_array_element];
                            const VkAccelerationStructureKHR* src_accel_struct =
                                &write_accel_struct->pAccelerationStructures[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                dst_accel_struct_ids[i] =
                                    GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                dst_accel_struct[i] = src_accel_struct[i];
                            }
                        }
                    }
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
            auto dst_wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->dstSet);
            auto src_wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->srcSet);
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
                if (src_binding.buffers != nullptr)
                {
                    memcpy(&dst_binding.buffers[current_dst_array_element],
                           &src_binding.buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));
                }
                if (src_binding.acceleration_structures != nullptr)
                {
                    memcpy(&dst_binding.acceleration_structures[current_dst_array_element],
                           &src_binding.acceleration_structures[current_src_array_element],
                           (sizeof(VkWriteDescriptorSetAccelerationStructureKHR) * current_copies));
                }
                if (src_binding.texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.texel_buffer_views[current_dst_array_element],
                           &src_binding.texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));
                }
                if (src_binding.mutable_type != nullptr)
                {
                    memcpy(&dst_binding.mutable_type[current_dst_array_element],
                           &src_binding.mutable_type[current_src_array_element],
                           (sizeof(VkDescriptorType) * current_copies));
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
        auto           wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorSetWrapper>(set);
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
                        dst_sampler_ids[i] = GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(image_info->sampler);
                    }

                    if (binding.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        dst_image_ids[i] = GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(image_info->imageView);
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
                    dst_buffer_ids[i] = GetVulkanWrappedId<vulkan_wrappers::BufferWrapper>(buffer_info->buffer);
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
                    dst_view_ids[i]  = GetVulkanWrappedId<vulkan_wrappers::BufferViewWrapper>(*buffer_view);
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

        for (const auto& entry : template_info->acceleration_structure_khr)
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

                assert(binding.acceleration_structures != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*           dst_view_ids = &binding.handle_ids[current_array_element];
                VkAccelerationStructureKHR* dst_info     = &binding.acceleration_structures[current_array_element];
                const uint8_t*              src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    const auto* accel_struct = reinterpret_cast<const VkAccelerationStructureKHR*>(src_address);
                    dst_view_ids[i] =
                        GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(*accel_struct);
                    dst_info[i] = *accel_struct;

                    src_address += entry.stride;
                }
                // Because UpdateWithTemplate does not require pNext to update acceleration structures
                // but state recreation uses UpdateDescriptorSets which does require pNext to update acceleration
                // structures we create a relevant pNext
                const VkWriteDescriptorSetAccelerationStructureKHR p_next{
                    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR,
                    nullptr,
                    current_writes,
                    binding.acceleration_structures.get()
                };

                binding.write_pnext = TrackStruct(&p_next, &binding.write_pnext_memory);

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

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::DescriptorPoolWrapper>(descriptor_pool);

    // Pool reset implicitly frees descriptor sets, so remove all wrappers from the state tracker.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& set_entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(set_entry.second);
    }
}

void VulkanStateTracker::TrackQueryActivation(
    VkCommandBuffer command_buffer, VkQueryPool query_pool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    const vulkan_wrappers::CommandPoolWrapper* command_pool_wrapper = wrapper->parent_pool;

    auto& query_pool_info = wrapper->recorded_queries[GetVulkanWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];
    auto& query_info      = query_pool_info[query];
    query_info.active     = true;
    query_info.flags      = flags;
    query_info.query_type_index   = index;
    query_info.queue_family_index = command_pool_wrapper->queue_family_index;
}

void VulkanStateTracker::TrackQueryReset(VkCommandBuffer command_buffer,
                                         VkQueryPool     query_pool,
                                         uint32_t        first_query,
                                         uint32_t        query_count)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    auto  wrapper         = GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    auto& query_pool_info = wrapper->recorded_queries[GetVulkanWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        query_pool_info[i].active = false;
    }
}

void VulkanStateTracker::TrackQueryReset(VkQueryPool query_pool, uint32_t first_query, uint32_t query_count)
{
    assert(query_pool != VK_NULL_HANDLE);

    auto wrapper = GetVulkanWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool);
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
        auto wrapper = GetVulkanWrapper<vulkan_wrappers::SemaphoreWrapper>(signal);
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
        if (waits != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                auto wrapper = GetVulkanWrapper<vulkan_wrappers::SemaphoreWrapper>(waits[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signals != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper = GetVulkanWrapper<vulkan_wrappers::SemaphoreWrapper>(signals[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackSemaphoreInfoSignalState(uint32_t                     wait_count,
                                                       const VkSemaphoreSubmitInfo* wait_infos,
                                                       uint32_t                     signal_count,
                                                       const VkSemaphoreSubmitInfo* signal_infos)
{
    if (((wait_infos != nullptr) && (wait_count > 0)) || ((signal_infos != nullptr) && (signal_count > 0)))
    {
        if (wait_infos != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                auto wrapper = GetVulkanWrapper<vulkan_wrappers::SemaphoreWrapper>(wait_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signal_infos != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper = GetVulkanWrapper<vulkan_wrappers::SemaphoreWrapper>(signal_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackAcquireImage(
    uint32_t image_index, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
{
    auto wrapper = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);

    assert(wrapper != nullptr);

    if (image_index >= wrapper->image_acquired_info.size())
    {
        wrapper->image_acquired_info.resize(image_index + 1);
        wrapper->image_acquired_info[image_index].last_presented_queue = VK_NULL_HANDLE;
    }

    wrapper->image_acquired_info[image_index].is_acquired          = true;
    wrapper->image_acquired_info[image_index].acquired_device_mask = deviceMask;
    wrapper->image_acquired_info[image_index].acquired_semaphore_id =
        GetVulkanWrappedId<vulkan_wrappers::SemaphoreWrapper>(semaphore);
    wrapper->image_acquired_info[image_index].acquired_fence_id =
        GetVulkanWrappedId<vulkan_wrappers::FenceWrapper>(fence);
}

void VulkanStateTracker::TrackPresentedImages(uint32_t              count,
                                              const VkSwapchainKHR* swapchains,
                                              const uint32_t*       image_indices,
                                              VkQueue               queue)
{
    assert((count > 0) && (swapchains != nullptr) && (image_indices != nullptr));

    for (uint32_t i = 0; i < count; ++i)
    {
        auto     wrapper     = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchains[i]);
        uint32_t image_index = image_indices[i];

        assert((wrapper != nullptr) && (image_index < wrapper->image_acquired_info.size()));

        wrapper->last_presented_image                                  = image_index;
        wrapper->image_acquired_info[image_index].is_acquired          = false;
        wrapper->image_acquired_info[image_index].last_presented_queue = queue;
    }
}

void VulkanStateTracker::TrackAccelerationStructureKHRDeviceAddress(VkDevice                   device,
                                                                    VkAccelerationStructureKHR accel_struct,
                                                                    VkDeviceAddress            address)
{
    assert((device != VK_NULL_HANDLE) && (accel_struct != VK_NULL_HANDLE));

    auto wrapper       = GetVulkanWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(accel_struct);
    wrapper->device_id = GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    assert(address);
    as_device_addresses_map.emplace(address, wrapper);
}

void VulkanStateTracker::TrackDeviceMemoryDeviceAddress(VkDevice device, VkDeviceMemory memory, VkDeviceAddress address)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper       = GetVulkanWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->device_id = GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    device_memory_addresses_map.emplace(address, wrapper);
}

void VulkanStateTracker::TrackRayTracingShaderGroupHandles(VkDevice    device,
                                                           VkPipeline  pipeline,
                                                           size_t      data_size,
                                                           const void* data)
{
    assert((device != VK_NULL_HANDLE) && (pipeline != VK_NULL_HANDLE));

    auto           wrapper   = GetVulkanWrapper<vulkan_wrappers::PipelineWrapper>(pipeline);
    const uint8_t* byte_data = reinterpret_cast<const uint8_t*>(data);
    wrapper->device_id       = GetVulkanWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->shader_group_handle_data.assign(byte_data, byte_data + data_size);
}

void VulkanStateTracker::TrackAcquireFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper                                = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->acquire_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackReleaseFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper                                = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->release_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackSetPrivateData(
    VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
    assert(privateDataSlot != VK_NULL_HANDLE);

    auto wrapper        = GetVulkanWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(privateDataSlot);
    auto device_wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);

    wrapper->device        = device_wrapper;
    wrapper->object_type   = objectType;
    wrapper->object_handle = GetVulkanWrappedId(objectHandle, objectType);
    wrapper->data          = data;
}

void VulkanStateTracker::TrackSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
    assert(swapChain != VK_NULL_HANDLE);

    auto wrapper        = GetVulkanWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapChain);
    auto device_wrapper = GetVulkanWrapper<vulkan_wrappers::DeviceWrapper>(device);

    wrapper->device                   = device_wrapper;
    wrapper->using_local_dimming_AMD  = true;
    wrapper->local_dimming_enable_AMD = localDimmingEnable;
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::InstanceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Physical devices are not explicitly destroyed, so need to be removed from the state tracker when their parent
    // instance is destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
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

void VulkanStateTracker::DestroyState(vulkan_wrappers::DeviceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Queues are not explicitly destroyed, so need to be removed from the state tracker when their parent device is
    // destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_queues)
    {
        state_table_.RemoveWrapper(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::CommandPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_buffers)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DescriptorPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::SwapchainKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Swapchain images are not explicitly destroyed, so need to be removed from state tracking when the parent
    // swapchain is destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (auto entry : wrapper->child_images)
    {
        state_table_.RemoveWrapper(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DeviceMemoryWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    const auto& entry = device_memory_addresses_map.find(wrapper->address);
    if (entry != device_memory_addresses_map.end())
    {
        device_memory_addresses_map.erase(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    const auto& entry = as_device_addresses_map.find(wrapper->address);
    if (entry != as_device_addresses_map.end())
    {
        as_device_addresses_map.erase(entry);
    }
}

void VulkanStateTracker::TrackTlasToBlasDependencies(uint32_t               command_buffer_count,
                                                     const VkCommandBuffer* command_buffers)
{
    if (!command_buffer_count || !command_buffers)
    {
        return;
    }

    for (uint32_t c = 0; c < command_buffer_count; ++c)
    {
        const vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            GetVulkanWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[c]);

        for (const auto& tlas_build_info : cmd_buf_wrapper->tlas_build_info_map)
        {
            // Sanity checks. Build infos with one of these 0 should not be inserted in the map
            assert(tlas_build_info.second.address);
            assert(tlas_build_info.second.blas_count);

            // Find to which device memory this address belongs
            const VkDeviceAddress                       address         = tlas_build_info.second.address;
            const vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper = nullptr;
            for (const auto& dev_mem : device_memory_addresses_map)
            {
                if (address >= dev_mem.second->address &&
                    address < dev_mem.second->address + dev_mem.second->allocation_size)
                {
                    dev_mem_wrapper = dev_mem.second;
                    break;
                }
            }

            assert(dev_mem_wrapper);
            if (!dev_mem_wrapper)
            {
                continue;
            }

            assert(dev_mem_wrapper->address);
            assert(address >= dev_mem_wrapper->address);

            // Calculate total offset:
            //  address:        The address of the buffer where the
            //                  VkAccelerationStructureInstanceKHRs are located.
            //  base_address:   The device address of the device memory where
            //                  the buffer is bound.
            //  buffer_offset:  The offset within the buffer as provided in the
            //                  BuildAccelerationStructureKHR command.
            const VkDeviceAddress base_address  = dev_mem_wrapper->address;
            const VkDeviceAddress buffer_offset = tlas_build_info.second.offset;
            const VkDeviceSize    total_offset  = (address - base_address) + buffer_offset;

            const VkAccelerationStructureInstanceKHR* instances = nullptr;
            const util::PageGuardManager*             manager   = util::PageGuardManager::Get();

            // Check with page guard manager first. The memory might be already and the
            // PageGuardManager can provide the pointer
            if (manager)
            {
                const void* mapped_memory = manager->GetMappedMemory(dev_mem_wrapper->handle_id);
                if (mapped_memory)
                {
                    instances = reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(
                        static_cast<const uint8_t*>(mapped_memory) + total_offset);
                }
            }

            const uint32_t blas_count      = tlas_build_info.second.blas_count;
            bool           needs_unmapping = false;
            if (!instances)
            {
                // If PageGuardManager is not used or if it couldn't find the memory id it means that
                // we need to map the memory.
                VkDevice                 device        = dev_mem_wrapper->parent_device->handle;
                const VulkanDeviceTable* device_table  = GetVulkanDeviceTable(device);
                const VkDeviceSize       map_size      = sizeof(VkAccelerationStructureInstanceKHR) * blas_count;
                void*                    mapped_memory = nullptr;
                const VkResult           result =
                    device_table->MapMemory(device, dev_mem_wrapper->handle, total_offset, map_size, 0, &mapped_memory);

                if (result == VK_SUCCESS)
                {
                    needs_unmapping = true;

                    instances = reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(mapped_memory);
                }
            }

            if (instances)
            {
                vulkan_wrappers::AccelerationStructureKHRWrapper* tlas_wrapper = tlas_build_info.first;

                for (uint32_t b = 0; b < blas_count; ++b)
                {
                    // Find to which BLAS the device address stored in
                    // VkAccelerationStructureInstanceKHR::accelerationStructureReference referes to
                    const uint64_t as_reference = instances[b].accelerationStructureReference;

                    const auto blas_dev_mem_pair = as_device_addresses_map.find(as_reference);
                    if (blas_dev_mem_pair != as_device_addresses_map.end())
                    {
                        tlas_wrapper->blas.push_back(blas_dev_mem_pair->second);
                    }
                }

                // If we had to map the device memory unmap it now
                if (needs_unmapping)
                {
                    VkDevice                 device       = dev_mem_wrapper->parent_device->handle;
                    const VulkanDeviceTable* device_table = GetVulkanDeviceTable(device);
                    device_table->UnmapMemory(device, dev_mem_wrapper->handle);
                }
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
