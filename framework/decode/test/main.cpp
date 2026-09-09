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

#include "decode/referenced_resource_table.h"
#include "decode/screenshot_controller.h"
#include "decode/vulkan_screenshot_handler.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/common_object_info_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "graphics/vulkan_submit_info_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "decode/block_parser.h"

#include <limits>
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

TEST_CASE("Test a roundtrip between SubmitInfo2Translator and SubmitInfoTranslator", "[]")
{
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

    const VkDeviceGroupSubmitInfo device_group{ VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO,
                                                nullptr,
                                                2,
                                                wait_device_indices,
                                                1,
                                                command_buffer_masks,
                                                1,
                                                signal_device_indices };
    const VkProtectedSubmitInfo   protected_info{ VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO, &device_group, VK_TRUE };
    const VkTimelineSemaphoreSubmitInfo timeline{
        VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO, &protected_info, 2, wait_values, 1, signal_values
    };

    const VkSubmitInfo submit_info{ VK_STRUCTURE_TYPE_SUBMIT_INFO,
                                    &timeline,
                                    2,
                                    wait_semaphores,
                                    wait_stages,
                                    1,
                                    command_buffers,
                                    1,
                                    signal_semaphores };

    const std::vector<VkSubmitInfo>                 infos_v1{ submit_info };
    const gfxrecon::graphics::SubmitInfo2Translator v1_to_v2_translator(infos_v1);
    const auto&                                     infos_v2 = v1_to_v2_translator.GetSubmitInfos2();

    REQUIRE(infos_v1.size() == infos_v2.size());

    const VkSubmitInfo2& submit_info2 = infos_v2[0];
    REQUIRE(submit_info2.sType == VK_STRUCTURE_TYPE_SUBMIT_INFO_2);

    // Verify protected submission flag
    REQUIRE((submit_info2.flags & VK_SUBMIT_PROTECTED_BIT) != 0);

    // Verify Wait semaphores
    REQUIRE(submit_info2.waitSemaphoreInfoCount == 2);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].semaphore == wait_semaphores[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[0]));
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].value == wait_values[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[0].deviceIndex == wait_device_indices[0]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].semaphore == wait_semaphores[1]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].stageMask == static_cast<VkPipelineStageFlags2>(wait_stages[1]));
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].value == wait_values[1]);
    REQUIRE(submit_info2.pWaitSemaphoreInfos[1].deviceIndex == wait_device_indices[1]);

    // Verify command buffers
    REQUIRE(submit_info2.commandBufferInfoCount == 1);
    REQUIRE(submit_info2.pCommandBufferInfos[0].commandBuffer == command_buffers[0]);
    REQUIRE(submit_info2.pCommandBufferInfos[0].deviceMask == command_buffer_masks[0]);

    // Signal semaphores signal at ALL_COMMANDS and carry the timeline value and device index.
    REQUIRE(submit_info2.signalSemaphoreInfoCount == 1);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].semaphore == signal_semaphores[0]);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].stageMask == VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].value == signal_values[0]);
    REQUIRE(submit_info2.pSignalSemaphoreInfos[0].deviceIndex == signal_device_indices[0]);

    // All three translated structures must be stripped from the VkSubmitInfo2 pNext-chain.
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&submit_info2) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&submit_info2) == nullptr);
    REQUIRE(gfxrecon::graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&submit_info2) == nullptr);

    // Round-trip: narrow the VkSubmitInfo2 back into a VkSubmitInfo. The result must be equivalent to the original
    // VkSubmitInfo, with the timeline/device-group/protected information reconstructed into pNext structures.
    const gfxrecon::graphics::SubmitInfoTranslator v2_to_v1_translator(infos_v2);
    const auto&                                    infos_v1_roundtrip = v2_to_v1_translator.GetSubmitInfos();

    REQUIRE(infos_v1_roundtrip.size() == infos_v2.size());

    const VkSubmitInfo& r = infos_v1_roundtrip[0];
    REQUIRE(r.sType == VK_STRUCTURE_TYPE_SUBMIT_INFO);

    // Verify wait semaphores
    REQUIRE(r.waitSemaphoreCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r.pWaitSemaphores[i] == submit_info.pWaitSemaphores[i]);
        REQUIRE(r.pWaitDstStageMask[i] == submit_info.pWaitDstStageMask[i]);
    }

    REQUIRE(r.commandBufferCount == submit_info.commandBufferCount);
    for (uint32_t i = 0; i < submit_info.commandBufferCount; ++i)
    {
        REQUIRE(r.pCommandBuffers[i] == submit_info.pCommandBuffers[i]);
    }

    REQUIRE(r.signalSemaphoreCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r.pSignalSemaphores[i] == submit_info.pSignalSemaphores[i]);
    }

    // Verify that the protected flag has turned into a VkProtectedSubmitInfo.
    const auto* r_protected = gfxrecon::graphics::vulkan_struct_get_pnext<VkProtectedSubmitInfo>(&r);
    REQUIRE(r_protected != nullptr);
    REQUIRE(r_protected->protectedSubmit == protected_info.protectedSubmit);

    // Verify that the timeline values have turned into a VkTimelineSemaphoreSubmitInfo.
    const auto* r_timeline = gfxrecon::graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(&r);
    REQUIRE(r_timeline != nullptr);
    REQUIRE(r_timeline->waitSemaphoreValueCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r_timeline->pWaitSemaphoreValues[i] == wait_values[i]);
    }
    REQUIRE(r_timeline->signalSemaphoreValueCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r_timeline->pSignalSemaphoreValues[i] == signal_values[i]);
    }

    // Verify that the device-group indices/masks have turned into a VkDeviceGroupSubmitInfo.
    const auto* r_device_group = gfxrecon::graphics::vulkan_struct_get_pnext<VkDeviceGroupSubmitInfo>(&r);
    REQUIRE(r_device_group != nullptr);
    REQUIRE(r_device_group->waitSemaphoreCount == submit_info.waitSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; ++i)
    {
        REQUIRE(r_device_group->pWaitSemaphoreDeviceIndices[i] == wait_device_indices[i]);
    }
    REQUIRE(r_device_group->commandBufferCount == submit_info.commandBufferCount);
    for (uint32_t i = 0; i < submit_info.commandBufferCount; ++i)
    {
        REQUIRE(r_device_group->pCommandBufferDeviceMasks[i] == command_buffer_masks[i]);
    }
    REQUIRE(r_device_group->signalSemaphoreCount == submit_info.signalSemaphoreCount);
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; ++i)
    {
        REQUIRE(r_device_group->pSignalSemaphoreDeviceIndices[i] == signal_device_indices[i]);
    }
}

