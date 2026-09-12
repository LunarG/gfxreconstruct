/*
** Copyright (c) 2020 LunarG, Inc.
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

// Define VMA_ASSERT for use in vk_mem_alloc.h
// For debug compiles, VMA_ASSERT failure is treated as a warning.
// For release compiles, VMA_ASSERT failure is a no-op.
// The expr_ parameter can be in the form of 'condition && "error string"'.
// The error string will be printed if condition is false.
#include "util/logging.h"
#ifdef NDEBUG
#define VMA_ASSERT(expr_)
#else
#define VMA_ASSERT(expr_)                                                \
    if (!static_cast<bool>(expr_))                                       \
    {                                                                    \
        std::string msg = __FILE__ ":" + std::to_string(__LINE__) + " "; \
        if (strchr(#expr_, '"'))                                         \
        {                                                                \
            msg += strchr(#expr_, '"');                                  \
        }                                                                \
        else                                                             \
        {                                                                \
            msg += #expr_;                                               \
        }                                                                \
        GFXRECON_LOG_ERROR(msg.c_str());                                 \
    }
#endif

#include "generated/generated_vulkan_dispatch_table.h"

// This file needs to be included first to ensure it is processed with the VMA_IMPLEMENTATION directive, in case it is
// indirectly included by other include files.
#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/resource_util.h"
#include "decode/vulkan_enum_util.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/alignment_utils.h"
#include "util/platform.h"
#include "graphics/vulkan_util.h"
#include "graphics/vulkan_resources_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr format::HandleId kPlaceholderHandleId = static_cast<format::HandleId>(~0ul);
constexpr uintptr_t        kPlaceholderAddress  = static_cast<uintptr_t>(~0ul);

// Called by VMA before vkFreeMemory on each internally managed VkDeviceMemory block.
// Removes the corresponding external mutex so block_mutexes_ doesn't grow unbounded.
extern VKAPI_ATTR void VKAPI_CALL OnVmaFreeDeviceMemory(
    VmaAllocator allocator, uint32_t memory_type, VkDeviceMemory memory, VkDeviceSize size, void* user_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocator);
    GFXRECON_UNREFERENCED_PARAMETER(memory_type);

    auto*           self = static_cast<VulkanRebindAllocator*>(user_data);
    std::lock_guard guard(self->block_mutexes_guard_);
    self->block_mutexes_.erase(memory);
}

VulkanRebindAllocator::VulkanRebindAllocator() :
    VulkanResourceAllocator(), allocator_(VK_NULL_HANDLE), vma_functions_{},
    capture_device_type_(VK_PHYSICAL_DEVICE_TYPE_OTHER), capture_memory_properties_{}
{}

void VulkanRebindAllocator::DefaultVmaBackend::GetImageMemoryRequirements(VmaAllocator          allocator,
                                                                          VkImage               image,
                                                                          VkMemoryRequirements& memory_requirements,
                                                                          bool& requires_dedicated_allocation,
                                                                          bool& prefers_dedicated_allocation)
{
    allocator->GetImageMemoryRequirements(
        image, memory_requirements, requires_dedicated_allocation, prefers_dedicated_allocation);
}

VkResult VulkanRebindAllocator::DefaultVmaBackend::CreateBuffer(VmaAllocator                   allocator,
                                                                const VkBufferCreateInfo*      create_info,
                                                                const VmaAllocationCreateInfo* allocation_create_info,
                                                                VkBuffer*                      buffer,
                                                                VmaAllocation*                 allocation,
                                                                VmaAllocationInfo*             allocation_info)
{
    return vmaCreateBuffer(allocator, create_info, allocation_create_info, buffer, allocation, allocation_info);
}

VkResult
VulkanRebindAllocator::DefaultVmaBackend::AllocateMemoryForImage(VmaAllocator                   allocator,
                                                                 VkImage                        image,
                                                                 const VmaAllocationCreateInfo* allocation_create_info,
                                                                 VmaAllocation*                 allocation,
                                                                 VmaAllocationInfo*             allocation_info)
{
    return vmaAllocateMemoryForImage(allocator, image, allocation_create_info, allocation, allocation_info);
}

VkResult VulkanRebindAllocator::DefaultVmaBackend::AllocateMemory(VmaAllocator                   allocator,
                                                                  const VkMemoryRequirements*    memory_requirements,
                                                                  const VmaAllocationCreateInfo* allocation_create_info,
                                                                  VmaAllocation*                 allocation,
                                                                  VmaAllocationInfo*             allocation_info)
{
    return vmaAllocateMemory(allocator, memory_requirements, allocation_create_info, allocation, allocation_info);
}

void VulkanRebindAllocator::DefaultVmaBackend::FreeMemory(VmaAllocator allocator, VmaAllocation allocation)
{
    vmaFreeMemory(allocator, allocation);
}

VkResult VulkanRebindAllocator::DefaultVmaBackend::MapMemory(VmaAllocator  allocator,
                                                             VmaAllocation allocation,
                                                             void**        mapped_pointer)
{
    return vmaMapMemory(allocator, allocation, mapped_pointer);
}

void VulkanRebindAllocator::DefaultVmaBackend::FlushAllocation(VmaAllocator  allocator,
                                                               VmaAllocation allocation,
                                                               VkDeviceSize  offset,
                                                               VkDeviceSize  size)
{
    vmaFlushAllocation(allocator, allocation, offset, size);
}

void VulkanRebindAllocator::DefaultVmaBackend::UnmapMemory(VmaAllocator allocator, VmaAllocation allocation)
{
    vmaUnmapMemory(allocator, allocation);
}

std::mutex& VulkanRebindAllocator::GetOrCreateBlockMutex(VkDeviceMemory device_memory)
{
    std::lock_guard guard(block_mutexes_guard_);
    auto&           mutex_ptr = block_mutexes_[device_memory];

    if (!mutex_ptr)
    {
        mutex_ptr = std::make_unique<std::mutex>();
    }
    return *mutex_ptr;
}

VkResult VulkanRebindAllocator::Initialize(const VulkanPhysicalDeviceInfo*      physical_device_info,
                                           VkDevice                             device,
                                           const VkDeviceCreateInfo&            device_create_info,
                                           const std::vector<std::string>&      enabled_device_extensions,
                                           const graphics::VulkanInstanceTable& instance_table,
                                           const graphics::VulkanDeviceTable*   device_table)
{
    VkResult result = VulkanResourceAllocator::Initialize(
        physical_device_info, device, device_create_info, enabled_device_extensions, instance_table, device_table);
    if (result != VK_SUCCESS)
    {
        return result;
    }

    result = VK_ERROR_INITIALIZATION_FAILED;

    const VkPhysicalDeviceMemoryProperties& capture_memory_properties = physical_device_info->capture_memory_properties;

    if ((capture_memory_properties.memoryTypeCount == 0) || (replay_memory_properties_.memoryTypeCount == 0))
    {
        GFXRECON_LOG_FATAL("Capture file does not contain physical device memory properties and cannot be used with "
                           "memory translation.");
    }
    else if (allocator_ == VK_NULL_HANDLE)
    {
        capture_device_type_       = physical_device_info->capture_device_type;
        capture_memory_properties_ = capture_memory_properties;

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
        vma_functions_.vkGetInstanceProcAddr                   = functions_.get_instance_proc_addr;
        vma_functions_.vkGetDeviceProcAddr                     = functions_.get_device_proc_addr;

        VmaAllocatorCreateInfo create_info = {};

        GFXRECON_ASSERT(physical_device_info->replay_device_info->properties.has_value());
        const VkPhysicalDevice physical_device = physical_device_info->handle;
        const uint32_t         api_version     = std::min(physical_device_info->parent_info.api_version,
                                              physical_device_info->replay_device_info->properties->apiVersion);

        create_info.physicalDevice   = physical_device;
        create_info.device           = device;
        create_info.pVulkanFunctions = &vma_functions_;
        create_info.instance         = physical_device_info->parent;
        create_info.vulkanApiVersion = api_version;

        // register our custom handler, invoked when blocks are freed
        const VmaDeviceMemoryCallbacks block_lifetime_callbacks = { nullptr, &OnVmaFreeDeviceMemory, this };
        create_info.pDeviceMemoryCallbacks                      = &block_lifetime_callbacks;

        uint32_t queue_family_count = 0;
        functions_.get_physical_device_queue_family_properties(physical_device, &queue_family_count, nullptr);

        std::vector<VkQueueFamilyProperties> queue_family_properties(queue_family_count);
        functions_.get_physical_device_queue_family_properties(
            physical_device, &queue_family_count, queue_family_properties.data());

        std::vector<bool> used_queue_families(queue_family_count, false);
        for (uint32_t i = 0; i < device_create_info.queueCreateInfoCount; ++i)
        {
            used_queue_families[device_create_info.pQueueCreateInfos[i].queueFamilyIndex] = true;
        }

        staging_queue_family_ = 0;
        for (const VkQueueFamilyProperties& elt : queue_family_properties)
        {
            if ((elt.queueFlags & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT)) &&
                used_queue_families[staging_queue_family_])
            {
                break;
            }
            staging_queue_family_++;
        }
        assert(staging_queue_family_ < queue_family_count);

        VkCommandPoolCreateInfo cmd_pool_info = {};
        cmd_pool_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        cmd_pool_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        cmd_pool_info.queueFamilyIndex        = staging_queue_family_;

        {
            auto injected = device_table_.Open();

            result = injected->CreateCommandPool(device_, &cmd_pool_info, NULL, &cmd_pool_);
            assert(result == VK_SUCCESS);

            injected->GetDeviceQueue(device_, staging_queue_family_, 0, &staging_queue_);
        }

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
            else if (entry == VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME)
            {
                create_info.flags |= VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT;
            }
        }

        if (api_version >= VK_API_VERSION_1_2)
        {
            // when core (1.2+), use the feature unconditionally
            create_info.flags |= VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT;
        }

        if (have_memory_reqs2 && have_dedicated_allocation)
        {
            create_info.flags |= VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT;
        }

        // Mark vma's api calls as synthesized
        util::MarkInjectedCommandsHelper injected;
        result = vmaCreateAllocator(&create_info, &allocator_);
    }

    return result;
}

void VulkanRebindAllocator::Destroy()
{
    auto injected = device_table_.Open();
    ClearStagingResources();
    {
        injected->DestroyCommandPool(device_, cmd_pool_, nullptr);
    }

    if (allocator_ != VK_NULL_HANDLE)
    {
        vmaDestroyAllocator(allocator_);
        allocator_ = VK_NULL_HANDLE;
    }

    {
        std::lock_guard guard(block_mutexes_guard_);
        block_mutexes_.clear();
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
        auto modified_info = *create_info;
        modified_info.size = util::aligned_value(create_info->size, min_buffer_alignment_);

        result = functions_.create_buffer(device_, &modified_info, allocator_->GetAllocationCallbacks(), buffer);

        if (result >= 0)
        {
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->usage       = create_info->usage;
            resource_alloc_info->object_type = VK_OBJECT_TYPE_BUFFER;
            resource_alloc_info->create_size = create_info->size;
            (*allocator_data)                = reinterpret_cast<uintptr_t>(resource_alloc_info);

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

    if (buffer == VK_NULL_HANDLE)
    {
        GFXRECON_ASSERT(allocator_data == 0);
        return;
    }

    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        RemoveVmaMemoryInfo(*resource_alloc_info, VK_HANDLE_TO_UINT64(buffer));
        delete resource_alloc_info;
    }

    vmaDestroyBuffer(allocator_, buffer, VK_NULL_HANDLE);
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
        result = functions_.create_image(device_, create_info, allocator_->GetAllocationCallbacks(), image);

        if (result >= 0)
        {
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->usage       = create_info->usage;
            resource_alloc_info->tiling      = create_info->tiling;
            resource_alloc_info->height      = create_info->extent.height;
            resource_alloc_info->format      = create_info->format;
            resource_alloc_info->object_type = VK_OBJECT_TYPE_IMAGE;
            (*allocator_data)                = reinterpret_cast<uintptr_t>(resource_alloc_info);

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

    if (image == VK_NULL_HANDLE)
    {
        GFXRECON_ASSERT(allocator_data == 0);
        return;
    }

    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        RemoveVmaMemoryInfo(*resource_alloc_info, VK_HANDLE_TO_UINT64(image));
        delete resource_alloc_info;
    }

    vmaDestroyImage(allocator_, image, VK_NULL_HANDLE);
}

VkResult VulkanRebindAllocator::CreateVideoSession(const VkVideoSessionCreateInfoKHR* create_info,
                                                   const VkAllocationCallbacks*       allocation_callbacks,
                                                   format::HandleId                   capture_id,
                                                   VkVideoSessionKHR*                 session,
                                                   ResourceData*                      allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((create_info != nullptr) && (session != nullptr) && (allocator_data != nullptr))
    {
        result = functions_.create_video_session(device_, create_info, allocator_->GetAllocationCallbacks(), session);

        if (result >= 0)
        {
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->object_type = VK_OBJECT_TYPE_VIDEO_SESSION_KHR;
            (*allocator_data)                = reinterpret_cast<uintptr_t>(resource_alloc_info);

            if (create_info->pNext != nullptr)
            {
                resource_alloc_info->uses_extensions = true;
            }
        }
    }

    return result;
}

void VulkanRebindAllocator::DestroyVideoSession(VkVideoSessionKHR            session,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_ASSERT(session != VK_NULL_HANDLE);

    if (allocator_data != 0)
    {
        auto* resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        RemoveVmaMemoryInfo(*resource_alloc_info, VK_HANDLE_TO_UINT64(session));
        delete resource_alloc_info;
    }

    functions_.destroy_video_session(allocator_->m_hDevice, session, allocator_->GetAllocationCallbacks());
}

void VulkanRebindAllocator::GetBufferMemoryRequirements(VkBuffer              buffer,
                                                        VkMemoryRequirements* memory_requirements,
                                                        ResourceData          allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (resource_alloc_info->capture_mem_reqs.empty())
        {
            resource_alloc_info->capture_mem_reqs.resize(1);
        }
        resource_alloc_info->capture_mem_reqs[0] = *memory_requirements;
    }
    functions_.get_buffer_memory_requirements(device_, buffer, memory_requirements);
}

void VulkanRebindAllocator::GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* info,
                                                         VkMemoryRequirements2*                 memory_requirements,
                                                         ResourceData                           allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (resource_alloc_info->capture_mem_reqs.empty())
        {
            resource_alloc_info->capture_mem_reqs.resize(1);
        }
        resource_alloc_info->capture_mem_reqs[0] = memory_requirements->memoryRequirements;
    }
    functions_.get_buffer_memory_requirements2(device_, info, memory_requirements);
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

void VulkanRebindAllocator::GetImageMemoryRequirements(VkImage               image,
                                                       VkMemoryRequirements* memory_requirements,
                                                       ResourceData          allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (resource_alloc_info->capture_mem_reqs.empty())
        {
            resource_alloc_info->capture_mem_reqs.resize(1);
        }
        resource_alloc_info->capture_mem_reqs[0] = *memory_requirements;
    }
    functions_.get_image_memory_requirements(device_, image, memory_requirements);
}

void VulkanRebindAllocator::GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* info,
                                                        VkMemoryRequirements2*                memory_requirements,
                                                        ResourceData                          allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (resource_alloc_info->capture_mem_reqs.empty())
        {
            resource_alloc_info->capture_mem_reqs.resize(1);
        }
        resource_alloc_info->capture_mem_reqs[0] = memory_requirements->memoryRequirements;
    }
    functions_.get_image_memory_requirements2(device_, info, memory_requirements);
}

VkResult
VulkanRebindAllocator::GetVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR video_session,
                                                            uint32_t*         memory_requirements_count,
                                                            VkVideoSessionMemoryRequirementsKHR* memory_requirements,
                                                            ResourceData                         allocator_data)
{
    if (allocator_data != 0 && *memory_requirements_count > 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        resource_alloc_info->capture_mem_reqs.resize(*memory_requirements_count);

        for (uint32_t i = 0; i < *memory_requirements_count; ++i)
        {
            resource_alloc_info->capture_mem_reqs[i] = memory_requirements[i].memoryRequirements;
        }
    }
    return functions_.get_video_session_memory_requirements(
        device_, video_session, memory_requirements_count, memory_requirements);
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
        memory_alloc_info->capture_id      = capture_id;
        memory_alloc_info->allocation_size = allocate_info->allocationSize;
        memory_alloc_info->original_index  = allocate_info->memoryTypeIndex;
        memory_alloc_info->is_free         = false;

        (*memory)         = format::FromHandleId<VkDeviceMemory>(kPlaceholderHandleId);
        (*allocator_data) = reinterpret_cast<uintptr_t>(memory_alloc_info);

        result = VK_SUCCESS;

        // Track android hardware buffer
        if (auto import_ahb_info =
                graphics::vulkan_struct_get_pnext<VkImportAndroidHardwareBufferInfoANDROID>(allocate_info))
        {
            memory_alloc_info->ahb = import_ahb_info->buffer;
        }
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

        if (memory_alloc_info->ahb)
        {
            functions_.free_memory(device_, memory_alloc_info->ahb_memory, allocator_->GetAllocationCallbacks());
        }
        memory_alloc_info->is_free = true;

        // All objects are destroyed and the memory is freed, so delete the MemoryAllocInfo.
        if (memory_alloc_info->original_objects.empty())
        {
            delete memory_alloc_info;
        }
    }
}

VulkanRebindAllocator::VmaMemoryInfo*
VulkanRebindAllocator::FindAliasedMemoryInfo(const MemoryAllocInfo&      memory_alloc_info,
                                             VkDeviceSize                memory_offset,
                                             VkDeviceSize                footprint,
                                             const VkMemoryRequirements& replay_req,
                                             bool                        requires_dedicated_allocation,
                                             bool                        prefers_dedicated_allocation)
{
    // Without a captured byte-extent we cannot test overlap (e.g. a size-0 image with no
    // create_size proxy); fall back to the per-resource path.
    if (footprint == 0)
    {
        return nullptr;
    }

    const VkDeviceSize new_begin = memory_offset;
    const VkDeviceSize new_end   = memory_offset + footprint;

    for (const auto& range : memory_alloc_info.bound_ranges)
    {
        if (range.footprint == 0 || range.vma_mem_info == nullptr)
        {
            continue;
        }

        // Half-open captured ranges overlap => the two resources alias the same bytes.
        if (new_begin >= range.offset + range.footprint || range.offset >= new_end)
        {
            continue;
        }

        VmaMemoryInfo*     existing = range.vma_mem_info;
        const VkDeviceSize base     = existing->offset_from_original_device_memory;

        // VMA 'can' create dedicated blocks with neither 'prefers/requires dedicated' flag set.
        // -> query the VMA-allocation
        VmaAllocationInfo2 existing_info{};
        if (existing->allocation != VK_NULL_HANDLE)
        {
            vmaGetAllocationInfo2(allocator_, existing->allocation, &existing_info);
        }
        if (existing_info.dedicatedMemory == VK_TRUE)
        {
            GFXRECON_LOG_WARNING("Rebind aliasing: the aliased resource holds a dedicated allocation at replay. "
                                 "cannot reproduce the share.");
            return nullptr;
        }

        // The newcomer gets its own dedicated allocation at replay and therefore cannot share the existing memory.
        if (requires_dedicated_allocation || prefers_dedicated_allocation)
        {
            GFXRECON_LOG_WARNING(
                "Rebind aliasing: a dedicated allocation is required at replay. cannot reproduce the share.");
            return nullptr;
        }

        // The existing allocation's memory type must be allowed for the newcomer at replay.
        if ((replay_req.memoryTypeBits & (1u << existing->allocation_info.memoryType)) == 0)
        {
            GFXRECON_LOG_WARNING("Rebind aliasing: memory type %u is not supported by the resource at replay. cannot "
                                 "reproduce the share.",
                                 existing->allocation_info.memoryType);
            return nullptr;
        }

        // The newcomer must sit at a non-negative offset inside the existing allocation. If it starts
        // before the existing resource (e.g. a parent buffer binding after its sub-range), we cannot
        // place it here; warn rather than silently drop the alias.
        if (memory_offset < base)
        {
            GFXRECON_LOG_WARNING("Rebind aliasing: resource at captured offset %" PRIu64
                                 " precedes the aliased resource at offset %" PRIu64 ". cannot reproduce the share.",
                                 memory_offset,
                                 base);
            return nullptr;
        }

        const VkDeviceSize local = memory_offset - base;

        // A VmaAllocation cannot be grown: a larger aliased resource binding after a smaller one may
        // not fit (replay-size inflation). Detectable, not silent.
        if (local + replay_req.size > existing->replay_mem_req.size)
        {
            GFXRECON_LOG_WARNING("Rebind aliasing: resource at relative offset %" PRIu64 " (size %" PRIu64
                                 ") exceeds the aliased allocation size %" PRIu64 ". cannot reproduce the share.",
                                 local,
                                 replay_req.size,
                                 existing->replay_mem_req.size);
            return nullptr;
        }

        // The resulting device-memory offset must satisfy the replay resource's alignment.
        const VkDeviceSize device_offset = existing->allocation_info.offset + local;
        if (replay_req.alignment != 0 && device_offset % replay_req.alignment != 0)
        {
            GFXRECON_LOG_WARNING("Rebind aliasing: device offset %" PRIu64 " does not satisfy replay alignment %" PRIu64
                                 ". cannot reproduce the share.",
                                 device_offset,
                                 replay_req.alignment);
            return nullptr;
        }

        // avoid unintended aliasing
        if (OverlapsUnaliasedResource(memory_alloc_info, existing, memory_offset, footprint, local, replay_req.size))
        {
            return nullptr;
        }

        return existing;
    }
    return nullptr;
}

// True if placing a resource at [local, local + replay_size) inside `allocation` would overlap a
// resource already bound there whose *captured* range is disjoint from [memory_offset, +footprint).
bool VulkanRebindAllocator::OverlapsUnaliasedResource(const MemoryAllocInfo& memory_alloc_info,
                                                      const VmaMemoryInfo*   allocation,
                                                      VkDeviceSize           memory_offset,
                                                      VkDeviceSize           footprint,
                                                      VkDeviceSize           local,
                                                      VkDeviceSize           replay_size) const
{
    const VkDeviceSize base = allocation->offset_from_original_device_memory;

    for (const auto& other : memory_alloc_info.bound_ranges)
    {
        // Only resources sharing this allocation can collide, and only if their extents are known.
        if (other.vma_mem_info != allocation || other.replay_size == 0 || other.offset < base)
        {
            continue;
        }

        const VkDeviceSize other_local = other.offset - base;
        if (local >= other_local + other.replay_size || other_local >= local + replay_size)
        {
            continue; // disjoint at replay
        }

        if (memory_offset < other.offset + other.footprint && other.offset < memory_offset + footprint)
        {
            continue; // they aliased in the capture too: this is the share being reproduced
        }

        GFXRECON_LOG_WARNING("Rebind aliasing: replay extent [%" PRIu64 ", %" PRIu64 ") would overlap resource %" PRIu64
                             " at [%" PRIu64 ", %" PRIu64 "), which it does not alias in the capture. cannot "
                             "reproduce the share.",
                             local,
                             local + replay_size,
                             other.object_handle,
                             other_local,
                             other_local + other.replay_size);
        return true;
    }
    return false;
}

void VulkanRebindAllocator::RemoveBoundRange(MemoryAllocInfo& memory_alloc_info, uint64_t object_handle)
{
    std::erase_if(memory_alloc_info.bound_ranges,
                  [object_handle](const BoundResourceRange& r) { return r.object_handle == object_handle; });
}

VkResult
VulkanRebindAllocator::AllocateMemoryForBuffer(VkBuffer                                buffer,
                                               VkDeviceSize                            memory_offset,
                                               const VkPhysicalDeviceMemoryProperties& device_memory_properties,
                                               ResourceAllocInfo&                      resource_alloc_info,
                                               MemoryAllocInfo&                        memory_alloc_info,
                                               VmaMemoryInfo**                         vma_mem_info)
{
    VkMemoryRequirements capture_req = {};
    if (resource_alloc_info.capture_mem_reqs.size() > 0)
    {
        capture_req = resource_alloc_info.capture_mem_reqs[0];
    }

    VkMemoryRequirements replay_req                    = {};
    bool                 requires_dedicated_allocation = false;
    bool                 prefers_dedicated_allocation  = false;
    allocator_->GetBufferMemoryRequirements(
        buffer, replay_req, requires_dedicated_allocation, prefers_dedicated_allocation);

    replay_req.alignment = std::max<VkDeviceSize>(replay_req.alignment, min_buffer_alignment_);

    VmaAllocationCreateInfo create_info{};
    create_info.flags = 0;
    create_info.usage =
        GetBufferMemoryUsage(resource_alloc_info.usage,
                             device_memory_properties.memoryTypes[memory_alloc_info.original_index].propertyFlags,
                             replay_req);
    create_info.requiredFlags  = 0;
    create_info.preferredFlags = 0;
    create_info.memoryTypeBits = 0;
    create_info.pool           = VK_NULL_HANDLE;
    create_info.pUserData      = nullptr;

    // The captured byte-extent, used to detect aliasing. Prefer the smaller of requirement- and
    // create-size: page-guard tracking rewrites the recorded requirement to a page multiple (a
    // 168-byte buffer can read as 65536), which would overlap every neighbour within that page.
    const VkDeviceSize footprint = (capture_req.size > 0 && resource_alloc_info.create_size > 0)
                                       ? std::min(capture_req.size, resource_alloc_info.create_size)
                                       : std::max(capture_req.size, resource_alloc_info.create_size);

    if (VmaMemoryInfo* aliased = FindAliasedMemoryInfo(memory_alloc_info,
                                                       memory_offset,
                                                       footprint,
                                                       replay_req,
                                                       requires_dedicated_allocation,
                                                       prefers_dedicated_allocation))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(buffer), memory_offset, footprint, aliased, replay_req.size });
        *vma_mem_info = aliased;
        return VK_SUCCESS;
    }

    if (FindVmaMemoryInfo(memory_alloc_info,
                          memory_offset,
                          capture_req,
                          replay_req,
                          requires_dedicated_allocation,
                          prefers_dedicated_allocation,
                          create_info,
                          vma_mem_info))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(buffer), memory_offset, footprint, *vma_mem_info, replay_req.size });
        return VK_SUCCESS;
    }

    VmaMemoryInfo mem_info                      = {};
    mem_info.memory_info                        = &memory_alloc_info;
    mem_info.capture_mem_req                    = capture_req;
    mem_info.replay_mem_req                     = replay_req;
    mem_info.requires_dedicated_allocation      = requires_dedicated_allocation;
    mem_info.prefers_dedicated_allocation       = prefers_dedicated_allocation;
    mem_info.alc_create_info                    = create_info;
    mem_info.offset_from_original_device_memory = memory_offset;

    // Mark vma's api calls as synthesized
    util::MarkInjectedCommandsHelper injected;
    auto                             result =
        vmaAllocateMemoryForBuffer(allocator_, buffer, &create_info, &mem_info.allocation, &mem_info.allocation_info);

    if (result >= 0)
    {
        memory_alloc_info.vma_mem_infos.emplace_back(std::make_unique<VmaMemoryInfo>(mem_info));
        *vma_mem_info = memory_alloc_info.vma_mem_infos.back().get();
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(buffer), memory_offset, footprint, *vma_mem_info, replay_req.size });
    }
    return result;
}

void VulkanRebindAllocator::UpdateAllocInfo(ResourceAllocInfo&     resource_alloc_info,
                                            uint64_t               object_handle,
                                            MemoryInfoType         memory_info_type,
                                            MemoryAllocInfo&       memory_alloc_info,
                                            VmaMemoryInfo&         vma_mem_info,
                                            VkMemoryPropertyFlags& bind_memory_property)
{
    resource_alloc_info.memory_info_type = memory_info_type;

    switch (memory_info_type)
    {
        case MemoryInfoType::kBasic:
        {
            if (resource_alloc_info.bound_memory_infos.empty())
            {
                resource_alloc_info.bound_memory_infos.resize(1);
            }
            resource_alloc_info.bound_memory_infos[0] = &vma_mem_info;
            ++vma_mem_info.reference_count;
            break;
        }
        case MemoryInfoType::kSparse:
        case MemoryInfoType::kVideoSession:
        case MemoryInfoType::kDataGraphSession:
        {
            bool is_found = false;
            for (const auto& mem_info : resource_alloc_info.bound_memory_infos)
            {
                if (mem_info == &vma_mem_info)
                {
                    is_found = true;
                    break;
                }
            }

            if (!is_found)
            {
                resource_alloc_info.bound_memory_infos.push_back(&vma_mem_info);
                ++vma_mem_info.reference_count;
            }
            break;
        }
        default:
            break;
    }

    VkMemoryPropertyFlags property_flags =
        replay_memory_properties_.memoryTypes[vma_mem_info.allocation_info.memoryType].propertyFlags;

    if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
    {
        vma_mem_info.is_host_visible = true;
    }

    memory_alloc_info.original_objects.insert(std::make_pair(object_handle, &resource_alloc_info));

    if (memory_alloc_info.original_content != nullptr)
    {
        // Memory has been mapped and written prior to bind.  Copy the original content to the new
        // allocation to ensure it contains the correct data.

        // If the buffer is bigger at replay time than at capture time, you don't want to read
        // memory_alloc_info->original_content out of bounds
        VkDeviceSize copy_size =
            std::min(vma_mem_info.allocation_info.size,
                     memory_alloc_info.allocation_size - vma_mem_info.offset_from_original_device_memory);

        WriteBoundResource(&resource_alloc_info,
                           &vma_mem_info,
                           vma_mem_info.offset_from_original_device_memory,
                           0,
                           copy_size,
                           memory_alloc_info.original_content.get());
    }

    bind_memory_property = property_flags;

    SetBindingDebugUtilsNameAndTag(
        &memory_alloc_info, &resource_alloc_info, vma_mem_info.allocation_info.deviceMemory, object_handle);
}

VkResult VulkanRebindAllocator::BindBufferMemory(VkBuffer                                buffer,
                                                 VkDeviceMemory                          memory,
                                                 VkDeviceSize                            memory_offset,
                                                 ResourceData                            allocator_buffer_data,
                                                 MemoryData                              allocator_memory_data,
                                                 VkMemoryPropertyFlags*                  bind_memory_properties,
                                                 const VkPhysicalDeviceMemoryProperties& device_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((buffer != VK_NULL_HANDLE) && (allocator_buffer_data != 0) && (allocator_memory_data != 0) &&
        (bind_memory_properties != nullptr))
    {
        auto           resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buffer_data);
        auto           memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
        VmaMemoryInfo* vma_mem_info        = nullptr;

        result = AllocateMemoryForBuffer(
            buffer, memory_offset, device_memory_properties, *resource_alloc_info, *memory_alloc_info, &vma_mem_info);

        if (result >= 0)
        {
            GFXRECON_ASSERT(vma_mem_info);

            auto offset = GetRebindOffsetFromVMA(memory_offset, *vma_mem_info);

            // Mark vma's api calls as synthesized
            util::MarkInjectedCommandsHelper injected;
            result = vmaBindBufferMemory2(allocator_, vma_mem_info->allocation, offset, buffer, nullptr);

            if (result >= 0)
            {
                UpdateAllocInfo(*resource_alloc_info,
                                VK_HANDLE_TO_UINT64(buffer),
                                MemoryInfoType::kBasic,
                                *memory_alloc_info,
                                *vma_mem_info,
                                *bind_memory_properties);
            }
            else
            {
                RemoveBoundRange(*memory_alloc_info, VK_HANDLE_TO_UINT64(buffer));
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind BindBufferMemory.",
                                 util::ToString<VkResult>(result).c_str());
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
                auto           resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buffer_data);
                auto           memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                VmaMemoryInfo* vma_mem_info        = nullptr;

                result = AllocateMemoryForBuffer(buffer,
                                                 bind_infos[i].memoryOffset,
                                                 capture_memory_properties_,
                                                 *resource_alloc_info,
                                                 *memory_alloc_info,
                                                 &vma_mem_info);

                if (result >= 0)
                {
                    GFXRECON_ASSERT(vma_mem_info);

                    auto bind_info = &bind_infos[i];
                    auto offset    = GetRebindOffsetFromVMA(bind_info->memoryOffset, *vma_mem_info);

                    // Mark vma's api calls as synthesized
                    util::MarkInjectedCommandsHelper injected;
                    result =
                        vmaBindBufferMemory2(allocator_, vma_mem_info->allocation, offset, buffer, bind_info->pNext);

                    if (result >= 0)
                    {
                        UpdateAllocInfo(*resource_alloc_info,
                                        VK_HANDLE_TO_UINT64(buffer),
                                        MemoryInfoType::kBasic,
                                        *memory_alloc_info,
                                        *vma_mem_info,
                                        bind_memory_properties[i]);
                    }
                    else
                    {
                        RemoveBoundRange(*memory_alloc_info, VK_HANDLE_TO_UINT64(buffer));
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind BindBufferMemory2.",
                                         util::ToString<VkResult>(result).c_str());
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::AllocateAHBMemory(MemoryAllocInfo* memory_alloc_info, const VkImage image)
{
    GFXRECON_ASSERT(memory_alloc_info->ahb != nullptr);

    VkImportAndroidHardwareBufferInfoANDROID importAHBInfo;
    importAHBInfo.sType  = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
    importAHBInfo.pNext  = nullptr;
    importAHBInfo.buffer = memory_alloc_info->ahb;

    VkMemoryDedicatedAllocateInfo dedicatedAllocateInfo{};
    dedicatedAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
    dedicatedAllocateInfo.pNext = &importAHBInfo;
    dedicatedAllocateInfo.image = image;

    VkAndroidHardwareBufferPropertiesANDROID androidHardwareBufferProperties;
    androidHardwareBufferProperties.sType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID;
    androidHardwareBufferProperties.pNext = nullptr;
    {
        auto injected = device_table_.Open();
        injected->GetAndroidHardwareBufferPropertiesANDROID(
            device_, memory_alloc_info->ahb, &androidHardwareBufferProperties);
    }

    VkMemoryAllocateInfo allocate_info{};
    allocate_info.sType           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.pNext           = &dedicatedAllocateInfo;
    allocate_info.allocationSize  = androidHardwareBufferProperties.allocationSize;
    allocate_info.memoryTypeIndex = replay_memory_properties_.memoryTypeCount;
    for (uint32_t i = 0; i < replay_memory_properties_.memoryTypeCount; ++i)
    {
        if ((androidHardwareBufferProperties.memoryTypeBits & (1 << i)) &&
            (replay_memory_properties_.memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) ==
                VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
        {
            allocate_info.memoryTypeIndex = i;
        }
    }
    assert(allocate_info.memoryTypeIndex < replay_memory_properties_.memoryTypeCount);
    VkResult result = functions_.allocate_memory(device_, &allocate_info, nullptr, &memory_alloc_info->ahb_memory);
    return result;
}

VkResult VulkanRebindAllocator::AllocateMemoryForImage(VkImage                                 image,
                                                       VkDeviceSize                            memory_offset,
                                                       const VkPhysicalDeviceMemoryProperties& device_memory_properties,
                                                       ResourceAllocInfo&                      resource_alloc_info,
                                                       MemoryAllocInfo&                        memory_alloc_info,
                                                       VmaMemoryInfo**                         vma_mem_info)
{
    VkMemoryRequirements capture_req = {};
    if (resource_alloc_info.capture_mem_reqs.size() > 0)
    {
        capture_req = resource_alloc_info.capture_mem_reqs[0];
    }

    VkMemoryRequirements replay_req                    = {};
    bool                 requires_dedicated_allocation = false;
    bool                 prefers_dedicated_allocation  = false;
    // Route the replay requirement query through the backend so unit tests can validate this policy in isolation.
    vma_backend_->GetImageMemoryRequirements(
        allocator_, image, replay_req, requires_dedicated_allocation, prefers_dedicated_allocation);

    VmaAllocationCreateInfo create_info{};
    create_info.flags = 0;
    create_info.usage =
        GetImageMemoryUsage(resource_alloc_info.usage,
                            resource_alloc_info.tiling,
                            device_memory_properties.memoryTypes[memory_alloc_info.original_index].propertyFlags,
                            replay_req);
    create_info.requiredFlags  = 0;
    create_info.preferredFlags = 0;
    create_info.memoryTypeBits = 0;
    create_info.pool           = VK_NULL_HANDLE;
    create_info.pUserData      = nullptr;

    // Images carry no flat create-size proxy, so the footprint is only known when the memory
    // requirement size was recorded; otherwise overlap is untestable and we use the per-resource path.
    const VkDeviceSize footprint = capture_req.size;

    if (VmaMemoryInfo* aliased = FindAliasedMemoryInfo(memory_alloc_info,
                                                       memory_offset,
                                                       footprint,
                                                       replay_req,
                                                       requires_dedicated_allocation,
                                                       prefers_dedicated_allocation))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(image), memory_offset, footprint, aliased, replay_req.size });
        *vma_mem_info = aliased;
        return VK_SUCCESS;
    }

    if (FindVmaMemoryInfo(memory_alloc_info,
                          memory_offset,
                          capture_req,
                          replay_req,
                          requires_dedicated_allocation,
                          prefers_dedicated_allocation,
                          create_info,
                          vma_mem_info))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(image), memory_offset, footprint, *vma_mem_info, replay_req.size });
        return VK_SUCCESS;
    }

    VmaMemoryInfo mem_info                      = {};
    mem_info.memory_info                        = &memory_alloc_info;
    mem_info.capture_mem_req                    = capture_req;
    mem_info.replay_mem_req                     = replay_req;
    mem_info.requires_dedicated_allocation      = requires_dedicated_allocation;
    mem_info.prefers_dedicated_allocation       = prefers_dedicated_allocation;
    mem_info.alc_create_info                    = create_info;
    mem_info.offset_from_original_device_memory = memory_offset;

    util::MarkInjectedCommandsHelper injected;
    auto                             result = vma_backend_->AllocateMemoryForImage(
        allocator_, image, &create_info, &mem_info.allocation, &mem_info.allocation_info);

    if (result >= 0)
    {
        memory_alloc_info.vma_mem_infos.emplace_back(std::make_unique<VmaMemoryInfo>(mem_info));
        *vma_mem_info = memory_alloc_info.vma_mem_infos.back().get();
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(image), memory_offset, footprint, *vma_mem_info, replay_req.size });
    }
    return result;
}

VkDeviceSize VulkanRebindAllocator::GetRebindOffsetFromVMA(VkDeviceSize         original_offset,
                                                           const VmaMemoryInfo& vma_mem_info)
{
    return original_offset - vma_mem_info.offset_from_original_device_memory;
}

VkDeviceSize VulkanRebindAllocator::GetRebindOffsetFromOriginalDeviceMemory(VkDeviceSize         original_offset,
                                                                            const VmaMemoryInfo& vma_mem_info)
{
    return GetRebindOffsetFromVMA(original_offset, vma_mem_info) + vma_mem_info.allocation_info.offset;
}

VkResult VulkanRebindAllocator::BindImageMemory(VkImage                                 image,
                                                VkDeviceMemory                          memory,
                                                VkDeviceSize                            memory_offset,
                                                ResourceData                            allocator_image_data,
                                                MemoryData                              allocator_memory_data,
                                                VkMemoryPropertyFlags*                  bind_memory_properties,
                                                const VkPhysicalDeviceMemoryProperties& device_memory_properties)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((image != VK_NULL_HANDLE) && (allocator_image_data != 0) && (allocator_memory_data != 0) &&
        (bind_memory_properties != nullptr))
    {
        auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

        if (memory_alloc_info->ahb)
        {
            result = AllocateAHBMemory(memory_alloc_info, image);

            if (result >= 0)
            {
                result = functions_.bind_image_memory(device_, image, memory_alloc_info->ahb_memory, memory_offset);
            }
        }
        else
        {
            auto           resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);
            VmaMemoryInfo* vma_mem_info        = nullptr;

            result = AllocateMemoryForImage(image,
                                            memory_offset,
                                            device_memory_properties,
                                            *resource_alloc_info,
                                            *memory_alloc_info,
                                            &vma_mem_info);

            if (result >= 0)
            {
                GFXRECON_ASSERT(vma_mem_info);

                auto offset = GetRebindOffsetFromVMA(memory_offset, *vma_mem_info);

                // Mark vma's api calls as synthesized
                util::MarkInjectedCommandsHelper injected;
                result = vmaBindImageMemory2(allocator_, vma_mem_info->allocation, offset, image, nullptr);

                if (result >= 0)
                {
                    UpdateAllocInfo(*resource_alloc_info,
                                    VK_HANDLE_TO_UINT64(image),
                                    MemoryInfoType::kBasic,
                                    *memory_alloc_info,
                                    *vma_mem_info,
                                    *bind_memory_properties);
                }
                else
                {
                    RemoveBoundRange(*memory_alloc_info, VK_HANDLE_TO_UINT64(image));
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind BindImageMemory.",
                                     util::ToString<VkResult>(result).c_str());
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
                auto         memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                VkDeviceSize memory_offset     = bind_infos[i].memoryOffset;

                if (memory_alloc_info->ahb)
                {
                    result = AllocateAHBMemory(memory_alloc_info, image);

                    if (result >= 0)
                    {
                        VkBindImageMemoryInfo bind_image_memory_info;
                        bind_image_memory_info.sType        = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
                        bind_image_memory_info.pNext        = bind_infos[i].pNext;
                        bind_image_memory_info.image        = image;
                        bind_image_memory_info.memory       = memory_alloc_info->ahb_memory;
                        bind_image_memory_info.memoryOffset = memory_offset;
                        result = functions_.bind_image_memory2(device_, 1u, &bind_image_memory_info);
                    }
                }
                else
                {
                    auto           resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);
                    VmaMemoryInfo* vma_mem_info        = nullptr;

                    result = AllocateMemoryForImage(image,
                                                    memory_offset,
                                                    capture_memory_properties_,
                                                    *resource_alloc_info,
                                                    *memory_alloc_info,
                                                    &vma_mem_info);

                    if (result >= 0)
                    {
                        GFXRECON_ASSERT(vma_mem_info);

                        auto bind_info = &bind_infos[i];

                        auto offset = GetRebindOffsetFromVMA(memory_offset, *vma_mem_info);

                        // Mark vma's api calls as synthesized
                        util::MarkInjectedCommandsHelper injected;
                        result =
                            vmaBindImageMemory2(allocator_, vma_mem_info->allocation, offset, image, bind_info->pNext);

                        if (result >= 0)
                        {
                            UpdateAllocInfo(*resource_alloc_info,
                                            VK_HANDLE_TO_UINT64(image),
                                            MemoryInfoType::kBasic,
                                            *memory_alloc_info,
                                            *vma_mem_info,
                                            bind_memory_properties[i]);
                        }
                        else
                        {
                            RemoveBoundRange(*memory_alloc_info, VK_HANDLE_TO_UINT64(image));
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind BindImageMemory2.",
                                             util::ToString<VkResult>(result).c_str());
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::BindVideoSessionMemory(VkVideoSessionKHR                      video_session,
                                                       uint32_t                               bind_info_count,
                                                       const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                                       const ResourceData                     allocator_session_data,
                                                       const MemoryData*                      allocator_memory_datas,
                                                       VkMemoryPropertyFlags*                 bind_memory_properties)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((video_session != VK_NULL_HANDLE) && (bind_infos != nullptr) && (allocator_session_data != 0) &&
        (allocator_memory_datas != nullptr) && (bind_memory_properties != nullptr))
    {
        uint32_t replay_req_count = 0;
        functions_.get_video_session_memory_requirements(device_, video_session, &replay_req_count, nullptr);

        VkVideoSessionMemoryRequirementsKHR reqs = {};
        reqs.sType                               = VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR;
        std::vector<VkVideoSessionMemoryRequirementsKHR> replay_reqs(replay_req_count, reqs);
        functions_.get_video_session_memory_requirements(device_, video_session, &replay_req_count, replay_reqs.data());

        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_session_data);

        // Use replay MemoryRequeirements to AllocateMemory and Bind.
        for (uint32_t bind_i = 0; bind_i < bind_info_count; ++bind_i)
        {
            uintptr_t allocator_memory_data = allocator_memory_datas[bind_i];
            if (allocator_memory_data == 0)
            {
                continue;
            }

            auto*       memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
            const auto& bind_info         = bind_infos[bind_i];
            auto        replay_req        = replay_reqs[bind_info.memoryBindIndex].memoryRequirements;

            auto usage = GetVideoSessionMemoryUsage(
                capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags, replay_req);

            VkMemoryRequirements capture_req = {};
            if (resource_alloc_info->capture_mem_reqs.size() > bind_info.memoryBindIndex)
            {
                capture_req = resource_alloc_info->capture_mem_reqs[bind_info.memoryBindIndex];
            }

            VmaMemoryInfo* vma_mem_info = nullptr;

            auto result = VmaAllocateMemory(*memory_alloc_info,
                                            bind_info.memoryOffset,
                                            capture_req,
                                            replay_req,
                                            false,
                                            false,
                                            VK_NULL_HANDLE,
                                            VK_NULL_HANDLE,
                                            usage,
                                            &vma_mem_info);
            if (result >= 0)
            {
                GFXRECON_ASSERT(vma_mem_info);

                VkBindVideoSessionMemoryInfoKHR modified_bind_info = bind_info;
                modified_bind_info.memory                          = vma_mem_info->allocation_info.deviceMemory;
                modified_bind_info.memoryOffset =
                    GetRebindOffsetFromOriginalDeviceMemory(bind_info.memoryOffset, *vma_mem_info);

                switch (vma_mem_info->allocation->GetType())
                {
                    case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
                    {
                        result = functions_.bind_video_session_memory(device_, video_session, 1, &modified_bind_info);
                        break;
                    }
                    case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
                    {
                        VmaDeviceMemoryBlock* const pBlock = vma_mem_info->allocation->GetBlock();
                        VMA_ASSERT(pBlock && "Binding Video Session to allocation that doesn't belong to any block.");

                        // This lock is important so that we don't call vkBind... and/or vkMap... simultaneously
                        // on the same VkDeviceMemory from multiple threads.
                        std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                        if (allocator_->m_UseMutex)
                        {
                            lock.lock();
                        }
                        result = functions_.bind_video_session_memory(device_, video_session, 1, &modified_bind_info);
                        break;
                    }
                    default:
                        VMA_ASSERT(0);
                }

                if (result >= 0)
                {
                    UpdateAllocInfo(*resource_alloc_info,
                                    VK_HANDLE_TO_UINT64(video_session),
                                    MemoryInfoType::kVideoSession,
                                    *memory_alloc_info,
                                    *vma_mem_info,
                                    bind_memory_properties[bind_i]);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind BindVideoSessionMemory.",
                                     util::ToString<VkResult>(result).c_str());
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

VkResult
VulkanRebindAllocator::MapMemory2(const VkMemoryMapInfo* memory_map_info, void** data, MemoryData allocator_data)
{
    VkResult result = VK_ERROR_MEMORY_MAP_FAILED;

    if (allocator_data != 0)
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        memory_alloc_info->is_mapped     = true;
        memory_alloc_info->mapped_offset = memory_map_info->offset;
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

VkResult VulkanRebindAllocator::UnmapMemory2(const VkMemoryUnmapInfo* memory_unmap_info, MemoryData allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_unmap_info);

    if (allocator_data != 0)
    {
        auto memory_alloc_info           = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
        memory_alloc_info->is_mapped     = false;
        memory_alloc_info->mapped_offset = 0;
    }
    return VK_SUCCESS;
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

VkResult VulkanRebindAllocator::SetDebugUtilsObjectNameEXT(VkDevice                       device,
                                                           VkDebugUtilsObjectNameInfoEXT* name_info,
                                                           uintptr_t                      allocator_data)
{
    if (allocator_data != 0)
    {
        switch (name_info->objectType)
        {
            case VK_OBJECT_TYPE_DEVICE_MEMORY:
            {
                MemoryAllocInfo* memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
                GFXRECON_ASSERT(memory_alloc_info);

                if (memory_alloc_info->vma_mem_infos.empty())
                {
                    memory_alloc_info->debug_utils_name = name_info->pObjectName;
                    return VK_SUCCESS;
                }
                else
                {
                    name_info->objectHandle =
                        VK_HANDLE_TO_UINT64(memory_alloc_info->vma_mem_infos[0]->allocation_info.deviceMemory);
                    break;
                }
                break;
            }
            case VK_OBJECT_TYPE_BUFFER:
            case VK_OBJECT_TYPE_IMAGE:
            case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            {
                ResourceAllocInfo* resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

                bool found_memory_info = false;
                for (const auto& mem_info : resource_alloc_info->bound_memory_infos)
                {
                    if (mem_info->memory_info)
                    {
                        found_memory_info = true;
                        break;
                    }
                }

                if (!found_memory_info)
                {
                    resource_alloc_info->debug_utils_name = name_info->pObjectName;
                    return VK_SUCCESS;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return functions_.set_debug_utils_object_name(device, name_info);
}

VkResult VulkanRebindAllocator::SetDebugUtilsObjectTagEXT(VkDevice                      device,
                                                          VkDebugUtilsObjectTagInfoEXT* tag_info,
                                                          uintptr_t                     allocator_data)
{
    if (allocator_data != 0)
    {
        switch (tag_info->objectType)
        {
            case VK_OBJECT_TYPE_DEVICE_MEMORY:
            {
                MemoryAllocInfo* memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
                GFXRECON_ASSERT(memory_alloc_info);

                if (memory_alloc_info->vma_mem_infos.empty())
                {
                    std::vector<uint8_t>& buffer = memory_alloc_info->debug_utils_tag;
                    const uint8_t*        data   = reinterpret_cast<const uint8_t*>(tag_info->pTag);

                    buffer.clear();
                    buffer.insert(buffer.end(), data, data + tag_info->tagSize);
                    memory_alloc_info->debug_utils_tag_name = tag_info->tagName;

                    return VK_SUCCESS;
                }
                else
                {
                    tag_info->objectHandle =
                        VK_HANDLE_TO_UINT64(memory_alloc_info->vma_mem_infos[0]->allocation_info.deviceMemory);
                    break;
                }
                break;
            }
            case VK_OBJECT_TYPE_BUFFER:
            case VK_OBJECT_TYPE_IMAGE:
            case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            {
                ResourceAllocInfo* resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

                bool found_memory_info = false;
                for (const auto& mem_info : resource_alloc_info->bound_memory_infos)
                {
                    if (mem_info->memory_info)
                    {
                        found_memory_info = true;
                        break;
                    }
                }

                if (!found_memory_info)
                {
                    std::vector<uint8_t>& buffer = resource_alloc_info->debug_utils_tag;
                    const uint8_t*        data   = reinterpret_cast<const uint8_t*>(tag_info->pTag);

                    buffer.clear();
                    buffer.insert(buffer.end(), data, data + tag_info->tagSize);
                    resource_alloc_info->debug_utils_tag_name = tag_info->tagName;

                    return VK_SUCCESS;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return functions_.set_debug_utils_object_tag(device, tag_info);
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
            for (const auto& entry : memory_alloc_info->original_objects)
            {
                for (auto& entry_bound : entry.second->bound_memory_infos)
                {
                    UpdateBoundResource(entry.second, entry_bound, write_start, write_end, data);
                }
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

void VulkanRebindAllocator::ReportBindVideoSessionIncompatibility(VkVideoSessionKHR video_session,
                                                                  uint32_t          bind_info_count,
                                                                  const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                                                  const ResourceData allocator_resource_data,
                                                                  const MemoryData*  allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(video_session);
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);

    ReportBindIncompatibility(&allocator_resource_data, 1);
}

void VulkanRebindAllocator::ReportBindAccelerationStructureMemoryNVIncompatibility(
    uint32_t                                       bind_info_count,
    const VkBindAccelerationStructureMemoryInfoNV* bind_infos,
    const ResourceData*                            allocator_acc_datas,
    const MemoryData*                              allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);
}

void VulkanRebindAllocator::ReportQueueBindSparseIncompatibility(VkQueue                 queue,
                                                                 uint32_t                bind_info_count,
                                                                 const VkBindSparseInfo* bind_infos,
                                                                 VkFence                 fence,
                                                                 const ResourceData*     allocator_buf_datas,
                                                                 const MemoryData*       allocator_buf_mem_datas,
                                                                 const ResourceData*     allocator_img_op_datas,
                                                                 const MemoryData*       allocator_img_op_mem_datas,
                                                                 const ResourceData*     allocator_img_datas,
                                                                 const MemoryData*       allocator_img_mem_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(fence);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_buf_mem_datas);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_img_op_mem_datas);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_img_mem_datas);

    uint32_t buf_count    = 0;
    uint32_t img_op_count = 0;
    uint32_t img_count    = 0;

    for (uint32_t i = 0; i < bind_info_count; ++i)
    {
        const auto* bind_info = &bind_infos[i];
        buf_count += bind_info->bufferBindCount;
        img_op_count += bind_info->imageOpaqueBindCount;
        img_count += bind_info->imageBindCount;
    }

    if (buf_count > 0)
    {
        ReportBindIncompatibility(allocator_buf_datas, buf_count);
    }
    if (img_op_count > 0)
    {
        ReportBindIncompatibility(allocator_img_op_datas, img_op_count);
    }
    if (img_count > 0)
    {
        ReportBindIncompatibility(allocator_img_datas, img_count);
    }
}

void VulkanRebindAllocator::WriteBoundResourceDirect(ResourceAllocInfo* resource_alloc_info,
                                                     VmaMemoryInfo*     bound_memory_info,
                                                     size_t             src_offset,
                                                     size_t             dst_offset,
                                                     size_t             data_size,
                                                     const uint8_t*     data)
{
    switch (resource_alloc_info->object_type)
    {
        case VK_OBJECT_TYPE_BUFFER:
        {
            util::platform::MemoryCopy(static_cast<uint8_t*>(bound_memory_info->mapped_pointer) + dst_offset,
                                       data_size,
                                       data + src_offset,
                                       data_size);
            break;
        }
        case VK_OBJECT_TYPE_IMAGE:
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

                    resource::CopyImageSubresourceMemory(static_cast<uint8_t*>(bound_memory_info->mapped_pointer),
                                                         data + src_offset,
                                                         dst_offset,
                                                         data_size,
                                                         rebind_row_pitch,
                                                         original_row_pitch,
                                                         resource_alloc_info->height);
                }
                else
                {
                    // TODO: multi-plane image format support when strides do not match.
                    GFXRECON_LOG_ERROR_ONCE(
                        "Skipping mapped memory write for image with multiple subresources: support "
                        "not yet implemented");
                }
            }
            else
            {
                GFXRECON_LOG_WARNING_ONCE("Image subresource layout info is not available for mapped memory write; "
                                          "capture/replay memory alignment differences will not be handled properly");

                util::platform::MemoryCopy(static_cast<uint8_t*>(bound_memory_info->mapped_pointer) + dst_offset,
                                           data_size,
                                           data + src_offset,
                                           data_size);
            }
            break;
        }
        case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
        {
            // TODO: implement direct video session copy
            GFXRECON_LOG_WARNING_ONCE("Skipping video session in direct write: support not yet implemented");
            break;
        }
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
        {
            // TODO: Implement it when it's necessary.
            GFXRECON_LOG_WARNING_ONCE(
                "Skipping acceleration structure NV in direct write: support not yet implemented");
            break;
        }
        default:
            break;
    }
}

void VulkanRebindAllocator::WriteBoundResourceStaging(ResourceAllocInfo* resource_alloc_info,
                                                      VmaMemoryInfo*     bound_memory_info,
                                                      size_t             src_offset,
                                                      size_t             dst_offset,
                                                      size_t             data_size,
                                                      const uint8_t*     data)
{
    if (resource_alloc_info->object_type == VK_OBJECT_TYPE_IMAGE && dst_offset != 0)
    {
        // TODO: implement offset based stagging image copy
        GFXRECON_LOG_WARNING("Skipping image with offset in staging write: support not yet implemented");
        return;
    }

    if (resource_alloc_info->object_type == VK_OBJECT_TYPE_VIDEO_SESSION_KHR)
    {
        // TODO: Implement it when it's necessary.
        GFXRECON_LOG_WARNING("Skipping video session in staging write: support not yet implemented");
        return;
    }

    if (resource_alloc_info->object_type == VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV)
    {
        // TODO: Implement it when it's necessary.
        GFXRECON_LOG_WARNING("Skipping acceleration structure NV in staging write: support not yet implemented");
        return;
    }

    std::vector<VkSemaphore>          waiting_semaphores;
    std::vector<VkPipelineStageFlags> waiting_semaphores_dst_stage_mask;

    for (const auto& staging_resource : staging_resources_)
    {
        bool is_already_in_use =
            resource_alloc_info == staging_resource.resource_alloc_info &&
            (dst_offset == staging_resource.dst_offset || dst_offset + data_size > staging_resource.dst_offset);

        if (is_already_in_use)
        {
            // If we have a scenario in which there are multiple staging copies on the same memory range before a
            // queue submit we are forced to chain them to avoid data corruption
            GFXRECON_LOG_WARNING("Detected multiple staging writes on the same resource before a vkQueueSubmit, "
                                 "staging writes will be chained.");
            waiting_semaphores.push_back(staging_resource.staging_semaphore);
            waiting_semaphores_dst_stage_mask.push_back(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
        }
    }

    // The following operations will be submitted and waited upon at the time of the next trace file VkQueueSubmit
    StagingResources staging_resources{};
    staging_resources.resource_alloc_info = resource_alloc_info;
    staging_resources.dst_offset          = dst_offset;

    VkCommandBufferAllocateInfo cmd_buff_alloc_info = {};
    cmd_buff_alloc_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cmd_buff_alloc_info.pNext                       = nullptr;
    cmd_buff_alloc_info.commandPool                 = cmd_pool_;
    cmd_buff_alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmd_buff_alloc_info.commandBufferCount          = 1;

    // Everything below is replay-synthesized staging work; one injected-commands window covers it all.
    auto injected = device_table_.Open();

    VkResult result = injected->AllocateCommandBuffers(device_, &cmd_buff_alloc_info, &staging_resources.cmd_buffer);

    if (result == VK_SUCCESS)
    {
        VkBufferCreateInfo staging_buf_create_info{};
        staging_buf_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        staging_buf_create_info.size  = data_size;
        staging_buf_create_info.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;

        VmaAllocationInfo       staging_alloc_info{};
        VmaAllocationCreateInfo staging_alloc_create_info = {};
        staging_alloc_create_info.flags =
            VMA_ALLOCATION_CREATE_HOST_ACCESS_SEQUENTIAL_WRITE_BIT | VMA_ALLOCATION_CREATE_MAPPED_BIT;
        staging_alloc_create_info.usage = VMA_MEMORY_USAGE_CPU_ONLY;

        result = vma_backend_->CreateBuffer(allocator_,
                                            &staging_buf_create_info,
                                            &staging_alloc_create_info,
                                            &staging_resources.staging_buf,
                                            &staging_resources.staging_alloc,
                                            &staging_alloc_info);
    }

    void* copy_mapped_pointer{ bound_memory_info->mapped_pointer };

    if (result == VK_SUCCESS)
    {
        result =
            vma_backend_->MapMemory(allocator_, staging_resources.staging_alloc, &bound_memory_info->mapped_pointer);
    }

    if (result == VK_SUCCESS)
    {
        WriteBoundResourceDirect(resource_alloc_info, bound_memory_info, src_offset, 0, data_size, data);
        bound_memory_info->mapped_pointer = copy_mapped_pointer;
        vma_backend_->FlushAllocation(allocator_, staging_resources.staging_alloc, 0, VK_WHOLE_SIZE);
        vma_backend_->UnmapMemory(allocator_, staging_resources.staging_alloc);

        VkCommandBufferBeginInfo cmd_buf_begin_info = {};
        cmd_buf_begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

        result = injected.BeginCommandBuffer(staging_resources.cmd_buffer, &cmd_buf_begin_info, __func__);
    }

    if (result == VK_SUCCESS)
    {
        if (resource_alloc_info->object_type == VK_OBJECT_TYPE_IMAGE)
        {
            VkImage original_image{};

            for (const auto& elt : bound_memory_info->memory_info->original_objects)
            {
                if (elt.second == resource_alloc_info)
                {
                    original_image = UINT64_TO_VK_HANDLE(VkImage, elt.first);
                    break;
                }
            }

            if (original_image)
            {
                // TODO: handle mip maps/array layers
                GFXRECON_LOG_WARNING(
                    "Ignoring potential mip maps/array layers in staging buffer to image copy: support "
                    "not yet implemented");

                std::vector<VkImageAspectFlagBits> aspects;
                graphics::GetFormatAspects(resource_alloc_info->format, &aspects);

                for (auto aspect : aspects)
                {
                    VkImageAspectFlags aspect_flags = aspect;

                    VkBufferImageCopy region{};
                    region.bufferOffset      = 0;
                    region.bufferRowLength   = 0;
                    region.bufferImageHeight = 0;
                    region.imageSubresource  = { aspect_flags, 0, 0, 1 };
                    region.imageOffset       = { 0, 0, 0 };
                    region.imageExtent       = { 1, 1, 1 };
                    injected->CmdCopyBufferToImage(staging_resources.cmd_buffer,
                                                   staging_resources.staging_buf,
                                                   original_image,
                                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                                   1,
                                                   &region);
                }
            }
        }
        else if (resource_alloc_info->object_type == VK_OBJECT_TYPE_BUFFER)
        {
            VkBuffer original_buffer{};
            for (const auto& elt : bound_memory_info->memory_info->original_objects)
            {
                if (elt.second == resource_alloc_info)
                {
                    original_buffer = UINT64_TO_VK_HANDLE(VkBuffer, elt.first);
                    break;
                }
            }

            if (original_buffer)
            {
                VkBufferCopy copy_region{};
                copy_region.srcOffset = 0;
                copy_region.dstOffset = dst_offset;
                copy_region.size      = data_size;

                injected->CmdCopyBuffer(
                    staging_resources.cmd_buffer, staging_resources.staging_buf, original_buffer, 1, &copy_region);
            }
        }
    }

    if (result == VK_SUCCESS)
    {
        result = injected->EndCommandBuffer(staging_resources.cmd_buffer);
    }

    if (result == VK_SUCCESS)
    {
        VkSemaphoreCreateInfo semaphore_create_info{};
        semaphore_create_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        result =
            injected->CreateSemaphore(device_, &semaphore_create_info, nullptr, &staging_resources.staging_semaphore);
    }

    if (result == VK_SUCCESS)
    {
        VkFenceCreateInfo fence_create_info{};
        fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;

        result = injected->CreateFence(device_, &fence_create_info, nullptr, &staging_resources.staging_fence);
    }

    if (result == VK_SUCCESS)
    {
        VkSubmitInfo compute_submit_info{};
        compute_submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        compute_submit_info.commandBufferCount = 1;
        compute_submit_info.pCommandBuffers    = &staging_resources.cmd_buffer;
        GFXRECON_NARROWING_ASSIGN(compute_submit_info.waitSemaphoreCount, waiting_semaphores.size());
        compute_submit_info.pWaitSemaphores      = waiting_semaphores.data();
        compute_submit_info.pWaitDstStageMask    = waiting_semaphores_dst_stage_mask.data();
        compute_submit_info.signalSemaphoreCount = 1;
        compute_submit_info.pSignalSemaphores    = &staging_resources.staging_semaphore;

        result = injected->QueueSubmit(staging_queue_, 1, &compute_submit_info, staging_resources.staging_fence);
    }

    if (result == VK_SUCCESS)
    {
        staging_resources_.push_back(staging_resources);
    }
}

void VulkanRebindAllocator::WriteBoundResource(ResourceAllocInfo* resource_alloc_info,
                                               VmaMemoryInfo*     bound_memory_info,
                                               VkDeviceSize       src_offset,
                                               VkDeviceSize       dst_offset,
                                               VkDeviceSize       data_size,
                                               const uint8_t*     data)
{
    GFXRECON_ASSERT(resource_alloc_info != nullptr);
    GFXRECON_ASSERT(bound_memory_info != nullptr);
    GFXRECON_ASSERT(bound_memory_info->memory_info != nullptr);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, src_offset);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, dst_offset);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);

    size_t copy_src_offset = static_cast<size_t>(src_offset);
    size_t copy_dst_offset = static_cast<size_t>(dst_offset);
    size_t copy_size       = static_cast<size_t>(data_size);

    if (bound_memory_info->is_host_visible)
    {
        VkResult result = VK_SUCCESS;

        if (bound_memory_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            // Mark vma's api calls as synthesized
            util::MarkInjectedCommandsHelper injected;
            result = vmaMapMemory(allocator_, bound_memory_info->allocation, &bound_memory_info->mapped_pointer);
        }

        if (result == VK_SUCCESS)
        {
            WriteBoundResourceDirect(
                resource_alloc_info, bound_memory_info, copy_src_offset, copy_dst_offset, copy_size, data);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to map device memory: vmaMapMemory returned %s",
                               util::ToString<VkResult>(result).c_str());
        }
    }
    else
    {
        WriteBoundResourceStaging(
            resource_alloc_info, bound_memory_info, copy_src_offset, copy_dst_offset, copy_size, data);
    }
}

bool VulkanRebindAllocator::TranslateMemoryRange(const VmaMemoryInfo* bound_memory_info,
                                                 VkDeviceSize         original_start,
                                                 VkDeviceSize         original_end,
                                                 VkDeviceSize*        src_offset,
                                                 VkDeviceSize*        dst_offset,
                                                 VkDeviceSize*        data_size)
{
    assert((src_offset != nullptr) && (dst_offset != nullptr) && (data_size));

    if (bound_memory_info->memory_info == nullptr)
    {
        return false;
    }

    VkDeviceSize resource_start = bound_memory_info->offset_from_original_device_memory;
    auto         original_size  = bound_memory_info->memory_info->allocation_size;
    auto         rebind_size    = bound_memory_info->replay_mem_req.size;

    // This should correspond to the offset to the end of the resource at capture time.
    //
    // However, if the rebind size is smaller than the original size, we don't want data_size to be big enough to cause
    // an overflow, so the original size is artifically clamped to the rebind size.
    VkDeviceSize resource_end =
        resource_start + (original_size != 0 ? std::min(original_size, rebind_size) : rebind_size);

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
                                                VmaMemoryInfo*     bound_memory_info,
                                                VkDeviceSize       write_start,
                                                VkDeviceSize       write_end,
                                                const uint8_t*     data)
{
    assert(resource_alloc_info != nullptr);

    VkDeviceSize src_offset = 0;
    VkDeviceSize dst_offset = 0;
    VkDeviceSize data_size  = 0;

    if (TranslateMemoryRange(bound_memory_info, write_start, write_end, &src_offset, &dst_offset, &data_size))
    {
        WriteBoundResource(resource_alloc_info, bound_memory_info, src_offset, dst_offset, data_size, data);
    }
}

VkResult VulkanRebindAllocator::UpdateMappedMemoryRange(
    VmaMemoryInfo* bound_memory_info,
    VkDeviceSize   original_start,
    VkDeviceSize   original_end,
    VkResult (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult     result     = VK_SUCCESS;
    VkDeviceSize src_offset = 0;
    VkDeviceSize dst_offset = 0;
    VkDeviceSize data_size  = 0;

    if (TranslateMemoryRange(bound_memory_info, original_start, original_end, &src_offset, &dst_offset, &data_size))
    {
        if (bound_memory_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            result = vmaMapMemory(allocator_, bound_memory_info->allocation, &bound_memory_info->mapped_pointer);
        }

        if (result == VK_SUCCESS)
        {
            result = update_func(allocator_, bound_memory_info->allocation, dst_offset, data_size);
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::UpdateMappedMemoryRanges(
    uint32_t                   memory_range_count,
    const VkMappedMemoryRange* memory_ranges,
    const MemoryData*          allocator_datas,
    VkResult (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult result = VK_SUCCESS;

    // Mark vma's api calls as synthesized
    auto injected = device_table_.Open();

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

                for (const auto& entry : memory_alloc_info->original_objects)
                {
                    for (auto& entry_bound : entry.second->bound_memory_infos)
                    {
                        if (UpdateMappedMemoryRange(entry_bound, range_start, range_end, update_func) != VK_SUCCESS)
                        {
                            result = VK_ERROR_MEMORY_MAP_FAILED;
                        }
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
        graphics::ImageHasUsage(image_usage, VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT))
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

VmaMemoryUsage VulkanRebindAllocator::GetVideoSessionMemoryUsage(VkMemoryPropertyFlags       capture_properties,
                                                                 const VkMemoryRequirements& replay_requirements)
{
    // Start with CPU_TO_GPU usage.
    VmaMemoryUsage memory_usage = VMA_MEMORY_USAGE_CPU_TO_GPU;

    // Adjust memory usage based on capture memory properties.
    // If present, remove AMD device extension property flags and perform checks using only the core property flags.
    capture_properties &= ~(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD | VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);

    if ((memory_usage != VMA_MEMORY_USAGE_GPU_TO_CPU) &&
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

VkResult VulkanRebindAllocator::MapResourceMemoryDirectImpl(VkDeviceSize     size,
                                                            VkMemoryMapFlags flags,
                                                            void**           data,
                                                            ResourceData     allocator_data)
{
    VkResult result = VK_ERROR_MEMORY_MAP_FAILED;

    if ((data != nullptr) && (allocator_data != 0))
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (!resource_alloc_info->bound_memory_infos.empty())
        {
            auto& mem_info = resource_alloc_info->bound_memory_infos[0];

            if (mem_info->mapped_pointer == nullptr)
            {
                // vma's api calls are marked as synthesized by the scope MapResourceMemoryDirect opened.
                result = vmaMapMemory(allocator_, mem_info->allocation, &mem_info->mapped_pointer);
            }
            else
            {
                result = VK_SUCCESS;
            }

            if (result == VK_SUCCESS)
            {
                (*data) = reinterpret_cast<uint8_t*>(mem_info->mapped_pointer);
            }
        }

        // TODO: Implement it when it's necessary.
        if (resource_alloc_info->bound_memory_infos.size() > 1)
        {
            switch (resource_alloc_info->memory_info_type)
            {
                case MemoryInfoType::kSparse:
                    GFXRECON_LOG_WARNING("VulkanRebindAllocator::MapResourceMemoryDirect map only the first memory of "
                                         "sparse memories.");
                    break;
                case MemoryInfoType::kVideoSession:
                    GFXRECON_LOG_WARNING(
                        "VulkanRebindAllocator::MapResourceMemoryDirect map only the first memory of VideoSession.");
                    break;
                case MemoryInfoType::kDataGraphSession:
                    GFXRECON_LOG_WARNING("VulkanRebindAllocator::MapResourceMemoryDirect map only the first memory of "
                                         "DataGraphPipelineSession.");
                    break;
                default:
                    break;
            }
        }
    }

    return result;
}

void VulkanRebindAllocator::SetBindingDebugUtilsNameAndTag(const MemoryAllocInfo*   memory_alloc_info,
                                                           const ResourceAllocInfo* resource_alloc_info,
                                                           VkDeviceMemory           device_memory,
                                                           uint64_t                 resource_handle)
{
    VkDebugUtilsObjectNameInfoEXT name_info;
    name_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
    name_info.pNext = nullptr;

    VkDebugUtilsObjectTagInfoEXT tag_info;
    tag_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
    tag_info.pNext = nullptr;

    auto injected = device_table_.Open();

    if (!memory_alloc_info->debug_utils_name.empty())
    {
        name_info.objectType   = VK_OBJECT_TYPE_DEVICE_MEMORY;
        name_info.objectHandle = VK_HANDLE_TO_UINT64(device_memory);
        name_info.pObjectName  = memory_alloc_info->debug_utils_name.c_str();

        functions_.set_debug_utils_object_name(device_, &name_info);
    }

    if (!memory_alloc_info->debug_utils_tag.empty())
    {
        tag_info.objectType   = VK_OBJECT_TYPE_DEVICE_MEMORY;
        tag_info.objectHandle = VK_HANDLE_TO_UINT64(device_memory);
        tag_info.tagName      = memory_alloc_info->debug_utils_tag_name;
        tag_info.tagSize      = memory_alloc_info->debug_utils_tag.size();
        tag_info.pTag         = memory_alloc_info->debug_utils_tag.data();

        functions_.set_debug_utils_object_tag(device_, &tag_info);
    }

    if (!resource_alloc_info->debug_utils_name.empty())
    {
        name_info.objectType   = resource_alloc_info->object_type;
        name_info.objectHandle = resource_handle;
        name_info.pObjectName  = resource_alloc_info->debug_utils_name.c_str();

        functions_.set_debug_utils_object_name(device_, &name_info);
    }

    if (!resource_alloc_info->debug_utils_tag.empty())
    {
        tag_info.objectType   = resource_alloc_info->object_type;
        tag_info.objectHandle = resource_handle;
        tag_info.tagName      = resource_alloc_info->debug_utils_tag_name;
        tag_info.tagSize      = resource_alloc_info->debug_utils_tag.size();
        tag_info.pTag         = resource_alloc_info->debug_utils_tag.data();

        functions_.set_debug_utils_object_tag(device_, &tag_info);
    }
}

VkResult VulkanRebindAllocator::VmaAllocateMemory(MemoryAllocInfo&            memory_alloc_info,
                                                  VkDeviceSize                original_offset,
                                                  const VkMemoryRequirements& capture_mem_req,
                                                  const VkMemoryRequirements& replay_mem_req,
                                                  bool                        requires_dedicated_allocation,
                                                  bool                        prefers_dedicated_allocation,
                                                  VkBuffer                    dedicated_buffer,
                                                  VkImage                     dedicated_image,
                                                  VmaMemoryUsage              usage,
                                                  VmaMemoryInfo**             vma_mem_info)
{
    VmaAllocationCreateInfo create_info{};
    create_info.flags          = 0;
    create_info.usage          = usage;
    create_info.requiredFlags  = 0;
    create_info.preferredFlags = 0;
    create_info.memoryTypeBits = 0;
    create_info.pool           = VK_NULL_HANDLE;
    create_info.pUserData      = nullptr;

    if (FindVmaMemoryInfo(memory_alloc_info,
                          original_offset,
                          capture_mem_req,
                          replay_mem_req,
                          requires_dedicated_allocation,
                          prefers_dedicated_allocation,
                          create_info,
                          vma_mem_info))
    {
        return VK_SUCCESS;
    }

    VmaMemoryInfo mem_info                      = {};
    mem_info.memory_info                        = &memory_alloc_info;
    mem_info.capture_mem_req                    = capture_mem_req;
    mem_info.replay_mem_req                     = replay_mem_req;
    mem_info.requires_dedicated_allocation      = requires_dedicated_allocation;
    mem_info.prefers_dedicated_allocation       = prefers_dedicated_allocation;
    mem_info.alc_create_info                    = create_info;
    mem_info.offset_from_original_device_memory = original_offset;

    VmaSuballocationType suballoc_type = VmaSuballocationType::VMA_SUBALLOCATION_TYPE_FREE;

    if (dedicated_buffer != VK_NULL_HANDLE)
    {
        suballoc_type = VmaSuballocationType::VMA_SUBALLOCATION_TYPE_BUFFER;
    }
    else if (dedicated_image != VK_NULL_HANDLE)
    {
        suballoc_type = VmaSuballocationType::VMA_SUBALLOCATION_TYPE_IMAGE_UNKNOWN;
    }

    auto result = allocator_->AllocateMemory(replay_mem_req,
                                             requires_dedicated_allocation,
                                             prefers_dedicated_allocation,
                                             dedicated_buffer,
                                             dedicated_image,
                                             VmaBufferImageUsage::UNKNOWN,
                                             nullptr,
                                             create_info,
                                             suballoc_type,
                                             1,
                                             &mem_info.allocation);
    if (result >= 0)
    {
        allocator_->GetAllocationInfo(mem_info.allocation, &mem_info.allocation_info);

        memory_alloc_info.vma_mem_infos.emplace_back(std::make_unique<VmaMemoryInfo>(mem_info));
        *vma_mem_info = memory_alloc_info.vma_mem_infos.back().get();
    }
    return result;
}

void VulkanRebindAllocator::GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                                      VkDeviceSize*  committed_memory_in_bytes,
                                                      MemoryData     allocator_data)
{
    VkDeviceMemory   modified_mem      = VK_NULL_HANDLE;
    MemoryAllocInfo* memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    GFXRECON_ASSERT(memory_alloc_info);

    if (memory_alloc_info->vma_mem_infos.empty())
    {
        GFXRECON_LOG_WARNING("There's no allocations or memory is VK_NULL_HANDLE. Skip GetDeviceMemoryCommitment");
        return;
    }

    for (const auto& mem_info : memory_alloc_info->vma_mem_infos)
    {
        GFXRECON_ASSERT(mem_info->allocation);
        modified_mem = mem_info->allocation_info.deviceMemory;

        switch (mem_info->allocation->GetType())
        {
            case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
            {
                functions_.get_device_memory_commitment(device_, modified_mem, committed_memory_in_bytes);
                break;
            }
            case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
            {
                VmaDeviceMemoryBlock* const pBlock = mem_info->allocation->GetBlock();
                VMA_ASSERT(pBlock && "GetDeviceMemoryCommitment to allocation that doesn't belong to any block.");

                std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                if (allocator_->m_UseMutex)
                {
                    lock.lock();
                }
                functions_.get_device_memory_commitment(device_, modified_mem, committed_memory_in_bytes);
                break;
            }
            default:
                VMA_ASSERT(0);
        }
    }
}

void VulkanRebindAllocator::SetDeviceMemoryPriority(VkDeviceMemory memory, float priority, MemoryData allocator_data)
{
    VkDeviceMemory   modified_mem      = VK_NULL_HANDLE;
    MemoryAllocInfo* memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    GFXRECON_ASSERT(memory_alloc_info);

    if (memory_alloc_info->vma_mem_infos.empty())
    {
        GFXRECON_LOG_WARNING("There's no allocations or memory is VK_NULL_HANDLE. Skip SetDeviceMemoryPriority");
        return;
    }

    for (const auto& mem_info : memory_alloc_info->vma_mem_infos)
    {
        GFXRECON_ASSERT(mem_info->allocation);
        modified_mem = mem_info->allocation_info.deviceMemory;

        switch (mem_info->allocation->GetType())
        {
            case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
            {
                functions_.set_device_memory_priority(device_, modified_mem, priority);
                break;
            }
            case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
            {
                VmaDeviceMemoryBlock* const pBlock = mem_info->allocation->GetBlock();
                VMA_ASSERT(pBlock && "SetDeviceMemoryPriority to allocation that doesn't belong to any block.");

                std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                if (allocator_->m_UseMutex)
                {
                    lock.lock();
                }
                functions_.set_device_memory_priority(device_, modified_mem, priority);
                break;
            }
            default:
                VMA_ASSERT(0);
        }
    }
}

VkResult
VulkanRebindAllocator::GetMemoryRemoteAddressNV(const VkMemoryGetRemoteAddressInfoNV* memory_get_remote_address_info,
                                                VkRemoteAddressNV*                    address,
                                                MemoryData                            allocator_data)
{
    auto             modified_get_mem_remote_addr_info = *memory_get_remote_address_info;
    MemoryAllocInfo* memory_alloc_info                 = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    GFXRECON_ASSERT(memory_alloc_info);

    if (memory_alloc_info->vma_mem_infos.empty())
    {
        GFXRECON_LOG_WARNING("There's no allocations or memory is VK_NULL_HANDLE. Skip GetMemoryRemoteAddressNV");
        return VK_SUCCESS;
    }

    auto result = VK_ERROR_INITIALIZATION_FAILED;

    for (const auto& mem_info : memory_alloc_info->vma_mem_infos)
    {
        GFXRECON_ASSERT(mem_info->allocation);
        modified_get_mem_remote_addr_info.memory = mem_info->allocation_info.deviceMemory;

        switch (mem_info->allocation->GetType())
        {
            case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
            {
                result = functions_.get_memory_remote_address_nv(device_, &modified_get_mem_remote_addr_info, address);
                break;
            }
            case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
            {
                VmaDeviceMemoryBlock* const pBlock = mem_info->allocation->GetBlock();
                VMA_ASSERT(pBlock && "GetMemoryRemoteAddressNV to allocation that doesn't belong to any block.");

                std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                if (allocator_->m_UseMutex)
                {
                    lock.lock();
                }
                result = functions_.get_memory_remote_address_nv(device_, &modified_get_mem_remote_addr_info, address);
                break;
            }
            default:
                VMA_ASSERT(0);
        }
    }
    return result;
}

VkResult VulkanRebindAllocator::CreateAccelerationStructureNV(const VkAccelerationStructureCreateInfoNV* create_info,
                                                              const VkAllocationCallbacks* allocation_callbacks,
                                                              format::HandleId             capture_id,
                                                              VkAccelerationStructureNV*   acc_str,
                                                              ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    GFXRECON_LOG_FATAL("-m rebind doesn't support CreateAccelerationStructureNV. VK_NV_ray_tracing is deprecated. It "
                       "won't get more support.");
    return VK_ERROR_EXTENSION_NOT_PRESENT;
}

void VulkanRebindAllocator::DestroyAccelerationStructureNV(VkAccelerationStructureNV    acc_str,
                                                           const VkAllocationCallbacks* allocation_callbacks,
                                                           ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    GFXRECON_LOG_FATAL("-m rebind doesn't support DestroyAccelerationStructureNV. VK_NV_ray_tracing is deprecated. It "
                       "won't get more support.");
}

void VulkanRebindAllocator::GetAccelerationStructureMemoryRequirementsNV(
    const VkAccelerationStructureMemoryRequirementsInfoNV* info,
    VkMemoryRequirements2KHR*                              memory_requirements,
    ResourceData                                           allocator_data)
{
    GFXRECON_LOG_FATAL("-m rebind doesn't support GetAccelerationStructureMemoryRequirementsNV. VK_NV_ray_tracing is "
                       "deprecated. It won't get more support.");
}

VkResult
VulkanRebindAllocator::BindAccelerationStructureMemoryNV(uint32_t                                       bind_info_count,
                                                         const VkBindAccelerationStructureMemoryInfoNV* bind_infos,
                                                         const ResourceData*    allocator_acc_datas,
                                                         const MemoryData*      allocator_memory_datas,
                                                         VkMemoryPropertyFlags* bind_memory_properties)
{
    GFXRECON_LOG_FATAL("-m rebind doesn't support BindAccelerationStructureMemoryNV. VK_NV_ray_tracing is deprecated. "
                       "It won't get more support.");
    return VK_ERROR_EXTENSION_NOT_PRESENT;
}

VkResult
VulkanRebindAllocator::GetMemoryFd(const VkMemoryGetFdInfoKHR* get_fd_info, int* pFd, MemoryData allocator_data)
{
    auto             modified_get_fd_info = *get_fd_info;
    MemoryAllocInfo* memory_alloc_info    = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    GFXRECON_ASSERT(memory_alloc_info);

    if (memory_alloc_info->vma_mem_infos.empty())
    {
        GFXRECON_LOG_WARNING("There's no allocations or memory is VK_NULL_HANDLE. Skip GetMemoryFd");
        return VK_SUCCESS;
    }

    auto result = VK_ERROR_INITIALIZATION_FAILED;

    for (const auto& mem_info : memory_alloc_info->vma_mem_infos)
    {
        GFXRECON_ASSERT(mem_info->allocation);
        modified_get_fd_info.memory = mem_info->allocation_info.deviceMemory;

        switch (mem_info->allocation->GetType())
        {
            case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
            {
                result = functions_.get_memory_fd(device_, &modified_get_fd_info, pFd);
                break;
            }
            case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
            {
                VmaDeviceMemoryBlock* const pBlock = mem_info->allocation->GetBlock();
                VMA_ASSERT(pBlock && "GetMemoryFd to allocation that doesn't belong to any block.");

                std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                if (allocator_->m_UseMutex)
                {
                    lock.lock();
                }
                result = functions_.get_memory_fd(device_, &modified_get_fd_info, pFd);
                break;
            }
            default:
                VMA_ASSERT(0);
        }
    }
    return result;
}

bool VulkanRebindAllocator::FindVmaMemoryInfo(MemoryAllocInfo&               memory_alloc_info,
                                              VkDeviceSize                   original_offset,
                                              const VkMemoryRequirements&    capture_mem_req,
                                              const VkMemoryRequirements&    replay_mem_req,
                                              bool                           requires_dedicated_allocation,
                                              bool                           prefers_dedicated_allocation,
                                              const VmaAllocationCreateInfo& alc_create_info,
                                              VmaMemoryInfo**                vma_mem_info)
{
    if (requires_dedicated_allocation || prefers_dedicated_allocation)
    {
        return false;
    }

    for (auto& mem_info : memory_alloc_info.vma_mem_infos)
    {
        if (mem_info->is_compatible(original_offset, capture_mem_req, replay_mem_req, alc_create_info))
        {
            *vma_mem_info = mem_info.get();
            return true;
        }
    }
    return false;
}

void VulkanRebindAllocator::RemoveVmaMemoryInfo(ResourceAllocInfo& resource_alloc_info, uint64_t object_hanlde)
{
    auto injected = device_table_.Open();

    // It could bind sparse memories. It could have plural memories.
    for (auto& mem_info : resource_alloc_info.bound_memory_infos)
    {
        auto mem_alc_info = mem_info->memory_info;
        GFXRECON_ASSERT(mem_alc_info != VK_NULL_HANDLE);

        --mem_info->reference_count;
        if (mem_info->reference_count == 0)
        {
            if (mem_info->allocation != VK_NULL_HANDLE)
            {
                if (mem_info->mapped_pointer != nullptr)
                {
                    vmaUnmapMemory(allocator_, mem_info->allocation);
                }
                vma_backend_->FreeMemory(allocator_, mem_info->allocation);
            }

            for (auto entry = mem_alc_info->vma_mem_infos.begin(); entry != mem_alc_info->vma_mem_infos.end();)
            {
                if (entry->get() == mem_info)
                {
                    mem_alc_info->vma_mem_infos.erase(entry);
                    break;
                }
                else
                {
                    ++entry;
                }
            }
        }

        // drop aliasing ranges for this object,
        // so later binds to same memory do not test overlap against destroyed resources.
        RemoveBoundRange(*mem_alc_info, object_hanlde);

        // All objects are destroyed and the memory is freed, so delete the MemoryAllocInfo.
        mem_alc_info->original_objects.erase(object_hanlde);
        if (mem_alc_info->is_free && mem_alc_info->original_objects.empty())
        {
            delete mem_alc_info;
        }
    }
}

template <typename T, typename S>
void VulkanRebindAllocator::RebindSparseMemory(const T&                     original_memory_bind,
                                               T&                           modified_memory_bind,
                                               ResourceAllocInfo*           res_alloc_info,
                                               MemoryAllocInfo*             mem_alloc_info,
                                               S&                           vma_mem_blocks,
                                               std::vector<VmaMemoryInfo*>& vma_memory_infos,
                                               VkBuffer                     buffer,
                                               VkImage                      image,
                                               const std::string&           type_string,
                                               VkDeviceSize                 alloc_size)
{
    static_assert(std::is_same_v<T, VkSparseMemoryBind> || std::is_same_v<T, VkSparseImageMemoryBind>);

    VmaMemoryInfo*& vma_mem_info = vma_memory_infos.emplace_back(nullptr);

    VkMemoryRequirements capture_req = {};
    if (!res_alloc_info->capture_mem_reqs.empty())
    {
        capture_req = res_alloc_info->capture_mem_reqs[0];
    }

    modified_memory_bind.memory = VK_NULL_HANDLE;

    // memory could be nullptr, but bind_infos's memory isn't real, so using mem_alloc_info to check it.
    if (mem_alloc_info)
    {
        VkMemoryRequirements replay_req                    = {};
        bool                 requires_dedicated_allocation = false;
        bool                 prefers_dedicated_allocation  = false;

        if (buffer != VK_NULL_HANDLE)
        {
            GFXRECON_ASSERT(image == VK_NULL_HANDLE);
            allocator_->GetBufferMemoryRequirements(
                buffer, replay_req, requires_dedicated_allocation, prefers_dedicated_allocation);

            replay_req.alignment = std::max<VkDeviceSize>(replay_req.alignment, min_buffer_alignment_);
        }
        else
        {
            GFXRECON_ASSERT(image != VK_NULL_HANDLE);
            allocator_->GetImageMemoryRequirements(
                image, replay_req, requires_dedicated_allocation, prefers_dedicated_allocation);
        }

        if constexpr (std::is_same_v<T, VkSparseImageMemoryBind>)
        {
            alloc_size = std::min(replay_req.size, mem_alloc_info->allocation_size - original_memory_bind.memoryOffset);
        }

        if (alloc_size > 0)
        {
            replay_req.size = alloc_size;
        }

        if (capture_req.size != 0)
        {
            capture_req.size = alloc_size;
        }

        VmaMemoryUsage usage;
        if (buffer != VK_NULL_HANDLE)
        {
            usage = GetBufferMemoryUsage(
                res_alloc_info->usage,
                capture_memory_properties_.memoryTypes[mem_alloc_info->original_index].propertyFlags,
                replay_req);
        }
        else
        {
            usage = GetImageMemoryUsage(
                res_alloc_info->usage,
                res_alloc_info->tiling,
                capture_memory_properties_.memoryTypes[mem_alloc_info->original_index].propertyFlags,
                replay_req);
        }

        VkResult result = VmaAllocateMemory(*mem_alloc_info,
                                            original_memory_bind.memoryOffset,
                                            capture_req,
                                            replay_req,
                                            requires_dedicated_allocation,
                                            prefers_dedicated_allocation,
                                            buffer,
                                            image,
                                            usage,
                                            &vma_mem_info);
        if (result < 0)
        {
            GFXRECON_LOG_WARNING("AllocateMemory failed: %s in Rebind QueueBindSparse %s.",
                                 util::ToString<VkResult>(result).c_str(),
                                 type_string.c_str());
            return;
        }

        GFXRECON_ASSERT(vma_mem_info);
        modified_memory_bind.memory = vma_mem_info->allocation_info.deviceMemory;
        modified_memory_bind.memoryOffset =
            GetRebindOffsetFromOriginalDeviceMemory(original_memory_bind.memoryOffset, *vma_mem_info);
    }

    if (vma_mem_info != nullptr && vma_mem_info->allocation != nullptr &&
        vma_mem_info->allocation->GetType() == VmaAllocation_T::ALLOCATION_TYPE_BLOCK)
    {
        VmaDeviceMemoryBlock* const pBlock = vma_mem_info->allocation->GetBlock();
        VMA_ASSERT(pBlock && "QueueBindSparse to allocation that doesn't belong to any block.");
        vma_mem_blocks.insert(pBlock->GetDeviceMemory());
    }
}

VkResult VulkanRebindAllocator::QueueBindSparse(VkQueue                 queue,
                                                uint32_t                bind_info_count,
                                                const VkBindSparseInfo* bind_infos,
                                                VkFence                 fence,
                                                ResourceData*           allocator_buf_datas,
                                                const MemoryData*       allocator_buf_mem_datas,
                                                VkMemoryPropertyFlags*  bind_buf_mem_properties,
                                                ResourceData*           allocator_img_op_datas,
                                                const MemoryData*       allocator_img_op_mem_datas,
                                                VkMemoryPropertyFlags*  bind_img_op_mem_properties,
                                                ResourceData*           allocator_img_datas,
                                                const MemoryData*       allocator_img_mem_datas,
                                                VkMemoryPropertyFlags*  bind_img_mem_properties)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (bind_info_count == 0)
    {
        return result;
    }

    std::vector<VkBindSparseInfo> modified_bind_infos(bind_infos, bind_infos + bind_info_count);

    std::vector<std::vector<VkSparseBufferMemoryBindInfo>>      modified_buffer_bind_infos(bind_info_count);
    std::vector<std::vector<VkSparseImageOpaqueMemoryBindInfo>> modified_image_opaque_bind_infos(bind_info_count);
    std::vector<std::vector<VkSparseImageMemoryBindInfo>>       modified_image_bind_infos(bind_info_count);

    std::vector<std::vector<VkSparseMemoryBind>>      memory_binds;
    std::vector<std::vector<VkSparseImageMemoryBind>> image_memory_binds;

    std::unordered_set<VkDeviceMemory> vma_mem_blocks;
    std::vector<VmaMemoryInfo*>        vma_memory_infos;

    uint32_t alc_buf_i    = 0;
    uint32_t alc_img_op_i = 0;
    uint32_t alc_img_i    = 0;

    uint32_t alc_buf_mem_i    = 0;
    uint32_t alc_img_op_mem_i = 0;
    uint32_t alc_img_mem_i    = 0;

    for (uint32_t i = 0; i < bind_info_count; ++i)
    {
        const VkBindSparseInfo& original_bind_info = bind_infos[i];
        VkBindSparseInfo&       modified_bind_info = modified_bind_infos[i];

        modified_buffer_bind_infos[i]       = { original_bind_info.pBufferBinds,
                                                original_bind_info.pBufferBinds + original_bind_info.bufferBindCount };
        modified_image_opaque_bind_infos[i] = { original_bind_info.pImageOpaqueBinds,
                                                original_bind_info.pImageOpaqueBinds +
                                                    original_bind_info.imageOpaqueBindCount };
        modified_image_bind_infos[i]        = { original_bind_info.pImageBinds,
                                                original_bind_info.pImageBinds + original_bind_info.imageBindCount };

        for (uint32_t buf_i = 0; buf_i < original_bind_info.bufferBindCount; ++buf_i)
        {
            const VkSparseBufferMemoryBindInfo& original_buffer_bind_info = original_bind_info.pBufferBinds[buf_i];
            VkSparseBufferMemoryBindInfo&       modified_buffer_bind_info = modified_buffer_bind_infos[i][buf_i];

            memory_binds.emplace_back(original_buffer_bind_info.pBinds,
                                      original_buffer_bind_info.pBinds + original_buffer_bind_info.bindCount);

            for (uint32_t buf_mem_i = 0; buf_mem_i < original_buffer_bind_info.bindCount; ++buf_mem_i)
            {
                const VkSparseMemoryBind& original_memory_bind = original_buffer_bind_info.pBinds[buf_mem_i];
                MemoryAllocInfo*          mem_alloc_info =
                    reinterpret_cast<MemoryAllocInfo*>(allocator_buf_mem_datas[alc_buf_mem_i]);
                RebindSparseMemory<VkSparseMemoryBind, std::unordered_set<VkDeviceMemory>>(
                    original_memory_bind,
                    memory_binds.back()[buf_mem_i],
                    reinterpret_cast<ResourceAllocInfo*>(allocator_buf_datas[alc_buf_i]),
                    mem_alloc_info,
                    vma_mem_blocks,
                    vma_memory_infos,
                    original_buffer_bind_info.buffer,
                    VK_NULL_HANDLE,
                    "buffer",
                    original_memory_bind.size);
                ++alc_buf_mem_i;
            }

            modified_buffer_bind_info.pBinds = memory_binds.back().data();

            ++alc_buf_i;
        }

        for (uint32_t img_op_i = 0; img_op_i < original_bind_info.imageOpaqueBindCount; ++img_op_i)
        {
            const VkSparseImageOpaqueMemoryBindInfo& original_image_opaque_bind_info =
                original_bind_info.pImageOpaqueBinds[img_op_i];
            VkSparseImageOpaqueMemoryBindInfo& modified_image_opaque_bind_info =
                modified_image_opaque_bind_infos[i][img_op_i];

            memory_binds.emplace_back(original_image_opaque_bind_info.pBinds,
                                      original_image_opaque_bind_info.pBinds +
                                          original_image_opaque_bind_info.bindCount);

            for (uint32_t img_op_mem_i = 0; img_op_mem_i < original_image_opaque_bind_info.bindCount; ++img_op_mem_i)
            {
                const VkSparseMemoryBind& original_memory_bind = original_image_opaque_bind_info.pBinds[img_op_mem_i];
                auto* mem_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_img_op_mem_datas[alc_img_op_mem_i]);
                RebindSparseMemory<VkSparseMemoryBind, std::unordered_set<VkDeviceMemory>>(
                    original_memory_bind,
                    memory_binds.back()[img_op_mem_i],
                    reinterpret_cast<ResourceAllocInfo*>(allocator_img_op_datas[alc_img_op_i]),
                    mem_alloc_info,
                    vma_mem_blocks,
                    vma_memory_infos,
                    VK_NULL_HANDLE,
                    original_image_opaque_bind_info.image,
                    "imageOpaque",
                    original_memory_bind.size);
                ++alc_img_op_mem_i;
            }

            modified_image_opaque_bind_info.pBinds = memory_binds.back().data();

            ++alc_img_op_i;
        }

        for (uint32_t img_i = 0; img_i < original_bind_info.imageBindCount; ++img_i)
        {
            const VkSparseImageMemoryBindInfo& original_image_bind_info = original_bind_info.pImageBinds[img_i];
            VkSparseImageMemoryBindInfo&       modified_image_bind_info = modified_image_bind_infos[i][img_i];

            image_memory_binds.emplace_back(original_image_bind_info.pBinds,
                                            original_image_bind_info.pBinds + original_image_bind_info.bindCount);

            for (uint32_t img_mem_i = 0; img_mem_i < original_image_bind_info.bindCount; ++img_mem_i)
            {
                const VkSparseImageMemoryBind& original_memory_bind = original_image_bind_info.pBinds[img_mem_i];
                auto* mem_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_img_mem_datas[alc_img_mem_i]);

                RebindSparseMemory<VkSparseImageMemoryBind, std::unordered_set<VkDeviceMemory>>(
                    original_memory_bind,
                    image_memory_binds.back()[img_mem_i],
                    reinterpret_cast<ResourceAllocInfo*>(allocator_img_datas[alc_img_i]),
                    mem_alloc_info,
                    vma_mem_blocks,
                    vma_memory_infos,
                    VK_NULL_HANDLE,
                    original_image_bind_info.image,
                    "image",
                    0);

                ++alc_img_mem_i;
            }
            modified_image_bind_info.pBinds = image_memory_binds.back().data();
            ++alc_img_i;
        }

        GFXRECON_NARROWING_ASSIGN(modified_bind_info.bufferBindCount, modified_buffer_bind_infos[i].size());
        modified_bind_info.pBufferBinds = modified_buffer_bind_infos[i].data();
        GFXRECON_NARROWING_ASSIGN(modified_bind_info.imageOpaqueBindCount, modified_image_opaque_bind_infos[i].size());
        modified_bind_info.pImageOpaqueBinds = modified_image_opaque_bind_infos[i].data();
        GFXRECON_NARROWING_ASSIGN(modified_bind_info.imageBindCount, modified_image_bind_infos[i].size());
        modified_bind_info.pImageBinds = modified_image_bind_infos[i].data();
    }

    std::vector<std::unique_lock<std::mutex>> block_locks;
    if (allocator_->m_UseMutex)
    {
        block_locks.reserve(vma_mem_blocks.size());
        for (VkDeviceMemory mem : vma_mem_blocks)
        {
            block_locks.emplace_back(GetOrCreateBlockMutex(mem));
        }
    }

    result = functions_.queue_bind_sparse(
        queue, GFXRECON_NARROWING_CAST(uint32_t, modified_bind_infos.size()), modified_bind_infos.data(), fence);

    block_locks.clear();

    if (result == VK_SUCCESS)
    {
        alc_buf_i    = 0;
        alc_img_op_i = 0;
        alc_img_i    = 0;

        alc_buf_mem_i    = 0;
        alc_img_op_mem_i = 0;
        alc_img_mem_i    = 0;

        uint32_t vma_mem_info_i = 0;

        for (const VkBindSparseInfo& bind_info : modified_bind_infos)
        {
            for (uint32_t buf_i = 0; buf_i < bind_info.bufferBindCount; ++buf_i)
            {
                const VkSparseBufferMemoryBindInfo& buffer_bind_info = bind_info.pBufferBinds[buf_i];

                for (uint32_t buf_mem_i = 0; buf_mem_i < buffer_bind_info.bindCount; ++buf_mem_i)
                {
                    auto res_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buf_datas[alc_buf_i]);
                    auto mem_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_buf_mem_datas[alc_buf_mem_i]);

                    if (mem_alloc_info != nullptr)
                    {
                        UpdateAllocInfo(*res_alloc_info,
                                        VK_HANDLE_TO_UINT64(buffer_bind_info.buffer),
                                        MemoryInfoType::kSparse,
                                        *mem_alloc_info,
                                        *vma_memory_infos[vma_mem_info_i],
                                        bind_buf_mem_properties[alc_buf_mem_i]);
                    }

                    ++vma_mem_info_i;
                    ++alc_buf_mem_i;
                }
                ++alc_buf_i;
            }

            for (uint32_t img_op_i = 0; img_op_i < bind_info.imageOpaqueBindCount; ++img_op_i)
            {
                const VkSparseImageOpaqueMemoryBindInfo& image_opaque_bind_info = bind_info.pImageOpaqueBinds[img_op_i];

                for (uint32_t img_op_mem_i = 0; img_op_mem_i < image_opaque_bind_info.bindCount; ++img_op_mem_i)
                {
                    auto res_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_img_op_datas[alc_img_op_i]);
                    auto mem_alloc_info =
                        reinterpret_cast<MemoryAllocInfo*>(allocator_img_op_mem_datas[alc_img_op_mem_i]);

                    if (mem_alloc_info != nullptr)
                    {
                        UpdateAllocInfo(*res_alloc_info,
                                        VK_HANDLE_TO_UINT64(image_opaque_bind_info.image),
                                        MemoryInfoType::kSparse,
                                        *mem_alloc_info,
                                        *vma_memory_infos[vma_mem_info_i],
                                        bind_img_op_mem_properties[alc_img_op_mem_i]);
                    }

                    ++vma_mem_info_i;
                    ++alc_img_op_mem_i;
                }
                ++alc_img_op_i;
            }

            for (uint32_t img_i = 0; img_i < bind_info.imageBindCount; ++img_i)
            {
                const VkSparseImageMemoryBindInfo& image_bind_info = bind_info.pImageBinds[img_i];

                for (uint32_t img_mem_i = 0; img_mem_i < image_bind_info.bindCount; ++img_mem_i)
                {
                    auto res_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_img_datas[alc_img_i]);
                    auto mem_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_img_mem_datas[alc_img_mem_i]);

                    if (mem_alloc_info != nullptr)
                    {
                        UpdateAllocInfo(*res_alloc_info,
                                        VK_HANDLE_TO_UINT64(image_bind_info.image),
                                        MemoryInfoType::kSparse,
                                        *mem_alloc_info,
                                        *vma_memory_infos[vma_mem_info_i],
                                        bind_img_mem_properties[alc_img_mem_i]);
                    }

                    ++vma_mem_info_i;
                    ++alc_img_mem_i;
                }
                ++alc_img_i;
            }
        }
    }

    return result;
}

uint64_t VulkanRebindAllocator::GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* info,
                                                                    MemoryData allocator_data)
{
    auto             modified_info     = *info;
    MemoryAllocInfo* memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_data);
    GFXRECON_ASSERT(memory_alloc_info);

    if (memory_alloc_info->vma_mem_infos.empty())
    {
        GFXRECON_LOG_WARNING(
            "There's no allocations or memory is VK_NULL_HANDLE. Skip GetDeviceMemoryOpaqueCaptureAddress");
        return 0;
    }

    uint64_t result = 0;

    for (const auto& mem_info : memory_alloc_info->vma_mem_infos)
    {
        modified_info.memory = mem_info->allocation_info.deviceMemory;

        switch (mem_info->allocation->GetType())
        {
            case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
            {
                result = functions_.get_device_memory_opaque_capture_address(device_, &modified_info);
                break;
            }
            case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
            {
                VmaDeviceMemoryBlock* const pBlock = mem_info->allocation->GetBlock();
                VMA_ASSERT(pBlock &&
                           "GetDeviceMemoryOpaqueCaptureAddress to allocation that doesn't belong to any block.");

                std::unique_lock lock(GetOrCreateBlockMutex(pBlock->GetDeviceMemory()), std::defer_lock);
                if (allocator_->m_UseMutex)
                {
                    lock.lock();
                }
                result = functions_.get_device_memory_opaque_capture_address(device_, &modified_info);
                break;
            }
            default:
                VMA_ASSERT(0);
        }
    }
    return result;
}

void VulkanRebindAllocator::ClearStagingResources()
{
    if (staging_resources_.empty())
    {
        return;
    }
    const auto           num_fences = GFXRECON_NARROWING_CAST(uint32_t, staging_resources_.size());
    std::vector<VkFence> fences(num_fences);
    for (uint32_t i = 0; i < num_fences; i++)
    {
        fences[i] = staging_resources_[i].staging_fence;
    }
    // Tearing down replay-synthesized staging resources; one injected-commands window covers it all.
    auto injected = device_table_.Open();

    injected->WaitForFences(device_, num_fences, fences.data(), VK_TRUE, UINT64_MAX);
    std::vector<VkCommandBuffer> cmd_buffers_to_delete;

    for (auto& staging_resource : staging_resources_)
    {
        cmd_buffers_to_delete.push_back(staging_resource.cmd_buffer);
        injected->DestroyFence(device_, staging_resource.staging_fence, nullptr);
        injected->DestroySemaphore(device_, staging_resource.staging_semaphore, nullptr);
        vmaDestroyBuffer(allocator_, staging_resource.staging_buf, staging_resource.staging_alloc);
    }
    injected->FreeCommandBuffers(device_,
                                 cmd_pool_,
                                 GFXRECON_NARROWING_CAST(uint32_t, cmd_buffers_to_delete.size()),
                                 cmd_buffers_to_delete.data());
    staging_resources_.clear();
}

VmaMemoryUsage VulkanRebindAllocator::GetTensorMemoryUsage(VkTensorUsageFlagsARM       tensor_usage,
                                                           VkMemoryPropertyFlags       capture_properties,
                                                           const VkMemoryRequirements& replay_requirements)
{
    VmaMemoryUsage memory_usage        = VMA_MEMORY_USAGE_CPU_TO_GPU;
    bool           prefer_device_local = false;

    if (tensor_usage == VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM)
    {
        memory_usage = VMA_MEMORY_USAGE_CPU_ONLY;
    }
    else if (tensor_usage == VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM)
    {
        memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
    }
    else if ((capture_device_type_ == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) &&
             ((tensor_usage & VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM) == VK_TENSOR_USAGE_TRANSFER_DST_BIT_ARM) &&
             (((tensor_usage & VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM) != VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM)))
    {
        prefer_device_local = true;
    }

    capture_properties &= ~(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD | VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);

    if ((memory_usage != VMA_MEMORY_USAGE_GPU_TO_CPU) &&
        (capture_properties & VK_MEMORY_PROPERTY_HOST_CACHED_BIT) == VK_MEMORY_PROPERTY_HOST_CACHED_BIT)
    {
        memory_usage = VMA_MEMORY_USAGE_GPU_TO_CPU;
    }
    else if (memory_usage != VMA_MEMORY_USAGE_GPU_ONLY)
    {
        if (capture_properties == VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
        {
            memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
        }
        else if (((capture_properties & (VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) ==
                  (VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) &&
                 prefer_device_local)
        {
            memory_usage = VMA_MEMORY_USAGE_GPU_ONLY;
        }
    }

    return AdjustMemoryUsage(memory_usage, replay_requirements);
}

VkResult VulkanRebindAllocator::CreateTensor(const VkTensorCreateInfoARM* create_info,
                                             const VkAllocationCallbacks* allocation_callbacks,
                                             format::HandleId             capture_id,
                                             VkTensorARM*                 tensor,
                                             ResourceData*                allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((create_info != nullptr) && (tensor != nullptr) && (allocator_data != nullptr))
    {
        result = functions_.create_tensor(device_, create_info, allocator_->GetAllocationCallbacks(), tensor);

        if (result >= 0)
        {
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->usage       = create_info->pDescription->usage;
            resource_alloc_info->object_type = VK_OBJECT_TYPE_TENSOR_ARM;
            (*allocator_data)                = reinterpret_cast<uintptr_t>(resource_alloc_info);

            if (create_info->pNext != nullptr)
            {
                resource_alloc_info->uses_extensions = true;
            }
        }
    }

    return result;
}

VkResult
VulkanRebindAllocator::CreateDataGraphPipelineSession(const VkDataGraphPipelineSessionCreateInfoARM* create_info,
                                                      const VkAllocationCallbacks*   allocation_callbacks,
                                                      format::HandleId               capture_id,
                                                      VkDataGraphPipelineSessionARM* data_graph_pipeline_session,
                                                      ResourceData*                  allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    if (!create_info || !data_graph_pipeline_session || !allocator_data)
    {
        GFXRECON_LOG_DEBUG(
            "CreateDataGraphPipelineSession: invalid input (create_info=%p, session=%p, allocator_data=%p)",
            (void*)create_info,
            (void*)data_graph_pipeline_session,
            (void*)allocator_data);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    *allocator_data = 0;

    VkResult result = functions_.create_data_graph_pipeline_session(
        device_, create_info, allocator_->GetAllocationCallbacks(), data_graph_pipeline_session);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateDataGraphPipelineSession: vkCreateDataGraphPipelineSessionARM failed: %d", result);
        return result;
    }

    ResourceAllocInfo* resource_alloc_info = new ResourceAllocInfo();
    resource_alloc_info->object_type       = VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM;
    resource_alloc_info->uses_extensions   = (create_info->pNext != nullptr);
    resource_alloc_info->usage             = create_info->flags;

    ResourceData session_allocator_data = reinterpret_cast<ResourceData>(resource_alloc_info);

    // Replay may require session memory even when capture required none and therefore emitted no bind command.
    // Initialize directly from replay requirements as part of creating the replay session.
    result = InitializeDataGraphPipelineSessionMemory(*data_graph_pipeline_session, resource_alloc_info);
    if (result != VK_SUCCESS)
    {
        functions_.destroy_data_graph_pipeline_session(
            device_, *data_graph_pipeline_session, allocator_->GetAllocationCallbacks());
        delete resource_alloc_info;
        *data_graph_pipeline_session = VK_NULL_HANDLE;
        return result;
    }

    *allocator_data = session_allocator_data;
    return VK_SUCCESS;
}

void VulkanRebindAllocator::DestroyDataGraphPipelineSession(VkDataGraphPipelineSessionARM data_graph_pipeline_session,
                                                            const VkAllocationCallbacks*  allocation_callbacks,
                                                            ResourceData                  allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        RemoveVmaMemoryInfo(*resource_alloc_info, VK_HANDLE_TO_UINT64(data_graph_pipeline_session));
        delete resource_alloc_info;
    }

    functions_.destroy_data_graph_pipeline_session(
        device_, data_graph_pipeline_session, allocator_->GetAllocationCallbacks());
}

void VulkanRebindAllocator::DestroyTensor(VkTensorARM                  tensor,
                                          const VkAllocationCallbacks* allocation_callbacks,
                                          ResourceData                 allocator_data)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    if (allocator_data != 0)
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        RemoveVmaMemoryInfo(*resource_alloc_info, VK_HANDLE_TO_UINT64(tensor));
        delete resource_alloc_info;
    }

    functions_.destroy_tensor(device_, tensor, allocator_->GetAllocationCallbacks());
}

VkResult
VulkanRebindAllocator::AllocateMemoryForTensor(VkTensorARM                             tensor,
                                               VkDeviceSize                            memory_offset,
                                               const VkPhysicalDeviceMemoryProperties& device_memory_properties,
                                               ResourceAllocInfo&                      resource_alloc_info,
                                               MemoryAllocInfo&                        memory_alloc_info,
                                               VmaMemoryInfo**                         vma_mem_info)
{
    VkMemoryRequirements capture_req = {};
    if (resource_alloc_info.capture_mem_reqs.size() > 0)
    {
        capture_req = resource_alloc_info.capture_mem_reqs[0];
    }

    VkTensorMemoryRequirementsInfoARM tensor_mem_req{};
    tensor_mem_req.sType  = VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM;
    tensor_mem_req.tensor = tensor;

    VkMemoryRequirements2 replay_req_2{};
    replay_req_2.sType = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;

    functions_.get_tensor_memory_requirements(device_, &tensor_mem_req, &replay_req_2);

    VkMemoryRequirements& replay_req                    = replay_req_2.memoryRequirements;
    bool                  requires_dedicated_allocation = false;
    bool                  prefers_dedicated_allocation  = false;

    VmaAllocationCreateInfo create_info{};
    create_info.flags = 0;
    create_info.usage =
        GetTensorMemoryUsage(resource_alloc_info.usage,
                             device_memory_properties.memoryTypes[memory_alloc_info.original_index].propertyFlags,
                             replay_req);
    create_info.requiredFlags  = 0;
    create_info.preferredFlags = 0;
    create_info.memoryTypeBits = 0;
    create_info.pool           = VK_NULL_HANDLE;
    create_info.pUserData      = nullptr;

    const VkDeviceSize footprint = capture_req.size;

    if (VmaMemoryInfo* aliased = FindAliasedMemoryInfo(memory_alloc_info,
                                                       memory_offset,
                                                       footprint,
                                                       replay_req,
                                                       requires_dedicated_allocation,
                                                       prefers_dedicated_allocation))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(tensor), memory_offset, footprint, aliased, replay_req.size });
        *vma_mem_info = aliased;
        return VK_SUCCESS;
    }

    if (FindVmaMemoryInfo(memory_alloc_info,
                          memory_offset,
                          capture_req,
                          replay_req,
                          requires_dedicated_allocation,
                          prefers_dedicated_allocation,
                          create_info,
                          vma_mem_info))
    {
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(tensor), memory_offset, footprint, *vma_mem_info, replay_req.size });
        return VK_SUCCESS;
    }

    VmaMemoryInfo mem_info                      = {};
    mem_info.memory_info                        = &memory_alloc_info;
    mem_info.capture_mem_req                    = capture_req;
    mem_info.replay_mem_req                     = replay_req;
    mem_info.requires_dedicated_allocation      = requires_dedicated_allocation;
    mem_info.prefers_dedicated_allocation       = prefers_dedicated_allocation;
    mem_info.alc_create_info                    = create_info;
    mem_info.offset_from_original_device_memory = memory_offset;

    // Mark vma's api calls as synthesized
    util::MarkInjectedCommandsHelper injected;
    auto                             result =
        vmaAllocateMemory(allocator_, &replay_req, &create_info, &mem_info.allocation, &mem_info.allocation_info);

    if (result >= 0)
    {
        memory_alloc_info.vma_mem_infos.emplace_back(std::make_unique<VmaMemoryInfo>(mem_info));
        *vma_mem_info = memory_alloc_info.vma_mem_infos.back().get();
        memory_alloc_info.bound_ranges.push_back(
            { VK_HANDLE_TO_UINT64(tensor), memory_offset, footprint, *vma_mem_info, replay_req.size });
    }
    return result;
}

VkResult
VulkanRebindAllocator::BindDataGraphPipelineSessionMemory(uint32_t bind_info_count,
                                                          const VkBindDataGraphPipelineSessionMemoryInfoARM* bind_infos,
                                                          const ResourceData*    allocator_session_datas,
                                                          const MemoryData*      allocator_memory_datas,
                                                          VkMemoryPropertyFlags* bind_memory_properties)
{
    // Data graph session memory is created entirely from replay-device requirements when the replay session is
    // created. Captured bind commands describe capture-device requirements, so consuming them must have no effect.
    GFXRECON_UNREFERENCED_PARAMETER(bind_info_count);
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_session_datas);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);
    GFXRECON_UNREFERENCED_PARAMETER(bind_memory_properties);
    return VK_SUCCESS;
}

VkResult VulkanRebindAllocator::InitializeDataGraphPipelineSessionMemory(VkDataGraphPipelineSessionARM session,
                                                                         ResourceAllocInfo* resource_alloc_info)
{
    struct PendingBinding
    {
        VmaAllocator                     allocator   = VK_NULL_HANDLE;
        VmaBackend*                      vma_backend = nullptr;
        std::unique_ptr<MemoryAllocInfo> memory_alloc_info;
        VmaMemoryInfo                    memory_info{};

        ~PendingBinding()
        {
            if (memory_info.allocation != VK_NULL_HANDLE)
            {
                vma_backend->FreeMemory(allocator, memory_info.allocation);
            }
        }
    };

    if ((session == VK_NULL_HANDLE) || (resource_alloc_info == nullptr) ||
        (resource_alloc_info->object_type != VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM))
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkDataGraphPipelineSessionBindPointRequirementsInfoARM requirements_info{
        VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM
    };
    requirements_info.session = session;

    uint32_t requirement_count = 0;
    VkResult result            = functions_.get_data_graph_pipeline_session_bind_point_requirements(
        device_, &requirements_info, &requirement_count, nullptr);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("vkGetDataGraphPipelineSessionBindPointRequirementsARM failed for session 0x%llx: %d",
                           static_cast<unsigned long long>(VK_HANDLE_TO_UINT64(session)),
                           result);
        return result;
    }

    std::vector<VkDataGraphPipelineSessionBindPointRequirementARM> requirements(
        requirement_count,
        VkDataGraphPipelineSessionBindPointRequirementARM{
            VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM, nullptr });

    if (requirement_count != 0)
    {
        result = functions_.get_data_graph_pipeline_session_bind_point_requirements(
            device_, &requirements_info, &requirement_count, requirements.data());
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("vkGetDataGraphPipelineSessionBindPointRequirementsARM failed while enumerating session "
                               "0x%llx: %d",
                               static_cast<unsigned long long>(VK_HANDLE_TO_UINT64(session)),
                               result);
            return result;
        }
        requirements.resize(requirement_count);
    }

    const bool protected_session =
        (resource_alloc_info->usage & VK_DATA_GRAPH_PIPELINE_SESSION_CREATE_PROTECTED_BIT_ARM) != 0;

    std::vector<VkBindDataGraphPipelineSessionMemoryInfoARM> replay_bind_infos;
    std::vector<std::unique_ptr<PendingBinding>>             pending_bindings;

    auto injected = device_table_.Open();

    for (const auto& requirement : requirements)
    {
        if (requirement.bindPointType != VK_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_TYPE_MEMORY_ARM)
        {
            continue;
        }

        for (uint32_t object_index = 0; object_index < requirement.numObjects; ++object_index)
        {
            VkDataGraphPipelineSessionMemoryRequirementsInfoARM memory_requirements_info{
                VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM
            };
            memory_requirements_info.session     = session;
            memory_requirements_info.bindPoint   = requirement.bindPoint;
            memory_requirements_info.objectIndex = object_index;

            VkMemoryRequirements2 memory_requirements{ VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 };
            functions_.get_data_graph_pipeline_session_memory_requirements(
                device_, &memory_requirements_info, &memory_requirements);

            uint32_t compatible_memory_type_bits = memory_requirements.memoryRequirements.memoryTypeBits;
            for (uint32_t memory_type_index = 0; memory_type_index < replay_memory_properties_.memoryTypeCount;
                 ++memory_type_index)
            {
                const bool protected_memory = (replay_memory_properties_.memoryTypes[memory_type_index].propertyFlags &
                                               VK_MEMORY_PROPERTY_PROTECTED_BIT) != 0;
                if (protected_memory != protected_session)
                {
                    compatible_memory_type_bits &= ~(1u << memory_type_index);
                }
            }

            if (compatible_memory_type_bits == 0)
            {
                GFXRECON_LOG_ERROR(
                    "No compatible %s memory type for data graph session 0x%llx bindPoint=%u objectIndex=%u.",
                    protected_session ? "protected" : "unprotected",
                    static_cast<unsigned long long>(VK_HANDLE_TO_UINT64(session)),
                    static_cast<unsigned>(requirement.bindPoint),
                    object_index);
                return VK_ERROR_FEATURE_NOT_PRESENT;
            }

            VmaAllocationCreateInfo allocation_create_info{};
            // Session memory is device-side working memory that is never mapped. Without a preference VMA
            // takes the lowest compatible memory type index, which is not device-local everywhere.
            allocation_create_info.usage          = VMA_MEMORY_USAGE_GPU_ONLY;
            allocation_create_info.memoryTypeBits = compatible_memory_type_bits;
            allocation_create_info.requiredFlags  = protected_session ? VK_MEMORY_PROPERTY_PROTECTED_BIT : 0;

            auto pending_binding                                = std::make_unique<PendingBinding>();
            pending_binding->allocator                          = allocator_;
            pending_binding->vma_backend                        = vma_backend_;
            pending_binding->memory_alloc_info                  = std::make_unique<MemoryAllocInfo>();
            pending_binding->memory_alloc_info->allocation_size = memory_requirements.memoryRequirements.size;
            pending_binding->memory_alloc_info->is_free         = true;

            auto& memory_info                              = pending_binding->memory_info;
            memory_info.memory_info                        = pending_binding->memory_alloc_info.get();
            memory_info.replay_mem_req                     = memory_requirements.memoryRequirements;
            memory_info.alc_create_info                    = allocation_create_info;
            memory_info.offset_from_original_device_memory = 0;

            util::MarkInjectedCommandsHelper injected;
            result = vma_backend_->AllocateMemory(allocator_,
                                                  &memory_requirements.memoryRequirements,
                                                  &allocation_create_info,
                                                  &memory_info.allocation,
                                                  &memory_info.allocation_info);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "vmaAllocateMemory failed for data graph session 0x%llx bindPoint=%u objectIndex=%u: %d",
                    static_cast<unsigned long long>(VK_HANDLE_TO_UINT64(session)),
                    static_cast<unsigned>(requirement.bindPoint),
                    object_index,
                    result);
                return result;
            }

            VkBindDataGraphPipelineSessionMemoryInfoARM replay_bind_info{
                VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM
            };
            replay_bind_info.session      = session;
            replay_bind_info.bindPoint    = requirement.bindPoint;
            replay_bind_info.objectIndex  = object_index;
            replay_bind_info.memory       = memory_info.allocation_info.deviceMemory;
            replay_bind_info.memoryOffset = memory_info.allocation_info.offset;

            replay_bind_infos.push_back(replay_bind_info);
            pending_bindings.emplace_back(std::move(pending_binding));
        }
    }

    if (!replay_bind_infos.empty())
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(uint32_t, replay_bind_infos.size());
        result = functions_.bind_data_graph_pipeline_session_memory(
            device_, static_cast<uint32_t>(replay_bind_infos.size()), replay_bind_infos.data());
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "vkBindDataGraphPipelineSessionMemoryARM failed for replay-generated batch of %zu bindings: %d",
                replay_bind_infos.size(),
                result);
            return result;
        }
    }

    for (auto& pending_binding_ptr : pending_bindings)
    {
        auto& pending_binding       = *pending_binding_ptr;
        auto  memory_alloc_info     = std::move(pending_binding.memory_alloc_info);
        auto* memory_alloc_info_ptr = memory_alloc_info.get();
        memory_alloc_info_ptr->vma_mem_infos.emplace_back(std::make_unique<VmaMemoryInfo>(pending_binding.memory_info));

        auto* committed_memory_info            = memory_alloc_info_ptr->vma_mem_infos.back().get();
        pending_binding.memory_info.allocation = VK_NULL_HANDLE;

        VkMemoryPropertyFlags unused_memory_properties = 0;
        UpdateAllocInfo(*resource_alloc_info,
                        VK_HANDLE_TO_UINT64(session),
                        MemoryInfoType::kDataGraphSession,
                        *memory_alloc_info_ptr,
                        *committed_memory_info,
                        unused_memory_properties);

        memory_alloc_info.release();
    }

    return VK_SUCCESS;
}

VkResult VulkanRebindAllocator::BindTensorMemory(uint32_t                         bind_info_count,
                                                 const VkBindTensorMemoryInfoARM* bind_infos,
                                                 const ResourceData*              allocator_tensor_datas,
                                                 const MemoryData*                allocator_memory_datas,
                                                 VkMemoryPropertyFlags*           bind_memory_properties)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (bind_infos != nullptr && allocator_tensor_datas != nullptr && allocator_memory_datas != nullptr &&
        bind_memory_properties != nullptr)
    {
        result = VK_SUCCESS;

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            VkTensorARM tensor                = bind_infos[i].tensor;
            uintptr_t   allocator_tensor_data = allocator_tensor_datas[i];
            uintptr_t   allocator_memory_data = allocator_memory_datas[i];

            if ((tensor != VK_NULL_HANDLE) && (allocator_tensor_data != 0) && (allocator_memory_data != 0))
            {
                auto           resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_tensor_data);
                auto           memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                VkDeviceSize   memory_offset       = bind_infos[i].memoryOffset;
                VmaMemoryInfo* vma_mem_info        = nullptr;

                const size_t vma_count_before = memory_alloc_info->vma_mem_infos.size();
                result                        = AllocateMemoryForTensor(tensor,
                                                 memory_offset,
                                                 capture_memory_properties_,
                                                 *resource_alloc_info,
                                                 *memory_alloc_info,
                                                 &vma_mem_info);

                if (result >= 0)
                {
                    auto offset = GetRebindOffsetFromOriginalDeviceMemory(memory_offset, *vma_mem_info);

                    VkBindTensorMemoryInfoARM bind_tensor_memory_info{};
                    bind_tensor_memory_info.sType        = VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM;
                    bind_tensor_memory_info.tensor       = tensor;
                    bind_tensor_memory_info.memory       = vma_mem_info->allocation_info.deviceMemory;
                    bind_tensor_memory_info.memoryOffset = offset;
                    result = functions_.bind_tensor_memory(device_, 1, &bind_tensor_memory_info);

                    if (result >= 0)
                    {
                        UpdateAllocInfo(*resource_alloc_info,
                                        VK_HANDLE_TO_UINT64(tensor),
                                        MemoryInfoType::kBasic,
                                        *memory_alloc_info,
                                        *vma_mem_info,
                                        bind_memory_properties[i]);
                    }
                    else
                    {
                        // The bind failed: drop the recorded range, and free a new per-resource VMA
                        // allocation that was never successfully bound to avoid a leak.
                        RemoveBoundRange(*memory_alloc_info, VK_HANDLE_TO_UINT64(tensor));
                        if (memory_alloc_info->vma_mem_infos.size() > vma_count_before)
                        {
                            // Mark vma's api calls as synthesized
                            util::MarkInjectedCommandsHelper injected;
                            vmaFreeMemory(allocator_, vma_mem_info->allocation);
                            memory_alloc_info->vma_mem_infos.pop_back();
                        }
                    }
                }
            }
        }
    }
    return result;
}

void VulkanRebindAllocator::GetTensorMemoryRequirementsARM(
    VkTensorMemoryRequirementsInfoARM* tensor_memory_requirements,
    VkMemoryRequirements2*             memory_requirements,
    ResourceData                       allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info              = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        resource_alloc_info->capture_mem_reqs = { memory_requirements->memoryRequirements };
    }

    functions_.get_tensor_memory_requirements(device_, tensor_memory_requirements, memory_requirements);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
