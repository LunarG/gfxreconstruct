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

#include "layer/trace_layer.h"

#include "encode/trace_manager.h"
#include "generated/generated_vulkan_api_call_encoders.h"
#include "generated/generated_layer_func_table.h"
#include "layer/custom_vulkan_api_call_encoders.h"
#include "layer/vk_dispatch_table_helper.h"

#include "vulkan/vk_layer.h"

#include <cstring>
#include <string>
#include <unordered_map>

static const VkLayerProperties LayerProps = {
    "VK_LAYER_LUNARG_gfxreconstruct",
    VK_MAKE_VERSION(1, 0, VK_HEADER_VERSION),
    1,
    "GFXReconstruct Capture Layer",
};

static const VkLayerInstanceCreateInfo* get_instance_chain_info(const VkInstanceCreateInfo* pCreateInfo,
                                                                VkLayerFunction             func)
{
    const VkLayerInstanceCreateInfo* chain_info =
        reinterpret_cast<const VkLayerInstanceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info &&
           ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerInstanceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

static const VkLayerDeviceCreateInfo* get_device_chain_info(const VkDeviceCreateInfo* pCreateInfo, VkLayerFunction func)
{
    const VkLayerDeviceCreateInfo* chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info &&
           ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

static const void* get_dispatch_key(const void* handle)
{
    const VkLayerDispatchTable* const* dispatch_table = reinterpret_cast<const VkLayerDispatchTable* const*>(handle);
    return static_cast<const void*>(*dispatch_table);
}

static std::unordered_map<const void*, VkLayerInstanceDispatchTable> instance_table;
static std::unordered_map<const void*, VkLayerDispatchTable>         device_table;

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

std::mutex g_create_destroy_mutex;

void init_instance_table(VkInstance instance, PFN_vkGetInstanceProcAddr gpa)
{
    auto& table = instance_table[get_dispatch_key(instance)];
    layer_init_instance_dispatch_table(instance, &table, gpa);
}

void init_device_table(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    auto& table = device_table[get_dispatch_key(device)];
    layer_init_device_dispatch_table(device, &table, gpa);
}

VkLayerInstanceDispatchTable* get_instance_table(const void* instance)
{
    auto table = instance_table.find(get_dispatch_key(instance));
    return (table != instance_table.end()) ? &table->second : nullptr;
}

VkLayerDispatchTable* get_device_table(const void* device)
{
    auto table = device_table.find(get_dispatch_key(device));
    return (table != device_table.end()) ? &table->second : nullptr;
}

VkResult dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                 const VkAllocationCallbacks* pAllocator,
                                 VkInstance*                  pInstance)
{
    VkResult                   result                = VK_ERROR_INITIALIZATION_FAILED;
    PFN_vkGetInstanceProcAddr  fpGetInstanceProcAddr = nullptr;
    PFN_vkCreateInstance       fpCreateInstance      = nullptr;
    VkLayerInstanceCreateInfo* chain_info =
        const_cast<VkLayerInstanceCreateInfo*>(get_instance_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

    if (chain_info && chain_info->u.pLayerInfo)
    {
        fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    }

    if (fpGetInstanceProcAddr)
    {
        fpCreateInstance = reinterpret_cast<PFN_vkCreateInstance>(fpGetInstanceProcAddr(NULL, "vkCreateInstance"));
    }

    if (fpCreateInstance)
    {
        // Advance the link info for the next element on the chain
        chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

        result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);
    }

    if ((result == VK_SUCCESS) && pInstance && (*pInstance != nullptr))
    {
        // TODO: Additional vktrace initialization.
        init_instance_table(*pInstance, fpGetInstanceProcAddr);
    }

    return result;
}

VkResult dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                               const VkDeviceCreateInfo*    pCreateInfo,
                               const VkAllocationCallbacks* pAllocator,
                               VkDevice*                    pDevice)
{
    VkResult                  result                = VK_ERROR_INITIALIZATION_FAILED;
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = nullptr;
    PFN_vkGetDeviceProcAddr   fpGetDeviceProcAddr   = nullptr;
    PFN_vkCreateDevice        fpCreateDevice        = nullptr;
    VkLayerDeviceCreateInfo*  chain_info =
        const_cast<VkLayerDeviceCreateInfo*>(get_device_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

    if (chain_info && chain_info->u.pLayerInfo)
    {
        fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        fpGetDeviceProcAddr   = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    }

    if (fpGetInstanceProcAddr && fpGetDeviceProcAddr)
    {
        fpCreateDevice = reinterpret_cast<PFN_vkCreateDevice>(fpGetInstanceProcAddr(NULL, "vkCreateDevice"));
    }

    if (fpCreateDevice)
    {
        // Advance the link info for the next element on the chain
        chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

        result = fpCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    }

    if ((result == VK_SUCCESS) && pDevice && (*pDevice != nullptr))
    {
        // TODO: Additional vktrace initialization.
        init_device_table(*pDevice, fpGetDeviceProcAddr);
    }

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;
    const auto         entry  = gfxrecon::func_table.find(pName);

    if (entry != gfxrecon::func_table.end())
    {
        result = entry->second;
    }
    else
    {
        const auto table = gfxrecon::get_instance_table(instance);
        if (table && table->GetInstanceProcAddr)
        {
            result = table->GetInstanceProcAddr(instance, pName);
        }
    }

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;
    const auto         entry  = gfxrecon::func_table.find(pName);

    if (entry != gfxrecon::func_table.end())
    {
        result = entry->second;
    }
    else
    {
        const auto table = gfxrecon::get_device_table(device);
        if (table && table->GetDeviceProcAddr)
        {
            result = table->GetDeviceProcAddr(device, pName);
        }
    }

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetPhysicalDeviceProcAddr(VkInstance instance, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;
    assert(instance != VK_NULL_HANDLE);
    const auto table = gfxrecon::get_instance_table(instance);
    if (table && table->GetPhysicalDeviceProcAddr)
    {
        result = table->GetPhysicalDeviceProcAddr(instance, pName);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                  const char*            pLayerName,
                                                                  uint32_t*              pPropertyCount,
                                                                  VkExtensionProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    // This layer has no properties to export.
    if ((pLayerName != nullptr) && (strcmp(pLayerName, LayerProps.layerName) == 0))
    {
        if (pPropertyCount != nullptr)
        {
            *pPropertyCount = 0;
        }
    }
    else
    {
        // If this function was not called with the layer's name, we expect to dispatch down the chain to obtain the ICD
        // provided extensions.
        result = gfxrecon::get_instance_table(physicalDevice)
                     ->EnumerateDeviceExtensionProperties(physicalDevice, nullptr, pPropertyCount, pProperties);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                    uint32_t*              pPropertyCount,
                                                                    VkExtensionProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if (pLayerName && (strcmp(pLayerName, LayerProps.layerName) == 0))
    {
        if (pPropertyCount != nullptr)
        {
            *pPropertyCount = 0;
        }
    }
    else
    {
        result = VK_ERROR_LAYER_NOT_PRESENT;
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                VkLayerProperties* pProperties)
{
    VkResult result = VK_SUCCESS;

    if (pProperties == nullptr)
    {
        if (pPropertyCount != nullptr)
        {
            *pPropertyCount = 1;
        }
    }
    else
    {
        if ((pPropertyCount != nullptr) && (*pPropertyCount >= 1))
        {
            memcpy(pProperties, &LayerProps, sizeof(LayerProps));
            *pPropertyCount = 1;
        }
        else
        {
            result = VK_INCOMPLETE;
        }
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                              uint32_t*          pPropertyCount,
                                                              VkLayerProperties* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    return EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

GFXRECON_END_NAMESPACE(gfxrecon)

// To be safe, we extern "C" these items to remove name mangling for all the items we want to export for Android and old
// loaders to find.
extern "C" {

VK_LAYER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL
                                    vkNegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct)
{
    assert(pVersionStruct != NULL);
    assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);

    // Fill in the function pointers if our version is at least capable of having the structure contain them.
    if (pVersionStruct->loaderLayerInterfaceVersion >= 2)
    {
        pVersionStruct->pfnGetInstanceProcAddr       = gfxrecon::GetInstanceProcAddr;
        pVersionStruct->pfnGetDeviceProcAddr         = gfxrecon::GetDeviceProcAddr;
        pVersionStruct->pfnGetPhysicalDeviceProcAddr = gfxrecon::GetPhysicalDeviceProcAddr;
    }

    if (pVersionStruct->loaderLayerInterfaceVersion > CURRENT_LOADER_LAYER_INTERFACE_VERSION)
    {
        pVersionStruct->loaderLayerInterfaceVersion = CURRENT_LOADER_LAYER_INTERFACE_VERSION;
    }

    return VK_SUCCESS;
}

// The following three functions are not directly invoked by the desktop loader, which instead uses the function
// pointers returned by the negotiate function.
VK_LAYER_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName)
{
    return gfxrecon::GetInstanceProcAddr(instance, pName);
}

VK_LAYER_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName)
{
    return gfxrecon::GetDeviceProcAddr(device, pName);
}

VK_LAYER_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_layerGetPhysicalDeviceProcAddr(VkInstance  instance,
                                                                                           const char* pName)
{
    return gfxrecon::GetPhysicalDeviceProcAddr(instance, pName);
}

// The following four functions are not invoked by the desktop loader, which retrieves the layer specific properties and
// extensions from both the layer's JSON file and during the negotiation process.
VK_LAYER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                                    const char*      pLayerName,
                                                                                    uint32_t*        pPropertyCount,
                                                                                    VkExtensionProperties* pProperties)
{
    assert(physicalDevice == VK_NULL_HANDLE);
    return gfxrecon::EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
}

VK_LAYER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(
    const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{
    return gfxrecon::EnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}

VK_LAYER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                                  VkLayerProperties* pProperties)
{
    return gfxrecon::EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

VK_LAYER_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                                                uint32_t*          pPropertyCount,
                                                                                VkLayerProperties* pProperties)
{
    assert(physicalDevice == VK_NULL_HANDLE);
    return gfxrecon::EnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
}

} // extern "C"
