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
#include "decode/vulkan_replay_consumer_base.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayFrameLoopConsumer : public VulkanReplayFrameLoopConsumerBase
{
  public:
    VulkanReplayFrameLoopConsumer(std::shared_ptr<application::Application> application,
                                  const VulkanReplayOptions&                options,
                                  graphics::FrameLoopInfo&                  frame_loop_info) :
        VulkanReplayFrameLoopConsumerBase(application, options), frame_loop_info_(frame_loop_info)
    {}

    graphics::FrameLoopInfo& getFrameLoopInfo() override { return frame_loop_info_; }

    void Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                     VkResult                                               returnValue,
                                     format::HandleId                                       device,
                                     StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                     HandlePointerDecoder<VkCommandPool>*                   pCommandPool) override;

    void Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                          VkResult                                                   returnValue,
                                          format::HandleId                                           device,
                                          StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                          HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    void Process_vkQueuePresentKHR(const ApiCallInfo&                              call_info,
                                   VkResult                                        returnValue,
                                   format::HandleId                                queue,
                                   StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

  private:
    graphics::FrameLoopInfo&             frame_loop_info_;
    std::unordered_set<VkDescriptorPool> active_descriptor_pools_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
