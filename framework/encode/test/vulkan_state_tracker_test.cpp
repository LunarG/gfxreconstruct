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

// Before any Vulkan header: on Linux, vulkan.h includes Xlib.h, whose macros break catch.hpp.
#include <catch2/catch.hpp>

#include "encode/vulkan_device_address_tracker.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_info.h"
#include "encode/vulkan_state_tracker.h"
#include "encode/vulkan_state_writer.h"
#include "format/format.h"
#include "util/file_output_stream.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"
#include "util/thread_data.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cstring>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <memory>
#include <unordered_map>
#include <vector>

namespace // Support functions and data for the VulkanStateTracker tests
{
gfxrecon::format::HandleId GetNextTrackedHandleId()
{
    static gfxrecon::format::HandleId next_id = 1000;
    return ++next_id;
}

// A dispatchable handle points to an object whose first member is the loader's dispatch table pointer.
struct DispatchableObject
{
    void* dispatch_table{ nullptr };
};

// The wrappers the state tracker reads, created as the capture layer creates them, for handles no driver has made.
class TrackedObjects
{
  public:
    TrackedObjects()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        device_ = reinterpret_cast<VkDevice>(&device_object_);
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(
            VK_NULL_HANDLE, NoParentWrapper::kHandleValue, &device_, GetNextTrackedHandleId);
    }

    ~TrackedObjects()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        // Destroying a pool destroys the wrappers of its command buffers.
        for (VkCommandPool pool : command_pools_)
        {
            DestroyWrappedHandle<CommandPoolWrapper>(pool);
        }
        for (VkBuffer buffer : buffers_)
        {
            DestroyWrappedHandle<BufferWrapper>(buffer);
        }
        for (VkImage image : images_)
        {
            DestroyWrappedHandle<ImageWrapper>(image);
        }
        DestroyWrappedHandle<DeviceWrapper>(device_);
    }

    VkCommandPool CreateCommandPool(uint32_t queue_family_index)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkCommandPool pool = gfxrecon::format::FromHandleId<VkCommandPool>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, CommandPoolWrapper>(
            device_, NoParentWrapper::kHandleValue, &pool, GetNextTrackedHandleId);
        GetWrapper<CommandPoolWrapper>(pool)->queue_family_index = queue_family_index;

        command_pools_.push_back(pool);
        return pool;
    }

    VkCommandBuffer CreateCommandBuffer(VkCommandPool pool)
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkCommandBuffer command_buffer = reinterpret_cast<VkCommandBuffer>(&command_buffer_objects_.emplace_back());
        CreateWrappedHandle<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(
            device_, pool, &command_buffer, GetNextTrackedHandleId);

        return command_buffer;
    }

    VkBuffer CreateBuffer()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkBuffer buffer = gfxrecon::format::FromHandleId<VkBuffer>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferWrapper>(
            device_, NoParentWrapper::kHandleValue, &buffer, GetNextTrackedHandleId);

        buffers_.push_back(buffer);
        return buffer;
    }

    VkImage CreateImage()
    {
        using namespace gfxrecon::encode::vulkan_wrappers;

        VkImage image = gfxrecon::format::FromHandleId<VkImage>(NextHandleValue());
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageWrapper>(
            device_, NoParentWrapper::kHandleValue, &image, GetNextTrackedHandleId);

        images_.push_back(image);
        return image;
    }

    gfxrecon::encode::vulkan_wrappers::DeviceWrapper* GetDeviceWrapper() const
    {
        return gfxrecon::encode::vulkan_wrappers::GetWrapper<gfxrecon::encode::vulkan_wrappers::DeviceWrapper>(device_);
    }

  private:
    uint64_t NextHandleValue() { return ++next_handle_value_; }

    uint64_t                       next_handle_value_{ 0x10000 };
    DispatchableObject             device_object_;
    VkDevice                       device_{ VK_NULL_HANDLE };
    std::deque<DispatchableObject> command_buffer_objects_; // A deque keeps the addresses the handles point to.
    std::vector<VkCommandPool>     command_pools_;
    std::vector<VkBuffer>          buffers_;
    std::vector<VkImage>           images_;
};

