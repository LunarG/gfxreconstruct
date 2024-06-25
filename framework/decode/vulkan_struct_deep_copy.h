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
// size_t deep_copy(const T* structs, uint32_t count, uint8_t* out_data);

inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

//! create a helper-lambda to handle pointer-type struct-members
auto create_handle_pointer_member_function = [](uint8_t* out_data, uint32_t i, uint64_t& offset, auto& base_struct) {
    auto handle_pointer_member = [out_data, i, &offset, &base_struct](const auto& pointer_member, uint32_t count) {
        using struct_type              = std::decay_t<decltype(base_struct)>;
        constexpr uint32_t struct_size = sizeof(struct_type);

        // member-offset within struct in bytes
        uint32_t member_offset =
            reinterpret_cast<const uint8_t*>(&pointer_member) - reinterpret_cast<const uint8_t*>(&base_struct);

        // copy pointer-chain recursively
        uint32_t copy_size = deep_copy(pointer_member, count, offset_ptr(out_data, offset));

        // re-direct pointers to point at copy
        if (out_data != nullptr)
        {
            using pointer_type    = std::decay_t<decltype(pointer_member)>;
            pointer_type* out_ptr = reinterpret_cast<pointer_type*>(out_data + i * struct_size + member_offset);
            *out_ptr              = reinterpret_cast<pointer_type>(offset_ptr(out_data, offset));
        }
        offset += copy_size;
    };
    return handle_pointer_member;
};

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
size_t deep_copy(const VkPipelineVertexInputStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
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
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    uint64_t offset = 0;

    // start with base structure array
    offset += struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];

        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }

        // copy pNext-chain
        offset += deep_copy_pnext(base_struct.pNext, offset_ptr(out_data, offset));

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pStages, base_struct.stageCount);
        handle_pointer_member(base_struct.pVertexInputState, 1);
        handle_pointer_member(base_struct.pInputAssemblyState, 1);
        handle_pointer_member(base_struct.pTessellationState, 1);
        handle_pointer_member(base_struct.pViewportState, 1);
        handle_pointer_member(base_struct.pRasterizationState, 1);
        handle_pointer_member(base_struct.pMultisampleState, 1);
        handle_pointer_member(base_struct.pRasterizationState, 1);
        handle_pointer_member(base_struct.pDepthStencilState, 1);
        handle_pointer_member(base_struct.pColorBlendState, 1);
        handle_pointer_member(base_struct.pDynamicState, 1);
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
        auto base = reinterpret_cast<const VkBaseInStructure*>(pNext);

        switch (base->sType)
        {
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
                offset += deep_copy(
                    reinterpret_cast<const VkPipelineRenderingCreateInfo*>(pNext), 1, offset_ptr(out_data, offset));
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
        pNext = base->pNext;
    }
    return offset;
}

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DEEP_COPY_H
