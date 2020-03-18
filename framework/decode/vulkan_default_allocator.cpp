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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanDefaultAllocator::VulkanDefaultAllocator() : device_(VK_NULL_HANDLE) {}

VkResult VulkanDefaultAllocator::Initialize(uint32_t                                api_version,
                                            VkInstance                              instance,
                                            VkPhysicalDevice                        physical_device,
                                            VkDevice                                device,
                                            const std::vector<std::string>&         enabled_device_extensions,
                                            const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                            const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                            const Functions&                        functions)
{
    GFXRECON_UNREFERENCED_PARAMETER(api_version);
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(enabled_device_extensions);
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
                                              VkBuffer*                    buffer,
                                              ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    return functions_.create_buffer(device_, create_info, allocation_callbacks, buffer);
}

void VulkanDefaultAllocator::DestroyBuffer(VkBuffer                     buffer,
                                           const VkAllocationCallbacks* allocation_callbacks,
                                           ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    functions_.destroy_buffer(device_, buffer, allocation_callbacks);
}

VkResult VulkanDefaultAllocator::CreateImage(const VkImageCreateInfo*     create_info,
                                             const VkAllocationCallbacks* allocation_callbacks,
                                             VkImage*                     image,
                                             ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    return functions_.create_image(device_, create_info, allocation_callbacks, image);
}

void VulkanDefaultAllocator::DestroyImage(VkImage                      image,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
    functions_.destroy_image(device_, image, allocation_callbacks);
}

VkResult VulkanDefaultAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                VkDeviceMemory*              memory,
                                                MemoryData*                  allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocate_info != nullptr) && (allocator_data != nullptr))
    {
        result = functions_.allocate_memory(device_, allocate_info, allocation_callbacks, memory);

        if (result >= 0)
        {
            assert(allocate_info->memoryTypeIndex < memory_properties_.memoryTypeCount);

            auto memory_alloc_info = new MemoryAllocInfo;
            memory_alloc_info->property_flags =
                memory_properties_.memoryTypes[allocate_info->memoryTypeIndex].propertyFlags;
            (*allocator_data) = reinterpret_cast<uintptr_t>(memory_alloc_info);
        }
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

    if ((data != nullptr) && (allocator_data != 0))
    {
        result = functions_.map_memory(device_, memory, offset, size, flags, data);

        if (result >= 0)
        {
            auto memory_alloc_info            = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
            memory_alloc_info->mapped_pointer = static_cast<uint8_t*>(*data);
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

void VulkanDefaultAllocator::WriteMappedMemoryRange(MemoryData     allocator_data,
                                                    uint64_t       offset,
                                                    uint64_t       size,
                                                    const uint8_t* data)
{
    if (allocator_data != 0)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        size_t copy_size         = static_cast<size_t>(size);
        auto   memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);

        util::platform::MemoryCopy(memory_alloc_info->mapped_pointer + offset, copy_size, data, copy_size);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
