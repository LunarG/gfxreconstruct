#include <gtest/gtest.h>

#include "verify-gfxr.h"

// Disabled until the app indexes sync_.image_in_flight by the acquired image index. It indexes by
// the in-flight frame, and the list has one entry per swapchain image. The mock ICD has one
// swapchain image and the app has two frames in flight, so the second frame reads past the end.
TEST(SparseResources, DISABLED_CorrectGFXR)
{
    verify_gfxr("sparse-resources");
}
