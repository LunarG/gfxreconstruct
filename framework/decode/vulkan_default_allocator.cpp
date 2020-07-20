/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_default_allocator.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanDefaultAllocator::VulkanDefaultAllocator() : device_(VK_NULL_HANDLE), memory_properties_{} {}

VulkanDefaultAllocator::VulkanDefaultAllocator(const std::string& custom_error_string) :
    device_(VK_NULL_HANDLE), memory_properties_{}, custom_error_string_(custom_error_string)
{}

VulkanDefaultAllocator::VulkanDefaultAllocator(std::string&& custom_error_string) :
    device_(VK_NULL_HANDLE), memory_properties_{}, custom_error_string_(std::move(custom_error_string))
{}

VkResult VulkanDefaultAllocator::Initialize(uint32_t                                api_version,
                                            VkInstance                              instance,
                                            VkPhysicalDevice                        physical_device,
                                            VkDevice                                device,
                                            const std::vector<std::string>&         enabled_device_extensions,
                                            VkPhysicalDeviceType                    capture_device_type,
                                            const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                            const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                            const Functions&                        functions)
{
    GFXRECON_UNREFERENCED_PARAMETER(api_version);
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(enabled_device_extensions);
    GFXRECON_UNREFERENCED_PARAMETER(capture_device_type);
    GFXRECON_UNREFERENCED_PARAMETER(capture_memory_properties);

    device_            = device;
    functions_         = functions;
    memory_properties_ = replay_memory_properties;

    return VK_SUCCESS;
}

void VulkanDefaultAllocator::Destroy()
{
    device_ = VK_NULL_HANDLE;
}

VkResult VulkanDefaultAllocator::CreateBuffer(const VkBufferCreateInfo*    create_info,
                                              const VkAllocationCallbacks* allocation_callbacks,
                                              format::HandleId             capture_id,
                                              VkBuffer*                    buffer,
                                              ResourceData*                allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocator_data != nullptr)
    {
        auto resource_alloc_info        = new ResourceAllocInfo;
        resource_alloc_info->capture_id = capture_id;
        (*allocator_data)               = reinterpret_cast<ResourceData>(resource_alloc_info);

        result = functions_.create_buffer(device_, create_info, allocation_callbacks, buffer);
    }

    return result;
}

void VulkanDefaultAllocator::DestroyBuffer(VkBuffer                     buffer,
                                           const VkAllocationCallbacks* allocation_callbacks,
                                           ResourceData                 allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        delete resource_alloc_info;
    }

    functions_.destroy_buffer(device_, buffer, allocation_callbacks);
}

VkResult VulkanDefaultAllocator::CreateImage(const VkImageCreateInfo*     create_info,
                                             const VkAllocationCallbacks* allocation_callbacks,
                                             format::HandleId             capture_id,
                                             VkImage*                     image,
                                             ResourceData*                allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocator_data != nullptr)
    {
        auto resource_alloc_info        = new ResourceAllocInfo;
        resource_alloc_info->capture_id = capture_id;
        (*allocator_data)               = reinterpret_cast<ResourceData>(resource_alloc_info);

        result = functions_.create_image(device_, create_info, allocation_callbacks, image);
    }

    return result;
}

void VulkanDefaultAllocator::DestroyImage(VkImage                      image,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          ResourceData                 allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        delete resource_alloc_info;
    }

    functions_.destroy_image(device_, image, allocation_callbacks);
}

void VulkanDefaultAllocator::GetImageSubresourceLayout(VkImage                    image,
                                                       const VkImageSubresource*  subresource,
                                                       VkSubresourceLayout*       layout,
                                                       const VkSubresourceLayout* original_layout,
                                                       ResourceData               allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_layout);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    functions_.get_image_subresource_layout(device_, image, subresource, layout);
}

VkResult VulkanDefaultAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                format::HandleId             capture_id,
                                                VkDeviceMemory*              memory,
                                                MemoryData*                  allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocate_info != nullptr) && (allocator_data != nullptr) &&
        (allocate_info->memoryTypeIndex < memory_properties_.memoryTypeCount))
    {
        result = Allocate(allocate_info, allocation_callbacks, capture_id, memory, allocator_data);
    }

    return result;
}

void VulkanDefaultAllocator::FreeMemory(VkDeviceMemory               memory,
                                        const VkAllocationCallbacks* allocation_callbacks,
                                        MemoryData                   allocator_data)
{
    if (allocator_data != 0)
    {
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        delete memory_alloc_info;
    }
    else if (memory != VK_NULL_HANDLE)
    {
        GFXRECON_LOG_WARNING("VulkanDefaultAllocator freeing a VkDeviceMemory object without allocator data");
    }

    functions_.free_memory(device_, memory, allocation_callbacks);
}

void VulkanDefaultAllocator::GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                                       VkDeviceSize*  committed_memory_in_bytes,
                                                       MemoryData     allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    functions_.get_device_memory_commitment(device_, memory, committed_memory_in_bytes);
}

