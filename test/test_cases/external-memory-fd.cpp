#include <gtest/gtest.h>

#include "verify-gfxr.h"


char const* const KNOWN_GFXR_PATH = "external-memory-fd-import.gfxr";

TEST(ExternalMemoryFD, CorrectGFXR)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr("external-memory-fd-import", KNOWN_GFXR_PATH);
}
