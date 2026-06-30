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
} // namespace

VulkanReplayFrameLoopConsumer::~VulkanReplayFrameLoopConsumer()
{
    if (restoration_command_pool_ != VK_NULL_HANDLE && restoration_device_ != VK_NULL_HANDLE)
    {
        const graphics::VulkanDeviceTable* dev_table = GetDeviceTable(restoration_device_);
        if (dev_table)
        {
            dev_table->DestroyCommandPool(restoration_device_, restoration_command_pool_, nullptr);
        }
    }
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
    RecordInitialLayouts();

    loop_start_recording_cbs_ = recording_cbs_;
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

void VulkanReplayFrameLoopConsumer::CaptureInitialFenceStates()
{
    GFXRECON_LOG_DEBUG("VulkanReplayFrameLoopConsumer::CaptureInitialFenceStates: Capturing initial fence states...");
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
                    GFXRECON_LOG_DEBUG("  Fence %" PRIu64 " (handle %" PRIu64 ") initial state: %s",
                                       fence_info->capture_id,
                                       (uint64_t)fence_info->handle,
                                       status == VK_SUCCESS ? "SIGNALED"
                                                            : (status == VK_NOT_READY ? "UNSIGNALED" : "ERROR"));
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

    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);

    PropagateImageLayoutsFromSubmit(pSubmits);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                                           VkResult                                     returnValue,
                                                           format::HandleId                             queue,
                                                           uint32_t                                     submitCount,
                                                           StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                           format::HandleId                             fence)
{
    TrackSubmittedCommandBuffers(pSubmits);

    VulkanReplayConsumer::Process_vkQueueSubmit2(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);

    PropagateImageLayoutsFromSubmit(pSubmits);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                                              VkResult                                     returnValue,
                                                              format::HandleId                             queue,
                                                              uint32_t                                     submitCount,
                                                              StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                              format::HandleId                             fence)
{
    TrackSubmittedCommandBuffers(pSubmits);

    VulkanReplayConsumer::Process_vkQueueSubmit2KHR(call_info, returnValue, queue, submitCount, pSubmits, fence);

    UpdateActiveQueueInfo(queue);

    PropagateImageLayoutsFromSubmit(pSubmits);
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
void VulkanReplayFrameLoopConsumer::PropagateImageLayoutsFromSubmit(StructPointerDecoder<T>* pSubmits)
{
    if (pSubmits != nullptr && pSubmits->GetMetaStructPointer() != nullptr)
    {
        uint32_t submit_count = pSubmits->GetLength();
        auto     submits      = pSubmits->GetMetaStructPointer();
        for (uint32_t i = 0; i < submit_count; ++i)
        {
            PropagateImageLayouts(submits[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::PropagateImageLayouts(const Decoded_VkSubmitInfo& submit)
{
    uint32_t cb_count = submit.pCommandBuffers.GetLength();
    auto     cbs      = submit.pCommandBuffers.GetPointer();
    if (cbs != nullptr)
    {
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            auto command_buffer_info = GetObjectInfoTable().GetVkCommandBufferInfo(cbs[j]);
            if (command_buffer_info != nullptr)
            {
                for (auto image_layout : command_buffer_info->image_layout_barriers)
                {
                    auto image_info = GetObjectInfoTable().GetVkImageInfo(image_layout.first);
                    if (image_info != nullptr)
                    {
                        image_info->current_layout = image_layout.second;
                    }
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::PropagateImageLayouts(const Decoded_VkSubmitInfo2& submit)
{
    if (submit.pCommandBufferInfos != nullptr && submit.pCommandBufferInfos->GetMetaStructPointer() != nullptr)
    {
        uint32_t cb_count = submit.pCommandBufferInfos->GetLength();
        auto     cb_infos = submit.pCommandBufferInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < cb_count; ++j)
        {
            auto command_buffer_info = GetObjectInfoTable().GetVkCommandBufferInfo(cb_infos[j].commandBuffer);
            if (command_buffer_info != nullptr)
            {
                for (auto image_layout : command_buffer_info->image_layout_barriers)
                {
                    auto image_info = GetObjectInfoTable().GetVkImageInfo(image_layout.first);
                    if (image_info != nullptr)
                    {
                        image_info->current_layout = image_layout.second;
                    }
                }
            }
        }
    }
}

template void VulkanReplayFrameLoopConsumer::PropagateImageLayoutsFromSubmit<Decoded_VkSubmitInfo>(
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits);
template void VulkanReplayFrameLoopConsumer::PropagateImageLayoutsFromSubmit<Decoded_VkSubmitInfo2>(
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits);

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

    UpdateActiveQueueInfo(queue);

    if (IsLoopAnyIteration() && active_queue_info_ != nullptr)
    {
        if (!ShouldUseFrameMarkers())
        {
            ResetLoopBoundary();
        }
    }

    frame_number_++;
}

void VulkanReplayFrameLoopConsumer::ProcessFrameEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessFrameEndMarker(frame_number);

    if (IsLoopAnyIteration())
    {
        GFXRECON_LOG_DEBUG("ProcessFrameEndMarker: FrameEndMarker received for frame %" PRIu64, frame_number);

        if (ShouldUseFrameMarkers())
        {
            ResetLoopBoundary();
        }
    }
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

    VulkanReplayFrameLoopConsumerBase::Process_vkAllocateCommandBuffers(
        call_info, returnValue, device, pAllocateInfo, pCommandBuffers);

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

    VulkanReplayFrameLoopConsumerBase::Process_vkFreeCommandBuffers(
        call_info, device, commandPool, commandBufferCount, pCommandBuffers);
}

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
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
    VulkanReplayConsumer::Process_vkEndCommandBuffer(call_info, returnValue, commandBuffer);

    recording_cbs_.erase(commandBuffer);

    if (IsLoopFirstIteration())
    {
        loop_ended_cbs_.insert(commandBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     commandBuffer,
    VkPipelineStageFlags                                 srcStageMask,
    VkPipelineStageFlags                                 dstStageMask,
    VkDependencyFlags                                    dependencyFlags,
    uint32_t                                             memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                             bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                             imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{
    auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    // On-The-Fly Layout Barrier Fixer: patch trace oldLayout to match actual layout before this barrier
    if (pImageMemoryBarriers != nullptr && pImageMemoryBarriers->GetMetaStructPointer() != nullptr &&
        cb_info != nullptr)
    {
        uint32_t barrier_count = pImageMemoryBarriers->GetLength();
        auto     barriers      = pImageMemoryBarriers->GetMetaStructPointer();
        for (uint32_t i = 0; i < barrier_count; ++i)
        {
            format::HandleId image_id   = barriers[i].image;
            auto             image_info = GetObjectInfoTable().GetVkImageInfo(image_id);
            if (image_info != nullptr && barriers[i].decoded_value != nullptr)
            {
                // Local-aware layout lookup!
                VkImageLayout actual_layout = image_info->current_layout;
                auto          it            = cb_info->image_layout_barriers.find(image_id);
                if (it != cb_info->image_layout_barriers.end())
                {
                    actual_layout = it->second;
                }

                VkImageLayout trace_old_layout = barriers[i].decoded_value->oldLayout;

                // If trace oldLayout mismatch with actual, and it's not UNDEFINED, surgically patch it!
                if (IsLoopAnyIteration() && trace_old_layout != actual_layout &&
                    trace_old_layout != VK_IMAGE_LAYOUT_UNDEFINED)
                {
                    barriers[i].decoded_value->oldLayout = actual_layout;
                }

                // Update both local and global trackers immediately during recording to propagate layouts across
                // command buffers!
                cb_info->image_layout_barriers[image_id] = barriers[i].decoded_value->newLayout;
                if (IsLoopAnyIteration())
                {
                    image_info->current_layout = barriers[i].decoded_value->newLayout;
                }
            }
        }
    }

    VulkanReplayConsumer::Process_vkCmdPipelineBarrier(call_info,
                                                       commandBuffer,
                                                       srcStageMask,
                                                       dstStageMask,
                                                       dependencyFlags,
                                                       memoryBarrierCount,
                                                       pMemoryBarriers,
                                                       bufferMemoryBarrierCount,
                                                       pBufferMemoryBarriers,
                                                       imageMemoryBarrierCount,
                                                       pImageMemoryBarriers);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                                  call_info,
    format::HandleId                                    commandBuffer,
    VkPipelineBindPoint                                 pipelineBindPoint,
    format::HandleId                                    layout,
    uint32_t                                            set,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    // Patch layouts in pDescriptorWrites if needed before mapping handles!
    VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites->GetPointer();
    if (in_pDescriptorWrites != nullptr)
    {
        GFXRECON_LOG_DEBUG(
            "Process_vkCmdPushDescriptorSetKHR: CB=%" PRIu64 ", write_count=%d", commandBuffer, descriptorWriteCount);
        for (uint32_t s = 0; s < descriptorWriteCount; ++s)
        {
            VkWriteDescriptorSet& write = in_pDescriptorWrites[s];
            GFXRECON_LOG_DEBUG("  write[%d]: type=%d, count=%d", s, write.descriptorType, write.descriptorCount);
            if (write.descriptorType == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE ||
                write.descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                write.descriptorType == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT)
            {
                const auto* write_meta = pDescriptorWrites->GetMetaStructPointer();
                GFXRECON_LOG_DEBUG("    matching type: write_meta=%p, pImageInfo=%p",
                                   write_meta,
                                   write_meta ? write_meta[s].pImageInfo : nullptr);
                if (write_meta != nullptr && write_meta[s].pImageInfo != nullptr)
                {
                    const auto* image_info_meta = write_meta[s].pImageInfo->GetMetaStructPointer();
                    for (uint32_t i = 0; i < write.descriptorCount; ++i)
                    {
                        format::HandleId image_view_id = image_info_meta[i].imageView;
                        PatchImageDescriptor(const_cast<VkDescriptorImageInfo*>(write.pImageInfo)[i],
                                             image_view_id,
                                             write.descriptorType);
                    }
                }
            }
        }
    }

    // Delegate to base class to map handles and call the driver!
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
        call_info, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                              call_info,
    format::HandleId                                commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FixAndLogPipelineBarrier2(commandBuffer, pDependencyInfo);
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(call_info, commandBuffer, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                              call_info,
    format::HandleId                                commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    FixAndLogPipelineBarrier2(commandBuffer, pDependencyInfo);
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(call_info, commandBuffer, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumer::FixAndLogPipelineBarrier2(
    format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    if (pDependencyInfo != nullptr && pDependencyInfo->GetMetaStructPointer() != nullptr && cb_info != nullptr)
    {
        auto dependency_info = pDependencyInfo->GetMetaStructPointer();
        if (dependency_info->pImageMemoryBarriers != nullptr &&
            dependency_info->pImageMemoryBarriers->GetMetaStructPointer() != nullptr)
        {
            uint32_t barrier_count = dependency_info->pImageMemoryBarriers->GetLength();
            auto     barriers      = dependency_info->pImageMemoryBarriers->GetMetaStructPointer();
            for (uint32_t i = 0; i < barrier_count; ++i)
            {
                format::HandleId image_id   = barriers[i].image;
                auto             image_info = GetObjectInfoTable().GetVkImageInfo(image_id);
                if (image_info != nullptr && barriers[i].decoded_value != nullptr)
                {
                    // Local-aware layout lookup!
                    VkImageLayout actual_layout = image_info->current_layout;
                    auto          it            = cb_info->image_layout_barriers.find(image_id);
                    if (it != cb_info->image_layout_barriers.end())
                    {
                        actual_layout = it->second;
                    }

                    VkImageLayout trace_old_layout = barriers[i].decoded_value->oldLayout;

                    // If trace oldLayout mismatch with actual, and it's not UNDEFINED, surgically patch it!
                    if (IsLoopAnyIteration() && trace_old_layout != actual_layout &&
                        trace_old_layout != VK_IMAGE_LAYOUT_UNDEFINED)
                    {
                        barriers[i].decoded_value->oldLayout = actual_layout;
                    }

                    // Update both local and global trackers immediately during recording to propagate layouts
                    // across command buffers!
                    cb_info->image_layout_barriers[image_id] = barriers[i].decoded_value->newLayout;
                    if (IsLoopAnyIteration())
                    {
                        image_info->current_layout = barriers[i].decoded_value->newLayout;
                    }
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWriteTimestamp(const ApiCallInfo&      call_info,
                                                                format::HandleId        commandBuffer,
                                                                VkPipelineStageFlagBits pipelineStage,
                                                                format::HandleId        queryPool,
                                                                uint32_t                query)
{
    // Unconditionally skip query commands during looping to avoid any "query not reset" validation errors,
    // especially for static command buffers recorded outside the loop but submitted inside it.
    return;
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginQuery(const ApiCallInfo&  call_info,
                                                            format::HandleId    commandBuffer,
                                                            format::HandleId    queryPool,
                                                            uint32_t            query,
                                                            VkQueryControlFlags flags)
{
    // Unconditionally skip query commands during looping to avoid any "query not reset" validation errors
    return;
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdEndQuery(const ApiCallInfo& call_info,
                                                          format::HandleId   commandBuffer,
                                                          format::HandleId   queryPool,
                                                          uint32_t           query)
{
    // Unconditionally skip query commands during looping to avoid any "query not reset" validation errors
    return;
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdResetQueryPool(const ApiCallInfo& call_info,
                                                                format::HandleId   commandBuffer,
                                                                format::HandleId   queryPool,
                                                                uint32_t           firstQuery,
                                                                uint32_t           queryCount)
{
    // Unconditionally skip query commands during looping to avoid any "query not reset" validation errors
    return;
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

    frame_number_++;
    if (frame_loop_info_.IsEnteringLoopFrame(frame_number_))
    {
        RecordInitialLayouts();
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
    GetObjectInfoTable().VisitVkImageInfo([this](const VulkanImageInfo* info) {
        if (info != nullptr && info->handle != VK_NULL_HANDLE)
        {
            initial_image_layouts_[info->capture_id] = info->current_layout;
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
        restoration_command_pool_ = VK_NULL_HANDLE;
        restoration_device_       = VK_NULL_HANDLE;
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

        VkResult wait_result = active_device_table_->DeviceWaitIdle(active_device_);
        CHECK_VK_RESULT(wait_result, "vkDeviceWaitIdle");

        // Restore image layouts at the loop boundary
        RestoreImageLayouts(active_device_, active_device_table_, active_queue_info_);

        // Classify command pools once at the end of the first iteration
        ClassifyActiveCommandPools();

        // Reset active command pools at the loop boundary
        ResetActiveCommandPools();

        FixupDeviceFences(active_queue_info_->parent_id, active_queue_id_);
    }
    else
    {
        GFXRECON_LOG_WARNING("ResetLoopBoundary: Missing active queue info, cannot reset loop boundary!");
    }
}

void VulkanReplayFrameLoopConsumer::RestoreImageLayouts(VkDevice                           device,
                                                        const graphics::VulkanDeviceTable* device_table,
                                                        VulkanQueueInfo*                   queue_info)
{
    std::vector<VkImageMemoryBarrier> barriers;

    GetObjectInfoTable().VisitVkImageInfo([this, &barriers](const VulkanImageInfo* info) {
        if (info == nullptr || info->handle == VK_NULL_HANDLE)
        {
            return;
        }

        VkImageLayout target_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        auto          it            = initial_image_layouts_.find(info->capture_id);
        if (it != initial_image_layouts_.end())
        {
            target_layout = it->second;
        }
        else
        {
            target_layout = info->initial_layout;
        }

        if (target_layout == VK_IMAGE_LAYOUT_UNDEFINED || target_layout == VK_IMAGE_LAYOUT_PREINITIALIZED)
        {
            return;
        }

        if (info->current_layout != target_layout)
        {
            VkImageMemoryBarrier barrier = {};
            barrier.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barrier.oldLayout            = info->current_layout;
            barrier.newLayout            = target_layout;
            barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
            barrier.image                = info->handle;

            barrier.subresourceRange.aspectMask     = GetAspectMask(info->format);
            barrier.subresourceRange.baseMipLevel   = 0;
            barrier.subresourceRange.levelCount     = info->level_count;
            barrier.subresourceRange.baseArrayLayer = 0;
            barrier.subresourceRange.layerCount     = info->layer_count;

            barrier.srcAccessMask = GetAccessFlags(info->current_layout);
            barrier.dstAccessMask = GetAccessFlags(target_layout);

            barriers.push_back(barrier);

            auto mutable_info            = const_cast<VulkanImageInfo*>(info);
            mutable_info->current_layout = target_layout;
        }
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

void VulkanReplayFrameLoopConsumer::ClassifyActiveCommandPools()
{
    // 1. Classify loop state once at the boundary of the 1st play
    if (IsLoopFirstIteration() && !loop_state_classified_)
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

                        if (is_restorable)
                        {
                            cbs_to_recreate_with_rebegin_.push_back(cb_info->capture_id);
                        }
                        else if (is_recorded_in_loop)
                        {
                            cbs_to_recreate_without_rebegin_.push_back(cb_info->capture_id);
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

bool VulkanReplayFrameLoopConsumer::IsIncompatibleSampledImageLayout(VkImageLayout layout)
{
    return layout == VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL ||
           layout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdExecuteCommands(const ApiCallInfo& call_info,
                                                                 format::HandleId   commandBuffer,
                                                                 uint32_t           commandBufferCount,
                                                                 HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    VulkanReplayConsumer::Process_vkCmdExecuteCommands(call_info, commandBuffer, commandBufferCount, pCommandBuffers);

    auto primary_cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);
    if (primary_cb_info != nullptr && pCommandBuffers != nullptr)
    {
        const auto secondary_handles = pCommandBuffers->GetHandlePointer();
        const auto secondary_ids     = pCommandBuffers->GetPointer();
        if (secondary_handles != nullptr && secondary_ids != nullptr)
        {
            for (uint32_t i = 0; i < commandBufferCount; ++i)
            {
                auto secondary_cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(secondary_ids[i]);
                if (secondary_cb_info != nullptr)
                {
                    for (const auto& barrier : secondary_cb_info->image_layout_barriers)
                    {
                        primary_cb_info->image_layout_barriers[barrier.first] = barrier.second;
                    }
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::PropagateRenderPassFinalLayouts(format::HandleId commandBuffer)
{
    if (IsLoopAnyIteration())
    {
        auto cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);
        if (cb_info != nullptr)
        {
            const auto& attachment_image_view_ids = cb_info->active_render_pass_attachment_image_view_ids;
            auto        render_pass_info = GetObjectInfoTable().GetVkRenderPassInfo(cb_info->active_render_pass_id);
            if (render_pass_info != nullptr &&
                attachment_image_view_ids.size() == render_pass_info->attachment_description_final_layouts.size())
            {
                for (size_t i = 0; i < render_pass_info->attachment_description_final_layouts.size(); ++i)
                {
                    auto image_view_id   = attachment_image_view_ids[i];
                    auto image_view_info = GetObjectInfoTable().GetVkImageViewInfo(image_view_id);
                    if (image_view_info != nullptr)
                    {
                        VulkanImageInfo* img_info = GetObjectInfoTable().GetVkImageInfo(image_view_info->image_id);
                        if (img_info != nullptr)
                        {
                            img_info->current_layout = render_pass_info->attachment_description_final_layouts[i];
                        }
                    }
                }
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdEndRenderPass(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer)
{
    PropagateRenderPassFinalLayouts(commandBuffer);
    VulkanReplayConsumer::Process_vkCmdEndRenderPass(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    format::HandleId                                commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    PropagateRenderPassFinalLayouts(commandBuffer);
    VulkanReplayConsumer::Process_vkCmdEndRenderPass2(call_info, commandBuffer, pSubpassEndInfo);
}

void VulkanReplayFrameLoopConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                                  call_info,
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    if (pDescriptorWrites != nullptr)
    {
        VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites->GetPointer();
        const auto*           write_meta           = pDescriptorWrites->GetMetaStructPointer();
        if (in_pDescriptorWrites != nullptr && write_meta != nullptr)
        {
            for (uint32_t s = 0; s < descriptorWriteCount; ++s)
            {
                VkWriteDescriptorSet& write = in_pDescriptorWrites[s];
                if (write.descriptorType == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE ||
                    write.descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                    write.descriptorType == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT)
                {
                    if (write_meta[s].pImageInfo != nullptr)
                    {
                        const auto* image_info_meta = write_meta[s].pImageInfo->GetMetaStructPointer();
                        for (uint32_t i = 0; i < write.descriptorCount; ++i)
                        {
                            format::HandleId image_view_id = image_info_meta[i].imageView;
                            PatchImageDescriptor(const_cast<VkDescriptorImageInfo*>(write.pImageInfo)[i],
                                                 image_view_id,
                                                 write.descriptorType);
                        }
                    }
                }
            }
        }
    }

    VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
        call_info, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

void VulkanReplayFrameLoopConsumer::PatchImageDescriptor(VkDescriptorImageInfo& image_info,
                                                         format::HandleId       image_view_id,
                                                         VkDescriptorType       descriptor_type)
{
    auto image_view_info = GetObjectInfoTable().GetVkImageViewInfo(image_view_id);
    if (image_view_info != nullptr)
    {
        VkImageLayout layout = image_info.imageLayout;
        if (IsIncompatibleSampledImageLayout(layout))
        {
            image_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        }
    }
}

void VulkanReplayFrameLoopConsumer::PatchDescriptorUpdateTemplate(
    const VulkanDescriptorUpdateTemplateInfo* template_info, DescriptorUpdateTemplateDecoder* decoder)
{
    if (template_info == nullptr || decoder == nullptr)
    {
        return;
    }

    size_t                               image_info_count = 0;
    VkDescriptorImageInfo*               raw_image_infos  = decoder->GetImageInfoPointer();
    const Decoded_VkDescriptorImageInfo* img_desc_info    = decoder->GetImageInfoMetaStructPointer();

    if (raw_image_infos == nullptr || img_desc_info == nullptr)
    {
        return;
    }

    for (size_t entry_idx = 0; entry_idx < template_info->entries.size(); ++entry_idx)
    {
        const auto&            entry = template_info->entries[entry_idx];
        const VkDescriptorType type  = entry.descriptorType;
        const uint32_t         count = entry.descriptorCount;

        switch (type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            {
                for (uint32_t i = 0; i < count; ++i)
                {
                    size_t idx = image_info_count + i;
                    if (idx < decoder->GetImageInfoCount())
                    {
                        format::HandleId image_view_id = img_desc_info[idx].imageView;
                        PatchImageDescriptor(raw_image_infos[idx], image_view_id, type);
                    }
                }
                image_info_count += count;
            }
            break;

            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            {
                image_info_count += count;
            }
            break;

            default:
                break;
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                              format::HandleId   device,
                                                                              format::HandleId   descriptorSet,
                                                                              format::HandleId descriptorUpdateTemplate,
                                                                              DescriptorUpdateTemplateDecoder* pData)
{
    auto update_template_info = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);
    PatchDescriptorUpdateTemplate(update_template_info, pData);

    VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplate(
        call_info, device, descriptorSet, descriptorUpdateTemplate, pData);
}

void VulkanReplayFrameLoopConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{
    auto update_template_info = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);
    PatchDescriptorUpdateTemplate(update_template_info, pData);

    VulkanReplayConsumer::Process_vkUpdateDescriptorSetWithTemplateKHR(
        call_info, device, descriptorSet, descriptorUpdateTemplate, pData);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 commandBuffer,
    format::HandleId                 descriptorUpdateTemplate,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* pData)
{
    auto update_template_info = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);
    PatchDescriptorUpdateTemplate(update_template_info, pData);

    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetWithTemplateKHR(
        call_info, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                                                 call_info,
    format::HandleId                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfo>* pPushDescriptorSetWithTemplateInfo)
{
    if (pPushDescriptorSetWithTemplateInfo != nullptr)
    {
        auto* in_info = pPushDescriptorSetWithTemplateInfo->GetMetaStructPointer();
        if (in_info != nullptr)
        {
            auto update_template_info =
                GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(in_info->descriptorUpdateTemplate);
            PatchDescriptorUpdateTemplate(update_template_info, &in_info->pData);
        }
    }

    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
        call_info, commandBuffer, pPushDescriptorSetWithTemplateInfo);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
