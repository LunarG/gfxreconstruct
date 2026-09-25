#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the serialize-compute-and-transfer app and replay it with --serialize-compute-and-transfer.
 * The replay tool wraps every compute dispatch with an injected pipeline barrier before and after, so compute and
 * transfer work cannot overlap on the GPU.
 * This test exercises the code path and checks that there are injected barriers.
 */
TEST(SerializeComputeAndTransfer, ReplayInjectsBarriersAroundDispatches)
{
    const char*                    test_name = "serialize-compute-and-transfer";
    const std::vector<std::string> counted   = {
          "vkCmdPipelineBarrier", "vkCmdDispatch", "vkCmdDispatchBase", "vkCmdDispatchIndirect"
    };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    // Replay the app with and without the option "--serialize-compute-and-transfer" to compare the counts of barrier
    // commands.
    std::map<std::string, int> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, &baseline));
    std::map<std::string, int> with_option;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(
        test_name, { "--serialize-compute-and-transfer" }, "_replay_option", counted, &with_option));

    ASSERT_GT(with_option["vkCmdDispatch"], 0);
    ASSERT_GT(with_option["vkCmdDispatchBase"], 0);
    ASSERT_GT(with_option["vkCmdDispatchIndirect"], 0);

    // Must not add or drop a dispatch.
    EXPECT_EQ(with_option["vkCmdDispatch"], baseline["vkCmdDispatch"]);
    EXPECT_EQ(with_option["vkCmdDispatchBase"], baseline["vkCmdDispatchBase"]);
    EXPECT_EQ(with_option["vkCmdDispatchIndirect"], baseline["vkCmdDispatchIndirect"]);

    const int dispatches =
        with_option["vkCmdDispatch"] + with_option["vkCmdDispatchBase"] + with_option["vkCmdDispatchIndirect"];

    // One barrier before and one after each of them.
    EXPECT_EQ(with_option["vkCmdPipelineBarrier"] - baseline["vkCmdPipelineBarrier"], 2 * dispatches);
}
