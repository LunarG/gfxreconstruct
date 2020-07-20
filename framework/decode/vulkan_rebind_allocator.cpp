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

#include "decode/resource_util.h"
#include "decode/vulkan_enum_util.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const format::HandleId kPlaceholderHandleId = static_cast<format::HandleId>(~0);
const uintptr_t        kPlaceholderAddress  = static_cast<uintptr_t>(~0);

VulkanRebindAllocator::VulkanRebindAllocator() :
    device_(VK_NULL_HANDLE), allocator_(VK_NULL_HANDLE), vma_functions_{},
    capture_device_type_(VK_PHYSICAL_DEVICE_TYPE_OTHER), capture_memory_properties_{}, replay_memory_properties_{}
{}

VulkanRebindAllocator::~VulkanRebindAllocator() {}

VkResult VulkanRebindAllocator::Initialize(uint32_t                                api_version,
                                           VkInstance                              instance,
                                           VkPhysicalDevice                        physical_device,
                                           VkDevice                                device,
                                           const std::vector<std::string>&         enabled_device_extensions,
                                           VkPhysicalDeviceType                    capture_device_type,
                                           const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                           const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                           const Functions&                        functions)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((capture_memory_properties.memoryTypeCount == 0) || (replay_memory_properties.memoryTypeCount == 0))
    {
        GFXRECON_LOG_FATAL("Capture file does not contain physical device memory properties and cannot be used with "
                           "memory translation.");
    }
    else if (allocator_ == VK_NULL_HANDLE)
    {
        device_                    = device;
        functions_                 = functions;
        capture_device_type_       = capture_device_type;
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

VkResult VulkanRebindAllocator::CreateBuffer(const VkBufferCreateInfo*    create_info,
                                             const VkAllocationCallbacks* allocation_callbacks,
                                             format::HandleId             capture_id,
                                             VkBuffer*                    buffer,
                                             ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((create_info != nullptr) && (buffer != nullptr) && (allocator_data != nullptr))
    {
        result = functions_.create_buffer(device_, create_info, nullptr, buffer);

        if (result >= 0)
        {
            auto resource_alloc_info      = new ResourceAllocInfo;
            resource_alloc_info->usage    = create_info->usage;
            resource_alloc_info->is_image = false;
            (*allocator_data)             = reinterpret_cast<uintptr_t>(resource_alloc_info);

            if (create_info->pNext != nullptr)
            {
                resource_alloc_info->uses_extensions = true;
            }
        }
    }

    return result;
}

void VulkanRebindAllocator::DestroyBuffer(VkBuffer                     buffer,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    if (allocator_data != 0)
    {
        assert(buffer != VK_NULL_HANDLE);

        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        auto memory_alloc_info   = resource_alloc_info->memory_info;

        if (memory_alloc_info != nullptr)
        {
            memory_alloc_info->original_buffers.erase(buffer);
        }

        if (resource_alloc_info->mapped_pointer != nullptr)
        {
            vmaUnmapMemory(allocator_, resource_alloc_info->allocation);
        }

        vmaDestroyBuffer(allocator_, buffer, resource_alloc_info->allocation);

        delete resource_alloc_info;
    }
}

VkResult VulkanRebindAllocator::CreateImage(const VkImageCreateInfo*     create_info,
                                            const VkAllocationCallbacks* allocation_callbacks,
                                            format::HandleId             capture_id,
                                            VkImage*                     image,
                                            ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((create_info != nullptr) && (image != nullptr) && (allocator_data != nullptr))
    {
        result = functions_.create_image(device_, create_info, allocation_callbacks, image);

        if (result >= 0)
        {
            auto resource_alloc_info      = new ResourceAllocInfo;
            resource_alloc_info->usage    = create_info->usage;
            resource_alloc_info->tiling   = create_info->tiling;
            resource_alloc_info->is_image = true;
            (*allocator_data)             = reinterpret_cast<uintptr_t>(resource_alloc_info);

            if (create_info->pNext != nullptr)
            {
                resource_alloc_info->uses_extensions = true;
            }
        }
    }

    return result;
}

void VulkanRebindAllocator::DestroyImage(VkImage                      image,
                                         const VkAllocationCallbacks* allocation_callbacks,
                                         ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    if (allocator_data != 0)
    {
        assert(image != VK_NULL_HANDLE);

        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        auto memory_alloc_info   = resource_alloc_info->memory_info;

        if (memory_alloc_info != nullptr)
        {
            memory_alloc_info->original_images.erase(image);
        }

        if (resource_alloc_info->mapped_pointer != nullptr)
        {
            vmaUnmapMemory(allocator_, resource_alloc_info->allocation);
        }

        vmaDestroyImage(allocator_, image, resource_alloc_info->allocation);

        delete resource_alloc_info;
    }
}

void VulkanRebindAllocator::GetImageSubresourceLayout(VkImage                    image,
                                                      const VkImageSubresource*  subresource,
                                                      VkSubresourceLayout*       layout,
                                                      const VkSubresourceLayout* original_layout,
                                                      ResourceData               allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);

    functions_.get_image_subresource_layout(device_, image, subresource, layout);

    if ((allocator_data != 0) && (layout != nullptr) && (original_layout != nullptr))
    {
        auto        resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        const auto& layouts             = resource_alloc_info->layouts;

        auto comparison_func = [subresource](const SubresourceLayouts& entry) -> bool {
            const auto& key = entry.subresource;
            return (subresource->aspectMask == key.aspectMask) && (subresource->arrayLayer == key.arrayLayer) &&
                   (subresource->mipLevel == key.mipLevel);
        };

        if (std::find_if(layouts.begin(), layouts.end(), comparison_func) == layouts.end())
        {
            SubresourceLayouts layouts;
            layouts.subresource = *subresource;
            layouts.original    = *original_layout;
            layouts.rebind      = *layout;

            resource_alloc_info->layouts.emplace_back(std::move(layouts));
        }
    }
}

