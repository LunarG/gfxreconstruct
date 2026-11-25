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

#include "decode/vulkan_stage_isolate_command_buffer.h"
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
    VulkanStageIsolateCommandBuffer stage_;
};

// The two stages in the order that --isolate-render-passes needs.
class ChainRig : public StageRig
{
  public:
    ChainRig() { Connect({ &render_pass_stage_, &command_buffer_stage_ }); }

  private:
    VulkanStageIsolateRenderPass    render_pass_stage_;
    VulkanStageIsolateCommandBuffer command_buffer_stage_;
};

using Lines = std::vector<std::string>;

} // namespace

TEST_CASE("Command buffer stage submits each command buffer in a call of its own", "[stage][isolate_cb]")
{
    Rig rig;

    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 12, 11 } } }) == Lines{
                                                                            "Submit [10] count 1",
                                                                            "Submit [12] count 1",
                                                                            "Submit [11] count 1",
                                                                        });
}

TEST_CASE("Command buffer stage submits the waits first and the signals last", "[stage][isolate_cb]")
{
    Rig rig;

    const AppSubmitInfo submit = {
        .command_buffers = { 10, 11, 12 },
        .wait_semaphores = { 30, 32 },
        // Two different masks show that each wait keeps its own.
        .wait_stages       = { VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT },
        .signal_semaphores = { 31, 33 },
    };
    CHECK(rig.SubmitLines({ submit }) == Lines{
                                             "Submit wait 30 32 stage 4096 stage 1024 [10] count 1",
                                             "Submit [11] count 1",
                                             "Submit [12] count 1 signal 31 33",
                                         });
}

TEST_CASE("Command buffer stage keeps the waits and signals of each submit info with its own command buffers",
          "[stage][isolate_cb]")
{
    Rig rig;

    const auto lines = rig.SubmitLines({
        { .command_buffers = { 10, 11 }, .wait_semaphores = { 30 }, .wait_stages = { 1 }, .signal_semaphores = { 31 } },
        { .command_buffers = { 12 }, .wait_semaphores = { 32 }, .wait_stages = { 2 }, .signal_semaphores = { 33 } },
        { .command_buffers = { 13, 14 }, .wait_semaphores = { 34 }, .wait_stages = { 4 }, .signal_semaphores = { 35 } },
    });
    CHECK(lines == Lines{
                       "Submit wait 30 stage 1 [10] count 1",
                       "Submit [11] count 1 signal 31",
                       "Submit wait 32 stage 2 [12] count 1 signal 33",
                       "Submit wait 34 stage 4 [13] count 1",
                       "Submit [14] count 1 signal 35",
                   });
}

TEST_CASE("Command buffer stage submits the fence with the last call only", "[stage][isolate_cb]")
{
    Rig rig;

    CHECK(rig.SubmitLines({ { .command_buffers = { 12 } }, { .command_buffers = { 10, 11 } } }, kFence) ==
          Lines{
              "Submit [12] count 1",
              "Submit [10] count 1",
              "Submit [11] count 1 fence 40",
          });
    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 11 } }, { .command_buffers = { 12 } } }, kFence) ==
          Lines{
              "Submit [10] count 1",
              "Submit [11] count 1",
              "Submit [12] count 1 fence 40",
          });
}

TEST_CASE("Command buffer stage submits every call with the result of the app's call", "[stage][isolate_cb]")
{
    Rig rig;

    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 11 } } }, format::kNullHandleId, VK_ERROR_DEVICE_LOST) ==
          Lines{
              "Submit [10] count 1 result -4",
              "Submit [11] count 1 result -4",
          });
}

TEST_CASE("Command buffer stage submits a submit info that has only semaphores", "[stage][isolate_cb]")
{
    Rig rig;

    const AppSubmitInfo semaphores_only = { .wait_semaphores   = { 30 },
                                            .wait_stages       = { 1 },
                                            .signal_semaphores = { 31 } };
    CHECK(rig.SubmitLines({ semaphores_only, { .command_buffers = { 10 } } }, kFence) ==
          Lines{
              "Submit wait 30 stage 1 [] count 0 signal 31",
              "Submit [10] count 1 fence 40",
          });
    CHECK(rig.SubmitLines({ { .command_buffers = { 10 } }, semaphores_only }, kFence) ==
          Lines{
              "Submit [10] count 1",
              "Submit wait 30 stage 1 [] count 0 signal 31 fence 40",
          });
}