TEST_CASE("ReferencedResourceTable classifies destroyed command buffers", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool     = 1;
    constexpr HandleId kCmd      = 2;
    constexpr HandleId kPipeline = 3;

    ReferencedResourceTable table;
    table.AddResource(kPipeline);
    table.AddUser(kPool, kCmd);
    table.AddResourceToUser(kCmd, kPipeline);

    std::unordered_set<HandleId> unreferenced;

    SECTION("recorded, never submitted, then freed: user and resource are both unreferenced")
    {
        // The recorded blocks of a destroyed command buffer stay in the capture file, so the user must still be
        // classified as unreferenced for those blocks to be removed together with the pipeline creation call.
        table.RemoveUser(kCmd); // vkFreeCommandBuffers

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 1);
        REQUIRE(unreferenced.count(kPipeline) == 1);
    }

    SECTION("recorded, never submitted, then pool destroyed: user and resource are both unreferenced")
    {
        table.ClearUsers(kPool); // vkDestroyCommandPool

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 1);
        REQUIRE(unreferenced.count(kPipeline) == 1);
    }

    SECTION("submitted and then freed: user and resource are both referenced")
    {
        table.ProcessUserSubmission(kCmd);
        table.RemoveUser(kCmd);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kCmd) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }
}

TEST_CASE("ReferencedResourceTable marks resources recorded into a previously submitted user", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool      = 1;
    constexpr HandleId kCmd       = 2;
    constexpr HandleId kPipeline1 = 3;
    constexpr HandleId kPipeline2 = 4;

    ReferencedResourceTable table;
    table.AddUser(kPool, kCmd);
    table.AddResource(kPipeline1);
    table.AddResourceToUser(kCmd, kPipeline1);
    table.ProcessUserSubmission(kCmd);

    // Re-record the command buffer with a new pipeline, without a following submission (e.g. the capture ended
    // between recording and submission).  All blocks of the submitted command buffer stay in the capture file,
    // including the new recording, so the new pipeline must be classified as referenced.
    table.ResetUser(kCmd); // vkBeginCommandBuffer
    table.AddResource(kPipeline2);
    table.AddResourceToUser(kCmd, kPipeline2);

    std::unordered_set<HandleId> unreferenced;
    table.GetReferencedHandleIds(nullptr, &unreferenced);
    REQUIRE(unreferenced.count(kPipeline1) == 0);
    REQUIRE(unreferenced.count(kPipeline2) == 0);
}

