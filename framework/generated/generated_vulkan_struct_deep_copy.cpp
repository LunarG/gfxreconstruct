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

inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)
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

//! create a helper-lambda to handle pointer-type struct-members
template <typename T>
auto create_pointer_helper_function(const T& base_struct, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    auto handle_pointer_fn = [out_data, out_index, &offset, &base_struct](const auto& pointer_member, uint32_t count) {
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
            auto* out_ptr      = reinterpret_cast<pointer_type*>(out_data + out_index * sizeof(T) + member_offset);
            *out_ptr           = reinterpret_cast<pointer_type>(offset_ptr(out_data, offset));
        }
        offset += copy_size;
    };
    return handle_pointer_fn;

};

template <typename T>
void handle_pnext(const T& base_struct, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    if (base_struct.pNext != nullptr)
    {
        uint8_t* out_address = offset_ptr(out_data, offset);
        offset += vulkan_struct_deep_copy_pnext(base_struct.pNext, out_address);
        if (out_address != nullptr)
        {
            void** out_pNext = reinterpret_cast<void**>(out_data + out_index * sizeof(T) + offsetof(T, pNext));
            *out_pNext       = out_address;
        }
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
size_t vulkan_struct_deep_copy(const VkAllocationCallbacks* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUserData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pApplicationName, 1);
        handle_pointer_member(base_struct.pEngineName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pApplicationInfo, 1);
        if(base_struct.ppEnabledLayerNames != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.enabledLayerCount; ++j)
            {
                handle_pointer_member(base_struct.ppEnabledLayerNames[j], 1);
            }
        }
        if(base_struct.ppEnabledExtensionNames != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.enabledExtensionCount; ++j)
            {
                handle_pointer_member(base_struct.ppEnabledExtensionNames[j], 1);
            }
        }
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueuePriorities, base_struct.queueCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueueCreateInfos, base_struct.queueCreateInfoCount);
        if(base_struct.ppEnabledLayerNames != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.enabledLayerCount; ++j)
            {
                handle_pointer_member(base_struct.ppEnabledLayerNames[j], 1);
            }
        }
        if(base_struct.ppEnabledExtensionNames != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.enabledExtensionCount; ++j)
            {
                handle_pointer_member(base_struct.ppEnabledExtensionNames[j], 1);
            }
        }
        handle_pointer_member(base_struct.pEnabledFeatures, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount);
        handle_pointer_member(base_struct.pWaitDstStageMask, base_struct.waitSemaphoreCount);
        handle_pointer_member(base_struct.pCommandBuffers, base_struct.commandBufferCount);
        handle_pointer_member(base_struct.pSignalSemaphores, base_struct.signalSemaphoreCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBinds, base_struct.bindCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBinds, base_struct.bindCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBinds, base_struct.bindCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount);
        handle_pointer_member(base_struct.pBufferBinds, base_struct.bufferBindCount);
        handle_pointer_member(base_struct.pImageOpaqueBinds, base_struct.imageOpaqueBindCount);
        handle_pointer_member(base_struct.pImageBinds, base_struct.imageBindCount);
        handle_pointer_member(base_struct.pSignalSemaphores, base_struct.signalSemaphoreCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCode, base_struct.codeSize/4);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pInitialData, base_struct.initialDataSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pMapEntries, base_struct.mapEntryCount);
        handle_pointer_member(base_struct.pData, base_struct.dataSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pName, 1);
        handle_pointer_member(base_struct.pSpecializationInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVertexBindingDescriptions, base_struct.vertexBindingDescriptionCount);
        handle_pointer_member(base_struct.pVertexAttributeDescriptions, base_struct.vertexAttributeDescriptionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSampleMask, (base_struct.rasterizationSamples + 31) / 32);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDynamicStates, base_struct.dynamicStateCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStages, base_struct.stageCount);
        handle_pointer_member(base_struct.pVertexInputState, 1);
        handle_pointer_member(base_struct.pInputAssemblyState, 1);
        handle_pointer_member(base_struct.pTessellationState, 1);
        handle_pointer_member(base_struct.pViewportState, 1);
        handle_pointer_member(base_struct.pRasterizationState, 1);
        handle_pointer_member(base_struct.pMultisampleState, 1);
        handle_pointer_member(base_struct.pDepthStencilState, 1);
        handle_pointer_member(base_struct.pColorBlendState, 1);
        handle_pointer_member(base_struct.pDynamicState, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSetLayouts, base_struct.setLayoutCount);
        handle_pointer_member(base_struct.pPushConstantRanges, base_struct.pushConstantRangeCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPoolSizes, base_struct.poolSizeCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSetLayouts, base_struct.descriptorSetCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pImmutableSamplers, base_struct.descriptorCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBindings, base_struct.bindingCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pImageInfo, base_struct.descriptorCount);
        handle_pointer_member(base_struct.pBufferInfo, base_struct.descriptorCount);
        handle_pointer_member(base_struct.pTexelBufferView, base_struct.descriptorCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachments, base_struct.attachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pInputAttachments, base_struct.inputAttachmentCount);
        handle_pointer_member(base_struct.pColorAttachments, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pResolveAttachments, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pDepthStencilAttachment, 1);
        handle_pointer_member(base_struct.pPreserveAttachments, base_struct.preserveAttachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachments, base_struct.attachmentCount);
        handle_pointer_member(base_struct.pSubpasses, base_struct.subpassCount);
        handle_pointer_member(base_struct.pDependencies, base_struct.dependencyCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pInheritanceInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pClearValues, base_struct.clearValueCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDeviceRenderAreas, base_struct.deviceRenderAreaCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphoreDeviceIndices, base_struct.waitSemaphoreCount);
        handle_pointer_member(base_struct.pCommandBufferDeviceMasks, base_struct.commandBufferCount);
        handle_pointer_member(base_struct.pSignalSemaphoreDeviceIndices, base_struct.signalSemaphoreCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDeviceIndices, base_struct.deviceIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDeviceIndices, base_struct.deviceIndexCount);
        handle_pointer_member(base_struct.pSplitInstanceBindRegions, base_struct.splitInstanceBindRegionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPhysicalDevices, base_struct.physicalDeviceCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAspectReferences, base_struct.aspectReferenceCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewMasks, base_struct.subpassCount);
        handle_pointer_member(base_struct.pViewOffsets, base_struct.dependencyCount);
        handle_pointer_member(base_struct.pCorrelationMasks, base_struct.correlationMaskCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDescriptorUpdateEntries, base_struct.descriptorUpdateEntryCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewFormats, base_struct.viewFormatCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pInputAttachments, base_struct.inputAttachmentCount);
        handle_pointer_member(base_struct.pColorAttachments, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pResolveAttachments, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pDepthStencilAttachment, 1);
        handle_pointer_member(base_struct.pPreserveAttachments, base_struct.preserveAttachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachments, base_struct.attachmentCount);
        handle_pointer_member(base_struct.pSubpasses, base_struct.subpassCount);
        handle_pointer_member(base_struct.pDependencies, base_struct.dependencyCount);
        handle_pointer_member(base_struct.pCorrelatedViewMasks, base_struct.correlatedViewMaskCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBindingFlags, base_struct.bindingCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDescriptorCounts, base_struct.descriptorSetCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDepthStencilResolveAttachment, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewFormats, base_struct.viewFormatCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachmentImageInfos, base_struct.attachmentImageInfoCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachments, base_struct.attachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphoreValues, base_struct.waitSemaphoreValueCount);
        handle_pointer_member(base_struct.pSignalSemaphoreValues, base_struct.signalSemaphoreValueCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSemaphores, base_struct.semaphoreCount);
        handle_pointer_member(base_struct.pValues, base_struct.semaphoreCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPipelineCreationFeedback, 1);
        handle_pointer_member(base_struct.pPipelineStageCreationFeedbacks, base_struct.pipelineStageCreationFeedbackCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pMemoryBarriers, base_struct.memoryBarrierCount);
        handle_pointer_member(base_struct.pBufferMemoryBarriers, base_struct.bufferMemoryBarrierCount);
        handle_pointer_member(base_struct.pImageMemoryBarriers, base_struct.imageMemoryBarrierCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphoreInfos, base_struct.waitSemaphoreInfoCount);
        handle_pointer_member(base_struct.pCommandBufferInfos, base_struct.commandBufferInfoCount);
        handle_pointer_member(base_struct.pSignalSemaphoreInfos, base_struct.signalSemaphoreInfoCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pData, base_struct.dataSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachments, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pDepthAttachment, 1);
        handle_pointer_member(base_struct.pStencilAttachment, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCreateInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCreateInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphores, base_struct.waitSemaphoreCount);
        handle_pointer_member(base_struct.pSwapchains, base_struct.swapchainCount);
        handle_pointer_member(base_struct.pImageIndices, base_struct.swapchainCount);
        handle_pointer_member(base_struct.pResults, base_struct.swapchainCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDeviceMasks, base_struct.swapchainCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.displayName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.hinstance, 1);
        handle_pointer_member(base_struct.hwnd, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pProfiles, base_struct.profileCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPictureResource, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVideoProfile, 1);
        handle_pointer_member(base_struct.pStdHeaderVersion, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pReferenceSlots, base_struct.referenceSlotCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSetupReferenceSlot, 1);
        handle_pointer_member(base_struct.pReferenceSlots, base_struct.referenceSlotCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdSPSs, base_struct.stdSPSCount);
        handle_pointer_member(base_struct.pStdPPSs, base_struct.stdPPSCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pParametersAddInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdSliceHeader, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pNaluSliceEntries, base_struct.naluSliceEntryCount);
        handle_pointer_member(base_struct.pStdPictureInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdReferenceInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdVPSs, base_struct.stdVPSCount);
        handle_pointer_member(base_struct.pStdSPSs, base_struct.stdSPSCount);
        handle_pointer_member(base_struct.pStdPPSs, base_struct.stdPPSCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pParametersAddInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdSliceSegmentHeader, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pNaluSliceSegmentEntries, base_struct.naluSliceSegmentEntryCount);
        handle_pointer_member(base_struct.pStdPictureInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdReferenceInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdSPSs, base_struct.stdSPSCount);
        handle_pointer_member(base_struct.pStdPPSs, base_struct.stdPPSCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pParametersAddInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdPictureInfo, 1);
        handle_pointer_member(base_struct.pSliceOffsets, base_struct.sliceCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdReferenceInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentSamples, base_struct.colorAttachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.handle, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttributes, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAcquireSyncs, base_struct.acquireCount);
        handle_pointer_member(base_struct.pAcquireKeys, base_struct.acquireCount);
        handle_pointer_member(base_struct.pAcquireTimeouts, base_struct.acquireCount);
        handle_pointer_member(base_struct.pReleaseSyncs, base_struct.releaseCount);
        handle_pointer_member(base_struct.pReleaseKeys, base_struct.releaseCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.handle, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttributes, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pWaitSemaphoreValues, base_struct.waitSemaphoreValuesCount);
        handle_pointer_member(base_struct.pSignalSemaphoreValues, base_struct.signalSemaphoreValuesCount);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePushDescriptorPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRectangles, base_struct.rectangleCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.swapchainCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.handle, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttributes, 1);
        handle_pointer_member(base_struct.name, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCounterIndices, base_struct.counterIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdVPSs, base_struct.stdVPSCount);
        handle_pointer_member(base_struct.pStdSPSs, base_struct.stdSPSCount);
        handle_pointer_member(base_struct.pStdPPSs, base_struct.stdPPSCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pParametersAddInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdPictureInfo, 1);
        handle_pointer_member(base_struct.pSliceSegmentOffsets, base_struct.sliceSegmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdReferenceInfo, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceQueueGlobalPriorityCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkQueueFamilyGlobalPriorityPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pFragmentShadingRateAttachment, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingAttachmentLocationInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentLocations, base_struct.colorAttachmentCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingInputAttachmentIndexInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentInputIndices, base_struct.colorAttachmentCount);
        handle_pointer_member(base_struct.pDepthInputAttachmentIndex, 1);
        handle_pointer_member(base_struct.pStencilInputAttachmentIndex, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pData, base_struct.dataSize);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryMapInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryUnmapInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pLibraries, base_struct.libraryCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPresentIds, base_struct.swapchainCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSetupReferenceSlot, 1);
        handle_pointer_member(base_struct.pReferenceSlots, base_struct.referenceSlotCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pLayers, base_struct.layerCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVideoProfile, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCheckpointMarker, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance5FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance5PropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkRenderingAreaInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorAttachmentFormats, base_struct.colorAttachmentCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageSubresource2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkDeviceImageSubresourceInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCreateInfo, 1);
        handle_pointer_member(base_struct.pSubresource, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubresourceLayout2KHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
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
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBufferUsageFlags2CreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdSequenceHeader, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdPictureInfo, 1);
        handle_pointer_member(base_struct.pTileOffsets, base_struct.tileCount);
        handle_pointer_member(base_struct.pTileSizes, base_struct.tileCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStdReferenceInfo, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineVertexInputDivisorStateCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVertexBindingDivisors, base_struct.vertexBindingDivisorCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderFloatControls2FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceIndexTypeUint8FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLineRasterizationFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceLineRasterizationPropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRasterizationLineStateCreateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance6FeaturesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceMaintenance6PropertiesKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindMemoryStatusKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pResult, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkBindDescriptorSetsInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDescriptorSets, base_struct.descriptorSetCount);
        handle_pointer_member(base_struct.pDynamicOffsets, base_struct.dynamicOffsetCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushConstantsInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pValues, base_struct.size);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushDescriptorSetInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDescriptorWrites, base_struct.descriptorWriteCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPushDescriptorSetWithTemplateInfoKHR* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pBufferIndices, base_struct.setCount);
        handle_pointer_member(base_struct.pOffsets, base_struct.setCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pLayeredApis, base_struct.layeredApiCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUserData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pObjectName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pTag, base_struct.tagSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pMarkerName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.handle, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttributes, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAcquireSyncs, base_struct.acquireCount);
        handle_pointer_member(base_struct.pAcquireKeys, base_struct.acquireCount);
        handle_pointer_member(base_struct.pAcquireTimeoutMilliseconds, base_struct.acquireCount);
        handle_pointer_member(base_struct.pReleaseSyncs, base_struct.releaseCount);
        handle_pointer_member(base_struct.pReleaseKeys, base_struct.releaseCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDisabledValidationChecks, base_struct.disabledValidationCheckCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.window, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineRobustnessFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineRobustnessPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPipelineRobustnessCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewportWScalings, base_struct.viewportCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pTimes, base_struct.swapchainCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewportSwizzles, base_struct.viewportCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDiscardRectangles, base_struct.discardRectangleCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pView, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pView, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pLabelName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pObjectName, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pMessageIdName, 1);
        handle_pointer_member(base_struct.pMessage, 1);
        handle_pointer_member(base_struct.pQueueLabels, base_struct.queueLabelCount);
        handle_pointer_member(base_struct.pCmdBufLabels, base_struct.cmdBufLabelCount);
        handle_pointer_member(base_struct.pObjects, base_struct.objectCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUserData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pTag, base_struct.tagSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSampleLocations, base_struct.sampleLocationsCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAttachmentInitialSampleLocations, base_struct.attachmentInitialSampleLocationsCount);
        handle_pointer_member(base_struct.pPostSubpassSampleLocations, base_struct.postSubpassSampleLocationsCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCoverageModulationTable, base_struct.coverageModulationTableCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDrmFormatModifierProperties, base_struct.drmFormatModifierCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueueFamilyIndices, base_struct.queueFamilyIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDrmFormatModifiers, base_struct.drmFormatModifierCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPlaneLayouts, base_struct.drmFormatModifierPlaneCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDrmFormatModifierProperties, base_struct.drmFormatModifierCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pInitialData, base_struct.initialDataSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pShadingRatePaletteEntries, base_struct.shadingRatePaletteEntryCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pShadingRatePalettes, base_struct.viewportCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSampleLocations, base_struct.sampleLocationCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCustomSampleOrders, base_struct.customSampleOrderCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStages, base_struct.stageCount);
        handle_pointer_member(base_struct.pGroups, base_struct.groupCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pGeometries, base_struct.geometryCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDeviceIndices, base_struct.deviceIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAccelerationStructures, base_struct.accelerationStructureCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pHostPointer, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pExclusiveScissors, base_struct.exclusiveScissorCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCheckpointMarker, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUserData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pEnabledValidationFeatures, base_struct.enabledValidationFeatureCount);
        handle_pointer_member(base_struct.pDisabledValidationFeatures, base_struct.disabledValidationFeatureCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.hmonitor, 1);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHostImageCopyFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceHostImageCopyPropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCopySrcLayouts, base_struct.copySrcLayoutCount);
        handle_pointer_member(base_struct.pCopyDstLayouts, base_struct.copyDstLayoutCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkMemoryToImageCopyEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pHostPointer, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkImageToMemoryCopyEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pHostPointer, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyMemoryToImageInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageToMemoryInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkCopyImageToImageInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHostImageLayoutTransitionInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubresourceHostMemcpySizeEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkHostImageCopyDevicePerformanceQueryEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPlacedAddress, 1);
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
size_t vulkan_struct_deep_copy(const VkSurfacePresentModeEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfacePresentScalingCapabilitiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSurfacePresentModeCompatibilityEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPresentModes, base_struct.presentModeCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentFenceInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pFences, base_struct.swapchainCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentModesCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPresentModes, base_struct.presentModeCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentModeInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPresentModes, base_struct.swapchainCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSwapchainPresentScalingCreateInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkReleaseSwapchainImagesInfoEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pImageIndices, base_struct.imageIndexCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStages, base_struct.stageCount);
        handle_pointer_member(base_struct.pVertexInputState, 1);
        handle_pointer_member(base_struct.pTessellationState, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pGroups, base_struct.groupCount);
        handle_pointer_member(base_struct.pPipelines, base_struct.pipelineCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pIndexTypes, base_struct.indexTypeCount);
        handle_pointer_member(base_struct.pIndexTypeValues, base_struct.indexTypeCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pTokens, base_struct.tokenCount);
        handle_pointer_member(base_struct.pStreamStrides, base_struct.streamCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStreams, base_struct.streamCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pViewportDepths, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUserData, 1);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRobustness2FeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceRobustness2PropertiesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pQueriedLowLatencyData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pFixedRateFlags, base_struct.compressionControlPlaneCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAddressInfos, 1);
        handle_pointer_member(base_struct.pVendorInfos, 1);
        handle_pointer_member(base_struct.pVendorBinaryData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDescriptorTypes, base_struct.descriptorTypeCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pMutableDescriptorTypeLists, base_struct.mutableDescriptorTypeListCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pImages, base_struct.imageCount);
        handle_pointer_member(base_struct.pBuffers, base_struct.bufferCount);
        handle_pointer_member(base_struct.pTag, base_struct.tagSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pColorWriteEnables, base_struct.attachmentCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUsageCounts, base_struct.usageCountsCount);
        if(base_struct.ppUsageCounts != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.usageCountsCount; ++j)
            {
                handle_pointer_member(base_struct.ppUsageCounts[j], 1);
            }
        }
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVersionData, 2 * VK_UUID_SIZE);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUsageCounts, base_struct.usageCountsCount);
        if(base_struct.ppUsageCounts != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.usageCountsCount; ++j)
            {
                handle_pointer_member(base_struct.ppUsageCounts[j], 1);
            }
        }
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pUsageCounts, base_struct.usageCountsCount);
        if(base_struct.ppUsageCounts != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.usageCountsCount; ++j)
            {
                handle_pointer_member(base_struct.ppUsageCounts[j], 1);
            }
        }
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
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStripeInfos, base_struct.stripeInfoCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStripeSemaphoreInfos, base_struct.stripeSemaphoreInfoCount);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        handle_pnext(base_struct, i, offset, out_data);
    }
    return offset;
}

