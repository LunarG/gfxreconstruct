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

#include "decode/vulkan_submit_job.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "generated/generated_vulkan_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanSubmitJobPlan::Push(uint32_t submit_index, VulkanSubmitJob job)
{
    // Ensure submit_jobs_ has enough entries to accommodate the submit_index.
    if (submit_index >= submit_jobs_.size())
    {
        submit_jobs_.resize(submit_index + 1);
    }
    submit_jobs_[submit_index].jobs.emplace_back(std::move(job));
}

const VulkanSubmitJobs* VulkanSubmitJobPlan::GetSubmitJobsForIndex(uint32_t submit_index) const
{
    if (submit_index < submit_jobs_.size())
    {
        return &submit_jobs_[submit_index];
    }
    else
    {
        return nullptr;
    }
}

bool VulkanSubmitJobPlan::HasJobsForIndex(uint32_t submit_index) const
{
    const auto* jobs_for_index = GetSubmitJobsForIndex(submit_index);
    return jobs_for_index && !jobs_for_index->jobs.empty();
}

VulkanInjectedSemaphore::VulkanInjectedSemaphore(const VulkanDeviceInfo*            device_info,
                                                 const graphics::VulkanDeviceTable* device_table) :
    device_info_{ device_info },
    device_table_{ device_table }
{
    GFXRECON_ASSERT(device_info_ != nullptr);
    GFXRECON_ASSERT(device_table_ != nullptr);

    VkSemaphoreTypeCreateInfo timeline_create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO };
    timeline_create_info.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
    timeline_create_info.initialValue  = 0;

    VkSemaphoreCreateInfo semaphore_create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
    semaphore_create_info.pNext = &timeline_create_info;

    VkResult result = device_table_->CreateSemaphore(device_info_->handle, &semaphore_create_info, nullptr, &handle);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        GFXRECON_LOG_ERROR("Failed to create timeline semaphore for submit job execution: %s",
                           util::ToString(result).c_str());
    }
}

bool VulkanInjectedSemaphore::HasReachedTargetValue() const
{
    if (handle == VK_NULL_HANDLE)
    {
        return false;
    }

    VkSemaphoreWaitInfo wait_info = { VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO };
    wait_info.semaphoreCount      = 1;
    wait_info.pSemaphores         = &handle;
    wait_info.pValues             = &target_value;
    VkResult result               = device_table_->WaitSemaphores(device_info_->handle, &wait_info, 0);
    if (result != VK_SUCCESS && result != VK_TIMEOUT)
    {
        GFXRECON_LOG_ERROR("Failed to wait on timeline semaphore for submit job execution: %s",
                           util::ToString(result).c_str());
    }
    return result == VK_SUCCESS;
}

VulkanInjectedSemaphore::~VulkanInjectedSemaphore()
{
    if (handle != VK_NULL_HANDLE)
    {
        if (!HasReachedTargetValue())
        {
            GFXRECON_LOG_ERROR("Injected timeline semaphore has not reached its target value at destruction time.");
        }
        device_table_->DestroySemaphore(device_info_->handle, handle, nullptr);
    }
}

VulkanInjectedSemaphoreInfo::VulkanInjectedSemaphoreInfo(const VulkanDeviceInfo*            device_info,
                                                         const graphics::VulkanDeviceTable* device_table) :
    semaphore{ device_info, device_table }
{
    GFXRECON_ASSERT(semaphore.handle != VK_NULL_HANDLE);
    info.semaphore = semaphore.handle;
    info.stageMask = VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT;
}

