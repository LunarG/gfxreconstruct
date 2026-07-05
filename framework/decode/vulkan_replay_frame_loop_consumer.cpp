/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/custom_vulkan_struct_handle_mappers.h"

#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"
#include "decode/vulkan_replay_frame_loop_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

#define CHECK_VK_RESULT(_res_, _func_)                                        \
    {                                                                         \
        VkResult _RES = (_res_);                                              \
        if (_RES != VK_SUCCESS)                                               \
        {                                                                     \
            GFXRECON_LOG_ERROR("[%s:%u] synthetic call to %s failed with %s", \
                               __FILE__,                                      \
                               __LINE__,                                      \
                               _func_,                                        \
                               util::ToString(_RES).c_str());                 \
            std::exit(-1);                                                    \
        }                                                                     \
    }

namespace
{
VkImageAspectFlags GetAspectMask(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            return VK_IMAGE_ASPECT_DEPTH_BIT;
        case VK_FORMAT_S8_UINT:
            return VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

VkAccessFlags GetAccessFlags(VkImageLayout layout)
{
    switch (layout)
    {
        case VK_IMAGE_LAYOUT_UNDEFINED:
            return 0;
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            return VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
            return VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            return VK_ACCESS_SHADER_READ_BIT;
        case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
            return VK_ACCESS_TRANSFER_READ_BIT;
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
            return VK_ACCESS_TRANSFER_WRITE_BIT;
        default:
            return VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    }
}

std::vector<ImageSubresourceLayoutTracker::SubresourceLayout> GetNormalizedSubresourceLayouts(
    const VulkanImageInfo* info)
{
    std::vector<ImageSubresourceLayoutTracker::SubresourceLayout> normalized;
    if (info == nullptr)
    {
        return normalized;
    }

    VkImageAspectFlags full_aspect = GetAspectMask(info->format);

    // Check for both depth and stencil aspects
    bool is_depth_stencil = (full_aspect & (VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT)) ==
                            (VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT);

    auto current_layouts = info->subresource_layouts.GetSubresourceLayouts();
    for (auto layout_entry : current_layouts)
    {
        if (is_depth_stencil)
        {
            layout_entry.range.aspectMask = full_aspect;
        }

        bool found = false;
        for (const auto& existing : normalized)
        {
            if (existing.range.aspectMask == layout_entry.range.aspectMask &&
                existing.range.baseMipLevel == layout_entry.range.baseMipLevel &&
                existing.range.levelCount == layout_entry.range.levelCount &&
                existing.range.baseArrayLayer == layout_entry.range.baseArrayLayer &&
                existing.range.layerCount == layout_entry.range.layerCount && existing.layout == layout_entry.layout)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            normalized.push_back(layout_entry);
        }
    }
    return normalized;
}
} // namespace

void VulkanReplayFrameLoopConsumer::DestroyShadowBuffers()
{
    for (const auto& [buf_id, shadow] : shadow_buffers_)
    {
        format::HandleId dev_id = shadow.parent_id;
        if (dev_id == format::kNullHandleId)
        {
            auto buf_info = GetObjectInfoTable().GetVkBufferInfo(buf_id);
            if (buf_info != nullptr)
            {
                dev_id = buf_info->parent_id;
            }
        }

        if (dev_id != format::kNullHandleId)
        {
            auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(dev_id);
            if (dev_info != nullptr && dev_info->allocator != nullptr)
            {
                if (shadow.shadow_buffer != VK_NULL_HANDLE)
                {
                    dev_info->allocator->DestroyBufferDirect(shadow.shadow_buffer, nullptr, shadow.alloc_data);
                }
                if (shadow.shadow_memory != VK_NULL_HANDLE)
                {
                    dev_info->allocator->FreeMemoryDirect(shadow.shadow_memory, nullptr, shadow.mem_data);
                }
            }
        }
    }
    shadow_buffers_.clear();
}

void VulkanReplayFrameLoopConsumer::DestroyShadowImages()
{
    for (const auto& [image_id, shadow] : shadow_images_)
    {
        format::HandleId dev_id = shadow.parent_id;
        if (dev_id == format::kNullHandleId)
        {
            auto img_info = GetObjectInfoTable().GetVkImageInfo(image_id);
            if (img_info != nullptr)
            {
                dev_id = img_info->parent_id;
            }
        }

        if (dev_id != format::kNullHandleId)
        {
            auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(dev_id);
            if (dev_info != nullptr && dev_info->allocator != nullptr)
            {
                if (shadow.shadow_image != VK_NULL_HANDLE)
                {
                    dev_info->allocator->DestroyImageDirect(shadow.shadow_image, nullptr, shadow.alloc_data);
                }
                if (shadow.shadow_memory != VK_NULL_HANDLE)
                {
                    dev_info->allocator->FreeMemoryDirect(shadow.shadow_memory, nullptr, shadow.mem_data);
                }
            }
        }
    }
    shadow_images_.clear();
}

VulkanReplayFrameLoopConsumer::~VulkanReplayFrameLoopConsumer()
{
    DestroyShadowBuffers();
    DestroyShadowImages();
    DestroyShadowPools();

    if (restoration_device_ != VK_NULL_HANDLE)
    {
        if (restoration_command_pool_ != VK_NULL_HANDLE)
        {
            const graphics::VulkanDeviceTable* dev_table = GetDeviceTable(restoration_device_);
            if (dev_table)
            {
                dev_table->DestroyCommandPool(restoration_device_, restoration_command_pool_, nullptr);
            }
        }
        restoration_command_pool_   = VK_NULL_HANDLE;
        restoration_command_buffer_ = VK_NULL_HANDLE;
        restoration_device_         = VK_NULL_HANDLE;
    }
}

void VulkanReplayFrameLoopConsumer::DestroyShadowPools()
{
    VulkanObjectInfoTable& table = GetObjectInfoTable();
    for (auto& [original_pool, shadow_pool] : shadow_pools_)
    {
        VulkanCommandPoolInfo* pool_info = nullptr;
        table.VisitVkCommandPoolInfo([original_pool, &pool_info](const VulkanCommandPoolInfo* info) {
            if (info->handle == original_pool)
            {
                pool_info = const_cast<VulkanCommandPoolInfo*>(info);
            }
        });
        if (pool_info != nullptr && pool_info->parent_id != format::kNullHandleId)
        {
            auto device_info = table.GetVkDeviceInfo(pool_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                auto device_table = GetDeviceTable(device_info->handle);
                if (device_table != nullptr)
                {
                    device_table->DestroyCommandPool(device_info->handle, shadow_pool, nullptr);
                }
            }
        }
    }
    shadow_pools_.clear();
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*                      pBuffer)
{
    if (pCreateInfo != nullptr && !pCreateInfo->IsNull() && pCreateInfo->GetPointer() != nullptr)
    {
        pCreateInfo->GetPointer()->usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    }
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(
        call_info, returnValue, device, pCreateInfo, pAllocator, pBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkCommandPool>*                   pCommandPool)
{
    if (IsLoopNotFirstIteration() && pCommandPool != nullptr && pCommandPool->GetPointer() != nullptr)
    {
        if (dangling_create_command_pools_.contains(*pCommandPool->GetPointer()))
        {
            return;
        }
    }

    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    if (pCreateInfo != nullptr && pCreateInfo->GetPointer() != nullptr)
    {
        VkCommandPoolCreateInfo* create_info = pCreateInfo->GetPointer();
        create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateCommandPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pCommandPool);

    if (returnValue == VK_SUCCESS && pCommandPool != nullptr && pCommandPool->GetPointer() != nullptr)
    {
        auto pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(*pCommandPool->GetPointer());
        if (pool_info != nullptr && pCreateInfo != nullptr && pCreateInfo->GetPointer() != nullptr)
        {
            pool_info->flags              = pCreateInfo->GetPointer()->flags;
            pool_info->queue_family_index = pCreateInfo->GetPointer()->queueFamilyIndex;
        }
    }

    if (IsLoopFirstIteration() && pCommandPool != nullptr && pCommandPool->GetPointer() != nullptr)
    {
        dangling_create_command_pools_.insert(*pCommandPool->GetPointer());
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsLoopNotFirstIteration())
    {
        if (dangling_destroy_command_pools_.contains(commandPool))
        {
            return;
        }
    }

    if (IsLoopFirstIteration())
    {
        if (!dangling_create_command_pools_.contains(commandPool))
        {
            dangling_destroy_command_pools_.insert(commandPool);
            return;
        }
        else
        {
            dangling_create_command_pools_.erase(commandPool);
        }
    }

    auto pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(commandPool);
    if (pool_info != nullptr && pool_info->handle != VK_NULL_HANDLE)
    {
        VkCommandPool vk_pool = pool_info->handle;
        for (auto& [dev, pools] : active_command_pools_)
        {
            pools.erase(vk_pool);
        }

        auto shadow_it = shadow_pools_.find(vk_pool);
        if (shadow_it != shadow_pools_.end())
        {
            VkCommandPool shadow_pool = shadow_it->second;
            auto          device_info = GetObjectInfoTable().GetVkDeviceInfo(device);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                auto device_table = GetDeviceTable(device_info->handle);
                if (device_table != nullptr)
                {
                    device_table->DestroyCommandPool(device_info->handle, shadow_pool, nullptr);
                    GFXRECON_LOG_INFO(
                        "Process_vkDestroyCommandPool: Destroyed shadow command pool %p for original pool %p",
                        shadow_pool,
                        vk_pool);
                }
            }
            shadow_pools_.erase(shadow_it);
        }
        pools_requiring_shadows_.erase(vk_pool);
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyCommandPool(call_info, device, commandPool, pAllocator);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*                   pDescriptorPool)
{
    format::HandleId pool_id = *pDescriptorPool->GetPointer();
    GFXRECON_ASSERT(pDescriptorPool != nullptr && pDescriptorPool->GetPointer() != nullptr);

    if (IsLoopNotFirstIteration())
    {
        // Skip allocation of descriptor pools with a dangling creation
        if (dangling_create_descriptor_pools_.contains(pool_id))
        {
            return;
        }
    }

    VulkanReplayConsumer::Process_vkCreateDescriptorPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pDescriptorPool);

    if (IsLoopFirstIteration())
    {
        // Gather descriptor pools that are created during the loop range
        // We will delete any pools from this set that are destroyed during the loop range
        dangling_create_descriptor_pools_.insert(pool_id);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsLoopNotFirstIteration())
    {
        // Skip destruction of descriptor pools with a dangling destruction
        if (dangling_destroy_descriptor_pools_.contains(descriptorPool))
        {
            return;
        }
    }

    if (IsLoopFirstIteration())
    {
        if (!dangling_create_descriptor_pools_.contains(descriptorPool))
        {
            // If this pool was not created during the loop range, ignore destroying it.
            dangling_destroy_descriptor_pools_.insert(descriptorPool);
            return;
        }
        else
        {
            // Created and destroyed during the loop range, not dangling
            dangling_create_descriptor_pools_.erase(descriptorPool);

            // Check if this was the pool for any heretofore dangling descriptors
            RemovePoolDanglingCreateDescriptors(descriptorPool);
        }
    }
    VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, device, descriptorPool, pAllocator);
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    bool should_destroy = !getFrameLoopInfo().IsLooping() || allocatedLoopResources.contains(buffer) ||
                          getFrameLoopInfo().IsFinalIteration();

