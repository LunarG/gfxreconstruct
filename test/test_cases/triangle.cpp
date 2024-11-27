#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "triangle";
#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-triangle.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-triangle";
#endif
char const* const CAPTURE_FILE      = "triangle.gfxr";
char const* const KNOWN_GFXR_PATH   = "triangle.gfxr";

TEST(Triangle, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, CAPTURE_FILE, KNOWN_GFXR_PATH);
}
