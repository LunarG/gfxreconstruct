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

#include "decode/vulkan_stage_isolate_render_pass.h"
#include "vulkan_stage_test_util.h"

using namespace stage_test;

namespace
{

class Rig : public StageRig
{
  public:
    Rig() { Connect({ &stage_ }); }

  private:
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

TEST_CASE("Isolate stage gives back-to-back render passes one part each", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    // The split after the first pass and the split before the second are one split, so no part is empty.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage puts a command after a split render pass in its own part", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
    rig.End(10);

    // The render pass runs in S1, so the stage must find the recording of 10 after the pass ends there.
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
                               "CopyBuffer S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage puts a command between two render passes in its own part", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
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
                               "CopyBuffer S2",
                               "End S2",
                               "Allocate 1 2 primary S3",
                               "Begin S3 flags 0",
                               "BeginRenderPass S3",
                               "EndRenderPass S3",
                               "End S3",
                           });
}

TEST_CASE("Isolate stage splits around every begin and end call of a render pass", "[stage][isolate]")
{
    for (const RenderPassCalls& calls : kRenderPassCalls)
    {
        INFO(calls.begin_name);

        Rig rig;
        rig.Allocate({ 10 });
        rig.Begin(10);
        rig.CopyBuffer(10);
        rig.Send(calls.begin_id, calls.encode_begin(10));
        rig.Send(calls.end_id, calls.encode_end(10));
        rig.CopyBuffer(10);
        rig.End(10);

        CHECK(rig.log.lines == Lines{
                                   "Allocate 1 2 primary 10",
                                   "Begin 10 flags 0",
                                   "CopyBuffer 10",
                                   "End 10",
                                   "Allocate 1 2 primary S1",
                                   "Begin S1 flags 0",
                                   calls.begin_name + " S1",
                                   calls.end_name + " S1",
                                   "End S1",
                                   "Allocate 1 2 primary S2",
                                   "Begin S2 flags 0",
                                   "CopyBuffer S2",
                                   "End S2",
                               });
    }
}

TEST_CASE("Isolate stage puts a copy and two render passes in three parts", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BindPipeline S2 80",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage reissues every state command with the data behind its pointers", "[stage][isolate]")
{
    for (const StateCall& call : kStateCalls)
    {
        INFO(call.name);

        Rig rig;
        rig.Allocate({ 10 });
        rig.Begin(10);
        rig.Send(call.id, call.encode(10));
        rig.CopyBuffer(10);
        rig.BeginRenderPass(10);

        CHECK(rig.log.lines == Lines{
                                   "Allocate 1 2 primary 10",
                                   "Begin 10 flags 0",
                                   call.name + " 10" + call.values,
                                   "CopyBuffer 10",
                                   "End 10",
                                   "Allocate 1 2 primary S1",
                                   "Begin S1 flags 0",
                                   call.name + " S1" + call.values,
                                   "BeginRenderPass S1",
                               });
    }
}

TEST_CASE("Isolate stage reissues state commands in the order that the app recorded them", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10, 80);
    rig.SetViewport(10);
    rig.BindPipeline(10, 81);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    // The last bind wins on the GPU, so the order decides which pipeline the part draws with.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "SetViewport 10 640x480 320x240",
                               "BindPipeline 10 81",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "SetViewport S1 640x480 320x240",
                               "BindPipeline S1 81",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage sends a state command that follows a pass to the next part once", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BeginRenderPass(10);
    rig.Draw(10);
    rig.EndRenderPass(10);
    rig.BindPipeline(10);
    rig.Draw(10);
    rig.End(10);

    // The bind opens the new part. The part must not get the bind both as a reissue and as the app's call.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BeginRenderPass 10",
                               "Draw 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "Draw S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage lets state commands share the part of the render pass after them", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10, 80);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.BindPipeline(10, 81);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.End(10);

    // A state command is not work. A part that holds only state commands is still fresh, so the render pass
    // after it does not split again.
    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "BindPipeline 10 80",
                               "BeginRenderPass 10",
                               "EndRenderPass 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BindPipeline S1 80",
                               "BindPipeline S1 81",
                               "BeginRenderPass S1",
                               "EndRenderPass S1",
                               "End S1",
                           });
}

