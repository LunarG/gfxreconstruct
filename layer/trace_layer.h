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

#ifndef BRIMSTONE_TRACE_LAYER_H
#define BRIMSTONE_TRACE_LAYER_H

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/parameter_encoder.h"
#include "format/trace_manager.h"

#if defined(CreateSemaphore)
#undef CreateSemaphore
#endif
#if defined(CreateEvent)
#undef CreateEvent
#endif
#include "format/metadata_handler.h"
#include "layer/vk_layer_dispatch_table.h"

extern "C" {
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName);
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName);
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
}

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

bool init_layer();
void destroy_layer();
format::TraceManager* get_trace_manager();
format::MetadataHandler* get_metadata_handler();

void init_instance_table(VkInstance instance, PFN_vkGetInstanceProcAddr gpa);
void init_device_table(VkDevice device, PFN_vkGetDeviceProcAddr gpa);

VkLayerInstanceDispatchTable* get_instance_table(const void* instance);
VkLayerDispatchTable* get_device_table(const void* device);

VkResult dispatch_CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
VkResult dispatch_CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);

size_t encode_struct_ptr(format::ParameterEncoder* encoder, const void* value);
size_t encode_struct_array(format::ParameterEncoder* encoder, const void* value, size_t len);

BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_TRACE_LAYER_H
