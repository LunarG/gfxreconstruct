/*
** Copyright (c) 2018 Valve Corporation
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

#ifndef GFXRECON_DECODE_VULKAN_ENUM_UTIL_H
#define GFXRECON_DECODE_VULKAN_ENUM_UTIL_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(enumutil)

static const char* GetResultValueString(VkResult result)
{
    // clang-format off
    switch (result)
    {
        case VK_SUCCESS:                        return GFXRECON_STR(VK_SUCCESS);
        case VK_NOT_READY:                      return GFXRECON_STR(VK_NOT_READY);
        case VK_TIMEOUT:                        return GFXRECON_STR(VK_TIMEOUT);
        case VK_EVENT_SET:                      return GFXRECON_STR(VK_EVENT_SET);
        case VK_EVENT_RESET:                    return GFXRECON_STR(VK_EVENT_RESET);
        case VK_INCOMPLETE:                     return GFXRECON_STR(VK_INCOMPLETE);
        case VK_ERROR_OUT_OF_HOST_MEMORY:       return GFXRECON_STR(VK_ERROR_OUT_OF_HOST_MEMORY);
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:     return GFXRECON_STR(VK_ERROR_OUT_OF_DEVICE_MEMORY);
        case VK_ERROR_INITIALIZATION_FAILED:    return GFXRECON_STR(VK_ERROR_INITIALIZATION_FAILED);
        case VK_ERROR_DEVICE_LOST:              return GFXRECON_STR(VK_ERROR_DEVICE_LOST);
        case VK_ERROR_MEMORY_MAP_FAILED:        return GFXRECON_STR(VK_ERROR_MEMORY_MAP_FAILED);
        case VK_ERROR_LAYER_NOT_PRESENT:        return GFXRECON_STR(VK_ERROR_LAYER_NOT_PRESENT);
        case VK_ERROR_EXTENSION_NOT_PRESENT:    return GFXRECON_STR(VK_ERROR_EXTENSION_NOT_PRESENT);
        case VK_ERROR_FEATURE_NOT_PRESENT:      return GFXRECON_STR(VK_ERROR_FEATURE_NOT_PRESENT);
        case VK_ERROR_INCOMPATIBLE_DRIVER:      return GFXRECON_STR(VK_ERROR_INCOMPATIBLE_DRIVER);
        case VK_ERROR_TOO_MANY_OBJECTS:         return GFXRECON_STR(VK_ERROR_TOO_MANY_OBJECTS);
        case VK_ERROR_FORMAT_NOT_SUPPORTED:     return GFXRECON_STR(VK_ERROR_FORMAT_NOT_SUPPORTED);
        case VK_ERROR_FRAGMENTED_POOL:          return GFXRECON_STR(VK_ERROR_FRAGMENTED_POOL);
        case VK_ERROR_OUT_OF_POOL_MEMORY:       return GFXRECON_STR(VK_ERROR_OUT_OF_POOL_MEMORY);
        case VK_ERROR_INVALID_EXTERNAL_HANDLE:  return GFXRECON_STR(VK_ERROR_INVALID_EXTERNAL_HANDLE);
        case VK_ERROR_SURFACE_LOST_KHR:         return GFXRECON_STR(VK_ERROR_SURFACE_LOST_KHR);
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return GFXRECON_STR(VK_ERROR_NATIVE_WINDOW_IN_USE_KHR);
        case VK_SUBOPTIMAL_KHR:                 return GFXRECON_STR(VK_SUBOPTIMAL_KHR);
        case VK_ERROR_OUT_OF_DATE_KHR:          return GFXRECON_STR(VK_ERROR_OUT_OF_DATE_KHR);
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return GFXRECON_STR(VK_ERROR_INCOMPATIBLE_DISPLAY_KHR);
        case VK_ERROR_VALIDATION_FAILED_EXT:    return GFXRECON_STR(VK_ERROR_VALIDATION_FAILED_EXT);
        case VK_ERROR_INVALID_SHADER_NV:        return GFXRECON_STR(VK_ERROR_INVALID_SHADER_NV);
        case VK_ERROR_FRAGMENTATION_EXT:        return GFXRECON_STR(VK_ERROR_FRAGMENTATION_EXT);
        case VK_ERROR_NOT_PERMITTED_EXT:        return GFXRECON_STR(VK_ERROR_NOT_PERMITTED_EXT);
        default:                                return "(Unrecognized VkResult Value)";
    }
    // clang-format on
}

/**
 * Get VkResult code description.
 *
 * Returns a string describing the specified VkResult code.  The description is based on the language in the Vulkan API
 * specification.
 *
 * @param value VkResult code to process.
 * @return String describing the specified VkResult code.
 */
