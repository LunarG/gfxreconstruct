/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/screenshot_handler.h"
#include "util/image_writer.h"
#include "util/logging.h"
#include "util/platform.h"
#include "decode/decoder_util.h"

#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static constexpr uint32_t kDefaultQueueFamilyIndex = 0;
static constexpr uint32_t kDefaultQueueIndex       = 0;

static constexpr size_t kUnormIndex = 0;
static constexpr size_t kSrgbIndex  = 1;

inline void WriteImageFile(const std::string&     filename,
                           util::ScreenshotFormat file_format,
                           uint32_t               width,
                           uint32_t               height,
                           uint64_t               size,
                           void*                  data)
{
    switch (file_format)
    {
        default:
            GFXRECON_LOG_ERROR("Screenshot format invalid!  Expected BMP or PNG, falling back to BMP.");
            // Intentional fall-through
        case util::ScreenshotFormat::kBmp:
            if (!util::imagewriter::WriteBmpImage(filename + ".bmp", width, height, size, data))
            {
                GFXRECON_LOG_ERROR("Screenshot could not be created: failed to write BMP file %s", filename.c_str());
            }
            break;
#ifdef GFXRECON_ENABLE_PNG_SCREENSHOT
        case util::ScreenshotFormat::kPng:
            if (!util::imagewriter::WritePngImage(filename + ".png", width, height, size, data))
            {
                GFXRECON_LOG_ERROR("Screenshot could not be created: failed to write PNG file %s", filename.c_str());
            }
            break;
#endif // GFXRECON_ENABLE_PNG_SCREENSHOT
    }
}