void VulkanSubmitJobExecution::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo> submit_infos)
{
    // Ensure that InjectBefore is not called multiple times for the same submit infos.
    GFXRECON_ASSERT(std::all_of(submit_infos.begin(), submit_infos.end(), [this](VkSubmitInfo& info) {
        return !original_wait_semaphores_.contains(&info) && !injected_wait_semaphores_.contains(&info);
    }));

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_infos.size(); ++submit_index)
    {
        // Only gather original wait-semaphores if there are jobs to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            VkSubmitInfo& submit_info                          = submit_infos[submit_index];
            original_wait_semaphores_[&submit_info].semaphores = graphics::StripWaitSemaphores(&submit_info);
        }
    }

    // Execute jobs for each submit and gather injected wait-semaphores
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            VkSubmitInfo& submit_info              = submit_infos[submit_index];
            auto&         original_wait_semaphores = original_wait_semaphores_[&submit_info].semaphores;
            auto&         injected_wait_semaphores = injected_wait_semaphores_[&submit_info];

            // Execute each job function and gather injected wait-semaphores.
            for (const auto& job : jobs)
            {
                VkSemaphore submit_semaphore = job(original_wait_semaphores);
                GFXRECON_ASSERT(submit_semaphore != VK_NULL_HANDLE);
                injected_wait_semaphores.push_back(submit_semaphore);
            }

            // Replace the original waits with waits for the injected jobs.
            submit_info.waitSemaphoreCount = static_cast<uint32_t>(injected_wait_semaphores.size());
            submit_info.pWaitSemaphores    = injected_wait_semaphores.data();

            // If waitSemaphoreCount was 0, pWaitDstStageMask might be nullptr.
            // Make sure it points to valid data in all cases.
            auto& wait_dst_stage_masks    = GetWaitDstStageMasks(submit_info, true);
            submit_info.pWaitDstStageMask = wait_dst_stage_masks.data();

            // The original waits were stripped, so any timeline wait values that described them must be removed too.
            if (auto* timeline_info = graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_info))
            {
                timeline_info->waitSemaphoreValueCount = 0;
                timeline_info->pWaitSemaphoreValues    = nullptr;
            }
        }
    }
}

void VulkanSubmitJobExecution::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo2> submit_infos)
{
    // Ensure that InjectBefore is not called multiple times for the same submit infos.
    GFXRECON_ASSERT(std::all_of(submit_infos.begin(), submit_infos.end(), [this](VkSubmitInfo2& info) {
        return !original_wait_semaphores_.contains(&info) && !injected_wait_semaphore_infos_.contains(&info);
    }));

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_infos.size(); ++submit_index)
    {
        VkSubmitInfo2& submit_info              = submit_infos[submit_index];
        auto&          original_wait_semaphores = original_wait_semaphores_[&submit_info].semaphores;

        // Only gather original wait-semaphores if there are jobs to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            original_wait_semaphores = graphics::StripWaitSemaphores(&submit_info);
        }
    }

    // Execute jobs for each submit and gather injected wait-semaphores
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            VkSubmitInfo2& submit_info                   = submit_infos[submit_index];
            auto&          original_wait_semaphores      = original_wait_semaphores_[&submit_info].semaphores;
            auto&          injected_wait_semaphore_infos = injected_wait_semaphore_infos_[&submit_info];

            // Execute each job function and gather injected wait-semaphores.
            for (const auto& job : jobs)
            {
                VkSemaphore submit_semaphore = job(original_wait_semaphores);
                GFXRECON_ASSERT(submit_semaphore != VK_NULL_HANDLE);

                VkSemaphoreSubmitInfo semaphore_info = {};
                semaphore_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                semaphore_info.semaphore             = submit_semaphore;
                semaphore_info.value                 = 1;
                semaphore_info.stageMask             = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                injected_wait_semaphore_infos.push_back(semaphore_info);
            }

            // Replace the original waits with waits for the injected jobs.
            submit_info.waitSemaphoreInfoCount = static_cast<uint32_t>(injected_wait_semaphore_infos.size());
            submit_info.pWaitSemaphoreInfos    = injected_wait_semaphore_infos.data();
        }
    }
}

