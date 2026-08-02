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

#ifndef GFXRECON_VULKAN_SUBMIT_INFO_HELPER_H
#define GFXRECON_VULKAN_SUBMIT_INFO_HELPER_H

#include "graphics/vulkan_injected_call_table.h"
#include "graphics/vulkan_semaphore_util.h"
#include "decode/vulkan_object_info.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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
    graphics::VulkanSemaphore semaphore_{ VK_NULL_HANDLE };

    const VulkanDeviceInfo*                  device_info_;
    const graphics::VulkanInjectedDeviceCallsTable* device_table_;

  public:
    bool                      HasReachedTargetValue() const;
    graphics::VulkanSemaphore GetSemaphore() const { return semaphore_; }
    VkSemaphore               GetHandle() const { return semaphore_.semaphore; }
    uint64_t                  GetTargetValue() const { return semaphore_.timeline_value; }
    void                      IncreaseTargetValue() { semaphore_.timeline_value++; }

    VulkanInjectedSemaphore(const VulkanDeviceInfo* device_info, const graphics::VulkanInjectedDeviceCallsTable* table);
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

    VulkanInjectedSemaphoreInfo(const VulkanDeviceInfo* device_info, const graphics::VulkanInjectedDeviceCallsTable* table);
};

/**
 * @brief   Original wait semaphores stripped from a submit before injected jobs run.
 */
struct VulkanSubmitSemaphores
{
    std::vector<graphics::VulkanSemaphore> semaphores;
};

class VulkanSubmitInfoHelper
{
  private:
    VkSubmitInfo& submit_info_;

    /// Backing storage for this submit's wait semaphores (binary semaphore handles).
    std::vector<VkSemaphore> wait_semaphores_;

    /// Backing storage for this submit's signal semaphores.
    std::vector<VkSemaphore> signal_semaphores_;

    /// Backing storage for this submit's timeline signal-semaphore values.
    std::vector<uint64_t> signal_semaphore_values_;

    /// Backing storage for this submit's timeline wait-semaphore values.
    std::vector<uint64_t> wait_semaphore_values_;

    /// Owned `VkTimelineSemaphoreSubmitInfo` inserted into this submit's pNext chain.
    VkTimelineSemaphoreSubmitInfo timeline_semaphore_info_{ VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO };

    /// Backing storage for this submit's wait dst stage masks.
    std::vector<VkPipelineStageFlags> wait_dst_stage_masks_;

    void CopyWaitSemaphores();
    void CopyWaitDstStageMasks();
    void CopyWaitValues();
    void CopySignalSemaphores();
    void CopySignalValues();
    void CopyTimelineSemaphoreSubmitInfo();

  public:
    VulkanSubmitInfoHelper(VkSubmitInfo& submit_info);
    ~VulkanSubmitInfoHelper() = default;

    VulkanSubmitInfoHelper(const VulkanSubmitInfoHelper&)            = delete;
    VulkanSubmitInfoHelper& operator=(const VulkanSubmitInfoHelper&) = delete;
    VulkanSubmitInfoHelper(VulkanSubmitInfoHelper&&)                 = delete;
    VulkanSubmitInfoHelper& operator=(VulkanSubmitInfoHelper&&)      = delete;

    /**
     * @brief Append a binary wait semaphore.
     */
    void AddWaitSemaphore(VkSemaphore semaphore);

    /**
     * @brief Append a VulkanSemaphore wait semaphore.
     */
    void AddWaitSemaphore(const graphics::VulkanSemaphore& semaphore);

    /**
     * @brief Append a timeline wait semaphore.
     */
    void AddWaitSemaphore(const VulkanInjectedSemaphore& semaphore);

    /**
     * @brief Append a timeline signal semaphore.
     */
    void AddSignalSemaphore(const VulkanInjectedSemaphore& semaphore);

    /**
     * @brief Append one timeline wait/signal pair to a VkSubmitInfo and advance the target value.
     *
     * The submit waits on `semaphore.target_value`, then signals `semaphore.target_value + 1`.
     */
    void InjectSemaphore(VulkanInjectedSemaphore& semaphore);
};

class VulkanSubmitInfo2Helper
{
  private:
    VkSubmitInfo2& submit_info2_;

    /// Injected waits for VkSubmitInfo2 (binary or timeline semaphore submit infos).
    std::vector<VkSemaphoreSubmitInfo> wait_semaphore_infos_;

    /// Injected signals for VkSubmitInfo2 (binary or timeline semaphore submit infos).
    std::vector<VkSemaphoreSubmitInfo> signal_semaphore_infos_;

    void CopyWaitSemaphoreInfos();
    void CopySignalSemaphoreInfos();

  public:
    VulkanSubmitInfo2Helper(VkSubmitInfo2& submit_info2);
    ~VulkanSubmitInfo2Helper() = default;

    VulkanSubmitInfo2Helper(const VulkanSubmitInfo2Helper&)            = delete;
    VulkanSubmitInfo2Helper& operator=(const VulkanSubmitInfo2Helper&) = delete;
    VulkanSubmitInfo2Helper(VulkanSubmitInfo2Helper&&)                 = delete;
    VulkanSubmitInfo2Helper& operator=(VulkanSubmitInfo2Helper&&)      = delete;

    /**
     * @brief Append a binary wait semaphore info to one VkSubmitInfo2.
     */
    void AddWaitSemaphore(VkSemaphoreSubmitInfo semaphore);

    /**
     * @brief Append a timeline wait semaphore info to one VkSubmitInfo2.
     */
    void AddWaitSemaphore(const VulkanInjectedSemaphoreInfo& semaphore);

    /**
     * @brief Append a timeline signal semaphore info to one VkSubmitInfo2.
     */
    void AddSignalSemaphore(const VulkanInjectedSemaphoreInfo& semaphore);

    /**
     * @brief Append one timeline wait/signal pair to a VkSubmitInfo2 and advance the target value.
     *
     * The submit waits on `semaphore_info.info.value`, then signals `semaphore_info.info.value + 1`.
     */
    void InjectSemaphore(VulkanInjectedSemaphoreInfo& semaphore_info);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_SUBMIT_INFO_HELPER_H