VkResult VulkanDefaultAllocator::BindBufferMemory(VkBuffer               buffer,
                                                  VkDeviceMemory         memory,
                                                  VkDeviceSize           memory_offset,
                                                  ResourceData           allocator_buffer_data,
                                                  MemoryData             allocator_memory_data,
                                                  VkMemoryPropertyFlags* bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_buffer_data);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (bind_memory_properties != nullptr)
    {
        if (allocator_memory_data != 0)
        {
            auto memory_alloc_info    = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
            (*bind_memory_properties) = memory_alloc_info->property_flags;
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "VulkanDefaultAllocator binding a VkBuffer object to a VkDeviceMemory object without allocator data");
        }

        result = functions_.bind_buffer_memory(device_, buffer, memory, memory_offset);
    }

    return result;
}

VkResult VulkanDefaultAllocator::BindBufferMemory2(uint32_t                      bind_info_count,
                                                   const VkBindBufferMemoryInfo* bind_infos,
                                                   const ResourceData*           allocator_buffer_datas,
                                                   const MemoryData*             allocator_memory_datas,
                                                   VkMemoryPropertyFlags*        bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_buffer_datas);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocator_memory_datas != nullptr) && (bind_memory_properties != nullptr))
    {
        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            auto allocator_memory_data = allocator_memory_datas[i];

            if (allocator_memory_data != 0)
            {
                auto memory_alloc_info    = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                bind_memory_properties[i] = memory_alloc_info->property_flags;
            }
            else
            {
                GFXRECON_LOG_WARNING("VulkanDefaultAllocator binding a VkBuffer object to a VkDeviceMemory object "
                                     "without allocator data");
            }
        }

        result = functions_.bind_buffer_memory2(device_, bind_info_count, bind_infos);
    }

    return result;
}

VkResult VulkanDefaultAllocator::BindImageMemory(VkImage                image,
                                                 VkDeviceMemory         memory,
                                                 VkDeviceSize           memory_offset,
                                                 ResourceData           allocator_image_data,
                                                 MemoryData             allocator_memory_data,
                                                 VkMemoryPropertyFlags* bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_image_data);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (bind_memory_properties != nullptr)
    {
        if (allocator_memory_data != 0)
        {
            auto memory_alloc_info    = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
            (*bind_memory_properties) = memory_alloc_info->property_flags;
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "VulkanDefaultAllocator binding a VkImage object to a VkDeviceMemory object without allocator data");
        }

        result = functions_.bind_image_memory(device_, image, memory, memory_offset);
    }

    return result;
}

VkResult VulkanDefaultAllocator::BindImageMemory2(uint32_t                     bind_info_count,
                                                  const VkBindImageMemoryInfo* bind_infos,
                                                  const ResourceData*          allocator_image_datas,
                                                  const MemoryData*            allocator_memory_datas,
                                                  VkMemoryPropertyFlags*       bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_image_datas);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocator_memory_datas != nullptr) && (bind_memory_properties != nullptr))
    {
        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            auto allocator_memory_data = allocator_memory_datas[i];

            if (allocator_memory_data != 0)
            {
                auto memory_alloc_info    = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                bind_memory_properties[i] = memory_alloc_info->property_flags;
            }
            else
            {
                GFXRECON_LOG_WARNING("VulkanDefaultAllocator binding a VkImage object to a VkDeviceMemory object "
                                     "without allocator data");
            }
        }

        result = functions_.bind_image_memory2(device_, bind_info_count, bind_infos);
    }

    return result;
}

VkResult VulkanDefaultAllocator::MapMemory(VkDeviceMemory   memory,
                                           VkDeviceSize     offset,
                                           VkDeviceSize     size,
                                           VkMemoryMapFlags flags,
                                           void**           data,
                                           MemoryData       allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (data != nullptr)
    {
        result = functions_.map_memory(device_, memory, offset, size, flags, data);

        if (result >= 0)
        {
            if (allocator_data != 0)
            {
                auto memory_alloc_info            = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
                memory_alloc_info->mapped_pointer = static_cast<uint8_t*>(*data);
            }
            else
            {
                GFXRECON_LOG_WARNING("VulkanDefaultAllocator mapping a VkDeviceMemory object without allocator data");
            }
        }
    }

    return result;
}

void VulkanDefaultAllocator::UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data)
{
    if (allocator_data != 0)
    {
        auto memory_alloc_info            = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        memory_alloc_info->mapped_pointer = nullptr;
    }

    functions_.unmap_memory(device_, memory);
}

VkResult VulkanDefaultAllocator::FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                                         const VkMappedMemoryRange* memory_ranges,
                                                         const MemoryData*          allocator_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_datas);
    return functions_.flush_memory_ranges(device_, memory_range_count, memory_ranges);
}

VkResult VulkanDefaultAllocator::InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                              const VkMappedMemoryRange* memory_ranges,
                                                              const MemoryData*          allocator_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_datas);
    return functions_.invalidate_memory_ranges(device_, memory_range_count, memory_ranges);
}