VkResult VulkanRebindAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                               const VkAllocationCallbacks* allocation_callbacks,
                                               format::HandleId             capture_id,
                                               VkDeviceMemory*              memory,
                                               MemoryData*                  allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocate_info != nullptr) && (memory != nullptr) && (allocator_data != nullptr))
    {
        // With rebinding, memory allocations are managed by VMA.  We just store the size and memory type index for the
        // VkDeviceMemory object here.  If the VkDeviceMemory object is mapped, the size will be used to create a system
        // memory allocation that will be used to reconstruct the content of the original memory object.  The
        // reconstructed data will be used to populate the memory allocations created by VMA.
        auto memory_alloc_info             = new MemoryAllocInfo;
        memory_alloc_info->allocation_size = allocate_info->allocationSize;
        memory_alloc_info->original_index  = allocate_info->memoryTypeIndex;

        (*memory)         = format::FromHandleId<VkDeviceMemory>(kPlaceholderHandleId);
        (*allocator_data) = reinterpret_cast<uintptr_t>(memory_alloc_info);

        result = VK_SUCCESS;
    }

    return result;
}

void VulkanRebindAllocator::FreeMemory(VkDeviceMemory               memory,
                                       const VkAllocationCallbacks* allocation_callbacks,
                                       MemoryData                   allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    if (allocator_data != 0)
    {
        // Clear references from resources to the allocation info and cleanup allocation info memory.
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);

        for (const auto& entry : memory_alloc_info->original_buffers)
        {
            entry.second->memory_info = nullptr;
        }

        for (const auto& entry : memory_alloc_info->original_images)
        {
            entry.second->memory_info = nullptr;
        }

        delete memory_alloc_info;
    }
}

void VulkanRebindAllocator::GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                                      VkDeviceSize*  committed_memory_in_bytes,
                                                      MemoryData     allocator_data)
{
    // We don't have a valid memory handle for this call.
    GFXRECON_UNREFERENCED_PARAMETER(memory);
    GFXRECON_UNREFERENCED_PARAMETER(committed_memory_in_bytes);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_data);
}

