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

#include <span>
#include <unordered_map>

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

        // Commands in the current part. The stage splits only when this is not zero,
        // so a recording that starts with a render pass gets no empty part.
        size_t command_count = 0;

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
    };

  public:
    void Process_vkAllocateCommandBuffers(const ApiCallInfo& call_info, args::AllocateCommandBuffers& args) override
    {
        const auto* allocate_info = args.pAllocateInfo.GetMetaStructPointer();

        // vkCmdBeginRenderPass is valid only in a primary command buffer, so only primaries are tracked.
        // Commands on a secondary find no recording and pass through unchanged.
        if (allocate_info->decoded_value->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY)
        {
            const format::HandleId pool_id = allocate_info->commandPool;
            for (const format::HandleId command_buffer_id : args.pCommandBuffers.GetSpan())
            {
                command_buffer_to_recording_map_[command_buffer_id] = Recording{ args.device, pool_id };
            }
        }

        Forward(call_info, args);
    }

    void OnCommand(const ApiCallInfo& call_info, format::HandleId& command_buffer_id) override
    {
        if (auto entry = command_buffer_to_recording_map_.find(command_buffer_id);
            entry != command_buffer_to_recording_map_.end())
        {
            Recording& recording = entry->second;

            if (recording.split_pending)
            {
                Split(recording, call_info);
            }

            recording.command_count++;

            // Send the command to the current part. Before the first split, the current part is
            // the app's own command buffer.
            command_buffer_id = recording.current_command_buffer_id;
        }
    }

    void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override
    {
        if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
            entry != command_buffer_to_recording_map_.end())
        {
            // Each recording starts in the app's own command buffer.
            Recording& recording                = entry->second;
            recording.current_command_buffer_id = args.commandBuffer;
            recording.command_count             = 0;
            recording.begin_flags               = args.pBeginInfo.GetPointer()->flags;
            recording.split_pending             = false;
        }

        Forward(call_info, args);
    }

    void Process_vkEndCommandBuffer(const ApiCallInfo& call_info, args::EndCommandBuffer& args) override
    {
        if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
            entry != command_buffer_to_recording_map_.end())
        {
            Recording& recording    = entry->second;
            recording.split_pending = false;

            // Explanation of why this works:
            // Case 1, no split happens:
            // - recording.current_command_buffer_id is the original app command buffer id
            //   which means it is just the normal course of events.
            // Case 2, a split has occurred:
            // - original command buffer has already been ended by the split
            // - recording.current_command_buffer_id is the new synthetic command buffer id
            //   which must be ended, so we redirect the End call to it.
            args.commandBuffer = recording.current_command_buffer_id;
        }
        Forward(call_info, args);
    }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo& call_info, args::CmdBeginRenderPass& args) override
    {
        ProcessBeginRender(call_info, args);
    }

    void Process_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, args::CmdBeginRenderPass2& args) override
    {
        ProcessBeginRender(call_info, args);
    }

    void Process_vkCmdBeginRenderPass2KHR(const ApiCallInfo& call_info, args::CmdBeginRenderPass2KHR& args) override
    {
        ProcessBeginRender(call_info, args);
    }

    void Process_vkCmdBeginRendering(const ApiCallInfo& call_info, args::CmdBeginRendering& args) override
    {
        ProcessBeginRender(call_info, args);
    }

    void Process_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, args::CmdBeginRenderingKHR& args) override
    {
        ProcessBeginRender(call_info, args);
    }

    void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, args::CmdEndRenderPass& args) override
    {
        ProcessEndRender(call_info, args);
    }

    void Process_vkCmdEndRenderPass2(const ApiCallInfo& call_info, args::CmdEndRenderPass2& args) override
    {
        ProcessEndRender(call_info, args);
    }

    void Process_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, args::CmdEndRenderPass2KHR& args) override
    {
        ProcessEndRender(call_info, args);
    }

    void Process_vkCmdEndRendering(const ApiCallInfo& call_info, args::CmdEndRendering& args) override
    {
        ProcessEndRender(call_info, args);
    }

    void Process_vkCmdEndRenderingKHR(const ApiCallInfo& call_info, args::CmdEndRenderingKHR& args) override
    {
        ProcessEndRender(call_info, args);
    }

  private:
    template <typename ArgsT>
    void ProcessBeginRender(const ApiCallInfo& call_info, ArgsT& args)
    {
        if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
            entry != command_buffer_to_recording_map_.end())
        {
            Recording& recording = entry->second;
            // Instead of splitting immediately here, we can set a flag to indicate
            // that a split should occur before the next command.
            // In this case, the next command is expected to be the beginning of a renderpass/rendering.
            recording.split_pending = recording.command_count > 0;
        }

        ProcessCommand(call_info, args);
    }

    template <typename ArgsT>
    void ProcessEndRender(const ApiCallInfo& call_info, ArgsT& args)
    {
        // Save the original command buffer ID before processing the command,
        // as `args.commandBuffer` may be modified during processing.
        const format::HandleId original_command_buffer_id = args.commandBuffer;

        ProcessCommand(call_info, args);

        if (auto entry = command_buffer_to_recording_map_.find(original_command_buffer_id);
            entry != command_buffer_to_recording_map_.end())
        {
            Recording& recording = entry->second;
            // Do not split yet, just mark that a split is pending for this recording.
            // Reason is that we might not need to split if the next call is `vkEndCommandBuffer`,
            // or we might want to emit different calls if the next command is `vkBeginRenderPass`
            // in case we want to avoid an empty recording between render passes.
            recording.split_pending = true;
        }
    }

    // Split ends the current part and begins a new one, so the command that follows starts in its own
    // command buffer.
    void Split(Recording& recording, const ApiCallInfo& call_info);

    // Emit decodes the bytes of a call that the stage invents, and sends the call to the next consumers.
    void Emit(format::ApiCallId call_id, const ApiCallInfo& call_info, std::span<const uint8_t> bytes);

    // Synthetic ids set the top bit. Capture ids count up from 1 and never reach it, so the two never collide.
    static constexpr format::HandleId kSyntheticBit = 1ull << 63;

    format::HandleId next_synthetic_id_ = 0;

    // The map holds the recording of each primary command buffer of the app, keyed by the app's id.
    std::unordered_map<format::HandleId, Recording> command_buffer_to_recording_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_RENDER_PASS_H