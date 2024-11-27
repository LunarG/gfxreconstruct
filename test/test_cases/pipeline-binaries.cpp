#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "pipeline-binaries";
#ifdef WIN32
char const* const APP_PATH          = "gfxrecon-testapp-pipeline-binaries.exe";
#else
char const* const APP_PATH          = "gfxrecon-testapp-pipeline-binaries";
#endif
char const* const CAPTURE_FILE      = "pipeline-binaries.gfxr";
char const* const KNOWN_GFXR_PATH   = "pipeline-binaries.gfxr";

TEST(PipelineBinaries, CorrectGFXR)
{
    verify_gfxr(APP_RUN_DIRECTORY, APP_PATH, CAPTURE_FILE, KNOWN_GFXR_PATH);
}
