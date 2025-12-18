/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_DISPATCH_TABLE_H
#define  GFXRECON_GENERATED_VULKAN_DISPATCH_TABLE_H

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vk_layer.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

typedef const void* VulkanDispatchKey;

// Retrieve a dispatch key from a dispatchable handle
static VulkanDispatchKey GetVulkanDispatchKey(const void* handle)
{
    const VulkanDispatchKey* dispatch_key = reinterpret_cast<const VulkanDispatchKey*>(handle);
    return (*dispatch_key);
}

GFXRECON_BEGIN_NAMESPACE(noop)
// clang-format off
inline VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyInstance was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance, uint32_t*, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDevices was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(VkPhysicalDevice, VkPhysicalDeviceFeatures*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice, VkFormat, VkFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(VkPhysicalDevice, VkPhysicalDeviceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetInstanceProcAddr was called, resulting in no-op behavior."); return nullptr; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumerateDeviceExtensionProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice, uint32_t*, VkLayerProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumerateDeviceLayerProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceGroups was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalBufferProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalFenceProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalSemaphoreProperties was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolProperties(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceToolProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySurfaceKHR(VkInstance, VkSurfaceKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySurfaceKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice, uint32_t, VkSurfaceKHR, VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceSupportKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkSurfaceFormatKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceFormatsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDevicePresentRectanglesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPlanePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPlanePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneSupportedDisplaysKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModePropertiesKHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayModePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayModeKHR(VkPhysicalDevice, VkDisplayKHR, const VkDisplayModeCreateInfoKHR*, const VkAllocationCallbacks*, VkDisplayModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDisplayModeKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice, VkDisplayModeKHR, uint32_t, VkDisplayPlaneCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayPlaneSurfaceKHR(VkInstance, const VkDisplaySurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDisplayPlaneSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance, const VkXlibSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateXlibSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice, uint32_t, Display*, VisualID) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceXlibPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance, const VkXcbSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateXcbSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice, uint32_t, xcb_connection_t*, xcb_visualid_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceXcbPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateWaylandSurfaceKHR(VkInstance, const VkWaylandSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateWaylandSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice, uint32_t, struct wl_display*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceWaylandPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateAndroidSurfaceKHR(VkInstance, const VkAndroidSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAndroidSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(VkInstance, const VkWin32SurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateWin32SurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceWin32PresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice, const VkVideoProfileInfoKHR*, VkVideoCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR*, uint32_t*, VkVideoFormatPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoFormatPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroupsKHR(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceGroupsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalBufferPropertiesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalSemaphorePropertiesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalFencePropertiesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkPerformanceCounterKHR*, VkPerformanceCounterDescriptionKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice, const VkQueryPoolPerformanceCreateInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkSurfaceCapabilities2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkSurfaceFormat2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceFormats2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayPlaneProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPlaneProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModeProperties2KHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModeProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayModeProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice, const VkDisplayPlaneInfo2KHR*, VkDisplayPlaneCapabilities2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceFragmentShadingRateKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFragmentShadingRatesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*, VkVideoEncodeQualityLevelPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice, uint32_t*, VkTimeDomainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCalibrateableTimeDomainsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(VkInstance, const VkDebugReportCallbackCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugReportCallbackEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDebugReportCallbackEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackEXT(VkInstance, VkDebugReportCallbackEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDebugReportCallbackEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkDebugReportMessageEXT(VkInstance, VkDebugReportFlagsEXT, VkDebugReportObjectTypeEXT, uint64_t, size_t, int32_t, const char*, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugReportMessageEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateStreamDescriptorSurfaceGGP(VkInstance, const VkStreamDescriptorSurfaceCreateInfoGGP*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateStreamDescriptorSurfaceGGP was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkExternalMemoryHandleTypeFlagsNV, VkExternalImageFormatPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalImageFormatPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateViSurfaceNN(VkInstance, const VkViSurfaceCreateInfoNN*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateViSurfaceNN was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleaseDisplayEXT(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireXlibDisplayEXT(VkPhysicalDevice, Display*, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireXlibDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetRandROutputDisplayEXT(VkPhysicalDevice, Display*, RROutput, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRandROutputDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilities2EXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(VkInstance, const VkIOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateMacOSSurfaceMVK(VkInstance, const VkMacOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMacOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice, const VkDebugUtilsObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDebugUtilsObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice, const VkDebugUtilsObjectTagInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDebugUtilsObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance, const VkDebugUtilsMessengerCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugUtilsMessengerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(VkInstance, VkDebugUtilsMessengerEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDebugUtilsMessengerEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(VkInstance, VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSubmitDebugUtilsMessageEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice, VkSampleCountFlagBits, VkMultisamplePropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMultisamplePropertiesEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice, uint32_t*, VkTimeDomainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCalibrateableTimeDomainsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(VkInstance, const VkImagePipeSurfaceCreateInfoFUCHSIA*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImagePipeSurfaceFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(VkInstance, const VkMetalSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMetalSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceToolPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeMatrixPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice, uint32_t*, VkFramebufferMixedSamplesCombinationNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateHeadlessSurfaceEXT(VkInstance, const VkHeadlessSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateHeadlessSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireDrmDisplayEXT(VkPhysicalDevice, int32_t, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDrmDisplayEXT(VkPhysicalDevice, int32_t, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(VkPhysicalDevice, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDirectFBSurfaceEXT(VkInstance, const VkDirectFBSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDirectFBSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice, uint32_t, IDirectFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDirectFBPresentationSupportEXT was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(VkInstance, const VkScreenSurfaceCreateInfoQNX*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateScreenSurfaceQNX was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice, uint32_t, struct _screen_window*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceScreenPresentationSupportQNX was called, resulting in no-op behavior."); return VK_TRUE; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice, const VkOpticalFlowImageFormatInfoNV*, uint32_t*, VkOpticalFlowImageFormatPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceOpticalFlowImageFormatsNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice, uint32_t*, VkCooperativeVectorPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeVectorPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice, uint32_t, uint32_t*, VkQueueFamilyDataGraphPropertiesARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*, VkQueueFamilyDataGraphProcessingEnginePropertiesARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixFlexibleDimensionsPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(VkPhysicalDevice, uint32_t, uint32_t*, VkPerformanceCounterARM*, VkPerformanceCounterDescriptionARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceProcAddr was called, resulting in no-op behavior."); return nullptr; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(VkDevice, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDevice was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(VkDevice, uint32_t, uint32_t, VkQueue*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceQueue was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(VkQueue, uint32_t, const VkSubmitInfo*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDeviceWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkFreeMemory(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeMemory was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMapMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(VkDevice, VkDeviceMemory) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUnmapMemory was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFlushMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkInvalidateMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice, VkDeviceMemory, VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryCommitment was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice, VkBuffer, VkMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice, VkImage, VkMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueBindSparse was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateFence was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyFence(VkDevice, VkFence, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyFence was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(VkDevice, uint32_t, const VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(VkDevice, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitForFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySemaphore(VkDevice, VkSemaphore, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySemaphore was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateQueryPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyQueryPool(VkDevice, VkQueryPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyQueryPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueryPoolResults was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateBuffer(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyBuffer(VkDevice, VkBuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImage was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyImage(VkDevice, VkImage, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImageView was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyImageView(VkDevice, VkImageView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyImageView was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyCommandPool(VkDevice, VkCommandPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyCommandPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandPool(VkDevice, VkCommandPool, VkCommandPoolResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateCommandBuffers was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkFreeCommandBuffers(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeCommandBuffers was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer, const VkCommandBufferBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBeginCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEndCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer, VkCommandBufferResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdUpdateBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdUpdateBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdFillBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdFillBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginQuery was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndQuery was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetQueryPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyQueryPoolResults was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdExecuteCommands was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateEvent(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyEvent(VkDevice, VkEvent, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyEvent was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetEventStatus(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetEventStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkResetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferView(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateBufferView was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyBufferView(VkDevice, VkBufferView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyBufferView was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateShaderModule was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyShaderModule(VkDevice, VkShaderModule, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyShaderModule was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePipelineCache was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineCache(VkDevice, VkPipelineCache, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipelineCache was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice, VkPipelineCache, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineCacheData was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMergePipelineCaches was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateComputePipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPipeline(VkDevice, VkPipeline, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipeline was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePipelineLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineLayout(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipelineLayout was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSampler was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySampler(VkDevice, VkSampler, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySampler was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorSetLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorSetLayout was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorPool(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSets(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSets was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindPipeline was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorSets was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearColorImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatch(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatch was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchIndirect was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushConstants was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateGraphicsPipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateFramebuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyFramebuffer(VkDevice, VkFramebuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyFramebuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyRenderPass(VkDevice, VkRenderPass, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyRenderPass was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice, VkRenderPass, VkExtent2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRenderAreaGranularity was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewport was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissor was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineWidth was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer, float, float, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBias was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer, const float[4]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetBlendConstants was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer, float, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBounds was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilCompareMask was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilWriteMask was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilReference was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindIndexBuffer was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDraw(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDraw was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexed was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirect was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirect was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearDepthStencilImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearAttachments was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer, VkSubpassContents) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPeerMemoryFeatures was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMask(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDeviceMask was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkTrimCommandPool(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTrimCommandPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue2(VkDevice, const VkDeviceQueueInfo2*, VkQueue*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceQueue2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBase(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchBase was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorUpdateTemplate was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorUpdateTemplate was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSetWithTemplate was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupport(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutSupport was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSamplerYcbcrConversion was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversion(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySamplerYcbcrConversion was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkResetQueryPool(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetQueryPool was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValue(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreCounterValue was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphores(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitSemaphores was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphore(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSignalSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddress was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCount was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCount was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlot(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePrivateDataSlot was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlot(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPrivateDataSlot was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetPrivateData was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPrivateData was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceBufferMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginRendering(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRendering was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRendering was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCullMode(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCullMode was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFace(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFrontFace was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopology(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveTopology was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCount(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWithCount was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCount(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissorWithCount was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthTestEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthWriteEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOp(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthCompareOp was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBoundsTestEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilTestEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOp(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilOp was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizerDiscardEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBiasEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveRestartEnable was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2(VkDevice, const VkMemoryMapInfo*, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMapMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2(VkDevice, const VkMemoryUnmapInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUnmapMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayout(VkDevice, const VkDeviceImageSubresourceInfo*, VkSubresourceLayout2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSubresourceLayout was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2(VkDevice, VkImage, const VkImageSubresource2*, VkSubresourceLayout2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImage(VkDevice, const VkCopyMemoryToImageInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToImage was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemory(VkDevice, const VkCopyImageToMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImage(VkDevice, const VkCopyImageToImageInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToImage was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayout(VkDevice, uint32_t, const VkHostImageLayoutTransitionInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTransitionImageLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkWriteDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSet was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer, VkDescriptorUpdateTemplate, VkPipelineLayout, uint32_t, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplate was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2(VkCommandBuffer, const VkBindDescriptorSetsInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorSets2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2(VkCommandBuffer, const VkPushConstantsInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushConstants2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2(VkCommandBuffer, const VkPushDescriptorSetInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSet2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2(VkCommandBuffer, const VkPushDescriptorSetWithTemplateInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplate2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStipple(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStipple was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindIndexBuffer2 was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularity(VkDevice, const VkRenderingAreaInfo*, VkExtent2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRenderingAreaGranularity was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocations(VkCommandBuffer, const VkRenderingAttachmentLocationInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingAttachmentLocations was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndices(VkCommandBuffer, const VkRenderingInputAttachmentIndexInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingInputAttachmentIndices was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSwapchainKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(VkDevice, VkSwapchainKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySwapchainKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice, VkSwapchainKHR, uint32_t*, VkImage*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainImagesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImageKHR(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireNextImageKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(VkQueue, const VkPresentInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueuePresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice, VkDeviceGroupPresentCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPresentCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(VkDevice, VkSurfaceKHR, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImage2KHR(VkDevice, const VkAcquireNextImageInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireNextImage2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(VkDevice, uint32_t, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSharedSwapchainsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionKHR(VkDevice, const VkVideoSessionCreateInfoKHR*, const VkAllocationCallbacks*, VkVideoSessionKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateVideoSessionKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionKHR(VkDevice, VkVideoSessionKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyVideoSessionKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(VkDevice, VkVideoSessionKHR, uint32_t*, VkVideoSessionMemoryRequirementsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetVideoSessionMemoryRequirementsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(VkDevice, VkVideoSessionKHR, uint32_t, const VkBindVideoSessionMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindVideoSessionMemoryKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(VkDevice, const VkVideoSessionParametersCreateInfoKHR*, const VkAllocationCallbacks*, VkVideoSessionParametersKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(VkDevice, VkVideoSessionParametersKHR, const VkVideoSessionParametersUpdateInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionParametersKHR(VkDevice, VkVideoSessionParametersKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyVideoSessionParametersKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginVideoCodingKHR(VkCommandBuffer, const VkVideoBeginCodingInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginVideoCodingKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndVideoCodingKHR(VkCommandBuffer, const VkVideoEndCodingInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndVideoCodingKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdControlVideoCodingKHR(VkCommandBuffer, const VkVideoCodingControlInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdControlVideoCodingKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDecodeVideoKHR(VkCommandBuffer, const VkVideoDecodeInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDecodeVideoKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderingKHR(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderingKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderingKHR(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderingKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPeerMemoryFeaturesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMaskKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDeviceMaskKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBaseKHR(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchBaseKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkTrimCommandPoolKHR(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTrimCommandPoolKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(VkDevice, const VkMemoryGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, HANDLE, VkMemoryWin32HandlePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandlePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdKHR(VkDevice, const VkMemoryGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, int, VkMemoryFdPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryFdPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(VkDevice, const VkImportSemaphoreWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(VkDevice, const VkSemaphoreGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreFdKHR(VkDevice, const VkImportSemaphoreFdInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreFdKHR(VkDevice, const VkSemaphoreGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetKHR(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkWriteDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer, VkDescriptorUpdateTemplate, VkPipelineLayout, uint32_t, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2KHR(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2KHR(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2KHR(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2KHR(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainStatusKHR(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainStatusKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(VkDevice, const VkImportFenceWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(VkDevice, const VkFenceGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceFdKHR(VkDevice, const VkImportFenceFdInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceFdKHR(VkDevice, const VkFenceGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireProfilingLockKHR(VkDevice, const VkAcquireProfilingLockInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireProfilingLockKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkReleaseProfilingLockKHR(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseProfilingLockKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2KHR(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSamplerYcbcrConversionKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySamplerYcbcrConversionKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2KHR(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2KHR(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutSupportKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCountKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCountKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreCounterValueKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphoresKHR(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitSemaphoresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphoreKHR(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSignalSemaphoreKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateKHR(VkCommandBuffer, const VkExtent2D*, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFragmentShadingRateKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer, const VkRenderingAttachmentLocationInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingAttachmentLocationsKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer, const VkRenderingInputAttachmentIndexInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingInputAttachmentIndicesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresentKHR(VkDevice, VkSwapchainKHR, uint64_t, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitForPresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDeferredOperationKHR(VkDevice, const VkAllocationCallbacks*, VkDeferredOperationKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDeferredOperationKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDeferredOperationKHR(VkDevice, VkDeferredOperationKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDeferredOperationKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeferredOperationMaxConcurrencyKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeferredOperationResultKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkDeferredOperationJoinKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDeferredOperationJoinKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(VkDevice, const VkPipelineInfoKHR*, uint32_t*, VkPipelineExecutablePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutablePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableStatisticKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutableStatisticsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableInternalRepresentationKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutableInternalRepresentationsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2KHR(VkDevice, const VkMemoryMapInfo*, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMapMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2KHR(VkDevice, const VkMemoryUnmapInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUnmapMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetEncodedVideoSessionParametersKHR(VkDevice, const VkVideoEncodeSessionParametersGetInfoKHR*, VkVideoEncodeSessionParametersFeedbackInfoKHR*, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetEncodedVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEncodeVideoKHR(VkCommandBuffer, const VkVideoEncodeInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEncodeVideoKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2KHR(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2KHR(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2KHR(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2KHR(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2KHR(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2KHR(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2KHR(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2KHR(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2KHR(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2KHR(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2KHR(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2KHR(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirect2KHR(VkCommandBuffer, VkDeviceAddress) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysIndirect2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceBufferMemoryRequirementsKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageMemoryRequirementsKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSparseMemoryRequirementsKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2KHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindIndexBuffer2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularityKHR(VkDevice, const VkRenderingAreaInfo*, VkExtent2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRenderingAreaGranularityKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayoutKHR(VkDevice, const VkDeviceImageSubresourceInfo*, VkSubresourceLayout2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSubresourceLayoutKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2KHR(VkDevice, VkImage, const VkImageSubresource2*, VkSubresourceLayout2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresent2KHR(VkDevice, VkSwapchainKHR, const VkPresentWait2InfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitForPresent2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineBinariesKHR(VkDevice, const VkPipelineBinaryCreateInfoKHR*, const VkAllocationCallbacks*, VkPipelineBinaryHandlesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePipelineBinariesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineBinaryKHR(VkDevice, VkPipelineBinaryKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipelineBinaryKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineKeyKHR(VkDevice, const VkPipelineCreateInfoKHR*, VkPipelineBinaryKeyKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineKeyKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineBinaryDataKHR(VkDevice, const VkPipelineBinaryDataInfoKHR*, VkPipelineBinaryKeyKHR*, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineBinaryDataKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleaseCapturedPipelineDataKHR(VkDevice, const VkReleaseCapturedPipelineDataInfoKHR*, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseCapturedPipelineDataKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesKHR(VkDevice, const VkReleaseSwapchainImagesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseSwapchainImagesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleKHR(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsKHR(VkDevice, uint32_t, const VkCalibratedTimestampInfoKHR*, uint64_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetCalibratedTimestampsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2KHR(VkCommandBuffer, const VkBindDescriptorSetsInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorSets2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2KHR(VkCommandBuffer, const VkPushConstantsInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushConstants2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2KHR(VkCommandBuffer, const VkPushDescriptorSetInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSet2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer, const VkPushDescriptorSetWithTemplateInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplate2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDescriptorBufferOffsets2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorBufferEmbeddedSamplers2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectKHR(VkCommandBuffer, const VkCopyMemoryIndirectInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryIndirectKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectKHR(VkCommandBuffer, const VkCopyMemoryToImageIndirectInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryToImageIndirectKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2KHR(VkCommandBuffer, const VkRenderingEndInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRendering2KHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkFrameBoundaryANDROID(VkDevice, VkSemaphore, VkImage) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFrameBoundaryANDROID was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice, const VkDebugMarkerObjectTagInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugMarkerSetObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice, const VkDebugMarkerObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugMarkerSetObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerBeginEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerEndEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerInsertEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindTransformFeedbackBuffersEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginTransformFeedbackEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndTransformFeedbackEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginQueryIndexedEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndQueryIndexedEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCountEXT(VkCommandBuffer, uint32_t, uint32_t, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectByteCountEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR uint32_t VKAPI_CALL vkGetImageViewHandleNVX(VkDevice, const VkImageViewHandleInfoNVX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewHandleNVX was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR uint64_t VKAPI_CALL vkGetImageViewHandle64NVX(VkDevice, const VkImageViewHandleInfoNVX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewHandle64NVX was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewAddressNVX(VkDevice, VkImageView, VkImageViewAddressPropertiesNVX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewAddressNVX was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCountAMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCountAMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInfoAMD(VkDevice, VkPipeline, VkShaderStageFlagBits, VkShaderInfoTypeAMD, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderInfoAMD was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(VkDevice, VkDeviceMemory, VkExternalMemoryHandleTypeFlagsNV, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRenderingEXT(VkCommandBuffer, const VkConditionalRenderingBeginInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginConditionalRenderingEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndConditionalRenderingEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndConditionalRenderingEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingNV(VkCommandBuffer, uint32_t, uint32_t, const VkViewportWScalingNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWScalingNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkDisplayPowerControlEXT(VkDevice, VkDisplayKHR, const VkDisplayPowerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDisplayPowerControlEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDeviceEventEXT(VkDevice, const VkDeviceEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkRegisterDeviceEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDisplayEventEXT(VkDevice, VkDisplayKHR, const VkDisplayEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkRegisterDisplayEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainCounterEXT(VkDevice, VkSwapchainKHR, VkSurfaceCounterFlagBitsEXT, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainCounterEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(VkDevice, VkSwapchainKHR, VkRefreshCycleDurationGOOGLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRefreshCycleDurationGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(VkDevice, VkSwapchainKHR, uint32_t*, VkPastPresentationTimingGOOGLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPastPresentationTimingGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEXT(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer, VkDiscardRectangleModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkSetHdrMetadataEXT(VkDevice, uint32_t, const VkSwapchainKHR*, const VkHdrMetadataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetHdrMetadataEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(VkQueue) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice, const struct AHardwareBuffer*, VkAndroidHardwareBufferPropertiesANDROID*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAndroidHardwareBufferPropertiesANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryAndroidHardwareBufferANDROID(VkDevice, const VkMemoryGetAndroidHardwareBufferInfoANDROID*, struct AHardwareBuffer**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryAndroidHardwareBufferANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEXT(VkCommandBuffer, const VkSampleLocationsInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleLocationsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(VkDevice, VkImage, VkImageDrmFormatModifierPropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageDrmFormatModifierPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateValidationCacheEXT(VkDevice, const VkValidationCacheCreateInfoEXT*, const VkAllocationCallbacks*, VkValidationCacheEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateValidationCacheEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyValidationCacheEXT(VkDevice, VkValidationCacheEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyValidationCacheEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkMergeValidationCachesEXT(VkDevice, VkValidationCacheEXT, uint32_t, const VkValidationCacheEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMergeValidationCachesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetValidationCacheDataEXT(VkDevice, VkValidationCacheEXT, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetValidationCacheDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindShadingRateImageNV(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindShadingRateImageNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer, uint32_t, uint32_t, const VkShadingRatePaletteNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportShadingRatePaletteNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoarseSampleOrderNV(VkCommandBuffer, VkCoarseSampleOrderTypeNV, uint32_t, const VkCoarseSampleOrderCustomNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoarseSampleOrderNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureNV(VkDevice, const VkAccelerationStructureCreateInfoNV*, const VkAllocationCallbacks*, VkAccelerationStructureNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAccelerationStructureNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureNV(VkDevice, VkAccelerationStructureNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyAccelerationStructureNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(VkDevice, const VkAccelerationStructureMemoryRequirementsInfoNV*, VkMemoryRequirements2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureMemoryRequirementsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(VkDevice, uint32_t, const VkBindAccelerationStructureMemoryInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindAccelerationStructureMemoryNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructureNV(VkCommandBuffer, const VkAccelerationStructureInfoNV*, VkBuffer, VkDeviceSize, VkBool32, VkAccelerationStructureNV, VkAccelerationStructureNV, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructureNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureNV(VkCommandBuffer, VkAccelerationStructureNV, VkAccelerationStructureNV, VkCopyAccelerationStructureModeKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoNV*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRayTracingPipelinesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupHandlesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(VkDevice, VkAccelerationStructureNV, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureHandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer, uint32_t, const VkAccelerationStructureNV*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteAccelerationStructuresPropertiesNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCompileDeferredNV(VkDevice, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCompileDeferredNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(VkDevice, VkExternalMemoryHandleTypeFlagBits, const void*, VkMemoryHostPointerPropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryHostPointerPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarkerAMD(VkCommandBuffer, VkPipelineStageFlagBits, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteBufferMarkerAMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarker2AMD(VkCommandBuffer, VkPipelineStageFlags2, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteBufferMarker2AMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(VkDevice, uint32_t, const VkCalibratedTimestampInfoKHR*, uint64_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetCalibratedTimestampsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksNV(VkCommandBuffer, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectCountNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer, uint32_t, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExclusiveScissorEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorNV(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExclusiveScissorNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCheckpointNV(VkCommandBuffer, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCheckpointNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointDataNV(VkQueue, uint32_t*, VkCheckpointDataNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueueCheckpointDataNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointData2NV(VkQueue, uint32_t*, VkCheckpointData2NV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueueCheckpointData2NV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetSwapchainPresentTimingQueueSizeEXT(VkDevice, VkSwapchainKHR, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetSwapchainPresentTimingQueueSizeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimingPropertiesEXT(VkDevice, VkSwapchainKHR, VkSwapchainTimingPropertiesEXT*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainTimingPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimeDomainPropertiesEXT(VkDevice, VkSwapchainKHR, VkSwapchainTimeDomainPropertiesEXT*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainTimeDomainPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingEXT(VkDevice, const VkPastPresentationTimingInfoEXT*, VkPastPresentationTimingPropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPastPresentationTimingEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(VkDevice, const VkInitializePerformanceApiInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkInitializePerformanceApiINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkUninitializePerformanceApiINTEL(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUninitializePerformanceApiINTEL was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer, const VkPerformanceMarkerInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer, const VkPerformanceStreamMarkerInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceStreamMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer, const VkPerformanceOverrideInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceOverrideINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(VkDevice, const VkPerformanceConfigurationAcquireInfoINTEL*, VkPerformanceConfigurationINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquirePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(VkDevice, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleasePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerformanceConfigurationINTEL(VkQueue, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSetPerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(VkDevice, VkPerformanceParameterTypeINTEL, VkPerformanceValueINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPerformanceParameterINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkSetLocalDimmingAMD(VkDevice, VkSwapchainKHR, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLocalDimmingAMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddressEXT was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEXT(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkResetQueryPoolEXT(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetQueryPoolEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCullModeEXT(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCullModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFaceEXT(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFrontFaceEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveTopologyEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCountEXT(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWithCountEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCountEXT(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissorWithCountEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2EXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthTestEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthWriteEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOpEXT(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthCompareOpEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBoundsTestEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilTestEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOpEXT(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilOpEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImageEXT(VkDevice, const VkCopyMemoryToImageInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToImageEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemoryEXT(VkDevice, const VkCopyImageToMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToMemoryEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImageEXT(VkDevice, const VkCopyImageToImageInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToImageEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayoutEXT(VkDevice, uint32_t, const VkHostImageLayoutTransitionInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTransitionImageLayoutEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2EXT(VkDevice, VkImage, const VkImageSubresource2*, VkSubresourceLayout2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(VkDevice, const VkReleaseSwapchainImagesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseSwapchainImagesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice, const VkGeneratedCommandsMemoryRequirementsInfoNV*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetGeneratedCommandsMemoryRequirementsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPreprocessGeneratedCommandsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer, VkBool32, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdExecuteGeneratedCommandsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindPipelineShaderGroupNV(VkCommandBuffer, VkPipelineBindPoint, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindPipelineShaderGroupNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(VkDevice, const VkIndirectCommandsLayoutCreateInfoNV*, const VkAllocationCallbacks*, VkIndirectCommandsLayoutNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIndirectCommandsLayoutNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(VkDevice, VkIndirectCommandsLayoutNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyIndirectCommandsLayoutNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias2EXT(VkCommandBuffer, const VkDepthBiasInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBias2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePrivateDataSlotEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlotEXT(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPrivateDataSlotEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetPrivateDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPrivateDataEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatchTileQCOM(VkCommandBuffer, const VkDispatchTileInfoQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchTileQCOM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginPerTileExecutionQCOM(VkCommandBuffer, const VkPerTileBeginInfoQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginPerTileExecutionQCOM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndPerTileExecutionQCOM(VkCommandBuffer, const VkPerTileEndInfoQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndPerTileExecutionQCOM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(VkDevice, VkDescriptorSetLayout, VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutSizeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice, VkDescriptorSetLayout, uint32_t, VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutBindingOffsetEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorEXT(VkDevice, const VkDescriptorGetInfoEXT*, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBuffersEXT(VkCommandBuffer, uint32_t, const VkDescriptorBufferBindingInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorBuffersEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const uint32_t*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDescriptorBufferOffsetsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorBufferEmbeddedSamplersEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice, const VkBufferCaptureDescriptorDataInfoEXT*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferOpaqueCaptureDescriptorDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice, const VkImageCaptureDescriptorDataInfoEXT*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageOpaqueCaptureDescriptorDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice, const VkImageViewCaptureDescriptorDataInfoEXT*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewOpaqueCaptureDescriptorDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice, const VkSamplerCaptureDescriptorDataInfoEXT*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSamplerOpaqueCaptureDescriptorDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice, const VkAccelerationStructureCaptureDescriptorDataInfoEXT*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer, VkFragmentShadingRateNV, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFragmentShadingRateEnumNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(VkDevice, VkDeviceFaultCountsEXT*, VkDeviceFaultInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceFaultInfoEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetVertexInputEXT(VkCommandBuffer, uint32_t, const VkVertexInputBindingDescription2EXT*, uint32_t, const VkVertexInputAttributeDescription2EXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetVertexInputEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(VkDevice, const VkMemoryGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice, VkExternalMemoryHandleTypeFlagBits, zx_handle_t, VkMemoryZirconHandlePropertiesFUCHSIA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryZirconHandlePropertiesFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(VkDevice, const VkImportSemaphoreZirconHandleInfoFUCHSIA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(VkDevice, const VkSemaphoreGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindInvocationMaskHUAWEI was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(VkDevice, const VkMemoryGetRemoteAddressInfoNV*, VkRemoteAddressNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryRemoteAddressNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPatchControlPointsEXT(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPatchControlPointsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizerDiscardEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBiasEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEXT(VkCommandBuffer, VkLogicOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLogicOpEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveRestartEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void                                    VKAPI_CALL vkCmdSetColorWriteEnableEXT(VkCommandBuffer, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorWriteEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiEXT(VkCommandBuffer, uint32_t, const VkMultiDrawInfoEXT*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMultiEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiIndexedEXT(VkCommandBuffer, uint32_t, const VkMultiDrawIndexedInfoEXT*, uint32_t, uint32_t, uint32_t, const int32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMultiIndexedEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateMicromapEXT(VkDevice, const VkMicromapCreateInfoEXT*, const VkAllocationCallbacks*, VkMicromapEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyMicromapEXT(VkDevice, VkMicromapEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyMicromapEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBuildMicromapsEXT(VkCommandBuffer, uint32_t, const VkMicromapBuildInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildMicromapsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBuildMicromapsEXT(VkDevice, VkDeferredOperationKHR, uint32_t, const VkMicromapBuildInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBuildMicromapsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMicromapToMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMicromapToMemoryEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMemoryToMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(VkDevice, uint32_t, const VkMicromapEXT*, VkQueryType, size_t, void*, size_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWriteMicromapsPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapEXT(VkCommandBuffer, const VkCopyMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMicromapEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer, const VkCopyMicromapToMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMicromapToMemoryEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer, const VkCopyMemoryToMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryToMicromapEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer, uint32_t, const VkMicromapEXT*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteMicromapsPropertiesEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(VkDevice, const VkMicromapVersionInfoEXT*, VkAccelerationStructureCompatibilityKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMicromapCompatibilityEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetMicromapBuildSizesEXT(VkDevice, VkAccelerationStructureBuildTypeKHR, const VkMicromapBuildInfoEXT*, VkMicromapBuildSizesInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMicromapBuildSizesEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterHUAWEI(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawClusterHUAWEI was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawClusterIndirectHUAWEI was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(VkDevice, VkDeviceMemory, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDeviceMemoryPriorityEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice, const VkDescriptorSetBindingReferenceVALVE*, VkDescriptorSetLayoutHostMappingInfoVALVE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutHostMappingInfoVALVE was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(VkDevice, VkDescriptorSet, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetHostMappingVALVE was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPipelineIndirectMemoryRequirementsNV(VkDevice, const VkComputePipelineCreateInfo*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineIndirectMemoryRequirementsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdUpdatePipelineIndirectBufferNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetPipelineIndirectDeviceAddressNV(VkDevice, const VkPipelineIndirectDeviceAddressInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineIndirectDeviceAddressNV was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClampEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetPolygonModeEXT(VkCommandBuffer, VkPolygonMode) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPolygonModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationSamplesEXT(VkCommandBuffer, VkSampleCountFlagBits) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizationSamplesEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleMaskEXT(VkCommandBuffer, VkSampleCountFlagBits, const VkSampleMask*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleMaskEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAlphaToCoverageEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAlphaToOneEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLogicOpEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEnableEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEquationEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorBlendEquationEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendEquationEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteMaskEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorComponentFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorWriteMaskEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer, VkTessellationDomainOrigin) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetTessellationDomainOriginEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationStreamEXT(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizationStreamEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer, VkConservativeRasterizationModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetConservativeRasterizationModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExtraPrimitiveOverestimationSizeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClipEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleLocationsEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorBlendAdvancedEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendAdvancedEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetProvokingVertexModeEXT(VkCommandBuffer, VkProvokingVertexModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetProvokingVertexModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineRasterizationModeEXT(VkCommandBuffer, VkLineRasterizationModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineRasterizationModeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClipNegativeOneToOneEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWScalingEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportSwizzleNV(VkCommandBuffer, uint32_t, uint32_t, const VkViewportSwizzleNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportSwizzleNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageToColorEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorLocationNV(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageToColorLocationNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationModeNV(VkCommandBuffer, VkCoverageModulationModeNV) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationModeNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationTableEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableNV(VkCommandBuffer, uint32_t, const float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationTableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetShadingRateImageEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetShadingRateImageEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRepresentativeFragmentTestEnableNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageReductionModeNV(VkCommandBuffer, VkCoverageReductionModeNV) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageReductionModeNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleIdentifierEXT(VkDevice, VkShaderModule, VkShaderModuleIdentifierEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderModuleIdentifierEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice, const VkShaderModuleCreateInfo*, VkShaderModuleIdentifierEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderModuleCreateInfoIdentifierEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(VkDevice, const VkOpticalFlowSessionCreateInfoNV*, const VkAllocationCallbacks*, VkOpticalFlowSessionNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateOpticalFlowSessionNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyOpticalFlowSessionNV(VkDevice, VkOpticalFlowSessionNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyOpticalFlowSessionNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(VkDevice, VkOpticalFlowSessionNV, VkOpticalFlowSessionBindingPointNV, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindOpticalFlowSessionImageNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdOpticalFlowExecuteNV(VkCommandBuffer, VkOpticalFlowSessionNV, const VkOpticalFlowExecuteInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdOpticalFlowExecuteNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkAntiLagUpdateAMD(VkDevice, const VkAntiLagDataAMD*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAntiLagUpdateAMD was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateShadersEXT(VkDevice, uint32_t, const VkShaderCreateInfoEXT*, const VkAllocationCallbacks*, VkShaderEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateShadersEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyShaderEXT(VkDevice, VkShaderEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyShaderEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(VkDevice, VkShaderEXT, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderBinaryDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindShadersEXT(VkCommandBuffer, uint32_t, const VkShaderStageFlagBits*, const VkShaderEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindShadersEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampRangeEXT(VkCommandBuffer, VkDepthClampModeEXT, const VkDepthClampRangeEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClampRangeEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(VkDevice, VkFramebuffer, uint32_t*, VkTilePropertiesQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFramebufferTilePropertiesQCOM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(VkDevice, const VkRenderingInfo*, VkTilePropertiesQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDynamicRenderingTilePropertiesQCOM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkConvertCooperativeVectorMatrixNV(VkDevice, const VkConvertCooperativeVectorMatrixInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkConvertCooperativeVectorMatrixNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdConvertCooperativeVectorMatrixNV(VkCommandBuffer, uint32_t, const VkConvertCooperativeVectorMatrixInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdConvertCooperativeVectorMatrixNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkSetLatencySleepModeNV(VkDevice, VkSwapchainKHR, const VkLatencySleepModeInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLatencySleepModeNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkLatencySleepNV(VkDevice, VkSwapchainKHR, const VkLatencySleepInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkLatencySleepNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkSetLatencyMarkerNV(VkDevice, VkSwapchainKHR, const VkSetLatencyMarkerInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLatencyMarkerNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetLatencyTimingsNV(VkDevice, VkSwapchainKHR, VkGetLatencyMarkerInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetLatencyTimingsNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkQueueNotifyOutOfBandNV(VkQueue, const VkOutOfBandQueueTypeInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueNotifyOutOfBandNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelinesARM(VkDevice, VkDeferredOperationKHR, VkPipelineCache, uint32_t, const VkDataGraphPipelineCreateInfoARM*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDataGraphPipelinesARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelineSessionARM(VkDevice, const VkDataGraphPipelineSessionCreateInfoARM*, const VkAllocationCallbacks*, VkDataGraphPipelineSessionARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDataGraphPipelineSessionARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM*, uint32_t*, VkDataGraphPipelineSessionBindPointRequirementARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDataGraphPipelineSessionBindPointRequirementsARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkGetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDataGraphPipelineSessionMemoryRequirementsARM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBindDataGraphPipelineSessionMemoryARM(VkDevice, uint32_t, const VkBindDataGraphPipelineSessionMemoryInfoARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindDataGraphPipelineSessionMemoryARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyDataGraphPipelineSessionARM(VkDevice, VkDataGraphPipelineSessionARM, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDataGraphPipelineSessionARM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDispatchDataGraphARM(VkCommandBuffer, VkDataGraphPipelineSessionARM, const VkDataGraphPipelineDispatchInfoARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchDataGraphARM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineAvailablePropertiesARM(VkDevice, const VkDataGraphPipelineInfoARM*, uint32_t*, VkDataGraphPipelinePropertyARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDataGraphPipelineAvailablePropertiesARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelinePropertiesARM(VkDevice, const VkDataGraphPipelineInfoARM*, uint32_t, VkDataGraphPipelinePropertyQueryResultARM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDataGraphPipelinePropertiesARM was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer, VkImageAspectFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAttachmentFeedbackLoopEnableEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBindTileMemoryQCOM(VkCommandBuffer, const VkTileMemoryBindInfoQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindTileMemoryQCOM was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryEXT(VkCommandBuffer, const VkDecompressMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDecompressMemoryEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountEXT(VkCommandBuffer, VkMemoryDecompressionMethodFlagsEXT, VkDeviceAddress, VkDeviceAddress, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDecompressMemoryIndirectCountEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetPartitionedAccelerationStructuresBuildSizesNV(VkDevice, const VkPartitionedAccelerationStructureInstancesInputNV*, VkAccelerationStructureBuildSizesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPartitionedAccelerationStructuresBuildSizesNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildPartitionedAccelerationStructuresNV was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsEXT(VkDevice, const VkGeneratedCommandsMemoryRequirementsInfoEXT*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetGeneratedCommandsMemoryRequirementsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer, const VkGeneratedCommandsInfoEXT*, VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPreprocessGeneratedCommandsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsEXT(VkCommandBuffer, VkBool32, const VkGeneratedCommandsInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdExecuteGeneratedCommandsEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutEXT(VkDevice, const VkIndirectCommandsLayoutCreateInfoEXT*, const VkAllocationCallbacks*, VkIndirectCommandsLayoutEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIndirectCommandsLayoutEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutEXT(VkDevice, VkIndirectCommandsLayoutEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyIndirectCommandsLayoutEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectExecutionSetEXT(VkDevice, const VkIndirectExecutionSetCreateInfoEXT*, const VkAllocationCallbacks*, VkIndirectExecutionSetEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIndirectExecutionSetEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectExecutionSetEXT(VkDevice, VkIndirectExecutionSetEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyIndirectExecutionSetEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetPipelineEXT(VkDevice, VkIndirectExecutionSetEXT, uint32_t, const VkWriteIndirectExecutionSetPipelineEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateIndirectExecutionSetPipelineEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetShaderEXT(VkDevice, VkIndirectExecutionSetEXT, uint32_t, const VkWriteIndirectExecutionSetShaderEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateIndirectExecutionSetShaderEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandleEXT(VkDevice, const VkMemoryGetMetalHandleInfoEXT*, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryMetalHandleEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandlePropertiesEXT(VkDevice, VkExternalMemoryHandleTypeFlagBits, const void*, VkMemoryMetalHandlePropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryMetalHandlePropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2EXT(VkCommandBuffer, const VkRenderingEndInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRendering2EXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBeginCustomResolveEXT(VkCommandBuffer, const VkBeginCustomResolveInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginCustomResolveEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(VkDevice, const VkAccelerationStructureCreateInfoKHR*, const VkAllocationCallbacks*, VkAccelerationStructureKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureKHR(VkDevice, VkAccelerationStructureKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyAccelerationStructureKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkDeviceAddress*, const uint32_t*, const uint32_t* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructuresIndirectKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(VkDevice, VkDeferredOperationKHR, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(VkDevice, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, size_t, void*, size_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureKHR(VkCommandBuffer, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice, const VkAccelerationStructureDeviceAddressInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice, const VkAccelerationStructureVersionInfoKHR*, VkAccelerationStructureCompatibilityKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceAccelerationStructureCompatibilityKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(VkDevice, VkAccelerationStructureBuildTypeKHR, const VkAccelerationStructureBuildGeometryInfoKHR*, const uint32_t*, VkAccelerationStructureBuildSizesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureBuildSizesKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice, VkDeferredOperationKHR, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoKHR*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRayTracingPipelinesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingCaptureReplayShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirectKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, VkDeviceAddress) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysIndirectKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(VkDevice, VkPipeline, uint32_t, VkShaderGroupShaderKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupStackSizeKHR was called, resulting in no-op behavior."); return 0; }
inline VKAPI_ATTR void VKAPI_CALL vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRayTracingPipelineStackSizeKHR was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksEXT(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectEXT was called, resulting in no-op behavior."); }
inline VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectCountEXT was called, resulting in no-op behavior."); }
// clang-format on
GFXRECON_END_NAMESPACE(noop)

struct VulkanLayerTable
{
    PFN_vkCreateInstance CreateInstance{ nullptr };
    PFN_vkCreateDevice CreateDevice{ nullptr };
};

struct VulkanInstanceTable
{
    PFN_vkDestroyInstance DestroyInstance{ noop::vkDestroyInstance };
    PFN_vkEnumeratePhysicalDevices EnumeratePhysicalDevices{ noop::vkEnumeratePhysicalDevices };
    PFN_vkGetPhysicalDeviceFeatures GetPhysicalDeviceFeatures{ noop::vkGetPhysicalDeviceFeatures };
    PFN_vkGetPhysicalDeviceFormatProperties GetPhysicalDeviceFormatProperties{ noop::vkGetPhysicalDeviceFormatProperties };
    PFN_vkGetPhysicalDeviceImageFormatProperties GetPhysicalDeviceImageFormatProperties{ noop::vkGetPhysicalDeviceImageFormatProperties };
    PFN_vkGetPhysicalDeviceProperties GetPhysicalDeviceProperties{ noop::vkGetPhysicalDeviceProperties };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties GetPhysicalDeviceQueueFamilyProperties{ noop::vkGetPhysicalDeviceQueueFamilyProperties };
    PFN_vkGetPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties{ noop::vkGetPhysicalDeviceMemoryProperties };
    PFN_vkGetInstanceProcAddr GetInstanceProcAddr{ noop::vkGetInstanceProcAddr };
    PFN_vkEnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties{ noop::vkEnumerateDeviceExtensionProperties };
    PFN_vkEnumerateDeviceLayerProperties EnumerateDeviceLayerProperties{ noop::vkEnumerateDeviceLayerProperties };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties GetPhysicalDeviceSparseImageFormatProperties{ noop::vkGetPhysicalDeviceSparseImageFormatProperties };
    PFN_vkEnumeratePhysicalDeviceGroups EnumeratePhysicalDeviceGroups{ noop::vkEnumeratePhysicalDeviceGroups };
    PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2{ noop::vkGetPhysicalDeviceFeatures2 };
    PFN_vkGetPhysicalDeviceProperties2 GetPhysicalDeviceProperties2{ noop::vkGetPhysicalDeviceProperties2 };
    PFN_vkGetPhysicalDeviceFormatProperties2 GetPhysicalDeviceFormatProperties2{ noop::vkGetPhysicalDeviceFormatProperties2 };
    PFN_vkGetPhysicalDeviceImageFormatProperties2 GetPhysicalDeviceImageFormatProperties2{ noop::vkGetPhysicalDeviceImageFormatProperties2 };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 GetPhysicalDeviceQueueFamilyProperties2{ noop::vkGetPhysicalDeviceQueueFamilyProperties2 };
    PFN_vkGetPhysicalDeviceMemoryProperties2 GetPhysicalDeviceMemoryProperties2{ noop::vkGetPhysicalDeviceMemoryProperties2 };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 GetPhysicalDeviceSparseImageFormatProperties2{ noop::vkGetPhysicalDeviceSparseImageFormatProperties2 };
    PFN_vkGetPhysicalDeviceExternalBufferProperties GetPhysicalDeviceExternalBufferProperties{ noop::vkGetPhysicalDeviceExternalBufferProperties };
    PFN_vkGetPhysicalDeviceExternalFenceProperties GetPhysicalDeviceExternalFenceProperties{ noop::vkGetPhysicalDeviceExternalFenceProperties };
    PFN_vkGetPhysicalDeviceExternalSemaphoreProperties GetPhysicalDeviceExternalSemaphoreProperties{ noop::vkGetPhysicalDeviceExternalSemaphoreProperties };
    PFN_vkGetPhysicalDeviceToolProperties GetPhysicalDeviceToolProperties{ noop::vkGetPhysicalDeviceToolProperties };
    PFN_vkDestroySurfaceKHR DestroySurfaceKHR{ noop::vkDestroySurfaceKHR };
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR GetPhysicalDeviceSurfaceSupportKHR{ noop::vkGetPhysicalDeviceSurfaceSupportKHR };
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR GetPhysicalDeviceSurfaceCapabilitiesKHR{ noop::vkGetPhysicalDeviceSurfaceCapabilitiesKHR };
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR GetPhysicalDeviceSurfaceFormatsKHR{ noop::vkGetPhysicalDeviceSurfaceFormatsKHR };
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR GetPhysicalDeviceSurfacePresentModesKHR{ noop::vkGetPhysicalDeviceSurfacePresentModesKHR };
    PFN_vkGetPhysicalDevicePresentRectanglesKHR GetPhysicalDevicePresentRectanglesKHR{ noop::vkGetPhysicalDevicePresentRectanglesKHR };
    PFN_vkGetPhysicalDeviceDisplayPropertiesKHR GetPhysicalDeviceDisplayPropertiesKHR{ noop::vkGetPhysicalDeviceDisplayPropertiesKHR };
    PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR GetPhysicalDeviceDisplayPlanePropertiesKHR{ noop::vkGetPhysicalDeviceDisplayPlanePropertiesKHR };
    PFN_vkGetDisplayPlaneSupportedDisplaysKHR GetDisplayPlaneSupportedDisplaysKHR{ noop::vkGetDisplayPlaneSupportedDisplaysKHR };
    PFN_vkGetDisplayModePropertiesKHR GetDisplayModePropertiesKHR{ noop::vkGetDisplayModePropertiesKHR };
    PFN_vkCreateDisplayModeKHR CreateDisplayModeKHR{ noop::vkCreateDisplayModeKHR };
    PFN_vkGetDisplayPlaneCapabilitiesKHR GetDisplayPlaneCapabilitiesKHR{ noop::vkGetDisplayPlaneCapabilitiesKHR };
    PFN_vkCreateDisplayPlaneSurfaceKHR CreateDisplayPlaneSurfaceKHR{ noop::vkCreateDisplayPlaneSurfaceKHR };
    PFN_vkCreateXlibSurfaceKHR CreateXlibSurfaceKHR{ noop::vkCreateXlibSurfaceKHR };
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR GetPhysicalDeviceXlibPresentationSupportKHR{ noop::vkGetPhysicalDeviceXlibPresentationSupportKHR };
    PFN_vkCreateXcbSurfaceKHR CreateXcbSurfaceKHR{ noop::vkCreateXcbSurfaceKHR };
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR GetPhysicalDeviceXcbPresentationSupportKHR{ noop::vkGetPhysicalDeviceXcbPresentationSupportKHR };
    PFN_vkCreateWaylandSurfaceKHR CreateWaylandSurfaceKHR{ noop::vkCreateWaylandSurfaceKHR };
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR GetPhysicalDeviceWaylandPresentationSupportKHR{ noop::vkGetPhysicalDeviceWaylandPresentationSupportKHR };
    PFN_vkCreateAndroidSurfaceKHR CreateAndroidSurfaceKHR{ noop::vkCreateAndroidSurfaceKHR };
    PFN_vkCreateWin32SurfaceKHR CreateWin32SurfaceKHR{ noop::vkCreateWin32SurfaceKHR };
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR GetPhysicalDeviceWin32PresentationSupportKHR{ noop::vkGetPhysicalDeviceWin32PresentationSupportKHR };
    PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR GetPhysicalDeviceVideoCapabilitiesKHR{ noop::vkGetPhysicalDeviceVideoCapabilitiesKHR };
    PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR GetPhysicalDeviceVideoFormatPropertiesKHR{ noop::vkGetPhysicalDeviceVideoFormatPropertiesKHR };
    PFN_vkGetPhysicalDeviceFeatures2KHR GetPhysicalDeviceFeatures2KHR{ noop::vkGetPhysicalDeviceFeatures2KHR };
    PFN_vkGetPhysicalDeviceProperties2KHR GetPhysicalDeviceProperties2KHR{ noop::vkGetPhysicalDeviceProperties2KHR };
    PFN_vkGetPhysicalDeviceFormatProperties2KHR GetPhysicalDeviceFormatProperties2KHR{ noop::vkGetPhysicalDeviceFormatProperties2KHR };
    PFN_vkGetPhysicalDeviceImageFormatProperties2KHR GetPhysicalDeviceImageFormatProperties2KHR{ noop::vkGetPhysicalDeviceImageFormatProperties2KHR };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR GetPhysicalDeviceQueueFamilyProperties2KHR{ noop::vkGetPhysicalDeviceQueueFamilyProperties2KHR };
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR GetPhysicalDeviceMemoryProperties2KHR{ noop::vkGetPhysicalDeviceMemoryProperties2KHR };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR GetPhysicalDeviceSparseImageFormatProperties2KHR{ noop::vkGetPhysicalDeviceSparseImageFormatProperties2KHR };
    PFN_vkEnumeratePhysicalDeviceGroupsKHR EnumeratePhysicalDeviceGroupsKHR{ noop::vkEnumeratePhysicalDeviceGroupsKHR };
    PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR GetPhysicalDeviceExternalBufferPropertiesKHR{ noop::vkGetPhysicalDeviceExternalBufferPropertiesKHR };
    PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR GetPhysicalDeviceExternalSemaphorePropertiesKHR{ noop::vkGetPhysicalDeviceExternalSemaphorePropertiesKHR };
    PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR GetPhysicalDeviceExternalFencePropertiesKHR{ noop::vkGetPhysicalDeviceExternalFencePropertiesKHR };
    PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR{ noop::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR };
    PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR{ noop::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR };
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR GetPhysicalDeviceSurfaceCapabilities2KHR{ noop::vkGetPhysicalDeviceSurfaceCapabilities2KHR };
    PFN_vkGetPhysicalDeviceSurfaceFormats2KHR GetPhysicalDeviceSurfaceFormats2KHR{ noop::vkGetPhysicalDeviceSurfaceFormats2KHR };
    PFN_vkGetPhysicalDeviceDisplayProperties2KHR GetPhysicalDeviceDisplayProperties2KHR{ noop::vkGetPhysicalDeviceDisplayProperties2KHR };
    PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR GetPhysicalDeviceDisplayPlaneProperties2KHR{ noop::vkGetPhysicalDeviceDisplayPlaneProperties2KHR };
    PFN_vkGetDisplayModeProperties2KHR GetDisplayModeProperties2KHR{ noop::vkGetDisplayModeProperties2KHR };
    PFN_vkGetDisplayPlaneCapabilities2KHR GetDisplayPlaneCapabilities2KHR{ noop::vkGetDisplayPlaneCapabilities2KHR };
    PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR GetPhysicalDeviceFragmentShadingRatesKHR{ noop::vkGetPhysicalDeviceFragmentShadingRatesKHR };
    PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR{ noop::vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR };
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR GetPhysicalDeviceCooperativeMatrixPropertiesKHR{ noop::vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR };
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR GetPhysicalDeviceCalibrateableTimeDomainsKHR{ noop::vkGetPhysicalDeviceCalibrateableTimeDomainsKHR };
    PFN_vkCreateDebugReportCallbackEXT CreateDebugReportCallbackEXT{ noop::vkCreateDebugReportCallbackEXT };
    PFN_vkDestroyDebugReportCallbackEXT DestroyDebugReportCallbackEXT{ noop::vkDestroyDebugReportCallbackEXT };
    PFN_vkDebugReportMessageEXT DebugReportMessageEXT{ noop::vkDebugReportMessageEXT };
    PFN_vkCreateStreamDescriptorSurfaceGGP CreateStreamDescriptorSurfaceGGP{ noop::vkCreateStreamDescriptorSurfaceGGP };
    PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV GetPhysicalDeviceExternalImageFormatPropertiesNV{ noop::vkGetPhysicalDeviceExternalImageFormatPropertiesNV };
    PFN_vkCreateViSurfaceNN CreateViSurfaceNN{ noop::vkCreateViSurfaceNN };
    PFN_vkReleaseDisplayEXT ReleaseDisplayEXT{ noop::vkReleaseDisplayEXT };
    PFN_vkAcquireXlibDisplayEXT AcquireXlibDisplayEXT{ noop::vkAcquireXlibDisplayEXT };
    PFN_vkGetRandROutputDisplayEXT GetRandROutputDisplayEXT{ noop::vkGetRandROutputDisplayEXT };
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT GetPhysicalDeviceSurfaceCapabilities2EXT{ noop::vkGetPhysicalDeviceSurfaceCapabilities2EXT };
    PFN_vkCreateIOSSurfaceMVK CreateIOSSurfaceMVK{ noop::vkCreateIOSSurfaceMVK };
    PFN_vkCreateMacOSSurfaceMVK CreateMacOSSurfaceMVK{ noop::vkCreateMacOSSurfaceMVK };
    PFN_vkSetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT{ noop::vkSetDebugUtilsObjectNameEXT };
    PFN_vkSetDebugUtilsObjectTagEXT SetDebugUtilsObjectTagEXT{ noop::vkSetDebugUtilsObjectTagEXT };
    PFN_vkCreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT{ noop::vkCreateDebugUtilsMessengerEXT };
    PFN_vkDestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessengerEXT{ noop::vkDestroyDebugUtilsMessengerEXT };
    PFN_vkSubmitDebugUtilsMessageEXT SubmitDebugUtilsMessageEXT{ noop::vkSubmitDebugUtilsMessageEXT };
    PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT GetPhysicalDeviceMultisamplePropertiesEXT{ noop::vkGetPhysicalDeviceMultisamplePropertiesEXT };
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT GetPhysicalDeviceCalibrateableTimeDomainsEXT{ noop::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT };
    PFN_vkCreateImagePipeSurfaceFUCHSIA CreateImagePipeSurfaceFUCHSIA{ noop::vkCreateImagePipeSurfaceFUCHSIA };
    PFN_vkCreateMetalSurfaceEXT CreateMetalSurfaceEXT{ noop::vkCreateMetalSurfaceEXT };
    PFN_vkGetPhysicalDeviceToolPropertiesEXT GetPhysicalDeviceToolPropertiesEXT{ noop::vkGetPhysicalDeviceToolPropertiesEXT };
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV GetPhysicalDeviceCooperativeMatrixPropertiesNV{ noop::vkGetPhysicalDeviceCooperativeMatrixPropertiesNV };
    PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV{ noop::vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV };
    PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT GetPhysicalDeviceSurfacePresentModes2EXT{ noop::vkGetPhysicalDeviceSurfacePresentModes2EXT };
    PFN_vkCreateHeadlessSurfaceEXT CreateHeadlessSurfaceEXT{ noop::vkCreateHeadlessSurfaceEXT };
    PFN_vkAcquireDrmDisplayEXT AcquireDrmDisplayEXT{ noop::vkAcquireDrmDisplayEXT };
    PFN_vkGetDrmDisplayEXT GetDrmDisplayEXT{ noop::vkGetDrmDisplayEXT };
    PFN_vkAcquireWinrtDisplayNV AcquireWinrtDisplayNV{ noop::vkAcquireWinrtDisplayNV };
    PFN_vkGetWinrtDisplayNV GetWinrtDisplayNV{ noop::vkGetWinrtDisplayNV };
    PFN_vkCreateDirectFBSurfaceEXT CreateDirectFBSurfaceEXT{ noop::vkCreateDirectFBSurfaceEXT };
    PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT GetPhysicalDeviceDirectFBPresentationSupportEXT{ noop::vkGetPhysicalDeviceDirectFBPresentationSupportEXT };
    PFN_vkCreateScreenSurfaceQNX CreateScreenSurfaceQNX{ noop::vkCreateScreenSurfaceQNX };
    PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX GetPhysicalDeviceScreenPresentationSupportQNX{ noop::vkGetPhysicalDeviceScreenPresentationSupportQNX };
    PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV GetPhysicalDeviceOpticalFlowImageFormatsNV{ noop::vkGetPhysicalDeviceOpticalFlowImageFormatsNV };
    PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV GetPhysicalDeviceCooperativeVectorPropertiesNV{ noop::vkGetPhysicalDeviceCooperativeVectorPropertiesNV };
    PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM{ noop::vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM };
    PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM{ noop::vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM };
    PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV{ noop::vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV };
    PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM{ noop::vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM };
};

struct VulkanDeviceTable
{
    PFN_vkGetDeviceProcAddr GetDeviceProcAddr{ noop::vkGetDeviceProcAddr };
    PFN_vkDestroyDevice DestroyDevice{ noop::vkDestroyDevice };
    PFN_vkGetDeviceQueue GetDeviceQueue{ noop::vkGetDeviceQueue };
    PFN_vkQueueSubmit QueueSubmit{ noop::vkQueueSubmit };
    PFN_vkQueueWaitIdle QueueWaitIdle{ noop::vkQueueWaitIdle };
    PFN_vkDeviceWaitIdle DeviceWaitIdle{ noop::vkDeviceWaitIdle };
    PFN_vkAllocateMemory AllocateMemory{ noop::vkAllocateMemory };
    PFN_vkFreeMemory FreeMemory{ noop::vkFreeMemory };
    PFN_vkMapMemory MapMemory{ noop::vkMapMemory };
    PFN_vkUnmapMemory UnmapMemory{ noop::vkUnmapMemory };
    PFN_vkFlushMappedMemoryRanges FlushMappedMemoryRanges{ noop::vkFlushMappedMemoryRanges };
    PFN_vkInvalidateMappedMemoryRanges InvalidateMappedMemoryRanges{ noop::vkInvalidateMappedMemoryRanges };
    PFN_vkGetDeviceMemoryCommitment GetDeviceMemoryCommitment{ noop::vkGetDeviceMemoryCommitment };
    PFN_vkBindBufferMemory BindBufferMemory{ noop::vkBindBufferMemory };
    PFN_vkBindImageMemory BindImageMemory{ noop::vkBindImageMemory };
    PFN_vkGetBufferMemoryRequirements GetBufferMemoryRequirements{ noop::vkGetBufferMemoryRequirements };
    PFN_vkGetImageMemoryRequirements GetImageMemoryRequirements{ noop::vkGetImageMemoryRequirements };
    PFN_vkGetImageSparseMemoryRequirements GetImageSparseMemoryRequirements{ noop::vkGetImageSparseMemoryRequirements };
    PFN_vkQueueBindSparse QueueBindSparse{ noop::vkQueueBindSparse };
    PFN_vkCreateFence CreateFence{ noop::vkCreateFence };
    PFN_vkDestroyFence DestroyFence{ noop::vkDestroyFence };
    PFN_vkResetFences ResetFences{ noop::vkResetFences };
    PFN_vkGetFenceStatus GetFenceStatus{ noop::vkGetFenceStatus };
    PFN_vkWaitForFences WaitForFences{ noop::vkWaitForFences };
    PFN_vkCreateSemaphore CreateSemaphore{ noop::vkCreateSemaphore };
    PFN_vkDestroySemaphore DestroySemaphore{ noop::vkDestroySemaphore };
    PFN_vkCreateQueryPool CreateQueryPool{ noop::vkCreateQueryPool };
    PFN_vkDestroyQueryPool DestroyQueryPool{ noop::vkDestroyQueryPool };
    PFN_vkGetQueryPoolResults GetQueryPoolResults{ noop::vkGetQueryPoolResults };
    PFN_vkCreateBuffer CreateBuffer{ noop::vkCreateBuffer };
    PFN_vkDestroyBuffer DestroyBuffer{ noop::vkDestroyBuffer };
    PFN_vkCreateImage CreateImage{ noop::vkCreateImage };
    PFN_vkDestroyImage DestroyImage{ noop::vkDestroyImage };
    PFN_vkGetImageSubresourceLayout GetImageSubresourceLayout{ noop::vkGetImageSubresourceLayout };
    PFN_vkCreateImageView CreateImageView{ noop::vkCreateImageView };
    PFN_vkDestroyImageView DestroyImageView{ noop::vkDestroyImageView };
    PFN_vkCreateCommandPool CreateCommandPool{ noop::vkCreateCommandPool };
    PFN_vkDestroyCommandPool DestroyCommandPool{ noop::vkDestroyCommandPool };
    PFN_vkResetCommandPool ResetCommandPool{ noop::vkResetCommandPool };
    PFN_vkAllocateCommandBuffers AllocateCommandBuffers{ noop::vkAllocateCommandBuffers };
    PFN_vkFreeCommandBuffers FreeCommandBuffers{ noop::vkFreeCommandBuffers };
    PFN_vkBeginCommandBuffer BeginCommandBuffer{ noop::vkBeginCommandBuffer };
    PFN_vkEndCommandBuffer EndCommandBuffer{ noop::vkEndCommandBuffer };
    PFN_vkResetCommandBuffer ResetCommandBuffer{ noop::vkResetCommandBuffer };
    PFN_vkCmdCopyBuffer CmdCopyBuffer{ noop::vkCmdCopyBuffer };
    PFN_vkCmdCopyImage CmdCopyImage{ noop::vkCmdCopyImage };
    PFN_vkCmdCopyBufferToImage CmdCopyBufferToImage{ noop::vkCmdCopyBufferToImage };
    PFN_vkCmdCopyImageToBuffer CmdCopyImageToBuffer{ noop::vkCmdCopyImageToBuffer };
    PFN_vkCmdUpdateBuffer CmdUpdateBuffer{ noop::vkCmdUpdateBuffer };
    PFN_vkCmdFillBuffer CmdFillBuffer{ noop::vkCmdFillBuffer };
    PFN_vkCmdPipelineBarrier CmdPipelineBarrier{ noop::vkCmdPipelineBarrier };
    PFN_vkCmdBeginQuery CmdBeginQuery{ noop::vkCmdBeginQuery };
    PFN_vkCmdEndQuery CmdEndQuery{ noop::vkCmdEndQuery };
    PFN_vkCmdResetQueryPool CmdResetQueryPool{ noop::vkCmdResetQueryPool };
    PFN_vkCmdWriteTimestamp CmdWriteTimestamp{ noop::vkCmdWriteTimestamp };
    PFN_vkCmdCopyQueryPoolResults CmdCopyQueryPoolResults{ noop::vkCmdCopyQueryPoolResults };
    PFN_vkCmdExecuteCommands CmdExecuteCommands{ noop::vkCmdExecuteCommands };
    PFN_vkCreateEvent CreateEvent{ noop::vkCreateEvent };
    PFN_vkDestroyEvent DestroyEvent{ noop::vkDestroyEvent };
    PFN_vkGetEventStatus GetEventStatus{ noop::vkGetEventStatus };
    PFN_vkSetEvent SetEvent{ noop::vkSetEvent };
    PFN_vkResetEvent ResetEvent{ noop::vkResetEvent };
    PFN_vkCreateBufferView CreateBufferView{ noop::vkCreateBufferView };
    PFN_vkDestroyBufferView DestroyBufferView{ noop::vkDestroyBufferView };
    PFN_vkCreateShaderModule CreateShaderModule{ noop::vkCreateShaderModule };
    PFN_vkDestroyShaderModule DestroyShaderModule{ noop::vkDestroyShaderModule };
    PFN_vkCreatePipelineCache CreatePipelineCache{ noop::vkCreatePipelineCache };
    PFN_vkDestroyPipelineCache DestroyPipelineCache{ noop::vkDestroyPipelineCache };
    PFN_vkGetPipelineCacheData GetPipelineCacheData{ noop::vkGetPipelineCacheData };
    PFN_vkMergePipelineCaches MergePipelineCaches{ noop::vkMergePipelineCaches };
    PFN_vkCreateComputePipelines CreateComputePipelines{ noop::vkCreateComputePipelines };
    PFN_vkDestroyPipeline DestroyPipeline{ noop::vkDestroyPipeline };
    PFN_vkCreatePipelineLayout CreatePipelineLayout{ noop::vkCreatePipelineLayout };
    PFN_vkDestroyPipelineLayout DestroyPipelineLayout{ noop::vkDestroyPipelineLayout };
    PFN_vkCreateSampler CreateSampler{ noop::vkCreateSampler };
    PFN_vkDestroySampler DestroySampler{ noop::vkDestroySampler };
    PFN_vkCreateDescriptorSetLayout CreateDescriptorSetLayout{ noop::vkCreateDescriptorSetLayout };
    PFN_vkDestroyDescriptorSetLayout DestroyDescriptorSetLayout{ noop::vkDestroyDescriptorSetLayout };
    PFN_vkCreateDescriptorPool CreateDescriptorPool{ noop::vkCreateDescriptorPool };
    PFN_vkDestroyDescriptorPool DestroyDescriptorPool{ noop::vkDestroyDescriptorPool };
    PFN_vkResetDescriptorPool ResetDescriptorPool{ noop::vkResetDescriptorPool };
    PFN_vkAllocateDescriptorSets AllocateDescriptorSets{ noop::vkAllocateDescriptorSets };
    PFN_vkFreeDescriptorSets FreeDescriptorSets{ noop::vkFreeDescriptorSets };
    PFN_vkUpdateDescriptorSets UpdateDescriptorSets{ noop::vkUpdateDescriptorSets };
    PFN_vkCmdBindPipeline CmdBindPipeline{ noop::vkCmdBindPipeline };
    PFN_vkCmdBindDescriptorSets CmdBindDescriptorSets{ noop::vkCmdBindDescriptorSets };
    PFN_vkCmdClearColorImage CmdClearColorImage{ noop::vkCmdClearColorImage };
    PFN_vkCmdDispatch CmdDispatch{ noop::vkCmdDispatch };
    PFN_vkCmdDispatchIndirect CmdDispatchIndirect{ noop::vkCmdDispatchIndirect };
    PFN_vkCmdSetEvent CmdSetEvent{ noop::vkCmdSetEvent };
    PFN_vkCmdResetEvent CmdResetEvent{ noop::vkCmdResetEvent };
    PFN_vkCmdWaitEvents CmdWaitEvents{ noop::vkCmdWaitEvents };
    PFN_vkCmdPushConstants CmdPushConstants{ noop::vkCmdPushConstants };
    PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines{ noop::vkCreateGraphicsPipelines };
    PFN_vkCreateFramebuffer CreateFramebuffer{ noop::vkCreateFramebuffer };
    PFN_vkDestroyFramebuffer DestroyFramebuffer{ noop::vkDestroyFramebuffer };
    PFN_vkCreateRenderPass CreateRenderPass{ noop::vkCreateRenderPass };
    PFN_vkDestroyRenderPass DestroyRenderPass{ noop::vkDestroyRenderPass };
    PFN_vkGetRenderAreaGranularity GetRenderAreaGranularity{ noop::vkGetRenderAreaGranularity };
    PFN_vkCmdSetViewport CmdSetViewport{ noop::vkCmdSetViewport };
    PFN_vkCmdSetScissor CmdSetScissor{ noop::vkCmdSetScissor };
    PFN_vkCmdSetLineWidth CmdSetLineWidth{ noop::vkCmdSetLineWidth };
    PFN_vkCmdSetDepthBias CmdSetDepthBias{ noop::vkCmdSetDepthBias };
    PFN_vkCmdSetBlendConstants CmdSetBlendConstants{ noop::vkCmdSetBlendConstants };
    PFN_vkCmdSetDepthBounds CmdSetDepthBounds{ noop::vkCmdSetDepthBounds };
    PFN_vkCmdSetStencilCompareMask CmdSetStencilCompareMask{ noop::vkCmdSetStencilCompareMask };
    PFN_vkCmdSetStencilWriteMask CmdSetStencilWriteMask{ noop::vkCmdSetStencilWriteMask };
    PFN_vkCmdSetStencilReference CmdSetStencilReference{ noop::vkCmdSetStencilReference };
    PFN_vkCmdBindIndexBuffer CmdBindIndexBuffer{ noop::vkCmdBindIndexBuffer };
    PFN_vkCmdBindVertexBuffers CmdBindVertexBuffers{ noop::vkCmdBindVertexBuffers };
    PFN_vkCmdDraw CmdDraw{ noop::vkCmdDraw };
    PFN_vkCmdDrawIndexed CmdDrawIndexed{ noop::vkCmdDrawIndexed };
    PFN_vkCmdDrawIndirect CmdDrawIndirect{ noop::vkCmdDrawIndirect };
    PFN_vkCmdDrawIndexedIndirect CmdDrawIndexedIndirect{ noop::vkCmdDrawIndexedIndirect };
    PFN_vkCmdBlitImage CmdBlitImage{ noop::vkCmdBlitImage };
    PFN_vkCmdClearDepthStencilImage CmdClearDepthStencilImage{ noop::vkCmdClearDepthStencilImage };
    PFN_vkCmdClearAttachments CmdClearAttachments{ noop::vkCmdClearAttachments };
    PFN_vkCmdResolveImage CmdResolveImage{ noop::vkCmdResolveImage };
    PFN_vkCmdBeginRenderPass CmdBeginRenderPass{ noop::vkCmdBeginRenderPass };
    PFN_vkCmdNextSubpass CmdNextSubpass{ noop::vkCmdNextSubpass };
    PFN_vkCmdEndRenderPass CmdEndRenderPass{ noop::vkCmdEndRenderPass };
    PFN_vkBindBufferMemory2 BindBufferMemory2{ noop::vkBindBufferMemory2 };
    PFN_vkBindImageMemory2 BindImageMemory2{ noop::vkBindImageMemory2 };
    PFN_vkGetDeviceGroupPeerMemoryFeatures GetDeviceGroupPeerMemoryFeatures{ noop::vkGetDeviceGroupPeerMemoryFeatures };
    PFN_vkCmdSetDeviceMask CmdSetDeviceMask{ noop::vkCmdSetDeviceMask };
    PFN_vkGetImageMemoryRequirements2 GetImageMemoryRequirements2{ noop::vkGetImageMemoryRequirements2 };
    PFN_vkGetBufferMemoryRequirements2 GetBufferMemoryRequirements2{ noop::vkGetBufferMemoryRequirements2 };
    PFN_vkGetImageSparseMemoryRequirements2 GetImageSparseMemoryRequirements2{ noop::vkGetImageSparseMemoryRequirements2 };
    PFN_vkTrimCommandPool TrimCommandPool{ noop::vkTrimCommandPool };
    PFN_vkGetDeviceQueue2 GetDeviceQueue2{ noop::vkGetDeviceQueue2 };
    PFN_vkCmdDispatchBase CmdDispatchBase{ noop::vkCmdDispatchBase };
    PFN_vkCreateDescriptorUpdateTemplate CreateDescriptorUpdateTemplate{ noop::vkCreateDescriptorUpdateTemplate };
    PFN_vkDestroyDescriptorUpdateTemplate DestroyDescriptorUpdateTemplate{ noop::vkDestroyDescriptorUpdateTemplate };
    PFN_vkUpdateDescriptorSetWithTemplate UpdateDescriptorSetWithTemplate{ noop::vkUpdateDescriptorSetWithTemplate };
    PFN_vkGetDescriptorSetLayoutSupport GetDescriptorSetLayoutSupport{ noop::vkGetDescriptorSetLayoutSupport };
    PFN_vkCreateSamplerYcbcrConversion CreateSamplerYcbcrConversion{ noop::vkCreateSamplerYcbcrConversion };
    PFN_vkDestroySamplerYcbcrConversion DestroySamplerYcbcrConversion{ noop::vkDestroySamplerYcbcrConversion };
    PFN_vkResetQueryPool ResetQueryPool{ noop::vkResetQueryPool };
    PFN_vkGetSemaphoreCounterValue GetSemaphoreCounterValue{ noop::vkGetSemaphoreCounterValue };
    PFN_vkWaitSemaphores WaitSemaphores{ noop::vkWaitSemaphores };
    PFN_vkSignalSemaphore SignalSemaphore{ noop::vkSignalSemaphore };
    PFN_vkGetBufferDeviceAddress GetBufferDeviceAddress{ noop::vkGetBufferDeviceAddress };
    PFN_vkGetBufferOpaqueCaptureAddress GetBufferOpaqueCaptureAddress{ noop::vkGetBufferOpaqueCaptureAddress };
    PFN_vkGetDeviceMemoryOpaqueCaptureAddress GetDeviceMemoryOpaqueCaptureAddress{ noop::vkGetDeviceMemoryOpaqueCaptureAddress };
    PFN_vkCmdDrawIndirectCount CmdDrawIndirectCount{ noop::vkCmdDrawIndirectCount };
    PFN_vkCmdDrawIndexedIndirectCount CmdDrawIndexedIndirectCount{ noop::vkCmdDrawIndexedIndirectCount };
    PFN_vkCreateRenderPass2 CreateRenderPass2{ noop::vkCreateRenderPass2 };
    PFN_vkCmdBeginRenderPass2 CmdBeginRenderPass2{ noop::vkCmdBeginRenderPass2 };
    PFN_vkCmdNextSubpass2 CmdNextSubpass2{ noop::vkCmdNextSubpass2 };
    PFN_vkCmdEndRenderPass2 CmdEndRenderPass2{ noop::vkCmdEndRenderPass2 };
    PFN_vkCreatePrivateDataSlot CreatePrivateDataSlot{ noop::vkCreatePrivateDataSlot };
    PFN_vkDestroyPrivateDataSlot DestroyPrivateDataSlot{ noop::vkDestroyPrivateDataSlot };
    PFN_vkSetPrivateData SetPrivateData{ noop::vkSetPrivateData };
    PFN_vkGetPrivateData GetPrivateData{ noop::vkGetPrivateData };
    PFN_vkCmdPipelineBarrier2 CmdPipelineBarrier2{ noop::vkCmdPipelineBarrier2 };
    PFN_vkCmdWriteTimestamp2 CmdWriteTimestamp2{ noop::vkCmdWriteTimestamp2 };
    PFN_vkQueueSubmit2 QueueSubmit2{ noop::vkQueueSubmit2 };
    PFN_vkCmdCopyBuffer2 CmdCopyBuffer2{ noop::vkCmdCopyBuffer2 };
    PFN_vkCmdCopyImage2 CmdCopyImage2{ noop::vkCmdCopyImage2 };
    PFN_vkCmdCopyBufferToImage2 CmdCopyBufferToImage2{ noop::vkCmdCopyBufferToImage2 };
    PFN_vkCmdCopyImageToBuffer2 CmdCopyImageToBuffer2{ noop::vkCmdCopyImageToBuffer2 };
    PFN_vkGetDeviceBufferMemoryRequirements GetDeviceBufferMemoryRequirements{ noop::vkGetDeviceBufferMemoryRequirements };
    PFN_vkGetDeviceImageMemoryRequirements GetDeviceImageMemoryRequirements{ noop::vkGetDeviceImageMemoryRequirements };
    PFN_vkGetDeviceImageSparseMemoryRequirements GetDeviceImageSparseMemoryRequirements{ noop::vkGetDeviceImageSparseMemoryRequirements };
    PFN_vkCmdSetEvent2 CmdSetEvent2{ noop::vkCmdSetEvent2 };
    PFN_vkCmdResetEvent2 CmdResetEvent2{ noop::vkCmdResetEvent2 };
    PFN_vkCmdWaitEvents2 CmdWaitEvents2{ noop::vkCmdWaitEvents2 };
    PFN_vkCmdBlitImage2 CmdBlitImage2{ noop::vkCmdBlitImage2 };
    PFN_vkCmdResolveImage2 CmdResolveImage2{ noop::vkCmdResolveImage2 };
    PFN_vkCmdBeginRendering CmdBeginRendering{ noop::vkCmdBeginRendering };
    PFN_vkCmdEndRendering CmdEndRendering{ noop::vkCmdEndRendering };
    PFN_vkCmdSetCullMode CmdSetCullMode{ noop::vkCmdSetCullMode };
    PFN_vkCmdSetFrontFace CmdSetFrontFace{ noop::vkCmdSetFrontFace };
    PFN_vkCmdSetPrimitiveTopology CmdSetPrimitiveTopology{ noop::vkCmdSetPrimitiveTopology };
    PFN_vkCmdSetViewportWithCount CmdSetViewportWithCount{ noop::vkCmdSetViewportWithCount };
    PFN_vkCmdSetScissorWithCount CmdSetScissorWithCount{ noop::vkCmdSetScissorWithCount };
    PFN_vkCmdBindVertexBuffers2 CmdBindVertexBuffers2{ noop::vkCmdBindVertexBuffers2 };
    PFN_vkCmdSetDepthTestEnable CmdSetDepthTestEnable{ noop::vkCmdSetDepthTestEnable };
    PFN_vkCmdSetDepthWriteEnable CmdSetDepthWriteEnable{ noop::vkCmdSetDepthWriteEnable };
    PFN_vkCmdSetDepthCompareOp CmdSetDepthCompareOp{ noop::vkCmdSetDepthCompareOp };
    PFN_vkCmdSetDepthBoundsTestEnable CmdSetDepthBoundsTestEnable{ noop::vkCmdSetDepthBoundsTestEnable };
    PFN_vkCmdSetStencilTestEnable CmdSetStencilTestEnable{ noop::vkCmdSetStencilTestEnable };
    PFN_vkCmdSetStencilOp CmdSetStencilOp{ noop::vkCmdSetStencilOp };
    PFN_vkCmdSetRasterizerDiscardEnable CmdSetRasterizerDiscardEnable{ noop::vkCmdSetRasterizerDiscardEnable };
    PFN_vkCmdSetDepthBiasEnable CmdSetDepthBiasEnable{ noop::vkCmdSetDepthBiasEnable };
    PFN_vkCmdSetPrimitiveRestartEnable CmdSetPrimitiveRestartEnable{ noop::vkCmdSetPrimitiveRestartEnable };
    PFN_vkMapMemory2 MapMemory2{ noop::vkMapMemory2 };
    PFN_vkUnmapMemory2 UnmapMemory2{ noop::vkUnmapMemory2 };
    PFN_vkGetDeviceImageSubresourceLayout GetDeviceImageSubresourceLayout{ noop::vkGetDeviceImageSubresourceLayout };
    PFN_vkGetImageSubresourceLayout2 GetImageSubresourceLayout2{ noop::vkGetImageSubresourceLayout2 };
    PFN_vkCopyMemoryToImage CopyMemoryToImage{ noop::vkCopyMemoryToImage };
    PFN_vkCopyImageToMemory CopyImageToMemory{ noop::vkCopyImageToMemory };
    PFN_vkCopyImageToImage CopyImageToImage{ noop::vkCopyImageToImage };
    PFN_vkTransitionImageLayout TransitionImageLayout{ noop::vkTransitionImageLayout };
    PFN_vkCmdPushDescriptorSet CmdPushDescriptorSet{ noop::vkCmdPushDescriptorSet };
    PFN_vkCmdPushDescriptorSetWithTemplate CmdPushDescriptorSetWithTemplate{ noop::vkCmdPushDescriptorSetWithTemplate };
    PFN_vkCmdBindDescriptorSets2 CmdBindDescriptorSets2{ noop::vkCmdBindDescriptorSets2 };
    PFN_vkCmdPushConstants2 CmdPushConstants2{ noop::vkCmdPushConstants2 };
    PFN_vkCmdPushDescriptorSet2 CmdPushDescriptorSet2{ noop::vkCmdPushDescriptorSet2 };
    PFN_vkCmdPushDescriptorSetWithTemplate2 CmdPushDescriptorSetWithTemplate2{ noop::vkCmdPushDescriptorSetWithTemplate2 };
    PFN_vkCmdSetLineStipple CmdSetLineStipple{ noop::vkCmdSetLineStipple };
    PFN_vkCmdBindIndexBuffer2 CmdBindIndexBuffer2{ noop::vkCmdBindIndexBuffer2 };
    PFN_vkGetRenderingAreaGranularity GetRenderingAreaGranularity{ noop::vkGetRenderingAreaGranularity };
    PFN_vkCmdSetRenderingAttachmentLocations CmdSetRenderingAttachmentLocations{ noop::vkCmdSetRenderingAttachmentLocations };
    PFN_vkCmdSetRenderingInputAttachmentIndices CmdSetRenderingInputAttachmentIndices{ noop::vkCmdSetRenderingInputAttachmentIndices };
    PFN_vkCreateSwapchainKHR CreateSwapchainKHR{ noop::vkCreateSwapchainKHR };
    PFN_vkDestroySwapchainKHR DestroySwapchainKHR{ noop::vkDestroySwapchainKHR };
    PFN_vkGetSwapchainImagesKHR GetSwapchainImagesKHR{ noop::vkGetSwapchainImagesKHR };
    PFN_vkAcquireNextImageKHR AcquireNextImageKHR{ noop::vkAcquireNextImageKHR };
    PFN_vkQueuePresentKHR QueuePresentKHR{ noop::vkQueuePresentKHR };
    PFN_vkGetDeviceGroupPresentCapabilitiesKHR GetDeviceGroupPresentCapabilitiesKHR{ noop::vkGetDeviceGroupPresentCapabilitiesKHR };
    PFN_vkGetDeviceGroupSurfacePresentModesKHR GetDeviceGroupSurfacePresentModesKHR{ noop::vkGetDeviceGroupSurfacePresentModesKHR };
    PFN_vkAcquireNextImage2KHR AcquireNextImage2KHR{ noop::vkAcquireNextImage2KHR };
    PFN_vkCreateSharedSwapchainsKHR CreateSharedSwapchainsKHR{ noop::vkCreateSharedSwapchainsKHR };
    PFN_vkCreateVideoSessionKHR CreateVideoSessionKHR{ noop::vkCreateVideoSessionKHR };
    PFN_vkDestroyVideoSessionKHR DestroyVideoSessionKHR{ noop::vkDestroyVideoSessionKHR };
    PFN_vkGetVideoSessionMemoryRequirementsKHR GetVideoSessionMemoryRequirementsKHR{ noop::vkGetVideoSessionMemoryRequirementsKHR };
    PFN_vkBindVideoSessionMemoryKHR BindVideoSessionMemoryKHR{ noop::vkBindVideoSessionMemoryKHR };
    PFN_vkCreateVideoSessionParametersKHR CreateVideoSessionParametersKHR{ noop::vkCreateVideoSessionParametersKHR };
    PFN_vkUpdateVideoSessionParametersKHR UpdateVideoSessionParametersKHR{ noop::vkUpdateVideoSessionParametersKHR };
    PFN_vkDestroyVideoSessionParametersKHR DestroyVideoSessionParametersKHR{ noop::vkDestroyVideoSessionParametersKHR };
    PFN_vkCmdBeginVideoCodingKHR CmdBeginVideoCodingKHR{ noop::vkCmdBeginVideoCodingKHR };
    PFN_vkCmdEndVideoCodingKHR CmdEndVideoCodingKHR{ noop::vkCmdEndVideoCodingKHR };
    PFN_vkCmdControlVideoCodingKHR CmdControlVideoCodingKHR{ noop::vkCmdControlVideoCodingKHR };
    PFN_vkCmdDecodeVideoKHR CmdDecodeVideoKHR{ noop::vkCmdDecodeVideoKHR };
    PFN_vkCmdBeginRenderingKHR CmdBeginRenderingKHR{ noop::vkCmdBeginRenderingKHR };
    PFN_vkCmdEndRenderingKHR CmdEndRenderingKHR{ noop::vkCmdEndRenderingKHR };
    PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR GetDeviceGroupPeerMemoryFeaturesKHR{ noop::vkGetDeviceGroupPeerMemoryFeaturesKHR };
    PFN_vkCmdSetDeviceMaskKHR CmdSetDeviceMaskKHR{ noop::vkCmdSetDeviceMaskKHR };
    PFN_vkCmdDispatchBaseKHR CmdDispatchBaseKHR{ noop::vkCmdDispatchBaseKHR };
    PFN_vkTrimCommandPoolKHR TrimCommandPoolKHR{ noop::vkTrimCommandPoolKHR };
    PFN_vkGetMemoryWin32HandleKHR GetMemoryWin32HandleKHR{ noop::vkGetMemoryWin32HandleKHR };
    PFN_vkGetMemoryWin32HandlePropertiesKHR GetMemoryWin32HandlePropertiesKHR{ noop::vkGetMemoryWin32HandlePropertiesKHR };
    PFN_vkGetMemoryFdKHR GetMemoryFdKHR{ noop::vkGetMemoryFdKHR };
    PFN_vkGetMemoryFdPropertiesKHR GetMemoryFdPropertiesKHR{ noop::vkGetMemoryFdPropertiesKHR };
    PFN_vkImportSemaphoreWin32HandleKHR ImportSemaphoreWin32HandleKHR{ noop::vkImportSemaphoreWin32HandleKHR };
    PFN_vkGetSemaphoreWin32HandleKHR GetSemaphoreWin32HandleKHR{ noop::vkGetSemaphoreWin32HandleKHR };
    PFN_vkImportSemaphoreFdKHR ImportSemaphoreFdKHR{ noop::vkImportSemaphoreFdKHR };
    PFN_vkGetSemaphoreFdKHR GetSemaphoreFdKHR{ noop::vkGetSemaphoreFdKHR };
    PFN_vkCmdPushDescriptorSetKHR CmdPushDescriptorSetKHR{ noop::vkCmdPushDescriptorSetKHR };
    PFN_vkCmdPushDescriptorSetWithTemplateKHR CmdPushDescriptorSetWithTemplateKHR{ noop::vkCmdPushDescriptorSetWithTemplateKHR };
    PFN_vkCreateDescriptorUpdateTemplateKHR CreateDescriptorUpdateTemplateKHR{ noop::vkCreateDescriptorUpdateTemplateKHR };
    PFN_vkDestroyDescriptorUpdateTemplateKHR DestroyDescriptorUpdateTemplateKHR{ noop::vkDestroyDescriptorUpdateTemplateKHR };
    PFN_vkUpdateDescriptorSetWithTemplateKHR UpdateDescriptorSetWithTemplateKHR{ noop::vkUpdateDescriptorSetWithTemplateKHR };
    PFN_vkCreateRenderPass2KHR CreateRenderPass2KHR{ noop::vkCreateRenderPass2KHR };
    PFN_vkCmdBeginRenderPass2KHR CmdBeginRenderPass2KHR{ noop::vkCmdBeginRenderPass2KHR };
    PFN_vkCmdNextSubpass2KHR CmdNextSubpass2KHR{ noop::vkCmdNextSubpass2KHR };
    PFN_vkCmdEndRenderPass2KHR CmdEndRenderPass2KHR{ noop::vkCmdEndRenderPass2KHR };
    PFN_vkGetSwapchainStatusKHR GetSwapchainStatusKHR{ noop::vkGetSwapchainStatusKHR };
    PFN_vkImportFenceWin32HandleKHR ImportFenceWin32HandleKHR{ noop::vkImportFenceWin32HandleKHR };
    PFN_vkGetFenceWin32HandleKHR GetFenceWin32HandleKHR{ noop::vkGetFenceWin32HandleKHR };
    PFN_vkImportFenceFdKHR ImportFenceFdKHR{ noop::vkImportFenceFdKHR };
    PFN_vkGetFenceFdKHR GetFenceFdKHR{ noop::vkGetFenceFdKHR };
    PFN_vkAcquireProfilingLockKHR AcquireProfilingLockKHR{ noop::vkAcquireProfilingLockKHR };
    PFN_vkReleaseProfilingLockKHR ReleaseProfilingLockKHR{ noop::vkReleaseProfilingLockKHR };
    PFN_vkGetImageMemoryRequirements2KHR GetImageMemoryRequirements2KHR{ noop::vkGetImageMemoryRequirements2KHR };
    PFN_vkGetBufferMemoryRequirements2KHR GetBufferMemoryRequirements2KHR{ noop::vkGetBufferMemoryRequirements2KHR };
    PFN_vkGetImageSparseMemoryRequirements2KHR GetImageSparseMemoryRequirements2KHR{ noop::vkGetImageSparseMemoryRequirements2KHR };
    PFN_vkCreateSamplerYcbcrConversionKHR CreateSamplerYcbcrConversionKHR{ noop::vkCreateSamplerYcbcrConversionKHR };
    PFN_vkDestroySamplerYcbcrConversionKHR DestroySamplerYcbcrConversionKHR{ noop::vkDestroySamplerYcbcrConversionKHR };
    PFN_vkBindBufferMemory2KHR BindBufferMemory2KHR{ noop::vkBindBufferMemory2KHR };
    PFN_vkBindImageMemory2KHR BindImageMemory2KHR{ noop::vkBindImageMemory2KHR };
    PFN_vkGetDescriptorSetLayoutSupportKHR GetDescriptorSetLayoutSupportKHR{ noop::vkGetDescriptorSetLayoutSupportKHR };
    PFN_vkCmdDrawIndirectCountKHR CmdDrawIndirectCountKHR{ noop::vkCmdDrawIndirectCountKHR };
    PFN_vkCmdDrawIndexedIndirectCountKHR CmdDrawIndexedIndirectCountKHR{ noop::vkCmdDrawIndexedIndirectCountKHR };
    PFN_vkGetSemaphoreCounterValueKHR GetSemaphoreCounterValueKHR{ noop::vkGetSemaphoreCounterValueKHR };
    PFN_vkWaitSemaphoresKHR WaitSemaphoresKHR{ noop::vkWaitSemaphoresKHR };
    PFN_vkSignalSemaphoreKHR SignalSemaphoreKHR{ noop::vkSignalSemaphoreKHR };
    PFN_vkCmdSetFragmentShadingRateKHR CmdSetFragmentShadingRateKHR{ noop::vkCmdSetFragmentShadingRateKHR };
    PFN_vkCmdSetRenderingAttachmentLocationsKHR CmdSetRenderingAttachmentLocationsKHR{ noop::vkCmdSetRenderingAttachmentLocationsKHR };
    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR CmdSetRenderingInputAttachmentIndicesKHR{ noop::vkCmdSetRenderingInputAttachmentIndicesKHR };
    PFN_vkWaitForPresentKHR WaitForPresentKHR{ noop::vkWaitForPresentKHR };
    PFN_vkGetBufferDeviceAddressKHR GetBufferDeviceAddressKHR{ noop::vkGetBufferDeviceAddressKHR };
    PFN_vkGetBufferOpaqueCaptureAddressKHR GetBufferOpaqueCaptureAddressKHR{ noop::vkGetBufferOpaqueCaptureAddressKHR };
    PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR GetDeviceMemoryOpaqueCaptureAddressKHR{ noop::vkGetDeviceMemoryOpaqueCaptureAddressKHR };
    PFN_vkCreateDeferredOperationKHR CreateDeferredOperationKHR{ noop::vkCreateDeferredOperationKHR };
    PFN_vkDestroyDeferredOperationKHR DestroyDeferredOperationKHR{ noop::vkDestroyDeferredOperationKHR };
    PFN_vkGetDeferredOperationMaxConcurrencyKHR GetDeferredOperationMaxConcurrencyKHR{ noop::vkGetDeferredOperationMaxConcurrencyKHR };
    PFN_vkGetDeferredOperationResultKHR GetDeferredOperationResultKHR{ noop::vkGetDeferredOperationResultKHR };
    PFN_vkDeferredOperationJoinKHR DeferredOperationJoinKHR{ noop::vkDeferredOperationJoinKHR };
    PFN_vkGetPipelineExecutablePropertiesKHR GetPipelineExecutablePropertiesKHR{ noop::vkGetPipelineExecutablePropertiesKHR };
    PFN_vkGetPipelineExecutableStatisticsKHR GetPipelineExecutableStatisticsKHR{ noop::vkGetPipelineExecutableStatisticsKHR };
    PFN_vkGetPipelineExecutableInternalRepresentationsKHR GetPipelineExecutableInternalRepresentationsKHR{ noop::vkGetPipelineExecutableInternalRepresentationsKHR };
    PFN_vkMapMemory2KHR MapMemory2KHR{ noop::vkMapMemory2KHR };
    PFN_vkUnmapMemory2KHR UnmapMemory2KHR{ noop::vkUnmapMemory2KHR };
    PFN_vkGetEncodedVideoSessionParametersKHR GetEncodedVideoSessionParametersKHR{ noop::vkGetEncodedVideoSessionParametersKHR };
    PFN_vkCmdEncodeVideoKHR CmdEncodeVideoKHR{ noop::vkCmdEncodeVideoKHR };
    PFN_vkCmdSetEvent2KHR CmdSetEvent2KHR{ noop::vkCmdSetEvent2KHR };
    PFN_vkCmdResetEvent2KHR CmdResetEvent2KHR{ noop::vkCmdResetEvent2KHR };
    PFN_vkCmdWaitEvents2KHR CmdWaitEvents2KHR{ noop::vkCmdWaitEvents2KHR };
    PFN_vkCmdPipelineBarrier2KHR CmdPipelineBarrier2KHR{ noop::vkCmdPipelineBarrier2KHR };
    PFN_vkCmdWriteTimestamp2KHR CmdWriteTimestamp2KHR{ noop::vkCmdWriteTimestamp2KHR };
    PFN_vkQueueSubmit2KHR QueueSubmit2KHR{ noop::vkQueueSubmit2KHR };
    PFN_vkCmdCopyBuffer2KHR CmdCopyBuffer2KHR{ noop::vkCmdCopyBuffer2KHR };
    PFN_vkCmdCopyImage2KHR CmdCopyImage2KHR{ noop::vkCmdCopyImage2KHR };
    PFN_vkCmdCopyBufferToImage2KHR CmdCopyBufferToImage2KHR{ noop::vkCmdCopyBufferToImage2KHR };
    PFN_vkCmdCopyImageToBuffer2KHR CmdCopyImageToBuffer2KHR{ noop::vkCmdCopyImageToBuffer2KHR };
    PFN_vkCmdBlitImage2KHR CmdBlitImage2KHR{ noop::vkCmdBlitImage2KHR };
    PFN_vkCmdResolveImage2KHR CmdResolveImage2KHR{ noop::vkCmdResolveImage2KHR };
    PFN_vkCmdTraceRaysIndirect2KHR CmdTraceRaysIndirect2KHR{ noop::vkCmdTraceRaysIndirect2KHR };
    PFN_vkGetDeviceBufferMemoryRequirementsKHR GetDeviceBufferMemoryRequirementsKHR{ noop::vkGetDeviceBufferMemoryRequirementsKHR };
    PFN_vkGetDeviceImageMemoryRequirementsKHR GetDeviceImageMemoryRequirementsKHR{ noop::vkGetDeviceImageMemoryRequirementsKHR };
    PFN_vkGetDeviceImageSparseMemoryRequirementsKHR GetDeviceImageSparseMemoryRequirementsKHR{ noop::vkGetDeviceImageSparseMemoryRequirementsKHR };
    PFN_vkCmdBindIndexBuffer2KHR CmdBindIndexBuffer2KHR{ noop::vkCmdBindIndexBuffer2KHR };
    PFN_vkGetRenderingAreaGranularityKHR GetRenderingAreaGranularityKHR{ noop::vkGetRenderingAreaGranularityKHR };
    PFN_vkGetDeviceImageSubresourceLayoutKHR GetDeviceImageSubresourceLayoutKHR{ noop::vkGetDeviceImageSubresourceLayoutKHR };
    PFN_vkGetImageSubresourceLayout2KHR GetImageSubresourceLayout2KHR{ noop::vkGetImageSubresourceLayout2KHR };
    PFN_vkWaitForPresent2KHR WaitForPresent2KHR{ noop::vkWaitForPresent2KHR };
    PFN_vkCreatePipelineBinariesKHR CreatePipelineBinariesKHR{ noop::vkCreatePipelineBinariesKHR };
    PFN_vkDestroyPipelineBinaryKHR DestroyPipelineBinaryKHR{ noop::vkDestroyPipelineBinaryKHR };
    PFN_vkGetPipelineKeyKHR GetPipelineKeyKHR{ noop::vkGetPipelineKeyKHR };
    PFN_vkGetPipelineBinaryDataKHR GetPipelineBinaryDataKHR{ noop::vkGetPipelineBinaryDataKHR };
    PFN_vkReleaseCapturedPipelineDataKHR ReleaseCapturedPipelineDataKHR{ noop::vkReleaseCapturedPipelineDataKHR };
    PFN_vkReleaseSwapchainImagesKHR ReleaseSwapchainImagesKHR{ noop::vkReleaseSwapchainImagesKHR };
    PFN_vkCmdSetLineStippleKHR CmdSetLineStippleKHR{ noop::vkCmdSetLineStippleKHR };
    PFN_vkGetCalibratedTimestampsKHR GetCalibratedTimestampsKHR{ noop::vkGetCalibratedTimestampsKHR };
    PFN_vkCmdBindDescriptorSets2KHR CmdBindDescriptorSets2KHR{ noop::vkCmdBindDescriptorSets2KHR };
    PFN_vkCmdPushConstants2KHR CmdPushConstants2KHR{ noop::vkCmdPushConstants2KHR };
    PFN_vkCmdPushDescriptorSet2KHR CmdPushDescriptorSet2KHR{ noop::vkCmdPushDescriptorSet2KHR };
    PFN_vkCmdPushDescriptorSetWithTemplate2KHR CmdPushDescriptorSetWithTemplate2KHR{ noop::vkCmdPushDescriptorSetWithTemplate2KHR };
    PFN_vkCmdSetDescriptorBufferOffsets2EXT CmdSetDescriptorBufferOffsets2EXT{ noop::vkCmdSetDescriptorBufferOffsets2EXT };
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT CmdBindDescriptorBufferEmbeddedSamplers2EXT{ noop::vkCmdBindDescriptorBufferEmbeddedSamplers2EXT };
    PFN_vkCmdCopyMemoryIndirectKHR CmdCopyMemoryIndirectKHR{ noop::vkCmdCopyMemoryIndirectKHR };
    PFN_vkCmdCopyMemoryToImageIndirectKHR CmdCopyMemoryToImageIndirectKHR{ noop::vkCmdCopyMemoryToImageIndirectKHR };
    PFN_vkCmdEndRendering2KHR CmdEndRendering2KHR{ noop::vkCmdEndRendering2KHR };
    PFN_vkFrameBoundaryANDROID FrameBoundaryANDROID{ noop::vkFrameBoundaryANDROID };
    PFN_vkDebugMarkerSetObjectTagEXT DebugMarkerSetObjectTagEXT{ noop::vkDebugMarkerSetObjectTagEXT };
    PFN_vkDebugMarkerSetObjectNameEXT DebugMarkerSetObjectNameEXT{ noop::vkDebugMarkerSetObjectNameEXT };
    PFN_vkCmdDebugMarkerBeginEXT CmdDebugMarkerBeginEXT{ noop::vkCmdDebugMarkerBeginEXT };
    PFN_vkCmdDebugMarkerEndEXT CmdDebugMarkerEndEXT{ noop::vkCmdDebugMarkerEndEXT };
    PFN_vkCmdDebugMarkerInsertEXT CmdDebugMarkerInsertEXT{ noop::vkCmdDebugMarkerInsertEXT };
    PFN_vkCmdBindTransformFeedbackBuffersEXT CmdBindTransformFeedbackBuffersEXT{ noop::vkCmdBindTransformFeedbackBuffersEXT };
    PFN_vkCmdBeginTransformFeedbackEXT CmdBeginTransformFeedbackEXT{ noop::vkCmdBeginTransformFeedbackEXT };
    PFN_vkCmdEndTransformFeedbackEXT CmdEndTransformFeedbackEXT{ noop::vkCmdEndTransformFeedbackEXT };
    PFN_vkCmdBeginQueryIndexedEXT CmdBeginQueryIndexedEXT{ noop::vkCmdBeginQueryIndexedEXT };
    PFN_vkCmdEndQueryIndexedEXT CmdEndQueryIndexedEXT{ noop::vkCmdEndQueryIndexedEXT };
    PFN_vkCmdDrawIndirectByteCountEXT CmdDrawIndirectByteCountEXT{ noop::vkCmdDrawIndirectByteCountEXT };
    PFN_vkGetImageViewHandleNVX GetImageViewHandleNVX{ noop::vkGetImageViewHandleNVX };
    PFN_vkGetImageViewHandle64NVX GetImageViewHandle64NVX{ noop::vkGetImageViewHandle64NVX };
    PFN_vkGetImageViewAddressNVX GetImageViewAddressNVX{ noop::vkGetImageViewAddressNVX };
    PFN_vkCmdDrawIndirectCountAMD CmdDrawIndirectCountAMD{ noop::vkCmdDrawIndirectCountAMD };
    PFN_vkCmdDrawIndexedIndirectCountAMD CmdDrawIndexedIndirectCountAMD{ noop::vkCmdDrawIndexedIndirectCountAMD };
    PFN_vkGetShaderInfoAMD GetShaderInfoAMD{ noop::vkGetShaderInfoAMD };
    PFN_vkGetMemoryWin32HandleNV GetMemoryWin32HandleNV{ noop::vkGetMemoryWin32HandleNV };
    PFN_vkCmdBeginConditionalRenderingEXT CmdBeginConditionalRenderingEXT{ noop::vkCmdBeginConditionalRenderingEXT };
    PFN_vkCmdEndConditionalRenderingEXT CmdEndConditionalRenderingEXT{ noop::vkCmdEndConditionalRenderingEXT };
    PFN_vkCmdSetViewportWScalingNV CmdSetViewportWScalingNV{ noop::vkCmdSetViewportWScalingNV };
    PFN_vkDisplayPowerControlEXT DisplayPowerControlEXT{ noop::vkDisplayPowerControlEXT };
    PFN_vkRegisterDeviceEventEXT RegisterDeviceEventEXT{ noop::vkRegisterDeviceEventEXT };
    PFN_vkRegisterDisplayEventEXT RegisterDisplayEventEXT{ noop::vkRegisterDisplayEventEXT };
    PFN_vkGetSwapchainCounterEXT GetSwapchainCounterEXT{ noop::vkGetSwapchainCounterEXT };
    PFN_vkGetRefreshCycleDurationGOOGLE GetRefreshCycleDurationGOOGLE{ noop::vkGetRefreshCycleDurationGOOGLE };
    PFN_vkGetPastPresentationTimingGOOGLE GetPastPresentationTimingGOOGLE{ noop::vkGetPastPresentationTimingGOOGLE };
    PFN_vkCmdSetDiscardRectangleEXT CmdSetDiscardRectangleEXT{ noop::vkCmdSetDiscardRectangleEXT };
    PFN_vkCmdSetDiscardRectangleEnableEXT CmdSetDiscardRectangleEnableEXT{ noop::vkCmdSetDiscardRectangleEnableEXT };
    PFN_vkCmdSetDiscardRectangleModeEXT CmdSetDiscardRectangleModeEXT{ noop::vkCmdSetDiscardRectangleModeEXT };
    PFN_vkSetHdrMetadataEXT SetHdrMetadataEXT{ noop::vkSetHdrMetadataEXT };
    PFN_vkQueueBeginDebugUtilsLabelEXT QueueBeginDebugUtilsLabelEXT{ noop::vkQueueBeginDebugUtilsLabelEXT };
    PFN_vkQueueEndDebugUtilsLabelEXT QueueEndDebugUtilsLabelEXT{ noop::vkQueueEndDebugUtilsLabelEXT };
    PFN_vkQueueInsertDebugUtilsLabelEXT QueueInsertDebugUtilsLabelEXT{ noop::vkQueueInsertDebugUtilsLabelEXT };
    PFN_vkCmdBeginDebugUtilsLabelEXT CmdBeginDebugUtilsLabelEXT{ noop::vkCmdBeginDebugUtilsLabelEXT };
    PFN_vkCmdEndDebugUtilsLabelEXT CmdEndDebugUtilsLabelEXT{ noop::vkCmdEndDebugUtilsLabelEXT };
    PFN_vkCmdInsertDebugUtilsLabelEXT CmdInsertDebugUtilsLabelEXT{ noop::vkCmdInsertDebugUtilsLabelEXT };
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID GetAndroidHardwareBufferPropertiesANDROID{ noop::vkGetAndroidHardwareBufferPropertiesANDROID };
    PFN_vkGetMemoryAndroidHardwareBufferANDROID GetMemoryAndroidHardwareBufferANDROID{ noop::vkGetMemoryAndroidHardwareBufferANDROID };
    PFN_vkCmdSetSampleLocationsEXT CmdSetSampleLocationsEXT{ noop::vkCmdSetSampleLocationsEXT };
    PFN_vkGetImageDrmFormatModifierPropertiesEXT GetImageDrmFormatModifierPropertiesEXT{ noop::vkGetImageDrmFormatModifierPropertiesEXT };
    PFN_vkCreateValidationCacheEXT CreateValidationCacheEXT{ noop::vkCreateValidationCacheEXT };
    PFN_vkDestroyValidationCacheEXT DestroyValidationCacheEXT{ noop::vkDestroyValidationCacheEXT };
    PFN_vkMergeValidationCachesEXT MergeValidationCachesEXT{ noop::vkMergeValidationCachesEXT };
    PFN_vkGetValidationCacheDataEXT GetValidationCacheDataEXT{ noop::vkGetValidationCacheDataEXT };
    PFN_vkCmdBindShadingRateImageNV CmdBindShadingRateImageNV{ noop::vkCmdBindShadingRateImageNV };
    PFN_vkCmdSetViewportShadingRatePaletteNV CmdSetViewportShadingRatePaletteNV{ noop::vkCmdSetViewportShadingRatePaletteNV };
    PFN_vkCmdSetCoarseSampleOrderNV CmdSetCoarseSampleOrderNV{ noop::vkCmdSetCoarseSampleOrderNV };
    PFN_vkCreateAccelerationStructureNV CreateAccelerationStructureNV{ noop::vkCreateAccelerationStructureNV };
    PFN_vkDestroyAccelerationStructureNV DestroyAccelerationStructureNV{ noop::vkDestroyAccelerationStructureNV };
    PFN_vkGetAccelerationStructureMemoryRequirementsNV GetAccelerationStructureMemoryRequirementsNV{ noop::vkGetAccelerationStructureMemoryRequirementsNV };
    PFN_vkBindAccelerationStructureMemoryNV BindAccelerationStructureMemoryNV{ noop::vkBindAccelerationStructureMemoryNV };
    PFN_vkCmdBuildAccelerationStructureNV CmdBuildAccelerationStructureNV{ noop::vkCmdBuildAccelerationStructureNV };
    PFN_vkCmdCopyAccelerationStructureNV CmdCopyAccelerationStructureNV{ noop::vkCmdCopyAccelerationStructureNV };
    PFN_vkCmdTraceRaysNV CmdTraceRaysNV{ noop::vkCmdTraceRaysNV };
    PFN_vkCreateRayTracingPipelinesNV CreateRayTracingPipelinesNV{ noop::vkCreateRayTracingPipelinesNV };
    PFN_vkGetRayTracingShaderGroupHandlesKHR GetRayTracingShaderGroupHandlesKHR{ noop::vkGetRayTracingShaderGroupHandlesKHR };
    PFN_vkGetRayTracingShaderGroupHandlesNV GetRayTracingShaderGroupHandlesNV{ noop::vkGetRayTracingShaderGroupHandlesNV };
    PFN_vkGetAccelerationStructureHandleNV GetAccelerationStructureHandleNV{ noop::vkGetAccelerationStructureHandleNV };
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV CmdWriteAccelerationStructuresPropertiesNV{ noop::vkCmdWriteAccelerationStructuresPropertiesNV };
    PFN_vkCompileDeferredNV CompileDeferredNV{ noop::vkCompileDeferredNV };
    PFN_vkGetMemoryHostPointerPropertiesEXT GetMemoryHostPointerPropertiesEXT{ noop::vkGetMemoryHostPointerPropertiesEXT };
    PFN_vkCmdWriteBufferMarkerAMD CmdWriteBufferMarkerAMD{ noop::vkCmdWriteBufferMarkerAMD };
    PFN_vkCmdWriteBufferMarker2AMD CmdWriteBufferMarker2AMD{ noop::vkCmdWriteBufferMarker2AMD };
    PFN_vkGetCalibratedTimestampsEXT GetCalibratedTimestampsEXT{ noop::vkGetCalibratedTimestampsEXT };
    PFN_vkCmdDrawMeshTasksNV CmdDrawMeshTasksNV{ noop::vkCmdDrawMeshTasksNV };
    PFN_vkCmdDrawMeshTasksIndirectNV CmdDrawMeshTasksIndirectNV{ noop::vkCmdDrawMeshTasksIndirectNV };
    PFN_vkCmdDrawMeshTasksIndirectCountNV CmdDrawMeshTasksIndirectCountNV{ noop::vkCmdDrawMeshTasksIndirectCountNV };
    PFN_vkCmdSetExclusiveScissorEnableNV CmdSetExclusiveScissorEnableNV{ noop::vkCmdSetExclusiveScissorEnableNV };
    PFN_vkCmdSetExclusiveScissorNV CmdSetExclusiveScissorNV{ noop::vkCmdSetExclusiveScissorNV };
    PFN_vkCmdSetCheckpointNV CmdSetCheckpointNV{ noop::vkCmdSetCheckpointNV };
    PFN_vkGetQueueCheckpointDataNV GetQueueCheckpointDataNV{ noop::vkGetQueueCheckpointDataNV };
    PFN_vkGetQueueCheckpointData2NV GetQueueCheckpointData2NV{ noop::vkGetQueueCheckpointData2NV };
    PFN_vkSetSwapchainPresentTimingQueueSizeEXT SetSwapchainPresentTimingQueueSizeEXT{ noop::vkSetSwapchainPresentTimingQueueSizeEXT };
    PFN_vkGetSwapchainTimingPropertiesEXT GetSwapchainTimingPropertiesEXT{ noop::vkGetSwapchainTimingPropertiesEXT };
    PFN_vkGetSwapchainTimeDomainPropertiesEXT GetSwapchainTimeDomainPropertiesEXT{ noop::vkGetSwapchainTimeDomainPropertiesEXT };
    PFN_vkGetPastPresentationTimingEXT GetPastPresentationTimingEXT{ noop::vkGetPastPresentationTimingEXT };
    PFN_vkInitializePerformanceApiINTEL InitializePerformanceApiINTEL{ noop::vkInitializePerformanceApiINTEL };
    PFN_vkUninitializePerformanceApiINTEL UninitializePerformanceApiINTEL{ noop::vkUninitializePerformanceApiINTEL };
    PFN_vkCmdSetPerformanceMarkerINTEL CmdSetPerformanceMarkerINTEL{ noop::vkCmdSetPerformanceMarkerINTEL };
    PFN_vkCmdSetPerformanceStreamMarkerINTEL CmdSetPerformanceStreamMarkerINTEL{ noop::vkCmdSetPerformanceStreamMarkerINTEL };
    PFN_vkCmdSetPerformanceOverrideINTEL CmdSetPerformanceOverrideINTEL{ noop::vkCmdSetPerformanceOverrideINTEL };
    PFN_vkAcquirePerformanceConfigurationINTEL AcquirePerformanceConfigurationINTEL{ noop::vkAcquirePerformanceConfigurationINTEL };
    PFN_vkReleasePerformanceConfigurationINTEL ReleasePerformanceConfigurationINTEL{ noop::vkReleasePerformanceConfigurationINTEL };
    PFN_vkQueueSetPerformanceConfigurationINTEL QueueSetPerformanceConfigurationINTEL{ noop::vkQueueSetPerformanceConfigurationINTEL };
    PFN_vkGetPerformanceParameterINTEL GetPerformanceParameterINTEL{ noop::vkGetPerformanceParameterINTEL };
    PFN_vkSetLocalDimmingAMD SetLocalDimmingAMD{ noop::vkSetLocalDimmingAMD };
    PFN_vkGetBufferDeviceAddressEXT GetBufferDeviceAddressEXT{ noop::vkGetBufferDeviceAddressEXT };
    PFN_vkAcquireFullScreenExclusiveModeEXT AcquireFullScreenExclusiveModeEXT{ noop::vkAcquireFullScreenExclusiveModeEXT };
    PFN_vkReleaseFullScreenExclusiveModeEXT ReleaseFullScreenExclusiveModeEXT{ noop::vkReleaseFullScreenExclusiveModeEXT };
    PFN_vkGetDeviceGroupSurfacePresentModes2EXT GetDeviceGroupSurfacePresentModes2EXT{ noop::vkGetDeviceGroupSurfacePresentModes2EXT };
    PFN_vkCmdSetLineStippleEXT CmdSetLineStippleEXT{ noop::vkCmdSetLineStippleEXT };
    PFN_vkResetQueryPoolEXT ResetQueryPoolEXT{ noop::vkResetQueryPoolEXT };
    PFN_vkCmdSetCullModeEXT CmdSetCullModeEXT{ noop::vkCmdSetCullModeEXT };
    PFN_vkCmdSetFrontFaceEXT CmdSetFrontFaceEXT{ noop::vkCmdSetFrontFaceEXT };
    PFN_vkCmdSetPrimitiveTopologyEXT CmdSetPrimitiveTopologyEXT{ noop::vkCmdSetPrimitiveTopologyEXT };
    PFN_vkCmdSetViewportWithCountEXT CmdSetViewportWithCountEXT{ noop::vkCmdSetViewportWithCountEXT };
    PFN_vkCmdSetScissorWithCountEXT CmdSetScissorWithCountEXT{ noop::vkCmdSetScissorWithCountEXT };
    PFN_vkCmdBindVertexBuffers2EXT CmdBindVertexBuffers2EXT{ noop::vkCmdBindVertexBuffers2EXT };
    PFN_vkCmdSetDepthTestEnableEXT CmdSetDepthTestEnableEXT{ noop::vkCmdSetDepthTestEnableEXT };
    PFN_vkCmdSetDepthWriteEnableEXT CmdSetDepthWriteEnableEXT{ noop::vkCmdSetDepthWriteEnableEXT };
    PFN_vkCmdSetDepthCompareOpEXT CmdSetDepthCompareOpEXT{ noop::vkCmdSetDepthCompareOpEXT };
    PFN_vkCmdSetDepthBoundsTestEnableEXT CmdSetDepthBoundsTestEnableEXT{ noop::vkCmdSetDepthBoundsTestEnableEXT };
    PFN_vkCmdSetStencilTestEnableEXT CmdSetStencilTestEnableEXT{ noop::vkCmdSetStencilTestEnableEXT };
    PFN_vkCmdSetStencilOpEXT CmdSetStencilOpEXT{ noop::vkCmdSetStencilOpEXT };
    PFN_vkCopyMemoryToImageEXT CopyMemoryToImageEXT{ noop::vkCopyMemoryToImageEXT };
    PFN_vkCopyImageToMemoryEXT CopyImageToMemoryEXT{ noop::vkCopyImageToMemoryEXT };
    PFN_vkCopyImageToImageEXT CopyImageToImageEXT{ noop::vkCopyImageToImageEXT };
    PFN_vkTransitionImageLayoutEXT TransitionImageLayoutEXT{ noop::vkTransitionImageLayoutEXT };
    PFN_vkGetImageSubresourceLayout2EXT GetImageSubresourceLayout2EXT{ noop::vkGetImageSubresourceLayout2EXT };
    PFN_vkReleaseSwapchainImagesEXT ReleaseSwapchainImagesEXT{ noop::vkReleaseSwapchainImagesEXT };
    PFN_vkGetGeneratedCommandsMemoryRequirementsNV GetGeneratedCommandsMemoryRequirementsNV{ noop::vkGetGeneratedCommandsMemoryRequirementsNV };
    PFN_vkCmdPreprocessGeneratedCommandsNV CmdPreprocessGeneratedCommandsNV{ noop::vkCmdPreprocessGeneratedCommandsNV };
    PFN_vkCmdExecuteGeneratedCommandsNV CmdExecuteGeneratedCommandsNV{ noop::vkCmdExecuteGeneratedCommandsNV };
    PFN_vkCmdBindPipelineShaderGroupNV CmdBindPipelineShaderGroupNV{ noop::vkCmdBindPipelineShaderGroupNV };
    PFN_vkCreateIndirectCommandsLayoutNV CreateIndirectCommandsLayoutNV{ noop::vkCreateIndirectCommandsLayoutNV };
    PFN_vkDestroyIndirectCommandsLayoutNV DestroyIndirectCommandsLayoutNV{ noop::vkDestroyIndirectCommandsLayoutNV };
    PFN_vkCmdSetDepthBias2EXT CmdSetDepthBias2EXT{ noop::vkCmdSetDepthBias2EXT };
    PFN_vkCreatePrivateDataSlotEXT CreatePrivateDataSlotEXT{ noop::vkCreatePrivateDataSlotEXT };
    PFN_vkDestroyPrivateDataSlotEXT DestroyPrivateDataSlotEXT{ noop::vkDestroyPrivateDataSlotEXT };
    PFN_vkSetPrivateDataEXT SetPrivateDataEXT{ noop::vkSetPrivateDataEXT };
    PFN_vkGetPrivateDataEXT GetPrivateDataEXT{ noop::vkGetPrivateDataEXT };
    PFN_vkCmdDispatchTileQCOM CmdDispatchTileQCOM{ noop::vkCmdDispatchTileQCOM };
    PFN_vkCmdBeginPerTileExecutionQCOM CmdBeginPerTileExecutionQCOM{ noop::vkCmdBeginPerTileExecutionQCOM };
    PFN_vkCmdEndPerTileExecutionQCOM CmdEndPerTileExecutionQCOM{ noop::vkCmdEndPerTileExecutionQCOM };
    PFN_vkGetDescriptorSetLayoutSizeEXT GetDescriptorSetLayoutSizeEXT{ noop::vkGetDescriptorSetLayoutSizeEXT };
    PFN_vkGetDescriptorSetLayoutBindingOffsetEXT GetDescriptorSetLayoutBindingOffsetEXT{ noop::vkGetDescriptorSetLayoutBindingOffsetEXT };
    PFN_vkGetDescriptorEXT GetDescriptorEXT{ noop::vkGetDescriptorEXT };
    PFN_vkCmdBindDescriptorBuffersEXT CmdBindDescriptorBuffersEXT{ noop::vkCmdBindDescriptorBuffersEXT };
    PFN_vkCmdSetDescriptorBufferOffsetsEXT CmdSetDescriptorBufferOffsetsEXT{ noop::vkCmdSetDescriptorBufferOffsetsEXT };
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT CmdBindDescriptorBufferEmbeddedSamplersEXT{ noop::vkCmdBindDescriptorBufferEmbeddedSamplersEXT };
    PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT GetBufferOpaqueCaptureDescriptorDataEXT{ noop::vkGetBufferOpaqueCaptureDescriptorDataEXT };
    PFN_vkGetImageOpaqueCaptureDescriptorDataEXT GetImageOpaqueCaptureDescriptorDataEXT{ noop::vkGetImageOpaqueCaptureDescriptorDataEXT };
    PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT GetImageViewOpaqueCaptureDescriptorDataEXT{ noop::vkGetImageViewOpaqueCaptureDescriptorDataEXT };
    PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT GetSamplerOpaqueCaptureDescriptorDataEXT{ noop::vkGetSamplerOpaqueCaptureDescriptorDataEXT };
    PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT GetAccelerationStructureOpaqueCaptureDescriptorDataEXT{ noop::vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT };
    PFN_vkCmdSetFragmentShadingRateEnumNV CmdSetFragmentShadingRateEnumNV{ noop::vkCmdSetFragmentShadingRateEnumNV };
    PFN_vkGetDeviceFaultInfoEXT GetDeviceFaultInfoEXT{ noop::vkGetDeviceFaultInfoEXT };
    PFN_vkCmdSetVertexInputEXT CmdSetVertexInputEXT{ noop::vkCmdSetVertexInputEXT };
    PFN_vkGetMemoryZirconHandleFUCHSIA GetMemoryZirconHandleFUCHSIA{ noop::vkGetMemoryZirconHandleFUCHSIA };
    PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA GetMemoryZirconHandlePropertiesFUCHSIA{ noop::vkGetMemoryZirconHandlePropertiesFUCHSIA };
    PFN_vkImportSemaphoreZirconHandleFUCHSIA ImportSemaphoreZirconHandleFUCHSIA{ noop::vkImportSemaphoreZirconHandleFUCHSIA };
    PFN_vkGetSemaphoreZirconHandleFUCHSIA GetSemaphoreZirconHandleFUCHSIA{ noop::vkGetSemaphoreZirconHandleFUCHSIA };
    PFN_vkCmdBindInvocationMaskHUAWEI CmdBindInvocationMaskHUAWEI{ noop::vkCmdBindInvocationMaskHUAWEI };
    PFN_vkGetMemoryRemoteAddressNV GetMemoryRemoteAddressNV{ noop::vkGetMemoryRemoteAddressNV };
    PFN_vkCmdSetPatchControlPointsEXT CmdSetPatchControlPointsEXT{ noop::vkCmdSetPatchControlPointsEXT };
    PFN_vkCmdSetRasterizerDiscardEnableEXT CmdSetRasterizerDiscardEnableEXT{ noop::vkCmdSetRasterizerDiscardEnableEXT };
    PFN_vkCmdSetDepthBiasEnableEXT CmdSetDepthBiasEnableEXT{ noop::vkCmdSetDepthBiasEnableEXT };
    PFN_vkCmdSetLogicOpEXT CmdSetLogicOpEXT{ noop::vkCmdSetLogicOpEXT };
    PFN_vkCmdSetPrimitiveRestartEnableEXT CmdSetPrimitiveRestartEnableEXT{ noop::vkCmdSetPrimitiveRestartEnableEXT };
    PFN_vkCmdSetColorWriteEnableEXT CmdSetColorWriteEnableEXT{ noop::vkCmdSetColorWriteEnableEXT };
    PFN_vkCmdDrawMultiEXT CmdDrawMultiEXT{ noop::vkCmdDrawMultiEXT };
    PFN_vkCmdDrawMultiIndexedEXT CmdDrawMultiIndexedEXT{ noop::vkCmdDrawMultiIndexedEXT };
    PFN_vkCreateMicromapEXT CreateMicromapEXT{ noop::vkCreateMicromapEXT };
    PFN_vkDestroyMicromapEXT DestroyMicromapEXT{ noop::vkDestroyMicromapEXT };
    PFN_vkCmdBuildMicromapsEXT CmdBuildMicromapsEXT{ noop::vkCmdBuildMicromapsEXT };
    PFN_vkBuildMicromapsEXT BuildMicromapsEXT{ noop::vkBuildMicromapsEXT };
    PFN_vkCopyMicromapEXT CopyMicromapEXT{ noop::vkCopyMicromapEXT };
    PFN_vkCopyMicromapToMemoryEXT CopyMicromapToMemoryEXT{ noop::vkCopyMicromapToMemoryEXT };
    PFN_vkCopyMemoryToMicromapEXT CopyMemoryToMicromapEXT{ noop::vkCopyMemoryToMicromapEXT };
    PFN_vkWriteMicromapsPropertiesEXT WriteMicromapsPropertiesEXT{ noop::vkWriteMicromapsPropertiesEXT };
    PFN_vkCmdCopyMicromapEXT CmdCopyMicromapEXT{ noop::vkCmdCopyMicromapEXT };
    PFN_vkCmdCopyMicromapToMemoryEXT CmdCopyMicromapToMemoryEXT{ noop::vkCmdCopyMicromapToMemoryEXT };
    PFN_vkCmdCopyMemoryToMicromapEXT CmdCopyMemoryToMicromapEXT{ noop::vkCmdCopyMemoryToMicromapEXT };
    PFN_vkCmdWriteMicromapsPropertiesEXT CmdWriteMicromapsPropertiesEXT{ noop::vkCmdWriteMicromapsPropertiesEXT };
    PFN_vkGetDeviceMicromapCompatibilityEXT GetDeviceMicromapCompatibilityEXT{ noop::vkGetDeviceMicromapCompatibilityEXT };
    PFN_vkGetMicromapBuildSizesEXT GetMicromapBuildSizesEXT{ noop::vkGetMicromapBuildSizesEXT };
    PFN_vkCmdDrawClusterHUAWEI CmdDrawClusterHUAWEI{ noop::vkCmdDrawClusterHUAWEI };
    PFN_vkCmdDrawClusterIndirectHUAWEI CmdDrawClusterIndirectHUAWEI{ noop::vkCmdDrawClusterIndirectHUAWEI };
    PFN_vkSetDeviceMemoryPriorityEXT SetDeviceMemoryPriorityEXT{ noop::vkSetDeviceMemoryPriorityEXT };
    PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE GetDescriptorSetLayoutHostMappingInfoVALVE{ noop::vkGetDescriptorSetLayoutHostMappingInfoVALVE };
    PFN_vkGetDescriptorSetHostMappingVALVE GetDescriptorSetHostMappingVALVE{ noop::vkGetDescriptorSetHostMappingVALVE };
    PFN_vkGetPipelineIndirectMemoryRequirementsNV GetPipelineIndirectMemoryRequirementsNV{ noop::vkGetPipelineIndirectMemoryRequirementsNV };
    PFN_vkCmdUpdatePipelineIndirectBufferNV CmdUpdatePipelineIndirectBufferNV{ noop::vkCmdUpdatePipelineIndirectBufferNV };
    PFN_vkGetPipelineIndirectDeviceAddressNV GetPipelineIndirectDeviceAddressNV{ noop::vkGetPipelineIndirectDeviceAddressNV };
    PFN_vkCmdSetDepthClampEnableEXT CmdSetDepthClampEnableEXT{ noop::vkCmdSetDepthClampEnableEXT };
    PFN_vkCmdSetPolygonModeEXT CmdSetPolygonModeEXT{ noop::vkCmdSetPolygonModeEXT };
    PFN_vkCmdSetRasterizationSamplesEXT CmdSetRasterizationSamplesEXT{ noop::vkCmdSetRasterizationSamplesEXT };
    PFN_vkCmdSetSampleMaskEXT CmdSetSampleMaskEXT{ noop::vkCmdSetSampleMaskEXT };
    PFN_vkCmdSetAlphaToCoverageEnableEXT CmdSetAlphaToCoverageEnableEXT{ noop::vkCmdSetAlphaToCoverageEnableEXT };
    PFN_vkCmdSetAlphaToOneEnableEXT CmdSetAlphaToOneEnableEXT{ noop::vkCmdSetAlphaToOneEnableEXT };
    PFN_vkCmdSetLogicOpEnableEXT CmdSetLogicOpEnableEXT{ noop::vkCmdSetLogicOpEnableEXT };
    PFN_vkCmdSetColorBlendEnableEXT CmdSetColorBlendEnableEXT{ noop::vkCmdSetColorBlendEnableEXT };
    PFN_vkCmdSetColorBlendEquationEXT CmdSetColorBlendEquationEXT{ noop::vkCmdSetColorBlendEquationEXT };
    PFN_vkCmdSetColorWriteMaskEXT CmdSetColorWriteMaskEXT{ noop::vkCmdSetColorWriteMaskEXT };
    PFN_vkCmdSetTessellationDomainOriginEXT CmdSetTessellationDomainOriginEXT{ noop::vkCmdSetTessellationDomainOriginEXT };
    PFN_vkCmdSetRasterizationStreamEXT CmdSetRasterizationStreamEXT{ noop::vkCmdSetRasterizationStreamEXT };
    PFN_vkCmdSetConservativeRasterizationModeEXT CmdSetConservativeRasterizationModeEXT{ noop::vkCmdSetConservativeRasterizationModeEXT };
    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT CmdSetExtraPrimitiveOverestimationSizeEXT{ noop::vkCmdSetExtraPrimitiveOverestimationSizeEXT };
    PFN_vkCmdSetDepthClipEnableEXT CmdSetDepthClipEnableEXT{ noop::vkCmdSetDepthClipEnableEXT };
    PFN_vkCmdSetSampleLocationsEnableEXT CmdSetSampleLocationsEnableEXT{ noop::vkCmdSetSampleLocationsEnableEXT };
    PFN_vkCmdSetColorBlendAdvancedEXT CmdSetColorBlendAdvancedEXT{ noop::vkCmdSetColorBlendAdvancedEXT };
    PFN_vkCmdSetProvokingVertexModeEXT CmdSetProvokingVertexModeEXT{ noop::vkCmdSetProvokingVertexModeEXT };
    PFN_vkCmdSetLineRasterizationModeEXT CmdSetLineRasterizationModeEXT{ noop::vkCmdSetLineRasterizationModeEXT };
    PFN_vkCmdSetLineStippleEnableEXT CmdSetLineStippleEnableEXT{ noop::vkCmdSetLineStippleEnableEXT };
    PFN_vkCmdSetDepthClipNegativeOneToOneEXT CmdSetDepthClipNegativeOneToOneEXT{ noop::vkCmdSetDepthClipNegativeOneToOneEXT };
    PFN_vkCmdSetViewportWScalingEnableNV CmdSetViewportWScalingEnableNV{ noop::vkCmdSetViewportWScalingEnableNV };
    PFN_vkCmdSetViewportSwizzleNV CmdSetViewportSwizzleNV{ noop::vkCmdSetViewportSwizzleNV };
    PFN_vkCmdSetCoverageToColorEnableNV CmdSetCoverageToColorEnableNV{ noop::vkCmdSetCoverageToColorEnableNV };
    PFN_vkCmdSetCoverageToColorLocationNV CmdSetCoverageToColorLocationNV{ noop::vkCmdSetCoverageToColorLocationNV };
    PFN_vkCmdSetCoverageModulationModeNV CmdSetCoverageModulationModeNV{ noop::vkCmdSetCoverageModulationModeNV };
    PFN_vkCmdSetCoverageModulationTableEnableNV CmdSetCoverageModulationTableEnableNV{ noop::vkCmdSetCoverageModulationTableEnableNV };
    PFN_vkCmdSetCoverageModulationTableNV CmdSetCoverageModulationTableNV{ noop::vkCmdSetCoverageModulationTableNV };
    PFN_vkCmdSetShadingRateImageEnableNV CmdSetShadingRateImageEnableNV{ noop::vkCmdSetShadingRateImageEnableNV };
    PFN_vkCmdSetRepresentativeFragmentTestEnableNV CmdSetRepresentativeFragmentTestEnableNV{ noop::vkCmdSetRepresentativeFragmentTestEnableNV };
    PFN_vkCmdSetCoverageReductionModeNV CmdSetCoverageReductionModeNV{ noop::vkCmdSetCoverageReductionModeNV };
    PFN_vkGetShaderModuleIdentifierEXT GetShaderModuleIdentifierEXT{ noop::vkGetShaderModuleIdentifierEXT };
    PFN_vkGetShaderModuleCreateInfoIdentifierEXT GetShaderModuleCreateInfoIdentifierEXT{ noop::vkGetShaderModuleCreateInfoIdentifierEXT };
    PFN_vkCreateOpticalFlowSessionNV CreateOpticalFlowSessionNV{ noop::vkCreateOpticalFlowSessionNV };
    PFN_vkDestroyOpticalFlowSessionNV DestroyOpticalFlowSessionNV{ noop::vkDestroyOpticalFlowSessionNV };
    PFN_vkBindOpticalFlowSessionImageNV BindOpticalFlowSessionImageNV{ noop::vkBindOpticalFlowSessionImageNV };
    PFN_vkCmdOpticalFlowExecuteNV CmdOpticalFlowExecuteNV{ noop::vkCmdOpticalFlowExecuteNV };
    PFN_vkAntiLagUpdateAMD AntiLagUpdateAMD{ noop::vkAntiLagUpdateAMD };
    PFN_vkCreateShadersEXT CreateShadersEXT{ noop::vkCreateShadersEXT };
    PFN_vkDestroyShaderEXT DestroyShaderEXT{ noop::vkDestroyShaderEXT };
    PFN_vkGetShaderBinaryDataEXT GetShaderBinaryDataEXT{ noop::vkGetShaderBinaryDataEXT };
    PFN_vkCmdBindShadersEXT CmdBindShadersEXT{ noop::vkCmdBindShadersEXT };
    PFN_vkCmdSetDepthClampRangeEXT CmdSetDepthClampRangeEXT{ noop::vkCmdSetDepthClampRangeEXT };
    PFN_vkGetFramebufferTilePropertiesQCOM GetFramebufferTilePropertiesQCOM{ noop::vkGetFramebufferTilePropertiesQCOM };
    PFN_vkGetDynamicRenderingTilePropertiesQCOM GetDynamicRenderingTilePropertiesQCOM{ noop::vkGetDynamicRenderingTilePropertiesQCOM };
    PFN_vkConvertCooperativeVectorMatrixNV ConvertCooperativeVectorMatrixNV{ noop::vkConvertCooperativeVectorMatrixNV };
    PFN_vkCmdConvertCooperativeVectorMatrixNV CmdConvertCooperativeVectorMatrixNV{ noop::vkCmdConvertCooperativeVectorMatrixNV };
    PFN_vkSetLatencySleepModeNV SetLatencySleepModeNV{ noop::vkSetLatencySleepModeNV };
    PFN_vkLatencySleepNV LatencySleepNV{ noop::vkLatencySleepNV };
    PFN_vkSetLatencyMarkerNV SetLatencyMarkerNV{ noop::vkSetLatencyMarkerNV };
    PFN_vkGetLatencyTimingsNV GetLatencyTimingsNV{ noop::vkGetLatencyTimingsNV };
    PFN_vkQueueNotifyOutOfBandNV QueueNotifyOutOfBandNV{ noop::vkQueueNotifyOutOfBandNV };
    PFN_vkCreateDataGraphPipelinesARM CreateDataGraphPipelinesARM{ noop::vkCreateDataGraphPipelinesARM };
    PFN_vkCreateDataGraphPipelineSessionARM CreateDataGraphPipelineSessionARM{ noop::vkCreateDataGraphPipelineSessionARM };
    PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM GetDataGraphPipelineSessionBindPointRequirementsARM{ noop::vkGetDataGraphPipelineSessionBindPointRequirementsARM };
    PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM GetDataGraphPipelineSessionMemoryRequirementsARM{ noop::vkGetDataGraphPipelineSessionMemoryRequirementsARM };
    PFN_vkBindDataGraphPipelineSessionMemoryARM BindDataGraphPipelineSessionMemoryARM{ noop::vkBindDataGraphPipelineSessionMemoryARM };
    PFN_vkDestroyDataGraphPipelineSessionARM DestroyDataGraphPipelineSessionARM{ noop::vkDestroyDataGraphPipelineSessionARM };
    PFN_vkCmdDispatchDataGraphARM CmdDispatchDataGraphARM{ noop::vkCmdDispatchDataGraphARM };
    PFN_vkGetDataGraphPipelineAvailablePropertiesARM GetDataGraphPipelineAvailablePropertiesARM{ noop::vkGetDataGraphPipelineAvailablePropertiesARM };
    PFN_vkGetDataGraphPipelinePropertiesARM GetDataGraphPipelinePropertiesARM{ noop::vkGetDataGraphPipelinePropertiesARM };
    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT CmdSetAttachmentFeedbackLoopEnableEXT{ noop::vkCmdSetAttachmentFeedbackLoopEnableEXT };
    PFN_vkCmdBindTileMemoryQCOM CmdBindTileMemoryQCOM{ noop::vkCmdBindTileMemoryQCOM };
    PFN_vkCmdDecompressMemoryEXT CmdDecompressMemoryEXT{ noop::vkCmdDecompressMemoryEXT };
    PFN_vkCmdDecompressMemoryIndirectCountEXT CmdDecompressMemoryIndirectCountEXT{ noop::vkCmdDecompressMemoryIndirectCountEXT };
    PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV GetPartitionedAccelerationStructuresBuildSizesNV{ noop::vkGetPartitionedAccelerationStructuresBuildSizesNV };
    PFN_vkCmdBuildPartitionedAccelerationStructuresNV CmdBuildPartitionedAccelerationStructuresNV{ noop::vkCmdBuildPartitionedAccelerationStructuresNV };
    PFN_vkGetGeneratedCommandsMemoryRequirementsEXT GetGeneratedCommandsMemoryRequirementsEXT{ noop::vkGetGeneratedCommandsMemoryRequirementsEXT };
    PFN_vkCmdPreprocessGeneratedCommandsEXT CmdPreprocessGeneratedCommandsEXT{ noop::vkCmdPreprocessGeneratedCommandsEXT };
    PFN_vkCmdExecuteGeneratedCommandsEXT CmdExecuteGeneratedCommandsEXT{ noop::vkCmdExecuteGeneratedCommandsEXT };
    PFN_vkCreateIndirectCommandsLayoutEXT CreateIndirectCommandsLayoutEXT{ noop::vkCreateIndirectCommandsLayoutEXT };
    PFN_vkDestroyIndirectCommandsLayoutEXT DestroyIndirectCommandsLayoutEXT{ noop::vkDestroyIndirectCommandsLayoutEXT };
    PFN_vkCreateIndirectExecutionSetEXT CreateIndirectExecutionSetEXT{ noop::vkCreateIndirectExecutionSetEXT };
    PFN_vkDestroyIndirectExecutionSetEXT DestroyIndirectExecutionSetEXT{ noop::vkDestroyIndirectExecutionSetEXT };
    PFN_vkUpdateIndirectExecutionSetPipelineEXT UpdateIndirectExecutionSetPipelineEXT{ noop::vkUpdateIndirectExecutionSetPipelineEXT };
    PFN_vkUpdateIndirectExecutionSetShaderEXT UpdateIndirectExecutionSetShaderEXT{ noop::vkUpdateIndirectExecutionSetShaderEXT };
    PFN_vkGetMemoryMetalHandleEXT GetMemoryMetalHandleEXT{ noop::vkGetMemoryMetalHandleEXT };
    PFN_vkGetMemoryMetalHandlePropertiesEXT GetMemoryMetalHandlePropertiesEXT{ noop::vkGetMemoryMetalHandlePropertiesEXT };
    PFN_vkCmdEndRendering2EXT CmdEndRendering2EXT{ noop::vkCmdEndRendering2EXT };
    PFN_vkCmdBeginCustomResolveEXT CmdBeginCustomResolveEXT{ noop::vkCmdBeginCustomResolveEXT };
    PFN_vkCreateAccelerationStructureKHR CreateAccelerationStructureKHR{ noop::vkCreateAccelerationStructureKHR };
    PFN_vkDestroyAccelerationStructureKHR DestroyAccelerationStructureKHR{ noop::vkDestroyAccelerationStructureKHR };
    PFN_vkCmdBuildAccelerationStructuresKHR CmdBuildAccelerationStructuresKHR{ noop::vkCmdBuildAccelerationStructuresKHR };
    PFN_vkCmdBuildAccelerationStructuresIndirectKHR CmdBuildAccelerationStructuresIndirectKHR{ noop::vkCmdBuildAccelerationStructuresIndirectKHR };
    PFN_vkBuildAccelerationStructuresKHR BuildAccelerationStructuresKHR{ noop::vkBuildAccelerationStructuresKHR };
    PFN_vkCopyAccelerationStructureKHR CopyAccelerationStructureKHR{ noop::vkCopyAccelerationStructureKHR };
    PFN_vkCopyAccelerationStructureToMemoryKHR CopyAccelerationStructureToMemoryKHR{ noop::vkCopyAccelerationStructureToMemoryKHR };
    PFN_vkCopyMemoryToAccelerationStructureKHR CopyMemoryToAccelerationStructureKHR{ noop::vkCopyMemoryToAccelerationStructureKHR };
    PFN_vkWriteAccelerationStructuresPropertiesKHR WriteAccelerationStructuresPropertiesKHR{ noop::vkWriteAccelerationStructuresPropertiesKHR };
    PFN_vkCmdCopyAccelerationStructureKHR CmdCopyAccelerationStructureKHR{ noop::vkCmdCopyAccelerationStructureKHR };
    PFN_vkCmdCopyAccelerationStructureToMemoryKHR CmdCopyAccelerationStructureToMemoryKHR{ noop::vkCmdCopyAccelerationStructureToMemoryKHR };
    PFN_vkCmdCopyMemoryToAccelerationStructureKHR CmdCopyMemoryToAccelerationStructureKHR{ noop::vkCmdCopyMemoryToAccelerationStructureKHR };
    PFN_vkGetAccelerationStructureDeviceAddressKHR GetAccelerationStructureDeviceAddressKHR{ noop::vkGetAccelerationStructureDeviceAddressKHR };
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR CmdWriteAccelerationStructuresPropertiesKHR{ noop::vkCmdWriteAccelerationStructuresPropertiesKHR };
    PFN_vkGetDeviceAccelerationStructureCompatibilityKHR GetDeviceAccelerationStructureCompatibilityKHR{ noop::vkGetDeviceAccelerationStructureCompatibilityKHR };
    PFN_vkGetAccelerationStructureBuildSizesKHR GetAccelerationStructureBuildSizesKHR{ noop::vkGetAccelerationStructureBuildSizesKHR };
    PFN_vkCmdTraceRaysKHR CmdTraceRaysKHR{ noop::vkCmdTraceRaysKHR };
    PFN_vkCreateRayTracingPipelinesKHR CreateRayTracingPipelinesKHR{ noop::vkCreateRayTracingPipelinesKHR };
    PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR GetRayTracingCaptureReplayShaderGroupHandlesKHR{ noop::vkGetRayTracingCaptureReplayShaderGroupHandlesKHR };
    PFN_vkCmdTraceRaysIndirectKHR CmdTraceRaysIndirectKHR{ noop::vkCmdTraceRaysIndirectKHR };
    PFN_vkGetRayTracingShaderGroupStackSizeKHR GetRayTracingShaderGroupStackSizeKHR{ noop::vkGetRayTracingShaderGroupStackSizeKHR };
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR CmdSetRayTracingPipelineStackSizeKHR{ noop::vkCmdSetRayTracingPipelineStackSizeKHR };
    PFN_vkCmdDrawMeshTasksEXT CmdDrawMeshTasksEXT{ noop::vkCmdDrawMeshTasksEXT };
    PFN_vkCmdDrawMeshTasksIndirectEXT CmdDrawMeshTasksIndirectEXT{ noop::vkCmdDrawMeshTasksIndirectEXT };
    PFN_vkCmdDrawMeshTasksIndirectCountEXT CmdDrawMeshTasksIndirectCountEXT{ noop::vkCmdDrawMeshTasksIndirectCountEXT };
};

template <typename GetProcAddr, typename Handle, typename FuncP>
static void LoadVulkanFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result != nullptr)
    {
        (*funcp) = result;
    }
}

