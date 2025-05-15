#include <gtest/gtest.h>

#include "verify-gfxr.h"

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "triangle_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "triangle.gfxr";
#endif

TEST(Triangle, CorrectGFXR)
{
    verify_gfxr("triangle", KNOWN_GFXR_PATH);
}
