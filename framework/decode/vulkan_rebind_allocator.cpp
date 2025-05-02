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

// This file needs to be included first to ensure it is processed with the VMA_IMPLEMENTATION directive, in case it is
// indirectly included by other include files.
#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

#include "decode/vulkan_rebind_allocator.h"

#include "decode/resource_util.h"
#include "decode/vulkan_enum_util.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/alignment_utils.h"
#include "util/platform.h"
#include "graphics/vulkan_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr format::HandleId kPlaceholderHandleId = static_cast<format::HandleId>(~0ul);
constexpr uintptr_t        kPlaceholderAddress  = static_cast<uintptr_t>(~0ul);

VulkanRebindAllocator::VulkanRebindAllocator() :
    device_(VK_NULL_HANDLE), allocator_(VK_NULL_HANDLE), vma_functions_{},
    capture_device_type_(VK_PHYSICAL_DEVICE_TYPE_OTHER), capture_memory_properties_{}, replay_memory_properties_{}
{}

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
        vma_functions_.vkGetInstanceProcAddr                   = functions_.get_instance_proc_addr;
        vma_functions_.vkGetDeviceProcAddr                     = functions_.get_device_proc_addr;

        VmaAllocatorCreateInfo create_info = {};

        create_info.physicalDevice   = physical_device;
        create_info.device           = device;
        create_info.pVulkanFunctions = &vma_functions_;
        create_info.instance         = instance;
        create_info.vulkanApiVersion = api_version;

        uint32_t queue_family_count = 0;
        functions_.get_physical_device_queue_family_properties(physical_device, &queue_family_count, nullptr);

        std::vector<VkQueueFamilyProperties> queue_family_properties(queue_family_count);
        functions_.get_physical_device_queue_family_properties(
            physical_device, &queue_family_count, queue_family_properties.data());

        staging_queue_family_ = 0;
        for (const VkQueueFamilyProperties& elt : queue_family_properties)
        {
            if (elt.queueFlags & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT))
            {
                break;
            }
            staging_queue_family_++;
        }

        VkCommandPoolCreateInfo cmd_pool_info = {};
        cmd_pool_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        cmd_pool_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        cmd_pool_info.queueFamilyIndex        = staging_queue_family_;

        result = functions_.create_command_pool(device_, &cmd_pool_info, NULL, &cmd_pool_);
        assert(result == VK_SUCCESS);

        VkCommandBufferAllocateInfo cmd_buff_alloc_info = {};
        cmd_buff_alloc_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        cmd_buff_alloc_info.pNext                       = NULL;
        cmd_buff_alloc_info.commandPool                 = cmd_pool_;
        cmd_buff_alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        cmd_buff_alloc_info.commandBufferCount          = 1;

        functions_.get_device_queue(device_, staging_queue_family_, 0, &staging_queue_);

        result = functions_.allocate_command_buffers(device_, &cmd_buff_alloc_info, &cmd_buffer_);
        assert(result == VK_SUCCESS);

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

        result = vmaCreateAllocator(&create_info, &allocator_);
    }

    return result;
}

