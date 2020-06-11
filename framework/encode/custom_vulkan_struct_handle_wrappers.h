/*
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_STRUCT_HANDLE_WRAPPERS_H
#define GFXRECON_ENCODE_CUSTOM_STRUCT_HANDLE_WRAPPERS_H

#include "encode/vulkan_handle_wrapper_util.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Vulkan structures that require special processing that the code generator cannot infer from the XML registry.
void UnwrapStructHandles(VkDescriptorType type, VkDescriptorImageInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_STRUCT_HANDLE_WRAPPERS_H