VkImageMemoryBarrier MakeLayoutTransition(VkImage image, VkImageLayout old_layout, VkImageLayout new_layout)
{
    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
    barrier.oldLayout            = old_layout;
    barrier.newLayout            = new_layout;
    barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.image                = image;
    barrier.subresourceRange     = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };
    return barrier;
}
} // namespace

TEST_CASE("Every submit in a batch applies its command buffers' image layouts", "[state_tracking]")
{
    using gfxrecon::encode::vulkan_wrappers::GetWrapper;
    using gfxrecon::encode::vulkan_wrappers::ImageWrapper;

    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    {
        TrackedObjects                       objects;
        gfxrecon::encode::VulkanStateTracker tracker;

        const VkCommandPool   pool           = objects.CreateCommandPool(0);
        const VkCommandBuffer command_buffer = objects.CreateCommandBuffer(pool);
        const VkImage         image          = objects.CreateImage();

        const VkImageMemoryBarrier barrier =
            MakeLayoutTransition(image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        tracker.TrackImageBarriers(command_buffer, 1, &barrier);

        REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_UNDEFINED);

        // The first submit carries no command buffers, as a submit that only waits on or signals semaphores does.
        SECTION("vkQueueSubmit")
        {
            VkSubmitInfo submits[2]       = { { VK_STRUCTURE_TYPE_SUBMIT_INFO }, { VK_STRUCTURE_TYPE_SUBMIT_INFO } };
            submits[1].commandBufferCount = 1;
            submits[1].pCommandBuffers    = &command_buffer;

            tracker.TrackCommandBufferSubmissions(2, submits);

            REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        }

        SECTION("vkQueueSubmit2")
        {
            VkCommandBufferSubmitInfo command_buffer_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO };
            command_buffer_info.commandBuffer             = command_buffer;

            VkSubmitInfo2 submits[2] = { { VK_STRUCTURE_TYPE_SUBMIT_INFO_2 }, { VK_STRUCTURE_TYPE_SUBMIT_INFO_2 } };
            submits[1].commandBufferInfoCount = 1;
            submits[1].pCommandBufferInfos    = &command_buffer_info;

            tracker.TrackCommandBufferSubmissions2(2, submits);

            REQUIRE(GetWrapper<ImageWrapper>(image)->current_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
        }
    }

    gfxrecon::util::Log::Release();
}

