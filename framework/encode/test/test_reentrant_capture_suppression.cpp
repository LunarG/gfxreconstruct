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

#include <catch2/catch.hpp>

#include "encode/capture_manager.h"
#include "format/api_call_id.h"

#include <atomic>
#include <thread>

namespace
{

using gfxrecon::encode::CommonCaptureManager;
using gfxrecon::encode::ParameterEncoder;
using gfxrecon::format::ApiCallId;

// CommonCaptureManager has a protected destructor. The tests need a type that they can
// construct on the stack. The constructor sets the capture mode to write.
class TestCaptureManager : public CommonCaptureManager
{
  public:
    TestCaptureManager()  = default;
    ~TestCaptureManager() = default;
};

constexpr ApiCallId                  kCallId   = ApiCallId::ApiCall_vkQueueSubmit;
constexpr gfxrecon::format::HandleId kObjectId = 1;

// Returns true when every Begin*CallCapture function returns an encoder.
bool CaptureIsActive(TestCaptureManager& manager)
{
    return (manager.BeginApiCallCapture(kCallId) != nullptr) &&
           (manager.BeginTrackedApiCallCapture(kCallId) != nullptr) &&
           (manager.BeginMethodCallCapture(kCallId, kObjectId) != nullptr) &&
           (manager.BeginTrackedMethodCallCapture(kCallId, kObjectId) != nullptr);
}

// Returns true when every Begin*CallCapture function returns null.
bool CaptureIsSuppressed(TestCaptureManager& manager)
{
    return (manager.BeginApiCallCapture(kCallId) == nullptr) &&
           (manager.BeginTrackedApiCallCapture(kCallId) == nullptr) &&
           (manager.BeginMethodCallCapture(kCallId, kObjectId) == nullptr) &&
           (manager.BeginTrackedMethodCallCapture(kCallId, kObjectId) == nullptr);
}

} // namespace

TEST_CASE("reentrant capture suppression - scope is active only inside its block", "[capture_manager]")
{
    REQUIRE_FALSE(CommonCaptureManager::IsReentrantCaptureSuppressed());

    {
        CommonCaptureManager::ScopedReentrantCaptureSuppression suppress;
        REQUIRE(CommonCaptureManager::IsReentrantCaptureSuppressed());
    }

    REQUIRE_FALSE(CommonCaptureManager::IsReentrantCaptureSuppressed());
}

TEST_CASE("reentrant capture suppression - nested scopes keep the suppression until the outer scope ends",
          "[capture_manager]")
{
    {
        CommonCaptureManager::ScopedReentrantCaptureSuppression outer;
        {
            CommonCaptureManager::ScopedReentrantCaptureSuppression inner;
            REQUIRE(CommonCaptureManager::IsReentrantCaptureSuppressed());
        }
        REQUIRE(CommonCaptureManager::IsReentrantCaptureSuppressed());
    }

    REQUIRE_FALSE(CommonCaptureManager::IsReentrantCaptureSuppressed());
}

TEST_CASE("reentrant capture suppression - scope does not change other threads", "[capture_manager]")
{
    CommonCaptureManager::ScopedReentrantCaptureSuppression suppress;
    REQUIRE(CommonCaptureManager::IsReentrantCaptureSuppressed());

    bool        other_thread_suppressed = true;
    std::thread other([&other_thread_suppressed]() {
        other_thread_suppressed = CommonCaptureManager::IsReentrantCaptureSuppressed();
    });
    other.join();

    REQUIRE_FALSE(other_thread_suppressed);
}

TEST_CASE("reentrant capture suppression - Begin*CallCapture return null inside the scope", "[capture_manager]")
{
    TestCaptureManager manager;

    REQUIRE(CaptureIsActive(manager));

    {
        CommonCaptureManager::ScopedReentrantCaptureSuppression suppress;
        REQUIRE(CaptureIsSuppressed(manager));
    }

    REQUIRE(CaptureIsActive(manager));
}

TEST_CASE("reentrant capture suppression - scope on one thread does not stop capture on another thread",
          "[capture_manager]")
{
    TestCaptureManager manager;

    std::atomic<bool> runtime_thread_in_scope{ false };
    std::atomic<bool> app_thread_done{ false };

    // This thread stands in for the thread that is inside a call into the OpenXR runtime.
    std::thread runtime_thread([&]() {
        CommonCaptureManager::ScopedReentrantCaptureSuppression suppress;
        runtime_thread_in_scope = true;
        while (!app_thread_done)
        {
            std::this_thread::yield();
        }
    });

    while (!runtime_thread_in_scope)
    {
        std::this_thread::yield();
    }

    // This thread stands in for an application thread that records its own API calls.
    bool        app_capture_active = false;
    std::thread app_thread([&]() {
        app_capture_active = CaptureIsActive(manager);
        app_thread_done    = true;
    });

    app_thread.join();
    runtime_thread.join();

    REQUIRE(app_capture_active);
    REQUIRE_FALSE(CommonCaptureManager::IsReentrantCaptureSuppressed());
}
