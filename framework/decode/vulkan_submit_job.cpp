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

            // Inject wait-semaphore into submit-info.
            submit_info.waitSemaphoreCount = static_cast<uint32_t>(injected_wait_semaphores.size());
            submit_info.pWaitSemaphores    = injected_wait_semaphores.data();

            // If waitSemaphoreCount was 0, pWaitDstStageMask might be nullptr.
            // Make sure it points to valid data in all cases.
            static VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
            submit_info.pWaitDstStageMask               = &wait_stage_mask;

            // Handle potential timeline-semaphores in pnext-chain.
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
        VkSubmitInfo2& submit_info                   = submit_infos[submit_index];
        auto&          original_wait_semaphores      = original_wait_semaphores_[&submit_info].semaphores;
        auto&          injected_wait_semaphore_infos = injected_wait_semaphore_infos_[&submit_info];

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

            // Inject wait-semaphore into submit-info.
            submit_info.waitSemaphoreInfoCount = static_cast<uint32_t>(injected_wait_semaphore_infos.size());
            submit_info.pWaitSemaphoreInfos    = injected_wait_semaphore_infos.data();
        }
    }
}

std::vector<VkSemaphore>& VulkanSubmitJobExecution::GetWaitSemaphores(VkSubmitInfo& submit_info)
{
    if (!injected_wait_semaphores_.contains(&submit_info))
    {
        injected_wait_semaphores_[&submit_info] =
            std::vector(submit_info.pWaitSemaphores, submit_info.pWaitSemaphores + submit_info.waitSemaphoreCount);
    }
    return injected_wait_semaphores_[&submit_info];
}

std::vector<VkSemaphoreSubmitInfo>& VulkanSubmitJobExecution::GetWaitSemaphores(VkSubmitInfo2& submit_info2)
{
    if (!injected_wait_semaphore_infos_.contains(&submit_info2))
    {
        injected_wait_semaphore_infos_[&submit_info2] = std::vector(
            submit_info2.pWaitSemaphoreInfos, submit_info2.pWaitSemaphoreInfos + submit_info2.waitSemaphoreInfoCount);
    }
    return injected_wait_semaphore_infos_[&submit_info2];
}

void VulkanSubmitJobExecution::SerializeExecution(std::span<VkSubmitInfo> submit_infos)
{
    // Each submit info should wait on semaphores signaled by the previous submit.
    std::span<const VkSemaphore> previous_submit_signal_semaphores = {};

    for (VkSubmitInfo& submit_info : submit_infos)
    {
        // Ensure this submit signals at least one semaphore so the next submit can wait on it.
        if (submit_info.signalSemaphoreCount == 0 || submit_info.pSignalSemaphores == nullptr)
        {
            VkSemaphore dummy_semaphore = executor_.CreateSemaphore();

            // Store the injected signal semaphore so it remains alive until executor cleanup.
            auto& injected_signal_semaphore = injected_signal_semaphores_[&submit_info];
            injected_signal_semaphore.push_back(dummy_semaphore);

            submit_info.signalSemaphoreCount = static_cast<uint32_t>(injected_signal_semaphore.size());
            submit_info.pSignalSemaphores    = injected_signal_semaphore.data();
        }

        // If the previous submit signaled semaphores, append them to this submit's wait list.
        if (!previous_submit_signal_semaphores.empty())
        {
            auto& wait_semaphores = GetWaitSemaphores(submit_info);

            // Append previous submit signal semaphores to the wait semaphores of the current submit.
            wait_semaphores.insert(wait_semaphores.end(),
                                   previous_submit_signal_semaphores.begin(),
                                   previous_submit_signal_semaphores.end());

            // Update submit info with the new wait semaphores pointer and count.
            submit_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());
            submit_info.pWaitSemaphores    = wait_semaphores.data();

            // Ensure wait dst stage mask points to valid storage.
            static VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
            submit_info.pWaitDstStageMask               = &wait_stage_mask;
        }

        previous_submit_signal_semaphores = std::span(submit_info.pSignalSemaphores, submit_info.signalSemaphoreCount);
    }
}

void VulkanSubmitJobExecution::SerializeExecution(std::span<VkSubmitInfo2> submit_infos2)
{
    // Each submit info should wait on semaphores signaled by the previous submit.
    std::span<const VkSemaphoreSubmitInfo> previous_submit_signal_semaphores = {};

    for (VkSubmitInfo2& submit_info : submit_infos2)
    {
        // Ensure this submit signals at least one semaphore so the next submit can wait on it.
        if (submit_info.signalSemaphoreInfoCount == 0 || submit_info.pSignalSemaphoreInfos == nullptr)
        {
            VkSemaphoreSubmitInfo dummy_semaphore_info = { VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO };
            dummy_semaphore_info.semaphore             = executor_.CreateSemaphore();
            dummy_semaphore_info.value                 = 1;
            dummy_semaphore_info.stageMask             = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

            auto& injected_signal_semaphore_infos = injected_signal_semaphore_infos_[&submit_info];
            injected_signal_semaphore_infos.push_back(dummy_semaphore_info);

            submit_info.signalSemaphoreInfoCount = static_cast<uint32_t>(injected_signal_semaphore_infos.size());
            submit_info.pSignalSemaphoreInfos    = injected_signal_semaphore_infos.data();
        }

        // If the previous submit signaled semaphores, append them to this submit's wait list.
        if (!previous_submit_signal_semaphores.empty())
        {
            auto& wait_semaphore_infos = GetWaitSemaphores(submit_info);

            // Append previous submit signal semaphore infos to the wait semaphore infos of the current submit.
            wait_semaphore_infos.insert(wait_semaphore_infos.end(),
                                        previous_submit_signal_semaphores.begin(),
                                        previous_submit_signal_semaphores.end());

            // Update submit info with the new wait semaphore infos pointer and count.
            submit_info.waitSemaphoreInfoCount = static_cast<uint32_t>(wait_semaphore_infos.size());
            submit_info.pWaitSemaphoreInfos    = wait_semaphore_infos.data();
        }

        previous_submit_signal_semaphores =
            std::span(submit_info.pSignalSemaphoreInfos, submit_info.signalSemaphoreInfoCount);
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

VulkanSubmitJobExecutor::~VulkanSubmitJobExecutor()
{
    for (VkSemaphore semaphore : semaphores_)
    {
        device_table_->DestroySemaphore(device_info_->handle, semaphore, nullptr);
    }
    semaphores_.clear();
}

VkSemaphore VulkanSubmitJobExecutor::CreateSemaphore()
{
    VkSemaphoreCreateInfo semaphore_create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
    VkSemaphore           semaphore = VK_NULL_HANDLE;

    VkResult result = device_table_->CreateSemaphore(device_info_->handle, &semaphore_create_info, nullptr, &semaphore);
    if (result != VK_SUCCESS) [[unlikely]]
    {
        GFXRECON_LOG_ERROR("Failed to create semaphore for submit job execution: %s", util::ToString(result).c_str());
        return VK_NULL_HANDLE;
    }
    else [[likely]]
    {
        semaphores_.push_back(semaphore);
        return semaphore;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
