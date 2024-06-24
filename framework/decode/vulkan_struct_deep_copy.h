/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_DEEP_COPY_H
#define GFXRECON_DECODE_VULKAN_DEEP_COPY_H

#include "util/defines.h"
#include <cstring>
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// do not use for structs containing pointers
template <typename T>
size_t deep_copy(const T* structs, uint32_t count, uint8_t* out_data)
{
    if (structs == nullptr)
    {
        return 0;
    }
    uint32_t num_bytes = sizeof(T) * count;
    if (out_data != nullptr)
    {
        memcpy(out_data, structs, num_bytes);
    }
    return num_bytes;
}

// template <typename T>
// size_t deep_copy(const T* structs, uint32_t count, uint8_t* out_data, uint64_t offset);

inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

size_t deep_copy_pnext(const void* pNext, uint8_t* out_data);

template <>
size_t deep_copy(const VkPipelineShaderStageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    uint64_t offset = 0;

    // start with base structure array
    offset += sizeof(VkPipelineShaderStageCreateInfo) * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info = structs[i];

        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<VkPipelineShaderStageCreateInfo*>(out_data);
            out_structures[i]   = create_info;
        }

        // TODO: deep copy all pointer members

        offset += deep_copy_pnext(create_info.pNext, out_data != nullptr ? out_data + offset : nullptr);
    }
    return offset;
}

template <>
size_t
deep_copy(const VkPipelineVertexInputStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    uint64_t offset = 0;

    // start with base structure array
    offset += sizeof(VkPipelineVertexInputStateCreateInfo) * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info = structs[i];

        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<VkPipelineVertexInputStateCreateInfo*>(out_data);
            out_structures[i]   = create_info;
        }
        offset += deep_copy_pnext(create_info.pNext, offset_ptr(out_data, offset));
    }
    return offset;
}

template <>
size_t deep_copy(const VkGraphicsPipelineCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    uint64_t offset = 0;

    // start with base structure array
    offset += sizeof(VkGraphicsPipelineCreateInfo) * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& create_info = structs[i];

        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<VkGraphicsPipelineCreateInfo*>(out_data);
            out_structures[i]   = create_info;
        }

        // TODO: deep copy all pointer members

        // VkPipelineShaderStageCreateInfo
        offset += deep_copy(create_info.pStages, create_info.stageCount, offset_ptr(out_data, offset));

        offset += deep_copy(create_info.pVertexInputState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pInputAssemblyState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pTessellationState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pViewportState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pRasterizationState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pMultisampleState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pRasterizationState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pDepthStencilState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pColorBlendState, 1, offset_ptr(out_data, offset));
        offset += deep_copy(create_info.pDynamicState, 1, offset_ptr(out_data, offset));

        offset += deep_copy_pnext(create_info.pNext, offset_ptr(out_data, offset));
    }
    return offset;
}

// --------------- VkGraphicsPipelineCreateInfo pNext -----------------

// VkPipelineRenderingCreateInfo
// VkPipelineCreateFlags2CreateInfoKHR
// VkPipelineDiscardRectangleStateCreateInfoEXT

size_t deep_copy_pnext(const void* pNext, uint8_t* out_data)
{
    uint64_t offset = 0;

    while (pNext != nullptr)
    {
        auto base_struct = reinterpret_cast<const VkBaseInStructure*>(pNext);

        switch (base_struct->sType)
        {
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
                offset += deep_copy(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(pNext),
                                    1,
                                    offset_ptr(out_data, offset));
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
                offset += deep_copy(reinterpret_cast<const VkPipelineCreateFlags2CreateInfoKHR*>(pNext),
                                    1,
                                    offset_ptr(out_data, offset));
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
                offset += deep_copy(reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(pNext),
                                    1,
                                    offset_ptr(out_data, offset));
                break;
            default:
                assert(false);
                break;
        }
        pNext = base_struct->pNext;
    }
    return offset;
}

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DEEP_COPY_H
