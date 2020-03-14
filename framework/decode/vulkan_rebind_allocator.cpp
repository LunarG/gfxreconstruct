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

// This file needs to be included first to ensure it is processed with the VMA_IMPLEMENTATION directive, in case it is
// indirectly included by other include files.
#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

#include "decode/vulkan_rebind_allocator.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_enum_util.h"
#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/platform.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const format::HandleId kPlaceholderHandleId = static_cast<format::HandleId>(~0);
const uintptr_t        kPlaceholderAddress  = static_cast<uintptr_t>(~0);

VulkanRebindAllocator::VulkanRebindAllocator() : device_(VK_NULL_HANDLE), allocator_(VK_NULL_HANDLE) {}

VulkanRebindAllocator::~VulkanRebindAllocator() {}

VkResult VulkanRebindAllocator::Initialize(uint32_t                                api_version,
                                           VkInstance                              instance,
                                           VkPhysicalDevice                        physical_device,
                                           VkDevice                                device,
                                           const std::vector<std::string>&         enabled_device_extensions,
                                           const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                           const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                           const Functions&                        functions)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocator_ == VK_NULL_HANDLE)
    {
        device_                    = device;
        functions_                 = functions;
        capture_memory_properties_ = capture_memory_properties;
        replay_memory_properties_  = replay_memory_properties;

        vma_functions_.vkGetPhysicalDeviceProperties           = functions_.get_physical_device_properties;
        vma_functions_.vkGetPhysicalDeviceMemoryProperties     = functions_.get_physical_device_memory_properties;
        vma_functions_.vkAllocateMemory                        = functions_.allocate_memory;
        vma_functions_.vkFreeMemory                            = functions_.free_memory;
        vma_functions_.vkMapMemory                             = functions_.map_memory;
        vma_functions_.vkUnmapMemory                           = functions_.unmap_memory;
        vma_functions_.vkFlushMappedMemoryRanges               = functions_.flush_memory_ranges;
        vma_functions_.vkInvalidateMappedMemoryRanges          = functions_.invalidate_memory_ranges;
        vma_functions_.vkBindBufferMemory                      = functions_.bind_buffer_memory;
        vma_functions_.vkBindImageMemory                       = functions_.bind_image_memory;
        vma_functions_.vkGetBufferMemoryRequirements           = functions_.get_buffer_memory_requirements;
        vma_functions_.vkGetImageMemoryRequirements            = functions_.get_image_memory_requirements;
        vma_functions_.vkCreateBuffer                          = functions_.create_buffer;
        vma_functions_.vkDestroyBuffer                         = functions_.destroy_buffer;
        vma_functions_.vkCreateImage                           = functions_.create_image;
        vma_functions_.vkDestroyImage                          = functions_.destroy_image;
        vma_functions_.vkCmdCopyBuffer                         = functions_.cmd_copy_buffer;
        vma_functions_.vkGetBufferMemoryRequirements2KHR       = functions_.get_buffer_memory_requirements2;
        vma_functions_.vkGetImageMemoryRequirements2KHR        = functions_.get_image_memory_requirements2;
        vma_functions_.vkBindBufferMemory2KHR                  = functions_.bind_buffer_memory2;
        vma_functions_.vkBindImageMemory2KHR                   = functions_.bind_image_memory2;
        vma_functions_.vkGetPhysicalDeviceMemoryProperties2KHR = functions_.get_physical_device_memory_properties2;

        VmaAllocatorCreateInfo create_info = {};

        create_info.physicalDevice   = physical_device;
        create_info.device           = device;
        create_info.pVulkanFunctions = &vma_functions_;
        create_info.instance         = instance;
        create_info.vulkanApiVersion = api_version;

        // Select creation flags from enabled extensions.
        bool have_memory_reqs2         = false;
        bool have_dedicated_allocation = false;

        for (const auto& entry : enabled_device_extensions)
        {
            if (entry == VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME)
            {
                have_memory_reqs2 = true;
            }
            else if (entry == VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME)
            {
                have_dedicated_allocation = true;
            }
            else if (entry == VK_KHR_BIND_MEMORY_2_EXTENSION_NAME)
            {
                create_info.flags |= VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT;
            }
            else if (entry == VK_EXT_MEMORY_BUDGET_EXTENSION_NAME)
            {
                // Note that this assumes that the VK_KHR_get_physical_device_properties2 instance extension was also
                // enabled by the captured application.
                create_info.flags |= VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT;
            }
            else if (entry == VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME)
            {
                create_info.flags |= VMA_ALLOCATOR_CREATE_AMD_DEVICE_COHERENT_MEMORY_BIT;
            }
        }

        if (have_memory_reqs2 && have_dedicated_allocation)
        {
            create_info.flags |= VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT;
        }

        result = vmaCreateAllocator(&create_info, &allocator_);
    }

    return result;
}

