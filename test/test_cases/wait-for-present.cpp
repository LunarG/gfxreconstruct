#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "wait-for-present";

#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-wait-for-present.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-wait-for-present";
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "wait-for-present_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "wait-for-present.gfxr";
#endif

char const* const TRIMMING_FRAMES = "2";

TEST(WaitForPresent, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, KNOWN_GFXR_PATH, TRIMMING_FRAMES);
}