TEST_CASE("Command buffer stage writes an empty array of a submit as a null array", "[stage][isolate_cb]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);

    SECTION("the arrays of the other call")
    {
        rig.Submit({ { .command_buffers = { 10, 11 }, .wait_semaphores = { 30 }, .signal_semaphores = { 31 } } });

        // The first call has no signals, and the last call has no waits.
        CHECK(probe.null_arrays == Lines{ "signals", "waits", "stages" });
    }

    SECTION("the app's own empty arrays")
    {
        // The first call takes the waits of an info that has none, and no command buffers.
        rig.Submit({ { .signal_semaphores = { 31 } },
                     { .command_buffers = { 10, 11 }, .wait_semaphores = { 30 }, .signal_semaphores = { 32 } } });

        CHECK(probe.null_arrays == Lines{ "waits", "stages", "command buffers", "signals", "waits", "stages" });
    }
}

TEST_CASE("Command buffer stage submits a timeline struct with every command buffer of its submit info",
          "[stage][isolate_cb][timeline]")
{
    Rig rig;

    const auto lines = rig.SubmitLines({
        { .command_buffers   = { 10, 11, 12 },
          .wait_semaphores   = { 30 },
          .wait_stages       = { 1 },
          .signal_semaphores = { 31 },
          .timeline          = AppTimelineInfo{ 1, { 7 }, 1, { 9 } } },
        { .command_buffers   = { 13 },
          .signal_semaphores = { 32 },
          .timeline          = AppTimelineInfo{ .signal_count = 1, .signal_values = { 11 } } },
        // This info has no timeline struct, so its calls have none either.
        { .command_buffers = { 14, 15 } },
    });
    CHECK(lines == Lines{
                       "Submit timeline 1 [7] 1 [9] wait 30 stage 1 [10] count 1",
                       "Submit timeline 1 [7] 1 [9] [11] count 1",
                       "Submit timeline 1 [7] 1 [9] [12] count 1 signal 31",
                       "Submit timeline 0 [] 1 [11] [13] count 1 signal 32",
                       "Submit [14] count 1",
                       "Submit [15] count 1",
                   });
}

TEST_CASE("Command buffer stage keeps a timeline count that has no values", "[stage][isolate_cb][timeline]")
{
    Rig rig;

    // The values are optional in vk.xml, so the app may give a count with a null array.
    const auto lines = rig.SubmitLines({ { .command_buffers   = { 10, 11 },
                                           .wait_semaphores   = { 30 },
                                           .wait_stages       = { 1 },
                                           .signal_semaphores = { 31 },
                                           .timeline          = AppTimelineInfo{ 1, {}, 1, { 9 } } } });
    CHECK(lines == Lines{
                       "Submit timeline 1 [] 1 [9] wait 30 stage 1 [10] count 1",
                       "Submit timeline 1 [] 1 [9] [11] count 1 signal 31",
                   });
}

TEST_CASE("Command buffer stage submits a frame boundary with the last command buffer of its submit info only",
          "[stage][isolate_cb][frame_boundary]")
{
    Rig rig;

    const auto lines = rig.SubmitLines({
        { .command_buffers = { 10, 11, 12 }, .frame_boundary = kFrameBoundary },
        // An info with one command buffer keeps its boundary.
        { .command_buffers = { 13 }, .frame_boundary = AppFrameBoundary{ .frame_id = 6 } },
        { .command_buffers = { 14, 15 } },
    });
    CHECK(lines == Lines{
                       "Submit [10] count 1",
                       "Submit [11] count 1",
                       "Submit" + kFrameBoundaryText + " [12] count 1",
                       "Submit boundary 6 flags 0 images 0 [] buffers 0 [] tag 0 size 0 [] [13] count 1",
                       "Submit [14] count 1",
                       "Submit [15] count 1",
                   });
}

