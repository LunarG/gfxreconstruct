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

#include "decode/vulkan_stage_queue_wait.h"

#include "util/callbacks.h"
#include "util/logging.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanStageQueueWait::Process_vkGetDeviceQueue(const ApiCallInfo& call_info, args::GetDeviceQueue& args)
{
    const format::HandleId* queue_id = args.pQueue.GetPointer();
    if (queue_id != nullptr)
    {
        queue_to_device_[*queue_id] = args.device;
    }

    Forward(call_info, args);
}

void VulkanStageQueueWait::Process_vkGetDeviceQueue2(const ApiCallInfo& call_info, args::GetDeviceQueue2& args)
{
    const format::HandleId* queue_id = args.pQueue.GetPointer();
    if (queue_id != nullptr)
    {
        queue_to_device_[*queue_id] = args.device;
    }

    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageQueueWait::ProcessSubmit(const ApiCallInfo& call_info, ArgsT& args)
{
    if (options_.idle_before_submit)
    {
        EmitDeviceWaitIdle(call_info, args.queue);
    }

    Forward(call_info, args);
}

void VulkanStageQueueWait::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    ProcessSubmit(call_info, args);
}

void VulkanStageQueueWait::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    ProcessSubmit(call_info, args);
}

void VulkanStageQueueWait::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    ProcessSubmit(call_info, args);
}

void VulkanStageQueueWait::Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args)
{
    if (options_.idle_before_present)
    {
        EmitDeviceWaitIdle(call_info, args.queue);
    }

    Forward(call_info, args);
}

void VulkanStageQueueWait::EmitDeviceWaitIdle(const ApiCallInfo& call_info, format::HandleId queue_id)
{
    const auto device_entry = queue_to_device_.find(queue_id);
    if (device_entry == queue_to_device_.end())
    {
        // Without a device the stage cannot wait. The app call still goes through.
        if (unknown_queues_.insert(queue_id).second)
        {
            GFXRECON_LOG_WARNING("No vkGetDeviceQueue found for queue %" PRIu64 ", so replay does not wait for it.",
                                 queue_id);
        }
        return;
    }

    // vkDeviceWaitIdle: the device, then the result.
    const std::vector<uint8_t> bytes =
        ByteWriter().Put<format::HandleId>(device_entry->second).Put<int32_t>(VK_SUCCESS).Bytes();

    // The wait is not a call of the app. Marking it keeps recapture IDs and the injected-command callbacks
    // the same as when the replay consumer made the wait itself.
    util::MarkInjectedCommandsHelper injected_commands_scope;
    Emit(format::ApiCallId::ApiCall_vkDeviceWaitIdle, call_info, bytes);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