void ScreenshotHandler::WriteImage(const std::string&                      filename_prefix,
                                   const VulkanDeviceInfo*                 device_info,
                                   const encode::VulkanDeviceTable*        device_table,
                                   const VkPhysicalDeviceMemoryProperties& memory_properties,
                                   VulkanResourceAllocator*                allocator,
                                   VkImage                                 image,
                                   VkFormat                                format,
                                   uint32_t                                width,
                                   uint32_t                                height,
                                   uint32_t                                copy_width,
                                   uint32_t                                copy_height,
                                   VkImageLayout                           image_layout)
{
    if ((device_table == nullptr) || (allocator == nullptr))
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: missing device table or allocator");
        return;
    }

    if ((width == 0) || (height == 0))
    {
        GFXRECON_LOG_WARNING("Cannot create screenshot \"%s\" for 0 size image (width=%" PRIu32 ", height=%" PRIu32
                             ").",
                             filename_prefix.c_str(),
                             width,
                             height);
        return;
    }

    VkResult result = VK_SUCCESS;
    auto     device = device_info->handle;
    // TODO: Improved queue selection; ensure queue supports transfer operations.

    // Get a command pool for the device.
    auto copy_resource_entry = copy_resources_.find(device);
    if (copy_resource_entry == copy_resources_.end())
    {
        VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
        create_info.pNext                   = nullptr;
        create_info.flags                   = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
        create_info.queueFamilyIndex        = kDefaultQueueFamilyIndex;

        VkCommandPool command_pool = VK_NULL_HANDLE;
        result                     = device_table->CreateCommandPool(device, &create_info, nullptr, &command_pool);

        if (result == VK_SUCCESS)
        {
            CopyResource copy_resource = {};
            copy_resource.command_pool = command_pool;
            copy_resource.allocator    = allocator;

            auto pair           = copy_resources_.emplace(device, std::move(copy_resource));
            copy_resource_entry = pair.first;
        }
    }

    if (result == VK_SUCCESS)
    {
        auto&   copy_resource = copy_resource_entry->second;
        auto    copy_format   = GetConversionFormat(format);
        VkQueue queue         = VK_NULL_HANDLE;

        // Get a queue.
        queue = GetDeviceQueue(device_table, device_info, kDefaultQueueFamilyIndex, kDefaultQueueIndex);

        // Get a buffer size.
        VkDeviceSize buffer_size     = copy_resource.buffer_size;
        bool         create_resource = false;

        // If the copy resource is not initialized, or the image properties have changed, recompute the copy size.
        if ((buffer_size == 0) || (copy_resource.width != copy_width) || (copy_resource.height != copy_height) ||
            (copy_resource.format != copy_format))
        {
            buffer_size     = GetCopyBufferSize(device, device_table, copy_format, copy_width, copy_height);
            create_resource = true;
        }

        if (create_resource)
        {
            // Need to create/recreate resource.
            DestroyCopyResource(device, &copy_resource);

            result = CreateCopyResource(device,
                                        device_table,
                                        memory_properties,
                                        buffer_size,
                                        format,
                                        copy_format,
                                        width,
                                        height,
                                        copy_width,
                                        copy_height,
                                        &copy_resource);
        }
        else if (buffer_size == 0)
        {
            // GetCopyBufferSize failed to determine a valid size.
            result = VK_ERROR_INITIALIZATION_FAILED;
        }

        if (result == VK_SUCCESS)
        {
            // Get a command buffer.
            VkCommandBuffer command_buffer = VK_NULL_HANDLE;

            VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
            allocate_info.pNext                       = nullptr;
            allocate_info.commandPool                 = copy_resource.command_pool;
            allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
            allocate_info.commandBufferCount          = 1;

            result = device_table->AllocateCommandBuffers(device, &allocate_info, &command_buffer);
            if (result == VK_SUCCESS)
            {
                VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
                begin_info.pNext                    = nullptr;
                begin_info.flags                    = 0;
                begin_info.pInheritanceInfo         = nullptr;

                result = device_table->BeginCommandBuffer(command_buffer, &begin_info);
            }

            if (result == VK_SUCCESS)
            {
                // Transition source image from image_layout to the TRANSFER_DST layout.
                VkImageMemoryBarrier image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
                image_barrier.pNext                           = nullptr;
                image_barrier.srcAccessMask                   = 0;
                image_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
                image_barrier.oldLayout                       = image_layout;
                image_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                image_barrier.image                           = image;
                image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                image_barrier.subresourceRange.baseArrayLayer = 0;
                image_barrier.subresourceRange.layerCount     = 1;
                image_barrier.subresourceRange.baseMipLevel   = 0;
                image_barrier.subresourceRange.levelCount     = 1;

                device_table->CmdPipelineBarrier(command_buffer,
                                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                 0,
                                                 0,
                                                 nullptr,
                                                 0,
                                                 nullptr,
                                                 1,
                                                 &image_barrier);

                // The 'copy_image' is the image to be used with the image to buffer copy.
                VkImage copy_image = image;
                if (copy_resource.convert_image != VK_NULL_HANDLE)
                {
                    // Need to perform a blit to covert the Vulkan image format to the image file format.
                    copy_image = copy_resource.convert_image;

                    // Transition blit target to the TRANSFER_DST layout.
                    VkImageMemoryBarrier convert_image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
                    convert_image_barrier.pNext                           = nullptr;
                    convert_image_barrier.srcAccessMask                   = 0;
                    convert_image_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_WRITE_BIT;
                    convert_image_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
                    convert_image_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                    convert_image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                    convert_image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                    convert_image_barrier.image                           = copy_image;
                    convert_image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                    convert_image_barrier.subresourceRange.baseArrayLayer = 0;
                    convert_image_barrier.subresourceRange.layerCount     = 1;
                    convert_image_barrier.subresourceRange.baseMipLevel   = 0;
                    convert_image_barrier.subresourceRange.levelCount     = 1;

                    device_table->CmdPipelineBarrier(command_buffer,
                                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     0,
                                                     0,
                                                     nullptr,
                                                     0,
                                                     nullptr,
                                                     1,
                                                     &convert_image_barrier);

                    VkImageBlit blit_region;
                    blit_region.srcSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                    blit_region.srcSubresource.mipLevel       = 0;
                    blit_region.srcSubresource.baseArrayLayer = 0;
                    blit_region.srcSubresource.layerCount     = 1;
                    blit_region.srcOffsets[0].x               = 0;
                    blit_region.srcOffsets[0].y               = 0;
                    blit_region.srcOffsets[0].z               = 0;
                    blit_region.srcOffsets[1].x               = width;
                    blit_region.srcOffsets[1].y               = height;
                    blit_region.srcOffsets[1].z               = 1;
                    blit_region.dstSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                    blit_region.dstSubresource.mipLevel       = 0;
                    blit_region.dstSubresource.baseArrayLayer = 0;
                    blit_region.dstSubresource.layerCount     = 1;
                    blit_region.dstOffsets[0].x               = 0;
                    blit_region.dstOffsets[0].y               = 0;
                    blit_region.dstOffsets[0].z               = 0;
                    blit_region.dstOffsets[1].x               = copy_width;
                    blit_region.dstOffsets[1].y               = copy_height;
                    blit_region.dstOffsets[1].z               = 1;

                    device_table->CmdBlitImage(command_buffer,
                                               image,
                                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                               copy_image,
                                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                               1,
                                               &blit_region,
                                               VK_FILTER_NEAREST);

                    // Transition blit target from the TRANSFER_DST layout to TRANSFER_SRC layout for the image to
                    // buffer copy.
                    convert_image_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                    convert_image_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                    convert_image_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                    convert_image_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

                    device_table->CmdPipelineBarrier(command_buffer,
                                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     0,
                                                     0,
                                                     nullptr,
                                                     0,
                                                     nullptr,
                                                     1,
                                                     &convert_image_barrier);
                }

                VkBufferImageCopy copy_region;
                copy_region.bufferOffset                    = 0;
                copy_region.bufferRowLength                 = 0;
                copy_region.bufferImageHeight               = 0;
                copy_region.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                copy_region.imageSubresource.mipLevel       = 0;
                copy_region.imageSubresource.baseArrayLayer = 0;
                copy_region.imageSubresource.layerCount     = 1;
                copy_region.imageOffset                     = { 0, 0, 0 };
                copy_region.imageExtent                     = { copy_width, copy_height, 1 };

                device_table->CmdCopyImageToBuffer(command_buffer,
                                                   copy_image,
                                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                   copy_resource.buffer,
                                                   1,
                                                   &copy_region);

                // Transition source image back to image_layout after the screenshot.
                image_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
                image_barrier.dstAccessMask       = 0;
                image_barrier.oldLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                image_barrier.newLayout           = image_layout;
                image_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
                image_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;

                device_table->CmdPipelineBarrier(command_buffer,
                                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                 VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                 0,
                                                 0,
                                                 nullptr,
                                                 0,
                                                 nullptr,
                                                 1,
                                                 &image_barrier);

                device_table->EndCommandBuffer(command_buffer);

                // Make sure any pending work is finished, as we are not waiting on any semaphores from previous
                // submissions.
                result = device_table->DeviceWaitIdle(device);

                if (result == VK_SUCCESS)
                {
                    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
                    submit_info.waitSemaphoreCount   = 0;
                    submit_info.pWaitSemaphores      = nullptr;
                    submit_info.pWaitDstStageMask    = nullptr;
                    submit_info.commandBufferCount   = 1;
                    submit_info.pCommandBuffers      = &command_buffer;
                    submit_info.signalSemaphoreCount = 0;
                    submit_info.pSignalSemaphores    = nullptr;

                    result = device_table->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);
                }

                if (result == VK_SUCCESS)
                {
                    result = device_table->QueueWaitIdle(queue);
                }

                if (result == VK_SUCCESS)
                {
                    void* data = nullptr;
                    result     = allocator->MapResourceMemoryDirect(
                        copy_resource.buffer_size, 0, &data, copy_resource.buffer_data);

                    if (result == VK_SUCCESS)
                    {
                        if ((copy_resource.memory_property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) !=
                            VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
                        {
                            VkMappedMemoryRange invalidate_range = { VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE };
                            invalidate_range.pNext               = nullptr;
                            invalidate_range.memory              = copy_resource.buffer_memory;
                            invalidate_range.offset              = 0;
                            invalidate_range.size                = copy_resource.buffer_size;

                            allocator->InvalidateMappedMemoryRangesDirect(
                                1, &invalidate_range, &copy_resource.buffer_memory_data);
                        }

                        WriteImageFile(filename_prefix,
                                       screenshot_format_,
                                       copy_width,
                                       copy_height,
                                       copy_resource.buffer_size,
                                       data);

                        allocator->UnmapResourceMemoryDirect(copy_resource.buffer_data);
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("Screenshot could not be created: failed to execute image transfer");
                }

                device_table->FreeCommandBuffers(device, copy_resource.command_pool, 1, &command_buffer);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Screenshot could not be created: failed to create a transfer resource");
        }
    }
}

void ScreenshotHandler::DestroyDeviceResources(VkDevice device, const encode::VulkanDeviceTable* device_table)
{
    auto entry = copy_resources_.find(device);
    if (entry != copy_resources_.end())
    {
        auto& copy_resource = entry->second;

        if (device_table != nullptr)
        {
            device_table->DestroyCommandPool(entry->first, copy_resource.command_pool, nullptr);
        }

        DestroyCopyResource(device, &copy_resource);

        copy_resources_.erase(entry);
    }
}

bool ScreenshotHandler::IsSrgbFormat(VkFormat image_format) const
{
    switch (image_format)
    {
        case VK_FORMAT_R8_SRGB:
        case VK_FORMAT_R8G8_SRGB:
        case VK_FORMAT_R8G8B8_SRGB:
        case VK_FORMAT_B8G8R8_SRGB:
        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_B8G8R8A8_SRGB:
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        case VK_FORMAT_BC2_SRGB_BLOCK:
        case VK_FORMAT_BC3_SRGB_BLOCK:
        case VK_FORMAT_BC7_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return true;
        default:
            return false;
    }
}

VkFormat ScreenshotHandler::GetConversionFormat(VkFormat image_format) const
{
    return IsSrgbFormat(image_format) ? VK_FORMAT_B8G8R8A8_SRGB : VK_FORMAT_B8G8R8A8_UNORM;
}

VkDeviceSize ScreenshotHandler::GetCopyBufferSize(VkDevice                         device,
                                                  const encode::VulkanDeviceTable* device_table,
                                                  VkFormat                         format,
                                                  uint32_t                         width,
                                                  uint32_t                         height) const
{
    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = VK_IMAGE_TYPE_2D;
    create_info.format                = format;
    create_info.extent                = { width, height, 1 };
    create_info.mipLevels             = 1;
    create_info.arrayLayers           = 1;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = VK_IMAGE_TILING_LINEAR;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImage              image               = VK_NULL_HANDLE;
    VkMemoryRequirements memory_requirements = {};

    VkResult result = device_table->CreateImage(device, &create_info, nullptr, &image);
    if (result == VK_SUCCESS)
    {
        device_table->GetImageMemoryRequirements(device, image, &memory_requirements);
        device_table->DestroyImage(device, image, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: failed to determine transfer buffer size");
    }

    return memory_requirements.size;
}

uint32_t ScreenshotHandler::GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                               uint32_t                                type_bits,
                                               VkMemoryPropertyFlags                   property_flags) const
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

VkResult ScreenshotHandler::CreateCopyResource(VkDevice                                device,
                                               const encode::VulkanDeviceTable*        device_table,
                                               const VkPhysicalDeviceMemoryProperties& memory_properties,
                                               VkDeviceSize                            buffer_size,
                                               VkFormat                                image_format,
                                               VkFormat                                screenshot_format,
                                               uint32_t                                width,
                                               uint32_t                                height,
                                               uint32_t                                copy_width,
                                               uint32_t                                copy_height,
                                               CopyResource*                           copy_resource) const
{
    assert(device_table != nullptr);

    if ((buffer_size == 0) || (copy_resource == nullptr))
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    auto allocator = copy_resource->allocator;

    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = buffer_size;
    create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    VkResult result =
        allocator->CreateBufferDirect(&create_info, nullptr, &copy_resource->buffer, &copy_resource->buffer_data);

    if (result == VK_SUCCESS)
    {
        VkMemoryRequirements memory_requirements;
        device_table->GetBufferMemoryRequirements(device, copy_resource->buffer, &memory_requirements);

        uint32_t memory_type_index =
            GetMemoryTypeIndex(memory_properties,
                               memory_requirements.memoryTypeBits,
                               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT);

        if (memory_type_index == std::numeric_limits<uint32_t>::max())
        {
            /* fallback to coherent */
            memory_type_index =
                GetMemoryTypeIndex(memory_properties,
                                   memory_requirements.memoryTypeBits,
                                   VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
        }

        assert(memory_type_index != std::numeric_limits<uint32_t>::max());

        VkMemoryAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        allocate_info.pNext                = nullptr;
        allocate_info.allocationSize       = memory_requirements.size;
        allocate_info.memoryTypeIndex      = memory_type_index;

        result = allocator->AllocateMemoryDirect(
            &allocate_info, nullptr, &copy_resource->buffer_memory, &copy_resource->buffer_memory_data);
    }

    if (result == VK_SUCCESS)
    {
        result = allocator->BindBufferMemoryDirect(copy_resource->buffer,
                                                   copy_resource->buffer_memory,
                                                   0,
                                                   copy_resource->buffer_data,
                                                   copy_resource->buffer_memory_data,
                                                   &copy_resource->memory_property_flags);
    }

    if ((result == VK_SUCCESS) &&
        ((image_format != screenshot_format) || (width != copy_width) || (height != copy_height)))
    {
        // The source image format does not match the image file format and requires a format conversion.  Create an
        // image to serve as the tranfer destination of a blit based color conversion.
        VkImageCreateInfo image_create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
        image_create_info.pNext                 = nullptr;
        image_create_info.flags                 = 0;
        image_create_info.imageType             = VK_IMAGE_TYPE_2D;
        image_create_info.format                = screenshot_format;
        image_create_info.extent                = { copy_width, copy_height, 1 };
        image_create_info.mipLevels             = 1;
        image_create_info.arrayLayers           = 1;
        image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
        image_create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        image_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        image_create_info.queueFamilyIndexCount = 0;
        image_create_info.pQueueFamilyIndices   = nullptr;
        image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

        result = allocator->CreateImageDirect(
            &image_create_info, nullptr, &copy_resource->convert_image, &copy_resource->convert_image_data);

        if (result == VK_SUCCESS)
        {
            VkMemoryRequirements memory_requirements;
            device_table->GetImageMemoryRequirements(device, copy_resource->convert_image, &memory_requirements);

            uint32_t memory_type_index = GetMemoryTypeIndex(
                memory_properties, memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

            assert(memory_type_index != std::numeric_limits<uint32_t>::max());

            VkMemoryAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            allocate_info.pNext                = nullptr;
            allocate_info.allocationSize       = memory_requirements.size;
            allocate_info.memoryTypeIndex      = memory_type_index;

            result = allocator->AllocateMemoryDirect(&allocate_info,
                                                     nullptr,
                                                     &copy_resource->convert_image_memory,
                                                     &copy_resource->convert_image_memory_data);
        }

        if (result == VK_SUCCESS)
        {
            VkMemoryPropertyFlags image_memory_property_flags = 0;

            result = allocator->BindImageMemoryDirect(copy_resource->convert_image,
                                                      copy_resource->convert_image_memory,
                                                      0,
                                                      copy_resource->convert_image_data,
                                                      copy_resource->convert_image_memory_data,
                                                      &image_memory_property_flags);
        }
    }

    if (result == VK_SUCCESS)
    {
        // Resource creation succeeded.
        copy_resource->buffer_size = buffer_size;
        copy_resource->format      = screenshot_format;
        copy_resource->width       = copy_width;
        copy_resource->height      = copy_height;
    }
    else
    {
        DestroyCopyResource(device, copy_resource);
    }

    return result;
}

void ScreenshotHandler::DestroyCopyResource(VkDevice device, CopyResource* copy_resource) const
{
    if (copy_resource != nullptr)
    {
        if (copy_resource->buffer != VK_NULL_HANDLE)
        {
            copy_resource->allocator->DestroyBufferDirect(copy_resource->buffer, nullptr, copy_resource->buffer_data);
            copy_resource->buffer      = VK_NULL_HANDLE;
            copy_resource->buffer_data = 0;
        }

        if (copy_resource->buffer_memory != VK_NULL_HANDLE)
        {
            copy_resource->allocator->FreeMemoryDirect(
                copy_resource->buffer_memory, nullptr, copy_resource->buffer_memory_data);
            copy_resource->buffer_memory         = VK_NULL_HANDLE;
            copy_resource->buffer_memory_data    = 0;
            copy_resource->memory_property_flags = 0;
        }

        if (copy_resource->convert_image != VK_NULL_HANDLE)
        {
            copy_resource->allocator->DestroyImageDirect(
                copy_resource->convert_image, nullptr, copy_resource->convert_image_data);
            copy_resource->convert_image      = VK_NULL_HANDLE;
            copy_resource->convert_image_data = 0;
        }

        if (copy_resource->convert_image_memory != VK_NULL_HANDLE)
        {
            copy_resource->allocator->FreeMemoryDirect(
                copy_resource->convert_image_memory, nullptr, copy_resource->convert_image_memory_data);
            copy_resource->convert_image_memory      = VK_NULL_HANDLE;
            copy_resource->convert_image_memory_data = 0;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
