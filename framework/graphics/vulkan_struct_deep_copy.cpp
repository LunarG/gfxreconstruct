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

#include "vulkan_struct_deep_copy.h"
#include "util/logging.h"
#include <cstring>
#include <type_traits>
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// do not use for structs containing pointers
template <typename T>
inline size_t shallow_copy(const T* structs, uint32_t count, uint8_t* out_data)
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

inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

//! create a helper-lambda to handle pointer-type struct-members
template <typename T>
auto create_handle_pointer_member_function(uint8_t* out_data, uint32_t i, uint64_t& offset, const T& base_struct)
{
    auto handle_pointer_member = [out_data, i, &offset, &base_struct](const auto& pointer_member, uint32_t count) {
        if (pointer_member == nullptr || count == 0)
        {
            return;
        }

        // member-offset within struct in bytes
        uint32_t member_offset =
            reinterpret_cast<const uint8_t*>(&pointer_member) - reinterpret_cast<const uint8_t*>(&base_struct);

        // copy pointer-chain recursively
        uint32_t copy_size = vulkan_struct_deep_copy(pointer_member, count, offset_ptr(out_data, offset));

        // re-direct pointers to point at copy
        if (out_data != nullptr)
        {
            using pointer_type = std::decay_t<decltype(pointer_member)>;
            auto* out_ptr      = reinterpret_cast<pointer_type*>(out_data + i * sizeof(T) + member_offset);
            *out_ptr           = reinterpret_cast<pointer_type>(offset_ptr(out_data, offset));
        }
        offset += copy_size;
    };
    return handle_pointer_member;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// template <typename T>
// size_t vulkan_struct_deep_copy(const T* structs, uint32_t count, uint8_t* out_data)
//{
//     static_assert(false);
//     return 0;
// }

template <>
size_t vulkan_struct_deep_copy(const char* str, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const void* data, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineShaderStageCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputAttributeDescription* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputBindingDescription* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkSpecializationInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkSpecializationMapEntry* structs, uint32_t count, uint8_t* out_data);

template <>
size_t
vulkan_struct_deep_copy(const VkPipelineInputAssemblyStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineTessellationStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkViewport* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkRect2D* structs, uint32_t count, uint8_t* out_data);

template <>
size_t
vulkan_struct_deep_copy(const VkPipelineRasterizationStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineMultisampleStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineDepthStencilStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkSampleMask* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorBlendStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineDynamicStateCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorBlendAttachmentState* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkDynamicState* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRenderingCreateInfo* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCreateFlags2CreateInfoKHR* structs, uint32_t count, uint8_t* out_data);

template <>
size_t
vulkan_struct_deep_copy(const VkPipelineDiscardRectangleStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkFormat* structs, uint32_t count, uint8_t* out_data);

template <>
size_t
vulkan_struct_deep_copy(const VkGraphicsPipelineLibraryCreateInfoEXT* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipelineLibraryCreateInfoKHR* structs, uint32_t count, uint8_t* out_data);

template <>
size_t vulkan_struct_deep_copy(const VkPipeline* structs, uint32_t count, uint8_t* out_data);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <>
size_t vulkan_struct_deep_copy(const char* str, uint32_t /*count*/, uint8_t* out_data)
{
    if (str != nullptr)
    {
        size_t len = strlen(str);
        if (out_data != nullptr)
        {
            strcpy(reinterpret_cast<char*>(out_data), str);
        }
        return len + 1;
    }
    return 0;
}

template <>
size_t vulkan_struct_deep_copy(const void* data, uint32_t count, uint8_t* out_data)
{
    // copy binary blob pointed to
    if (out_data != nullptr)
    {
        memcpy(out_data, data, count);
    }
    return count;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineShaderStageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, offset_ptr(out_data, offset));

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pName, 1);
        handle_pointer_member(base_struct.pSpecializationInfo, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineVertexInputStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pVertexBindingDescriptions, base_struct.vertexBindingDescriptionCount);
        handle_pointer_member(base_struct.pVertexAttributeDescriptions, base_struct.vertexAttributeDescriptionCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSpecializationInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pMapEntries, base_struct.mapEntryCount);
        handle_pointer_member(base_struct.pData, base_struct.dataSize);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineInputAssemblyStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineTessellationStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pViewports, base_struct.viewportCount);
        handle_pointer_member(base_struct.pScissors, base_struct.scissorCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineMultisampleStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pSampleMask, base_struct.rasterizationSamples / 32 + 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineDepthStencilStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorBlendStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pAttachments, base_struct.attachmentCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineDynamicStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pDynamicStates, base_struct.dynamicStateCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRenderingCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCreateFlags2CreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t
vulkan_struct_deep_copy(const VkPipelineDiscardRectangleStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pDiscardRectangles, base_struct.discardRectangleCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGraphicsPipelineLibraryCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineLibraryCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

        // create lambda to handle pointer-members
        auto handle_pointer_member = create_handle_pointer_member_function(out_data, i, offset, base_struct);

        // deep copy all pointer members
        handle_pointer_member(base_struct.pLibraries, base_struct.libraryCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGraphicsPipelineCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
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
        if (base_struct.pNext != nullptr)
        {
            uint8_t* out_address = offset_ptr(out_data, offset);
            offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);

            if (out_address != nullptr)
            {
                void** out_pNext = reinterpret_cast<void**>(out_data + i * struct_size + offsetof(struct_type, pNext));
                *out_pNext       = out_address;
            }
        }

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

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputBindingDescription* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputAttributeDescription* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkSpecializationMapEntry* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkViewport* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkRect2D* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkSampleMask* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorBlendAttachmentState* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkDynamicState* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkFormat* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const VkPipeline* structs, uint32_t count, uint8_t* out_data)
{
    return shallow_copy(structs, count, out_data);
}

size_t vulkan_struct_deep_copy_pnext(const void* pNext, uint8_t* out_data)
{
    uint64_t offset = 0;

    while (pNext != nullptr)
    {
        auto     base    = reinterpret_cast<const VkBaseInStructure*>(pNext);
        uint8_t* out_ptr = offset_ptr(out_data, offset);

        switch (base->sType)
        {
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
                offset +=
                    vulkan_struct_deep_copy(reinterpret_cast<const VkPipelineRenderingCreateInfo*>(pNext), 1, out_ptr);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
                offset += vulkan_struct_deep_copy(
                    reinterpret_cast<const VkPipelineCreateFlags2CreateInfoKHR*>(pNext), 1, out_ptr);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
                offset += vulkan_struct_deep_copy(
                    reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(pNext), 1, out_ptr);
                break;
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
                offset += vulkan_struct_deep_copy(
                    reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(pNext), 1, out_ptr);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
                offset +=
                    vulkan_struct_deep_copy(reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(pNext), 1, out_ptr);
                break;
            default:
                GFXRECON_LOG_WARNING("vulkan_struct_deep_copy_pnext: unhandled sType: %d", base->sType);
                break;
        }
        pNext = base->pNext;
    }
    return offset;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)