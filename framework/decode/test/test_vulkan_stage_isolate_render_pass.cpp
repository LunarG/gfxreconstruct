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
#include "decode/vulkan_stage_isolate_render_pass.h"
#include "generated/generated_vulkan_decoder.h"

#include <initializer_list>
#include <map>
#include <string>
#include <vector>

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;

namespace
{

constexpr format::HandleId kDevice = 1;
constexpr format::HandleId kPool   = 2;

constexpr uint32_t kStructPointer     = format::kIsStruct | format::kIsSingle | format::kHasAddress | format::kHasData;
constexpr uint32_t kNullStructPointer = format::kIsStruct | format::kIsSingle | format::kIsNull;
constexpr uint32_t kNullStructArray   = format::kIsStruct | format::kIsArray | format::kIsNull;
constexpr uint32_t kArrayPointer      = format::kIsArray | format::kHasAddress | format::kHasData;

// Writes call parameters in capture file order. The stage's own writer is private to its .cpp.
class Bytes
{
  public:
    template <typename T>
    Bytes& Put(T value)
    {
        const auto* first = reinterpret_cast<const uint8_t*>(&value);
        data.insert(data.end(), first, first + sizeof(T));
        return *this;
    }

    std::vector<uint8_t> data;
};

// Logs every call that the stage sends on, one line per call. A synthetic id prints as S1, S2 and so on,
// in the order that it first appears, so the expected streams read like section 5.1 of the lesson.
class CallLog : public VulkanConsumer
{
  public:
    void Process_vkAllocateCommandBuffers(const ApiCallInfo&, args::AllocateCommandBuffers& args) override
    {
        const auto* info  = args.pAllocateInfo.GetMetaStructPointer();
        std::string level = info->decoded_value->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY ? "primary" : "secondary";
        std::string line  = "Allocate " + Name(args.device) + " " + Name(info->commandPool) + " " + level;
        for (const format::HandleId id : args.pCommandBuffers.GetSpan())
        {
            line += " " + Name(id);
        }
        lines.push_back(line);
    }

    void Process_vkBeginCommandBuffer(const ApiCallInfo&, args::BeginCommandBuffer& args) override
    {
        lines.push_back("Begin " + Name(args.commandBuffer) + " flags " +
                        std::to_string(args.pBeginInfo.GetPointer()->flags));
    }

    void Process_vkEndCommandBuffer(const ApiCallInfo&, args::EndCommandBuffer& args) override
    {
        lines.push_back("End " + Name(args.commandBuffer));
    }

    void Process_vkCmdCopyBuffer(const ApiCallInfo&, args::CmdCopyBuffer& args) override
    {
        lines.push_back("CopyBuffer " + Name(args.commandBuffer));
    }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo&, args::CmdBeginRenderPass& args) override
    {
        lines.push_back("BeginRenderPass " + Name(args.commandBuffer));
    }

    void Process_vkCmdDraw(const ApiCallInfo&, args::CmdDraw& args) override
    {
        lines.push_back("Draw " + Name(args.commandBuffer));
    }

    void Process_vkCmdEndRenderPass(const ApiCallInfo&, args::CmdEndRenderPass& args) override
    {
        lines.push_back("EndRenderPass " + Name(args.commandBuffer));
    }

    std::vector<std::string> lines;

  private:
    std::string Name(format::HandleId id)
    {
        if ((id >> 63) == 0)
        {
            return std::to_string(id);
        }

        const auto entry = synthetic_names_.try_emplace(id, synthetic_names_.size() + 1).first;
        return "S" + std::to_string(entry->second);
    }

    std::map<format::HandleId, size_t> synthetic_names_;
};

// Keeps the call bytes that it holds when vkCmdBeginRenderPass arrives.
class CallBytesProbe : public VulkanConsumer
{
  public:
    void SetCurrentCallBytes(const CallBytes& call_bytes) override { current = call_bytes; }

    void Process_vkCmdBeginRenderPass(const ApiCallInfo&, args::CmdBeginRenderPass&) override
    {
        seen_at_render_pass = current;
    }

    CallBytes current;
    CallBytes seen_at_render_pass;
};

// Sends app calls through decoder -> stage -> log, the way the file processor would.
class Rig
{
  public:
    Rig()
    {
        decoder_.AddConsumer(&stage_);
        stage_.AddNext(&log);
    }

