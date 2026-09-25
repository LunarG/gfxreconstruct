#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the isolate-render-passes app and replay it with --serialize-render-passes.
 * The replay tool injects an ALL_GRAPHICS -> ALL_GRAPHICS execution barrier before every render pass begin, so
 * rendering cannot overlap on the GPU.
 * This test exercises the code path and checks that there are injected barriers.
 */
TEST(SerializeRenderPasses, ReplayInjectsBarrierBeforeEachRenderPass)
{
    const char*                    test_name = "isolate-render-passes"; // This app has multiple render passes.
    const std::vector<std::string> counted   = { "vkCmdPipelineBarrier", "vkCmdBeginRenderPass" };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    // Replay the app with and without the option "--serialize-render-passes" to compare the counts of barrier commands.
    std::map<std::string, int> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, &baseline));
    std::map<std::string, int> with_option;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(
        test_name, { "--serialize-render-passes" }, "_replay_option", counted, &with_option));

    const int render_passes = with_option["vkCmdBeginRenderPass"];

    // The app has to actually begin render passes for the option to have anything to serialize.
    ASSERT_GT(render_passes, 0);

    // Number of render passes stays the same.
    EXPECT_EQ(render_passes, baseline["vkCmdBeginRenderPass"]);

    // Exactly one barrier injected before each of them.
    EXPECT_EQ(with_option["vkCmdPipelineBarrier"] - baseline["vkCmdPipelineBarrier"], render_passes);
}
