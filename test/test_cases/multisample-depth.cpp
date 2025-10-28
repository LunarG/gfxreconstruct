#include <gtest/gtest.h>

#include "verify-gfxr.h"

TEST(MultisampleDepth, CorrectGFXR)
{
    verify_gfxr("multisample-depth");
}
