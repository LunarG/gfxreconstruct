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
#include "decode/common_object_info_table.h"

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
 * @brief   An executor for Vulkan submit jobs.
 *
 * This is useful for both injecting new jobs and serializing submit entries within a single
 * `vkQueueSubmit()`/`vkQueueSubmit2()` call by making each `VkSubmitInfo`/`VkSubmitInfo2` wait on semaphores
 * signaled by the previous submit.
 *
 * It does not preserve state across separate queue-submit calls.
 *
 * @note This object owns backing storage for pointers written into submit structs (semaphores).
 *       It must outlive the queue submit that consumes those structs.
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

    /**
     * @brief   Access mutable wait-semaphore storage for one VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, the current wait semaphores from
     * `submit_info` are copied into internal backing storage first.
     *
     * @param   submit_info      submit struct whose wait-semaphore storage should be accessed.
     * @return  mutable vector owned by this executor and suitable for rewriting `submit_info` wait semaphores.
     */
    std::vector<VkSemaphore>& GetWaitSemaphores(VkSubmitInfo& submit_info);

    /**
     * @brief   Access mutable wait-semaphore-info storage for one VkSubmitInfo2.
     *
     * If executor-owned storage has not been created for this submit yet, the current wait semaphore infos from
     * `submit_info` are copied into internal backing storage first.
     *
     * @param   submit_info      submit struct whose wait-semaphore-info storage should be accessed.
     * @return  mutable vector owned by this executor and suitable for rewriting `submit_info` wait semaphore infos.
     */
    std::vector<VkSemaphoreSubmitInfo>& GetWaitSemaphores(VkSubmitInfo2& submit_info);

    /**
     * @brief  SerializeExecution submit entries within one queue-submit call.
     *
     * Make each submit wait on semaphores signaled by the previous submit in the same
     * `vkQueueSubmit()` call. This mutates the provided submit array to insert the
     * necessary wait semaphores.
     *
     * @param  submit_infos     submit array to mutate in place.
     */
    void SerializeExecution(std::span<VkSubmitInfo> submit_infos);

    /**
     * @brief  SerializeExecution submit entries within one queue-submit call.
     *
     * Make each submit wait on semaphores signaled by the previous submit in the same
     * `vkQueueSubmit2()` call. This mutates the provided submit2 array to insert the
     * necessary wait semaphore infos.
     *
     * @param  submit_infos2    submit2 array to mutate in place.
     */
    void SerializeExecution(std::span<VkSubmitInfo2> submit_infos2);

  private:
    /// Original waits stripped from each submit before injection, keyed by either `VkSubmitInfo*` or `VkSubmitInfo2*`.
    std::unordered_map<void*, VulkanSubmitSemaphores> original_wait_semaphores_;

    /// Injected waits for VkSubmitInfo (binary semaphore handles), keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<VkSemaphore>> injected_wait_semaphores_;

    /// Injected waits for VkSubmitInfo2 (binary or timeline semaphore submit infos), keyed by `VkSubmitInfo2*`.
    std::unordered_map<VkSubmitInfo2*, std::vector<VkSemaphoreSubmitInfo>> injected_wait_semaphore_infos_;
};

using VulkanPerDeviceSubmitJobExecutors = std::unordered_map<const VulkanDeviceInfo*, VulkanSubmitJobExecutor>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SUBMIT_JOB_H
