/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_BASE_LAYER_H
#define GFXRECON_BASE_LAYER_H

#include "util/defines.h"
#include "generated/generated_vulkan_dispatch_table.h"

#include "vulkan/vulkan.h"

#include <mutex>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

#include <unordered_map>
#include <stdarg.h>

#ifndef GFXRECON_LAYER_NAME
#error "GFXRECON_LAYER_NAME must be define"
#endif

#ifndef GFXRECON_LAYER_VERSION_MAJOR
#error "GFXRECON_LAYER_VERSION_MAJOR must be define"
#endif

#ifndef GFXRECON_LAYER_VERSION_MINOR
#error "GFXRECON_LAYER_VERSION_MINOR must be define"
#endif

#ifndef GFXRECON_LAYER_VERSION_PATCH
#error "GFXRECON_LAYER_VERSION_PATCH must be define"
#endif

#ifndef GFXRECON_LAYER_DESCRIPTION
#error "GFXRECON_LAYER_DESCRIPTION must be define"
#endif

#ifndef GFXRECON_LAYER_VERSION_DESIGNATION
#error "GFXRECON_LAYER_VERSION_DESIGNATION must be define"
#endif

#define GFXRECON_VERSION_STR_EXPAND(x) #x
#define GFXRECON_VERSION_STR(x) GFXRECON_VERSION_STR_EXPAND(x)

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL base_layer_GetInstanceProcAddr(VkInstance instance, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL base_layer_GetDeviceProcAddr(VkDevice device, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL base_layer_GetPhysicalDeviceProcAddr(VkInstance  ourInstanceWrapper,
                                                                              const char* pName);

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                  const char*            pLayerName,
                                                                  uint32_t*              pPropertyCount,
                                                                  VkExtensionProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                    uint32_t*              pPropertyCount,
                                                                    VkExtensionProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t*          pPropertyCount,
                                                                VkLayerProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                              uint32_t*          pPropertyCount,
                                                              VkLayerProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkInstance*                  pInstance);

VKAPI_ATTR VkResult VKAPI_CALL dispatch_CreateDevice(VkPhysicalDevice             physicalDevice,
                                                     const VkDeviceCreateInfo*    pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkDevice*                    pDevice);

struct instance_dispatch_table
{
    VkInstance            instance;
    encode::InstanceTable dispatch_table;
};

struct device_dispatch_table
{
    VkDevice            device;
    encode::DeviceTable dispatch_table;
};

static std::mutex                                               global_lock;
static std::unordered_map<const void*, instance_dispatch_table> instance_handles;
static std::unordered_map<const void*, device_dispatch_table>   device_handles;

static encode::InstanceTable* add_instance_handle(VkInstance instance)
{
    // Store the instance for use with vkCreateDevice.
    std::lock_guard<std::mutex> lock(global_lock);
    instance_handles[encode::GetDispatchKey(instance)] = { instance, encode::InstanceTable() };
    memset(&instance_handles[encode::GetDispatchKey(instance)].dispatch_table, 0, sizeof(encode::InstanceTable));
    return &instance_handles[encode::GetDispatchKey(instance)].dispatch_table;
}

static void remove_instance_handle(const void* handle)
{
    std::lock_guard<std::mutex> lock(global_lock);
    auto                        entry = instance_handles.find(encode::GetDispatchKey(handle));
    if (entry != instance_handles.end())
    {
        instance_handles.erase(entry);
    }
}

static instance_dispatch_table* get_instance_handle(const void* handle)
{
    std::lock_guard<std::mutex> lock(global_lock);
    auto                        entry = instance_handles.find(encode::GetDispatchKey(handle));
    return (entry != instance_handles.end()) ? &entry->second : nullptr;
}

static encode::DeviceTable* add_device_handle(VkDevice device)
{
    // Store the instance for use with vkCreateDevice.
    std::lock_guard<std::mutex> lock(global_lock);
    device_handles[encode::GetDispatchKey(device)] = { device, encode::DeviceTable() };
    memset(&device_handles[encode::GetDispatchKey(device)].dispatch_table, 0, sizeof(encode::DeviceTable));
    return &device_handles[encode::GetDispatchKey(device)].dispatch_table;
}

static void remove_device_handle(const void* handle)
{
    std::lock_guard<std::mutex> lock(global_lock);
    auto                        entry = device_handles.find(encode::GetDispatchKey(handle));
    if (entry != device_handles.end())
    {
        device_handles.erase(entry);
    }
}

static device_dispatch_table* get_device_handle(const void* handle)
{
    std::lock_guard<std::mutex> lock(global_lock);
    auto                        entry = device_handles.find(encode::GetDispatchKey(handle));
    return (entry != device_handles.end()) ? &entry->second : nullptr;
}

static void base_layer_print_info(const char* format, ...)
{
    va_list args;
    va_start(args, format);

#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_INFO, "[" GFXRECON_LAYER_NAME "]", format, args);
#else
    printf("[" GFXRECON_LAYER_NAME "] ");
    printf(format, args);
#endif

    va_end(args);
}

static void base_layer_print_error(const char* format, ...)
{
    va_list args;
    va_start(args, format);

#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_ERROR, "[" GFXRECON_LAYER_NAME "]", format, args);
#else
    fprintf(stderr, "[" GFXRECON_LAYER_NAME "] ");
    fprintf(stderr, format, args);
#endif

    va_end(args);
}

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BASE_LAYER_H
