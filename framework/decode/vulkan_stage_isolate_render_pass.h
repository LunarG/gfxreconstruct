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

// This stage splits a primary command buffer of the app before each render pass that follows other
// commands. The app's commands after the split go to a new command buffer, which the stage allocates.
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
        }
        Forward(call_info, args);
    }

    void Process_vkEndCommandBuffer(const ApiCallInfo& call_info, args::EndCommandBuffer& args) override
    {
        if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
            entry != command_buffer_to_recording_map_.end())
        {
            // A split has already ended the app's command buffer, so the app's End goes to the current part.
            // Before any split, the current part is the app's own command buffer.
            args.commandBuffer = entry->second.current_command_buffer_id;
        }
        Forward(call_info, args);
    }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo& call_info, args::CmdBeginRenderPass& args) override
    {
        // Split before ProcessCommand, so that ProcessCommand sends the render pass to the new part.
        if (auto entry = command_buffer_to_recording_map_.find(args.commandBuffer);
            entry != command_buffer_to_recording_map_.end())
        {
            Recording& recording = entry->second;

            if (recording.command_count > 0)
            {
                Split(recording, call_info);
            }
        }
        ProcessCommand(call_info, args);
    }

  private:
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