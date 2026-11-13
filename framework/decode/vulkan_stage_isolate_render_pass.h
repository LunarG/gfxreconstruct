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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_RENDER_PASS_H
#define GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_RENDER_PASS_H

#include "generated/generated_vulkan_stage_command_buffer.h"
#include "format/api_call_log.h"

#include <span>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// This stage splits a primary command buffer of the app around each render pass,
/// so each pass runs in a command buffer of its own.
class VulkanStageIsolateRenderPass : public VulkanStageCommandBuffer
{
  private:
    // A Recording holds what the stage knows about one primary command buffer of the app.
    struct Recording
    {
        // Device and pool of the app's command buffer. Each new part is allocated from them.
        format::HandleId device_id = format::kNullHandleId;
        format::HandleId pool_id   = format::kNullHandleId;

        // Flags of the app's vkBeginCommandBuffer. Each new part begins with the same flags.
        VkCommandBufferUsageFlags begin_flags = 0;

        /// Working commands in the current part. The stage splits only when this is not zero,
        /// so a recording that starts with a render pass gets no empty part.
        /// Note: a state command is not counted as a working command.
        size_t working_command_count = 0;

        // Command buffer that receives the app's commands. It is the app's own id
        // until the first split, and the newest part after that.
        format::HandleId current_command_buffer_id = format::kNullHandleId;

        /// This flag is the core of the splitting algorithm, here's how it works:
        /// - before processing BeginRenderPass, the flag is set to indicate that a split should occur.
        /// - after processing EndRenderPass, the flag is set to indicate that a split should occur.
        /// - just before processing a command (OnCommand hook), if the flag is set, a split occurs.
        ///   so that the command is sent to a new command buffer.
        ///
        /// This means that, if no commands are processed after EndRenderPass, no split would occur.
        /// It also means that, if a BeginRenderPass is encountered after an EndRenderPass, a split
        /// will naturally occur before the new render pass begins.
        bool split_pending = false;

        /// Keeps the state commands of the recording to send them again at the start
        /// of a new command buffer after a split.
        format::ApiCallLog<ApiCallInfo> state_log;

        /// Command buffers that a split has ended, in recording order. The first one is the app's own.
        /// These ids, followed by current_command_buffer_id, are every command buffer of the recording.
        std::vector<format::HandleId> previous_command_buffer_ids;
    };

    // A CommandPoolInfo holds the parts that the stage can hand out again for one command pool of the app.
    struct CommandPoolInfo
    {
        /// Whether the pool has the VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT set.
        bool reset_bit = false;

        /// Command buffers that are available for reuse.
        std::vector<format::HandleId> spare_command_buffer_ids;

        /// Command buffers that wait for a pool reset.
        std::vector<format::HandleId> dirty_command_buffer_ids;
    };

  public:
    // Command pools

    void Process_vkCreateCommandPool(const ApiCallInfo& call_info, args::CreateCommandPool& args) override;
    void Process_vkDestroyCommandPool(const ApiCallInfo& call_info, args::DestroyCommandPool& args) override;
    void Process_vkResetCommandPool(const ApiCallInfo& call_info, args::ResetCommandPool& args) override;

    // Command buffers

    void Process_vkAllocateCommandBuffers(const ApiCallInfo& call_info, args::AllocateCommandBuffers& args) override;
    void Process_vkFreeCommandBuffers(const ApiCallInfo& call_info, args::FreeCommandBuffers& args) override;
    void Process_vkResetCommandBuffer(const ApiCallInfo& call_info, args::ResetCommandBuffer& args) override;
    void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override;
    void Process_vkEndCommandBuffer(const ApiCallInfo& call_info, args::EndCommandBuffer& args) override;

    // OnCommand sends every vkCmd* of a tracked command buffer to the current part.
    void OnCommand(const ApiCallInfo& call_info, format::HandleId& command_buffer_id) override;

    // Submits

    // Each submit override puts every command buffer of a split recording in place of the app's command buffer.
    // A submit that names no split command buffer is forwarded unchanged.
    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;

    // Begin render