template <>
size_t vulkan_struct_deep_copy(const VkSubpassFragmentDensityMapOffsetEndInfoQCOM* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
        {
            auto out_structures = reinterpret_cast<struct_type*>(out_data);
            out_structures[i]   = base_struct;
        }
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pFragmentDensityOffsets, base_struct.fragmentDensityOffsetCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRenderPassFeedback, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSubpassFeedback, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pDrivers, base_struct.driverCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pIdentifier, base_struct.identifierSize);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPrivateData, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pRegions, base_struct.regionCount);
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
size_t vulkan_struct_deep_copy(const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* structs, uint32_t count, uint8_t* out_data)
{
    using struct_type              = std::decay_t<decltype(*structs)>;
    constexpr uint32_t struct_size = sizeof(struct_type);

    if (structs == nullptr || count == 0)
    {
        return 0;
    }
    uint64_t offset = struct_size * count;

    for (uint32_t i = 0; i < count; ++i)
    {
        const auto& base_struct = structs[i];
        if (out_data != nullptr)
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pCode, base_struct.codeSize);
        handle_pointer_member(base_struct.pName, 1);
        handle_pointer_member(base_struct.pSetLayouts, base_struct.setLayoutCount);
        handle_pointer_member(base_struct.pPushConstantRanges, base_struct.pushConstantRangeCount);
        handle_pointer_member(base_struct.pSpecializationInfo, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pLayerName, 1);
        handle_pointer_member(base_struct.pSettingName, 1);
        handle_pointer_member(base_struct.pValues, base_struct.valueCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pSettings, base_struct.settingCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pTimings, base_struct.timingCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPresentModes, base_struct.presentModeCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pPerViewRenderAreas, base_struct.perViewRenderAreaCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pGeometries, base_struct.geometryCount);
        if(base_struct.ppGeometries != nullptr)
        {
            for(uint32_t j = 0; j < base_struct.geometryCount; ++j)
            {
                handle_pointer_member(base_struct.ppGeometries[j], 1);
            }
        }
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pAccelerationStructures, base_struct.accelerationStructureCount);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pVersionData, 2 * VK_UUID_SIZE);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pShaderGroupCaptureReplayHandle, 1);
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
        auto handle_pointer_member = create_pointer_helper_function(base_struct, i, offset, out_data);
        handle_pnext(base_struct, i, offset, out_data);
        handle_pointer_member(base_struct.pStages, base_struct.stageCount);
        handle_pointer_member(base_struct.pGroups, base_struct.groupCount);
        handle_pointer_member(base_struct.pLibraryInfo, 1);
        handle_pointer_member(base_struct.pLibraryInterface, 1);
        handle_pointer_member(base_struct.pDynamicState, 1);
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
