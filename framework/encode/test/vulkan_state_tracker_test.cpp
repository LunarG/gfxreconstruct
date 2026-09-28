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

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_tracker.h"
#include "format/format.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <deque>
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
