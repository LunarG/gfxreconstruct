#include <gtest/gtest.h>

#include "verify-gfxr.h"

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "multisample-depth_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "multisample-depth.gfxr";
#endif

TEST(MultisampleDepth, CorrectGFXR)
{
    verify_gfxr("multisample-depth", KNOWN_GFXR_PATH);
}
