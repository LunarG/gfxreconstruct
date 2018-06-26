/*
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

#include <cstring>
#include <string>
#include <unordered_map>

#include "vulkan/vk_layer.h"

#include "layer/trace_layer.h"
#include "layer/vk_dispatch_table_helper.h"

#include "generated/generated_struct_encoders.inc"
#include "generated/generated_encode_pnext_struct.inc"
#include "generated/generated_api_call_encoders.inc"
#include "generated/generated_layer_func_table.inc"

static const VkLayerProperties LayerProps = {
    "VK_LAYER_LUNARG_vktrace", VK_MAKE_VERSION(1, 0, VK_HEADER_VERSION), 1, "LunarG tracing layer",
};

static const VkLayerInstanceCreateInfo* get_instance_chain_info(const VkInstanceCreateInfo* pCreateInfo, VkLayerFunction func)
{
    const VkLayerInstanceCreateInfo* chain_info = reinterpret_cast<const VkLayerInstanceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info && ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) || (chain_info->function != func)))
    {
        chain_info = reinterpret_cast<const VkLayerInstanceCreateInfo*>(chain_info->pNext);
    }

    return chain_info;
}

static const VkLayerDeviceCreateInfo* get_device_chain_info(const VkDeviceCreateInfo* pCreateInfo, VkLayerFunction func)
{
    const VkLayerDeviceCreateInfo* chain_info = reinterpret_cast<const VkLayerDeviceCreateInfo*>(pCreateInfo->pNext);

    while (chain_info && ((chain_info->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO) || (chain_info->function != func)))
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
static std::unordered_map<const void*, VkLayerDispatchTable> device_table;
static brimstone::format::TraceManager trace_manager;
static brimstone::format::MetadataHandler* metadata_handler = nullptr;

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

bool init_layer()
{
    // TODO: load settings from file.
    format::EnabledOptions options;
    metadata_handler = new brimstone::format::MetadataHandler;
    if (nullptr == metadata_handler)
    {
        return false;
    }
    return trace_manager.Initialize("D:\\temp\\brimstone_test.bin", options);
}

void destroy_layer()
{
    trace_manager.Destroy();
    if (nullptr != metadata_handler)
    {
        delete metadata_handler;
        metadata_handler = nullptr;
    }
}

format::TraceManager* get_trace_manager()
{
    return &trace_manager;
}

format::MetadataHandler* get_metadata_handler()
{
    return metadata_handler;
}

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

VkResult dispatch_CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = nullptr;
    PFN_vkCreateInstance fpCreateInstance = nullptr;
    VkLayerInstanceCreateInfo* chain_info = const_cast<VkLayerInstanceCreateInfo*>(get_instance_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

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

VkResult dispatch_CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = nullptr;
    PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = nullptr;
    PFN_vkCreateDevice fpCreateDevice = nullptr;
    VkLayerDeviceCreateInfo* chain_info = const_cast<VkLayerDeviceCreateInfo*>(get_device_chain_info(pCreateInfo, VK_LAYER_LINK_INFO));

    if (chain_info && chain_info->u.pLayerInfo)
    {
        fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        fpGetDeviceProcAddr = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
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

size_t encode_struct_ptr(format::ParameterEncoder* encoder, const void* value)
{
    return 0;
}

size_t encode_struct_array(format::ParameterEncoder* encoder, const void* value, size_t len)
{
    return 0;
}

BRIMSTONE_END_NAMESPACE(brimstone)

PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;
    const auto entry = brimstone::func_table.find(pName);

    if (entry != brimstone::func_table.end())
    {
        result = entry->second;
    }
    else
    {
        const auto table = brimstone::get_instance_table(instance);
        if (table && table->GetInstanceProcAddr)
        {
            result = table->GetInstanceProcAddr(instance, pName);
        }
    }

    return result;
}

PFN_vkVoidFunction vkGetDeviceProcAddr(VkDevice device, const char* pName)
{
    PFN_vkVoidFunction result = nullptr;
    const auto entry = brimstone::func_table.find(pName);

    if (entry != brimstone::func_table.end())
    {
        result = entry->second;
    }
    else
    {
        const auto table = brimstone::get_device_table(device);
        if (table && table->GetDeviceProcAddr)
        {
            result = table->GetDeviceProcAddr(device, pName);
        }
    }

    return result;
}

// The following four functions are not invoked by the desktop loader, which retrieves the layer specific properties and extensions from the layer's JSON file.
VkResult vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
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
        // If this function was not called with the layer's name, we expect to dispatch down the chain to obtain the ICD provided extensions.
        result = brimstone::get_instance_table(physicalDevice)->EnumerateDeviceExtensionProperties(physicalDevice, nullptr, pPropertyCount, pProperties);
    }

    return result;
}

VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
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

VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
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

VkResult vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(physicalDevice);
    return vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}