    void Process_vkCmdBeginRenderPass(const ApiCallInfo& call_info, args::CmdBeginRenderPass& args) override;
    void Process_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, args::CmdBeginRenderPass2& args) override;
    void Process_vkCmdBeginRenderPass2KHR(const ApiCallInfo& call_info, args::CmdBeginRenderPass2KHR& args) override;
    void Process_vkCmdBeginRendering(const ApiCallInfo& call_info, args::CmdBeginRendering& args) override;
    void Process_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, args::CmdBeginRenderingKHR& args) override;

    // End render

    void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, args::CmdEndRenderPass& args) override;
    void Process_vkCmdEndRenderPass2(const ApiCallInfo& call_info, args::CmdEndRenderPass2& args) override;
    void Process_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, args::CmdEndRenderPass2KHR& args) override;
    void Process_vkCmdEndRendering(const ApiCallInfo& call_info, args::CmdEndRendering& args) override;
    void Process_vkCmdEndRenderingKHR(const ApiCallInfo& call_info, args::CmdEndRenderingKHR& args) override;

    // State commands

    void Process_vkCmdBindPipeline(const ApiCallInfo& call_info, args::CmdBindPipeline& args) override;
    void Process_vkCmdBindDescriptorSets(const ApiCallInfo& call_info, args::CmdBindDescriptorSets& args) override;
    void Process_vkCmdBindIndexBuffer(const ApiCallInfo& call_info, args::CmdBindIndexBuffer& args) override;
    void Process_vkCmdBindVertexBuffers(const ApiCallInfo& call_info, args::CmdBindVertexBuffers& args) override;
    void Process_vkCmdSetViewport(const ApiCallInfo& call_info, args::CmdSetViewport& args) override;
    void Process_vkCmdSetScissor(const ApiCallInfo& call_info, args::CmdSetScissor& args) override;
    void Process_vkCmdPushConstants(const ApiCallInfo& call_info, args::CmdPushConstants& args) override;

  private:
    // ProcessBeginRender marks a split before the render pass when the current part already holds work.
    template <typename ArgsT>
    void ProcessBeginRender(const ApiCallInfo& call_info, ArgsT& args);

    // ProcessEndRender marks a split after the render pass. The next command performs it.
    template <typename ArgsT>
    void ProcessEndRender(const ApiCallInfo& call_info, ArgsT& args);

    // ProcessStateCommand keeps a state command, so that each new part can reissue it.
    template <typename ArgsT>
    void ProcessStateCommand(const ApiCallInfo& call_info, ArgsT& args);

    // Split ends the current part and begins a new one, so the command that follows starts in its own
    // command buffer.
    void Split(Recording& recording, const ApiCallInfo& call_info);

    // Emit decodes the bytes of a call that the stage invents, and sends the call to the next consumers.
    void Emit(format::ApiCallId call_id, const ApiCallInfo& call_info, std::span<const uint8_t> bytes);

    /// Called after a split once recording has a new command buffer, to reissue all previously recorded state commands.
    void ReissueStateCommands(const Recording& recording);

    /// Appends the command buffers to submit in place of one command buffer of the app.
    /// Returns true when that command buffer was split.
    bool AppendCommandBufferIdsToSubmit(format::HandleId               app_command_buffer_id,
                                        std::vector<format::HandleId>& ids_to_submit) const;

    // Serves vkQueueSubmit2 and vkQueueSubmit2KHR, whose args have the same members.
    template <typename ArgsT>
    void ProcessQueueSubmit2(const ApiCallInfo& call_info, ArgsT& args);

    // Release gives the parts of a recording to its pool, and makes the app's command buffer current again.
    // The parts go to the spare list when the pool has the reset bit, and to the dirty list otherwise.
    void Release(Recording& recording);

    // Synthetic ids set the top bit. Capture ids count up from 1 and never reach it, so the two never collide.
    static constexpr format::HandleId kSyntheticBit = 1ull << 63;

    format::HandleId next_synthetic_id_ = 0;

    // The map holds the recording of each primary command buffer of the app, keyed by the app's id.
    std::unordered_map<format::HandleId, Recording> command_buffer_to_recording_map_;

    /// Holds information about command pools.
    std::unordered_map<format::HandleId, CommandPoolInfo> pool_info_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_RENDER_PASS_H