void VulkanRebindAllocator::Destroy()
{
    if (allocator_ != VK_NULL_HANDLE)
    {
        vmaDestroyAllocator(allocator_);
        allocator_ = VK_NULL_HANDLE;
    }

    device_ = VK_NULL_HANDLE;
}

VkResult VulkanRebindAllocator::CreateBuffer(const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
                                             const VkAllocationCallbacks*                            pAllocator,
                                             HandlePointerDecoder<VkBuffer>*                         pBuffer)
{
    return functions_.create_buffer(device_, pCreateInfo.GetPointer(), pAllocator, pBuffer->GetHandlePointer());
}

void VulkanRebindAllocator::DestroyBuffer(BufferInfo* buffer_info, const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (buffer_info->allocator_info != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(buffer_info->allocator_info);
        auto memory_alloc_info   = resource_alloc_info->memory_info;

        if (memory_alloc_info != nullptr)
        {
            memory_alloc_info->original_buffers.erase(buffer_info->handle);
        }

        if (resource_alloc_info->mapped_pointer != nullptr)
        {
            vmaUnmapMemory(allocator_, resource_alloc_info->allocation);
        }

        vmaDestroyBuffer(allocator_, buffer_info->handle, resource_alloc_info->allocation);

        delete resource_alloc_info;
        buffer_info->allocator_info = 0;
    }
}

VkResult VulkanRebindAllocator::CreateImage(const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
                                            const VkAllocationCallbacks*                           pAllocator,
                                            HandlePointerDecoder<VkImage>*                         pImage)
{
    return functions_.create_image(device_, pCreateInfo.GetPointer(), pAllocator, pImage->GetHandlePointer());
}

void VulkanRebindAllocator::DestroyImage(ImageInfo* image_info, const VkAllocationCallbacks* pAllocator)
{
    if (image_info->allocator_info != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(image_info->allocator_info);
        auto memory_alloc_info   = resource_alloc_info->memory_info;

        if (memory_alloc_info != nullptr)
        {
            memory_alloc_info->original_images.erase(image_info->handle);
        }

        if (resource_alloc_info->mapped_pointer != nullptr)
        {
            vmaUnmapMemory(allocator_, resource_alloc_info->allocation);
        }

        vmaDestroyImage(allocator_, image_info->handle, resource_alloc_info->allocation);

        delete resource_alloc_info;
        image_info->allocator_info = 0;
    }
}

