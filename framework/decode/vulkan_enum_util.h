/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_ENUM_UTIL_H
#define GFXRECON_DECODE_VULKAN_ENUM_UTIL_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(enumutil)

/**
 * Get VkResult code description.
 *
 * Returns a string describing the specified VkResult code.  The description is based on the language in the Vulkan API
 * specification.
 *
 * @param value VkResult code to process.
 * @return String describing the specified VkResult code.
 */
inline const char* GetResultDescription(VkResult result)
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
        case VK_ERROR_UNKNOWN:                  return "An unknown error has occurred; either the application has provided "
                                                       "invalid input, or an implementation failure has occurred.";
        case VK_ERROR_OUT_OF_POOL_MEMORY:       return "a pool memory allocation has failed";
        case VK_ERROR_INVALID_EXTERNAL_HANDLE:  return "an external handle is not a valid handle of the specified type";
        case VK_ERROR_FRAGMENTATION:            return "A descriptor pool creation has failed due to fragmentation";
        case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: return "A buffer creation or memory allocation failed because the requested " 
                                                             "address is not available. A shader group handle assignment failed "
                                                             "because the requested shader group handle information is no longer valid.";
        case VK_PIPELINE_COMPILE_REQUIRED:      return "A requested pipeline creation would have required compilation, "
                                                       "but the application requested compilation to not be performed.";
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
        case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return "VkImageDrmFormatModifierExplicitCreateInfoEXT info can't pass the validation.";
        case VK_ERROR_NOT_PERMITTED_KHR:        return "an operation is not permitted";
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: return "An operation on a swapchain created with "
                                                                  "VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT failed as it did "
                                                                  "not have exlusive full-screen access. This may occur due to "
                                                                  "implementation-dependent reasons, outside of the application's control.";
        case VK_THREAD_IDLE_KHR:                return "A deferred operation is not complete but there is currently no work "
                                                       "for this thread to do at the time of this call.";
        case VK_THREAD_DONE_KHR:                return "A deferred operation is not complete but there is no work remaining "
                                                       "to assign to additional threads.";
        case VK_OPERATION_DEFERRED_KHR:         return "A deferred operation was requested and at least some of the work was deferred.";
        case VK_OPERATION_NOT_DEFERRED_KHR:     return "A deferred operation was requested and no operations were deferred.";
        default:                                return "an error has occurred";
    }
    // clang-format on
}

GFXRECON_END_NAMESPACE(enumutil)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ENUM_UTIL_H