TEST_CASE("Isolate stage reissues clean values after a consumer edits the arguments", "[stage][isolate]")
{
    ViewportEditor editor;

    Rig rig;
    rig.AddNext(&editor);
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.SetViewport(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.EndRenderPass(10);
    rig.CopyBuffer(10);
    rig.End(10);

    // The editor runs after the log. A stage that sent the same decoded viewports again would show the
    // editor's 1x1 in the log on the second and third line.
    Lines viewports;
    for (const std::string& line : rig.log.lines)
    {
        if (line.rfind("SetViewport", 0) == 0)
        {
            viewports.push_back(line);
        }
    }
    CHECK(viewports == Lines{
                           "SetViewport 10 640x480 320x240",
                           "SetViewport S1 640x480 320x240",
                           "SetViewport S2 640x480 320x240",
                       });
}

TEST_CASE("Isolate stage keeps its own copy of the bytes of a state command", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);

    // The file processor reuses its buffer for the next block, so the bytes change after the call returns.
    Bytes bind = EncodeBindPipeline(10);
    rig.Send(format::ApiCall_vkCmdBindPipeline, bind);
    std::fill(bind.data.begin(), bind.data.end(), uint8_t{ 0xAB });

    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    REQUIRE(rig.log.lines.size() == 9);
    CHECK(rig.log.lines[7] == "BindPipeline S1 80");
}

TEST_CASE("Isolate stage does not reissue the state of an earlier recording", "[stage][isolate]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.BindPipeline(10);
    rig.End(10);

    rig.log.lines.clear();
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);

    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                           });
}

TEST_CASE("Isolate stage lists every part of a split command buffer in the submit", "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 2);

    CHECK(rig.SubmitLines({ { .command_buffers = { 10 } } }) == Lines{ "Submit [10 S1 S2] count 3" });
}

TEST_CASE("Isolate stage keeps the submitted order and lists an unsplit command buffer once",
          "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);

    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 11 } } }) == Lines{ "Submit [10 S1 S2 11] count 4" });
    CHECK(rig.SubmitLines({ { .command_buffers = { 11, 10 } } }) == Lines{ "Submit [11 10 S1 S2] count 4" });
}

TEST_CASE("Isolate stage rewrites each submit info of one call on its own", "[stage][isolate][submit]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10, 11, 12 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.RecordCopyAndRenderPasses(12, 0);

    const auto lines = rig.SubmitLines(
        { { .command_buffers = { 10 } }, { .command_buffers = { 12 } }, { .command_buffers = { 11 } } });
    CHECK(lines == Lines{ "Submit [10 S1 S2] count 3 [12] count 1 [11 S3] count 2" });
    CHECK(probe.replaced == std::vector<bool>{ true, false, true });
}

TEST_CASE("Isolate stage keeps everything else of a rewritten submit", "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 1);

    const auto lines = rig.SubmitLines({ { .command_buffers   = { 10 },
                                           .wait_semaphores   = { 30 },
                                           .wait_stages       = { 1 },
                                           .signal_semaphores = { 31 },
                                           .timeline          = AppTimelineInfo{ 1, { 7 }, 1, { 9 } },
                                           .frame_boundary    = kFrameBoundary,
                                           .performance_query = true } },
                                       kFence,
                                       VK_ERROR_DEVICE_LOST);
    CHECK(lines == Lines{ "Submit timeline 1 [7] 1 [9]" + kFrameBoundaryText +
                          " query wait 30 stage 1 [10 S1] count 2 signal 31 fence 40 result -4" });
}

TEST_CASE("Isolate stage does not start to track a command buffer when it rewrites a submit",
          "[stage][isolate][submit]")
{
    Rig rig;
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 1);

    // The stage tracks no command buffer 99, so it must not split 99 after the submit either.
    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 99 } } }) == Lines{ "Submit [10 S1 99] count 3" });
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(99, 1);
    CHECK(rig.log.lines == Lines{
                               "Begin 99 flags 0",
                               "CopyBuffer 99",
                               "BeginRenderPass 99",
                               "Draw 99",
                               "EndRenderPass 99",
                               "End 99",
                           });
}

TEST_CASE("Isolate stage forwards a submit with no split command buffer untouched", "[stage][isolate][submit]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);

    // The stage tracks no command buffer 99.
    rig.Submit({ { .command_buffers = { 11, 99 } } });

    CHECK(rig.log.lines.back() == "Submit [11 99] count 2");
    CHECK(probe.replaced == std::vector<bool>{ false });
}

