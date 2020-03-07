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
#include "decode/portability.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanRemapAllocator::Initialize(uint32_t                                api_version,
                                          VkInstance                              instance,
                                          VkPhysicalDevice                        physical_device,
                                          VkDevice                                device,
                                          const std::vector<std::string>&         enabled_device_extensions,
                                          const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                          const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                          const Functions&                        functions)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    VulkanDefaultAllocator::Initialize(api_version,
                                       instance,
                                       physical_device,
                                       device,
                                       enabled_device_extensions,
                                       capture_memory_properties,
                                       replay_memory_properties,
                                       functions);

    if (portability::CheckMemoryTypeCompatibility(capture_memory_properties, replay_memory_properties, false))
    {
        // One-to-one mapping when all memory types match.
        for (uint32_t i = 0; i < replay_memory_properties.memoryTypeCount; ++i)
        {
            index_map_.push_back(i);
        }

        result = VK_SUCCESS;
    }
    else
    {
        index_map_.resize(capture_memory_properties.memoryTypeCount);

        for (uint32_t i = 0; i < capture_memory_properties.memoryTypeCount; ++i)
        {
            index_map_[i] =
                portability::FindCompatibleMemoryType(i, capture_memory_properties, replay_memory_properties);
        }

        if (portability::CheckMemoryTypeIndexValidity(index_map_))
        {
            result = VK_SUCCESS;
        }
        else
        {
            GFXRECON_LOG_FATAL(
                "Failed to find valid memory type mappings for replay when using the \"-m remap\" option");
            GFXRECON_LOG_FATAL(
                "Try replay with rebind memory translation enabled via the \"-m rebind\" option instead");
        }
    }

    return result;
}

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
