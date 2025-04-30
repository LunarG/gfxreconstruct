#include <gtest/gtest.h>

#include "verify-gfxr.h"

char const* const KNOWN_GFXR_PATH = "external-memory-fd.gfxr";

TEST(ExternalMemoryFD, CorrectGFXR)
{
    const char *actual_gfxr = strdup(getenv("GFXRECON_CAPTURE_FILE"));
    // setenv("GFXRECON_CAPTURE_FILE", "background.gfxr", 1);
    run_in_background("external-memory-fd-export");
    // setenv("GFXRECON_CAPTURE_FILE", actual_gfxr, 1);

    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr("external-memory-fd-import", KNOWN_GFXR_PATH);
}
