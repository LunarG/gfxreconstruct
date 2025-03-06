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

#ifdef ENABLE_OPENXR_SUPPORT

#include "encode/custom_openxr_struct_encoders.h"
#include "generated/generated_openxr_struct_encoders.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_handle_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanInstanceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(value.systemId);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFunctionPtr(value.pfnGetInstanceProcAddr);
    EncodeStructPtr(encoder, value.vulkanCreateInfo);
    EncodeStructPtr(encoder, value.vulkanAllocator);
}

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanDeviceCreateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.type);
    EncodeNextStruct(encoder, value.next);
    encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(value.systemId);
    encoder->EncodeFlags64Value(value.createFlags);
    encoder->EncodeFunctionPtr(value.pfnGetInstanceProcAddr);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::PhysicalDeviceWrapper>(value.vulkanPhysicalDevice);
    EncodeStructPtr(encoder, value.vulkanCreateInfo);
    EncodeStructPtr(encoder, value.vulkanAllocator);
}

void EncodeStruct(ParameterEncoder* encoder, const timespec& value)
{
    // timespec types are architecture specific, but we always encode/decode as int64/int64
    encoder->EncodeInt64Value(static_cast<int64_t>(value.tv_sec));
    encoder->EncodeInt64Value(static_cast<int64_t>(value.tv_nsec));
}

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBuffer& value)
{
    // XrEventDatabuffer can safely alias to XrEventDataBaseHeader
    EncodeStruct(encoder, reinterpret_cast<const XrEventDataBaseHeader&>(value));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
