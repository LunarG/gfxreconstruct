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

#if ENABLE_OPENXR_SUPPORT

#include "decode/custom_openxr_struct_decoders.h"
#include "decode/custom_vulkan_struct_decoders.h"

#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeNextStruct(const uint8_t* buffer, size_t buffer_size, OpenXrNextNode** next);

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrFrameEndInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t          bytes_read = 0;
    XrFrameEndInfo* value      = wrapper->decoded_value;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrBindingModificationsKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                     bytes_read = 0;
    XrBindingModificationsKHR* value      = wrapper->decoded_value;

    return bytes_read;
}

size_t
DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                     bytes_read = 0;
    XrSecondaryViewConfigurationLayerInfoMSFT* value      = wrapper->decoded_value;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanInstanceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    XrVulkanInstanceCreateInfoKHR* value      = wrapper->decoded_value;

    wrapper->vulkanCreateInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkInstanceCreateInfo>>();
    bytes_read += wrapper->vulkanCreateInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vulkanCreateInfo = wrapper->vulkanCreateInfo->GetPointer();

    wrapper->vulkanAllocator = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkAllocationCallbacks>>();
    bytes_read += wrapper->vulkanAllocator->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vulkanAllocator = wrapper->vulkanAllocator->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_XrVulkanDeviceCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                       bytes_read = 0;
    XrVulkanDeviceCreateInfoKHR* value      = wrapper->decoded_value;

    wrapper->vulkanCreateInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDeviceCreateInfo>>();
    bytes_read += wrapper->vulkanCreateInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vulkanCreateInfo = wrapper->vulkanCreateInfo->GetPointer();

    wrapper->vulkanAllocator = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkAllocationCallbacks>>();
    bytes_read += wrapper->vulkanAllocator->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->vulkanAllocator = wrapper->vulkanAllocator->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_timespec* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t    bytes_read = 0;
    timespec* value      = wrapper->decoded_value;

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
