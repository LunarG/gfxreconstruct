#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the triangle app with and without --idle-before-submit and check occurences of injected
 * vkDeviceWaitIdle
 */
TEST(IdleBeforeSubmit, ReplayInjectsADeviceWaitIdleBeforeEverySubmit)
{
    const char*                    test_name = "triangle";
    const std::vector<std::string> counted   = { "vkDeviceWaitIdle", "vkQueueSubmit", "vkQueueSubmit2" };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::map<std::string, uint32_t> captured;
    ASSERT_NO_FATAL_FAILURE(count_calls_in_capture(test_name, counted, captured));

    const uint32_t captured_submits = captured["vkQueueSubmit"] + captured["vkQueueSubmit2"];

    // The app has to actually submit for the option to have anything to wait before.
    ASSERT_GT(captured_submits, 0u);

    // Replay the app with and without the option "--idle-before-submit" to compare.
    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--idle-before-submit" }, "_replay_option", counted, with_option));

    // Submits should not change
    EXPECT_EQ(with_option["vkQueueSubmit"], baseline["vkQueueSubmit"]);
    EXPECT_EQ(with_option["vkQueueSubmit2"], baseline["vkQueueSubmit2"]);

    // Check that there is exactly one injected wait for every submit the capture holds.
    const int64_t injected_waits =
        static_cast<int64_t>(with_option["vkDeviceWaitIdle"]) - static_cast<int64_t>(baseline["vkDeviceWaitIdle"]);
    EXPECT_EQ(injected_waits, static_cast<int64_t>(captured_submits))
        << "--idle-before-submit did not inject one vkDeviceWaitIdle per captured submit";
}
