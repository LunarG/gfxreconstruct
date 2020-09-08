/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_SCREENSHOT_HANDLER_H
#define GFXRECON_DECODE_SCREENSHOT_HANDLER_H

#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_allocator.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class ScreenshotHandler
{
  public:
    ScreenshotHandler(ScreenshotFormat screenshot_format, const std::vector<ScreenshotRange>& screenshot_ranges);

    ScreenshotHandler(ScreenshotFormat screenshot_format, std::vector<ScreenshotRange>&& screenshot_ranges);

    uint32_t GetCurrentFrame() const { return current_frame_number_; }

    void EndFrame();

    bool IsScreenshotFrame() const;

    void WriteImage(const std::string&                      filename_prefix,
                    VkDevice                                device,
                    const encode::DeviceTable*              device_table,
                    const VkPhysicalDeviceMemoryProperties& memory_properties,
                    VulkanResourceAllocator*                allocator,
                    VkImage                                 image,
                    VkFormat                                format,
                    uint32_t                                width,
                    uint32_t                                height);

    void DestroyDevice(VkDevice device, const encode::DeviceTable* device_table);

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
    VkDeviceSize GetCopyBufferSize(VkDevice                   device,
                                   const encode::DeviceTable* device_table,
                                   VkFormat                   format,
                                   uint32_t                   width,
                                   uint32_t                   height) const;

    uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                uint32_t                                type_bits,
                                VkMemoryPropertyFlags                   property_flags) const;

    VkResult CreateCopyResource(VkDevice                                device,
                                const encode::DeviceTable*              device_table,
                                const VkPhysicalDeviceMemoryProperties& memory_properties,
                                VkDeviceSize                            buffer_size,
                                VkFormat                                image_format,
                                uint32_t                                width,
                                uint32_t                                height,
                                CopyResource*                           copy_resource) const;

    void
    DestroyCopyResource(VkDevice device, const encode::DeviceTable* device_table, CopyResource* copy_resource) const;

  private:
    uint32_t                     current_frame_number_;
    CommandPools                 copy_resources_;
    ScreenshotFormat             screenshot_format_;
    std::vector<ScreenshotRange> screenshot_ranges_;
    size_t                       current_range_index_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_HANDLER_H
