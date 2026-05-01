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
#include <vector>
#include <unordered_map>

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
 * Submit indices correspond to entries in the VkSubmitInfo/VkSubmitInfo2 arrays passed to VulkanSubmitJobExecution.
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
 * @brief   Original wait semaphores stripped from a submit before injected jobs run.
 */
struct VulkanSubmitSemaphores
{
    std::vector<graphics::VulkanSemaphore> semaphores;
};

class VulkanSubmitJobExecutor;

/**
 * @brief   Executor-owned timeline semaphore used to order rewritten submit entries.
 *
 * `SerializeExecution()` creates one injected timeline semaphore for one `vkQueueSubmit()` call and reuses it for every
 * submit entry in that call. Each rewritten submit waits on the semaphore's current `target_value`, then signals the
 * next value. After all submits have been rewritten, `target_value` is the final value that must be reached before the
 * executor can safely destroy the semaphore.
 */
class VulkanInjectedSemaphore
{
  private:
    VkSemaphore handle_       = VK_NULL_HANDLE;
    uint64_t    target_value_ = 0;

    const VulkanDeviceInfo*            device_info_;
    const graphics::VulkanDeviceTable* device_table_;

  public:
    bool        HasReachedTargetValue() const;
    VkSemaphore GetHandle() const { return handle_; }
    uint64_t    GetTargetValue() const { return target_value_; }
    void        IncreaseTargetValue() { ++target_value_; }

    VulkanInjectedSemaphore(const VulkanDeviceInfo* device_info, const graphics::VulkanDeviceTable* table);
    ~VulkanInjectedSemaphore();

    VulkanInjectedSemaphore(const VulkanInjectedSemaphore&)            = delete;
    VulkanInjectedSemaphore& operator=(const VulkanInjectedSemaphore&) = delete;

    VulkanInjectedSemaphore(VulkanInjectedSemaphore&&);
    VulkanInjectedSemaphore& operator=(VulkanInjectedSemaphore&&) noexcept;
};

/**
 * @brief   Executor-owned timeline semaphore plus VkSubmitInfo2-compatible submit info.
 *
 * `info.value` is updated alongside `VulkanInjectedSemaphore::target_value` while rewriting a `VkSubmitInfo2` array so
 * the same injected semaphore can be used for the wait and signal pair in each submit entry.
 */
struct VulkanInjectedSemaphoreInfo
{
    VulkanInjectedSemaphore semaphore;
    VkSemaphoreSubmitInfo   info = { VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO };

    VulkanInjectedSemaphoreInfo(const VulkanDeviceInfo* device_info, const graphics::VulkanDeviceTable* table);
};

/**
 * @brief   An execution for Vulkan submit jobs.
 *
 * This is useful for both injecting new jobs and serializing submit entries within a single
 * `vkQueueSubmit()`/`vkQueueSubmit2()` call by making each `VkSubmitInfo`/`VkSubmitInfo2` wait on semaphores
 * signaled by the previous submit.
 * Submit serialization uses one executor-owned timeline semaphore for the full submit array. Each submit waits on the
 * current timeline value and signals the next value, so the timeline value advances once per submit entry.
 *
 * It does not preserve state across separate queue-submit calls.
 *
 * @note This object owns backing storage for pointers written into submit structs, including semaphore arrays, wait
 *       stage masks, timeline values, and injected pNext structures.
 *       It must outlive the queue submit that consumes those structs.
 */
class VulkanSubmitJobExecution
{
  public:
    VulkanSubmitJobExecution(VulkanSubmitJobExecutor& executor) : executor_(executor) {}

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
     * @brief Append a timeline wait semaphore to one VkSubmitInfo.
     */
    void AddWaitSemaphore(VkSubmitInfo& submit_info, const VulkanInjectedSemaphore& semaphore);

    /**
     * @brief Append a timeline signal semaphore to one VkSubmitInfo.
     */
    void AddSignalSemaphore(VkSubmitInfo& submit_info, const VulkanInjectedSemaphore& semaphore);

