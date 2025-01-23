/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#include "decode/vulkan_object_info.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_info.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_table_base.h"
#include "encode/vulkan_track_struct.h"
#include "format/format.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/to_string.h"
#include "vulkan/vulkan_core.h"

#include "util/page_status_tracker.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>

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
        wrapper->command_data.Clear();
        wrapper->pending_layouts.clear();
        wrapper->recorded_queries.clear();
        wrapper->tlas_build_info_map.clear();
        wrapper->modified_assets.clear();
        wrapper->secondaries.clear();
        for (uint32_t point = vulkan_state_info::kBindPoint_graphics; point != vulkan_state_info::kBindPoint_count;
             ++point)
        {
            wrapper->bound_descriptors[point].clear();
            wrapper->bound_pipelines[point] = nullptr;
        }

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

    auto wrapper               = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);
    wrapper->trim_command_pool = true;

    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->device     = device_wrapper;
}

void VulkanStateTracker::TrackResetCommandPool(VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);

    for (const auto& entry : wrapper->child_buffers)
    {
        entry.second->command_data.Clear();
        entry.second->pending_layouts.clear();
        entry.second->recorded_queries.clear();
        entry.second->tlas_build_info_map.clear();
        entry.second->modified_assets.clear();
        entry.second->secondaries.clear();
        for (uint32_t point = vulkan_state_info::kBindPoint_graphics; point != vulkan_state_info::kBindPoint_count;
             ++point)
        {
            entry.second->bound_descriptors[point].clear();
            entry.second->bound_pipelines[point] = nullptr;
        }

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

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);

    wrapper->memory_properties = *properties;
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                                  uint32_t                       property_count,
                                                                  const VkQueueFamilyProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
    // If queue family properties were already retrieved with a count larger than the current property_count, we must
    // not discard those additional properties
    if (property_count < wrapper->queue_family_properties_count)
        return;

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

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
    // If queue family properties were already retrieved with a count larger than the current property_count, we must
    // not discard those additional properties
    if (property_count < wrapper->queue_family_properties_count)
        return;

    wrapper->queue_family_properties_call_id = call_id;
    wrapper->queue_family_properties_count   = property_count;
    wrapper->queue_family_properties2        = std::make_unique<VkQueueFamilyProperties2[]>(property_count);
    memcpy(wrapper->queue_family_properties2.get(), properties, property_count);

    // Copy pNext structure and update pNext pointers.
    for (uint32_t i = 0; i < property_count; ++i)
    {
        if (auto queue_family_properties_nv =
                graphics::vulkan_struct_get_pnext<VkQueueFamilyCheckpointPropertiesNV>(properties + i))
        {
            std::unique_ptr<VkQueueFamilyCheckpointPropertiesNV> copy =
                std::make_unique<VkQueueFamilyCheckpointPropertiesNV>(*queue_family_properties_nv);

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

void VulkanStateTracker::TrackPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                                           uint32_t         queue_family_index,
                                                           VkSurfaceKHR     surface,
                                                           VkBool32         supported)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper
            ->surface_support[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];
    entry[queue_family_index] = supported;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                                VkSurfaceKHR                    surface,
                                                                const VkSurfaceCapabilitiesKHR* capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (capabilities != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry   = wrapper->surface_capabilities[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];

    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface;

    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = *capabilities;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice                       physical_device,
                                                                 const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                                 VkSurfaceCapabilities2KHR* surface_capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface_info.surface != VK_NULL_HANDLE));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
    auto& entry   = wrapper->surface_capabilities[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];

    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface_info.surface;

    if (surface_info.pNext != nullptr)
    {
        entry.surface_info.pNext = vulkan_trackers::TrackStruct(surface_info.pNext, entry.surface_info_pnext_memory);
    }

    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = surface_capabilities->surfaceCapabilities;

    if (surface_capabilities->pNext != nullptr)
    {
        entry.surface_capabilities.pNext =
            vulkan_trackers::TrackStruct(surface_capabilities->pNext, entry.surface_capabilities_pnext_memory);
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
        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
        auto& entry   = wrapper->surface_formats[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
            physical_device)];

        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface;

        std::vector<VkSurfaceFormat2KHR> surface_formats(format_count);

        for (uint32_t i = 0; i < format_count; ++i)
        {
            surface_formats[i].sType         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
            surface_formats[i].pNext         = nullptr;
            surface_formats[i].surfaceFormat = formats[i];
        }
        entry.surface_format_count = format_count;
        entry.surface_formats =
            vulkan_trackers::TrackStructs(surface_formats.data(), format_count, entry.surface_formats_memory);
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
        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
        auto& entry   = wrapper->surface_formats[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
            physical_device)];

        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface_info.surface;

        if (surface_info.pNext != nullptr)
        {
            entry.surface_info.pNext =
                vulkan_trackers::TrackStruct(surface_info.pNext, entry.surface_info_pnext_memory);
        }

        entry.surface_format_count = surface_format_count;
        entry.surface_formats =
            vulkan_trackers::TrackStructs(surface_formats, surface_format_count, entry.surface_formats_memory);
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                                VkSurfaceKHR            surface,
                                                                uint32_t                mode_count,
                                                                const VkPresentModeKHR* modes,
                                                                const void*             surface_info_pnext)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (modes != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry = wrapper->surface_present_modes[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];
    entry.present_modes.assign(modes, modes + mode_count);

    entry.surface_info_pnext = nullptr;
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = vulkan_trackers::TrackStruct(surface_info_pnext, entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackDeviceGroupSurfacePresentModes(VkDevice                          device,
                                                             VkSurfaceKHR                      surface,
                                                             VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                             const void*                       surface_info_pnext)
{
    assert((device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (pModes != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper->group_surface_present_modes[vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device)];
    entry.present_modes = *pModes;

    entry.surface_info_pnext = nullptr;
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = vulkan_trackers::TrackStruct(surface_info_pnext, entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackBufferDeviceAddress(VkDevice device, VkBuffer buffer, VkDeviceAddress address)
{
    GFXRECON_ASSERT((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE));

    auto wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    device_address_trackers_[device].TrackBuffer(wrapper);
}

void VulkanStateTracker::TrackOpaqueBufferDeviceAddress(VkDevice        device,
                                                        VkBuffer        buffer,
                                                        VkDeviceAddress opaque_address)
{
    GFXRECON_ASSERT((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE));

    auto wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->device_id      = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->opaque_address = opaque_address;
}

void VulkanStateTracker::TrackBufferMemoryBinding(
    VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset, const void* bind_info_pnext)
{
    assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->bind_device    = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->bind_memory_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->bind_offset    = memoryOffset;
    wrapper->bind_pnext     = nullptr;

    vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert(mem_wrapper != nullptr);
    mem_wrapper->asset_map_lock.lock();
    mem_wrapper->bound_assets.emplace(wrapper);
    mem_wrapper->asset_map_lock.unlock();

    if (bind_info_pnext != nullptr)
    {
        wrapper->bind_pnext = vulkan_trackers::TrackStruct(bind_info_pnext, wrapper->bind_pnext_memory);
    }
}

void VulkanStateTracker::TrackAccelerationStructureBuildCommand(
    VkCommandBuffer                                        command_buffer,
    uint32_t                                               info_count,
    const VkAccelerationStructureBuildGeometryInfoKHR*     p_infos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* pp_buildRange_infos)
{
    if (info_count == 0 || p_infos == nullptr || pp_buildRange_infos == nullptr)
    {
        return;
    }

    auto cmd_buf_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    auto device_wrapper  = cmd_buf_wrapper->parent_pool->device;

    for (uint32_t i = 0; i < info_count; ++i)
    {
        const VkAccelerationStructureBuildGeometryInfoKHR& build_info = p_infos[i];

        if (build_info.dstAccelerationStructure == VK_NULL_HANDLE || build_info.geometryCount == 0 ||
            (build_info.pGeometries == nullptr && build_info.ppGeometries == nullptr))
        {
            continue;
        }

        std::vector<VkDeviceAddress> to_extract = { build_info.scratchData.deviceAddress };

        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
            build_info.dstAccelerationStructure);

        vulkan_wrappers::AccelerationStructureKHRWrapper::AccelerationStructureKHRBuildCommandData dst_command{};
        // Extract command information for 1 AccelerationStructure
        for (uint32_t g = 0; g < build_info.geometryCount; ++g)
        {
            auto geometry = build_info.pGeometries != nullptr ? build_info.pGeometries + g : build_info.ppGeometries[g];

            switch (geometry->geometryType)
            {
                case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                {
                    for (const auto& address : { geometry->geometry.triangles.vertexData.deviceAddress,
                                                 geometry->geometry.triangles.indexData.deviceAddress,
                                                 geometry->geometry.triangles.transformData.deviceAddress })
                    {
                        to_extract.push_back(address);
                    }
                    break;
                }
                case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_AABBS_KHR:
                {
                    to_extract.push_back(geometry->geometry.aabbs.data.deviceAddress);
                    break;
                }
                case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_INSTANCES_KHR:
                {
                    to_extract.push_back(geometry->geometry.instances.data.deviceAddress);
                    break;
                }
                case VK_GEOMETRY_TYPE_MAX_ENUM_KHR:
                    break;
            }

            for (const VkDeviceAddress address : to_extract)
            {
                if (address == 0)
                {
                    continue;
                }

                auto target_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                    device_address_trackers_[device_wrapper->handle].GetBufferByDeviceAddress(address));

                GFXRECON_ASSERT(target_buffer_wrapper != nullptr);

                vulkan_wrappers::AccelerationStructureKHRWrapper::ASInputBuffer& buffer =
                    dst_command.input_buffers[target_buffer_wrapper->handle_id];

                buffer.capture_address    = address;
                buffer.handle             = target_buffer_wrapper->handle;
                buffer.handle_id          = target_buffer_wrapper->handle_id;
                buffer.bind_device        = target_buffer_wrapper->bind_device;
                buffer.queue_family_index = target_buffer_wrapper->queue_family_index;
                buffer.created_size       = target_buffer_wrapper->size;
                buffer.usage              = target_buffer_wrapper->usage;
            }

            dst_command.geometry_info                     = build_info;
            VkAccelerationStructureGeometryKHR* unwrapped = gfxrecon::encode::vulkan_trackers::TrackStructs(
                build_info.pGeometries, build_info.geometryCount, dst_command.geometry_info_memory);
            dst_command.geometry_info.pGeometries = unwrapped;

            dst_command.build_range_infos.insert(dst_command.build_range_infos.end(),
                                                 pp_buildRange_infos[i],
                                                 pp_buildRange_infos[i] + build_info.geometryCount);
        }

        if (build_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR)
        {
            wrapper->latest_build_command_ = std::move(dst_command);
        }
        else if (build_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR)
        {
            wrapper->latest_update_command_ = std::move(dst_command);
        }

        wrapper->blas.clear();

        for (uint32_t g = 0; g < build_info.geometryCount; ++g)
        {
            if (build_info.pGeometries[g].geometryType != VK_GEOMETRY_TYPE_INSTANCES_KHR)
            {
                continue;
            }
            const VkDeviceAddress address         = build_info.pGeometries[g].geometry.instances.data.deviceAddress;
            const uint32_t        primitive_count = pp_buildRange_infos[i]->primitiveCount;
            // According to spec both address and primitiveCount can be 0.
            // Nothing to handle in these cases.
            if (address && primitive_count)
            {
                const vulkan_wrappers::CommandBufferWrapper::tlas_build_info tlas_info = {
                    address, primitive_count, pp_buildRange_infos[i]->primitiveOffset
                };

                cmd_buf_wrapper->tlas_build_info_map.emplace_back(wrapper, tlas_info);
            }
        }
    }
}

void VulkanStateTracker::TrackAccelerationStructureCopyCommand(VkCommandBuffer                           command_buffer,
                                                               const VkCopyAccelerationStructureInfoKHR* info)
{
    // TODO: Support other types of copies (clone, serialize, deserialize)
    if (info == nullptr || info->mode != VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR)
    {
        return;
    }
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(info->src);
    if (!wrapper->latest_copy_command_)
    {
        wrapper->latest_copy_command_ =
            vulkan_wrappers::AccelerationStructureKHRWrapper::AccelerationStructureCopyCommandData{};
    }
    wrapper->latest_copy_command_->device = wrapper->device->handle_id;
    wrapper->latest_copy_command_->info   = *info;
}

void VulkanStateTracker::TrackWriteAccelerationStructuresPropertiesCommand(
    VkCommandBuffer                   commandBuffer,
    uint32_t                          accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures,
    VkQueryType                       queryType,
    VkQueryPool                       queryPool,
    uint32_t                          firstQuery)
{
    auto* cmd_buf_wrapper    = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    auto* query_pool_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(queryPool);

    for (uint32_t i = 0; i < accelerationStructureCount; ++i)
    {
        auto* wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(pAccelerationStructures[i]);
        wrapper->latest_write_properties_command_ =
            vulkan_wrappers::AccelerationStructureKHRWrapper::AccelerationStructureWritePropertiesCommandData{};
        wrapper->latest_write_properties_command_->device     = wrapper->device->handle_id;
        wrapper->latest_write_properties_command_->query_type = queryType;
    }
}

void VulkanStateTracker::TrackImageMemoryBinding(
    VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset, const void* bind_info_pnext)
{
    // If VkBindImageMemorySwapchainInfoKHR is in pnext, memory must be VK_NULL_HANDLE.
    assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE));

    auto wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
    wrapper->bind_device    = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->bind_memory_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->bind_offset    = memoryOffset;
    wrapper->bind_pnext     = nullptr;

    vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert(mem_wrapper != nullptr);
    mem_wrapper->asset_map_lock.lock();
    mem_wrapper->bound_assets.emplace(wrapper);
    mem_wrapper->asset_map_lock.unlock();

    if (bind_info_pnext != nullptr)
    {
        wrapper->bind_pnext = vulkan_trackers::TrackStruct(bind_info_pnext, wrapper->bind_pnext_memory);
    }
}

void VulkanStateTracker::TrackMappedMemory(VkDevice         device,
                                           VkDeviceMemory   memory,
                                           void*            mapped_data,
                                           VkDeviceSize     mapped_offset,
                                           VkDeviceSize     mapped_size,
                                           VkMemoryMapFlags mapped_flags,
                                           bool             track_assets)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper           = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->mapped_data   = mapped_data;
    wrapper->mapped_offset = mapped_offset;
    wrapper->mapped_size   = mapped_size;
    wrapper->mapped_flags  = mapped_flags;

    // Scan assets on unmap
    if (track_assets && mapped_data == nullptr)
    {
        TrackMappedAssetsWrites(wrapper->handle_id);
    }
}

void VulkanStateTracker::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert((command_buffer != VK_NULL_HANDLE) && (begin_info != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    wrapper->active_render_pass =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(begin_info->renderPass);
    wrapper->render_pass_framebuffer =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(begin_info->framebuffer);

    if (wrapper->render_pass_framebuffer != nullptr)
    {
        for (size_t i = 0; i < wrapper->render_pass_framebuffer->attachments.size(); ++i)
        {
            if (wrapper->render_pass_framebuffer->attachments[i]->is_swapchain_image)
            {
                continue;
            }

            const bool has_stencil = vkuFormatHasStencil(wrapper->render_pass_framebuffer->attachments[i]->format);
            if ((!has_stencil &&
                 wrapper->active_render_pass->attachment_info.store_op[i] == VK_ATTACHMENT_STORE_OP_STORE) ||
                (has_stencil &&
                 wrapper->active_render_pass->attachment_info.stencil_store_op[i] == VK_ATTACHMENT_STORE_OP_STORE))
            {
                wrapper->modified_assets.insert(wrapper->render_pass_framebuffer->attachments[i]);
            }
        }
    }
}

void VulkanStateTracker::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    assert(command_buffer != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    assert((wrapper->active_render_pass != VK_NULL_HANDLE) && (wrapper->render_pass_framebuffer != VK_NULL_HANDLE));

    auto render_pass_wrapper = wrapper->active_render_pass;
    auto framebuffer_wrapper = wrapper->render_pass_framebuffer;
    assert((framebuffer_wrapper != nullptr) && (render_pass_wrapper != nullptr));

    uint32_t attachment_count = static_cast<uint32_t>(framebuffer_wrapper->attachments.size());
    assert(attachment_count <= render_pass_wrapper->attachment_info.attachment_final_layouts.size());

    for (uint32_t i = 0; i < attachment_count; ++i)
    {
        wrapper->pending_layouts[framebuffer_wrapper->attachments[i]] =
            render_pass_wrapper->attachment_info.attachment_final_layouts[i];
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

    auto primary_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

    for (uint32_t i = 0; i < command_buffer_count; ++i)
    {
        auto secondary_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[i]);
        assert(secondary_wrapper != nullptr);

        primary_wrapper->secondaries.push_back(secondary_wrapper);

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
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
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
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
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
                auto command_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[cmd]);
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
                auto command_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    command_buffer_infos[cmd].commandBuffer);
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
        for (uint32_t wi = 0; wi < write_count; ++wi)
        {
            const VkWriteDescriptorSet* write = &writes[wi];
            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(write->dstSet);
            assert(wrapper != nullptr);

            wrapper->dirty = true;

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
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            if (sampler_wrapper != nullptr)
                            {
                                sampler_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
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
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                image_view_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }

                            vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            if (sampler_wrapper != nullptr)
                            {
                                sampler_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                image_view_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.storage_images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                image_view_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info       = &binding.buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info       = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::BufferWrapper* buffer_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            if (buffer_wrapper != nullptr)
                            {
                                buffer_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info = &binding.storage_buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::BufferWrapper* buffer_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            if (buffer_wrapper != nullptr)
                            {
                                buffer_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        const bool is_storage = binding.type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;

                        format::HandleId*   dst_view_ids = &binding.handle_ids[current_dst_array_element];
                        VkBufferView*       dst_info     = is_storage
                                                               ? &binding.storage_texel_buffer_views[current_dst_array_element]
                                                               : &binding.uniform_texel_buffer_views[current_dst_array_element];
                        const VkBufferView* src_info     = &write->pTexelBufferView[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_view_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            dst_info[i] = src_info[i];

                            vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            if (buffer_view_wrapper != nullptr)
                            {
                                buffer_view_wrapper->descriptor_sets_bound_to.insert(wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        auto write_inline_uniform_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetInlineUniformBlock>(write);

                        if (write_inline_uniform_struct != nullptr)
                        {
                            uint8_t*       dst_inline_uniform_data = binding.inline_uniform_block.get();
                            const uint8_t* src_inline_uniform_data =
                                reinterpret_cast<const uint8_t*>(write_inline_uniform_struct->pData);
                            memcpy(dst_inline_uniform_data, src_inline_uniform_data, current_writes);
                        }
                    }
                    break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                    {
                        const VkWriteDescriptorSetAccelerationStructureNV* write_accel_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetAccelerationStructureNV>(write);

                        if (write_accel_struct != nullptr)
                        {
                            const VkAccelerationStructureNV* src_accel_struct =
                                &write_accel_struct->pAccelerationStructures[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                vulkan_wrappers::AccelerationStructureNVWrapper* accel_struct_wrapper =
                                    vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(
                                        src_accel_struct[i]);
                                if (accel_struct_wrapper != nullptr)
                                {
                                    accel_struct_wrapper->descriptor_sets_bound_to.insert(wrapper);
                                }
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        auto write_accel_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetAccelerationStructureKHR>(write);

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
                                    vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                dst_accel_struct[i] = src_accel_struct[i];

                                vulkan_wrappers::AccelerationStructureKHRWrapper* accel_struct_wrapper =
                                    vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                if (accel_struct_wrapper != nullptr)
                                {
                                    accel_struct_wrapper->descriptor_sets_bound_to.insert(wrapper);
                                }
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
            auto dst_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->dstSet);
            auto src_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->srcSet);
            assert((dst_wrapper != nullptr) && (src_wrapper != nullptr));

            dst_wrapper->dirty = true;

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

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                src_binding.images[d].imageView);
                        if (image_view_wrapper != nullptr)
                        {
                            image_view_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }

                        vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(src_binding.images[i].sampler);
                        if (sampler_wrapper != nullptr)
                        {
                            sampler_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.storage_images != nullptr)
                {
                    memcpy(&dst_binding.storage_images[current_dst_array_element],
                           &src_binding.storage_images[current_src_array_element],
                           (sizeof(VkDescriptorImageInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                src_binding.storage_images[d].imageView);
                        if (image_view_wrapper != nullptr)
                        {
                            image_view_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.buffers != nullptr)
                {
                    memcpy(&dst_binding.buffers[current_dst_array_element],
                           &src_binding.buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferWrapper* buffer_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(src_binding.buffers[i].buffer);
                        if (buffer_wrapper != nullptr)
                        {
                            buffer_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.storage_buffers != nullptr)
                {
                    memcpy(&dst_binding.storage_buffers[current_dst_array_element],
                           &src_binding.storage_buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferWrapper* buffer_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                src_binding.storage_buffers[i].buffer);
                        if (buffer_wrapper != nullptr)
                        {
                            buffer_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.acceleration_structures != nullptr)
                {
                    memcpy(&dst_binding.acceleration_structures[current_dst_array_element],
                           &src_binding.acceleration_structures[current_src_array_element],
                           (sizeof(VkWriteDescriptorSetAccelerationStructureKHR) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::AccelerationStructureKHRWrapper* accel_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                src_binding.acceleration_structures[i]);
                        if (accel_wrapper != nullptr)
                        {
                            accel_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.inline_uniform_block != nullptr)
                {
                    memcpy(&dst_binding.inline_uniform_block[current_dst_array_element],
                           &src_binding.inline_uniform_block[current_src_array_element],
                           current_copies);
                }
                if (src_binding.uniform_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.uniform_texel_buffer_views[current_dst_array_element],
                           &src_binding.uniform_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                src_binding.uniform_texel_buffer_views[i]);
                        if (buffer_view_wrapper != nullptr)
                        {
                            buffer_view_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
                }
                if (src_binding.storage_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.storage_texel_buffer_views[current_dst_array_element],
                           &src_binding.storage_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                src_binding.storage_texel_buffer_views[i]);
                        if (buffer_view_wrapper != nullptr)
                        {
                            buffer_view_wrapper->descriptor_sets_bound_to.insert(dst_wrapper);
                        }
                    }
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
        auto           wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(set);
        const uint8_t* bytes   = reinterpret_cast<const uint8_t*>(data);

        wrapper->dirty = true;

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

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_image = binding.type == VK_DESCRIPTOR_TYPE_SAMPLER ||
                                             binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                                             binding.type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE ||
                                             binding.type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;

                assert((immutable_image && binding.images != nullptr) ||
                       (!immutable_image && binding.storage_images != nullptr));

                format::HandleId*      dst_sampler_ids = &binding.sampler_ids[current_array_element];
                format::HandleId*      dst_image_ids   = &binding.handle_ids[current_array_element];
                VkDescriptorImageInfo* dst_info        = immutable_image ? &binding.images[current_array_element]
                                                                         : &binding.storage_images[current_array_element];
                const uint8_t*         src_address     = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto image_info = reinterpret_cast<const VkDescriptorImageInfo*>(src_address);
                    if ((binding.type == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        dst_sampler_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(image_info->sampler);
                    }

                    if (binding.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        dst_image_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(image_info->imageView);
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

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_buffer = binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                                              binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;

                if (immutable_buffer)
                {
                    GFXRECON_ASSERT(binding.buffers != nullptr);
                }
                else
                {
                    GFXRECON_ASSERT(binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC ||
                                    binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
                    GFXRECON_ASSERT(binding.storage_buffers != nullptr);
                }

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*       dst_buffer_ids = &binding.handle_ids[current_array_element];
                VkDescriptorBufferInfo* dst_info       = immutable_buffer ? &binding.buffers[current_array_element]
                                                                          : &binding.storage_buffers[current_array_element];
                const uint8_t*          src_address    = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_info = reinterpret_cast<const VkDescriptorBufferInfo*>(src_address);
                    dst_buffer_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer_info->buffer);
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

                assert(binding.uniform_texel_buffer_views != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_buffer = binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;

                format::HandleId* dst_view_ids = &binding.handle_ids[current_array_element];
                VkBufferView*  dst_info = immutable_buffer ? &binding.uniform_texel_buffer_views[current_array_element]
                                                           : &binding.storage_texel_buffer_views[current_array_element];
                const uint8_t* src_address = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_view = reinterpret_cast<const VkBufferView*>(src_address);
                    dst_view_ids[i]  = vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(*buffer_view);
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
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(*accel_struct);
                    dst_info[i] = *accel_struct;

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
        for (const auto& entry : template_info->inline_uniform_block)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[entry.binding];
                GFXRECON_ASSERT(binding.inline_uniform_block != nullptr);

                // Check count for consecutive updates.
                const uint32_t current_num_bytes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_num_bytes, true);

                const uint8_t* src_address = bytes + current_offset;
                uint8_t*       dst_address = binding.inline_uniform_block.get() + entry.array_element;
                memcpy(dst_address, src_address, current_num_bytes);

                // Check for consecutive update.
                if (current_count == current_num_bytes)
                {
                    break;
                }
                else
                {
                    current_count -= current_num_bytes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_num_bytes * entry.stride);
                }
            }
        }
    }
}

void VulkanStateTracker::TrackResetDescriptorPool(VkDescriptorPool descriptor_pool)
{
    assert(descriptor_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(descriptor_pool);

    // Pool reset implicitly frees descriptor sets, so remove all wrappers from the state tracker.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& set_entry : wrapper->child_sets)
    {
        DestroyState(set_entry.second);
        state_table_.RemoveWrapper(set_entry.second);
    }
}

void VulkanStateTracker::TrackQueryActivation(
    VkCommandBuffer command_buffer, VkQueryPool query_pool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    const vulkan_wrappers::CommandPoolWrapper* command_pool_wrapper = wrapper->parent_pool;

    auto& query_pool_info =
        wrapper->recorded_queries[vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];
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

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    auto& query_pool_info =
        wrapper->recorded_queries[vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        query_pool_info[i].active = false;
    }
}

void VulkanStateTracker::TrackQueryReset(VkQueryPool query_pool, uint32_t first_query, uint32_t query_count)
{
    assert(query_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool);
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
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signal);
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
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(waits[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signals != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signals[i]);
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
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(wait_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signal_infos != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signal_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackAcquireImage(
    uint32_t image_index, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);

    assert(wrapper != nullptr);

    if (image_index >= wrapper->image_acquired_info.size())
    {
        wrapper->image_acquired_info.resize(image_index + 1);
        wrapper->image_acquired_info[image_index].last_presented_queue = VK_NULL_HANDLE;
    }

    wrapper->image_acquired_info[image_index].is_acquired          = true;
    wrapper->image_acquired_info[image_index].acquired_device_mask = deviceMask;
    wrapper->image_acquired_info[image_index].acquired_semaphore_id =
        vulkan_wrappers::GetWrappedId<vulkan_wrappers::SemaphoreWrapper>(semaphore);
    wrapper->image_acquired_info[image_index].acquired_fence_id =
        vulkan_wrappers::GetWrappedId<vulkan_wrappers::FenceWrapper>(fence);
}

void VulkanStateTracker::TrackPresentedImages(uint32_t              count,
                                              const VkSwapchainKHR* swapchains,
                                              const uint32_t*       image_indices,
                                              VkQueue               queue)
{
    assert((count > 0) && (swapchains != nullptr) && (image_indices != nullptr));

    for (uint32_t i = 0; i < count; ++i)
    {
        auto     wrapper     = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchains[i]);
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

    auto wrapper     = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(accel_struct);
    wrapper->device  = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address = address;

    device_address_trackers_[device].TrackAccelerationStructure(wrapper);
}

void VulkanStateTracker::TrackDeviceMemoryDeviceAddress(VkDevice device, VkDeviceMemory memory, VkDeviceAddress address)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    device_memory_addresses_map.emplace(address, wrapper);
}

void VulkanStateTracker::TrackRayTracingPipelineProperties(
    VkPhysicalDevice physicalDevice, VkPhysicalDeviceRayTracingPipelinePropertiesKHR* ray_properties)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);
    wrapper->ray_tracing_pipeline_properties        = *ray_properties;
    wrapper->ray_tracing_pipeline_properties->pNext = nullptr;
}

void VulkanStateTracker::TrackAccelerationStructureProperties(
    VkPhysicalDevice                                    physicalDevice,
    VkPhysicalDeviceAccelerationStructurePropertiesKHR* acceleration_structure_properties)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);
    wrapper->acceleration_structure_properties        = *acceleration_structure_properties;
    wrapper->acceleration_structure_properties->pNext = nullptr;
}

void VulkanStateTracker::TrackRayTracingShaderGroupHandles(VkDevice    device,
                                                           VkPipeline  pipeline,
                                                           size_t      data_size,
                                                           const void* data)
{
    assert((device != VK_NULL_HANDLE) && (pipeline != VK_NULL_HANDLE));
    auto  wrapper      = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pipeline);
    auto* byte_data    = reinterpret_cast<const uint8_t*>(data);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->shader_group_handle_data.assign(byte_data, byte_data + data_size);
}

void VulkanStateTracker::TrackAcquireFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->acquire_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackReleaseFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->release_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackSetPrivateData(
    VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
    assert(privateDataSlot != VK_NULL_HANDLE);

    auto wrapper        = vulkan_wrappers::GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(privateDataSlot);
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

    wrapper->device        = device_wrapper;
    wrapper->object_type   = objectType;
    wrapper->object_handle = vulkan_wrappers::GetWrappedId(objectHandle, objectType);
    wrapper->data          = data;
}

void VulkanStateTracker::TrackSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
    assert(swapChain != VK_NULL_HANDLE);

    auto wrapper        = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapChain);
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

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
        DestroyState(entry.second);
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
        DestroyState(entry);
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

void gfxrecon::encode::VulkanStateTracker::DestroyState(vulkan_wrappers::BufferWrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    if (wrapper != nullptr && wrapper->bind_device != nullptr)
    {
        device_address_trackers_[wrapper->bind_device->handle].RemoveBuffer(wrapper);
    }

    state_table_.VisitWrappers([&wrapper, this](vulkan_wrappers::AccelerationStructureKHRWrapper* acc_wrapper) {
        GFXRECON_ASSERT(acc_wrapper);
        for (auto& command : { &acc_wrapper->latest_build_command_, &acc_wrapper->latest_update_command_ })
        {
            if (!command || !command->has_value())
            {
                continue;
            }

            auto it = (*command)->input_buffers.find(wrapper->handle_id);
            if (it != (*command)->input_buffers.end())
            {
                vulkan_wrappers::AccelerationStructureKHRWrapper::ASInputBuffer& buffer = it->second;
                buffer.destroyed                                                        = true;
                auto [resource_util, created]                                           = resource_utils_.try_emplace(
                    buffer.bind_device->handle,
                    graphics::VulkanResourcesUtil(buffer.bind_device->handle,
                                                  buffer.bind_device->physical_device->handle,
                                                  buffer.bind_device->layer_table,
                                                  *buffer.bind_device->physical_device->layer_table_ref,
                                                  buffer.bind_device->physical_device->memory_properties));
                buffer.bind_device->layer_table.GetBufferMemoryRequirements(
                    buffer.bind_device->handle, buffer.handle, &buffer.memory_requirements);
                resource_util->second.ReadFromBufferResource(
                    buffer.handle, buffer.created_size, 0, buffer.queue_family_index, buffer.bytes);
            }
        }
    });

    if (wrapper->bind_memory_id != format::kNullHandleId)
    {
        vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
            state_table_.GetDeviceMemoryWrapper(wrapper->bind_memory_id);

        if (mem_wrapper != nullptr)
        {
            mem_wrapper->asset_map_lock.lock();
            auto bind_entry = mem_wrapper->bound_assets.find(wrapper);
            if (bind_entry != mem_wrapper->bound_assets.end())
            {
                mem_wrapper->bound_assets.erase(bind_entry);
            }
            mem_wrapper->asset_map_lock.unlock();
        }
    }

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }

    for (vulkan_wrappers::BufferViewWrapper* view_wrapper : wrapper->buffer_views)
    {
        view_wrapper->buffer    = nullptr;
        view_wrapper->buffer_id = format::kNullHandleId;
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    assert(wrapper->device != nullptr);
    wrapper->create_parameters = nullptr;
    device_address_trackers_[wrapper->device->handle].RemoveAccelerationStructure(wrapper);

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }

    wrapper->descriptor_sets_bound_to.clear();
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::AccelerationStructureNVWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::ImageWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    if (wrapper->bind_memory_id != format::kNullHandleId)
    {
        vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
            state_table_.GetDeviceMemoryWrapper(wrapper->bind_memory_id);

        if (mem_wrapper != nullptr)
        {
            mem_wrapper->asset_map_lock.lock();
            auto bind_entry = mem_wrapper->bound_assets.find(wrapper);
            if (bind_entry != mem_wrapper->bound_assets.end())
            {
                mem_wrapper->bound_assets.erase(bind_entry);
            }
            mem_wrapper->asset_map_lock.unlock();
        }
    }

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }

    for (vulkan_wrappers::ImageViewWrapper* view_wrapper : wrapper->image_views)
    {
        view_wrapper->image    = nullptr;
        view_wrapper->image_id = format::kNullHandleId;
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::ImageViewWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }

    if (wrapper->image != nullptr)
    {
        wrapper->image->image_views.erase(wrapper);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::BufferViewWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }

    if (wrapper->buffer != nullptr)
    {
        wrapper->buffer->buffer_views.erase(wrapper);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::SamplerWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    for (auto entry : wrapper->descriptor_sets_bound_to)
    {
        entry->dirty = true;
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DescriptorSetWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    for (auto& entry : wrapper->bindings)
    {
        vulkan_state_info::DescriptorInfo& binding = entry.second;
        switch (binding.type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                assert(binding.count);
                assert(binding.images);

                if (binding.type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE ||
                    binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                    binding.type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT)
                {
                    for (uint32_t i = 0; i < binding.count; ++i)
                    {
                        vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(binding.images[i].imageView,
                                                                                           false);
                        if (image_view_wrapper != nullptr)
                        {
                            auto img_view_desc_entry = image_view_wrapper->descriptor_sets_bound_to.find(wrapper);
                            if (img_view_desc_entry != image_view_wrapper->descriptor_sets_bound_to.end())
                            {
                                image_view_wrapper->descriptor_sets_bound_to.erase(img_view_desc_entry);
                            }
                        }
                    }

                    if (binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                        binding.type == VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        for (uint32_t i = 0; i < binding.count; ++i)
                        {
                            vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(binding.images[i].sampler,
                                                                                             false);
                            if (sampler_wrapper != nullptr)
                            {
                                auto desc_entry = sampler_wrapper->descriptor_sets_bound_to.find(wrapper);
                                if (desc_entry != sampler_wrapper->descriptor_sets_bound_to.end())
                                {
                                    sampler_wrapper->descriptor_sets_bound_to.erase(desc_entry);
                                }
                            }
                        }
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            {
                assert(binding.count);
                assert(binding.storage_images);

                for (uint32_t i = 0; i < binding.count; ++i)
                {
                    vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                            binding.storage_images[i].imageView, false);
                    if (image_view_wrapper != nullptr)
                    {
                        auto img_view_desc_entry = image_view_wrapper->descriptor_sets_bound_to.find(wrapper);
                        if (img_view_desc_entry != image_view_wrapper->descriptor_sets_bound_to.end())
                        {
                            image_view_wrapper->descriptor_sets_bound_to.erase(img_view_desc_entry);
                        }
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                const bool is_storage = binding.type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;

                assert(binding.count);
                assert((is_storage && binding.storage_texel_buffer_views) ||
                       (!is_storage && binding.uniform_texel_buffer_views));

                for (uint32_t i = 0; i < binding.count; ++i)
                {
                    vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                            is_storage ? binding.storage_texel_buffer_views[i] : binding.uniform_texel_buffer_views[i],
                            false);
                    if (buf_view_wrapper != nullptr)
                    {
                        auto view_entry = buf_view_wrapper->descriptor_sets_bound_to.find(wrapper);
                        if (view_entry != buf_view_wrapper->descriptor_sets_bound_to.end())
                        {
                            buf_view_wrapper->descriptor_sets_bound_to.erase(view_entry);
                        }

                        if (buf_view_wrapper->buffer != nullptr)
                        {
                            auto buf_entry = buf_view_wrapper->buffer->descriptor_sets_bound_to.find(wrapper);
                            if (buf_entry != buf_view_wrapper->buffer->descriptor_sets_bound_to.end())
                            {
                                buf_view_wrapper->buffer->descriptor_sets_bound_to.erase(buf_entry);
                            }
                        }
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                const bool is_storage = (binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                                        (binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC);

                assert(binding.count);
                assert((is_storage && binding.storage_buffers) || (!is_storage && binding.buffers));

                for (uint32_t i = 0; i < binding.count; ++i)
                {
                    vulkan_wrappers::BufferWrapper* buf_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                            is_storage ? binding.storage_buffers[i].buffer : binding.buffers[i].buffer, false);
                    if (buf_wrapper != nullptr)
                    {
                        auto entry = buf_wrapper->descriptor_sets_bound_to.find(wrapper);
                        if (entry != buf_wrapper->descriptor_sets_bound_to.end())
                        {
                            buf_wrapper->descriptor_sets_bound_to.erase(entry);
                        }
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            {
                assert(binding.count);
                assert(binding.acceleration_structures);

                for (uint32_t i = 0; i < binding.count; ++i)
                {
                    vulkan_wrappers::AccelerationStructureKHRWrapper* accel_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                            binding.acceleration_structures[i], false);
                    if (accel_wrapper != nullptr)
                    {
                        auto entry = accel_wrapper->descriptor_sets_bound_to.find(wrapper);
                        if (entry != accel_wrapper->descriptor_sets_bound_to.end())
                        {
                            accel_wrapper->descriptor_sets_bound_to.erase(entry);
                        }
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                // nothing to do, only sanity-check
                GFXRECON_ASSERT(binding.count);
                GFXRECON_ASSERT(binding.inline_uniform_block);
                break;

            default:
                GFXRECON_LOG_WARNING("%s() Descriptor type %u not handled", __func__, binding.type);
                break;
        }
    }
    wrapper->bindings.clear();
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
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[c]);
        const auto device_wrapper = cmd_buf_wrapper->parent_pool->device;

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
                const VulkanDeviceTable* device_table  = vulkan_wrappers::GetDeviceTable(device);
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

                    if (auto as_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                            device_address_trackers_[device_wrapper->handle].GetAccelerationStructureByDeviceAddress(
                                as_reference)))
                    {
                        tlas_wrapper->blas.push_back(as_wrapper);
                    }
                }

                // If we had to map the device memory unmap it now
                if (needs_unmapping)
                {
                    VkDevice                 device       = dev_mem_wrapper->parent_device->handle;
                    const VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);
                    device_table->UnmapMemory(device, dev_mem_wrapper->handle);
                }
            }
        }
    }
}

void VulkanStateTracker::TrackCmdBindDescriptorSets(VkCommandBuffer        commandBuffer,
                                                    VkPipelineBindPoint    pipelineBindPoint,
                                                    VkPipelineLayout       layout,
                                                    uint32_t               firstSet,
                                                    uint32_t               descriptorSetCount,
                                                    const VkDescriptorSet* pDescriptorSets,
                                                    uint32_t               dynamicOffsetCount,
                                                    const uint32_t*        pDynamicOffsets)
{
    if (pDescriptorSets != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < descriptorSetCount; ++i)
        {
            vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(pDescriptorSets[i]);

            const vulkan_state_info::PipelineBindPoints bind_point =
                vulkan_state_info::VkPipelinePointToPipelinePoint(pipelineBindPoint);
            cmd_buf_wrapper->bound_descriptors[bind_point][firstSet + i] = desc_set_wrapper;
        }
    }
}

void VulkanStateTracker::TrackCmdBindDescriptorSets2KHR(VkCommandBuffer                    commandBuffer,
                                                        const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    if (pBindDescriptorSetsInfo != nullptr && pBindDescriptorSetsInfo->pDescriptorSets != nullptr &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < pBindDescriptorSetsInfo->descriptorSetCount; ++i)
        {
            vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(
                    pBindDescriptorSetsInfo->pDescriptorSets[i]);

            std::vector<vulkan_state_info::PipelineBindPoints> bind_points;
            vulkan_state_info::VkShaderStageFlagsToPipelinePoint(pBindDescriptorSetsInfo->stageFlags, bind_points);
            for (auto bind_point : bind_points)
            {
                cmd_buf_wrapper->bound_descriptors[bind_point][pBindDescriptorSetsInfo->firstSet + i] =
                    desc_set_wrapper;
            }
        }
    }
}

void VulkanStateTracker::TrackCmdBindPipeline(VkCommandBuffer     commandBuffer,
                                              VkPipelineBindPoint pipelineBindPoint,
                                              VkPipeline          pipeline)
{
    if (commandBuffer != VK_NULL_HANDLE && pipeline != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper);

        const vulkan_wrappers::PipelineWrapper* ppl_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pipeline);
        assert(ppl_wrapper != nullptr);

        vulkan_state_info::PipelineBindPoints bind_point =
            vulkan_state_info::VkPipelinePointToPipelinePoint(pipelineBindPoint);
        cmd_buf_wrapper->bound_pipelines[bind_point] = ppl_wrapper;
    }
}

void VulkanStateTracker::InsertImageAssetInCommandBuffer(VkCommandBuffer command_buffer, VkImage image)
{
    if (command_buffer != VK_NULL_HANDLE && image != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* image_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        assert(image_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(image_wrapper);
    }
}

void VulkanStateTracker::InsertBufferAssetInCommandBuffer(VkCommandBuffer command_buffer, VkBuffer buffer)
{
    if (command_buffer != VK_NULL_HANDLE && buffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        assert(buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                                            VkBuffer            srcBuffer,
                                            VkBuffer            dstBuffer,
                                            uint32_t            regionCount,
                                            const VkBufferCopy* pRegions)
{
    InsertBufferAssetInCommandBuffer(commandBuffer, dstBuffer);
}

void VulkanStateTracker::TrackCmdCopyImage(VkCommandBuffer    commandBuffer,
                                           VkImage            srcImage,
                                           VkImageLayout      srcImageLayout,
                                           VkImage            dstImage,
                                           VkImageLayout      dstImageLayout,
                                           uint32_t           regionCount,
                                           const VkImageCopy* pRegions)
{
    InsertImageAssetInCommandBuffer(commandBuffer, dstImage);
}

void VulkanStateTracker::TrackCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                                   VkBuffer                 srcBuffer,
                                                   VkImage                  dstImage,
                                                   VkImageLayout            dstImageLayout,
                                                   uint32_t                 regionCount,
                                                   const VkBufferImageCopy* pRegions)
{
    InsertImageAssetInCommandBuffer(commandBuffer, dstImage);
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                                   VkImage                  srcImage,
                                                   VkImageLayout            srcImageLayout,
                                                   VkBuffer                 dstBuffer,
                                                   uint32_t                 regionCount,
                                                   const VkBufferImageCopy* pRegions)
{
    InsertBufferAssetInCommandBuffer(commandBuffer, dstBuffer);
}

void VulkanStateTracker::TrackCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr)
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, pCopyBufferInfo->dstBuffer);
    }
}

void VulkanStateTracker::TrackCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pCopyImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pCopyBufferToImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != nullptr)
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, pCopyImageToBufferInfo->dstBuffer);
    }
}

