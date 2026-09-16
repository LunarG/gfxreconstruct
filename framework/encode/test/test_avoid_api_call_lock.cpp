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

#include <thread>

namespace
{

using gfxrecon::encode::CommonCaptureManager;
using gfxrecon::encode::ScopedCounter;

// CommonCaptureManager has a protected destructor. The tests need a type that they can
// construct on the stack.
class TestCaptureManager : public CommonCaptureManager
{
  public:
    TestCaptureManager()  = default;
    ~TestCaptureManager() = default;
};

} // namespace

TEST_CASE("avoid API call lock - nested calls on the current thread take no lock", "[capture_manager]")
{
    TestCaptureManager manager;

    REQUIRE(CommonCaptureManager::AcquireSharedApiCallLock().owns_lock());
    REQUIRE(CommonCaptureManager::AcquireExclusiveApiCallLock().owns_lock());
    REQUIRE(manager.AcquireCallLock().IsShared());

    {
        ScopedCounter nested_call(manager.AvoidApiCallLock());

        REQUIRE_FALSE(CommonCaptureManager::AcquireSharedApiCallLock().owns_lock());
        REQUIRE_FALSE(CommonCaptureManager::AcquireExclusiveApiCallLock().owns_lock());
        REQUIRE_FALSE(manager.AcquireCallLock().IsShared());
    }

    REQUIRE(CommonCaptureManager::AcquireSharedApiCallLock().owns_lock());
    REQUIRE(CommonCaptureManager::AcquireExclusiveApiCallLock().owns_lock());
    REQUIRE(manager.AcquireCallLock().IsShared());
}

TEST_CASE("avoid API call lock - a nested call on one thread keeps the lock on other threads", "[capture_manager]")
{
    TestCaptureManager manager;

    ScopedCounter nested_call(manager.AvoidApiCallLock());
    REQUIRE_FALSE(CommonCaptureManager::AcquireSharedApiCallLock().owns_lock());

    bool        other_thread_owns_shared_lock    = false;
    bool        other_thread_owns_exclusive_lock = false;
    std::thread other([&]() {
        other_thread_owns_shared_lock    = CommonCaptureManager::AcquireSharedApiCallLock().owns_lock();
        other_thread_owns_exclusive_lock = CommonCaptureManager::AcquireExclusiveApiCallLock().owns_lock();
    });
    other.join();

    REQUIRE(other_thread_owns_shared_lock);
    REQUIRE(other_thread_owns_exclusive_lock);
}