void VulkanRebindAllocator::Destroy()
{
    functions_.free_command_buffers(device_, cmd_pool_, 1, &cmd_buffer_);
    functions_.destroy_command_pool(device_, cmd_pool_, nullptr);

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
        auto modified_info = *create_info;
        modified_info.size = util::aligned_value(create_info->size, min_buffer_alignment_);
        result             = functions_.create_buffer(device_, &modified_info, nullptr, buffer);

        if (result >= 0)
        {
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->usage       = create_info->usage;
            resource_alloc_info->object_type = ObjectType::buffer;
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
            auto resource_alloc_info         = new ResourceAllocInfo;
            resource_alloc_info->usage       = create_info->usage;
            resource_alloc_info->tiling      = create_info->tiling;
            resource_alloc_info->height      = create_info->extent.height;
            resource_alloc_info->format      = create_info->format;
            resource_alloc_info->object_type = ObjectType::image;
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

VkResult VulkanRebindAllocator::CreateVideoSession(const VkVideoSessionCreateInfoKHR* create_info,
                                                   const VkAllocationCallbacks*       allocation_callbacks,
                                                   format::HandleId                   capture_id,
                                                   VkVideoSessionKHR*                 session,
                                                   std::vector<ResourceData>*         allocator_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((create_info != nullptr) && (session != nullptr) && (allocator_datas != nullptr))
    {
        result = functions_.create_video_session(device_, create_info, allocation_callbacks, session);

        if (result >= 0)
        {
            uint32_t count = 0;
            functions_.get_video_session_memory_requirements(device_, *session, &count, nullptr);
            allocator_datas->resize(count);
            for (auto& allocator_data : *allocator_datas)
            {
                auto resource_alloc_info         = new ResourceAllocInfo;
                resource_alloc_info->object_type = ObjectType::video_session;
                allocator_data                   = reinterpret_cast<uintptr_t>(resource_alloc_info);

                if (create_info->pNext != nullptr)
                {
                    resource_alloc_info->uses_extensions = true;
                }
            }
        }
    }

    return result;
}

void VulkanRebindAllocator::DestroyVideoSession(VkVideoSessionKHR            session,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                std::vector<ResourceData>    allocator_datas)
{
    // TODO: VMA doesn't support video session(vmaDestroyVideoSession). Do it ourselves until VMA support it.
    GFXRECON_UNREFERENCED_PARAMETER(allocation_callbacks);

    uint32_t index = 0;
    for (auto& allocator_data : allocator_datas)
    {
        if (allocator_data != 0)
        {
            auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
            auto memory_alloc_info   = resource_alloc_info->memory_info;

            if (memory_alloc_info != nullptr)
            {
                memory_alloc_info->original_sessions.erase(session);
            }

            if (resource_alloc_info->allocation != VK_NULL_HANDLE)
            {
                if (resource_alloc_info->mapped_pointer != nullptr)
                {
                    vmaUnmapMemory(allocator_, resource_alloc_info->allocation);
                }
                allocator_->FreeMemory(1, &resource_alloc_info->allocation);
            }
            delete resource_alloc_info;
        }
        ++index;
    }
    allocator_datas.clear();
    GFXRECON_ASSERT(session != VK_NULL_HANDLE);
    functions_.destroy_video_session(allocator_->m_hDevice, session, allocator_->GetAllocationCallbacks());
}

void VulkanRebindAllocator::GetBufferMemoryRequirements(VkBuffer              buffer,
                                                        VkMemoryRequirements* memory_requirements,
                                                        ResourceData          allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info           = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        resource_alloc_info->original_size = memory_requirements->size;
    }

    functions_.get_buffer_memory_requirements(device_, buffer, memory_requirements);
}

void VulkanRebindAllocator::GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* info,
                                                         VkMemoryRequirements2*                 memory_requirements,
                                                         ResourceData                           allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info           = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        resource_alloc_info->original_size = memory_requirements->memoryRequirements.size;
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
        auto resource_alloc_info           = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        resource_alloc_info->original_size = memory_requirements->size;
    }

    functions_.get_image_memory_requirements(device_, image, memory_requirements);
}

void VulkanRebindAllocator::GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* info,
                                                        VkMemoryRequirements2*                memory_requirements,
                                                        ResourceData                          allocator_data)
{
    if (allocator_data != 0)
    {
        auto resource_alloc_info           = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
        resource_alloc_info->original_size = memory_requirements->memoryRequirements.size;
    }

    functions_.get_image_memory_requirements2(device_, info, memory_requirements);
}

