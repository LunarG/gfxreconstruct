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

// Catch must come before the Vulkan headers.
#include <catch2/catch.hpp>

#include "decode/decode_allocator.h"
#include "decode/vulkan_stage_image_layout.h"
#include "generated/generated_vulkan_decoder.h"

#include <cstring>
#include <string>
#include <vector>

using namespace gfxrecon::decode;
namespace format = gfxrecon::format;

namespace
{

constexpr format::HandleId kDevice         = 1;
constexpr format::HandleId kQueue          = 10;
constexpr format::HandleId kImage          = 20;
constexpr format::HandleId kOtherImage     = 21;
constexpr format::HandleId kCommandBuffer  = 30;
constexpr format::HandleId kSecondary      = 31;
constexpr format::HandleId kUnknownCommand = 39;

// A 2D color image with two mip levels and one layer, created in VK_IMAGE_LAYOUT_UNDEFINED.
std::vector<uint8_t> CreateImageBytes(format::HandleId image)
{
    return ByteWriter()
        .Put<format::HandleId>(kDevice)                     // device
        .Put<uint32_t>(kStructPointer)                      // pCreateInfo
        .Put<uint64_t>(kUnusedAddress)                      //   address
        .Put<uint32_t>(VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)                  //   pNext
        .Put<uint32_t>(0)                                   //   flags
        .Put<uint32_t>(VK_IMAGE_TYPE_2D)                    //   imageType
        .Put<uint32_t>(VK_FORMAT_R8G8B8A8_UNORM)            //   format
        .Put<uint32_t>(64)                                  //   extent.width
        .Put<uint32_t>(64)                                  //   extent.height
        .Put<uint32_t>(1)                                   //   extent.depth
        .Put<uint32_t>(2)                                   //   mipLevels
        .Put<uint32_t>(1)                                   //   arrayLayers
        .Put<uint32_t>(VK_SAMPLE_COUNT_1_BIT)               //   samples
        .Put<uint32_t>(VK_IMAGE_TILING_OPTIMAL)             //   tiling
        .Put<uint32_t>(VK_IMAGE_USAGE_TRANSFER_DST_BIT)     //   usage
        .Put<uint32_t>(VK_SHARING_MODE_EXCLUSIVE)           //   sharingMode
        .Put<uint32_t>(0)                                   //   queueFamilyIndexCount
        .Put<uint32_t>(kNullArray)                          //   pQueueFamilyIndices
        .Put<uint32_t>(VK_IMAGE_LAYOUT_UNDEFINED)           //   initialLayout
        .Put<uint32_t>(kNullStructPointer)                  // pAllocator
        .Put<uint32_t>(kHandlePointer)                      // pImage
        .Put<uint64_t>(kUnusedAddress)                      //   address
        .Put<format::HandleId>(image)                       //   id
        .Put<int32_t>(VK_SUCCESS)                           // result
        .Bytes();
}

// One image barrier that moves a mip level of the image to new_layout.
std::vector<uint8_t>
PipelineBarrierBytes(format::HandleId command_buffer, format::HandleId image, uint32_t mip, VkImageLayout new_layout)
{
    return ByteWriter()
        .Put<format::HandleId>(command_buffer)                 // commandBuffer
        .Put<uint32_t>(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT)     // srcStageMask
        .Put<uint32_t>(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT)     // dstStageMask
        .Put<uint32_t>(0)                                      // dependencyFlags
        .Put<uint32_t>(0)                                      // memoryBarrierCount
        .Put<uint32_t>(kNullStructArray)                       // pMemoryBarriers
        .Put<uint32_t>(0)                                      // bufferMemoryBarrierCount
        .Put<uint32_t>(kNullStructArray)                       // pBufferMemoryBarriers
        .Put<uint32_t>(1)                                      // imageMemoryBarrierCount
        .Put<uint32_t>(kStructArrayPointer)                    // pImageMemoryBarriers
        .Put<uint64_t>(kUnusedAddress)                         //   address
        .Put<uint64_t>(1)                                      //   length
        .Put<uint32_t>(VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER) //   sType
        .Put<uint32_t>(kNullStructPointer)                     //   pNext
        .Put<uint32_t>(0)                                      //   srcAccessMask
        .Put<uint32_t>(0)                                      //   dstAccessMask
        .Put<uint32_t>(VK_IMAGE_LAYOUT_UNDEFINED)              //   oldLayout
        .Put<uint32_t>(new_layout)                             //   newLayout
        .Put<uint32_t>(VK_QUEUE_FAMILY_IGNORED)                //   srcQueueFamilyIndex
        .Put<uint32_t>(VK_QUEUE_FAMILY_IGNORED)                //   dstQueueFamilyIndex
        .Put<format::HandleId>(image)                          //   image
        .Put<uint32_t>(VK_IMAGE_ASPECT_COLOR_BIT)              //   subresourceRange.aspectMask
        .Put<uint32_t>(mip)                                    //   subresourceRange.baseMipLevel
        .Put<uint32_t>(1)                                      //   subresourceRange.levelCount
        .Put<uint32_t>(0)                                      //   subresourceRange.baseArrayLayer
        .Put<uint32_t>(1)                                      //   subresourceRange.layerCount
        .Bytes();
}

std::vector<uint8_t> ExecuteCommandsBytes(format::HandleId primary, format::HandleId secondary)
{
    return ByteWriter()
        .Put<format::HandleId>(primary)   // commandBuffer
        .Put<uint32_t>(1)                 // commandBufferCount
        .Put<uint32_t>(kArrayPointer)     // pCommandBuffers
        .Put<uint64_t>(kUnusedAddress)    //   address
        .Put<uint64_t>(1)                 //   length
        .Put<format::HandleId>(secondary) //   ids
        .Bytes();
}

// One submit info with one command buffer, no semaphores, no fence.
std::vector<uint8_t> QueueSubmitBytes(format::HandleId command_buffer, VkResult result)
{
    return ByteWriter()
        .Put<format::HandleId>(kQueue)                // queue
        .Put<uint32_t>(1)                             // submitCount
        .Put<uint32_t>(kStructArrayPointer)           // pSubmits
        .Put<uint64_t>(kUnusedAddress)                //   address
        .Put<uint64_t>(1)                             //   length
        .Put<uint32_t>(VK_STRUCTURE_TYPE_SUBMIT_INFO) //   sType
        .Put<uint32_t>(kNullStructPointer)            //   pNext
        .Put<uint32_t>(0)                             //   waitSemaphoreCount
        .Put<uint32_t>(kNullArray)                    //   pWaitSemaphores
        .Put<uint32_t>(kNullArray)                    //   pWaitDstStageMask
        .Put<uint32_t>(1)                             //   commandBufferCount
        .Put<uint32_t>(kArrayPointer)                 //   pCommandBuffers
        .Put<uint64_t>(kUnusedAddress)                //     address
        .Put<uint64_t>(1)                             //     length
        .Put<format::HandleId>(command_buffer)        //     ids
        .Put<uint32_t>(0)                             //   signalSemaphoreCount
        .Put<uint32_t>(kNullArray)                    //   pSignalSemaphores
        .Put<format::HandleId>(format::kNullHandleId) // fence
        .Put<int32_t>(result)                         // result
        .Bytes();
}

// The object info table keeps only infos with a handle. The tests never call Vulkan, so any non-null value works.
// VkImage is a pointer on 64-bit platforms and an integer on 32-bit ones, so copy the bytes.
template <typename HandleT>
HandleT FakeHandle(uint64_t value)
{
    static_assert(sizeof(HandleT) <= sizeof(value));
    HandleT handle{};
    std::memcpy(&handle, &value, sizeof(HandleT));
    return handle;
}

// Stands in for the replay consumer, which fills the object info table. It adds the info of each image that it
// creates, and counts the calls that the stage sends on.
class FakeReplayConsumer : public VulkanConsumer
{
  public:
    explicit FakeReplayConsumer(CommonObjectInfoTable& table) : table_(table) {}