TEST_CASE("ReferencedResourceTable processes executed secondary command buffers", "[optimize]")
{
    using gfxrecon::decode::ReferencedResourceTable;
    using gfxrecon::format::HandleId;

    constexpr HandleId kPool      = 1;
    constexpr HandleId kPrimary   = 2;
    constexpr HandleId kSecondary = 3;
    constexpr HandleId kNested    = 4;
    constexpr HandleId kPipeline  = 5;

    ReferencedResourceTable table;
    table.AddUser(kPool, kPrimary);
    table.AddUser(kPool, kSecondary);

    std::unordered_set<HandleId> unreferenced;

    SECTION("nested secondaries of a submitted primary are marked recursively")
    {
        table.AddUser(kPool, kNested);
        table.AddResource(kPipeline);
        table.AddResourceToUser(kNested, kPipeline);
        table.AddUserToUser(kSecondary, kNested);  // vkCmdExecuteCommands in the secondary
        table.AddUserToUser(kPrimary, kSecondary); // vkCmdExecuteCommands in the primary
        table.ProcessUserSubmission(kPrimary);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kSecondary) == 0);
        REQUIRE(unreferenced.count(kNested) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }

    SECTION("execute-commands recorded into an already submitted primary marks the secondary")
    {
        table.ProcessUserSubmission(kPrimary);

        // Trailing recording without a following submission: the primary's blocks all stay in the capture file,
        // so the executed secondary and its resources must be classified as referenced.
        table.AddResource(kPipeline);
        table.AddResourceToUser(kSecondary, kPipeline);
        table.AddUserToUser(kPrimary, kSecondary);

        table.GetReferencedHandleIds(nullptr, &unreferenced);
        REQUIRE(unreferenced.count(kSecondary) == 0);
        REQUIRE(unreferenced.count(kPipeline) == 0);
    }
}

// ScreenshotController holds every part of a screenshot that is not an API
// call.  None of this had a test: the frame selection lived in
// ScreenshotHandlerBase and the rest lived in the Vulkan consumer.
TEST_CASE("ScreenshotController selects the frames it was asked for", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;
    using gfxrecon::decode::ScreenshotRange;

    SECTION("no range asked for")
    {
        ReplayOptions        options;
        ScreenshotController controller(options);

        REQUIRE_FALSE(controller.Enabled());
        REQUIRE_FALSE(controller.IsScreenshotFrame());
    }

    SECTION("one closed range")
    {
        ReplayOptions options;
        options.screenshot_ranges = { ScreenshotRange{ 3, 5 } };

        ScreenshotController controller(options);
        REQUIRE(controller.Enabled());

        // Frames 1 and 2 are outside it, 3 to 5 are inside, 6 is past it.
        const bool expected[] = { false, false, true, true, true, false };
        for (uint32_t frame = 1; frame <= 6; ++frame)
        {
            REQUIRE(controller.GetCurrentFrame() == frame);
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("an interval counts from the start of the range")
    {
        ReplayOptions options;
        options.screenshot_ranges   = { ScreenshotRange{ 2, 8 } };
        options.screenshot_interval = 3;

        ScreenshotController controller(options);

        // 2, 5 and 8: every third frame counting from the first of the range,
        // not from frame 1.
        const bool expected[] = { false, true, false, false, true, false, false, true };
        for (uint32_t frame = 1; frame <= 8; ++frame)
        {
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("two ranges are taken in turn")
    {
        ReplayOptions options;
        options.screenshot_ranges = { ScreenshotRange{ 1, 2 }, ScreenshotRange{ 4, 4 } };

        ScreenshotController controller(options);

        const bool expected[] = { true, true, false, true, false };
        for (uint32_t frame = 1; frame <= 5; ++frame)
        {
            REQUIRE(controller.IsScreenshotFrame() == expected[frame - 1]);
            controller.EndFrame();
        }
    }

    SECTION("an interval of zero does not divide by zero")
    {
        ReplayOptions options;
        options.screenshot_ranges   = { ScreenshotRange{ 1, 2 } };
        options.screenshot_interval = 0;

        ScreenshotController controller(options);
        REQUIRE(controller.IsScreenshotFrame());
    }
}

TEST_CASE("ScreenshotController names one file per presented image", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;
    using gfxrecon::decode::ScreenshotRange;

    ReplayOptions options;
    options.screenshot_ranges      = { ScreenshotRange{ 1, 4 } };
    options.screenshot_file_prefix = "shot";

    ScreenshotController controller(options);

    // One image in the frame: the name says nothing about a swapchain, which is
    // the name these files have always had.
    REQUIRE(controller.FilenameFor() == "shot_frame_1");

    // More than one: each gets its own name.
    REQUIRE(controller.FilenameFor(0, 2) == "shot_swapchain_0_frame_1");
    REQUIRE(controller.FilenameFor(1, 2) == "shot_swapchain_1_frame_1");

    controller.EndFrame();
    REQUIRE(controller.FilenameFor() == "shot_frame_2");
}

// The one rule that was written down twice, with opposite emphasis:
// tools/replay/replay_settings.h says --screenshot-size is ignored when a scale
// is given, and android/scripts/gfxrecon.py says the scale overrides the size.
// Same rule; this is the executable statement of it.
TEST_CASE("ScreenshotController resolves a scale, and a scale beats a size", "[screenshot]")
{
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::ScreenshotController;

    SECTION("neither given: the image is read at its own size")
    {
        ReplayOptions options;
        REQUIRE_FALSE(ScreenshotController(options).ResolveScale(800, 600).has_value());
    }

    SECTION("a scale is used as given, both axes")
    {
        ReplayOptions options;
        options.screenshot_scale = std::array<float, 2>{ 0.5f, -1.0f };

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.5f);

        // A negative factor is how an axis is flipped, thus the sign has to
        // survive.
        REQUIRE(scale.value()[1] == -1.0f);
    }

    SECTION("a size becomes the scale that reaches it")
    {
        ReplayOptions options;
        options.screenshot_width  = 400;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.5f);
        REQUIRE(scale.value()[1] == 0.5f);
    }

    SECTION("a size need not keep the aspect ratio")
    {
        ReplayOptions options;
        options.screenshot_width  = 800;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 1.0f);
        REQUIRE(scale.value()[1] == 0.5f);
    }

    SECTION("both given: the scale wins and the size is ignored")
    {
        ReplayOptions options;
        options.screenshot_scale  = std::array<float, 2>{ 0.25f, 0.25f };
        options.screenshot_width  = 400;
        options.screenshot_height = 300;

        const auto scale = ScreenshotController(options).ResolveScale(800, 600);
        REQUIRE(scale.has_value());
        REQUIRE(scale.value()[0] == 0.25f);
        REQUIRE(scale.value()[1] == 0.25f);
    }

    SECTION("half a size is no size at all")
    {
        ReplayOptions options;
        options.screenshot_width = 400; // and no height

        REQUIRE_FALSE(ScreenshotController(options).ResolveScale(800, 600).has_value());
    }
}

TEST_CASE("ScreenshotController writes the file, rotating when asked", "[screenshot]")
{
    using gfxrecon::decode::CpuImage;
    using gfxrecon::decode::ReplayOptions;
    using gfxrecon::decode::Rotation;
    using gfxrecon::decode::ScreenshotController;
    namespace imagewriter = gfxrecon::util::imagewriter;

    const uint32_t        width  = 4;
    const uint32_t        height = 2;
    std::vector<uint32_t> pixels(width * height);
    for (size_t i = 0; i < pixels.size(); ++i)
    {
        pixels[i] = static_cast<uint32_t>(0xff000000u | (i * 0x010203u));
    }

    CpuImage image;
    image.width  = width;
    image.height = height;
    image.pitch  = width * 4;
    image.format = imagewriter::kFormat_BGRA;
    image.pixels = pixels.data();

    ReplayOptions options;
    options.screenshot_format = gfxrecon::util::ScreenshotFormat::kBmp;

    SECTION("no rotation")
    {
        ScreenshotController controller(options);
        REQUIRE(controller.Finish("screenshot_controller_plain", image, Rotation{}));
    }

    SECTION("a quarter turn swaps the sides")
    {
        ScreenshotController controller(options);

        Rotation rotation;
        rotation.rotation = imagewriter::ImageRotation::DEG_90;

        REQUIRE(controller.Finish("screenshot_controller_turned", image, rotation));
    }

    SECTION("an image that was never read back is refused")
    {
        ScreenshotController controller(options);

        CpuImage empty;
        REQUIRE_FALSE(controller.Finish("screenshot_controller_empty", empty, Rotation{}));
    }
}

// ---------------------------------------------------------------------------------------------------------
// Resource aliasing groups meta-data block, encode -> decode round trip.
// ---------------------------------------------------------------------------------------------------------

#include "decode/decode_allocator.h"
#include "encode/vulkan_resource_aliasing_writer.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_decoder.h"

#include <cstring>

namespace
{

// Records what the decoder handed the consumer, so the test can compare it against what was written.
class AliasingGroupsRecorder : public gfxrecon::decode::VulkanConsumer
{
  public:
    void
    ProcessResourceAliasingGroupsCommand(gfxrecon::format::HandleId                                  device_id,
                                         const std::vector<gfxrecon::decode::ResourceAliasingGroup>& groups) override
    {
        ++call_count;
        this->device_id = device_id;
        this->groups    = groups;
    }

    uint32_t                                             call_count{ 0 };
    gfxrecon::format::HandleId                           device_id{ gfxrecon::format::kNullHandleId };
    std::vector<gfxrecon::decode::ResourceAliasingGroup> groups;
};

// The block a writer produces, and its payload: everything the decoder is handed, i.e. the block without
// its MetaDataHeader.
struct WrittenBlock
{
    std::vector<uint8_t> bytes;

    const uint8_t* Payload() const { return bytes.data() + sizeof(gfxrecon::format::MetaDataHeader); }
    size_t         PayloadSize() const { return bytes.size() - sizeof(gfxrecon::format::MetaDataHeader); }
};

WrittenBlock WriteTwoGroups()
{
    VkBufferCreateInfo buffer_create_info{};
    buffer_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.size  = 4096;
    buffer_create_info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;

    VkImageCreateInfo image_create_info{};
    image_create_info.sType       = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.imageType   = VK_IMAGE_TYPE_2D;
    image_create_info.format      = VK_FORMAT_R8G8B8A8_UNORM;
    image_create_info.extent      = { 64, 32, 1 };
    image_create_info.mipLevels   = 1;
    image_create_info.arrayLayers = 1;
    image_create_info.samples     = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.usage       = VK_IMAGE_USAGE_SAMPLED_BIT;

    // Two members of different resource types at distinct bind offsets, so the round trip covers a
    // per-member offset and a per-member create-info type rather than one repeated value.
    const gfxrecon::encode::ResourceAliasingCreateInfo encoded_buffer =
        gfxrecon::encode::EncodeResourceAliasingCreateInfo(buffer_create_info);
    const gfxrecon::encode::ResourceAliasingCreateInfo encoded_image =
        gfxrecon::encode::EncodeResourceAliasingCreateInfo(image_create_info);

    gfxrecon::encode::ResourceAliasingGroupInfo group_0;
    group_0.memory_id = 12;
    group_0.group_id  = 1;
    group_0.members.push_back({ 100, 0, encoded_buffer });
    group_0.members.push_back({ 101, 2048, encoded_image });

    gfxrecon::encode::ResourceAliasingGroupInfo group_1;
    group_1.memory_id = 15;
    group_1.group_id  = 2;
    group_1.members.push_back({ 200, 4096, encoded_image });
    group_1.members.push_back({ 201, 4096, encoded_buffer });

    gfxrecon::util::MemoryOutputStream stream;
    gfxrecon::encode::WriteResourceAliasingGroupsCommand(&stream, 7, 42, { group_0, group_1 });

    WrittenBlock block;
    block.bytes.assign(stream.GetData(), stream.GetData() + stream.GetDataSize());
    return block;
}

// The first member header follows the block header fields and the first group header.
constexpr size_t kFirstMemberOffset = sizeof(gfxrecon::format::ThreadId) + sizeof(gfxrecon::format::HandleId) +
                                      sizeof(uint32_t) + sizeof(uint32_t) +
                                      sizeof(gfxrecon::format::ResourceAliasingGroupHeader);

} // namespace

TEST_CASE("A resource aliasing groups block survives an encode-decode round trip", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    format::ResourceAliasingGroupsCommandHeader header{};
    std::memcpy(&header, block.bytes.data(), sizeof(format::MetaDataHeader));

    REQUIRE(header.meta_header.block_header.type == format::BlockType::kMetaDataBlock);
    REQUIRE(header.meta_header.meta_data_id ==
            format::MakeMetaDataId(format::ApiFamily_Vulkan, format::MetaDataType::kResourceAliasingGroupsCommand));
    // BlockHeader::size counts everything after the BlockHeader, which is how a reader that does not know
    // this block type skips it.
    REQUIRE(header.meta_header.block_header.size == (block.bytes.size() - sizeof(format::BlockHeader)));

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(block.Payload(), block.PayloadSize());

    REQUIRE(recorder.call_count == 1);
    REQUIRE(recorder.device_id == 42);
    REQUIRE(recorder.groups.size() == 2);

    REQUIRE(recorder.groups[0].memory_id == 12);
    REQUIRE(recorder.groups[0].group_id == 1);
    REQUIRE(recorder.groups[0].members.size() == 2);

    const decode::ResourceAliasingMember& buffer_member = recorder.groups[0].members[0];
    REQUIRE(buffer_member.GetResourceType() == format::ResourceAliasingResourceType::kBuffer);
    REQUIRE(buffer_member.resource_id == 100);
    REQUIRE(buffer_member.bind_offset == 0);
    const VkBufferCreateInfo* decoded_buffer_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkBufferCreateInfo>>(buffer_member.create_info)
            .GetPointer();
    REQUIRE(decoded_buffer_info != nullptr);
    REQUIRE(decoded_buffer_info->size == 4096);
    REQUIRE(decoded_buffer_info->usage == VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);

    const decode::ResourceAliasingMember& image_member = recorder.groups[0].members[1];
    REQUIRE(image_member.GetResourceType() == format::ResourceAliasingResourceType::kImage);
    REQUIRE(image_member.resource_id == 101);
    REQUIRE(image_member.bind_offset == 2048);
    const VkImageCreateInfo* decoded_image_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkImageCreateInfo>>(image_member.create_info)
            .GetPointer();
    REQUIRE(decoded_image_info != nullptr);
    REQUIRE(decoded_image_info->format == VK_FORMAT_R8G8B8A8_UNORM);
    REQUIRE(decoded_image_info->extent.width == 64);
    REQUIRE(decoded_image_info->extent.height == 32);

    REQUIRE(recorder.groups[1].memory_id == 15);
    REQUIRE(recorder.groups[1].group_id == 2);
    REQUIRE(recorder.groups[1].members.size() == 2);
    REQUIRE(recorder.groups[1].members[0].bind_offset == 4096);
    REQUIRE(recorder.groups[1].members[1].GetResourceType() == format::ResourceAliasingResourceType::kBuffer);

    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups block is dropped whole when it cannot be read", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();

    SECTION("a truncated block reaches no consumer")
    {
        decoder.DispatchResourceAliasingGroupsCommand(block.Payload(), block.PayloadSize() - 1);
        REQUIRE(recorder.call_count == 0);
    }

    SECTION("a block written by a later layout version reaches no consumer")
    {
        std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

        // layout_version follows thread_id and device_id in the payload.
        const size_t   version_offset = sizeof(format::ThreadId) + sizeof(format::HandleId);
        const uint32_t next_version   = format::kResourceAliasingGroupsLayoutVersion + 1;
        std::memcpy(bytes.data() + version_offset, &next_version, sizeof(next_version));

        decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());
        REQUIRE(recorder.call_count == 0);
    }

    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups block with an unrecognized resource type is dropped", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock   block = WriteTwoGroups();
    std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

    format::ResourceAliasingMemberHeader member_header{};
    std::memcpy(&member_header, bytes.data() + kFirstMemberOffset, sizeof(member_header));
    REQUIRE(member_header.resource_id == 100);

    // kUnknown is what a member whose create-info was never filled in carries, and it is also what a
    // resource type added later looks like to this reader.
    member_header.resource_type = static_cast<uint32_t>(format::ResourceAliasingResourceType::kUnknown);
    std::memcpy(bytes.data() + kFirstMemberOffset, &member_header, sizeof(member_header));

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());
    REQUIRE(recorder.call_count == 0);
    decode::DecodeAllocator::End();
}

