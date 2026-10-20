#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the triangle app and replay it with --frame-warm-up-spirv and --frame-warm-up-load.
 * Checks that there is an additional submit before every frame that dispatches a compute when doing frame warmup.
 * The warm-up shader is the example compute shader from the Frame Warm-Up section of USAGE_desktop_Vulkan.md.
 */
TEST(FrameWarmUp, ReplaySubmitsComputeBeforeEachFrame)
{
    const char*                    test_name = "triangle";
    const std::vector<std::string> counted   = {
          "vkQueueSubmit",        "vkQueuePresentKHR",        "vkCmdDispatch",
          "vkCreateShaderModule", "vkCreateComputePipelines", "vkBeginCommandBuffer"
    };
    const std::vector<std::string> warm_up_args = {
        "--frame-warm-up-spirv", "res/frame-warm-up/shaders/warm_up.comp.spv", "--frame-warm-up-load", "1"
    };

    ASSERT_NO_FATAL_FAILURE(capture_app(test_name));

    std::map<std::string, uint32_t> captured;
    ASSERT_NO_FATAL_FAILURE(count_calls_in_capture(test_name, counted, captured));

    const uint32_t frames = captured["vkQueuePresentKHR"];
    ASSERT_GT(frames, 0u);

    // Check triangle app submits on each frame and doesn't do compute work.
    ASSERT_EQ(captured["vkQueueSubmit"], frames);
    ASSERT_EQ(captured["vkCmdDispatch"], 0u);
    ASSERT_EQ(captured["vkCreateComputePipelines"], 0u);

    // Replay the app with and without the frame warm-up options to compare.
    std::map<std::string, uint32_t> baseline;
    ASSERT_NO_FATAL_FAILURE(replay_and_count_recapture(test_name, {}, "_replay_baseline", counted, baseline));
    std::map<std::string, uint32_t> with_option;
    ASSERT_NO_FATAL_FAILURE(
        replay_and_count_recapture(test_name, warm_up_args, "_replay_option", counted, with_option));

    // The warm-up builds a single compute pipeline and records its dispatch into one command buffer.
    EXPECT_EQ(with_option["vkCreateShaderModule"] - baseline["vkCreateShaderModule"], 1u);
    EXPECT_EQ(with_option["vkCreateComputePipelines"] - baseline["vkCreateComputePipelines"], 1u);
    EXPECT_EQ(with_option["vkBeginCommandBuffer"] - baseline["vkBeginCommandBuffer"], 1u);
    EXPECT_EQ(with_option["vkCmdDispatch"] - baseline["vkCmdDispatch"], 1u);

    // The computes are submitted before every frame.
    EXPECT_EQ(with_option["vkQueueSubmit"] - baseline["vkQueueSubmit"], frames);
}