TEST_CASE("Command buffer stage submits a frame boundary and a timeline struct of one submit info",
          "[stage][isolate_cb][timeline][frame_boundary]")
{
    Rig rig;

    // The app may chain the two structs in either order.
    const bool frame_boundary_first = GENERATE(false, true);
    INFO("frame_boundary_first " << frame_boundary_first);

    const auto lines = rig.SubmitLines({ { .command_buffers      = { 10, 11 },
                                           .wait_semaphores      = { 30 },
                                           .wait_stages          = { 1 },
                                           .signal_semaphores    = { 31 },
                                           .timeline             = AppTimelineInfo{ 1, { 7 }, 1, { 9 } },
                                           .frame_boundary       = kFrameBoundary,
                                           .frame_boundary_first = frame_boundary_first } });
    CHECK(lines == Lines{
                       "Submit timeline 1 [7] 1 [9] wait 30 stage 1 [10] count 1",
                       "Submit timeline 1 [7] 1 [9]" + kFrameBoundaryText + " [11] count 1 signal 31",
                   });
}

TEST_CASE("Command buffer stage keeps a frame boundary count that has no values", "[stage][isolate_cb][frame_boundary]")
{
    Rig rig;

    // The lists and the tag are optional in vk.xml, so the app may give a count with a null array.
    const auto lines = rig.SubmitLines(
        { { .command_buffers = { 10, 11 },
            .frame_boundary  = AppFrameBoundary{ .image_count = 1, .buffer_count = 2, .tag_size = 3 } } });
    CHECK(lines == Lines{
                       "Submit [10] count 1",
                       "Submit boundary 0 flags 0 images 1 [] buffers 2 [] tag 0 size 3 [] [11] count 1",
                   });
}

TEST_CASE("Command buffer stage drops a pNext struct that it cannot write and keeps the rest of the chain",
          "[stage][isolate_cb][pnext]")
{
    Rig rig;

    SECTION("In a call that it splits")
    {
        const auto lines = rig.SubmitLines({
            { .command_buffers   = { 10, 11 },
              .signal_semaphores = { 31 },
              .timeline          = AppTimelineInfo{ .signal_count = 1, .signal_values = { 9 } },
              .frame_boundary    = kFrameBoundary,
              .performance_query = true },
            // The stage writes every info of the call, so this one loses the struct as well.
            { .command_buffers = { 12 }, .performance_query = true },
        });
        CHECK(lines == Lines{
                           "Submit timeline 0 [] 1 [9] [10] count 1",
                           "Submit timeline 0 [] 1 [9]" + kFrameBoundaryText + " [11] count 1 signal 31",
                           "Submit [12] count 1",
                       });
    }

    SECTION("But not in a call that it forwards")
    {
        const auto lines = rig.SubmitLines({ { .command_buffers = { 11 }, .performance_query = true } });
        CHECK(lines == Lines{ "Submit query [11] count 1" });
    }
}

TEST_CASE("Command buffer stage forwards a call that has nothing to isolate", "[stage][isolate_cb]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);

    SECTION("one command buffer")
    {
        CHECK(rig.SubmitLines({ { .command_buffers = { 10 } } }, kFence) == Lines{ "Submit [10] count 1 fence 40" });
        CHECK(probe.replaced == std::vector<bool>{ false });
    }

    SECTION("no command buffer")
    {
        const AppSubmitInfo signal_only = { .signal_semaphores = { 31 } };
        CHECK(rig.SubmitLines({ signal_only }, kFence) == Lines{ "Submit [] count 0 signal 31 fence 40" });
    }

    SECTION("no submit info")
    {
        CHECK(rig.SubmitLines({}, kFence) == Lines{ "Submit fence 40" });
    }
}

// vkQueueSubmit2 and vkQueueSubmit2KHR. Each entry holds the name that CallLog prints and the call.
const std::vector<std::pair<std::string, format::ApiCallId>> kSubmit2Calls = {
    { "Submit2", format::ApiCall_vkQueueSubmit2 },
    { "Submit2KHR", format::ApiCall_vkQueueSubmit2KHR },
};

