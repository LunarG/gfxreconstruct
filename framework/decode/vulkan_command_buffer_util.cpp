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
#include "decode/vulkan_command_buffer_util.h"
#include "decode/vulkan_submit_info_helper.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/callbacks.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanCommandBufferAssociatedInfo::VulkanCommandBufferAssociatedInfo(
    const VulkanDeviceInfo*                    device_info,
    const graphics::VulkanInjectedDeviceCalls& device_table,
    CommonObjectInfoTable*                     object_table,
    format::HandleId                           command_buffer_id) :
    device_info_(device_info),
    device_table_(device_table), object_table_(object_table), split_semaphore_(device_info, device_table)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(object_table != nullptr);

    // Store the original command buffer handle and map it to the command buffer ID for future reference.
    VulkanCommandBufferInfo* command_buffer_info = object_table_->GetVkCommandBufferInfo(command_buffer_id);
    GFXRECON_ASSERT(command_buffer_info != nullptr);
    original_handle_ = command_buffer_info->handle;
}

void VulkanCommandBufferAssociatedInfo::ReplaceWithNewHandle(VulkanCommandBufferInfo* command_buffer_info)
{
    VkCommandBuffer next_handle = VK_NULL_HANDLE;

    // Create a new handle if there are none to reuse.
    if (next_associated_index_ >= associated_handles_.size())
    {
        VulkanCommandPoolInfo* pool_info = object_table_->GetVkCommandPoolInfo(command_buffer_info->pool_id);

        const VulkanDeviceInfo* device_info = object_table_->GetVkDeviceInfo(command_buffer_info->parent_id);
        GFXRECON_ASSERT(device_info == device_info_);

        constexpr size_t NEW_COMMAND_BUFFER_COUNT = 8;
        const size_t     previous_size            = associated_handles_.size();
        associated_handles_.resize(previous_size + NEW_COMMAND_BUFFER_COUNT);
        VkCommandBuffer* new_handles_ptr = associated_handles_.data() + previous_size;

        // Create a bunch of new handles for the split.
        VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        alloc_info.commandPool                 = pool_info->handle;
        alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandBufferCount          = NEW_COMMAND_BUFFER_COUNT;

        auto     injected = device_table_.Open();
        VkResult result   = injected->AllocateCommandBuffers(device_info_->handle, &alloc_info, new_handles_ptr);
        GFXRECON_ASSERT(result == VK_SUCCESS);
    }

    next_handle = associated_handles_[next_associated_index_];
    ++next_associated_index_;

    command_buffer_info->handle = next_handle;
}

VulkanCommandBufferUtil::VulkanCommandBufferUtil(const VulkanDeviceInfo*                    device_info,
                                                 const graphics::VulkanInjectedDeviceCalls& device_table,
                                                 CommonObjectInfoTable*                     object_table,
                                                 VulkanStateRecordingDecoder*               decoder) :
    device_info_(device_info),
    device_table_(device_table), object_table_(object_table), decoder_(decoder)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(object_table != nullptr);
}

VulkanCommandBufferAssociatedInfo&
VulkanCommandBufferUtil::GetOrCreateAssociatedInfo(format::HandleId command_buffer_id)
{
    if (auto it = split_infos_.find(command_buffer_id); it != split_infos_.end())
    {
        return it->second;
    }

    auto [new_it, success] = split_infos_.insert(
        { command_buffer_id,
          VulkanCommandBufferAssociatedInfo(device_info_, device_table_, object_table_, command_buffer_id) });
    GFXRECON_ASSERT(success);
    return new_it->second;
}

VulkanCommandBufferAssociatedInfo* VulkanCommandBufferUtil::GetAssociatedInfo(format::HandleId command_buffer_id)
{
    if (auto it = split_infos_.find(command_buffer_id); it != split_infos_.end())
    {
        return &it->second;
    }
    return nullptr;
}