TEST_CASE("A resource aliasing groups member skips a property it does not know", "[optimize]")
{
    using namespace gfxrecon;

    const WrittenBlock block = WriteTwoGroups();

    // Splice an unknown property into the first member, in front of its create-info, and bump the member's
    // property count.  A reader of a later layout version writes exactly this.

    std::vector<uint8_t> bytes(block.Payload(), block.Payload() + block.PayloadSize());

    format::ResourceAliasingMemberHeader member_header{};
    std::memcpy(&member_header, bytes.data() + kFirstMemberOffset, sizeof(member_header));
    REQUIRE(member_header.resource_id == 100);
    REQUIRE(member_header.property_count == 1);

    member_header.property_count = 2;
    std::memcpy(bytes.data() + kFirstMemberOffset, &member_header, sizeof(member_header));

    const std::vector<uint8_t>             unknown_payload{ 0xde, 0xad, 0xbe, 0xef, 0x01, 0x02 };
    format::ResourceAliasingPropertyHeader unknown_header{};
    unknown_header.property_id   = 0xffff;
    unknown_header.property_size = static_cast<uint32_t>(unknown_payload.size());

    const size_t         properties_offset = kFirstMemberOffset + sizeof(member_header);
    std::vector<uint8_t> unknown_property(sizeof(unknown_header) + unknown_payload.size());
    std::memcpy(unknown_property.data(), &unknown_header, sizeof(unknown_header));
    std::memcpy(unknown_property.data() + sizeof(unknown_header), unknown_payload.data(), unknown_payload.size());
    bytes.insert(bytes.begin() + properties_offset, unknown_property.begin(), unknown_property.end());

    AliasingGroupsRecorder recorder;
    decode::VulkanDecoder  decoder;
    decoder.AddConsumer(&recorder);

    decode::DecodeAllocator::Begin();
    decoder.DispatchResourceAliasingGroupsCommand(bytes.data(), bytes.size());

    REQUIRE(recorder.call_count == 1);
    REQUIRE(recorder.groups.size() == 2);
    REQUIRE(recorder.groups[0].members.size() == 2);

    // The unknown property is skipped by its length, so the create-info behind it still decodes.
    const decode::ResourceAliasingMember& buffer_member = recorder.groups[0].members[0];
    REQUIRE(buffer_member.resource_id == 100);
    const VkBufferCreateInfo* decoded_buffer_info =
        std::get<decode::StructPointerDecoder<decode::Decoded_VkBufferCreateInfo>>(buffer_member.create_info)
            .GetPointer();
    REQUIRE(decoded_buffer_info != nullptr);
    REQUIRE(decoded_buffer_info->size == 4096);

    // The members and groups behind the spliced property are unaffected.
    REQUIRE(recorder.groups[0].members[1].resource_id == 101);
    REQUIRE(recorder.groups[1].members[1].resource_id == 201);

    decode::DecodeAllocator::End();
}

