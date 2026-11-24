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

// Catch must come before the Vulkan headers.
#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/vulkan_stage_queue_wait.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/callbacks.h"

#include <string>
#include <vector>

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;
namespace util   = gfxrecon::util;

namespace
{

constexpr format::HandleId kDevice       = 1;
constexpr format::HandleId kQueue        = 10;
constexpr format::HandleId kQueue2       = 11;
constexpr format::HandleId kUnknownQueue = 99;

std::vector<uint8_t> GetDeviceQueueBytes(format::HandleId device, format::HandleId queue)
{
    return ByteWriter()
        .Put<format::HandleId>(device) // device
        .Put<uint32_t>(0)              // queueFamilyIndex
        .Put<uint32_t>(0)              // queueIndex
        .Put<uint32_t>(kHandlePointer) // pQueue
        .Put<uint64_t>(kUnusedAddress) //   address
        .Put<format::HandleId>(queue)  //   id
        .Bytes();
}

std::vector<uint8_t> GetDeviceQueue2Bytes(format::HandleId device, format::HandleId queue)
{
    return ByteWriter()
        .Put<format::HandleId>(device)                        // device
        .Put<uint32_t>(kStructPointer)                        // pQueueInfo
        .Put<uint64_t>(kUnusedAddress)                        //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2) //   sType
        .Put<uint32_t>(kNullStructPointer)                    //   pNext
        .Put<uint32_t>(0)                                     //   flags
        .Put<uint32_t>(0)                                     //   queueFamilyIndex
        .Put<uint32_t>(0)                                     //   queueIndex
        .Put<uint32_t>(kHandlePointer)                        // pQueue
        .Put<uint64_t>(kUnusedAddress)                        //   address
        .Put<format::HandleId>(queue)                         //   id
        .Bytes();
}

// vkQueueSubmit, vkQueueSubmit2 and vkQueueSubmit2KHR share this layout. No submit infos, no fence.
std::vector<uint8_t> EmptySubmitBytes(format::HandleId queue)
{
    return ByteWriter()
        .Put<format::HandleId>(queue)                 // queue
        .Put<uint32_t>(0)                             // submitCount
        .Put<uint32_t>(kNullStructArray)              // pSubmits
        .Put<format::HandleId>(format::kNullHandleId) // fence
        .Put<int32_t>(VK_SUCCESS)                     // result
        .Bytes();
}

std::vector<uint8_t> PresentBytes(format::HandleId queue)
{
    return ByteWriter()
        .Put<format::HandleId>(queue)      // queue
        .Put<uint32_t>(kNullStructPointer) // pPresentInfo
        .Put<int32_t>(VK_SUCCESS)          // result
        .Bytes();
}

// Logs every call that the stage sends on, one line per call. A call made inside an injected-commands
// scope ends with " (injected)".
class CallLog : public VulkanConsumer
{
  public:
    void Process_vkGetDeviceQueue(const ApiCallInfo&, args::GetDeviceQueue& args) override
    {
        Log("GetDeviceQueue " + std::to_string(*args.pQueue.GetPointer()));
    }

    void Process_vkGetDeviceQueue2(const ApiCallInfo&, args::GetDeviceQueue2& args) override
    {
        Log("GetDeviceQueue2 " + std::to_string(*args.pQueue.GetPointer()));
    }

    void Process_vkDeviceWaitIdle(const ApiCallInfo&, args::DeviceWaitIdle& args) override
    {
        Log("DeviceWaitIdle " + std::to_string(args.device));
    }

    void Process_vkQueueSubmit(const ApiCallInfo&, args::QueueSubmit& args) override
    {
        Log("QueueSubmit " + std::to_string(args.queue));
    }

    void Process_vkQueueSubmit2(const ApiCallInfo&, args::QueueSubmit2& args) override
    {
        Log("QueueSubmit2 " + std::to_string(args.queue));
    }

    void Process_vkQueueSubmit2KHR(const ApiCallInfo&, args::QueueSubmit2KHR& args) override
    {
        Log("QueueSubmit2KHR " + std::to_string(args.queue));
    }

    void Process_vkQueuePresentKHR(const ApiCallInfo&, args::QueuePresentKHR& args) override
    {
        Log("QueuePresentKHR " + std::to_string(args.queue));
    }

    std::vector<std::string> lines;

