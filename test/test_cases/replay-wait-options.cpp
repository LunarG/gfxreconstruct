#include <gtest/gtest.h>

#include <cstdint>
#include <string>
#include <vector>

#include "replay-event-recorder-utils.h"

/**
 * Replay a capture with --wait-before-frame and --wait-before-first-submit and assert that replay
 * emits the wait events the plugin ABI promises.
 */

namespace
{

// Replay sleeps this long before the first queue submit of each replayed frame.
constexpr uint32_t kWaitBeforeFrameMs = 20;

// Replay sleeps until this much time has elapsed since it parsed its options, once per process.
constexpr uint32_t kWaitBeforeFirstSubmitMs = 200;

void check_wait_duration(const std::vector<RecordedEvent>& events)
{
    // Allow one us of slack
    constexpr uint64_t kTimestampResolutionNs = 1000;

    for (size_t i = 0; i < events.size(); ++i)
    {
        if (events[i].type != GFXR_REPLAY_EVENT_WAIT_BEGIN)
        {
            continue;
        }

        ASSERT_LT(i + 1, events.size()) << "the last recorded event is a WAIT_BEGIN with no WAIT_END";

        const RecordedEvent& wait_begin = events[i];
        const RecordedEvent& wait_end   = events[i + 1];
        ASSERT_EQ(wait_end.type, GFXR_REPLAY_EVENT_WAIT_END)
            << "event " << i << " is a WAIT_BEGIN, but the event after it is not its WAIT_END";

        uint64_t begin_ns = unsigned_field(wait_begin, "timestamp_ns");
        uint64_t end_ns   = unsigned_field(wait_end, "timestamp_ns");
        ASSERT_GE(end_ns, begin_ns) << "the WAIT_END at event " << (i + 1) << " is timestamped before its WAIT_BEGIN";

        uint64_t requested_ns = unsigned_field(wait_begin, "requested_duration_ms") * 1000000;
        EXPECT_GE(end_ns - begin_ns + kTimestampResolutionNs, requested_ns)
            << "the wait at event " << i << " requested " << requested_ns << " ns but lasted only "
            << (end_ns - begin_ns) << " ns";
    }
}

} // namespace

TEST(ReplayWaitOptions, WaitBeforeFrameEmitsAWaitPerFrame)
{
    std::vector<RecordedEvent> events;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_record_events("triangle", { "--wait-before-frame", std::to_string(kWaitBeforeFrameMs) }, events));

    std::vector<RecordedEvent> wait_begins = events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN);

    EXPECT_GT(wait_begins.size(), 1) << "--wait-before-frame emitted " << wait_begins.size()
                                     << " waits, so it did not wait before every frame";
    EXPECT_EQ(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).size(), wait_begins.size());

    for (const RecordedEvent& wait_begin : wait_begins)
    {
        EXPECT_EQ(unsigned_field(wait_begin, "requested_duration_ms"), kWaitBeforeFrameMs);
    }

    check_wait_duration(events);
}

TEST(ReplayWaitOptions, WaitBeforeFirstSubmitEmitsOneWait)
{
    std::vector<RecordedEvent> events;
    ASSERT_NO_FATAL_FAILURE(replay_and_record_events(
        "triangle", { "--wait-before-first-submit", std::to_string(kWaitBeforeFirstSubmitMs) }, events));

    std::vector<RecordedEvent> wait_begins = events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN);

    ASSERT_EQ(wait_begins.size(), 1) << "the first queue submit is only delayed once per replay";
    EXPECT_EQ(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).size(), 1);

    // Check the wait was for a valid time.
    EXPECT_GT(unsigned_field(wait_begins.front(), "requested_duration_ms"), 0);

    check_wait_duration(events);
}

TEST(ReplayWaitOptions, NoWaitOptionEmitsNoWaitEvents)
{
    std::vector<RecordedEvent> events;
    ASSERT_NO_FATAL_FAILURE(replay_and_record_events("triangle", {}, events));

    EXPECT_FALSE(events.empty()) << "the recorder plugin received no events at all";
    EXPECT_TRUE(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_BEGIN).empty());
    EXPECT_TRUE(events_of_type(events, GFXR_REPLAY_EVENT_WAIT_END).empty());
}
