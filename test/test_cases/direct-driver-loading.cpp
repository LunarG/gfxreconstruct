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

#include <cstdlib>
#include <filesystem>
#include <string>

namespace
{

const char kAppName[] = "direct-driver-loading";

// The mock ICD library that the test app hands to the loader. The run-tests script sets this variable.
std::string MockIcdPath()
{
    const char* path = std::getenv("GFXRECON_TESTAPP_MOCK_ICD");
    return (path != nullptr) ? path : "";
}

} // namespace

// The capture holds the SetDirectDriverInfoCommand block before vkCreateInstance.
TEST(DirectDriverLoading, CorrectGFXR)
{
    verify_gfxr(kAppName);
}

// A trimmed capture holds the same block, written by the state writer.
TEST(DirectDriverLoading, CorrectTrimmedGFXR)
{
    verify_gfxr(kAppName, "2");
}

// Replay loads the recorded driver library. The manifest path points at a missing file, so only the direct
// path can supply a driver, and the require policy stops the replay if that path fails.
TEST(DirectDriverLoading, ReplayLoadsRecordedDriver)
{
    CaptureReplayOptions options;
    options.replay_args = { "--direct-driver-policy", "require" };
    options.replay_env  = { { "VK_DRIVER_FILES", "no-such-manifest.json" } };
    capture_and_replay(kAppName, options);
}

// Capture with a copy of the mock ICD, delete the copy, and replay with the original path given as the
// replacement. The recorded path is gone, so only the replacement can make the require policy pass.
TEST(DirectDriverLoading, ReplayLoadsRemappedDriver)
{
    const std::string original = MockIcdPath();
    ASSERT_FALSE(original.empty()) << "GFXRECON_TESTAPP_MOCK_ICD is not set";

    const std::filesystem::path original_path(original);
    const std::filesystem::path copy_path =
        original_path.parent_path() / (std::string("gfxrecon_ddl_copy") + original_path.extension().string());
    std::filesystem::copy_file(original_path, copy_path, std::filesystem::copy_options::overwrite_existing);

    CaptureReplayOptions options;
    options.capture_env   = { { "GFXRECON_TESTAPP_MOCK_ICD", copy_path.string() } };
    options.before_replay = [copy_path]() { std::filesystem::remove(copy_path); };
    options.replay_args   = { "--direct-driver-lib", original, "--direct-driver-policy", "require" };
    options.replay_env    = { { "VK_DRIVER_FILES", "no-such-manifest.json" } };
    capture_and_replay(kAppName, options);

    std::filesystem::remove(copy_path);
}

// With the auto policy a driver that does not load makes replay remove the extension and use the manifest
// drivers instead.
TEST(DirectDriverLoading, ReplayFallsBackToManifestDrivers)
{
    CaptureReplayOptions options;
    options.replay_args = { "--direct-driver-lib", "no-such-driver-library", "--direct-driver-policy", "auto" };
    capture_and_replay(kAppName, options);
}

// With the require policy the same failure stops the replay.
TEST(DirectDriverLoading, ReplayStopsWhenRequiredDriverIsMissing)
{
    CaptureReplayOptions options;
    options.replay_args = { "--direct-driver-lib", "no-such-driver-library", "--direct-driver-policy", "require" };
    options.expect_replay_success = false;
    capture_and_replay(kAppName, options);
}

// The strip policy never loads the recorded driver and uses the manifest drivers.
TEST(DirectDriverLoading, ReplayStripsTheExtension)
{
    CaptureReplayOptions options;
    options.replay_args = { "--direct-driver-policy", "strip" };
    capture_and_replay(kAppName, options);
}
