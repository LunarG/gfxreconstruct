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

#include "graphics/vulkan_submit_info_util.h"
#include "graphics/vulkan_struct_deep_copy.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "util/logging.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

SubmitInfo2Translator::SubmitInfo2Translator(std::span<const VkSubmitInfo> submit_infos) :
    submit_infos_2_(submit_infos.size()), wait_semaphores_(submit_infos.size()), command_buffers_(submit_infos.size()),
    signal_semaphores_(submit_infos.size()), pnext_deep_copies_(submit_infos.size())
{
    for (size_t i = 0; i < submit_infos.size(); ++i)
    {
        const auto* timeline_semaphore_submit_info =
            graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_infos[i]);
        const auto* protected_submit_info = graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&submit_infos[i]);
        const auto* device_group_submit_info =
            graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&submit_infos[i]);

        // These pNext structures are valid on VkSubmitInfo but not on VkSubmitInfo2, and there is no field in
        // VkSubmitInfo2 to carry their information. Warn so that an unexpectedly forwarded (and invalid) struct is at
        // least diagnosable rather than silently passed to vkQueueSubmit2.
        if (graphics::vulkan_struct_get_pnext<VkD3D12FenceSubmitInfoKHR>(&submit_infos[i]) != nullptr)
        {
            GFXRECON_LOG_WARNING("VkD3D12FenceSubmitInfoKHR is not supported in the VkSubmitInfo->VkSubmitInfo2 "
                                 "translation and will be ignored.");
        }

        // If any of the structures that need translation are detected in the submit info's pNext chain then we
        // translate their information into the VkSubmitInfo2 structures and we remove them from the chain. Because we
        // interfere with the pNext chain we create a deep copy.
        VkSubmitInfo* modified_pnext_chain = nullptr;
        if (timeline_semaphore_submit_info != nullptr || protected_submit_info != nullptr ||
            device_group_submit_info != nullptr)
        {
            const size_t num_bytes = graphics::vulkan_struct_deep_copy(&submit_infos[i], 1, nullptr);
            pnext_deep_copies_[i].resize(num_bytes);
            graphics::vulkan_struct_deep_copy(&submit_infos[i], 1, pnext_deep_copies_[i].data());

            modified_pnext_chain = reinterpret_cast<VkSubmitInfo*>(pnext_deep_copies_[i].data());
        }

        // Extract timeline semaphore values and remove them from pNext chain
        std::vector<uint64_t> timeline_semaphore_wait_values(submit_infos[i].waitSemaphoreCount);
        std::vector<uint64_t> timeline_semaphore_signal_values(submit_infos[i].signalSemaphoreCount);
        if (timeline_semaphore_submit_info != nullptr)
        {
            for (uint32_t s = 0; s < std::min(submit_infos[i].waitSemaphoreCount,
                                              timeline_semaphore_submit_info->waitSemaphoreValueCount);
                 ++s)
            {
                timeline_semaphore_wait_values[s] = timeline_semaphore_submit_info->pWaitSemaphoreValues[s];
            }

            for (uint32_t s = 0; s < std::min(submit_infos[i].signalSemaphoreCount,
                                              timeline_semaphore_submit_info->signalSemaphoreValueCount);
                 ++s)
            {
                timeline_semaphore_signal_values[s] = timeline_semaphore_submit_info->pSignalSemaphoreValues[s];
            }

            GFXRECON_ASSERT(modified_pnext_chain != nullptr);
            graphics::vulkan_struct_remove_pnext<VkTimelineSemaphoreSubmitInfo>(modified_pnext_chain);
        }

        // Extract protected submission information and remove it from pNext chain
        VkSubmitFlags flags = 0;
        if (protected_submit_info != nullptr)
        {
            if (protected_submit_info->protectedSubmit == VK_TRUE)
            {
                flags = VK_SUBMIT_PROTECTED_BIT;
            }

            GFXRECON_ASSERT(modified_pnext_chain != nullptr);
            graphics::vulkan_struct_remove_pnext<VkProtectedSubmitInfo>(modified_pnext_chain);
        }

        // Extract device group indices/masks and remove the struct from the pNext chain. In VkSubmitInfo2 the
        // per-semaphore device index and per-command-buffer device mask move into the respective sub-structures.
        std::vector<uint32_t> wait_device_indices(submit_infos[i].waitSemaphoreCount);
        std::vector<uint32_t> signal_device_indices(submit_infos[i].signalSemaphoreCount);
        std::vector<uint32_t> command_buffer_device_masks(submit_infos[i].commandBufferCount);
        if (device_group_submit_info != nullptr)
        {
            for (uint32_t s = 0;
                 s < std::min(submit_infos[i].waitSemaphoreCount, device_group_submit_info->waitSemaphoreCount);
                 ++s)
            {
                wait_device_indices[s] = device_group_submit_info->pWaitSemaphoreDeviceIndices[s];
            }

            for (uint32_t s = 0;
                 s < std::min(submit_infos[i].signalSemaphoreCount, device_group_submit_info->signalSemaphoreCount);
                 ++s)
            {
                signal_device_indices[s] = device_group_submit_info->pSignalSemaphoreDeviceIndices[s];
            }

            for (uint32_t s = 0;
                 s < std::min(submit_infos[i].commandBufferCount, device_group_submit_info->commandBufferCount);
                 ++s)
            {
                command_buffer_device_masks[s] = device_group_submit_info->pCommandBufferDeviceMasks[s];
            }

            GFXRECON_ASSERT(modified_pnext_chain != nullptr);
            graphics::vulkan_struct_remove_pnext<VkDeviceGroupSubmitInfo>(modified_pnext_chain);
        }

        // Wait semaphores. The per-semaphore wait stage moves from pWaitDstStageMask into VkSemaphoreSubmitInfo.
        wait_semaphores_[i].resize(submit_infos[i].waitSemaphoreCount);
        for (uint32_t j = 0; j < submit_infos[i].waitSemaphoreCount; ++j)
        {
            wait_semaphores_[i][j] =
                VkSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO,
                                       nullptr,
                                       submit_infos[i].pWaitSemaphores[j],
                                       timeline_semaphore_wait_values[j],
                                       submit_infos[i].pWaitDstStageMask
                                           ? static_cast<VkPipelineStageFlags2>(submit_infos[i].pWaitDstStageMask[j])
                                           : VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                                       wait_device_indices[j] };
        }

        // Command buffers
        command_buffers_[i].resize(submit_infos[i].commandBufferCount);
        for (uint32_t j = 0; j < submit_infos[i].commandBufferCount; ++j)
        {
            command_buffers_[i][j] = VkCommandBufferSubmitInfo{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO,
                                                                nullptr,
                                                                submit_infos[i].pCommandBuffers[j],
                                                                command_buffer_device_masks[j] };
        }

        // Signal semaphores. A VkSubmitInfo signals once all submitted work completes, i.e. at ALL_COMMANDS.
        signal_semaphores_[i].resize(submit_infos[i].signalSemaphoreCount);
        for (uint32_t j = 0; j < submit_infos[i].signalSemaphoreCount; ++j)
        {
            signal_semaphores_[i][j] =
                VkSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, nullptr,
                                       submit_infos[i].pSignalSemaphores[j],    timeline_semaphore_signal_values[j],
                                       VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,    signal_device_indices[j] };
        }

        submit_infos_2_[i] =
            VkSubmitInfo2{ VK_STRUCTURE_TYPE_SUBMIT_INFO_2,
                           modified_pnext_chain != nullptr ? modified_pnext_chain->pNext : submit_infos[i].pNext,
                           flags,
                           static_cast<uint32_t>(wait_semaphores_[i].size()),
                           wait_semaphores_[i].size() ? wait_semaphores_[i].data() : nullptr,
                           static_cast<uint32_t>(command_buffers_[i].size()),
                           command_buffers_[i].size() ? command_buffers_[i].data() : nullptr,
                           static_cast<uint32_t>(signal_semaphores_[i].size()),
                           signal_semaphores_[i].size() ? signal_semaphores_[i].data() : nullptr };
    }
}

