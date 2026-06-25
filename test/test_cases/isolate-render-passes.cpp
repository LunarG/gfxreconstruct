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
