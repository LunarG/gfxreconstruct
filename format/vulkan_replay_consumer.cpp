/*
** Copyright (c) 2018 LunarG, Inc.
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

#include "volk.h"

#include "util/platform.h"
#include "format/vulkan_replay_consumer.h"

#include "generated/generated_decoded_struct_types.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

VulkanReplayConsumer::VulkanReplayConsumer()
{
}

VulkanReplayConsumer::~VulkanReplayConsumer()
{
}

const VkAllocationCallbacks* VulkanReplayConsumer::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    BRIMSTONE_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

VkResult VulkanReplayConsumer::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkInstance*                  pInstance)
{
    static bool initialized = false;
    if (!initialized)
    {
        volkInitialize();
        initialized = true;
    }

    VkResult result = vkCreateInstance(pCreateInfo, pAllocator, pInstance);

    if ((pInstance != nullptr) && (result == VK_SUCCESS))
    {
        volkLoadInstance(*pInstance);
    }

    return result;
}

VkResult VulkanReplayConsumer::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                                    const VkDeviceCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkDevice*                    pDevice)
{
    VkResult result = vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

    if ((pDevice != nullptr) && (result == VK_SUCCESS))
    {
        // TODO: Per-device dispatch tables.
        volkLoadDevice(*pDevice);
    }

    return result;
}

#include "generated/generated_api_call_replay_consumer_definitions.inc"

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
