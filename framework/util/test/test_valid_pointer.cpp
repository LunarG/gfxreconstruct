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

#include <catch2/catch.hpp>
#include "util/platform.h"

using namespace gfxrecon::util::platform;

TEST_CASE("valid_pointer - stack", "[]")
{
    int   ans = 42;
    void* p   = &ans;
    REQUIRE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - null", "[]")
{
    void* p = nullptr;
    REQUIRE_FALSE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - invalid", "[]")
{
    // This is an address that is very likely to be invalid in any process.
    void* p = reinterpret_cast<void*>(0x123);
    REQUIRE_FALSE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - heap", "[]")
{
    int* p = new int(42);
    REQUIRE(PointerIsValid(p));
    delete p;
}

namespace
{

// Two consecutive pages, mapped readable; the second can be released or made its own region.
class TwoPages
{
  public:
    TwoPages() : page_size_(GetSystemPageSize())
    {
#if defined(_WIN32)
        base_ = static_cast<uint8_t*>(VirtualAlloc(nullptr, 2 * page_size_, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
#else
        base_ = static_cast<uint8_t*>(
            mmap(nullptr, 2 * page_size_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
        if (base_ == MAP_FAILED)
        {
            base_ = nullptr;
        }
#endif
    }

    ~TwoPages()
    {
        if (base_ == nullptr)
        {
            return;
        }
#if defined(_WIN32)
        VirtualFree(base_, 0, MEM_RELEASE);
#else
        munmap(base_, second_released_ ? page_size_ : 2 * page_size_);
#endif
    }

    bool Mapped() const
    {
        return base_ != nullptr;
    }
    const uint8_t* Boundary() const
    {
        return base_ + page_size_;
    }

    // The second page stops being readable: decommitted on Windows, unmapped on POSIX.
    void ReleaseSecond()
    {
#if defined(_WIN32)
        VirtualFree(base_ + page_size_, page_size_, MEM_DECOMMIT);
#else
        munmap(base_ + page_size_, page_size_);
#endif
        second_released_ = true;
    }

    // The second page stays readable as a region of its own: a different protection on Windows; every page is its
    // own region on POSIX already.
    void SplitSecond()
    {
#if defined(_WIN32)
        DWORD old_protect = 0;
        VirtualProtect(base_ + page_size_, page_size_, PAGE_READONLY, &old_protect);
#else
        mprotect(base_ + page_size_, page_size_, PROT_READ);
#endif
    }

  private:
    size_t   page_size_;
    uint8_t* base_            = nullptr;
    bool     second_released_ = false;
};

} // namespace

TEST_CASE("valid_pointer - span within a page", "[]")
{
    int arr[4] = { 1, 2, 3, 4 };
    REQUIRE(PointerIsValid(arr, sizeof(arr)));
}

TEST_CASE("valid_pointer - span off the end of readable memory", "[]")
{
    TwoPages pages;
    REQUIRE(pages.Mapped());
    pages.ReleaseSecond();

    // Nothing stops the allocator from reusing the released page before the probe; report that rather than fail.
    if (ReadableRegion(pages.Boundary()).IsValid())
    {
        WARN("The released page was remapped before the probe; the span case was not exercised.");
        return;
    }

    const uint8_t* near_end = pages.Boundary() - 8;
    CHECK(PointerIsValid(near_end, 8));
    CHECK_FALSE(PointerIsValid(near_end, 16));
}

TEST_CASE("valid_pointer - span straddling two readable regions", "[]")
{
    TwoPages pages;
    REQUIRE(pages.Mapped());
    pages.SplitSecond();

    const uint8_t* near_end = pages.Boundary() - 8;
    REQUIRE(PointerIsValid(near_end, 16));
}

TEST_CASE("valid_pointer - size zero reads as one", "[]")
{
    int ans = 42;
    REQUIRE(PointerIsValid(&ans, 0) == PointerIsValid(&ans));
}

TEST_CASE("valid_pointer - null with a size", "[]")
{
    REQUIRE_FALSE(PointerIsValid(nullptr, 16));
}

TEST_CASE("valid_pointer - ReadableRegion", "[]")
{
    REQUIRE_FALSE(ReadableRegion(nullptr).IsValid());

    int            ans = 42;
    ReadableRegion region(&ans);
    REQUIRE(region.IsValid());
    REQUIRE(region.Contains(&ans));

    TwoPages pages;
    REQUIRE(pages.Mapped());
    pages.ReleaseSecond();
    if (ReadableRegion(pages.Boundary()).IsValid())
    {
        WARN("The released page was remapped before the probe; the advance-off-the-end case was not exercised.");
        return;
    }
    ReadableRegion first(pages.Boundary() - 1);
    REQUIRE(first.IsValid());
    ++first;
    REQUIRE_FALSE(first.IsValid());
}
