/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REMAP_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_REMAP_ALLOCATOR_H

#include "decode/vulkan_default_allocator.h"
#include "util/defines.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanRemapAllocator : public VulkanDefaultAllocator
{
  public:
    VulkanRemapAllocator() {}

    VulkanRemapAllocator(const std::string& custom_error_string) : VulkanDefaultAllocator(custom_error_string) {}

    VulkanRemapAllocator(std::string&& custom_error_string) : VulkanDefaultAllocator(std::move(custom_error_string)) {}

    virtual VkResult Initialize(uint32_t                                api_version,
                                VkInstance                              instance,
                                VkPhysicalDevice                        physical_device,
                                VkDevice                                device,
                                const std::vector<std::string>&         enabled_device_extensions,
                                VkPhysicalDeviceType                    capture_device_type,
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) override;

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    format::HandleId             capture_id,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) override;

  private:
    std::vector<uint32_t> index_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REMAP_ALLOCATOR_H
