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

VulkanInjectedSemaphore::VulkanInjectedSemaphore(const VulkanDeviceInfo*                  device_info,
                                                 const graphics::VulkanInjectedCallTable* device_table) :
    device_info_{ device_info },
    device_table_{ device_table }
{
    GFXRECON_ASSERT(device_info_ != nullptr);
    GFXRECON_ASSERT(device_table_ != nullptr);

    auto injected_command_scope = device_table_->MarkScope();

    VkSemaphoreTypeCreateInfo timeline_create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO };
    timeline_create_info.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
    timeline_create_info.initialValue  = 0;

    VkSemaphoreCreateInfo semaphore_create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
    semaphore_create_info.pNext = &timeline_create_info;

    VkResult result =
        device_table_->CreateSemaphore(device_info_->handle, &semaphore_create_info, nullptr, &semaphore_.semaphore);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        GFXRECON_LOG_ERROR("Failed to create timeline semaphore for submit job execution: %s",
                           util::ToString(result).c_str());
    }
}

VulkanInjectedSemaphore::VulkanInjectedSemaphore(VulkanInjectedSemaphore&& other) :
    semaphore_{ other.semaphore_ }, device_info_{ other.device_info_ }, device_table_{ other.device_table_ }
{
    other.semaphore_ = graphics::VulkanSemaphore(VK_NULL_HANDLE);
}

VulkanInjectedSemaphore& VulkanInjectedSemaphore::operator=(VulkanInjectedSemaphore&& other) noexcept
{
    if (this != &other)
    {
        std::swap(semaphore_, other.semaphore_);
        std::swap(device_info_, other.device_info_);
        std::swap(device_table_, other.device_table_);
    }
    return *this;
}

bool VulkanInjectedSemaphore::HasReachedTargetValue() const
{
    if (semaphore_.semaphore == VK_NULL_HANDLE)
    {
        return false;
    }

    GFXRECON_ASSERT(device_table_->GetSemaphoreCounterValue != nullptr);

    auto injected_command_scope = device_table_->MarkScope();

    uint64_t read_value = 0;
    VkResult result = device_table_->GetSemaphoreCounterValue(device_info_->handle, semaphore_.semaphore, &read_value);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to get timeline semaphore value for submit job execution: %s",
                           util::ToString(result).c_str());
    }
    return result == VK_SUCCESS && read_value >= semaphore_.timeline_value;
}

VulkanInjectedSemaphore::~VulkanInjectedSemaphore()
{
    if (semaphore_.semaphore != VK_NULL_HANDLE)
    {
        if (!HasReachedTargetValue())
        {
            GFXRECON_LOG_ERROR("Injected timeline semaphore has not reached its target value at destruction time.");
        }
        auto injected_command_scope = device_table_->MarkScope();
        device_table_->DestroySemaphore(device_info_->handle, semaphore_.semaphore, nullptr);
    }
}

VulkanInjectedSemaphoreInfo::VulkanInjectedSemaphoreInfo(const VulkanDeviceInfo*                  device_info,
                                                         const graphics::VulkanInjectedCallTable* device_table) :
    semaphore{ device_info, device_table }
{
    GFXRECON_ASSERT(semaphore.GetHandle() != VK_NULL_HANDLE);
    info.semaphore = semaphore.GetHandle();
    info.stageMask = VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT;
}

VulkanSubmitInfoHelper& VulkanSubmitJobExecution::GetSubmitInfoHelper(VkSubmitInfo& submit_info)
{
    auto it = submit_info_helpers_.find(&submit_info);
    if (it == submit_info_helpers_.end())
    {
        auto [new_it, inserted] =
            submit_info_helpers_.emplace(&submit_info, std::make_unique<VulkanSubmitInfoHelper>(submit_info));
        GFXRECON_ASSERT(inserted);
        it = new_it;
    }
    return *(it->second);
}

