/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_FRAMEWORK_ENCODE_VULKAN_LAYER_SETTINGS_H
#define GFXRECON_FRAMEWORK_ENCODE_VULKAN_LAYER_SETTINGS_H

#include "vulkan/vulkan.h"

#include "encode/capture_settings.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/// @brief Extracts the capture layer settings from a `VkInstanceCreateInfo` structure.
///
/// @param pCreateInfo A pointer to a `VkInstanceCreateInfo` structure which might contain one or more
///                    `VkLayerSettingsCreateInfoEXT` structures in its `pNext` chain.
///
/// @note This function only extracts settings for `VK_LAYER_LUNARG_gfxreconstruct`.
///
/// @return A `TraceSettings` object containing the extracted settings.
CaptureSettings::TraceSettings GetVulkanLayerTraceSettings(const VkInstanceCreateInfo* pCreateInfo);
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FRAMEWORK_ENCODE_VULKAN_LAYER_SETTINGS_H
