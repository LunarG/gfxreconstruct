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
 * Replaying with --isolate-render-passes cuts the recording at every render pass boundary, so replay must reissue the
 * state bound before each cut.
 */
TEST(IsolateRenderPasses, ReplayReissuesCommandBufferState)
{
    const char*                    test_name = "triangle";
    const std::vector<std::string> counted   = {
          "vkCmdBeginRenderPass", "vkCmdSetViewport", "vkCmdSetScissor", "vkCmdBindPipeline"
    };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    // Replay the app with and without the option "--isolate-render-passes" to compare.
    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--isolate-render-passes" }, "_replay_option", counted, with_option));

    const uint32_t render_passes = with_option["vkCmdBeginRenderPass"];

    // The app has to actually begin render passes for the option to have anything to isolate.
    ASSERT_GT(render_passes, 0u);

    EXPECT_EQ(render_passes, baseline["vkCmdBeginRenderPass"]);

    // The app binds each of these once per render pass.
    ASSERT_EQ(baseline["vkCmdSetViewport"], render_passes);
    ASSERT_EQ(baseline["vkCmdSetScissor"], render_passes);
    ASSERT_EQ(baseline["vkCmdBindPipeline"], render_passes);

    // The recording is cut twice per render pass, before vkCmdBeginRenderPass and before vkCmdEndRenderPass.
    const uint32_t cuts = 2 * render_passes;

    // Viewport and scissor are set before the render pass begins, so both are already recorded by the first cut and
    // are reissued into the command buffer that every cut starts.
    EXPECT_EQ(with_option["vkCmdSetViewport"] - baseline["vkCmdSetViewport"], cuts);
    EXPECT_EQ(with_option["vkCmdSetScissor"] - baseline["vkCmdSetScissor"], cuts);

    // The pipeline is bound inside the render pass, so it is only on record by the time of the second cut and is
    // reissued once per render pass rather than once per cut.
    EXPECT_EQ(with_option["vkCmdBindPipeline"] - baseline["vkCmdBindPipeline"], render_passes);
}

/**
 * Check every draw for it's state that was bound to match what was being bound without the option.
 *
 * Triangle capture binds only a pipeline, viewport and scissor.
 */
TEST(IsolateRenderPasses, ReissuedStateReachesEveryDraw)
{
    const char* test_name = "triangle";

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::vector<DrawCallState> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_record_draw_states(test_name, {}, "_draw_state_baseline", baseline));
    std::vector<DrawCallState> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_record_draw_states(test_name, { "--isolate-render-passes" }, "_draw_state_option", with_option));

    // The app has to actually draw for there to be anything to reissue state for.
    ASSERT_GT(baseline.size(), 0u);

    // Isolating the render passes moves the draws into other command buffers, but must not add or drop any.
    ASSERT_EQ(with_option.size(), baseline.size());

    for (size_t i = 0; i < with_option.size(); ++i)
    {
        // Without the reissue the draws that follow a cut would land in a command buffer with nothing bound to it.
        for (const char* required : { "vkCmdBindPipeline", "vkCmdSetViewport", "vkCmdSetScissor" })
        {
            EXPECT_NE(with_option[i].count(required), 0u)
                << "draw " << i << " had no " << required << " on its command buffer";
        }

        EXPECT_EQ(with_option[i], baseline[i]) << "draw " << i << " was bound different state than without the option";
    }
}