  private:
    void Log(std::string line)
    {
        if (util::InjectedCommandsActive())
        {
            line += " (injected)";
        }
        lines.push_back(std::move(line));
    }
};

// A decoder that feeds the stage, and a log behind the stage.
class Harness
{
  public:
    explicit Harness(const QueueWaitStageOptions& options) : stage_(options)
    {
        decoder_.AddConsumer(&stage_);
        stage_.AddNext(&log);
    }

    // The guard opens the allocator scope for one call, as the file processor does.
    void Send(format::ApiCallId call_id, const std::vector<uint8_t>& bytes)
    {
        DecoderAllocGuard<true> guard;
        decoder_.DecodeFunctionCall(call_id, ApiCallInfo{}, bytes.data(), bytes.size());
    }

    CallLog log;

  private:
    VulkanDecoder        decoder_;
    VulkanStageQueueWait stage_;
};

using Lines = std::vector<std::string>;

QueueWaitStageOptions Options(bool idle_before_submit, bool idle_before_present)
{
    QueueWaitStageOptions options;
    options.idle_before_submit  = idle_before_submit;
    options.idle_before_present = idle_before_present;
    return options;
}

} // namespace

TEST_CASE("Queue wait stage forwards every call unchanged when no option is set", "[stage][queue_wait]")
{
    Harness harness(Options(false, false));
    harness.Send(format::ApiCall_vkGetDeviceQueue, GetDeviceQueueBytes(kDevice, kQueue));
    harness.Send(format::ApiCall_vkQueueSubmit, EmptySubmitBytes(kQueue));
    harness.Send(format::ApiCall_vkQueuePresentKHR, PresentBytes(kQueue));

    CHECK(harness.log.lines == Lines{ "GetDeviceQueue 10", "QueueSubmit 10", "QueuePresentKHR 10" });
}

TEST_CASE("Queue wait stage waits for the device before each kind of submit", "[stage][queue_wait]")
{
    Harness harness(Options(true, false));
    harness.Send(format::ApiCall_vkGetDeviceQueue, GetDeviceQueueBytes(kDevice, kQueue));
    harness.Send(format::ApiCall_vkQueueSubmit, EmptySubmitBytes(kQueue));
    harness.Send(format::ApiCall_vkQueueSubmit2, EmptySubmitBytes(kQueue));
    harness.Send(format::ApiCall_vkQueueSubmit2KHR, EmptySubmitBytes(kQueue));
    harness.Send(format::ApiCall_vkQueuePresentKHR, PresentBytes(kQueue));

    CHECK(harness.log.lines == Lines{ "GetDeviceQueue 10",
                                      "DeviceWaitIdle 1 (injected)",
                                      "QueueSubmit 10",
                                      "DeviceWaitIdle 1 (injected)",
                                      "QueueSubmit2 10",
                                      "DeviceWaitIdle 1 (injected)",
                                      "QueueSubmit2KHR 10",
                                      "QueuePresentKHR 10" });
}

TEST_CASE("Queue wait stage waits for the device before a present", "[stage][queue_wait]")
{
    Harness harness(Options(false, true));
    harness.Send(format::ApiCall_vkGetDeviceQueue, GetDeviceQueueBytes(kDevice, kQueue));
    harness.Send(format::ApiCall_vkQueueSubmit, EmptySubmitBytes(kQueue));
    harness.Send(format::ApiCall_vkQueuePresentKHR, PresentBytes(kQueue));

    CHECK(harness.log.lines ==
          Lines{ "GetDeviceQueue 10", "QueueSubmit 10", "DeviceWaitIdle 1 (injected)", "QueuePresentKHR 10" });
}

TEST_CASE("Queue wait stage finds the device of a queue from vkGetDeviceQueue2", "[stage][queue_wait]")
{
    Harness harness(Options(true, false));
    harness.Send(format::ApiCall_vkGetDeviceQueue2, GetDeviceQueue2Bytes(kDevice, kQueue2));
    harness.Send(format::ApiCall_vkQueueSubmit, EmptySubmitBytes(kQueue2));

    CHECK(harness.log.lines == Lines{ "GetDeviceQueue2 11", "DeviceWaitIdle 1 (injected)", "QueueSubmit 11" });
}

TEST_CASE("Queue wait stage forwards a submit on an unknown queue without a wait", "[stage][queue_wait]")
{
    Harness harness(Options(true, true));
    harness.Send(format::ApiCall_vkQueueSubmit, EmptySubmitBytes(kUnknownQueue));
    harness.Send(format::ApiCall_vkQueuePresentKHR, PresentBytes(kUnknownQueue));

    CHECK(harness.log.lines == Lines{ "QueueSubmit 99", "QueuePresentKHR 99" });
}
