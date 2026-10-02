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

    // Replay the app with and without the option "--idle-before-submit" to compare.
    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--idle-before-submit" }, "_replay_option", counted, with_option));

    const uint32_t submits = with_option["vkQueueSubmit"] + with_option["vkQueueSubmit2"];

    // The app has to actually submit for the option to have anything to wait before.
    ASSERT_GT(submits, 0u);

    // Submits should not change
    EXPECT_EQ(with_option["vkQueueSubmit"], baseline["vkQueueSubmit"]);
    EXPECT_EQ(with_option["vkQueueSubmit2"], baseline["vkQueueSubmit2"]);

    // Check that there are injected waits.
    const int64_t injected_waits =
        static_cast<int64_t>(with_option["vkDeviceWaitIdle"]) - static_cast<int64_t>(baseline["vkDeviceWaitIdle"]);
    EXPECT_GT(injected_waits, 0) << "--idle-before-submit did not inject any vkDeviceWaitIdle calls";
    EXPECT_LE(injected_waits, static_cast<int64_t>(submits)) << "replay waited more often than it submitted";
}
