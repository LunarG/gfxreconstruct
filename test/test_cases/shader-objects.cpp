#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "shader-objects";
#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-shader-objects.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-shader-objects";
#endif
char const* const CAPTURE_FILE      = "shader-objects.gfxr";
char const* const KNOWN_GFXR_PATH   = "shader-objects.gfxr";

TEST(ShaderObjects, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, CAPTURE_FILE, KNOWN_GFXR_PATH);
}
