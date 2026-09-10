#include <gtest/gtest.h>

#include "verify-gfxr.h"

TEST(SparseResources, CorrectGFXR)
{
    verify_gfxr("sparse-resources");
}