TEST_CASE("Queue family ownership releases are held until their acquire", "[state_tracking]")
{
    using gfxrecon::encode::vulkan_state_info::ApplyQueueFamilyOwnershipTransfer;
    using gfxrecon::encode::vulkan_state_info::IsQueueFamilyOwnershipTransfer;
    using gfxrecon::encode::vulkan_state_info::QueueFamilyOwnershipTransfer;

    const uint32_t kGraphics = 0;
    const uint32_t kCompute  = 2;

    SECTION("Only transfers between two of the device's queue families count")
    {
        REQUIRE(IsQueueFamilyOwnershipTransfer(kGraphics, kCompute));
        REQUIRE_FALSE(IsQueueFamilyOwnershipTransfer(kGraphics, kGraphics));
        REQUIRE_FALSE(IsQueueFamilyOwnershipTransfer(VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED));
        REQUIRE_FALSE(IsQueueFamilyOwnershipTransfer(kGraphics, VK_QUEUE_FAMILY_IGNORED));
        REQUIRE_FALSE(IsQueueFamilyOwnershipTransfer(VK_QUEUE_FAMILY_EXTERNAL, kCompute));
        REQUIRE_FALSE(IsQueueFamilyOwnershipTransfer(kGraphics, VK_QUEUE_FAMILY_FOREIGN_EXT));
    }

    QueueFamilyOwnershipTransfer to_compute;
    to_compute.src_queue_family_index = kGraphics;
    to_compute.dst_queue_family_index = kCompute;
    to_compute.offset                 = 0;
    to_compute.size                   = VK_WHOLE_SIZE;

    QueueFamilyOwnershipTransfer to_graphics = to_compute;
    to_graphics.src_queue_family_index       = kCompute;
    to_graphics.dst_queue_family_index       = kGraphics;

    std::vector<QueueFamilyOwnershipTransfer> pending;

    SECTION("A matching acquire completes a release")
    {
        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);
        REQUIRE(pending.size() == 1);

        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, false);
        REQUIRE(pending.empty());
    }

    SECTION("Releasing the same range twice leaves one pending release")
    {
        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);
        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);
        REQUIRE(pending.size() == 1);
    }

    SECTION("An acquire with other parameters leaves the release pending")
    {
        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);

        QueueFamilyOwnershipTransfer other_range = to_compute;
        other_range.size                         = 256;
        ApplyQueueFamilyOwnershipTransfer(pending, other_range, false);
        ApplyQueueFamilyOwnershipTransfer(pending, to_graphics, false);

        REQUIRE(pending.size() == 1);
        REQUIRE(pending[0] == to_compute);
    }

    SECTION("A frame's round trip leaves the last release pending")
    {
        // The first release, recorded before the first frame.
        ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);

        for (uint32_t frame = 0; frame < 3; ++frame)
        {
            // Compute acquires, dispatches, and gives it back; graphics acquires, draws, and releases it again.
            ApplyQueueFamilyOwnershipTransfer(pending, to_compute, false);
            ApplyQueueFamilyOwnershipTransfer(pending, to_graphics, true);
            ApplyQueueFamilyOwnershipTransfer(pending, to_graphics, false);
            ApplyQueueFamilyOwnershipTransfer(pending, to_compute, true);
        }

        REQUIRE(pending.size() == 1);
        REQUIRE(pending[0] == to_compute);
    }

    SECTION("Image transfers match on layouts and subresource range")
    {
        QueueFamilyOwnershipTransfer image_release;
        image_release.src_queue_family_index = kGraphics;
        image_release.dst_queue_family_index = kCompute;
        image_release.old_layout             = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        image_release.new_layout             = VK_IMAGE_LAYOUT_GENERAL;
        image_release.subresource_range      = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };

        ApplyQueueFamilyOwnershipTransfer(pending, image_release, true);

        QueueFamilyOwnershipTransfer other_layout = image_release;
        other_layout.old_layout                   = VK_IMAGE_LAYOUT_GENERAL;
        ApplyQueueFamilyOwnershipTransfer(pending, other_layout, false);

        QueueFamilyOwnershipTransfer other_level   = image_release;
        other_level.subresource_range.baseMipLevel = 1;
        ApplyQueueFamilyOwnershipTransfer(pending, other_level, false);

        REQUIRE(pending.size() == 1);

        ApplyQueueFamilyOwnershipTransfer(pending, image_release, false);
        REQUIRE(pending.empty());
    }
}