TEST_CASE("Command buffer stage submits each command buffer of a vkQueueSubmit2 in a call of its own",
          "[stage][isolate_cb][submit2]")
{
    const auto [name, call_id] = GENERATE(from_range(kSubmit2Calls));
    INFO(name);

    Rig rig;

    const auto lines =
        rig.Submit2Lines(call_id,
                         {
                             { .command_buffers   = { 10, 12, 11 },
                               .device_masks      = { 1, 2, 4 },
                               .wait_semaphores   = { 30, 32 },
                               .signal_semaphores = { 31, 33 },
                               .flags             = VK_SUBMIT_PROTECTED_BIT },
                             { .command_buffers = { 13 }, .device_masks = { 8 }, .wait_semaphores = { 34 } },
                             { .command_buffers = { 14, 15 }, .device_masks = { 16, 32 }, .signal_semaphores = { 35 } },
                         },
                         kFence,
                         VK_ERROR_DEVICE_LOST);
    CHECK(lines == Lines{
                       name + " flags 1 wait 30 32 [10:1] count 1 result -4",
                       name + " flags 1 [12:2] count 1 result -4",
                       name + " flags 1 [11:4] count 1 signal 31 33 result -4",
                       name + " wait 34 [13:8] count 1 result -4",
                       name + " [14:16] count 1 result -4",
                       name + " [15:32] count 1 signal 35 fence 40 result -4",
                   });
}

TEST_CASE("Command buffer stage submits a vkQueueSubmit2 info that has only semaphores", "[stage][isolate_cb][submit2]")
{
    const auto [name, call_id] = GENERATE(from_range(kSubmit2Calls));
    INFO(name);

    Rig rig;

    const AppSubmitInfo semaphores_only = { .wait_semaphores = { 30 }, .signal_semaphores = { 31 } };
    CHECK(rig.Submit2Lines(call_id, { semaphores_only, { .command_buffers = { 10 } } }, kFence) ==
          Lines{
              name + " wait 30 [] count 0 signal 31",
              name + " [10:0] count 1 fence 40",
          });
}

TEST_CASE("Command buffer stage writes an empty array of a vkQueueSubmit2 as a null array",
          "[stage][isolate_cb][submit2]")
{
    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);
    rig.Submit2Lines(format::ApiCall_vkQueueSubmit2,
                     { { .signal_semaphores = { 31 } },
                       { .command_buffers = { 10, 11 }, .wait_semaphores = { 30 }, .signal_semaphores = { 32 } } });

    // The first call has only signals. The other two share the waits and signals of their info.
    CHECK(probe.null_arrays == Lines{ "waits", "command buffers", "signals", "waits" });
}

TEST_CASE("Command buffer stage keeps the frame boundary of a vkQueueSubmit2 and drops a struct that it cannot write",
          "[stage][isolate_cb][submit2]")
{
    const auto [name, call_id] = GENERATE(from_range(kSubmit2Calls));
    INFO(name);

    Rig rig;

    const auto lines = rig.Submit2Lines(
        call_id,
        {
            { .command_buffers = { 10, 11, 12 }, .frame_boundary = kFrameBoundary, .performance_query = true },
            { .command_buffers = { 13 } },
        });
    CHECK(lines == Lines{
                       name + " [10:0] count 1",
                       name + " [11:0] count 1",
                       name + kFrameBoundaryText + " [12:0] count 1",
                       name + " [13:0] count 1",
                   });
}

TEST_CASE("Command buffer stage forwards a vkQueueSubmit2 that has nothing to isolate", "[stage][isolate_cb][submit2]")
{
    const auto [name, call_id] = GENERATE(from_range(kSubmit2Calls));
    INFO(name);

    SubmitProbe probe;

    Rig rig;
    rig.AddNext(&probe);

    SECTION("one command buffer")
    {
        CHECK(rig.Submit2Lines(call_id, { { .command_buffers = { 10 }, .performance_query = true } }, kFence) ==
              Lines{ name + " query [10:0] count 1 fence 40" });
        CHECK(probe.replaced == std::vector<bool>{ false });
    }

    SECTION("no command buffer")
    {
        CHECK(rig.Submit2Lines(call_id, { { .signal_semaphores = { 31 } } }, kFence) ==
              Lines{ name + " [] count 0 signal 31 fence 40" });
    }

    SECTION("no submit info")
    {
        CHECK(rig.Submit2Lines(call_id, {}, kFence) == Lines{ name + " fence 40" });
    }
}

