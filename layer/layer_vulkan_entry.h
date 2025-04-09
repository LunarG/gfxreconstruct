/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_LAYER_VULKAN_ENTRY_H
#define GFXRECON_LAYER_VULKAN_ENTRY_H

#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vk_layer.h"

#include <mutex>
#include <unordered_map>
#include <vector>

#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(vulkan_layer)

// The following prototype declarations are required so the dispatch table can find these
// functions which are defined in the .cpp
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

class LayerVulkanEntry
{
  public:
    static LayerVulkanEntry* Get()
    {
        GFXRECON_ASSERT(singleton_ != nullptr);
        return singleton_;
    }

    static LayerVulkanEntry* InitSingleton();
    static void              DestroySingleton();

    LayerVulkanEntry(){};
    virtual ~LayerVulkanEntry(){};

    // The following prototype declarations are required so the dispatch table can find these
    // functions which are defined in trace_layer.cpp
    virtual PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* pName);
    virtual PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* pName);
    virtual PFN_vkVoidFunction GetPhysicalDeviceProcAddr(VkInstance ourInstanceWrapper, const char* pName);
    virtual VkResult           EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                  const char*            pLayerName,
                                                                  uint32_t*              pPropertyCount,
                                                                  VkExtensionProperties* pProperties);
    virtual VkResult           EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                    uint32_t*              pPropertyCount,
                                                                    VkExtensionProperties* pProperties);
    virtual VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
    virtual VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                    uint32_t*          pPropertyCount,
                                                    VkLayerProperties* pProperties);

    virtual VkResult dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkInstance*                  pInstance);
    virtual VkResult dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                                           const VkDeviceCreateInfo*    pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkDevice*                    pDevice);

    // RemoveExtensions is public to enable test in layer\test\main.cpp
    static void RemoveExtensions(std::vector<VkExtensionProperties>& extensionProps,
                                 const char* const                   screenedExtensions[],
                                 const size_t                        screenedCount);

  private:
    static LayerVulkanEntry* singleton_;

    static const VkLayerProperties kLayerProps;

    struct VulkanLayerExtensionProps
    {
        VkExtensionProperties    props;
        std::vector<std::string> instance_funcs;
        std::vector<std::string> device_funcs;
    };

    static const std::vector<VulkanLayerExtensionProps> kVulkanDeviceExtensionProps;

    /// An alphabetical list of device extensions which we do not report upstream if
    /// other layers or ICDs expose them to us.
    static const char* const kVulkanUnsupportedDeviceExtensions[];

    std::mutex                                  vulkan_instance_handles_lock;
    std::unordered_map<const void*, VkInstance> vulkan_instance_handles;

    // The GetPhysicalDeviceProcAddr of the next layer in the chain.
    // Retrieved during instance creation and forwarded to by this layer's
    // GetPhysicalDeviceProcAddr() after unwrapping its VkInstance parameter.
    std::mutex                                                    vulkan_gpdpa_lock;
    std::unordered_map<VkInstance, PFN_GetPhysicalDeviceProcAddr> vulkan_next_gpdpa;

    const VkLayerInstanceCreateInfo* GetInstanceChainInfo(const VkInstanceCreateInfo* pCreateInfo,
                                                          VkLayerFunction             func);
    const VkLayerDeviceCreateInfo*   GetDeviceChainInfo(const VkDeviceCreateInfo* pCreateInfo, VkLayerFunction func);

    void       AddInstanceHandle(VkInstance instance);
    VkInstance GetInstanceHandle(const void* handle);

    void SetInstanceNextGPDPA(const VkInstance instance, PFN_GetPhysicalDeviceProcAddr p_vulkan_next_gpdpa);
    PFN_GetPhysicalDeviceProcAddr GetNextGPDPA(const VkInstance instance);
};

GFXRECON_END_NAMESPACE(vulkan_layer)

#if ENABLE_OPENXR_SUPPORT
GFXRECON_BEGIN_NAMESPACE(openxr_layer)
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
GFXRECON_END_NAMESPACE(openxr_layer)
#endif // ENABLE_OPENXR_SUPPORT

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_LAYER_VULKAN_ENTRY_H
