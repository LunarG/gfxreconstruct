/*
** Copyright (c) 2022 LunarG, Inc.
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

#include "generated/generated_vulkan_command_buffer_util.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_info.h"

#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void TrackCmdPushDescriptorSetKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper,
                                         VkPipelineLayout                       layout,
                                         uint32_t                               descriptorWriteCount,
                                         const VkWriteDescriptorSet*            pDescriptorWrites)
{
    assert(wrapper != nullptr);

    if (layout != VK_NULL_HANDLE)
    {
        wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(
            GetVulkanWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(layout));
    }

    if (pDescriptorWrites != nullptr)
    {
        for (uint32_t pDescriptorWrites_index = 0; pDescriptorWrites_index < descriptorWriteCount;
             ++pDescriptorWrites_index)
        {
            auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pDescriptorWrites->pNext);
            while (pnext_header != nullptr)
            {
                switch (pnext_header->sType)
                {
                    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
                    {
                        auto pnext_value =
                            reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(pnext_header);
                        if (pnext_value->pAccelerationStructures != nullptr)
                        {
                            for (uint32_t pAccelerationStructures_index = 0;
                                 pAccelerationStructures_index < pnext_value->accelerationStructureCount;
                                 ++pAccelerationStructures_index)
                            {
                                if (pnext_value->pAccelerationStructures[pAccelerationStructures_index] !=
                                    VK_NULL_HANDLE)
                                {
                                    wrapper
                                        ->command_handles
                                            [vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle]
                                        .insert(GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                            pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                        }
                    }
                    break;
                    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
                    {
                        auto pnext_value =
                            reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(pnext_header);
                        if (pnext_value->pAccelerationStructures != nullptr)
                        {
                            for (uint32_t pAccelerationStructures_index = 0;
                                 pAccelerationStructures_index < pnext_value->accelerationStructureCount;
                                 ++pAccelerationStructures_index)
                            {
                                if (pnext_value->pAccelerationStructures[pAccelerationStructures_index] !=
                                    VK_NULL_HANDLE)
                                {
                                    wrapper
                                        ->command_handles
                                            [vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle]
                                        .insert(GetVulkanWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(
                                            pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                        }
                    }
                    break;
                    default:
                        break;
                }
                pnext_header = pnext_header->pNext;
            }

            auto descriptorWrite = pDescriptorWrites[pDescriptorWrites_index];

            if (descriptorWrite.dstSet != VK_NULL_HANDLE)
            {
                wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetHandle].insert(
                    GetVulkanWrappedId<vulkan_wrappers::DescriptorSetWrapper>(descriptorWrite.dstSet));
            }

            switch (descriptorWrite.descriptorType)
            {
                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    if (descriptorWrite.pImageInfo != nullptr)
                    {
                        for (uint32_t pImageInfo_index = 0; pImageInfo_index < descriptorWrite.descriptorCount;
                             ++pImageInfo_index)
                        {
                            // TODO : It seems that immutable VkSamplers may need more support to ensure
                            //  they're handled correctly for all scenarios.  We should be looking up the
                            //  immutable VkSamplers member of the VkDescriptorSetLayout for the binding
                            //  we're currently processing...if there is one we should use that over any
                            //  VkSampler provided in the VkDescriptorWrite.
                            if (descriptorWrite.pImageInfo[pImageInfo_index].sampler != VK_NULL_HANDLE)
                            {
                                wrapper->command_handles[vulkan_state_info::CommandHandleType::SamplerHandle].insert(
                                    GetVulkanWrappedId<vulkan_wrappers::SamplerWrapper>(
                                        descriptorWrite.pImageInfo[pImageInfo_index].sampler));
                            }
                            if (descriptorWrite.pImageInfo[pImageInfo_index].imageView != VK_NULL_HANDLE)
                            {
                                wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(
                                    GetVulkanWrappedId<vulkan_wrappers::ImageViewWrapper>(
                                        descriptorWrite.pImageInfo[pImageInfo_index].imageView));
                            }
                        }
                    }
                }
                break;
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    if (descriptorWrite.pBufferInfo != nullptr)
                    {
                        for (uint32_t pBufferInfo_index = 0; pBufferInfo_index < descriptorWrite.descriptorCount;
                             ++pBufferInfo_index)
                        {
                            if (descriptorWrite.pBufferInfo[pBufferInfo_index].buffer != VK_NULL_HANDLE)
                            {
                                wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(
                                    GetVulkanWrappedId<vulkan_wrappers::BufferWrapper>(
                                        descriptorWrite.pBufferInfo[pBufferInfo_index].buffer));
                            }
                        }
                    }
                }
                break;
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    if (descriptorWrite.pTexelBufferView != nullptr)
                    {
                        for (uint32_t pTexelBufferView_index = 0;
                             pTexelBufferView_index < descriptorWrite.descriptorCount;
                             ++pTexelBufferView_index)
                        {
                            if (descriptorWrite.pTexelBufferView[pTexelBufferView_index] != VK_NULL_HANDLE)
                            {
                                wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferViewHandle].insert(
                                    GetVulkanWrappedId<vulkan_wrappers::BufferViewWrapper>(
                                        descriptorWrite.pTexelBufferView[pTexelBufferView_index]));
                            }
                        }
                    }
                }
                break;
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                {
                    assert(false && "Maintentance required to support pushed inline uniform block descriptors when "
                                    "creating trimmed captures");
                }
                break;
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                case VK_DESCRIPTOR_TYPE_MUTABLE_VALVE:
                default:
                    break;
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
