/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H
#define GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/vulkan_object_info_table.h"
#include "util/defines.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanBufferTracker
{
  public:
    VulkanBufferTracker(const encode::VulkanDeviceTable* device_table,
                        const PhysicalDeviceInfo*        physical_device_info,
                        VkDevice                         device,
                        VulkanResourceAllocator*         allocator);

    ~VulkanBufferTracker();

    std::vector<BufferInfo*>* GetBuffers() { return &buffers_; }

    void SetBufferInfo(BufferInfo* buffer_info);

    void UpdateBufferDeviceAddress(VkDeviceAddress& address);

    BufferInfo* GetBufferByReplayDeviceAddress(VkDeviceAddress replay_address);

    BufferInfo* GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address);

    VkDeviceAddress GetBufferDeviceAddress(VkBuffer buffer);

    void OnDestroyBuffer(const BufferInfo* buffer_info);

  private:
    void InitializeFunctionPointers(const encode::VulkanDeviceTable* device_table);
    struct Functions
    {
        PFN_vkGetBufferDeviceAddress get_buffer_device_address{ nullptr };
    };

  private:
    Functions                 functions_;
    VkDevice                  device_;
    VulkanResourceAllocator*  allocator_;
    const PhysicalDeviceInfo* physical_device_info_;
    std::vector<BufferInfo*>  buffers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_BUFFER_TRACKER_H