void VulkanStateTracker::TrackCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr)
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, pCopyBufferInfo->dstBuffer);
    }
}

void VulkanStateTracker::TrackCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pCopyImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdCopyBufferToImage2KHR(VkCommandBuffer                 commandBuffer,
                                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pCopyBufferToImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer2KHR(VkCommandBuffer                 commandBuffer,
                                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != nullptr)
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, pCopyImageToBufferInfo->dstBuffer);
    }
}

void VulkanStateTracker::TrackCmdBlitImage(VkCommandBuffer    commandBuffer,
                                           VkImage            srcImage,
                                           VkImageLayout      srcImageLayout,
                                           VkImage            dstImage,
                                           VkImageLayout      dstImageLayout,
                                           uint32_t           regionCount,
                                           const VkImageBlit* pRegions,
                                           VkFilter           filter)
{
    InsertImageAssetInCommandBuffer(commandBuffer, dstImage);
}

void VulkanStateTracker::TrackCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    if (pBlitImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pBlitImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    TrackCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void VulkanStateTracker::TrackCmdUpdateBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    InsertBufferAssetInCommandBuffer(commandBuffer, dstBuffer);
}

void VulkanStateTracker::TrackCmdFillBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    InsertBufferAssetInCommandBuffer(commandBuffer, dstBuffer);
}

