#include <gtest/gtest.h>

#include "replay-event-recorder-utils.h"
#include "verify-gfxr.h"

#include <cstdint>
#include <vector>

namespace
{

// Use a trimmed capture as it carries a state block.
constexpr const char* kTestApp       = "triangle";
constexpr const char* kTrimmedFrames = "5-7";

} // namespace

/**
 * Replay a trimmed capture and check that its state setup is replayed before the first frame starts.
 *
 * Uses a replay event plugin to record the order of the STATE_SETUP_BEGIN/END and FRAME_BEGIN/END events.
 */
TEST(PreFrameBoundary, StateSetupIsReplayedBeforeTheFirstFrame)
{
    std::vector<RecordedEvent> events;
    ASSERT_NO_FATAL_FAILURE(replay_and_record_events(kTestApp, {}, events, kTrimmedFrames));

    const size_t state_begin = index_of_first_event(events, GFXR_REPLAY_EVENT_STATE_SETUP_BEGIN);
    const size_t state_end   = index_of_first_event(events, GFXR_REPLAY_EVENT_STATE_SETUP_END);
    const size_t frame_begin = index_of_first_event(events, GFXR_REPLAY_EVENT_FRAME_BEGIN);
    const size_t frame_end   = index_of_first_event(events, GFXR_REPLAY_EVENT_FRAME_END);

    ASSERT_NE(state_begin, kEventNotFound)
        << "replay emitted no STATE_SETUP_BEGIN: the trimmed capture holds no state block";
    ASSERT_NE(state_end, kEventNotFound) << "replay emitted no STATE_SETUP_END";
    ASSERT_NE(frame_begin, kEventNotFound) << "replay emitted no FRAME_BEGIN";
    ASSERT_NE(frame_end, kEventNotFound) << "replay emitted no FRAME_END";

    EXPECT_LT(state_begin, state_end) << "the state setup ends before it begins";
    EXPECT_LT(frame_begin, frame_end) << "the first frame ends before it begins";

    EXPECT_LT(state_end, frame_begin) << "the state setup was replayed inside the first frame instead of ahead of it";
}
