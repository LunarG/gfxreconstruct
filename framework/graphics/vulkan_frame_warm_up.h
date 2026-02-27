/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Google
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

#ifndef GFXRECON_VULKAN_FRAME_WARMUP_H
#define GFXRECON_VULKAN_FRAME_WARMUP_H

#include <vector>
#include <vulkan/vulkan.h>

#include "decode/vulkan_object_info.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Helper class to perform a "warm up" compute dispatch before replaying each frame.
// This is intended to make sure the GPU frequency is at the expected level before replaying a frame, which can be
// important for accurate performance measurements.
class VulkanFrameWarmUp
{
  public:
    VulkanFrameWarmUp(uint32_t warm_up_load) : warm_up_load_(warm_up_load) {}
    ~VulkanFrameWarmUp() = default;

    void WarmUp(VkDevice                                device,
                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                uint32_t                                queue_family_index,
                VkQueue                                 queue,
                const VulkanDeviceTable*                device_table);

  private:
    uint32_t warm_up_load_{ 0 };

    VkCommandPool            command_pool_{ VK_NULL_HANDLE };
    VkCommandBuffer          command_buffer_{ VK_NULL_HANDLE };
    VkShaderModule           shader_module_{ VK_NULL_HANDLE };
    VkDescriptorPool         descriptor_pool_{ VK_NULL_HANDLE };
    VkDescriptorSetLayout    descriptor_set_layout_{ VK_NULL_HANDLE };
    VkDescriptorSet          descriptor_set_{ VK_NULL_HANDLE };
    VkPipelineLayout         pipeline_layout_{ VK_NULL_HANDLE };
    VkPipeline               pipeline_{ VK_NULL_HANDLE };
    VkBuffer                 buffer_{ VK_NULL_HANDLE };
    VkDeviceMemory           buffer_memory_{ VK_NULL_HANDLE };
    std::vector<VkSemaphore> semaphores_;
    uint32_t                 next_semaphore_index_{ 0 };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_FRAME_WARMUP_H