VkResult VulkanRebindAllocator::BindBufferMemory(VkBuffer               buffer,
                                                 VkDeviceMemory         memory,
                                                 VkDeviceSize           memory_offset,
                                                 ResourceData           allocator_buffer_data,
                                                 MemoryData             allocator_memory_data,
                                                 VkMemoryPropertyFlags* bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((buffer != VK_NULL_HANDLE) && (allocator_buffer_data != 0) && (allocator_memory_data != 0) &&
        (bind_memory_properties != nullptr))
    {
        VmaAllocation allocation          = VK_NULL_HANDLE;
        auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buffer_data);
        auto          memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

        VkMemoryRequirements requirements;
        functions_.get_buffer_memory_requirements(device_, buffer, &requirements);

        VmaAllocationCreateInfo create_info;
        create_info.flags = 0;
        create_info.usage = GetBufferMemoryUsage(
            resource_alloc_info->usage,
            capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
            requirements);
        create_info.requiredFlags  = 0;
        create_info.preferredFlags = 0;
        create_info.memoryTypeBits = 0;
        create_info.pool           = VK_NULL_HANDLE;
        create_info.pUserData      = nullptr;

        VmaAllocationInfo allocation_info;
        result = vmaAllocateMemoryForBuffer(allocator_, buffer, &create_info, &allocation, &allocation_info);

        if (result >= 0)
        {
            result = vmaBindBufferMemory(allocator_, allocation, buffer);

            if (result >= 0)
            {
                resource_alloc_info->allocation      = allocation;
                resource_alloc_info->mapped_pointer  = nullptr;
                resource_alloc_info->memory_info     = memory_alloc_info;
                resource_alloc_info->original_offset = memory_offset;
                resource_alloc_info->rebind_offset   = allocation_info.offset;
                resource_alloc_info->size            = allocation_info.size;

                VkMemoryPropertyFlags property_flags =
                    replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    resource_alloc_info->is_host_visible = true;
                }

                if (memory_alloc_info->original_content != nullptr)
                {
                    // Memory has been mapped and written prior to bind.  Copy the original content to the new
                    // allocation to ensure it contains the correct data.
                    WriteBoundResource(resource_alloc_info,
                                       memory_offset,
                                       0,
                                       allocation_info.size,
                                       memory_alloc_info->original_content.get());
                }

                memory_alloc_info->original_buffers.insert(std::make_pair(buffer, resource_alloc_info));

                (*bind_memory_properties) = property_flags;
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindBufferMemory2(uint32_t                      bind_info_count,
                                                  const VkBindBufferMemoryInfo* bind_infos,
                                                  const ResourceData*           allocator_buffer_datas,
                                                  const MemoryData*             allocator_memory_datas,
                                                  VkMemoryPropertyFlags*        bind_memory_properties)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((bind_infos != nullptr) && (allocator_buffer_datas != nullptr) && (allocator_memory_datas != nullptr) &&
        (bind_memory_properties != nullptr))
    {
        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            VkBuffer  buffer                = bind_infos[i].buffer;
            uintptr_t allocator_buffer_data = allocator_buffer_datas[i];
            uintptr_t allocator_memory_data = allocator_memory_datas[i];

            if ((buffer != VK_NULL_HANDLE) && (allocator_buffer_data != 0) && (allocator_memory_data != 0))
            {
                VmaAllocation allocation          = VK_NULL_HANDLE;
                auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buffer_data);
                auto          memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

                VkMemoryRequirements requirements;
                functions_.get_buffer_memory_requirements(device_, buffer, &requirements);

                VmaAllocationCreateInfo create_info;
                create_info.flags = 0;
                create_info.usage = GetBufferMemoryUsage(
                    resource_alloc_info->usage,
                    capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                    requirements);
                create_info.requiredFlags  = 0;
                create_info.preferredFlags = 0;
                create_info.memoryTypeBits = 0;
                create_info.pool           = VK_NULL_HANDLE;
                create_info.pUserData      = nullptr;

                VmaAllocationInfo allocation_info;
                result = vmaAllocateMemoryForBuffer(allocator_, buffer, &create_info, &allocation, &allocation_info);

                if (result >= 0)
                {
                    auto bind_info = &bind_infos[i];

                    result = vmaBindBufferMemory2(allocator_, allocation, 0, buffer, bind_info->pNext);

                    if (result >= 0)
                    {
                        resource_alloc_info->allocation      = allocation;
                        resource_alloc_info->mapped_pointer  = nullptr;
                        resource_alloc_info->memory_info     = memory_alloc_info;
                        resource_alloc_info->original_offset = bind_info->memoryOffset;
                        resource_alloc_info->rebind_offset   = allocation_info.offset;
                        resource_alloc_info->size            = allocation_info.size;

                        VkMemoryPropertyFlags property_flags =
                            replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                        if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
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

                        memory_alloc_info->original_buffers.insert(std::make_pair(buffer, resource_alloc_info));

                        bind_memory_properties[i] = property_flags;
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindImageMemory(VkImage                image,
                                                VkDeviceMemory         memory,
                                                VkDeviceSize           memory_offset,
                                                ResourceData           allocator_image_data,
                                                MemoryData             allocator_memory_data,
                                                VkMemoryPropertyFlags* bind_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((image != VK_NULL_HANDLE) && (allocator_image_data != 0) && (allocator_memory_data != 0) &&
        (bind_memory_properties != nullptr))
    {
        VmaAllocation allocation          = VK_NULL_HANDLE;
        auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);
        auto          memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

        VkMemoryRequirements requirements;
        functions_.get_image_memory_requirements(device_, image, &requirements);

        VmaAllocationCreateInfo create_info;
        create_info.flags = 0;
        create_info.usage =
            GetImageMemoryUsage(resource_alloc_info->usage,
                                resource_alloc_info->tiling,
                                capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                                requirements);
        create_info.requiredFlags  = 0;
        create_info.preferredFlags = 0;
        create_info.memoryTypeBits = 0;
        create_info.pool           = VK_NULL_HANDLE;
        create_info.pUserData      = nullptr;

        VmaAllocationInfo allocation_info;
        result = vmaAllocateMemoryForImage(allocator_, image, &create_info, &allocation, &allocation_info);

        if (result >= 0)
        {
            result = vmaBindImageMemory(allocator_, allocation, image);

            if (result >= 0)
            {
                resource_alloc_info->allocation      = allocation;
                resource_alloc_info->mapped_pointer  = nullptr;
                resource_alloc_info->memory_info     = memory_alloc_info;
                resource_alloc_info->original_offset = memory_offset;
                resource_alloc_info->rebind_offset   = allocation_info.offset;
                resource_alloc_info->size            = allocation_info.size;

                VkMemoryPropertyFlags property_flags =
                    replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    resource_alloc_info->is_host_visible = true;
                }

                if (memory_alloc_info->original_content != nullptr)
                {
                    // Memory has been mapped and written prior to bind.  Copy the original content to the new
                    // allocation to ensure it contains the correct data.
                    WriteBoundResource(resource_alloc_info,
                                       memory_offset,
                                       0,
                                       allocation_info.size,
                                       memory_alloc_info->original_content.get());
                }

                memory_alloc_info->original_images.insert(std::make_pair(image, resource_alloc_info));

                (*bind_memory_properties) = property_flags;
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindImageMemory2(uint32_t                     bind_info_count,
                                                 const VkBindImageMemoryInfo* bind_infos,
                                                 const ResourceData*          allocator_image_datas,
                                                 const MemoryData*            allocator_memory_datas,
                                                 VkMemoryPropertyFlags*       bind_memory_properties)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((bind_infos != nullptr) && (allocator_image_datas != nullptr) && (allocator_memory_datas != nullptr) &&
        (bind_memory_properties != nullptr))
    {
        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            VkImage   image                 = bind_infos[i].image;
            uintptr_t allocator_image_data  = allocator_image_datas[i];
            uintptr_t allocator_memory_data = allocator_memory_datas[i];

            if ((image != VK_NULL_HANDLE) && (allocator_image_data != 0) && (allocator_memory_data != 0))
            {
                VmaAllocation allocation          = VK_NULL_HANDLE;
                auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);
                auto          memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

                VkMemoryRequirements requirements;
                functions_.get_image_memory_requirements(device_, image, &requirements);

                VmaAllocationCreateInfo create_info;
                create_info.flags = 0;
                create_info.usage = GetImageMemoryUsage(
                    resource_alloc_info->usage,
                    resource_alloc_info->tiling,
                    capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                    requirements);
                create_info.requiredFlags  = 0;
                create_info.preferredFlags = 0;
                create_info.memoryTypeBits = 0;
                create_info.pool           = VK_NULL_HANDLE;
                create_info.pUserData      = nullptr;

                VmaAllocationInfo allocation_info;
                result = vmaAllocateMemoryForImage(allocator_, image, &create_info, &allocation, &allocation_info);

                if (result >= 0)
                {
                    auto bind_info = &bind_infos[i];

                    result = vmaBindImageMemory2(allocator_, allocation, 0, image, bind_info->pNext);

                    if (result >= 0)
                    {
                        resource_alloc_info->allocation      = allocation;
                        resource_alloc_info->mapped_pointer  = nullptr;
                        resource_alloc_info->memory_info     = memory_alloc_info;
                        resource_alloc_info->original_offset = bind_info->memoryOffset;
                        resource_alloc_info->rebind_offset   = allocation_info.offset;
                        resource_alloc_info->size            = allocation_info.size;

                        VkMemoryPropertyFlags property_flags =
                            replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                        if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
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

                        memory_alloc_info->original_images.insert(std::make_pair(image, resource_alloc_info));

                        bind_memory_properties[i] = property_flags;
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::MapMemory(VkDeviceMemory   memory,
                                          VkDeviceSize     offset,
                                          VkDeviceSize     size,
                                          VkMemoryMapFlags flags,
                                          void**           data,
                                          MemoryData       allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    VkResult result = VK_ERROR_MEMORY_MAP_FAILED;

    if (allocator_data != 0)
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        memory_alloc_info->is_mapped     = true;
        memory_alloc_info->mapped_offset = offset;
        result                           = VK_SUCCESS;
        (*data)                          = reinterpret_cast<void*>(kPlaceholderAddress);
    }

    return result;
}

void VulkanRebindAllocator::UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    if (allocator_data != 0)
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        memory_alloc_info->is_mapped     = false;
        memory_alloc_info->mapped_offset = 0;
    }
}

VkResult VulkanRebindAllocator::FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                                        const VkMappedMemoryRange* memory_ranges,
                                                        const MemoryData*          allocator_datas)
{
    return UpdateMappedMemoryRanges(memory_range_count, memory_ranges, allocator_datas, vmaFlushAllocation);
}

VkResult VulkanRebindAllocator::InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                             const VkMappedMemoryRange* memory_ranges,
                                                             const MemoryData*          allocator_datas)
{
    return UpdateMappedMemoryRanges(memory_range_count, memory_ranges, allocator_datas, vmaInvalidateAllocation);
}

VkResult VulkanRebindAllocator::WriteMappedMemoryRange(MemoryData     allocator_data,
                                                       uint64_t       offset,
                                                       uint64_t       size,
                                                       const uint8_t* data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocator_data != 0)
    {
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);

        if (memory_alloc_info->is_mapped)
        {
            if (memory_alloc_info->original_content == nullptr)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, memory_alloc_info->allocation_size);
                size_t allocation_size = static_cast<size_t>(memory_alloc_info->allocation_size);

                memory_alloc_info->original_content = std::make_unique<uint8_t[]>(allocation_size);
            }

            // Update the reconstructed memory, which is written to memory allocations created at resource bind to
            // ensure they contain the correct data.
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
            size_t   copy_size = static_cast<size_t>(size);
            uint8_t* copy_dst  = memory_alloc_info->original_content.get() + memory_alloc_info->mapped_offset + offset;

            util::platform::MemoryCopy(copy_dst, copy_size, data, copy_size);

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

            result = VK_SUCCESS;
        }
        else
        {
            result = VK_ERROR_MEMORY_MAP_FAILED;
        }
    }

    return result;
}

void VulkanRebindAllocator::ReportAllocateMemoryIncompatibility(const VkMemoryAllocateInfo* allocate_info)
{
    // The rebind allocator defers allocation until bind and always returns success from vkAllocateMemory, so has no
    // incompatibility to check for.
    GFXRECON_UNREFERENCED_PARAMETER(allocate_info);
}

void VulkanRebindAllocator::ReportBindBufferIncompatibility(VkBuffer     buffer,
                                                            ResourceData allocator_resource_data,
                                                            MemoryData   allocator_memory_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(buffer);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_data);

    ReportBindIncompatibility(&allocator_resource_data, 1);
}

