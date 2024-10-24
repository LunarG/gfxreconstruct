/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#include "decode/custom_vulkan_struct_handle_mappers.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(VkDescriptorType               type,
                      Decoded_VkDescriptorImageInfo* wrapper,
                      const VulkanObjectInfoTable&   object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkDescriptorImageInfo* value = wrapper->decoded_value;

        if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
        {
            // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
            value->sampler = handle_mapping::MapHandle<VulkanSamplerInfo>(
                wrapper->sampler, object_info_table, &VulkanObjectInfoTable::GetVkSamplerInfo);
        }

        if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
        {
            value->imageView = handle_mapping::MapHandle<VulkanImageViewInfo>(
                wrapper->imageView, object_info_table, &VulkanObjectInfoTable::GetVkImageViewInfo);
        }
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectInfoTable& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkWriteDescriptorSet* value = wrapper->decoded_value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->dstSet = handle_mapping::MapHandle<VulkanDescriptorSetInfo>(
            wrapper->dstSet, object_mapper, &VulkanObjectInfoTable::GetVkDescriptorSetInfo);

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
                value->pTexelBufferView = handle_mapping::MapHandleArray<VulkanBufferViewInfo>(
                    &wrapper->pTexelBufferView, object_mapper, &VulkanObjectInfoTable::GetVkBufferViewInfo);
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                // Handles are mapped in the VkWriteDescriptorSetInlineUniformBlock structure in the pNext chain
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                // Handles are mapped in the VkWriteDescriptorSetAccelerationStructureKHR structure in the pNext chain
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                break;
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureGeometryKHR* wrapper,
                      const VulkanObjectInfoTable&                object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureGeometryKHR* value = wrapper->decoded_value;

        switch (value->geometryType)
        {
            case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                MapStructHandles(wrapper->geometry->triangles, object_info_table);
                break;
            case VK_GEOMETRY_TYPE_AABBS_KHR:
                // No handle there so the map func doesn't exist
                break;
            case VK_GEOMETRY_TYPE_INSTANCES_KHR:
                // No handle there so the map func doesn't exist
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to map unknown acceleration structure geometry type");
                break;
        }
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper,
                      const VulkanObjectInfoTable&                         object_info_table)
{
    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))
    {
        VkAccelerationStructureBuildGeometryInfoKHR* value = wrapper->decoded_value;

        value->srcAccelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(
            wrapper->srcAccelerationStructure,
            object_info_table,
            &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        value->dstAccelerationStructure = handle_mapping::MapHandle<VulkanAccelerationStructureKHRInfo>(
            wrapper->dstAccelerationStructure,
            object_info_table,
            &VulkanObjectInfoTable::GetVkAccelerationStructureKHRInfo);

        MapStructArrayHandles<Decoded_VkAccelerationStructureGeometryKHR>(
            wrapper->pGeometries->GetMetaStructPointer(), wrapper->pGeometries->GetLength(), object_info_table);

        if (wrapper->ppGeometries->GetMetaStructPointer() != nullptr)
        {
            for (size_t i = 0; i < wrapper->ppGeometries->GetLength(); ++i)
            {
                MapStructHandles(wrapper->ppGeometries->GetMetaStructPointer()[i], object_info_table);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