TEST_CASE("The state tracker holds a submitted ownership release until its acquire is submitted", "[state_tracking]")
{
    using gfxrecon::encode::vulkan_wrappers::BufferWrapper;
    using gfxrecon::encode::vulkan_wrappers::GetWrapper;
    using gfxrecon::encode::vulkan_wrappers::ImageWrapper;

    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    {
        const uint32_t kGraphics = 0;
        const uint32_t kCompute  = 2;

        TrackedObjects                       objects;
        gfxrecon::encode::VulkanStateTracker tracker;

        const VkCommandPool   graphics_pool     = objects.CreateCommandPool(kGraphics);
        const VkCommandPool   compute_pool      = objects.CreateCommandPool(kCompute);
        const VkCommandBuffer graphics_commands = objects.CreateCommandBuffer(graphics_pool);
        const VkCommandBuffer compute_commands  = objects.CreateCommandBuffer(compute_pool);
        const VkBuffer        buffer            = objects.CreateBuffer();
        const VkImage         image             = objects.CreateImage();

        const auto& buffer_releases = GetWrapper<BufferWrapper>(buffer)->pending_ownership_releases;
        const auto& image_releases  = GetWrapper<ImageWrapper>(image)->pending_ownership_releases;

        // The same barrier is recorded on both queues: graphics records it as the release, compute as the acquire.
        VkBufferMemoryBarrier buffer_transfer = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER };
        buffer_transfer.srcAccessMask         = VK_ACCESS_SHADER_WRITE_BIT;
        buffer_transfer.srcQueueFamilyIndex   = kGraphics;
        buffer_transfer.dstQueueFamilyIndex   = kCompute;
        buffer_transfer.buffer                = buffer;
        buffer_transfer.offset                = 0;
        buffer_transfer.size                  = VK_WHOLE_SIZE;

        VkImageMemoryBarrier image_transfer =
            MakeLayoutTransition(image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_GENERAL);
        image_transfer.srcQueueFamilyIndex = kGraphics;
        image_transfer.dstQueueFamilyIndex = kCompute;

        VkSubmitInfo graphics_submit       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        graphics_submit.commandBufferCount = 1;
        graphics_submit.pCommandBuffers    = &graphics_commands;

        VkSubmitInfo compute_submit       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        compute_submit.commandBufferCount = 1;
        compute_submit.pCommandBuffers    = &compute_commands;

        SECTION("vkCmdPipelineBarrier: a release is pending from its submit to its acquire's submit")
        {
            tracker.TrackOwnershipTransfers(graphics_commands, 1, &buffer_transfer, 1, &image_transfer);
            tracker.TrackOwnershipTransfers(compute_commands, 1, &buffer_transfer, 1, &image_transfer);

            // Recorded, not yet submitted.
            REQUIRE(buffer_releases.empty());
            REQUIRE(image_releases.empty());

            // A trim that starts here has to re-record the release, or the acquire it replays next is invalid
            // (VUID-vkQueueSubmit-pSubmits-02207).
            tracker.TrackCommandBufferSubmissions(1, &graphics_submit);

            REQUIRE(buffer_releases.size() == 1);
            REQUIRE(buffer_releases[0].src_queue_family_index == kGraphics);
            REQUIRE(buffer_releases[0].dst_queue_family_index == kCompute);
            REQUIRE(buffer_releases[0].size == VK_WHOLE_SIZE);

            REQUIRE(image_releases.size() == 1);
            REQUIRE(image_releases[0].old_layout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
            REQUIRE(image_releases[0].new_layout == VK_IMAGE_LAYOUT_GENERAL);

            tracker.TrackCommandBufferSubmissions(1, &compute_submit);

            REQUIRE(buffer_releases.empty());
            REQUIRE(image_releases.empty());
        }

        SECTION("vkCmdPipelineBarrier2: a release is pending from its submit to its acquire's submit")
        {
            VkBufferMemoryBarrier2 buffer_transfer2 = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2 };
            buffer_transfer2.srcStageMask           = VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT;
            buffer_transfer2.srcAccessMask          = VK_ACCESS_2_SHADER_WRITE_BIT;
            buffer_transfer2.srcQueueFamilyIndex    = kGraphics;
            buffer_transfer2.dstQueueFamilyIndex    = kCompute;
            buffer_transfer2.buffer                 = buffer;
            buffer_transfer2.offset                 = 0;
            buffer_transfer2.size                   = VK_WHOLE_SIZE;

            VkDependencyInfo dependency         = { VK_STRUCTURE_TYPE_DEPENDENCY_INFO };
            dependency.bufferMemoryBarrierCount = 1;
            dependency.pBufferMemoryBarriers    = &buffer_transfer2;

            tracker.TrackOwnershipTransfers2(graphics_commands, 1, &dependency);
            tracker.TrackOwnershipTransfers2(compute_commands, 1, &dependency);

            tracker.TrackCommandBufferSubmissions(1, &graphics_submit);
            REQUIRE(buffer_releases.size() == 1);

            tracker.TrackCommandBufferSubmissions(1, &compute_submit);
            REQUIRE(buffer_releases.empty());
        }

        SECTION("A release recorded in a secondary command buffer is pending once its primary is submitted")
        {
            const VkCommandBuffer secondary = objects.CreateCommandBuffer(graphics_pool);

            tracker.TrackOwnershipTransfers(secondary, 1, &buffer_transfer, 0, nullptr);
            tracker.TrackExecuteCommands(graphics_commands, 1, &secondary);

            tracker.TrackCommandBufferSubmissions(1, &graphics_submit);
            REQUIRE(buffer_releases.size() == 1);
        }

        SECTION("A barrier on neither of its queue families is not a release or an acquire")
        {
            const VkCommandPool   transfer_pool     = objects.CreateCommandPool(1);
            const VkCommandBuffer transfer_commands = objects.CreateCommandBuffer(transfer_pool);

            tracker.TrackOwnershipTransfers(transfer_commands, 1, &buffer_transfer, 0, nullptr);

            VkSubmitInfo transfer_submit       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            transfer_submit.commandBufferCount = 1;
            transfer_submit.pCommandBuffers    = &transfer_commands;

            tracker.TrackCommandBufferSubmissions(1, &transfer_submit);
            REQUIRE(buffer_releases.empty());
        }

        SECTION("A barrier that keeps the queue family is not a transfer")
        {
            buffer_transfer.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buffer_transfer.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;

            tracker.TrackOwnershipTransfers(graphics_commands, 1, &buffer_transfer, 0, nullptr);
            tracker.TrackCommandBufferSubmissions(1, &graphics_submit);

            REQUIRE(buffer_releases.empty());
        }
    }

    gfxrecon::util::Log::Release();
}

