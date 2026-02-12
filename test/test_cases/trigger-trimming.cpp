#include <gtest/gtest.h>
#include <stdio.h>

#include "verify-gfxr.h"

TEST(TriggerTrimming, CorrectGFXR)
{
    verify_gfxr("trigger-trimming", nullptr, true);
}
