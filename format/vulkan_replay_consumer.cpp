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

#include <cstdint>

#include "volk.h"

#include "util/logging.h"
#include "util/platform.h"
#include "format/vulkan_enum_util.h"
#include "format/vulkan_replay_consumer.h"

#include "generated/generated_decoded_struct_types.inc"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

const uint32_t kDefaultWindowWidth = 320;
const uint32_t kDefaultWindowHeight = 240;

VulkanReplayConsumer::VulkanReplayConsumer(WindowFactory* window_factory) : window_factory_(window_factory)
{
    assert(window_factory != nullptr);
}

VulkanReplayConsumer::~VulkanReplayConsumer()
{
}

void VulkanReplayConsumer::ProcessDisplayMessageCommand(const std::string& message)
{
    BRIMSTONE_LOG_INFO("Trace Message: %s", message.c_str());
}

void VulkanReplayConsumer::ProcessFillMemoryCommand(uint64_t       pointer_id,
                                                    uint64_t       offset,
                                                    uint64_t       size,
                                                    const uint8_t* data)
{
    auto entry = pointer_map_.find(pointer_id);

    if ((entry != pointer_map_.end()) && (entry->second != nullptr))
    {
        memcpy(static_cast<uint8_t*>(entry->second) + offset, data, size);
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping memory fill for unrecognized mapped pointer (%" PRIx64 ")", pointer_id);
    }
}

void VulkanReplayConsumer::ProcessResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    VkSurfaceKHR surface = object_mapper_.MapVkSurfaceKHR(surface_id);

    if (surface != VK_NULL_HANDLE)
    {
        auto entry = window_map_.find(surface);

        if ((entry != window_map_.end()) && (entry->second != nullptr))
        {
            Window* window = entry->second;
            window->SetSize(width, height);
        }
        else
        {
            BRIMSTONE_LOG_WARNING(
                "Skipping window resize for VkSurface object (%" PRIx64 ") without an associated window", surface_id);
        }
    }
}

void VulkanReplayConsumer::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void* VulkanReplayConsumer::ProcessExternalObject(uint64_t object_id, ApiCallId call_id, const char* call_name)
{
    void* object = nullptr;

    if ((call_id == ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR) ||
        (call_id == ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR))
    {
        // For window system related handles, we put the object ID into the pointer.
        // The dispatch override for the API call will use this ID as a key to the window map.
        // TODO: For x86 builds, we should map the object_id to a 32-bit sequence number that won't be truncated by the cast.
        object = reinterpret_cast<void*>(object_id);
    }
    else
    {
        BRIMSTONE_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                              call_name);
    }

    return object;
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

VkResult VulkanReplayConsumer::OverrideCreateWin32SurfaceKHR(VkInstance                         instance,
                                                             const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*       pAllocator,
                                                             VkSurfaceKHR*                      pSurface)
{
    // Create a window for our surface.
    Window* window = window_factory_->Create(kDefaultWindowWidth, kDefaultWindowWidth);

    if (window == nullptr)
    {
        // Failure to create a window is a fatal error.
        BRIMSTONE_LOG_FATAL("Failed to create a window for use with vkCreateWin32SurfaceKHR.  Replay cannot continue.");
        RaiseFatalError("Replay has encountered a fatal error and cannot continue (window creation failed)");
    }

    VkResult result = window->CreateSurface(instance, pCreateInfo->flags, pSurface);

    if ((result == VK_SUCCESS) && (pSurface != nullptr))
    {
        VkSurfaceKHR key = (*pSurface);

        assert(window_map_.find(key) == window_map_.end());

        window_map_.insert(std::make_pair(key, window));
    }

    return result;
}

VkBool32 VulkanReplayConsumer::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice,
                                                                                    uint32_t         queueFamilyIndex)
{
    return window_factory_->GetPhysicalDevicePresentationSupport(physicalDevice, queueFamilyIndex);
}


#include "generated/generated_api_call_replay_consumer_definitions.inc"

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
