/*
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H
#define GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H

#include "decode/vulkan_object_info_table.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(object_cleanup)

void FreeAllLiveObjects(VulkanObjectInfoTable*                                   table,
                        bool                                                     remove_entries,
                        bool                                                     report_leaks,
                        std::function<const encode::InstanceTable*(const void*)> get_instance_table,
                        std::function<const encode::DeviceTable*(const void*)>   get_device_table);

GFXRECON_END_NAMESPACE(object_cleanup)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_CLEANUP_UTIL_H
