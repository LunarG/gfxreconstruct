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
#include "graphics/vulkan_injected_calls.h"
#include "util/defines.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// @brief Sizes the command buffer's layout map for an image, so that later SetLayout calls have somewhere to record.
///
/// Every subresource of the new map starts VK_IMAGE_LAYOUT_UNDEFINED, which marks it as untouched by this command
/// buffer. Does nothing if the map already exists.
/// @param command_buffer_info Command buffer that records the layout transitions.
/// @param image_info Image whose subresources the map is sized from.
void InitializeCommandBufferImageLayouts(VulkanCommandBufferInfo* command_buffer_info,
                                         const VulkanImageInfo*   image_info);

/// @brief Handles and semaphore that belong to the splits of one command buffer.
///
/// Replay can split one recording across multiple command buffers. This class owns the
/// extra handles, named associated handles, that replay allocates for the splits of one
/// original command buffer. When the application resets and records the command buffer
/// again, a new split reuses these handles. When all handles are in use, replay
/// allocates more. This class also owns the timeline semaphore that orders the submits
/// of the split parts.
class VulkanCommandBufferAssociatedInfo
{
  private:
    const VulkanDeviceInfo*             device_info_ = nullptr;
    graphics::VulkanInjectedDeviceCalls device_table_;
    CommonObjectInfoTable*              object_table_ = nullptr;

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
    /// @brief Stores the original handle of the command buffer with the given capture ID.
    /// @param device_info Device that owns the command buffer.
    /// @param device_table Dispatch table of that device.
    /// @param object_table Table that maps capture IDs to replay objects.
    /// @param command_buffer_id Capture ID of the original command buffer.
    VulkanCommandBufferAssociatedInfo(const VulkanDeviceInfo*                    device_info,
                                      const graphics::VulkanInjectedDeviceCalls& device_table,
                                      CommonObjectInfoTable*                     object_table,
                                      format::HandleId                           command_buffer_id);

    VulkanCommandBufferAssociatedInfo(const VulkanCommandBufferAssociatedInfo&)            = delete;
    VulkanCommandBufferAssociatedInfo& operator=(const VulkanCommandBufferAssociatedInfo&) = delete;
    VulkanCommandBufferAssociatedInfo(VulkanCommandBufferAssociatedInfo&&)                 = default;
    VulkanCommandBufferAssociatedInfo& operator=(VulkanCommandBufferAssociatedInfo&&)      = default;
    ~VulkanCommandBufferAssociatedInfo()                                                   = default;

    /// @brief Sets the handle of the command buffer info to the next associated handle.
    ///
    /// If no handle is free, the function allocates more. The new handle is not reset and
    /// is not in the recording state.
    /// @param command_buffer_info Command buffer info that receives the new handle.
    void ReplaceWithNewHandle(VulkanCommandBufferInfo* command_buffer_info);

    /// @return All handles allocated for splits of this command buffer, without the original handle.
    [[nodiscard]] const std::vector<VkCommandBuffer>& GetAssociatedHandles() const { return associated_handles_; }

    /// @brief Stores the handle of a finished part of the current recording.
    void PushSplitHandle(VkCommandBuffer handle) { split_handles_.push_back(handle); }

    /// @return Handles of the finished parts of the current recording, in record order.
    /// The newest part is not included: its handle is in the command buffer info.
    [[nodiscard]] const std::vector<VkCommandBuffer>& GetSplitHandles() const { return split_handles_; }

    /// @brief Resets all associated command buffers and clears the current split.
    /// @return The original handle. The caller must put it back in the command buffer info.
    [[nodiscard]] VkCommandBuffer ResetAssociatedHandles();

    /// @return The timeline semaphore that orders the submits of the split parts.
    [[nodiscard]] VulkanInjectedSemaphore& GetSplitSemaphore() { return split_semaphore_; }

    /// @brief Frees all associated command buffers and clears the current split.
    /// @param pool Pool that owns the command buffers.
    /// @return The original handle. The caller must put it back in the command buffer info.
    [[nodiscard]] VkCommandBuffer FreeAssociatedHandles(VkCommandPool pool);
};

/// @brief Splits command buffers during replay and submits the split parts in order.
///
/// The `--isolate-render-passes` replay option puts each render pass in its own queue
/// submit. For this option, replay calls SplitCommandBuffer() at each render pass
/// boundary. The call ends the current command buffer and continues the recording in a
/// fresh one. At queue submission, SubmitPreviouslySplitCommandBuffers() submits the
/// earlier parts first, one queue submit for each part. An injected timeline semaphore
/// keeps these submits in order. The reset, begin, and free entry points keep the split
/// handles and the recorded state of the decoder consistent. Replay creates one instance
/// of this class for each device (see VulkanPerDeviceCommandBufferUtils).
class VulkanCommandBufferUtil
{
  public:
    /// @param device_info Device that this utility serves.
    /// @param device_table Dispatch table of that device.
    /// @param object_table Table that maps capture IDs to replay objects.
    /// @param decoder Decoder that records and reissues command buffer state.
    VulkanCommandBufferUtil(const VulkanDeviceInfo*                    device_info,
                            const graphics::VulkanInjectedDeviceCalls& device_table,
                            CommonObjectInfoTable*                     object_table,
                            VulkanStateRecordingDecoder*               decoder);

    ~VulkanCommandBufferUtil() = default;

