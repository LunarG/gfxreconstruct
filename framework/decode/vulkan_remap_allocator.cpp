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

#include "decode/vulkan_remap_allocator.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanRemapAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                              const VkAllocationCallbacks* allocation_callbacks,
                                              VkDeviceMemory*              memory,
                                              MemoryData*                  allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (allocate_info != nullptr)
    {
        VkMemoryAllocateInfo replay_allocate_info = *allocate_info;

        replay_allocate_info.memoryTypeIndex = index_map_[allocate_info->memoryTypeIndex];

        result =
            VulkanDefaultAllocator::AllocateMemory(&replay_allocate_info, allocation_callbacks, memory, allocator_data);
    }

    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