std::vector<VkSemaphore>& VulkanSubmitJobExecution::GetWaitSemaphores(VkSubmitInfo& submit_info)
{
    if (!injected_wait_semaphores_.contains(&submit_info))
    {
        if (submit_info.pWaitSemaphores != nullptr && submit_info.waitSemaphoreCount > 0)
        {

            injected_wait_semaphores_[&submit_info] =
                std::vector(submit_info.pWaitSemaphores, submit_info.pWaitSemaphores + submit_info.waitSemaphoreCount);
        }
        else
        {
            injected_wait_semaphores_[&submit_info] = std::vector<VkSemaphore>();
        }

        // Override wait semaphores pointer.
        submit_info.pWaitSemaphores = injected_wait_semaphores_[&submit_info].data();
    }
    return injected_wait_semaphores_[&submit_info];
}

void VulkanSubmitJobExecution::AddWaitSemaphore(VkSubmitInfo& submit_info, const VulkanInjectedSemaphore& semaphore)
{
    std::vector<VkSemaphore>&          wait_semaphores                = GetWaitSemaphores(submit_info);
    std::vector<VkPipelineStageFlags>& wait_dst_stage_masks           = GetWaitDstStageMasks(submit_info, true);
    std::vector<uint64_t>&             wait_values                    = GetWaitValues(submit_info);
    VkTimelineSemaphoreSubmitInfo&     timeline_semaphore_submit_info = GetTimelineSemaphoreSubmitInfo(submit_info);

    wait_semaphores.push_back(semaphore.handle);
    submit_info.pWaitSemaphores    = wait_semaphores.data();
    submit_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());

    wait_dst_stage_masks.push_back(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    submit_info.pWaitDstStageMask = wait_dst_stage_masks.data();

    wait_values.push_back(semaphore.target_value);

    timeline_semaphore_submit_info.pWaitSemaphoreValues    = wait_values.data();
    timeline_semaphore_submit_info.waitSemaphoreValueCount = static_cast<uint32_t>(wait_values.size());

    GFXRECON_ASSERT(wait_semaphores.size() == wait_values.size());
}

void VulkanSubmitJobExecution::AddSignalSemaphore(VkSubmitInfo& submit_info, const VulkanInjectedSemaphore& semaphore)
{
    std::vector<VkSemaphore>&      signal_semaphores              = GetSignalSemaphores(submit_info);
    std::vector<uint64_t>&         signal_values                  = GetSignalValues(submit_info);
    VkTimelineSemaphoreSubmitInfo& timeline_semaphore_submit_info = GetTimelineSemaphoreSubmitInfo(submit_info);

    signal_semaphores.push_back(semaphore.handle);
    submit_info.pSignalSemaphores    = signal_semaphores.data();
    submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());

    signal_values.push_back(semaphore.target_value);

    timeline_semaphore_submit_info.pSignalSemaphoreValues    = signal_values.data();
    timeline_semaphore_submit_info.signalSemaphoreValueCount = static_cast<uint32_t>(signal_values.size());

    GFXRECON_ASSERT(signal_semaphores.size() == signal_values.size());
}

void VulkanSubmitJobExecution::AddWaitSemaphore(VkSubmitInfo2&                     submit_info,
                                                const VulkanInjectedSemaphoreInfo& semaphore)
{
    std::vector<VkSemaphoreSubmitInfo>& wait_semaphores = GetWaitSemaphoreInfos(submit_info);
    wait_semaphores.push_back(semaphore.info);
    submit_info.pWaitSemaphoreInfos    = wait_semaphores.data();
    submit_info.waitSemaphoreInfoCount = static_cast<uint32_t>(wait_semaphores.size());
}

void VulkanSubmitJobExecution::AddSignalSemaphore(VkSubmitInfo2&                     submit_info,
                                                  const VulkanInjectedSemaphoreInfo& semaphore)
{
    std::vector<VkSemaphoreSubmitInfo>& signal_semaphores = GetSignalSemaphoreInfos(submit_info);
    signal_semaphores.push_back(semaphore.info);
    submit_info.pSignalSemaphoreInfos    = signal_semaphores.data();
    submit_info.signalSemaphoreInfoCount = static_cast<uint32_t>(signal_semaphores.size());
}

std::vector<VkSemaphore>& VulkanSubmitJobExecution::GetSignalSemaphores(VkSubmitInfo& submit_info)
{
    if (!injected_signal_semaphores_.contains(&submit_info))
    {
        if (submit_info.pSignalSemaphores != nullptr && submit_info.signalSemaphoreCount > 0)
        {
            injected_signal_semaphores_[&submit_info] = std::vector(
                submit_info.pSignalSemaphores, submit_info.pSignalSemaphores + submit_info.signalSemaphoreCount);
        }
        else
        {
            injected_signal_semaphores_[&submit_info] = std::vector<VkSemaphore>();
        }

        // Override signal semaphore pointer.
        submit_info.pSignalSemaphores = injected_signal_semaphores_[&submit_info].data();
    }
    return injected_signal_semaphores_[&submit_info];
}

std::vector<uint64_t>& VulkanSubmitJobExecution::GetWaitValues(VkSubmitInfo& submit_info)
{
    if (!injected_wait_semaphore_values_.contains(&submit_info))
    {
        VkTimelineSemaphoreSubmitInfo& timeline_info = GetTimelineSemaphoreSubmitInfo(submit_info);
        if (timeline_info.waitSemaphoreValueCount > 0 && timeline_info.pWaitSemaphoreValues != nullptr)
        {
            injected_wait_semaphore_values_[&submit_info] =
                std::vector<uint64_t>(timeline_info.pWaitSemaphoreValues,
                                      timeline_info.pWaitSemaphoreValues + timeline_info.waitSemaphoreValueCount);
        }
        else
        {
            injected_wait_semaphore_values_[&submit_info] = std::vector<uint64_t>(submit_info.waitSemaphoreCount, 0);
        }

        // Override any existing values pointer.
        timeline_info.pWaitSemaphoreValues = injected_wait_semaphore_values_[&submit_info].data();
    }
    return injected_wait_semaphore_values_[&submit_info];
}

std::vector<uint64_t>& VulkanSubmitJobExecution::GetSignalValues(VkSubmitInfo& submit_info)
{
    if (!injected_signal_semaphore_values_.contains(&submit_info))
    {
        VkTimelineSemaphoreSubmitInfo& timeline_info = GetTimelineSemaphoreSubmitInfo(submit_info);
        if (timeline_info.signalSemaphoreValueCount > 0 && timeline_info.pSignalSemaphoreValues != nullptr)
        {
            injected_signal_semaphore_values_[&submit_info] =
                std::vector<uint64_t>(timeline_info.pSignalSemaphoreValues,
                                      timeline_info.pSignalSemaphoreValues + timeline_info.signalSemaphoreValueCount);
        }
        else
        {
            injected_signal_semaphore_values_[&submit_info] =
                std::vector<uint64_t>(submit_info.signalSemaphoreCount, 0);
        }

        // Override signal semaphore values.
        timeline_info.pSignalSemaphoreValues = injected_signal_semaphore_values_[&submit_info].data();
    }
    return injected_signal_semaphore_values_[&submit_info];
}