    /**
     * @brief Append a timeline wait semaphore info to one VkSubmitInfo2.
     */
    void AddWaitSemaphore(VkSubmitInfo2& submit_info, const VulkanInjectedSemaphoreInfo& semaphore);

    /**
     * @brief Append a timeline signal semaphore info to one VkSubmitInfo2.
     */
    void AddSignalSemaphore(VkSubmitInfo2& submit_info, const VulkanInjectedSemaphoreInfo& semaphore);

    /**
     * @brief Access mutable signal-semaphore storage for a VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, the current signal semaphores from
     * `submit_info` are copied into internal backing storage first.
     *
     * @param submit_info submit struct whose signal-semaphore storage should be accessed.
     * @return mutable vector owned by this executor and suitable for rewriting `submit_info` signal semaphores.
     */
    std::vector<VkSemaphore>& GetSignalSemaphores(VkSubmitInfo& submit_info);

    /**
     * @brief Access mutable timeline signal-value storage for one VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, current signal values from
     * `submit_info` are copied into internal backing storage first. If no timeline values exist, storage is initialized
     * with zero values matching `signalSemaphoreCount` so counts remain aligned when a timeline signal is appended.
     *
     * @param submit_info submit struct whose signal-values storage should be accessed.
     * @return mutable vector owned by this executor and suitable for rewriting `submit_info` signal values.
     */
    std::vector<uint64_t>& GetSignalValues(VkSubmitInfo& submit_info);

    /**
     * @brief   Access mutable wait-semaphore-info storage for one VkSubmitInfo2.
     *
     * If executor-owned storage has not been created for this submit yet, the current wait semaphore infos from
     * `submit_info` are copied into internal backing storage first.
     *
     * @param   submit_info      submit struct whose wait-semaphore-info storage should be accessed.
     * @return  mutable vector owned by this executor and suitable for rewriting `submit_info` wait semaphore infos.
     */
    std::vector<VkSemaphoreSubmitInfo>& GetWaitSemaphoreInfos(VkSubmitInfo2& submit_info);

    /**
     * @brief   Access mutable signal-semaphore-info storage for one VkSubmitInfo2.
     *
     * If executor-owned storage has not been created for this submit yet, the current signal semaphore infos from
     * `submit_info` are copied into internal backing storage first.
     *
     * @param   submit_info      submit struct whose signal-semaphore-info storage should be accessed.
     * @return  mutable vector owned by this executor and suitable for rewriting `submit_info` signal semaphore infos.
     */
    std::vector<VkSemaphoreSubmitInfo>& GetSignalSemaphoreInfos(VkSubmitInfo2& submit_info);

    /**
     * @brief  Access mutable wait dst stage mask storage for one VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, the current wait dst stage masks from
     * `submit_info` are copied into internal backing storage first. If `override` is true, the backing storage is
     * filled with `VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT`.
     *
     * @param   submit_info      submit struct whose wait dst stage masks should be accessed.
     * @param   override         if true, existing masks will be overridden with `VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT`.
     * @return  mutable vector owned by this executor and suitable for rewriting `submit_info` wait dst stage masks.
     */
    std::vector<VkPipelineStageFlags>& GetWaitDstStageMasks(VkSubmitInfo& submit_info, bool override = false);

    /**
     * @brief Access mutable timeline semaphore value storage for one VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, current wait values from `submit_info` are
     * copied into internal backing storage first. If no timeline values exist, storage is initialized with zero values
     * matching `waitSemaphoreCount` so counts remain aligned when a timeline wait is appended.
     *
     * @param  submit_info      submit struct whose timeline semaphore value storage should be accessed.
     * @return mutable vector owned by this executor and suitable for rewriting `submit_info` timeline semaphore values.
     */
    std::vector<uint64_t>& GetWaitValues(VkSubmitInfo& submit_info);

