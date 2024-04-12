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

#ifndef GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODER_DECLARATIONS_H
#define GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODER_DECLARATIONS_H

#if ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_XrFrameEndInfo;
struct Decoded_XrBindingModificationsKHR;
struct Decoded_XrSecondaryViewConfigurationLayerInfoMSFT;
struct Decoded_XrVulkanInstanceCreateInfoKHR;
struct Decoded_XrVulkanDeviceCreateInfoKHR;
struct Decoded_timespec;

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameEndInfo* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBindingModificationsKHR* wrapper);
size_t
DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanInstanceCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanDeviceCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_timespec* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_CUSTOM_OPENXR_STRUCT_DECODER_DECLARATIONS_H
