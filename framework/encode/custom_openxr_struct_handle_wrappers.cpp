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

#include "encode/custom_openxr_struct_handle_wrappers.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

void UnwrapStructHandles(const XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {}
}

void UnwrapStructHandles(const XrBindingModificationsKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {}
}

void UnwrapStructHandles(const XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {}
}

void UnwrapStructHandles(const XrVulkanInstanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {}
}

void UnwrapStructHandles(const XrVulkanDeviceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {}
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
