#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the legacy-render-pass app and replay it with --isolate-render-passes.
 * The replay tool splits the command buffer at each vkCmdBeginRenderPass/vkCmdEndRenderPass boundary
 * and submits the segments separately.
 * This test exercises that code path against the mock ICD and asserts the replay completes successfully.
 */
TEST(IsolateRenderPasses, ReplaySplitsLegacyRenderPasses)
{
    capture_and_replay("isolate-render-passes", { "--isolate-render-passes" });
}

/**
 * Capture the isolate-render-passes app and replay it with --isolate-render-passes.
 * The replay tool cuts the recording at every vkCmdBeginRenderPass and vkCmdEndRenderPass, continuing it in a fresh
 * command buffer each time, so every render pass has it's own command buffer.
 */
TEST(IsolateRenderPasses, ReplaySubmitsEachRenderPassSeparately)
{
    const char*                    test_name = "isolate-render-passes";
    const std::vector<std::string> counted   = {
          "vkCmdBeginRenderPass", "vkBeginCommandBuffer", "vkEndCommandBuffer", "vkQueueSubmit", "vkCreateSemaphore"
    };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    // Replay the app with and without the option "--isolate-render-passes" to compare.
    std::map<std::string, int> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, &baseline));
    std::map<std::string, int> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--isolate-render-passes" }, "_replay_option", counted, &with_option));

    const int render_passes = with_option["vkCmdBeginRenderPass"];

    // The app has to actually begin render passes for the option to have anything to isolate.
    ASSERT_GT(render_passes, 0);

    EXPECT_EQ(render_passes, baseline["vkCmdBeginRenderPass"]);

    // The recording is cut twice per render pass.
    const int cuts = 2 * render_passes;

    // Every cut ends the current command buffer and begins a fresh one.
    EXPECT_EQ(with_option["vkBeginCommandBuffer"] - baseline["vkBeginCommandBuffer"], cuts);
    EXPECT_EQ(with_option["vkEndCommandBuffer"] - baseline["vkEndCommandBuffer"], cuts);

    // Each part finished by a cut gets a queue submit of its own, on top of the submit the app itself recorded.
    EXPECT_EQ(with_option["vkQueueSubmit"] - baseline["vkQueueSubmit"], cuts);

    // Every command buffer this app records holds render passes, so each one is split and gets one injected timeline
    // semaphore that keeps the submits of its parts in order.
    const int recorded_command_buffers = baseline["vkBeginCommandBuffer"];
    ASSERT_GT(recorded_command_buffers, 0);
    EXPECT_EQ(with_option["vkCreateSemaphore"] - baseline["vkCreateSemaphore"], recorded_command_buffers);
}
