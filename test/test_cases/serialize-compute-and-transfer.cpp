#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the serialize-compute-and-transfer app and replay it with --serialize-compute-and-transfer.
 * The replay tool wraps every compute dispatch with an injected pipeline barrier before and after,
 * so compute and transfer work cannot overlap on the GPU.
 * This test exercises that code path against the mock ICD and asserts the replay completes successfully.
 */
TEST(SerializeComputeAndTransfer, ReplayInjectsBarriersAroundDispatches)
{
    capture_and_replay("serialize-compute-and-transfer", { "--serialize-compute-and-transfer" });
}