    /**
     * @brief   Access mutable timeline semaphore submit info for one VkSubmitInfo.
     *
     * If executor-owned storage has not been created for this submit yet, an existing `VkTimelineSemaphoreSubmitInfo`
     * is copied from the pNext chain or a new one is created and inserted into the chain.
     *
     * @param   submit_info      submit struct whose timeline semaphore submit info should be accessed.
     * @return  mutable timeline semaphore submit info owned by this executor and suitable for rewriting `submit_info`.
     */
    VkTimelineSemaphoreSubmitInfo& GetTimelineSemaphoreSubmitInfo(VkSubmitInfo& submit_info);

    /**
     * @brief Append one timeline wait/signal pair to a VkSubmitInfo and advance the target value.
     *
     * The submit waits on `semaphore.target_value`, then signals `semaphore.target_value + 1`.
     */
    void InjectSemaphore(VkSubmitInfo& submit_info, VulkanInjectedSemaphore& semaphore);

    /**
     * @brief Append one timeline wait/signal pair to a VkSubmitInfo2 and advance the target value.
     *
     * The submit waits on `semaphore_info.info.value`, then signals `semaphore_info.info.value + 1`.
     */
    void InjectSemaphore(VkSubmitInfo2& submit_info, VulkanInjectedSemaphoreInfo& semaphore_info);

    /**
     * @brief  SerializeExecution submit entries within one queue-submit call.
     *
     * Mutates the provided submit array to serialize execution order within one `vkQueueSubmit()` call. One injected
     * timeline semaphore is added to every submit: each submit waits on the current timeline value and signals the next
     * value. The first submit waits on the semaphore's initial value, and each subsequent submit waits for the value
     * signaled by the previous submit.
     *
     * @param  submit_infos     submit array to mutate in place.
     */
    void SerializeExecution(std::span<VkSubmitInfo> submit_infos);

    /**
     * @brief  SerializeExecution submit entries within one queue-submit call.
     *
     * Mutates the provided submit2 array to serialize execution order within one `vkQueueSubmit2()` call. One injected
     * timeline semaphore is added to every submit: each submit waits on the current timeline value and signals the next
     * value. The first submit waits on the semaphore's initial value, and each subsequent submit waits for the value
     * signaled by the previous submit.
     *
     * @param  submit_infos2    submit2 array to mutate in place.
     */
    void SerializeExecution(std::span<VkSubmitInfo2> submit_infos2);

  private:
    VulkanSubmitJobExecutor& executor_;

    /// Original waits stripped from each submit before injection, keyed by either `VkSubmitInfo*` or `VkSubmitInfo2*`.
    std::unordered_map<void*, VulkanSubmitSemaphores> original_wait_semaphores_;

    /// Injected waits for VkSubmitInfo (binary semaphore handles), keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<VkSemaphore>> injected_wait_semaphores_;

    /// Signal semaphores of a VkSubmitInfo, keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<VkSemaphore>> injected_signal_semaphores_;

    /// Injected timeline signal semaphore values, keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<uint64_t>> injected_signal_semaphore_values_;

    /// Injected timeline wait semaphore values, keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<uint64_t>> injected_wait_semaphore_values_;

    /// Injected `VkTimelineSemaphoreSubmitInfo` keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, VkTimelineSemaphoreSubmitInfo> injected_timeline_semaphore_infos_;

    /// Injected wait dst stage masks, keyed by `VkSubmitInfo*`.
    std::unordered_map<VkSubmitInfo*, std::vector<VkPipelineStageFlags>> injected_wait_dst_stage_masks_;

    /// Injected waits for VkSubmitInfo2 (binary or timeline semaphore submit infos), keyed by `VkSubmitInfo2*`.
    std::unordered_map<VkSubmitInfo2*, std::vector<VkSemaphoreSubmitInfo>> injected_wait_semaphore_infos_;