    void Process_vkCreateImage(const ApiCallInfo&, args::CreateImage& args) override
    {
        ++calls;

        const VkImageCreateInfo* create_info = args.pCreateInfo.GetPointer();
        VulkanImageInfo          info;
        info.capture_id     = *args.pImage.GetPointer();
        info.handle         = FakeHandle<VkImage>(info.capture_id);
        info.format         = create_info->format;
        info.level_count    = create_info->mipLevels;
        info.layer_count    = create_info->arrayLayers;
        info.initial_layout = create_info->initialLayout;
        table_.AddVkImageInfo(std::move(info));
    }

    void Process_vkCmdPipelineBarrier(const ApiCallInfo&, args::CmdPipelineBarrier&) override { ++calls; }
    void Process_vkCmdExecuteCommands(const ApiCallInfo&, args::CmdExecuteCommands&) override { ++calls; }

    // Keeps the layout of the first subresource of kImage that the consumer sees during the submit.
    void Process_vkQueueSubmit(const ApiCallInfo&, args::QueueSubmit&) override
    {
        ++calls;

        const VulkanImageInfo* image_info = table_.GetVkImageInfo(kImage);
        if (image_info != nullptr)
        {
            layout_at_submit = image_info->subresource_layouts.GetSubresourceLayout(VK_IMAGE_ASPECT_COLOR_BIT, 0, 0);
        }
    }

