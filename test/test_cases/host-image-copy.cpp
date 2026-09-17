#include <gtest/gtest.h>

#include "verify-gfxr.h"

// Disabled until the mock ICD backs device memory and executes host image copies. The app copies a
// buffer into an image and back with VK_EXT_host_image_copy, then compares the bytes. The mock
// returns fresh memory from every vkMapMemory call and moves no bytes, so the app stops with
// "memory does not match" before it presents a frame.
TEST(HostImageCopy, DISABLED_CorrectGFXR)
{
    verify_gfxr("host-image-copy");
}
