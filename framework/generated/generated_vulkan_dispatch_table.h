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
GFXRECON_BEGIN_NAMESPACE(encode)

typedef const void* VulkanDispatchKey;

// Retrieve a dispatch key from a dispatchable handle
static VulkanDispatchKey GetVulkanDispatchKey(const void* handle)
{
    const VulkanDispatchKey* dispatch_key = reinterpret_cast<const VulkanDispatchKey*>(handle);
    return (*dispatch_key);
}

GFXRECON_BEGIN_NAMESPACE(noop)
// clang-format off
static VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyInstance was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance, uint32_t*, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDevices was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice, VkPhysicalDeviceFeatures*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice, VkFormat, VkFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice, VkPhysicalDeviceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetInstanceProcAddr was called, resulting in no-op behavior."); return nullptr; }
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumerateDeviceExtensionProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice, uint32_t*, VkLayerProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumerateDeviceLayerProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceGroups was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalBufferProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalFenceProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalSemaphoreProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceToolProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance, VkSurfaceKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySurfaceKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice, uint32_t, VkSurfaceKHR, VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceSupportKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkSurfaceFormatKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceFormatsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDevicePresentRectanglesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPlanePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPlanePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneSupportedDisplaysKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayModePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice, VkDisplayKHR, const VkDisplayModeCreateInfoKHR*, const VkAllocationCallbacks*, VkDisplayModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDisplayModeKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice, VkDisplayModeKHR, uint32_t, VkDisplayPlaneCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance, const VkDisplaySurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDisplayPlaneSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(VkInstance, const VkXlibSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateXlibSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice, uint32_t, Display*, VisualID) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceXlibPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(VkInstance, const VkXcbSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateXcbSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice, uint32_t, xcb_connection_t*, xcb_visualid_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceXcbPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(VkInstance, const VkWaylandSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateWaylandSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice, uint32_t, struct wl_display*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceWaylandPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(VkInstance, const VkAndroidSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAndroidSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(VkInstance, const VkWin32SurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateWin32SurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceWin32PresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice, const VkVideoProfileInfoKHR*, VkVideoCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR*, uint32_t*, VkVideoFormatPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoFormatPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFeatures2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFormatProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceImageFormatProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMemoryProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceGroupsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalBufferPropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalSemaphorePropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalFencePropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkPerformanceCounterKHR*, VkPerformanceCounterDescriptionKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice, const VkQueryPoolPerformanceCreateInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkSurfaceCapabilities2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkSurfaceFormat2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceFormats2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayPlaneProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDisplayPlaneProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModeProperties2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayModeProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice, const VkDisplayPlaneInfo2KHR*, VkDisplayPlaneCapabilities2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDisplayPlaneCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceFragmentShadingRateKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceFragmentShadingRatesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*, VkVideoEncodeQualityLevelPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice, uint32_t*, VkTimeDomainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCalibrateableTimeDomainsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(VkInstance, const VkDebugReportCallbackCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugReportCallbackEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDebugReportCallbackEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(VkInstance, VkDebugReportCallbackEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDebugReportCallbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(VkInstance, VkDebugReportFlagsEXT, VkDebugReportObjectTypeEXT, uint64_t, size_t, int32_t, const char*, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugReportMessageEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP(VkInstance, const VkStreamDescriptorSurfaceCreateInfoGGP*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateStreamDescriptorSurfaceGGP was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkExternalMemoryHandleTypeFlagsNV, VkExternalImageFormatPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceExternalImageFormatPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(VkInstance, const VkViSurfaceCreateInfoNN*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateViSurfaceNN was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(VkPhysicalDevice, Display*, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireXlibDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(VkPhysicalDevice, Display*, RROutput, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRandROutputDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilities2EXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(VkInstance, const VkIOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(VkInstance, const VkMacOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMacOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice, const VkDebugUtilsObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDebugUtilsObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice, const VkDebugUtilsObjectTagInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDebugUtilsObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance, const VkDebugUtilsMessengerCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugUtilsMessengerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance, VkDebugUtilsMessengerEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDebugUtilsMessengerEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance, VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSubmitDebugUtilsMessageEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice, VkSampleCountFlagBits, VkMultisamplePropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceMultisamplePropertiesEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice, uint32_t*, VkTimeDomainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCalibrateableTimeDomainsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(VkInstance, const VkImagePipeSurfaceCreateInfoFUCHSIA*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImagePipeSurfaceFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT(VkInstance, const VkMetalSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMetalSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceToolPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceCooperativeMatrixPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice, uint32_t*, VkFramebufferMixedSamplesCombinationNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance, const VkHeadlessSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateHeadlessSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireDrmDisplayEXT(VkPhysicalDevice, int32_t, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDrmDisplayEXT(VkPhysicalDevice, int32_t, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(VkPhysicalDevice, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT(VkInstance, const VkDirectFBSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDirectFBSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice, uint32_t, IDirectFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceDirectFBPresentationSupportEXT was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateScreenSurfaceQNX(VkInstance, const VkScreenSurfaceCreateInfoQNX*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateScreenSurfaceQNX was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice, uint32_t, struct _screen_window*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceScreenPresentationSupportQNX was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice, const VkOpticalFlowImageFormatInfoNV*, uint32_t*, VkOpticalFlowImageFormatPropertiesNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPhysicalDeviceOpticalFlowImageFormatsNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice, const char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceProcAddr was called, resulting in no-op behavior."); return nullptr; }
static VKAPI_ATTR void VKAPI_CALL DestroyDevice(VkDevice, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDevice was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice, uint32_t, uint32_t, VkQueue*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceQueue was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(VkQueue, uint32_t, const VkSubmitInfo*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDeviceWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL FreeMemory(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeMemory was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL MapMemory(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMapMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory(VkDevice, VkDeviceMemory) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUnmapMemory was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFlushMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkInvalidateMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice, VkDeviceMemory, VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryCommitment was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(VkDevice, VkBuffer, VkMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(VkDevice, VkImage, VkMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueBindSparse was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateFence was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice, VkFence, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyFence was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice, uint32_t, const VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitForFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice, VkSemaphore, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySemaphore was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice, VkEvent, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetEventStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateQueryPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(VkDevice, VkQueryPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueryPoolResults was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice, VkBuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateBufferView was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice, VkBufferView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyBufferView was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImage(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImage was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyImage(VkDevice, VkImage, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateImageView was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice, VkImageView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyImageView was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateShaderModule was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(VkDevice, VkShaderModule, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyShaderModule was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePipelineCache was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice, VkPipelineCache, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipelineCache was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(VkDevice, VkPipelineCache, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineCacheData was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMergePipelineCaches was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateGraphicsPipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateComputePipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice, VkPipeline, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipeline was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePipelineLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPipelineLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSampler was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice, VkSampler, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySampler was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorSetLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorSetLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSets was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateFramebuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice, VkFramebuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyFramebuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice, VkRenderPass, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(VkDevice, VkRenderPass, VkExtent2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRenderAreaGranularity was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(VkDevice, VkCommandPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyCommandPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice, VkCommandPool, VkCommandPoolResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAllocateCommandBuffers was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFreeCommandBuffers was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer, const VkCommandBufferBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBeginCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkEndCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer, VkCommandBufferResetFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindPipeline was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewport was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissor was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineWidth was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer, float, float, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBias was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer, const float[4]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetBlendConstants was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer, float, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBounds was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilCompareMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilWriteMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilReference was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorSets was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindIndexBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDraw was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexed was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatch was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdUpdateBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdFillBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearColorImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearDepthStencilImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdClearAttachments was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginQuery was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndQuery was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyQueryPoolResults was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushConstants was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer, VkSubpassContents) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdExecuteCommands was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPeerMemoryFeatures was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDeviceMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchBase was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPool(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTrimCommandPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice, const VkDeviceQueueInfo2*, VkQueue*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceQueue2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSamplerYcbcrConversion was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySamplerYcbcrConversion was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorUpdateTemplate was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorUpdateTemplate was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSetWithTemplate was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutSupport was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreCounterValue was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitSemaphores was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSignalSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePrivateDataSlot was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPrivateDataSlot was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetPrivateData was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPrivateData was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRendering was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRendering was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCullMode was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFrontFace was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveTopology was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWithCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissorWithCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthWriteEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthCompareOp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBoundsTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilOp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizerDiscardEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBiasEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveRestartEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceBufferMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSwapchainKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(VkDevice, VkSwapchainKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySwapchainKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice, VkSwapchainKHR, uint32_t*, VkImage*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainImagesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireNextImageKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue, const VkPresentInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueuePresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(VkDevice, VkDeviceGroupPresentCapabilitiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPresentCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice, VkSurfaceKHR, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice, const VkAcquireNextImageInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireNextImage2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice, uint32_t, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSharedSwapchainsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionKHR(VkDevice, const VkVideoSessionCreateInfoKHR*, const VkAllocationCallbacks*, VkVideoSessionKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateVideoSessionKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR(VkDevice, VkVideoSessionKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyVideoSessionKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetVideoSessionMemoryRequirementsKHR(VkDevice, VkVideoSessionKHR, uint32_t*, VkVideoSessionMemoryRequirementsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetVideoSessionMemoryRequirementsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindVideoSessionMemoryKHR(VkDevice, VkVideoSessionKHR, uint32_t, const VkBindVideoSessionMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindVideoSessionMemoryKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionParametersKHR(VkDevice, const VkVideoSessionParametersCreateInfoKHR*, const VkAllocationCallbacks*, VkVideoSessionParametersKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL UpdateVideoSessionParametersKHR(VkDevice, VkVideoSessionParametersKHR, const VkVideoSessionParametersUpdateInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR(VkDevice, VkVideoSessionParametersKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyVideoSessionParametersKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR(VkCommandBuffer, const VkVideoBeginCodingInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginVideoCodingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR(VkCommandBuffer, const VkVideoEndCodingInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndVideoCodingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR(VkCommandBuffer, const VkVideoCodingControlInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdControlVideoCodingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR(VkCommandBuffer, const VkVideoDecodeInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDecodeVideoKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupPeerMemoryFeaturesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDeviceMaskKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDispatchBaseKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTrimCommandPoolKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(VkDevice, const VkMemoryGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, HANDLE, VkMemoryWin32HandlePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandlePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(VkDevice, const VkMemoryGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, int, VkMemoryFdPropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryFdPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(VkDevice, const VkImportSemaphoreWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(VkDevice, const VkSemaphoreGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice, const VkImportSemaphoreFdInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice, const VkSemaphoreGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkWriteDescriptorSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer, VkDescriptorUpdateTemplate, VkPipelineLayout, uint32_t, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUpdateDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRenderPass2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginRenderPass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdNextSubpass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndRenderPass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainStatusKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(VkDevice, const VkImportFenceWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(VkDevice, const VkFenceGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice, const VkImportFenceFdInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(VkDevice, const VkFenceGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice, const VkAcquireProfilingLockInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireProfilingLockKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseProfilingLockKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSparseMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateSamplerYcbcrConversionKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroySamplerYcbcrConversionKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindBufferMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindImageMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutSupportKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCountKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCountKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreCounterValueKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitSemaphoresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSignalSemaphoreKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer, const VkExtent2D*, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFragmentShadingRateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer, const VkRenderingAttachmentLocationInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingAttachmentLocationsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer, const VkRenderingInputAttachmentIndexInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRenderingInputAttachmentIndicesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL WaitForPresentKHR(VkDevice, VkSwapchainKHR, uint64_t, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWaitForPresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR(VkDevice, const VkAllocationCallbacks*, VkDeferredOperationKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateDeferredOperationKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR(VkDevice, VkDeferredOperationKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyDeferredOperationKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeferredOperationMaxConcurrencyKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeferredOperationResultKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDeferredOperationJoinKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR(VkDevice, const VkPipelineInfoKHR*, uint32_t*, VkPipelineExecutablePropertiesKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutablePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableStatisticKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutableStatisticsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableInternalRepresentationKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineExecutableInternalRepresentationsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL MapMemory2KHR(VkDevice, const VkMemoryMapInfoKHR*, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMapMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL UnmapMemory2KHR(VkDevice, const VkMemoryUnmapInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUnmapMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetEncodedVideoSessionParametersKHR(VkDevice, const VkVideoEncodeSessionParametersGetInfoKHR*, VkVideoEncodeSessionParametersFeedbackInfoKHR*, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetEncodedVideoSessionParametersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR(VkCommandBuffer, const VkVideoEncodeInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEncodeVideoKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetEvent2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResetEvent2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWaitEvents2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPipelineBarrier2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteTimestamp2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSubmit2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD(VkCommandBuffer, VkPipelineStageFlags2, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteBufferMarker2AMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV(VkQueue, uint32_t*, VkCheckpointData2NV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueueCheckpointData2NV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBuffer2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyBufferToImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyImageToBuffer2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBlitImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdResolveImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR(VkCommandBuffer, VkDeviceAddress) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysIndirect2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceBufferMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSparseMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer2KHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindIndexBuffer2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetRenderingAreaGranularityKHR(VkDevice, const VkRenderingAreaInfoKHR*, VkExtent2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRenderingAreaGranularityKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSubresourceLayoutKHR(VkDevice, const VkDeviceImageSubresourceInfoKHR*, VkSubresourceLayout2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceImageSubresourceLayoutKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2KHR(VkDevice, VkImage, const VkImageSubresource2KHR*, VkSubresourceLayout2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleKHR(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsKHR(VkDevice, uint32_t, const VkCalibratedTimestampInfoKHR*, uint64_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetCalibratedTimestampsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets2KHR(VkCommandBuffer, const VkBindDescriptorSetsInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorSets2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants2KHR(VkCommandBuffer, const VkPushConstantsInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushConstants2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet2KHR(VkCommandBuffer, const VkPushDescriptorSetInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSet2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPushDescriptorSetWithTemplate2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDescriptorBufferOffsets2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindDescriptorBufferEmbeddedSamplers2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL FrameBoundaryANDROID(VkDevice, VkSemaphore, VkImage) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkFrameBoundaryANDROID was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(VkDevice, const VkDebugMarkerObjectTagInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugMarkerSetObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(VkDevice, const VkDebugMarkerObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDebugMarkerSetObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerBeginEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerEndEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDebugMarkerInsertEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindTransformFeedbackBuffersEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginTransformFeedbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndTransformFeedbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginQueryIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndQueryIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT(VkCommandBuffer, uint32_t, uint32_t, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectByteCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX(VkDevice, const VkImageViewHandleInfoNVX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewHandleNVX was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX(VkDevice, VkImageView, VkImageViewAddressPropertiesNVX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageViewAddressNVX was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndirectCountAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawIndexedIndirectCountAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(VkDevice, VkPipeline, VkShaderStageFlagBits, VkShaderInfoTypeAMD, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderInfoAMD was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(VkDevice, VkDeviceMemory, VkExternalMemoryHandleTypeFlagsNV, HANDLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryWin32HandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(VkCommandBuffer, const VkConditionalRenderingBeginInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginConditionalRenderingEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndConditionalRenderingEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(VkCommandBuffer, uint32_t, uint32_t, const VkViewportWScalingNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWScalingNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice, VkDisplayKHR, const VkDisplayPowerInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDisplayPowerControlEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice, const VkDeviceEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkRegisterDeviceEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(VkDevice, VkDisplayKHR, const VkDisplayEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkRegisterDisplayEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice, VkSwapchainKHR, VkSurfaceCounterFlagBitsEXT, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSwapchainCounterEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(VkDevice, VkSwapchainKHR, VkRefreshCycleDurationGOOGLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRefreshCycleDurationGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(VkDevice, VkSwapchainKHR, uint32_t*, VkPastPresentationTimingGOOGLE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPastPresentationTimingGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT(VkCommandBuffer, VkDiscardRectangleModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDiscardRectangleModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice, uint32_t, const VkSwapchainKHR*, const VkHdrMetadataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetHdrMetadataEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(VkDevice, const struct AHardwareBuffer*, VkAndroidHardwareBufferPropertiesANDROID*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAndroidHardwareBufferPropertiesANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(VkDevice, const VkMemoryGetAndroidHardwareBufferInfoANDROID*, struct AHardwareBuffer**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryAndroidHardwareBufferANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer, const VkSampleLocationsInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleLocationsEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice, VkImage, VkImageDrmFormatModifierPropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageDrmFormatModifierPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(VkDevice, const VkValidationCacheCreateInfoEXT*, const VkAllocationCallbacks*, VkValidationCacheEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateValidationCacheEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(VkDevice, VkValidationCacheEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyValidationCacheEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(VkDevice, VkValidationCacheEXT, uint32_t, const VkValidationCacheEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkMergeValidationCachesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(VkDevice, VkValidationCacheEXT, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetValidationCacheDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindShadingRateImageNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(VkCommandBuffer, uint32_t, uint32_t, const VkShadingRatePaletteNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportShadingRatePaletteNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(VkCommandBuffer, VkCoarseSampleOrderTypeNV, uint32_t, const VkCoarseSampleOrderCustomNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoarseSampleOrderNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(VkDevice, const VkAccelerationStructureCreateInfoNV*, const VkAllocationCallbacks*, VkAccelerationStructureNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAccelerationStructureNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(VkDevice, VkAccelerationStructureNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(VkDevice, const VkAccelerationStructureMemoryRequirementsInfoNV*, VkMemoryRequirements2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureMemoryRequirementsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(VkDevice, uint32_t, const VkBindAccelerationStructureMemoryInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindAccelerationStructureMemoryNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV(VkCommandBuffer, const VkAccelerationStructureInfoNV*, VkBuffer, VkDeviceSize, VkBool32, VkAccelerationStructureNV, VkAccelerationStructureNV, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(VkCommandBuffer, VkAccelerationStructureNV, VkAccelerationStructureNV, VkCopyAccelerationStructureModeKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(VkDevice, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoNV*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRayTracingPipelinesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupHandlesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(VkDevice, VkAccelerationStructureNV, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureHandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer, uint32_t, const VkAccelerationStructureNV*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteAccelerationStructuresPropertiesNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(VkDevice, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCompileDeferredNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(VkDevice, VkExternalMemoryHandleTypeFlagBits, const void*, VkMemoryHostPointerPropertiesEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryHostPointerPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(VkCommandBuffer, VkPipelineStageFlagBits, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteBufferMarkerAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(VkDevice, uint32_t, const VkCalibratedTimestampInfoKHR*, uint64_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetCalibratedTimestampsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(VkCommandBuffer, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectCountNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV(VkCommandBuffer, uint32_t, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExclusiveScissorEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExclusiveScissorNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(VkCommandBuffer, const void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCheckpointNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(VkQueue, uint32_t*, VkCheckpointDataNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetQueueCheckpointDataNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL(VkDevice, const VkInitializePerformanceApiInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkInitializePerformanceApiINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL(VkDevice) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkUninitializePerformanceApiINTEL was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL(VkCommandBuffer, const VkPerformanceMarkerInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer, const VkPerformanceStreamMarkerInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceStreamMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL(VkCommandBuffer, const VkPerformanceOverrideInfoINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPerformanceOverrideINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL(VkDevice, const VkPerformanceConfigurationAcquireInfoINTEL*, VkPerformanceConfigurationINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquirePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL(VkDevice, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleasePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL(VkQueue, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueSetPerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL(VkDevice, VkPerformanceParameterTypeINTEL, VkPerformanceValueINTEL*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPerformanceParameterINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD(VkDevice, VkSwapchainKHR, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLocalDimmingAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetBufferDeviceAddressEXT was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkAcquireFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT(VkDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceGroupSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkResetQueryPoolEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCullModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFrontFaceEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveTopologyEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWithCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetScissorWithCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindVertexBuffers2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthWriteEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthCompareOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBoundsTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetStencilOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToImageEXT(VkDevice, const VkCopyMemoryToImageInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToImageEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToMemoryEXT(VkDevice, const VkCopyImageToMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToMemoryEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToImageEXT(VkDevice, const VkCopyImageToImageInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyImageToImageEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL TransitionImageLayoutEXT(VkDevice, uint32_t, const VkHostImageLayoutTransitionInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkTransitionImageLayoutEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT(VkDevice, VkImage, const VkImageSubresource2KHR*, VkSubresourceLayout2KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetImageSubresourceLayout2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseSwapchainImagesEXT(VkDevice, const VkReleaseSwapchainImagesInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkReleaseSwapchainImagesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV(VkDevice, const VkGeneratedCommandsMemoryRequirementsInfoNV*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetGeneratedCommandsMemoryRequirementsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV(VkCommandBuffer, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdPreprocessGeneratedCommandsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV(VkCommandBuffer, VkBool32, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdExecuteGeneratedCommandsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV(VkCommandBuffer, VkPipelineBindPoint, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindPipelineShaderGroupNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV(VkDevice, const VkIndirectCommandsLayoutCreateInfoNV*, const VkAllocationCallbacks*, VkIndirectCommandsLayoutNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateIndirectCommandsLayoutNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV(VkDevice, VkIndirectCommandsLayoutNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyIndirectCommandsLayoutNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias2EXT(VkCommandBuffer, const VkDepthBiasInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBias2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreatePrivateDataSlotEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyPrivateDataSlotEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetPrivateDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPrivateDataEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV(VkCommandBuffer, VkFragmentShadingRateNV, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetFragmentShadingRateEnumNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceFaultInfoEXT(VkDevice, VkDeviceFaultCountsEXT*, VkDeviceFaultInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceFaultInfoEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer, uint32_t, const VkVertexInputBindingDescription2EXT*, uint32_t, const VkVertexInputAttributeDescription2EXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetVertexInputEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandleFUCHSIA(VkDevice, const VkMemoryGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA(VkDevice, VkExternalMemoryHandleTypeFlagBits, zx_handle_t, VkMemoryZirconHandlePropertiesFUCHSIA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryZirconHandlePropertiesFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA(VkDevice, const VkImportSemaphoreZirconHandleInfoFUCHSIA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkImportSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA(VkDevice, const VkSemaphoreGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindInvocationMaskHUAWEI was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryRemoteAddressNV(VkDevice, const VkMemoryGetRemoteAddressInfoNV*, VkRemoteAddressNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMemoryRemoteAddressNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPatchControlPointsEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizerDiscardEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthBiasEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer, VkLogicOp) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLogicOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPrimitiveRestartEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void                                    VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorWriteEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT(VkCommandBuffer, uint32_t, const VkMultiDrawInfoEXT*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMultiEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT(VkCommandBuffer, uint32_t, const VkMultiDrawIndexedInfoEXT*, uint32_t, uint32_t, uint32_t, const int32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMultiIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateMicromapEXT(VkDevice, const VkMicromapCreateInfoEXT*, const VkAllocationCallbacks*, VkMicromapEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT(VkDevice, VkMicromapEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyMicromapEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT(VkCommandBuffer, uint32_t, const VkMicromapBuildInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildMicromapsEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BuildMicromapsEXT(VkDevice, VkDeferredOperationKHR, uint32_t, const VkMicromapBuildInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBuildMicromapsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapToMemoryEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMicromapToMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMicromapToMemoryEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToMicromapEXT(VkDevice, VkDeferredOperationKHR, const VkCopyMemoryToMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToMicromapEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WriteMicromapsPropertiesEXT(VkDevice, uint32_t, const VkMicromapEXT*, VkQueryType, size_t, void*, size_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWriteMicromapsPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT(VkCommandBuffer, const VkCopyMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMicromapEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT(VkCommandBuffer, const VkCopyMicromapToMemoryInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMicromapToMemoryEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT(VkCommandBuffer, const VkCopyMemoryToMicromapInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryToMicromapEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT(VkCommandBuffer, uint32_t, const VkMicromapEXT*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteMicromapsPropertiesEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT(VkDevice, const VkMicromapVersionInfoEXT*, VkAccelerationStructureCompatibilityKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceMicromapCompatibilityEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT(VkDevice, VkAccelerationStructureBuildTypeKHR, const VkMicromapBuildInfoEXT*, VkMicromapBuildSizesInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetMicromapBuildSizesEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawClusterHUAWEI was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI(VkCommandBuffer, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawClusterIndirectHUAWEI was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT(VkDevice, VkDeviceMemory, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetDeviceMemoryPriorityEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice, const VkDescriptorSetBindingReferenceVALVE*, VkDescriptorSetLayoutHostMappingInfoVALVE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetLayoutHostMappingInfoVALVE was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE(VkDevice, VkDescriptorSet, void**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDescriptorSetHostMappingVALVE was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPipelineIndirectMemoryRequirementsNV(VkDevice, const VkComputePipelineCreateInfo*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineIndirectMemoryRequirementsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdUpdatePipelineIndirectBufferNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetPipelineIndirectDeviceAddressNV(VkDevice, const VkPipelineIndirectDeviceAddressInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetPipelineIndirectDeviceAddressNV was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClampEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT(VkCommandBuffer, VkPolygonMode) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetPolygonModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT(VkCommandBuffer, VkSampleCountFlagBits) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizationSamplesEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT(VkCommandBuffer, VkSampleCountFlagBits, const VkSampleMask*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleMaskEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAlphaToCoverageEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAlphaToOneEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLogicOpEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorBlendEquationEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendEquationEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorComponentFlags*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorWriteMaskEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT(VkCommandBuffer, VkTessellationDomainOrigin) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetTessellationDomainOriginEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRasterizationStreamEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT(VkCommandBuffer, VkConservativeRasterizationModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetConservativeRasterizationModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetExtraPrimitiveOverestimationSizeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClipEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetSampleLocationsEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT(VkCommandBuffer, uint32_t, uint32_t, const VkColorBlendAdvancedEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetColorBlendAdvancedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT(VkCommandBuffer, VkProvokingVertexModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetProvokingVertexModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT(VkCommandBuffer, VkLineRasterizationModeEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineRasterizationModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetLineStippleEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetDepthClipNegativeOneToOneEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportWScalingEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV(VkCommandBuffer, uint32_t, uint32_t, const VkViewportSwizzleNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetViewportSwizzleNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageToColorEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageToColorLocationNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV(VkCommandBuffer, VkCoverageModulationModeNV) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationModeNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationTableEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV(VkCommandBuffer, uint32_t, const float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageModulationTableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetShadingRateImageEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRepresentativeFragmentTestEnableNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV(VkCommandBuffer, VkCoverageReductionModeNV) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetCoverageReductionModeNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT(VkDevice, VkShaderModule, VkShaderModuleIdentifierEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderModuleIdentifierEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT(VkDevice, const VkShaderModuleCreateInfo*, VkShaderModuleIdentifierEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderModuleCreateInfoIdentifierEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateOpticalFlowSessionNV(VkDevice, const VkOpticalFlowSessionCreateInfoNV*, const VkAllocationCallbacks*, VkOpticalFlowSessionNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateOpticalFlowSessionNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV(VkDevice, VkOpticalFlowSessionNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyOpticalFlowSessionNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindOpticalFlowSessionImageNV(VkDevice, VkOpticalFlowSessionNV, VkOpticalFlowSessionBindingPointNV, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBindOpticalFlowSessionImageNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV(VkCommandBuffer, VkOpticalFlowSessionNV, const VkOpticalFlowExecuteInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdOpticalFlowExecuteNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateShadersEXT(VkDevice, uint32_t, const VkShaderCreateInfoEXT*, const VkAllocationCallbacks*, VkShaderEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateShadersEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderEXT(VkDevice, VkShaderEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyShaderEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetShaderBinaryDataEXT(VkDevice, VkShaderEXT, size_t*, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetShaderBinaryDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadersEXT(VkCommandBuffer, uint32_t, const VkShaderStageFlagBits*, const VkShaderEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBindShadersEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetFramebufferTilePropertiesQCOM(VkDevice, VkFramebuffer, uint32_t*, VkTilePropertiesQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetFramebufferTilePropertiesQCOM was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM(VkDevice, const VkRenderingInfo*, VkTilePropertiesQCOM*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDynamicRenderingTilePropertiesQCOM was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetLatencySleepModeNV(VkDevice, VkSwapchainKHR, const VkLatencySleepModeInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLatencySleepModeNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL LatencySleepNV(VkDevice, VkSwapchainKHR, const VkLatencySleepInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkLatencySleepNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL SetLatencyMarkerNV(VkDevice, VkSwapchainKHR, const VkSetLatencyMarkerInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkSetLatencyMarkerNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetLatencyTimingsNV(VkDevice, VkSwapchainKHR, VkGetLatencyMarkerInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetLatencyTimingsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueNotifyOutOfBandNV(VkQueue, const VkOutOfBandQueueTypeInfoNV*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkQueueNotifyOutOfBandNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer, VkImageAspectFlags) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetAttachmentFeedbackLoopEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR(VkDevice, const VkAccelerationStructureCreateInfoKHR*, const VkAllocationCallbacks*, VkAccelerationStructureKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR(VkDevice, VkAccelerationStructureKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkDestroyAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkDeviceAddress*, const uint32_t*, const uint32_t* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdBuildAccelerationStructuresIndirectKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BuildAccelerationStructuresKHR(VkDevice, VkDeferredOperationKHR, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WriteAccelerationStructuresPropertiesKHR(VkDevice, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, size_t, void*, size_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR(VkCommandBuffer, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR(VkDevice, const VkAccelerationStructureDeviceAddressInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR(VkDevice, const VkAccelerationStructureVersionInfoKHR*, VkAccelerationStructureCompatibilityKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetDeviceAccelerationStructureCompatibilityKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR(VkDevice, VkAccelerationStructureBuildTypeKHR, const VkAccelerationStructureBuildGeometryInfoKHR*, const uint32_t*, VkAccelerationStructureBuildSizesInfoKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetAccelerationStructureBuildSizesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(VkDevice, VkDeferredOperationKHR, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoKHR*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCreateRayTracingPipelinesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingCaptureReplayShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, VkDeviceAddress) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdTraceRaysIndirectKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceSize VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR(VkDevice, VkPipeline, uint32_t, VkShaderGroupShaderKHR) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkGetRayTracingShaderGroupStackSizeKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdSetRayTracingPipelineStackSizeKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function vkCmdDrawMeshTasksIndirectCountEXT was called, resulting in no-op behavior."); }
// clang-format on
GFXRECON_END_NAMESPACE(noop)

struct VulkanLayerTable
{
    PFN_vkCreateInstance CreateInstance{ nullptr };
    PFN_vkCreateDevice CreateDevice{ nullptr };
};

struct VulkanInstanceTable
{
    PFN_vkDestroyInstance DestroyInstance{ noop::DestroyInstance };
    PFN_vkEnumeratePhysicalDevices EnumeratePhysicalDevices{ noop::EnumeratePhysicalDevices };
    PFN_vkGetPhysicalDeviceFeatures GetPhysicalDeviceFeatures{ noop::GetPhysicalDeviceFeatures };
    PFN_vkGetPhysicalDeviceFormatProperties GetPhysicalDeviceFormatProperties{ noop::GetPhysicalDeviceFormatProperties };
    PFN_vkGetPhysicalDeviceImageFormatProperties GetPhysicalDeviceImageFormatProperties{ noop::GetPhysicalDeviceImageFormatProperties };
    PFN_vkGetPhysicalDeviceProperties GetPhysicalDeviceProperties{ noop::GetPhysicalDeviceProperties };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties GetPhysicalDeviceQueueFamilyProperties{ noop::GetPhysicalDeviceQueueFamilyProperties };
    PFN_vkGetPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties{ noop::GetPhysicalDeviceMemoryProperties };
    PFN_vkGetInstanceProcAddr GetInstanceProcAddr{ noop::GetInstanceProcAddr };
    PFN_vkEnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties{ noop::EnumerateDeviceExtensionProperties };
    PFN_vkEnumerateDeviceLayerProperties EnumerateDeviceLayerProperties{ noop::EnumerateDeviceLayerProperties };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties GetPhysicalDeviceSparseImageFormatProperties{ noop::GetPhysicalDeviceSparseImageFormatProperties };
    PFN_vkEnumeratePhysicalDeviceGroups EnumeratePhysicalDeviceGroups{ noop::EnumeratePhysicalDeviceGroups };
    PFN_vkGetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2{ noop::GetPhysicalDeviceFeatures2 };
    PFN_vkGetPhysicalDeviceProperties2 GetPhysicalDeviceProperties2{ noop::GetPhysicalDeviceProperties2 };
    PFN_vkGetPhysicalDeviceFormatProperties2 GetPhysicalDeviceFormatProperties2{ noop::GetPhysicalDeviceFormatProperties2 };
    PFN_vkGetPhysicalDeviceImageFormatProperties2 GetPhysicalDeviceImageFormatProperties2{ noop::GetPhysicalDeviceImageFormatProperties2 };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2 GetPhysicalDeviceQueueFamilyProperties2{ noop::GetPhysicalDeviceQueueFamilyProperties2 };
    PFN_vkGetPhysicalDeviceMemoryProperties2 GetPhysicalDeviceMemoryProperties2{ noop::GetPhysicalDeviceMemoryProperties2 };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 GetPhysicalDeviceSparseImageFormatProperties2{ noop::GetPhysicalDeviceSparseImageFormatProperties2 };
    PFN_vkGetPhysicalDeviceExternalBufferProperties GetPhysicalDeviceExternalBufferProperties{ noop::GetPhysicalDeviceExternalBufferProperties };
    PFN_vkGetPhysicalDeviceExternalFenceProperties GetPhysicalDeviceExternalFenceProperties{ noop::GetPhysicalDeviceExternalFenceProperties };
    PFN_vkGetPhysicalDeviceExternalSemaphoreProperties GetPhysicalDeviceExternalSemaphoreProperties{ noop::GetPhysicalDeviceExternalSemaphoreProperties };
    PFN_vkGetPhysicalDeviceToolProperties GetPhysicalDeviceToolProperties{ noop::GetPhysicalDeviceToolProperties };
    PFN_vkDestroySurfaceKHR DestroySurfaceKHR{ noop::DestroySurfaceKHR };
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR GetPhysicalDeviceSurfaceSupportKHR{ noop::GetPhysicalDeviceSurfaceSupportKHR };
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR GetPhysicalDeviceSurfaceCapabilitiesKHR{ noop::GetPhysicalDeviceSurfaceCapabilitiesKHR };
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR GetPhysicalDeviceSurfaceFormatsKHR{ noop::GetPhysicalDeviceSurfaceFormatsKHR };
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR GetPhysicalDeviceSurfacePresentModesKHR{ noop::GetPhysicalDeviceSurfacePresentModesKHR };
    PFN_vkGetPhysicalDevicePresentRectanglesKHR GetPhysicalDevicePresentRectanglesKHR{ noop::GetPhysicalDevicePresentRectanglesKHR };
    PFN_vkGetPhysicalDeviceDisplayPropertiesKHR GetPhysicalDeviceDisplayPropertiesKHR{ noop::GetPhysicalDeviceDisplayPropertiesKHR };
    PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR GetPhysicalDeviceDisplayPlanePropertiesKHR{ noop::GetPhysicalDeviceDisplayPlanePropertiesKHR };
    PFN_vkGetDisplayPlaneSupportedDisplaysKHR GetDisplayPlaneSupportedDisplaysKHR{ noop::GetDisplayPlaneSupportedDisplaysKHR };
    PFN_vkGetDisplayModePropertiesKHR GetDisplayModePropertiesKHR{ noop::GetDisplayModePropertiesKHR };
    PFN_vkCreateDisplayModeKHR CreateDisplayModeKHR{ noop::CreateDisplayModeKHR };
    PFN_vkGetDisplayPlaneCapabilitiesKHR GetDisplayPlaneCapabilitiesKHR{ noop::GetDisplayPlaneCapabilitiesKHR };
    PFN_vkCreateDisplayPlaneSurfaceKHR CreateDisplayPlaneSurfaceKHR{ noop::CreateDisplayPlaneSurfaceKHR };
    PFN_vkCreateXlibSurfaceKHR CreateXlibSurfaceKHR{ noop::CreateXlibSurfaceKHR };
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR GetPhysicalDeviceXlibPresentationSupportKHR{ noop::GetPhysicalDeviceXlibPresentationSupportKHR };
    PFN_vkCreateXcbSurfaceKHR CreateXcbSurfaceKHR{ noop::CreateXcbSurfaceKHR };
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR GetPhysicalDeviceXcbPresentationSupportKHR{ noop::GetPhysicalDeviceXcbPresentationSupportKHR };
    PFN_vkCreateWaylandSurfaceKHR CreateWaylandSurfaceKHR{ noop::CreateWaylandSurfaceKHR };
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR GetPhysicalDeviceWaylandPresentationSupportKHR{ noop::GetPhysicalDeviceWaylandPresentationSupportKHR };
    PFN_vkCreateAndroidSurfaceKHR CreateAndroidSurfaceKHR{ noop::CreateAndroidSurfaceKHR };
    PFN_vkCreateWin32SurfaceKHR CreateWin32SurfaceKHR{ noop::CreateWin32SurfaceKHR };
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR GetPhysicalDeviceWin32PresentationSupportKHR{ noop::GetPhysicalDeviceWin32PresentationSupportKHR };
    PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR GetPhysicalDeviceVideoCapabilitiesKHR{ noop::GetPhysicalDeviceVideoCapabilitiesKHR };
    PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR GetPhysicalDeviceVideoFormatPropertiesKHR{ noop::GetPhysicalDeviceVideoFormatPropertiesKHR };
    PFN_vkGetPhysicalDeviceFeatures2KHR GetPhysicalDeviceFeatures2KHR{ noop::GetPhysicalDeviceFeatures2KHR };
    PFN_vkGetPhysicalDeviceProperties2KHR GetPhysicalDeviceProperties2KHR{ noop::GetPhysicalDeviceProperties2KHR };
    PFN_vkGetPhysicalDeviceFormatProperties2KHR GetPhysicalDeviceFormatProperties2KHR{ noop::GetPhysicalDeviceFormatProperties2KHR };
    PFN_vkGetPhysicalDeviceImageFormatProperties2KHR GetPhysicalDeviceImageFormatProperties2KHR{ noop::GetPhysicalDeviceImageFormatProperties2KHR };
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR GetPhysicalDeviceQueueFamilyProperties2KHR{ noop::GetPhysicalDeviceQueueFamilyProperties2KHR };
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR GetPhysicalDeviceMemoryProperties2KHR{ noop::GetPhysicalDeviceMemoryProperties2KHR };
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR GetPhysicalDeviceSparseImageFormatProperties2KHR{ noop::GetPhysicalDeviceSparseImageFormatProperties2KHR };
    PFN_vkEnumeratePhysicalDeviceGroupsKHR EnumeratePhysicalDeviceGroupsKHR{ noop::EnumeratePhysicalDeviceGroupsKHR };
    PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR GetPhysicalDeviceExternalBufferPropertiesKHR{ noop::GetPhysicalDeviceExternalBufferPropertiesKHR };
    PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR GetPhysicalDeviceExternalSemaphorePropertiesKHR{ noop::GetPhysicalDeviceExternalSemaphorePropertiesKHR };
    PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR GetPhysicalDeviceExternalFencePropertiesKHR{ noop::GetPhysicalDeviceExternalFencePropertiesKHR };
    PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR{ noop::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR };
    PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR{ noop::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR };
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR GetPhysicalDeviceSurfaceCapabilities2KHR{ noop::GetPhysicalDeviceSurfaceCapabilities2KHR };
    PFN_vkGetPhysicalDeviceSurfaceFormats2KHR GetPhysicalDeviceSurfaceFormats2KHR{ noop::GetPhysicalDeviceSurfaceFormats2KHR };
    PFN_vkGetPhysicalDeviceDisplayProperties2KHR GetPhysicalDeviceDisplayProperties2KHR{ noop::GetPhysicalDeviceDisplayProperties2KHR };
    PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR GetPhysicalDeviceDisplayPlaneProperties2KHR{ noop::GetPhysicalDeviceDisplayPlaneProperties2KHR };
    PFN_vkGetDisplayModeProperties2KHR GetDisplayModeProperties2KHR{ noop::GetDisplayModeProperties2KHR };
    PFN_vkGetDisplayPlaneCapabilities2KHR GetDisplayPlaneCapabilities2KHR{ noop::GetDisplayPlaneCapabilities2KHR };
    PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR GetPhysicalDeviceFragmentShadingRatesKHR{ noop::GetPhysicalDeviceFragmentShadingRatesKHR };
    PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR{ noop::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR };
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR GetPhysicalDeviceCooperativeMatrixPropertiesKHR{ noop::GetPhysicalDeviceCooperativeMatrixPropertiesKHR };
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR GetPhysicalDeviceCalibrateableTimeDomainsKHR{ noop::GetPhysicalDeviceCalibrateableTimeDomainsKHR };
    PFN_vkCreateDebugReportCallbackEXT CreateDebugReportCallbackEXT{ noop::CreateDebugReportCallbackEXT };
    PFN_vkDestroyDebugReportCallbackEXT DestroyDebugReportCallbackEXT{ noop::DestroyDebugReportCallbackEXT };
    PFN_vkDebugReportMessageEXT DebugReportMessageEXT{ noop::DebugReportMessageEXT };
    PFN_vkCreateStreamDescriptorSurfaceGGP CreateStreamDescriptorSurfaceGGP{ noop::CreateStreamDescriptorSurfaceGGP };
    PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV GetPhysicalDeviceExternalImageFormatPropertiesNV{ noop::GetPhysicalDeviceExternalImageFormatPropertiesNV };
    PFN_vkCreateViSurfaceNN CreateViSurfaceNN{ noop::CreateViSurfaceNN };
    PFN_vkReleaseDisplayEXT ReleaseDisplayEXT{ noop::ReleaseDisplayEXT };
    PFN_vkAcquireXlibDisplayEXT AcquireXlibDisplayEXT{ noop::AcquireXlibDisplayEXT };
    PFN_vkGetRandROutputDisplayEXT GetRandROutputDisplayEXT{ noop::GetRandROutputDisplayEXT };
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT GetPhysicalDeviceSurfaceCapabilities2EXT{ noop::GetPhysicalDeviceSurfaceCapabilities2EXT };
    PFN_vkCreateIOSSurfaceMVK CreateIOSSurfaceMVK{ noop::CreateIOSSurfaceMVK };
    PFN_vkCreateMacOSSurfaceMVK CreateMacOSSurfaceMVK{ noop::CreateMacOSSurfaceMVK };
    PFN_vkSetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT{ noop::SetDebugUtilsObjectNameEXT };
    PFN_vkSetDebugUtilsObjectTagEXT SetDebugUtilsObjectTagEXT{ noop::SetDebugUtilsObjectTagEXT };
    PFN_vkCreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT{ noop::CreateDebugUtilsMessengerEXT };
    PFN_vkDestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessengerEXT{ noop::DestroyDebugUtilsMessengerEXT };
    PFN_vkSubmitDebugUtilsMessageEXT SubmitDebugUtilsMessageEXT{ noop::SubmitDebugUtilsMessageEXT };
    PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT GetPhysicalDeviceMultisamplePropertiesEXT{ noop::GetPhysicalDeviceMultisamplePropertiesEXT };
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT GetPhysicalDeviceCalibrateableTimeDomainsEXT{ noop::GetPhysicalDeviceCalibrateableTimeDomainsEXT };
    PFN_vkCreateImagePipeSurfaceFUCHSIA CreateImagePipeSurfaceFUCHSIA{ noop::CreateImagePipeSurfaceFUCHSIA };
    PFN_vkCreateMetalSurfaceEXT CreateMetalSurfaceEXT{ noop::CreateMetalSurfaceEXT };
    PFN_vkGetPhysicalDeviceToolPropertiesEXT GetPhysicalDeviceToolPropertiesEXT{ noop::GetPhysicalDeviceToolPropertiesEXT };
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV GetPhysicalDeviceCooperativeMatrixPropertiesNV{ noop::GetPhysicalDeviceCooperativeMatrixPropertiesNV };
    PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV{ noop::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV };
    PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT GetPhysicalDeviceSurfacePresentModes2EXT{ noop::GetPhysicalDeviceSurfacePresentModes2EXT };
    PFN_vkCreateHeadlessSurfaceEXT CreateHeadlessSurfaceEXT{ noop::CreateHeadlessSurfaceEXT };
    PFN_vkAcquireDrmDisplayEXT AcquireDrmDisplayEXT{ noop::AcquireDrmDisplayEXT };
    PFN_vkGetDrmDisplayEXT GetDrmDisplayEXT{ noop::GetDrmDisplayEXT };
    PFN_vkAcquireWinrtDisplayNV AcquireWinrtDisplayNV{ noop::AcquireWinrtDisplayNV };
    PFN_vkGetWinrtDisplayNV GetWinrtDisplayNV{ noop::GetWinrtDisplayNV };
    PFN_vkCreateDirectFBSurfaceEXT CreateDirectFBSurfaceEXT{ noop::CreateDirectFBSurfaceEXT };
    PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT GetPhysicalDeviceDirectFBPresentationSupportEXT{ noop::GetPhysicalDeviceDirectFBPresentationSupportEXT };
    PFN_vkCreateScreenSurfaceQNX CreateScreenSurfaceQNX{ noop::CreateScreenSurfaceQNX };
    PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX GetPhysicalDeviceScreenPresentationSupportQNX{ noop::GetPhysicalDeviceScreenPresentationSupportQNX };
    PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV GetPhysicalDeviceOpticalFlowImageFormatsNV{ noop::GetPhysicalDeviceOpticalFlowImageFormatsNV };
};

struct VulkanDeviceTable
{
    PFN_vkGetDeviceProcAddr GetDeviceProcAddr{ noop::GetDeviceProcAddr };
    PFN_vkDestroyDevice DestroyDevice{ noop::DestroyDevice };
    PFN_vkGetDeviceQueue GetDeviceQueue{ noop::GetDeviceQueue };
    PFN_vkQueueSubmit QueueSubmit{ noop::QueueSubmit };
    PFN_vkQueueWaitIdle QueueWaitIdle{ noop::QueueWaitIdle };
    PFN_vkDeviceWaitIdle DeviceWaitIdle{ noop::DeviceWaitIdle };
    PFN_vkAllocateMemory AllocateMemory{ noop::AllocateMemory };
    PFN_vkFreeMemory FreeMemory{ noop::FreeMemory };
    PFN_vkMapMemory MapMemory{ noop::MapMemory };
    PFN_vkUnmapMemory UnmapMemory{ noop::UnmapMemory };
    PFN_vkFlushMappedMemoryRanges FlushMappedMemoryRanges{ noop::FlushMappedMemoryRanges };
    PFN_vkInvalidateMappedMemoryRanges InvalidateMappedMemoryRanges{ noop::InvalidateMappedMemoryRanges };
    PFN_vkGetDeviceMemoryCommitment GetDeviceMemoryCommitment{ noop::GetDeviceMemoryCommitment };
    PFN_vkBindBufferMemory BindBufferMemory{ noop::BindBufferMemory };
    PFN_vkBindImageMemory BindImageMemory{ noop::BindImageMemory };
    PFN_vkGetBufferMemoryRequirements GetBufferMemoryRequirements{ noop::GetBufferMemoryRequirements };
    PFN_vkGetImageMemoryRequirements GetImageMemoryRequirements{ noop::GetImageMemoryRequirements };
    PFN_vkGetImageSparseMemoryRequirements GetImageSparseMemoryRequirements{ noop::GetImageSparseMemoryRequirements };
    PFN_vkQueueBindSparse QueueBindSparse{ noop::QueueBindSparse };
    PFN_vkCreateFence CreateFence{ noop::CreateFence };
    PFN_vkDestroyFence DestroyFence{ noop::DestroyFence };
    PFN_vkResetFences ResetFences{ noop::ResetFences };
    PFN_vkGetFenceStatus GetFenceStatus{ noop::GetFenceStatus };
    PFN_vkWaitForFences WaitForFences{ noop::WaitForFences };
    PFN_vkCreateSemaphore CreateSemaphore{ noop::CreateSemaphore };
    PFN_vkDestroySemaphore DestroySemaphore{ noop::DestroySemaphore };
    PFN_vkCreateEvent CreateEvent{ noop::CreateEvent };
    PFN_vkDestroyEvent DestroyEvent{ noop::DestroyEvent };
    PFN_vkGetEventStatus GetEventStatus{ noop::GetEventStatus };
    PFN_vkSetEvent SetEvent{ noop::SetEvent };
    PFN_vkResetEvent ResetEvent{ noop::ResetEvent };
    PFN_vkCreateQueryPool CreateQueryPool{ noop::CreateQueryPool };
    PFN_vkDestroyQueryPool DestroyQueryPool{ noop::DestroyQueryPool };
    PFN_vkGetQueryPoolResults GetQueryPoolResults{ noop::GetQueryPoolResults };
    PFN_vkCreateBuffer CreateBuffer{ noop::CreateBuffer };
    PFN_vkDestroyBuffer DestroyBuffer{ noop::DestroyBuffer };
    PFN_vkCreateBufferView CreateBufferView{ noop::CreateBufferView };
    PFN_vkDestroyBufferView DestroyBufferView{ noop::DestroyBufferView };
    PFN_vkCreateImage CreateImage{ noop::CreateImage };
    PFN_vkDestroyImage DestroyImage{ noop::DestroyImage };
    PFN_vkGetImageSubresourceLayout GetImageSubresourceLayout{ noop::GetImageSubresourceLayout };
    PFN_vkCreateImageView CreateImageView{ noop::CreateImageView };
    PFN_vkDestroyImageView DestroyImageView{ noop::DestroyImageView };
    PFN_vkCreateShaderModule CreateShaderModule{ noop::CreateShaderModule };
    PFN_vkDestroyShaderModule DestroyShaderModule{ noop::DestroyShaderModule };
    PFN_vkCreatePipelineCache CreatePipelineCache{ noop::CreatePipelineCache };
    PFN_vkDestroyPipelineCache DestroyPipelineCache{ noop::DestroyPipelineCache };
    PFN_vkGetPipelineCacheData GetPipelineCacheData{ noop::GetPipelineCacheData };
    PFN_vkMergePipelineCaches MergePipelineCaches{ noop::MergePipelineCaches };
    PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines{ noop::CreateGraphicsPipelines };
    PFN_vkCreateComputePipelines CreateComputePipelines{ noop::CreateComputePipelines };
    PFN_vkDestroyPipeline DestroyPipeline{ noop::DestroyPipeline };
    PFN_vkCreatePipelineLayout CreatePipelineLayout{ noop::CreatePipelineLayout };
    PFN_vkDestroyPipelineLayout DestroyPipelineLayout{ noop::DestroyPipelineLayout };
    PFN_vkCreateSampler CreateSampler{ noop::CreateSampler };
    PFN_vkDestroySampler DestroySampler{ noop::DestroySampler };
    PFN_vkCreateDescriptorSetLayout CreateDescriptorSetLayout{ noop::CreateDescriptorSetLayout };
    PFN_vkDestroyDescriptorSetLayout DestroyDescriptorSetLayout{ noop::DestroyDescriptorSetLayout };
    PFN_vkCreateDescriptorPool CreateDescriptorPool{ noop::CreateDescriptorPool };
    PFN_vkDestroyDescriptorPool DestroyDescriptorPool{ noop::DestroyDescriptorPool };
    PFN_vkResetDescriptorPool ResetDescriptorPool{ noop::ResetDescriptorPool };
    PFN_vkAllocateDescriptorSets AllocateDescriptorSets{ noop::AllocateDescriptorSets };
    PFN_vkFreeDescriptorSets FreeDescriptorSets{ noop::FreeDescriptorSets };
    PFN_vkUpdateDescriptorSets UpdateDescriptorSets{ noop::UpdateDescriptorSets };
    PFN_vkCreateFramebuffer CreateFramebuffer{ noop::CreateFramebuffer };
    PFN_vkDestroyFramebuffer DestroyFramebuffer{ noop::DestroyFramebuffer };
    PFN_vkCreateRenderPass CreateRenderPass{ noop::CreateRenderPass };
    PFN_vkDestroyRenderPass DestroyRenderPass{ noop::DestroyRenderPass };
    PFN_vkGetRenderAreaGranularity GetRenderAreaGranularity{ noop::GetRenderAreaGranularity };
    PFN_vkCreateCommandPool CreateCommandPool{ noop::CreateCommandPool };
    PFN_vkDestroyCommandPool DestroyCommandPool{ noop::DestroyCommandPool };
    PFN_vkResetCommandPool ResetCommandPool{ noop::ResetCommandPool };
    PFN_vkAllocateCommandBuffers AllocateCommandBuffers{ noop::AllocateCommandBuffers };
    PFN_vkFreeCommandBuffers FreeCommandBuffers{ noop::FreeCommandBuffers };
    PFN_vkBeginCommandBuffer BeginCommandBuffer{ noop::BeginCommandBuffer };
    PFN_vkEndCommandBuffer EndCommandBuffer{ noop::EndCommandBuffer };
    PFN_vkResetCommandBuffer ResetCommandBuffer{ noop::ResetCommandBuffer };
    PFN_vkCmdBindPipeline CmdBindPipeline{ noop::CmdBindPipeline };
    PFN_vkCmdSetViewport CmdSetViewport{ noop::CmdSetViewport };
    PFN_vkCmdSetScissor CmdSetScissor{ noop::CmdSetScissor };
    PFN_vkCmdSetLineWidth CmdSetLineWidth{ noop::CmdSetLineWidth };
    PFN_vkCmdSetDepthBias CmdSetDepthBias{ noop::CmdSetDepthBias };
    PFN_vkCmdSetBlendConstants CmdSetBlendConstants{ noop::CmdSetBlendConstants };
    PFN_vkCmdSetDepthBounds CmdSetDepthBounds{ noop::CmdSetDepthBounds };
    PFN_vkCmdSetStencilCompareMask CmdSetStencilCompareMask{ noop::CmdSetStencilCompareMask };
    PFN_vkCmdSetStencilWriteMask CmdSetStencilWriteMask{ noop::CmdSetStencilWriteMask };
    PFN_vkCmdSetStencilReference CmdSetStencilReference{ noop::CmdSetStencilReference };
    PFN_vkCmdBindDescriptorSets CmdBindDescriptorSets{ noop::CmdBindDescriptorSets };
    PFN_vkCmdBindIndexBuffer CmdBindIndexBuffer{ noop::CmdBindIndexBuffer };
    PFN_vkCmdBindVertexBuffers CmdBindVertexBuffers{ noop::CmdBindVertexBuffers };
    PFN_vkCmdDraw CmdDraw{ noop::CmdDraw };
    PFN_vkCmdDrawIndexed CmdDrawIndexed{ noop::CmdDrawIndexed };
    PFN_vkCmdDrawIndirect CmdDrawIndirect{ noop::CmdDrawIndirect };
    PFN_vkCmdDrawIndexedIndirect CmdDrawIndexedIndirect{ noop::CmdDrawIndexedIndirect };
    PFN_vkCmdDispatch CmdDispatch{ noop::CmdDispatch };
    PFN_vkCmdDispatchIndirect CmdDispatchIndirect{ noop::CmdDispatchIndirect };
    PFN_vkCmdCopyBuffer CmdCopyBuffer{ noop::CmdCopyBuffer };
    PFN_vkCmdCopyImage CmdCopyImage{ noop::CmdCopyImage };
    PFN_vkCmdBlitImage CmdBlitImage{ noop::CmdBlitImage };
    PFN_vkCmdCopyBufferToImage CmdCopyBufferToImage{ noop::CmdCopyBufferToImage };
    PFN_vkCmdCopyImageToBuffer CmdCopyImageToBuffer{ noop::CmdCopyImageToBuffer };
    PFN_vkCmdUpdateBuffer CmdUpdateBuffer{ noop::CmdUpdateBuffer };
    PFN_vkCmdFillBuffer CmdFillBuffer{ noop::CmdFillBuffer };
    PFN_vkCmdClearColorImage CmdClearColorImage{ noop::CmdClearColorImage };
    PFN_vkCmdClearDepthStencilImage CmdClearDepthStencilImage{ noop::CmdClearDepthStencilImage };
    PFN_vkCmdClearAttachments CmdClearAttachments{ noop::CmdClearAttachments };
    PFN_vkCmdResolveImage CmdResolveImage{ noop::CmdResolveImage };
    PFN_vkCmdSetEvent CmdSetEvent{ noop::CmdSetEvent };
    PFN_vkCmdResetEvent CmdResetEvent{ noop::CmdResetEvent };
    PFN_vkCmdWaitEvents CmdWaitEvents{ noop::CmdWaitEvents };
    PFN_vkCmdPipelineBarrier CmdPipelineBarrier{ noop::CmdPipelineBarrier };
    PFN_vkCmdBeginQuery CmdBeginQuery{ noop::CmdBeginQuery };
    PFN_vkCmdEndQuery CmdEndQuery{ noop::CmdEndQuery };
    PFN_vkCmdResetQueryPool CmdResetQueryPool{ noop::CmdResetQueryPool };
    PFN_vkCmdWriteTimestamp CmdWriteTimestamp{ noop::CmdWriteTimestamp };
    PFN_vkCmdCopyQueryPoolResults CmdCopyQueryPoolResults{ noop::CmdCopyQueryPoolResults };
    PFN_vkCmdPushConstants CmdPushConstants{ noop::CmdPushConstants };
    PFN_vkCmdBeginRenderPass CmdBeginRenderPass{ noop::CmdBeginRenderPass };
    PFN_vkCmdNextSubpass CmdNextSubpass{ noop::CmdNextSubpass };
    PFN_vkCmdEndRenderPass CmdEndRenderPass{ noop::CmdEndRenderPass };
    PFN_vkCmdExecuteCommands CmdExecuteCommands{ noop::CmdExecuteCommands };
    PFN_vkBindBufferMemory2 BindBufferMemory2{ noop::BindBufferMemory2 };
    PFN_vkBindImageMemory2 BindImageMemory2{ noop::BindImageMemory2 };
    PFN_vkGetDeviceGroupPeerMemoryFeatures GetDeviceGroupPeerMemoryFeatures{ noop::GetDeviceGroupPeerMemoryFeatures };
    PFN_vkCmdSetDeviceMask CmdSetDeviceMask{ noop::CmdSetDeviceMask };
    PFN_vkCmdDispatchBase CmdDispatchBase{ noop::CmdDispatchBase };
    PFN_vkGetImageMemoryRequirements2 GetImageMemoryRequirements2{ noop::GetImageMemoryRequirements2 };
    PFN_vkGetBufferMemoryRequirements2 GetBufferMemoryRequirements2{ noop::GetBufferMemoryRequirements2 };
    PFN_vkGetImageSparseMemoryRequirements2 GetImageSparseMemoryRequirements2{ noop::GetImageSparseMemoryRequirements2 };
    PFN_vkTrimCommandPool TrimCommandPool{ noop::TrimCommandPool };
    PFN_vkGetDeviceQueue2 GetDeviceQueue2{ noop::GetDeviceQueue2 };
    PFN_vkCreateSamplerYcbcrConversion CreateSamplerYcbcrConversion{ noop::CreateSamplerYcbcrConversion };
    PFN_vkDestroySamplerYcbcrConversion DestroySamplerYcbcrConversion{ noop::DestroySamplerYcbcrConversion };
    PFN_vkCreateDescriptorUpdateTemplate CreateDescriptorUpdateTemplate{ noop::CreateDescriptorUpdateTemplate };
    PFN_vkDestroyDescriptorUpdateTemplate DestroyDescriptorUpdateTemplate{ noop::DestroyDescriptorUpdateTemplate };
    PFN_vkUpdateDescriptorSetWithTemplate UpdateDescriptorSetWithTemplate{ noop::UpdateDescriptorSetWithTemplate };
    PFN_vkGetDescriptorSetLayoutSupport GetDescriptorSetLayoutSupport{ noop::GetDescriptorSetLayoutSupport };
    PFN_vkCmdDrawIndirectCount CmdDrawIndirectCount{ noop::CmdDrawIndirectCount };
    PFN_vkCmdDrawIndexedIndirectCount CmdDrawIndexedIndirectCount{ noop::CmdDrawIndexedIndirectCount };
    PFN_vkCreateRenderPass2 CreateRenderPass2{ noop::CreateRenderPass2 };
    PFN_vkCmdBeginRenderPass2 CmdBeginRenderPass2{ noop::CmdBeginRenderPass2 };
    PFN_vkCmdNextSubpass2 CmdNextSubpass2{ noop::CmdNextSubpass2 };
    PFN_vkCmdEndRenderPass2 CmdEndRenderPass2{ noop::CmdEndRenderPass2 };
    PFN_vkResetQueryPool ResetQueryPool{ noop::ResetQueryPool };
    PFN_vkGetSemaphoreCounterValue GetSemaphoreCounterValue{ noop::GetSemaphoreCounterValue };
    PFN_vkWaitSemaphores WaitSemaphores{ noop::WaitSemaphores };
    PFN_vkSignalSemaphore SignalSemaphore{ noop::SignalSemaphore };
    PFN_vkGetBufferDeviceAddress GetBufferDeviceAddress{ noop::GetBufferDeviceAddress };
    PFN_vkGetBufferOpaqueCaptureAddress GetBufferOpaqueCaptureAddress{ noop::GetBufferOpaqueCaptureAddress };
    PFN_vkGetDeviceMemoryOpaqueCaptureAddress GetDeviceMemoryOpaqueCaptureAddress{ noop::GetDeviceMemoryOpaqueCaptureAddress };
    PFN_vkCreatePrivateDataSlot CreatePrivateDataSlot{ noop::CreatePrivateDataSlot };
    PFN_vkDestroyPrivateDataSlot DestroyPrivateDataSlot{ noop::DestroyPrivateDataSlot };
    PFN_vkSetPrivateData SetPrivateData{ noop::SetPrivateData };
    PFN_vkGetPrivateData GetPrivateData{ noop::GetPrivateData };
    PFN_vkCmdSetEvent2 CmdSetEvent2{ noop::CmdSetEvent2 };
    PFN_vkCmdResetEvent2 CmdResetEvent2{ noop::CmdResetEvent2 };
    PFN_vkCmdWaitEvents2 CmdWaitEvents2{ noop::CmdWaitEvents2 };
    PFN_vkCmdPipelineBarrier2 CmdPipelineBarrier2{ noop::CmdPipelineBarrier2 };
    PFN_vkCmdWriteTimestamp2 CmdWriteTimestamp2{ noop::CmdWriteTimestamp2 };
    PFN_vkQueueSubmit2 QueueSubmit2{ noop::QueueSubmit2 };
    PFN_vkCmdCopyBuffer2 CmdCopyBuffer2{ noop::CmdCopyBuffer2 };
    PFN_vkCmdCopyImage2 CmdCopyImage2{ noop::CmdCopyImage2 };
    PFN_vkCmdCopyBufferToImage2 CmdCopyBufferToImage2{ noop::CmdCopyBufferToImage2 };
    PFN_vkCmdCopyImageToBuffer2 CmdCopyImageToBuffer2{ noop::CmdCopyImageToBuffer2 };
    PFN_vkCmdBlitImage2 CmdBlitImage2{ noop::CmdBlitImage2 };
    PFN_vkCmdResolveImage2 CmdResolveImage2{ noop::CmdResolveImage2 };
    PFN_vkCmdBeginRendering CmdBeginRendering{ noop::CmdBeginRendering };
    PFN_vkCmdEndRendering CmdEndRendering{ noop::CmdEndRendering };
    PFN_vkCmdSetCullMode CmdSetCullMode{ noop::CmdSetCullMode };
    PFN_vkCmdSetFrontFace CmdSetFrontFace{ noop::CmdSetFrontFace };
    PFN_vkCmdSetPrimitiveTopology CmdSetPrimitiveTopology{ noop::CmdSetPrimitiveTopology };
    PFN_vkCmdSetViewportWithCount CmdSetViewportWithCount{ noop::CmdSetViewportWithCount };
    PFN_vkCmdSetScissorWithCount CmdSetScissorWithCount{ noop::CmdSetScissorWithCount };
    PFN_vkCmdBindVertexBuffers2 CmdBindVertexBuffers2{ noop::CmdBindVertexBuffers2 };
    PFN_vkCmdSetDepthTestEnable CmdSetDepthTestEnable{ noop::CmdSetDepthTestEnable };
    PFN_vkCmdSetDepthWriteEnable CmdSetDepthWriteEnable{ noop::CmdSetDepthWriteEnable };
    PFN_vkCmdSetDepthCompareOp CmdSetDepthCompareOp{ noop::CmdSetDepthCompareOp };
    PFN_vkCmdSetDepthBoundsTestEnable CmdSetDepthBoundsTestEnable{ noop::CmdSetDepthBoundsTestEnable };
    PFN_vkCmdSetStencilTestEnable CmdSetStencilTestEnable{ noop::CmdSetStencilTestEnable };
    PFN_vkCmdSetStencilOp CmdSetStencilOp{ noop::CmdSetStencilOp };
    PFN_vkCmdSetRasterizerDiscardEnable CmdSetRasterizerDiscardEnable{ noop::CmdSetRasterizerDiscardEnable };
    PFN_vkCmdSetDepthBiasEnable CmdSetDepthBiasEnable{ noop::CmdSetDepthBiasEnable };
    PFN_vkCmdSetPrimitiveRestartEnable CmdSetPrimitiveRestartEnable{ noop::CmdSetPrimitiveRestartEnable };
    PFN_vkGetDeviceBufferMemoryRequirements GetDeviceBufferMemoryRequirements{ noop::GetDeviceBufferMemoryRequirements };
    PFN_vkGetDeviceImageMemoryRequirements GetDeviceImageMemoryRequirements{ noop::GetDeviceImageMemoryRequirements };
    PFN_vkGetDeviceImageSparseMemoryRequirements GetDeviceImageSparseMemoryRequirements{ noop::GetDeviceImageSparseMemoryRequirements };
    PFN_vkCreateSwapchainKHR CreateSwapchainKHR{ noop::CreateSwapchainKHR };
    PFN_vkDestroySwapchainKHR DestroySwapchainKHR{ noop::DestroySwapchainKHR };
    PFN_vkGetSwapchainImagesKHR GetSwapchainImagesKHR{ noop::GetSwapchainImagesKHR };
    PFN_vkAcquireNextImageKHR AcquireNextImageKHR{ noop::AcquireNextImageKHR };
    PFN_vkQueuePresentKHR QueuePresentKHR{ noop::QueuePresentKHR };
    PFN_vkGetDeviceGroupPresentCapabilitiesKHR GetDeviceGroupPresentCapabilitiesKHR{ noop::GetDeviceGroupPresentCapabilitiesKHR };
    PFN_vkGetDeviceGroupSurfacePresentModesKHR GetDeviceGroupSurfacePresentModesKHR{ noop::GetDeviceGroupSurfacePresentModesKHR };
    PFN_vkAcquireNextImage2KHR AcquireNextImage2KHR{ noop::AcquireNextImage2KHR };
    PFN_vkCreateSharedSwapchainsKHR CreateSharedSwapchainsKHR{ noop::CreateSharedSwapchainsKHR };
    PFN_vkCreateVideoSessionKHR CreateVideoSessionKHR{ noop::CreateVideoSessionKHR };
    PFN_vkDestroyVideoSessionKHR DestroyVideoSessionKHR{ noop::DestroyVideoSessionKHR };
    PFN_vkGetVideoSessionMemoryRequirementsKHR GetVideoSessionMemoryRequirementsKHR{ noop::GetVideoSessionMemoryRequirementsKHR };
    PFN_vkBindVideoSessionMemoryKHR BindVideoSessionMemoryKHR{ noop::BindVideoSessionMemoryKHR };
    PFN_vkCreateVideoSessionParametersKHR CreateVideoSessionParametersKHR{ noop::CreateVideoSessionParametersKHR };
    PFN_vkUpdateVideoSessionParametersKHR UpdateVideoSessionParametersKHR{ noop::UpdateVideoSessionParametersKHR };
    PFN_vkDestroyVideoSessionParametersKHR DestroyVideoSessionParametersKHR{ noop::DestroyVideoSessionParametersKHR };
    PFN_vkCmdBeginVideoCodingKHR CmdBeginVideoCodingKHR{ noop::CmdBeginVideoCodingKHR };
    PFN_vkCmdEndVideoCodingKHR CmdEndVideoCodingKHR{ noop::CmdEndVideoCodingKHR };
    PFN_vkCmdControlVideoCodingKHR CmdControlVideoCodingKHR{ noop::CmdControlVideoCodingKHR };
    PFN_vkCmdDecodeVideoKHR CmdDecodeVideoKHR{ noop::CmdDecodeVideoKHR };
    PFN_vkCmdBeginRenderingKHR CmdBeginRenderingKHR{ noop::CmdBeginRenderingKHR };
    PFN_vkCmdEndRenderingKHR CmdEndRenderingKHR{ noop::CmdEndRenderingKHR };
    PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR GetDeviceGroupPeerMemoryFeaturesKHR{ noop::GetDeviceGroupPeerMemoryFeaturesKHR };
    PFN_vkCmdSetDeviceMaskKHR CmdSetDeviceMaskKHR{ noop::CmdSetDeviceMaskKHR };
    PFN_vkCmdDispatchBaseKHR CmdDispatchBaseKHR{ noop::CmdDispatchBaseKHR };
    PFN_vkTrimCommandPoolKHR TrimCommandPoolKHR{ noop::TrimCommandPoolKHR };
    PFN_vkGetMemoryWin32HandleKHR GetMemoryWin32HandleKHR{ noop::GetMemoryWin32HandleKHR };
    PFN_vkGetMemoryWin32HandlePropertiesKHR GetMemoryWin32HandlePropertiesKHR{ noop::GetMemoryWin32HandlePropertiesKHR };
    PFN_vkGetMemoryFdKHR GetMemoryFdKHR{ noop::GetMemoryFdKHR };
    PFN_vkGetMemoryFdPropertiesKHR GetMemoryFdPropertiesKHR{ noop::GetMemoryFdPropertiesKHR };
    PFN_vkImportSemaphoreWin32HandleKHR ImportSemaphoreWin32HandleKHR{ noop::ImportSemaphoreWin32HandleKHR };
    PFN_vkGetSemaphoreWin32HandleKHR GetSemaphoreWin32HandleKHR{ noop::GetSemaphoreWin32HandleKHR };
    PFN_vkImportSemaphoreFdKHR ImportSemaphoreFdKHR{ noop::ImportSemaphoreFdKHR };
    PFN_vkGetSemaphoreFdKHR GetSemaphoreFdKHR{ noop::GetSemaphoreFdKHR };
    PFN_vkCmdPushDescriptorSetKHR CmdPushDescriptorSetKHR{ noop::CmdPushDescriptorSetKHR };
    PFN_vkCmdPushDescriptorSetWithTemplateKHR CmdPushDescriptorSetWithTemplateKHR{ noop::CmdPushDescriptorSetWithTemplateKHR };
    PFN_vkCreateDescriptorUpdateTemplateKHR CreateDescriptorUpdateTemplateKHR{ noop::CreateDescriptorUpdateTemplateKHR };
    PFN_vkDestroyDescriptorUpdateTemplateKHR DestroyDescriptorUpdateTemplateKHR{ noop::DestroyDescriptorUpdateTemplateKHR };
    PFN_vkUpdateDescriptorSetWithTemplateKHR UpdateDescriptorSetWithTemplateKHR{ noop::UpdateDescriptorSetWithTemplateKHR };
    PFN_vkCreateRenderPass2KHR CreateRenderPass2KHR{ noop::CreateRenderPass2KHR };
    PFN_vkCmdBeginRenderPass2KHR CmdBeginRenderPass2KHR{ noop::CmdBeginRenderPass2KHR };
    PFN_vkCmdNextSubpass2KHR CmdNextSubpass2KHR{ noop::CmdNextSubpass2KHR };
    PFN_vkCmdEndRenderPass2KHR CmdEndRenderPass2KHR{ noop::CmdEndRenderPass2KHR };
    PFN_vkGetSwapchainStatusKHR GetSwapchainStatusKHR{ noop::GetSwapchainStatusKHR };
    PFN_vkImportFenceWin32HandleKHR ImportFenceWin32HandleKHR{ noop::ImportFenceWin32HandleKHR };
    PFN_vkGetFenceWin32HandleKHR GetFenceWin32HandleKHR{ noop::GetFenceWin32HandleKHR };
    PFN_vkImportFenceFdKHR ImportFenceFdKHR{ noop::ImportFenceFdKHR };
    PFN_vkGetFenceFdKHR GetFenceFdKHR{ noop::GetFenceFdKHR };
    PFN_vkAcquireProfilingLockKHR AcquireProfilingLockKHR{ noop::AcquireProfilingLockKHR };
    PFN_vkReleaseProfilingLockKHR ReleaseProfilingLockKHR{ noop::ReleaseProfilingLockKHR };
    PFN_vkGetImageMemoryRequirements2KHR GetImageMemoryRequirements2KHR{ noop::GetImageMemoryRequirements2KHR };
    PFN_vkGetBufferMemoryRequirements2KHR GetBufferMemoryRequirements2KHR{ noop::GetBufferMemoryRequirements2KHR };
    PFN_vkGetImageSparseMemoryRequirements2KHR GetImageSparseMemoryRequirements2KHR{ noop::GetImageSparseMemoryRequirements2KHR };
    PFN_vkCreateSamplerYcbcrConversionKHR CreateSamplerYcbcrConversionKHR{ noop::CreateSamplerYcbcrConversionKHR };
    PFN_vkDestroySamplerYcbcrConversionKHR DestroySamplerYcbcrConversionKHR{ noop::DestroySamplerYcbcrConversionKHR };
    PFN_vkBindBufferMemory2KHR BindBufferMemory2KHR{ noop::BindBufferMemory2KHR };
    PFN_vkBindImageMemory2KHR BindImageMemory2KHR{ noop::BindImageMemory2KHR };
    PFN_vkGetDescriptorSetLayoutSupportKHR GetDescriptorSetLayoutSupportKHR{ noop::GetDescriptorSetLayoutSupportKHR };
    PFN_vkCmdDrawIndirectCountKHR CmdDrawIndirectCountKHR{ noop::CmdDrawIndirectCountKHR };
    PFN_vkCmdDrawIndexedIndirectCountKHR CmdDrawIndexedIndirectCountKHR{ noop::CmdDrawIndexedIndirectCountKHR };
    PFN_vkGetSemaphoreCounterValueKHR GetSemaphoreCounterValueKHR{ noop::GetSemaphoreCounterValueKHR };
    PFN_vkWaitSemaphoresKHR WaitSemaphoresKHR{ noop::WaitSemaphoresKHR };
    PFN_vkSignalSemaphoreKHR SignalSemaphoreKHR{ noop::SignalSemaphoreKHR };
    PFN_vkCmdSetFragmentShadingRateKHR CmdSetFragmentShadingRateKHR{ noop::CmdSetFragmentShadingRateKHR };
    PFN_vkCmdSetRenderingAttachmentLocationsKHR CmdSetRenderingAttachmentLocationsKHR{ noop::CmdSetRenderingAttachmentLocationsKHR };
    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR CmdSetRenderingInputAttachmentIndicesKHR{ noop::CmdSetRenderingInputAttachmentIndicesKHR };
    PFN_vkWaitForPresentKHR WaitForPresentKHR{ noop::WaitForPresentKHR };
    PFN_vkGetBufferDeviceAddressKHR GetBufferDeviceAddressKHR{ noop::GetBufferDeviceAddressKHR };
    PFN_vkGetBufferOpaqueCaptureAddressKHR GetBufferOpaqueCaptureAddressKHR{ noop::GetBufferOpaqueCaptureAddressKHR };
    PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR GetDeviceMemoryOpaqueCaptureAddressKHR{ noop::GetDeviceMemoryOpaqueCaptureAddressKHR };
    PFN_vkCreateDeferredOperationKHR CreateDeferredOperationKHR{ noop::CreateDeferredOperationKHR };
    PFN_vkDestroyDeferredOperationKHR DestroyDeferredOperationKHR{ noop::DestroyDeferredOperationKHR };
    PFN_vkGetDeferredOperationMaxConcurrencyKHR GetDeferredOperationMaxConcurrencyKHR{ noop::GetDeferredOperationMaxConcurrencyKHR };
    PFN_vkGetDeferredOperationResultKHR GetDeferredOperationResultKHR{ noop::GetDeferredOperationResultKHR };
    PFN_vkDeferredOperationJoinKHR DeferredOperationJoinKHR{ noop::DeferredOperationJoinKHR };
    PFN_vkGetPipelineExecutablePropertiesKHR GetPipelineExecutablePropertiesKHR{ noop::GetPipelineExecutablePropertiesKHR };
    PFN_vkGetPipelineExecutableStatisticsKHR GetPipelineExecutableStatisticsKHR{ noop::GetPipelineExecutableStatisticsKHR };
    PFN_vkGetPipelineExecutableInternalRepresentationsKHR GetPipelineExecutableInternalRepresentationsKHR{ noop::GetPipelineExecutableInternalRepresentationsKHR };
    PFN_vkMapMemory2KHR MapMemory2KHR{ noop::MapMemory2KHR };
    PFN_vkUnmapMemory2KHR UnmapMemory2KHR{ noop::UnmapMemory2KHR };
    PFN_vkGetEncodedVideoSessionParametersKHR GetEncodedVideoSessionParametersKHR{ noop::GetEncodedVideoSessionParametersKHR };
    PFN_vkCmdEncodeVideoKHR CmdEncodeVideoKHR{ noop::CmdEncodeVideoKHR };
    PFN_vkCmdSetEvent2KHR CmdSetEvent2KHR{ noop::CmdSetEvent2KHR };
    PFN_vkCmdResetEvent2KHR CmdResetEvent2KHR{ noop::CmdResetEvent2KHR };
    PFN_vkCmdWaitEvents2KHR CmdWaitEvents2KHR{ noop::CmdWaitEvents2KHR };
    PFN_vkCmdPipelineBarrier2KHR CmdPipelineBarrier2KHR{ noop::CmdPipelineBarrier2KHR };
    PFN_vkCmdWriteTimestamp2KHR CmdWriteTimestamp2KHR{ noop::CmdWriteTimestamp2KHR };
    PFN_vkQueueSubmit2KHR QueueSubmit2KHR{ noop::QueueSubmit2KHR };
    PFN_vkCmdWriteBufferMarker2AMD CmdWriteBufferMarker2AMD{ noop::CmdWriteBufferMarker2AMD };
    PFN_vkGetQueueCheckpointData2NV GetQueueCheckpointData2NV{ noop::GetQueueCheckpointData2NV };
    PFN_vkCmdCopyBuffer2KHR CmdCopyBuffer2KHR{ noop::CmdCopyBuffer2KHR };
    PFN_vkCmdCopyImage2KHR CmdCopyImage2KHR{ noop::CmdCopyImage2KHR };
    PFN_vkCmdCopyBufferToImage2KHR CmdCopyBufferToImage2KHR{ noop::CmdCopyBufferToImage2KHR };
    PFN_vkCmdCopyImageToBuffer2KHR CmdCopyImageToBuffer2KHR{ noop::CmdCopyImageToBuffer2KHR };
    PFN_vkCmdBlitImage2KHR CmdBlitImage2KHR{ noop::CmdBlitImage2KHR };
    PFN_vkCmdResolveImage2KHR CmdResolveImage2KHR{ noop::CmdResolveImage2KHR };
    PFN_vkCmdTraceRaysIndirect2KHR CmdTraceRaysIndirect2KHR{ noop::CmdTraceRaysIndirect2KHR };
    PFN_vkGetDeviceBufferMemoryRequirementsKHR GetDeviceBufferMemoryRequirementsKHR{ noop::GetDeviceBufferMemoryRequirementsKHR };
    PFN_vkGetDeviceImageMemoryRequirementsKHR GetDeviceImageMemoryRequirementsKHR{ noop::GetDeviceImageMemoryRequirementsKHR };
    PFN_vkGetDeviceImageSparseMemoryRequirementsKHR GetDeviceImageSparseMemoryRequirementsKHR{ noop::GetDeviceImageSparseMemoryRequirementsKHR };
    PFN_vkCmdBindIndexBuffer2KHR CmdBindIndexBuffer2KHR{ noop::CmdBindIndexBuffer2KHR };
    PFN_vkGetRenderingAreaGranularityKHR GetRenderingAreaGranularityKHR{ noop::GetRenderingAreaGranularityKHR };
    PFN_vkGetDeviceImageSubresourceLayoutKHR GetDeviceImageSubresourceLayoutKHR{ noop::GetDeviceImageSubresourceLayoutKHR };
    PFN_vkGetImageSubresourceLayout2KHR GetImageSubresourceLayout2KHR{ noop::GetImageSubresourceLayout2KHR };
    PFN_vkCmdSetLineStippleKHR CmdSetLineStippleKHR{ noop::CmdSetLineStippleKHR };
    PFN_vkGetCalibratedTimestampsKHR GetCalibratedTimestampsKHR{ noop::GetCalibratedTimestampsKHR };
    PFN_vkCmdBindDescriptorSets2KHR CmdBindDescriptorSets2KHR{ noop::CmdBindDescriptorSets2KHR };
    PFN_vkCmdPushConstants2KHR CmdPushConstants2KHR{ noop::CmdPushConstants2KHR };
    PFN_vkCmdPushDescriptorSet2KHR CmdPushDescriptorSet2KHR{ noop::CmdPushDescriptorSet2KHR };
    PFN_vkCmdPushDescriptorSetWithTemplate2KHR CmdPushDescriptorSetWithTemplate2KHR{ noop::CmdPushDescriptorSetWithTemplate2KHR };
    PFN_vkCmdSetDescriptorBufferOffsets2EXT CmdSetDescriptorBufferOffsets2EXT{ noop::CmdSetDescriptorBufferOffsets2EXT };
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT CmdBindDescriptorBufferEmbeddedSamplers2EXT{ noop::CmdBindDescriptorBufferEmbeddedSamplers2EXT };
    PFN_vkFrameBoundaryANDROID FrameBoundaryANDROID{ noop::FrameBoundaryANDROID };
    PFN_vkDebugMarkerSetObjectTagEXT DebugMarkerSetObjectTagEXT{ noop::DebugMarkerSetObjectTagEXT };
    PFN_vkDebugMarkerSetObjectNameEXT DebugMarkerSetObjectNameEXT{ noop::DebugMarkerSetObjectNameEXT };
    PFN_vkCmdDebugMarkerBeginEXT CmdDebugMarkerBeginEXT{ noop::CmdDebugMarkerBeginEXT };
    PFN_vkCmdDebugMarkerEndEXT CmdDebugMarkerEndEXT{ noop::CmdDebugMarkerEndEXT };
    PFN_vkCmdDebugMarkerInsertEXT CmdDebugMarkerInsertEXT{ noop::CmdDebugMarkerInsertEXT };
    PFN_vkCmdBindTransformFeedbackBuffersEXT CmdBindTransformFeedbackBuffersEXT{ noop::CmdBindTransformFeedbackBuffersEXT };
    PFN_vkCmdBeginTransformFeedbackEXT CmdBeginTransformFeedbackEXT{ noop::CmdBeginTransformFeedbackEXT };
    PFN_vkCmdEndTransformFeedbackEXT CmdEndTransformFeedbackEXT{ noop::CmdEndTransformFeedbackEXT };
    PFN_vkCmdBeginQueryIndexedEXT CmdBeginQueryIndexedEXT{ noop::CmdBeginQueryIndexedEXT };
    PFN_vkCmdEndQueryIndexedEXT CmdEndQueryIndexedEXT{ noop::CmdEndQueryIndexedEXT };
    PFN_vkCmdDrawIndirectByteCountEXT CmdDrawIndirectByteCountEXT{ noop::CmdDrawIndirectByteCountEXT };
    PFN_vkGetImageViewHandleNVX GetImageViewHandleNVX{ noop::GetImageViewHandleNVX };
    PFN_vkGetImageViewAddressNVX GetImageViewAddressNVX{ noop::GetImageViewAddressNVX };
    PFN_vkCmdDrawIndirectCountAMD CmdDrawIndirectCountAMD{ noop::CmdDrawIndirectCountAMD };
    PFN_vkCmdDrawIndexedIndirectCountAMD CmdDrawIndexedIndirectCountAMD{ noop::CmdDrawIndexedIndirectCountAMD };
    PFN_vkGetShaderInfoAMD GetShaderInfoAMD{ noop::GetShaderInfoAMD };
    PFN_vkGetMemoryWin32HandleNV GetMemoryWin32HandleNV{ noop::GetMemoryWin32HandleNV };
    PFN_vkCmdBeginConditionalRenderingEXT CmdBeginConditionalRenderingEXT{ noop::CmdBeginConditionalRenderingEXT };
    PFN_vkCmdEndConditionalRenderingEXT CmdEndConditionalRenderingEXT{ noop::CmdEndConditionalRenderingEXT };
    PFN_vkCmdSetViewportWScalingNV CmdSetViewportWScalingNV{ noop::CmdSetViewportWScalingNV };
    PFN_vkDisplayPowerControlEXT DisplayPowerControlEXT{ noop::DisplayPowerControlEXT };
    PFN_vkRegisterDeviceEventEXT RegisterDeviceEventEXT{ noop::RegisterDeviceEventEXT };
    PFN_vkRegisterDisplayEventEXT RegisterDisplayEventEXT{ noop::RegisterDisplayEventEXT };
    PFN_vkGetSwapchainCounterEXT GetSwapchainCounterEXT{ noop::GetSwapchainCounterEXT };
    PFN_vkGetRefreshCycleDurationGOOGLE GetRefreshCycleDurationGOOGLE{ noop::GetRefreshCycleDurationGOOGLE };
    PFN_vkGetPastPresentationTimingGOOGLE GetPastPresentationTimingGOOGLE{ noop::GetPastPresentationTimingGOOGLE };
    PFN_vkCmdSetDiscardRectangleEXT CmdSetDiscardRectangleEXT{ noop::CmdSetDiscardRectangleEXT };
    PFN_vkCmdSetDiscardRectangleEnableEXT CmdSetDiscardRectangleEnableEXT{ noop::CmdSetDiscardRectangleEnableEXT };
    PFN_vkCmdSetDiscardRectangleModeEXT CmdSetDiscardRectangleModeEXT{ noop::CmdSetDiscardRectangleModeEXT };
    PFN_vkSetHdrMetadataEXT SetHdrMetadataEXT{ noop::SetHdrMetadataEXT };
    PFN_vkQueueBeginDebugUtilsLabelEXT QueueBeginDebugUtilsLabelEXT{ noop::QueueBeginDebugUtilsLabelEXT };
    PFN_vkQueueEndDebugUtilsLabelEXT QueueEndDebugUtilsLabelEXT{ noop::QueueEndDebugUtilsLabelEXT };
    PFN_vkQueueInsertDebugUtilsLabelEXT QueueInsertDebugUtilsLabelEXT{ noop::QueueInsertDebugUtilsLabelEXT };
    PFN_vkCmdBeginDebugUtilsLabelEXT CmdBeginDebugUtilsLabelEXT{ noop::CmdBeginDebugUtilsLabelEXT };
    PFN_vkCmdEndDebugUtilsLabelEXT CmdEndDebugUtilsLabelEXT{ noop::CmdEndDebugUtilsLabelEXT };
    PFN_vkCmdInsertDebugUtilsLabelEXT CmdInsertDebugUtilsLabelEXT{ noop::CmdInsertDebugUtilsLabelEXT };
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID GetAndroidHardwareBufferPropertiesANDROID{ noop::GetAndroidHardwareBufferPropertiesANDROID };
    PFN_vkGetMemoryAndroidHardwareBufferANDROID GetMemoryAndroidHardwareBufferANDROID{ noop::GetMemoryAndroidHardwareBufferANDROID };
    PFN_vkCmdSetSampleLocationsEXT CmdSetSampleLocationsEXT{ noop::CmdSetSampleLocationsEXT };
    PFN_vkGetImageDrmFormatModifierPropertiesEXT GetImageDrmFormatModifierPropertiesEXT{ noop::GetImageDrmFormatModifierPropertiesEXT };
    PFN_vkCreateValidationCacheEXT CreateValidationCacheEXT{ noop::CreateValidationCacheEXT };
    PFN_vkDestroyValidationCacheEXT DestroyValidationCacheEXT{ noop::DestroyValidationCacheEXT };
    PFN_vkMergeValidationCachesEXT MergeValidationCachesEXT{ noop::MergeValidationCachesEXT };
    PFN_vkGetValidationCacheDataEXT GetValidationCacheDataEXT{ noop::GetValidationCacheDataEXT };
    PFN_vkCmdBindShadingRateImageNV CmdBindShadingRateImageNV{ noop::CmdBindShadingRateImageNV };
    PFN_vkCmdSetViewportShadingRatePaletteNV CmdSetViewportShadingRatePaletteNV{ noop::CmdSetViewportShadingRatePaletteNV };
    PFN_vkCmdSetCoarseSampleOrderNV CmdSetCoarseSampleOrderNV{ noop::CmdSetCoarseSampleOrderNV };
    PFN_vkCreateAccelerationStructureNV CreateAccelerationStructureNV{ noop::CreateAccelerationStructureNV };
    PFN_vkDestroyAccelerationStructureNV DestroyAccelerationStructureNV{ noop::DestroyAccelerationStructureNV };
    PFN_vkGetAccelerationStructureMemoryRequirementsNV GetAccelerationStructureMemoryRequirementsNV{ noop::GetAccelerationStructureMemoryRequirementsNV };
    PFN_vkBindAccelerationStructureMemoryNV BindAccelerationStructureMemoryNV{ noop::BindAccelerationStructureMemoryNV };
    PFN_vkCmdBuildAccelerationStructureNV CmdBuildAccelerationStructureNV{ noop::CmdBuildAccelerationStructureNV };
    PFN_vkCmdCopyAccelerationStructureNV CmdCopyAccelerationStructureNV{ noop::CmdCopyAccelerationStructureNV };
    PFN_vkCmdTraceRaysNV CmdTraceRaysNV{ noop::CmdTraceRaysNV };
    PFN_vkCreateRayTracingPipelinesNV CreateRayTracingPipelinesNV{ noop::CreateRayTracingPipelinesNV };
    PFN_vkGetRayTracingShaderGroupHandlesKHR GetRayTracingShaderGroupHandlesKHR{ noop::GetRayTracingShaderGroupHandlesKHR };
    PFN_vkGetRayTracingShaderGroupHandlesNV GetRayTracingShaderGroupHandlesNV{ noop::GetRayTracingShaderGroupHandlesNV };
    PFN_vkGetAccelerationStructureHandleNV GetAccelerationStructureHandleNV{ noop::GetAccelerationStructureHandleNV };
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV CmdWriteAccelerationStructuresPropertiesNV{ noop::CmdWriteAccelerationStructuresPropertiesNV };
    PFN_vkCompileDeferredNV CompileDeferredNV{ noop::CompileDeferredNV };
    PFN_vkGetMemoryHostPointerPropertiesEXT GetMemoryHostPointerPropertiesEXT{ noop::GetMemoryHostPointerPropertiesEXT };
    PFN_vkCmdWriteBufferMarkerAMD CmdWriteBufferMarkerAMD{ noop::CmdWriteBufferMarkerAMD };
    PFN_vkGetCalibratedTimestampsEXT GetCalibratedTimestampsEXT{ noop::GetCalibratedTimestampsEXT };
    PFN_vkCmdDrawMeshTasksNV CmdDrawMeshTasksNV{ noop::CmdDrawMeshTasksNV };
    PFN_vkCmdDrawMeshTasksIndirectNV CmdDrawMeshTasksIndirectNV{ noop::CmdDrawMeshTasksIndirectNV };
    PFN_vkCmdDrawMeshTasksIndirectCountNV CmdDrawMeshTasksIndirectCountNV{ noop::CmdDrawMeshTasksIndirectCountNV };
    PFN_vkCmdSetExclusiveScissorEnableNV CmdSetExclusiveScissorEnableNV{ noop::CmdSetExclusiveScissorEnableNV };
    PFN_vkCmdSetExclusiveScissorNV CmdSetExclusiveScissorNV{ noop::CmdSetExclusiveScissorNV };
    PFN_vkCmdSetCheckpointNV CmdSetCheckpointNV{ noop::CmdSetCheckpointNV };
    PFN_vkGetQueueCheckpointDataNV GetQueueCheckpointDataNV{ noop::GetQueueCheckpointDataNV };
    PFN_vkInitializePerformanceApiINTEL InitializePerformanceApiINTEL{ noop::InitializePerformanceApiINTEL };
    PFN_vkUninitializePerformanceApiINTEL UninitializePerformanceApiINTEL{ noop::UninitializePerformanceApiINTEL };
    PFN_vkCmdSetPerformanceMarkerINTEL CmdSetPerformanceMarkerINTEL{ noop::CmdSetPerformanceMarkerINTEL };
    PFN_vkCmdSetPerformanceStreamMarkerINTEL CmdSetPerformanceStreamMarkerINTEL{ noop::CmdSetPerformanceStreamMarkerINTEL };
    PFN_vkCmdSetPerformanceOverrideINTEL CmdSetPerformanceOverrideINTEL{ noop::CmdSetPerformanceOverrideINTEL };
    PFN_vkAcquirePerformanceConfigurationINTEL AcquirePerformanceConfigurationINTEL{ noop::AcquirePerformanceConfigurationINTEL };
    PFN_vkReleasePerformanceConfigurationINTEL ReleasePerformanceConfigurationINTEL{ noop::ReleasePerformanceConfigurationINTEL };
    PFN_vkQueueSetPerformanceConfigurationINTEL QueueSetPerformanceConfigurationINTEL{ noop::QueueSetPerformanceConfigurationINTEL };
    PFN_vkGetPerformanceParameterINTEL GetPerformanceParameterINTEL{ noop::GetPerformanceParameterINTEL };
    PFN_vkSetLocalDimmingAMD SetLocalDimmingAMD{ noop::SetLocalDimmingAMD };
    PFN_vkGetBufferDeviceAddressEXT GetBufferDeviceAddressEXT{ noop::GetBufferDeviceAddressEXT };
    PFN_vkAcquireFullScreenExclusiveModeEXT AcquireFullScreenExclusiveModeEXT{ noop::AcquireFullScreenExclusiveModeEXT };
    PFN_vkReleaseFullScreenExclusiveModeEXT ReleaseFullScreenExclusiveModeEXT{ noop::ReleaseFullScreenExclusiveModeEXT };
    PFN_vkGetDeviceGroupSurfacePresentModes2EXT GetDeviceGroupSurfacePresentModes2EXT{ noop::GetDeviceGroupSurfacePresentModes2EXT };
    PFN_vkCmdSetLineStippleEXT CmdSetLineStippleEXT{ noop::CmdSetLineStippleEXT };
    PFN_vkResetQueryPoolEXT ResetQueryPoolEXT{ noop::ResetQueryPoolEXT };
    PFN_vkCmdSetCullModeEXT CmdSetCullModeEXT{ noop::CmdSetCullModeEXT };
    PFN_vkCmdSetFrontFaceEXT CmdSetFrontFaceEXT{ noop::CmdSetFrontFaceEXT };
    PFN_vkCmdSetPrimitiveTopologyEXT CmdSetPrimitiveTopologyEXT{ noop::CmdSetPrimitiveTopologyEXT };
    PFN_vkCmdSetViewportWithCountEXT CmdSetViewportWithCountEXT{ noop::CmdSetViewportWithCountEXT };
    PFN_vkCmdSetScissorWithCountEXT CmdSetScissorWithCountEXT{ noop::CmdSetScissorWithCountEXT };
    PFN_vkCmdBindVertexBuffers2EXT CmdBindVertexBuffers2EXT{ noop::CmdBindVertexBuffers2EXT };
    PFN_vkCmdSetDepthTestEnableEXT CmdSetDepthTestEnableEXT{ noop::CmdSetDepthTestEnableEXT };
    PFN_vkCmdSetDepthWriteEnableEXT CmdSetDepthWriteEnableEXT{ noop::CmdSetDepthWriteEnableEXT };
    PFN_vkCmdSetDepthCompareOpEXT CmdSetDepthCompareOpEXT{ noop::CmdSetDepthCompareOpEXT };
    PFN_vkCmdSetDepthBoundsTestEnableEXT CmdSetDepthBoundsTestEnableEXT{ noop::CmdSetDepthBoundsTestEnableEXT };
    PFN_vkCmdSetStencilTestEnableEXT CmdSetStencilTestEnableEXT{ noop::CmdSetStencilTestEnableEXT };
    PFN_vkCmdSetStencilOpEXT CmdSetStencilOpEXT{ noop::CmdSetStencilOpEXT };
    PFN_vkCopyMemoryToImageEXT CopyMemoryToImageEXT{ noop::CopyMemoryToImageEXT };
    PFN_vkCopyImageToMemoryEXT CopyImageToMemoryEXT{ noop::CopyImageToMemoryEXT };
    PFN_vkCopyImageToImageEXT CopyImageToImageEXT{ noop::CopyImageToImageEXT };
    PFN_vkTransitionImageLayoutEXT TransitionImageLayoutEXT{ noop::TransitionImageLayoutEXT };
    PFN_vkGetImageSubresourceLayout2EXT GetImageSubresourceLayout2EXT{ noop::GetImageSubresourceLayout2EXT };
    PFN_vkReleaseSwapchainImagesEXT ReleaseSwapchainImagesEXT{ noop::ReleaseSwapchainImagesEXT };
    PFN_vkGetGeneratedCommandsMemoryRequirementsNV GetGeneratedCommandsMemoryRequirementsNV{ noop::GetGeneratedCommandsMemoryRequirementsNV };
    PFN_vkCmdPreprocessGeneratedCommandsNV CmdPreprocessGeneratedCommandsNV{ noop::CmdPreprocessGeneratedCommandsNV };
    PFN_vkCmdExecuteGeneratedCommandsNV CmdExecuteGeneratedCommandsNV{ noop::CmdExecuteGeneratedCommandsNV };
    PFN_vkCmdBindPipelineShaderGroupNV CmdBindPipelineShaderGroupNV{ noop::CmdBindPipelineShaderGroupNV };
    PFN_vkCreateIndirectCommandsLayoutNV CreateIndirectCommandsLayoutNV{ noop::CreateIndirectCommandsLayoutNV };
    PFN_vkDestroyIndirectCommandsLayoutNV DestroyIndirectCommandsLayoutNV{ noop::DestroyIndirectCommandsLayoutNV };
    PFN_vkCmdSetDepthBias2EXT CmdSetDepthBias2EXT{ noop::CmdSetDepthBias2EXT };
    PFN_vkCreatePrivateDataSlotEXT CreatePrivateDataSlotEXT{ noop::CreatePrivateDataSlotEXT };
    PFN_vkDestroyPrivateDataSlotEXT DestroyPrivateDataSlotEXT{ noop::DestroyPrivateDataSlotEXT };
    PFN_vkSetPrivateDataEXT SetPrivateDataEXT{ noop::SetPrivateDataEXT };
    PFN_vkGetPrivateDataEXT GetPrivateDataEXT{ noop::GetPrivateDataEXT };
    PFN_vkCmdSetFragmentShadingRateEnumNV CmdSetFragmentShadingRateEnumNV{ noop::CmdSetFragmentShadingRateEnumNV };
    PFN_vkGetDeviceFaultInfoEXT GetDeviceFaultInfoEXT{ noop::GetDeviceFaultInfoEXT };
    PFN_vkCmdSetVertexInputEXT CmdSetVertexInputEXT{ noop::CmdSetVertexInputEXT };
    PFN_vkGetMemoryZirconHandleFUCHSIA GetMemoryZirconHandleFUCHSIA{ noop::GetMemoryZirconHandleFUCHSIA };
    PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA GetMemoryZirconHandlePropertiesFUCHSIA{ noop::GetMemoryZirconHandlePropertiesFUCHSIA };
    PFN_vkImportSemaphoreZirconHandleFUCHSIA ImportSemaphoreZirconHandleFUCHSIA{ noop::ImportSemaphoreZirconHandleFUCHSIA };
    PFN_vkGetSemaphoreZirconHandleFUCHSIA GetSemaphoreZirconHandleFUCHSIA{ noop::GetSemaphoreZirconHandleFUCHSIA };
    PFN_vkCmdBindInvocationMaskHUAWEI CmdBindInvocationMaskHUAWEI{ noop::CmdBindInvocationMaskHUAWEI };
    PFN_vkGetMemoryRemoteAddressNV GetMemoryRemoteAddressNV{ noop::GetMemoryRemoteAddressNV };
    PFN_vkCmdSetPatchControlPointsEXT CmdSetPatchControlPointsEXT{ noop::CmdSetPatchControlPointsEXT };
    PFN_vkCmdSetRasterizerDiscardEnableEXT CmdSetRasterizerDiscardEnableEXT{ noop::CmdSetRasterizerDiscardEnableEXT };
    PFN_vkCmdSetDepthBiasEnableEXT CmdSetDepthBiasEnableEXT{ noop::CmdSetDepthBiasEnableEXT };
    PFN_vkCmdSetLogicOpEXT CmdSetLogicOpEXT{ noop::CmdSetLogicOpEXT };
    PFN_vkCmdSetPrimitiveRestartEnableEXT CmdSetPrimitiveRestartEnableEXT{ noop::CmdSetPrimitiveRestartEnableEXT };
    PFN_vkCmdSetColorWriteEnableEXT CmdSetColorWriteEnableEXT{ noop::CmdSetColorWriteEnableEXT };
    PFN_vkCmdDrawMultiEXT CmdDrawMultiEXT{ noop::CmdDrawMultiEXT };
    PFN_vkCmdDrawMultiIndexedEXT CmdDrawMultiIndexedEXT{ noop::CmdDrawMultiIndexedEXT };
    PFN_vkCreateMicromapEXT CreateMicromapEXT{ noop::CreateMicromapEXT };
    PFN_vkDestroyMicromapEXT DestroyMicromapEXT{ noop::DestroyMicromapEXT };
    PFN_vkCmdBuildMicromapsEXT CmdBuildMicromapsEXT{ noop::CmdBuildMicromapsEXT };
    PFN_vkBuildMicromapsEXT BuildMicromapsEXT{ noop::BuildMicromapsEXT };
    PFN_vkCopyMicromapEXT CopyMicromapEXT{ noop::CopyMicromapEXT };
    PFN_vkCopyMicromapToMemoryEXT CopyMicromapToMemoryEXT{ noop::CopyMicromapToMemoryEXT };
    PFN_vkCopyMemoryToMicromapEXT CopyMemoryToMicromapEXT{ noop::CopyMemoryToMicromapEXT };
    PFN_vkWriteMicromapsPropertiesEXT WriteMicromapsPropertiesEXT{ noop::WriteMicromapsPropertiesEXT };
    PFN_vkCmdCopyMicromapEXT CmdCopyMicromapEXT{ noop::CmdCopyMicromapEXT };
    PFN_vkCmdCopyMicromapToMemoryEXT CmdCopyMicromapToMemoryEXT{ noop::CmdCopyMicromapToMemoryEXT };
    PFN_vkCmdCopyMemoryToMicromapEXT CmdCopyMemoryToMicromapEXT{ noop::CmdCopyMemoryToMicromapEXT };
    PFN_vkCmdWriteMicromapsPropertiesEXT CmdWriteMicromapsPropertiesEXT{ noop::CmdWriteMicromapsPropertiesEXT };
    PFN_vkGetDeviceMicromapCompatibilityEXT GetDeviceMicromapCompatibilityEXT{ noop::GetDeviceMicromapCompatibilityEXT };
    PFN_vkGetMicromapBuildSizesEXT GetMicromapBuildSizesEXT{ noop::GetMicromapBuildSizesEXT };
    PFN_vkCmdDrawClusterHUAWEI CmdDrawClusterHUAWEI{ noop::CmdDrawClusterHUAWEI };
    PFN_vkCmdDrawClusterIndirectHUAWEI CmdDrawClusterIndirectHUAWEI{ noop::CmdDrawClusterIndirectHUAWEI };
    PFN_vkSetDeviceMemoryPriorityEXT SetDeviceMemoryPriorityEXT{ noop::SetDeviceMemoryPriorityEXT };
    PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE GetDescriptorSetLayoutHostMappingInfoVALVE{ noop::GetDescriptorSetLayoutHostMappingInfoVALVE };
    PFN_vkGetDescriptorSetHostMappingVALVE GetDescriptorSetHostMappingVALVE{ noop::GetDescriptorSetHostMappingVALVE };
    PFN_vkGetPipelineIndirectMemoryRequirementsNV GetPipelineIndirectMemoryRequirementsNV{ noop::GetPipelineIndirectMemoryRequirementsNV };
    PFN_vkCmdUpdatePipelineIndirectBufferNV CmdUpdatePipelineIndirectBufferNV{ noop::CmdUpdatePipelineIndirectBufferNV };
    PFN_vkGetPipelineIndirectDeviceAddressNV GetPipelineIndirectDeviceAddressNV{ noop::GetPipelineIndirectDeviceAddressNV };
    PFN_vkCmdSetDepthClampEnableEXT CmdSetDepthClampEnableEXT{ noop::CmdSetDepthClampEnableEXT };
    PFN_vkCmdSetPolygonModeEXT CmdSetPolygonModeEXT{ noop::CmdSetPolygonModeEXT };
    PFN_vkCmdSetRasterizationSamplesEXT CmdSetRasterizationSamplesEXT{ noop::CmdSetRasterizationSamplesEXT };
    PFN_vkCmdSetSampleMaskEXT CmdSetSampleMaskEXT{ noop::CmdSetSampleMaskEXT };
    PFN_vkCmdSetAlphaToCoverageEnableEXT CmdSetAlphaToCoverageEnableEXT{ noop::CmdSetAlphaToCoverageEnableEXT };
    PFN_vkCmdSetAlphaToOneEnableEXT CmdSetAlphaToOneEnableEXT{ noop::CmdSetAlphaToOneEnableEXT };
    PFN_vkCmdSetLogicOpEnableEXT CmdSetLogicOpEnableEXT{ noop::CmdSetLogicOpEnableEXT };
    PFN_vkCmdSetColorBlendEnableEXT CmdSetColorBlendEnableEXT{ noop::CmdSetColorBlendEnableEXT };
    PFN_vkCmdSetColorBlendEquationEXT CmdSetColorBlendEquationEXT{ noop::CmdSetColorBlendEquationEXT };
    PFN_vkCmdSetColorWriteMaskEXT CmdSetColorWriteMaskEXT{ noop::CmdSetColorWriteMaskEXT };
    PFN_vkCmdSetTessellationDomainOriginEXT CmdSetTessellationDomainOriginEXT{ noop::CmdSetTessellationDomainOriginEXT };
    PFN_vkCmdSetRasterizationStreamEXT CmdSetRasterizationStreamEXT{ noop::CmdSetRasterizationStreamEXT };
    PFN_vkCmdSetConservativeRasterizationModeEXT CmdSetConservativeRasterizationModeEXT{ noop::CmdSetConservativeRasterizationModeEXT };
    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT CmdSetExtraPrimitiveOverestimationSizeEXT{ noop::CmdSetExtraPrimitiveOverestimationSizeEXT };
    PFN_vkCmdSetDepthClipEnableEXT CmdSetDepthClipEnableEXT{ noop::CmdSetDepthClipEnableEXT };
    PFN_vkCmdSetSampleLocationsEnableEXT CmdSetSampleLocationsEnableEXT{ noop::CmdSetSampleLocationsEnableEXT };
    PFN_vkCmdSetColorBlendAdvancedEXT CmdSetColorBlendAdvancedEXT{ noop::CmdSetColorBlendAdvancedEXT };
    PFN_vkCmdSetProvokingVertexModeEXT CmdSetProvokingVertexModeEXT{ noop::CmdSetProvokingVertexModeEXT };
    PFN_vkCmdSetLineRasterizationModeEXT CmdSetLineRasterizationModeEXT{ noop::CmdSetLineRasterizationModeEXT };
    PFN_vkCmdSetLineStippleEnableEXT CmdSetLineStippleEnableEXT{ noop::CmdSetLineStippleEnableEXT };
    PFN_vkCmdSetDepthClipNegativeOneToOneEXT CmdSetDepthClipNegativeOneToOneEXT{ noop::CmdSetDepthClipNegativeOneToOneEXT };
    PFN_vkCmdSetViewportWScalingEnableNV CmdSetViewportWScalingEnableNV{ noop::CmdSetViewportWScalingEnableNV };
    PFN_vkCmdSetViewportSwizzleNV CmdSetViewportSwizzleNV{ noop::CmdSetViewportSwizzleNV };
    PFN_vkCmdSetCoverageToColorEnableNV CmdSetCoverageToColorEnableNV{ noop::CmdSetCoverageToColorEnableNV };
    PFN_vkCmdSetCoverageToColorLocationNV CmdSetCoverageToColorLocationNV{ noop::CmdSetCoverageToColorLocationNV };
    PFN_vkCmdSetCoverageModulationModeNV CmdSetCoverageModulationModeNV{ noop::CmdSetCoverageModulationModeNV };
    PFN_vkCmdSetCoverageModulationTableEnableNV CmdSetCoverageModulationTableEnableNV{ noop::CmdSetCoverageModulationTableEnableNV };
    PFN_vkCmdSetCoverageModulationTableNV CmdSetCoverageModulationTableNV{ noop::CmdSetCoverageModulationTableNV };
    PFN_vkCmdSetShadingRateImageEnableNV CmdSetShadingRateImageEnableNV{ noop::CmdSetShadingRateImageEnableNV };
    PFN_vkCmdSetRepresentativeFragmentTestEnableNV CmdSetRepresentativeFragmentTestEnableNV{ noop::CmdSetRepresentativeFragmentTestEnableNV };
    PFN_vkCmdSetCoverageReductionModeNV CmdSetCoverageReductionModeNV{ noop::CmdSetCoverageReductionModeNV };
    PFN_vkGetShaderModuleIdentifierEXT GetShaderModuleIdentifierEXT{ noop::GetShaderModuleIdentifierEXT };
    PFN_vkGetShaderModuleCreateInfoIdentifierEXT GetShaderModuleCreateInfoIdentifierEXT{ noop::GetShaderModuleCreateInfoIdentifierEXT };
    PFN_vkCreateOpticalFlowSessionNV CreateOpticalFlowSessionNV{ noop::CreateOpticalFlowSessionNV };
    PFN_vkDestroyOpticalFlowSessionNV DestroyOpticalFlowSessionNV{ noop::DestroyOpticalFlowSessionNV };
    PFN_vkBindOpticalFlowSessionImageNV BindOpticalFlowSessionImageNV{ noop::BindOpticalFlowSessionImageNV };
    PFN_vkCmdOpticalFlowExecuteNV CmdOpticalFlowExecuteNV{ noop::CmdOpticalFlowExecuteNV };
    PFN_vkCreateShadersEXT CreateShadersEXT{ noop::CreateShadersEXT };
    PFN_vkDestroyShaderEXT DestroyShaderEXT{ noop::DestroyShaderEXT };
    PFN_vkGetShaderBinaryDataEXT GetShaderBinaryDataEXT{ noop::GetShaderBinaryDataEXT };
    PFN_vkCmdBindShadersEXT CmdBindShadersEXT{ noop::CmdBindShadersEXT };
    PFN_vkGetFramebufferTilePropertiesQCOM GetFramebufferTilePropertiesQCOM{ noop::GetFramebufferTilePropertiesQCOM };
    PFN_vkGetDynamicRenderingTilePropertiesQCOM GetDynamicRenderingTilePropertiesQCOM{ noop::GetDynamicRenderingTilePropertiesQCOM };
    PFN_vkSetLatencySleepModeNV SetLatencySleepModeNV{ noop::SetLatencySleepModeNV };
    PFN_vkLatencySleepNV LatencySleepNV{ noop::LatencySleepNV };
    PFN_vkSetLatencyMarkerNV SetLatencyMarkerNV{ noop::SetLatencyMarkerNV };
    PFN_vkGetLatencyTimingsNV GetLatencyTimingsNV{ noop::GetLatencyTimingsNV };
    PFN_vkQueueNotifyOutOfBandNV QueueNotifyOutOfBandNV{ noop::QueueNotifyOutOfBandNV };
    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT CmdSetAttachmentFeedbackLoopEnableEXT{ noop::CmdSetAttachmentFeedbackLoopEnableEXT };
    PFN_vkCreateAccelerationStructureKHR CreateAccelerationStructureKHR{ noop::CreateAccelerationStructureKHR };
    PFN_vkDestroyAccelerationStructureKHR DestroyAccelerationStructureKHR{ noop::DestroyAccelerationStructureKHR };
    PFN_vkCmdBuildAccelerationStructuresKHR CmdBuildAccelerationStructuresKHR{ noop::CmdBuildAccelerationStructuresKHR };
    PFN_vkCmdBuildAccelerationStructuresIndirectKHR CmdBuildAccelerationStructuresIndirectKHR{ noop::CmdBuildAccelerationStructuresIndirectKHR };
    PFN_vkBuildAccelerationStructuresKHR BuildAccelerationStructuresKHR{ noop::BuildAccelerationStructuresKHR };
    PFN_vkCopyAccelerationStructureKHR CopyAccelerationStructureKHR{ noop::CopyAccelerationStructureKHR };
    PFN_vkCopyAccelerationStructureToMemoryKHR CopyAccelerationStructureToMemoryKHR{ noop::CopyAccelerationStructureToMemoryKHR };
    PFN_vkCopyMemoryToAccelerationStructureKHR CopyMemoryToAccelerationStructureKHR{ noop::CopyMemoryToAccelerationStructureKHR };
    PFN_vkWriteAccelerationStructuresPropertiesKHR WriteAccelerationStructuresPropertiesKHR{ noop::WriteAccelerationStructuresPropertiesKHR };
    PFN_vkCmdCopyAccelerationStructureKHR CmdCopyAccelerationStructureKHR{ noop::CmdCopyAccelerationStructureKHR };
    PFN_vkCmdCopyAccelerationStructureToMemoryKHR CmdCopyAccelerationStructureToMemoryKHR{ noop::CmdCopyAccelerationStructureToMemoryKHR };
    PFN_vkCmdCopyMemoryToAccelerationStructureKHR CmdCopyMemoryToAccelerationStructureKHR{ noop::CmdCopyMemoryToAccelerationStructureKHR };
    PFN_vkGetAccelerationStructureDeviceAddressKHR GetAccelerationStructureDeviceAddressKHR{ noop::GetAccelerationStructureDeviceAddressKHR };
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR CmdWriteAccelerationStructuresPropertiesKHR{ noop::CmdWriteAccelerationStructuresPropertiesKHR };
    PFN_vkGetDeviceAccelerationStructureCompatibilityKHR GetDeviceAccelerationStructureCompatibilityKHR{ noop::GetDeviceAccelerationStructureCompatibilityKHR };
    PFN_vkGetAccelerationStructureBuildSizesKHR GetAccelerationStructureBuildSizesKHR{ noop::GetAccelerationStructureBuildSizesKHR };
    PFN_vkCmdTraceRaysKHR CmdTraceRaysKHR{ noop::CmdTraceRaysKHR };
    PFN_vkCreateRayTracingPipelinesKHR CreateRayTracingPipelinesKHR{ noop::CreateRayTracingPipelinesKHR };
    PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR GetRayTracingCaptureReplayShaderGroupHandlesKHR{ noop::GetRayTracingCaptureReplayShaderGroupHandlesKHR };
    PFN_vkCmdTraceRaysIndirectKHR CmdTraceRaysIndirectKHR{ noop::CmdTraceRaysIndirectKHR };
    PFN_vkGetRayTracingShaderGroupStackSizeKHR GetRayTracingShaderGroupStackSizeKHR{ noop::GetRayTracingShaderGroupStackSizeKHR };
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR CmdSetRayTracingPipelineStackSizeKHR{ noop::CmdSetRayTracingPipelineStackSizeKHR };
    PFN_vkCmdDrawMeshTasksEXT CmdDrawMeshTasksEXT{ noop::CmdDrawMeshTasksEXT };
    PFN_vkCmdDrawMeshTasksIndirectEXT CmdDrawMeshTasksIndirectEXT{ noop::CmdDrawMeshTasksIndirectEXT };
    PFN_vkCmdDrawMeshTasksIndirectCountEXT CmdDrawMeshTasksIndirectCountEXT{ noop::CmdDrawMeshTasksIndirectCountEXT };
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
    LoadVulkanFunction(gpa, device, "vkCreateEvent", &table->CreateEvent);
    LoadVulkanFunction(gpa, device, "vkDestroyEvent", &table->DestroyEvent);
    LoadVulkanFunction(gpa, device, "vkGetEventStatus", &table->GetEventStatus);
    LoadVulkanFunction(gpa, device, "vkSetEvent", &table->SetEvent);
    LoadVulkanFunction(gpa, device, "vkResetEvent", &table->ResetEvent);
    LoadVulkanFunction(gpa, device, "vkCreateQueryPool", &table->CreateQueryPool);
    LoadVulkanFunction(gpa, device, "vkDestroyQueryPool", &table->DestroyQueryPool);
    LoadVulkanFunction(gpa, device, "vkGetQueryPoolResults", &table->GetQueryPoolResults);
    LoadVulkanFunction(gpa, device, "vkCreateBuffer", &table->CreateBuffer);
    LoadVulkanFunction(gpa, device, "vkDestroyBuffer", &table->DestroyBuffer);
    LoadVulkanFunction(gpa, device, "vkCreateBufferView", &table->CreateBufferView);
    LoadVulkanFunction(gpa, device, "vkDestroyBufferView", &table->DestroyBufferView);
    LoadVulkanFunction(gpa, device, "vkCreateImage", &table->CreateImage);
    LoadVulkanFunction(gpa, device, "vkDestroyImage", &table->DestroyImage);
    LoadVulkanFunction(gpa, device, "vkGetImageSubresourceLayout", &table->GetImageSubresourceLayout);
    LoadVulkanFunction(gpa, device, "vkCreateImageView", &table->CreateImageView);
    LoadVulkanFunction(gpa, device, "vkDestroyImageView", &table->DestroyImageView);
    LoadVulkanFunction(gpa, device, "vkCreateShaderModule", &table->CreateShaderModule);
    LoadVulkanFunction(gpa, device, "vkDestroyShaderModule", &table->DestroyShaderModule);
    LoadVulkanFunction(gpa, device, "vkCreatePipelineCache", &table->CreatePipelineCache);
    LoadVulkanFunction(gpa, device, "vkDestroyPipelineCache", &table->DestroyPipelineCache);
    LoadVulkanFunction(gpa, device, "vkGetPipelineCacheData", &table->GetPipelineCacheData);
    LoadVulkanFunction(gpa, device, "vkMergePipelineCaches", &table->MergePipelineCaches);
    LoadVulkanFunction(gpa, device, "vkCreateGraphicsPipelines", &table->CreateGraphicsPipelines);
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
    LoadVulkanFunction(gpa, device, "vkCreateFramebuffer", &table->CreateFramebuffer);
    LoadVulkanFunction(gpa, device, "vkDestroyFramebuffer", &table->DestroyFramebuffer);
    LoadVulkanFunction(gpa, device, "vkCreateRenderPass", &table->CreateRenderPass);
    LoadVulkanFunction(gpa, device, "vkDestroyRenderPass", &table->DestroyRenderPass);
    LoadVulkanFunction(gpa, device, "vkGetRenderAreaGranularity", &table->GetRenderAreaGranularity);
    LoadVulkanFunction(gpa, device, "vkCreateCommandPool", &table->CreateCommandPool);
    LoadVulkanFunction(gpa, device, "vkDestroyCommandPool", &table->DestroyCommandPool);
    LoadVulkanFunction(gpa, device, "vkResetCommandPool", &table->ResetCommandPool);
    LoadVulkanFunction(gpa, device, "vkAllocateCommandBuffers", &table->AllocateCommandBuffers);
    LoadVulkanFunction(gpa, device, "vkFreeCommandBuffers", &table->FreeCommandBuffers);
    LoadVulkanFunction(gpa, device, "vkBeginCommandBuffer", &table->BeginCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkEndCommandBuffer", &table->EndCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkResetCommandBuffer", &table->ResetCommandBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdBindPipeline", &table->CmdBindPipeline);
    LoadVulkanFunction(gpa, device, "vkCmdSetViewport", &table->CmdSetViewport);
    LoadVulkanFunction(gpa, device, "vkCmdSetScissor", &table->CmdSetScissor);
    LoadVulkanFunction(gpa, device, "vkCmdSetLineWidth", &table->CmdSetLineWidth);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBias", &table->CmdSetDepthBias);
    LoadVulkanFunction(gpa, device, "vkCmdSetBlendConstants", &table->CmdSetBlendConstants);
    LoadVulkanFunction(gpa, device, "vkCmdSetDepthBounds", &table->CmdSetDepthBounds);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilCompareMask", &table->CmdSetStencilCompareMask);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilWriteMask", &table->CmdSetStencilWriteMask);
    LoadVulkanFunction(gpa, device, "vkCmdSetStencilReference", &table->CmdSetStencilReference);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorSets", &table->CmdBindDescriptorSets);
    LoadVulkanFunction(gpa, device, "vkCmdBindIndexBuffer", &table->CmdBindIndexBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdBindVertexBuffers", &table->CmdBindVertexBuffers);
    LoadVulkanFunction(gpa, device, "vkCmdDraw", &table->CmdDraw);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexed", &table->CmdDrawIndexed);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirect", &table->CmdDrawIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirect", &table->CmdDrawIndexedIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdDispatch", &table->CmdDispatch);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchIndirect", &table->CmdDispatchIndirect);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBuffer", &table->CmdCopyBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImage", &table->CmdCopyImage);
    LoadVulkanFunction(gpa, device, "vkCmdBlitImage", &table->CmdBlitImage);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBufferToImage", &table->CmdCopyBufferToImage);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImageToBuffer", &table->CmdCopyImageToBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdUpdateBuffer", &table->CmdUpdateBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdFillBuffer", &table->CmdFillBuffer);
    LoadVulkanFunction(gpa, device, "vkCmdClearColorImage", &table->CmdClearColorImage);
    LoadVulkanFunction(gpa, device, "vkCmdClearDepthStencilImage", &table->CmdClearDepthStencilImage);
    LoadVulkanFunction(gpa, device, "vkCmdClearAttachments", &table->CmdClearAttachments);
    LoadVulkanFunction(gpa, device, "vkCmdResolveImage", &table->CmdResolveImage);
    LoadVulkanFunction(gpa, device, "vkCmdSetEvent", &table->CmdSetEvent);
    LoadVulkanFunction(gpa, device, "vkCmdResetEvent", &table->CmdResetEvent);
    LoadVulkanFunction(gpa, device, "vkCmdWaitEvents", &table->CmdWaitEvents);
    LoadVulkanFunction(gpa, device, "vkCmdPipelineBarrier", &table->CmdPipelineBarrier);
    LoadVulkanFunction(gpa, device, "vkCmdBeginQuery", &table->CmdBeginQuery);
    LoadVulkanFunction(gpa, device, "vkCmdEndQuery", &table->CmdEndQuery);
    LoadVulkanFunction(gpa, device, "vkCmdResetQueryPool", &table->CmdResetQueryPool);
    LoadVulkanFunction(gpa, device, "vkCmdWriteTimestamp", &table->CmdWriteTimestamp);
    LoadVulkanFunction(gpa, device, "vkCmdCopyQueryPoolResults", &table->CmdCopyQueryPoolResults);
    LoadVulkanFunction(gpa, device, "vkCmdPushConstants", &table->CmdPushConstants);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderPass", &table->CmdBeginRenderPass);
    LoadVulkanFunction(gpa, device, "vkCmdNextSubpass", &table->CmdNextSubpass);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderPass", &table->CmdEndRenderPass);
    LoadVulkanFunction(gpa, device, "vkCmdExecuteCommands", &table->CmdExecuteCommands);
    LoadVulkanFunction(gpa, device, "vkBindBufferMemory2", &table->BindBufferMemory2);
    LoadVulkanFunction(gpa, device, "vkBindImageMemory2", &table->BindImageMemory2);
    LoadVulkanFunction(gpa, device, "vkGetDeviceGroupPeerMemoryFeatures", &table->GetDeviceGroupPeerMemoryFeatures);
    LoadVulkanFunction(gpa, device, "vkCmdSetDeviceMask", &table->CmdSetDeviceMask);
    LoadVulkanFunction(gpa, device, "vkCmdDispatchBase", &table->CmdDispatchBase);
    LoadVulkanFunction(gpa, device, "vkGetImageMemoryRequirements2", &table->GetImageMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkGetBufferMemoryRequirements2", &table->GetBufferMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkGetImageSparseMemoryRequirements2", &table->GetImageSparseMemoryRequirements2);
    LoadVulkanFunction(gpa, device, "vkTrimCommandPool", &table->TrimCommandPool);
    LoadVulkanFunction(gpa, device, "vkGetDeviceQueue2", &table->GetDeviceQueue2);
    LoadVulkanFunction(gpa, device, "vkCreateSamplerYcbcrConversion", &table->CreateSamplerYcbcrConversion);
    LoadVulkanFunction(gpa, device, "vkDestroySamplerYcbcrConversion", &table->DestroySamplerYcbcrConversion);
    LoadVulkanFunction(gpa, device, "vkCreateDescriptorUpdateTemplate", &table->CreateDescriptorUpdateTemplate);
    LoadVulkanFunction(gpa, device, "vkDestroyDescriptorUpdateTemplate", &table->DestroyDescriptorUpdateTemplate);
    LoadVulkanFunction(gpa, device, "vkUpdateDescriptorSetWithTemplate", &table->UpdateDescriptorSetWithTemplate);
    LoadVulkanFunction(gpa, device, "vkGetDescriptorSetLayoutSupport", &table->GetDescriptorSetLayoutSupport);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndirectCount", &table->CmdDrawIndirectCount);
    LoadVulkanFunction(gpa, device, "vkCmdDrawIndexedIndirectCount", &table->CmdDrawIndexedIndirectCount);
    LoadVulkanFunction(gpa, device, "vkCreateRenderPass2", &table->CreateRenderPass2);
    LoadVulkanFunction(gpa, device, "vkCmdBeginRenderPass2", &table->CmdBeginRenderPass2);
    LoadVulkanFunction(gpa, device, "vkCmdNextSubpass2", &table->CmdNextSubpass2);
    LoadVulkanFunction(gpa, device, "vkCmdEndRenderPass2", &table->CmdEndRenderPass2);
    LoadVulkanFunction(gpa, device, "vkResetQueryPool", &table->ResetQueryPool);
    LoadVulkanFunction(gpa, device, "vkGetSemaphoreCounterValue", &table->GetSemaphoreCounterValue);
    LoadVulkanFunction(gpa, device, "vkWaitSemaphores", &table->WaitSemaphores);
    LoadVulkanFunction(gpa, device, "vkSignalSemaphore", &table->SignalSemaphore);
    LoadVulkanFunction(gpa, device, "vkGetBufferDeviceAddress", &table->GetBufferDeviceAddress);
    LoadVulkanFunction(gpa, device, "vkGetBufferOpaqueCaptureAddress", &table->GetBufferOpaqueCaptureAddress);
    LoadVulkanFunction(gpa, device, "vkGetDeviceMemoryOpaqueCaptureAddress", &table->GetDeviceMemoryOpaqueCaptureAddress);
    LoadVulkanFunction(gpa, device, "vkCreatePrivateDataSlot", &table->CreatePrivateDataSlot);
    LoadVulkanFunction(gpa, device, "vkDestroyPrivateDataSlot", &table->DestroyPrivateDataSlot);
    LoadVulkanFunction(gpa, device, "vkSetPrivateData", &table->SetPrivateData);
    LoadVulkanFunction(gpa, device, "vkGetPrivateData", &table->GetPrivateData);
    LoadVulkanFunction(gpa, device, "vkCmdSetEvent2", &table->CmdSetEvent2);
    LoadVulkanFunction(gpa, device, "vkCmdResetEvent2", &table->CmdResetEvent2);
    LoadVulkanFunction(gpa, device, "vkCmdWaitEvents2", &table->CmdWaitEvents2);
    LoadVulkanFunction(gpa, device, "vkCmdPipelineBarrier2", &table->CmdPipelineBarrier2);
    LoadVulkanFunction(gpa, device, "vkCmdWriteTimestamp2", &table->CmdWriteTimestamp2);
    LoadVulkanFunction(gpa, device, "vkQueueSubmit2", &table->QueueSubmit2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBuffer2", &table->CmdCopyBuffer2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImage2", &table->CmdCopyImage2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyBufferToImage2", &table->CmdCopyBufferToImage2);
    LoadVulkanFunction(gpa, device, "vkCmdCopyImageToBuffer2", &table->CmdCopyImageToBuffer2);
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
    LoadVulkanFunction(gpa, device, "vkGetDeviceBufferMemoryRequirements", &table->GetDeviceBufferMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageMemoryRequirements", &table->GetDeviceImageMemoryRequirements);
    LoadVulkanFunction(gpa, device, "vkGetDeviceImageSparseMemoryRequirements", &table->GetDeviceImageSparseMemoryRequirements);
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
    LoadVulkanFunction(gpa, device, "vkCmdWriteBufferMarker2AMD", &table->CmdWriteBufferMarker2AMD);
    LoadVulkanFunction(gpa, device, "vkGetQueueCheckpointData2NV", &table->GetQueueCheckpointData2NV);
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
    LoadVulkanFunction(gpa, device, "vkCmdSetLineStippleKHR", &table->CmdSetLineStippleKHR);
    LoadVulkanFunction(gpa, device, "vkGetCalibratedTimestampsKHR", &table->GetCalibratedTimestampsKHR);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorSets2KHR", &table->CmdBindDescriptorSets2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushConstants2KHR", &table->CmdPushConstants2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSet2KHR", &table->CmdPushDescriptorSet2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplate2KHR", &table->CmdPushDescriptorSetWithTemplate2KHR);
    LoadVulkanFunction(gpa, device, "vkCmdSetDescriptorBufferOffsets2EXT", &table->CmdSetDescriptorBufferOffsets2EXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT", &table->CmdBindDescriptorBufferEmbeddedSamplers2EXT);
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
    LoadVulkanFunction(gpa, device, "vkGetCalibratedTimestampsEXT", &table->GetCalibratedTimestampsEXT);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksNV", &table->CmdDrawMeshTasksNV);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectNV", &table->CmdDrawMeshTasksIndirectNV);
    LoadVulkanFunction(gpa, device, "vkCmdDrawMeshTasksIndirectCountNV", &table->CmdDrawMeshTasksIndirectCountNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetExclusiveScissorEnableNV", &table->CmdSetExclusiveScissorEnableNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetExclusiveScissorNV", &table->CmdSetExclusiveScissorNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetCheckpointNV", &table->CmdSetCheckpointNV);
    LoadVulkanFunction(gpa, device, "vkGetQueueCheckpointDataNV", &table->GetQueueCheckpointDataNV);
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
    LoadVulkanFunction(gpa, device, "vkCreateShadersEXT", &table->CreateShadersEXT);
    LoadVulkanFunction(gpa, device, "vkDestroyShaderEXT", &table->DestroyShaderEXT);
    LoadVulkanFunction(gpa, device, "vkGetShaderBinaryDataEXT", &table->GetShaderBinaryDataEXT);
    LoadVulkanFunction(gpa, device, "vkCmdBindShadersEXT", &table->CmdBindShadersEXT);
    LoadVulkanFunction(gpa, device, "vkGetFramebufferTilePropertiesQCOM", &table->GetFramebufferTilePropertiesQCOM);
    LoadVulkanFunction(gpa, device, "vkGetDynamicRenderingTilePropertiesQCOM", &table->GetDynamicRenderingTilePropertiesQCOM);
    LoadVulkanFunction(gpa, device, "vkSetLatencySleepModeNV", &table->SetLatencySleepModeNV);
    LoadVulkanFunction(gpa, device, "vkLatencySleepNV", &table->LatencySleepNV);
    LoadVulkanFunction(gpa, device, "vkSetLatencyMarkerNV", &table->SetLatencyMarkerNV);
    LoadVulkanFunction(gpa, device, "vkGetLatencyTimingsNV", &table->GetLatencyTimingsNV);
    LoadVulkanFunction(gpa, device, "vkQueueNotifyOutOfBandNV", &table->QueueNotifyOutOfBandNV);
    LoadVulkanFunction(gpa, device, "vkCmdSetAttachmentFeedbackLoopEnableEXT", &table->CmdSetAttachmentFeedbackLoopEnableEXT);
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