    int           calls            = 0;
    VkImageLayout layout_at_submit = VK_IMAGE_LAYOUT_MAX_ENUM;

  private:
    CommonObjectInfoTable& table_;
};

class Harness
{
  public:
    Harness() : consumer(table), stage_(table)
    {
        decoder_.AddConsumer(&stage_);
        stage_.AddNext(&consumer);

        for (const format::HandleId command_buffer : { kCommandBuffer, kSecondary })
        {
            VulkanCommandBufferInfo info;
            info.capture_id = command_buffer;
            info.handle     = FakeHandle<VkCommandBuffer>(command_buffer);
            table.AddVkCommandBufferInfo(std::move(info));
        }
    }

    void Send(format::ApiCallId call_id, const std::vector<uint8_t>& bytes)
    {
        DecoderAllocGuard<true> guard;
        decoder_.DecodeFunctionCall(call_id, ApiCallInfo{}, bytes.data(), bytes.size());
    }

    // The layout of a mip level once the submitted work is done.
    VkImageLayout Layout(format::HandleId image, uint32_t mip) const
    {
        const VulkanImageInfo* image_info = table.GetVkImageInfo(image);
        return (image_info != nullptr)
                   ? image_info->subresource_layouts.GetSubresourceLayout(VK_IMAGE_ASPECT_COLOR_BIT, mip, 0)
                   : VK_IMAGE_LAYOUT_MAX_ENUM;
    }

    // The layout of a mip level that a command buffer leaves behind. VK_IMAGE_LAYOUT_MAX_ENUM when the command buffer
    // does not move the image.
    VkImageLayout Recorded(format::HandleId command_buffer, format::HandleId image, uint32_t mip) const
    {
        const VulkanCommandBufferInfo* command_buffer_info = table.GetVkCommandBufferInfo(command_buffer);
        if (command_buffer_info == nullptr)
        {
            return VK_IMAGE_LAYOUT_MAX_ENUM;
        }

        const auto entry = command_buffer_info->image_layout_barriers.find(image);
        return (entry != command_buffer_info->image_layout_barriers.end())
                   ? entry->second.GetSubresourceLayout(VK_IMAGE_ASPECT_COLOR_BIT, mip, 0)
                   : VK_IMAGE_LAYOUT_MAX_ENUM;
    }

    // The table comes first, because the stage and the consumer keep a reference to it.
    CommonObjectInfoTable table;
    FakeReplayConsumer    consumer;

  private:
    VulkanDecoder          decoder_;
    VulkanStageImageLayout stage_;
};

} // namespace