std::vector<VkPipelineStageFlags>& VulkanSubmitJobExecution::GetWaitDstStageMasks(VkSubmitInfo& submit_info,
                                                                                  bool          override)
{
    // Make sure there is injected storage for wait dst stage masks for this submit info.
    if (!injected_wait_dst_stage_masks_.contains(&submit_info))
    {
        if (submit_info.pWaitDstStageMask != nullptr && submit_info.waitSemaphoreCount > 0)
        {
            // Copy existing wait dst stage masks if they exist.
            injected_wait_dst_stage_masks_[&submit_info] = std::vector<VkPipelineStageFlags>(
                submit_info.pWaitDstStageMask, submit_info.pWaitDstStageMask + submit_info.waitSemaphoreCount);
        }
        else
        {
            // Otherwise, initialize wait dst stage masks with a valid default for each wait semaphore.
            injected_wait_dst_stage_masks_[&submit_info] =
                std::vector<VkPipelineStageFlags>(submit_info.waitSemaphoreCount, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
        }

        // Override wait dst stage mask pointer.
        submit_info.pWaitDstStageMask = injected_wait_dst_stage_masks_[&submit_info].data();
    }

    if (override)
    {
        std::fill(injected_wait_dst_stage_masks_[&submit_info].begin(),
                  injected_wait_dst_stage_masks_[&submit_info].end(),
                  VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    }

    return injected_wait_dst_stage_masks_[&submit_info];
}

std::vector<VkSemaphoreSubmitInfo>& VulkanSubmitJobExecution::GetWaitSemaphoreInfos(VkSubmitInfo2& submit_info2)
{
    if (!injected_wait_semaphore_infos_.contains(&submit_info2))
    {
        if (submit_info2.pWaitSemaphoreInfos != nullptr && submit_info2.waitSemaphoreInfoCount > 0)
        {
            injected_wait_semaphore_infos_[&submit_info2] =
                std::vector(submit_info2.pWaitSemaphoreInfos,
                            submit_info2.pWaitSemaphoreInfos + submit_info2.waitSemaphoreInfoCount);
        }
        else
        {
            injected_wait_semaphore_infos_[&submit_info2] = std::vector<VkSemaphoreSubmitInfo>();
        }

        // Override any existing wait semaphore pointer.
        submit_info2.pWaitSemaphoreInfos = injected_wait_semaphore_infos_[&submit_info2].data();
    }
    return injected_wait_semaphore_infos_[&submit_info2];
}

std::vector<VkSemaphoreSubmitInfo>& VulkanSubmitJobExecution::GetSignalSemaphoreInfos(VkSubmitInfo2& submit_info)
{
    if (!injected_signal_semaphore_infos_.contains(&submit_info))
    {
        if (submit_info.pSignalSemaphoreInfos != nullptr && submit_info.signalSemaphoreInfoCount > 0)
        {
            injected_signal_semaphore_infos_[&submit_info] =
                std::vector(submit_info.pSignalSemaphoreInfos,
                            submit_info.pSignalSemaphoreInfos + submit_info.signalSemaphoreInfoCount);
        }
        else
        {
            injected_signal_semaphore_infos_[&submit_info] = std::vector<VkSemaphoreSubmitInfo>();
        }

        // Override any existing signal semaphore pointer.
        submit_info.pSignalSemaphoreInfos = injected_signal_semaphore_infos_[&submit_info].data();
    }
    return injected_signal_semaphore_infos_[&submit_info];
}

VkTimelineSemaphoreSubmitInfo& VulkanSubmitJobExecution::GetTimelineSemaphoreSubmitInfo(VkSubmitInfo& submit_info)
{
    if (!injected_timeline_semaphore_infos_.contains(&submit_info))
    {
        if (auto* existing_info = graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_info))
        {
            injected_timeline_semaphore_infos_[&submit_info] = *existing_info;
        }
        else
        {
            injected_timeline_semaphore_infos_[&submit_info] =
                VkTimelineSemaphoreSubmitInfo{ VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO };
        }

        // Insert owned timeline submit info, replacing any existing VkTimelineSemaphoreSubmitInfo.
        graphics::vulkan_struct_add_pnext(&submit_info, &injected_timeline_semaphore_infos_[&submit_info]);
    }
    return injected_timeline_semaphore_infos_[&submit_info];
}

void VulkanSubmitJobExecution::InjectSemaphore(VkSubmitInfo& submit_info, VulkanInjectedSemaphore& semaphore)
{
    // Wait on the current value, then signal the next value on the same injected timeline semaphore.
    AddWaitSemaphore(submit_info, semaphore);
    semaphore.target_value++;
    AddSignalSemaphore(submit_info, semaphore);
}

void VulkanSubmitJobExecution::InjectSemaphore(VkSubmitInfo2& submit_info, VulkanInjectedSemaphoreInfo& semaphore_info)
{
    // Wait on the current value, then signal the next value on the same injected timeline semaphore.
    AddWaitSemaphore(submit_info, semaphore_info);
    semaphore_info.info.value++;
    semaphore_info.info.stageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;
    semaphore_info.semaphore.target_value++;
    AddSignalSemaphore(submit_info, semaphore_info);
}

void VulkanSubmitJobExecution::SerializeExecution(std::span<VkSubmitInfo> submit_infos)
{
    // No need to serialize fewer than two submits.
    if (submit_infos.size() < 2)
    {
        return;
    }

    VulkanInjectedSemaphore* injected_semaphore = executor_.CreateTimelineSemaphore();
    GFXRECON_ASSERT(injected_semaphore != nullptr);
    if (injected_semaphore == nullptr) [[unlikely]]
    {
        return;
    }

    // One timeline semaphore serializes the whole submit array by advancing its value once per submit.
    for (VkSubmitInfo& submit_info : submit_infos)
    {
        InjectSemaphore(submit_info, *injected_semaphore);
    }
}

void VulkanSubmitJobExecution::SerializeExecution(std::span<VkSubmitInfo2> submit_infos2)
{
    // No need to serialize fewer than two submits.
    if (submit_infos2.size() < 2)
    {
        return;
    }

    VulkanInjectedSemaphoreInfo* injected_semaphore_info = executor_.CreateTimelineSemaphoreInfo();
    GFXRECON_ASSERT(injected_semaphore_info != nullptr);
    if (injected_semaphore_info == nullptr) [[unlikely]]
    {
        return;
    }

    // One timeline semaphore serializes the whole submit array by advancing its value once per submit.
    for (VkSubmitInfo2& submit_info2 : submit_infos2)
    {
        InjectSemaphore(submit_info2, *injected_semaphore_info);
    }
}

VulkanSubmitJobExecutor::VulkanSubmitJobExecutor(const VulkanDeviceInfo*            device_info,
                                                 const graphics::VulkanDeviceTable* device_table) :
    device_info_(device_info),
    device_table_(device_table)
{
    GFXRECON_ASSERT(device_info_ != nullptr);
    GFXRECON_ASSERT(device_table_ != nullptr);
}

VulkanInjectedSemaphore* VulkanSubmitJobExecutor::CreateTimelineSemaphore()
{
    PruneSignaledTimelineSemaphores();

    auto injected_semaphore = std::make_unique<VulkanInjectedSemaphore>(device_info_, device_table_);
    if (injected_semaphore->handle == VK_NULL_HANDLE) [[unlikely]]
    {
        return nullptr;
    }
    injected_semaphores_.push_back(std::move(injected_semaphore));
    return injected_semaphores_.back().get();
}

VulkanInjectedSemaphoreInfo* VulkanSubmitJobExecutor::CreateTimelineSemaphoreInfo()
{
    PruneSignaledTimelineSemaphoreInfos();

    auto injected_semaphore_info = std::make_unique<VulkanInjectedSemaphoreInfo>(device_info_, device_table_);
    if (injected_semaphore_info->semaphore.handle == VK_NULL_HANDLE) [[unlikely]]
    {
        return nullptr;
    }
    injected_semaphore_infos_.push_back(std::move(injected_semaphore_info));
    return injected_semaphore_infos_.back().get();
}

void VulkanSubmitJobExecutor::PruneSignaledTimelineSemaphores()
{
    // Remove tracked timeline semaphores that have reached or exceeded their target value.
    auto it = injected_semaphores_.begin();
    while (it != injected_semaphores_.end())
    {
        auto& semaphore = *it;
        if (semaphore->HasReachedTargetValue())
        {
            it = injected_semaphores_.erase(it);
        }
        else
        {
            // Semaphore is still pending, keep it tracked.
            ++it;
        }
    }
}

void VulkanSubmitJobExecutor::PruneSignaledTimelineSemaphoreInfos()
{
    // Remove tracked timeline semaphores that have reached or exceeded their target value.
    auto it = injected_semaphore_infos_.begin();
    while (it != injected_semaphore_infos_.end())
    {
        auto& semaphore_info = *it;
        if (semaphore_info->semaphore.HasReachedTargetValue())
        {
            it = injected_semaphore_infos_.erase(it);
        }
        else
        {
            // Semaphore is still pending, keep it tracked.
            ++it;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
