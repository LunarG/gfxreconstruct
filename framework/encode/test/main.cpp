///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
//
// Licensed under the Apache License, Version 2.0(the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http: // www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
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
}
