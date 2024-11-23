#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "multisample-depth";

#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-multisample-depth.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-multisample-depth";
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "multisample-depth_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "multisample-depth.gfxr";
#endif

TEST(MultisampleDepth, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, KNOWN_GFXR_PATH);
}
