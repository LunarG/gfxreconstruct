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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_COMMAND_BUFFER_H
#define GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_COMMAND_BUFFER_H

#include "generated/generated_vulkan_consumer_stage.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// This stage sends each command buffer of a queue submit in a call of its own.
/// A call with one submit info and at most one command buffer is forwarded unchanged.
///
/// A render pass that one command buffer suspends and another resumes breaks, because Vulkan wants both command
/// buffers in one submit info. The stage warns about such a pass.
class VulkanStageIsolateCommandBuffer : public VulkanConsumerStage
{
  public:
    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;

    void Process_vkCmdBeginRendering(const ApiCallInfo& call_info, args::CmdBeginRendering& args) override;
    void Process_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, args::CmdBeginRenderingKHR& args) override;

  private:
    template <typename ArgsT>
    void ProcessQueueSubmit(format::ApiCallId call_id, const ApiCallInfo& call_info, ArgsT& args);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_ISOLATE_COMMAND_BUFFER_H
