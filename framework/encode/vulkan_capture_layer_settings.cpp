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

#include "encode/vulkan_capture_layer_settings.h"

#include "graphics/vulkan_struct_get_pnext.h"

#include "encode/capture_settings.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/// @return Capture file name extracted from `VkLayerSettingEXT` when successful, otherwise the
/// `CaptureSettings::kDefaultCaptureFileName` default value.
std::string GetCaptureFileName(const VkLayerSettingEXT& setting)
{

    if (setting.type != VK_LAYER_SETTING_TYPE_STRING_EXT)
    {
        GFXRECON_LOG_ERROR("Expected setting type for '%s' to be "
                           "VK_LAYER_SETTING_TYPE_STRING_EXT, but got %d",
                           CAPTURE_FILE_NAME_LOWER,
                           setting.type);
        return CaptureSettings::kDefaultCaptureFileName;
    }
    if (setting.valueCount != 1)
    {
        GFXRECON_LOG_ERROR(
            "Expected value count for '%s' setting to be 1, but got %d", CAPTURE_FILE_NAME_LOWER, setting.valueCount);
        return CaptureSettings::kDefaultCaptureFileName;
    }
    if (setting.pValues == nullptr)
    {
        GFXRECON_LOG_ERROR("Expected non-null array of values for '%s' setting", CAPTURE_FILE_NAME_LOWER);
        return CaptureSettings::kDefaultCaptureFileName;
    }

    auto* values = reinterpret_cast<const char* const*>(setting.pValues);

    if (values[0] == nullptr)
    {
        GFXRECON_LOG_ERROR("Expected non-null value for '%s' setting", CAPTURE_FILE_NAME_LOWER);
        return CaptureSettings::kDefaultCaptureFileName;
    }

    return std::string(values[0]);
}

CaptureSettings::TraceSettings GetVulkanLayerTraceSettings(const VkInstanceCreateInfo* pCreateInfo)
{
    CaptureSettings::TraceSettings layer_settings;

    if (pCreateInfo == nullptr)
    {
        return layer_settings;
    }

    // There can be multiple VkLayerSettingsCreateInfoEXT structures in the pNext chain.
    const VkBaseInStructure* p_next = reinterpret_cast<const VkBaseInStructure*>(pCreateInfo);
    while (p_next != nullptr)
    {
        const auto* settings_create_info = graphics::vulkan_struct_get_pnext<VkLayerSettingsCreateInfoEXT>(p_next);
        if (settings_create_info == nullptr)
        {
            // No more to find
            break;
        }

        if (settings_create_info->settingCount > 0 && settings_create_info->pSettings == nullptr)
        {
            GFXRECON_LOG_ERROR("Expected non-null pSettings for VkLayerSettingsCreateInfoEXT with settingCount > 0");
            break;
        }

        static const char* VK_LAYER_NAME = "VK_LAYER_LUNARG_gfxreconstruct";
        for (uint32_t i = 0; i < settings_create_info->settingCount; ++i)
        {
            const VkLayerSettingEXT& setting = settings_create_info->pSettings[i];

            // Only add settings for the GFXReconstruct layer
            if (setting.pLayerName != nullptr && strcmp(setting.pLayerName, VK_LAYER_NAME) == 0)
            {
                if (setting.pSettingName == nullptr)
                {
                    GFXRECON_LOG_ERROR("Setting name is null for layer '%s'", VK_LAYER_NAME);
                    continue;
                }

                // Get capture name setting
                if (strcmp(setting.pSettingName, CAPTURE_FILE_NAME_LOWER) == 0)
                {
                    layer_settings.capture_file = GetCaptureFileName(setting);
                }
            }
        }

        p_next = reinterpret_cast<const VkBaseInStructure*>(settings_create_info->pNext);
    }

    return layer_settings;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