VkResult
VulkanRebindAllocator::GetVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR video_session,
                                                            uint32_t*         memory_requirements_count,
                                                            VkVideoSessionMemoryRequirementsKHR* memory_requirements,
                                                            std::vector<ResourceData>            allocator_datas)
{
    if (memory_requirements != nullptr)
    {
        GFXRECON_ASSERT(*memory_requirements_count == allocator_datas.size());
        for (uint32_t i = 0; i < *memory_requirements_count; ++i)
        {
            if (allocator_datas[i] != 0)
            {
                auto resource_alloc_info           = reinterpret_cast<ResourceAllocInfo*>(allocator_datas[i]);
                resource_alloc_info->original_size = memory_requirements[i].memoryRequirements.size;
            }
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
        memory_alloc_info->allocation_size = allocate_info->allocationSize;
        memory_alloc_info->original_index  = allocate_info->memoryTypeIndex;

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
            functions_.free_memory(device_, memory_alloc_info->ahb_memory, nullptr);
        }

        for (const auto& entry : memory_alloc_info->original_buffers)
        {
            entry.second->memory_info = nullptr;
        }

        for (const auto& entry : memory_alloc_info->original_images)
        {
            entry.second->memory_info = nullptr;
        }

        for (const auto& entry : memory_alloc_info->original_sessions)
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
        VmaAllocation allocation          = VK_NULL_HANDLE;
        auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_buffer_data);
        auto          memory_alloc_info   = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

        VkMemoryRequirements requirements;
        functions_.get_buffer_memory_requirements(device_, buffer, &requirements);
        requirements.alignment = std::max<VkDeviceSize>(requirements.alignment, min_buffer_alignment_);

        VmaAllocationCreateInfo create_info;
        create_info.flags = 0;
        create_info.usage =
            GetBufferMemoryUsage(resource_alloc_info->usage,
                                 device_memory_properties.memoryTypes[memory_alloc_info->original_index].propertyFlags,
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
                resource_alloc_info->rebind_size     = allocation_info.size;

                VkMemoryPropertyFlags property_flags =
                    replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    resource_alloc_info->is_host_visible = true;
                }

                memory_alloc_info->original_buffers.insert(std::make_pair(buffer, resource_alloc_info));

                if (memory_alloc_info->original_content != nullptr)
                {
                    // Memory has been mapped and written prior to bind.  Copy the original content to the new
                    // allocation to ensure it contains the correct data.

                    // If the buffer is bigger at replay time than at capture time, you don't want to read
                    // memory_alloc_info->original_content out of bounds
                    VkDeviceSize copy_size =
                        std::min(allocation_info.size, memory_alloc_info->allocation_size - memory_offset);

                    WriteBoundResource(
                        resource_alloc_info, memory_offset, 0, copy_size, memory_alloc_info->original_content.get());
                }

                (*bind_memory_properties) = property_flags;

                SetBindingDebugUtilsNameAndTag(memory_alloc_info,
                                               resource_alloc_info,
                                               allocation_info.deviceMemory,
                                               VK_OBJECT_TYPE_BUFFER,
                                               VK_HANDLE_TO_UINT64(buffer));
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
                requirements.alignment = std::max<VkDeviceSize>(requirements.alignment, min_buffer_alignment_);

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
                        resource_alloc_info->rebind_size     = allocation_info.size;

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

                            // If the buffer is bigger at replay time than at capture time, you don't want to read
                            // memory_alloc_info->original_content out of bounds
                            VkDeviceSize copy_size = std::min(
                                allocation_info.size, memory_alloc_info->allocation_size - bind_info->memoryOffset);

                            WriteBoundResource(resource_alloc_info,
                                               bind_info->memoryOffset,
                                               0,
                                               copy_size,
                                               memory_alloc_info->original_content.get());
                        }

                        memory_alloc_info->original_buffers.insert(std::make_pair(buffer, resource_alloc_info));

                        bind_memory_properties[i] = property_flags;

                        SetBindingDebugUtilsNameAndTag(memory_alloc_info,
                                                       resource_alloc_info,
                                                       allocation_info.deviceMemory,
                                                       VK_OBJECT_TYPE_BUFFER,
                                                       VK_HANDLE_TO_UINT64(buffer));
                    }
                }
            }
        }
    }

    return result;
}

VkResult VulkanRebindAllocator::AllocateAHBMemory(MemoryAllocInfo* memory_alloc_info, const VkImage image)
{
    VkImportAndroidHardwareBufferInfoANDROID importAHBInfo;
    importAHBInfo.sType  = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
    importAHBInfo.pNext  = nullptr;
    importAHBInfo.buffer = memory_alloc_info->ahb;

    VkMemoryDedicatedAllocateInfo dedicatedAllocateInfo{};
    dedicatedAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
    dedicatedAllocateInfo.pNext = &importAHBInfo;
    dedicatedAllocateInfo.image = image;

    VkMemoryRequirements memoryRequirements;
    functions_.get_image_memory_requirements(device_, image, &memoryRequirements);

    VkMemoryAllocateInfo allocate_info{};
    allocate_info.sType           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.pNext           = &dedicatedAllocateInfo;
    allocate_info.allocationSize  = memory_alloc_info->allocation_size;
    allocate_info.memoryTypeIndex = replay_memory_properties_.memoryTypeCount;
    for (uint32_t i = 0; i < replay_memory_properties_.memoryTypeCount; ++i)
    {
        if ((memoryRequirements.memoryTypeBits & (1 << i)) &&
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
            VmaAllocation allocation          = VK_NULL_HANDLE;
            auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);

            VkMemoryRequirements requirements;
            functions_.get_image_memory_requirements(device_, image, &requirements);

            VmaAllocationCreateInfo create_info;
            create_info.flags = 0;
            create_info.usage = GetImageMemoryUsage(
                resource_alloc_info->usage,
                resource_alloc_info->tiling,
                device_memory_properties.memoryTypes[memory_alloc_info->original_index].propertyFlags,
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
                    resource_alloc_info->rebind_size     = allocation_info.size;

                    VkMemoryPropertyFlags property_flags =
                        replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                    if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                    {
                        resource_alloc_info->is_host_visible = true;
                    }

                    memory_alloc_info->original_images.insert(std::make_pair(image, resource_alloc_info));

                    if (memory_alloc_info->original_content != nullptr)
                    {
                        // Memory has been mapped and written prior to bind.  Copy the original content to the new
                        // allocation to ensure it contains the correct data.

                        // If the image is bigger at replay time than at capture time, you don't want to read
                        // memory_alloc_info->original_content out of bounds
                        VkDeviceSize copy_size =
                            std::min(allocation_info.size, memory_alloc_info->allocation_size - memory_offset);

                        WriteBoundResource(resource_alloc_info,
                                           memory_offset,
                                           0,
                                           copy_size,
                                           memory_alloc_info->original_content.get());
                    }

                    (*bind_memory_properties) = property_flags;

                    SetBindingDebugUtilsNameAndTag(memory_alloc_info,
                                                   resource_alloc_info,
                                                   allocation_info.deviceMemory,
                                                   VK_OBJECT_TYPE_IMAGE,
                                                   VK_HANDLE_TO_UINT64(image));
                }
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
                auto memory_alloc_info = reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);
                if (memory_alloc_info->ahb)
                {
                    VkDeviceSize memory_offset = bind_infos[i].memoryOffset;

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
                    VmaAllocation allocation          = VK_NULL_HANDLE;
                    auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_image_data);

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
                            resource_alloc_info->rebind_size     = allocation_info.size;

                            VkMemoryPropertyFlags property_flags =
                                replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                            if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                            {
                                resource_alloc_info->is_host_visible = true;
                            }

                            if (memory_alloc_info->original_content != nullptr)
                            {
                                // Memory has been mapped and written prior to bind.  Copy the original content to the
                                // new allocation to ensure it contains the correct data.

                                // If the image is bigger at replay time than at capture time, you don't want to read
                                // memory_alloc_info->original_content out of bounds
                                VkDeviceSize copy_size = std::min(
                                    allocation_info.size, memory_alloc_info->allocation_size - bind_info->memoryOffset);

                                WriteBoundResource(resource_alloc_info,
                                                   bind_info->memoryOffset,
                                                   0,
                                                   copy_size,
                                                   memory_alloc_info->original_content.get());
                            }

                            memory_alloc_info->original_images.insert(std::make_pair(image, resource_alloc_info));

                            bind_memory_properties[i] = property_flags;

                            SetBindingDebugUtilsNameAndTag(memory_alloc_info,
                                                           resource_alloc_info,
                                                           allocation_info.deviceMemory,
                                                           VK_OBJECT_TYPE_IMAGE,
                                                           VK_HANDLE_TO_UINT64(image));
                        }
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
                                                       const ResourceData*                    allocator_session_datas,
                                                       const MemoryData*                      allocator_memory_datas,
                                                       VkMemoryPropertyFlags*                 bind_memory_properties)
{
    // TODO: VMA doesn't support video session(vmaAllocateMemoryForVideoSession and vmaBindVideoSessionMemory).
    //       Do it ourselves until VMA support it.
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((video_session != VK_NULL_HANDLE) && (bind_infos != nullptr) && (allocator_session_datas != nullptr) &&
        (allocator_memory_datas != nullptr) && (bind_memory_properties != nullptr))
    {
        uint32_t session_requirements_count = 0;
        functions_.get_video_session_memory_requirements(device_, video_session, &session_requirements_count, nullptr);

        VkVideoSessionMemoryRequirementsKHR reqs = {};
        reqs.sType                               = VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR;
        std::vector<VkVideoSessionMemoryRequirementsKHR> session_requirements(session_requirements_count, reqs);
        functions_.get_video_session_memory_requirements(
            device_, video_session, &session_requirements_count, session_requirements.data());

        // Use replay MemoryRequeirements to AllocateMemory and Bind.
        for (uint32_t mem_index = 0; mem_index < session_requirements_count; ++mem_index)
        {
            uintptr_t allocator_session_data = allocator_session_datas[mem_index];
            uintptr_t allocator_memory_data  = allocator_memory_datas[mem_index];

            if (allocator_session_data != 0)
            {
                VmaAllocation allocation          = VK_NULL_HANDLE;
                auto          resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_session_data);

                // if allocator_memory_data is 0, it means replay MemoryRequirements has more count.
                MemoryAllocInfo* memory_alloc_info = (allocator_memory_data == 0)
                                                         ? new MemoryAllocInfo
                                                         : reinterpret_cast<MemoryAllocInfo*>(allocator_memory_data);

                auto requirements = session_requirements[mem_index].memoryRequirements;
                if (allocator_memory_data == 0)
                {
                    memory_alloc_info->allocation_size = requirements.size;
                    memory_alloc_info->original_index  = requirements.memoryTypeBits;
                }
                VmaAllocationCreateInfo create_info;
                create_info.flags = 0;
                create_info.usage = GetVideoSeesionMemoryUsage(
                    capture_memory_properties_.memoryTypes[memory_alloc_info->original_index].propertyFlags,
                    requirements);
                create_info.requiredFlags  = 0;
                create_info.preferredFlags = 0;
                create_info.memoryTypeBits = 0;
                create_info.pool           = VK_NULL_HANDLE;
                create_info.pUserData      = nullptr;

                VmaAllocationInfo allocation_info;
                result = allocator_->AllocateMemory(session_requirements[mem_index].memoryRequirements,
                                                    false,
                                                    false,
                                                    VK_NULL_HANDLE,               // dedicatedBuffer
                                                    VK_NULL_HANDLE,               // dedicatedImage
                                                    VmaBufferImageUsage::UNKNOWN, // dedicatedBufferImageUsage
                                                    create_info,
                                                    VMA_SUBALLOCATION_TYPE_FREE,
                                                    1, // allocationCount
                                                    &allocation);

                if (result == VK_SUCCESS)
                {
                    allocator_->GetAllocationInfo(allocation, &allocation_info);
                }

                if (result >= 0)
                {
                    VkBindVideoSessionMemoryInfoKHR modified_bind_info{};
                    modified_bind_info.sType           = VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR;
                    modified_bind_info.memoryBindIndex = mem_index;
                    modified_bind_info.memoryOffset    = 0;
                    modified_bind_info.memorySize      = session_requirements[mem_index].memoryRequirements.size;

                    switch (allocation->GetType())
                    {
                        case VmaAllocation_T::ALLOCATION_TYPE_DEDICATED:
                        {
                            modified_bind_info.memory = allocation->GetMemory();
                            result =
                                functions_.bind_video_session_memory(device_, video_session, 1, &modified_bind_info);
                            break;
                        }
                        case VmaAllocation_T::ALLOCATION_TYPE_BLOCK:
                        {
                            VmaDeviceMemoryBlock* const pBlock = allocation->GetBlock();
                            VMA_ASSERT(pBlock &&
                                       "Binding Video Seesion to allocation that doesn't belong to any block.");

                            // This lock is important so that we don't call vkBind... and/or vkMap... simultaneously
                            // on the same VkDeviceMemory from multiple threads.
                            VmaMutexLock lock(pBlock->m_MapAndBindMutex, allocator_->m_UseMutex);
                            modified_bind_info.memory = pBlock->m_hMemory;
                            modified_bind_info.memoryOffset += allocation->GetOffset();
                            result =
                                functions_.bind_video_session_memory(device_, video_session, 1, &modified_bind_info);
                            break;
                        }
                        default:
                            VMA_ASSERT(0);
                    }

                    if (result >= 0)
                    {
                        resource_alloc_info->allocation     = allocation;
                        resource_alloc_info->mapped_pointer = nullptr;
                        resource_alloc_info->memory_info    = memory_alloc_info;

                        // The new bind_infos's index and captured bind_infos's index meanings are different.
                        VkDeviceSize src_offset = 0;

                        for (uint32_t i = 0; i < bind_info_count; ++i)
                        {
                            if (bind_infos[i].memoryBindIndex == mem_index)
                            {
                                src_offset = bind_infos[mem_index].memoryOffset;
                                break;
                            }
                        }

                        resource_alloc_info->original_offset = src_offset;
                        resource_alloc_info->rebind_offset   = allocation_info.offset;
                        resource_alloc_info->rebind_size     = allocation_info.size;

                        VkMemoryPropertyFlags property_flags =
                            replay_memory_properties_.memoryTypes[allocation_info.memoryType].propertyFlags;

                        if ((property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                        {
                            resource_alloc_info->is_host_visible = true;
                        }

                        if (memory_alloc_info->original_content != nullptr)
                        {
                            // Memory has been mapped and written prior to bind. Copy the original content to the new
                            // allocation to ensure it contains the correct data.

                            // If the session is bigger at replay time than at capture time, you don't want to read
                            // memory_alloc_info->original_content out of bounds
                            VkDeviceSize copy_size =
                                std::min(allocation_info.size, memory_alloc_info->allocation_size - src_offset);

                            WriteBoundResource(resource_alloc_info,
                                               src_offset,
                                               0,
                                               copy_size,
                                               memory_alloc_info->original_content.get());
                        }

                        memory_alloc_info->original_sessions.insert(std::make_pair(video_session, resource_alloc_info));

                        bind_memory_properties[mem_index] = property_flags;
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
                if (memory_alloc_info->original_buffers.empty() && memory_alloc_info->original_images.empty())
                {
                    memory_alloc_info->debug_utils_name = name_info->pObjectName;
                    return VK_SUCCESS;
                }
                else
                {
                    VmaAllocationInfo allocation_info;
                    if (!memory_alloc_info->original_buffers.empty())
                    {
                        auto it = memory_alloc_info->original_buffers.begin();
                        vmaGetAllocationInfo(allocator_, it->second->allocation, &allocation_info);
                    }
                    else
                    {
                        auto it = memory_alloc_info->original_images.begin();
                        vmaGetAllocationInfo(allocator_, it->second->allocation, &allocation_info);
                    }

                    name_info->objectHandle = VK_HANDLE_TO_UINT64(allocation_info.deviceMemory);
                }
                break;
            }
            case VK_OBJECT_TYPE_BUFFER:
            case VK_OBJECT_TYPE_IMAGE:
            {
                ResourceAllocInfo* resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
                if (resource_alloc_info->memory_info == nullptr)
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
                if (memory_alloc_info->original_buffers.empty() && memory_alloc_info->original_images.empty())
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
                    VmaAllocationInfo allocation_info;
                    if (!memory_alloc_info->original_buffers.empty())
                    {
                        auto it = memory_alloc_info->original_buffers.begin();
                        vmaGetAllocationInfo(allocator_, it->second->allocation, &allocation_info);
                    }
                    else
                    {
                        auto it = memory_alloc_info->original_images.begin();
                        vmaGetAllocationInfo(allocator_, it->second->allocation, &allocation_info);
                    }

                    tag_info->objectHandle = VK_HANDLE_TO_UINT64(allocation_info.deviceMemory);
                }
                break;
            }
            case VK_OBJECT_TYPE_BUFFER:
            case VK_OBJECT_TYPE_IMAGE:
            {
                ResourceAllocInfo* resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);
                if (resource_alloc_info->memory_info == nullptr)
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
            for (const auto& entry : memory_alloc_info->original_buffers)
            {
                UpdateBoundResource(entry.second, write_start, write_end, data);
            }

            for (const auto& entry : memory_alloc_info->original_images)
            {
                UpdateBoundResource(entry.second, write_start, write_end, data);
            }

            for (const auto& entry : memory_alloc_info->original_sessions)
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

void VulkanRebindAllocator::ReportBindVideoSessionIncompatibility(VkVideoSessionKHR video_session,
                                                                  uint32_t          bind_info_count,
                                                                  const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                                                  const ResourceData* allocator_resource_datas,
                                                                  const MemoryData*   allocator_memory_datas)
{
    GFXRECON_UNREFERENCED_PARAMETER(video_session);
    GFXRECON_UNREFERENCED_PARAMETER(bind_infos);
    GFXRECON_UNREFERENCED_PARAMETER(allocator_memory_datas);

    ReportBindIncompatibility(allocator_resource_datas, bind_info_count);
}

void VulkanRebindAllocator::WriteBoundResourceDirect(
    ResourceAllocInfo* resource_alloc_info, size_t src_offset, size_t dst_offset, size_t data_size, const uint8_t* data)
{
    if (resource_alloc_info->object_type == ObjectType::buffer)
    {
        util::platform::MemoryCopy(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer) + dst_offset,
                                   data_size,
                                   data + src_offset,
                                   data_size);
    }
    else if (resource_alloc_info->object_type == ObjectType::image)
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
                GFXRECON_LOG_ERROR("Skipping mapped memory write for image with multiple subresources: support "
                                   "not yet implemented");
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Image subresource layout info is not available for mapped memory write; "
                                 "capture/replay memory alignment differences will not be handled properly");

            util::platform::MemoryCopy(static_cast<uint8_t*>(resource_alloc_info->mapped_pointer) + dst_offset,
                                       data_size,
                                       data + src_offset,
                                       data_size);
        }
    }
    else if (resource_alloc_info->object_type == ObjectType::video_session)
    {
        // TODO: implement direct video session copy
        GFXRECON_LOG_WARNING("Skipping video session in direct write: support not yet implemented");
    }
}

void VulkanRebindAllocator::WriteBoundResourceStaging(
    ResourceAllocInfo* resource_alloc_info, size_t src_offset, size_t dst_offset, size_t data_size, const uint8_t* data)
{
    if (resource_alloc_info->object_type == ObjectType::image && dst_offset != 0)
    {
        // TODO: implement offset based stagging image copy
        GFXRECON_LOG_WARNING("Skipping image with offset in staging write: support not yet implemented");
        return;
    }

    if (resource_alloc_info->object_type == ObjectType::video_session)
    {
        // TODO: implement stagging video session copy
        GFXRECON_LOG_WARNING("Skipping video session in staging write: support not yet implemented");
        return;
    }

    VkBuffer           staging_buf{};
    VkBufferCreateInfo staging_buf_create_info{};
    staging_buf_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    staging_buf_create_info.size  = data_size;
    staging_buf_create_info.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;

    VmaAllocation           staging_alloc{};
    VmaAllocationInfo       staging_alloc_info{};
    VmaAllocationCreateInfo staging_alloc_create_info = {};
    staging_alloc_create_info.flags =
        VMA_ALLOCATION_CREATE_HOST_ACCESS_SEQUENTIAL_WRITE_BIT | VMA_ALLOCATION_CREATE_MAPPED_BIT;
    staging_alloc_create_info.usage = VMA_MEMORY_USAGE_CPU_ONLY;

    VkResult result = vmaCreateBuffer(allocator_,
                                      &staging_buf_create_info,
                                      &staging_alloc_create_info,
                                      &staging_buf,
                                      &staging_alloc,
                                      &staging_alloc_info);

    void* copy_mapped_pointer{ resource_alloc_info->mapped_pointer };

    if (result == VK_SUCCESS)
    {
        result = vmaMapMemory(allocator_, staging_alloc, &resource_alloc_info->mapped_pointer);
    }

    if (result == VK_SUCCESS)
    {
        WriteBoundResourceDirect(resource_alloc_info, src_offset, 0, data_size, data);
        resource_alloc_info->mapped_pointer = copy_mapped_pointer;
        vmaFlushAllocation(allocator_, staging_alloc, 0, VK_WHOLE_SIZE);
        vmaUnmapMemory(allocator_, staging_alloc);

        VkCommandBufferBeginInfo cmd_buf_begin_info = {};
        cmd_buf_begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

        result = functions_.begin_command_buffer(cmd_buffer_, &cmd_buf_begin_info);
    }

    if (result == VK_SUCCESS)
    {
        if (resource_alloc_info->object_type == ObjectType::image)
        {
            VkImage original_image{};

            for (const std::pair<const VkImage, VulkanRebindAllocator::ResourceAllocInfo*>& elt :
                 resource_alloc_info->memory_info->original_images)
            {
                if (elt.second == resource_alloc_info)
                {
                    original_image = elt.first;
                    break;
                }
            }

            if (original_image)
            {
                // TODO: handle mip maps/array layers
                GFXRECON_LOG_WARNING(
                    "Ignoring potential mip maps/array layers in staging buffer to image copy: support "
                    "not yet implemented");

                VkImageAspectFlags aspect{};
                switch (resource_alloc_info->format)
                {
                    case VK_FORMAT_D16_UNORM:
                    case VK_FORMAT_X8_D24_UNORM_PACK32:
                    case VK_FORMAT_D32_SFLOAT:
                        aspect = VK_IMAGE_ASPECT_DEPTH_BIT;
                        break;
                    case VK_FORMAT_S8_UINT:
                        aspect = VK_IMAGE_ASPECT_STENCIL_BIT;
                        break;
                    case VK_FORMAT_D16_UNORM_S8_UINT:
                    case VK_FORMAT_D24_UNORM_S8_UINT:
                    case VK_FORMAT_D32_SFLOAT_S8_UINT:
                        aspect = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
                        break;
                    default:
                        aspect = VK_IMAGE_ASPECT_COLOR_BIT;
                        break;
                }

                VkBufferImageCopy region{};
                region.bufferOffset      = 0;
                region.bufferRowLength   = 0;
                region.bufferImageHeight = 0;
                region.imageSubresource  = { aspect, 0, 0, 1 };
                region.imageOffset       = { 0, 0, 0 };
                region.imageExtent       = { 1, 1, 1 };

                functions_.cmd_copy_buffer_to_image(
                    cmd_buffer_, staging_buf, original_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
                result = functions_.end_command_buffer(cmd_buffer_);
            }
        }
        else if (resource_alloc_info->object_type == ObjectType::buffer)
        {
            VkBuffer original_buffer{};
            for (const std::pair<const VkBuffer, VulkanRebindAllocator::ResourceAllocInfo*>& elt :
                 resource_alloc_info->memory_info->original_buffers)
            {
                if (elt.second == resource_alloc_info)
                {
                    original_buffer = elt.first;
                    break;
                }
            }

            if (original_buffer)
            {
                VkBufferCopy copy_region{};
                copy_region.srcOffset = 0;
                copy_region.dstOffset = dst_offset;
                copy_region.size      = data_size;

                functions_.cmd_copy_buffer(cmd_buffer_, staging_buf, original_buffer, 1, &copy_region);
                result = functions_.end_command_buffer(cmd_buffer_);
            }
        }
    }

    if (result == VK_SUCCESS)
    {
        VkSubmitInfo compute_submit_info{};
        compute_submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        compute_submit_info.commandBufferCount = 1;
        compute_submit_info.pCommandBuffers    = &cmd_buffer_;

        result = functions_.queue_submit(staging_queue_, 1, &compute_submit_info, VK_NULL_HANDLE);
    }

    if (result == VK_SUCCESS)
    {
        result = functions_.queue_wait_idle(staging_queue_);
    }

    if (result == VK_SUCCESS)
    {
        result = functions_.reset_command_buffer(cmd_buffer_, VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT);
    }

    vmaDestroyBuffer(allocator_, staging_buf, staging_alloc);
}

void VulkanRebindAllocator::WriteBoundResource(ResourceAllocInfo* resource_alloc_info,
                                               VkDeviceSize       src_offset,
                                               VkDeviceSize       dst_offset,
                                               VkDeviceSize       data_size,
                                               const uint8_t*     data)
{
    assert(resource_alloc_info != nullptr);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, src_offset);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, dst_offset);
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);

    size_t copy_src_offset = static_cast<size_t>(src_offset);
    size_t copy_dst_offset = static_cast<size_t>(dst_offset);
    size_t copy_size       = static_cast<size_t>(data_size);

    if (resource_alloc_info->is_host_visible)
    {
        VkResult result = VK_SUCCESS;

        if (resource_alloc_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            result = vmaMapMemory(allocator_, resource_alloc_info->allocation, &resource_alloc_info->mapped_pointer);
        }

        if (result == VK_SUCCESS)
        {
            WriteBoundResourceDirect(resource_alloc_info, copy_src_offset, copy_dst_offset, copy_size, data);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to map device memory: vmaMapMemory returned %s",
                               util::ToString<VkResult>(result).c_str());
        }
    }
    else
    {
        WriteBoundResourceStaging(resource_alloc_info, copy_src_offset, copy_dst_offset, copy_size, data);
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

    // This should correspond to the offset to the end of the resource at capture time.
    //
    // However, if the rebind size is smaller than the original size, we don't want data_size to be big enough to cause
    // an overflow, so the original size is artifically clamped to the rebind size.
    VkDeviceSize resource_end =
        resource_start + (resource_alloc_info->original_size != 0
                              ? std::min(resource_alloc_info->original_size, resource_alloc_info->rebind_size)
                              : resource_alloc_info->rebind_size);

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
    VkDeviceSize       original_start,
    VkDeviceSize       original_end,
    VkResult (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize))
{
    VkResult     result     = VK_SUCCESS;
    VkDeviceSize src_offset = 0;
    VkDeviceSize dst_offset = 0;
    VkDeviceSize data_size  = 0;

    if (TranslateMemoryRange(resource_alloc_info, original_start, original_end, &src_offset, &dst_offset, &data_size))
    {
        if (resource_alloc_info->mapped_pointer == nullptr)
        {
            // After first map, the allocation will stay mapped until it is destroyed.
            result = vmaMapMemory(allocator_, resource_alloc_info->allocation, &resource_alloc_info->mapped_pointer);
        }

        if (result == VK_SUCCESS)
        {
            result = update_func(allocator_, resource_alloc_info->allocation, dst_offset, data_size);
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

                for (const auto& entry : memory_alloc_info->original_sessions)
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

VmaMemoryUsage VulkanRebindAllocator::GetVideoSeesionMemoryUsage(VkMemoryPropertyFlags       capture_properties,
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

VkResult VulkanRebindAllocator::MapResourceMemoryDirect(VkDeviceSize     size,
                                                        VkMemoryMapFlags flags,
                                                        void**           data,
                                                        ResourceData     allocator_data)
{
    VkResult result = VK_ERROR_MEMORY_MAP_FAILED;

    if ((data != nullptr) && (allocator_data != 0))
    {
        auto resource_alloc_info = reinterpret_cast<ResourceAllocInfo*>(allocator_data);

        if (resource_alloc_info->mapped_pointer == nullptr)
        {
            result = vmaMapMemory(allocator_, resource_alloc_info->allocation, &resource_alloc_info->mapped_pointer);
        }
        else
        {
            result = VK_SUCCESS;
        }

        if (result == VK_SUCCESS)
        {
            (*data) = reinterpret_cast<uint8_t*>(resource_alloc_info->mapped_pointer);
        }
    }

    return result;
}

void VulkanRebindAllocator::SetBindingDebugUtilsNameAndTag(const MemoryAllocInfo*   memory_alloc_info,
                                                           const ResourceAllocInfo* resource_alloc_info,
                                                           VkDeviceMemory           device_memory,
                                                           VkObjectType             resource_type,
                                                           uint64_t                 resource_handle)
{
    VkDebugUtilsObjectNameInfoEXT name_info;
    name_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
    name_info.pNext = nullptr;

    VkDebugUtilsObjectTagInfoEXT tag_info;
    tag_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
    tag_info.pNext = nullptr;

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
        name_info.objectType   = resource_type;
        name_info.objectHandle = resource_handle;
        name_info.pObjectName  = resource_alloc_info->debug_utils_name.c_str();

        functions_.set_debug_utils_object_name(device_, &name_info);
    }

    if (!resource_alloc_info->debug_utils_tag.empty())
    {
        tag_info.objectType   = resource_type;
        tag_info.objectHandle = resource_handle;
        tag_info.tagName      = resource_alloc_info->debug_utils_tag_name;
        tag_info.tagSize      = resource_alloc_info->debug_utils_tag.size();
        tag_info.pTag         = resource_alloc_info->debug_utils_tag.data();

        functions_.set_debug_utils_object_tag(device_, &tag_info);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
