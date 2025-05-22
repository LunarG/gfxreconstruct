#include <gtest/gtest.h>

#include "verify-gfxr.h"

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "pipeline-binaries_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "pipeline-binaries.gfxr";
#endif

TEST(PipelineBinaries, CorrectGFXR)
{
    verify_gfxr("pipeline-binaries", KNOWN_GFXR_PATH);
}
