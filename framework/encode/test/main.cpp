///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \author AMD Developer Tools Team
/// \description gfxrecon_encode test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "format/format.h"
#include "format/format_util.h"

#include "vulkan/vulkan.h"

const auto                       kBufferHandle = gfxrecon::format::FromHandleId<VkBuffer>(0xabcd);
const gfxrecon::format::HandleId kBufferId     = 12;

gfxrecon::format::HandleId GetHandleId()
{
    return kBufferId;
}

TEST_CASE("handles can be wrapped and unwrapped", "[wrapper]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);

    VkBuffer buffer = kBufferHandle;
    gfxrecon::encode::CreateWrappedHandle<gfxrecon::encode::DeviceWrapper,
                                          gfxrecon::encode::NoParentWrapper,
                                          gfxrecon::encode::BufferWrapper>(
        VK_NULL_HANDLE, gfxrecon::encode::NoParentWrapper::kHandleValue, &buffer, GetHandleId);

    SECTION("The handle now references the wrapper instead of the buffer") { REQUIRE(buffer != kBufferHandle); }

    SECTION("The handle retrieved from the wrapper is the original buffer handle")
    {
        REQUIRE(gfxrecon::encode::GetWrappedHandle(buffer) == kBufferHandle);
    }

    SECTION("The handle ID retrieved from the wrapper is 12")
    {
        REQUIRE(gfxrecon::encode::GetWrappedId(buffer) == kBufferId);
    }

    SECTION("The handle retrieved from an integer handle with type VK_OBJECT_TYPE_BUFFER is the original buffer handle")
    {
        uint64_t object = gfxrecon::format::ToHandleId(buffer);

        REQUIRE(gfxrecon::encode::GetWrappedHandle(object, VK_OBJECT_TYPE_BUFFER) ==
                gfxrecon::format::ToHandleId(kBufferHandle));
    }

    SECTION("The handle ID retrieved from an integer handle with type VK_OBJECT_TYPE_BUFFER is 12")
    {
        uint64_t object = gfxrecon::format::ToHandleId(buffer);

        REQUIRE(gfxrecon::encode::GetWrappedId(object, VK_OBJECT_TYPE_BUFFER) == 12);
    }

    gfxrecon::encode::DestroyWrappedHandle<gfxrecon::encode::BufferWrapper>(buffer);

    gfxrecon::util::Log::Release();
}
