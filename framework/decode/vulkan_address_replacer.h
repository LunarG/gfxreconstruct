/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H
#define GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H

#include "decode/common_object_info_table.h"
#include "graphics/vulkan_shader_group_handle.h"
#include "format/platform_types.h"
#include "vulkan_device_address_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanAddressReplacer
{
  public:
    VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                          const encode::VulkanDeviceTable*     device_table,
                          const decode::CommonObjectInfoTable& object_table);

    ~VulkanAddressReplacer();

    void ProcessCmdTraceRays(
        VkCommandBuffer                                                                             commandBuffer,
        VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
        const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
        const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map);

  private:
    const encode::VulkanDeviceTable* device_table_        = nullptr;
    bool                             valid_sbt_alignment_ = true;

    VkDevice         device_          = VK_NULL_HANDLE;
    VkPipelineLayout pipeline_layout_ = VK_NULL_HANDLE;
    VkPipeline       pipeline_        = VK_NULL_HANDLE;
};
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H
