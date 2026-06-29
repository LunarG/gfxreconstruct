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
    submit_infos_2_(submit_infos.size()), wait_semaphores_(submit_infos.size()),
    command_buffers_(submit_infos.size()), signal_semaphores_(submit_infos.size()),
    pnext_deep_copies_(submit_infos.size())
{
    for (size_t i = 0; i < submit_infos.size(); ++i)
    {
        const auto* timeline_semaphore_submit_info =
            graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_infos[i]);
        const auto* protected_submit_info = graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&submit_infos[i]);

        // If VkTimelineSemaphoreSubmitInfo or VkProtectedSubmitInfo are detected in the submit info's pNext chain then
        // we translate the struct's information into the VkSubmitInfo2's structure and we remove them from the chain.
        // Because we interfere with the pNext chain we create a deep copy
        VkSubmitInfo* modified_pnext_chain = nullptr;
        if (timeline_semaphore_submit_info != nullptr || protected_submit_info != nullptr)
        {
            const size_t num_bytes = graphics::vulkan_struct_deep_copy(&submit_infos[i], 1, nullptr);
            pnext_deep_copies_[i].resize(num_bytes);
            graphics::vulkan_struct_deep_copy(&submit_infos[i], 1, pnext_deep_copies_[i].data());

            modified_pnext_chain = reinterpret_cast<VkSubmitInfo*>(pnext_deep_copies_[i].data());
        }

        std::vector<uint64_t> timeline_semaphore_wait_values(submit_infos[i].waitSemaphoreCount);
        std::vector<uint64_t> timeline_semaphore_signal_values(submit_infos[i].signalSemaphoreCount);

        // Extract timeline semaphore values and remove them from pNext chain
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
                                       0 };
        }

        // Command buffers
        command_buffers_[i].resize(submit_infos[i].commandBufferCount);
        for (uint32_t j = 0; j < submit_infos[i].commandBufferCount; ++j)
        {
            command_buffers_[i][j] = VkCommandBufferSubmitInfo{
                VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, nullptr, submit_infos[i].pCommandBuffers[j], 0
            };
        }

        // Signal semaphores. A VkSubmitInfo signals once all submitted work completes, i.e. at ALL_COMMANDS.
        signal_semaphores_[i].resize(submit_infos[i].signalSemaphoreCount);
        for (uint32_t j = 0; j < submit_infos[i].signalSemaphoreCount; ++j)
        {
            signal_semaphores_[i][j] =
                VkSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, nullptr,
                                       submit_infos[i].pSignalSemaphores[j],    timeline_semaphore_signal_values[j],
                                       VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,    0 };
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

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
