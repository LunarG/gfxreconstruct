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

#ifndef GFXRECON_ENCODE_DESCRIPTOR_UPDATE_TEMPLATE_INFO_H
#define GFXRECON_ENCODE_DESCRIPTOR_UPDATE_TEMPLATE_INFO_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct UpdateTemplateEntryInfo
{
    uint32_t         binding;       // Used for state tracking only.
    uint32_t         array_element; // Used for state tracking only.
    uint32_t         count;
    size_t           offset;
    size_t           stride;
    VkDescriptorType type;
};

struct UpdateTemplateInfo
{
    // The counts are the sum of the total descriptorCount for each update template entry type. When written to the
    // capture file, the update template data will be written as tightly packed arrays of VkDescriptorImageInfo,
    // VkDescriptorBufferInfo, and VkBufferView types.  There will be one array per descriptor update entry, so the
    // counts are pre-computed for the file encoding process to know the total number of items to encode prior to
    // processing the individual UpdateTemplateEntry structures.
    size_t                               max_size{ 0 };
    size_t                               image_info_count{ 0 };
    size_t                               buffer_info_count{ 0 };
    size_t                               texel_buffer_view_count{ 0 };
    std::vector<UpdateTemplateEntryInfo> image_info;
    std::vector<UpdateTemplateEntryInfo> buffer_info;
    std::vector<UpdateTemplateEntryInfo> texel_buffer_view;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DESCRIPTOR_UPDATE_TEMPLATE_INFO_H
