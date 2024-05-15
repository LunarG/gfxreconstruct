/*
** Copyright (c) 2019 LunarG, Inc.
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
    // VkDescriptorBufferInfo, VkBufferView, VkAccelerationStructureKHR or byte-arrays
    // in case of VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK.
    // There will be one array per descriptor update entry,
    // so the counts are pre-computed for the file encoding process to know the total number of
    // items to encode prior to processing the individual UpdateTemplateEntry structures.
    size_t                               max_size{ 0 };
    size_t                               image_info_count{ 0 };
    size_t                               buffer_info_count{ 0 };
    size_t                               texel_buffer_view_count{ 0 };
    size_t                               acceleration_structure_khr_count{ 0 };
    size_t                               inline_uniform_block_count{ 0 };
    std::vector<UpdateTemplateEntryInfo> image_info;
    std::vector<UpdateTemplateEntryInfo> buffer_info;
    std::vector<UpdateTemplateEntryInfo> texel_buffer_view;
    std::vector<UpdateTemplateEntryInfo> acceleration_structure_khr;
    std::vector<UpdateTemplateEntryInfo> inline_uniform_block;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DESCRIPTOR_UPDATE_TEMPLATE_INFO_H
