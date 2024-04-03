/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_TRACE_LAYER_H
#define GFXRECON_TRACE_LAYER_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#ifdef ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// The following prototype declarations are required so the dispatch table can find these
// functions which are defined in trace_layer.cpp

#ifdef ENABLE_OPENXR_SUPPORT
// OpenXR
XRAPI_ATTR XrResult XRAPI_CALL OpenXrEnumerateInstanceExtensionProperties(const char*            layerName,
                                                                          uint32_t               propertyCapacityInput,
                                                                          uint32_t*              propertyCountOutput,
                                                                          XrExtensionProperties* properties);
XRAPI_ATTR XrResult XRAPI_CALL OpenXrEnumerateApiLayerProperties(uint32_t              propertyCapacityInput,
                                                                 uint32_t*             propertyCountOutput,
                                                                 XrApiLayerProperties* properties);
XRAPI_ATTR XrResult XRAPI_CALL OpenXrCreateApiLayerInstance(const XrInstanceCreateInfo* info,
                                                            const XrApiLayerCreateInfo* apiLayerInfo,
                                                            XrInstance*                 instance);
XRAPI_ATTR XrResult XRAPI_CALL OpenXrGetInstanceProcAddr(XrInstance          instance,
                                                         const char*         name,
                                                         PFN_xrVoidFunction* function);
#endif // ENABLE_OPENXR_SUPPORT

// Vulkan
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VulkanGetInstanceProcAddr(VkInstance instance, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VulkanGetDeviceProcAddr(VkDevice device, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VulkanGetPhysicalDeviceProcAddr(VkInstance  ourInstanceWrapper,
                                                                         const char* pName);
VKAPI_ATTR VkResult VKAPI_CALL           VulkanEnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                                  const char*            pLayerName,
                                                                                  uint32_t*              pPropertyCount,
                                                                                  VkExtensionProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           VulkanEnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                                    uint32_t*              pPropertyCount,
                                                                                    VkExtensionProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           VulkanEnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                                VkLayerProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           VulkanEnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                                              uint32_t*          pPropertyCount,
                                                                              VkLayerProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL dispatch_VulkanCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             VkInstance*                  pInstance);
VKAPI_ATTR VkResult VKAPI_CALL dispatch_VulkanCreateDevice(VkPhysicalDevice             physicalDevice,
                                                           const VkDeviceCreateInfo*    pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkDevice*                    pDevice);

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TRACE_LAYER_H