    if (should_destroy)
    {
        auto it = shadow_buffers_.find(buffer);
        if (it != shadow_buffers_.end())
        {
            format::HandleId dev_id = it->second.parent_id;
            if (dev_id == format::kNullHandleId)
            {
                auto buf_info = GetObjectInfoTable().GetVkBufferInfo(buffer);
                if (buf_info != nullptr)
                {
                    dev_id = buf_info->parent_id;
                }
            }
            if (dev_id != format::kNullHandleId)
            {
                auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(dev_id);
                if (dev_info != nullptr && dev_info->allocator != nullptr)
                {
                    if (it->second.shadow_buffer != VK_NULL_HANDLE)
                    {
                        dev_info->allocator->DestroyBufferDirect(
                            it->second.shadow_buffer, nullptr, it->second.alloc_data);
                    }
                    if (it->second.shadow_memory != VK_NULL_HANDLE)
                    {
                        dev_info->allocator->FreeMemoryDirect(it->second.shadow_memory, nullptr, it->second.mem_data);
                    }
                }
            }
            shadow_buffers_.erase(it);
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyBuffer(call_info, device, buffer, pAllocator);
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    bool should_destroy = !getFrameLoopInfo().IsLooping() || allocatedLoopResources.contains(image) ||
                          getFrameLoopInfo().IsFinalIteration();

    if (should_destroy)
    {
        auto it = shadow_images_.find(image);
        if (it != shadow_images_.end())
        {
            format::HandleId dev_id = it->second.parent_id;
            if (dev_id == format::kNullHandleId)
            {
                auto img_info = GetObjectInfoTable().GetVkImageInfo(image);
                if (img_info != nullptr)
                {
                    dev_id = img_info->parent_id;
                }
            }
            if (dev_id != format::kNullHandleId)
            {
                auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(dev_id);
                if (dev_info != nullptr && dev_info->allocator != nullptr)
                {
                    if (it->second.shadow_image != VK_NULL_HANDLE)
                    {
                        dev_info->allocator->DestroyImageDirect(
                            it->second.shadow_image, nullptr, it->second.alloc_data);
                    }
                    if (it->second.shadow_memory != VK_NULL_HANDLE)
                    {
                        dev_info->allocator->FreeMemoryDirect(it->second.shadow_memory, nullptr, it->second.mem_data);
                    }
                }
            }
            shadow_images_.erase(it);
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyImage(call_info, device, image, pAllocator);
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (!IsLoopAnyIteration())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(event));
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
    }
    else if (IsLoopLastIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
        allocatedLoopResources.erase(event);
    }
}

void VulkanReplayFrameLoopConsumer::RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool)
{
    std::vector<format::HandleId> handles_to_delete;
    handles_to_delete.reserve(dangling_create_descriptor_sets_.size());
    for (format::HandleId handle : dangling_create_descriptor_sets_)
    {
        VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(handle);
        if (info != nullptr && info->pool_id == descriptorPool)
        {
            handles_to_delete.push_back(handle);
        }
    }
    for (format::HandleId handle : handles_to_delete)
    {
        dangling_create_descriptor_sets_.erase(handle);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                                                  VkResult                   returnValue,
                                                                  format::HandleId           device,
                                                                  format::HandleId           descriptorPool,
                                                                  VkDescriptorPoolResetFlags flags)
{
    if (IsLoopAnyIteration())
    {
        // If any of the sets in this pool are dangling, skip pool reset
        for (format::HandleId set_id : dangling_create_descriptor_sets_)
        {
            VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(set_id);
            if (info != nullptr && info->pool_id == descriptorPool)
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkResetDescriptorPool(call_info, returnValue, device, descriptorPool, flags);
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    if (IsLoopNotFirstIteration())
    {
        // Skip allocation of dangling descriptor sets
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            if (dangling_create_descriptor_sets_.contains(set_handle))
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
        call_info, returnValue, device, pAllocateInfo, pDescriptorSets);

    if (IsLoopFirstIteration())
    {
        // During first iteration of looping range, record which descriptor sets are allocated
        // They will be removed from the set if they are freed during the loop range
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            dangling_create_descriptor_sets_.insert(set_handle);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeDescriptorSets(const ApiCallInfo& call_info,
                                                                 VkResult           returnValue,
                                                                 format::HandleId   device,
                                                                 format::HandleId   descriptorPool,
                                                                 uint32_t           descriptorSetCount,
                                                                 HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets)
{
    if (IsLoopNotFirstIteration())
    {
        // If any of the descriptor sets are in the dangling list,
        // then we want to omit their destruction
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            if (dangling_destroy_descriptor_sets_.contains(set_handle))
            {
                return;
            }
        }
    }

    if (IsLoopFirstIteration())
    {
        bool skip_call = false;
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            if (dangling_create_descriptor_sets_.contains(set_handle))
            {
                // Any descriptor set that was freed during the loop range is not dangling
                dangling_create_descriptor_sets_.erase(set_handle);
            }
            else
            {
                // Descriptor set freed during loop range but created before
                dangling_destroy_descriptor_sets_.insert(set_handle);
                skip_call = true;
            }
        }
        if (skip_call)
        {
            return;
        }
    }

    // For pools that contain dangling descriptor sets, this code will only be reached once,
    // during the final iteration of the loop range.
    RemovePoolDanglingCreateDescriptors(descriptorPool);

    VulkanReplayConsumer::Process_vkFreeDescriptorSets(
        call_info, returnValue, device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

void VulkanReplayFrameLoopConsumer::OnLoopStart()
{
    WaitDevicesIdle();
    CaptureInitialFenceStates();
    CaptureInitialEventStates();
    RecordInitialLayouts();

    if (active_queue_info_ == nullptr)
    {
        GetObjectInfoTable().VisitVkQueueInfo([this](const VulkanQueueInfo* q_info) {
            if (q_info != nullptr && q_info->handle != VK_NULL_HANDLE && active_queue_info_ == nullptr)
            {
                active_queue_info_   = const_cast<VulkanQueueInfo*>(q_info);
                active_device_       = q_info->parent;
                active_device_table_ = GetDeviceTable(active_device_);
            }
        });
    }

    std::unordered_set<VkDevice> visited_devices;
    GetObjectInfoTable().VisitVkQueueInfo([this, &visited_devices](const VulkanQueueInfo* q_info) {
        if (q_info != nullptr && q_info->handle != VK_NULL_HANDLE && q_info->parent != VK_NULL_HANDLE)
        {
            if (visited_devices.insert(q_info->parent).second)
            {
                const graphics::VulkanDeviceTable* dev_table = GetDeviceTable(q_info->parent);
                if (dev_table != nullptr)
                {
                    RecordInitialBufferStates(q_info->parent, dev_table, const_cast<VulkanQueueInfo*>(q_info));
                }
            }
        }
    });

    // Wiping command buffers at loop repeats that span the boundary would destroy their state
    // (pipeline binds, render passes, dynamic rendering, etc.) and trigger validation errors or crashes.
    initial_loop_recording_cbs_ = recording_cbs_;
    loop_start_recording_cbs_   = recording_cbs_;

    GFXRECON_LOG_INFO("OnLoopStart: Captured %zu recording command buffers at loop start.",
                      loop_start_recording_cbs_.size());

    // Track pools of loop start recording command buffers as active to ensure they are recreated/reset
    for (auto cb_id : loop_start_recording_cbs_)
    {
        auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
        if (cb_info != nullptr)
        {
            format::HandleId pool_id   = cb_info->pool_id;
            auto             pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(pool_id);
            if (pool_info != nullptr && pool_info->handle != VK_NULL_HANDLE)
            {
                auto device_info = GetObjectInfoTable().GetVkDeviceInfo(cb_info->parent_id);
                if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
                {
                    active_command_pools_[device_info->handle].insert(pool_info->handle);
                    pools_requiring_shadows_.insert(pool_info->handle);
                    GFXRECON_LOG_INFO("OnLoopStart: Tracked pool %" PRIu64
                                      " (handle %p) as active for loop-start recording CB %" PRIu64,
                                      pool_id,
                                      pool_info->handle,
                                      cb_id);
                }
            }
        }
    }
    setup_complete_ = true;
}

void VulkanReplayFrameLoopConsumer::OnFrameBegin()
{
    if (IsLoopNotFirstIteration())
    {
        ResetLoopBoundary();
    }
}

void VulkanReplayFrameLoopConsumer::CaptureInitialFenceStates()
{
    initial_fence_states_.clear();

    VulkanObjectInfoTable& table = GetObjectInfoTable();
    table.VisitVkFenceInfo([this, &table](const VulkanFenceInfo* fence_info) {
        if (fence_info->handle != VK_NULL_HANDLE)
        {
            auto device_info = table.GetVkDeviceInfo(fence_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                VkDevice                           device       = device_info->handle;
                const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
                if (device_table != nullptr)
                {
                    VkResult status = device_table->GetFenceStatus(device, fence_info->handle);
                    initial_fence_states_[fence_info->capture_id] = status;
                }
            }
        }
    });
}

void VulkanReplayFrameLoopConsumer::CaptureInitialEventStates()
{
    initial_event_states_.clear();

    VulkanObjectInfoTable& table = GetObjectInfoTable();
    table.VisitVkEventInfo([this, &table](const VulkanEventInfo* event_info) {
        if (event_info->handle != VK_NULL_HANDLE)
        {
            // Do not attempt to query host status of device-only events
            if (device_only_events_.find(event_info->capture_id) != device_only_events_.end())
            {
                return;
            }

            auto device_info = table.GetVkDeviceInfo(event_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                VkDevice                           device       = device_info->handle;
                const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
                if (device_table != nullptr)
                {
                    VkResult status = device_table->GetEventStatus(device, event_info->handle);
                    initial_event_states_[event_info->capture_id] = (status == VK_EVENT_SET);
                }
            }
        }
    });
}

void VulkanReplayFrameLoopConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessStateEndMarker(frame_number);

    if (IsBeforeLoop())
    {
        OnLoopStart();
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceFences(format::HandleId device, format::HandleId queue)
{
    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    VkDevice                           vk_device    = table.GetVkDeviceInfo(device)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(vk_device);

    std::vector<VkFence> fences_to_reset;  // Fences to reset (signaled -> unsignaled)
    std::vector<VkFence> fences_to_signal; // Fences to signal (unsignaled -> signaled)

    for (auto [fence_id, initial_status] : initial_fence_states_)
    {
        const VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
        if (fence_info == nullptr || fence_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        // Only process fences for this device
        if (fence_info->parent_id != device)
        {
            continue;
        }

        VkResult current_status = device_table->GetFenceStatus(vk_device, fence_info->handle);

        if (initial_status == VK_NOT_READY && current_status == VK_SUCCESS)
        {
            GFXRECON_LOG_DEBUG("Fence %" PRIu64 " (handle %" PRIu64
                               ") was initially UNSIGNALED but is now SIGNALED. Will reset it.",
                               fence_id,
                               (uint64_t)fence_info->handle);
            fences_to_reset.push_back(fence_info->handle);
        }
        else if (initial_status == VK_SUCCESS && current_status == VK_NOT_READY)
        {
            GFXRECON_LOG_DEBUG("Fence %" PRIu64 " (handle %" PRIu64
                               ") was initially SIGNALED but is now UNSIGNALED. Will signal it.",
                               fence_id,
                               (uint64_t)fence_info->handle);
            fences_to_signal.push_back(fence_info->handle);
        }
    }

    if (fences_to_reset.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically resetting %zu fences...", fences_to_reset.size());
        VkResult result = device_table->ResetFences(vk_device, fences_to_reset.size(), fences_to_reset.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    if (fences_to_signal.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically signaling %zu fences...", fences_to_signal.size());
        VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
        for (VkFence fence : fences_to_signal)
        {
            VkResult result = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
            CHECK_VK_RESULT(result, "vkQueueSubmit");
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkMapMemory(const ApiCallInfo&               call_info,
                                                        VkResult                         returnValue,
                                                        format::HandleId                 device,
                                                        format::HandleId                 memory,
                                                        VkDeviceSize                     offset,
                                                        VkDeviceSize                     size,
                                                        VkMemoryMapFlags                 flags,
                                                        PointerDecoder<uint64_t, void*>* ppData)
{
    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in mapped_loop_memory
    if (IsLoopAnyIteration())
    {
        if (mapped_loop_memory.contains(memory))
        {
            return; // Already mapped in loop range, skip re-mapping
        }

        // First time mapping in the loop
        mapped_loop_memory.insert(memory);
    }
    VulkanReplayConsumer::Process_vkMapMemory(call_info, returnValue, device, memory, offset, size, flags, ppData);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                                          VkResult                                    returnValue,
                                                          format::HandleId                            queue,
                                                          uint32_t                                    submitCount,
                                                          StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                          format::HandleId                            fence)
{
    TrackSubmittedCommandBuffers(pSubmits);
    TrackAndAdjustSubmitSemaphores(queue, pSubmits);
    BackupImagesForSubmit(queue, pSubmits);

    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                                           VkResult                                     returnValue,
                                                           format::HandleId                             queue,
                                                           uint32_t                                     submitCount,
                                                           StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                           format::HandleId                             fence)
{
    TrackSubmittedCommandBuffers(pSubmits);
    TrackAndAdjustSubmitSemaphores(queue, pSubmits);
    BackupImagesForSubmit(queue, pSubmits);

    VulkanReplayConsumer::Process_vkQueueSubmit2(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                                              VkResult                                     returnValue,
                                                              format::HandleId                             queue,
                                                              uint32_t                                     submitCount,
                                                              StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                              format::HandleId                             fence)
{
    TrackSubmittedCommandBuffers(pSubmits);
    TrackAndAdjustSubmitSemaphores(queue, pSubmits);
    BackupImagesForSubmit(queue, pSubmits);

    VulkanReplayConsumer::Process_vkQueueSubmit2KHR(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);
}

template <typename T>
void VulkanReplayFrameLoopConsumer::TrackSubmittedCommandBuffers(StructPointerDecoder<T>* pSubmits)
{
    if (IsLoopFirstIteration())
    {
        if (pSubmits != nullptr && pSubmits->GetMetaStructPointer() != nullptr)
        {
            uint32_t submit_count = pSubmits->GetLength();
            auto     submits      = pSubmits->GetMetaStructPointer();
            for (uint32_t i = 0; i < submit_count; ++i)
            {
                ExtractAndTrackCommandBuffers(submits[i]);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::CollectTouchedImagesFromCommandBuffer(format::HandleId cb_id)
{
    auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
    if (cb_info == nullptr)
    {
        return;
    }

    auto add_image = [this](format::HandleId image_id) {
        if (image_id != format::kNullHandleId)
        {
            loop_touched_images_.insert(image_id);
            if (IsLoopFirstIteration() && initial_image_layouts_.find(image_id) == initial_image_layouts_.end())
            {
                auto img_info = GetObjectInfoTable().GetVkImageInfo(image_id);
                if (img_info != nullptr)
                {
                    initial_image_layouts_[image_id] = img_info->subresource_layouts;
                    GFXRECON_LOG_INFO("CollectTouched: Initial snapshot for image %" PRIu64, image_id);
                }
            }
        }
    };

    for (auto fb_id : cb_info->frame_buffer_ids)
    {
        auto fb_info = GetObjectInfoTable().GetVkFramebufferInfo(fb_id);
        if (fb_info != nullptr)
        {
            for (auto iv_id : fb_info->attachment_image_view_ids)
            {
                auto iv_info = GetObjectInfoTable().GetVkImageViewInfo(iv_id);
                if (iv_info != nullptr)
                {
                    add_image(iv_info->image_id);
                }
            }
        }
    }

    for (const auto& pair : cb_info->image_layout_barriers)
    {
        add_image(pair.first);
    }

    for (auto iv_id : cb_info->active_render_pass_attachment_image_view_ids)
    {
        auto iv_info = GetObjectInfoTable().GetVkImageViewInfo(iv_id);
        if (iv_info != nullptr)
        {
            add_image(iv_info->image_id);
        }
    }

    for (auto sec_id : cb_info->executed_secondary_command_buffers)
    {
        CollectTouchedImagesFromCommandBuffer(sec_id);
    }
}

void VulkanReplayFrameLoopConsumer::ExtractAndTrackCommandBuffers(const Decoded_VkSubmitInfo& submit)
{
    uint32_t cb_count = submit.pCommandBuffers.GetLength();
    auto     cbs      = submit.pCommandBuffers.GetPointer();
    if (cbs != nullptr)
    {
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            format::HandleId cb_id = cbs[j];
            loop_submitted_cbs_.insert(cb_id);
            CollectTouchedImagesFromCommandBuffer(cb_id);
            GFXRECON_LOG_DEBUG("TrackSubmittedCommandBuffers (Submit1): Tracked loop-submitted CB %" PRIu64, cb_id);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ExtractAndTrackCommandBuffers(const Decoded_VkSubmitInfo2& submit)
{
    if (submit.pCommandBufferInfos != nullptr && submit.pCommandBufferInfos->GetMetaStructPointer() != nullptr)
    {
        uint32_t cb_count = submit.pCommandBufferInfos->GetLength();
        auto     cb_infos = submit.pCommandBufferInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            format::HandleId cb_id = cb_infos[j].commandBuffer;
            loop_submitted_cbs_.insert(cb_id);
            CollectTouchedImagesFromCommandBuffer(cb_id);
            GFXRECON_LOG_DEBUG("TrackSubmittedCommandBuffers (Submit2): Tracked loop-submitted CB %" PRIu64, cb_id);
        }
    }
}

// Explicit template instantiations to keep implementation in source file
template void VulkanReplayFrameLoopConsumer::TrackSubmittedCommandBuffers<Decoded_VkSubmitInfo>(
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits);
template void VulkanReplayFrameLoopConsumer::TrackSubmittedCommandBuffers<Decoded_VkSubmitInfo2>(
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits);

template <typename T>
void VulkanReplayFrameLoopConsumer::BackupImagesForSubmit(format::HandleId queue, StructPointerDecoder<T>* pSubmits)
{
    if (!IsLoopFirstIteration() || pSubmits == nullptr || pSubmits->GetMetaStructPointer() == nullptr)
    {
        return;
    }

    UpdateActiveQueueInfo(queue);
    std::vector<format::HandleId> cb_ids;
    uint32_t                      submit_count = pSubmits->GetLength();
    auto                          submits      = pSubmits->GetMetaStructPointer();
    for (uint32_t i = 0; i < submit_count; ++i)
    {
        ExtractCommandBuffersForBackup(submits[i], cb_ids);
    }
    auto queue_info = GetObjectInfoTable().GetVkQueueInfo(queue);
    if (queue_info != nullptr && queue_info->handle != VK_NULL_HANDLE)
    {
        LazyBackupImagesForSubmit(queue_info->handle, static_cast<uint32_t>(cb_ids.size()), cb_ids.data());
    }
}

void VulkanReplayFrameLoopConsumer::ExtractCommandBuffersForBackup(const Decoded_VkSubmitInfo&    submit,
                                                                   std::vector<format::HandleId>& cb_ids)
{
    uint32_t cb_count = submit.pCommandBuffers.GetLength();
    auto     cbs      = submit.pCommandBuffers.GetPointer();
    if (cbs != nullptr)
    {
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            cb_ids.push_back(cbs[j]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ExtractCommandBuffersForBackup(const Decoded_VkSubmitInfo2&   submit,
                                                                   std::vector<format::HandleId>& cb_ids)
{
    if (submit.pCommandBufferInfos != nullptr && submit.pCommandBufferInfos->GetMetaStructPointer() != nullptr)
    {
        uint32_t cb_count = submit.pCommandBufferInfos->GetLength();
        auto     cb_infos = submit.pCommandBufferInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            cb_ids.push_back(cb_infos[j].commandBuffer);
        }
    }
}

template void VulkanReplayFrameLoopConsumer::BackupImagesForSubmit<Decoded_VkSubmitInfo>(
    format::HandleId queue, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits);
template void VulkanReplayFrameLoopConsumer::BackupImagesForSubmit<Decoded_VkSubmitInfo2>(
    format::HandleId queue, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits);

void VulkanReplayFrameLoopConsumer::UpdateActiveQueueInfo(format::HandleId queue)
{
    CommonObjectInfoTable& table = GetObjectInfoTable();
    active_queue_info_           = table.GetVkQueueInfo(queue);
    if (active_queue_info_ != nullptr)
    {
        active_device_       = active_queue_info_->parent;
        active_device_table_ = GetDeviceTable(active_device_);
        active_queue_id_     = queue;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                              call_info,
    VkResult                                        returnValue,
    format::HandleId                                queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, returnValue, queue, pPresentInfo);

    if (IsLoopFirstIteration() && pPresentInfo != nullptr && pPresentInfo->GetMetaStructPointer() != nullptr)
    {
        auto present_info = pPresentInfo->GetMetaStructPointer();
        if (present_info->pWaitSemaphores.GetPointer() != nullptr)
        {
            uint32_t count = present_info->pWaitSemaphores.GetLength();
            auto     sems  = present_info->pWaitSemaphores.GetPointer();
            for (uint32_t i = 0; i < count; ++i)
            {
                loop_pending_signaled_semaphores_.erase(sems[i]);
            }
        }
    }

    UpdateActiveQueueInfo(queue);
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    if (IsLoopNotFirstIteration() && pCommandBuffers != nullptr && pCommandBuffers->GetPointer() != nullptr &&
        pAllocateInfo != nullptr && pAllocateInfo->GetPointer() != nullptr)
    {
        bool skip = true;
        for (size_t i = 0; i < pAllocateInfo->GetPointer()->commandBufferCount; ++i)
        {
            if (!dangling_allocate_command_buffers_.contains(pCommandBuffers->GetPointer()[i]))
            {
                skip = false;
                break;
            }
        }
        if (skip)
        {
            return;
        }
    }

    VkCommandPool original_pool_handle = VK_NULL_HANDLE;
    bool          redirected           = false;

    if (setup_complete_ && pAllocateInfo != nullptr && pAllocateInfo->GetPointer() != nullptr)
    {
        VkCommandPool pool_handle = pAllocateInfo->GetPointer()->commandPool;
        if (pools_requiring_shadows_.contains(pool_handle))
        {
            VkCommandPool shadow_pool = VK_NULL_HANDLE;
            auto          shadow_it   = shadow_pools_.find(pool_handle);
            if (shadow_it == shadow_pools_.end())
            {
                // Find pool ID to retrieve creation info
                format::HandleId pool_id = format::kNullHandleId;
                GetObjectInfoTable().VisitVkCommandPoolInfo([pool_handle, &pool_id](const VulkanCommandPoolInfo* info) {
                    if (info->handle == pool_handle)
                    {
                        pool_id = info->capture_id;
                    }
                });
                auto pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(pool_id);
                if (pool_info != nullptr && pool_info->parent_id != format::kNullHandleId)
                {
                    auto device_info = GetObjectInfoTable().GetVkDeviceInfo(pool_info->parent_id);
                    if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
                    {
                        VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
                        create_info.flags = pool_info->flags | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
                        create_info.queueFamilyIndex = pool_info->queue_family_index;

                        auto dev_table = GetDeviceTable(device_info->handle);
                        if (dev_table != nullptr)
                        {
                            VkResult res =
                                dev_table->CreateCommandPool(device_info->handle, &create_info, nullptr, &shadow_pool);
                            if (res == VK_SUCCESS)
                            {
                                shadow_pools_[pool_handle] = shadow_pool;
                                GFXRECON_LOG_INFO("Process_vkAllocateCommandBuffers: Lazily created shadow command "
                                                  "pool %p for original pool %p on device %p",
                                                  shadow_pool,
                                                  pool_handle,
                                                  device_info->handle);
                            }
                            else
                            {
                                GFXRECON_LOG_ERROR("Process_vkAllocateCommandBuffers: Failed to lazily create shadow "
                                                   "command pool for pool %p, error %d",
                                                   pool_handle,
                                                   res);
                            }
                        }
                    }
                }
            }
            else
            {
                shadow_pool = shadow_it->second;
            }

            if (shadow_pool != VK_NULL_HANDLE)
            {
                original_pool_handle                     = pool_handle;
                pAllocateInfo->GetPointer()->commandPool = shadow_pool;
                redirected                               = true;
            }
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkAllocateCommandBuffers(
        call_info, returnValue, device, pAllocateInfo, pCommandBuffers);

    if (redirected && pAllocateInfo != nullptr && pAllocateInfo->GetPointer() != nullptr)
    {
        pAllocateInfo->GetPointer()->commandPool = original_pool_handle;
    }

    if (returnValue == VK_SUCCESS && pAllocateInfo->GetPointer() != nullptr && pCommandBuffers->GetPointer() != nullptr)
    {
        VkCommandBufferLevel level = pAllocateInfo->GetPointer()->level;
        for (size_t i = 0; i < pAllocateInfo->GetPointer()->commandBufferCount; ++i)
        {
            format::HandleId cb_id   = pCommandBuffers->GetPointer()[i];
            auto             cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
            if (cb_info != nullptr)
            {
                cb_info->level = level;
            }
            if (IsLoopFirstIteration())
            {
                dangling_allocate_command_buffers_.insert(cb_id);
            }
            if (redirected && pCommandBuffers->GetHandlePointer() != nullptr)
            {
                redirected_cbs_.insert(pCommandBuffers->GetHandlePointer()[i]);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeCommandBuffers(const ApiCallInfo& call_info,
                                                                 format::HandleId   device,
                                                                 format::HandleId   commandPool,
                                                                 uint32_t           commandBufferCount,
                                                                 HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    if (pCommandBuffers == nullptr || pCommandBuffers->GetPointer() == nullptr)
    {
        return;
    }

    if (IsLoopNotFirstIteration())
    {
        return;
    }

    if (IsLoopFirstIteration())
    {
        bool                    all_allocated_in_loop = true;
        const format::HandleId* cbs                   = pCommandBuffers->GetPointer();
        for (uint32_t i = 0; i < commandBufferCount; ++i)
        {
            if (!dangling_allocate_command_buffers_.contains(cbs[i]))
            {
                all_allocated_in_loop = false;
                break;
            }
        }
        if (!all_allocated_in_loop)
        {
            for (uint32_t i = 0; i < commandBufferCount; ++i)
            {
                dangling_free_command_buffers_.insert(cbs[i]);
            }
            return;
        }
        for (uint32_t i = 0; i < commandBufferCount; ++i)
        {
            dangling_allocate_command_buffers_.erase(cbs[i]);
        }
    }

    VkCommandPool          original_pool_handle = VK_NULL_HANDLE;
    VulkanCommandPoolInfo* pool_info            = GetObjectInfoTable().GetVkCommandPoolInfo(commandPool);
    bool                   redirected           = false;

    if (pool_info != nullptr && pCommandBuffers->GetHandlePointer() != nullptr && commandBufferCount > 0)
    {
        VkCommandBuffer first_cb = pCommandBuffers->GetHandlePointer()[0];
        if (redirected_cbs_.contains(first_cb))
        {
            auto shadow_it = shadow_pools_.find(pool_info->handle);
            if (shadow_it != shadow_pools_.end())
            {
                original_pool_handle = pool_info->handle;
                pool_info->handle    = shadow_it->second;
                redirected           = true;
            }
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkFreeCommandBuffers(
        call_info, device, commandPool, commandBufferCount, pCommandBuffers);

    if (redirected)
    {
        pool_info->handle = original_pool_handle;
        if (pCommandBuffers->GetHandlePointer() != nullptr)
        {
            for (uint32_t i = 0; i < commandBufferCount; ++i)
            {
                redirected_cbs_.erase(pCommandBuffers->GetHandlePointer()[i]);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    if (pBeginInfo != nullptr && pBeginInfo->GetPointer() != nullptr)
    {
        auto* begin_info = const_cast<VkCommandBufferBeginInfo*>(pBeginInfo->GetPointer());
        begin_info->flags &= ~VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    }

    VulkanReplayConsumer::Process_vkBeginCommandBuffer(call_info, returnValue, commandBuffer, pBeginInfo);

    recording_cbs_.insert(commandBuffer);

    auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);
    if (cb_info != nullptr)
    {
        cb_info->image_layout_barriers.clear();
        auto device_info = GetObjectInfoTable().GetVkDeviceInfo(cb_info->parent_id);
        if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
        {
            SavedCommandBufferBeginInfo begin_info_saved;
            begin_info_saved.device = device_info->handle;
            if (pBeginInfo->GetPointer() != nullptr)
            {
                begin_info_saved.flags = pBeginInfo->GetPointer()->flags;
                if (pBeginInfo->GetPointer()->pInheritanceInfo != nullptr)
                {
                    begin_info_saved.has_inheritance_info = true;
                    begin_info_saved.inheritance_info     = *pBeginInfo->GetPointer()->pInheritanceInfo;
                }
            }
            cb_begin_infos_[commandBuffer] = begin_info_saved;
        }

        if (IsLoopAnyIteration())
        {
            // Track recorded command buffers during the first play of the loop
            if (IsLoopFirstIteration())
            {
                loop_recorded_cbs_.insert(commandBuffer);
            }

            format::HandleId pool_id   = cb_info->pool_id;
            auto             pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(pool_id);
            if (pool_info != nullptr && pool_info->handle != VK_NULL_HANDLE)
            {
                auto device_info = GetObjectInfoTable().GetVkDeviceInfo(cb_info->parent_id);
                if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
                {
                    active_command_pools_[device_info->handle].insert(pool_info->handle);
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                                               VkResult           returnValue,
                                                               format::HandleId   commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }

    VulkanReplayConsumer::Process_vkEndCommandBuffer(call_info, returnValue, commandBuffer);

    recording_cbs_.erase(commandBuffer);

    if (IsLoopFirstIteration())
    {
        loop_ended_cbs_.insert(commandBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkUnmapMemory(const ApiCallInfo& call_info,
                                                          format::HandleId   device,
                                                          format::HandleId   memory)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if memory is in mapped_loop_memory

    // Call Process_vkUnmapMemory if:
    //    We are not looping
    //    We are looping and memory is in mapped_loop_memory, i.e. it is mapped/unmapped inside loop
    //    We are looping and this is the last iteration
    if (!IsLoopAnyIteration())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(memory));
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
    }
    else if (mapped_loop_memory.contains(memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
        mapped_loop_memory.erase(memory);
    }
    else if (IsLoopLastIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is false (not acquired), call replay consumer
    if (!IsLoopAnyIteration() || !profilingLockState.contains(device) || !profilingLockState[device])
    {
        VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(call_info, returnValue, device, pInfo);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[device] = true;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info,
                                                                      format::HandleId   device)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is true (acquired), call replay consumer
    if (!IsLoopAnyIteration() || !profilingLockState.contains(device) || profilingLockState[device])
    {
        VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(call_info, device);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[device] = false;
    }
}

void VulkanReplayFrameLoopConsumer::RecordInitialLayouts()
{
    initial_image_layouts_.clear();
    loop_touched_images_.clear();
    GetObjectInfoTable().VisitVkImageInfo([this](const VulkanImageInfo* info) {
        if (info != nullptr && info->handle != VK_NULL_HANDLE)
        {
            initial_image_layouts_[info->capture_id] = info->subresource_layouts;
        }
    });
}
bool VulkanReplayFrameLoopConsumer::InitializeRestorationResources(VkDevice device, uint32_t queue_family_index)
{
    if (restoration_command_pool_ != VK_NULL_HANDLE)
    {
        if (restoration_device_ == device)
        {
            return true;
        }
        else
        {
            // Destroy old resources first, then recreate
            const graphics::VulkanDeviceTable* old_dev_table = GetDeviceTable(restoration_device_);
            if (old_dev_table)
            {
                old_dev_table->DestroyCommandPool(restoration_device_, restoration_command_pool_, nullptr);
            }
            restoration_command_pool_   = VK_NULL_HANDLE;
            restoration_command_buffer_ = VK_NULL_HANDLE;
            restoration_device_         = VK_NULL_HANDLE;
        }
    }

    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table);

    VkCommandPoolCreateInfo pool_create_info = {};
    pool_create_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    VkResult result = device_table->CreateCommandPool(device, &pool_create_info, nullptr, &restoration_command_pool_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create restoration command pool, result=%d", result);
        restoration_command_pool_ = VK_NULL_HANDLE;
        return false;
    }

    restoration_device_ = device;

    VkCommandBufferAllocateInfo alloc_info = {};
    alloc_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    alloc_info.commandPool                 = restoration_command_pool_;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    result = device_table->AllocateCommandBuffers(device, &alloc_info, &restoration_command_buffer_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to allocate restoration command buffer, result=%d", result);
        device_table->DestroyCommandPool(device, restoration_command_pool_, nullptr);
        restoration_command_pool_   = VK_NULL_HANDLE;
        restoration_command_buffer_ = VK_NULL_HANDLE;
        restoration_device_         = VK_NULL_HANDLE;
        return false;
    }

    return true;
}

void VulkanReplayFrameLoopConsumer::ResetLoopBoundary()
{
    if (active_device_ != VK_NULL_HANDLE && active_queue_info_ != nullptr)
    {
        GFXRECON_ASSERT(active_device_);
        GFXRECON_ASSERT(active_device_table_);

        WaitDevicesIdle();

        RestoreImageContents(active_device_, active_device_table_, active_queue_info_);
        RestoreImageLayouts(active_device_, active_device_table_, active_queue_info_);
        RestoreBufferStates(active_device_, active_device_table_, active_queue_info_);

        // Classify command pools once at the end of the first iteration
        ClassifyActiveCommandPools();

        // Reset active command pools at the loop boundary
        ResetActiveCommandPools();

        FixupDeviceFences(active_queue_info_->parent_id, active_queue_id_);
        FixupLoopBoundarySemaphores();
        RestoreInitialEventStates();
    }
    else
    {
        GFXRECON_LOG_WARNING("ResetLoopBoundary: Missing active queue info, cannot reset loop boundary!");
    }
}

void VulkanReplayFrameLoopConsumer::RestoreInitialEventStates()
{
    // Restore initial event states
    for (const auto& [event_id, is_set] : initial_event_states_)
    {
        if (device_only_events_.find(event_id) != device_only_events_.end())
        {
            continue;
        }

        auto event_info = GetObjectInfoTable().GetVkEventInfo(event_id);
        if (event_info != nullptr && event_info->handle != VK_NULL_HANDLE)
        {
            auto device_info = GetObjectInfoTable().GetVkDeviceInfo(event_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
                if (device_table != nullptr)
                {
                    if (is_set)
                    {
                        device_table->SetEvent(device_info->handle, event_info->handle);
                    }
                    else
                    {
                        device_table->ResetEvent(device_info->handle, event_info->handle);
                    }
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::RestoreImageLayouts(VkDevice                           device,
                                                        const graphics::VulkanDeviceTable* device_table,
                                                        VulkanQueueInfo*                   queue_info)
{
    std::vector<VkImageMemoryBarrier> barriers;

    GFXRECON_LOG_INFO("RestoreImageLayouts: loop_touched_images_ count = %zu", loop_touched_images_.size());

    GetObjectInfoTable().VisitVkImageInfo([this, device, &barriers](const VulkanImageInfo* info) {
        if (info == nullptr || info->handle == VK_NULL_HANDLE)
        {
            return;
        }

        auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(info->parent_id);
        if (dev_info == nullptr || dev_info->handle != device)
        {
            return;
        }

        ImageSubresourceLayoutTracker initial_tracker;
        auto                          it = initial_image_layouts_.find(info->capture_id);
        if (it != initial_image_layouts_.end())
        {
            initial_tracker = it->second;
        }
        else
        {
            initial_tracker.SetUniformLayout(info->initial_layout);
        }

        if (!loop_touched_images_.contains(info->capture_id))
        {
            return;
        }

        auto current_layouts = GetNormalizedSubresourceLayouts(info);
        for (const auto& subres_layout : current_layouts)
        {
            VkImageLayout target_layout = initial_tracker.GetLayout(
                subres_layout.range.aspectMask, subres_layout.range.baseMipLevel, subres_layout.range.baseArrayLayer);
            if (target_layout == VK_IMAGE_LAYOUT_UNDEFINED || target_layout == VK_IMAGE_LAYOUT_PREINITIALIZED)
            {
                continue;
            }
            if (subres_layout.layout == target_layout)
            {
                continue;
            }

            VkImageMemoryBarrier barrier = {};
            barrier.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barrier.oldLayout            = subres_layout.layout;
            barrier.newLayout            = target_layout;
            barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.image                = info->handle;

            barrier.subresourceRange = subres_layout.range;

            barrier.srcAccessMask = GetAccessFlags(barrier.oldLayout);
            barrier.dstAccessMask = GetAccessFlags(target_layout);

            barriers.push_back(barrier);
            GFXRECON_LOG_INFO("RestoreImageLayouts: Restoring image %" PRIu64
                              " aspect %d mip %d layer %d from %d to %d",
                              info->capture_id,
                              subres_layout.range.aspectMask,
                              subres_layout.range.baseMipLevel,
                              subres_layout.range.baseArrayLayer,
                              barrier.oldLayout,
                              barrier.newLayout);
        }

        auto mutable_info                 = const_cast<VulkanImageInfo*>(info);
        mutable_info->subresource_layouts = initial_tracker;
    });

    if (barriers.empty())
    {
        return;
    }

    if (!InitializeRestorationResources(device, queue_info->family_index))
    {
        return;
    }

    // Record commands
    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);

    device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     static_cast<uint32_t>(barriers.size()),
                                     barriers.data());

    device_table->EndCommandBuffer(restoration_command_buffer_);

    // Submit
    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &restoration_command_buffer_;

    VkQueue  replayed_queue = queue_info->handle;
    VkResult result         = device_table->QueueSubmit(replayed_queue, 1, &submit_info, VK_NULL_HANDLE);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to submit layout restoration commands, result=%d", result);
    }
    else
    {
        device_table->QueueWaitIdle(replayed_queue);
    }
}

void VulkanReplayFrameLoopConsumer::RecordInitialBufferStates(VkDevice                           device,
                                                              const graphics::VulkanDeviceTable* device_table,
                                                              VulkanQueueInfo*                   queue_info)
{
    if (queue_info == nullptr || !InitializeRestorationResources(device, queue_info->family_index))
    {
        GFXRECON_LOG_ERROR("RecordInitialBufferStates: Failed to initialize restoration resources.");
        return;
    }

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VkResult res                        = device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("RecordInitialBufferStates: BeginCommandBuffer failed with %d", res);
        return;
    }

    VkMemoryBarrier memory_barrier = { VK_STRUCTURE_TYPE_MEMORY_BARRIER };
    memory_barrier.srcAccessMask   = VK_ACCESS_MEMORY_WRITE_BIT;
    memory_barrier.dstAccessMask   = VK_ACCESS_TRANSFER_READ_BIT;
    device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     1,
                                     &memory_barrier,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr);

    uint32_t copy_count = 0;
    GetObjectInfoTable().VisitVkBufferInfo([this, device, device_table, &copy_count](const VulkanBufferInfo* info) {
        if (info == nullptr || info->handle == VK_NULL_HANDLE || info->size == 0)
        {
            return;
        }

        auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(info->parent_id);
        if (dev_info == nullptr || dev_info->handle != device || dev_info->allocator == nullptr)
        {
            return;
        }

        auto phys_info = GetObjectInfoTable().GetVkPhysicalDeviceInfo(dev_info->parent_id);
        if (phys_info == nullptr)
        {
            return;
        }

        const VkPhysicalDeviceMemoryProperties* mem_props = &phys_info->capture_memory_properties;
        if (phys_info->replay_device_info != nullptr && phys_info->replay_device_info->memory_properties.has_value())
        {
            mem_props = &phys_info->replay_device_info->memory_properties.value();
        }

        if (shadow_buffers_.find(info->capture_id) != shadow_buffers_.end())
        {
            return;
        }

        VkBufferCreateInfo create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
        create_info.size               = info->size;
        create_info.usage              = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

        VkBuffer                              shadow_buf = VK_NULL_HANDLE;
        VulkanResourceAllocator::ResourceData alloc_data = 0;
        VkResult create_res = dev_info->allocator->CreateBufferDirect(&create_info, nullptr, &shadow_buf, &alloc_data);
        if (create_res != VK_SUCCESS || shadow_buf == VK_NULL_HANDLE)
        {
            return;
        }

        VkMemoryRequirements mem_reqs;
        device_table->GetBufferMemoryRequirements(device, shadow_buf, &mem_reqs);

        uint32_t mem_idx =
            graphics::GetMemoryTypeIndex(*mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
        if (mem_idx == std::numeric_limits<uint32_t>::max())
        {
            mem_idx = graphics::GetMemoryTypeIndex(*mem_props, mem_reqs.memoryTypeBits, 0);
        }
        if (mem_idx == std::numeric_limits<uint32_t>::max())
        {
            dev_info->allocator->DestroyBufferDirect(shadow_buf, nullptr, alloc_data);
            return;
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.allocationSize       = mem_reqs.size;
        alloc_info.memoryTypeIndex      = mem_idx;

        VkDeviceMemory                      shadow_mem = VK_NULL_HANDLE;
        VulkanResourceAllocator::MemoryData mem_data   = 0;
        VkResult alloc_res = dev_info->allocator->AllocateMemoryDirect(&alloc_info, nullptr, &shadow_mem, &mem_data);
        if (alloc_res != VK_SUCCESS || shadow_mem == VK_NULL_HANDLE)
        {
            dev_info->allocator->DestroyBufferDirect(shadow_buf, nullptr, alloc_data);
            return;
        }

        VkMemoryPropertyFlags bind_props = 0;
        VkResult              bind_res =
            dev_info->allocator->BindBufferMemoryDirect(shadow_buf, shadow_mem, 0, alloc_data, mem_data, &bind_props);
        if (bind_res != VK_SUCCESS)
        {
            dev_info->allocator->FreeMemoryDirect(shadow_mem, nullptr, mem_data);
            dev_info->allocator->DestroyBufferDirect(shadow_buf, nullptr, alloc_data);
            return;
        }

        ShadowBufferInfo shadow;
        shadow.parent_id                  = info->parent_id;
        shadow.shadow_buffer              = shadow_buf;
        shadow.shadow_memory              = shadow_mem;
        shadow.size                       = info->size;
        shadow.alloc_data                 = alloc_data;
        shadow.mem_data                   = mem_data;
        shadow_buffers_[info->capture_id] = shadow;

        VkBufferCopy region = {};
        region.srcOffset    = 0;
        region.dstOffset    = 0;
        region.size         = info->size;
        device_table->CmdCopyBuffer(restoration_command_buffer_, info->handle, shadow_buf, 1, &region);
        copy_count++;
    });

    res = device_table->EndCommandBuffer(restoration_command_buffer_);
    if (res == VK_SUCCESS && copy_count > 0 && queue_info != nullptr)
    {
        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &restoration_command_buffer_;

        VkResult submit_res = device_table->QueueSubmit(queue_info->handle, 1, &submit_info, VK_NULL_HANDLE);
        if (submit_res == VK_SUCCESS)
        {
            device_table->QueueWaitIdle(queue_info->handle);
            GFXRECON_LOG_INFO("RecordInitialBufferStates: Snapshotted %u buffers into shadow memory.", copy_count);
        }
    }
}

void VulkanReplayFrameLoopConsumer::RestoreBufferStates(VkDevice                           device,
                                                        const graphics::VulkanDeviceTable* device_table,
                                                        VulkanQueueInfo*                   queue_info)
{
    if (shadow_buffers_.empty() || queue_info == nullptr)
    {
        return;
    }

    if (!InitializeRestorationResources(device, queue_info->family_index))
    {
        return;
    }

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VkResult res                        = device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);
    if (res != VK_SUCCESS)
    {
        return;
    }

    uint32_t restore_count = 0;
    for (const auto& [buf_id, shadow] : shadow_buffers_)
    {
        auto buf_info = GetObjectInfoTable().GetVkBufferInfo(buf_id);
        if (buf_info != nullptr && buf_info->handle != VK_NULL_HANDLE && shadow.shadow_buffer != VK_NULL_HANDLE)
        {
            auto dev_info = GetObjectInfoTable().GetVkDeviceInfo(buf_info->parent_id);
            if (dev_info == nullptr || dev_info->handle != device)
            {
                continue;
            }

            VkBufferCopy region = {};
            region.srcOffset    = 0;
            region.dstOffset    = 0;
            region.size         = shadow.size;
            device_table->CmdCopyBuffer(
                restoration_command_buffer_, shadow.shadow_buffer, buf_info->handle, 1, &region);
            restore_count++;
        }
    }

    if (restore_count > 0)
    {
        VkMemoryBarrier memory_barrier = { VK_STRUCTURE_TYPE_MEMORY_BARRIER };
        memory_barrier.srcAccessMask   = VK_ACCESS_TRANSFER_WRITE_BIT;
        memory_barrier.dstAccessMask   = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;

        device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                         0,
                                         1,
                                         &memory_barrier,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr);
    }

    res = device_table->EndCommandBuffer(restoration_command_buffer_);
    if (res == VK_SUCCESS && restore_count > 0)
    {
        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &restoration_command_buffer_;

        VkResult submit_res = device_table->QueueSubmit(queue_info->handle, 1, &submit_info, VK_NULL_HANDLE);
        if (submit_res == VK_SUCCESS)
        {
            device_table->QueueWaitIdle(queue_info->handle);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ClassifyActiveCommandPools()
{
    // 1. Classify loop state once at the boundary of the 1st play
    if (!loop_state_classified_)
    {
        VulkanObjectInfoTable& pool_info_table = GetObjectInfoTable();

        for (const auto& [dev, pools] : active_command_pools_)
        {
            for (VkCommandPool pool_handle : pools)
            {
                // Find the format::HandleId of this pool
                format::HandleId pool_id = format::kNullHandleId;
                pool_info_table.VisitVkCommandPoolInfo([pool_handle, &pool_id](const VulkanCommandPoolInfo* info) {
                    if (info->handle == pool_handle)
                        pool_id = info->capture_id;
                });

                if (pool_id == format::kNullHandleId)
                    continue;

                // Collect all CBs in this pool that are active in the loop
                pool_info_table.VisitVkCommandBufferInfo([this, pool_id](const VulkanCommandBufferInfo* cb_info) {
                    if (cb_info->pool_id == pool_id)
                    {
                        bool is_restorable       = loop_start_recording_cbs_.contains(cb_info->capture_id);
                        bool is_recorded_in_loop = loop_recorded_cbs_.contains(cb_info->capture_id);

                        if (!is_restorable)
                        {
                            if (initial_loop_recording_cbs_.contains(cb_info->capture_id))
                            {
                                cbs_to_recreate_with_rebegin_.push_back(cb_info->capture_id);
                            }
                            else if (is_recorded_in_loop)
                            {
                                cbs_to_recreate_without_rebegin_.push_back(cb_info->capture_id);
                            }
                        }
                    }
                });
            }
        }

        loop_state_classified_ = true;
        active_command_pools_.clear(); // No longer needed
    }
}

void VulkanReplayFrameLoopConsumer::ResetActiveCommandPools()
{
    // Reset all shadow pools
    for (auto& [original_pool, shadow_pool] : shadow_pools_)
    {
        VulkanCommandPoolInfo* pool_info = nullptr;
        GetObjectInfoTable().VisitVkCommandPoolInfo([original_pool, &pool_info](const VulkanCommandPoolInfo* info) {
            if (info->handle == original_pool)
            {
                pool_info = const_cast<VulkanCommandPoolInfo*>(info);
            }
        });
        if (pool_info != nullptr && pool_info->parent_id != format::kNullHandleId)
        {
            auto device_info = GetObjectInfoTable().GetVkDeviceInfo(pool_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                auto device_table = GetDeviceTable(device_info->handle);
                if (device_table != nullptr)
                {
                    VkResult res = device_table->ResetCommandPool(device_info->handle, shadow_pool, 0);
                    if (res == VK_SUCCESS)
                    {
                        GFXRECON_LOG_INFO("ResetActiveCommandPools: Reset shadow command pool %p", shadow_pool);
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("ResetActiveCommandPools: Failed to reset shadow command pool %p, error %d",
                                           shadow_pool,
                                           res);
                    }
                }
            }
        }
    }

    // 2. Execute resetting/recreation (runs EVERY iteration!)
    if (loop_state_classified_)
    {
        // A. Recreate and re-begin CBs (active at start)
        for (auto cb_id : cbs_to_recreate_with_rebegin_)
        {
            RecreateAndRebeginCommandBuffer(cb_id, true);
        }

        // B. Recreate CBs (begun in loop, reset to INITIAL)
        for (auto cb_id : cbs_to_recreate_without_rebegin_)
        {
            auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
            if (cb_info != nullptr && redirected_cbs_.contains(cb_info->handle))
            {
                continue;
            }
            RecreateAndRebeginCommandBuffer(cb_id, false);
        }
    }
}

void VulkanReplayFrameLoopConsumer::RebeginCommandBuffer(format::HandleId cb_id)
{
    auto it = cb_begin_infos_.find(cb_id);
    if (it == cb_begin_infos_.end())
    {
        GFXRECON_LOG_WARNING("RebeginCommandBuffer: Missing begin info for CB %" PRIu64 ", cannot re-begin!", cb_id);
        return;
    }

    const auto& begin_info_saved = it->second;
    auto        cb_info          = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
    if (cb_info == nullptr || cb_info->handle == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_WARNING("RebeginCommandBuffer: Missing handle for CB %" PRIu64 ", cannot re-begin!", cb_id);
        return;
    }

    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(begin_info_saved.device);
    if (device_table == nullptr)
    {
        GFXRECON_LOG_WARNING("RebeginCommandBuffer: Missing device table for CB %" PRIu64 ", cannot re-begin!", cb_id);
        return;
    }

    GFXRECON_LOG_INFO("RebeginCommandBuffer: Synthetically re-beginning CB %" PRIu64 " (handle %p) on device %p...",
                      cb_id,
                      cb_info->handle,
                      begin_info_saved.device);

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags                    = begin_info_saved.flags;

    VkCommandBufferInheritanceInfo inheritance_info = {};
    if (begin_info_saved.has_inheritance_info)
    {
        inheritance_info            = begin_info_saved.inheritance_info;
        begin_info.pInheritanceInfo = &inheritance_info;
    }

    VkResult result = device_table->BeginCommandBuffer(cb_info->handle, &begin_info);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("RebeginCommandBuffer: Failed to re-begin CB %" PRIu64 ", result=%d", cb_id, result);
    }
    else
    {
        // Put it back to recording set!
        recording_cbs_.insert(cb_id);
    }
}

void VulkanReplayFrameLoopConsumer::RecreateAndRebeginCommandBuffer(format::HandleId cb_id, bool rebegin)
{
    auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_id);
    if (cb_info == nullptr || cb_info->handle == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_WARNING("RecreateAndRebeginCommandBuffer: Missing handle for CB %" PRIu64 ", cannot recreate!",
                             cb_id);
        return;
    }

    auto device_info = GetObjectInfoTable().GetVkDeviceInfo(cb_info->parent_id);
    if (device_info == nullptr || device_info->handle == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_WARNING("RecreateAndRebeginCommandBuffer: Missing device for CB %" PRIu64 ", cannot recreate!",
                             cb_id);
        return;
    }
    VkDevice                           device       = device_info->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    if (device_table == nullptr)
    {
        GFXRECON_LOG_WARNING(
            "RecreateAndRebeginCommandBuffer: Missing device table for CB %" PRIu64 ", cannot recreate!", cb_id);
        return;
    }

    format::HandleId pool_id   = cb_info->pool_id;
    auto             pool_info = GetObjectInfoTable().GetVkCommandPoolInfo(pool_id);
    if (pool_info == nullptr || pool_info->handle == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_WARNING("RecreateAndRebeginCommandBuffer: Missing pool for CB %" PRIu64 ", cannot recreate!",
                             cb_id);
        return;
    }
    VkCommandPool pool = pool_info->handle;

    // 1. Free the old command buffer
    VkCommandBuffer old_cb_handle = cb_info->handle;
    device_table->FreeCommandBuffers(device, pool, 1, &old_cb_handle);

    // 2. Allocate a new command buffer
    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.commandPool                 = pool;
    alloc_info.level                       = cb_info->level;
    alloc_info.commandBufferCount          = 1;

    VkCommandBuffer new_cb_handle = VK_NULL_HANDLE;
    VkResult        result        = device_table->AllocateCommandBuffers(device, &alloc_info, &new_cb_handle);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "RecreateAndRebeginCommandBuffer: Failed to allocate new CB for %" PRIu64 ", result=%d", cb_id, result);
        return;
    }

    // 3. Update the handle mapping in the ObjectInfoTable
    // We already have cb_info pointing directly to the entry in the map, so updating
    // cb_info->handle directly is sufficient and runs in O(1) time.
    cb_info->handle = new_cb_handle;

    // 4. Re-begin if requested
    if (rebegin)
    {
        auto it = cb_begin_infos_.find(cb_id);
        if (it == cb_begin_infos_.end())
        {
            GFXRECON_LOG_WARNING(
                "RecreateAndRebeginCommandBuffer: Missing begin info for CB %" PRIu64 ", cannot rebegin!", cb_id);
            return;
        }
        const auto& begin_info_saved = it->second;

        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
        begin_info.flags                    = begin_info_saved.flags;

        VkCommandBufferInheritanceInfo inheritance_info = {};
        if (begin_info_saved.has_inheritance_info)
        {
            inheritance_info            = begin_info_saved.inheritance_info;
            begin_info.pInheritanceInfo = &inheritance_info;
        }

        result = device_table->BeginCommandBuffer(new_cb_handle, &begin_info);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("RecreateAndRebeginCommandBuffer: Failed to begin new CB %" PRIu64
                               " (handle %p), result=%d",
                               cb_id,
                               new_cb_handle,
                               result);
        }
        else
        {
            recording_cbs_.insert(cb_id);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdExecuteCommands(const ApiCallInfo& call_info,
                                                                 format::HandleId   commandBuffer,
                                                                 uint32_t           commandBufferCount,
                                                                 HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteCommands(call_info, commandBuffer, commandBufferCount, pCommandBuffers);

    auto primary_cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);
    if (primary_cb_info != nullptr && pCommandBuffers != nullptr)
    {
        const auto secondary_handles = pCommandBuffers->GetHandlePointer();
        const auto secondary_ids     = pCommandBuffers->GetPointer();
        if (secondary_handles != nullptr && secondary_ids != nullptr)
        {
            if (loop_start_recording_cbs_.contains(commandBuffer))
            {
                for (uint32_t i = 0; i < commandBufferCount; ++i)
                {
                    loop_start_recording_cbs_.insert(secondary_ids[i]);
                }
            }
            for (uint32_t i = 0; i < commandBufferCount; ++i)
            {
                primary_cb_info->executed_secondary_command_buffers.push_back(secondary_ids[i]);
                auto secondary_cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(secondary_ids[i]);
                if (secondary_cb_info != nullptr)
                {
                    for (const auto& barrier : secondary_cb_info->image_layout_barriers)
                    {
                        auto& transitions = primary_cb_info->image_layout_barriers[barrier.first];
                        transitions.insert(transitions.end(), barrier.second.begin(), barrier.second.end());
                    }
                    primary_cb_info->bound_descriptor_sets.insert(primary_cb_info->bound_descriptor_sets.end(),
                                                                  secondary_cb_info->bound_descriptor_sets.begin(),
                                                                  secondary_cb_info->bound_descriptor_sets.end());
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>*     pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*                       pEvent)
{
    if (setup_complete_ && pEvent != nullptr && pEvent->GetPointer() != nullptr)
    {
        auto capture_id = pEvent->GetPointer()[0];
        auto event_info = GetObjectInfoTable().GetVkEventInfo(capture_id);
        if (event_info != nullptr && event_info->handle != VK_NULL_HANDLE)
        {
            auto device_info = GetObjectInfoTable().GetVkDeviceInfo(event_info->parent_id);
            if (device_info != nullptr)
            {
                const auto* device_table = GetDeviceTable(device_info->handle);
                if (device_table != nullptr)
                {
                    device_table->DestroyEvent(device_info->handle, event_info->handle, nullptr);
                }
            }
            GetObjectInfoTable().RemoveVkEventInfo(capture_id);
        }
    }

    VulkanReplayConsumer::Process_vkCreateEvent(call_info, returnValue, device, pCreateInfo, pAllocator, pEvent);

    if (returnValue == VK_SUCCESS && pCreateInfo != nullptr && pEvent != nullptr)
    {
        auto* create_info = pCreateInfo->GetPointer();
        if (create_info != nullptr && pEvent->GetPointer() != nullptr)
        {
            if (create_info->flags & VK_EVENT_CREATE_DEVICE_ONLY_BIT)
            {
                device_only_events_.insert(pEvent->GetPointer()[0]);
            }
        }
    }
}

VkResult VulkanReplayFrameLoopConsumer::CreateShadowImage(VkDevice                               device,
                                                          const VulkanImageInfo*                 orig_info,
                                                          VkImage*                               shadow_image,
                                                          VkDeviceMemory*                        shadow_memory,
                                                          VulkanResourceAllocator::ResourceData* alloc_data,
                                                          VulkanResourceAllocator::MemoryData*   mem_data)
{
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    auto                               dev_info     = GetObjectInfoTable().GetVkDeviceInfo(orig_info->parent_id);
    GFXRECON_ASSERT(device_table && dev_info && dev_info->allocator);

    auto phys_info = GetObjectInfoTable().GetVkPhysicalDeviceInfo(dev_info->parent_id);
    GFXRECON_ASSERT(phys_info);

    const VkPhysicalDeviceMemoryProperties* mem_props = &phys_info->capture_memory_properties;
    if (phys_info->replay_device_info != nullptr && phys_info->replay_device_info->memory_properties.has_value())
    {
        mem_props = &phys_info->replay_device_info->memory_properties.value();
    }

    VkImageCreateInfo create_info = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.imageType         = orig_info->type;
    create_info.format            = orig_info->format;
    create_info.extent            = orig_info->extent;
    create_info.mipLevels         = orig_info->level_count;
    create_info.arrayLayers       = orig_info->layer_count;
    create_info.samples           = orig_info->sample_count;
    create_info.tiling            = orig_info->tiling;
    create_info.usage             = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;
    create_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImage                               shadow_img   = VK_NULL_HANDLE;
    VulkanResourceAllocator::ResourceData shadow_alloc = 0;
    VkResult res = dev_info->allocator->CreateImageDirect(&create_info, nullptr, &shadow_img, &shadow_alloc);
    if (res != VK_SUCCESS || shadow_img == VK_NULL_HANDLE)
    {
        return res;
    }

    VkMemoryRequirements mem_reqs;
    device_table->GetImageMemoryRequirements(device, shadow_img, &mem_reqs);

    uint32_t mem_idx =
        graphics::GetMemoryTypeIndex(*mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (mem_idx == std::numeric_limits<uint32_t>::max())
    {
        mem_idx = graphics::GetMemoryTypeIndex(*mem_props, mem_reqs.memoryTypeBits, 0);
    }
    if (mem_idx == std::numeric_limits<uint32_t>::max())
    {
        dev_info->allocator->DestroyImageDirect(shadow_img, nullptr, shadow_alloc);
        return VK_ERROR_OUT_OF_DEVICE_MEMORY;
    }

    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    mem_alloc_info.allocationSize       = mem_reqs.size;
    mem_alloc_info.memoryTypeIndex      = mem_idx;

    VkDeviceMemory                      shadow_mem      = VK_NULL_HANDLE;
    VulkanResourceAllocator::MemoryData shadow_mem_data = 0;
    res = dev_info->allocator->AllocateMemoryDirect(&mem_alloc_info, nullptr, &shadow_mem, &shadow_mem_data);
    if (res != VK_SUCCESS || shadow_mem == VK_NULL_HANDLE)
    {
        dev_info->allocator->DestroyImageDirect(shadow_img, nullptr, shadow_alloc);
        return res;
    }

    VkMemoryPropertyFlags bind_props = 0;
    res                              = dev_info->allocator->BindImageMemoryDirect(
        shadow_img, shadow_mem, 0, shadow_alloc, shadow_mem_data, &bind_props);
    if (res != VK_SUCCESS)
    {
        dev_info->allocator->FreeMemoryDirect(shadow_mem, nullptr, shadow_mem_data);
        dev_info->allocator->DestroyImageDirect(shadow_img, nullptr, shadow_alloc);
        return res;
    }

    *shadow_image  = shadow_img;
    *shadow_memory = shadow_mem;
    *alloc_data    = shadow_alloc;
    *mem_data      = shadow_mem_data;

    return VK_SUCCESS;
}

void VulkanReplayFrameLoopConsumer::LazyBackupImagesForSubmit(VkQueue                 queue,
                                                              uint32_t                cb_count,
                                                              const format::HandleId* cb_ids)
{
    if (cb_count == 0 || cb_ids == nullptr)
    {
        return;
    }

    VulkanQueueInfo* queue_info = nullptr;
    GetObjectInfoTable().VisitVkQueueInfo([queue, &queue_info](const VulkanQueueInfo* q_info) {
        if (q_info->handle == queue)
        {
            queue_info = const_cast<VulkanQueueInfo*>(q_info);
        }
    });

    if (queue_info == nullptr)
    {
        return;
    }

    VkDevice                           device = GetObjectInfoTable().GetVkDeviceInfo(queue_info->parent_id)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);

    if (!InitializeRestorationResources(device, queue_info->family_index))
    {
        return;
    }

    std::vector<format::HandleId> images_to_backup;
    for (uint32_t i = 0; i < cb_count; ++i)
    {
        auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_ids[i]);
        if (cb_info != nullptr)
        {
            CollectTouchedImagesFromCommandBuffer(cb_ids[i]);
        }
    }

    for (auto image_id : loop_touched_images_)
    {
        auto img_info = GetObjectInfoTable().GetVkImageInfo(image_id);
        if (img_info == nullptr || img_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        if (shadow_images_.find(image_id) != shadow_images_.end())
        {
            continue;
        }

        VkImageUsageFlags write_flags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |
                                        VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_STORAGE_BIT |
                                        VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        if ((img_info->usage & write_flags) == 0)
        {
            continue;
        }

        if ((img_info->usage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) != 0)
        {
            continue;
        }

        if ((img_info->usage & (VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT)) !=
            (VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT))
        {
            continue;
        }

        auto layouts       = img_info->subresource_layouts.GetSubresourceLayouts();
        bool all_undefined = true;
        for (const auto& sub : layouts)
        {
            if (sub.layout != VK_IMAGE_LAYOUT_UNDEFINED && sub.layout != VK_IMAGE_LAYOUT_PREINITIALIZED)
            {
                all_undefined = false;
                break;
            }
        }
        if (layouts.empty() || all_undefined)
        {
            continue;
        }

        images_to_backup.push_back(image_id);
    }

    if (images_to_backup.empty())
    {
        return;
    }

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);

    for (auto image_id : images_to_backup)
    {
        auto img_info = GetObjectInfoTable().GetVkImageInfo(image_id);

        ShadowImageInfo shadow_info;
        shadow_info.parent_id    = img_info->parent_id;
        shadow_info.format       = img_info->format;
        shadow_info.extent       = img_info->extent;
        shadow_info.mip_levels   = img_info->level_count;
        shadow_info.array_layers = img_info->layer_count;
        shadow_info.samples      = img_info->sample_count;

        VkResult res = CreateShadowImage(device,
                                         img_info,
                                         &shadow_info.shadow_image,
                                         &shadow_info.shadow_memory,
                                         &shadow_info.alloc_data,
                                         &shadow_info.mem_data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("LazyBackup: Failed to create shadow image for %" PRIu64 ", res=%d", image_id, res);
            continue;
        }

        shadow_info.current_layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        shadow_images_[image_id]   = shadow_info;

        VkImageLayout current_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        auto          layouts        = img_info->subresource_layouts.GetSubresourceLayouts();
        if (!layouts.empty())
        {
            current_layout = layouts[0].layout;
        }

        VkImageAspectFlags aspect_mask = GetAspectMask(img_info->format);

        VkImageMemoryBarrier barrier_orig            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        barrier_orig.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        barrier_orig.srcAccessMask                   = 0;
        barrier_orig.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
        barrier_orig.oldLayout                       = current_layout;
        barrier_orig.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        barrier_orig.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        barrier_orig.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        barrier_orig.image                           = img_info->handle;
        barrier_orig.subresourceRange.aspectMask     = aspect_mask;
        barrier_orig.subresourceRange.baseMipLevel   = 0;
        barrier_orig.subresourceRange.levelCount     = img_info->level_count;
        barrier_orig.subresourceRange.baseArrayLayer = 0;
        barrier_orig.subresourceRange.layerCount     = img_info->layer_count;

        VkImageMemoryBarrier barrier_shadow = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        barrier_shadow.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        barrier_shadow.srcAccessMask        = 0;
        barrier_shadow.dstAccessMask        = VK_ACCESS_TRANSFER_WRITE_BIT;
        barrier_shadow.oldLayout            = VK_IMAGE_LAYOUT_UNDEFINED;
        barrier_shadow.newLayout            = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        barrier_shadow.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
        barrier_shadow.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
        barrier_shadow.image                = shadow_info.shadow_image;
        barrier_shadow.subresourceRange     = barrier_orig.subresourceRange;

        VkImageMemoryBarrier barriers[2] = { barrier_orig, barrier_shadow };
        device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                         VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         2,
                                         barriers);

        std::vector<VkImageCopy> copy_regions;
        for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
        {
            VkImageCopy region                   = {};
            region.srcSubresource.aspectMask     = aspect_mask;
            region.srcSubresource.mipLevel       = mip;
            region.srcSubresource.baseArrayLayer = 0;
            region.srcSubresource.layerCount     = img_info->layer_count;
            region.dstSubresource                = region.srcSubresource;
            region.extent.width                  = std::max(1u, img_info->extent.width >> mip);
            region.extent.height                 = std::max(1u, img_info->extent.height >> mip);
            region.extent.depth                  = std::max(1u, img_info->extent.depth >> mip);
            copy_regions.push_back(region);
        }

        device_table->CmdCopyImage(restoration_command_buffer_,
                                   img_info->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   shadow_info.shadow_image,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   static_cast<uint32_t>(copy_regions.size()),
                                   copy_regions.data());

        VkImageMemoryBarrier barrier_restore = barrier_orig;
        barrier_restore.oldLayout            = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        barrier_restore.newLayout            = current_layout;
        barrier_restore.srcAccessMask        = VK_ACCESS_TRANSFER_READ_BIT;

        // Set destination access flags for layout restoration
        barrier_restore.dstAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT |
                                        VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

        device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &barrier_restore);

        GFXRECON_LOG_INFO("LazyBackup: Captured initial content for image %" PRIu64
                          " (handle %p) using shadow image %p",
                          image_id,
                          img_info->handle,
                          shadow_info.shadow_image);
    }

    device_table->EndCommandBuffer(restoration_command_buffer_);

    VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &restoration_command_buffer_;

    device_table->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);
    device_table->QueueWaitIdle(queue);
}

void VulkanReplayFrameLoopConsumer::RestoreImageContents(VkDevice                           device,
                                                         const graphics::VulkanDeviceTable* device_table,
                                                         VulkanQueueInfo*                   queue_info)
{
    if (shadow_images_.empty())
    {
        return;
    }

    if (!InitializeRestorationResources(device, queue_info->family_index))
    {
        return;
    }

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);

    std::vector<VkImageMemoryBarrier> pre_barriers;
    std::vector<VkImageMemoryBarrier> post_barriers;

    struct ImageRestoreData
    {
        VkImage            original_image;
        VkImage            shadow_image;
        VkFormat           format;
        VkExtent3D         extent;
        uint32_t           mip_levels;
        uint32_t           array_layers;
        VkImageAspectFlags aspect_mask;
    };
    std::vector<ImageRestoreData> restores;

    for (auto& [image_id, shadow_info] : shadow_images_)
    {
        auto img_info = GetObjectInfoTable().GetVkImageInfo(image_id);
        if (img_info == nullptr)
        {
            continue;
        }

        ImageSubresourceLayoutTracker initial_tracker;
        auto                          it = initial_image_layouts_.find(img_info->capture_id);
        if (it != initial_image_layouts_.end())
        {
            initial_tracker = it->second;
        }
        else
        {
            initial_tracker.SetUniformLayout(img_info->initial_layout);
        }

        VkImageAspectFlags aspect_mask = GetAspectMask(img_info->format);

        auto current_layouts = GetNormalizedSubresourceLayouts(img_info);
        for (const auto& subres_layout : current_layouts)
        {
            VkImageMemoryBarrier barrier = {};
            barrier.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barrier.oldLayout            = subres_layout.layout;
            barrier.newLayout            = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.image                = img_info->handle;
            barrier.subresourceRange     = subres_layout.range;
            barrier.srcAccessMask        = GetAccessFlags(barrier.oldLayout);
            barrier.dstAccessMask        = VK_ACCESS_TRANSFER_WRITE_BIT;
            pre_barriers.push_back(barrier);

            VkImageLayout target_layout = initial_tracker.GetLayout(
                subres_layout.range.aspectMask, subres_layout.range.baseMipLevel, subres_layout.range.baseArrayLayer);
            if (target_layout == VK_IMAGE_LAYOUT_UNDEFINED || target_layout == VK_IMAGE_LAYOUT_PREINITIALIZED)
            {
                target_layout = VK_IMAGE_LAYOUT_GENERAL;
            }

            VkImageMemoryBarrier restore_barrier = {};
            restore_barrier.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            restore_barrier.oldLayout            = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            restore_barrier.newLayout            = target_layout;
            restore_barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            restore_barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            restore_barrier.image                = img_info->handle;
            restore_barrier.subresourceRange     = subres_layout.range;
            restore_barrier.srcAccessMask        = VK_ACCESS_TRANSFER_WRITE_BIT;
            restore_barrier.dstAccessMask        = GetAccessFlags(target_layout);
            post_barriers.push_back(restore_barrier);
        }

        VkImageMemoryBarrier barrier_shadow            = {};
        barrier_shadow.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        barrier_shadow.oldLayout                       = shadow_info.current_layout;
        barrier_shadow.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        barrier_shadow.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        barrier_shadow.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        barrier_shadow.image                           = shadow_info.shadow_image;
        barrier_shadow.subresourceRange.aspectMask     = aspect_mask;
        barrier_shadow.subresourceRange.baseMipLevel   = 0;
        barrier_shadow.subresourceRange.levelCount     = img_info->level_count;
        barrier_shadow.subresourceRange.baseArrayLayer = 0;
        barrier_shadow.subresourceRange.layerCount     = img_info->layer_count;
        barrier_shadow.srcAccessMask                   = VK_ACCESS_TRANSFER_WRITE_BIT;
        barrier_shadow.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
        pre_barriers.push_back(barrier_shadow);

        const_cast<ShadowImageInfo&>(shadow_info).current_layout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

        ImageRestoreData restore_data;
        restore_data.original_image = img_info->handle;
        restore_data.shadow_image   = shadow_info.shadow_image;
        restore_data.format         = img_info->format;
        restore_data.extent         = img_info->extent;
        restore_data.mip_levels     = img_info->level_count;
        restore_data.array_layers   = img_info->layer_count;
        restore_data.aspect_mask    = aspect_mask;
        restores.push_back(restore_data);

        auto mutable_info                 = const_cast<VulkanImageInfo*>(img_info);
        mutable_info->subresource_layouts = initial_tracker;
    }

    if (!pre_barriers.empty())
    {
        device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                         VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         static_cast<uint32_t>(pre_barriers.size()),
                                         pre_barriers.data());
    }

    for (const auto& restore : restores)
    {
        std::vector<VkImageCopy> copy_regions;
        for (uint32_t mip = 0; mip < restore.mip_levels; ++mip)
        {
            VkImageCopy region                   = {};
            region.srcSubresource.aspectMask     = restore.aspect_mask;
            region.srcSubresource.mipLevel       = mip;
            region.srcSubresource.baseArrayLayer = 0;
            region.srcSubresource.layerCount     = restore.array_layers;
            region.dstSubresource                = region.srcSubresource;
            region.extent.width                  = std::max(1u, restore.extent.width >> mip);
            region.extent.height                 = std::max(1u, restore.extent.height >> mip);
            region.extent.depth                  = std::max(1u, restore.extent.depth >> mip);
            copy_regions.push_back(region);
        }

        device_table->CmdCopyImage(restoration_command_buffer_,
                                   restore.shadow_image,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   restore.original_image,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   static_cast<uint32_t>(copy_regions.size()),
                                   copy_regions.data());
    }

    if (!post_barriers.empty())
    {
        device_table->CmdPipelineBarrier(restoration_command_buffer_,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         static_cast<uint32_t>(post_barriers.size()),
                                         post_barriers.data());
    }

    device_table->EndCommandBuffer(restoration_command_buffer_);

    VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &restoration_command_buffer_;

    VkQueue active_queue = active_queue_info_->handle;
    device_table->QueueSubmit(active_queue, 1, &submit_info, VK_NULL_HANDLE);
    device_table->QueueWaitIdle(active_queue);
}

template <typename T>
void VulkanReplayFrameLoopConsumer::TrackAndAdjustSubmitSemaphores(format::HandleId         queue,
                                                                   StructPointerDecoder<T>* pSubmits)
{
    if (pSubmits == nullptr || pSubmits->GetMetaStructPointer() == nullptr)
    {
        return;
    }
    uint32_t count   = pSubmits->GetLength();
    auto     submits = pSubmits->GetMetaStructPointer();
    for (uint32_t i = 0; i < count; ++i)
    {
        ProcessSemaphoreUsage(queue, submits[i]);
    }
}

template void VulkanReplayFrameLoopConsumer::TrackAndAdjustSubmitSemaphores<Decoded_VkSubmitInfo>(
    format::HandleId queue, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits);
template void VulkanReplayFrameLoopConsumer::TrackAndAdjustSubmitSemaphores<Decoded_VkSubmitInfo2>(
    format::HandleId queue, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits);

void VulkanReplayFrameLoopConsumer::ProcessSemaphoreUsage(format::HandleId queue, const Decoded_VkSubmitInfo& submit)
{
    Decoded_VkTimelineSemaphoreSubmitInfo* timeline_info = const_cast<Decoded_VkTimelineSemaphoreSubmitInfo*>(
        GetPNextMetaStruct<Decoded_VkTimelineSemaphoreSubmitInfo>(submit.pNext));

    uint32_t  wait_count  = submit.pWaitSemaphores.GetLength();
    auto      wait_sems   = submit.pWaitSemaphores.GetPointer();
    uint64_t* wait_values = (timeline_info != nullptr && timeline_info->pWaitSemaphoreValues.GetPointer() != nullptr)
                                ? timeline_info->pWaitSemaphoreValues.GetPointer()
                                : nullptr;

    for (uint32_t j = 0; j < wait_count; ++j)
    {
        format::HandleId sem_id = wait_sems[j];
        bool is_timeline = timeline_semaphores_.contains(sem_id) || (wait_values != nullptr && wait_values[j] != 0);
        if (is_timeline && wait_values != nullptr)
        {
            timeline_semaphores_.insert(sem_id);
            if (IsLoopFirstIteration())
            {
                timeline_trackers_[sem_id].min_value = std::min(timeline_trackers_[sem_id].min_value, wait_values[j]);
                timeline_trackers_[sem_id].max_value = std::max(timeline_trackers_[sem_id].max_value, wait_values[j]);
            }
            else
            {
                wait_values[j] += timeline_trackers_[sem_id].current_offset;
            }
        }
        else if (IsLoopFirstIteration())
        {
            if (loop_pending_signaled_semaphores_.contains(sem_id))
            {
                loop_pending_signaled_semaphores_.erase(sem_id);
            }
            else
            {
                loop_external_waited_semaphores_.insert(sem_id);
            }
        }
    }

    uint32_t  signal_count = submit.pSignalSemaphores.GetLength();
    auto      signal_sems  = submit.pSignalSemaphores.GetPointer();
    uint64_t* signal_values =
        (timeline_info != nullptr && timeline_info->pSignalSemaphoreValues.GetPointer() != nullptr)
            ? timeline_info->pSignalSemaphoreValues.GetPointer()
            : nullptr;

    for (uint32_t j = 0; j < signal_count; ++j)
    {
        format::HandleId sem_id = signal_sems[j];
        bool is_timeline = timeline_semaphores_.contains(sem_id) || (signal_values != nullptr && signal_values[j] != 0);
        if (is_timeline && signal_values != nullptr)
        {
            timeline_semaphores_.insert(sem_id);
            if (IsLoopFirstIteration())
            {
                timeline_trackers_[sem_id].min_value = std::min(timeline_trackers_[sem_id].min_value, signal_values[j]);
                timeline_trackers_[sem_id].max_value = std::max(timeline_trackers_[sem_id].max_value, signal_values[j]);
            }
            else
            {
                signal_values[j] += timeline_trackers_[sem_id].current_offset;
            }
        }
        else if (IsLoopFirstIteration())
        {
            loop_pending_signaled_semaphores_.insert(sem_id);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ProcessSemaphoreUsage(format::HandleId queue, const Decoded_VkSubmitInfo2& submit)
{
    if (submit.pWaitSemaphoreInfos != nullptr && submit.pWaitSemaphoreInfos->GetMetaStructPointer() != nullptr)
    {
        uint32_t count      = submit.pWaitSemaphoreInfos->GetLength();
        auto     wait_infos = submit.pWaitSemaphoreInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < count; ++j)
        {
            format::HandleId sem_id = wait_infos[j].semaphore;
            uint64_t         val    = (wait_infos[j].decoded_value != nullptr) ? wait_infos[j].decoded_value->value : 0;
            bool             is_timeline = timeline_semaphores_.contains(sem_id) || val != 0;
            if (is_timeline)
            {
                timeline_semaphores_.insert(sem_id);
                if (IsLoopFirstIteration())
                {
                    timeline_trackers_[sem_id].min_value = std::min(timeline_trackers_[sem_id].min_value, val);
                    timeline_trackers_[sem_id].max_value = std::max(timeline_trackers_[sem_id].max_value, val);
                }
                else if (wait_infos[j].decoded_value != nullptr)
                {
                    wait_infos[j].decoded_value->value += timeline_trackers_[sem_id].current_offset;
                }
            }
            else if (IsLoopFirstIteration())
            {
                if (loop_pending_signaled_semaphores_.contains(sem_id))
                {
                    loop_pending_signaled_semaphores_.erase(sem_id);
                }
                else
                {
                    loop_external_waited_semaphores_.insert(sem_id);
                }
            }
        }
    }

    if (submit.pSignalSemaphoreInfos != nullptr && submit.pSignalSemaphoreInfos->GetMetaStructPointer() != nullptr)
    {
        uint32_t count        = submit.pSignalSemaphoreInfos->GetLength();
        auto     signal_infos = submit.pSignalSemaphoreInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < count; ++j)
        {
            format::HandleId sem_id = signal_infos[j].semaphore;
            uint64_t val = (signal_infos[j].decoded_value != nullptr) ? signal_infos[j].decoded_value->value : 0;
            bool     is_timeline = timeline_semaphores_.contains(sem_id) || val != 0;
            if (is_timeline)
            {
                timeline_semaphores_.insert(sem_id);
                if (IsLoopFirstIteration())
                {
                    timeline_trackers_[sem_id].min_value = std::min(timeline_trackers_[sem_id].min_value, val);
                    timeline_trackers_[sem_id].max_value = std::max(timeline_trackers_[sem_id].max_value, val);
                }
                else if (signal_infos[j].decoded_value != nullptr)
                {
                    signal_infos[j].decoded_value->value += timeline_trackers_[sem_id].current_offset;
                }
            }
            else if (IsLoopFirstIteration())
            {
                loop_pending_signaled_semaphores_.insert(sem_id);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::FixupLoopBoundarySemaphores()
{
    if (active_device_ == VK_NULL_HANDLE || active_queue_info_ == nullptr)
    {
        return;
    }

    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(active_device_);
    if (device_table == nullptr)
    {
        return;
    }

    std::vector<VkSemaphore> timeline_signal_sems;
    std::vector<uint64_t>    timeline_signal_values;

    for (auto& [sem_id, tracker] : timeline_trackers_)
    {
        if (tracker.min_value <= tracker.max_value)
        {
            uint64_t delta = tracker.max_value - tracker.min_value + 1;
            tracker.current_offset += delta;

            const VulkanSemaphoreInfo* sem_info = table.GetVkSemaphoreInfo(sem_id);
            if (sem_info != nullptr && sem_info->handle != VK_NULL_HANDLE)
            {
                timeline_signal_sems.push_back(sem_info->handle);
                timeline_signal_values.push_back(tracker.min_value + tracker.current_offset);
                GFXRECON_LOG_INFO("Loop boundary dummy signal for timeline semaphore %llu to value %llu",
                                  (unsigned long long)sem_id,
                                  (unsigned long long)(tracker.min_value + tracker.current_offset));
            }
        }
    }

    if (!timeline_signal_sems.empty())
    {
        VkTimelineSemaphoreSubmitInfo timeline_info = { VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO };
        timeline_info.signalSemaphoreValueCount     = static_cast<uint32_t>(timeline_signal_values.size());
        timeline_info.pSignalSemaphoreValues        = timeline_signal_values.data();

        VkSubmitInfo submit         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit.pNext                = &timeline_info;
        submit.signalSemaphoreCount = static_cast<uint32_t>(timeline_signal_sems.size());
        submit.pSignalSemaphores    = timeline_signal_sems.data();

        device_table->QueueSubmit(active_queue_info_->handle, 1, &submit, VK_NULL_HANDLE);
        device_table->QueueWaitIdle(active_queue_info_->handle);
    }

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.commandPool                 = restoration_command_pool_;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;
    VkCommandBuffer boundary_cb            = VK_NULL_HANDLE;
    if (restoration_command_pool_ != VK_NULL_HANDLE)
    {
        device_table->AllocateCommandBuffers(active_device_, &alloc_info, &boundary_cb);
        if (boundary_cb != VK_NULL_HANDLE)
        {
            VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
            begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
            device_table->BeginCommandBuffer(boundary_cb, &begin_info);
            VkMemoryBarrier barrier = { VK_STRUCTURE_TYPE_MEMORY_BARRIER };
            barrier.srcAccessMask   = 0;
            barrier.dstAccessMask   = 0;
            device_table->CmdPipelineBarrier(boundary_cb,
                                             VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                             VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                             0,
                                             1,
                                             &barrier,
                                             0,
                                             nullptr,
                                             0,
                                             nullptr);
            device_table->EndCommandBuffer(boundary_cb);
        }
    }

    std::unordered_set<VkSemaphore>   seen_waits;
    std::vector<VkSemaphore>          wait_sems;
    std::vector<VkPipelineStageFlags> wait_stages;
    for (format::HandleId sem_id : loop_pending_signaled_semaphores_)
    {
        const VulkanSemaphoreInfo* sem_info = table.GetVkSemaphoreInfo(sem_id);
        if (sem_info != nullptr && sem_info->handle != VK_NULL_HANDLE)
        {
            if (IsShadowSemaphore(sem_info->handle) || !sem_info->forward_progress)
            {
                continue;
            }
            if (seen_waits.insert(sem_info->handle).second)
            {
                wait_sems.push_back(sem_info->handle);
                wait_stages.push_back(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
                GFXRECON_LOG_INFO("Loop boundary dummy wait for binary semaphore %llu", (unsigned long long)sem_id);
            }
        }
    }

    std::unordered_set<VkSemaphore> seen_signals;
    std::vector<VkSemaphore>        signal_sems;
    for (format::HandleId sem_id : loop_external_waited_semaphores_)
    {
        if (loop_pending_signaled_semaphores_.contains(sem_id))
        {
            continue;
        }
        const VulkanSemaphoreInfo* sem_info = table.GetVkSemaphoreInfo(sem_id);
        if (sem_info != nullptr && sem_info->handle != VK_NULL_HANDLE)
        {
            if (IsShadowSemaphore(sem_info->handle) || !sem_info->forward_progress)
            {
                continue;
            }
            if (!seen_waits.contains(sem_info->handle) && seen_signals.insert(sem_info->handle).second)
            {
                signal_sems.push_back(sem_info->handle);
                GFXRECON_LOG_INFO("Loop boundary dummy signal for binary semaphore %llu", (unsigned long long)sem_id);
            }
        }
    }

    if (!wait_sems.empty() || !signal_sems.empty())
    {
        VkSubmitInfo submit       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit.waitSemaphoreCount = static_cast<uint32_t>(wait_sems.size());
        submit.pWaitSemaphores    = wait_sems.data();
        submit.pWaitDstStageMask  = wait_stages.data();
        if (boundary_cb != VK_NULL_HANDLE)
        {
            submit.commandBufferCount = 1;
            submit.pCommandBuffers    = &boundary_cb;
        }
        submit.signalSemaphoreCount = static_cast<uint32_t>(signal_sems.size());
        submit.pSignalSemaphores    = signal_sems.data();

        device_table->QueueSubmit(active_queue_info_->handle, 1, &submit, VK_NULL_HANDLE);
        device_table->QueueWaitIdle(active_queue_info_->handle);
    }

    if (boundary_cb != VK_NULL_HANDLE)
    {
        device_table->FreeCommandBuffers(active_device_, restoration_command_pool_, 1, &boundary_cb);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*                   pSemaphore)
{
    VulkanReplayConsumer::Process_vkCreateSemaphore(
        call_info, returnValue, device, pCreateInfo, pAllocator, pSemaphore);

    if (pSemaphore != nullptr && !pSemaphore->IsNull() && pCreateInfo != nullptr &&
        pCreateInfo->GetMetaStructPointer() != nullptr)
    {
        format::HandleId handle      = *pSemaphore->GetPointer();
        auto             create_info = pCreateInfo->GetMetaStructPointer();
        auto             type_info   = const_cast<Decoded_VkSemaphoreTypeCreateInfo*>(
            GetPNextMetaStruct<Decoded_VkSemaphoreTypeCreateInfo>(create_info->pNext));
        if (type_info != nullptr && type_info->decoded_value != nullptr &&
            type_info->decoded_value->semaphoreType == VK_SEMAPHORE_TYPE_TIMELINE)
        {
            timeline_semaphores_.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireNextImageKHR(const ApiCallInfo&        call_info,
                                                                  VkResult                  returnValue,
                                                                  format::HandleId          device,
                                                                  format::HandleId          swapchain,
                                                                  uint64_t                  timeout,
                                                                  format::HandleId          semaphore,
                                                                  format::HandleId          fence,
                                                                  PointerDecoder<uint32_t>* pImageIndex)
{
    VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
        call_info, returnValue, device, swapchain, timeout, semaphore, fence, pImageIndex);
    if (semaphore != format::kNullHandleId)
    {
        loop_acquire_semaphores_.insert(semaphore);
        if (IsLoopFirstIteration())
        {
            loop_pending_signaled_semaphores_.insert(semaphore);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                                       call_info,
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                pImageIndex)
{
    VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(call_info, returnValue, device, pAcquireInfo, pImageIndex);
    if (pAcquireInfo != nullptr && pAcquireInfo->GetMetaStructPointer() != nullptr)
    {
        format::HandleId semaphore = pAcquireInfo->GetMetaStructPointer()->semaphore;
        if (semaphore != format::kNullHandleId)
        {
            loop_acquire_semaphores_.insert(semaphore);
            if (IsLoopFirstIteration())
            {
                loop_pending_signaled_semaphores_.insert(semaphore);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
