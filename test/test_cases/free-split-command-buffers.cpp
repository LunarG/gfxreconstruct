#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the free-split-command-buffers app, which frees every command buffer it records, and replay it with
 * --isolate-render-passes. The replay tool splits each recorded command buffer at its render pass boundaries into
 * extra command buffers that it allocates behind the original one. When the app frees the original, replay has to
 * free those extra command buffers too, and must not touch them again afterwards: #3190 reset them after freeing them.
 */
TEST(FreeSplitCommandBuffers, ReplayFreesSplitCommandBuffersWithoutUsingThemAfterwards)
{
    const char*                    test_name = "free-split-command-buffers";
    const std::vector<std::string> counted   = { "vkFreeCommandBuffers", "vkCmdBeginRenderPass" };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::map<std::string, uint32_t> captured;
    ASSERT_NO_FATAL_FAILURE(count_calls_in_capture(test_name, counted, captured));

    // The app has to free command buffers that hold render passes for the option to have anything to split and free.
    ASSERT_GT(captured["vkFreeCommandBuffers"], 0u);
    ASSERT_GT(captured["vkCmdBeginRenderPass"], 0u);

    // Replay the app with and without the option "--isolate-render-passes" to compare.
    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, { "--isolate-render-passes" }, "_replay_option", counted, with_option));

    // Every command buffer this app records holds render passes, so each one is split. Freeing it also frees the
    // extra command buffers of the split, in one vkFreeCommandBuffers call of their own.
    EXPECT_EQ(with_option["vkFreeCommandBuffers"] - baseline["vkFreeCommandBuffers"], captured["vkFreeCommandBuffers"]);

    // Nothing in either replay may use a command buffer after it was freed, neither the ones the app frees nor the
    // extra ones replay frees along with them.
    uint32_t baseline_uses = 0;
    ASSERT_NO_FATAL_FAILURE(
        count_uses_of_freed_command_buffers_in_recapture(test_name, "_replay_baseline", baseline_uses));
    EXPECT_EQ(baseline_uses, 0u);

    uint32_t with_option_uses = 0;
    ASSERT_NO_FATAL_FAILURE(
        count_uses_of_freed_command_buffers_in_recapture(test_name, "_replay_option", with_option_uses));
    EXPECT_EQ(with_option_uses, 0u) << "--isolate-render-passes used command buffers after freeing them";
}
