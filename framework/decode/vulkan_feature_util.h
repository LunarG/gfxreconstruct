/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_FEATURE_FILTER_UTIL_H
#define GFXRECON_DECODE_VULKAN_FEATURE_FILTER_UTIL_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

VkResult GetInstanceExtensions(PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc,
                               std::vector<VkExtensionProperties>*        properties);

VkResult GetDeviceExtensions(VkPhysicalDevice                         physical_device,
                             PFN_vkEnumerateDeviceExtensionProperties device_extension_proc,
                             std::vector<VkExtensionProperties>*      properties);

void RemoveUnsupportedExtensions(const std::vector<VkExtensionProperties>& properties,
                                 std::vector<const char*>*                 extensions);

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_FEATURE_FILTER_UTIL_H
