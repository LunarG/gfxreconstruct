#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "pipeline-binaries";

#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-pipeline-binaries.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-pipeline-binaries";
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH   = "pipeline-binaries_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH   = "pipeline-binaries.gfxr";
#endif

TEST(PipelineBinaries, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, KNOWN_GFXR_PATH);
}
