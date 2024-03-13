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

GFXRECON_BEGIN_NAMESPACE(vulkan_entry)
// The following prototype declarations are required so the dispatch table can find these
// functions which are defined in trace_layer.cpp
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetPhysicalDeviceProcAddr(VkInstance ourInstanceWrapper, const char* pName);
VKAPI_ATTR VkResult VKAPI_CALL           EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                            const char*            pLayerName,
                                                                            uint32_t*              pPropertyCount,
                                                                            VkExtensionProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                              uint32_t*              pPropertyCount,
                                                                              VkExtensionProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           EnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                          VkLayerProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL           EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                                        uint32_t*          pPropertyCount,
                                                                        VkLayerProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkInstance*                  pInstance);
VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                                                     const VkDeviceCreateInfo*    pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkDevice*                    pDevice);
GFXRECON_END_NAMESPACE(vulkan_entry)

#ifdef ENABLE_OPENXR_SUPPORT
GFXRECON_BEGIN_NAMESPACE(openxr_entry)
// OpenXR
XRAPI_ATTR XrResult XRAPI_CALL EnumerateInstanceExtensionProperties(const char*            layerName,
                                                                    uint32_t               propertyCapacityInput,
                                                                    uint32_t*              propertyCountOutput,
                                                                    XrExtensionProperties* properties);
XRAPI_ATTR XrResult XRAPI_CALL EnumerateApiLayerProperties(uint32_t              propertyCapacityInput,
                                                           uint32_t*             propertyCountOutput,
                                                           XrApiLayerProperties* properties);
XRAPI_ATTR XrResult XRAPI_CALL GetInstanceProcAddr(XrInstance instance, const char* name, PFN_xrVoidFunction* function);
XRAPI_ATTR XrResult XRAPI_CALL dispatch_CreateApiLayerInstance(const XrInstanceCreateInfo* info,
                                                               const XrApiLayerCreateInfo* apiLayerInfo,
                                                               XrInstance*                 instance);
GFXRECON_END_NAMESPACE(openxr_entry)
#endif // ENABLE_OPENXR_SUPPORT

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TRACE_LAYER_H
