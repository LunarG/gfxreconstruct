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
#include "decode/common_object_info_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "graphics/vulkan_submit_info_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "decode/block_parser.h"

#include <vector>

const VkBuffer                   kBufferHandles[] = { gfxrecon::format::FromHandleId<VkBuffer>(0xabcd),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xbcda),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xcdab),
                                                      gfxrecon::format::FromHandleId<VkBuffer>(0xdabc) };
const gfxrecon::format::HandleId kBufferIds[]     = { 12, 24, 48, 96 };
const gfxrecon::format::HandleId kDeviceId        = 6;

TEST_CASE("handle IDs need to be mapped to valid handles", "[wrapper]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    gfxrecon::decode::CommonObjectInfoTable info_table;

    // Basic add.
    gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
        kDeviceId,
        kBufferIds[0],
        kBufferHandles[0],
        &info_table,
        &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

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
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        // Array add with info and different ID/handle counts.
        gfxrecon::decode::handle_mapping::AddHandleArray<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            &kBufferIds[2],
            1,
            &kBufferHandles[2],
            2,
            std::vector<gfxrecon::decode::VulkanBufferInfo>(1),
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        // Add with info.
        gfxrecon::decode::handle_mapping::AddHandle<gfxrecon::decode::VulkanBufferInfo>(
            kDeviceId,
            kBufferIds[3],
            kBufferHandles[3],
            gfxrecon::decode::VulkanBufferInfo{},
            &info_table,
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

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
            &gfxrecon::decode::CommonObjectInfoTable::AddVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 1);
    }

    SECTION("Remove an entry from the object table")
    {
        gfxrecon::decode::handle_mapping::RemoveHandle(
            kBufferIds[0], &info_table, &gfxrecon::decode::CommonObjectInfoTable::RemoveVkBufferInfo);

        std::vector<const gfxrecon::decode::VulkanBufferInfo*> buffers;
        info_table.VisitVkBufferInfo(
            [&buffers](const gfxrecon::decode::VulkanBufferInfo* info) { buffers.push_back(info); });

        REQUIRE(buffers.size() == 0);
    }

    SECTION("Buffer ID 12 maps to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            kBufferIds[0], info_table, &gfxrecon::decode::CommonObjectInfoTable::GetVkBufferInfo);

        REQUIRE(buffer == kBufferHandles[0]);
    }

    SECTION("Invalid buffer ID 99 does not map to a valid buffer handle")
    {
        auto buffer = gfxrecon::decode::handle_mapping::MapHandle<gfxrecon::decode::VulkanBufferInfo>(
            99, info_table, &gfxrecon::decode::CommonObjectInfoTable::GetVkBufferInfo);

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

TEST_CASE("BlockParser basic usage", "[wrapper]")
{
    bool err_triggered = false;
    auto err_handler   = [&err_triggered](gfxrecon::decode::BlockIOError, const char*) { err_triggered = true; };

    gfxrecon::decode::BlockParser block_parser(err_handler, nullptr);

    // this should trigger some error
    block_parser.HandleBlockReadError(gfxrecon::decode::BlockIOError::kErrorReadingBlockData, "fatal fake error");
    REQUIRE(err_triggered);
}

TEST_CASE("SubmitInfo2Translator widens VkSubmitInfo into VkSubmitInfo2", "[]")
{
    // Handles are opaque here; fabricate distinct non-null values. They only need to compare equal.
    const VkSemaphore     wait_semaphores[2]   = { gfxrecon::format::FromHandleId<VkSemaphore>(0x11),
                                                   gfxrecon::format::FromHandleId<VkSemaphore>(0x12) };
    const VkSemaphore     signal_semaphores[1] = { gfxrecon::format::FromHandleId<VkSemaphore>(0x21) };
    const VkCommandBuffer command_buffers[1]   = { gfxrecon::format::FromHandleId<VkCommandBuffer>(0x31) };

    const VkPipelineStageFlags wait_stages[2] = { VK_PIPELINE_STAGE_VERTEX_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT };

    // Values carried by the three pNext structures that must be translated into VkSubmitInfo2 fields and removed from
    // the chain.
    const uint64_t wait_values[2]           = { 7, 8 };
    const uint64_t signal_values[1]         = { 42 };
    const uint32_t wait_device_indices[2]   = { 1, 0 };
    const uint32_t signal_device_indices[1] = { 1 };
    const uint32_t command_buffer_masks[1]  = { 0x2 };

    VkDeviceGroupSubmitInfo       device_group{ VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO,
                                          nullptr,
                                          2,
                                          wait_device_indices,
                                          1,
                                          command_buffer_masks,
                                          1,
                                          signal_device_indices };
    VkProtectedSubmitInfo         protected_info{ VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO, &device_group, VK_TRUE };
    VkTimelineSemaphoreSubmitInfo timeline{
        VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO, &protected_info, 2, wait_values, 1, signal_values
    };

    VkSubmitInfo info{};
    info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    info.pNext                = &timeline;
    info.waitSemaphoreCount   = 2;
    info.pWaitSemaphores      = wait_semaphores;
    info.pWaitDstStageMask    = wait_stages;
    info.commandBufferCount   = 1;
    info.pCommandBuffers      = command_buffers;
    info.signalSemaphoreCount = 1;
    info.pSignalSemaphores    = signal_semaphores;

    std::vector<VkSubmitInfo>                 infos_v1{ info };
    gfxrecon::graphics::SubmitInfo2Translator translator(infos_v1);
    const auto&                               infos_v2 = translator.GetSubmitInfos2();

    REQUIRE(infos_v1.size() == infos_v2.size());

    const VkSubmitInfo2& s = infos_v2[0];
    REQUIRE(s.sType == VK_STRUCTURE_TYPE_SUBMIT_INFO_2);

    // VkProtectedSubmitInfo::protectedSubmit becomes a submit flag.
    REQUIRE((s.flags & VK_SUBMIT_PROTECTED_BIT) != 0);

    // Wait semaphores carry the handle, the widened wait-stage mask, the timeline value and the device index.
    REQUIRE(s.waitSemaphoreInfoCount == 2);
    REQUIRE(s.pWaitSemaphoreInfos[0].semaphore == wait_semaphores[0]);
    REQUIRE(s.pWaitSemaphoreInfos[0].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[0]));
    REQUIRE(s.pWaitSemaphoreInfos[0].value == wait_values[0]);
    REQUIRE(s.pWaitSemaphoreInfos[0].deviceIndex == wait_device_indices[0]);
    REQUIRE(s.pWaitSemaphoreInfos[1].semaphore == wait_semaphores[1]);
    REQUIRE(s.pWaitSemaphoreInfos[1].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[1]));
    REQUIRE(s.pWaitSemaphoreInfos[1].value == wait_values[1]);
    REQUIRE(s.pWaitSemaphoreInfos[1].deviceIndex == wait_device_indices[1]);

    // Command buffers carry the handle and the device mask.
    REQUIRE(s.commandBufferInfoCount == 1);
    REQUIRE(s.pCommandBufferInfos[0].commandBuffer == command_buffers[0]);
    REQUIRE(s.pCommandBufferInfos[0].deviceMask == command_buffer_masks[0]);

    // Signal semaphores signal at ALL_COMMANDS and carry the timeline value and device index.
    REQUIRE(s.signalSemaphoreInfoCount == 1);
    REQUIRE(s.pSignalSemaphoreInfos[0].semaphore == signal_semaphores[0]);
    REQUIRE(s.pSignalSemaphoreInfos[0].stageMask == VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT);
    REQUIRE(s.pSignalSemaphoreInfos[0].value == signal_values[0]);
    REQUIRE(s.pSignalSemaphoreInfos[0].deviceIndex == signal_device_indices[0]);

    // All three translated structures must be stripped from the VkSubmitInfo2 pNext-chain.
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&s) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&s) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&s) == nullptr);
}
