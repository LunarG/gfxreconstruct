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
        VulkanReplayFrameLoopConsumerBase(application, options),
        frame_loop_info_(frame_loop_info)
    {}

    graphics::FrameLoopInfo& getFrameLoopInfo() override { return frame_loop_info_; }

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    virtual void StartLooping() override;

    void Process_vkCreateDevice(const ApiCallInfo& call_info, args::CreateDevice& args) override;

    void Process_vkCreateCommandPool(const ApiCallInfo& call_info, args::CreateCommandPool& args) override;
    
    void Process_vkResetCommandPool(const ApiCallInfo& call_info, args::ResetCommandPool& args) override;

    void Process_vkBeginCommandBuffer(const ApiCallInfo& call_info, args::BeginCommandBuffer& args) override;
    
    void Process_vkResetCommandBuffer(const ApiCallInfo& call_info, args::ResetCommandBuffer& args) override;

    void Process_vkDestroyDescriptorPool(const ApiCallInfo& call_info, args::DestroyDescriptorPool& args) override;

    void Process_vkResetDescriptorPool(const ApiCallInfo& call_info, args::ResetDescriptorPool& args) override;

    void Process_vkAllocateDescriptorSets(const ApiCallInfo& call_info, args::AllocateDescriptorSets& args) override;

    void Process_vkFreeDescriptorSets(const ApiCallInfo& call_info, args::FreeDescriptorSets& args) override;

    void Process_vkCreateFence(const ApiCallInfo& call_info, args::CreateFence& args) override;

    void Process_vkDestroyFence(const ApiCallInfo& call_info, args::DestroyFence& args) override;

    void Process_vkCreateEvent(const ApiCallInfo& call_info, args::CreateEvent& args) override;

    void Process_vkDestroyEvent(const ApiCallInfo& call_info, args::DestroyEvent& args) override;

    void Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args) override;

    void Process_vkMapMemory(const ApiCallInfo& call_info, args::MapMemory& args) override;

    void Process_vkUnmapMemory(const ApiCallInfo& call_info, args::UnmapMemory& args) override;

    void Process_vkAcquireProfilingLockKHR(const ApiCallInfo& call_info, args::AcquireProfilingLockKHR& args) override;

    void Process_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, args::ReleaseProfilingLockKHR& args) override;

    // Private declarations
  private:
    void RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool);

    struct FenceTracking
    {
        std::unordered_map<format::HandleId, bool> initial_fence_states_;
    };
    void TrackFenceStates();
    void TrackFenceState(format::HandleId device, format::HandleId fence);
    void FixupDeviceFences(format::HandleId device, format::HandleId queue);

    struct EventTracking
    {
        std::unordered_map<format::HandleId, bool> initial_event_states_;
    };
    void TrackEventStates();
    void TrackEventState(format::HandleId device, format::HandleId event);
    void FixupDeviceEvents(format::HandleId device);

    // Private data
  private:
    graphics::FrameLoopInfo& frame_loop_info_;

    VulkanDecoder* decoder_ = nullptr;

    // Command buffer util is per-device
    std::unordered_map<format::HandleId, VulkanCommandBufferUtil> command_buffer_utils_;

    /// A "dangling" resource is one that was either
    /// - created during the loop range but destroyed after it
    /// - or created before the loop range but destroyed during it
    std::unordered_set<format::HandleId> dangling_create_descriptor_sets_;
    std::unordered_set<format::HandleId> dangling_destroy_descriptor_sets_;

    std::unordered_map<format::HandleId, FenceTracking> per_device_fence_tracking_;

    std::unordered_set<format::HandleId>                host_visible_events_;
    std::unordered_map<format::HandleId, EventTracking> per_device_event_tracking_;

    // Support for vkMapMemory/vkUnMapMemory
    std::set<format::HandleId> mapped_loop_memory;

    // Support for vkAcquireProfilingLockKHR/vkReleaseProfilingLockKHR
    std::unordered_map<format::HandleId, bool> profilingLockState;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_FRAME_LOOP_CONSUMER_H
