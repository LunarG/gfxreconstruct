/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "graphics/vulkan_struct_deep_copy.h"
#include "format/platform_types.h"
#include "cstring"

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

inline uint8_t* offset_ptr(uint8_t* ptr, uint64_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

template <typename T>
size_t vulkan_struct_deep_copy(const T* structs, uint32_t count, uint8_t* out_data)
{
     return shallow_copy(structs, count, out_data);
}

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
size_t vulkan_struct_deep_copy(const void* structs, uint32_t count, uint8_t* out_data)
{
    // copy binary blob pointed to
    if (out_data != nullptr)
    {
        memcpy(out_data, structs, count);
    }
    return count;
}

template <typename T, typename U>
void handle_pointer(const T&  base_struct,
                    const U&  pointer_member,
                    uint64_t  count,
                    uint32_t  out_index,
                    uint64_t& offset,
                    uint8_t*  out_data)
{
    static_assert(std::is_pointer_v<U>);

    if (pointer_member == nullptr || count == 0)
    {
        return;
    }

    // member-offset within struct in bytes
    int64_t member_offset =
        reinterpret_cast<const uint8_t*>(&pointer_member) - reinterpret_cast<const uint8_t*>(&base_struct);

    // copy pointer-chain recursively
    uint64_t copy_size =
        vulkan_struct_deep_copy(pointer_member, static_cast<uint32_t>(count), offset_ptr(out_data, offset));

    // re-direct pointers to point at copy
    if (out_data != nullptr)
    {
        auto* out_ptr = reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        *out_ptr      = reinterpret_cast<U>(offset_ptr(out_data, offset));
    }
    offset += copy_size;
}

template <typename T>
void handle_pnext(const T& base_struct, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    if (base_struct.pNext != nullptr)
    {
        uint8_t* out_address = offset_ptr(out_data, offset);
        offset += vulkan_struct_deep_copy_stype(base_struct.pNext, out_address);
        if (out_address != nullptr)
        {
            void** out_pNext = reinterpret_cast<void**>(out_data + out_index * sizeof(T) + offsetof(T, pNext));
            *out_pNext       = out_address;
        }
    }
}

template <typename T, typename U>
void handle_struct_member(
    const T& base_struct, const U& struct_member, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    int64_t member_offset =
        reinterpret_cast<const uint8_t*>(&struct_member) - reinterpret_cast<const uint8_t*>(&base_struct);

    auto out_address = offset_ptr(out_data, offset);
    offset += vulkan_struct_deep_copy_stype(&struct_member, out_address);

    if (out_data != nullptr)
    {
        auto& out_struct_member = *reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        out_struct_member       = *reinterpret_cast<U*>(out_address);
    }
}

template <typename T, typename U>
void handle_array_of_pointers(const T&  base_struct,
                              const U&  struct_pointer_array,
                              uint32_t  struct_pointer_array_count,
                              uint32_t  out_index,
                              uint64_t& offset,
                              uint8_t*  out_data)
{
    using pointer_type = std::decay_t<decltype(*struct_pointer_array)>;
    static_assert(std::is_pointer_v<U> && std::is_pointer_v<pointer_type>);

    if (struct_pointer_array == nullptr || struct_pointer_array_count == 0)
    {
        return;
    }
    uint64_t copy_size = struct_pointer_array_count * sizeof(pointer_type);

    // member-offset within struct in bytes
    int64_t member_offset =
        reinterpret_cast<const uint8_t*>(&struct_pointer_array) - reinterpret_cast<const uint8_t*>(&base_struct);

    for (uint32_t i = 0; i < struct_pointer_array_count; ++i)
    {
        uint64_t out_offset = offset + copy_size;

        // copy pointers in array recursively
        copy_size += vulkan_struct_deep_copy(struct_pointer_array[i], 1, offset_ptr(out_data, out_offset));

        // re-direct pointers to point at copy
        if (out_data != nullptr)
        {
            auto* out_ptr = reinterpret_cast<pointer_type*>(out_data + offset + i * sizeof(pointer_type));
            *out_ptr      = reinterpret_cast<pointer_type>(offset_ptr(out_data, out_offset));
        }
    }
    // re-direct array-pointer to point at copy
    if (out_data != nullptr)
    {
        auto* out_ptr = reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        *out_ptr      = reinterpret_cast<U>(offset_ptr(out_data, offset));
    }
    offset += copy_size;
}

// explicit handling of problematic unions (members do not provide stype)
void handle_union(const VkIndirectCommandsLayoutTokenEXT& base_struct,
                  uint32_t                                out_index,
                  uint64_t&                               offset,
                  uint8_t*                                out_data)
{
    switch (base_struct.type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkIndirectCommandsPushConstantTokenEXT*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkIndirectCommandsVertexBufferTokenEXT*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkIndirectCommandsIndexBufferTokenEXT*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkIndirectCommandsExecutionSetTokenEXT*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        default:
            break;
    }
}

// explicit handling of problematic unions (members do not provide stype)
void handle_union(const VkDescriptorGetInfoEXT& base_struct, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    switch (base_struct.type)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            handle_pointer(
                base_struct, reinterpret_cast<const VkSampler*>(&base_struct.data), 1, out_index, offset, out_data);
            break;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkDescriptorImageInfo*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            handle_pointer(base_struct,
                           reinterpret_cast<const VkDescriptorAddressInfoEXT*>(&base_struct.data),
                           1,
                           out_index,
                           offset,
                           out_data);
            break;
        default:
            break;
    }
}


