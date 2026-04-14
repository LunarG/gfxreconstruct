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

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <vulkan/vulkan.h>

#include <plugin/replay_event_sink.h>

class TestReplayEventSink : public gfxrecon::plugin::ReplayEventSink
{
  public:
    GfxrReplayEventHeader         last_event_header     = {};
    GfxrReplayQueueSubmitEndEvent last_submit_end_event = {};
    GfxrReplayFrameEndEvent       last_frame_end_event  = {};

  protected:
    void EmitQueueSubmitBegin(const GfxrReplayQueueSubmitBeginEvent& event) override
    {
        REQUIRE(event.header.abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION);
        REQUIRE(event.header.type == GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN);
        REQUIRE(event.header.struct_size == sizeof(GfxrReplayQueueSubmitBeginEvent));
        last_event_header = event.header;
    }

    void EmitQueueSubmitEnd(const GfxrReplayQueueSubmitEndEvent& event) override
    {
        REQUIRE(event.header.abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION);
        REQUIRE(event.header.type == GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END);
        REQUIRE(event.header.struct_size == sizeof(GfxrReplayQueueSubmitEndEvent));
        last_event_header     = event.header;
        last_submit_end_event = event;
    }

    void EmitFrameBegin(const GfxrReplayFrameBeginEvent& event) override
    {
        REQUIRE(event.header.abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION);
        REQUIRE(event.header.type == GFXR_REPLAY_EVENT_FRAME_BEGIN);
        REQUIRE(event.header.struct_size == sizeof(GfxrReplayFrameBeginEvent));
        last_event_header = event.header;
    }

    void EmitFrameEnd(const GfxrReplayFrameEndEvent& event) override
    {
        REQUIRE(event.header.abi_version == GFXR_REPLAY_PLUGIN_ABI_VERSION);
        REQUIRE(event.header.type == GFXR_REPLAY_EVENT_FRAME_END);
        REQUIRE(event.header.struct_size == sizeof(GfxrReplayFrameEndEvent));
        last_event_header    = event.header;
        last_frame_end_event = event;
    }
};

TEST_CASE("ReplayEventSink - frame lifecycle", "[plugin]")
{
    using namespace gfxrecon::plugin;

    TestReplayEventSink event_sink;

    REQUIRE_FALSE(event_sink.IsFrameActive());
    event_sink.FrameBegin(0);
    REQUIRE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    event_sink.FrameEnd();
    REQUIRE_FALSE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    REQUIRE(event_sink.last_frame_end_event.first_submit_index == GFXR_REPLAY_INVALID_SUBMIT_INDEX);
    REQUIRE(event_sink.last_frame_end_event.last_submit_index == GFXR_REPLAY_INVALID_SUBMIT_INDEX);
}

TEST_CASE("ReplayEventSink - two submits", "[plugin]")
{
    using namespace gfxrecon::plugin;

    TestReplayEventSink event_sink;

    REQUIRE_FALSE(event_sink.IsFrameActive());
    event_sink.FrameBegin(0);
    REQUIRE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 0);

    uint64_t submit_index = event_sink.QueueSubmitBegin(0);
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    event_sink.QueueSubmitEnd(submit_index, 0, VK_SUCCESS, GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN);
    REQUIRE(submit_index == 0);
    REQUIRE(event_sink.last_submit_end_event.submit_index == submit_index);

    uint64_t next_submit_index = event_sink.QueueSubmitBegin(0);
    REQUIRE(next_submit_index == submit_index + 1);
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    event_sink.QueueSubmitEnd(
        next_submit_index, 0, VK_SUCCESS, GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN);
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    REQUIRE(event_sink.last_submit_end_event.submit_index == next_submit_index);

    event_sink.FrameEnd();
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    REQUIRE(event_sink.last_frame_end_event.first_submit_index == 0);
    REQUIRE(event_sink.last_frame_end_event.last_submit_index == next_submit_index);
    REQUIRE_FALSE(event_sink.IsFrameActive());
}

TEST_CASE("ReplayEventSink - global submit index", "[plugin]")
{
    using namespace gfxrecon::plugin;

    TestReplayEventSink event_sink;

    REQUIRE_FALSE(event_sink.IsFrameActive());
    event_sink.FrameBegin(0);
    REQUIRE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 0);

    uint64_t submit_index = event_sink.QueueSubmitBegin(0);
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    event_sink.QueueSubmitEnd(submit_index, 0, VK_SUCCESS, GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN);
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    REQUIRE(submit_index == 0);
    REQUIRE(event_sink.last_submit_end_event.submit_index == submit_index);

    event_sink.FrameEnd();
    REQUIRE_FALSE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 0);
    REQUIRE(event_sink.last_frame_end_event.first_submit_index == 0);
    REQUIRE(event_sink.last_frame_end_event.last_submit_index == submit_index);

    event_sink.FrameBegin(1);
    REQUIRE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 1);

    uint64_t next_submit_index = event_sink.QueueSubmitBegin(0);
    REQUIRE(event_sink.last_event_header.frame_index == 1);
    REQUIRE(next_submit_index == submit_index + 1);
    event_sink.QueueSubmitEnd(
        next_submit_index, 0, VK_SUCCESS, GFXR_REPLAY_QUEUE_SUBMIT_COMPLETION_SOURCE_SUBMIT_RETURN);
    REQUIRE(event_sink.last_event_header.frame_index == 1);
    REQUIRE(event_sink.last_submit_end_event.submit_index == next_submit_index);
    event_sink.FrameEnd();
    REQUIRE_FALSE(event_sink.IsFrameActive());
    REQUIRE(event_sink.last_event_header.frame_index == 1);
    REQUIRE(event_sink.last_frame_end_event.first_submit_index == next_submit_index);
    REQUIRE(event_sink.last_frame_end_event.last_submit_index == next_submit_index);
}
