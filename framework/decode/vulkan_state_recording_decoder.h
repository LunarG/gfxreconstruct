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

#ifndef GFXRECON_DECODE_VULKAN_STATE_RECORDING_DECODER_H
#define GFXRECON_DECODE_VULKAN_STATE_RECORDING_DECODER_H

#include "format/api_call_log.h"
#include "generated/generated_vulkan_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanStateCommandRecorder
{
  public:
    /// Log of encoded API calls; each entry keeps the original block's ApiCallInfo, replayed verbatim.
    using CommandBufferLog = format::ApiCallLog<ApiCallInfo>;

    /// Records the undecoded buffer of a Vulkan API call for reissuing later.
    void
    Record(format::ApiCallId call_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
    {
        // The call is expected to be a command buffer call, so the first parameter is the command buffer handle.
        format::HandleId command_buffer_id = 0;
        ValueDecoder::DecodeHandleIdValue(parameter_buffer, buffer_size, &command_buffer_id);

        per_cb_log_[command_buffer_id].Append(call_id, call_info, parameter_buffer, buffer_size);
    }

    const CommandBufferLog* GetCommandBufferLog(format::HandleId command_buffer_id) const
    {
        const auto it = per_cb_log_.find(command_buffer_id);
        if (it != per_cb_log_.end())
        {
            return &it->second;
        }
        return nullptr;
    }

    void ClearRecordedState(format::HandleId command_buffer_id) { per_cb_log_.erase(command_buffer_id); }
    void Clear() { per_cb_log_.clear(); }

  private:
    std::unordered_map<format::HandleId, CommandBufferLog> per_cb_log_;
};

class VulkanStateRecordingDecoder : public VulkanDecoder
{
  public:
    void DecodeFunctionCall(format::ApiCallId  call_id,
                            const ApiCallInfo& call_info,
                            const uint8_t*     parameter_buffer,
                            size_t             buffer_size) override
    {
        if (recording_ && IsVulkanStateCommand(call_id))
        {
            state_recorder_.Record(call_id, call_info, parameter_buffer, buffer_size);
        }
        VulkanDecoder::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
    }

    bool IsVulkanStateCommand(format::ApiCallId call_id) const
    {
        switch (call_id)
        {
            case format::ApiCall_vkCmdBindDescriptorSets:
            case format::ApiCall_vkCmdBindIndexBuffer:
            case format::ApiCall_vkCmdBindPipeline:
            case format::ApiCall_vkCmdBindVertexBuffers:
            case format::ApiCall_vkCmdSetViewport:
            case format::ApiCall_vkCmdSetScissor:
            case format::ApiCall_vkCmdPushConstants:
                return true;
            default:
                break;
        }
        return false;
    }

    void ReissueCommandBufferState(format::HandleId command_buffer_id)
    {
        const VulkanStateCommandRecorder::CommandBufferLog* command_buffer_log =
            state_recorder_.GetCommandBufferLog(command_buffer_id);
        if (command_buffer_log == nullptr)
        {
            return;
        }

        recording_ = false;

        command_buffer_log->ForEach([this, command_buffer_id](format::ApiCallId  call_id,
                                                              const ApiCallInfo& call_info,
                                                              const uint8_t*     parameter_buffer,
                                                              size_t             buffer_size) {
            GFXRECON_LOG_DEBUG(
                "Reissuing Vulkan state command %" PRIu32 " for command buffer %" PRIu64, call_id, command_buffer_id);
            DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
        });

        recording_ = true;
    }

    void ClearRecordedState(format::HandleId command_buffer_id)
    {
        state_recorder_.ClearRecordedState(command_buffer_id);
    }

  private:
    bool                       recording_ = true;
    VulkanStateCommandRecorder state_recorder_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STATE_RECORDING_DECODER_H
