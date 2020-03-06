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

VkResult VulkanRemapAllocator::AllocateMemory(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                              const VkAllocationCallbacks*                              pAllocator,
                                              HandlePointerDecoder<VkDeviceMemory>*                     pMemory)
{
    const VkMemoryAllocateInfo* capture_allocate_info = pAllocateInfo.GetPointer();
    VkMemoryAllocateInfo        replay_allocate_info  = *capture_allocate_info;

    replay_allocate_info.memoryTypeIndex = index_map_[capture_allocate_info->memoryTypeIndex];

    // TODO: Store the new memory type index in the DeviceMemoryInfo structure and add a check at buffer/image bind,
    // reporting errors when binding to incompatible memory types.

    return GetFunctions().allocate_memory(GetDevice(), &replay_allocate_info, pAllocator, pMemory->GetHandlePointer());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