VkResult VulkanRebindAllocator::AllocateMemory(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                               const VkAllocationCallbacks*                              pAllocator,
                                               HandlePointerDecoder<VkDeviceMemory>*                     pMemory)
{
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    auto* handle_id = pMemory->GetPointer();
    if ((handle_id != nullptr) && ((*handle_id) != 0))
    {
        const VkMemoryAllocateInfo* capture_allocate_info = pAllocateInfo.GetPointer();
        auto                        memory_handle = reinterpret_cast<VkDeviceMemory*>(pMemory->GetHandlePointer());
        auto                        memory_info   = reinterpret_cast<DeviceMemoryInfo*>(pMemory->GetConsumerData(0));
        assert((memory_info != nullptr) && (memory_info->allocator_info == 0));

        // With rebinding, memory allocations are managed by VMA.  We just store the size and memory type index for the
        // VkDeviceMemory object here.  If the VkDeviceMemory object is mapped, the size will be used to create a system
        // memory allocation that will be used to reconstruct the content of the original memory object.  The
        // reconstructed data will be used to populate the memory allocations created by VMA.
        auto memory_alloc_info             = new MemoryAllocInfo;
        memory_alloc_info->allocation_size = capture_allocate_info->allocationSize;
        memory_alloc_info->original_index  = capture_allocate_info->memoryTypeIndex;

        (*memory_handle)            = format::FromHandleId<VkDeviceMemory>(kPlaceholderHandleId);
        memory_info->allocator_info = reinterpret_cast<uintptr_t>(memory_alloc_info);

        return VK_SUCCESS;
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void VulkanRebindAllocator::FreeMemory(DeviceMemoryInfo* memory_info, const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((memory_info != nullptr) && (memory_info->allocator_info != 0))
    {
        // Clear references from resources to the allocation info and cleanup allocation info memory.
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

        for (const auto& entry : memory_alloc_info->original_buffers)
        {
            entry.second->memory_info = nullptr;
        }

        for (const auto& entry : memory_alloc_info->original_images)
        {
            entry.second->memory_info = nullptr;
        }

        delete memory_alloc_info;
        memory_info->allocator_info = 0;
    }
}

void VulkanRebindAllocator::GetDeviceMemoryCommitment(const DeviceMemoryInfo* memory_info,
                                                      VkDeviceSize*           pCommittedMemoryInBytes)
{
    // We don't have a valid memory handle for this call.
    GFXRECON_UNREFERENCED_PARAMETER(memory_info);
    GFXRECON_UNREFERENCED_PARAMETER(pCommittedMemoryInBytes);
}

VkResult VulkanRebindAllocator::BindBufferMemory(BufferInfo*       buffer_info,
                                                 DeviceMemoryInfo* memory_info,
                                                 VkDeviceSize      memoryOffset)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((memory_info != nullptr) && (memory_info->allocator_info != 0) && (buffer_info != nullptr) &&
        (buffer_info->handle != VK_NULL_HANDLE))
    {
        VmaAllocation allocation        = VK_NULL_HANDLE;
        auto          memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

        VkMemoryRequirements requirements;
        functions_.get_buffer_memory_requirements(device_, buffer_info->handle, &requirements);

        VmaAllocationCreateInfo create_info;
        create_info.flags = 0;
        create_info.usage = GetBufferMemoryUsage(
            buffer_info->usage,
            capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
            requirements);
        create_info.requiredFlags  = 0;
        create_info.preferredFlags = 0;
        create_info.memoryTypeBits = 0;
        create_info.pool           = VK_NULL_HANDLE;
        create_info.pUserData      = nullptr;

        VmaAllocationInfo allocation_info;
        result =
            vmaAllocateMemoryForBuffer(allocator_, buffer_info->handle, &create_info, &allocation, &allocation_info);

        if (result >= 0)
        {
            result = vmaBindBufferMemory(allocator_, allocation, buffer_info->handle);

            if (result >= 0)
            {
                auto resource_alloc_info = new ResourceAllocInfo;

                resource_alloc_info->allocation      = allocation;
                resource_alloc_info->mapped_pointer  = nullptr;
                resource_alloc_info->memory_info     = memory_alloc_info;
                resource_alloc_info->original_offset = memoryOffset;
                resource_alloc_info->rebind_offset   = allocation_info.offset;
                resource_alloc_info->size            = allocation_info.size;
                resource_alloc_info->is_image        = false;

                if ((replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags &
                     VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    resource_alloc_info->is_host_visible = true;
                }

                if (memory_alloc_info->original_content != nullptr)
                {
                    // Memory has been mapped and written prior to bind.  Copy the original content to the new
                    // allocation to ensure it contains the correct data.
                    WriteBoundResource(resource_alloc_info,
                                       memoryOffset,
                                       0,
                                       allocation_info.size,
                                       memory_alloc_info->original_content.get());
                }

                memory_alloc_info->original_buffers.insert(std::make_pair(buffer_info->handle, resource_alloc_info));
                buffer_info->allocator_info = reinterpret_cast<uintptr_t>(resource_alloc_info);
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindBufferMemory2(uint32_t                      bindInfoCount,
                                                  const VkBindBufferMemoryInfo* pBindInfos,
                                                  DeviceMemoryInfo* const*      memory_infos,
                                                  BufferInfo* const*            buffer_infos)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((pBindInfos != nullptr) && (memory_infos != nullptr) && (buffer_infos != nullptr))
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            auto memory_info = memory_infos[i];
            auto buffer_info = buffer_infos[i];

            if ((memory_info != nullptr) && (memory_info->allocator_info != 0) && (buffer_info != nullptr) &&
                (buffer_info->handle != VK_NULL_HANDLE))
            {
                VmaAllocation allocation        = VK_NULL_HANDLE;
                auto          memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

                VkMemoryRequirements requirements;
                functions_.get_buffer_memory_requirements(device_, buffer_info->handle, &requirements);

                VmaAllocationCreateInfo create_info;
                create_info.flags = 0;
                create_info.usage = GetBufferMemoryUsage(
                    buffer_info->usage,
                    capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                    requirements);
                create_info.requiredFlags  = 0;
                create_info.preferredFlags = 0;
                create_info.memoryTypeBits = 0;
                create_info.pool           = VK_NULL_HANDLE;
                create_info.pUserData      = nullptr;

                VmaAllocationInfo allocation_info;
                result = vmaAllocateMemoryForBuffer(
                    allocator_, buffer_info->handle, &create_info, &allocation, &allocation_info);

                if (result >= 0)
                {
                    auto bind_info = &pBindInfos[i];

                    result = vmaBindBufferMemory2(allocator_, allocation, 0, buffer_info->handle, bind_info->pNext);

                    if (result >= 0)
                    {
                        auto resource_alloc_info = new ResourceAllocInfo;

                        resource_alloc_info->allocation      = allocation;
                        resource_alloc_info->mapped_pointer  = nullptr;
                        resource_alloc_info->memory_info     = memory_alloc_info;
                        resource_alloc_info->original_offset = bind_info->memoryOffset;
                        resource_alloc_info->rebind_offset   = allocation_info.offset;
                        resource_alloc_info->size            = allocation_info.size;
                        resource_alloc_info->is_image        = false;

                        if ((replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags &
                             VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                        {
                            resource_alloc_info->is_host_visible = true;
                        }

                        if (memory_alloc_info->original_content != nullptr)
                        {
                            // Memory has been mapped and written prior to bind.  Copy the original content to the new
                            // allocation to ensure it contains the correct data.
                            WriteBoundResource(resource_alloc_info,
                                               bind_info->memoryOffset,
                                               0,
                                               allocation_info.size,
                                               memory_alloc_info->original_content.get());
                        }

                        memory_alloc_info->original_buffers.insert(
                            std::make_pair(buffer_info->handle, resource_alloc_info));
                        buffer_info->allocator_info = reinterpret_cast<uintptr_t>(resource_alloc_info);
                    }
                }
            }
        }
    }

    return result;
}

VkResult
VulkanRebindAllocator::BindImageMemory(ImageInfo* image_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((memory_info != nullptr) && (memory_info->allocator_info != 0) && (image_info != nullptr) &&
        (image_info->handle != VK_NULL_HANDLE))
    {
        VmaAllocation allocation        = VK_NULL_HANDLE;
        auto          memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

        VkMemoryRequirements requirements;
        functions_.get_image_memory_requirements(device_, image_info->handle, &requirements);

        VmaAllocationCreateInfo create_info;
        create_info.flags = 0;
        create_info.usage =
            GetImageMemoryUsage(image_info->usage,
                                image_info->tiling,
                                capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                                requirements);
        create_info.requiredFlags  = 0;
        create_info.preferredFlags = 0;
        create_info.memoryTypeBits = 0;
        create_info.pool           = VK_NULL_HANDLE;
        create_info.pUserData      = nullptr;

        VmaAllocationInfo allocation_info;
        result = vmaAllocateMemoryForImage(allocator_, image_info->handle, &create_info, &allocation, &allocation_info);

        if (result >= 0)
        {
            result = vmaBindImageMemory(allocator_, allocation, image_info->handle);

            if (result >= 0)
            {
                auto resource_alloc_info = new ResourceAllocInfo;

                resource_alloc_info->allocation      = allocation;
                resource_alloc_info->mapped_pointer  = nullptr;
                resource_alloc_info->memory_info     = memory_alloc_info;
                resource_alloc_info->original_offset = memoryOffset;
                resource_alloc_info->rebind_offset   = allocation_info.offset;
                resource_alloc_info->size            = allocation_info.size;
                resource_alloc_info->is_image        = true;

                if ((replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags &
                     VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    resource_alloc_info->is_host_visible = true;
                }

                if (memory_alloc_info->original_content != nullptr)
                {
                    // Memory has been mapped and written prior to bind.  Copy the original content to the new
                    // allocation to ensure it contains the correct data.
                    WriteBoundResource(resource_alloc_info,
                                       memoryOffset,
                                       0,
                                       allocation_info.size,
                                       memory_alloc_info->original_content.get());
                }

                memory_alloc_info->original_images.insert(std::make_pair(image_info->handle, resource_alloc_info));
                image_info->allocator_info = reinterpret_cast<uintptr_t>(resource_alloc_info);
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindImageMemory2(uint32_t                     bindInfoCount,
                                                 const VkBindImageMemoryInfo* pBindInfos,
                                                 DeviceMemoryInfo* const*     memory_infos,
                                                 ImageInfo* const*            image_infos)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((pBindInfos != nullptr) && (memory_infos != nullptr) && (image_infos != nullptr))
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            auto memory_info = memory_infos[i];
            auto image_info  = image_infos[i];

            if ((memory_info != nullptr) && (memory_info->allocator_info != 0) && (image_info != nullptr) &&
                (image_info->handle != VK_NULL_HANDLE))
            {
                VmaAllocation allocation        = VK_NULL_HANDLE;
                auto          memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

                VkMemoryRequirements requirements;
                functions_.get_image_memory_requirements(device_, image_info->handle, &requirements);

                VmaAllocationCreateInfo create_info;
                create_info.flags = 0;
                create_info.usage = GetImageMemoryUsage(
                    image_info->usage,
                    image_info->tiling,
                    capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                    requirements);
                create_info.requiredFlags  = 0;
                create_info.preferredFlags = 0;
                create_info.memoryTypeBits = 0;
                create_info.pool           = VK_NULL_HANDLE;
                create_info.pUserData      = nullptr;

                VmaAllocationInfo allocation_info;
                result = vmaAllocateMemoryForImage(
                    allocator_, image_info->handle, &create_info, &allocation, &allocation_info);

                if (result >= 0)
                {
                    auto bind_info = &pBindInfos[i];

                    result = vmaBindImageMemory2(allocator_, allocation, 0, image_info->handle, bind_info->pNext);

                    if (result >= 0)
                    {
                        auto resource_alloc_info = new ResourceAllocInfo;

                        resource_alloc_info->allocation      = allocation;
                        resource_alloc_info->mapped_pointer  = nullptr;
                        resource_alloc_info->memory_info     = memory_alloc_info;
                        resource_alloc_info->original_offset = bind_info->memoryOffset;
                        resource_alloc_info->rebind_offset   = allocation_info.offset;
                        resource_alloc_info->size            = allocation_info.size;
                        resource_alloc_info->is_image        = true;

                        if ((replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags &
                             VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                        {
                            resource_alloc_info->is_host_visible = true;
                        }

                        if (memory_alloc_info->original_content != nullptr)
                        {
                            // Memory has been mapped and written prior to bind.  Copy the original content to the new
                            // allocation to ensure it contains the correct data.
                            WriteBoundResource(resource_alloc_info,
                                               bind_info->memoryOffset,
                                               0,
                                               allocation_info.size,
                                               memory_alloc_info->original_content.get());
                        }

                        memory_alloc_info->original_images.insert(
                            std::make_pair(image_info->handle, resource_alloc_info));
                        image_info->allocator_info = reinterpret_cast<uintptr_t>(resource_alloc_info);
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::MapMemory(
    DeviceMemoryInfo* memory_info, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
    VkResult result = VK_ERROR_MEMORY_MAP_FAILED;

    if ((memory_info != nullptr) && (memory_info->allocator_info != 0))
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);
        memory_alloc_info->is_mapped     = true;
        memory_alloc_info->mapped_offset = offset;
        result                           = VK_SUCCESS;
        (*ppData)                        = reinterpret_cast<void*>(kPlaceholderAddress);
    }

    return result;
}

void VulkanRebindAllocator::UnmapMemory(DeviceMemoryInfo* memory_info)
{
    if ((memory_info != nullptr) && (memory_info->allocator_info != 0))
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);
        memory_alloc_info->is_mapped     = false;
        memory_alloc_info->mapped_offset = 0;
    }
}

VkResult VulkanRebindAllocator::FlushMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                                        const VkMappedMemoryRange* pMemoryRanges,
                                                        DeviceMemoryInfo* const*   memory_infos)
{
    return UpdateMappedMemoryRanges(memoryRangeCount, pMemoryRanges, memory_infos, vmaFlushAllocation);
}

VkResult VulkanRebindAllocator::InvalidateMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                                             const VkMappedMemoryRange* pMemoryRanges,
                                                             DeviceMemoryInfo* const*   memory_infos)
{
    return UpdateMappedMemoryRanges(memoryRangeCount, pMemoryRanges, memory_infos, vmaInvalidateAllocation);
}

void VulkanRebindAllocator::WriteMappedMemoryRange(const DeviceMemoryInfo* memory_info,
                                                   uint64_t                offset,
                                                   uint64_t                size,
                                                   const uint8_t*          data)
{
    if ((memory_info != nullptr) && (memory_info->allocator_info != 0))
    {
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);

        assert(memory_alloc_info->is_mapped);

        if (memory_alloc_info->original_content == nullptr)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, memory_alloc_info->allocation_size);
            size_t allocation_size = static_cast<size_t>(memory_alloc_info->allocation_size);

            memory_alloc_info->original_content = std::make_unique<uint8_t[]>(allocation_size);
        }

        // Update the reconstructed memory, which is written to memory allocations performed at resource bind to ensure
        // they contain the correct data.
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
        size_t copy_size = static_cast<size_t>(size);

        util::platform::MemoryCopy(memory_alloc_info->original_content.get() + offset, copy_size, data, copy_size);

        VkDeviceSize write_start = memory_alloc_info->mapped_offset + offset;
        VkDeviceSize write_end   = write_start + size;

        // Copy to the resources that were bound to this range at capture.
        for (const auto& entry : memory_alloc_info->original_buffers)
        {
            UpdateBoundResource(entry.second, write_start, write_end, data);
        }

        for (const auto& entry : memory_alloc_info->original_images)
        {
            UpdateBoundResource(entry.second, write_start, write_end, data);
        }
    }
}

void VulkanRebindAllocator::WriteBoundResource(ResourceAllocInfo* resource_alloc_info,
                                               VkDeviceSize       src_offset,
                                               VkDeviceSize       dst_offset,
                                               VkDeviceSize       data_size,
                                               const uint8_t*     data)
{
    assert(resource_alloc_info != nullptr);

    if (resource_alloc_info->is_host_visible)
    {
        VkResult result = VK_SUCCESS;

        if (resource_alloc_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            result = vmaMapMemory(allocator_, resource_alloc_info->allocation, &resource_alloc_info->mapped_pointer);
        }

        if ((result == VK_SUCCESS) && (resource_alloc_info->mapped_pointer != nullptr))
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, src_offset);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, dst_offset);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);

            size_t copy_src_offset = static_cast<size_t>(src_offset);
            size_t copy_dst_offset = static_cast<size_t>(dst_offset);
            size_t copy_size       = static_cast<size_t>(data_size);

            if (!resource_alloc_info->is_image)
            {
                util::platform::MemoryCopy(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer) + copy_dst_offset,
                                           copy_size,
                                           data + copy_src_offset,
                                           copy_size);
            }
            else
            {
                // TODO: Copy needs to be row pitch aware.
                util::platform::MemoryCopy(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer) + copy_dst_offset,
                                           copy_size,
                                           data + copy_src_offset,
                                           copy_size);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to map device memory: vmaMapMemory returned %s",
                               enumutil::GetResultValueString(result));
        }
    }
    else
    {
        // TODO: Staging copy.
        GFXRECON_LOG_WARNING("Skipping mapped memory write the needs to be converted to a staging copy");
    }
}

