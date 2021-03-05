/*
** Copyright (c) 2020 LunarG, Inc.
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

bool IsSupportedExtension(const std::vector<VkExtensionProperties>& properties, const char* extension);

void RemoveUnsupportedExtensions(const std::vector<VkExtensionProperties>& properties,
                                 std::vector<const char*>*                 extensions);

// This is a declaration for a generated function.
void RemoveUnsupportedFeatures(VkPhysicalDevice                 physicalDevice,
                               PFN_vkGetPhysicalDeviceFeatures  get_device_features_proc,
                               PFN_vkGetPhysicalDeviceFeatures2 get_device_features2_proc,
                               const void*                      pNext,
                               const VkPhysicalDeviceFeatures*  pEnabledFeatures);

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_FEATURE_FILTER_UTIL_H