VulkanSubmitInfo2Helper& VulkanSubmitJobExecution::GetSubmitInfo2Helper(VkSubmitInfo2& submit_info2)
{
    auto it = submit_info2_helpers_.find(&submit_info2);
    if (it == submit_info2_helpers_.end())
    {
        auto [new_it, inserted] =
            submit_info2_helpers_.emplace(&submit_info2, std::make_unique<VulkanSubmitInfo2Helper>(submit_info2));
        GFXRECON_ASSERT(inserted);
        it = new_it;
    }
    return *(it->second);
}

void VulkanSubmitJobExecution::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo> submit_infos)
{
    // Special case for empty submit array. Just submit the plan with no semaphores.
    if (submit_infos.empty())
    {
        SubmitStandalone(std::move(plan));
        return;
    }

    // Ensure that InjectBefore is not called multiple times for the same submit infos.
    GFXRECON_ASSERT(std::all_of(submit_infos.begin(), submit_infos.end(), [this](VkSubmitInfo& info) {
        return !original_wait_semaphores_.contains(&info) && !submit_info_helpers_.contains(&info);
    }));

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
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
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            VkSubmitInfo& submit_info              = submit_infos[submit_index];
            auto&         original_wait_semaphores = original_wait_semaphores_[&submit_info].semaphores;
            auto&         submit_helper            = GetSubmitInfoHelper(submit_info);

            // Execute each job function and gather injected wait-semaphores.
            for (const auto& job : jobs)
            {
                graphics::VulkanSemaphore submit_semaphore = job(original_wait_semaphores);
                if (submit_semaphore.semaphore != VK_NULL_HANDLE)
                {
                    submit_helper.AddWaitSemaphore(submit_semaphore);
                }
            }
        }
    }
}

void VulkanSubmitJobExecution::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo2> submit_infos)
{
    // Special case for empty submit array. Just submit the plan with no semaphores.
    if (submit_infos.empty())
    {
        SubmitStandalone(std::move(plan));
        return;
    }

    // Ensure that InjectBefore is not called multiple times for the same submit infos.
    GFXRECON_ASSERT(std::all_of(submit_infos.begin(), submit_infos.end(), [this](VkSubmitInfo2& info) {
        return !original_wait_semaphores_.contains(&info) && !submit_info2_helpers_.contains(&info);
    }));

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
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
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            VkSubmitInfo2& submit_info                   = submit_infos[submit_index];
            auto&          original_wait_semaphores      = original_wait_semaphores_[&submit_info].semaphores;
            auto&          submit_helper                 = GetSubmitInfo2Helper(submit_info);

            // Execute each job function and gather injected wait-semaphores.
            for (const auto& job : jobs)
            {
                graphics::VulkanSemaphore submit_semaphore = job(original_wait_semaphores);

                if (submit_semaphore.semaphore != VK_NULL_HANDLE)
                {
                    VkSemaphoreSubmitInfo semaphore_info = {};
                    semaphore_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                    semaphore_info.semaphore             = submit_semaphore.semaphore;
                    semaphore_info.value                 = submit_semaphore.timeline_value;
                    semaphore_info.stageMask             = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                    submit_helper.AddWaitSemaphore(semaphore_info);
                }
            }
        }
    }
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
        auto& submit_helper = GetSubmitInfoHelper(submit_info);
        submit_helper.InjectSemaphore(*injected_semaphore);
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
        auto& submit_helper = GetSubmitInfo2Helper(submit_info2);
        submit_helper.InjectSemaphore(*injected_semaphore_info);
    }
}

void VulkanSubmitJobExecution::SubmitStandalone(VulkanSubmitJobPlan plan) const
{
    for (const auto& jobs : plan.GetSubmitJobs())
    {
        for (const auto& job : jobs.jobs)
        {
            // Do not care about the returned semaphore.
            job({});
        }
    }
}

VulkanSubmitJobExecutor::VulkanSubmitJobExecutor(const VulkanDeviceInfo*                  device_info,
                                                 const graphics::VulkanInjectedCallTable* device_table) :
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
    if (injected_semaphore->GetHandle() == VK_NULL_HANDLE) [[unlikely]]
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
    if (injected_semaphore_info->semaphore.GetHandle() == VK_NULL_HANDLE) [[unlikely]]
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