    void Allocate(std::initializer_list<format::HandleId> command_buffers,
                  VkCommandBufferLevel                    level = VK_COMMAND_BUFFER_LEVEL_PRIMARY)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(kDevice)
            .Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<format::HandleId>(kPool)
            .Put<uint32_t>(level)
            .Put<uint32_t>(static_cast<uint32_t>(command_buffers.size()))
            .Put<uint32_t>(kArrayPointer)
            .Put<uint64_t>(1)
            .Put<uint64_t>(command_buffers.size());
        for (const format::HandleId id : command_buffers)
        {
            bytes.Put<format::HandleId>(id);
        }
        bytes.Put<int32_t>(VK_SUCCESS);
        Send(format::ApiCall_vkAllocateCommandBuffers, bytes);
    }

    void Begin(format::HandleId command_buffer, VkCommandBufferUsageFlags flags = 0)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer)
            .Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<uint32_t>(flags)
            .Put<uint32_t>(kNullStructPointer)
            .Put<int32_t>(VK_SUCCESS);
        Send(format::ApiCall_vkBeginCommandBuffer, bytes);
    }

    void End(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkEndCommandBuffer,
             Bytes().Put<format::HandleId>(command_buffer).Put<int32_t>(VK_SUCCESS));
    }

    void CopyBuffer(format::HandleId command_buffer)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer)
            .Put<format::HandleId>(50) // srcBuffer
            .Put<format::HandleId>(51) // dstBuffer
            .Put<uint32_t>(0)          // regionCount
            .Put<uint32_t>(kNullStructArray);
        Send(format::ApiCall_vkCmdCopyBuffer, bytes);
    }

    // Returns the bytes of the call, so a test can compare them with what a consumer saw.
    std::vector<uint8_t> BeginRenderPass(format::HandleId command_buffer)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer)
            .Put<uint32_t>(kStructPointer)
            .Put<uint64_t>(1)
            .Put<uint32_t>(VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO)
            .Put<uint32_t>(kNullStructPointer)
            .Put<format::HandleId>(70) // renderPass
            .Put<format::HandleId>(71) // framebuffer
            .Put<int32_t>(0)           // renderArea.offset
            .Put<int32_t>(0)
            .Put<uint32_t>(4) // renderArea.extent
            .Put<uint32_t>(4)
            .Put<uint32_t>(0) // clearValueCount
            .Put<uint32_t>(kNullStructArray)
            .Put<uint32_t>(VK_SUBPASS_CONTENTS_INLINE);
        Send(format::ApiCall_vkCmdBeginRenderPass, bytes);
        return bytes.data;
    }

    void Draw(format::HandleId command_buffer)
    {
        Bytes bytes;
        bytes.Put<format::HandleId>(command_buffer).Put<uint32_t>(3).Put<uint32_t>(1).Put<uint32_t>(0).Put<uint32_t>(0);
        Send(format::ApiCall_vkCmdDraw, bytes);
    }

    void EndRenderPass(format::HandleId command_buffer)
    {
        Send(format::ApiCall_vkCmdEndRenderPass, Bytes().Put<format::HandleId>(command_buffer));
    }

    void AddNext(VulkanConsumer* next) { stage_.AddNext(next); }

    CallLog log;

  private:
    // The guard opens the allocator scope for one call, as the file processor does.
    void Send(format::ApiCallId call_id, const Bytes& bytes)
    {
        DecoderAllocGuard<true> guard;
        decoder_.DecodeFunctionCall(call_id, ApiCallInfo{}, bytes.data.data(), bytes.data.size());
    }

    VulkanDecoder                decoder_;
    VulkanStageIsolateRenderPass stage_;
};

using Lines = std::vector<std::string>;

} // namespace

TEST_CASE("Isolate stage splits a command buffer before a render pass", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage does not split a recording that starts with a render pass", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                           });
}

TEST_CASE("Isolate stage begins each part with the app's begin flags", "[stage][isolate]")
{
    constexpr VkCommandBufferUsageFlags kFlags =
        VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT | VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;

    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10, kFlags);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    REQUIRE(rig.log.lines.size() == 7);
    CHECK(rig.log.lines[5] == "Begin S1 flags " + std::to_string(kFlags));
}

TEST_CASE("Isolate stage never splits or redirects a secondary command buffer", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 20 }, VK_COMMAND_BUFFER_LEVEL_SECONDARY);
    rig.Begin(20);
    rig.CopyBuffer(20);

    // vkCmdBeginRenderPass is not valid in a secondary, but the stage must still leave it alone.
    rig.BeginRenderPass(20);
    rig.End(20);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 secondary 20",
                               "Begin 20 flags 0",
                               "CopyBuffer 20",
                               "BeginRenderPass 20",
                               "End 20",
                           });
}

TEST_CASE("Isolate stage gives each part its own synthetic id", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage tracks every command buffer of one allocation", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10, 11 });
    rig.Begin(11);
    rig.CopyBuffer(11);
    rig.BeginRenderPass(11);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10 11",
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage starts a new recording in the app's own command buffer", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    rig.log.lines.clear();
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                           });
}

TEST_CASE("Isolate stage gives the app call's bytes back after a split", "[stage][isolate]")
{
    CallBytesProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    const auto bytes = rig.BeginRenderPass(10);

    // The invented calls set their own bytes on the probe first. The app call's bytes must win.
    CHECK(probe.seen_at_render_pass.call_id == format::ApiCall_vkCmdBeginRenderPass);
    CHECK(probe.seen_at_render_pass.buffer_size == bytes.size());
}