    VulkanCommandBufferUtil(const VulkanCommandBufferUtil&)            = delete;
    VulkanCommandBufferUtil& operator=(const VulkanCommandBufferUtil&) = delete;
    VulkanCommandBufferUtil(VulkanCommandBufferUtil&&)                 = default;
    VulkanCommandBufferUtil& operator=(VulkanCommandBufferUtil&&)      = default;

    /// @brief Replaces the handle of the command buffer with a fresh associated handle.
    ///
    /// The function resets the new handle. Later replay calls on this command buffer go to
    /// the new handle.
    /// @param command_buffer_info Command buffer info that receives the new handle.
    void ReplaceWithAssociatedCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    /// @brief Ends the current recording and continues it in a fresh command buffer.
    ///
    /// The function ends the current handle, replaces it with an associated handle, and
    /// begins the new handle. It then reissues the recorded state commands, so the new
    /// part starts with the same state. The function does nothing while a reissue is in
    /// progress.
    /// @param command_buffer_info Command buffer that is in the recording state.
    void SplitCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    /// @brief Submits the earlier parts of the split command buffers found in the given submits.
    ///
    /// Call this function before you replay the queue submission itself. For each command
    /// buffer that was split, the earlier parts go to the queue first, one queue submit
    /// for each part. An injected timeline semaphore orders these submits. The wait
    /// semaphores gate only the first of these submits.
    /// @param queue_info Queue that receives the submits.
    /// @param current_submits_span Submit infos of the queue submission that replay is about to make.
    /// @param wait_semaphores Semaphores that the first submit waits on.
    /// @return Semaphore that the queue submission of the caller must wait on. If there
    /// was nothing to submit, the handle of the semaphore is VK_NULL_HANDLE.
    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                     queue_info,
                                        const std::span<VkSubmitInfo>              current_submits_span,
                                        const std::span<graphics::VulkanSemaphore> wait_semaphores = {});

    /// @brief Overload of SubmitPreviouslySplitCommandBuffers() for vkQueueSubmit2 submissions.
    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                     queue_info,
                                        const std::span<VkSubmitInfo2>             current_submits_span,
                                        const std::span<graphics::VulkanSemaphore> wait_semaphores = {});

    /// @brief Removes the split state of command buffers that the application frees.
    ///
    /// When replay frees command buffers, call this function. The function clears the
    /// recorded state of each command buffer. If a command buffer was split, the function
    /// frees its associated handles and restores its original handle.
    /// @param command_pool Pool that owns the command buffers.
    /// @param command_buffer_ids Capture IDs of the command buffers.
    void FreeCommandBuffers(VkCommandPool command_pool, const std::span<const format::HandleId> command_buffer_ids);

    /// @brief Clears the replay state of a reset command buffer.
    ///
    /// Call this function after the command buffer reset. The function clears the recorded
    /// state. If the command buffer was split, the function also resets its associated
    /// handles and restores its original handle.
    /// @param command_buffer_info Command buffer that was reset.
    void ResetCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

    /// @brief Prepares a command buffer for a new recording.
    ///
    /// Call this function before replay begins the command buffer. A new recording makes
    /// the recorded state of the previous one invalid, so the function clears it. If the
    /// pool has the VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT flag, vkBeginCommandBuffer does an implicit
    /// reset. In that case, if the command buffer was split, the function resets its
    /// associated handles and restores its original handle.
    /// @param command_buffer_info Command buffer that replay is about to begin.
    void BeginCommandBuffer(VulkanCommandBufferInfo* command_buffer_info);

  private:
    /// Shared implementation of the public overloads, on plain lists of command buffer handles.
    graphics::VulkanSemaphore
    SubmitPreviouslySplitCommandBuffers(const VulkanQueueInfo*                        queue_info,
                                        const std::span<std::vector<VkCommandBuffer>> current_submits_cmdbufs,
                                        const std::span<graphics::VulkanSemaphore>    wait_semaphores = {});

    /// Collects the command buffer handles of each submit info.
    std::vector<std::vector<VkCommandBuffer>>
    GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo> submits_span);
    std::vector<std::vector<VkCommandBuffer>>
    GetCommandBuffersFromSubmitInfos(const std::span<VkSubmitInfo2> submits_span);

    /// Returns the split info of the command buffer. Creates it on first use.
    VulkanCommandBufferAssociatedInfo& GetOrCreateAssociatedInfo(format::HandleId command_buffer_id);

    /// Returns the split info of the command buffer, or nullptr if it was never split.
    VulkanCommandBufferAssociatedInfo* GetAssociatedInfo(format::HandleId command_buffer_id);

    const VulkanDeviceInfo*             device_info_ = nullptr;
    graphics::VulkanInjectedDeviceCalls device_table_;
    CommonObjectInfoTable*              object_table_ = nullptr;
    VulkanStateRecordingDecoder*        decoder_      = nullptr;

    /// Map from the command buffer ID to the structure representing the split.
    std::unordered_map<format::HandleId, VulkanCommandBufferAssociatedInfo> split_infos_;

    /// Map from the command buffer handles to the original ID.
    std::unordered_map<VkCommandBuffer, format::HandleId> original_command_buffer_id_;

    /// Flag to indicate whether the decoder is currently reissuing command buffer state. This is used to prevent
    /// splitting command buffers while reissuing state, which could lead to infinite recursion.
    bool reissuing_command_buffer_state_ = false;
};

/// One VulkanCommandBufferUtil for each device.
using VulkanPerDeviceCommandBufferUtils = std::unordered_map<const VulkanDeviceInfo*, VulkanCommandBufferUtil>;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_COMMAND_BUFFER_UTIL_H
