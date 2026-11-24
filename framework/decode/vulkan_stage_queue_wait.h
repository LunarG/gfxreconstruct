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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_QUEUE_WAIT_H
#define GFXRECON_DECODE_VULKAN_STAGE_QUEUE_WAIT_H

#include "generated/generated_vulkan_consumer_stage.h"

#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct QueueWaitStageOptions
{
    // Wait for the device to become idle before each queue submit (--idle-before-submit).
    bool idle_before_submit = false;

    // Wait for the device to become idle before each present (--wait-before-present).
    bool idle_before_present = false;
};

/// This stage adds a vkDeviceWaitIdle before each queue submit, before each present, or both.
/// --sync stays in the replay consumer, because its wait feeds the QueueSubmitEnd event of the replay event plugin.
class VulkanStageQueueWait : public VulkanConsumerStage
{
  public:
    explicit VulkanStageQueueWait(const QueueWaitStageOptions& options) : options_(options) {}

    // Queues. The stage keeps the device of each queue, because the wait it adds needs the device.

    void Process_vkGetDeviceQueue(const ApiCallInfo& call_info, args::GetDeviceQueue& args) override;
    void Process_vkGetDeviceQueue2(const ApiCallInfo& call_info, args::GetDeviceQueue2& args) override;

    // Submits

    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;

    // Present

    void Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args) override;

  private:
    template <typename ArgsT>
    void ProcessSubmit(const ApiCallInfo& call_info, ArgsT& args);

    // Sends a vkDeviceWaitIdle for the device of the queue to the next consumers, marked as an injected call.
    void EmitDeviceWaitIdle(const ApiCallInfo& call_info, format::HandleId queue_id);

    QueueWaitStageOptions options_;

    std::unordered_map<format::HandleId, format::HandleId> queue_to_device_;

    // Queues that the stage could not find a device for. Each one is reported once.
    std::unordered_set<format::HandleId> unknown_queues_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_QUEUE_WAIT_H
