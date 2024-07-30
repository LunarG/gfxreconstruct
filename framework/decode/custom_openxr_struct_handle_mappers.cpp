/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#include "decode/custom_openxr_struct_handle_mappers.h"

#include "decode/custom_openxr_struct_decoders.h"
#include "decode/openxr_handle_mapping_util.h"
#include "decode/openxr_object_info.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_openxr_struct_handle_mappers.h"
#include "util/logging.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_XrVulkanInstanceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVulkanInstanceCreateInfoKHR* value = wrapper->decoded_value;

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(
            wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);
    }
}

void MapStructHandles(Decoded_XrVulkanDeviceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        XrVulkanDeviceCreateInfoKHR* value = wrapper->decoded_value;

        value->systemId = handle_mapping::MapHandle<OpenXrSystemIdInfo>(
            wrapper->systemId, object_info_table, &CommonObjectInfoTable::GetXrSystemIdInfo);

        value->vulkanPhysicalDevice = handle_mapping::MapHandle<VulkanPhysicalDeviceInfo>(
            wrapper->vulkanPhysicalDevice, object_info_table, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT