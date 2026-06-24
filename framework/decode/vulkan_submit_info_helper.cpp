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

#include "decode/vulkan_submit_info_helper.h"
#include "graphics/vulkan_struct_get_pnext.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanSubmitInfoHelper::VulkanSubmitInfoHelper(VkSubmitInfo& submit_info) : submit_info_(submit_info)
{
    CopyTimelineSemaphoreSubmitInfo();
    CopyWaitSemaphores();
    CopyWaitDstStageMasks();
    CopyWaitValues();
    CopySignalSemaphores();
    CopySignalValues();
}

void VulkanSubmitInfoHelper::CopyWaitSemaphores()
{
    if (submit_info_.pWaitSemaphores != nullptr && submit_info_.waitSemaphoreCount > 0)
    {
        wait_semaphores_ =
            std::vector(submit_info_.pWaitSemaphores, submit_info_.pWaitSemaphores + submit_info_.waitSemaphoreCount);
    }

    // Override wait semaphores pointer.
    submit_info_.pWaitSemaphores = wait_semaphores_.data();
}

void VulkanSubmitInfoHelper::AddWaitSemaphore(VkSemaphore semaphore)
{
    wait_semaphores_.push_back(semaphore);
    submit_info_.pWaitSemaphores    = wait_semaphores_.data();
    submit_info_.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores_.size());

    wait_dst_stage_masks_.push_back(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    submit_info_.pWaitDstStageMask = wait_dst_stage_masks_.data();

    wait_semaphore_values_.push_back(0);

    timeline_semaphore_info_.pWaitSemaphoreValues    = wait_semaphore_values_.data();
    timeline_semaphore_info_.waitSemaphoreValueCount = static_cast<uint32_t>(wait_semaphore_values_.size());

    GFXRECON_ASSERT(wait_semaphores_.size() == wait_semaphore_values_.size());
}

void VulkanSubmitInfoHelper::AddWaitSemaphore(const graphics::VulkanSemaphore& semaphore)
{
    AddWaitSemaphore(semaphore.semaphore);
    wait_semaphore_values_.back() = semaphore.timeline_value;
}

void VulkanSubmitInfoHelper::AddWaitSemaphore(const VulkanInjectedSemaphore& semaphore)
{
    wait_semaphores_.push_back(semaphore.GetHandle());
    submit_info_.pWaitSemaphores    = wait_semaphores_.data();
    submit_info_.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores_.size());

    wait_dst_stage_masks_.push_back(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    submit_info_.pWaitDstStageMask = wait_dst_stage_masks_.data();

    wait_semaphore_values_.push_back(semaphore.GetTargetValue());

    timeline_semaphore_info_.pWaitSemaphoreValues    = wait_semaphore_values_.data();
    timeline_semaphore_info_.waitSemaphoreValueCount = static_cast<uint32_t>(wait_semaphore_values_.size());

    GFXRECON_ASSERT(wait_semaphores_.size() == wait_semaphore_values_.size());
}

void VulkanSubmitInfoHelper::AddSignalSemaphore(const VulkanInjectedSemaphore& semaphore)
{
    signal_semaphores_.push_back(semaphore.GetHandle());
    submit_info_.pSignalSemaphores    = signal_semaphores_.data();
    submit_info_.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores_.size());

    signal_semaphore_values_.push_back(semaphore.GetTargetValue());

    timeline_semaphore_info_.pSignalSemaphoreValues    = signal_semaphore_values_.data();
    timeline_semaphore_info_.signalSemaphoreValueCount = static_cast<uint32_t>(signal_semaphore_values_.size());

    GFXRECON_ASSERT(signal_semaphores_.size() == signal_semaphore_values_.size());
}

void VulkanSubmitInfoHelper::CopySignalSemaphores()
{
    if (submit_info_.pSignalSemaphores != nullptr && submit_info_.signalSemaphoreCount > 0)
    {
        signal_semaphores_ = std::vector(submit_info_.pSignalSemaphores,
                                         submit_info_.pSignalSemaphores + submit_info_.signalSemaphoreCount);
    }

    // Override signal semaphore pointer.
    submit_info_.pSignalSemaphores = signal_semaphores_.data();
}

void VulkanSubmitInfoHelper::CopyWaitValues()
{
    auto& timeline_info = timeline_semaphore_info_;
    if (timeline_info.waitSemaphoreValueCount > 0 && timeline_info.pWaitSemaphoreValues != nullptr)
    {
        wait_semaphore_values_ =
            std::vector<uint64_t>(timeline_info.pWaitSemaphoreValues,
                                  timeline_info.pWaitSemaphoreValues + timeline_info.waitSemaphoreValueCount);
    }
    else
    {
        wait_semaphore_values_ = std::vector<uint64_t>(submit_info_.waitSemaphoreCount, 0);
    }

    // Override any existing values pointer.
    timeline_info.pWaitSemaphoreValues = wait_semaphore_values_.data();
}

void VulkanSubmitInfoHelper::CopySignalValues()
{
    VkTimelineSemaphoreSubmitInfo& timeline_info = timeline_semaphore_info_;
    if (timeline_info.signalSemaphoreValueCount > 0 && timeline_info.pSignalSemaphoreValues != nullptr)
    {
        signal_semaphore_values_ =
            std::vector<uint64_t>(timeline_info.pSignalSemaphoreValues,
                                  timeline_info.pSignalSemaphoreValues + timeline_info.signalSemaphoreValueCount);
    }
    else
    {
        signal_semaphore_values_ = std::vector<uint64_t>(submit_info_.signalSemaphoreCount, 0);
    }

    // Override signal semaphore values.
    timeline_info.pSignalSemaphoreValues = signal_semaphore_values_.data();
}

void VulkanSubmitInfoHelper::CopyWaitDstStageMasks()
{
    // Make sure there is injected storage for wait dst stage masks for this submit info.
    if (submit_info_.pWaitDstStageMask != nullptr && submit_info_.waitSemaphoreCount > 0)
    {
        // Copy existing wait dst stage masks if they exist.
        wait_dst_stage_masks_ = std::vector<VkPipelineStageFlags>(
            submit_info_.pWaitDstStageMask, submit_info_.pWaitDstStageMask + submit_info_.waitSemaphoreCount);
    }
    else
    {
        // Otherwise, initialize wait dst stage masks with a valid default for each wait semaphore.
        wait_dst_stage_masks_ =
            std::vector<VkPipelineStageFlags>(submit_info_.waitSemaphoreCount, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    }

    // Override wait dst stage mask pointer.
    submit_info_.pWaitDstStageMask = wait_dst_stage_masks_.data();
}

void VulkanSubmitInfoHelper::CopyTimelineSemaphoreSubmitInfo()
{
    if (auto* existing_info = graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_info_))
    {
        timeline_semaphore_info_ = *existing_info;
    }
    else
    {
        timeline_semaphore_info_ = VkTimelineSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO };
    }

    // Insert owned timeline submit info, replacing any existing VkTimelineSemaphoreSubmitInfo.
    graphics::vulkan_struct_add_pnext(&submit_info_, &timeline_semaphore_info_);
}

void VulkanSubmitInfoHelper::InjectSemaphore(VulkanInjectedSemaphore& semaphore)
{
    // Wait on the current value, then signal the next value on the same injected timeline semaphore.
    AddWaitSemaphore(semaphore);
    semaphore.IncreaseTargetValue();
    AddSignalSemaphore(semaphore);
}

VulkanSubmitInfo2Helper::VulkanSubmitInfo2Helper(VkSubmitInfo2& submit_info2) : submit_info2_(submit_info2)
{
    CopyWaitSemaphoreInfos();
    CopySignalSemaphoreInfos();
}

void VulkanSubmitInfo2Helper::CopyWaitSemaphoreInfos()
{
    if (submit_info2_.pWaitSemaphoreInfos != nullptr && submit_info2_.waitSemaphoreInfoCount > 0)
    {
        wait_semaphore_infos_ = std::vector(submit_info2_.pWaitSemaphoreInfos,
                                            submit_info2_.pWaitSemaphoreInfos + submit_info2_.waitSemaphoreInfoCount);
    }

    // Override any existing wait semaphore pointer.
    submit_info2_.pWaitSemaphoreInfos = wait_semaphore_infos_.data();
}

void VulkanSubmitInfo2Helper::CopySignalSemaphoreInfos()
{
    if (submit_info2_.pSignalSemaphoreInfos != nullptr && submit_info2_.signalSemaphoreInfoCount > 0)
    {
        signal_semaphore_infos_ =
            std::vector(submit_info2_.pSignalSemaphoreInfos,
                        submit_info2_.pSignalSemaphoreInfos + submit_info2_.signalSemaphoreInfoCount);
    }

    // Override any existing signal semaphore pointer.
    submit_info2_.pSignalSemaphoreInfos = signal_semaphore_infos_.data();
}

void VulkanSubmitInfo2Helper::AddWaitSemaphore(VkSemaphoreSubmitInfo semaphore_info)
{
    std::vector<VkSemaphoreSubmitInfo>& wait_semaphores = wait_semaphore_infos_;
    wait_semaphores.push_back(semaphore_info);
    submit_info2_.pWaitSemaphoreInfos    = wait_semaphores.data();
    submit_info2_.waitSemaphoreInfoCount = static_cast<uint32_t>(wait_semaphores.size());
}

void VulkanSubmitInfo2Helper::AddWaitSemaphore(const VulkanInjectedSemaphoreInfo& semaphore)
{
    std::vector<VkSemaphoreSubmitInfo>& wait_semaphores = wait_semaphore_infos_;
    wait_semaphores.push_back(semaphore.info);
    submit_info2_.pWaitSemaphoreInfos    = wait_semaphores.data();
    submit_info2_.waitSemaphoreInfoCount = static_cast<uint32_t>(wait_semaphores.size());
}

void VulkanSubmitInfo2Helper::AddSignalSemaphore(const VulkanInjectedSemaphoreInfo& semaphore)
{
    std::vector<VkSemaphoreSubmitInfo>& signal_semaphores = signal_semaphore_infos_;
    signal_semaphores.push_back(semaphore.info);
    submit_info2_.pSignalSemaphoreInfos    = signal_semaphores.data();
    submit_info2_.signalSemaphoreInfoCount = static_cast<uint32_t>(signal_semaphores.size());
}

void VulkanSubmitInfo2Helper::InjectSemaphore(VulkanInjectedSemaphoreInfo& semaphore_info)
{
    // Wait on the current value, then signal the next value on the same injected timeline semaphore.
    AddWaitSemaphore(semaphore_info);
    semaphore_info.info.value++;
    semaphore_info.info.stageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;
    semaphore_info.semaphore.IncreaseTargetValue();
    AddSignalSemaphore(semaphore_info);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