template <>
size_t vulkan_struct_deep_copy(const VkBufferMemoryBarrier* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageMemoryBarrier* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryBarrier* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkApplicationInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pApplicationName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pEngineName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkInstanceCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pApplicationInfo, 1, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppEnabledLayerNames, base_struct.enabledLayerCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppEnabledExtensionNames, base_struct.enabledExtensionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceQueueCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueuePriorities, base_struct.queueCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueCreateInfos, base_struct.queueCreateInfoCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppEnabledLayerNames, base_struct.enabledLayerCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppEnabledExtensionNames, base_struct.enabledExtensionCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pEnabledFeatures, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitDstStageMask, base_struct.waitSemaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCommandBuffers, base_struct.commandBufferCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphores, base_struct.signalSemaphoreCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMappedMemoryRange* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSparseBufferMemoryBindInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pBinds, base_struct.bindCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSparseImageOpaqueMemoryBindInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pBinds, base_struct.bindCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSparseImageMemoryBindInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pBinds, base_struct.bindCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindSparseInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBufferBinds, base_struct.bufferBindCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageOpaqueBinds, base_struct.imageOpaqueBindCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageBinds, base_struct.imageBindCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphores, base_struct.signalSemaphoreCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFenceCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkEventCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueryPoolCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferViewCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkShaderModuleCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCode, base_struct.codeSize/4, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCacheCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInitialData, base_struct.initialDataSize, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pMapEntries, base_struct.mapEntryCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pData, base_struct.dataSize, i, offset, out_data);
    }
    return offset;
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSpecializationInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkComputePipelineCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_struct_member(base_struct, base_struct.stage, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVertexBindingDescriptions, base_struct.vertexBindingDescriptionCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVertexAttributeDescriptions, base_struct.vertexAttributeDescriptionCount, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewports, base_struct.viewportCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pScissors, base_struct.scissorCount, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSampleMask, (base_struct.rasterizationSamples + 31) / 32, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachments, base_struct.attachmentCount, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDynamicStates, base_struct.dynamicStateCount, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStages, base_struct.stageCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVertexInputState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInputAssemblyState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTessellationState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewportState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRasterizationState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMultisampleState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthStencilState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorBlendState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDynamicState, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineLayoutCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetLayouts, base_struct.setLayoutCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPushConstantRanges, base_struct.pushConstantRangeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyDescriptorSet* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorPoolCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPoolSizes, base_struct.poolSizeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetLayouts, base_struct.descriptorSetCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetLayoutBinding* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pImmutableSamplers, base_struct.descriptorCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetLayoutCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBindings, base_struct.bindingCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteDescriptorSet* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageInfo, base_struct.descriptorCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBufferInfo, base_struct.descriptorCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTexelBufferView, base_struct.descriptorCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFramebufferCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachments, base_struct.attachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassDescription* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pInputAttachments, base_struct.inputAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachments, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pResolveAttachments, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthStencilAttachment, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPreserveAttachments, base_struct.preserveAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachments, base_struct.attachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSubpasses, base_struct.subpassCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDependencies, base_struct.dependencyCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandPoolCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferInheritanceInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInheritanceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pClearValues, base_struct.clearValueCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSubgroupProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindBufferMemoryInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindImageMemoryInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevice16BitStorageFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryDedicatedRequirements* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryDedicatedAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryAllocateFlagsInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupRenderPassBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDeviceRenderAreas, base_struct.deviceRenderAreaCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupCommandBufferBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphoreDeviceIndices, base_struct.waitSemaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCommandBufferDeviceMasks, base_struct.commandBufferCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphoreDeviceIndices, base_struct.signalSemaphoreCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupBindSparseInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindBufferMemoryDeviceGroupInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDeviceIndices, base_struct.deviceIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindImageMemoryDeviceGroupInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDeviceIndices, base_struct.deviceIndexCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSplitInstanceBindRegions, base_struct.splitInstanceBindRegionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceGroupProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupDeviceCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPhysicalDevices, base_struct.physicalDeviceCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferMemoryRequirementsInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageMemoryRequirementsInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageSparseMemoryRequirementsInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryRequirements2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSparseImageMemoryRequirements2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFeatures2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFormatProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageFormatProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageFormatInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMemoryProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSparseImageFormatProperties2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSparseImageFormatInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePointClippingProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassInputAttachmentAspectCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAspectReferences, base_struct.aspectReferenceCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewUsageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineTessellationDomainOriginStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassMultiviewCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewMasks, base_struct.subpassCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewOffsets, base_struct.dependencyCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCorrelationMasks, base_struct.correlationMaskCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiviewFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiviewProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVariablePointersFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceProtectedMemoryFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceProtectedMemoryProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceQueueInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkProtectedSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerYcbcrConversionCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerYcbcrConversionInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindImagePlaneMemoryInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImagePlaneMemoryRequirementsInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSamplerYcbcrConversionFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerYcbcrConversionImageFormatProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorUpdateTemplateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDescriptorUpdateEntries, base_struct.descriptorUpdateEntryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalImageFormatInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalImageFormatProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalBufferInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalBufferProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceIDProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalMemoryImageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalMemoryBufferCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportMemoryAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalFenceInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalFenceProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportFenceCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportSemaphoreCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalSemaphoreInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalSemaphoreProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance3Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetLayoutSupport* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderDrawParametersFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan11Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan11Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan12Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan12Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageFormatListCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewFormats, base_struct.viewFormatCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentDescription2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentReference2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassDescription2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInputAttachments, base_struct.inputAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachments, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pResolveAttachments, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthStencilAttachment, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPreserveAttachments, base_struct.preserveAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassDependency2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassCreateInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachments, base_struct.attachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSubpasses, base_struct.subpassCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDependencies, base_struct.dependencyCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCorrelatedViewMasks, base_struct.correlatedViewMaskCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassEndInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevice8BitStorageFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDriverProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderAtomicInt64Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderFloat16Int8Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFloatControlsProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetLayoutBindingFlagsCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBindingFlags, base_struct.bindingCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDescriptorIndexingFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDescriptorIndexingProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetVariableDescriptorCountAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDescriptorCounts, base_struct.descriptorSetCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetVariableDescriptorCountLayoutSupport* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassDescriptionDepthStencilResolve* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthStencilResolveAttachment, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthStencilResolveProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceScalarBlockLayoutFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageStencilUsageCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerReductionModeCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSamplerFilterMinmaxProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkanMemoryModelFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImagelessFramebufferFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFramebufferAttachmentImageInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewFormats, base_struct.viewFormatCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFramebufferAttachmentsCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachmentImageInfos, base_struct.attachmentImageInfoCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassAttachmentBeginInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachments, base_struct.attachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentReferenceStencilLayout* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentDescriptionStencilLayout* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHostQueryResetFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTimelineSemaphoreFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTimelineSemaphoreProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreTypeCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTimelineSemaphoreSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphoreValues, base_struct.waitSemaphoreValueCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphoreValues, base_struct.signalSemaphoreValueCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreWaitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSemaphores, base_struct.semaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pValues, base_struct.semaphoreCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreSignalInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceBufferDeviceAddressFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferDeviceAddressInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferOpaqueCaptureAddressCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryOpaqueCaptureAddressAllocateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceMemoryOpaqueCaptureAddressInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan13Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan13Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCreationFeedbackCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineCreationFeedback, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineStageCreationFeedbacks, base_struct.pipelineStageCreationFeedbackCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderTerminateInvocationFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceToolProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePrivateDataFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDevicePrivateDataCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPrivateDataSlotCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineCreationCacheControlFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryBarrier2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferMemoryBarrier2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageMemoryBarrier2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDependencyInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMemoryBarriers, base_struct.memoryBarrierCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBufferMemoryBarriers, base_struct.bufferMemoryBarrierCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageMemoryBarriers, base_struct.imageMemoryBarrierCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferSubmitInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubmitInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphoreInfos, base_struct.waitSemaphoreInfoCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCommandBufferInfos, base_struct.commandBufferInfoCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphoreInfos, base_struct.signalSemaphoreInfoCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSynchronization2Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageRobustnessFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferCopy2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyBufferInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageCopy2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferImageCopy2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyBufferToImageInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageToBufferInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageBlit2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBlitImageInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageResolve2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkResolveImageInfo2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSubgroupSizeControlFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSubgroupSizeControlProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceInlineUniformBlockFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceInlineUniformBlockProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteDescriptorSetInlineUniformBlock* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pData, base_struct.dataSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorPoolInlineUniformBlockCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingAttachmentInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachments, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthAttachment, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStencilAttachment, 1, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDynamicRenderingFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferInheritanceRenderingInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderIntegerDotProductFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderIntegerDotProductProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTexelBufferAlignmentProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFormatProperties3* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance4Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance4Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceBufferMemoryRequirements* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCreateInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceImageMemoryRequirements* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCreateInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan14Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVulkan14Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCopySrcLayouts, base_struct.copySrcLayoutCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCopyDstLayouts, base_struct.copyDstLayoutCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceQueueGlobalPriorityCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceGlobalPriorityQueryFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyGlobalPriorityProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSubgroupRotateFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderFloatControls2Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderExpectAssumeFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLineRasterizationFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLineRasterizationProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationLineStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeDivisorProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineVertexInputDivisorStateCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVertexBindingDivisors, base_struct.vertexBindingDivisorCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeDivisorFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceIndexTypeUint8Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryMapInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryUnmapInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance5Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance5Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingAreaInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageSubresource2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceImageSubresourceInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCreateInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSubresource, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubresourceLayout2* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCreateFlags2CreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferUsageFlags2CreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePushDescriptorProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDynamicRenderingLocalReadFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingAttachmentLocationInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentLocations, base_struct.colorAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingInputAttachmentIndexInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentInputIndices, base_struct.colorAttachmentCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthInputAttachmentIndex, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStencilInputAttachmentIndex, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance6Features* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance6Properties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindMemoryStatus* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pResult, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindDescriptorSetsInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDescriptorSets, base_struct.descriptorSetCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDynamicOffsets, base_struct.dynamicOffsetCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushConstantsInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pValues, base_struct.size, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushDescriptorSetInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDescriptorWrites, base_struct.descriptorWriteCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushDescriptorSetWithTemplateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineProtectedAccessFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineRobustnessFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineRobustnessProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRobustnessCreateInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHostImageCopyFeatures* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHostImageCopyProperties* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCopySrcLayouts, base_struct.copySrcLayoutCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCopyDstLayouts, base_struct.copyDstLayoutCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryToImageCopy* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageToMemoryCopy* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMemoryToImageInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageToMemoryInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageToImageInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHostImageLayoutTransitionInfo* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubresourceHostMemcpySize* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHostImageCopyDevicePerformanceQuery* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSwapchains, base_struct.swapchainCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageIndices, base_struct.swapchainCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pResults, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageSwapchainCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindImageMemorySwapchainInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAcquireNextImageInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupPresentCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupPresentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDeviceMasks, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceGroupSwapchainCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayModeCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.displayName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplaySurfaceCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPresentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWin32SurfaceCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyQueryResultStatusPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyVideoPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoProfileListInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pProfiles, base_struct.profileCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoFormatInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoFormatPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoPictureResourceInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoReferenceSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPictureResource, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoSessionMemoryRequirementsKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindVideoSessionMemoryInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoSessionCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVideoProfile, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdHeaderVersion, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoSessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoSessionParametersUpdateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoBeginCodingInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReferenceSlots, base_struct.referenceSlotCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEndCodingInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoCodingControlInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeUsageInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetupReferenceSlot, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReferenceSlots, base_struct.referenceSlotCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264QualityLevelPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264SessionCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264SessionParametersAddInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPSs, base_struct.stdSPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPSs, base_struct.stdPPSCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pParametersAddInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264SessionParametersGetInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264SessionParametersFeedbackInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264NaluSliceInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSliceHeader, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pNaluSliceEntries, base_struct.naluSliceEntryCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264RateControlInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264RateControlLayerInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264GopRemainingFrameInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265SessionCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265QualityLevelPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265SessionParametersAddInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdVPSs, base_struct.stdVPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPSs, base_struct.stdSPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPSs, base_struct.stdPPSCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pParametersAddInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265SessionParametersGetInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265SessionParametersFeedbackInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265NaluSliceSegmentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSliceSegmentHeader, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pNaluSliceSegmentEntries, base_struct.naluSliceSegmentEntryCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265RateControlInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265RateControlLayerInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265GopRemainingFrameInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264SessionParametersAddInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPSs, base_struct.stdSPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPSs, base_struct.stdPPSCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pParametersAddInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSliceOffsets, base_struct.sliceCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportMemoryWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttributes, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryWin32HandlePropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryFdPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWin32KeyedMutexAcquireReleaseInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireSyncs, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireKeys, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireTimeouts, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReleaseSyncs, base_struct.releaseCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReleaseKeys, base_struct.releaseCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportSemaphoreWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportSemaphoreWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttributes, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkD3D12FenceSubmitInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pWaitSemaphoreValues, base_struct.waitSemaphoreValuesCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSignalSemaphoreValues, base_struct.signalSemaphoreValuesCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreGetWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportSemaphoreFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreGetFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentRegionKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pRectangles, base_struct.rectangleCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentRegionsKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSharedPresentSurfaceCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportFenceWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportFenceWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttributes, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.name, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFenceGetWin32HandleInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportFenceFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFenceGetFdInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePerformanceQueryFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePerformanceQueryPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceCounterKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceCounterDescriptionKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueryPoolPerformanceCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCounterIndices, base_struct.counterIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAcquireProfilingLockInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceQuerySubmitInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSurfaceInfo2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilities2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceFormat2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayProperties2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPlaneProperties2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayModeProperties2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPlaneInfo2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPlaneCapabilities2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderBfloat16FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePortabilitySubsetFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePortabilitySubsetPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderClockFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265SessionParametersAddInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdVPSs, base_struct.stdVPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPSs, base_struct.stdSPSCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPSs, base_struct.stdPPSCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pParametersAddInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSliceSegmentOffsets, base_struct.sliceSegmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFragmentShadingRateAttachmentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pFragmentShadingRateAttachment, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineFragmentShadingRateStateCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShadingRateKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingFragmentShadingRateAttachmentInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderQuadControlFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceProtectedCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentWaitFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineExecutablePropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineExecutableInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineExecutableStatisticKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineExecutableInternalRepresentationKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pData, base_struct.dataSize, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLibraries, base_struct.libraryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentIdKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentIds, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentIdFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetupReferenceSlot, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReferenceSlots, base_struct.referenceSlotCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeUsageInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeRateControlLayerInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeRateControlInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLayers, base_struct.layerCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVideoProfile, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeQualityLevelPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeQualityLevelInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeSessionParametersGetInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeSessionParametersFeedbackInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilitiesPresentId2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentId2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentIds, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentId2FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilitiesPresentWait2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentWait2FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentWait2InfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineBinaryFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineBinaryPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDevicePipelineBinaryInternalCacheControlKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryKeyKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryDataKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pData, base_struct.dataSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryKeysAndDataKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pPipelineBinaryKeys, base_struct.binaryCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineBinaryData, base_struct.binaryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pKeysAndDataInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineCreateInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineBinaries, base_struct.binaryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkReleaseCapturedPipelineDataInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryDataInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineBinaryHandlesInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelineBinaries, base_struct.pipelineBinaryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfacePresentModeKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfacePresentScalingCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfacePresentModeCompatibilityKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentModes, base_struct.presentModeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentFenceInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pFences, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentModesCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentModes, base_struct.presentModeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentModeInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentModes, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentScalingCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkReleaseSwapchainImagesInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImageIndices, base_struct.imageIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCooperativeMatrixPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrixFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrixPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSequenceHeader, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTileOffsets, base_struct.tileCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTileSizes, base_struct.tileCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1QualityLevelPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1SessionCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1SessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSequenceHeader, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdDecoderModelInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdOperatingPoints, base_struct.stdOperatingPointCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1DpbSlotInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdReferenceInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1GopRemainingFrameInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1RateControlInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1RateControlLayerInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeVP9ProfileInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeVP9CapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeVP9PictureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPictureInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoMaintenance1FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoInlineQueryInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentFeedbackLoopInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCalibratedTimestampInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSetDescriptorBufferOffsetsInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBufferIndices, base_struct.setCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pOffsets, base_struct.setCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeIntraRefreshCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeSessionIntraRefreshCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeIntraRefreshInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoReferenceIntraRefreshInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeQuantizationMapCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoFormatQuantizationMapPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeQuantizationMapInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH264QuantizationMapCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeH265QuantizationMapCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoFormatH265QuantizationMapPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoFormatAV1QuantizationMapPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance7FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance7PropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLayeredApiPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLayeredApiPropertiesListKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLayeredApis, base_struct.layeredApiCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance8FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryBarrierAccessFlags3KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance9FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance9PropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyOwnershipTransferPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVideoMaintenance2FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH264InlineSessionParametersInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPS, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPS, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeH265InlineSessionParametersInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdVPS, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSPS, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdPPS, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVideoDecodeAV1InlineSessionParametersInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStdSequenceHeader, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRobustness2FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRobustness2PropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugReportCallbackCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationStateRasterizationOrderAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugMarkerObjectNameInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pObjectName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugMarkerObjectTagInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTag, base_struct.tagSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugMarkerMarkerInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMarkerName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDedicatedAllocationImageCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDedicatedAllocationBufferCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDedicatedAllocationMemoryAllocateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTransformFeedbackFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTransformFeedbackPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationStateStreamCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewHandleInfoNVX* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewAddressPropertiesNVX* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTextureLODGatherFormatPropertiesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkStreamDescriptorSurfaceCreateInfoGGP* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCornerSampledImageFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalMemoryImageCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportMemoryAllocateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryWin32HandleInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExportMemoryWin32HandleInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttributes, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWin32KeyedMutexAcquireReleaseInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireSyncs, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireKeys, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAcquireTimeoutMilliseconds, base_struct.acquireCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReleaseSyncs, base_struct.releaseCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pReleaseKeys, base_struct.releaseCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkValidationFlagsEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDisabledValidationChecks, base_struct.disabledValidationCheckCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkViSurfaceCreateInfoNN* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewASTCDecodeModeEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceASTCDecodeFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkConditionalRenderingBeginInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceConditionalRenderingFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferInheritanceConditionalRenderingInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportWScalingStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewportWScalings, base_struct.viewportCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilities2EXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayPowerInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceEventInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayEventInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainCounterCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentTimesInfoGOOGLE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTimes, base_struct.swapchainCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMultiviewPerViewAttributesInfoNVX* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportSwizzleStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewportSwizzles, base_struct.viewportCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDiscardRectanglePropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineDiscardRectangleStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDiscardRectangles, base_struct.discardRectangleCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationConservativeStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthClipEnableFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationDepthClipStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHdrMetadataEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIOSSurfaceCreateInfoMVK* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMacOSSurfaceCreateInfoMVK* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugUtilsLabelEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLabelName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugUtilsObjectNameInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pObjectName, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugUtilsMessengerCallbackDataEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMessageIdName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMessage, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueLabels, base_struct.queueLabelCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCmdBufLabels, base_struct.cmdBufLabelCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pObjects, base_struct.objectCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugUtilsMessengerCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDebugUtilsObjectTagInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTag, base_struct.tagSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAndroidHardwareBufferUsageANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAndroidHardwareBufferPropertiesANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAndroidHardwareBufferFormatPropertiesANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetAndroidHardwareBufferInfoANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalFormatANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAndroidHardwareBufferFormatProperties2ANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAttachmentSampleCountInfoAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorAttachmentSamples, base_struct.colorAttachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSampleLocationsInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSampleLocations, base_struct.sampleLocationsCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassSampleLocationsBeginInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAttachmentInitialSampleLocations, base_struct.attachmentInitialSampleLocationsCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPostSubpassSampleLocations, base_struct.postSubpassSampleLocationsCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineSampleLocationsStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSampleLocationsPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMultisamplePropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorBlendAdvancedStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCoverageToColorStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCoverageModulationStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCoverageModulationTable, base_struct.coverageModulationTableCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDrmFormatModifierPropertiesListEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDrmFormatModifierProperties, base_struct.drmFormatModifierCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageDrmFormatModifierListCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDrmFormatModifiers, base_struct.drmFormatModifierCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageDrmFormatModifierExplicitCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPlaneLayouts, base_struct.drmFormatModifierPlaneCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageDrmFormatModifierPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDrmFormatModifierPropertiesList2EXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDrmFormatModifierProperties, base_struct.drmFormatModifierCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkValidationCacheCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInitialData, base_struct.initialDataSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkShaderModuleValidationCacheCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkShadingRatePaletteNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pShadingRatePaletteEntries, base_struct.shadingRatePaletteEntryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportShadingRateImageStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pShadingRatePalettes, base_struct.viewportCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShadingRateImageFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShadingRateImagePropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCoarseSampleOrderCustomNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pSampleLocations, base_struct.sampleLocationCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCustomSampleOrders, base_struct.customSampleOrderCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRayTracingShaderGroupCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRayTracingPipelineCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStages, base_struct.stageCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pGroups, base_struct.groupCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeometryTrianglesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeometryAABBNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeometryNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pGeometries, base_struct.geometryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindAccelerationStructureMemoryInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDeviceIndices, base_struct.deviceIndexCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteDescriptorSetAccelerationStructureNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAccelerationStructures, base_struct.accelerationStructureCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureMemoryRequirementsInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageViewImageFormatInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFilterCubicImageViewImageFormatPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryHostPointerInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryHostPointerPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCompilerControlCreateInfoAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderCorePropertiesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceMemoryOverallocationCreateInfoAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPresentFrameTokenGGP* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMeshShaderFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMeshShaderPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderImageFootprintFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportExclusiveScissorStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pExclusiveScissors, base_struct.exclusiveScissorCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExclusiveScissorFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyCheckpointPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCheckpointDataNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyCheckpointProperties2NV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCheckpointData2NV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkInitializePerformanceApiInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueryPoolPerformanceQueryCreateInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceMarkerInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceStreamMarkerInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceOverrideInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerformanceConfigurationAcquireInfoINTEL* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePCIBusInfoPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayNativeHdrSurfaceCapabilitiesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainDisplayNativeHdrCreateInfoAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImagePipeSurfaceCreateInfoFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassFragmentDensityMapCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingFragmentDensityMapAttachmentInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderCoreProperties2AMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCoherentMemoryFeaturesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMemoryBudgetPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMemoryPriorityFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryPriorityAllocateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferDeviceAddressCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkValidationFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pEnabledValidationFeatures, base_struct.enabledValidationFeatureCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDisabledValidationFeatures, base_struct.disabledValidationFeatureCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCooperativeMatrixPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrixFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrixPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCoverageReductionModeFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineCoverageReductionStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFramebufferMixedSamplesCombinationNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceProvokingVertexFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceProvokingVertexPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceFullScreenExclusiveInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilitiesFullScreenExclusiveEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceFullScreenExclusiveWin32InfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHeadlessSurfaceCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryMapPlacedInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGraphicsShaderGroupCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStages, base_struct.stageCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVertexInputState, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTessellationState, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGraphicsPipelineShaderGroupsCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pGroups, base_struct.groupCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPipelines, base_struct.pipelineCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectCommandsLayoutTokenNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pIndexTypes, base_struct.indexTypeCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pIndexTypeValues, base_struct.indexTypeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectCommandsLayoutCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTokens, base_struct.tokenCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStreamStrides, base_struct.streamCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStreams, base_struct.streamCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsMemoryRequirementsInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceInheritedViewportScissorFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferInheritanceViewportScissorInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pViewportDepths, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassTransformBeginInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthBiasControlFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDepthBiasInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDepthBiasRepresentationInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceMemoryReportCallbackDataEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceDeviceMemoryReportCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerCustomBorderColorCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCustomBorderColorPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCustomBorderColorFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentBarrierFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfaceCapabilitiesPresentBarrierNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentBarrierCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceDiagnosticsConfigCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTileShadingFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTileShadingPropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassTileShadingCreateInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerTileBeginInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPerTileEndInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDispatchTileInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueryLowLatencySupportNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineFragmentShadingRateEnumStateCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryMotionTrianglesDataNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureMotionInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyCommandTransformInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageCompressionControlFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageCompressionControlEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pFixedRateFlags, base_struct.compressionControlPlaneCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageCompressionPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevice4444FormatsFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFaultFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceFaultCountsEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceFaultInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAddressInfos, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVendorInfos, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMutableDescriptorTypeListEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pDescriptorTypes, base_struct.descriptorTypeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMutableDescriptorTypeCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pMutableDescriptorTypeLists, base_struct.mutableDescriptorTypeListCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputBindingDescription2EXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkVertexInputAttributeDescription2EXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDrmPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAddressBindingReportFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceAddressBindingCallbackDataEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthClipControlFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportDepthClipControlCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryZirconHandleInfoFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryZirconHandlePropertiesFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetZirconHandleInfoFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportSemaphoreZirconHandleInfoFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSemaphoreGetZirconHandleInfoFUCHSIA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetRemoteAddressInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFrameBoundaryFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkFrameBoundaryEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pImages, base_struct.imageCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pBuffers, base_struct.bufferCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTag, base_struct.tagSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassResolvePerformanceQueryEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMultisampledRenderToSingleSampledInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceColorWriteEnableFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineColorWriteCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pColorWriteEnables, base_struct.attachmentCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageViewMinLodFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewMinLodCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiDrawFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiDrawPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderTileImageFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderTileImagePropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMicromapBuildInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMicromapCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceOpacityMicromapFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceOpacityMicromapPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMicromapVersionInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVersionData, 2 * VK_UUID_SIZE, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMicromapToMemoryInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMemoryToMicromapInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMicromapInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMicromapBuildSizesInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureTrianglesOpacityMicromapEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDisplacementMicromapFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDisplacementMicromapPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureTrianglesDisplacementMicromapNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppUsageCounts, base_struct.usageCountsCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerBorderColorComponentMappingCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderCorePropertiesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceQueueShaderCoreControlCreateInfoARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSchedulingControlsFeaturesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSchedulingControlsPropertiesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewSlicedCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetBindingReferenceVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDescriptorSetLayoutHostMappingInfoVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRenderPassStripedFeaturesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRenderPassStripedPropertiesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassStripeInfoARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassStripeBeginInfoARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStripeInfos, base_struct.stripeInfoCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassStripeSubmitInfoARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStripeSemaphoreInfos, base_struct.stripeSemaphoreInfoCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassFragmentDensityMapOffsetEndInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pFragmentDensityOffsets, base_struct.fragmentDensityOffsetCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkComputePipelineIndirectBufferInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineIndirectDeviceAddressInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryLinearSweptSpheresDataNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometrySpheresDataNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLinearColorAttachmentFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageViewSampleWeightCreateInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageProcessingFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageProcessingPropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceNestedCommandBufferFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceNestedCommandBufferPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkExternalMemoryAcquireUnmodifiedEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassCreationControlEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassCreationFeedbackCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRenderPassFeedback, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderPassSubpassFeedbackCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSubpassFeedback, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDirectDriverLoadingInfoLUNARG* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDirectDriverLoadingListLUNARG* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDrivers, base_struct.driverCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineShaderStageModuleIdentifierCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pIdentifier, base_struct.identifierSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkShaderModuleIdentifierEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceOpticalFlowFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceOpticalFlowPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOpticalFlowImageFormatInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOpticalFlowImageFormatPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOpticalFlowSessionCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOpticalFlowSessionCreatePrivateDataInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOpticalFlowExecuteInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pRegions, base_struct.regionCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLegacyDitheringFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAndroidHardwareBufferFormatResolvePropertiesANDROID* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAntiLagFeaturesAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAntiLagPresentationInfoAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAntiLagDataAMD* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentationInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderObjectFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderObjectPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkShaderCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pCode, base_struct.codeSize, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetLayouts, base_struct.setLayoutCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPushConstantRanges, base_struct.pushConstantRangeCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSpecializationInfo, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTilePropertiesFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTilePropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAmigoProfilingFeaturesSEC* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAmigoProfilingSubmitInfoSEC* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeVectorPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeVectorFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCooperativeVectorPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkConvertCooperativeVectorMatrixInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDstSize, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLayerSettingEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pointer(base_struct, base_struct.pLayerName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSettingName, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pValues, base_struct.valueCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLayerSettingsCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSettings, base_struct.settingCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLatencySleepModeInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLatencySleepInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSetLatencyMarkerInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLatencyTimingsFrameReportNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGetLatencyMarkerInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTimings, base_struct.timingCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLatencySubmissionPresentIdNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainLatencyCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkOutOfBandQueueTypeInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkLatencySurfaceCapabilitiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPresentModes, base_struct.presentModeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPerViewRenderAreas, base_struct.perViewRenderAreaCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePerStageDescriptorSetFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageProcessing2FeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageProcessing2PropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerBlockMatchWindowCreateInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCubicWeightsFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerCubicWeightsCreateInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBlitImageCubicWeightsInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCubicClampFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLayeredDriverPropertiesMSFT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTileMemoryRequirementsQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTileMemoryBindInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkTileMemorySizeInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplaySurfaceStereoCreateInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDisplayModeStereoPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRawAccessChainsFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderFloat8FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingValidationFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPartitionedAccelerationStructureFlagsNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteDescriptorSetPartitionedAccelerationStructureNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAccelerationStructures, base_struct.accelerationStructureCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPartitionedAccelerationStructureInstancesInputNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBuildPartitionedAccelerationStructureInfoNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureBuildSizesInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsMemoryRequirementsInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectExecutionSetPipelineInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectExecutionSetShaderLayoutInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetLayouts, base_struct.setLayoutCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectExecutionSetShaderInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pInitialShaders, base_struct.shaderCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pSetLayoutInfos, base_struct.shaderCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pPushConstantRanges, base_struct.pushConstantRangeCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectExecutionSetCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_struct_member(base_struct, base_struct.info, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteIndirectExecutionSetPipelineEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectCommandsLayoutTokenEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_union(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkIndirectCommandsLayoutCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pTokens, base_struct.tokenCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsPipelineInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkGeneratedCommandsShaderInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pShaders, base_struct.shaderCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteIndirectExecutionSetShaderEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageAlignmentControlFeaturesMESA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceImageAlignmentControlPropertiesMESA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageAlignmentControlCreateInfoMESA* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthClampControlFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineViewportDepthClampControlCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDepthClampRange, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHdrVividFeaturesHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHdrVividDynamicMetadataHUAWEI* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDynamicMetadata, base_struct.dynamicMetadataSize, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCooperativeMatrixFlexibleDimensionsPropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrix2FeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceCooperativeMatrix2PropertiesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImportMemoryMetalHandleInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryMetalHandlePropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryGetMetalHandleInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFormatPackFeaturesARM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSetPresentConfigNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePresentMeteringFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingEndInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryTrianglesDataKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryAabbsDataKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryInstancesDataKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureGeometryKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_struct_member(base_struct, base_struct.geometry, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureBuildGeometryInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pGeometries, base_struct.geometryCount, i, offset, out_data);
        handle_array_of_pointers(base_struct, base_struct.ppGeometries, base_struct.geometryCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkWriteDescriptorSetAccelerationStructureKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pAccelerationStructures, base_struct.accelerationStructureCount, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAccelerationStructureFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceAccelerationStructurePropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureDeviceAddressInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkAccelerationStructureVersionInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pVersionData, 2 * VK_UUID_SIZE, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyAccelerationStructureToMemoryInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMemoryToAccelerationStructureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyAccelerationStructureInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRayTracingShaderGroupCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRayTracingPipelineInterfaceCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRayTracingPipelineCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pStages, base_struct.stageCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pGroups, base_struct.groupCount, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLibraryInfo, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pLibraryInterface, 1, i, offset, out_data);
        handle_pointer(base_struct, base_struct.pDynamicState, 1, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayTracingPipelinePropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRayQueryFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMeshShaderFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMeshShaderPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
