#include <gtest/gtest.h>

#include "verify-gfxr.h"

// One test for each place where replay takes screenshots. Each compares the json that --screenshot-results writes
// with test/known_good/screenshots/<test app name>.json.

// vkQueuePresentKHR: the presented swapchain images.
TEST(ScreenshotResults, QueuePresent)
{
    capture_and_verify_screenshots("triangle", { "--screenshots", "1-2" });
}

// A submitted command buffer that carries the VR frame delimiter label: the attachments it rendered to.
TEST(ScreenshotResults, CommandBufferFrameBoundary)
{
    capture_and_verify_screenshots("screenshot-frame-boundary-command-buffer", { "--screenshot-all" });
}

// VkFrameBoundaryEXT in the pNext chain of vkQueueSubmit and vkQueueSubmit2: the images it lists.
TEST(ScreenshotResults, FrameBoundaryEXT)
{
    capture_and_verify_screenshots("screenshot-frame-boundary-ext", { "--screenshot-all" });
}

// vkFrameBoundaryANDROID: the image it names.
TEST(ScreenshotResults, FrameBoundaryANDROID)
{
    capture_and_verify_screenshots("screenshot-frame-boundary-android", { "--screenshot-all" });
}
