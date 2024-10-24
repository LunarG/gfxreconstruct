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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H
#define GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H

#include "decode/vulkan_swapchain.h"
#include "decode/common_object_info_table.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(object_cleanup)

void FreeAllLiveObjects(CommonObjectInfoTable*                                         table,
                        bool                                                           remove_entries,
                        bool                                                           report_leaks,
                        std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                        std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table,
                        VulkanSwapchain*                                               swapchain);

void FreeAllLiveInstances(CommonObjectInfoTable*                                         table,
                          bool                                                           remove_entries,
                          bool                                                           report_leaks,
                          std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                          std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table);

GFXRECON_END_NAMESPACE(object_cleanup)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H