static void LoadVulkanInstanceTable(PFN_vkGetInstanceProcAddr gpa, VkInstance instance, VulkanInstanceTable* table)
{
    assert(table != nullptr);

    LoadVulkanFunction(gpa, instance, "vkDestroyInstance", &table->DestroyInstance);
    LoadVulkanFunction(gpa, instance, "vkEnumeratePhysicalDevices", &table->EnumeratePhysicalDevices);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFeatures", &table->GetPhysicalDeviceFeatures);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties", &table->GetPhysicalDeviceFormatProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties", &table->GetPhysicalDeviceImageFormatProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceProperties", &table->GetPhysicalDeviceProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties", &table->GetPhysicalDeviceQueueFamilyProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties", &table->GetPhysicalDeviceMemoryProperties);
    table->GetInstanceProcAddr = gpa;
    LoadVulkanFunction(gpa, instance, "vkEnumerateDeviceExtensionProperties", &table->EnumerateDeviceExtensionProperties);
    LoadVulkanFunction(gpa, instance, "vkEnumerateDeviceLayerProperties", &table->EnumerateDeviceLayerProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties", &table->GetPhysicalDeviceSparseImageFormatProperties);
    LoadVulkanFunction(gpa, instance, "vkEnumeratePhysicalDeviceGroups", &table->EnumeratePhysicalDeviceGroups);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFeatures2", &table->GetPhysicalDeviceFeatures2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceProperties2", &table->GetPhysicalDeviceProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties2", &table->GetPhysicalDeviceFormatProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties2", &table->GetPhysicalDeviceImageFormatProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties2", &table->GetPhysicalDeviceQueueFamilyProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties2", &table->GetPhysicalDeviceMemoryProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties2", &table->GetPhysicalDeviceSparseImageFormatProperties2);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalBufferProperties", &table->GetPhysicalDeviceExternalBufferProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalFenceProperties", &table->GetPhysicalDeviceExternalFenceProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalSemaphoreProperties", &table->GetPhysicalDeviceExternalSemaphoreProperties);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceToolProperties", &table->GetPhysicalDeviceToolProperties);
    LoadVulkanFunction(gpa, instance, "vkDestroySurfaceKHR", &table->DestroySurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceSupportKHR", &table->GetPhysicalDeviceSurfaceSupportKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", &table->GetPhysicalDeviceSurfaceCapabilitiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceFormatsKHR", &table->GetPhysicalDeviceSurfaceFormatsKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfacePresentModesKHR", &table->GetPhysicalDeviceSurfacePresentModesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDevicePresentRectanglesKHR", &table->GetPhysicalDevicePresentRectanglesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPropertiesKHR", &table->GetPhysicalDeviceDisplayPropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", &table->GetPhysicalDeviceDisplayPlanePropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetDisplayPlaneSupportedDisplaysKHR", &table->GetDisplayPlaneSupportedDisplaysKHR);
    LoadVulkanFunction(gpa, instance, "vkGetDisplayModePropertiesKHR", &table->GetDisplayModePropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateDisplayModeKHR", &table->CreateDisplayModeKHR);
    LoadVulkanFunction(gpa, instance, "vkGetDisplayPlaneCapabilitiesKHR", &table->GetDisplayPlaneCapabilitiesKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateDisplayPlaneSurfaceKHR", &table->CreateDisplayPlaneSurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateXlibSurfaceKHR", &table->CreateXlibSurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR", &table->GetPhysicalDeviceXlibPresentationSupportKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateXcbSurfaceKHR", &table->CreateXcbSurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR", &table->GetPhysicalDeviceXcbPresentationSupportKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateWaylandSurfaceKHR", &table->CreateWaylandSurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR", &table->GetPhysicalDeviceWaylandPresentationSupportKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateAndroidSurfaceKHR", &table->CreateAndroidSurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateWin32SurfaceKHR", &table->CreateWin32SurfaceKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR", &table->GetPhysicalDeviceWin32PresentationSupportKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR", &table->GetPhysicalDeviceVideoCapabilitiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR", &table->GetPhysicalDeviceVideoFormatPropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFeatures2KHR", &table->GetPhysicalDeviceFeatures2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceProperties2KHR", &table->GetPhysicalDeviceProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties2KHR", &table->GetPhysicalDeviceFormatProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties2KHR", &table->GetPhysicalDeviceImageFormatProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR", &table->GetPhysicalDeviceQueueFamilyProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties2KHR", &table->GetPhysicalDeviceMemoryProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", &table->GetPhysicalDeviceSparseImageFormatProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkEnumeratePhysicalDeviceGroupsKHR", &table->EnumeratePhysicalDeviceGroupsKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR", &table->GetPhysicalDeviceExternalBufferPropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", &table->GetPhysicalDeviceExternalSemaphorePropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR", &table->GetPhysicalDeviceExternalFencePropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", &table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR", &table->GetPhysicalDeviceSurfaceCapabilities2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceFormats2KHR", &table->GetPhysicalDeviceSurfaceFormats2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceDisplayProperties2KHR", &table->GetPhysicalDeviceDisplayProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", &table->GetPhysicalDeviceDisplayPlaneProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetDisplayModeProperties2KHR", &table->GetDisplayModeProperties2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetDisplayPlaneCapabilities2KHR", &table->GetDisplayPlaneCapabilities2KHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR", &table->GetPhysicalDeviceFragmentShadingRatesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR", &table->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", &table->GetPhysicalDeviceCooperativeMatrixPropertiesKHR);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", &table->GetPhysicalDeviceCalibrateableTimeDomainsKHR);
    LoadVulkanFunction(gpa, instance, "vkCreateDebugReportCallbackEXT", &table->CreateDebugReportCallbackEXT);
    LoadVulkanFunction(gpa, instance, "vkDestroyDebugReportCallbackEXT", &table->DestroyDebugReportCallbackEXT);
    LoadVulkanFunction(gpa, instance, "vkDebugReportMessageEXT", &table->DebugReportMessageEXT);
    LoadVulkanFunction(gpa, instance, "vkCreateStreamDescriptorSurfaceGGP", &table->CreateStreamDescriptorSurfaceGGP);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", &table->GetPhysicalDeviceExternalImageFormatPropertiesNV);
    LoadVulkanFunction(gpa, instance, "vkCreateViSurfaceNN", &table->CreateViSurfaceNN);
    LoadVulkanFunction(gpa, instance, "vkReleaseDisplayEXT", &table->ReleaseDisplayEXT);
    LoadVulkanFunction(gpa, instance, "vkAcquireXlibDisplayEXT", &table->AcquireXlibDisplayEXT);
    LoadVulkanFunction(gpa, instance, "vkGetRandROutputDisplayEXT", &table->GetRandROutputDisplayEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT", &table->GetPhysicalDeviceSurfaceCapabilities2EXT);
    LoadVulkanFunction(gpa, instance, "vkCreateIOSSurfaceMVK", &table->CreateIOSSurfaceMVK);
    LoadVulkanFunction(gpa, instance, "vkCreateMacOSSurfaceMVK", &table->CreateMacOSSurfaceMVK);
    LoadVulkanFunction(gpa, instance, "vkSetDebugUtilsObjectNameEXT", &table->SetDebugUtilsObjectNameEXT);
    LoadVulkanFunction(gpa, instance, "vkSetDebugUtilsObjectTagEXT", &table->SetDebugUtilsObjectTagEXT);
    LoadVulkanFunction(gpa, instance, "vkCreateDebugUtilsMessengerEXT", &table->CreateDebugUtilsMessengerEXT);
    LoadVulkanFunction(gpa, instance, "vkDestroyDebugUtilsMessengerEXT", &table->DestroyDebugUtilsMessengerEXT);
    LoadVulkanFunction(gpa, instance, "vkSubmitDebugUtilsMessageEXT", &table->SubmitDebugUtilsMessageEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT", &table->GetPhysicalDeviceMultisamplePropertiesEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", &table->GetPhysicalDeviceCalibrateableTimeDomainsEXT);
    LoadVulkanFunction(gpa, instance, "vkCreateImagePipeSurfaceFUCHSIA", &table->CreateImagePipeSurfaceFUCHSIA);
    LoadVulkanFunction(gpa, instance, "vkCreateMetalSurfaceEXT", &table->CreateMetalSurfaceEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceToolPropertiesEXT", &table->GetPhysicalDeviceToolPropertiesEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", &table->GetPhysicalDeviceCooperativeMatrixPropertiesNV);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", &table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT", &table->GetPhysicalDeviceSurfacePresentModes2EXT);
    LoadVulkanFunction(gpa, instance, "vkCreateHeadlessSurfaceEXT", &table->CreateHeadlessSurfaceEXT);
    LoadVulkanFunction(gpa, instance, "vkAcquireDrmDisplayEXT", &table->AcquireDrmDisplayEXT);
    LoadVulkanFunction(gpa, instance, "vkGetDrmDisplayEXT", &table->GetDrmDisplayEXT);
    LoadVulkanFunction(gpa, instance, "vkAcquireWinrtDisplayNV", &table->AcquireWinrtDisplayNV);
    LoadVulkanFunction(gpa, instance, "vkGetWinrtDisplayNV", &table->GetWinrtDisplayNV);
    LoadVulkanFunction(gpa, instance, "vkCreateDirectFBSurfaceEXT", &table->CreateDirectFBSurfaceEXT);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", &table->GetPhysicalDeviceDirectFBPresentationSupportEXT);
    LoadVulkanFunction(gpa, instance, "vkCreateScreenSurfaceQNX", &table->CreateScreenSurfaceQNX);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX", &table->GetPhysicalDeviceScreenPresentationSupportQNX);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV", &table->GetPhysicalDeviceOpticalFlowImageFormatsNV);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV", &table->GetPhysicalDeviceCooperativeVectorPropertiesNV);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM", &table->GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM", &table->GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM);
    LoadVulkanFunction(gpa, instance, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV", &table->GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV);
    LoadVulkanFunction(gpa, instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM);
}