// ---------------------------------------------------------------------------------------------------------

#include "decode/vulkan_aliasing_group_layout.h"

namespace
{

using gfxrecon::decode::VulkanResourceAllocator;

VulkanResourceAllocator::AliasingGroupMember MakeAliasingMember(gfxrecon::format::HandleId id,
                                                                VkDeviceSize               offset,
                                                                VkDeviceSize               size,
                                                                VkDeviceSize               alignment,
                                                                uint32_t memory_type_bits = 0xffffffff)
{
    VulkanResourceAllocator::AliasingGroupMember member;
    member.resource_id                 = id;
    member.bind_offset                 = offset;
    member.requirements.size           = size;
    member.requirements.alignment      = alignment;
    member.requirements.memoryTypeBits = memory_type_bits;
    return member;
}

} // namespace

TEST_CASE("An aliasing group is sized from the union of its members", "[rebind]")
{
    SECTION("members at one offset need the largest of them")
    {
        // vulkan_compute_aliasing: a 4915200 byte buffer and a 1228800 byte image, both at offset 0.
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 4915200, 256), MakeAliasingMember(2, 0, 1228800, 1024) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.base_offset == 0);
        REQUIRE(layout.union_size == 4915200);
        REQUIRE(layout.alignment == 1024);
    }

    SECTION("a member reaching past the largest one extends the union")
    {
        // vulkan_aliasing_2: 1024 bytes at 0 and 1536 bytes at 512, so the union runs to 2048.
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 1024, 256), MakeAliasingMember(2, 512, 1536, 256) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.base_offset == 0);
        REQUIRE(layout.union_size == 2048);
    }

    SECTION("the base is the smallest bind offset, and the union is relative to it")
    {
        // vulkan_aliasing_5: two 512 byte buffers at 4096.
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 4096, 512, 256), MakeAliasingMember(2, 4096, 512, 256) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.base_offset == 4096);
        REQUIRE(layout.union_size == 512);
    }

    SECTION("nested members at three offsets all fit under the outermost")
    {
        // vulkan_aliasing_multilevel_containment: 8448 at 0 contains 4352 at 4096 contains 256 at 8192.
        const std::vector<VulkanResourceAllocator::AliasingGroupMember> members{ MakeAliasingMember(1, 0, 8448, 256),
                                                                                 MakeAliasingMember(2, 4096, 4352, 256),
                                                                                 MakeAliasingMember(
                                                                                     3, 8192, 256, 256) };
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(members, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.union_size == 8448);
    }

    SECTION("the union is rounded up to the alignment")
    {
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 1000, 1024), MakeAliasingMember(2, 0, 512, 256) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.alignment == 1024);
        REQUIRE(layout.union_size == 1024);
    }

    SECTION("the minimum alignment applies when no member asks for more")
    {
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 64, 16), MakeAliasingMember(2, 0, 32, 16) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.alignment == 128);
        REQUIRE(layout.union_size == 128);
    }

    SECTION("only the memory types every member accepts survive")
    {
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 512, 256, 0b1110), MakeAliasingMember(2, 0, 512, 256, 0b0111) }, 128);

        REQUIRE(layout.valid);
        REQUIRE(layout.memory_type_bits == 0b0110);
    }
}

TEST_CASE("An aliasing group that cannot be allocated is rejected", "[rebind]")
{
    SECTION("members sharing no memory type")
    {
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 512, 256, 0b0001), MakeAliasingMember(2, 0, 512, 256, 0b0010) }, 128);

        REQUIRE_FALSE(layout.valid);
    }

    SECTION("an empty group")
    {
        REQUIRE_FALSE(gfxrecon::decode::ComputeAliasingGroupLayout({}, 128).valid);
    }

    SECTION("a member whose extent overflows")
    {
        const auto layout = gfxrecon::decode::ComputeAliasingGroupLayout(
            { MakeAliasingMember(1, 0, 512, 256),
              MakeAliasingMember(2, 4096, std::numeric_limits<VkDeviceSize>::max(), 256) },
            128);

        REQUIRE_FALSE(layout.valid);
    }
}
