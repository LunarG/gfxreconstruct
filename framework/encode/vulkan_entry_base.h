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

#ifndef GFXRECON_VULKAN_ENTRY_BASE_H
#define GFXRECON_VULKAN_ENTRY_BASE_H

#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vk_layer.h"

#include <type_traits>
#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

typedef std::unordered_map<std::string, PFN_vkVoidFunction> VulkanFunctionTable;

class VulkanEntryBase
{
  public:
    static VulkanEntryBase* Get()
    {
        GFXRECON_ASSERT(singleton_ != nullptr);
        return singleton_;
    }

    static void DestroySingleton();

    VulkanEntryBase(const VulkanFunctionTable& vulkan_function_table) : vulkan_function_table_(vulkan_function_table){};
    virtual ~VulkanEntryBase(){};

    virtual PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* pName);
    virtual PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* pName);
    virtual PFN_vkVoidFunction GetPhysicalDeviceProcAddr(VkInstance ourInstanceWrapper, const char* pName);
    virtual VkResult           EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                  const char*            pLayerName,
                                                                  uint32_t*              pPropertyCount,
                                                                  VkExtensionProperties* pProperties)   = 0;
    virtual VkResult           EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                    uint32_t*              pPropertyCount,
                                                                    VkExtensionProperties* pProperties) = 0;
    virtual VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
    virtual VkResult EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                    uint32_t*          pPropertyCount,
                                                    VkLayerProperties* pProperties);

    virtual VkResult dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkInstance*                  pInstance) = 0;
    virtual VkResult dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                                           const VkDeviceCreateInfo*    pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkDevice*                    pDevice)       = 0;

    // RemoveExtensions is public to enable test in encode\test\main.cpp
    static void RemoveExtensions(std::vector<VkExtensionProperties>& extensionProps,
                                 const char* const                   screenedExtensions[],
                                 const size_t                        screenedCount);

  protected:
    static VulkanEntryBase* singleton_;

    template <typename T>
    static VulkanEntryBase* InitSingleton(const VulkanFunctionTable& vulkan_function_table)
    {
        static_assert(std::is_base_of<VulkanEntryBase, T>::value, "T must be derived from VulkanEntryBase.");
        if (!singleton_)
        {
            singleton_ = new T(vulkan_function_table);
        }
        return singleton_;
    }

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
    static const std::vector<const char*> kVulkanUnsupportedDeviceExtensions;

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

    const VulkanFunctionTable vulkan_function_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_ENTRY_BASE_H
