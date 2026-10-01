#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the serialize-queue-submissions app and replay it with --serialize-queue-submissions.
 * The replay tool orders the submit entries of a queue-submit against each other by creating one timeline semaphore
 * per call and having the entries signal and wait on it in turn.
 */
TEST(SerializeQueueSubmissions, ReplayCreatesOneTimelineSemaphorePerMultiEntrySubmit)
{
    const char*                    test_name = "serialize-queue-submissions";
    const std::vector<std::string> counted   = { "vkCreateSemaphore", "vkQueueSubmit" };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));

    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(
        test_name, { "--serialize-queue-submissions" }, "_replay_option", counted, with_option));

    ASSERT_EQ(baseline["vkQueueSubmit"], 1u);
    EXPECT_EQ(with_option["vkQueueSubmit"], 1u);

    // One timeline semaphore for the two-entry submit, reused by both of its entries.
    EXPECT_EQ(with_option["vkCreateSemaphore"] - baseline["vkCreateSemaphore"], 1u);
}
