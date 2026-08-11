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
#ifndef GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H
#define GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H

#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_state_recording_decoder.h"
#include "decode/vulkan_submit_job.h"
#include "util/defines.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// This helper class manages command buffer handles addressing cases where a single command buffer is reset and
/// recorded multiple times. In such cases, after splitting the command buffer for the first time, a reset is expected
/// before the next recording, and we want to avoid splitting again and instead reuse the handles of the first split.
class VulkanCommandBufferAssociatedInfo
{
  private:
    const VulkanDeviceInfo*            device_info_  = nullptr;
    const graphics::VulkanDeviceTable* device_table_ = nullptr;
    CommonObjectInfoTable*             object_table_ = nullptr;

    VulkanInjectedSemaphore split_semaphore_;

    VkCommandBuffer original_handle_ = VK_NULL_HANDLE;

    /// Associated command buffer handles, namely command buffers created at split-time that are associated with the
    /// original command buffer. This does not include the original handle itself.
    std::vector<VkCommandBuffer> associated_handles_;

    /// The index of the next associated handle to use. This is used to retrieve the next handle at each split point.
    /// When a command buffer is split for the first time, a new command buffer is created for the split and stored in
    /// the associated handles vector. In case of a subsequent split, the index resets to 0 to reuse any associated
    /// handles that were created at the first split, before creating new ones if needed.
    size_t next_associated_index_ = 0;

    /// The command buffer handles of the current split.
    /// First handle in the vector is the original command buffer. The rest are other handles in
    /// order for each split. The very last handle, which is the most recent split, is not stored in this vector,
    /// but is instead stored in the command buffer info's handle field.
    std::vector<VkCommandBuffer> split_handles_;

  public:
    VulkanCommandBufferAssociatedInfo(const VulkanDeviceInfo*            device_info,
                                      const graphics::VulkanDeviceTable* device_table,
                                      CommonObjectInfoTable*             object_table,
                                      format::HandleId                   command_buffer_id);

    VulkanCommandBufferAssociatedInfo(const VulkanCommandBufferAssociatedInfo&)            = delete;
    VulkanCommandBufferAssociatedInfo& operator=(const VulkanCommandBufferAssociatedInfo&) = delete;
    VulkanCommandBufferAssociatedInfo(VulkanCommandBufferAssociatedInfo&&)                 = default;
    VulkanCommandBufferAssociatedInfo& operator=(VulkanCommandBufferAssociatedInfo&&)      = default;
    ~VulkanCommandBufferAssociatedInfo()                                                   = default;

    void ReplaceWithNewHandle(VulkanCommandBufferInfo* command_buffer_info);

    [[nodiscard]] const std::vector<VkCommandBuffer>& GetAssociatedHandles() const { return associated_handles_; }

    void PushSplitHandle(VkCommandBuffer handle) { split_handles_.push_back(handle); }
    [[nodiscard]] const std::vector<VkCommandBuffer>& GetSplitHandles() const { return split_handles_; }

    [[nodiscard]] VkCommandBuffer ResetAssociatedHandles();

    [[nodiscard]] VulkanInjectedSemaphore& GetSplitSemaphore() { return split_semaphore_; }

    [[nodiscard]] VkCommandBuffer FreeAssociatedHandles(VkCommandPool pool);
};

class VulkanCommandBufferUtil
{
  public:
    VulkanCommandBufferUtil(const VulkanDeviceInfo*            device_info,
                            const graphics::VulkanDeviceTable* device_table,
                            CommonObjectInfoTable*             object_table,
                            VulkanStateRecordingDecoder*       decoder);

    ~VulkanCommandBufferUtil() = default;

    VulkanCommandBufferUtil(const VulkanCommandBufferUtil&)            = delete;
    VulkanCommandBufferUtil& operator=(const VulkanCommandBufferUtil&) = delete;
    VulkanCommandBufferUtil(VulkanCommandBufferUtil&&)                 = default;
    VulkanCommandBufferUtil& operator=(VulkanCommandBufferUtil&&)      = default;

    void ReplaceWithAssociatedCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    void SplitCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                     queue_info,
                                        const std::span<VkSubmitInfo>              current_submits_span,
                                        const std::span<graphics::VulkanSemaphore> wait_semaphores = {});

    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                     queue_info,
                                        const std::span<VkSubmitInfo2>             current_submits_span,
                                        const std::span<graphics::VulkanSemaphore> wait_semaphores = {});

    void FreeCommandBuffers(VkCommandPool command_pool, const std::span<const format::HandleId> command_buffer_ids);

    /// @brief To be called after resetting the current command buffer.
    /// @param command_buffer_info The command buffer info structure to reset.
    void ResetCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    void BeginCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

  private:
    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                        queue_info,
                                        const std::span<std::vector<VkCommandBuffer>> current_submits_cmdbufs,
                                        const std::span<graphics::VulkanSemaphore>    wait_semaphores = {});

    std::vector<std::vector<VkCommandBuffer>>
    GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo> submits_span);
    std::vector<std::vector<VkCommandBuffer>>
    GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo2> submits_span);

    VulkanCommandBufferAssociatedInfo& GetOrCreateAssociatedInfo(format::HandleId command_buffer_id);
    VulkanCommandBufferAssociatedInfo* GetAssociatedInfo(format::HandleId command_buffer_id);

    const VulkanDeviceInfo*            device_info_  = nullptr;
    const graphics::VulkanDeviceTable* device_table_ = nullptr;
    CommonObjectInfoTable*             object_table_ = nullptr;
    VulkanStateRecordingDecoder*       decoder_      = nullptr;

    /// Map from the command buffer ID to the structure representing the split.
    std::unordered_map<format::HandleId, VulkanCommandBufferAssociatedInfo> split_infos_;

    /// Map from the command buffer handles to the original ID.
    std::unordered_map<VkCommandBuffer, format::HandleId> original_command_buffer_id_;

    /// Flag to indicate whether the decoder is currently reissuing command buffer state. This is used to prevent
    /// splitting command buffers while reissuing state, which could lead to infinite recursion.
    bool reissuing_command_buffer_state_ = false;
};

using VulkanPerDeviceCommandBufferUtils = std::unordered_map<const VulkanDeviceInfo*, VulkanCommandBufferUtil>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H
