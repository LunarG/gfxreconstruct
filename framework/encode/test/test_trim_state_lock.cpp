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
#include "format/format.h"

#include <thread>
#include <vector>

namespace
{

using gfxrecon::encode::CommonCaptureManager;

// CommonCaptureManager has a protected destructor. The tests need a type that they can
// construct on the stack. The constructor leaves trimming disabled.
class TestCaptureManager : public CommonCaptureManager
{
  public:
    TestCaptureManager()  = default;
    ~TestCaptureManager() = default;
};

} // namespace

TEST_CASE("trim state lock - releases the shared lock of the caller and takes it again", "[capture_manager]")
{
    TestCaptureManager manager;

    auto shared_lock = CommonCaptureManager::AcquireSharedApiCallLock();
    REQUIRE(shared_lock.owns_lock());

    {
        CommonCaptureManager::ScopedTrimStateLock trim_state_lock(manager, shared_lock);
        REQUIRE_FALSE(shared_lock.owns_lock());
    }

    REQUIRE(shared_lock.owns_lock());
}

TEST_CASE("trim state lock - leaves a lock that the caller does not own alone", "[capture_manager]")
{
    TestCaptureManager manager;

    CommonCaptureManager::ApiSharedLockT empty_lock;
    REQUIRE_FALSE(empty_lock.owns_lock());

    {
        CommonCaptureManager::ScopedTrimStateLock trim_state_lock(manager, empty_lock);
        REQUIRE_FALSE(empty_lock.owns_lock());
    }

    REQUIRE_FALSE(empty_lock.owns_lock());
}

TEST_CASE("queue submit count - concurrent submits from several threads are all counted", "[capture_manager]")
{
    TestCaptureManager manager;

    constexpr uint32_t kThreadCount      = 4;
    constexpr uint32_t kSubmitsPerThread = 2000;

    REQUIRE(manager.GetQueueSubmitCount() == 0);

    std::vector<std::thread> threads;
    for (uint32_t i = 0; i < kThreadCount; ++i)
    {
        threads.emplace_back([&manager]() {
            for (uint32_t submit = 0; submit < kSubmitsPerThread; ++submit)
            {
                auto shared_lock = CommonCaptureManager::AcquireSharedApiCallLock();
                manager.PreQueueSubmit(gfxrecon::format::ApiFamilyId::ApiFamily_Vulkan, shared_lock);
                manager.PostQueueSubmit(gfxrecon::format::ApiFamilyId::ApiFamily_Vulkan, shared_lock);
            }
        });
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    REQUIRE(manager.GetQueueSubmitCount() == (kThreadCount * kSubmitsPerThread));
}
