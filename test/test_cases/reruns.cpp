/*
** Copyright (c) 2026 LunarG, Inc.
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

#include <string>

// Two reruns of the capture apps along a second axis each. They reach code that the plain
// run does not: the passive path of every layer entry point when capture is off, and the
// lock in every layer entry point when command serialization is on.

// Apps with a known-good capture. The serialized rerun compares against it.
static const char* const kCaptureApps[] = {
    "acquired-image",        "ahb",
    "debug-utils",           "deep-pnext-chain",
    "multisample-depth",     "pipeline-binaries",
    "set-environment",       "shader-objects",
    "sparse-resources",      "triangle",
    "triangle-extra-device",
#if defined(__linux__)
    "trigger-trimming",      "wait-for-present",
#endif
};

// Apps with no known-good capture. Only the capture-disabled rerun applies.
static const char* const kReplayOnlyApps[] = {
    "isolate-render-passes",
    "serialize-compute-and-transfer",
};

// gtest needs a name that is a C identifier.
static std::string TestName(const testing::TestParamInfo<const char*>& info)
{
    std::string name = info.param;
    for (char& c : name)
    {
        if (c == '-')
        {
            c = '_';
        }
    }
    return name;
}

class CaptureDisabled : public testing::TestWithParam<const char*>
{};

TEST_P(CaptureDisabled, ProducesNoFile)
{
    verify_no_capture(GetParam());
}

INSTANTIATE_TEST_SUITE_P(CaptureApps, CaptureDisabled, testing::ValuesIn(kCaptureApps), TestName);
INSTANTIATE_TEST_SUITE_P(ReplayOnlyApps, CaptureDisabled, testing::ValuesIn(kReplayOnlyApps), TestName);

class Serialized : public testing::TestWithParam<const char*>
{};

TEST_P(Serialized, CorrectGFXR)
{
    verify_gfxr_serialized(GetParam());
}

INSTANTIATE_TEST_SUITE_P(CaptureApps, Serialized, testing::ValuesIn(kCaptureApps), TestName);