void VulkanStateTracker::TrackCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                                 VkImage                        image,
                                                 VkImageLayout                  imageLayout,
                                                 const VkClearColorValue*       pColor,
                                                 uint32_t                       rangeCount,
                                                 const VkImageSubresourceRange* pRanges)
{
    InsertImageAssetInCommandBuffer(commandBuffer, image);
}

void VulkanStateTracker::TrackCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                                        VkImage                         image,
                                                        VkImageLayout                   imageLayout,
                                                        const VkClearDepthStencilValue* pDepthStencil,
                                                        uint32_t                        rangeCount,
                                                        const VkImageSubresourceRange*  pRanges)
{
    InsertImageAssetInCommandBuffer(commandBuffer, image);
}

void VulkanStateTracker::TrackCmdResolveImage(VkCommandBuffer       commandBuffer,
                                              VkImage               srcImage,
                                              VkImageLayout         srcImageLayout,
                                              VkImage               dstImage,
                                              VkImageLayout         dstImageLayout,
                                              uint32_t              regionCount,
                                              const VkImageResolve* pRegions)
{
    InsertImageAssetInCommandBuffer(commandBuffer, dstImage);
}

void VulkanStateTracker::TrackCmdResolveImage2(VkCommandBuffer            commandBuffer,
                                               const VkResolveImageInfo2* pResolveImageInfo)
{
    if (pResolveImageInfo != nullptr)
    {
        InsertImageAssetInCommandBuffer(commandBuffer, pResolveImageInfo->dstImage);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
    if (taskCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                              VkBuffer        buffer,
                                                              VkDeviceSize    offset,
                                                              VkBuffer        countBuffer,
                                                              VkDeviceSize    countBufferOffset,
                                                              uint32_t        maxDrawCount,
                                                              uint32_t        stride)
{
    if (maxDrawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                                  uint32_t        groupCountX,
                                                  uint32_t        groupCountY,
                                                  uint32_t        groupCountZ)
{
    if (groupCountX && groupCountY && groupCountZ)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                               VkBuffer        buffer,
                                                               VkDeviceSize    offset,
                                                               VkBuffer        countBuffer,
                                                               VkDeviceSize    countBufferOffset,
                                                               uint32_t        maxDrawCount,
                                                               uint32_t        stride)
{
    if (maxDrawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackMappedAssetsWrites(format::HandleId memory_id)
{
    util::PageGuardManager* manager = util::PageGuardManager::Get();
    if (manager == nullptr)
    {
        return;
    }

    std::unordered_map<uint64_t, const util::PageGuardManager::MemoryInfo&> memories_page_status;
    manager->GetDirtyMemoryRegions(memory_id, memories_page_status);
    const size_t page_size = util::platform::GetSystemPageSize();

    for (const auto& entry : memories_page_status)
    {
        assert(entry.second.status_tracker.HasActiveWriteBlock());

        const util::PageStatusTracker& page_status = entry.second.status_tracker;

        vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper = state_table_.GetDeviceMemoryWrapper(entry.first);
        assert(dev_mem_wrapper != nullptr);

        dev_mem_wrapper->asset_map_lock.lock();
        for (auto& asset : dev_mem_wrapper->bound_assets)
        {
            const size_t mapped_region_end =
                dev_mem_wrapper->mapped_offset + (dev_mem_wrapper->mapped_size == VK_WHOLE_SIZE
                                                      ? dev_mem_wrapper->allocation_size
                                                      : dev_mem_wrapper->mapped_size);
            if (asset->dirty || !asset->size || asset->bind_offset < dev_mem_wrapper->mapped_offset ||
                mapped_region_end < asset->bind_offset)
            {
                continue;
            }

            const size_t asset_offset_from_mapping = asset->bind_offset - dev_mem_wrapper->mapped_offset;
            const size_t first_page                = asset_offset_from_mapping / page_size;
            const size_t last_page                 = (asset_offset_from_mapping + asset->size - 1) / page_size;
            const size_t asset_page_count          = last_page - first_page + 1;
            assert(first_page <= last_page);
            assert(first_page < page_status.GetPageCount());
            assert(first_page + asset_page_count <= page_status.GetPageCount());

            if (page_status.HasActiveWriteBlock(first_page, asset_page_count))
            {
                asset->dirty = true;
            }
        }
        dev_mem_wrapper->asset_map_lock.unlock();
    }
}

void VulkanStateTracker::TrackPipelineDescriptors(vulkan_wrappers::CommandBufferWrapper* command_wrapper,
                                                  vulkan_state_info::PipelineBindPoints  ppl_bind_point)
{
    assert(command_wrapper != nullptr);
    assert(ppl_bind_point < vulkan_state_info::PipelineBindPoints::kBindPoint_count);

    const vulkan_wrappers::PipelineWrapper* ppl_wrapper = command_wrapper->bound_pipelines[ppl_bind_point];
    if (ppl_wrapper != nullptr)
    {
        for (const auto& stage : ppl_wrapper->bound_shaders)
        {
            for (const auto& set : stage.used_descriptors_info)
            {
                const uint32_t desc_set_index = set.first;
                for (const auto& desc : set.second)
                {
                    if (desc.second.accessed)
                    {
                        const uint32_t                               binding_index = desc.first;
                        const vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                            command_wrapper->bound_descriptors[ppl_bind_point][desc_set_index];

                        if (desc_set_wrapper == nullptr)
                        {
                            continue;
                        }

                        const auto& descriptor_binding = desc_set_wrapper->bindings.find(binding_index);
                        if (descriptor_binding == desc_set_wrapper->bindings.end())
                        {
                            continue;
                        }

                        switch (descriptor_binding->second.type)
                        {
                            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                            {
                                for (uint32_t a = 0; a < descriptor_binding->second.count; ++a)
                                {
                                    vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                            descriptor_binding->second.storage_images[a].imageView);

                                    if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                                    {
                                        command_wrapper->modified_assets.insert(img_view_wrapper->image);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                            {
                                for (uint32_t a = 0; a < descriptor_binding->second.count; ++a)
                                {
                                    vulkan_wrappers::BufferWrapper* buf_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                            descriptor_binding->second.storage_buffers[a].buffer);
                                    if (buf_wrapper != nullptr)
                                    {
                                        command_wrapper->modified_assets.insert(buf_wrapper);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                            {
                                for (uint32_t a = 0; a < descriptor_binding->second.count; ++a)
                                {
                                    vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                            descriptor_binding->second.storage_texel_buffer_views[a]);
                                    if (buf_view_wrapper != nullptr && buf_view_wrapper->buffer != nullptr)
                                    {
                                        command_wrapper->modified_assets.insert(buf_view_wrapper->buffer);
                                    }
                                }
                            }
                            break;

                            // Rest of descriptors are immutable within a shader
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
}

void VulkanStateTracker::TrackCmdDraw(VkCommandBuffer commandBuffer,
                                      uint32_t        vertexCount,
                                      uint32_t        instanceCount,
                                      uint32_t        firstVertex,
                                      uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                             uint32_t        indexCount,
                                             uint32_t        instanceCount,
                                             uint32_t        firstIndex,
                                             int32_t         vertexOffset,
                                             uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
                                                   VkBuffer        buffer,
                                                   VkDeviceSize    offset,
                                                   VkBuffer        countBuffer,
                                                   VkDeviceSize    countBufferOffset,
                                                   uint32_t        maxDrawCount,
                                                   uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
                                                          VkBuffer        buffer,
                                                          VkDeviceSize    offset,
                                                          VkBuffer        countBuffer,
                                                          VkDeviceSize    countBufferOffset,
                                                          uint32_t        maxDrawCount,
                                                          uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                      VkBuffer        buffer,
                                                      VkDeviceSize    offset,
                                                      VkBuffer        countBuffer,
                                                      VkDeviceSize    countBufferOffset,
                                                      uint32_t        maxDrawCount,
                                                      uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                             VkBuffer        buffer,
                                                             VkDeviceSize    offset,
                                                             VkBuffer        countBuffer,
                                                             VkDeviceSize    countBufferOffset,
                                                             uint32_t        maxDrawCount,
                                                             uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDispatch(VkCommandBuffer commandBuffer,
                                          uint32_t        groupCountX,
                                          uint32_t        groupCountY,
                                          uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdDispatchBase(VkCommandBuffer commandBuffer,
                                              uint32_t        baseGroupX,
                                              uint32_t        baseGroupY,
                                              uint32_t        baseGroupZ,
                                              uint32_t        groupCountX,
                                              uint32_t        groupCountY,
                                              uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
                                                 uint32_t        baseGroupX,
                                                 uint32_t        baseGroupY,
                                                 uint32_t        baseGroupZ,
                                                 uint32_t        groupCountX,
                                                 uint32_t        groupCountY,
                                                 uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdTraceRaysNV(VkCommandBuffer commandBuffer,
                                             VkBuffer        raygenShaderBindingTableBuffer,
                                             VkDeviceSize    raygenShaderBindingOffset,
                                             VkBuffer        missShaderBindingTableBuffer,
                                             VkDeviceSize    missShaderBindingOffset,
                                             VkDeviceSize    missShaderBindingStride,
                                             VkBuffer        hitShaderBindingTableBuffer,
                                             VkDeviceSize    hitShaderBindingOffset,
                                             VkDeviceSize    hitShaderBindingStride,
                                             VkBuffer        callableShaderBindingTableBuffer,
                                             VkDeviceSize    callableShaderBindingOffset,
                                             VkDeviceSize    callableShaderBindingStride,
                                             uint32_t        width,
                                             uint32_t        height,
                                             uint32_t        depth)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanStateTracker::TrackCmdTraceRaysKHR(VkCommandBuffer                        commandBuffer,
                                              const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                              const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                              uint32_t                               width,
                                              uint32_t                               height,
                                              uint32_t                               depth)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanStateTracker::TrackCmdTraceRaysIndirectKHR(
    VkCommandBuffer                        commandBuffer,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanStateTracker::TrackCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                       VkDeviceAddress indirectDeviceAddress)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanStateTracker::MarkReferencedAssetsAsDirty(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper)
{
    assert(cmd_buf_wrapper != nullptr);

    for (auto asset : cmd_buf_wrapper->modified_assets)
    {
        assert(asset);
        asset->dirty = true;
    }
}

void VulkanStateTracker::TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo* pSubmits)
{
    if (pSubmits != nullptr && submitCount)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(pSubmits[s].pCommandBuffers[c]);
                MarkReferencedAssetsAsDirty(primary);

                for (const auto secondary : primary->secondaries)
                {
                    MarkReferencedAssetsAsDirty(secondary);
                }
            }
        }

        TrackMappedAssetsWrites(format::kNullHandleId);
    }
}

void VulkanStateTracker::TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo2* pSubmits)
{
    if (pSubmits != nullptr && submitCount)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferInfoCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                        pSubmits[s].pCommandBufferInfos[c].commandBuffer);
                MarkReferencedAssetsAsDirty(primary);

                for (const auto secondary : primary->secondaries)
                {
                    MarkReferencedAssetsAsDirty(secondary);
                }
            }
        }

        TrackMappedAssetsWrites(format::kNullHandleId);
    }
}

void VulkanStateTracker::TrackBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo)
{
    if (commandBuffer != VK_NULL_HANDLE && pRenderingInfo != nullptr)
    {
        vulkan_wrappers::CommandBufferWrapper* wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(wrapper != nullptr);

        for (uint32_t i = 0; i < pRenderingInfo->colorAttachmentCount; ++i)
        {
            if (pRenderingInfo->pColorAttachments[i].storeOp == VK_ATTACHMENT_STORE_OP_STORE)
            {
                vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                        pRenderingInfo->pColorAttachments[i].imageView);
                assert(img_view_wrapper != nullptr);

                wrapper->modified_assets.insert(img_view_wrapper->image);
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr &&
            pRenderingInfo->pDepthAttachment->storeOp == VK_ATTACHMENT_STORE_OP_STORE)
        {
            vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                    pRenderingInfo->pDepthAttachment->imageView);
            assert(img_view_wrapper != nullptr);

            wrapper->modified_assets.insert(img_view_wrapper->image);
        }

        if (pRenderingInfo->pStencilAttachment != nullptr &&
            pRenderingInfo->pStencilAttachment->storeOp == VK_ATTACHMENT_STORE_OP_STORE)
        {
            vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                    pRenderingInfo->pStencilAttachment->imageView);
            assert(img_view_wrapper != nullptr);

            wrapper->modified_assets.insert(img_view_wrapper->image);
        }
    }
}

static void AssignDebugToObject(VkObjectType                        object_type,
                                uint64_t                            object_handle,
                                vulkan_state_info::CreateParameters object_name_parameter_buffer,
                                vulkan_state_info::CreateParameters object_tag_parameter_buffer)
{
    switch (object_type)
    {
        case VK_OBJECT_TYPE_INSTANCE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(
                    format::FromHandleId<VkInstance>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(
                    format::FromHandleId<VkInstance>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(
                    format::FromHandleId<VkPhysicalDevice>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(
                    format::FromHandleId<VkPhysicalDevice>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DEVICE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(
                    format::FromHandleId<VkDevice>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(
                    format::FromHandleId<VkDevice>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_QUEUE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(format::FromHandleId<VkQueue>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(format::FromHandleId<VkQueue>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SEMAPHORE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(
                    format::FromHandleId<VkSemaphore>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(
                    format::FromHandleId<VkSemaphore>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    format::FromHandleId<VkCommandBuffer>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    format::FromHandleId<VkCommandBuffer>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_FENCE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(format::FromHandleId<VkFence>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(format::FromHandleId<VkFence>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(
                    format::FromHandleId<VkDeviceMemory>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(
                    format::FromHandleId<VkDeviceMemory>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_BUFFER:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                    format::FromHandleId<VkBuffer>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                    format::FromHandleId<VkBuffer>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_IMAGE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(format::FromHandleId<VkImage>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(format::FromHandleId<VkImage>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_EVENT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::EventWrapper>(format::FromHandleId<VkEvent>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::EventWrapper>(format::FromHandleId<VkEvent>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_QUERY_POOL:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(
                    format::FromHandleId<VkQueryPool>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(
                    format::FromHandleId<VkQueryPool>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_BUFFER_VIEW:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                    format::FromHandleId<VkBufferView>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                    format::FromHandleId<VkBufferView>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_IMAGE_VIEW:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                    format::FromHandleId<VkImageView>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                    format::FromHandleId<VkImageView>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SHADER_MODULE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(
                    format::FromHandleId<VkShaderModule>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(
                    format::FromHandleId<VkShaderModule>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(
                    format::FromHandleId<VkPipelineCache>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineCacheWrapper>(
                    format::FromHandleId<VkPipelineCache>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(
                    format::FromHandleId<VkPipelineLayout>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineLayoutWrapper>(
                    format::FromHandleId<VkPipelineLayout>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_RENDER_PASS:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(
                    format::FromHandleId<VkRenderPass>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(
                    format::FromHandleId<VkRenderPass>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PIPELINE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(
                    format::FromHandleId<VkPipeline>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(
                    format::FromHandleId<VkPipeline>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(
                    format::FromHandleId<VkDescriptorSetLayout>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(
                    format::FromHandleId<VkDescriptorSetLayout>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SAMPLER:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(
                    format::FromHandleId<VkSampler>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(
                    format::FromHandleId<VkSampler>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(
                    format::FromHandleId<VkDescriptorPool>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(
                    format::FromHandleId<VkDescriptorPool>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(
                    format::FromHandleId<VkDescriptorSet>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(
                    format::FromHandleId<VkDescriptorSet>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_FRAMEBUFFER:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(
                    format::FromHandleId<VkFramebuffer>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(
                    format::FromHandleId<VkFramebuffer>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_COMMAND_POOL:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(
                    format::FromHandleId<VkCommandPool>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(
                    format::FromHandleId<VkCommandPool>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(
                    format::FromHandleId<VkSamplerYcbcrConversion>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerYcbcrConversionWrapper>(
                    format::FromHandleId<VkSamplerYcbcrConversion>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(
                    format::FromHandleId<VkDescriptorUpdateTemplate>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(
                    format::FromHandleId<VkDescriptorUpdateTemplate>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SURFACE_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(
                    format::FromHandleId<VkSurfaceKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(
                    format::FromHandleId<VkSurfaceKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(
                    format::FromHandleId<VkSwapchainKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(
                    format::FromHandleId<VkSwapchainKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DISPLAY_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(
                    format::FromHandleId<VkDisplayKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayKHRWrapper>(
                    format::FromHandleId<VkDisplayKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(
                    format::FromHandleId<VkDisplayModeKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DisplayModeKHRWrapper>(
                    format::FromHandleId<VkDisplayModeKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(
                    format::FromHandleId<VkDebugReportCallbackEXT>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugReportCallbackEXTWrapper>(
                    format::FromHandleId<VkDebugReportCallbackEXT>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(
                    format::FromHandleId<VkDebugUtilsMessengerEXT>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(
                    format::FromHandleId<VkDebugUtilsMessengerEXT>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                    format::FromHandleId<VkAccelerationStructureKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                    format::FromHandleId<VkAccelerationStructureKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(
                    format::FromHandleId<VkValidationCacheEXT>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ValidationCacheEXTWrapper>(
                    format::FromHandleId<VkValidationCacheEXT>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(
                    format::FromHandleId<VkPerformanceConfigurationINTEL>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(
                    format::FromHandleId<VkPerformanceConfigurationINTEL>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(
                    format::FromHandleId<VkDeferredOperationKHR>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(
                    format::FromHandleId<VkDeferredOperationKHR>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(
                    format::FromHandleId<VkIndirectCommandsLayoutNV>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(
                    format::FromHandleId<VkIndirectCommandsLayoutNV>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_MICROMAP_EXT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(
                    format::FromHandleId<VkMicromapEXT>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::MicromapEXTWrapper>(
                    format::FromHandleId<VkMicromapEXT>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PrivateDataSlotEXTWrapper>(
                    format::FromHandleId<VkPrivateDataSlotEXT>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PrivateDataSlotEXTWrapper>(
                    format::FromHandleId<VkPrivateDataSlotEXT>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            if (object_name_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(
                    format::FromHandleId<VkAccelerationStructureNV>(object_handle))
                    ->debug_name_create_parameters = std::move(object_name_parameter_buffer);
            }

            if (object_tag_parameter_buffer)
            {
                vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(
                    format::FromHandleId<VkAccelerationStructureNV>(object_handle))
                    ->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);
            }
            break;

        case VK_OBJECT_TYPE_UNKNOWN:
        default:
            break;
    }
}

void VulkanStateTracker::TrackSetDebugUtilsObjectNameEXT(VkDevice                             device,
                                                         const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                                         const util::MemoryOutputStream* object_name_parameter_buffer)
{
    AssignDebugToObject(pNameInfo->objectType,
                        pNameInfo->objectHandle,
                        std::make_shared<util::MemoryOutputStream>(object_name_parameter_buffer->GetData(),
                                                                   object_name_parameter_buffer->GetDataSize()),
                        nullptr);
}

void VulkanStateTracker::TrackSetDebugUtilsObjectTagEXT(VkDevice                            device,
                                                        const VkDebugUtilsObjectTagInfoEXT* pTagInfo,
                                                        const util::MemoryOutputStream*     object_tag_parameter_buffer)
{
    AssignDebugToObject(pTagInfo->objectType,
                        pTagInfo->objectHandle,
                        nullptr,
                        std::make_shared<util::MemoryOutputStream>(object_tag_parameter_buffer->GetData(),
                                                                   object_tag_parameter_buffer->GetDataSize()));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
