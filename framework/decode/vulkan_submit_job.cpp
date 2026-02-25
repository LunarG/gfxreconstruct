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

void VulkanSubmitJobExecutor::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo> submit_infos)
{
    GFXRECON_ASSERT(original_wait_semaphores_.empty());
    GFXRECON_ASSERT(injected_wait_semaphores_.empty());

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_infos.size(); ++submit_index)
    {
        original_wait_semaphores_.emplace_back();
        injected_wait_semaphores_.emplace_back();

        // Only gather original wait-semaphores if there are jobs to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            original_wait_semaphores_[submit_index].semaphores =
                graphics::StripWaitSemaphores(&submit_infos[submit_index]);
        }
    }

    // Execute jobs for each submit and gather injected wait-semaphores
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            auto& original_wait_semaphores = original_wait_semaphores_[submit_index].semaphores;
            auto& injected_wait_semaphores = injected_wait_semaphores_[submit_index];

            // Execute each job function and gather injected wait-semaphores.
            for (const auto& job : jobs)
            {
                VkSemaphore submit_semaphore = job(original_wait_semaphores);
                GFXRECON_ASSERT(submit_semaphore != VK_NULL_HANDLE);
                injected_wait_semaphores.push_back(submit_semaphore);
            }

            // Inject wait-semaphore into submit-info.
            auto& submit_info              = submit_infos[submit_index];
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

void VulkanSubmitJobExecutor::InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo2> submit_infos)
{
    GFXRECON_ASSERT(original_wait_semaphores_.empty());
    GFXRECON_ASSERT(injected_wait_semaphore_infos_.empty());

    // Gather original wait-semaphores for each submit and prepare storage for injected wait-semaphores.
    auto& submit_jobs = plan.GetSubmitJobs();
    for (uint32_t submit_index = 0; submit_index < submit_infos.size(); ++submit_index)
    {
        original_wait_semaphores_.emplace_back();
        injected_wait_semaphore_infos_.emplace_back();

        // Only gather original wait-semaphores if there are jobs to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            original_wait_semaphores_[submit_index].semaphores =
                graphics::StripWaitSemaphores(&submit_infos[submit_index]);
        }
    }

    // Execute jobs for each submit and gather injected wait-semaphores
    for (uint32_t submit_index = 0; submit_index < submit_jobs.size(); ++submit_index)
    {
        auto& jobs = submit_jobs[submit_index].jobs;

        // Only execute jobs if there are functions to execute for this submit.
        if (plan.HasJobsForIndex(submit_index))
        {
            auto& original_wait_semaphores      = original_wait_semaphores_[submit_index].semaphores;
            auto& injected_wait_semaphore_infos = injected_wait_semaphore_infos_[submit_index];

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
            auto& submit_info                  = submit_infos[submit_index];
            submit_info.waitSemaphoreInfoCount = static_cast<uint32_t>(injected_wait_semaphore_infos.size());
            submit_info.pWaitSemaphoreInfos    = injected_wait_semaphore_infos.data();
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
