/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

typedef const void* DispatchKey;

// Retrieve a dispatch key from a dispatchable handle
static DispatchKey GetDispatchKey(const void* handle)
{
    const DispatchKey* dispatch_key = reinterpret_cast<const DispatchKey*>(handle);
    return (*dispatch_key);
}

GFXRECON_BEGIN_NAMESPACE(noop)
// clang-format off
static VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyInstance was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance, uint32_t*, VkPhysicalDevice*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumeratePhysicalDevices was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice, VkPhysicalDeviceFeatures*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFeatures was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice, VkFormat, VkFormatProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFormatProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceImageFormatProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice, VkPhysicalDeviceProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceMemoryProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance, const char*) { GFXRECON_LOG_WARNING("Unsupported function vkGetInstanceProcAddr was called, resulting in no-op behavior."); return nullptr; }
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumerateDeviceExtensionProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice, uint32_t*, VkLayerProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumerateDeviceLayerProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumeratePhysicalDeviceGroups was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFeatures2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFormatProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceImageFormatProperties2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceMemoryProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalBufferProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalFenceProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalSemaphoreProperties was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceToolProperties was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance, VkSurfaceKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySurfaceKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice, uint32_t, VkSurfaceKHR, VkBool32*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceSupportKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilitiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkSurfaceFormatKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceFormatsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice, VkSurfaceKHR, uint32_t*, VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDevicePresentRectanglesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceDisplayPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice, uint32_t*, VkDisplayPlanePropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceDisplayPlanePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkDisplayKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDisplayPlaneSupportedDisplaysKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModePropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDisplayModePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice, VkDisplayKHR, const VkDisplayModeCreateInfoKHR*, const VkAllocationCallbacks*, VkDisplayModeKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDisplayModeKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice, VkDisplayModeKHR, uint32_t, VkDisplayPlaneCapabilitiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDisplayPlaneCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance, const VkDisplaySurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDisplayPlaneSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(VkInstance, const VkXlibSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateXlibSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice, uint32_t, Display*, VisualID) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceXlibPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(VkInstance, const VkXcbSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateXcbSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice, uint32_t, xcb_connection_t*, xcb_visualid_t) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceXcbPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(VkInstance, const VkWaylandSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateWaylandSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice, uint32_t, struct wl_display*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceWaylandPresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(VkInstance, const VkAndroidSurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateAndroidSurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(VkInstance, const VkWin32SurfaceCreateInfoKHR*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateWin32SurfaceKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceWin32PresentationSupportKHR was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice, VkPhysicalDeviceFeatures2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFeatures2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice, VkFormat, VkFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFormatProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceImageFormatInfo2*, VkImageFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceImageFormatProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceQueueFamilyProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceMemoryProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2*, uint32_t*, VkSparseImageFormatProperties2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSparseImageFormatProperties2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(VkInstance, uint32_t*, VkPhysicalDeviceGroupProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumeratePhysicalDeviceGroupsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalBufferInfo*, VkExternalBufferProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalBufferPropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo*, VkExternalSemaphoreProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalSemaphorePropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice, const VkPhysicalDeviceExternalFenceInfo*, VkExternalFenceProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalFencePropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice, uint32_t, uint32_t*, VkPerformanceCounterKHR*, VkPerformanceCounterDescriptionKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice, const VkQueryPoolPerformanceCreateInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkSurfaceCapabilities2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkSurfaceFormat2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceFormats2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayProperties2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceDisplayProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice, uint32_t*, VkDisplayPlaneProperties2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceDisplayPlaneProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice, VkDisplayKHR, uint32_t*, VkDisplayModeProperties2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDisplayModeProperties2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice, const VkDisplayPlaneInfo2KHR*, VkDisplayPlaneCapabilities2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDisplayPlaneCapabilities2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceFragmentShadingRateKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceFragmentShadingRatesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(VkInstance, const VkDebugReportCallbackCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugReportCallbackEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDebugReportCallbackEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(VkInstance, VkDebugReportCallbackEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDebugReportCallbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(VkInstance, VkDebugReportFlagsEXT, VkDebugReportObjectTypeEXT, uint64_t, size_t, int32_t, const char*, const char*) { GFXRECON_LOG_WARNING("Unsupported function vkDebugReportMessageEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP(VkInstance, const VkStreamDescriptorSurfaceCreateInfoGGP*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateStreamDescriptorSurfaceGGP was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkExternalMemoryHandleTypeFlagsNV, VkExternalImageFormatPropertiesNV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceExternalImageFormatPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(VkInstance, const VkViSurfaceCreateInfoNN*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateViSurfaceNN was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING("Unsupported function vkReleaseDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(VkPhysicalDevice, Display*, VkDisplayKHR) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireXlibDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(VkPhysicalDevice, Display*, RROutput, VkDisplayKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRandROutputDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice, VkSurfaceKHR, VkSurfaceCapabilities2EXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfaceCapabilities2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(VkInstance, const VkIOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateIOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(VkInstance, const VkMacOSSurfaceCreateInfoMVK*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateMacOSSurfaceMVK was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance, const VkDebugUtilsMessengerCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugUtilsMessengerEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance, VkDebugUtilsMessengerEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDebugUtilsMessengerEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance, VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkSubmitDebugUtilsMessageEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice, VkSampleCountFlagBits, VkMultisamplePropertiesEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceMultisamplePropertiesEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice, uint32_t*, VkTimeDomainEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceCalibrateableTimeDomainsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(VkInstance, const VkImagePipeSurfaceCreateInfoFUCHSIA*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateImagePipeSurfaceFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT(VkInstance, const VkMetalSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateMetalSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice, uint32_t*, VkPhysicalDeviceToolProperties*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceToolPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice, uint32_t*, VkCooperativeMatrixPropertiesNV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceCooperativeMatrixPropertiesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice, uint32_t*, VkFramebufferMixedSamplesCombinationNV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, uint32_t*, VkPresentModeKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance, const VkHeadlessSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateHeadlessSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireDrmDisplayEXT(VkPhysicalDevice, int32_t, VkDisplayKHR) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDrmDisplayEXT(VkPhysicalDevice, int32_t, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDrmDisplayEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(VkPhysicalDevice, VkDisplayKHR) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(VkPhysicalDevice, uint32_t, VkDisplayKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetWinrtDisplayNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT(VkInstance, const VkDirectFBSurfaceCreateInfoEXT*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDirectFBSurfaceEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice, uint32_t, IDirectFB*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceDirectFBPresentationSupportEXT was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateScreenSurfaceQNX(VkInstance, const VkScreenSurfaceCreateInfoQNX*, const VkAllocationCallbacks*, VkSurfaceKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateScreenSurfaceQNX was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice, uint32_t, struct _screen_window*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPhysicalDeviceScreenPresentationSupportQNX was called, resulting in no-op behavior."); return VK_TRUE; }
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice, const char*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceProcAddr was called, resulting in no-op behavior."); return nullptr; }
static VKAPI_ATTR void VKAPI_CALL DestroyDevice(VkDevice, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDevice was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice, uint32_t, uint32_t, VkQueue*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceQueue was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(VkQueue, uint32_t, const VkSubmitInfo*, VkFence) { GFXRECON_LOG_WARNING("Unsupported function vkQueueSubmit was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue) { GFXRECON_LOG_WARNING("Unsupported function vkQueueWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice) { GFXRECON_LOG_WARNING("Unsupported function vkDeviceWaitIdle was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*) { GFXRECON_LOG_WARNING("Unsupported function vkAllocateMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL FreeMemory(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkFreeMemory was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL MapMemory(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**) { GFXRECON_LOG_WARNING("Unsupported function vkMapMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory(VkDevice, VkDeviceMemory) { GFXRECON_LOG_WARNING("Unsupported function vkUnmapMemory was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING("Unsupported function vkFlushMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice, uint32_t, const VkMappedMemoryRange*) { GFXRECON_LOG_WARNING("Unsupported function vkInvalidateMappedMemoryRanges was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice, VkDeviceMemory, VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceMemoryCommitment was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING("Unsupported function vkBindBufferMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize) { GFXRECON_LOG_WARNING("Unsupported function vkBindImageMemory was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(VkDevice, VkBuffer, VkMemoryRequirements*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(VkDevice, VkImage, VkMemoryRequirements*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence) { GFXRECON_LOG_WARNING("Unsupported function vkQueueBindSparse was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateFence was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice, VkFence, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyFence was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice, uint32_t, const VkFence*) { GFXRECON_LOG_WARNING("Unsupported function vkResetFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice, VkFence) { GFXRECON_LOG_WARNING("Unsupported function vkGetFenceStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkWaitForFences was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice, VkSemaphore, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySemaphore was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice, VkEvent, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice, VkEvent) { GFXRECON_LOG_WARNING("Unsupported function vkGetEventStatus was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING("Unsupported function vkSetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice, VkEvent) { GFXRECON_LOG_WARNING("Unsupported function vkResetEvent was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateQueryPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(VkDevice, VkQueryPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING("Unsupported function vkGetQueryPoolResults was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice, VkBuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateBufferView was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice, VkBufferView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyBufferView was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImage(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateImage was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyImage(VkDevice, VkImage, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageSubresourceLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateImageView was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice, VkImageView, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyImageView was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateShaderModule was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(VkDevice, VkShaderModule, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyShaderModule was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*) { GFXRECON_LOG_WARNING("Unsupported function vkCreatePipelineCache was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice, VkPipelineCache, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyPipelineCache was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(VkDevice, VkPipelineCache, size_t*, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPipelineCacheData was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*) { GFXRECON_LOG_WARNING("Unsupported function vkMergePipelineCaches was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateGraphicsPipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateComputePipelines was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice, VkPipeline, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyPipeline was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*) { GFXRECON_LOG_WARNING("Unsupported function vkCreatePipelineLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyPipelineLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSampler was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice, VkSampler, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySampler was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDescriptorSetLayout was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDescriptorSetLayout was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDescriptorPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags) { GFXRECON_LOG_WARNING("Unsupported function vkResetDescriptorPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*) { GFXRECON_LOG_WARNING("Unsupported function vkAllocateDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*) { GFXRECON_LOG_WARNING("Unsupported function vkFreeDescriptorSets was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*) { GFXRECON_LOG_WARNING("Unsupported function vkUpdateDescriptorSets was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateFramebuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice, VkFramebuffer, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyFramebuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateRenderPass was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice, VkRenderPass, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(VkDevice, VkRenderPass, VkExtent2D*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRenderAreaGranularity was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(VkDevice, VkCommandPool, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyCommandPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice, VkCommandPool, VkCommandPoolResetFlags) { GFXRECON_LOG_WARNING("Unsupported function vkResetCommandPool was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*) { GFXRECON_LOG_WARNING("Unsupported function vkAllocateCommandBuffers was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING("Unsupported function vkFreeCommandBuffers was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer, const VkCommandBufferBeginInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkBeginCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkEndCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer, VkCommandBufferResetFlags) { GFXRECON_LOG_WARNING("Unsupported function vkResetCommandBuffer was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer, VkPipelineBindPoint, VkPipeline) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindPipeline was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetViewport was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetScissor was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer, float) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetLineWidth was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer, float, float, float) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBias was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer, const float[4]) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetBlendConstants was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer, float, float) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBounds was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilCompareMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilWriteMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer, VkStencilFaceFlags, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilReference was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindDescriptorSets was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindIndexBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindVertexBuffers was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDraw was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndexed was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndexedIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDispatch was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDispatchIndirect was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBlitImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBufferToImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImageToBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdUpdateBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdFillBuffer was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdClearColorImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdClearDepthStencilImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdClearAttachments was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResolveImage was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer, VkEvent, VkPipelineStageFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResetEvent was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWaitEvents was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPipelineBarrier was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginQuery was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndQuery was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResetQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteTimestamp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyQueryPoolResults was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPushConstants was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer, VkSubpassContents) { GFXRECON_LOG_WARNING("Unsupported function vkCmdNextSubpass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndRenderPass was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer, uint32_t, const VkCommandBuffer*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdExecuteCommands was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkBindBufferMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkBindImageMemory2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceGroupPeerMemoryFeatures was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDeviceMask was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDispatchBase was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageSparseMemoryRequirements2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPool(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING("Unsupported function vkTrimCommandPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice, const VkDeviceQueueInfo2*, VkQueue*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceQueue2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSamplerYcbcrConversion was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySamplerYcbcrConversion was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDescriptorUpdateTemplate was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDescriptorUpdateTemplate was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkUpdateDescriptorSetWithTemplate was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDescriptorSetLayoutSupport was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndirectCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndexedIndirectCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateRenderPass2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginRenderPass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdNextSubpass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndRenderPass2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkResetQueryPool was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSemaphoreCounterValue was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkWaitSemaphores was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkSignalSemaphore was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferDeviceAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddress was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING("Unsupported function vkCreatePrivateDataSlot was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyPrivateDataSlot was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkSetPrivateData was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPrivateData was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetEvent2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResetEvent2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWaitEvents2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPipelineBarrier2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteTimestamp2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING("Unsupported function vkQueueSubmit2 was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBuffer2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBufferToImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImageToBuffer2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBlitImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResolveImage2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginRendering was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndRendering was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetCullMode was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetFrontFace was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPrimitiveTopology was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetViewportWithCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetScissorWithCount was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindVertexBuffers2 was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthWriteEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthCompareOp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBoundsTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilTestEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilOp was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetRasterizerDiscardEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBiasEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPrimitiveRestartEnable was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceBufferMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceImageMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceImageSparseMemoryRequirements was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSwapchainKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(VkDevice, VkSwapchainKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySwapchainKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice, VkSwapchainKHR, uint32_t*, VkImage*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSwapchainImagesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireNextImageKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue, const VkPresentInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkQueuePresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(VkDevice, VkDeviceGroupPresentCapabilitiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceGroupPresentCapabilitiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice, VkSurfaceKHR, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceGroupSurfacePresentModesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice, const VkAcquireNextImageInfoKHR*, uint32_t*) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireNextImage2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice, uint32_t, const VkSwapchainCreateInfoKHR*, const VkAllocationCallbacks*, VkSwapchainKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSharedSwapchainsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR(VkCommandBuffer, const VkRenderingInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginRenderingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndRenderingKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(VkDevice, uint32_t, uint32_t, uint32_t, VkPeerMemoryFeatureFlags*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceGroupPeerMemoryFeaturesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDeviceMaskKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDispatchBaseKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(VkDevice, VkCommandPool, VkCommandPoolTrimFlags) { GFXRECON_LOG_WARNING("Unsupported function vkTrimCommandPoolKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(VkDevice, const VkMemoryGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, HANDLE, VkMemoryWin32HandlePropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryWin32HandlePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(VkDevice, const VkMemoryGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice, VkExternalMemoryHandleTypeFlagBits, int, VkMemoryFdPropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryFdPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(VkDevice, const VkImportSemaphoreWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkImportSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(VkDevice, const VkSemaphoreGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSemaphoreWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice, const VkImportSemaphoreFdInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkImportSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice, const VkSemaphoreGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSemaphoreFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkWriteDescriptorSet*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPushDescriptorSetKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer, VkDescriptorUpdateTemplate, VkPipelineLayout, uint32_t, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPushDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(VkDevice, const VkDescriptorUpdateTemplateCreateInfo*, const VkAllocationCallbacks*, VkDescriptorUpdateTemplate*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(VkDevice, VkDescriptorUpdateTemplate, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDescriptorUpdateTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(VkDevice, VkDescriptorSet, VkDescriptorUpdateTemplate, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkUpdateDescriptorSetWithTemplateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(VkDevice, const VkRenderPassCreateInfo2*, const VkAllocationCallbacks*, VkRenderPass*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateRenderPass2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(VkCommandBuffer, const VkRenderPassBeginInfo*, const VkSubpassBeginInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginRenderPass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(VkCommandBuffer, const VkSubpassBeginInfo*, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdNextSubpass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(VkCommandBuffer, const VkSubpassEndInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndRenderPass2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING("Unsupported function vkGetSwapchainStatusKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(VkDevice, const VkImportFenceWin32HandleInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkImportFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(VkDevice, const VkFenceGetWin32HandleInfoKHR*, HANDLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetFenceWin32HandleKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice, const VkImportFenceFdInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkImportFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(VkDevice, const VkFenceGetFdInfoKHR*, int*) { GFXRECON_LOG_WARNING("Unsupported function vkGetFenceFdKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice, const VkAcquireProfilingLockInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireProfilingLockKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice) { GFXRECON_LOG_WARNING("Unsupported function vkReleaseProfilingLockKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(VkDevice, const VkImageMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(VkDevice, const VkBufferMemoryRequirementsInfo2*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(VkDevice, const VkImageSparseMemoryRequirementsInfo2*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageSparseMemoryRequirements2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(VkDevice, const VkSamplerYcbcrConversionCreateInfo*, const VkAllocationCallbacks*, VkSamplerYcbcrConversion*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateSamplerYcbcrConversionKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(VkDevice, VkSamplerYcbcrConversion, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroySamplerYcbcrConversionKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(VkDevice, uint32_t, const VkBindBufferMemoryInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkBindBufferMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(VkDevice, uint32_t, const VkBindImageMemoryInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkBindImageMemory2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(VkDevice, const VkDescriptorSetLayoutCreateInfo*, VkDescriptorSetLayoutSupport*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDescriptorSetLayoutSupportKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndirectCountKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndexedIndirectCountKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR(VkDevice, VkSemaphore, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSemaphoreCounterValueKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR(VkDevice, const VkSemaphoreWaitInfo*, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkWaitSemaphoresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR(VkDevice, const VkSemaphoreSignalInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkSignalSemaphoreKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer, const VkExtent2D*, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetFragmentShadingRateKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL WaitForPresentKHR(VkDevice, VkSwapchainKHR, uint64_t, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkWaitForPresentKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice, const VkDeviceMemoryOpaqueCaptureAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceMemoryOpaqueCaptureAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR(VkDevice, const VkAllocationCallbacks*, VkDeferredOperationKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateDeferredOperationKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR(VkDevice, VkDeferredOperationKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyDeferredOperationKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeferredOperationMaxConcurrencyKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeferredOperationResultKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR(VkDevice, VkDeferredOperationKHR) { GFXRECON_LOG_WARNING("Unsupported function vkDeferredOperationJoinKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR(VkDevice, const VkPipelineInfoKHR*, uint32_t*, VkPipelineExecutablePropertiesKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPipelineExecutablePropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableStatisticKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPipelineExecutableStatisticsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR(VkDevice, const VkPipelineExecutableInfoKHR*, uint32_t*, VkPipelineExecutableInternalRepresentationKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPipelineExecutableInternalRepresentationsKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer, VkEvent, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetEvent2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer, VkEvent, VkPipelineStageFlags2) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResetEvent2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer, uint32_t, const VkEvent*, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWaitEvents2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer, const VkDependencyInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPipelineBarrier2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer, VkPipelineStageFlags2, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteTimestamp2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue, uint32_t, const VkSubmitInfo2*, VkFence) { GFXRECON_LOG_WARNING("Unsupported function vkQueueSubmit2KHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD(VkCommandBuffer, VkPipelineStageFlags2, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteBufferMarker2AMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV(VkQueue, uint32_t*, VkCheckpointData2NV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetQueueCheckpointData2NV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer, const VkCopyBufferInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBuffer2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer, const VkCopyImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer, const VkCopyBufferToImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyBufferToImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer, const VkCopyImageToBufferInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyImageToBuffer2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer, const VkBlitImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBlitImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer, const VkResolveImageInfo2*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdResolveImage2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR(VkCommandBuffer, VkDeviceAddress) { GFXRECON_LOG_WARNING("Unsupported function vkCmdTraceRaysIndirect2KHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR(VkDevice, const VkDeviceBufferMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceBufferMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceImageMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR(VkDevice, const VkDeviceImageMemoryRequirements*, uint32_t*, VkSparseImageMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceImageSparseMemoryRequirementsKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(VkDevice, const VkDebugMarkerObjectTagInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkDebugMarkerSetObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(VkDevice, const VkDebugMarkerObjectNameInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkDebugMarkerSetObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDebugMarkerBeginEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDebugMarkerEndEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(VkCommandBuffer, const VkDebugMarkerMarkerInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDebugMarkerInsertEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindTransformFeedbackBuffersEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginTransformFeedbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndTransformFeedbackEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginQueryIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndQueryIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT(VkCommandBuffer, uint32_t, uint32_t, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndirectByteCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX(VkDevice, const VkImageViewHandleInfoNVX*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageViewHandleNVX was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX(VkDevice, VkImageView, VkImageViewAddressPropertiesNVX*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageViewAddressNVX was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndirectCountAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawIndexedIndirectCountAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(VkDevice, VkPipeline, VkShaderStageFlagBits, VkShaderInfoTypeAMD, size_t*, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetShaderInfoAMD was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(VkDevice, VkDeviceMemory, VkExternalMemoryHandleTypeFlagsNV, HANDLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryWin32HandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(VkCommandBuffer, const VkConditionalRenderingBeginInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginConditionalRenderingEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndConditionalRenderingEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(VkCommandBuffer, uint32_t, uint32_t, const VkViewportWScalingNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetViewportWScalingNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice, VkDisplayKHR, const VkDisplayPowerInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkDisplayPowerControlEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice, const VkDeviceEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING("Unsupported function vkRegisterDeviceEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(VkDevice, VkDisplayKHR, const VkDisplayEventInfoEXT*, const VkAllocationCallbacks*, VkFence*) { GFXRECON_LOG_WARNING("Unsupported function vkRegisterDisplayEventEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice, VkSwapchainKHR, VkSurfaceCounterFlagBitsEXT, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSwapchainCounterEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(VkDevice, VkSwapchainKHR, VkRefreshCycleDurationGOOGLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRefreshCycleDurationGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(VkDevice, VkSwapchainKHR, uint32_t*, VkPastPresentationTimingGOOGLE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPastPresentationTimingGOOGLE was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDiscardRectangleEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice, uint32_t, const VkSwapchainKHR*, const VkHdrMetadataEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkSetHdrMetadataEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice, const VkDebugUtilsObjectNameInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkSetDebugUtilsObjectNameEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice, const VkDebugUtilsObjectTagInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkSetDebugUtilsObjectTagEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkQueueBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue) { GFXRECON_LOG_WARNING("Unsupported function vkQueueEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkQueueInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBeginDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer) { GFXRECON_LOG_WARNING("Unsupported function vkCmdEndDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer, const VkDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(VkDevice, const struct AHardwareBuffer*, VkAndroidHardwareBufferPropertiesANDROID*) { GFXRECON_LOG_WARNING("Unsupported function vkGetAndroidHardwareBufferPropertiesANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(VkDevice, const VkMemoryGetAndroidHardwareBufferInfoANDROID*, struct AHardwareBuffer**) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryAndroidHardwareBufferANDROID was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer, const VkSampleLocationsInfoEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetSampleLocationsEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice, VkImage, VkImageDrmFormatModifierPropertiesEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageDrmFormatModifierPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(VkDevice, const VkValidationCacheCreateInfoEXT*, const VkAllocationCallbacks*, VkValidationCacheEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateValidationCacheEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(VkDevice, VkValidationCacheEXT, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyValidationCacheEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(VkDevice, VkValidationCacheEXT, uint32_t, const VkValidationCacheEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkMergeValidationCachesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(VkDevice, VkValidationCacheEXT, size_t*, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetValidationCacheDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindShadingRateImageNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(VkCommandBuffer, uint32_t, uint32_t, const VkShadingRatePaletteNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetViewportShadingRatePaletteNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(VkCommandBuffer, VkCoarseSampleOrderTypeNV, uint32_t, const VkCoarseSampleOrderCustomNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetCoarseSampleOrderNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(VkDevice, const VkAccelerationStructureCreateInfoNV*, const VkAllocationCallbacks*, VkAccelerationStructureNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateAccelerationStructureNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(VkDevice, VkAccelerationStructureNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(VkDevice, const VkAccelerationStructureMemoryRequirementsInfoNV*, VkMemoryRequirements2KHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetAccelerationStructureMemoryRequirementsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(VkDevice, uint32_t, const VkBindAccelerationStructureMemoryInfoNV*) { GFXRECON_LOG_WARNING("Unsupported function vkBindAccelerationStructureMemoryNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV(VkCommandBuffer, const VkAccelerationStructureInfoNV*, VkBuffer, VkDeviceSize, VkBool32, VkAccelerationStructureNV, VkAccelerationStructureNV, VkBuffer, VkDeviceSize) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBuildAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(VkCommandBuffer, VkAccelerationStructureNV, VkAccelerationStructureNV, VkCopyAccelerationStructureModeKHR) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyAccelerationStructureNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdTraceRaysNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(VkDevice, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoNV*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateRayTracingPipelinesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRayTracingShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRayTracingShaderGroupHandlesNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(VkDevice, VkAccelerationStructureNV, size_t, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetAccelerationStructureHandleNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer, uint32_t, const VkAccelerationStructureNV*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteAccelerationStructuresPropertiesNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(VkDevice, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCompileDeferredNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(VkDevice, VkExternalMemoryHandleTypeFlagBits, const void*, VkMemoryHostPointerPropertiesEXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryHostPointerPropertiesEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(VkCommandBuffer, VkPipelineStageFlagBits, VkBuffer, VkDeviceSize, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteBufferMarkerAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(VkDevice, uint32_t, const VkCalibratedTimestampInfoEXT*, uint64_t*, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetCalibratedTimestampsEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(VkCommandBuffer, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawMeshTasksNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawMeshTasksIndirectNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer, VkBuffer, VkDeviceSize, VkBuffer, VkDeviceSize, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawMeshTasksIndirectCountNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetExclusiveScissorNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(VkCommandBuffer, const void*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetCheckpointNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(VkQueue, uint32_t*, VkCheckpointDataNV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetQueueCheckpointDataNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL(VkDevice, const VkInitializePerformanceApiInfoINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkInitializePerformanceApiINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL(VkDevice) { GFXRECON_LOG_WARNING("Unsupported function vkUninitializePerformanceApiINTEL was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL(VkCommandBuffer, const VkPerformanceMarkerInfoINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPerformanceMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer, const VkPerformanceStreamMarkerInfoINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPerformanceStreamMarkerINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL(VkCommandBuffer, const VkPerformanceOverrideInfoINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPerformanceOverrideINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL(VkDevice, const VkPerformanceConfigurationAcquireInfoINTEL*, VkPerformanceConfigurationINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkAcquirePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL(VkDevice, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING("Unsupported function vkReleasePerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL(VkQueue, VkPerformanceConfigurationINTEL) { GFXRECON_LOG_WARNING("Unsupported function vkQueueSetPerformanceConfigurationINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL(VkDevice, VkPerformanceParameterTypeINTEL, VkPerformanceValueINTEL*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPerformanceParameterINTEL was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD(VkDevice, VkSwapchainKHR, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkSetLocalDimmingAMD was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(VkDevice, const VkBufferDeviceAddressInfo*) { GFXRECON_LOG_WARNING("Unsupported function vkGetBufferDeviceAddressEXT was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING("Unsupported function vkAcquireFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT(VkDevice, VkSwapchainKHR) { GFXRECON_LOG_WARNING("Unsupported function vkReleaseFullScreenExclusiveModeEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT(VkDevice, const VkPhysicalDeviceSurfaceInfo2KHR*, VkDeviceGroupPresentModeFlagsKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceGroupSurfacePresentModes2EXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer, uint32_t, uint16_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetLineStippleEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT(VkDevice, VkQueryPool, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkResetQueryPoolEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer, VkCullModeFlags) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetCullModeEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer, VkFrontFace) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetFrontFaceEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer, VkPrimitiveTopology) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPrimitiveTopologyEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer, uint32_t, const VkViewport*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetViewportWithCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer, uint32_t, const VkRect2D*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetScissorWithCountEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*, const VkDeviceSize*, const VkDeviceSize*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindVertexBuffers2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthWriteEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer, VkCompareOp) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthCompareOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBoundsTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilTestEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer, VkStencilFaceFlags, VkStencilOp, VkStencilOp, VkStencilOp, VkCompareOp) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetStencilOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV(VkDevice, const VkGeneratedCommandsMemoryRequirementsInfoNV*, VkMemoryRequirements2*) { GFXRECON_LOG_WARNING("Unsupported function vkGetGeneratedCommandsMemoryRequirementsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV(VkCommandBuffer, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdPreprocessGeneratedCommandsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV(VkCommandBuffer, VkBool32, const VkGeneratedCommandsInfoNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdExecuteGeneratedCommandsNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV(VkCommandBuffer, VkPipelineBindPoint, VkPipeline, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindPipelineShaderGroupNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV(VkDevice, const VkIndirectCommandsLayoutCreateInfoNV*, const VkAllocationCallbacks*, VkIndirectCommandsLayoutNV*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateIndirectCommandsLayoutNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV(VkDevice, VkIndirectCommandsLayoutNV, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyIndirectCommandsLayoutNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT(VkDevice, const VkPrivateDataSlotCreateInfo*, const VkAllocationCallbacks*, VkPrivateDataSlot*) { GFXRECON_LOG_WARNING("Unsupported function vkCreatePrivateDataSlotEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT(VkDevice, VkPrivateDataSlot, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyPrivateDataSlotEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t) { GFXRECON_LOG_WARNING("Unsupported function vkSetPrivateDataEXT was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT(VkDevice, VkObjectType, uint64_t, VkPrivateDataSlot, uint64_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetPrivateDataEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV(VkCommandBuffer, VkFragmentShadingRateNV, const VkFragmentShadingRateCombinerOpKHR[2]) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetFragmentShadingRateEnumNV was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT(VkDevice, VkImage, const VkImageSubresource2EXT*, VkSubresourceLayout2EXT*) { GFXRECON_LOG_WARNING("Unsupported function vkGetImageSubresourceLayout2EXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer, uint32_t, const VkVertexInputBindingDescription2EXT*, uint32_t, const VkVertexInputAttributeDescription2EXT*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetVertexInputEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandleFUCHSIA(VkDevice, const VkMemoryGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA(VkDevice, VkExternalMemoryHandleTypeFlagBits, zx_handle_t, VkMemoryZirconHandlePropertiesFUCHSIA*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryZirconHandlePropertiesFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA(VkDevice, const VkImportSemaphoreZirconHandleInfoFUCHSIA*) { GFXRECON_LOG_WARNING("Unsupported function vkImportSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA(VkDevice, const VkSemaphoreGetZirconHandleInfoFUCHSIA*, zx_handle_t*) { GFXRECON_LOG_WARNING("Unsupported function vkGetSemaphoreZirconHandleFUCHSIA was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI(VkCommandBuffer, VkImageView, VkImageLayout) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBindInvocationMaskHUAWEI was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryRemoteAddressNV(VkDevice, const VkMemoryGetRemoteAddressInfoNV*, VkRemoteAddressNV*) { GFXRECON_LOG_WARNING("Unsupported function vkGetMemoryRemoteAddressNV was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPatchControlPointsEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetRasterizerDiscardEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetDepthBiasEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer, VkLogicOp) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetLogicOpEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer, VkBool32) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetPrimitiveRestartEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void                                    VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer, uint32_t, const VkBool32*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetColorWriteEnableEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT(VkCommandBuffer, uint32_t, const VkMultiDrawInfoEXT*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawMultiEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT(VkCommandBuffer, uint32_t, const VkMultiDrawIndexedInfoEXT*, uint32_t, uint32_t, uint32_t, const int32_t*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdDrawMultiIndexedEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT(VkDevice, VkDeviceMemory, float) { GFXRECON_LOG_WARNING("Unsupported function vkSetDeviceMemoryPriorityEXT was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice, const VkDescriptorSetBindingReferenceVALVE*, VkDescriptorSetLayoutHostMappingInfoVALVE*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDescriptorSetLayoutHostMappingInfoVALVE was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE(VkDevice, VkDescriptorSet, void**) { GFXRECON_LOG_WARNING("Unsupported function vkGetDescriptorSetHostMappingVALVE was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR(VkDevice, const VkAccelerationStructureCreateInfoKHR*, const VkAllocationCallbacks*, VkAccelerationStructureKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR(VkDevice, VkAccelerationStructureKHR, const VkAllocationCallbacks*) { GFXRECON_LOG_WARNING("Unsupported function vkDestroyAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkDeviceAddress*, const uint32_t*, const uint32_t* const*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdBuildAccelerationStructuresIndirectKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL BuildAccelerationStructuresKHR(VkDevice, VkDeferredOperationKHR, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*) { GFXRECON_LOG_WARNING("Unsupported function vkBuildAccelerationStructuresKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCopyAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR(VkDevice, VkDeferredOperationKHR, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR(VkDevice, VkDeferredOperationKHR, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL WriteAccelerationStructuresPropertiesKHR(VkDevice, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, size_t, void*, size_t) { GFXRECON_LOG_WARNING("Unsupported function vkWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR(VkCommandBuffer, const VkCopyAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyAccelerationStructureToMemoryKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkCmdCopyMemoryToAccelerationStructureKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR(VkDevice, const VkAccelerationStructureDeviceAddressInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetAccelerationStructureDeviceAddressKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer, uint32_t, const VkAccelerationStructureKHR*, VkQueryType, VkQueryPool, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdWriteAccelerationStructuresPropertiesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR(VkDevice, const VkAccelerationStructureVersionInfoKHR*, VkAccelerationStructureCompatibilityKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetDeviceAccelerationStructureCompatibilityKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR(VkDevice, VkAccelerationStructureBuildTypeKHR, const VkAccelerationStructureBuildGeometryInfoKHR*, const uint32_t*, VkAccelerationStructureBuildSizesInfoKHR*) { GFXRECON_LOG_WARNING("Unsupported function vkGetAccelerationStructureBuildSizesKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, uint32_t, uint32_t, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdTraceRaysKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(VkDevice, VkDeferredOperationKHR, VkPipelineCache, uint32_t, const VkRayTracingPipelineCreateInfoKHR*, const VkAllocationCallbacks*, VkPipeline*) { GFXRECON_LOG_WARNING("Unsupported function vkCreateRayTracingPipelinesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice, VkPipeline, uint32_t, uint32_t, size_t, void*) { GFXRECON_LOG_WARNING("Unsupported function vkGetRayTracingCaptureReplayShaderGroupHandlesKHR was called, resulting in no-op behavior."); return VK_SUCCESS; }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR(VkCommandBuffer, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, const VkStridedDeviceAddressRegionKHR*, VkDeviceAddress) { GFXRECON_LOG_WARNING("Unsupported function vkCmdTraceRaysIndirectKHR was called, resulting in no-op behavior."); }
static VKAPI_ATTR VkDeviceSize VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR(VkDevice, VkPipeline, uint32_t, VkShaderGroupShaderKHR) { GFXRECON_LOG_WARNING("Unsupported function vkGetRayTracingShaderGroupStackSizeKHR was called, resulting in no-op behavior."); return 0; }
static VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer, uint32_t) { GFXRECON_LOG_WARNING("Unsupported function vkCmdSetRayTracingPipelineStackSizeKHR was called, resulting in no-op behavior."); }
// clang-format on
GFXRECON_END_NAMESPACE(noop)

struct LayerTable
{
    PFN_vkCreateInstance CreateInstance{ nullptr };
    PFN_vkCreateDevice CreateDevice{ nullptr };
};

struct InstanceTable
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
};

struct DeviceTable
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
    PFN_vkSetHdrMetadataEXT SetHdrMetadataEXT{ noop::SetHdrMetadataEXT };
    PFN_vkSetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT{ noop::SetDebugUtilsObjectNameEXT };
    PFN_vkSetDebugUtilsObjectTagEXT SetDebugUtilsObjectTagEXT{ noop::SetDebugUtilsObjectTagEXT };
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
    PFN_vkGetGeneratedCommandsMemoryRequirementsNV GetGeneratedCommandsMemoryRequirementsNV{ noop::GetGeneratedCommandsMemoryRequirementsNV };
    PFN_vkCmdPreprocessGeneratedCommandsNV CmdPreprocessGeneratedCommandsNV{ noop::CmdPreprocessGeneratedCommandsNV };
    PFN_vkCmdExecuteGeneratedCommandsNV CmdExecuteGeneratedCommandsNV{ noop::CmdExecuteGeneratedCommandsNV };
    PFN_vkCmdBindPipelineShaderGroupNV CmdBindPipelineShaderGroupNV{ noop::CmdBindPipelineShaderGroupNV };
    PFN_vkCreateIndirectCommandsLayoutNV CreateIndirectCommandsLayoutNV{ noop::CreateIndirectCommandsLayoutNV };
    PFN_vkDestroyIndirectCommandsLayoutNV DestroyIndirectCommandsLayoutNV{ noop::DestroyIndirectCommandsLayoutNV };
    PFN_vkCreatePrivateDataSlotEXT CreatePrivateDataSlotEXT{ noop::CreatePrivateDataSlotEXT };
    PFN_vkDestroyPrivateDataSlotEXT DestroyPrivateDataSlotEXT{ noop::DestroyPrivateDataSlotEXT };
    PFN_vkSetPrivateDataEXT SetPrivateDataEXT{ noop::SetPrivateDataEXT };
    PFN_vkGetPrivateDataEXT GetPrivateDataEXT{ noop::GetPrivateDataEXT };
    PFN_vkCmdSetFragmentShadingRateEnumNV CmdSetFragmentShadingRateEnumNV{ noop::CmdSetFragmentShadingRateEnumNV };
    PFN_vkGetImageSubresourceLayout2EXT GetImageSubresourceLayout2EXT{ noop::GetImageSubresourceLayout2EXT };
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
    PFN_vkSetDeviceMemoryPriorityEXT SetDeviceMemoryPriorityEXT{ noop::SetDeviceMemoryPriorityEXT };
    PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE GetDescriptorSetLayoutHostMappingInfoVALVE{ noop::GetDescriptorSetLayoutHostMappingInfoVALVE };
    PFN_vkGetDescriptorSetHostMappingVALVE GetDescriptorSetHostMappingVALVE{ noop::GetDescriptorSetHostMappingVALVE };
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
};

template <typename GetProcAddr, typename Handle, typename FuncP>
static void LoadFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result != nullptr)
    {
        (*funcp) = result;
    }
}

static void LoadInstanceTable(PFN_vkGetInstanceProcAddr gpa, VkInstance instance, InstanceTable* table)
{
    assert(table != nullptr);

    LoadFunction(gpa, instance, "vkDestroyInstance", &table->DestroyInstance);
    LoadFunction(gpa, instance, "vkEnumeratePhysicalDevices", &table->EnumeratePhysicalDevices);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFeatures", &table->GetPhysicalDeviceFeatures);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties", &table->GetPhysicalDeviceFormatProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties", &table->GetPhysicalDeviceImageFormatProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceProperties", &table->GetPhysicalDeviceProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties", &table->GetPhysicalDeviceQueueFamilyProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties", &table->GetPhysicalDeviceMemoryProperties);
    table->GetInstanceProcAddr = gpa;
    LoadFunction(gpa, instance, "vkEnumerateDeviceExtensionProperties", &table->EnumerateDeviceExtensionProperties);
    LoadFunction(gpa, instance, "vkEnumerateDeviceLayerProperties", &table->EnumerateDeviceLayerProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties", &table->GetPhysicalDeviceSparseImageFormatProperties);
    LoadFunction(gpa, instance, "vkEnumeratePhysicalDeviceGroups", &table->EnumeratePhysicalDeviceGroups);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFeatures2", &table->GetPhysicalDeviceFeatures2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceProperties2", &table->GetPhysicalDeviceProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties2", &table->GetPhysicalDeviceFormatProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties2", &table->GetPhysicalDeviceImageFormatProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties2", &table->GetPhysicalDeviceQueueFamilyProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties2", &table->GetPhysicalDeviceMemoryProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties2", &table->GetPhysicalDeviceSparseImageFormatProperties2);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalBufferProperties", &table->GetPhysicalDeviceExternalBufferProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalFenceProperties", &table->GetPhysicalDeviceExternalFenceProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalSemaphoreProperties", &table->GetPhysicalDeviceExternalSemaphoreProperties);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceToolProperties", &table->GetPhysicalDeviceToolProperties);
    LoadFunction(gpa, instance, "vkDestroySurfaceKHR", &table->DestroySurfaceKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceSupportKHR", &table->GetPhysicalDeviceSurfaceSupportKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", &table->GetPhysicalDeviceSurfaceCapabilitiesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceFormatsKHR", &table->GetPhysicalDeviceSurfaceFormatsKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfacePresentModesKHR", &table->GetPhysicalDeviceSurfacePresentModesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDevicePresentRectanglesKHR", &table->GetPhysicalDevicePresentRectanglesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPropertiesKHR", &table->GetPhysicalDeviceDisplayPropertiesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", &table->GetPhysicalDeviceDisplayPlanePropertiesKHR);
    LoadFunction(gpa, instance, "vkGetDisplayPlaneSupportedDisplaysKHR", &table->GetDisplayPlaneSupportedDisplaysKHR);
    LoadFunction(gpa, instance, "vkGetDisplayModePropertiesKHR", &table->GetDisplayModePropertiesKHR);
    LoadFunction(gpa, instance, "vkCreateDisplayModeKHR", &table->CreateDisplayModeKHR);
    LoadFunction(gpa, instance, "vkGetDisplayPlaneCapabilitiesKHR", &table->GetDisplayPlaneCapabilitiesKHR);
    LoadFunction(gpa, instance, "vkCreateDisplayPlaneSurfaceKHR", &table->CreateDisplayPlaneSurfaceKHR);
    LoadFunction(gpa, instance, "vkCreateXlibSurfaceKHR", &table->CreateXlibSurfaceKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR", &table->GetPhysicalDeviceXlibPresentationSupportKHR);
    LoadFunction(gpa, instance, "vkCreateXcbSurfaceKHR", &table->CreateXcbSurfaceKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR", &table->GetPhysicalDeviceXcbPresentationSupportKHR);
    LoadFunction(gpa, instance, "vkCreateWaylandSurfaceKHR", &table->CreateWaylandSurfaceKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR", &table->GetPhysicalDeviceWaylandPresentationSupportKHR);
    LoadFunction(gpa, instance, "vkCreateAndroidSurfaceKHR", &table->CreateAndroidSurfaceKHR);
    LoadFunction(gpa, instance, "vkCreateWin32SurfaceKHR", &table->CreateWin32SurfaceKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR", &table->GetPhysicalDeviceWin32PresentationSupportKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFeatures2KHR", &table->GetPhysicalDeviceFeatures2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceProperties2KHR", &table->GetPhysicalDeviceProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFormatProperties2KHR", &table->GetPhysicalDeviceFormatProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceImageFormatProperties2KHR", &table->GetPhysicalDeviceImageFormatProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR", &table->GetPhysicalDeviceQueueFamilyProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceMemoryProperties2KHR", &table->GetPhysicalDeviceMemoryProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", &table->GetPhysicalDeviceSparseImageFormatProperties2KHR);
    LoadFunction(gpa, instance, "vkEnumeratePhysicalDeviceGroupsKHR", &table->EnumeratePhysicalDeviceGroupsKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR", &table->GetPhysicalDeviceExternalBufferPropertiesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", &table->GetPhysicalDeviceExternalSemaphorePropertiesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR", &table->GetPhysicalDeviceExternalFencePropertiesKHR);
    LoadFunction(gpa, instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", &table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR", &table->GetPhysicalDeviceSurfaceCapabilities2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceFormats2KHR", &table->GetPhysicalDeviceSurfaceFormats2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceDisplayProperties2KHR", &table->GetPhysicalDeviceDisplayProperties2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", &table->GetPhysicalDeviceDisplayPlaneProperties2KHR);
    LoadFunction(gpa, instance, "vkGetDisplayModeProperties2KHR", &table->GetDisplayModeProperties2KHR);
    LoadFunction(gpa, instance, "vkGetDisplayPlaneCapabilities2KHR", &table->GetDisplayPlaneCapabilities2KHR);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR", &table->GetPhysicalDeviceFragmentShadingRatesKHR);
    LoadFunction(gpa, instance, "vkCreateDebugReportCallbackEXT", &table->CreateDebugReportCallbackEXT);
    LoadFunction(gpa, instance, "vkDestroyDebugReportCallbackEXT", &table->DestroyDebugReportCallbackEXT);
    LoadFunction(gpa, instance, "vkDebugReportMessageEXT", &table->DebugReportMessageEXT);
    LoadFunction(gpa, instance, "vkCreateStreamDescriptorSurfaceGGP", &table->CreateStreamDescriptorSurfaceGGP);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", &table->GetPhysicalDeviceExternalImageFormatPropertiesNV);
    LoadFunction(gpa, instance, "vkCreateViSurfaceNN", &table->CreateViSurfaceNN);
    LoadFunction(gpa, instance, "vkReleaseDisplayEXT", &table->ReleaseDisplayEXT);
    LoadFunction(gpa, instance, "vkAcquireXlibDisplayEXT", &table->AcquireXlibDisplayEXT);
    LoadFunction(gpa, instance, "vkGetRandROutputDisplayEXT", &table->GetRandROutputDisplayEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT", &table->GetPhysicalDeviceSurfaceCapabilities2EXT);
    LoadFunction(gpa, instance, "vkCreateIOSSurfaceMVK", &table->CreateIOSSurfaceMVK);
    LoadFunction(gpa, instance, "vkCreateMacOSSurfaceMVK", &table->CreateMacOSSurfaceMVK);
    LoadFunction(gpa, instance, "vkCreateDebugUtilsMessengerEXT", &table->CreateDebugUtilsMessengerEXT);
    LoadFunction(gpa, instance, "vkDestroyDebugUtilsMessengerEXT", &table->DestroyDebugUtilsMessengerEXT);
    LoadFunction(gpa, instance, "vkSubmitDebugUtilsMessageEXT", &table->SubmitDebugUtilsMessageEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT", &table->GetPhysicalDeviceMultisamplePropertiesEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", &table->GetPhysicalDeviceCalibrateableTimeDomainsEXT);
    LoadFunction(gpa, instance, "vkCreateImagePipeSurfaceFUCHSIA", &table->CreateImagePipeSurfaceFUCHSIA);
    LoadFunction(gpa, instance, "vkCreateMetalSurfaceEXT", &table->CreateMetalSurfaceEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceToolPropertiesEXT", &table->GetPhysicalDeviceToolPropertiesEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", &table->GetPhysicalDeviceCooperativeMatrixPropertiesNV);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", &table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT", &table->GetPhysicalDeviceSurfacePresentModes2EXT);
    LoadFunction(gpa, instance, "vkCreateHeadlessSurfaceEXT", &table->CreateHeadlessSurfaceEXT);
    LoadFunction(gpa, instance, "vkAcquireDrmDisplayEXT", &table->AcquireDrmDisplayEXT);
    LoadFunction(gpa, instance, "vkGetDrmDisplayEXT", &table->GetDrmDisplayEXT);
    LoadFunction(gpa, instance, "vkAcquireWinrtDisplayNV", &table->AcquireWinrtDisplayNV);
    LoadFunction(gpa, instance, "vkGetWinrtDisplayNV", &table->GetWinrtDisplayNV);
    LoadFunction(gpa, instance, "vkCreateDirectFBSurfaceEXT", &table->CreateDirectFBSurfaceEXT);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", &table->GetPhysicalDeviceDirectFBPresentationSupportEXT);
    LoadFunction(gpa, instance, "vkCreateScreenSurfaceQNX", &table->CreateScreenSurfaceQNX);
    LoadFunction(gpa, instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX", &table->GetPhysicalDeviceScreenPresentationSupportQNX);
}

static void LoadDeviceTable(PFN_vkGetDeviceProcAddr gpa, VkDevice device, DeviceTable* table)
{
    assert(table != nullptr);

    table->GetDeviceProcAddr = gpa;
    LoadFunction(gpa, device, "vkDestroyDevice", &table->DestroyDevice);
    LoadFunction(gpa, device, "vkGetDeviceQueue", &table->GetDeviceQueue);
    LoadFunction(gpa, device, "vkQueueSubmit", &table->QueueSubmit);
    LoadFunction(gpa, device, "vkQueueWaitIdle", &table->QueueWaitIdle);
    LoadFunction(gpa, device, "vkDeviceWaitIdle", &table->DeviceWaitIdle);
    LoadFunction(gpa, device, "vkAllocateMemory", &table->AllocateMemory);
    LoadFunction(gpa, device, "vkFreeMemory", &table->FreeMemory);
    LoadFunction(gpa, device, "vkMapMemory", &table->MapMemory);
    LoadFunction(gpa, device, "vkUnmapMemory", &table->UnmapMemory);
    LoadFunction(gpa, device, "vkFlushMappedMemoryRanges", &table->FlushMappedMemoryRanges);
    LoadFunction(gpa, device, "vkInvalidateMappedMemoryRanges", &table->InvalidateMappedMemoryRanges);
    LoadFunction(gpa, device, "vkGetDeviceMemoryCommitment", &table->GetDeviceMemoryCommitment);
    LoadFunction(gpa, device, "vkBindBufferMemory", &table->BindBufferMemory);
    LoadFunction(gpa, device, "vkBindImageMemory", &table->BindImageMemory);
    LoadFunction(gpa, device, "vkGetBufferMemoryRequirements", &table->GetBufferMemoryRequirements);
    LoadFunction(gpa, device, "vkGetImageMemoryRequirements", &table->GetImageMemoryRequirements);
    LoadFunction(gpa, device, "vkGetImageSparseMemoryRequirements", &table->GetImageSparseMemoryRequirements);
    LoadFunction(gpa, device, "vkQueueBindSparse", &table->QueueBindSparse);
    LoadFunction(gpa, device, "vkCreateFence", &table->CreateFence);
    LoadFunction(gpa, device, "vkDestroyFence", &table->DestroyFence);
    LoadFunction(gpa, device, "vkResetFences", &table->ResetFences);
    LoadFunction(gpa, device, "vkGetFenceStatus", &table->GetFenceStatus);
    LoadFunction(gpa, device, "vkWaitForFences", &table->WaitForFences);
    LoadFunction(gpa, device, "vkCreateSemaphore", &table->CreateSemaphore);
    LoadFunction(gpa, device, "vkDestroySemaphore", &table->DestroySemaphore);
    LoadFunction(gpa, device, "vkCreateEvent", &table->CreateEvent);
    LoadFunction(gpa, device, "vkDestroyEvent", &table->DestroyEvent);
    LoadFunction(gpa, device, "vkGetEventStatus", &table->GetEventStatus);
    LoadFunction(gpa, device, "vkSetEvent", &table->SetEvent);
    LoadFunction(gpa, device, "vkResetEvent", &table->ResetEvent);
    LoadFunction(gpa, device, "vkCreateQueryPool", &table->CreateQueryPool);
    LoadFunction(gpa, device, "vkDestroyQueryPool", &table->DestroyQueryPool);
    LoadFunction(gpa, device, "vkGetQueryPoolResults", &table->GetQueryPoolResults);
    LoadFunction(gpa, device, "vkCreateBuffer", &table->CreateBuffer);
    LoadFunction(gpa, device, "vkDestroyBuffer", &table->DestroyBuffer);
    LoadFunction(gpa, device, "vkCreateBufferView", &table->CreateBufferView);
    LoadFunction(gpa, device, "vkDestroyBufferView", &table->DestroyBufferView);
    LoadFunction(gpa, device, "vkCreateImage", &table->CreateImage);
    LoadFunction(gpa, device, "vkDestroyImage", &table->DestroyImage);
    LoadFunction(gpa, device, "vkGetImageSubresourceLayout", &table->GetImageSubresourceLayout);
    LoadFunction(gpa, device, "vkCreateImageView", &table->CreateImageView);
    LoadFunction(gpa, device, "vkDestroyImageView", &table->DestroyImageView);
    LoadFunction(gpa, device, "vkCreateShaderModule", &table->CreateShaderModule);
    LoadFunction(gpa, device, "vkDestroyShaderModule", &table->DestroyShaderModule);
    LoadFunction(gpa, device, "vkCreatePipelineCache", &table->CreatePipelineCache);
    LoadFunction(gpa, device, "vkDestroyPipelineCache", &table->DestroyPipelineCache);
    LoadFunction(gpa, device, "vkGetPipelineCacheData", &table->GetPipelineCacheData);
    LoadFunction(gpa, device, "vkMergePipelineCaches", &table->MergePipelineCaches);
    LoadFunction(gpa, device, "vkCreateGraphicsPipelines", &table->CreateGraphicsPipelines);
    LoadFunction(gpa, device, "vkCreateComputePipelines", &table->CreateComputePipelines);
    LoadFunction(gpa, device, "vkDestroyPipeline", &table->DestroyPipeline);
    LoadFunction(gpa, device, "vkCreatePipelineLayout", &table->CreatePipelineLayout);
    LoadFunction(gpa, device, "vkDestroyPipelineLayout", &table->DestroyPipelineLayout);
    LoadFunction(gpa, device, "vkCreateSampler", &table->CreateSampler);
    LoadFunction(gpa, device, "vkDestroySampler", &table->DestroySampler);
    LoadFunction(gpa, device, "vkCreateDescriptorSetLayout", &table->CreateDescriptorSetLayout);
    LoadFunction(gpa, device, "vkDestroyDescriptorSetLayout", &table->DestroyDescriptorSetLayout);
    LoadFunction(gpa, device, "vkCreateDescriptorPool", &table->CreateDescriptorPool);
    LoadFunction(gpa, device, "vkDestroyDescriptorPool", &table->DestroyDescriptorPool);
    LoadFunction(gpa, device, "vkResetDescriptorPool", &table->ResetDescriptorPool);
    LoadFunction(gpa, device, "vkAllocateDescriptorSets", &table->AllocateDescriptorSets);
    LoadFunction(gpa, device, "vkFreeDescriptorSets", &table->FreeDescriptorSets);
    LoadFunction(gpa, device, "vkUpdateDescriptorSets", &table->UpdateDescriptorSets);
    LoadFunction(gpa, device, "vkCreateFramebuffer", &table->CreateFramebuffer);
    LoadFunction(gpa, device, "vkDestroyFramebuffer", &table->DestroyFramebuffer);
    LoadFunction(gpa, device, "vkCreateRenderPass", &table->CreateRenderPass);
    LoadFunction(gpa, device, "vkDestroyRenderPass", &table->DestroyRenderPass);
    LoadFunction(gpa, device, "vkGetRenderAreaGranularity", &table->GetRenderAreaGranularity);
    LoadFunction(gpa, device, "vkCreateCommandPool", &table->CreateCommandPool);
    LoadFunction(gpa, device, "vkDestroyCommandPool", &table->DestroyCommandPool);
    LoadFunction(gpa, device, "vkResetCommandPool", &table->ResetCommandPool);
    LoadFunction(gpa, device, "vkAllocateCommandBuffers", &table->AllocateCommandBuffers);
    LoadFunction(gpa, device, "vkFreeCommandBuffers", &table->FreeCommandBuffers);
    LoadFunction(gpa, device, "vkBeginCommandBuffer", &table->BeginCommandBuffer);
    LoadFunction(gpa, device, "vkEndCommandBuffer", &table->EndCommandBuffer);
    LoadFunction(gpa, device, "vkResetCommandBuffer", &table->ResetCommandBuffer);
    LoadFunction(gpa, device, "vkCmdBindPipeline", &table->CmdBindPipeline);
    LoadFunction(gpa, device, "vkCmdSetViewport", &table->CmdSetViewport);
    LoadFunction(gpa, device, "vkCmdSetScissor", &table->CmdSetScissor);
    LoadFunction(gpa, device, "vkCmdSetLineWidth", &table->CmdSetLineWidth);
    LoadFunction(gpa, device, "vkCmdSetDepthBias", &table->CmdSetDepthBias);
    LoadFunction(gpa, device, "vkCmdSetBlendConstants", &table->CmdSetBlendConstants);
    LoadFunction(gpa, device, "vkCmdSetDepthBounds", &table->CmdSetDepthBounds);
    LoadFunction(gpa, device, "vkCmdSetStencilCompareMask", &table->CmdSetStencilCompareMask);
    LoadFunction(gpa, device, "vkCmdSetStencilWriteMask", &table->CmdSetStencilWriteMask);
    LoadFunction(gpa, device, "vkCmdSetStencilReference", &table->CmdSetStencilReference);
    LoadFunction(gpa, device, "vkCmdBindDescriptorSets", &table->CmdBindDescriptorSets);
    LoadFunction(gpa, device, "vkCmdBindIndexBuffer", &table->CmdBindIndexBuffer);
    LoadFunction(gpa, device, "vkCmdBindVertexBuffers", &table->CmdBindVertexBuffers);
    LoadFunction(gpa, device, "vkCmdDraw", &table->CmdDraw);
    LoadFunction(gpa, device, "vkCmdDrawIndexed", &table->CmdDrawIndexed);
    LoadFunction(gpa, device, "vkCmdDrawIndirect", &table->CmdDrawIndirect);
    LoadFunction(gpa, device, "vkCmdDrawIndexedIndirect", &table->CmdDrawIndexedIndirect);
    LoadFunction(gpa, device, "vkCmdDispatch", &table->CmdDispatch);
    LoadFunction(gpa, device, "vkCmdDispatchIndirect", &table->CmdDispatchIndirect);
    LoadFunction(gpa, device, "vkCmdCopyBuffer", &table->CmdCopyBuffer);
    LoadFunction(gpa, device, "vkCmdCopyImage", &table->CmdCopyImage);
    LoadFunction(gpa, device, "vkCmdBlitImage", &table->CmdBlitImage);
    LoadFunction(gpa, device, "vkCmdCopyBufferToImage", &table->CmdCopyBufferToImage);
    LoadFunction(gpa, device, "vkCmdCopyImageToBuffer", &table->CmdCopyImageToBuffer);
    LoadFunction(gpa, device, "vkCmdUpdateBuffer", &table->CmdUpdateBuffer);
    LoadFunction(gpa, device, "vkCmdFillBuffer", &table->CmdFillBuffer);
    LoadFunction(gpa, device, "vkCmdClearColorImage", &table->CmdClearColorImage);
    LoadFunction(gpa, device, "vkCmdClearDepthStencilImage", &table->CmdClearDepthStencilImage);
    LoadFunction(gpa, device, "vkCmdClearAttachments", &table->CmdClearAttachments);
    LoadFunction(gpa, device, "vkCmdResolveImage", &table->CmdResolveImage);
    LoadFunction(gpa, device, "vkCmdSetEvent", &table->CmdSetEvent);
    LoadFunction(gpa, device, "vkCmdResetEvent", &table->CmdResetEvent);
    LoadFunction(gpa, device, "vkCmdWaitEvents", &table->CmdWaitEvents);
    LoadFunction(gpa, device, "vkCmdPipelineBarrier", &table->CmdPipelineBarrier);
    LoadFunction(gpa, device, "vkCmdBeginQuery", &table->CmdBeginQuery);
    LoadFunction(gpa, device, "vkCmdEndQuery", &table->CmdEndQuery);
    LoadFunction(gpa, device, "vkCmdResetQueryPool", &table->CmdResetQueryPool);
    LoadFunction(gpa, device, "vkCmdWriteTimestamp", &table->CmdWriteTimestamp);
    LoadFunction(gpa, device, "vkCmdCopyQueryPoolResults", &table->CmdCopyQueryPoolResults);
    LoadFunction(gpa, device, "vkCmdPushConstants", &table->CmdPushConstants);
    LoadFunction(gpa, device, "vkCmdBeginRenderPass", &table->CmdBeginRenderPass);
    LoadFunction(gpa, device, "vkCmdNextSubpass", &table->CmdNextSubpass);
    LoadFunction(gpa, device, "vkCmdEndRenderPass", &table->CmdEndRenderPass);
    LoadFunction(gpa, device, "vkCmdExecuteCommands", &table->CmdExecuteCommands);
    LoadFunction(gpa, device, "vkBindBufferMemory2", &table->BindBufferMemory2);
    LoadFunction(gpa, device, "vkBindImageMemory2", &table->BindImageMemory2);
    LoadFunction(gpa, device, "vkGetDeviceGroupPeerMemoryFeatures", &table->GetDeviceGroupPeerMemoryFeatures);
    LoadFunction(gpa, device, "vkCmdSetDeviceMask", &table->CmdSetDeviceMask);
    LoadFunction(gpa, device, "vkCmdDispatchBase", &table->CmdDispatchBase);
    LoadFunction(gpa, device, "vkGetImageMemoryRequirements2", &table->GetImageMemoryRequirements2);
    LoadFunction(gpa, device, "vkGetBufferMemoryRequirements2", &table->GetBufferMemoryRequirements2);
    LoadFunction(gpa, device, "vkGetImageSparseMemoryRequirements2", &table->GetImageSparseMemoryRequirements2);
    LoadFunction(gpa, device, "vkTrimCommandPool", &table->TrimCommandPool);
    LoadFunction(gpa, device, "vkGetDeviceQueue2", &table->GetDeviceQueue2);
    LoadFunction(gpa, device, "vkCreateSamplerYcbcrConversion", &table->CreateSamplerYcbcrConversion);
    LoadFunction(gpa, device, "vkDestroySamplerYcbcrConversion", &table->DestroySamplerYcbcrConversion);
    LoadFunction(gpa, device, "vkCreateDescriptorUpdateTemplate", &table->CreateDescriptorUpdateTemplate);
    LoadFunction(gpa, device, "vkDestroyDescriptorUpdateTemplate", &table->DestroyDescriptorUpdateTemplate);
    LoadFunction(gpa, device, "vkUpdateDescriptorSetWithTemplate", &table->UpdateDescriptorSetWithTemplate);
    LoadFunction(gpa, device, "vkGetDescriptorSetLayoutSupport", &table->GetDescriptorSetLayoutSupport);
    LoadFunction(gpa, device, "vkCmdDrawIndirectCount", &table->CmdDrawIndirectCount);
    LoadFunction(gpa, device, "vkCmdDrawIndexedIndirectCount", &table->CmdDrawIndexedIndirectCount);
    LoadFunction(gpa, device, "vkCreateRenderPass2", &table->CreateRenderPass2);
    LoadFunction(gpa, device, "vkCmdBeginRenderPass2", &table->CmdBeginRenderPass2);
    LoadFunction(gpa, device, "vkCmdNextSubpass2", &table->CmdNextSubpass2);
    LoadFunction(gpa, device, "vkCmdEndRenderPass2", &table->CmdEndRenderPass2);
    LoadFunction(gpa, device, "vkResetQueryPool", &table->ResetQueryPool);
    LoadFunction(gpa, device, "vkGetSemaphoreCounterValue", &table->GetSemaphoreCounterValue);
    LoadFunction(gpa, device, "vkWaitSemaphores", &table->WaitSemaphores);
    LoadFunction(gpa, device, "vkSignalSemaphore", &table->SignalSemaphore);
    LoadFunction(gpa, device, "vkGetBufferDeviceAddress", &table->GetBufferDeviceAddress);
    LoadFunction(gpa, device, "vkGetBufferOpaqueCaptureAddress", &table->GetBufferOpaqueCaptureAddress);
    LoadFunction(gpa, device, "vkGetDeviceMemoryOpaqueCaptureAddress", &table->GetDeviceMemoryOpaqueCaptureAddress);
    LoadFunction(gpa, device, "vkCreatePrivateDataSlot", &table->CreatePrivateDataSlot);
    LoadFunction(gpa, device, "vkDestroyPrivateDataSlot", &table->DestroyPrivateDataSlot);
    LoadFunction(gpa, device, "vkSetPrivateData", &table->SetPrivateData);
    LoadFunction(gpa, device, "vkGetPrivateData", &table->GetPrivateData);
    LoadFunction(gpa, device, "vkCmdSetEvent2", &table->CmdSetEvent2);
    LoadFunction(gpa, device, "vkCmdResetEvent2", &table->CmdResetEvent2);
    LoadFunction(gpa, device, "vkCmdWaitEvents2", &table->CmdWaitEvents2);
    LoadFunction(gpa, device, "vkCmdPipelineBarrier2", &table->CmdPipelineBarrier2);
    LoadFunction(gpa, device, "vkCmdWriteTimestamp2", &table->CmdWriteTimestamp2);
    LoadFunction(gpa, device, "vkQueueSubmit2", &table->QueueSubmit2);
    LoadFunction(gpa, device, "vkCmdCopyBuffer2", &table->CmdCopyBuffer2);
    LoadFunction(gpa, device, "vkCmdCopyImage2", &table->CmdCopyImage2);
    LoadFunction(gpa, device, "vkCmdCopyBufferToImage2", &table->CmdCopyBufferToImage2);
    LoadFunction(gpa, device, "vkCmdCopyImageToBuffer2", &table->CmdCopyImageToBuffer2);
    LoadFunction(gpa, device, "vkCmdBlitImage2", &table->CmdBlitImage2);
    LoadFunction(gpa, device, "vkCmdResolveImage2", &table->CmdResolveImage2);
    LoadFunction(gpa, device, "vkCmdBeginRendering", &table->CmdBeginRendering);
    LoadFunction(gpa, device, "vkCmdEndRendering", &table->CmdEndRendering);
    LoadFunction(gpa, device, "vkCmdSetCullMode", &table->CmdSetCullMode);
    LoadFunction(gpa, device, "vkCmdSetFrontFace", &table->CmdSetFrontFace);
    LoadFunction(gpa, device, "vkCmdSetPrimitiveTopology", &table->CmdSetPrimitiveTopology);
    LoadFunction(gpa, device, "vkCmdSetViewportWithCount", &table->CmdSetViewportWithCount);
    LoadFunction(gpa, device, "vkCmdSetScissorWithCount", &table->CmdSetScissorWithCount);
    LoadFunction(gpa, device, "vkCmdBindVertexBuffers2", &table->CmdBindVertexBuffers2);
    LoadFunction(gpa, device, "vkCmdSetDepthTestEnable", &table->CmdSetDepthTestEnable);
    LoadFunction(gpa, device, "vkCmdSetDepthWriteEnable", &table->CmdSetDepthWriteEnable);
    LoadFunction(gpa, device, "vkCmdSetDepthCompareOp", &table->CmdSetDepthCompareOp);
    LoadFunction(gpa, device, "vkCmdSetDepthBoundsTestEnable", &table->CmdSetDepthBoundsTestEnable);
    LoadFunction(gpa, device, "vkCmdSetStencilTestEnable", &table->CmdSetStencilTestEnable);
    LoadFunction(gpa, device, "vkCmdSetStencilOp", &table->CmdSetStencilOp);
    LoadFunction(gpa, device, "vkCmdSetRasterizerDiscardEnable", &table->CmdSetRasterizerDiscardEnable);
    LoadFunction(gpa, device, "vkCmdSetDepthBiasEnable", &table->CmdSetDepthBiasEnable);
    LoadFunction(gpa, device, "vkCmdSetPrimitiveRestartEnable", &table->CmdSetPrimitiveRestartEnable);
    LoadFunction(gpa, device, "vkGetDeviceBufferMemoryRequirements", &table->GetDeviceBufferMemoryRequirements);
    LoadFunction(gpa, device, "vkGetDeviceImageMemoryRequirements", &table->GetDeviceImageMemoryRequirements);
    LoadFunction(gpa, device, "vkGetDeviceImageSparseMemoryRequirements", &table->GetDeviceImageSparseMemoryRequirements);
    LoadFunction(gpa, device, "vkCreateSwapchainKHR", &table->CreateSwapchainKHR);
    LoadFunction(gpa, device, "vkDestroySwapchainKHR", &table->DestroySwapchainKHR);
    LoadFunction(gpa, device, "vkGetSwapchainImagesKHR", &table->GetSwapchainImagesKHR);
    LoadFunction(gpa, device, "vkAcquireNextImageKHR", &table->AcquireNextImageKHR);
    LoadFunction(gpa, device, "vkQueuePresentKHR", &table->QueuePresentKHR);
    LoadFunction(gpa, device, "vkGetDeviceGroupPresentCapabilitiesKHR", &table->GetDeviceGroupPresentCapabilitiesKHR);
    LoadFunction(gpa, device, "vkGetDeviceGroupSurfacePresentModesKHR", &table->GetDeviceGroupSurfacePresentModesKHR);
    LoadFunction(gpa, device, "vkAcquireNextImage2KHR", &table->AcquireNextImage2KHR);
    LoadFunction(gpa, device, "vkCreateSharedSwapchainsKHR", &table->CreateSharedSwapchainsKHR);
    LoadFunction(gpa, device, "vkCmdBeginRenderingKHR", &table->CmdBeginRenderingKHR);
    LoadFunction(gpa, device, "vkCmdEndRenderingKHR", &table->CmdEndRenderingKHR);
    LoadFunction(gpa, device, "vkGetDeviceGroupPeerMemoryFeaturesKHR", &table->GetDeviceGroupPeerMemoryFeaturesKHR);
    LoadFunction(gpa, device, "vkCmdSetDeviceMaskKHR", &table->CmdSetDeviceMaskKHR);
    LoadFunction(gpa, device, "vkCmdDispatchBaseKHR", &table->CmdDispatchBaseKHR);
    LoadFunction(gpa, device, "vkTrimCommandPoolKHR", &table->TrimCommandPoolKHR);
    LoadFunction(gpa, device, "vkGetMemoryWin32HandleKHR", &table->GetMemoryWin32HandleKHR);
    LoadFunction(gpa, device, "vkGetMemoryWin32HandlePropertiesKHR", &table->GetMemoryWin32HandlePropertiesKHR);
    LoadFunction(gpa, device, "vkGetMemoryFdKHR", &table->GetMemoryFdKHR);
    LoadFunction(gpa, device, "vkGetMemoryFdPropertiesKHR", &table->GetMemoryFdPropertiesKHR);
    LoadFunction(gpa, device, "vkImportSemaphoreWin32HandleKHR", &table->ImportSemaphoreWin32HandleKHR);
    LoadFunction(gpa, device, "vkGetSemaphoreWin32HandleKHR", &table->GetSemaphoreWin32HandleKHR);
    LoadFunction(gpa, device, "vkImportSemaphoreFdKHR", &table->ImportSemaphoreFdKHR);
    LoadFunction(gpa, device, "vkGetSemaphoreFdKHR", &table->GetSemaphoreFdKHR);
    LoadFunction(gpa, device, "vkCmdPushDescriptorSetKHR", &table->CmdPushDescriptorSetKHR);
    LoadFunction(gpa, device, "vkCmdPushDescriptorSetWithTemplateKHR", &table->CmdPushDescriptorSetWithTemplateKHR);
    LoadFunction(gpa, device, "vkCreateDescriptorUpdateTemplateKHR", &table->CreateDescriptorUpdateTemplateKHR);
    LoadFunction(gpa, device, "vkDestroyDescriptorUpdateTemplateKHR", &table->DestroyDescriptorUpdateTemplateKHR);
    LoadFunction(gpa, device, "vkUpdateDescriptorSetWithTemplateKHR", &table->UpdateDescriptorSetWithTemplateKHR);
    LoadFunction(gpa, device, "vkCreateRenderPass2KHR", &table->CreateRenderPass2KHR);
    LoadFunction(gpa, device, "vkCmdBeginRenderPass2KHR", &table->CmdBeginRenderPass2KHR);
    LoadFunction(gpa, device, "vkCmdNextSubpass2KHR", &table->CmdNextSubpass2KHR);
    LoadFunction(gpa, device, "vkCmdEndRenderPass2KHR", &table->CmdEndRenderPass2KHR);
    LoadFunction(gpa, device, "vkGetSwapchainStatusKHR", &table->GetSwapchainStatusKHR);
    LoadFunction(gpa, device, "vkImportFenceWin32HandleKHR", &table->ImportFenceWin32HandleKHR);
    LoadFunction(gpa, device, "vkGetFenceWin32HandleKHR", &table->GetFenceWin32HandleKHR);
    LoadFunction(gpa, device, "vkImportFenceFdKHR", &table->ImportFenceFdKHR);
    LoadFunction(gpa, device, "vkGetFenceFdKHR", &table->GetFenceFdKHR);
    LoadFunction(gpa, device, "vkAcquireProfilingLockKHR", &table->AcquireProfilingLockKHR);
    LoadFunction(gpa, device, "vkReleaseProfilingLockKHR", &table->ReleaseProfilingLockKHR);
    LoadFunction(gpa, device, "vkGetImageMemoryRequirements2KHR", &table->GetImageMemoryRequirements2KHR);
    LoadFunction(gpa, device, "vkGetBufferMemoryRequirements2KHR", &table->GetBufferMemoryRequirements2KHR);
    LoadFunction(gpa, device, "vkGetImageSparseMemoryRequirements2KHR", &table->GetImageSparseMemoryRequirements2KHR);
    LoadFunction(gpa, device, "vkCreateSamplerYcbcrConversionKHR", &table->CreateSamplerYcbcrConversionKHR);
    LoadFunction(gpa, device, "vkDestroySamplerYcbcrConversionKHR", &table->DestroySamplerYcbcrConversionKHR);
    LoadFunction(gpa, device, "vkBindBufferMemory2KHR", &table->BindBufferMemory2KHR);
    LoadFunction(gpa, device, "vkBindImageMemory2KHR", &table->BindImageMemory2KHR);
    LoadFunction(gpa, device, "vkGetDescriptorSetLayoutSupportKHR", &table->GetDescriptorSetLayoutSupportKHR);
    LoadFunction(gpa, device, "vkCmdDrawIndirectCountKHR", &table->CmdDrawIndirectCountKHR);
    LoadFunction(gpa, device, "vkCmdDrawIndexedIndirectCountKHR", &table->CmdDrawIndexedIndirectCountKHR);
    LoadFunction(gpa, device, "vkGetSemaphoreCounterValueKHR", &table->GetSemaphoreCounterValueKHR);
    LoadFunction(gpa, device, "vkWaitSemaphoresKHR", &table->WaitSemaphoresKHR);
    LoadFunction(gpa, device, "vkSignalSemaphoreKHR", &table->SignalSemaphoreKHR);
    LoadFunction(gpa, device, "vkCmdSetFragmentShadingRateKHR", &table->CmdSetFragmentShadingRateKHR);
    LoadFunction(gpa, device, "vkWaitForPresentKHR", &table->WaitForPresentKHR);
    LoadFunction(gpa, device, "vkGetBufferDeviceAddressKHR", &table->GetBufferDeviceAddressKHR);
    LoadFunction(gpa, device, "vkGetBufferOpaqueCaptureAddressKHR", &table->GetBufferOpaqueCaptureAddressKHR);
    LoadFunction(gpa, device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR", &table->GetDeviceMemoryOpaqueCaptureAddressKHR);
    LoadFunction(gpa, device, "vkCreateDeferredOperationKHR", &table->CreateDeferredOperationKHR);
    LoadFunction(gpa, device, "vkDestroyDeferredOperationKHR", &table->DestroyDeferredOperationKHR);
    LoadFunction(gpa, device, "vkGetDeferredOperationMaxConcurrencyKHR", &table->GetDeferredOperationMaxConcurrencyKHR);
    LoadFunction(gpa, device, "vkGetDeferredOperationResultKHR", &table->GetDeferredOperationResultKHR);
    LoadFunction(gpa, device, "vkDeferredOperationJoinKHR", &table->DeferredOperationJoinKHR);
    LoadFunction(gpa, device, "vkGetPipelineExecutablePropertiesKHR", &table->GetPipelineExecutablePropertiesKHR);
    LoadFunction(gpa, device, "vkGetPipelineExecutableStatisticsKHR", &table->GetPipelineExecutableStatisticsKHR);
    LoadFunction(gpa, device, "vkGetPipelineExecutableInternalRepresentationsKHR", &table->GetPipelineExecutableInternalRepresentationsKHR);
    LoadFunction(gpa, device, "vkCmdSetEvent2KHR", &table->CmdSetEvent2KHR);
    LoadFunction(gpa, device, "vkCmdResetEvent2KHR", &table->CmdResetEvent2KHR);
    LoadFunction(gpa, device, "vkCmdWaitEvents2KHR", &table->CmdWaitEvents2KHR);
    LoadFunction(gpa, device, "vkCmdPipelineBarrier2KHR", &table->CmdPipelineBarrier2KHR);
    LoadFunction(gpa, device, "vkCmdWriteTimestamp2KHR", &table->CmdWriteTimestamp2KHR);
    LoadFunction(gpa, device, "vkQueueSubmit2KHR", &table->QueueSubmit2KHR);
    LoadFunction(gpa, device, "vkCmdWriteBufferMarker2AMD", &table->CmdWriteBufferMarker2AMD);
    LoadFunction(gpa, device, "vkGetQueueCheckpointData2NV", &table->GetQueueCheckpointData2NV);
    LoadFunction(gpa, device, "vkCmdCopyBuffer2KHR", &table->CmdCopyBuffer2KHR);
    LoadFunction(gpa, device, "vkCmdCopyImage2KHR", &table->CmdCopyImage2KHR);
    LoadFunction(gpa, device, "vkCmdCopyBufferToImage2KHR", &table->CmdCopyBufferToImage2KHR);
    LoadFunction(gpa, device, "vkCmdCopyImageToBuffer2KHR", &table->CmdCopyImageToBuffer2KHR);
    LoadFunction(gpa, device, "vkCmdBlitImage2KHR", &table->CmdBlitImage2KHR);
    LoadFunction(gpa, device, "vkCmdResolveImage2KHR", &table->CmdResolveImage2KHR);
    LoadFunction(gpa, device, "vkCmdTraceRaysIndirect2KHR", &table->CmdTraceRaysIndirect2KHR);
    LoadFunction(gpa, device, "vkGetDeviceBufferMemoryRequirementsKHR", &table->GetDeviceBufferMemoryRequirementsKHR);
    LoadFunction(gpa, device, "vkGetDeviceImageMemoryRequirementsKHR", &table->GetDeviceImageMemoryRequirementsKHR);
    LoadFunction(gpa, device, "vkGetDeviceImageSparseMemoryRequirementsKHR", &table->GetDeviceImageSparseMemoryRequirementsKHR);
    LoadFunction(gpa, device, "vkDebugMarkerSetObjectTagEXT", &table->DebugMarkerSetObjectTagEXT);
    LoadFunction(gpa, device, "vkDebugMarkerSetObjectNameEXT", &table->DebugMarkerSetObjectNameEXT);
    LoadFunction(gpa, device, "vkCmdDebugMarkerBeginEXT", &table->CmdDebugMarkerBeginEXT);
    LoadFunction(gpa, device, "vkCmdDebugMarkerEndEXT", &table->CmdDebugMarkerEndEXT);
    LoadFunction(gpa, device, "vkCmdDebugMarkerInsertEXT", &table->CmdDebugMarkerInsertEXT);
    LoadFunction(gpa, device, "vkCmdBindTransformFeedbackBuffersEXT", &table->CmdBindTransformFeedbackBuffersEXT);
    LoadFunction(gpa, device, "vkCmdBeginTransformFeedbackEXT", &table->CmdBeginTransformFeedbackEXT);
    LoadFunction(gpa, device, "vkCmdEndTransformFeedbackEXT", &table->CmdEndTransformFeedbackEXT);
    LoadFunction(gpa, device, "vkCmdBeginQueryIndexedEXT", &table->CmdBeginQueryIndexedEXT);
    LoadFunction(gpa, device, "vkCmdEndQueryIndexedEXT", &table->CmdEndQueryIndexedEXT);
    LoadFunction(gpa, device, "vkCmdDrawIndirectByteCountEXT", &table->CmdDrawIndirectByteCountEXT);
    LoadFunction(gpa, device, "vkGetImageViewHandleNVX", &table->GetImageViewHandleNVX);
    LoadFunction(gpa, device, "vkGetImageViewAddressNVX", &table->GetImageViewAddressNVX);
    LoadFunction(gpa, device, "vkCmdDrawIndirectCountAMD", &table->CmdDrawIndirectCountAMD);
    LoadFunction(gpa, device, "vkCmdDrawIndexedIndirectCountAMD", &table->CmdDrawIndexedIndirectCountAMD);
    LoadFunction(gpa, device, "vkGetShaderInfoAMD", &table->GetShaderInfoAMD);
    LoadFunction(gpa, device, "vkGetMemoryWin32HandleNV", &table->GetMemoryWin32HandleNV);
    LoadFunction(gpa, device, "vkCmdBeginConditionalRenderingEXT", &table->CmdBeginConditionalRenderingEXT);
    LoadFunction(gpa, device, "vkCmdEndConditionalRenderingEXT", &table->CmdEndConditionalRenderingEXT);
    LoadFunction(gpa, device, "vkCmdSetViewportWScalingNV", &table->CmdSetViewportWScalingNV);
    LoadFunction(gpa, device, "vkDisplayPowerControlEXT", &table->DisplayPowerControlEXT);
    LoadFunction(gpa, device, "vkRegisterDeviceEventEXT", &table->RegisterDeviceEventEXT);
    LoadFunction(gpa, device, "vkRegisterDisplayEventEXT", &table->RegisterDisplayEventEXT);
    LoadFunction(gpa, device, "vkGetSwapchainCounterEXT", &table->GetSwapchainCounterEXT);
    LoadFunction(gpa, device, "vkGetRefreshCycleDurationGOOGLE", &table->GetRefreshCycleDurationGOOGLE);
    LoadFunction(gpa, device, "vkGetPastPresentationTimingGOOGLE", &table->GetPastPresentationTimingGOOGLE);
    LoadFunction(gpa, device, "vkCmdSetDiscardRectangleEXT", &table->CmdSetDiscardRectangleEXT);
    LoadFunction(gpa, device, "vkSetHdrMetadataEXT", &table->SetHdrMetadataEXT);
    LoadFunction(gpa, device, "vkSetDebugUtilsObjectNameEXT", &table->SetDebugUtilsObjectNameEXT);
    LoadFunction(gpa, device, "vkSetDebugUtilsObjectTagEXT", &table->SetDebugUtilsObjectTagEXT);
    LoadFunction(gpa, device, "vkQueueBeginDebugUtilsLabelEXT", &table->QueueBeginDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkQueueEndDebugUtilsLabelEXT", &table->QueueEndDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkQueueInsertDebugUtilsLabelEXT", &table->QueueInsertDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkCmdBeginDebugUtilsLabelEXT", &table->CmdBeginDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkCmdEndDebugUtilsLabelEXT", &table->CmdEndDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkCmdInsertDebugUtilsLabelEXT", &table->CmdInsertDebugUtilsLabelEXT);
    LoadFunction(gpa, device, "vkGetAndroidHardwareBufferPropertiesANDROID", &table->GetAndroidHardwareBufferPropertiesANDROID);
    LoadFunction(gpa, device, "vkGetMemoryAndroidHardwareBufferANDROID", &table->GetMemoryAndroidHardwareBufferANDROID);
    LoadFunction(gpa, device, "vkCmdSetSampleLocationsEXT", &table->CmdSetSampleLocationsEXT);
    LoadFunction(gpa, device, "vkGetImageDrmFormatModifierPropertiesEXT", &table->GetImageDrmFormatModifierPropertiesEXT);
    LoadFunction(gpa, device, "vkCreateValidationCacheEXT", &table->CreateValidationCacheEXT);
    LoadFunction(gpa, device, "vkDestroyValidationCacheEXT", &table->DestroyValidationCacheEXT);
    LoadFunction(gpa, device, "vkMergeValidationCachesEXT", &table->MergeValidationCachesEXT);
    LoadFunction(gpa, device, "vkGetValidationCacheDataEXT", &table->GetValidationCacheDataEXT);
    LoadFunction(gpa, device, "vkCmdBindShadingRateImageNV", &table->CmdBindShadingRateImageNV);
    LoadFunction(gpa, device, "vkCmdSetViewportShadingRatePaletteNV", &table->CmdSetViewportShadingRatePaletteNV);
    LoadFunction(gpa, device, "vkCmdSetCoarseSampleOrderNV", &table->CmdSetCoarseSampleOrderNV);
    LoadFunction(gpa, device, "vkCreateAccelerationStructureNV", &table->CreateAccelerationStructureNV);
    LoadFunction(gpa, device, "vkDestroyAccelerationStructureNV", &table->DestroyAccelerationStructureNV);
    LoadFunction(gpa, device, "vkGetAccelerationStructureMemoryRequirementsNV", &table->GetAccelerationStructureMemoryRequirementsNV);
    LoadFunction(gpa, device, "vkBindAccelerationStructureMemoryNV", &table->BindAccelerationStructureMemoryNV);
    LoadFunction(gpa, device, "vkCmdBuildAccelerationStructureNV", &table->CmdBuildAccelerationStructureNV);
    LoadFunction(gpa, device, "vkCmdCopyAccelerationStructureNV", &table->CmdCopyAccelerationStructureNV);
    LoadFunction(gpa, device, "vkCmdTraceRaysNV", &table->CmdTraceRaysNV);
    LoadFunction(gpa, device, "vkCreateRayTracingPipelinesNV", &table->CreateRayTracingPipelinesNV);
    LoadFunction(gpa, device, "vkGetRayTracingShaderGroupHandlesKHR", &table->GetRayTracingShaderGroupHandlesKHR);
    LoadFunction(gpa, device, "vkGetRayTracingShaderGroupHandlesNV", &table->GetRayTracingShaderGroupHandlesNV);
    LoadFunction(gpa, device, "vkGetAccelerationStructureHandleNV", &table->GetAccelerationStructureHandleNV);
    LoadFunction(gpa, device, "vkCmdWriteAccelerationStructuresPropertiesNV", &table->CmdWriteAccelerationStructuresPropertiesNV);
    LoadFunction(gpa, device, "vkCompileDeferredNV", &table->CompileDeferredNV);
    LoadFunction(gpa, device, "vkGetMemoryHostPointerPropertiesEXT", &table->GetMemoryHostPointerPropertiesEXT);
    LoadFunction(gpa, device, "vkCmdWriteBufferMarkerAMD", &table->CmdWriteBufferMarkerAMD);
    LoadFunction(gpa, device, "vkGetCalibratedTimestampsEXT", &table->GetCalibratedTimestampsEXT);
    LoadFunction(gpa, device, "vkCmdDrawMeshTasksNV", &table->CmdDrawMeshTasksNV);
    LoadFunction(gpa, device, "vkCmdDrawMeshTasksIndirectNV", &table->CmdDrawMeshTasksIndirectNV);
    LoadFunction(gpa, device, "vkCmdDrawMeshTasksIndirectCountNV", &table->CmdDrawMeshTasksIndirectCountNV);
    LoadFunction(gpa, device, "vkCmdSetExclusiveScissorNV", &table->CmdSetExclusiveScissorNV);
    LoadFunction(gpa, device, "vkCmdSetCheckpointNV", &table->CmdSetCheckpointNV);
    LoadFunction(gpa, device, "vkGetQueueCheckpointDataNV", &table->GetQueueCheckpointDataNV);
    LoadFunction(gpa, device, "vkInitializePerformanceApiINTEL", &table->InitializePerformanceApiINTEL);
    LoadFunction(gpa, device, "vkUninitializePerformanceApiINTEL", &table->UninitializePerformanceApiINTEL);
    LoadFunction(gpa, device, "vkCmdSetPerformanceMarkerINTEL", &table->CmdSetPerformanceMarkerINTEL);
    LoadFunction(gpa, device, "vkCmdSetPerformanceStreamMarkerINTEL", &table->CmdSetPerformanceStreamMarkerINTEL);
    LoadFunction(gpa, device, "vkCmdSetPerformanceOverrideINTEL", &table->CmdSetPerformanceOverrideINTEL);
    LoadFunction(gpa, device, "vkAcquirePerformanceConfigurationINTEL", &table->AcquirePerformanceConfigurationINTEL);
    LoadFunction(gpa, device, "vkReleasePerformanceConfigurationINTEL", &table->ReleasePerformanceConfigurationINTEL);
    LoadFunction(gpa, device, "vkQueueSetPerformanceConfigurationINTEL", &table->QueueSetPerformanceConfigurationINTEL);
    LoadFunction(gpa, device, "vkGetPerformanceParameterINTEL", &table->GetPerformanceParameterINTEL);
    LoadFunction(gpa, device, "vkSetLocalDimmingAMD", &table->SetLocalDimmingAMD);
    LoadFunction(gpa, device, "vkGetBufferDeviceAddressEXT", &table->GetBufferDeviceAddressEXT);
    LoadFunction(gpa, device, "vkAcquireFullScreenExclusiveModeEXT", &table->AcquireFullScreenExclusiveModeEXT);
    LoadFunction(gpa, device, "vkReleaseFullScreenExclusiveModeEXT", &table->ReleaseFullScreenExclusiveModeEXT);
    LoadFunction(gpa, device, "vkGetDeviceGroupSurfacePresentModes2EXT", &table->GetDeviceGroupSurfacePresentModes2EXT);
    LoadFunction(gpa, device, "vkCmdSetLineStippleEXT", &table->CmdSetLineStippleEXT);
    LoadFunction(gpa, device, "vkResetQueryPoolEXT", &table->ResetQueryPoolEXT);
    LoadFunction(gpa, device, "vkCmdSetCullModeEXT", &table->CmdSetCullModeEXT);
    LoadFunction(gpa, device, "vkCmdSetFrontFaceEXT", &table->CmdSetFrontFaceEXT);
    LoadFunction(gpa, device, "vkCmdSetPrimitiveTopologyEXT", &table->CmdSetPrimitiveTopologyEXT);
    LoadFunction(gpa, device, "vkCmdSetViewportWithCountEXT", &table->CmdSetViewportWithCountEXT);
    LoadFunction(gpa, device, "vkCmdSetScissorWithCountEXT", &table->CmdSetScissorWithCountEXT);
    LoadFunction(gpa, device, "vkCmdBindVertexBuffers2EXT", &table->CmdBindVertexBuffers2EXT);
    LoadFunction(gpa, device, "vkCmdSetDepthTestEnableEXT", &table->CmdSetDepthTestEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetDepthWriteEnableEXT", &table->CmdSetDepthWriteEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetDepthCompareOpEXT", &table->CmdSetDepthCompareOpEXT);
    LoadFunction(gpa, device, "vkCmdSetDepthBoundsTestEnableEXT", &table->CmdSetDepthBoundsTestEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetStencilTestEnableEXT", &table->CmdSetStencilTestEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetStencilOpEXT", &table->CmdSetStencilOpEXT);
    LoadFunction(gpa, device, "vkGetGeneratedCommandsMemoryRequirementsNV", &table->GetGeneratedCommandsMemoryRequirementsNV);
    LoadFunction(gpa, device, "vkCmdPreprocessGeneratedCommandsNV", &table->CmdPreprocessGeneratedCommandsNV);
    LoadFunction(gpa, device, "vkCmdExecuteGeneratedCommandsNV", &table->CmdExecuteGeneratedCommandsNV);
    LoadFunction(gpa, device, "vkCmdBindPipelineShaderGroupNV", &table->CmdBindPipelineShaderGroupNV);
    LoadFunction(gpa, device, "vkCreateIndirectCommandsLayoutNV", &table->CreateIndirectCommandsLayoutNV);
    LoadFunction(gpa, device, "vkDestroyIndirectCommandsLayoutNV", &table->DestroyIndirectCommandsLayoutNV);
    LoadFunction(gpa, device, "vkCreatePrivateDataSlotEXT", &table->CreatePrivateDataSlotEXT);
    LoadFunction(gpa, device, "vkDestroyPrivateDataSlotEXT", &table->DestroyPrivateDataSlotEXT);
    LoadFunction(gpa, device, "vkSetPrivateDataEXT", &table->SetPrivateDataEXT);
    LoadFunction(gpa, device, "vkGetPrivateDataEXT", &table->GetPrivateDataEXT);
    LoadFunction(gpa, device, "vkCmdSetFragmentShadingRateEnumNV", &table->CmdSetFragmentShadingRateEnumNV);
    LoadFunction(gpa, device, "vkGetImageSubresourceLayout2EXT", &table->GetImageSubresourceLayout2EXT);
    LoadFunction(gpa, device, "vkCmdSetVertexInputEXT", &table->CmdSetVertexInputEXT);
    LoadFunction(gpa, device, "vkGetMemoryZirconHandleFUCHSIA", &table->GetMemoryZirconHandleFUCHSIA);
    LoadFunction(gpa, device, "vkGetMemoryZirconHandlePropertiesFUCHSIA", &table->GetMemoryZirconHandlePropertiesFUCHSIA);
    LoadFunction(gpa, device, "vkImportSemaphoreZirconHandleFUCHSIA", &table->ImportSemaphoreZirconHandleFUCHSIA);
    LoadFunction(gpa, device, "vkGetSemaphoreZirconHandleFUCHSIA", &table->GetSemaphoreZirconHandleFUCHSIA);
    LoadFunction(gpa, device, "vkCmdBindInvocationMaskHUAWEI", &table->CmdBindInvocationMaskHUAWEI);
    LoadFunction(gpa, device, "vkGetMemoryRemoteAddressNV", &table->GetMemoryRemoteAddressNV);
    LoadFunction(gpa, device, "vkCmdSetPatchControlPointsEXT", &table->CmdSetPatchControlPointsEXT);
    LoadFunction(gpa, device, "vkCmdSetRasterizerDiscardEnableEXT", &table->CmdSetRasterizerDiscardEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetDepthBiasEnableEXT", &table->CmdSetDepthBiasEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetLogicOpEXT", &table->CmdSetLogicOpEXT);
    LoadFunction(gpa, device, "vkCmdSetPrimitiveRestartEnableEXT", &table->CmdSetPrimitiveRestartEnableEXT);
    LoadFunction(gpa, device, "vkCmdSetColorWriteEnableEXT", &table->CmdSetColorWriteEnableEXT);
    LoadFunction(gpa, device, "vkCmdDrawMultiEXT", &table->CmdDrawMultiEXT);
    LoadFunction(gpa, device, "vkCmdDrawMultiIndexedEXT", &table->CmdDrawMultiIndexedEXT);
    LoadFunction(gpa, device, "vkSetDeviceMemoryPriorityEXT", &table->SetDeviceMemoryPriorityEXT);
    LoadFunction(gpa, device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE", &table->GetDescriptorSetLayoutHostMappingInfoVALVE);
    LoadFunction(gpa, device, "vkGetDescriptorSetHostMappingVALVE", &table->GetDescriptorSetHostMappingVALVE);
    LoadFunction(gpa, device, "vkCreateAccelerationStructureKHR", &table->CreateAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkDestroyAccelerationStructureKHR", &table->DestroyAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkCmdBuildAccelerationStructuresKHR", &table->CmdBuildAccelerationStructuresKHR);
    LoadFunction(gpa, device, "vkCmdBuildAccelerationStructuresIndirectKHR", &table->CmdBuildAccelerationStructuresIndirectKHR);
    LoadFunction(gpa, device, "vkBuildAccelerationStructuresKHR", &table->BuildAccelerationStructuresKHR);
    LoadFunction(gpa, device, "vkCopyAccelerationStructureKHR", &table->CopyAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkCopyAccelerationStructureToMemoryKHR", &table->CopyAccelerationStructureToMemoryKHR);
    LoadFunction(gpa, device, "vkCopyMemoryToAccelerationStructureKHR", &table->CopyMemoryToAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkWriteAccelerationStructuresPropertiesKHR", &table->WriteAccelerationStructuresPropertiesKHR);
    LoadFunction(gpa, device, "vkCmdCopyAccelerationStructureKHR", &table->CmdCopyAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkCmdCopyAccelerationStructureToMemoryKHR", &table->CmdCopyAccelerationStructureToMemoryKHR);
    LoadFunction(gpa, device, "vkCmdCopyMemoryToAccelerationStructureKHR", &table->CmdCopyMemoryToAccelerationStructureKHR);
    LoadFunction(gpa, device, "vkGetAccelerationStructureDeviceAddressKHR", &table->GetAccelerationStructureDeviceAddressKHR);
    LoadFunction(gpa, device, "vkCmdWriteAccelerationStructuresPropertiesKHR", &table->CmdWriteAccelerationStructuresPropertiesKHR);
    LoadFunction(gpa, device, "vkGetDeviceAccelerationStructureCompatibilityKHR", &table->GetDeviceAccelerationStructureCompatibilityKHR);
    LoadFunction(gpa, device, "vkGetAccelerationStructureBuildSizesKHR", &table->GetAccelerationStructureBuildSizesKHR);
    LoadFunction(gpa, device, "vkCmdTraceRaysKHR", &table->CmdTraceRaysKHR);
    LoadFunction(gpa, device, "vkCreateRayTracingPipelinesKHR", &table->CreateRayTracingPipelinesKHR);
    LoadFunction(gpa, device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", &table->GetRayTracingCaptureReplayShaderGroupHandlesKHR);
    LoadFunction(gpa, device, "vkCmdTraceRaysIndirectKHR", &table->CmdTraceRaysIndirectKHR);
    LoadFunction(gpa, device, "vkGetRayTracingShaderGroupStackSizeKHR", &table->GetRayTracingShaderGroupStackSizeKHR);
    LoadFunction(gpa, device, "vkCmdSetRayTracingPipelineStackSizeKHR", &table->CmdSetRayTracingPipelineStackSizeKHR);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
