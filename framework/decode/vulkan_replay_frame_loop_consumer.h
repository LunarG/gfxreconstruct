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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H

#include "util/defines.h"
#include "generated/generated_vulkan_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool skip_while_looping(const graphics::FrameLoopInfo* frame_loop_info,
                        const ApiCallInfo&             call_info,
                        gfxrecon::format::ApiCallId    call_id);

class VulkanReplayFrameLoopConsumer : public VulkanReplayConsumer
{
  public:
    VulkanReplayFrameLoopConsumer(std::shared_ptr<application::Application> application,
                                  const VulkanReplayOptions&                options,
                                  graphics::FrameLoopInfo&                  frame_loop_info) :
        VulkanReplayConsumer(application, options),
        frame_loop_info_(frame_loop_info)
    {}

    void ProcessCreateHardwareBufferCommand(format::HandleId                                    device_id,
                                            format::HandleId                                    memory_id,
                                            uint64_t                                            buffer_id,
                                            uint32_t                                            format,
                                            uint32_t                                            width,
                                            uint32_t                                            height,
                                            uint32_t                                            stride,
                                            uint64_t                                            usage,
                                            uint32_t                                            layers,
                                            const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override;

  private:
    graphics::FrameLoopInfo& frame_loop_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
