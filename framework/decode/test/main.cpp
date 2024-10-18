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
/// \description gfxrecon_decode test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "format/format_util.h"

#include "vulkan/vulkan.h"

#include <vector>

const VkBuffer                   kBufferHandles[] = { gfxrecon::format::FromHandleId<VkBuffer>(0xabcd),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xbcda),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xcdab),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xdabc) };
const gfxrecon::format::HandleId kBufferIds[]     = { 12, 24, 48, 96 };
const gfxrecon::format::HandleId kDeviceId        = 6;

TEST_CASE("handle IDs need to be mapped to valid handles", "[wrapper]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);

    gfxrecon::decode::VulkanObjectInfoTable info_table;

    // Basic add.
    gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
        kDeviceId,
        kBufferIds[0],
        kBufferHandles[0],
        &info_table,
        &gfxrecon::decode::VulkanObjectInfoTable::AddVkBufferInfo);

    SECTION("Add a total of four entries to the object table")
    {
        // Basic array add.
        gfxrecon::decode::handle_mapping::AddHandleArray<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            &kBufferIds[1],
            1,
            &kBufferHandles[1],
            1,
            &info_table,
            &gfxrecon::decode::VulkanObjectInfoTable::AddVkBufferInfo);

        // Array add with info and different ID/handle counts.
        gfxrecon::decode::handle_mapping::AddHandleArray<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            &kBufferIds[2],
            1,
            &kBufferHandles[2],
            2,
            std::vector<gfxrecon::decode::VulkanBufferInfo>(1),
            &info_table,
            &gfxrecon::decode::VulkanObjectInfoTable::AddVkBufferInfo);

        // Add with info.
        gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            kBufferIds[3],
            kBufferHandles[3],
            gfxrecon::decode::VulkanBufferInfo{},
            &info_table,
            &gfxrecon::decode::VulkanObjectInfoTable::AddVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 4);
    }

    SECTION("Add a duplicate entry to the object table, which is ignored")
    {
        gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            kBufferIds[0],
            kBufferHandles[0],
            &info_table,
            &gfxrecon::decode::VulkanObjectInfoTable::AddVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 1);
    }

    SECTION("Remove an entry from the object table")
    {
        gfxrecon::decode::handle_mapping::RemoveHandle(
            kBufferIds[0], &info_table, &gfxrecon::decode::VulkanObjectInfoTable::RemoveVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 0);
    }

    SECTION("Buffer ID 12 maps to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            kBufferIds[0], info_table, &gfxrecon::decode::VulkanObjectInfoTable::GetVkBufferInfo);

        REQUIRE(buffer == kBufferHandles[0]);
    }

    SECTION("Invalid buffer ID 99 does not map to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            99, info_table, &gfxrecon::decode::VulkanObjectInfoTable::GetVkBufferInfo);

        REQUIRE(buffer == VK_NULL_HANDLE);
    }

    SECTION("An integer ID with value 12 and type VK_OBJECT_TYPE_BUFFER maps to a valid buffer handle represented as "
            "an integer")
    {
        auto object = gfxrecon::decode::handle_mapping::MapHandle(kBufferIds[0], VK_OBJECT_TYPE_BUFFER, info_table);

        REQUIRE(object == gfxrecon::format::ToHandleId(kBufferHandles[0]));
    }

    gfxrecon::util::Log::Release();
}