VkCommandBuffer VulkanCommandBufferAssociatedInfo::ResetAssociatedHandles()
{
    // Reset all the associated command buffers.
    for (VkCommandBuffer handle : associated_handles_)
    {
        auto     injected = device_table_.Open();
        VkResult result   = injected->ResetCommandBuffer(handle, 0);
        GFXRECON_ASSERT(result == VK_SUCCESS);
    }

    // Clear the split handles vector and reset the index.
    split_handles_.clear();
    next_associated_index_ = 0;

    return original_handle_;
}

VkCommandBuffer VulkanCommandBufferAssociatedInfo::FreeAssociatedHandles(VkCommandPool pool)
{
    GFXRECON_ASSERT(!associated_handles_.empty());

    auto injected = device_table_.Open();
    injected->FreeCommandBuffers(
        device_info_->handle, pool, static_cast<uint32_t>(associated_handles_.size()), associated_handles_.data());

    associated_handles_.clear();
    split_handles_.clear();
    next_associated_index_ = 0;

    return original_handle_;
}

void VulkanCommandBufferUtil::ReplaceWithAssociatedCommandBuffer(VulkanCommandBufferInfo* command_buffer_info)
{
    // Make sure current handle is mapped to the original command buffer ID.
    original_command_buffer_id_[command_buffer_info->handle] = command_buffer_info->capture_id;

    // Update the command buffer info to use the new handle for subsequent calls.
    GetOrCreateAssociatedInfo(command_buffer_info->capture_id).ReplaceWithNewHandle(command_buffer_info);

    // Map the new handle to the original command buffer ID for future reference.
    original_command_buffer_id_[command_buffer_info->handle] = command_buffer_info->capture_id;

    // Reset the command buffer just in case it was recycled.
    auto     injected = device_table_.Open();
    VkResult result   = injected->ResetCommandBuffer(command_buffer_info->handle, 0);
    GFXRECON_ASSERT(result == VK_SUCCESS);
}

void VulkanCommandBufferUtil::SplitCommandBuffer(VulkanCommandBufferInfo* command_buffer_info)
{
    if (reissuing_command_buffer_state_ == true)
    {
        return;
    }

    auto injected = device_table_.Open();
    injected->EndCommandBuffer(command_buffer_info->handle);

    GetOrCreateAssociatedInfo(command_buffer_info->capture_id).PushSplitHandle(command_buffer_info->handle);
    ReplaceWithAssociatedCommandBuffer(command_buffer_info);

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    injected->BeginCommandBuffer(command_buffer_info->handle, &begin_info);
    auto reinstate_cb_scope =
        device_table_.Label(injected, command_buffer_info->handle, "Restore command buffer's state");

    reissuing_command_buffer_state_ = true;
    decoder_->ReissueCommandBufferState(command_buffer_info->capture_id);
    reissuing_command_buffer_state_ = false;
}

graphics::VulkanSemaphore
VulkanCommandBufferUtil::SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*        queue_info,
                                                             const std::span<VkSubmitInfo> current_submits_span,
                                                             const std::span<graphics::VulkanSemaphore> wait_semaphores)
{
    auto submits_command_buffers = GetCommandBuffersFromSubmitInfos(current_submits_span);
    return SubmitPreviouslySplitCommandBuffers(queue_info, submits_command_buffers, wait_semaphores);
}

graphics::VulkanSemaphore
VulkanCommandBufferUtil::SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*         queue_info,
                                                             const std::span<VkSubmitInfo2> current_submits_span,
                                                             const std::span<graphics::VulkanSemaphore> wait_semaphores)
{
    auto submits_command_buffers = GetCommandBuffersFromSubmitInfos(current_submits_span);
    return SubmitPreviouslySplitCommandBuffers(queue_info, submits_command_buffers, wait_semaphores);
}

