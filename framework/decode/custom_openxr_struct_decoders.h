/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODERS_H

#if ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "decode/custom_openxr_struct_decoders_forward.h"
#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/openxr_next_node.h"
#include "generated/generated_openxr_struct_decoders_forward.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_XrFrameEndInfo
{
    using struct_type = XrFrameEndInfo;
    XrFrameEndInfo* decoded_value{ nullptr };
};

struct Decoded_XrBindingModificationsKHR
{
    using struct_type = XrBindingModificationsKHR;
    XrBindingModificationsKHR* decoded_value{ nullptr };
};

struct Decoded_XrSecondaryViewConfigurationLayerInfoMSFT
{
    using struct_type = XrSecondaryViewConfigurationLayerInfoMSFT;
    XrSecondaryViewConfigurationLayerInfoMSFT* decoded_value{ nullptr };
};

struct Decoded_XrVulkanInstanceCreateInfoKHR
{
    using struct_type = XrVulkanInstanceCreateInfoKHR;
    XrVulkanInstanceCreateInfoKHR*                       decoded_value{ nullptr };
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  vulkanCreateInfo{ nullptr };
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* vulkanAllocator{ nullptr };
};

struct Decoded_XrVulkanDeviceCreateInfoKHR
{
    using struct_type = XrVulkanDeviceCreateInfoKHR;
    XrVulkanDeviceCreateInfoKHR*                         decoded_value{ nullptr };
    format::HandleId                                     vulkanPhysicalDevice{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    vulkanCreateInfo{ nullptr };
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* vulkanAllocator{ nullptr };
};

struct Decoded_timespec
{
    using struct_type = timespec;
    timespec*                decoded_value{ nullptr };
    PointerDecoder<uint32_t> uint32;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODERS_H
