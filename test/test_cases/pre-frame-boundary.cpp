#include <gtest/gtest.h>

#include "verify-gfxr.h"

#include <string>
#include <vector>

namespace
{

// Use a trimmed capture as it carries a state block.
constexpr const char* kTestApp       = "triangle";
constexpr const char* kTrimmedFrames = "5-7";

// The replay runs offscreen to stay headless, which leaves it without a present to end its frames on.
// --offscreen-swapchain-frame-boundary makes it submit a VkFrameBoundaryEXT instead.
const std::vector<std::string> kFrameBoundaryArgs = { "--offscreen-swapchain-frame-boundary" };

constexpr size_t kNotFound = static_cast<size_t>(-1);

size_t index_of_first_marker(const std::vector<ConvertedBlock>& blocks, const char* marker, const char* marker_type)
{
    for (size_t i = 0; i < blocks.size(); ++i)
    {
        if (blocks[i].marker == marker && blocks[i].marker_type == marker_type)
        {
            return i;
        }
    }
    return kNotFound;
}

size_t index_of_last_marker(const std::vector<ConvertedBlock>& blocks, const char* marker, const char* marker_type)
{
    size_t found = kNotFound;
    for (size_t i = 0; i < blocks.size(); ++i)
    {
        if (blocks[i].marker == marker && blocks[i].marker_type == marker_type)
        {
            found = i;
        }
    }
    return found;
}

size_t index_of_first_call(const std::vector<ConvertedBlock>& blocks, const std::string& function_name)
{
    for (size_t i = 0; i < blocks.size(); ++i)
    {
        if (blocks[i].function == function_name)
        {
            return i;
        }
    }
    return kNotFound;
}

// Captures the trimmed trace and checks it has state setup ahead of the first frame.
void capture_and_check_state_block()
{
    std::vector<ConvertedBlock> blocks;
    ASSERT_NO_FATAL_FAILURE(capture_app(kTestApp, kTrimmedFrames));
    ASSERT_NO_FATAL_FAILURE(convert_capture(kTestApp, blocks, kTrimmedFrames));

    const size_t state_begin     = index_of_first_marker(blocks, "state", "BeginMarker");
    const size_t first_frame_end = index_of_first_marker(blocks, "frame", "EndMarker");

    ASSERT_NE(state_begin, kNotFound) << "the trimmed capture holds no state block";
    ASSERT_NE(first_frame_end, kNotFound) << "the trimmed capture holds no frame";

    const size_t state_end = index_of_last_marker(blocks, "state", "EndMarker");
    ASSERT_NE(state_end, kNotFound) << "the trimmed capture holds no state block end marker";

    ASSERT_LT(state_begin, state_end) << "the state block ends before it begins";

    ASSERT_LT(state_end, first_frame_end) << "the state block of the trimmed capture is not ahead of its first frame";
}

} // namespace

/**
 * Replay a trimmed capture and check that its state setup is replayed before the first frame starts.
 *
 * Uses --flush-measurement-range to insert a vkDeviceWaitIdle before every frame to indicate where the frame starts.
 */
TEST(PreFrameBoundary, StateSetupIsReplayedBeforeTheFirstFrame)
{
    ASSERT_NO_FATAL_FAILURE(capture_and_check_state_block());

    // The measurement range starts at frame 1, the first frame of the trimmed range.
    std::vector<std::string> flush_args = kFrameBoundaryArgs;
    flush_args.insert(flush_args.end(), { "--measurement-frame-range", "1-3", "--flush-measurement-range" });

    std::vector<ConvertedBlock> flushed;
    ASSERT_NO_FATAL_FAILURE(convert_recapture(kTestApp, flush_args, "_replay_flush", flushed, kTrimmedFrames));

    const size_t frame_one_end = index_of_first_marker(flushed, "frame", "EndMarker");
    ASSERT_NE(frame_one_end, kNotFound) << "the recapture of the replay holds no frame";

    const size_t frame_one_begin = index_of_first_call(flushed, "vkDeviceWaitIdle");
    ASSERT_NE(frame_one_begin, kNotFound)
        << "the replay recorded no vkDeviceWaitIdle: it did not flush before the measurement range";

    EXPECT_LT(frame_one_begin, frame_one_end) << "the flush of the measurement range landed past the first frame";
}