namespace // Support functions for TEST_CASE("The trim state snapshot re-records a pending ownership release")
{
struct FunctionCall
{
    gfxrecon::format::ApiCallId call_id{ gfxrecon::format::ApiCallId::ApiCall_Unknown };
    std::vector<uint8_t>        parameters;
};

// The uncompressed function call blocks of a capture file, in file order.
std::vector<FunctionCall> ReadFunctionCalls(const std::filesystem::path& path)
{
    std::ifstream        file(path, std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<FunctionCall> calls;
    size_t                    offset = 0;
    while ((offset + sizeof(gfxrecon::format::BlockHeader)) <= data.size())
    {
        gfxrecon::format::BlockHeader block_header;
        std::memcpy(&block_header, data.data() + offset, sizeof(block_header));

        const size_t block_end = offset + sizeof(block_header) + static_cast<size_t>(block_header.size);
        if (block_end > data.size())
        {
            break;
        }

        if (block_header.type == gfxrecon::format::BlockType::kFunctionCallBlock)
        {
            gfxrecon::format::FunctionCallHeader call_header;
            std::memcpy(&call_header, data.data() + offset, sizeof(call_header));

            FunctionCall call;
            call.call_id = call_header.api_call_id;
            call.parameters.assign(data.begin() + offset + sizeof(call_header), data.begin() + block_end);
            calls.push_back(std::move(call));
        }

        offset = block_end;
    }

    return calls;
}
} // namespace

TEST_CASE("The trim state snapshot re-records a pending ownership release", "[state_tracking]")
{
    using gfxrecon::encode::vulkan_wrappers::BufferWrapper;
    using gfxrecon::encode::vulkan_wrappers::GetWrapper;
    using gfxrecon::format::ApiCallId;

    gfxrecon::util::Log::Init(gfxrecon::util::LoggingSeverity::kError);

    const std::filesystem::path snapshot_path =
        std::filesystem::temp_directory_path() / "gfxrecon_encode_test_ownership_release.gfxr";

    {
        const uint32_t kGraphics = 0;
        const uint32_t kCompute  = 2;

        TrackedObjects                       objects;
        gfxrecon::encode::VulkanStateTracker tracker;

        const VkCommandPool   graphics_pool     = objects.CreateCommandPool(kGraphics);
        const VkCommandBuffer graphics_commands = objects.CreateCommandBuffer(graphics_pool);
        const VkBuffer        buffer            = objects.CreateBuffer();

        // A sparse buffer with no bindings: the snapshot writes its creation and its release, but reads no contents
        // through a driver.
        BufferWrapper* buffer_wrapper     = GetWrapper<BufferWrapper>(buffer);
        buffer_wrapper->device            = objects.GetDeviceWrapper();
        buffer_wrapper->is_sparse_buffer  = true;
        buffer_wrapper->create_call_id    = ApiCallId::ApiCall_vkCreateBuffer;
        buffer_wrapper->create_parameters = std::make_shared<gfxrecon::util::MemoryOutputStream>();

        // The frame before the trim range ends by releasing the buffer to compute, which acquires it inside the range.
        VkBufferMemoryBarrier release = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER };
        release.srcAccessMask         = VK_ACCESS_SHADER_WRITE_BIT;
        release.srcQueueFamilyIndex   = kGraphics;
        release.dstQueueFamilyIndex   = kCompute;
        release.buffer                = buffer;
        release.offset                = 0;
        release.size                  = VK_WHOLE_SIZE;

        tracker.TrackOwnershipTransfers(graphics_commands, 1, &release, 0, nullptr);

        VkSubmitInfo submit       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit.commandBufferCount = 1;
        submit.pCommandBuffers    = &graphics_commands;
        tracker.TrackCommandBufferSubmissions(1, &submit);

        gfxrecon::encode::VulkanStateTable state_table;
        state_table.InsertWrapper(buffer_wrapper->handle_id, buffer_wrapper);

        {
            gfxrecon::util::FileOutputStream output_stream(snapshot_path.string(), 4096);
            gfxrecon::util::ThreadData       thread_data;
            const std::unordered_map<VkDevice, gfxrecon::encode::VulkanDeviceAddressTracker> device_address_trackers;

            gfxrecon::encode::VulkanStateWriter writer(
                &output_stream, nullptr, &thread_data, GetNextTrackedHandleId, device_address_trackers);
            writer.WriteState(state_table, 1);
        }

        const std::vector<FunctionCall> calls = ReadFunctionCalls(snapshot_path);

        const auto barrier = std::find_if(calls.begin(), calls.end(), [](const FunctionCall& call) {
            return call.call_id == ApiCallId::ApiCall_vkCmdPipelineBarrier;
        });
        REQUIRE(barrier != calls.end());

        // The release is submitted on a queue of its source family. vkGetDeviceQueue's parameters start with the
        // device's handle id and the queue family index.
        const auto queue =
            std::find_if(std::make_reverse_iterator(barrier), calls.rend(), [](const FunctionCall& call) {
                return call.call_id == ApiCallId::ApiCall_vkGetDeviceQueue;
            });
        REQUIRE(queue != calls.rend());
        REQUIRE(queue->parameters.size() >= sizeof(gfxrecon::format::HandleId) + sizeof(uint32_t));

        uint32_t queue_family_index = 0;
        std::memcpy(&queue_family_index,
                    queue->parameters.data() + sizeof(gfxrecon::format::HandleId),
                    sizeof(queue_family_index));
        REQUIRE(queue_family_index == kGraphics);

        const auto execution = std::find_if(barrier, calls.end(), [](const FunctionCall& call) {
            return call.call_id == ApiCallId::ApiCall_vkQueueSubmit;
        });
        REQUIRE(execution != calls.end());
    }

    std::filesystem::remove(snapshot_path);

    gfxrecon::util::Log::Release();
}