    /// Injected signals for VkSubmitInfo2 (binary or timeline semaphore submit infos), keyed by `VkSubmitInfo2*`.
    std::unordered_map<VkSubmitInfo2*, std::vector<VkSemaphoreSubmitInfo>> injected_signal_semaphore_infos_;
};

/**
 * @brief   Executor managing device resources for submit job execution.
 *
 * `VulkanSubmitJobExecutor` owns device-side resources used by `VulkanSubmitJobExecution`
 * instances to implement injected jobs and serialization of submit entries.
 * Create one executor per device and call `CreateExecution()` to obtain a short-lived
 * execution object that borrows the executor for the duration of a single queue-submit call.
 *
 * The executor creates and destroys semaphores used for chaining submits and
 * holds them so their handles remain valid while modified submit structures
 * are in use. The executor must outlive any `VulkanSubmitJobExecution` and
 * the actual `vkQueueSubmit`/`vkQueueSubmit2` call that consumes the modified
 * submit arrays.
 * Semaphores created for serialization remain tracked until their final target value has been reached; pruning checks
 * that target value before destroying them.
 *
 * @note Instances are intended to be per-device and may be reused across
 *       multiple queue-submit calls. `VulkanSubmitJobExecution` objects are
 *       short-lived and are not safe to use after the executor is destroyed.
 */
class VulkanSubmitJobExecutor
{
  public:
    /**
     * @brief Construct a submit job executor for a device.
     *
     * @param device_info Pointer to VulkanDeviceInfo for the device this executor manages.
     * @param device_table Pointer to the Vulkan device dispatch table used to create/destroy resources.
     */
    VulkanSubmitJobExecutor(const VulkanDeviceInfo* device_info, const graphics::VulkanDeviceTable* device_table);

    /**
     * @brief Create a short-lived execution object for a single queue-submit call.
     *
     * The returned `VulkanSubmitJobExecution` borrows this executor and is intended to be used to
     * inject job work and/or serialize submits for the duration of a single `vkQueueSubmit`/`vkQueueSubmit2` call.
     *
     * @return VulkanSubmitJobExecution execution object tied to this executor.
     */
    VulkanSubmitJobExecution CreateExecution() { return VulkanSubmitJobExecution(*this); }

    /**
     * @brief Create a timeline semaphore.
     *
     * Semaphores are stored internally and destroyed when their target value is reached or when the executor is
     * destroyed. A serialization pass uses one created semaphore across all submits in that queue-submit call.
     *
     * @return A pointer to the `VulkanInjectedSemaphore` just created or `nullptr` on error.
     */
    VulkanInjectedSemaphore* CreateTimelineSemaphore();

    /**
     * @brief Create a timeline semaphore info.
     *
     * Semaphores are stored internally and destroyed when their target value is reached or when the executor is
     * destroyed. A serialization pass uses one created semaphore across all submits in that queue-submit call.
     *
     * @return A pointer to the `VulkanInjectedSemaphoreInfo` just created or `nullptr` on error.
     */
    VulkanInjectedSemaphoreInfo* CreateTimelineSemaphoreInfo();

    /**
     * @brief Prunes timeline semaphores that have reached or exceeded their final target value.
     */
    void PruneSignaledTimelineSemaphores();

    /**
     * @brief Prunes timeline semaphore infos that have reached or exceeded their final target value.
     */
    void PruneSignaledTimelineSemaphoreInfos();

  private:
    const VulkanDeviceInfo*            device_info_  = nullptr;
    const graphics::VulkanDeviceTable* device_table_ = nullptr;

    std::vector<std::unique_ptr<VulkanInjectedSemaphore>>     injected_semaphores_;
    std::vector<std::unique_ptr<VulkanInjectedSemaphoreInfo>> injected_semaphore_infos_;
};

using VulkanPerDeviceSubmitJobExecutors = std::unordered_map<const VulkanDeviceInfo*, VulkanSubmitJobExecutor>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SUBMIT_JOB_H