graphics::VulkanSemaphore VulkanCommandBufferUtil::SubmitPreviouslySplitCommandBuffers(
    const VulkanQueueInfo*                        queue_info,
    const std::span<std::vector<VkCommandBuffer>> current_submits_cmdbufs,
    const std::span<graphics::VulkanSemaphore>    wait_semaphores)
{
    auto injected = device_table_.Open();

    graphics::VulkanSemaphore signal_semaphore{ VK_NULL_HANDLE, 0 };

    // A QueueSubmit might have multiple submit infos (current_submits_span).
    // Each submit info might have multiple command buffers.
    // We check those command buffers, to see if any of them were split from the original command buffer.

    std::vector<VkSubmitInfo>                 prev_submits;
    std::vector<std::vector<VkCommandBuffer>> prev_submits_command_buffers;

    for (size_t span_index = 0; span_index < current_submits_cmdbufs.size(); ++span_index)
    {
        const auto& command_buffers = current_submits_cmdbufs[span_index];

        for (uint32_t cmdbuf_index = 0; cmdbuf_index < command_buffers.size(); ++cmdbuf_index)
        {
            VkCommandBuffer command_buffer = command_buffers[cmdbuf_index];
            if (original_command_buffer_id_.contains(command_buffer))
            {
                // The command buffer in this submit has associated command buffers.
                auto command_buffer_id = original_command_buffer_id_[command_buffer];

                const VulkanCommandBufferAssociatedInfo* split_info = GetAssociatedInfo(command_buffer_id);

                // Each command buffer handle created for a split will go in its own submit.
                auto& split_handles = split_info->GetSplitHandles();

                // There might cases where associated command buffers have been created, but not for a split.
                if (!split_handles.empty())
                {
                    // Make enough space for the new submits.
                    size_t submit_count = std::max(prev_submits.size(), split_handles.size());
                    prev_submits.resize(submit_count);
                    prev_submits_command_buffers.resize(submit_count);

                    // We need to submit the previous splits before submitting this one.
                    // Store each handle in the corresponding submit.
                    for (size_t split_index = 0; split_index < split_handles.size(); ++split_index)
                    {
                        auto& prev_command_buffers = prev_submits_command_buffers[split_index];
                        // Prev submits command buffers correspond to the previous handles in order.
                        prev_command_buffers.push_back(split_handles[split_index]);
                    }
                }
            }
        }
    }

    // Each submit will go in its own QueueSubmit.
    for (size_t i = 0; i < prev_submits.size(); ++i)
    {
        auto& prev_command_buffers = prev_submits_command_buffers[i];

        if (!prev_command_buffers.empty())
        {
            format::HandleId                   command_buffer_id = original_command_buffer_id_[prev_command_buffers[0]];
            VulkanCommandBufferAssociatedInfo* split_info        = GetAssociatedInfo(command_buffer_id);

            VkSubmitInfo           submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            VulkanSubmitInfoHelper submit_helper(submit_info);

            // External waits should gate only the first segment, the split semaphore will order the rest.
            if (i == 0)
            {
                for (auto& wait_semaphore : wait_semaphores)
                {
                    submit_helper.AddWaitSemaphore(wait_semaphore);
                }
            }

            submit_info.commandBufferCount = static_cast<uint32_t>(prev_command_buffers.size());
            submit_info.pCommandBuffers    = prev_command_buffers.data();

            VulkanInjectedSemaphore& split_semaphore = split_info->GetSplitSemaphore();
            submit_helper.InjectSemaphore(split_semaphore);
            if (i == prev_submits.size() - 1)
            {
                signal_semaphore = split_semaphore.GetSemaphore();
            }

            prev_submits[i] = submit_info;

            VkResult result = injected->QueueSubmit(queue_info->handle, 1, &prev_submits[i], VK_NULL_HANDLE);
            GFXRECON_ASSERT(result == VK_SUCCESS);
        }
    }

    return signal_semaphore;
}

std::vector<std::vector<VkCommandBuffer>>
VulkanCommandBufferUtil::GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo> submits_span)
{
    std::vector<std::vector<VkCommandBuffer>> submits_command_buffers(submits_span.size());

    for (size_t span_index = 0; span_index < submits_span.size(); ++span_index)
    {
        VkSubmitInfo& submit_info = submits_span[span_index];

        auto& command_buffers = submits_command_buffers[span_index];
        command_buffers       = std::vector<VkCommandBuffer>(submit_info.pCommandBuffers,
                                                       submit_info.pCommandBuffers + submit_info.commandBufferCount);
    }

    return submits_command_buffers;
}

std::vector<std::vector<VkCommandBuffer>>
VulkanCommandBufferUtil::GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo2> submits_span)
{
    std::vector<std::vector<VkCommandBuffer>> submits_command_buffers(submits_span.size());

    for (size_t span_index = 0; span_index < submits_span.size(); ++span_index)
    {
        VkSubmitInfo2& submit_info = submits_span[span_index];

        for (size_t cmdbuf_info_index = 0; cmdbuf_info_index < submit_info.commandBufferInfoCount; ++cmdbuf_info_index)
        {
            const VkCommandBufferSubmitInfo& info           = submit_info.pCommandBufferInfos[cmdbuf_info_index];
            VkCommandBuffer                  command_buffer = info.commandBuffer;
            submits_command_buffers[span_index].push_back(command_buffer);
        }
    }

    return submits_command_buffers;
}

void VulkanCommandBufferUtil::FreeCommandBuffers(VkCommandPool                           command_pool,
                                                 const std::span<const format::HandleId> command_buffer_ids)
{
    // Check whether any of the command buffers being freed are split command buffers.
    for (format::HandleId command_buffer_id : command_buffer_ids)
    {
        // Make sure to clear the recorded state for this command buffer.
        decoder_->ClearRecordedState(command_buffer_id);

        auto* split_info = GetAssociatedInfo(command_buffer_id);
        if (split_info != nullptr)
        {
            // Remove the associated handles from the tracking maps.
            for (VkCommandBuffer handle : split_info->GetAssociatedHandles())
            {
                original_command_buffer_id_.erase(handle);
            }

            // Update the command buffer info to use the original handle for subsequent calls.
            VulkanCommandBufferInfo* command_buffer_info = object_table_->GetVkCommandBufferInfo(command_buffer_id);
            command_buffer_info->handle                  = split_info->FreeAssociatedHandles(command_pool);

            split_infos_.erase(command_buffer_id);
        }
    }
}

void VulkanCommandBufferUtil::ResetCommandBuffer(VulkanCommandBufferInfo* command_buffer_info)
{
    // The recorded state does not survive a reset.
    decoder_->ClearRecordedState(command_buffer_info->capture_id);

    // This command buffer is expected to be already reset at this point.
    VkCommandBuffer command_buffer = command_buffer_info->handle;

    // Check whether this command buffer is result of a split.
    // If so, we need to reset all the split command buffers together and restore the command buffer info handle.
    if (original_command_buffer_id_.contains(command_buffer))
    {
        format::HandleId                   command_buffer_id = original_command_buffer_id_[command_buffer];
        VulkanCommandBufferAssociatedInfo* split_info        = GetAssociatedInfo(command_buffer_id);

        // Update the command buffer info to use the original handle for subsequent calls.
        command_buffer_info->handle = split_info->ResetAssociatedHandles();
    }
}

void VulkanCommandBufferUtil::BeginCommandBuffer(VulkanCommandBufferInfo* command_buffer_info)
{
    // A new recording invalidates the state commands recorded for the previous one.
    decoder_->ClearRecordedState(command_buffer_info->capture_id);

    VulkanCommandPoolInfo* command_pool_info = object_table_->GetVkCommandPoolInfo(command_buffer_info->pool_id);
    GFXRECON_ASSERT(command_pool_info != nullptr);

    if (command_pool_info->create_flags & VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT)
    {
        // If the command pool was created with the RESET_COMMAND_BUFFER_BIT flag, then the command buffer is implicitly
        // reset when vkBeginCommandBuffer is called. In this case, we need to reset all the split command buffers
        // together and restore the command buffer info handle.
        if (original_command_buffer_id_.contains(command_buffer_info->handle))
        {
            // Reset current handle and let `ResetCommandBuffer` handle the rest of the split handles.
            auto injected = device_table_.Open();
            injected->ResetCommandBuffer(command_buffer_info->handle, 0);
            ResetCommandBuffer(command_buffer_info);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
