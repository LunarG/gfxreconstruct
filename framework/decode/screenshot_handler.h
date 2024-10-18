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

#ifndef GFXRECON_DECODE_SCREENSHOT_HANDLER_H
#define GFXRECON_DECODE_SCREENSHOT_HANDLER_H

#include "decode/screenshot_handler_base.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_allocator.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <atomic>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class ScreenshotHandler : public ScreenshotHandlerBase
{
  public:
    ScreenshotHandler(util::ScreenshotFormat screenshot_format, const std::vector<ScreenshotRange>& screenshot_ranges) :
        ScreenshotHandlerBase(screenshot_format, screenshot_ranges)
    {}

    ScreenshotHandler(util::ScreenshotFormat screenshot_format, std::vector<ScreenshotRange>&& screenshot_ranges) :
        ScreenshotHandlerBase(screenshot_format, screenshot_ranges)
    {}

    void WriteImage(const std::string&                      filename_prefix,
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
                    VkImageLayout                           image_layout);

    void DestroyDeviceResources(VkDevice device, const encode::VulkanDeviceTable* device_table);

  private:
    struct CopyResource
    {
        VkCommandPool                         command_pool{ VK_NULL_HANDLE };
        VulkanResourceAllocator*              allocator{ nullptr };
        VkDeviceSize                          buffer_size{ 0 };
        VkDeviceMemory                        buffer_memory{ VK_NULL_HANDLE };
        VkBuffer                              buffer{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData   buffer_memory_data{ 0 };
        VulkanResourceAllocator::ResourceData buffer_data{ 0 };
        VkDeviceMemory                        convert_image_memory{ VK_NULL_HANDLE };
        VkImage                               convert_image{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData   convert_image_memory_data{ 0 };
        VulkanResourceAllocator::ResourceData convert_image_data{ 0 };
        VkFormat                              format{ VK_FORMAT_UNDEFINED };
        uint32_t                              width{ 0 };
        uint32_t                              height{ 0 };
        VkMemoryPropertyFlags                 memory_property_flags{ 0 };
    };

    typedef std::unordered_map<VkDevice, CopyResource> CommandPools;

  private:
    bool IsSrgbFormat(VkFormat image_format) const;

    VkFormat GetConversionFormat(VkFormat image_format) const;

    VkDeviceSize GetCopyBufferSize(VkDevice                         device,
                                   const encode::VulkanDeviceTable* device_table,
                                   VkFormat                         format,
                                   uint32_t                         width,
                                   uint32_t                         height) const;

    uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                uint32_t                                type_bits,
                                VkMemoryPropertyFlags                   property_flags) const;

    VkResult CreateCopyResource(VkDevice                                device,
                                const encode::VulkanDeviceTable*        device_table,
                                const VkPhysicalDeviceMemoryProperties& memory_properties,
                                VkDeviceSize                            buffer_size,
                                VkFormat                                image_format,
                                VkFormat                                screenshot_format,
                                uint32_t                                width,
                                uint32_t                                height,
                                uint32_t                                copy_width,
                                uint32_t                                copy_height,
                                CopyResource*                           copy_resource) const;

    void DestroyCopyResource(VkDevice device, CopyResource* copy_resource) const;

  private:
    CommandPools copy_resources_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_HANDLER_H