// The stage warns about these calls. The tests do not see the log.
TEST_CASE("Command buffer stage forwards a render pass that is suspended or resumed", "[stage][isolate_cb]")
{
    const VkRenderingFlags flags = GENERATE(VK_RENDERING_SUSPENDING_BIT, VK_RENDERING_RESUMING_BIT);

    Rig rig;
    rig.Send(format::ApiCall_vkCmdBeginRendering, EncodeBeginRendering(10, flags));
    rig.Send(format::ApiCall_vkCmdBeginRenderingKHR, EncodeBeginRendering(11, flags));

    CHECK(rig.log.lines == Lines{ "BeginRendering 10", "BeginRenderingKHR 11" });
}

// Both stages together.

TEST_CASE("Isolate stages submit each part of a split command buffer in a vkQueueSubmit2 of its own",
          "[stage][isolate_cb][submit2][chain]")
{
    const auto [name, call_id] = GENERATE(from_range(kSubmit2Calls));
    INFO(name);

    ChainRig rig;
    rig.Allocate({ 10, 11 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);

    // Each part takes the device mask of the app's entry that it replaces.
    const auto lines = rig.Submit2Lines(call_id,
                                        { { .command_buffers   = { 10, 11 },
                                            .device_masks      = { 1, 2 },
                                            .wait_semaphores   = { 30 },
                                            .signal_semaphores = { 31 } } },
                                        kFence);
    CHECK(lines == Lines{
                       name + " wait 30 [10:1] count 1",
                       name + " [S1:1] count 1",
                       name + " [S2:1] count 1",
                       name + " [11:2] count 1 signal 31 fence 40",
                   });
}

TEST_CASE("Isolate stages submit each part of a split command buffer in a call of its own",
          "[stage][isolate_cb][chain]")
{
    ChainRig rig;
    rig.Allocate({ 10, 11, 12 });
    rig.RecordCopyAndRenderPasses(10, 2);
    rig.RecordCopyAndRenderPasses(11, 0);
    rig.RecordCopyAndRenderPasses(12, 1);

    const auto lines = rig.SubmitLines(
        {
            { .command_buffers = { 10, 11 }, .wait_semaphores = { 30 }, .wait_stages = { 1 } },
            { .command_buffers   = { 12 },
              .signal_semaphores = { 31 },
              .timeline          = AppTimelineInfo{ .signal_count = 1, .signal_values = { 9 } },
              .frame_boundary    = kFrameBoundary },
        },
        kFence);
    CHECK(lines == Lines{
                       "Submit wait 30 stage 1 [10] count 1",
                       "Submit [S1] count 1",
                       "Submit [S2] count 1",
                       "Submit [11] count 1",
                       "Submit timeline 0 [] 1 [9] [12] count 1",
                       "Submit timeline 0 [] 1 [9]" + kFrameBoundaryText + " [S3] count 1 signal 31 fence 40",
                   });
}

TEST_CASE("Isolate stages split a call that lists unsplit command buffers with a render pass each",
          "[stage][isolate_cb][chain]")
{
    ChainRig rig;
    rig.Allocate({ 10, 11 });
    for (const format::HandleId command_buffer : { 10, 11 })
    {
        rig.Begin(command_buffer);
        rig.BeginRenderPass(command_buffer);
        rig.Draw(command_buffer);
        rig.EndRenderPass(command_buffer);
        rig.End(command_buffer);
    }

    CHECK(rig.SubmitLines({ { .command_buffers = { 10, 11 } } }) == Lines{
                                                                        "Submit [10] count 1",
                                                                        "Submit [11] count 1",
                                                                    });
}

TEST_CASE("Isolate stages send the split calls through the second stage unchanged", "[stage][isolate_cb][chain]")
{
    ChainRig rig;
    rig.Allocate({ 10 });
    rig.Begin(10);
    rig.CopyBuffer(10);
    rig.BeginRenderPass(10);
    rig.End(10);

    CHECK(rig.log.lines == Lines{
                               "Allocate 1 2 primary 10",
                               "Begin 10 flags 0",
                               "CopyBuffer 10",
                               "End 10",
                               "Allocate 1 2 primary S1",
                               "Begin S1 flags 0",
                               "BeginRenderPass S1",
                               "End S1",
                           });
}
