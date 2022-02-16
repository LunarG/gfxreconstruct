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

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static const VkDescriptorImageInfo* UnwrapDescriptorImageInfoStructArrayHandles(VkDescriptorType             type,
                                                                                const VkDescriptorImageInfo* values,
                                                                                size_t                       len,
                                                                                HandleUnwrapMemory* unwrap_memory)
{
    assert(unwrap_memory != nullptr);

    if ((values != nullptr) && (len > 0))
    {
        const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
        size_t         num_bytes = len * sizeof(values[0]);

        // Copy and transform handles.
        VkDescriptorImageInfo* unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(type, &unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

void UnwrapStructHandles(VkDescriptorType type, VkDescriptorImageInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
        {
            // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
            value->sampler = GetWrappedHandle<VkSampler>(value->sampler);
        }

        if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
        {
            value->imageView = GetWrappedHandle<VkImageView>(value->imageView);
        }
    }
}

void UnwrapStructHandles(VkWriteDescriptorSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);
        }

        value->dstSet = GetWrappedHandle<VkDescriptorSet>(value->dstSet);

        switch (value->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                value->pImageInfo = UnwrapDescriptorImageInfoStructArrayHandles(
                    value->descriptorType, value->pImageInfo, value->descriptorCount, unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                value->pBufferInfo =
                    UnwrapStructArrayHandles(value->pBufferInfo, value->descriptorCount, unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                value->pTexelBufferView =
                    UnwrapHandles<VkBufferView>(value->pTexelBufferView, value->descriptorCount, unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                // Handles are unwrapped in the VkWriteDescriptorSetAccelerationStructureKHR structure in the pNext
                // chain
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                break;
        }
    }
}

const void* TrackPNextStruct(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    const void*        ret        = nullptr;
    VkBaseInStructure* pnext      = nullptr;
    VkBaseInStructure* last_pnext = nullptr;
    auto               base       = reinterpret_cast<const VkBaseInStructure*>(value);
    while (base != nullptr)
    {
        // Use CopyPNextStruct, instead of UnwrapPNextStructHandles because it doesn't need to wrap handles.
        pnext = CopyPNextStruct(base, unwrap_memory);
        if (ret == nullptr)
        {
            ret = pnext;
        }
        else
        {
            last_pnext->pNext = pnext;
        }
        base       = base->pNext;
        last_pnext = pnext;
    }
    return ret;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