TEST_CASE("Isolate stage rewrites vkQueueSubmit2 and vkQueueSubmit2KHR", "[stage][isolate][submit]")
{
    const std::vector<std::pair<std::string, format::ApiCallId>> calls = {
        { "Submit2", format::ApiCall_vkQueueSubmit2 },
        { "Submit2KHR", format::ApiCall_vkQueueSubmit2KHR },
    };

    for (const auto& [name, call_id] : calls)
    {
        INFO(name);

        SubmitProbe probe;

        Rig rig;
        rig.AddNext(&probe);
        rig.Allocate({ 10, 11, 12, 13 });
        rig.RecordCopyAndRenderPasses(10, 2);
        rig.RecordCopyAndRenderPasses(11, 0);
        rig.RecordCopyAndRenderPasses(12, 0);
        rig.RecordCopyAndRenderPasses(13, 1);
        rig.Send(call_id,
                 EncodeQueueSubmit2(
                     {
                         { .command_buffers = { 10, 11 }, .device_masks = { 1, 2 }, .wait_semaphores = { 30 } },
                         { .command_buffers = { 12 }, .device_masks = { 4 }, .signal_semaphores = { 31 } },
                         { .command_buffers = { 13 }, .device_masks = { 8 } },
                     },
                     kFence));

        // Each part takes the device mask of the app's entry that it replaces.
        CHECK(rig.log.lines.back() ==
              name + " wait 30 [10:1 S1:1 S2:1 11:2] count 4 [12:4] count 1 signal 31 [13:8 S3:8] count 2 fence 40");
        CHECK(probe.replaced == std::vector<bool>{ true, false, true });
    }
}

TEST_CASE("Isolate stage reuses the parts of a command buffer that the app records again",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 2);

    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.Submit({ { .command_buffers = { 10 } } });

    // The spare list hands out the newest part first, so S2 comes before S1. No part is allocated again.
    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Submit [10 S2 S1] count 3",
                           });
}

TEST_CASE("Isolate stage reuses a part of a pool without the reset bit only after a pool reset",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, 0);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);

    // S1 has not been reset, so 11 cannot begin it.
    rig.FreeCommandBuffers({ 10 });
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    CHECK(rig.log.lines[3] == "Allocate 1 2 primary S2");

    rig.ResetCommandPool(kPool);
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    CHECK(rig.log.lines == Lines{
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage releases each part once on a pool reset", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, 0);
    rig.Allocate({ 10 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandPool(kPool);
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandPool(kPool);

    // Only S1 is spare, so the second split must allocate. A part that sits twice in the spare list would be
    // begun twice in one recording.
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(10, 2);
    CHECK(rig.log.lines == Lines{
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Allocate 1 2 primary S2",
                               "Begin S2 flags 0",
                               "BeginRenderPass S2",
                               "Draw S2",
                               "EndRenderPass S2",
                               "End S2",
                           });
}

TEST_CASE("Isolate stage gives the parts of a freed command buffer to another command buffer of the pool",
          "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.FreeCommandBuffers({ 10 });

    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.Submit({ { .command_buffers = { 11 } } });

    CHECK(rig.log.lines == Lines{
                               "Begin 11 flags 0",
                               "CopyBuffer 11",
                               "End 11",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "Draw S1",
                               "EndRenderPass S1",
                               "End S1",
                               "Submit [11 S1] count 2",
                           });
}

TEST_CASE("Isolate stage gives the parts of a reset command buffer to the pool", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.ResetCommandBuffer(10);

    // After the reset, 10 is one command buffer again, and 11 can begin its old part.
    rig.Submit({ { .command_buffers = { 10 } } });
    CHECK(rig.log.lines.back() == "Submit [10] count 1");
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(11, 1);

    CHECK(rig.log.lines[3] == "Begin S1 flags 0");
}

TEST_CASE("Isolate stage forgets a destroyed pool and its command buffers", "[stage][isolate][lifecycle]")
{
    Rig rig;
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 1);
    rig.RecordCopyAndRenderPasses(11, 1);
    rig.FreeCommandBuffers({ 10 });
    rig.DestroyCommandPool(kPool);

    // Destroying the pool frees 11, so the stage no longer expands it.
    rig.Submit({ { .command_buffers = { 11 } } });
    CHECK(rig.log.lines.back() == "Submit [11] count 1");

    // A capture never reuses a pool id. The test reuses it to see that the spare S1 went with the old pool.
    rig.CreateCommandPool(kPool, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
    rig.Allocate({ 12 });
    rig.log.lines.clear();
    rig.RecordCopyAndRenderPasses(12, 1);
    CHECK(rig.log.lines[3] == "Allocate 1 2 primary S3");
}
