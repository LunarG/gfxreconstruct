#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const APP_RUN_DIRECTORY = "external-memory-fd";

#ifdef WIN32
char const* const EXPORT_APP_PATH = "gfxrecon-testapp-external-memory-fd-export.exe";
char const* const IMPORT_APP_PATH = "gfxrecon-testapp-external-memory-fd-import.exe";
#else
char const* const EXPORT_APP_PATH = "gfxrecon-testapp-external-memory-fd-export";
char const* const IMPORT_APP_PATH = "gfxrecon-testapp-external-memory-fd-import";
#endif

char const* const KNOWN_GFXR_PATH = "external-memory-fd.gfxr";

TEST(ExternalMemoryFD, CorrectGFXR)
{
    run_in_background(APP_RUN_DIRECTORY, EXPORT_APP_PATH);
    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr(APP_RUN_DIRECTORY, IMPORT_APP_PATH, KNOWN_GFXR_PATH);
}