static void LoadVulkanDeviceTable(PFN_vkGetDeviceProcAddr gpa, VkDevice device, VulkanDeviceTable* table)
{
    assert(table != nullptr);

    table->GetDeviceProcAddr = gpa;
    LoadVulkanFunction(gpa, device, "vkDestroyDevice", &table->DestroyDevice);
    LoadVulkanFunction(gpa, device, "vkGetDeviceQueue", &table->GetDeviceQueue);
    LoadVulkanFunction(gpa, device, "vkQueueSubmit", &table->QueueSubmit);
    LoadVulkanFunction(gpa, device, "vkQueueWaitIdle", &table->QueueWaitIdle);
    LoadVulkanFunction(gpa, device, "vkDeviceWaitIdle", &table->DeviceWaitIdle);
    LoadVulkanFunction(gpa, device, "vkAllocateMemory", &table->AllocateMemory);
    LoadVulkanFunction(gpa, device, "vkFreeMemory", &table->FreeMemory);
    LoadVulkanFunction(gpa, device, "vkMapMemory", &table->MapMemory);
    LoadVulkanFunction(gpa, device, "vkUnmapMemory", &table->UnmapMemory);
    LoadVulkanFunction(gpa, device, "vkFlushMappedMemoryRanges", &table->FlushMappedMemoryRanges);
    LoadVulkanFunction(gpa, device, "vkInvalidateMappedMemoryRanges", &table->InvalidateMappedMemoryRanges);
    LoadVulkanFunction(gpa, device, "vkGetDeviceMemoryCommitment", &table->GetDeviceMemoryCommitment);
    LoadVulkanFunction(gpa, device, "vkBindBufferMemory", &table->BindBufferMemory);
    LoadVulkanFunction(gpa, device, "vkBindImageMemory", &table->BindImageMemory);
    LoadVulkanFunction(gpa, device, "vkGetBufferMemoryRequirements", &table->GetBufferMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetImageMemoryRequirements", &table->GetImageMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetImageSparseMemoryRequirements", &table->GetImageSparseMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkQueueBindSparse", &table->QueueBindSparse);
    LoadVulkanFunction(gpa, device, "vkCreateFence", &table->CreateFence);
    LoadVulkanFunction(gpa, device, "vkDestroyFence", &table->DestroyFence);
    LoadVulkanFunction(gpa, device, "vkResetFences", &table->ResetFences);
    LoadVulkanFunction(gpa, device, "vkGetFenceStatus", &table->GetFenceStatus);
    LoadVulkanFunction(gpa, device, "vkWaitForFences", &table->WaitForFences);
    LoadVulkanFunction(gpa, device, "vkCreateSemaphore", &table->CreateSemaphore);
    LoadVulkanFunction(gpa, device, "vkDestroySemaphore", &table->DestroySemaphore);
    LoadVulkanFunction(gpa, device, "vkCreateQueryPool", &table->CreateQueryPool);
    LoadVulkanFunction(gpa, device, "vkDestroyQueryPool", &table->DestroyQueryPool);
    LoadVulkanFunction(gpa, device, "vkGetQueryPoolResults", &table->GetQueryPoolResults);
    LoadVulkanFunction(gpa, device, "vkCreateBuffer", &table->CreateBuffer);
    LoadVulkanFunction(gpa, device, "vkDestroyBuffer", &table->DestroyBuffer);
    LoadVulkanFunction(gpa, device, "vkCreateImage", &table->CreateImage);
    LoadVulkanFunction(gpa, device, "vkDestroyImage", &table->DestroyImage);
    LoadVulkanFunction(gpa, device, "vkGetImageSubresourceLayout", &table->GetImageSubresourceLayout);
    LoadVulkanFunction(gpa, device, "vkCreateImageView", &table->CreateImageView);
    LoadVulkanFunction(gpa, device, "vkDestroyImageView", &table->DestroyImageView);
    LoadVulkanFunction(gpa, device, "vkCreateCommandPool", &table->CreateCommandPool);
    LoadVulkanFunction(gpa, device, "vkDestroyCommandPool", &table->DestroyCommandPool);
    LoadVulkanFunction(gpa, device, "vkResetCommandPool", &table->ResetCommandPool);
    LoadVulkanFunction(gpa, device, "vkAllocateCommandBuffers", &table->AllocateCommandBuffers);
    LoadVulkanFunction(gpa, device, "vkFreeCommandBuffers", &table->FreeCommandBuffers);
    LoadVulkanFunction(gpa, device, "vkBeginCommandBuffer", &table->BeginCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkEndCommandBuffer", &table->EndCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkResetCommandBuffer", &table->ResetCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBuffer", &table->CmdCopyBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImage", &table->CmdCopyImage);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBufferToImage", &table->CmdCopyBufferToImage);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImageToBuffer", &table->CmdCopyImageToBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdUpdateBuffer", &table->CmdUpdateBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdFillBuffer", &table->CmdFillBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdPipelineBarrier", &table->CmdPipelineBarrier);
    LoadVulkanFunction(gpa, device, "vkCmdBeginQuery", &table->CmdBeginQuery);
    LoadVulkanFunction(gpa, device, "vkCmdEndQuery", &table->CmdEndQuery);
    LoadVulkanFunction(gpa, device, "vkCmdResetQueryPool", &table->CmdResetQueryPool);
    LoadVulkanFunction(gpa, device, "vkCmdWriteTimestamp", &table->CmdWriteTimestamp);
    LoadVulkanFunction(gpa, device, "vkCmdCopyQueryPoolResults", &table->CmdCopyQueryPoolResults);
    LoadVulkanFunction(gpa, device, "vkCmdExecuteCommands", &table->CmdExecuteCommands);
    LoadVulkanFunction(gpa, device, "vkCreateEvent", &table->CreateEvent);
    LoadVulkanFunction(gpa, device, "vkDestroyEvent", &table->DestroyEvent);
    LoadVulkanFunction(gpa, device, "vkGetEventStatus", &table->GetEventStatus);
    LoadVulkanFunction(gpa, device, "vkSetEvent", &table->SetEvent);
    LoadVulkanFunction(gpa, device, "vkResetEvent", &table->ResetEvent);
    LoadVulkanFunction(gpa, device, "vkCreateBufferView", &table->CreateBufferView);
    LoadVulkanFunction(gpa, device, "vkDestroyBufferView", &table->DestroyBufferView);
    LoadVulkanFunction(gpa, device, "vkCreateShaderModule", &table->CreateShaderModule);
    LoadVulkanFunction(gpa, device, "vkDestroyShaderModule", &table->DestroyShaderModule);
    LoadVulkanFunction(gpa, device, "vkCreatePipelineCache", &table->CreatePipelineCache);
    LoadVulkanFunction(gpa, device, "vkDestroyPipelineCache", &table->DestroyPipelineCache);
    LoadVulkanFunction(gpa, device, "vkGetPipelineCacheData", &table->GetPipelineCacheData);
    LoadVulkanFunction(gpa, device, "vkMergePipelineCaches", &table->MergePipelineCaches);
    LoadVulkanFunction(gpa, device, "vkCreateComputePipelines", &table->CreateComputePipelines);
    LoadVulkanFunction(gpa, device, "vkDestroyPipeline", &table->DestroyPipeline);
    LoadVulkanFunction(gpa, device, "vkCreatePipelineLayout", &table->CreatePipelineLayout);
    LoadVulkanFunction(gpa, device, "vkDestroyPipelineLayout", &table->DestroyPipelineLayout);
    LoadVulkanFunction(gpa, device, "vkCreateSampler", &table->CreateSampler);
    LoadVulkanFunction(gpa, device, "vkDestroySampler", &table->DestroySampler);
    LoadVulkanFunction(gpa, device, "vkCreateDescriptorSetLayout", &table->CreateDescriptorSetLayout);
    LoadVulkanFunction(gpa, device, "vkDestroyDescriptorSetLayout", &table->DestroyDescriptorSetLayout);
    LoadVulkanFunction(gpa, device, "vkCreateDescriptorPool", &table->CreateDescriptorPool);
    LoadVulkanFunction(gpa, device, "vkDestroyDescriptorPool", &table->DestroyDescriptorPool);
    LoadVulkanFunction(gpa, device, "vkResetDescriptorPool", &table->ResetDescriptorPool);
    LoadVulkanFunction(gpa, device, "vkAllocateDescriptorSets", &table->AllocateDescriptorSets);
    LoadVulkanFunction(gpa, device, "vkFreeDescriptorSets", &table->FreeDescriptorSets);
    LoadVulkanFunction(gpa, device, "vkUpdateDescriptorSets", &table->UpdateDescriptorSets);
    LoadVulkanFunction(gpa, device, "vkCmdBindPipeline", &table->CmdBindPipeline);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorSets", &table->CmdBindDescriptorSets);
    LoadVulkanFunction(gpa, device, "vkCmdClearColorImage", &table->CmdClearColorImage);
    LoadVulkanFunction(gpa, device, "vkCmdDispatch", &table->CmdDispatch);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchIndirect", &table->CmdDispatchIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdSetEvent", &table->CmdSetEvent);
    LoadVulkanFunction(gpa, device, "vkCmdResetEvent", &table->CmdResetEvent);
    LoadVulkanFunction(gpa, device, "vkCmdWaitEvents", &table->CmdWaitEvents);
    LoadVulkanFunction(gpa, device, "vkCmdPushConstants", &table->CmdPushConstants);
    LoadVulkanFunction(gpa, device, "vkCreateGraphicsPipelines", &table->CreateGraphicsPipelines);
    LoadVulkanFunction(gpa, device, "vkCreateFramebuffer", &table->CreateFramebuffer);
    LoadVulkanFunction(gpa, device, "vkDestroyFramebuffer", &table->DestroyFramebuffer);
    LoadVulkanFunction(gpa, device, "vkCreateRenderPass", &table->CreateRenderPass);
    LoadVulkanFunction(gpa, device, "vkDestroyRenderPass", &table->DestroyRenderPass);
    LoadVulkanFunction(gpa, device, "vkGetRenderAreaGranularity", &table->GetRenderAreaGranularity);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewport", &table->CmdSetViewport);
    LoadVulkanFunction(gpa, device, "vkCmdSetScissor", &table->CmdSetScissor);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineWidth", &table->CmdSetLineWidth);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBias", &table->CmdSetDepthBias);
    LoadVulkanFunction(gpa, device, "vkCmdSetBlendConstants", &table->CmdSetBlendConstants);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBounds", &table->CmdSetDepthBounds);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilCompareMask", &table->CmdSetStencilCompareMask);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilWriteMask", &table->CmdSetStencilWriteMask);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilReference", &table->CmdSetStencilReference);
    LoadVulkanFunction(gpa, device, "vkCmdBindIndexBuffer", &table->CmdBindIndexBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdBindVertexBuffers", &table->CmdBindVertexBuffers);
    LoadVulkanFunction(gpa, device, "vkCmdDraw", &table->CmdDraw);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexed", &table->CmdDrawIndexed);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirect", &table->CmdDrawIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirect", &table->CmdDrawIndexedIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdBlitImage", &table->CmdBlitImage);
    LoadVulkanFunction(gpa, device, "vkCmdClearDepthStencilImage", &table->CmdClearDepthStencilImage);
    LoadVulkanFunction(gpa, device, "vkCmdClearAttachments", &table->CmdClearAttachments);
    LoadVulkanFunction(gpa, device, "vkCmdResolveImage", &table->CmdResolveImage);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderPass", &table->CmdBeginRenderPass);
    LoadVulkanFunction(gpa, device, "vkCmdNextSubpass", &table->CmdNextSubpass);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderPass", &table->CmdEndRenderPass);
    LoadVulkanFunction(gpa, device, "vkBindBufferMemory2", &table->BindBufferMemory2);
    LoadVulkanFunction(gpa, device, "vkBindImageMemory2", &table->BindImageMemory2);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupPeerMemoryFeatures", &table->GetDeviceGroupPeerMemoryFeatures);
    LoadVulkanFunction(gpa, device, "vkCmdSetDeviceMask", &table->CmdSetDeviceMask);
    LoadVulkanFunction(gpa, device, "vkGetImageMemoryRequirements2", &table->GetImageMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkGetBufferMemoryRequirements2", &table->GetBufferMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkGetImageSparseMemoryRequirements2", &table->GetImageSparseMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkTrimCommandPool", &table->TrimCommandPool);
    LoadVulkanFunction(gpa, device, "vkGetDeviceQueue2", &table->GetDeviceQueue2);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchBase", &table->CmdDispatchBase);
    LoadVulkanFunction(gpa, device, "vkCreateDescriptorUpdateTemplate", &table->CreateDescriptorUpdateTemplate);
    LoadVulkanFunction(gpa, device, "vkDestroyDescriptorUpdateTemplate", &table->DestroyDescriptorUpdateTemplate);
    LoadVulkanFunction(gpa, device, "vkUpdateDescriptorSetWithTemplate", &table->UpdateDescriptorSetWithTemplate);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutSupport", &table->GetDescriptorSetLayoutSupport);
    LoadVulkanFunction(gpa, device, "vkCreateSamplerYcbcrConversion", &table->CreateSamplerYcbcrConversion);
    LoadVulkanFunction(gpa, device, "vkDestroySamplerYcbcrConversion", &table->DestroySamplerYcbcrConversion);
    LoadVulkanFunction(gpa, device, "vkResetQueryPool", &table->ResetQueryPool);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreCounterValue", &table->GetSemaphoreCounterValue);
    LoadVulkanFunction(gpa, device, "vkWaitSemaphores", &table->WaitSemaphores);
    LoadVulkanFunction(gpa, device, "vkSignalSemaphore", &table->SignalSemaphore);
    LoadVulkanFunction(gpa, device, "vkGetBufferDeviceAddress", &table->GetBufferDeviceAddress);
    LoadVulkanFunction(gpa, device, "vkGetBufferOpaqueCaptureAddress", &table->GetBufferOpaqueCaptureAddress);
    LoadVulkanFunction(gpa, device, "vkGetDeviceMemoryOpaqueCaptureAddress", &table->GetDeviceMemoryOpaqueCaptureAddress);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirectCount", &table->CmdDrawIndirectCount);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirectCount", &table->CmdDrawIndexedIndirectCount);
    LoadVulkanFunction(gpa, device, "vkCreateRenderPass2", &table->CreateRenderPass2);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderPass2", &table->CmdBeginRenderPass2);
    LoadVulkanFunction(gpa, device, "vkCmdNextSubpass2", &table->CmdNextSubpass2);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderPass2", &table->CmdEndRenderPass2);
    LoadVulkanFunction(gpa, device, "vkCreatePrivateDataSlot", &table->CreatePrivateDataSlot);
    LoadVulkanFunction(gpa, device, "vkDestroyPrivateDataSlot", &table->DestroyPrivateDataSlot);
    LoadVulkanFunction(gpa, device, "vkSetPrivateData", &table->SetPrivateData);
    LoadVulkanFunction(gpa, device, "vkGetPrivateData", &table->GetPrivateData);
    LoadVulkanFunction(gpa, device, "vkCmdPipelineBarrier2", &table->CmdPipelineBarrier2);
    LoadVulkanFunction(gpa, device, "vkCmdWriteTimestamp2", &table->CmdWriteTimestamp2);
    LoadVulkanFunction(gpa, device, "vkQueueSubmit2", &table->QueueSubmit2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBuffer2", &table->CmdCopyBuffer2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImage2", &table->CmdCopyImage2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBufferToImage2", &table->CmdCopyBufferToImage2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImageToBuffer2", &table->CmdCopyImageToBuffer2);
    LoadVulkanFunction(gpa, device, "vkGetDeviceBufferMemoryRequirements", &table->GetDeviceBufferMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageMemoryRequirements", &table->GetDeviceImageMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageSparseMemoryRequirements", &table->GetDeviceImageSparseMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkCmdSetEvent2", &table->CmdSetEvent2);
    LoadVulkanFunction(gpa, device, "vkCmdResetEvent2", &table->CmdResetEvent2);
    LoadVulkanFunction(gpa, device, "vkCmdWaitEvents2", &table->CmdWaitEvents2);
    LoadVulkanFunction(gpa, device, "vkCmdBlitImage2", &table->CmdBlitImage2);
    LoadVulkanFunction(gpa, device, "vkCmdResolveImage2", &table->CmdResolveImage2);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRendering", &table->CmdBeginRendering);
    LoadVulkanFunction(gpa, device, "vkCmdEndRendering", &table->CmdEndRendering);
    LoadVulkanFunction(gpa, device, "vkCmdSetCullMode", &table->CmdSetCullMode);
    LoadVulkanFunction(gpa, device, "vkCmdSetFrontFace", &table->CmdSetFrontFace);
    LoadVulkanFunction(gpa, device, "vkCmdSetPrimitiveTopology", &table->CmdSetPrimitiveTopology);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportWithCount", &table->CmdSetViewportWithCount);
    LoadVulkanFunction(gpa, device, "vkCmdSetScissorWithCount", &table->CmdSetScissorWithCount);
    LoadVulkanFunction(gpa, device, "vkCmdBindVertexBuffers2", &table->CmdBindVertexBuffers2);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthTestEnable", &table->CmdSetDepthTestEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthWriteEnable", &table->CmdSetDepthWriteEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthCompareOp", &table->CmdSetDepthCompareOp);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBoundsTestEnable", &table->CmdSetDepthBoundsTestEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilTestEnable", &table->CmdSetStencilTestEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilOp", &table->CmdSetStencilOp);
    LoadVulkanFunction(gpa, device, "vkCmdSetRasterizerDiscardEnable", &table->CmdSetRasterizerDiscardEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBiasEnable", &table->CmdSetDepthBiasEnable);
    LoadVulkanFunction(gpa, device, "vkCmdSetPrimitiveRestartEnable", &table->CmdSetPrimitiveRestartEnable);
    LoadVulkanFunction(gpa, device, "vkMapMemory2", &table->MapMemory2);
    LoadVulkanFunction(gpa, device, "vkUnmapMemory2", &table->UnmapMemory2);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageSubresourceLayout", &table->GetDeviceImageSubresourceLayout);
    LoadVulkanFunction(gpa, device, "vkGetImageSubresourceLayout2", &table->GetImageSubresourceLayout2);
    LoadVulkanFunction(gpa, device, "vkCopyMemoryToImage", &table->CopyMemoryToImage);
    LoadVulkanFunction(gpa, device, "vkCopyImageToMemory", &table->CopyImageToMemory);
    LoadVulkanFunction(gpa, device, "vkCopyImageToImage", &table->CopyImageToImage);
    LoadVulkanFunction(gpa, device, "vkTransitionImageLayout", &table->TransitionImageLayout);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSet", &table->CmdPushDescriptorSet);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplate", &table->CmdPushDescriptorSetWithTemplate);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorSets2", &table->CmdBindDescriptorSets2);
    LoadVulkanFunction(gpa, device, "vkCmdPushConstants2", &table->CmdPushConstants2);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSet2", &table->CmdPushDescriptorSet2);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplate2", &table->CmdPushDescriptorSetWithTemplate2);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineStipple", &table->CmdSetLineStipple);
    LoadVulkanFunction(gpa, device, "vkCmdBindIndexBuffer2", &table->CmdBindIndexBuffer2);
    LoadVulkanFunction(gpa, device, "vkGetRenderingAreaGranularity", &table->GetRenderingAreaGranularity);
    LoadVulkanFunction(gpa, device, "vkCmdSetRenderingAttachmentLocations", &table->CmdSetRenderingAttachmentLocations);
    LoadVulkanFunction(gpa, device, "vkCmdSetRenderingInputAttachmentIndices", &table->CmdSetRenderingInputAttachmentIndices);
    LoadVulkanFunction(gpa, device, "vkCreateSwapchainKHR", &table->CreateSwapchainKHR);
    LoadVulkanFunction(gpa, device, "vkDestroySwapchainKHR", &table->DestroySwapchainKHR);
    LoadVulkanFunction(gpa, device, "vkGetSwapchainImagesKHR", &table->GetSwapchainImagesKHR);
    LoadVulkanFunction(gpa, device, "vkAcquireNextImageKHR", &table->AcquireNextImageKHR);
    LoadVulkanFunction(gpa, device, "vkQueuePresentKHR", &table->QueuePresentKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupPresentCapabilitiesKHR", &table->GetDeviceGroupPresentCapabilitiesKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupSurfacePresentModesKHR", &table->GetDeviceGroupSurfacePresentModesKHR);
    LoadVulkanFunction(gpa, device, "vkAcquireNextImage2KHR", &table->AcquireNextImage2KHR);
    LoadVulkanFunction(gpa, device, "vkCreateSharedSwapchainsKHR", &table->CreateSharedSwapchainsKHR);
    LoadVulkanFunction(gpa, device, "vkCreateVideoSessionKHR", &table->CreateVideoSessionKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyVideoSessionKHR", &table->DestroyVideoSessionKHR);
    LoadVulkanFunction(gpa, device, "vkGetVideoSessionMemoryRequirementsKHR", &table->GetVideoSessionMemoryRequirementsKHR);
    LoadVulkanFunction(gpa, device, "vkBindVideoSessionMemoryKHR", &table->BindVideoSessionMemoryKHR);
    LoadVulkanFunction(gpa, device, "vkCreateVideoSessionParametersKHR", &table->CreateVideoSessionParametersKHR);
    LoadVulkanFunction(gpa, device, "vkUpdateVideoSessionParametersKHR", &table->UpdateVideoSessionParametersKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyVideoSessionParametersKHR", &table->DestroyVideoSessionParametersKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBeginVideoCodingKHR", &table->CmdBeginVideoCodingKHR);
    LoadVulkanFunction(gpa, device, "vkCmdEndVideoCodingKHR", &table->CmdEndVideoCodingKHR);
    LoadVulkanFunction(gpa, device, "vkCmdControlVideoCodingKHR", &table->CmdControlVideoCodingKHR);
    LoadVulkanFunction(gpa, device, "vkCmdDecodeVideoKHR", &table->CmdDecodeVideoKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderingKHR", &table->CmdBeginRenderingKHR);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderingKHR", &table->CmdEndRenderingKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupPeerMemoryFeaturesKHR", &table->GetDeviceGroupPeerMemoryFeaturesKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetDeviceMaskKHR", &table->CmdSetDeviceMaskKHR);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchBaseKHR", &table->CmdDispatchBaseKHR);
    LoadVulkanFunction(gpa, device, "vkTrimCommandPoolKHR", &table->TrimCommandPoolKHR);
    LoadVulkanFunction(gpa, device, "vkGetMemoryWin32HandleKHR", &table->GetMemoryWin32HandleKHR);
    LoadVulkanFunction(gpa, device, "vkGetMemoryWin32HandlePropertiesKHR", &table->GetMemoryWin32HandlePropertiesKHR);
    LoadVulkanFunction(gpa, device, "vkGetMemoryFdKHR", &table->GetMemoryFdKHR);
    LoadVulkanFunction(gpa, device, "vkGetMemoryFdPropertiesKHR", &table->GetMemoryFdPropertiesKHR);
    LoadVulkanFunction(gpa, device, "vkImportSemaphoreWin32HandleKHR", &table->ImportSemaphoreWin32HandleKHR);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreWin32HandleKHR", &table->GetSemaphoreWin32HandleKHR);
    LoadVulkanFunction(gpa, device, "vkImportSemaphoreFdKHR", &table->ImportSemaphoreFdKHR);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreFdKHR", &table->GetSemaphoreFdKHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetKHR", &table->CmdPushDescriptorSetKHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplateKHR", &table->CmdPushDescriptorSetWithTemplateKHR);
    LoadVulkanFunction(gpa, device, "vkCreateDescriptorUpdateTemplateKHR", &table->CreateDescriptorUpdateTemplateKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyDescriptorUpdateTemplateKHR", &table->DestroyDescriptorUpdateTemplateKHR);
    LoadVulkanFunction(gpa, device, "vkUpdateDescriptorSetWithTemplateKHR", &table->UpdateDescriptorSetWithTemplateKHR);
    LoadVulkanFunction(gpa, device, "vkCreateRenderPass2KHR", &table->CreateRenderPass2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderPass2KHR", &table->CmdBeginRenderPass2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdNextSubpass2KHR", &table->CmdNextSubpass2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderPass2KHR", &table->CmdEndRenderPass2KHR);
    LoadVulkanFunction(gpa, device, "vkGetSwapchainStatusKHR", &table->GetSwapchainStatusKHR);
    LoadVulkanFunction(gpa, device, "vkImportFenceWin32HandleKHR", &table->ImportFenceWin32HandleKHR);
    LoadVulkanFunction(gpa, device, "vkGetFenceWin32HandleKHR", &table->GetFenceWin32HandleKHR);
    LoadVulkanFunction(gpa, device, "vkImportFenceFdKHR", &table->ImportFenceFdKHR);
    LoadVulkanFunction(gpa, device, "vkGetFenceFdKHR", &table->GetFenceFdKHR);
    LoadVulkanFunction(gpa, device, "vkAcquireProfilingLockKHR", &table->AcquireProfilingLockKHR);
    LoadVulkanFunction(gpa, device, "vkReleaseProfilingLockKHR", &table->ReleaseProfilingLockKHR);
    LoadVulkanFunction(gpa, device, "vkGetImageMemoryRequirements2KHR", &table->GetImageMemoryRequirements2KHR);
    LoadVulkanFunction(gpa, device, "vkGetBufferMemoryRequirements2KHR", &table->GetBufferMemoryRequirements2KHR);
    LoadVulkanFunction(gpa, device, "vkGetImageSparseMemoryRequirements2KHR", &table->GetImageSparseMemoryRequirements2KHR);
    LoadVulkanFunction(gpa, device, "vkCreateSamplerYcbcrConversionKHR", &table->CreateSamplerYcbcrConversionKHR);
    LoadVulkanFunction(gpa, device, "vkDestroySamplerYcbcrConversionKHR", &table->DestroySamplerYcbcrConversionKHR);
    LoadVulkanFunction(gpa, device, "vkBindBufferMemory2KHR", &table->BindBufferMemory2KHR);
    LoadVulkanFunction(gpa, device, "vkBindImageMemory2KHR", &table->BindImageMemory2KHR);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutSupportKHR", &table->GetDescriptorSetLayoutSupportKHR);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirectCountKHR", &table->CmdDrawIndirectCountKHR);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirectCountKHR", &table->CmdDrawIndexedIndirectCountKHR);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreCounterValueKHR", &table->GetSemaphoreCounterValueKHR);
    LoadVulkanFunction(gpa, device, "vkWaitSemaphoresKHR", &table->WaitSemaphoresKHR);
    LoadVulkanFunction(gpa, device, "vkSignalSemaphoreKHR", &table->SignalSemaphoreKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetFragmentShadingRateKHR", &table->CmdSetFragmentShadingRateKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetRenderingAttachmentLocationsKHR", &table->CmdSetRenderingAttachmentLocationsKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetRenderingInputAttachmentIndicesKHR", &table->CmdSetRenderingInputAttachmentIndicesKHR);
    LoadVulkanFunction(gpa, device, "vkWaitForPresentKHR", &table->WaitForPresentKHR);
    LoadVulkanFunction(gpa, device, "vkGetBufferDeviceAddressKHR", &table->GetBufferDeviceAddressKHR);
    LoadVulkanFunction(gpa, device, "vkGetBufferOpaqueCaptureAddressKHR", &table->GetBufferOpaqueCaptureAddressKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR", &table->GetDeviceMemoryOpaqueCaptureAddressKHR);
    LoadVulkanFunction(gpa, device, "vkCreateDeferredOperationKHR", &table->CreateDeferredOperationKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyDeferredOperationKHR", &table->DestroyDeferredOperationKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeferredOperationMaxConcurrencyKHR", &table->GetDeferredOperationMaxConcurrencyKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeferredOperationResultKHR", &table->GetDeferredOperationResultKHR);
    LoadVulkanFunction(gpa, device, "vkDeferredOperationJoinKHR", &table->DeferredOperationJoinKHR);
    LoadVulkanFunction(gpa, device, "vkGetPipelineExecutablePropertiesKHR", &table->GetPipelineExecutablePropertiesKHR);
    LoadVulkanFunction(gpa, device, "vkGetPipelineExecutableStatisticsKHR", &table->GetPipelineExecutableStatisticsKHR);
    LoadVulkanFunction(gpa, device, "vkGetPipelineExecutableInternalRepresentationsKHR", &table->GetPipelineExecutableInternalRepresentationsKHR);
    LoadVulkanFunction(gpa, device, "vkMapMemory2KHR", &table->MapMemory2KHR);
    LoadVulkanFunction(gpa, device, "vkUnmapMemory2KHR", &table->UnmapMemory2KHR);
    LoadVulkanFunction(gpa, device, "vkGetEncodedVideoSessionParametersKHR", &table->GetEncodedVideoSessionParametersKHR);
    LoadVulkanFunction(gpa, device, "vkCmdEncodeVideoKHR", &table->CmdEncodeVideoKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetEvent2KHR", &table->CmdSetEvent2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdResetEvent2KHR", &table->CmdResetEvent2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdWaitEvents2KHR", &table->CmdWaitEvents2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPipelineBarrier2KHR", &table->CmdPipelineBarrier2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdWriteTimestamp2KHR", &table->CmdWriteTimestamp2KHR);
    LoadVulkanFunction(gpa, device, "vkQueueSubmit2KHR", &table->QueueSubmit2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBuffer2KHR", &table->CmdCopyBuffer2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImage2KHR", &table->CmdCopyImage2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBufferToImage2KHR", &table->CmdCopyBufferToImage2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImageToBuffer2KHR", &table->CmdCopyImageToBuffer2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdBlitImage2KHR", &table->CmdBlitImage2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdResolveImage2KHR", &table->CmdResolveImage2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdTraceRaysIndirect2KHR", &table->CmdTraceRaysIndirect2KHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceBufferMemoryRequirementsKHR", &table->GetDeviceBufferMemoryRequirementsKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageMemoryRequirementsKHR", &table->GetDeviceImageMemoryRequirementsKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageSparseMemoryRequirementsKHR", &table->GetDeviceImageSparseMemoryRequirementsKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBindIndexBuffer2KHR", &table->CmdBindIndexBuffer2KHR);
    LoadVulkanFunction(gpa, device, "vkGetRenderingAreaGranularityKHR", &table->GetRenderingAreaGranularityKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageSubresourceLayoutKHR", &table->GetDeviceImageSubresourceLayoutKHR);
    LoadVulkanFunction(gpa, device, "vkGetImageSubresourceLayout2KHR", &table->GetImageSubresourceLayout2KHR);
    LoadVulkanFunction(gpa, device, "vkWaitForPresent2KHR", &table->WaitForPresent2KHR);
    LoadVulkanFunction(gpa, device, "vkCreatePipelineBinariesKHR", &table->CreatePipelineBinariesKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyPipelineBinaryKHR", &table->DestroyPipelineBinaryKHR);
    LoadVulkanFunction(gpa, device, "vkGetPipelineKeyKHR", &table->GetPipelineKeyKHR);
    LoadVulkanFunction(gpa, device, "vkGetPipelineBinaryDataKHR", &table->GetPipelineBinaryDataKHR);
    LoadVulkanFunction(gpa, device, "vkReleaseCapturedPipelineDataKHR", &table->ReleaseCapturedPipelineDataKHR);
    LoadVulkanFunction(gpa, device, "vkReleaseSwapchainImagesKHR", &table->ReleaseSwapchainImagesKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineStippleKHR", &table->CmdSetLineStippleKHR);
    LoadVulkanFunction(gpa, device, "vkGetCalibratedTimestampsKHR", &table->GetCalibratedTimestampsKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorSets2KHR", &table->CmdBindDescriptorSets2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushConstants2KHR", &table->CmdPushConstants2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSet2KHR", &table->CmdPushDescriptorSet2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplate2KHR", &table->CmdPushDescriptorSetWithTemplate2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetDescriptorBufferOffsets2EXT", &table->CmdSetDescriptorBufferOffsets2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT", &table->CmdBindDescriptorBufferEmbeddedSamplers2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMemoryIndirectKHR", &table->CmdCopyMemoryIndirectKHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMemoryToImageIndirectKHR", &table->CmdCopyMemoryToImageIndirectKHR);
    LoadVulkanFunction(gpa, device, "vkCmdEndRendering2KHR", &table->CmdEndRendering2KHR);
    LoadVulkanFunction(gpa, device, "vkFrameBoundaryANDROID", &table->FrameBoundaryANDROID);
    LoadVulkanFunction(gpa, device, "vkDebugMarkerSetObjectTagEXT", &table->DebugMarkerSetObjectTagEXT);
    LoadVulkanFunction(gpa, device, "vkDebugMarkerSetObjectNameEXT", &table->DebugMarkerSetObjectNameEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDebugMarkerBeginEXT", &table->CmdDebugMarkerBeginEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDebugMarkerEndEXT", &table->CmdDebugMarkerEndEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDebugMarkerInsertEXT", &table->CmdDebugMarkerInsertEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindTransformFeedbackBuffersEXT", &table->CmdBindTransformFeedbackBuffersEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBeginTransformFeedbackEXT", &table->CmdBeginTransformFeedbackEXT);
    LoadVulkanFunction(gpa, device, "vkCmdEndTransformFeedbackEXT", &table->CmdEndTransformFeedbackEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBeginQueryIndexedEXT", &table->CmdBeginQueryIndexedEXT);
    LoadVulkanFunction(gpa, device, "vkCmdEndQueryIndexedEXT", &table->CmdEndQueryIndexedEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirectByteCountEXT", &table->CmdDrawIndirectByteCountEXT);
    LoadVulkanFunction(gpa, device, "vkGetImageViewHandleNVX", &table->GetImageViewHandleNVX);
    LoadVulkanFunction(gpa, device, "vkGetImageViewHandle64NVX", &table->GetImageViewHandle64NVX);
    LoadVulkanFunction(gpa, device, "vkGetImageViewAddressNVX", &table->GetImageViewAddressNVX);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirectCountAMD", &table->CmdDrawIndirectCountAMD);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirectCountAMD", &table->CmdDrawIndexedIndirectCountAMD);
    LoadVulkanFunction(gpa, device, "vkGetShaderInfoAMD", &table->GetShaderInfoAMD);
    LoadVulkanFunction(gpa, device, "vkGetMemoryWin32HandleNV", &table->GetMemoryWin32HandleNV);
    LoadVulkanFunction(gpa, device, "vkCmdBeginConditionalRenderingEXT", &table->CmdBeginConditionalRenderingEXT);
    LoadVulkanFunction(gpa, device, "vkCmdEndConditionalRenderingEXT", &table->CmdEndConditionalRenderingEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportWScalingNV", &table->CmdSetViewportWScalingNV);
    LoadVulkanFunction(gpa, device, "vkDisplayPowerControlEXT", &table->DisplayPowerControlEXT);
    LoadVulkanFunction(gpa, device, "vkRegisterDeviceEventEXT", &table->RegisterDeviceEventEXT);
    LoadVulkanFunction(gpa, device, "vkRegisterDisplayEventEXT", &table->RegisterDisplayEventEXT);
    LoadVulkanFunction(gpa, device, "vkGetSwapchainCounterEXT", &table->GetSwapchainCounterEXT);
    LoadVulkanFunction(gpa, device, "vkGetRefreshCycleDurationGOOGLE", &table->GetRefreshCycleDurationGOOGLE);
    LoadVulkanFunction(gpa, device, "vkGetPastPresentationTimingGOOGLE", &table->GetPastPresentationTimingGOOGLE);
    LoadVulkanFunction(gpa, device, "vkCmdSetDiscardRectangleEXT", &table->CmdSetDiscardRectangleEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDiscardRectangleEnableEXT", &table->CmdSetDiscardRectangleEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDiscardRectangleModeEXT", &table->CmdSetDiscardRectangleModeEXT);
    LoadVulkanFunction(gpa, device, "vkSetHdrMetadataEXT", &table->SetHdrMetadataEXT);
    LoadVulkanFunction(gpa, device, "vkQueueBeginDebugUtilsLabelEXT", &table->QueueBeginDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkQueueEndDebugUtilsLabelEXT", &table->QueueEndDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkQueueInsertDebugUtilsLabelEXT", &table->QueueInsertDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBeginDebugUtilsLabelEXT", &table->CmdBeginDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkCmdEndDebugUtilsLabelEXT", &table->CmdEndDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkCmdInsertDebugUtilsLabelEXT", &table->CmdInsertDebugUtilsLabelEXT);
    LoadVulkanFunction(gpa, device, "vkGetAndroidHardwareBufferPropertiesANDROID", &table->GetAndroidHardwareBufferPropertiesANDROID);
    LoadVulkanFunction(gpa, device, "vkGetMemoryAndroidHardwareBufferANDROID", &table->GetMemoryAndroidHardwareBufferANDROID);
    LoadVulkanFunction(gpa, device, "vkCmdSetSampleLocationsEXT", &table->CmdSetSampleLocationsEXT);
    LoadVulkanFunction(gpa, device, "vkGetImageDrmFormatModifierPropertiesEXT", &table->GetImageDrmFormatModifierPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkCreateValidationCacheEXT", &table->CreateValidationCacheEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyValidationCacheEXT", &table->DestroyValidationCacheEXT);
    LoadVulkanFunction(gpa, device, "vkMergeValidationCachesEXT", &table->MergeValidationCachesEXT);
    LoadVulkanFunction(gpa, device, "vkGetValidationCacheDataEXT", &table->GetValidationCacheDataEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindShadingRateImageNV", &table->CmdBindShadingRateImageNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportShadingRatePaletteNV", &table->CmdSetViewportShadingRatePaletteNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoarseSampleOrderNV", &table->CmdSetCoarseSampleOrderNV);
    LoadVulkanFunction(gpa, device, "vkCreateAccelerationStructureNV", &table->CreateAccelerationStructureNV);
    LoadVulkanFunction(gpa, device, "vkDestroyAccelerationStructureNV", &table->DestroyAccelerationStructureNV);
    LoadVulkanFunction(gpa, device, "vkGetAccelerationStructureMemoryRequirementsNV", &table->GetAccelerationStructureMemoryRequirementsNV);
    LoadVulkanFunction(gpa, device, "vkBindAccelerationStructureMemoryNV", &table->BindAccelerationStructureMemoryNV);
    LoadVulkanFunction(gpa, device, "vkCmdBuildAccelerationStructureNV", &table->CmdBuildAccelerationStructureNV);
    LoadVulkanFunction(gpa, device, "vkCmdCopyAccelerationStructureNV", &table->CmdCopyAccelerationStructureNV);
    LoadVulkanFunction(gpa, device, "vkCmdTraceRaysNV", &table->CmdTraceRaysNV);
    LoadVulkanFunction(gpa, device, "vkCreateRayTracingPipelinesNV", &table->CreateRayTracingPipelinesNV);
    LoadVulkanFunction(gpa, device, "vkGetRayTracingShaderGroupHandlesKHR", &table->GetRayTracingShaderGroupHandlesKHR);
    LoadVulkanFunction(gpa, device, "vkGetRayTracingShaderGroupHandlesNV", &table->GetRayTracingShaderGroupHandlesNV);
    LoadVulkanFunction(gpa, device, "vkGetAccelerationStructureHandleNV", &table->GetAccelerationStructureHandleNV);
    LoadVulkanFunction(gpa, device, "vkCmdWriteAccelerationStructuresPropertiesNV", &table->CmdWriteAccelerationStructuresPropertiesNV);
    LoadVulkanFunction(gpa, device, "vkCompileDeferredNV", &table->CompileDeferredNV);
    LoadVulkanFunction(gpa, device, "vkGetMemoryHostPointerPropertiesEXT", &table->GetMemoryHostPointerPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkCmdWriteBufferMarkerAMD", &table->CmdWriteBufferMarkerAMD);
    LoadVulkanFunction(gpa, device, "vkCmdWriteBufferMarker2AMD", &table->CmdWriteBufferMarker2AMD);
    LoadVulkanFunction(gpa, device, "vkGetCalibratedTimestampsEXT", &table->GetCalibratedTimestampsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksNV", &table->CmdDrawMeshTasksNV);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectNV", &table->CmdDrawMeshTasksIndirectNV);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectCountNV", &table->CmdDrawMeshTasksIndirectCountNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetExclusiveScissorEnableNV", &table->CmdSetExclusiveScissorEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetExclusiveScissorNV", &table->CmdSetExclusiveScissorNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCheckpointNV", &table->CmdSetCheckpointNV);
    LoadVulkanFunction(gpa, device, "vkGetQueueCheckpointDataNV", &table->GetQueueCheckpointDataNV);
    LoadVulkanFunction(gpa, device, "vkGetQueueCheckpointData2NV", &table->GetQueueCheckpointData2NV);
    LoadVulkanFunction(gpa, device, "vkSetSwapchainPresentTimingQueueSizeEXT", &table->SetSwapchainPresentTimingQueueSizeEXT);
    LoadVulkanFunction(gpa, device, "vkGetSwapchainTimingPropertiesEXT", &table->GetSwapchainTimingPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkGetSwapchainTimeDomainPropertiesEXT", &table->GetSwapchainTimeDomainPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkGetPastPresentationTimingEXT", &table->GetPastPresentationTimingEXT);
    LoadVulkanFunction(gpa, device, "vkInitializePerformanceApiINTEL", &table->InitializePerformanceApiINTEL);
    LoadVulkanFunction(gpa, device, "vkUninitializePerformanceApiINTEL", &table->UninitializePerformanceApiINTEL);
    LoadVulkanFunction(gpa, device, "vkCmdSetPerformanceMarkerINTEL", &table->CmdSetPerformanceMarkerINTEL);
    LoadVulkanFunction(gpa, device, "vkCmdSetPerformanceStreamMarkerINTEL", &table->CmdSetPerformanceStreamMarkerINTEL);
    LoadVulkanFunction(gpa, device, "vkCmdSetPerformanceOverrideINTEL", &table->CmdSetPerformanceOverrideINTEL);
    LoadVulkanFunction(gpa, device, "vkAcquirePerformanceConfigurationINTEL", &table->AcquirePerformanceConfigurationINTEL);
    LoadVulkanFunction(gpa, device, "vkReleasePerformanceConfigurationINTEL", &table->ReleasePerformanceConfigurationINTEL);
    LoadVulkanFunction(gpa, device, "vkQueueSetPerformanceConfigurationINTEL", &table->QueueSetPerformanceConfigurationINTEL);
    LoadVulkanFunction(gpa, device, "vkGetPerformanceParameterINTEL", &table->GetPerformanceParameterINTEL);
    LoadVulkanFunction(gpa, device, "vkSetLocalDimmingAMD", &table->SetLocalDimmingAMD);
    LoadVulkanFunction(gpa, device, "vkGetBufferDeviceAddressEXT", &table->GetBufferDeviceAddressEXT);
    LoadVulkanFunction(gpa, device, "vkAcquireFullScreenExclusiveModeEXT", &table->AcquireFullScreenExclusiveModeEXT);
    LoadVulkanFunction(gpa, device, "vkReleaseFullScreenExclusiveModeEXT", &table->ReleaseFullScreenExclusiveModeEXT);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupSurfacePresentModes2EXT", &table->GetDeviceGroupSurfacePresentModes2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineStippleEXT", &table->CmdSetLineStippleEXT);
    LoadVulkanFunction(gpa, device, "vkResetQueryPoolEXT", &table->ResetQueryPoolEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetCullModeEXT", &table->CmdSetCullModeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetFrontFaceEXT", &table->CmdSetFrontFaceEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetPrimitiveTopologyEXT", &table->CmdSetPrimitiveTopologyEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportWithCountEXT", &table->CmdSetViewportWithCountEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetScissorWithCountEXT", &table->CmdSetScissorWithCountEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindVertexBuffers2EXT", &table->CmdBindVertexBuffers2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthTestEnableEXT", &table->CmdSetDepthTestEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthWriteEnableEXT", &table->CmdSetDepthWriteEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthCompareOpEXT", &table->CmdSetDepthCompareOpEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBoundsTestEnableEXT", &table->CmdSetDepthBoundsTestEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilTestEnableEXT", &table->CmdSetStencilTestEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilOpEXT", &table->CmdSetStencilOpEXT);
    LoadVulkanFunction(gpa, device, "vkCopyMemoryToImageEXT", &table->CopyMemoryToImageEXT);
    LoadVulkanFunction(gpa, device, "vkCopyImageToMemoryEXT", &table->CopyImageToMemoryEXT);
    LoadVulkanFunction(gpa, device, "vkCopyImageToImageEXT", &table->CopyImageToImageEXT);
    LoadVulkanFunction(gpa, device, "vkTransitionImageLayoutEXT", &table->TransitionImageLayoutEXT);
    LoadVulkanFunction(gpa, device, "vkGetImageSubresourceLayout2EXT", &table->GetImageSubresourceLayout2EXT);
    LoadVulkanFunction(gpa, device, "vkReleaseSwapchainImagesEXT", &table->ReleaseSwapchainImagesEXT);
    LoadVulkanFunction(gpa, device, "vkGetGeneratedCommandsMemoryRequirementsNV", &table->GetGeneratedCommandsMemoryRequirementsNV);
    LoadVulkanFunction(gpa, device, "vkCmdPreprocessGeneratedCommandsNV", &table->CmdPreprocessGeneratedCommandsNV);
    LoadVulkanFunction(gpa, device, "vkCmdExecuteGeneratedCommandsNV", &table->CmdExecuteGeneratedCommandsNV);
    LoadVulkanFunction(gpa, device, "vkCmdBindPipelineShaderGroupNV", &table->CmdBindPipelineShaderGroupNV);
    LoadVulkanFunction(gpa, device, "vkCreateIndirectCommandsLayoutNV", &table->CreateIndirectCommandsLayoutNV);
    LoadVulkanFunction(gpa, device, "vkDestroyIndirectCommandsLayoutNV", &table->DestroyIndirectCommandsLayoutNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBias2EXT", &table->CmdSetDepthBias2EXT);
    LoadVulkanFunction(gpa, device, "vkCreatePrivateDataSlotEXT", &table->CreatePrivateDataSlotEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyPrivateDataSlotEXT", &table->DestroyPrivateDataSlotEXT);
    LoadVulkanFunction(gpa, device, "vkSetPrivateDataEXT", &table->SetPrivateDataEXT);
    LoadVulkanFunction(gpa, device, "vkGetPrivateDataEXT", &table->GetPrivateDataEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchTileQCOM", &table->CmdDispatchTileQCOM);
    LoadVulkanFunction(gpa, device, "vkCmdBeginPerTileExecutionQCOM", &table->CmdBeginPerTileExecutionQCOM);
    LoadVulkanFunction(gpa, device, "vkCmdEndPerTileExecutionQCOM", &table->CmdEndPerTileExecutionQCOM);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutSizeEXT", &table->GetDescriptorSetLayoutSizeEXT);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutBindingOffsetEXT", &table->GetDescriptorSetLayoutBindingOffsetEXT);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorEXT", &table->GetDescriptorEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorBuffersEXT", &table->CmdBindDescriptorBuffersEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDescriptorBufferOffsetsEXT", &table->CmdSetDescriptorBufferOffsetsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT", &table->CmdBindDescriptorBufferEmbeddedSamplersEXT);
    LoadVulkanFunction(gpa, device, "vkGetBufferOpaqueCaptureDescriptorDataEXT", &table->GetBufferOpaqueCaptureDescriptorDataEXT);
    LoadVulkanFunction(gpa, device, "vkGetImageOpaqueCaptureDescriptorDataEXT", &table->GetImageOpaqueCaptureDescriptorDataEXT);
    LoadVulkanFunction(gpa, device, "vkGetImageViewOpaqueCaptureDescriptorDataEXT", &table->GetImageViewOpaqueCaptureDescriptorDataEXT);
    LoadVulkanFunction(gpa, device, "vkGetSamplerOpaqueCaptureDescriptorDataEXT", &table->GetSamplerOpaqueCaptureDescriptorDataEXT);
    LoadVulkanFunction(gpa, device, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT", &table->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetFragmentShadingRateEnumNV", &table->CmdSetFragmentShadingRateEnumNV);
    LoadVulkanFunction(gpa, device, "vkGetDeviceFaultInfoEXT", &table->GetDeviceFaultInfoEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetVertexInputEXT", &table->CmdSetVertexInputEXT);
    LoadVulkanFunction(gpa, device, "vkGetMemoryZirconHandleFUCHSIA", &table->GetMemoryZirconHandleFUCHSIA);
    LoadVulkanFunction(gpa, device, "vkGetMemoryZirconHandlePropertiesFUCHSIA", &table->GetMemoryZirconHandlePropertiesFUCHSIA);
    LoadVulkanFunction(gpa, device, "vkImportSemaphoreZirconHandleFUCHSIA", &table->ImportSemaphoreZirconHandleFUCHSIA);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreZirconHandleFUCHSIA", &table->GetSemaphoreZirconHandleFUCHSIA);
    LoadVulkanFunction(gpa, device, "vkCmdBindInvocationMaskHUAWEI", &table->CmdBindInvocationMaskHUAWEI);
    LoadVulkanFunction(gpa, device, "vkGetMemoryRemoteAddressNV", &table->GetMemoryRemoteAddressNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetPatchControlPointsEXT", &table->CmdSetPatchControlPointsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetRasterizerDiscardEnableEXT", &table->CmdSetRasterizerDiscardEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBiasEnableEXT", &table->CmdSetDepthBiasEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetLogicOpEXT", &table->CmdSetLogicOpEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetPrimitiveRestartEnableEXT", &table->CmdSetPrimitiveRestartEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetColorWriteEnableEXT", &table->CmdSetColorWriteEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMultiEXT", &table->CmdDrawMultiEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMultiIndexedEXT", &table->CmdDrawMultiIndexedEXT);
    LoadVulkanFunction(gpa, device, "vkCreateMicromapEXT", &table->CreateMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyMicromapEXT", &table->DestroyMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBuildMicromapsEXT", &table->CmdBuildMicromapsEXT);
    LoadVulkanFunction(gpa, device, "vkBuildMicromapsEXT", &table->BuildMicromapsEXT);
    LoadVulkanFunction(gpa, device, "vkCopyMicromapEXT", &table->CopyMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkCopyMicromapToMemoryEXT", &table->CopyMicromapToMemoryEXT);
    LoadVulkanFunction(gpa, device, "vkCopyMemoryToMicromapEXT", &table->CopyMemoryToMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkWriteMicromapsPropertiesEXT", &table->WriteMicromapsPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMicromapEXT", &table->CmdCopyMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMicromapToMemoryEXT", &table->CmdCopyMicromapToMemoryEXT);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMemoryToMicromapEXT", &table->CmdCopyMemoryToMicromapEXT);
    LoadVulkanFunction(gpa, device, "vkCmdWriteMicromapsPropertiesEXT", &table->CmdWriteMicromapsPropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkGetDeviceMicromapCompatibilityEXT", &table->GetDeviceMicromapCompatibilityEXT);
    LoadVulkanFunction(gpa, device, "vkGetMicromapBuildSizesEXT", &table->GetMicromapBuildSizesEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawClusterHUAWEI", &table->CmdDrawClusterHUAWEI);
    LoadVulkanFunction(gpa, device, "vkCmdDrawClusterIndirectHUAWEI", &table->CmdDrawClusterIndirectHUAWEI);
    LoadVulkanFunction(gpa, device, "vkSetDeviceMemoryPriorityEXT", &table->SetDeviceMemoryPriorityEXT);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE", &table->GetDescriptorSetLayoutHostMappingInfoVALVE);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetHostMappingVALVE", &table->GetDescriptorSetHostMappingVALVE);
    LoadVulkanFunction(gpa, device, "vkGetPipelineIndirectMemoryRequirementsNV", &table->GetPipelineIndirectMemoryRequirementsNV);
    LoadVulkanFunction(gpa, device, "vkCmdUpdatePipelineIndirectBufferNV", &table->CmdUpdatePipelineIndirectBufferNV);
    LoadVulkanFunction(gpa, device, "vkGetPipelineIndirectDeviceAddressNV", &table->GetPipelineIndirectDeviceAddressNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthClampEnableEXT", &table->CmdSetDepthClampEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetPolygonModeEXT", &table->CmdSetPolygonModeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetRasterizationSamplesEXT", &table->CmdSetRasterizationSamplesEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetSampleMaskEXT", &table->CmdSetSampleMaskEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetAlphaToCoverageEnableEXT", &table->CmdSetAlphaToCoverageEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetAlphaToOneEnableEXT", &table->CmdSetAlphaToOneEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetLogicOpEnableEXT", &table->CmdSetLogicOpEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetColorBlendEnableEXT", &table->CmdSetColorBlendEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetColorBlendEquationEXT", &table->CmdSetColorBlendEquationEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetColorWriteMaskEXT", &table->CmdSetColorWriteMaskEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetTessellationDomainOriginEXT", &table->CmdSetTessellationDomainOriginEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetRasterizationStreamEXT", &table->CmdSetRasterizationStreamEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetConservativeRasterizationModeEXT", &table->CmdSetConservativeRasterizationModeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetExtraPrimitiveOverestimationSizeEXT", &table->CmdSetExtraPrimitiveOverestimationSizeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthClipEnableEXT", &table->CmdSetDepthClipEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetSampleLocationsEnableEXT", &table->CmdSetSampleLocationsEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetColorBlendAdvancedEXT", &table->CmdSetColorBlendAdvancedEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetProvokingVertexModeEXT", &table->CmdSetProvokingVertexModeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineRasterizationModeEXT", &table->CmdSetLineRasterizationModeEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineStippleEnableEXT", &table->CmdSetLineStippleEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthClipNegativeOneToOneEXT", &table->CmdSetDepthClipNegativeOneToOneEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportWScalingEnableNV", &table->CmdSetViewportWScalingEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewportSwizzleNV", &table->CmdSetViewportSwizzleNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageToColorEnableNV", &table->CmdSetCoverageToColorEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageToColorLocationNV", &table->CmdSetCoverageToColorLocationNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageModulationModeNV", &table->CmdSetCoverageModulationModeNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageModulationTableEnableNV", &table->CmdSetCoverageModulationTableEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageModulationTableNV", &table->CmdSetCoverageModulationTableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetShadingRateImageEnableNV", &table->CmdSetShadingRateImageEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetRepresentativeFragmentTestEnableNV", &table->CmdSetRepresentativeFragmentTestEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCoverageReductionModeNV", &table->CmdSetCoverageReductionModeNV);
    LoadVulkanFunction(gpa, device, "vkGetShaderModuleIdentifierEXT", &table->GetShaderModuleIdentifierEXT);
    LoadVulkanFunction(gpa, device, "vkGetShaderModuleCreateInfoIdentifierEXT", &table->GetShaderModuleCreateInfoIdentifierEXT);
    LoadVulkanFunction(gpa, device, "vkCreateOpticalFlowSessionNV", &table->CreateOpticalFlowSessionNV);
    LoadVulkanFunction(gpa, device, "vkDestroyOpticalFlowSessionNV", &table->DestroyOpticalFlowSessionNV);
    LoadVulkanFunction(gpa, device, "vkBindOpticalFlowSessionImageNV", &table->BindOpticalFlowSessionImageNV);
    LoadVulkanFunction(gpa, device, "vkCmdOpticalFlowExecuteNV", &table->CmdOpticalFlowExecuteNV);
    LoadVulkanFunction(gpa, device, "vkAntiLagUpdateAMD", &table->AntiLagUpdateAMD);
    LoadVulkanFunction(gpa, device, "vkCreateShadersEXT", &table->CreateShadersEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyShaderEXT", &table->DestroyShaderEXT);
    LoadVulkanFunction(gpa, device, "vkGetShaderBinaryDataEXT", &table->GetShaderBinaryDataEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindShadersEXT", &table->CmdBindShadersEXT);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthClampRangeEXT", &table->CmdSetDepthClampRangeEXT);
    LoadVulkanFunction(gpa, device, "vkGetFramebufferTilePropertiesQCOM", &table->GetFramebufferTilePropertiesQCOM);
    LoadVulkanFunction(gpa, device, "vkGetDynamicRenderingTilePropertiesQCOM", &table->GetDynamicRenderingTilePropertiesQCOM);
    LoadVulkanFunction(gpa, device, "vkConvertCooperativeVectorMatrixNV", &table->ConvertCooperativeVectorMatrixNV);
    LoadVulkanFunction(gpa, device, "vkCmdConvertCooperativeVectorMatrixNV", &table->CmdConvertCooperativeVectorMatrixNV);
    LoadVulkanFunction(gpa, device, "vkSetLatencySleepModeNV", &table->SetLatencySleepModeNV);
    LoadVulkanFunction(gpa, device, "vkLatencySleepNV", &table->LatencySleepNV);
    LoadVulkanFunction(gpa, device, "vkSetLatencyMarkerNV", &table->SetLatencyMarkerNV);
    LoadVulkanFunction(gpa, device, "vkGetLatencyTimingsNV", &table->GetLatencyTimingsNV);
    LoadVulkanFunction(gpa, device, "vkQueueNotifyOutOfBandNV", &table->QueueNotifyOutOfBandNV);
    LoadVulkanFunction(gpa, device, "vkCreateDataGraphPipelinesARM", &table->CreateDataGraphPipelinesARM);
    LoadVulkanFunction(gpa, device, "vkCreateDataGraphPipelineSessionARM", &table->CreateDataGraphPipelineSessionARM);
    LoadVulkanFunction(gpa, device, "vkGetDataGraphPipelineSessionBindPointRequirementsARM", &table->GetDataGraphPipelineSessionBindPointRequirementsARM);
    LoadVulkanFunction(gpa, device, "vkGetDataGraphPipelineSessionMemoryRequirementsARM", &table->GetDataGraphPipelineSessionMemoryRequirementsARM);
    LoadVulkanFunction(gpa, device, "vkBindDataGraphPipelineSessionMemoryARM", &table->BindDataGraphPipelineSessionMemoryARM);
    LoadVulkanFunction(gpa, device, "vkDestroyDataGraphPipelineSessionARM", &table->DestroyDataGraphPipelineSessionARM);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchDataGraphARM", &table->CmdDispatchDataGraphARM);
    LoadVulkanFunction(gpa, device, "vkGetDataGraphPipelineAvailablePropertiesARM", &table->GetDataGraphPipelineAvailablePropertiesARM);
    LoadVulkanFunction(gpa, device, "vkGetDataGraphPipelinePropertiesARM", &table->GetDataGraphPipelinePropertiesARM);
    LoadVulkanFunction(gpa, device, "vkCmdSetAttachmentFeedbackLoopEnableEXT", &table->CmdSetAttachmentFeedbackLoopEnableEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindTileMemoryQCOM", &table->CmdBindTileMemoryQCOM);
    LoadVulkanFunction(gpa, device, "vkCmdDecompressMemoryEXT", &table->CmdDecompressMemoryEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDecompressMemoryIndirectCountEXT", &table->CmdDecompressMemoryIndirectCountEXT);
    LoadVulkanFunction(gpa, device, "vkGetPartitionedAccelerationStructuresBuildSizesNV", &table->GetPartitionedAccelerationStructuresBuildSizesNV);
    LoadVulkanFunction(gpa, device, "vkCmdBuildPartitionedAccelerationStructuresNV", &table->CmdBuildPartitionedAccelerationStructuresNV);
    LoadVulkanFunction(gpa, device, "vkGetGeneratedCommandsMemoryRequirementsEXT", &table->GetGeneratedCommandsMemoryRequirementsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdPreprocessGeneratedCommandsEXT", &table->CmdPreprocessGeneratedCommandsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdExecuteGeneratedCommandsEXT", &table->CmdExecuteGeneratedCommandsEXT);
    LoadVulkanFunction(gpa, device, "vkCreateIndirectCommandsLayoutEXT", &table->CreateIndirectCommandsLayoutEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyIndirectCommandsLayoutEXT", &table->DestroyIndirectCommandsLayoutEXT);
    LoadVulkanFunction(gpa, device, "vkCreateIndirectExecutionSetEXT", &table->CreateIndirectExecutionSetEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyIndirectExecutionSetEXT", &table->DestroyIndirectExecutionSetEXT);
    LoadVulkanFunction(gpa, device, "vkUpdateIndirectExecutionSetPipelineEXT", &table->UpdateIndirectExecutionSetPipelineEXT);
    LoadVulkanFunction(gpa, device, "vkUpdateIndirectExecutionSetShaderEXT", &table->UpdateIndirectExecutionSetShaderEXT);
    LoadVulkanFunction(gpa, device, "vkGetMemoryMetalHandleEXT", &table->GetMemoryMetalHandleEXT);
    LoadVulkanFunction(gpa, device, "vkGetMemoryMetalHandlePropertiesEXT", &table->GetMemoryMetalHandlePropertiesEXT);
    LoadVulkanFunction(gpa, device, "vkCmdEndRendering2EXT", &table->CmdEndRendering2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdBeginCustomResolveEXT", &table->CmdBeginCustomResolveEXT);
    LoadVulkanFunction(gpa, device, "vkCreateAccelerationStructureKHR", &table->CreateAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkDestroyAccelerationStructureKHR", &table->DestroyAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBuildAccelerationStructuresKHR", &table->CmdBuildAccelerationStructuresKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBuildAccelerationStructuresIndirectKHR", &table->CmdBuildAccelerationStructuresIndirectKHR);
    LoadVulkanFunction(gpa, device, "vkBuildAccelerationStructuresKHR", &table->BuildAccelerationStructuresKHR);
    LoadVulkanFunction(gpa, device, "vkCopyAccelerationStructureKHR", &table->CopyAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkCopyAccelerationStructureToMemoryKHR", &table->CopyAccelerationStructureToMemoryKHR);
    LoadVulkanFunction(gpa, device, "vkCopyMemoryToAccelerationStructureKHR", &table->CopyMemoryToAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkWriteAccelerationStructuresPropertiesKHR", &table->WriteAccelerationStructuresPropertiesKHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyAccelerationStructureKHR", &table->CmdCopyAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyAccelerationStructureToMemoryKHR", &table->CmdCopyAccelerationStructureToMemoryKHR);
    LoadVulkanFunction(gpa, device, "vkCmdCopyMemoryToAccelerationStructureKHR", &table->CmdCopyMemoryToAccelerationStructureKHR);
    LoadVulkanFunction(gpa, device, "vkGetAccelerationStructureDeviceAddressKHR", &table->GetAccelerationStructureDeviceAddressKHR);
    LoadVulkanFunction(gpa, device, "vkCmdWriteAccelerationStructuresPropertiesKHR", &table->CmdWriteAccelerationStructuresPropertiesKHR);
    LoadVulkanFunction(gpa, device, "vkGetDeviceAccelerationStructureCompatibilityKHR", &table->GetDeviceAccelerationStructureCompatibilityKHR);
    LoadVulkanFunction(gpa, device, "vkGetAccelerationStructureBuildSizesKHR", &table->GetAccelerationStructureBuildSizesKHR);
    LoadVulkanFunction(gpa, device, "vkCmdTraceRaysKHR", &table->CmdTraceRaysKHR);
    LoadVulkanFunction(gpa, device, "vkCreateRayTracingPipelinesKHR", &table->CreateRayTracingPipelinesKHR);
    LoadVulkanFunction(gpa, device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", &table->GetRayTracingCaptureReplayShaderGroupHandlesKHR);
    LoadVulkanFunction(gpa, device, "vkCmdTraceRaysIndirectKHR", &table->CmdTraceRaysIndirectKHR);
    LoadVulkanFunction(gpa, device, "vkGetRayTracingShaderGroupStackSizeKHR", &table->GetRayTracingShaderGroupStackSizeKHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetRayTracingPipelineStackSizeKHR", &table->CmdSetRayTracingPipelineStackSizeKHR);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksEXT", &table->CmdDrawMeshTasksEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectEXT", &table->CmdDrawMeshTasksIndirectEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectCountEXT", &table->CmdDrawMeshTasksIndirectCountEXT);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_DISPATCH_TABLE_H
