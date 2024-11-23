#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "triangle";

#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-triangle.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-triangle";
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "triangle_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "triangle.gfxr";
#endif

TEST(Triangle, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, KNOWN_GFXR_PATH);
}
