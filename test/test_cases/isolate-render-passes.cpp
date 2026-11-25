#include <gtest/gtest.h>

#include "verify-gfxr.h"

#include <algorithm>
#include <numeric>

/**
 * Capture the legacy-render-pass app and replay it with --isolate-render-passes.
 * The stages before the replay consumer split the command buffer around each render pass and submit the parts
 * separately.
 * This test exercises that code path against the mock ICD and asserts the replay completes successfully.
 */
TEST(IsolateRenderPasses, ReplaySplitsLegacyRenderPasses)
{
    capture_and_replay("isolate-render-passes", { "--isolate-render-passes" });
}

/**
 * Capture the isolate-render-passes app and replay it with --isolate-render-passes.
 * The recording is cut at every render pass boundary that has commands on its other side, and continues in a fresh
 * command buffer each time. Every render pass ends up in a command buffer and a queue submit of its own.
 */
TEST(IsolateRenderPasses, ReplaySubmitsEachRenderPassSeparately)
{
    const char*                    test_name = "isolate-render-passes";
    const std::vector<std::string> counted   = {
          "vkCmdBeginRenderPass", "vkBeginCommandBuffer", "vkEndCommandBuffer", "vkQueueSubmit", "vkCreateSemaphore"
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

    // The app records a barrier before, between and after its two render passes, so each pass is cut off on both sides.
    const uint32_t cuts = 2 * render_passes;

    // Every cut ends the current command buffer and begins a fresh one.
    EXPECT_EQ(with_option["vkBeginCommandBuffer"] - baseline["vkBeginCommandBuffer"], cuts);
    EXPECT_EQ(with_option["vkEndCommandBuffer"] - baseline["vkEndCommandBuffer"], cuts);

    // Each part that a cut adds gets a queue submit of its own.
    EXPECT_EQ(with_option["vkQueueSubmit"] - baseline["vkQueueSubmit"], cuts);

    // Submission order keeps the waits, the signals and the fence valid, so the option adds no semaphore.
    EXPECT_EQ(with_option["vkCreateSemaphore"], baseline["vkCreateSemaphore"]);
}

/**
 * Each queue submit of a replay with --isolate-render-passes holds at most one render pass.
 */
TEST(IsolateRenderPasses, ReplaySubmitsAtMostOneRenderPassPerCall)
{
    const char* test_name = "isolate-render-passes";

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::vector<uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_render_passes_per_submit(test_name, {}, "_passes_per_submit_baseline", baseline));
    std::vector<uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_render_passes_per_submit(
        test_name, { "--isolate-render-passes" }, "_passes_per_submit_option", with_option));

    // Without the option some submits hold more than one render pass, so there is something to isolate.
    ASSERT_FALSE(baseline.empty());
    ASSERT_GT(*std::max_element(baseline.begin(), baseline.end()), 1u);

    ASSERT_FALSE(with_option.empty());
    EXPECT_EQ(*std::max_element(with_option.begin(), with_option.end()), 1u);

    // No render pass is lost or submitted twice.
    EXPECT_EQ(std::accumulate(with_option.begin(), with_option.end(), 0u),
              std::accumulate(baseline.begin(), baseline.end(), 0u));
}

/**
 * --idle-before-submit waits before the submit of every part, so the render passes cannot overlap.
 */
TEST(IsolateRenderPasses, IdleBeforeSubmitWaitsBeforeEveryPart)
{
    const char*                    test_name = "isolate-render-passes";
    const std::vector<std::string> counted   = { "vkQueueSubmit", "vkDeviceWaitIdle" };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::map<std::string, uint32_t> captured;
    ASSERT_NO_FATAL_FAILURE(count_calls_in_capture(test_name, counted, captured));

    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> isolated;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--isolate-render-passes" }, "_replay_option", counted, isolated));
    std::map<std::string, uint32_t> with_idle;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(
        test_name, { "--isolate-render-passes", "--idle-before-submit" }, "_replay_idle", counted, with_idle));

    // Replay also submits for its offscreen swapchain, and it does not wait before those submits. So count the
    // submits of the app and the ones that the parts add.
    const uint32_t added_submits = isolated["vkQueueSubmit"] - baseline["vkQueueSubmit"];
    ASSERT_GT(added_submits, 0u);

    EXPECT_EQ(with_idle["vkQueueSubmit"], isolated["vkQueueSubmit"]);
    EXPECT_EQ(with_idle["vkDeviceWaitIdle"] - isolated["vkDeviceWaitIdle"], captured["vkQueueSubmit"] + added_submits);
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

    // The app records a barrier before and after its render pass, so the recording is cut on both sides of the pass.
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
