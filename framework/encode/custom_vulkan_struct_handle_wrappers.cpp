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

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static void UnwrapDescriptorImageInfoStructArrayHandles(VkDescriptorType             type,
                                                        const VkDescriptorImageInfo* values,
                                                        size_t                       len,
                                                        HandleStore*                 handle_store,
                                                        HandleArrayStore*            handle_array_store,
                                                        HandleArrayUnwrapMemory*     handle_unwrap_memory)
{
    if (values != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(type, &values[i], handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

static void RewrapDescriptorImageInfoStructArrayHandles(VkDescriptorType                  type,
                                                        const VkDescriptorImageInfo*      values,
                                                        size_t                            len,
                                                        HandleStore::const_iterator*      handle_store_iter,
                                                        HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (values != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            RewrapStructHandles(type, &values[i], handle_store_iter, handle_array_store_iter);
        }
    }
}

void UnwrapStructHandles(VkDescriptorType             type,
                         const VkDescriptorImageInfo* value,
                         HandleStore*                 handle_store,
                         HandleArrayStore*            handle_array_store,
                         HandleArrayUnwrapMemory*     handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
        {
            // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
            UnwrapHandle<SamplerWrapper>(&value->sampler, handle_store);
        }

        if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
        {
            UnwrapHandle<ImageViewWrapper>(&value->imageView, handle_store);
        }
    }
}

void RewrapStructHandles(VkDescriptorType                  type,
                         const VkDescriptorImageInfo*      value,
                         HandleStore::const_iterator*      handle_store_iter,
                         HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
        {
            // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
            RewrapHandle<SamplerWrapper>(&value->sampler, handle_store_iter);
        }

        if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
        {
            RewrapHandle<ImageViewWrapper>(&value->imageView, handle_store_iter);
        }
    }
}

void UnwrapStructHandles(const VkWriteDescriptorSet* value,
                         HandleStore*                handle_store,
                         HandleArrayStore*           handle_array_store,
                         HandleArrayUnwrapMemory*    handle_unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);
        }

        UnwrapHandle<DescriptorSetWrapper>(&value->dstSet, handle_store);

        switch (value->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                UnwrapDescriptorImageInfoStructArrayHandles(value->descriptorType,
                                                            value->pImageInfo,
                                                            value->descriptorCount,
                                                            handle_store,
                                                            handle_array_store,
                                                            handle_unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                UnwrapStructArrayHandles(
                    value->pBufferInfo, value->descriptorCount, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                UnwrapHandles<BufferViewWrapper>(
                    &value->pTexelBufferView, value->descriptorCount, handle_array_store, handle_unwrap_memory);
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                break;
        }
    }
}

void RewrapStructHandles(const VkWriteDescriptorSet*       value,
                         HandleStore::const_iterator*      handle_store_iter,
                         HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        if (value->pNext != nullptr)
        {
            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);
        }

        RewrapHandle<DescriptorSetWrapper>(&value->dstSet, handle_store_iter);

        switch (value->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                RewrapDescriptorImageInfoStructArrayHandles(value->descriptorType,
                                                            value->pImageInfo,
                                                            value->descriptorCount,
                                                            handle_store_iter,
                                                            handle_array_store_iter);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                RewrapStructArrayHandles(
                    value->pBufferInfo, value->descriptorCount, handle_store_iter, handle_array_store_iter);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                RewrapHandles<BufferViewWrapper>(
                    &value->pTexelBufferView, value->descriptorCount, handle_array_store_iter);
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                break;
        }
    }
}

void UnwrapStructHandles(const VkObjectTableEntryNVX* value,
                         HandleStore*                 handle_store,
                         HandleArrayStore*            handle_array_store,
                         HandleArrayUnwrapMemory*     handle_unwrap_memory)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            case VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableDescriptorSetEntryNVX*>(value);
                UnwrapStructHandles(object, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTablePipelineEntryNVX*>(value);
                UnwrapStructHandles(object, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableIndexBufferEntryNVX*>(value);
                UnwrapStructHandles(object, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableVertexBufferEntryNVX*>(value);
                UnwrapStructHandles(object, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTablePushConstantEntryNVX*>(value);
                UnwrapStructHandles(object, handle_store, handle_array_store, handle_unwrap_memory);
                break;
            }
            default:
                GFXRECON_LOG_WARNING(
                    "Skipping custom struct handle rewrapping for unrecognized VkObjectEntryTypeNVX %u", value->type);
                break;
        }
    }
}

void RewrapStructHandles(const VkObjectTableEntryNVX*      value,
                         HandleStore::const_iterator*      handle_store_iter,
                         HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            case VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableDescriptorSetEntryNVX*>(value);
                RewrapStructHandles(object, handle_store_iter, handle_array_store_iter);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTablePipelineEntryNVX*>(value);
                RewrapStructHandles(object, handle_store_iter, handle_array_store_iter);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableIndexBufferEntryNVX*>(value);
                RewrapStructHandles(object, handle_store_iter, handle_array_store_iter);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTableVertexBufferEntryNVX*>(value);
                RewrapStructHandles(object, handle_store_iter, handle_array_store_iter);
                break;
            }
            case VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX:
            {
                auto object = reinterpret_cast<const VkObjectTablePushConstantEntryNVX*>(value);
                RewrapStructHandles(object, handle_store_iter, handle_array_store_iter);
                break;
            }
            default:
                GFXRECON_LOG_WARNING(
                    "Skipping custom struct handle rewrapping for unrecognized VkObjectEntryTypeNVX %u", value->type);
                break;
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
