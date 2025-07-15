#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const TRIMMING_FRAMES = "2";

TEST(WaitForPresent, CorrectGFXR)
{
    verify_gfxr("wait-for-present", TRIMMING_FRAMES);
}
