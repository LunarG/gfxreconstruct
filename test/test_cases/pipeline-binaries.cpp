#include <gtest/gtest.h>

#include "verify-gfxr.h"

TEST(PipelineBinaries, CorrectGFXR)
{
    verify_gfxr("pipeline-binaries");
}