static const char* GetResultDescription(VkResult result)
{
    // clang-format off
    switch (result)
    {
        case VK_SUCCESS:                        return "a command completed successfully";
        case VK_NOT_READY:                      return "a fence or query has not yet completed";
        case VK_TIMEOUT:                        return "a wait operation has not completed in the specified time";
        case VK_EVENT_SET:                      return "an event is signaled";
        case VK_EVENT_RESET:                    return "an event is unsignalled";
        case VK_INCOMPLETE:                     return "a return array was too small for the result";
        case VK_ERROR_OUT_OF_HOST_MEMORY:       return "a host memory allocation has failed";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:     return "a device memory allocation has failed";
        case VK_ERROR_INITIALIZATION_FAILED:    return "initialization of an object has failed";
        case VK_ERROR_DEVICE_LOST:              return "the logical device has been lost";
        case VK_ERROR_MEMORY_MAP_FAILED:        return "mapping of a memory object has failed";
        case VK_ERROR_LAYER_NOT_PRESENT:        return "the specified layer does not exist";
        case VK_ERROR_EXTENSION_NOT_PRESENT:    return "the specified extension does not exist";
        case VK_ERROR_FEATURE_NOT_PRESENT:      return "the requested feature is not available on this device";
        case VK_ERROR_INCOMPATIBLE_DRIVER:      return "a Vulkan driver could not be found";
        case VK_ERROR_TOO_MANY_OBJECTS:         return "too many objects of the type have already been created";
        case VK_ERROR_FORMAT_NOT_SUPPORTED:     return "the requested format is not supported on this device";
        case VK_ERROR_FRAGMENTED_POOL:          return "a pool allocation has failed due to fragmentation of the pool's memory";
        case VK_ERROR_OUT_OF_POOL_MEMORY:       return "a pool memory allocation has failed";
        case VK_ERROR_INVALID_EXTERNAL_HANDLE:  return "an external handle is not a valid handle of the specified type";
        case VK_ERROR_SURFACE_LOST_KHR:         return "a surface is no longer available";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "the requested window is already connected to another "
                                                       "VkSurfaceKHR object, or some other non-Vulkan surface object";
        case VK_SUBOPTIMAL_KHR:                 return "an image became available, and the swapchain no longer "
                                                       "matches the surface properties exactly, but can still be used to "
                                                       "present to the surface successfully.";
        case VK_ERROR_OUT_OF_DATE_KHR:          return "a surface has changed in such a way that it is no "
                                                       "longer compatible with the swapchain";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "the display used by a swapchain does not use the same "
                                                       "presentable image layout, or is incompatible in a way that prevents "
                                                       "sharing an image";
        case VK_ERROR_VALIDATION_FAILED_EXT:    return "API validation has detected an invalid use of the API";
        case VK_ERROR_INVALID_SHADER_NV:        return "one or more shaders failed to compile or link";
        case VK_ERROR_FRAGMENTATION_EXT:        return "A descriptor pool creation has failed due to fragmentation";
        case VK_ERROR_NOT_PERMITTED_EXT:        return "an operation is not permitted";
        default:                                return "an error has occurred";
    }
    // clang-format on
}

GFXRECON_END_NAMESPACE(enumutil)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ENUM_UTIL_H
