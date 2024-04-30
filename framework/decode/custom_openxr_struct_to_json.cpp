/*
** Copyright (c) 2022-2024 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "custom_openxr_struct_to_json.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_openxr_struct_to_json.h"
#include "generated/generated_openxr_enum_to_json.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_to_json.h"
#include "generated/generated_vulkan_enum_to_json.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/custom_openxr_struct_decoders.h"
#include "decode/custom_vulkan_struct_decoders.h"

#include "util/platform.h"
#include "util/defines.h"

#include "nlohmann/json.hpp"
#include "openxr/openxr.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void FieldToJson(nlohmann::ordered_json& jdata, const MLCoordinateFrameUID& data, const util::JsonOptions& options)
{
    FieldToJson(jdata["data"], data.data, options);
}

void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const Decoded_XrBindingModificationsKHR* data,
                 const util::JsonOptions&                 options)
{
    if (data && data->decoded_value)
    {
        const XrBindingModificationsKHR&         decoded_value = *data->decoded_value;
        const Decoded_XrBindingModificationsKHR& meta_struct   = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["bindingModificationCount"], decoded_value.bindingModificationCount, options);
        FieldToJson(jdata["bindingModifications"], meta_struct.bindingModifications, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfo* data, const util::JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const XrFrameEndInfo&         decoded_value = *data->decoded_value;
        const Decoded_XrFrameEndInfo& meta_struct   = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["displayTime"], decoded_value.displayTime, options);
        FieldToJson(jdata["environmentBlendMode"], decoded_value.environmentBlendMode, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
        FieldToJson(jdata["layers"], meta_struct.layers, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                                  jdata,
                 const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* data,
                 const util::JsonOptions&                                 options)
{
    if (data && data->decoded_value)
    {
        const XrSecondaryViewConfigurationLayerInfoMSFT&         decoded_value = *data->decoded_value;
        const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT& meta_struct   = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["viewConfigurationType"], decoded_value.viewConfigurationType, options);
        FieldToJson(jdata["environmentBlendMode"], decoded_value.environmentBlendMode, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
        FieldToJson(jdata["layers"], meta_struct.layers, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const Decoded_XrVulkanInstanceCreateInfoKHR* data,
                 const util::JsonOptions&                     options)
{
    if (data && data->decoded_value)
    {
        const XrVulkanInstanceCreateInfoKHR&         decoded_value = *data->decoded_value;
        const Decoded_XrVulkanInstanceCreateInfoKHR& meta_struct   = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["systemId"], meta_struct.systemId, options);
        FieldToJson(jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["pfnGetInstanceProcAddr"], meta_struct.pfnGetInstanceProcAddr, options);
        FieldToJson(jdata["vulkanCreateInfo"], meta_struct.vulkanCreateInfo, options);
        FieldToJson(jdata["vulkanAllocator"], meta_struct.vulkanAllocator, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json&                    jdata,
                 const Decoded_XrVulkanDeviceCreateInfoKHR* data,
                 const util::JsonOptions&                   options)
{
    if (data && data->decoded_value)
    {
        const XrVulkanDeviceCreateInfoKHR&         decoded_value = *data->decoded_value;
        const Decoded_XrVulkanDeviceCreateInfoKHR& meta_struct   = *data;

        FieldToJson(jdata["type"], decoded_value.type, options);
        HandleToJson(jdata["systemId"], meta_struct.systemId, options);
        FieldToJson(jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["pfnGetInstanceProcAddr"], meta_struct.pfnGetInstanceProcAddr, options);
        HandleToJson(jdata["vulkanPhysicalDevice"], meta_struct.vulkanPhysicalDevice, options);
        FieldToJson(jdata["vulkanCreateInfo"], meta_struct.vulkanCreateInfo, options);
        FieldToJson(jdata["vulkanAllocator"], meta_struct.vulkanAllocator, options);
        FieldToJson(jdata["next"], meta_struct.next, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_timespec* data, const util::JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const timespec&         decoded_value = *data->decoded_value;
        const Decoded_timespec& meta_struct   = *data;

        FieldToJson(jdata["tv_sec"], decoded_value.tv_sec, options);
        FieldToJson(jdata["tv_nsec"], decoded_value.tv_nsec, options);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
