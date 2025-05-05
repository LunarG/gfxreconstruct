/*
** Copyright (c) 2025 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include <gtest/gtest.h>

#include "verify-gfxr.h"

#define TEST_APP_NAME "acquired-image"
#define TEST_APP_PREFIX "gfxrecon-testapp-"

char const* const APP_RUN_DIRECTORY = TEST_APP_NAME;

#ifdef WIN32
char const* const APP_PATH = TEST_APP_PREFIX TEST_APP_NAME ".exe";
#else
char const* const APP_PATH = TEST_APP_PREFIX TEST_APP_NAME;
#endif

#ifdef __APPLE__
char const* const KNOWN_GFXR_PATH = TEST_APP_NAME "_macos.gfxr";
#else
char const* const KNOWN_GFXR_PATH = TEST_APP_NAME ".gfxr";
#endif

TEST(AcquiredImage, CorrectGFXR)
{
    verify_gfxr(TEST_APP_NAME, KNOWN_GFXR_PATH);
}
