#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "shader-objects";

#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-shader-objects.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-shader-objects";
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "shader-objects_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "shader-objects.gfxr";
#endif

TEST(ShaderObjects, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, KNOWN_GFXR_PATH);
}