SubmitInfoTranslator::SubmitInfoTranslator(std::span<const VkSubmitInfo2> submit_infos_2) :
    submit_infos_(submit_infos_2.size()), wait_semaphores_(submit_infos_2.size()),
    wait_stage_masks_(submit_infos_2.size()), command_buffers_(submit_infos_2.size()),
    signal_semaphores_(submit_infos_2.size()), wait_values_(submit_infos_2.size()),
    signal_values_(submit_infos_2.size()), wait_device_indices_(submit_infos_2.size()),
    signal_device_indices_(submit_infos_2.size()), command_buffer_device_masks_(submit_infos_2.size()),
    timeline_submit_infos_(submit_infos_2.size()), device_group_submit_infos_(submit_infos_2.size()),
    protected_submit_infos_(submit_infos_2.size())
{
    for (size_t i = 0; i < submit_infos_2.size(); ++i)
    {
        const VkSubmitInfo2& submit_info_2 = submit_infos_2[i];

        wait_semaphores_[i].resize(submit_info_2.waitSemaphoreInfoCount);
        wait_stage_masks_[i].resize(submit_info_2.waitSemaphoreInfoCount);
        wait_values_[i].resize(submit_info_2.waitSemaphoreInfoCount);
        wait_device_indices_[i].resize(submit_info_2.waitSemaphoreInfoCount);
        bool has_device_group = false;
        for (uint32_t j = 0; j < submit_info_2.waitSemaphoreInfoCount; ++j)
        {
            wait_semaphores_[i][j]  = submit_info_2.pWaitSemaphoreInfos[j].semaphore;
            wait_stage_masks_[i][j] = static_cast<VkPipelineStageFlags>(submit_info_2.pWaitSemaphoreInfos[j].stageMask);
            wait_values_[i][j]      = submit_info_2.pWaitSemaphoreInfos[j].value;
            wait_device_indices_[i][j] = submit_info_2.pWaitSemaphoreInfos[j].deviceIndex;
            has_device_group |= wait_device_indices_[i][j] != 0;
        }

        command_buffers_[i].resize(submit_info_2.commandBufferInfoCount);
        command_buffer_device_masks_[i].resize(submit_info_2.commandBufferInfoCount);
        for (uint32_t j = 0; j < submit_info_2.commandBufferInfoCount; ++j)
        {
            command_buffers_[i][j]             = submit_info_2.pCommandBufferInfos[j].commandBuffer;
            command_buffer_device_masks_[i][j] = submit_info_2.pCommandBufferInfos[j].deviceMask;
            has_device_group |= command_buffer_device_masks_[i][j] != 0;
        }

        signal_semaphores_[i].resize(submit_info_2.signalSemaphoreInfoCount);
        signal_values_[i].resize(submit_info_2.signalSemaphoreInfoCount);
        signal_device_indices_[i].resize(submit_info_2.signalSemaphoreInfoCount);
        for (uint32_t j = 0; j < submit_info_2.signalSemaphoreInfoCount; ++j)
        {
            signal_semaphores_[i][j]     = submit_info_2.pSignalSemaphoreInfos[j].semaphore;
            signal_values_[i][j]         = submit_info_2.pSignalSemaphoreInfos[j].value;
            signal_device_indices_[i][j] = submit_info_2.pSignalSemaphoreInfos[j].deviceIndex;
            has_device_group |= signal_device_indices_[i][j] != 0;
        }

        // VkSubmitInfo2 carries timeline values and device-group indices/masks inline in its sub-structures, whereas
        // VkSubmitInfo conveys them through pNext structures. Reconstruct those structures and chain them ahead of the
        // original pNext-chain.
        const void* pnext = submit_info_2.pNext;

        // Timeline semaphore values. Values for binary semaphores are ignored, so this can be attached
        // unconditionally.
        timeline_submit_infos_[i] =
            VkTimelineSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO,
                                           pnext,
                                           submit_info_2.waitSemaphoreInfoCount,
                                           submit_info_2.waitSemaphoreInfoCount ? wait_values_[i].data() : nullptr,
                                           submit_info_2.signalSemaphoreInfoCount,
                                           submit_info_2.signalSemaphoreInfoCount ? signal_values_[i].data()
                                                                                  : nullptr };

        if (submit_info_2.waitSemaphoreInfoCount || submit_info_2.signalSemaphoreInfoCount)
        {
            pnext = &timeline_submit_infos_[i];
        }

        // Device-group indices/masks. Only reconstruct when at least one index/mask is non-zero: an absent
        // VkDeviceGroupSubmitInfo already yields the default single-device behavior, and an all-zero device mask is
        // not a valid mask value.
        device_group_submit_infos_[i] = VkDeviceGroupSubmitInfo{
            VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO,
            pnext,
            submit_info_2.waitSemaphoreInfoCount,
            submit_info_2.waitSemaphoreInfoCount ? wait_device_indices_[i].data() : nullptr,
            submit_info_2.commandBufferInfoCount,
            submit_info_2.commandBufferInfoCount ? command_buffer_device_masks_[i].data() : nullptr,
            submit_info_2.signalSemaphoreInfoCount,
            submit_info_2.signalSemaphoreInfoCount ? signal_device_indices_[i].data() : nullptr
        };

        if (has_device_group)
        {
            pnext = &device_group_submit_infos_[i];
        }

        // Handle protected queue submissions
        const bool is_protected_submission = (submit_info_2.flags & VK_SUBMIT_PROTECTED_BIT) == VK_SUBMIT_PROTECTED_BIT;
        protected_submit_infos_[i]         = VkProtectedSubmitInfo{ VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO,
                                                            pnext,
                                                            is_protected_submission ? VK_TRUE : VK_FALSE };
        if (is_protected_submission)
        {
            pnext = &protected_submit_infos_[i];
        }

        submit_infos_[i] =
            VkSubmitInfo{ VK_STRUCTURE_TYPE_SUBMIT_INFO,
                          pnext,
                          submit_info_2.waitSemaphoreInfoCount,
                          submit_info_2.waitSemaphoreInfoCount ? wait_semaphores_[i].data() : nullptr,
                          submit_info_2.waitSemaphoreInfoCount ? wait_stage_masks_[i].data() : nullptr,
                          submit_info_2.commandBufferInfoCount,
                          submit_info_2.commandBufferInfoCount ? command_buffers_[i].data() : nullptr,
                          submit_info_2.signalSemaphoreInfoCount,
                          submit_info_2.signalSemaphoreInfoCount ? signal_semaphores_[i].data() : nullptr };
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
