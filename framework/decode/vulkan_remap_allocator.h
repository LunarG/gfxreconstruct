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
    VulkanRemapAllocator(const std::vector<uint32_t>& index_map) : index_map_(index_map) {}

    VulkanRemapAllocator(std::vector<uint32_t>&& index_map) : index_map_(std::move(index_map)) {}

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) override;

  private:
    std::vector<uint32_t> index_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REMAP_ALLOCATOR_H
