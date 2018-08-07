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

#include "util/logging.h"
#include "util/platform.h"
#include "format/vulkan_enum_util.h"
#include "format/vulkan_replay_consumer.h"

#include "generated/generated_decoded_struct_types.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

VulkanReplayConsumer::VulkanReplayConsumer() {}

VulkanReplayConsumer::~VulkanReplayConsumer() {}

void VulkanReplayConsumer::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided.
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

const VkAllocationCallbacks* VulkanReplayConsumer::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    BRIMSTONE_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

void VulkanReplayConsumer::CheckResult(const char* func_name, VkResult original, VkResult replay)
{
    if ((original != VK_ERROR_DEVICE_LOST) && (replay == VK_ERROR_DEVICE_LOST))
    {
        // Only raise a fatal error if the device lost error is unique to playback.  If the original application
        // also encountered a device lost error, it may have handled it and continued.
        BRIMSTONE_LOG_FATAL("API call (%s) returned VK_ERROR_DEVICE_LOST.  Replay cannot continue.", func_name);
        RaiseFatalError(
            "Replay has encountered a fatal error and cannot continue (API call returned VK_ERROR_DEVICE_LOST)");
    }
    else
    {
        // Report error when replay result is different than the original result.
        if (original != replay)
        {
            BRIMSTONE_LOG_ERROR("API call (%s) returned value %s that does not match return value from trace file %s.",
                                func_name,
                                enumutil::GetResultValueString(replay),
                                enumutil::GetResultValueString(original));
        }

        // Warn when an API call returned a failure, regardless of original result (excluding fromat not supported results).
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            BRIMSTONE_LOG_WARNING("API call (%s) returned error result %s: %s",
                                  func_name,
                                  enumutil::GetResultValueString(replay),
                                  enumutil::GetResultDescription(replay));
        }
    }
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
