/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef GFXRECON_DECODE_CUSTOM_STRUCT_HANDLE_MAPPERS_H
#define GFXRECON_DECODE_CUSTOM_STRUCT_HANDLE_MAPPERS_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/pnext_node.h"
#include "decode/vulkan_object_info_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(VkDescriptorType               type,
                      Decoded_VkDescriptorImageInfo* wrapper,
                      const VulkanObjectInfoTable&   object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper,
                      const VulkanObjectInfoTable&                         object_info_table);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_HANDLE_MAPPERS_H