bool VulkanRebindAllocator::TranslateMemoryRange(const ResourceAllocInfo* resource_alloc_info,
                                                 VkDeviceSize             original_start,
                                                 VkDeviceSize             original_end,
                                                 VkDeviceSize*            src_offset,
                                                 VkDeviceSize*            dst_offset,
                                                 VkDeviceSize*            data_size)
{
    assert((src_offset != nullptr) && (dst_offset != nullptr) && (data_size));

    VkDeviceSize resource_start = resource_alloc_info->original_offset;
    VkDeviceSize resource_end   = resource_start + resource_alloc_info->size;

    // Range ends are exclusive.
    if ((resource_end <= original_start) || (original_end <= resource_start))
    {
        // Resource is outside of the copy range.
        return false;
    }

    VkDeviceSize new_src_offset = 0;
    VkDeviceSize new_dst_offset = 0;
    VkDeviceSize new_data_size  = 0;

    if (original_start > resource_start)
    {
        // Write starts inside the buffer.
        new_dst_offset = original_start - resource_start;
    }
    else
    {
        new_src_offset = resource_start - original_start;
    }

    if (original_end > resource_end)
    {
        // Write ends outside the buffer.
        new_data_size = resource_end - (resource_start + new_dst_offset);
    }
    else
    {
        new_data_size = original_end - (resource_start + new_dst_offset);
    }

    (*src_offset) = new_src_offset;
    (*dst_offset) = new_dst_offset;
    (*data_size)  = new_data_size;

    return true;
}

void VulkanRebindAllocator::UpdateBoundResource(ResourceAllocInfo* resource_alloc_info,
                                                VkDeviceSize       write_start,
                                                VkDeviceSize       write_end,
                                                const uint8_t*     data)
{
    assert(resource_alloc_info != nullptr);

    VkDeviceSize src_offset = 0;
    VkDeviceSize dst_offset = 0;
    VkDeviceSize data_size  = 0;

    if (TranslateMemoryRange(resource_alloc_info, write_start, write_end, &src_offset, &dst_offset, &data_size))
    {
        WriteBoundResource(resource_alloc_info, src_offset, dst_offset, data_size, data);
    }
}

VkResult VulkanRebindAllocator::UpdateMappedMemoryRange(
    ResourceAllocInfo* resource_alloc_info,
    VkDeviceSize       oiriginal_start,
    VkDeviceSize       original_end,
    void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult     result     = VK_SUCCESS;
    VkDeviceSize src_offset = 0;
    VkDeviceSize dst_offset = 0;
    VkDeviceSize data_size  = 0;

    if (TranslateMemoryRange(resource_alloc_info, oiriginal_start, original_end, &src_offset, &dst_offset, &data_size))
    {
        if (resource_alloc_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            result = vmaMapMemory(allocator_, resource_alloc_info->allocation, &resource_alloc_info->mapped_pointer);
        }

        if (result == VK_SUCCESS)
        {
            update_func(allocator_, resource_alloc_info->allocation, dst_offset, data_size);
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::UpdateMappedMemoryRanges(
    uint32_t                   memoryRangeCount,
    const VkMappedMemoryRange* pMemoryRanges,
    DeviceMemoryInfo* const*   memory_infos,
    void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult result = VK_SUCCESS;

    if ((pMemoryRanges != nullptr) && (memory_infos != nullptr))
    {
        for (uint32_t i = 0; i < memoryRangeCount; ++i)
        {
            auto memory_info = memory_infos[i];

            if ((memory_info != nullptr) && (memory_info->allocator_info != 0))
            {
                auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(memory_info->allocator_info);
                VkDeviceSize size = pMemoryRanges[i].size;

                if (size == VK_WHOLE_SIZE)
                {
                    size = memory_alloc_info->allocation_size - pMemoryRanges[i].offset;
                }

                VkDeviceSize range_start = pMemoryRanges[i].offset;
                VkDeviceSize range_end   = range_start + size;

                for (const auto& entry : memory_alloc_info->original_buffers)
                {
                    if (UpdateMappedMemoryRange(entry.second, range_start, range_end, update_func) != VK_SUCCESS)
                    {
                        result = VK_ERROR_MEMORY_MAP_FAILED;
                    }
                }

                for (const auto& entry : memory_alloc_info->original_images)
                {
                    if (UpdateMappedMemoryRange(entry.second, range_start, range_end, update_func) != VK_SUCCESS)
                    {
                        result = VK_ERROR_MEMORY_MAP_FAILED;
                    }
                }
            }
        }
    }

    return result;
}

VmaMemoryUsage VulkanRebindAllocator::GetBufferMemoryUsage(VkBufferUsageFlags          buffer_usage,
                                                           VkMemoryPropertyFlags       capture_properties,
                                                           const VkMemoryRequirements& replay_requirements)
{
    // Start with CPU_TO_GPU usage.
    VmaMemoryUsage memory_usage        = VMA_MEMORY_USAGE_CPU_TO_GPU;
    bool           prefer_device_local = false;

    // Adjust memory usage based on buffer usage flags.
    if (buffer_usage == VK_BUFFER_USAGE_TRANSFER_SRC_BIT)
    {
        // For exclusive TRANSFER_SRC usage, assume CPU_ONLY for staging copies.
        memory_usage = VMA_MEMORY_USAGE_CPU_ONLY;
    }
    else if (buffer_usage == VK_BUFFER_USAGE_TRANSFER_DST_BIT)
    {
        // For exclusive TRANSFER_DST usage, assume GPU_TO_CPU for read back.
        memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
    }
    else if (((buffer_usage & VK_BUFFER_USAGE_TRANSFER_DST_BIT) == VK_BUFFER_USAGE_TRANSFER_DST_BIT) &&
             (((buffer_usage & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) != VK_BUFFER_USAGE_TRANSFER_SRC_BIT) &&
              ((buffer_usage & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) != VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT)))
    {
        // When TRANSFER_DST is combined with non-transfer usage, prefer DEVICE_LOCAL memory when adjusting usage based
        // on capture memory property flags when there is a DEVICE_LOCAL|HOST_VISIBLE combination. UNIFORM_BUFFER usage
        // is excluded for cases such as the AMD DEVICE_LOCAL|HOST_VISIBLE memory type, which could be the target of
        // frequent CPU writes.
        prefer_device_local = true;
    }

    // Adjust memory usage based on capture memory properties.
    // If present, remove AMD device extension property flags and perform checks using only the core property flags.
    capture_properties &= ~(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD | VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);

    if ((memory_usage != VMA_MEMORY_USAGE_GPU_TO_CPU) &&
        (capture_properties & VK_MEMORY_PROPERTY_HOST_CACHED_BIT) == VK_MEMORY_PROPERTY_HOST_CACHED_BIT)
    {
        // If the resource was bound to HOST_CACHED memory, make it GPU_TO_CPU usage to continue using HOST_CACHED.
        memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
    }
    else if (memory_usage != VMA_MEMORY_USAGE_GPU_ONLY)
    {
        if (capture_properties == VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
        {
            // If the resource was bound to memory that was exclusively DEVICE_LOCAL, make it GPU_ONLY.
            memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
        }
        else if (((capture_properties & (VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) ==
                  (VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) &&
                 prefer_device_local)
        {
            // If the resource was bound to memory the was a combination of DEVICE_LOCAL and HOST_VISIBLE, make it
            // GPU_ONLY if the usage flags indicated a preference for DEVICE_LOCAL memory (eg. resource was created
            // with TRANSFER_DST usage).
            memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
        }
    }

    // Adjust memory usage based on replay memory requirements.
    return AdjustMemoryUsage(memory_usage, replay_requirements);
}

VmaMemoryUsage VulkanRebindAllocator::GetImageMemoryUsage(VkImageUsageFlags           image_usage,
                                                          VkImageTiling               tiling,
                                                          VkMemoryPropertyFlags       capture_properties,
                                                          const VkMemoryRequirements& replay_requirements)
{
    // Start with GPU_ONLY usage.
    VmaMemoryUsage memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;

    // Adjust memory usage based on image usage and tiling mode.
    if (tiling == VK_IMAGE_TILING_LINEAR)
    {
        if (image_usage == VK_IMAGE_USAGE_TRANSFER_SRC_BIT)
        {
            // For exclusive TRANSFER_SRC usage, assume CPU_ONLY for staging copies.
            memory_usage = VMA_MEMORY_USAGE_CPU_ONLY;
        }
        else if (image_usage == VK_IMAGE_USAGE_TRANSFER_DST_BIT)
        {
            // For exclusive TRANSFER_DST usage, assume GPU_TO_CPU for read back.
            memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
        }
        else
        {
            // Assume CPU_TO_GPU case.
            memory_usage = VMA_MEMORY_USAGE_CPU_TO_GPU;
        }
    }

    // Adjust memory usage based on capture memory properties.
    // If present, remove AMD device properties and perform checks using only the 'standard' properties.
    capture_properties &= ~(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD | VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);

    if (((capture_properties & VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT) == VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT) &&
        ((image_usage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) == VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT))
    {
        // If the resource was bound to memory with the LAZILY_ALLOCATED property, and had TRANSIENT_ATTACHMENT
        // usage, attempt to make it LAZILY_ALLOCATED.
        memory_usage = VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED;
    }
    else if ((memory_usage != VMA_MEMORY_USAGE_GPU_TO_CPU) &&
             (capture_properties & VK_MEMORY_PROPERTY_HOST_CACHED_BIT) == VK_MEMORY_PROPERTY_HOST_CACHED_BIT)
    {
        // If the resource was bound to HOST_CACHED memory, make it GPU_TO_CPU usage to continue using HOST_CACHED.
        memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
    }
    else if ((memory_usage != VMA_MEMORY_USAGE_GPU_ONLY) && (capture_properties == VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT))
    {
        // If the resource was bound to memory that was exclusively DEVICE_LOCAL, make it GPU_ONLY.
        memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
    }
    else if ((memory_usage == VMA_MEMORY_USAGE_GPU_ONLY) &&
             ((capture_properties & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) != VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT))
    {
        // If the resource was bound to memory that did not have the DEVICE_LOCAL property, pick a HOST_VISIBLE
        // usage option.
        memory_usage = VMA_MEMORY_USAGE_CPU_TO_GPU;
    }

    // Adjust memory usage based on replay memory requirements.
    return AdjustMemoryUsage(memory_usage, replay_requirements);
}

VmaMemoryUsage VulkanRebindAllocator::AdjustMemoryUsage(VmaMemoryUsage              desired_usage,
                                                        const VkMemoryRequirements& replay_requirements)
{
    VmaMemoryUsage memory_usage = desired_usage;

    // Check selected usage against the replay memory requirements.
    bool requirements_match = false;
    for (uint32_t i = 0; i < replay_memory_properties_.memoryTypeCount; ++i)
    {
        uint32_t current_bit = 1 << i;
        if ((replay_requirements.memoryTypeBits & current_bit) == current_bit)
        {
            VkMemoryPropertyFlags memory_flags = replay_memory_properties_.memoryTypes[i].propertyFlags;

            if (memory_usage == VMA_MEMORY_USAGE_GPU_ONLY)
            {
                if ((memory_flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) == VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
                {
                    requirements_match = true;
                    break;
                }
            }
            else if (memory_usage == VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED)
            {
                if ((memory_flags & VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT) == VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT)
                {
                    requirements_match = true;
                    break;
                }
            }
            else
            {
                if ((memory_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    requirements_match = true;
                    break;
                }
            }
        }
    }

    if (!requirements_match)
    {
        if (memory_usage == VMA_MEMORY_USAGE_GPU_ONLY)
        {
            // The memory requirements indicate that this resource cannot be bound to DEVICE_LOCAL memory, so change
            // to HOST_VISIBLE usage.
            memory_usage = VMA_MEMORY_USAGE_CPU_TO_GPU;
        }
        else
        {
            // The memory requirements indicate that this resource cannot be bound to HOST_VISIBLE memory, or that
            // LAZILY_ALLOCATED memory is not available, so change to DEVICE_LOCAL usage.
            memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
        }
    }

    return memory_usage;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
