#include <gtest/gtest.h>

#include "verify-gfxr.h"

TEST(SetEnvironment, CorrectGFXR)
{
    verify_gfxr("set-environment");
}
