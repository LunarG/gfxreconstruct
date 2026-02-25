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

#ifndef GFXRECON_DECODE_VULKAN_SUBMIT_JOB_H
#define GFXRECON_DECODE_VULKAN_SUBMIT_JOB_H

#include <functional>
#include <span>

#include "decode/vulkan_object_info.h"
#include "graphics/vulkan_semaphore_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief   Callback executed before a queue submit.
 *
 * The callback receives the submit's original wait-semaphores and returns a semaphore that should be waited on by
 * the original submit-info.
 */
typedef std::function<VkSemaphore(const std::span<graphics::VulkanSemaphore>)> VulkanSubmitJob;

/**
 * @brief   For each submit entry, multiple jobs can be registered.
 */
struct VulkanSubmitJobs
{
    std::vector<VulkanSubmitJob> jobs;
};

/**
 * @brief   Stores pre-submit jobs grouped by submit index.
 *
 * Submit indices correspond to entries in the VkSubmitInfo/VkSubmitInfo2 arrays passed to VulkanSubmitJobExecutor.
 */
class VulkanSubmitJobPlan
{
  public:
    VulkanSubmitJobPlan()  = default;
    ~VulkanSubmitJobPlan() = default;

    /**
     * @brief   Append a job for one submit entry.
     *
     * @param   submit_index     index in the submit array where the job will run.
     * @param   job              callback that performs injected work and returns a signal semaphore.
     */
    void Push(uint32_t submit_index, VulkanSubmitJob job);

    /**
     * @brief   Access submit-indexed jobs.
     *
     * @return  vector of job lists indexed by submit index.
     */
    const std::vector<VulkanSubmitJobs>& GetSubmitJobs() const { return submit_jobs_; }

    /**
     * @brief   Access submit-indexed jobs for a specific submit index.
     *
     * @param   submit_index     index in the submit array.
     * @return  pointer to the VulkanSubmitJobs for the given index, or nullptr if none exist.
     */
    const VulkanSubmitJobs* GetSubmitJobsForIndex(uint32_t submit_index) const;

    /**
     * @brief   Check if there are jobs for a specific submit index.
     *
     * @param   submit_index     index in the submit array.
     * @return  true if there are jobs for the given index, false otherwise.
     */
    bool HasJobsForIndex(uint32_t submit_index) const;

  private:
    std::vector<VulkanSubmitJobs> submit_jobs_;
};

/**
 * @brief   Semaphore container used while rewriting submit wait lists.
 */
struct VulkanSubmitSemaphores
{
    std::vector<graphics::VulkanSemaphore> semaphores;
};

/**
 * @brief   Executes submit jobs and injects produced wait-semaphores into submit infos.
 *
 * This object owns backing storage for pointers written into submit structs (semaphores).
 * It must outlive the queue submit that consumes those structs.
 */
class VulkanSubmitJobExecutor
{
  public:
    /**
     * @brief   Execute jobs and inject wait-semaphores into VkSubmitInfo.
     *
     * @param   plan             submit-indexed jobs to execute.
     * @param   submit_infos     submit array to mutate in place.
     */
    void InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo> submit_infos);

    /**
     * @brief   Execute jobs and inject wait-semaphore infos into VkSubmitInfo2.
     *
     * @param   plan             submit-indexed jobs to execute.
     * @param   submit_infos2    submit2 array to mutate in place.
     */
    void InjectBefore(VulkanSubmitJobPlan plan, std::span<VkSubmitInfo2> submit_infos2);

  private:
    // Original waits stripped from each submit before injection.
    std::vector<VulkanSubmitSemaphores> original_wait_semaphores_;

    // Injected waits for VkSubmitInfo (binary semaphore handles).
    std::vector<std::vector<VkSemaphore>> injected_wait_semaphores_;

    // Injected waits for VkSubmitInfo2 (binary or timeline semaphore submit infos).
    std::vector<std::vector<VkSemaphoreSubmitInfo>> injected_wait_semaphore_infos_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SUBMIT_JOB_H
