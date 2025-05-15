#include <gtest/gtest.h>

#include "verify-gfxr.h"

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "wait-for-present_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "wait-for-present.gfxr";
#endif

char const* const TRIMMING_FRAMES = "2";

TEST(WaitForPresent, CorrectGFXR)
{
    verify_gfxr("wait-for-present", KNOWN_GFXR_PATH, TRIMMING_FRAMES);
}