void VulkanRebindAllocator::ReportBindBuffer2Incompatibility(uint32_t                      bind_info_count,
                                                             const VkBindBufferMemoryInfo* bind_infos,
                                                             const ResourceData*           allocator_resource_datas,
                                                             const MemoryData*             allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);

    ReportBindIncompatibility(allocator_resource_datas, bind_info_count);
}

void VulkanRebindAllocator::ReportBindImageIncompatibility(VkImage      image,
                                                           ResourceData allocator_resource_data,
                                                           MemoryData   allocator_memory_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(image);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_data);

    ReportBindIncompatibility(&allocator_resource_data, 1);
}

void VulkanRebindAllocator::ReportBindImage2Incompatibility(uint32_t                     bind_info_count,
                                                            const VkBindImageMemoryInfo* bind_infos,
                                                            const ResourceData*          allocator_resource_datas,
                                                            const MemoryData*            allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);

    ReportBindIncompatibility(allocator_resource_datas, bind_info_count);
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
                if (!resource_alloc_info->layouts.empty())
                {
                    if (resource_alloc_info->layouts.size() == 1)
                    {
                        const auto& layouts = resource_alloc_info->layouts[0];

                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, layouts.original.rowPitch);
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, layouts.rebind.rowPitch);

                        size_t original_row_pitch = static_cast<size_t>(layouts.original.rowPitch);
                        size_t rebind_row_pitch   = static_cast<size_t>(layouts.rebind.rowPitch);

                        resource::CopyImageSubresourceMemory(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer),
                                                             data + copy_src_offset,
                                                             copy_dst_offset,
                                                             copy_size,
                                                             rebind_row_pitch,
                                                             original_row_pitch);
                    }
                    else
                    {
                        // TODO: multi-plane image format support when strides do not match.
                        GFXRECON_LOG_ERROR("Skipping mapped memory write for image with multiple subresources: support "
                                           "not yet implemented");
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING("Image subresource layout info is not available for mapped memory write; "
                                         "capture/replay memory alignment differences will not be handled properly");

                    util::platform::MemoryCopy(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer) +
                                                   copy_dst_offset,
                                               copy_size,
                                               data + copy_src_offset,
                                               copy_size);
                }
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
    uint32_t                   memory_range_count,
    const VkMappedMemoryRange* memory_ranges,
    const MemoryData*          allocator_datas,
    void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult result = VK_SUCCESS;

    if ((memory_ranges != nullptr) && (allocator_datas != nullptr))
    {
        for (uint32_t i = 0; i < memory_range_count; ++i)
        {
            auto allocator_data = allocator_datas[i];

            if (allocator_data != 0)
            {
                auto         memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
                VkDeviceSize size              = memory_ranges[i].size;

                if (size == VK_WHOLE_SIZE)
                {
                    size = memory_alloc_info->allocation_size - memory_ranges[i].offset;
                }

                VkDeviceSize range_start = memory_ranges[i].offset;
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
    else if ((capture_device_type_ == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) &&
             ((buffer_usage & VK_BUFFER_USAGE_TRANSFER_DST_BIT) == VK_BUFFER_USAGE_TRANSFER_DST_BIT) &&
             (((buffer_usage & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) != VK_BUFFER_USAGE_TRANSFER_SRC_BIT) &&
              ((buffer_usage & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) != VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT)))
    {
        // When TRANSFER_DST is combined with non-transfer usage on an integrated GPU, prefer DEVICE_LOCAL memory when
        // adjusting usage based on capture memory property flags when there is a DEVICE_LOCAL|HOST_VISIBLE combination.
        // UNIFORM_BUFFER usage is excluded due to the potential for frequent CPU writes.
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
            // with TRANSFER_DST usage on an integrated GPU).
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

void VulkanRebindAllocator::ReportBindIncompatibility(const ResourceData* allocator_resource_datas,
                                                      uint32_t            resource_count)
{
    assert(allocator_resource_datas != nullptr);

    for (uint32_t i = 0; i < resource_count; ++i)
    {
        auto allocator_resource_data = allocator_resource_datas[i];

        if (allocator_resource_data != 0)
        {
            auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_resource_data);

            if (resource_alloc_info->uses_extensions)
            {
                GFXRECON_LOG_FATAL("Resource memory bind failed: resource was created with an extension that may not "
                                   "be supported by memory rebind translation.");
                break;
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
