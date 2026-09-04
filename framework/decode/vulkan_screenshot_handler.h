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

#ifndef GFXRECON_DECODE_VULKAN_SCREENSHOT_HANDLER_H
#define GFXRECON_DECODE_VULKAN_SCREENSHOT_HANDLER_H

#include "decode/screenshot_controller.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "graphics/vulkan_resources_util.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <atomic>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//! What --screenshot-prerotation makes of a surface transform.
Rotation RotationForSurfaceTransform(VkSurfaceTransformFlagBitsKHR pre_transform);

/**
 * @brief One image, ready for the controller to read.
 *
 * Made where the image is chosen and used at once, because every value below
 * belongs to the one call that made it.  The read-back itself is
 * graphics::VulkanResourcesUtil, which dump-resources uses too.
 */
class VulkanScreenshotSource : public ScreenshotSource
{
  public:
    //! Everything about the image that the read-back has to know.
    struct Image
    {
        VkImage               handle{ VK_NULL_HANDLE };
        VkFormat              format{ VK_FORMAT_UNDEFINED };
        VkImageType           type{ VK_IMAGE_TYPE_2D };
        VkImageTiling         tiling{ VK_IMAGE_TILING_OPTIMAL };
        VkSampleCountFlagBits sample_count{ VK_SAMPLE_COUNT_1_BIT };
        VkImageLayout         layout{ VK_IMAGE_LAYOUT_UNDEFINED };
        uint32_t              queue_family_index{ 0 };
    };

    VulkanScreenshotSource(const VulkanDeviceInfo*                    device_info,
                           const graphics::VulkanInjectedDeviceCalls& injected_calls,
                           const graphics::VulkanInstanceTable*       instance_table,
                           const VkPhysicalDeviceMemoryProperties&    memory_properties,
                           const Image&                               image) :
        device_info_(device_info),
        injected_calls_(injected_calls), instance_table_(instance_table), memory_properties_(memory_properties),
        image_(image)
    {}

    bool Readback(const ScreenshotRequest& request, CpuImage* out) override;

  private:
    const VulkanDeviceInfo*              device_info_;
    graphics::VulkanInjectedDeviceCalls  injected_calls_;
    const graphics::VulkanInstanceTable* instance_table_;
    VkPhysicalDeviceMemoryProperties     memory_properties_;
    Image                                image_;

    //! Holds the pixels of the last Readback, because the staging memory goes away with the read.
    std::vector<uint8_t> pixels_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SCREENSHOT_HANDLER_H
