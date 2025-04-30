#include <gtest/gtest.h>

#include "verify-gfxr.h"

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "shader-objects_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "shader-objects.gfxr";
#endif

TEST(ShaderObjects, CorrectGFXR)
{
    verify_gfxr("shader-objects", KNOWN_GFXR_PATH);
}