TEST_CASE("Image layout stage starts an image in its initial layout", "[stage][image_layout]")
{
    Harness harness;
    harness.Send(format::ApiCall_vkCreateImage, CreateImageBytes(kImage));

    const VulkanImageInfo* image_info = harness.table.GetVkImageInfo(kImage);
    REQUIRE(image_info != nullptr);
    CHECK(image_info->subresource_layouts.IsInitialized());
    CHECK(image_info->subresource_layouts.GetMipLevels() == 2);
    CHECK(harness.Layout(kImage, 0) == VK_IMAGE_LAYOUT_UNDEFINED);
    CHECK(harness.Layout(kImage, 1) == VK_IMAGE_LAYOUT_UNDEFINED);
    CHECK(harness.consumer.calls == 1);
}

TEST_CASE("Image layout stage moves an image when the command buffer is submitted", "[stage][image_layout]")
{
    Harness harness;
    harness.Send(format::ApiCall_vkCreateImage, CreateImageBytes(kImage));
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kCommandBuffer, kImage, 0, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL));

    // Recording moves the command buffer's view of the image, but not the image.
    CHECK(harness.Recorded(kCommandBuffer, kImage, 0) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(harness.Recorded(kCommandBuffer, kImage, 1) == VK_IMAGE_LAYOUT_UNDEFINED);
    CHECK(harness.Layout(kImage, 0) == VK_IMAGE_LAYOUT_UNDEFINED);
    CHECK(harness.table.GetVkImageInfo(kImage)->intermediate_layout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);

    harness.Send(format::ApiCall_vkQueueSubmit, QueueSubmitBytes(kCommandBuffer, VK_SUCCESS));

    CHECK(harness.Layout(kImage, 0) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(harness.Layout(kImage, 1) == VK_IMAGE_LAYOUT_UNDEFINED);

    // The replay consumer sees the layouts that the submit leaves behind while it processes the submit.
    CHECK(harness.consumer.layout_at_submit == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(harness.consumer.calls == 3);
}

TEST_CASE("Image layout stage ignores a submit that failed in the capture", "[stage][image_layout]")
{
    Harness harness;
    harness.Send(format::ApiCall_vkCreateImage, CreateImageBytes(kImage));
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kCommandBuffer, kImage, 0, VK_IMAGE_LAYOUT_GENERAL));
    harness.Send(format::ApiCall_vkQueueSubmit, QueueSubmitBytes(kCommandBuffer, VK_ERROR_DEVICE_LOST));

    CHECK(harness.Layout(kImage, 0) == VK_IMAGE_LAYOUT_UNDEFINED);
}

TEST_CASE("Image layout stage adds a secondary command buffer to the primary that executes it", "[stage][image_layout]")
{
    Harness harness;
    harness.Send(format::ApiCall_vkCreateImage, CreateImageBytes(kImage));
    harness.Send(format::ApiCall_vkCreateImage, CreateImageBytes(kOtherImage));
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kSecondary, kImage, 1, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL));
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kCommandBuffer, kImage, 0, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL));
    harness.Send(format::ApiCall_vkCmdExecuteCommands, ExecuteCommandsBytes(kCommandBuffer, kSecondary));
    harness.Send(format::ApiCall_vkQueueSubmit, QueueSubmitBytes(kCommandBuffer, VK_SUCCESS));

    CHECK(harness.Layout(kImage, 0) == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    CHECK(harness.Layout(kImage, 1) == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
    CHECK(harness.Layout(kOtherImage, 0) == VK_IMAGE_LAYOUT_UNDEFINED);
}

TEST_CASE("Image layout stage skips images and command buffers that it does not know", "[stage][image_layout]")
{
    Harness harness;
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kUnknownCommand, kImage, 0, VK_IMAGE_LAYOUT_GENERAL));
    harness.Send(format::ApiCall_vkCmdPipelineBarrier,
                 PipelineBarrierBytes(kCommandBuffer, kImage, 0, VK_IMAGE_LAYOUT_GENERAL));
    harness.Send(format::ApiCall_vkQueueSubmit, QueueSubmitBytes(kUnknownCommand, VK_SUCCESS));

    CHECK(harness.table.GetVkImageInfo(kImage) == nullptr);
    CHECK(harness.Recorded(kCommandBuffer, kImage, 0) == VK_IMAGE_LAYOUT_MAX_ENUM);
    CHECK(harness.consumer.calls == 3);
}
