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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "decode/custom_vulkan_struct_handle_mappers.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
static void MapHandleArray(const format::HandleId*   ids,
                           T*                        handles,
                           size_t                    len,
                           const VulkanObjectMapper& object_mapper,
                           T (VulkanObjectMapper::*MapFunc)(format::HandleId) const)
{
    if ((ids != nullptr) && (handles != nullptr))
    {
        for (size_t i = 0; i < len; ++i)
        {
            handles[i] = (object_mapper.*MapFunc)(ids[i]);
        }
    }
}

void MapStructHandles(VkDescriptorType               type,
                      Decoded_VkDescriptorImageInfo* wrapper,
                      const VulkanObjectMapper&      object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorImageInfo* value = wrapper->value;

        if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
        {
            // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
            value->sampler = object_mapper.MapVkSampler(wrapper->sampler);
        }

        if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
        {
            value->imageView = object_mapper.MapVkImageView(wrapper->imageView);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSet* value = wrapper->value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->dstSet = object_mapper.MapVkDescriptorSet(wrapper->dstSet);

        switch (value->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                if (!wrapper->pImageInfo->IsNull())
                {
                    size_t                         len     = wrapper->pImageInfo->GetLength();
                    Decoded_VkDescriptorImageInfo* structs = wrapper->pImageInfo->GetMetaStructPointer();
                    for (size_t i = 0; i < len; ++i)
                    {
                        MapStructHandles(value->descriptorType, &structs[i], object_mapper);
                    }
                }
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                MapStructArrayHandles<Decoded_VkDescriptorBufferInfo>(
                    wrapper->pBufferInfo->GetMetaStructPointer(), wrapper->pBufferInfo->GetLength(), object_mapper);
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                MapHandleArray<VkBufferView>(wrapper->pTexelBufferView.GetPointer(),
                                             wrapper->pTexelBufferView.GetHandlePointer(),
                                             wrapper->pTexelBufferView.GetLength(),
                                             object_mapper,
                                             &VulkanObjectMapper::MapVkBufferView);
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
