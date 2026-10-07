#include <gtest/gtest.h>

#include "verify-gfxr.h"

/**
 * Capture the triangle app and replay it with the realign memory portability mode (-m realign).
 * Realign runs a resource tracking pass over the capture before the actual replay. That pass creates its own
 * instance and device, so these tests exercise the instance and device creation paths in
 * VulkanResourceTrackingConsumer, with and without --remove-unsupported, against the mock ICD and assert the replay
 * completes successfully.
 */
TEST(Realign, ReplayTriangle)
{
    capture_and_replay("triangle", { "-m", "realign" });
}

TEST(Realign, ReplayTriangleRemoveUnsupported)
{
    capture_and_replay("triangle", { "-m", "realign", "--remove-unsupported" });
}