VkResult VulkanDefaultAllocator::WriteMappedMemoryRange(MemoryData     allocator_data,
                                                        uint64_t       offset,
                                                        uint64_t       size,
                                                        const uint8_t* data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocator_data != 0)
    {
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);

        if (memory_alloc_info->mapped_pointer != nullptr)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

            size_t copy_size = static_cast<size_t>(size);

            util::platform::MemoryCopy(memory_alloc_info->mapped_pointer + offset, copy_size, data, copy_size);

            result = VK_SUCCESS;
        }
        else
        {
            result = VK_ERROR_MEMORY_MAP_FAILED;
        }
    }

    return result;
}

void VulkanDefaultAllocator::ReportAllocateMemoryIncompatibility(const VkMemoryAllocateInfo* allocate_info)
{
    if ((allocate_info != nullptr) && (allocate_info->memoryTypeIndex >= memory_properties_.memoryTypeCount))
    {
        GFXRECON_LOG_FATAL(
            "Memory allocation failed: specified memory type index exceeds number of available memory types.");

        if (!custom_error_string_.empty())
        {
            GFXRECON_LOG_FATAL("%s", custom_error_string_.c_str());
        }
    }
}

void VulkanDefaultAllocator::ReportBindBufferIncompatibility(VkBuffer     buffer,
                                                             ResourceData allocator_resource_data,
                                                             MemoryData   allocator_memory_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_resource_data);

    if (allocator_memory_data != 0)
    {
        VkMemoryRequirements requirements;
        functions_.get_buffer_memory_requirements(device_, buffer, &requirements);
        ReportBindIncompatibility(&requirements, &allocator_memory_data, 1);
    }
}

void VulkanDefaultAllocator::ReportBindBuffer2Incompatibility(uint32_t                      bind_info_count,
                                                              const VkBindBufferMemoryInfo* bind_infos,
                                                              const ResourceData*           allocator_resource_datas,
                                                              const MemoryData*             allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_resource_datas);

    if ((bind_infos != nullptr) && (allocator_memory_datas != nullptr))
    {
        std::vector<VkMemoryRequirements> requirements(bind_info_count);

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            functions_.get_buffer_memory_requirements(device_, bind_infos[i].buffer, &requirements[i]);
        }

        ReportBindIncompatibility(requirements.data(), allocator_memory_datas, bind_info_count);
    }
}

void VulkanDefaultAllocator::ReportBindImageIncompatibility(VkImage      image,
                                                            ResourceData allocator_resource_data,
                                                            MemoryData   allocator_memory_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_resource_data);

    if (allocator_memory_data != 0)
    {
        VkMemoryRequirements requirements;
        functions_.get_image_memory_requirements(device_, image, &requirements);
        ReportBindIncompatibility(&requirements, &allocator_memory_data, 1);
    }
}

void VulkanDefaultAllocator::ReportBindImage2Incompatibility(uint32_t                     bind_info_count,
                                                             const VkBindImageMemoryInfo* bind_infos,
                                                             const ResourceData*          allocator_resource_datas,
                                                             const MemoryData*            allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_resource_datas);

    if ((bind_infos != nullptr) && (allocator_memory_datas != nullptr))
    {
        std::vector<VkMemoryRequirements> requirements(bind_info_count);

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            functions_.get_image_memory_requirements(device_, bind_infos[i].image, &requirements[i]);
        }

        ReportBindIncompatibility(requirements.data(), allocator_memory_datas, bind_info_count);
    }
}

void VulkanDefaultAllocator::ReportBindIncompatibility(const VkMemoryRequirements* requirements,
                                                       const MemoryData*           allocator_memory_datas,
                                                       uint32_t                    resource_count)
{
    assert((requirements != nullptr) && (allocator_memory_datas != nullptr));

    for (uint32_t i = 0; i < resource_count; ++i)
    {
        auto allocator_memory_data = allocator_memory_datas[i];

        if (allocator_memory_data != 0)
        {
            auto     memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
            uint32_t memory_type_index = memory_alloc_info->memory_type_index;

            if ((requirements[i].memoryTypeBits & (1 << memory_type_index)) != 0)
            {
                GFXRECON_LOG_FATAL(
                    "Resource memory bind failed: resource is not compatible with the specified memory type.");

                if (!custom_error_string_.empty())
                {
                    GFXRECON_LOG_FATAL("%s", custom_error_string_.c_str());
                }

                break;
            }
        }
    }
}

VkResult VulkanDefaultAllocator::Allocate(const VkMemoryAllocateInfo*  allocate_info,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          format::HandleId             capture_id,
                                          VkDeviceMemory*              memory,
                                          MemoryData*                  allocator_data)
{
    assert((allocate_info != nullptr) && (allocator_data != nullptr));

    VkResult result = functions_.allocate_memory(device_, allocate_info, allocation_callbacks, memory);

    if (result >= 0)
    {
        assert(allocate_info->memoryTypeIndex < memory_properties_.memoryTypeCount);

        auto memory_alloc_info               = new MemoryAllocInfo;
        memory_alloc_info->capture_id        = capture_id;
        memory_alloc_info->memory_type_index = allocate_info->memoryTypeIndex;
        memory_alloc_info->property_flags =
            memory_properties_.memoryTypes[allocate_info->memoryTypeIndex].propertyFlags;
        (*allocator_data) = reinterpret_cast<MemoryData>(memory_alloc_info);
    }

    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
